/*----------------------------------------------------------------------------*-
					===============================
					 y_td - Stlyes for text draws!
					===============================
Description:
	Provides a wrapper to the SA:MP text_draw functions offering much
	improved functionality including XML definable styles, safe display,
	timed displays, styles and text separated, styles updateable dynamically
	and more.
Legal:
	Version: MPL 1.1
	
	The contents of this file are subject to the Mozilla Public License Version 
	1.1 (the "License"); you may not use this file except in compliance with 
	the License. You may obtain a copy of the License at 
	http://www.mozilla.org/MPL/
	
	Software distributed under the License is distributed on an "AS IS" basis,
	WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
	for the specific language governing rights and limitations under the
	License.
	
	The Original Code is the SA:MP script information include.
	
	The Initial Developer of the Original Code is Alex "Y_Less" Cole.
	Portions created by the Initial Developer are Copyright (C) 2008
	the Initial Developer. All Rights Reserved.
	
	Contributors:
		ZeeX, koolk
	
	Thanks:
		Peter, Cam - Support.
		ZeeX - Very productive conversations.
		koolk - IsPlayerinAreaEx code.
		TheAlpha - Danish translation.
		breadfish - German translation.
		Fireburn - Dutch translation.
		yom - French translation.
		50p - Polish translation.
		Zamaroht - Spanish translation.
		Dracoblue, sintax, mabako, Xtreme, other coders - Producing other modes
			for me to strive to better.
		Pixels^ - Running XScripters where the idea was born.
		Matite - Pestering me to release it and using it.
	
	Very special thanks to:
		Thiadmer - PAWN.
		Kye/Kalcor - SA:MP.
		SA:MP Team past, present and future - SA:MP.
Version:
	1.0
Changelog:
	06/08/10:
		First version
-*----------------------------------------------------------------------------*/

#include <YSI\internal\y_version>

#define ALS_PREFIX TD
#include <YSI\y_als>

#include <YSI\y_debug>
#include <YSI\y_bit>

#include <YSI\y_xml>

#include <YSI\y_utils>
#include <YSI\y_colours>

#include <foreach>

//#include <YSI\y_timer>

#include <a_samp>

#if !defined MAX_TEXT_DRAW_STYLES
	#define MAX_TEXT_DRAW_STYLES        (Style:32)
#endif

#define MAX_TEXT_DRAW_LINE              (128)
#define TEXT_DRAW_NO_NEXT               (Text:-1)

#define TEXT_DRAW_NAN                   (0xFFFFFFFF)

//#define TEXT_DRAW_NO_STYLE_NAME

#tryinclude <sscanf2>

enum td_align
{
	td_align_none,
	td_align_left,
	td_align_center,
	td_align_centre = td_align_center,
	td_align_right
}

enum e_TD_BITS (<<= 1)
{
	e_TD_BITS_SHADOW = 0x000000FF,
	e_TD_BITS_OUTLINE = 0x0000FF00,
	e_TD_BITS_ALIGN = 0x000F0000,
	e_TD_BITS_FONT = 0x00F00000,
	e_TD_BITS_BOX = 0x01000000,
	e_TD_BITS_PROP
}

enum E_TD_DATA
{
	#if !defined TEXT_DRAW_NO_STYLE_NAME
		E_TD_DATA_NAME[MAX_XML_ENTRY_NAME char],
	#endif
	E_TD_DATA_HASH,
	Float:E_TD_DATA_X,
	Float:E_TD_DATA_Y,
	Float:E_TD_DATA_LX,
	Float:E_TD_DATA_LY,
	Float:E_TD_DATA_TX,
	Float:E_TD_DATA_TY,
	E_TD_DATA_COLOUR,
	e_TD_BITS:E_TD_DATA_BITS,
	E_TD_DATA_BOX,
	E_TD_DATA_BG,
	E_TD_DATA_TIME,
	Text:E_TD_DATA_USE,
	E_TD_DATA_UPDATE
}

enum E_TD_DISPLAY
{
	Float:E_TD_DISPLAY_X,
	Float:E_TD_DISPLAY_Y,
	Text:E_TD_DISPLAY_NEXT,
	Style:E_TD_DISPLAY_STYLE,
	E_TD_DISPLAY_LIFE,
	Text:E_TD_DISPLAY_REAL,
	E_TD_DISPLAY_REVISION,
	E_TD_DISPLAY_TEXT[MAX_TEXT_DRAW_LINE char]
}

forward TD_LoadColour();
forward TD_Textdraw();
forward TD_HideForPlayerPub(playerid, Text:textDraw, revision);

static stock
	XML:YSI_g_sXMLRules = NO_XML_FILE,
	YSI_g_sTDData[MAX_TEXT_DRAW_STYLES][E_TD_DATA],
	YSI_g_sTDDisplay[Text:MAX_TEXT_DRAWS][E_TD_DISPLAY],
	//YSI_g_sTDTimers[Text:MAX_TEXT_DRAWS][MAX_PLAYERS],
	// This is actually dual purpose.
	Text:YSI_g_sUnused,
	BitArray:YSI_g_sPlayerDraws[MAX_PLAYERS]<MAX_TEXT_DRAWS>;
	//Bit:YSI_g_sPlayerDraws[MAX_PLAYERS][Bit_Bits(MAX_TEXT_DRAWS)];

ALS_DATA<>

//static stock TD_SetTimer(playerid, Text:td, time, revision)
//{
//	SetTimerEx("TD_HideForPlayer", time, 0, "iii", playerid, _:td, revision);
//}

#define TD_SetTimer(%0,%1,%2,%3) SetTimerEx("TD_HideForPlayerPub", (%2), 0, "iii", (%0), _:(%1), (%3))

/*----------------------------------------------------------------------------*-
Function:
	TD_IsValidStyle
Params:
	Style:id - Text draw style to check validity of,
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

#define TD_IsValidStyle(%1) \
	(Style:0 <= (%1) < MAX_TEXT_DRAW_STYLES && YSI_g_sTDData[(%1)][E_TD_DATA_HASH])

#define _TD_IsValid(%1) \
	((%1) < MAX_TEXT_DRAW_STYLES && YSI_g_sTDData[(%1)][E_TD_DATA_HASH])

#define _TD_TextValid(%0) \
	(Text:0 <= (%0) < Text:MAX_TEXT_DRAWS && YSI_g_sTDDisplay[(%0)][E_TD_DISPLAY_TEXT][0])

/*----------------------------------------------------------------------------*-
Function:
	TD_TD
Params:
	-
Return:
	-
Notes:
	Constructor.
-*----------------------------------------------------------------------------*/

#if defined FILTERSCRIPT
	public OnFilterScriptInit()
#else
	public OnGameModeInit()
#endif
{
	if (YSI_g_sXMLRules == NO_XML_FILE)
	{
		YSI_g_sXMLRules = XML_New();
		if (YSI_g_sXMLRules != NO_XML_FILE)
		{
			XML_AddHandler(YSI_g_sXMLRules, "color", "TD_LoadColour");
			XML_AddHandler(YSI_g_sXMLRules, "colour", "TD_LoadColour");
			XML_AddHandler(YSI_g_sXMLRules, "textdraw", "TD_Textdraw");
			//XML_AddHandler(YSI_g_sXMLRules, "box", "TD_Box");
			//XML_AddHandler(YSI_g_sXMLRules, "background", "TD_Background");
			//XML_AddHandler(YSI_g_sXMLRules, "style", "TD_Style");
		}
	}
	for (new Text:i; Text:i < Text:MAX_TEXT_DRAWS; i++)
	{
		YSI_g_sTDDisplay[i][E_TD_DISPLAY_REAL] = Text:INVALID_TEXT_DRAW;
		YSI_g_sTDDisplay[i][E_TD_DISPLAY_NEXT] = i + Text:1;
	}
	YSI_g_sTDDisplay[Text:(MAX_TEXT_DRAWS - 1)][E_TD_DISPLAY_NEXT] = TEXT_DRAW_NO_NEXT;
	ALS_DETECT<PlayerDisconnect>
	CallLocalFunction("TD_OnScriptInit", "");
	return 1;
}

#if defined FILTERSCRIPT
	#if defined _ALS_OnFilterScriptInit
		#undef OnFilterScriptInit
	#else
		#define _ALS_OnFilterScriptInit
	#endif
	#define OnFilterScriptInit TD_OnScriptInit
#else
	#if defined _ALS_OnGameModeInit
		#undef OnGameModeInit
	#else
		#define _ALS_OnGameModeInit
	#endif
	#define OnGameModeInit TD_OnScriptInit
#endif
forward TD_OnScriptInit();

/*----------------------------------------------------------------------------*-
Function:
	TD_Parse
Params:
	filename[] - File to parse as a textdraw data file.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock TD_Parse(filename[])
{
	return XML_Parse(YSI_g_sXMLRules, filename);
}

/*----------------------------------------------------------------------------*-
Function:
	TD_LoadColour
Params:
	-
Return:
	-
Notes:
	XML callback for loading the <colour> tag.
-*----------------------------------------------------------------------------*/

public TD_LoadColour()
{
	P:2("TD_LoadColour called");
	static
		name[MAX_XML_ENTRY_NAME],
		val[MAX_XML_ENTRY_TEXT];
	new
		colour,
		hash;
	while (XML_GetKeyValue(name, val))
	{
		if (!strcmp(name, "name", true))
		{
			hash = COLOUR_NAME_HASH(val);
		}
		else if (!strcmp(name, "hex", true))
		{
			#if defined _inc_sscanf2
				unformat(val, "x", colour);
			#else
				colour = hexstr(val);
			#endif
		}
		else if (!strcmp(name, "value", true))
		{
			#if defined _inc_sscanf2
				if (unformat(val, "n", colour))
			#else
				if (ishex(val)) colour = hexstr(val);
				else if (isnumeric(val)) colour = strval(val);
				else
			#endif
					colour = GetColour(val);
		}
	}
	//if (hash) Text_SetColour(hash, colour);
	if (hash) SetColourHash(hash, colour);
	return colour;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_Create
Params:
	Float:x - X position the text will appear at.
	Float:y - Y position the text will appear at,
	Float:letterX - Letter X size.
	Float:letterY - Letter Y size.
	Float:textX - Box X size.
	Float:textY - Box Y size.
	colour - Text colour.
	boxColour - Colour of the text box.
	bgColour - Colour of the text background.
	shadow - Text shadow size.
	outline - Text outline size.
	align - Text alignment.
	font - Text font style.
	bool:proportional - Wether to make the text proportional.
	bool:box - Wether to use a box.
	time - Time for the text to display in ms (0 = infinate).
	name[] - Name of the style.
Return:
	-
Notes:
	Creates a text draw style structure according to given
	parameters, can be used to display any text in the given
	style without repeated redefinitions.
-*----------------------------------------------------------------------------*/

stock Style:TD_Create(Float:x = 0.0, Float:y = 0.0, Float:letterX = 0.48, Float:letterY = 1.12, Float:textX = 1280.0, Float:textY = 1280.0, colour = 0xE1E1E1FF, boxColour = 0x80808080, bgColour = 0x000000FF, shadow = 2, outline = 0, align = _:td_align_none, font = 1, bool:proportional = false, bool:box = false, time = 0, name[] = "\1")
{
	new
		Style:i;
	while (_TD_IsValid(i))
	{
		++i;
	}
	if (i == MAX_TEXT_DRAW_STYLES)
	{
		return MAX_TEXT_DRAW_STYLES;
	}
	#if !defined TEXT_DRAW_NO_STYLE_NAME
		strpack(YSI_g_sTDData[i][E_TD_DATA_NAME], name, MAX_XML_ENTRY_NAME);
	#endif
	YSI_g_sTDData[i][E_TD_DATA_HASH] = bernstein(name);
	YSI_g_sTDData[i][E_TD_DATA_X] = x;
	YSI_g_sTDData[i][E_TD_DATA_Y] = y;
	YSI_g_sTDData[i][E_TD_DATA_LX] = letterX;
	YSI_g_sTDData[i][E_TD_DATA_LY] = letterY;
	YSI_g_sTDData[i][E_TD_DATA_TX] = textX;
	YSI_g_sTDData[i][E_TD_DATA_TY] = textY;
	YSI_g_sTDData[i][E_TD_DATA_COLOUR] = colour;
	YSI_g_sTDData[i][E_TD_DATA_BITS] =
		((box) ? (e_TD_BITS_BOX) : (e_TD_BITS:0)) |
		((proportional) ? (e_TD_BITS_PROP) : (e_TD_BITS:0)) |
		(e_TD_BITS:(shadow << 0) & e_TD_BITS_SHADOW) |
		(e_TD_BITS:(outline << 8) & e_TD_BITS_OUTLINE) |
		(e_TD_BITS:(align << 16) & e_TD_BITS_ALIGN) |
		(e_TD_BITS:(font << 20) & e_TD_BITS_FONT);
	YSI_g_sTDData[i][E_TD_DATA_BOX] = boxColour;
	YSI_g_sTDData[i][E_TD_DATA_BG] = bgColour;
	YSI_g_sTDData[i][E_TD_DATA_TIME] = time;
	YSI_g_sTDData[i][E_TD_DATA_USE] = TEXT_DRAW_NO_NEXT;
	YSI_g_sTDData[i][E_TD_DATA_UPDATE] = -1;
	return Style:i;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_Textdraw
Params:
	-
Return:
	-
Notes:
	XML callback for loading the <textdraw> tag.
-*----------------------------------------------------------------------------*/

public TD_Textdraw()
{
	// Set all the default values quickly.
	new
		Style:i = TD_Create();
	if (i != MAX_TEXT_DRAW_STYLES)
	{
		static
			name[MAX_XML_ENTRY_NAME],
			val[MAX_XML_ENTRY_TEXT];
		new
			e_TD_BITS:bits,
			// Bernstein hash of 1.
			hash = -32;
		// !"\1"
		//YSI_g_sTDData[i][E_TD_DATA_NAME] = 0x01000000;
		while (XML_GetKeyValue(name, val))
		{
			if (!strcmp(name, "x", true))
			{
				YSI_g_sTDData[i][E_TD_DATA_X] = floatstr(val);
			}
			else if (!strcmp(name, "y", true))
			{
				YSI_g_sTDData[i][E_TD_DATA_Y] = floatstr(val);
			}
			else if (!strcmp(name, "letterx", true))
			{
				YSI_g_sTDData[i][E_TD_DATA_LX] = floatstr(val);
			}
			else if (!strcmp(name, "lettery", true))
			{
				YSI_g_sTDData[i][E_TD_DATA_LY] = floatstr(val);
			}
			else if (!strcmp(name, "textx", true))
			{
				YSI_g_sTDData[i][E_TD_DATA_TX] = floatstr(val);
			}
			else if (!strcmp(name, "texty", true))
			{
				YSI_g_sTDData[i][E_TD_DATA_TY] = floatstr(val);
			}
			else if (!strcmp(name, "alignment", true))
			{
				bits &= ~e_TD_BITS_ALIGN;
				if (!strcmp(val, "left", true)) bits |= e_TD_BITS:(_:td_align_left << 16) & e_TD_BITS_ALIGN;
				else if (!strcmp(val, "right", true)) bits |= e_TD_BITS:(_:td_align_right << 16) & e_TD_BITS_ALIGN;
				else if (!strcmp(val, "center", true) || !strcmp(val, "centre", true)) bits |= e_TD_BITS:(_:td_align_center << 16) & e_TD_BITS_ALIGN;
			}
			else if (!strcmp(name, "color", true) || !strcmp(name, "colour", true))
			{
				P:2("TD_Textdraw: colour called");
				// This could now be done with the sscanf "n" type for "number".
				#if defined _inc_sscanf2
					new
						colour;
					if (!unformat(val, "n", colour)) YSI_g_sTDData[i][E_TD_DATA_COLOUR] = colour;
				#else
					if (ishex(val)) YSI_g_sTDData[i][E_TD_DATA_COLOUR] = hexstr(val);
					else if (isnumeric(val)) YSI_g_sTDData[i][E_TD_DATA_COLOUR] = strval(val);
				#endif
					else YSI_g_sTDData[i][E_TD_DATA_COLOUR] = GetColour(val);
			}
			else if (!strcmp(name, "box", true))
			{
				new
					box = strval(val);
				if (box)
				{
					bits |= e_TD_BITS_BOX;
					YSI_g_sTDData[i][E_TD_DATA_BOX] = box;
				}
			}
			else if (!strcmp(name, "shadow", true))
			{
				bits = (bits & ~e_TD_BITS_SHADOW) | (e_TD_BITS:(strval(val)) & e_TD_BITS_SHADOW);
			}
			else if (!strcmp(name, "outline", true))
			{
				bits = (bits & ~e_TD_BITS_OUTLINE) | (e_TD_BITS:(strval(val) << 8) & e_TD_BITS_OUTLINE);
			}
			else if (!strcmp(name, "background", true))
			{
				#if defined _inc_sscanf2
					new
						colour;
					if (!unformat(val, "n", colour)) YSI_g_sTDData[i][E_TD_DATA_BG] = colour;
				#else
					if (ishex(val)) YSI_g_sTDData[i][E_TD_DATA_BG] = hexstr(val);
					else if (isnumeric(val)) YSI_g_sTDData[i][E_TD_DATA_BG] = strval(val);
				#endif
					else YSI_g_sTDData[i][E_TD_DATA_BG] = GetColour(val);
					P:5("TD_Textdraw(): Background color: \"%s\", %d, %d: 0x%04x%04x", val, ishex(val), isnumeric(val), YSI_g_sTDData[i][E_TD_DATA_BG] >>> 16, YSI_g_sTDData[i][E_TD_DATA_BG] & 0xFFFF);
			}
			else if (!strcmp(name, "font", true))
			{
				bits = (bits & ~e_TD_BITS_FONT) | (e_TD_BITS:(strval(val) << 20) & e_TD_BITS_FONT);
			}
			else if (!strcmp(name, "proportional", true))
			{
				bits |= e_TD_BITS_PROP;
			}
			else if (!strcmp(name, "time", true))
			{
				YSI_g_sTDData[i][E_TD_DATA_TIME] = strval(val);
			}
			else if (!strcmp(name, "name", true))
			{
				#if !defined TEXT_DRAW_NO_STYLE_NAME
					strpack(YSI_g_sTDData[i][E_TD_DATA_NAME], val, MAX_XML_ENTRY_NAME);
				#endif
				hash = bernstein(val);
			}
		}
		YSI_g_sTDData[i][E_TD_DATA_BITS] = bits;
		/*if (!(YSI_g_sTDData[i][E_TD_DATA_NAME] & 0xFF000000))
		{
			YSI_g_sTDData[i][E_TD_DATA_NAME] = 0x01000000;
		}*/
		//YSI_g_sTDData[i][E_TD_DATA_HASH] = bernstein(YSI_g_sTDData[i][E_TD_DATA_NAME]);
		YSI_g_sTDData[i][E_TD_DATA_HASH] = hash;
		P:5("TD data: %.2f %.2f %.2f %.2f %.2f %.2f %x %d %x %d %d", YSI_g_sTDData[i][E_TD_DATA_X], YSI_g_sTDData[i][E_TD_DATA_Y], YSI_g_sTDData[i][E_TD_DATA_LX], YSI_g_sTDData[i][E_TD_DATA_LY], YSI_g_sTDData[i][E_TD_DATA_TX], YSI_g_sTDData[i][E_TD_DATA_TY], YSI_g_sTDData[i][E_TD_DATA_COLOUR], YSI_g_sTDData[i][E_TD_DATA_BOX], YSI_g_sTDData[i][E_TD_DATA_BG], YSI_g_sTDData[i][E_TD_DATA_TIME], YSI_g_sTDData[i][E_TD_DATA_BITS]);//, YSI_g_sTDData[i][E_TD_DATA_NAME]);
	}
	return _:i;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_GetID
Params:
	hash - Hash of a style name to get a style index for.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock Style:TD_GetID(hash)
{
	new
		Style:i;
	while (i != MAX_TEXT_DRAW_STYLES && YSI_g_sTDData[i][E_TD_DATA_HASH] != hash)
	{
		++i;
	}
	return i;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_Create
Params:
	Style:styleID - Style to clone.
	name[] - Name of the new style.
Return:
	-
Notes:
	Copies a text draw style and returns the new handle.
-*----------------------------------------------------------------------------*/
//#if 0
stock Style:TD_Clone(Style:styleID, name[] = "\1")
{
	if (!TD_IsValidStyle(styleID))
	{
		return MAX_TEXT_DRAW_STYLES;
	}
	new
		Style:i;
	while (_TD_IsValid(i))
	{
		i++;
	}
	if (i == MAX_TEXT_DRAW_STYLES)
	{
		return MAX_TEXT_DRAW_STYLES;
	}
	#if !defined TEXT_DRAW_NO_STYLE_NAME
		strpack(YSI_g_sTDData[i][E_TD_DATA_NAME], name, MAX_XML_ENTRY_NAME);
	#endif
	YSI_g_sTDData[i][E_TD_DATA_HASH] = bernstein(name);
	// memcpy?
	YSI_g_sTDData[i][E_TD_DATA_X] = YSI_g_sTDData[styleID][E_TD_DATA_X];
	YSI_g_sTDData[i][E_TD_DATA_Y] = YSI_g_sTDData[styleID][E_TD_DATA_Y];
	YSI_g_sTDData[i][E_TD_DATA_LX] = YSI_g_sTDData[styleID][E_TD_DATA_LX];
	YSI_g_sTDData[i][E_TD_DATA_LY] = YSI_g_sTDData[styleID][E_TD_DATA_LY];
	YSI_g_sTDData[i][E_TD_DATA_TX] = YSI_g_sTDData[styleID][E_TD_DATA_TX];
	YSI_g_sTDData[i][E_TD_DATA_TY] = YSI_g_sTDData[styleID][E_TD_DATA_TY];
	YSI_g_sTDData[i][E_TD_DATA_COLOUR] = YSI_g_sTDData[styleID][E_TD_DATA_COLOUR];
	YSI_g_sTDData[i][E_TD_DATA_BITS] = YSI_g_sTDData[styleID][E_TD_DATA_BITS];
	YSI_g_sTDData[i][E_TD_DATA_BOX] = YSI_g_sTDData[styleID][E_TD_DATA_BOX];
	YSI_g_sTDData[i][E_TD_DATA_BG] = YSI_g_sTDData[styleID][E_TD_DATA_BG];
	YSI_g_sTDData[i][E_TD_DATA_TIME] = YSI_g_sTDData[styleID][E_TD_DATA_TIME];
	YSI_g_sTDData[i][E_TD_DATA_USE] = TEXT_DRAW_NO_NEXT;
	YSI_g_sTDData[i][E_TD_DATA_UPDATE] = -1;
	return Style:i;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_Name
Params:
	Style:styleID - Style to modify.
	name[] - Name to give the style.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock TD_Name(Style:styleID, name[])
{
	if (!TD_IsValidStyle(styleID))
	{
		return 0;
	}
	#if !defined TEXT_DRAW_NO_STYLE_NAME
		strpack(YSI_g_sTDData[styleID][E_TD_DATA_NAME], name, MAX_XML_ENTRY_NAME);
	#endif
	YSI_g_sTDData[styleID][E_TD_DATA_HASH] = bernstein(name);
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_TextPosition
Params:
	Text:textID - Text to modify.
	Float:x - New horizontal position.
	Float:y - New vertical position.
Return:
	-
Notes:
	Moves a single bit of text, not all with a style.
-*----------------------------------------------------------------------------*/

stock TD_TextPosition(Text:textID, Float:x, Float:y)
{
	if (!_TD_TextValid(textID))
	{
		return 0;
	}
	YSI_g_sTDDisplay[textID][E_TD_DISPLAY_X] = x;
	YSI_g_sTDDisplay[textID][E_TD_DISPLAY_Y] = y;
	TD_UpdateOne(textID, YSI_g_sTDDisplay[textID][E_TD_DISPLAY_STYLE]);
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_TextXPos
Params:
	Text:textID - Text to modify.
	Float:x - New horizontal position.
Return:
	-
Notes:
	Moves a single bit of text, not all with a style.
-*----------------------------------------------------------------------------*/

stock TD_TextXPos(Text:textID, Float:x)
{
	if (!_TD_TextValid(textID))
	{
		return 0;
	}
	YSI_g_sTDDisplay[textID][E_TD_DISPLAY_X] = x;
	TD_UpdateOne(textID, YSI_g_sTDDisplay[textID][E_TD_DISPLAY_STYLE]);
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_TextYPos
Params:
	Text:textID - Text to modify.
	Float:y - New vertical position.
Return:
	-
Notes:
	Moves a single bit of text, not all with a style.
-*----------------------------------------------------------------------------*/

stock TD_TextYPos(Text:textID, Float:y)
{
	if (!_TD_TextValid(textID))
	{
		return 0;
	}
	YSI_g_sTDDisplay[textID][E_TD_DISPLAY_Y] = y;
	TD_UpdateOne(textID, YSI_g_sTDDisplay[textID][E_TD_DISPLAY_STYLE]);
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_StylePosition
Params:
	Style:styleID - Style to modify.
	Float:x - New horizontal position.
	Float:y - New vertical position.
	bool:update - Wether to update the appearence for players.
Return:
	-
Notes:
	Update is default false to not modify moved texts.
-*----------------------------------------------------------------------------*/

stock TD_StylePosition(Style:styleID, Float:x, Float:y)
{
	if (!TD_IsValidStyle(styleID))
	{
		return 0;
	}
	YSI_g_sTDData[styleID][E_TD_DATA_X] = x;
	YSI_g_sTDData[styleID][E_TD_DATA_Y] = y;
	if (update) TD_Update(styleID, true);
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_StyleXPos
Params:
	Style:styleID - Style to modify.
	Float:x - New horizontal position.
	bool:update - Wether to update the appearence for players.
Return:
	-
Notes:
	Update is default false to not modify moved texts.
-*----------------------------------------------------------------------------*/

stock TD_StyleXPos(Style:styleID, Float:x)
{
	if (!TD_IsValidStyle(styleID))
	{
		return 0;
	}
	YSI_g_sTDData[styleID][E_TD_DATA_X] = x;
	if (update) TD_Update(styleID, true);
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_StyleYPos
Params:
	Style:styleID - Style to modify.
	Float:y - New vertical position.
	bool:update - Wether to update the appearence for players.
Return:
	-
Notes:
	Update is default false to not modify moved texts.
-*----------------------------------------------------------------------------*/

stock TD_StyleYPos(Style:styleID, Float:y)
{
	if (!TD_IsValidStyle(styleID))
	{
		return 0;
	}
	YSI_g_sTDData[styleID][E_TD_DATA_Y] = y;
	if (update) TD_Update(styleID, true);
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_LetterSize
Params:
	Style:styleID - Style to modify.
	Float:x - New letter width.
	Float:y - New letter height.
	bool:update - Wether to update the appearence for players.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock TD_LetterSize(Style:styleID, Float:x, Float:y)
{
	if (!TD_IsValidStyle(styleID))
	{
		return 0;
	}
	YSI_g_sTDData[styleID][E_TD_DATA_LX] = x;
	YSI_g_sTDData[styleID][E_TD_DATA_LY] = y;
	TD_Update(styleID);
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_LetterX
Params:
	Style:styleID - Style to modify.
	Float:x - New letter width.
	bool:update - Wether to update the appearence for players.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock TD_LetterX(Style:styleID, Float:x)
{
	if (!TD_IsValidStyle(styleID))
	{
		return 0;
	}
	YSI_g_sTDData[styleID][E_TD_DATA_LX] = x;
	TD_Update(styleID);
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_LetterY
Params:
	Style:styleID - Style to modify.
	Float:y - New letter height.
	bool:update - Wether to update the appearence for players.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock TD_LetterY(Style:styleID, Float:y)
{
	if (!TD_IsValidStyle(styleID))
	{
		return 0;
	}
	YSI_g_sTDData[styleID][E_TD_DATA_LY] = y;
	TD_Update(styleID);
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_TextSize
Params:
	Style:styleID - Style to modify.
	Float:x - New text width.
	Float:y - New text height.
	bool:update - Wether to update the appearence for players.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock TD_TextSize(Style:styleID, Float:x, Float:y)
{
	if (!TD_IsValidStyle(styleID))
	{
		return 0;
	}
	YSI_g_sTDData[styleID][E_TD_DATA_TX] = x;
	YSI_g_sTDData[styleID][E_TD_DATA_TY] = y;
	TD_Update(styleID);
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_TextX
Params:
	Style:styleID - Style to modify.
	Float:x - New text width.
	bool:update - Wether to update the appearence for players.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock TD_TextX(Style:styleID, Float:x)
{
	if (!TD_IsValidStyle(styleID))
	{
		return 0;
	}
	YSI_g_sTDData[styleID][E_TD_DATA_TX] = x;
	TD_Update(styleID);
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_TextY
Params:
	Style:styleID - Style to modify.
	Float:y - New text height.
	bool:update - Wether to update the appearence for players.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock TD_TextY(Style:styleID, Float:y)
{
	if (!TD_IsValidStyle(styleID))
	{
		return 0;
	}
	YSI_g_sTDData[styleID][E_TD_DATA_TY] = y;
	TD_Update(styleID);
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_Alignment
Params:
	Style:styleID - Style to modify.
	alignment - Where to align the text in it's box.
	bool:update - Wether to update the appearence for players.
Return:
	-
Notes:
	Designed to take ta_align enum values and numbers.
-*----------------------------------------------------------------------------*/

stock TD_Alignment(Style:styleID, alignment = _:td_align_none)
{
	if (!TD_IsValidStyle(styleID))
	{
		return 0;
	}
	YSI_g_sTDData[styleID][E_TD_DATA_BITS] = (YSI_g_sTDData[styleID][E_TD_DATA_BITS] & ~e_TD_BITS_ALIGN) | (e_TD_BITS:(alignment << 16) & e_TD_BITS_ALIGN);
	TD_Update(styleID);
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_Colour
Params:
	Style:styleID - Style to modify.
	colour - New text colour.
	bool:update - Wether to update the appearence for players.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock TD_Colour(Style:styleID, colour)
{
	if (!TD_IsValidStyle(styleID))
	{
		return 0;
	}
	YSI_g_sTDData[styleID][E_TD_DATA_COLOUR] = colour;
	TD_Update(styleID);
	return 1;
}

#define TD_Color TD_Colour

/*----------------------------------------------------------------------------*-
Function:
	TD_UseBox
Params:
	Style:styleID - Style to modify.
	bool:use - Wether or not to show a box round the text.
	bool:update - Wether to update the appearence for players.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock TD_UseBox(Style:styleID, bool:use)
{
	if (!TD_IsValidStyle(styleID))
	{
		return 0;
	}
	if (use) YSI_g_sTDData[styleID][E_TD_DATA_BITS] |= e_TD_BITS_BOX;
	else YSI_g_sTDData[styleID][E_TD_DATA_BITS] &= ~e_TD_BITS_BOX;
	TD_Update(styleID);
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_BoxColour
Params:
	Style:styleID - Style to modify.
	colour - New box colour.
	bool:update - Wether to update the appearence for players.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock TD_BoxColour(Style:styleID, colour)
{
	if (!TD_IsValidStyle(styleID))
	{
		return 0;
	}
	YSI_g_sTDData[styleID][E_TD_DATA_BOX] = colour;
	TD_Update(styleID);
	return 1;
}

#define TD_BoxColor TD_BoxColour

/*----------------------------------------------------------------------------*-
Function:
	TD_SetShadow
Params:
	Style:styleID - Style to modify.
	size - Size of the letter shadow,
	bool:update - Wether to update the appearence for players.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock TD_SetShadow(Style:styleID, size)
{
	if (!TD_IsValidStyle(styleID))
	{
		return 0;
	}
	YSI_g_sTDData[styleID][E_TD_DATA_BITS] = (YSI_g_sTDData[styleID][E_TD_DATA_BITS] & ~e_TD_BITS_SHADOW) | (e_TD_BITS:(size) & e_TD_BITS_SHADOW);
	TD_Update(styleID);
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_SetOutline
Params:
	Style:styleID - Style to modify.
	size - Size of the letter outline.
	bool:update - Wether to update the appearence for players.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock TD_SetOutline(Style:styleID, size)
{
	if (!TD_IsValidStyle(styleID))
	{
		return 0;
	}
	YSI_g_sTDData[styleID][E_TD_DATA_BITS] = (YSI_g_sTDData[styleID][E_TD_DATA_BITS] & ~e_TD_BITS_OUTLINE) | (e_TD_BITS:(size << 8) & e_TD_BITS_OUTLINE);
	TD_Update(styleID);
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_BackgroundColour
Params:
	Style:styleID - Style to modify.
	colour - New background (outline/shadow) colour.
	bool:update - Wether to update the appearence for players.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock TD_BackgroundColour(Style:styleID, colour)
{
	if (!TD_IsValidStyle(styleID))
	{
		return 0;
	}
	YSI_g_sTDData[styleID][E_TD_DATA_BG] = colour;
	TD_Update(styleID);
	return 1;
}

#define TD_BackgroundColor TD_BackgroundColour

/*----------------------------------------------------------------------------*-
Function:
	TD_Font
Params:
	Style:styleID - Style to modify.
	font - New text font style.
	bool:update - Wether to update the appearence for players.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock TD_Font(Style:styleID, font)
{
	if (!TD_IsValidStyle(styleID))
	{
		return 0;
	}
	YSI_g_sTDData[styleID][E_TD_DATA_BITS] = (YSI_g_sTDData[styleID][E_TD_DATA_BITS] & ~e_TD_BITS_FONT) | (e_TD_BITS:(font << 20) & e_TD_BITS_FONT);
	TD_Update(styleID);
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_SetProportional
Params:
	Style:styleID - Style to modify.
	bool:set - Wether to make the letters proportional or not.
	bool:update - Wether to update the appearence for players.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock TD_SetProportional(Style:styleID, bool:set)
{
	if (!TD_IsValidStyle(styleID))
	{
		return 0;
	}
	if (set) YSI_g_sTDData[styleID][E_TD_DATA_BITS] |= e_TD_BITS_PROP;
	else YSI_g_sTDData[styleID][E_TD_DATA_BITS] &= ~e_TD_BITS_PROP;
	TD_Update(styleID);
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_SetTime
Params:
	Style:styleID - Style to modify.
	time - New time for the text to display for.
	existing - Whether or not to change the display of existing text draws.
Return:
	-
Notes:
	Doesn't update existing timed texts, just new ones.  Now does all of them.
-*----------------------------------------------------------------------------*/

stock TD_SetTime(Style:styleID, time, bool:existing = false)
{
	if (!TD_IsValidStyle(styleID))
	{
		return 0;
	}
	YSI_g_sTDData[styleID][E_TD_DATA_TIME] = time;
	if (existing)
	{
		// Hide this after the given time for all players.
		new
			Text:next = YSI_g_sTDData[styleId][E_TD_DATA_USE],
			Text:last = TEXT_DRAW_NO_NEXT;
		while (next != TEXT_DRAW_NO_NEXT)
		{
			// DO update the revision here!
			new
				index = Bit_Slot(next),
				Bit:mod = Bit_Mask(next),
				revision = ++YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_REVISION];
			foreach (Player, playerid)
			{
				if (YSI_g_sPlayerDraws[playerid][index] & mod)
				{
					TD_SetTimer(playerid, next, time, revision);
				}
			}
			last = next;
			next = YSI_g_sTDDisplay[next][E_TD_DISPLAY_NEXT];
		}
	}
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	Text:TD_Render
Params:
	text[] - String to output.
	Style:id - Text draw style to render the text in.
	Text:slot - the slot the text is stored in.
Return:
	TextDraw id.
Notes:
	Basically the application layer, creates a text_draw with the
	saved data.
-*----------------------------------------------------------------------------*/

static stock Text:TD_Render(text[], Style:id, Text:slot)
{
	new
		Text:textDraw = TextDrawCreate(YSI_g_sTDDisplay[slot][E_TD_DISPLAY_X], YSI_g_sTDDisplay[slot][E_TD_DISPLAY_Y], text);
	if (textDraw != Text:INVALID_TEXT_DRAW)
	{
		new
			e_TD_BITS:bits = YSI_g_sTDData[id][E_TD_DATA_BITS];
		TextDrawLetterSize(textDraw, YSI_g_sTDData[id][E_TD_DATA_LX], YSI_g_sTDData[id][E_TD_DATA_LY]);
		TextDrawTextSize(textDraw, YSI_g_sTDData[id][E_TD_DATA_TX], YSI_g_sTDData[id][E_TD_DATA_TY]);
		TextDrawAlignment(textDraw, _:(bits & e_TD_BITS_ALIGN) >> 16);
		TextDrawColor(textDraw, YSI_g_sTDData[id][E_TD_DATA_COLOUR]);
		TextDrawUseBox(textDraw, (bits & e_TD_BITS_BOX) ? 1 : 0);
		TextDrawBoxColor(textDraw, YSI_g_sTDData[id][E_TD_DATA_BOX]);
		TextDrawSetShadow(textDraw, _:(bits & e_TD_BITS_SHADOW));
		TextDrawSetOutline(textDraw, _:(bits & e_TD_BITS_OUTLINE) >> 8);
		TextDrawBackgroundColor(textDraw, YSI_g_sTDData[id][E_TD_DATA_BG]);
		TextDrawFont(textDraw, _:(bits & e_TD_BITS_FONT) >> 20);
		TextDrawSetProportional(textDraw, (bits & e_TD_BITS_PROP) ? 1 : 0);
	}
	return textDraw;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_Update
Params:
	Style:id - Style to update for players.
	bool:pos - Wether or not to update children's positions.
Return:
	-
Notes:
	Loops through all texts displayed using the current render
	style and updates their real display.
-*----------------------------------------------------------------------------*/

stock TD_Update(Style:id, bool:pos = false)
{
	if (!TD_IsValidStyle(id))
	{
		return;
	}
	new
		Text:next = YSI_g_sTDData[id][E_TD_DATA_USE],
		Float:x,
		Float:y;
	if (pos)
	{
		x = YSI_g_sTDData[id][E_TD_DATA_X],
		y = YSI_g_sTDData[id][E_TD_DATA_Y];
	}
	while (next != TEXT_DRAW_NO_NEXT)
	{
		if (pos)
		{
			YSI_g_sTDDisplay[next][E_TD_DISPLAY_X] = x;
			YSI_g_sTDDisplay[next][E_TD_DISPLAY_Y] = y;
		}
		//TD_UpdateOne(next, id);
		next = YSI_g_sTDDisplay[next][E_TD_DISPLAY_NEXT];
	}
	// Update the apperance after a load of updates have been applied.
	if (YSI_g_sTDData[id][E_TD_DATA_UPDATE] == -1)
	{
		YSI_g_sTDData[id][E_TD_DATA_UPDATE] = SetTimerEx("TD_UpdateInternal", 1, 0, "i", _:id);
	}
}

forward TD_UpdateInternal(Style:id);

public TD_UpdateInternal(Style:id)
{
	new
		Text:next = YSI_g_sTDData[id][E_TD_DATA_USE];
	while (next != TEXT_DRAW_NO_NEXT)
	{
		TD_UpdateOne(next, id);
		next = YSI_g_sTDDisplay[next][E_TD_DISPLAY_NEXT];
	}
}

/*----------------------------------------------------------------------------*-
Function:
	TD_UpdateOne
Params:
	Text:slot - Text to update.
	Style:id - Style to use.
Return:
	-
Notes:
	Updates a single text's appearance.  Modified to use a timer with a delay of
	1ms, to be called after the current slew of updates.  This means that doing
	a whole load of modifications at once will all be committed to players at
	the same time.  This used to be done with the optional "update" parameter.
-*----------------------------------------------------------------------------*/

stock TD_UpdateOne(Text:slot, Style:id)
{
	// DON'T update the revision in here - if you show a TD to a player for 5
	// seconds and change it after 2, they should just get the new version for
	// 3 seconds, it shouldn't reset the timer.
	new
		Text:real = YSI_g_sTDDisplay[slot][E_TD_DISPLAY_REAL];
	TextDrawDestroy(real);
	real = TD_Render(YSI_g_sTDDisplay[slot][E_TD_DISPLAY_TEXT], id, slot);
	YSI_g_sTDDisplay[slot][E_TD_DISPLAY_REAL] = real;
	if (real != Text:INVALID_TEXT_DRAW)
	{
		new
			index = Bit_Slot(slot),
			Bit:mod = Bit_Mask(slot);
		foreach (Player, playerid)
		{
			if (YSI_g_sPlayerDraws[playerid][index] & mod)
			{
				TextDrawShowForPlayer(playerid, real);
			}
		}
	}
}

/*----------------------------------------------------------------------------*-
Function:
	TD_Delete
Params:
	styleId - Text draw style ID you want to remove.
Return:
	-
Notes:
	Just nulls the name to remove it's active marker.
-*----------------------------------------------------------------------------*/

stock TD_Delete(Style:styleId)
{
	if (!TD_IsValidStyle(styleId))
	{
		return 0;
	}
	if (YSI_g_sTDData[styleId][E_TD_DATA_UPDATE] != -1)
	{
		KillTimer(YSI_g_sTDData[styleId][E_TD_DATA_UPDATE]);
		YSI_g_sTDData[styleId][E_TD_DATA_UPDATE] = -1;
	}
	new
		Text:next = YSI_g_sTDData[styleId][E_TD_DATA_USE],
		Text:last = TEXT_DRAW_NO_NEXT;
	// Loop through all the TDs using this style.
	while (next != TEXT_DRAW_NO_NEXT)
	{
		TextDrawDestroy(YSI_g_sTDDisplay[next][E_TD_DISPLAY_REAL]);
		YSI_g_sTDDisplay[next][E_TD_DISPLAY_REAL] = Text:INVALID_TEXT_DRAW;
		YSI_g_sTDDisplay[next][E_TD_DISPLAY_TEXT][0] = '\0';
		++YSI_g_sTDDisplay[next][E_TD_DISPLAY_REVISION];
		new
			index = Bit_Slot(next),
			Bit:mod = ~Bit_Mask(next);
		foreach (Player, playerid)
		{
			// TODO: Update.
			/*if (YSI_g_sTDTimers[next][playerid])
			{
				KillTimer(YSI_g_sTDTimers[next][playerid]);
			}
			YSI_g_sTDTimers[next][playerid] = 0;*/
			// Kill the update timer.
			// Mark this player as not having this TD.
			YSI_g_sPlayerDraws[playerid][index] &= mod;
		}
		last = next;
		next = YSI_g_sTDDisplay[next][E_TD_DISPLAY_NEXT];
	}
	// Add the entire style list to the unused list at once.
	if (last != TEXT_DRAW_NO_NEXT)
	{
		// There are items to add.
		YSI_g_sTDDisplay[last][E_TD_DISPLAY_NEXT] = YSI_g_sUnused;
		YSI_g_sUnused = YSI_g_sTDData[styleId][E_TD_DATA_USE];
	}
	// Mark the style as unused.
	YSI_g_sTDData[styleId][E_TD_DATA_USE] = TEXT_DRAW_NO_NEXT;
	#if !defined TEXT_DRAW_NO_STYLE_NAME
		YSI_g_sTDData[styleId][E_TD_DATA_NAME] = 0;
	#endif
	YSI_g_sTDData[styleId][E_TD_DATA_HASH] = 0;
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_TryDestroy
Params:
	Text:textDraw - Text draw to destroy safely.
Return:
	-
Notes:
	Destroys this text draw only if it is marked for garbage collection.  It
	does not however check that no-one can see the text draw, so those people
	who can currently see it will loose it.
-*----------------------------------------------------------------------------*/

static stock TD_TryDestroy(Text:textDraw)
{
	// Destroy this if it is marked to be garbage collected.
	if (YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_LIFE] & 0x80000000)
	{
		TD_Destroy(textDraw);
		return 1;
	}
	return 0;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_Destroy
Params:
	Text:textDraw - Text draw to destroy safely.
Return:
	-
Notes:
	Optimised for multiple people.  Not very well though...
-*----------------------------------------------------------------------------*/

stock TD_Destroy(Text:textDraw)
{
	if (Text:0 <= textDraw < Text:MAX_TEXT_DRAWS)
	{
		// Find the TD before this one in the style list.
		new
			Style:style = YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_STYLE],
			Text:next = YSI_g_sTDData[style][E_TD_DATA_USE],
			Text:last = TEXT_DRAW_NO_NEXT;
		while (next != TEXT_DRAW_NO_NEXT)
		{
			if (next == textDraw)
			{
				break;
			}
			last = next;
			next = YSI_g_sTDDisplay[next][E_TD_DISPLAY_NEXT];
		}
		// Destroy the SA:MP text draw.
		new
			Text:real = YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_REAL];
		YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_REAL] = Text:INVALID_TEXT_DRAW;
		YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_TEXT][0] = '\0';
		++YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_REVISION];
		if (real != Text:INVALID_TEXT_DRAW)
		{
			// TextDrawDestroy
			TextDrawDestroy(real);
			// Now kill timers for players.
			// TODO: Update.
			new
				index = Bit_Slot(textDraw),
				Bit:mod = ~Bit_Mask(textDraw);
			foreach (Player, playerid)
			{
				/*if (YSI_g_sTDTimers[textDraw][playerid])
				{
					KillTimer(YSI_g_sTDTimers[textDraw][playerid]);
				}
				YSI_g_sTDTimers[textDraw][playerid] = 0;*/
				YSI_g_sPlayerDraws[playerid][index] &= mod;
			}
		}
		// Remove from the style use list and add to the unused list.
		if (next != textDraw)
		{
			return 0;
		}
		C:1(else printf("*** Internal Error: Orphaned text draw found."););
		if (last == TEXT_DRAW_NO_NEXT)
		{
			YSI_g_sTDData[style][E_TD_DATA_USE] = YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_NEXT];
		}
		else
		{
			YSI_g_sTDDisplay[last][E_TD_DISPLAY_NEXT] = YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_NEXT];
		}
		YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_NEXT] = YSI_g_sUnused;
		YSI_g_sUnused = textDraw;
	}
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	Text:TD_Display
Params:
	text[] - Text to display onscreen.
	Style:id - Style to use to style text.
Return:
	Internal Text: id, not actual text draw's id.
Notes:
	Generates a text draw for to display to people.
-*----------------------------------------------------------------------------*/

stock Text:TD_Display(text[], Style:id, Float:x = (Float:TEXT_DRAW_NAN), Float:y = (Float:TEXT_DRAW_NAN))
{
	if (YSI_g_sUnused == TEXT_DRAW_NO_NEXT)
	{
		return Text:INVALID_TEXT_DRAW;
	}
	if (!TD_IsValidStyle(id))
	{
		return Text:INVALID_TEXT_DRAW;
	}
	// if (x != x)
	// Determine the screen position.
	if (_:x == TEXT_DRAW_NAN)
	{
		YSI_g_sTDDisplay[YSI_g_sUnused][E_TD_DISPLAY_X] = YSI_g_sTDData[id][E_TD_DATA_X];
	}
	else
	{
		YSI_g_sTDDisplay[YSI_g_sUnused][E_TD_DISPLAY_X] = x;
	}
	if (_:y == TEXT_DRAW_NAN)
	{
		YSI_g_sTDDisplay[YSI_g_sUnused][E_TD_DISPLAY_Y] = YSI_g_sTDData[id][E_TD_DATA_Y];
	}
	else
	{
		YSI_g_sTDDisplay[YSI_g_sUnused][E_TD_DISPLAY_Y] = y;
	}
	YSI_g_sTDDisplay[YSI_g_sUnused][E_TD_DISPLAY_STYLE] = id;
	// Render the code to an internal TD.  All TD_Render does is call SA:MP
	// functions, it does no variable sets.
	new
		Text:textDraw = TD_Render(text, id, YSI_g_sUnused);
	if (textDraw == Text:INVALID_TEXT_DRAW)
	{
		return Text:INVALID_TEXT_DRAW;
	}
	YSI_g_sTDDisplay[YSI_g_sUnused][E_TD_DISPLAY_REAL] = textDraw;
	// I don't know wether or not to use strpack here.
	//strcpy(YSI_g_sTDDisplay[YSI_g_sUnused][E_TD_DISPLAY_TEXT], text, MAX_TEXT_DRAW_LINE);
	strpack(YSI_g_sTDDisplay[YSI_g_sUnused][E_TD_DISPLAY_TEXT], text, MAX_TEXT_DRAW_LINE char);
	textDraw = Text:YSI_g_sUnused;
	YSI_g_sUnused = YSI_g_sTDDisplay[YSI_g_sUnused][E_TD_DISPLAY_NEXT];
	// Add to the list of items using this style.
	YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_NEXT] = YSI_g_sTDData[id][E_TD_DATA_USE];
	YSI_g_sTDData[id][E_TD_DATA_USE] = textDraw;
	// Nobody can see it, but don't destroy it.
	YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_LIFE] = 0;
	// Increment this every time this slot is used and cleared.
	++YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_REVISION];
	return textDraw;
}

stock Text:TD_DisplayForPlayer(playerid, text[], Style:id, Float:x = (Float:TEXT_DRAW_NAN), Float:y = (Float:TEXT_DRAW_NAN))
{
	new
		Text:td = TD_Display(text, id, x, y);
	TD_Garbage(td);
	TD_ShowForPlayer(playerid, td);
	return td;
}

stock Text:TD_DisplayForAll(text[], Style:id, Float:x = (Float:TEXT_DRAW_NAN), Float:y = (Float:TEXT_DRAW_NAN))
{
	new
		Text:td = TD_Display(text, id, x, y);
	TD_Garbage(td);
	TD_ShowForAll(td);
	return td;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_SetString
Params:
	Text:td - The text draw to modify.
	text[] - Text to display onscreen.
Return:
	-
Notes:
	Changes the text on people's screens quickly.
-*----------------------------------------------------------------------------*/

stock TD_SetString(Text:td, text[])
{
	if (_TD_TextValid(td))
	{
		//strcpy(YSI_g_sTDDisplay[td][E_TD_DISPLAY_TEXT], text, MAX_TEXT_DRAW_LINE);
		strpack(YSI_g_sTDDisplay[td][E_TD_DISPLAY_TEXT], text, MAX_TEXT_DRAW_LINE char);
		new
			Text:real = YSI_g_sTDDisplay[td][E_TD_DISPLAY_REAL];
		// This may have lost it's real rendering
		if (real == Text:INVALID_TEXT_DRAW)
		{
			return 0;
		}
		// Get the style information for showing this TD.
		TextDrawSetString(real, text);
	}
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	Text:TD_DisplayHashed
Params:
	text[] - Text to display.
	hash - Hashed style name for styling.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock Text:TD_DisplayHashed(text[], hash, Float:x = (Float:TEXT_DRAW_NAN), Float:y = (Float:TEXT_DRAW_NAN))
{
	new
		Style:id = TD_GetID(hash);
	if (id != MAX_TEXT_DRAW_STYLES)
	{
		return TD_Display(text, id, x, y);
	}
	return Text:INVALID_TEXT_DRAW;
}

stock Text:TD_DisplayHashedForPlayer(playerid, text[], hash, Float:x = (Float:TEXT_DRAW_NAN), Float:y = (Float:TEXT_DRAW_NAN))
{
	new
		Style:id = TD_GetID(hash);
	if (id != MAX_TEXT_DRAW_STYLES)
	{
		return TD_DisplayForPlayer(playerid, text, id, x, y);
	}
	return Text:INVALID_TEXT_DRAW;
}

stock Text:TD_DisplayHashedForAll(text[], hash, Float:x = (Float:TEXT_DRAW_NAN), Float:y = (Float:TEXT_DRAW_NAN))
{
	new
		Style:id = TD_GetID(hash);
	if (id != MAX_TEXT_DRAW_STYLES)
	{
		return TD_DisplayForAll(text, id, x, y);
	}
	return Text:INVALID_TEXT_DRAW;
}

/*----------------------------------------------------------------------------*-
Function:
	Text:TD_DisplayNamed
Params:
	text[] - Text to display.
	style[] - Named style to display the text with.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock Text:TD_DisplayNamed(text[], style[], Float:x = (Float:TEXT_DRAW_NAN), Float:y = (Float:TEXT_DRAW_NAN))
{
	return TD_DisplayHashed(text, bernstein(style), x, y);
}

stock Text:TD_DisplayNamedForPlayer(playerid, text[], style[], Float:x = (Float:TEXT_DRAW_NAN), Float:y = (Float:TEXT_DRAW_NAN))
{
	return TD_DisplayHashedForPlayer(playerid, text, bernstein(style), x, y);
}

stock Text:TD_DisplayNamedForAll(text[], style[], Float:x = (Float:TEXT_DRAW_NAN), Float:y = (Float:TEXT_DRAW_NAN))
{
	return TD_DisplayHashedForAll(text, bernstein(style), x, y);
}

/*----------------------------------------------------------------------------*-
Function:
	TD_ShowForPlayer
Params:
	playerid - Player to show the text to.
	Text:textDraw - ID of the text to show.
Return:
	-
Notes:
	Now destroys any existing text draws using the same style in
	the same place to avoid overlaps.
-*----------------------------------------------------------------------------*/

stock TD_ShowForPlayer(playerid, Text:textDraw)
{
	if (Text:0 <= textDraw < Text:MAX_TEXT_DRAWS && !Bit_GetBit(YSI_g_sPlayerDraws[playerid], _:textDraw))
	{
		new
			Text:real = YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_REAL],
			Style:style = YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_STYLE];
		// This may have lost it's real rendering
		if (real == Text:INVALID_TEXT_DRAW)
		{
			if (!YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_TEXT][0])
			{
				// There is no text to render.
				return 0;
			}
			real = TD_Render(YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_TEXT], style, textDraw);
			if (real == Text:INVALID_TEXT_DRAW)
			{
				return 0;
			}
			YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_REAL] = real;
		}
		// Now show this for a player.
		TextDrawShowForPlayer(playerid, real);
		Bit_Let(YSI_g_sPlayerDraws[playerid], _:textDraw);
		++YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_LIFE];
		new
			time = YSI_g_sTDData[style][E_TD_DATA_TIME];
		// TODO: Update.
		/*if (YSI_g_sTDTimers[textDraw][playerid])
		{
			KillTimer(YSI_g_sTDTimers[textDraw][playerid]);
		}*/
		if (time)
		{
			//YSI_g_sTDTimers[textDraw][playerid] = SetTimerEx("TD_HideForPlayer", time, 0, "ii", playerid, _:textDraw);
			TD_SetTimer(playerid, textDraw, time, YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_REVISION]);
		}
		return 1;
	}
	return 0;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_HideForPlayer
Params:
	playerid - Player to hide the text for.
	Text:textDraw - Text to hide.
	revision - The version of the text draw which existed when this was set.
Return:
	-
Notes:
	Public so the timer can call it to hide texts with a time set.
-*----------------------------------------------------------------------------*/

public TD_HideForPlayerPub(playerid, Text:textDraw, revision)
{
	// Hide the TD only if it's not changed since last time (avoids ABA errors).
	if (YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_REVISION] == revision)
	{
		//if (playerid == INVALID_PLAYER_ID)
		//{
		//	TD_HideForAll(textDraw);
		//}
		//else
		//{
			TD_HideForPlayer(playerid, textDraw);
		//}
	}
}

stock TD_HideForPlayer(playerid, Text:textDraw)
{
	if (IsPlayerConnected(playerid))
	{
		if (Text:0 <= textDraw < Text:MAX_TEXT_DRAWS && Bit_GetBit(YSI_g_sPlayerDraws[playerid], _:textDraw))
		{
			// TODO: Update this to find the correct timer.
			/*if (YSI_g_sTDTimers[textDraw][playerid])
			{
				KillTimer(YSI_g_sTDTimers[textDraw][playerid]);
			}
			YSI_g_sTDTimers[textDraw][playerid] = 0;*/
			//YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_LIFE] = (count & 0x80000000) | ((count & 0x7FFFFFFF) - 1);
			if (--YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_LIFE] == 0x80000000)
			{
				// No-one uses this any more, destroy it.  Looking back on the
				// code, this doesn't seem well implemented at all!  Actually it
				// is, ignore me.  I forgot that you have to MANUALLY mark TDs
				// as garbage for collection here.
				TD_Destroy(Text:textDraw);
			}
			else
			{
				Bit_Vet(YSI_g_sPlayerDraws[playerid], _:textDraw);
				TextDrawHideForPlayer(playerid, YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_REAL]);
			}
			return 1;
		}
	}
	return 0;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_ShowForAll
Params:
	Text:textDraw - Text to show to all players.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

stock TD_ShowForAll(Text:textDraw)
{
	if (Text:0 <= textDraw < Text:MAX_TEXT_DRAWS)
	{
		new
			Text:real = YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_REAL],
			Style:style = YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_STYLE];
		// This may have lost it's real rendering
		if (real == Text:INVALID_TEXT_DRAW)
		{
			if (!YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_TEXT][0])
			{
				// There is no text to render.
				return 0;
			}
			real = TD_Render(YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_TEXT], style, textDraw);
			if (real == Text:INVALID_TEXT_DRAW)
			{
				return 0;
			}
			YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_REAL] = real;
		}
		// Get the style information for showing this TD.
		/*new
			//index,
			//count,
			Float:x = YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_X],
			Float:y = YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_Y],
			Style:style = YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_STYLE],
			time = YSI_g_sTDData[style][E_TD_DATA_TIME],
			Text:next = YSI_g_sTDData[style][E_TD_DATA_USE],
			Text:last = TEXT_DRAW_NO_NEXT,
			Text:cur = TEXT_DRAW_NO_NEXT,
			Text:thisLast = TEXT_DRAW_NO_NEXT;*/
		/*while (next != TEXT_DRAW_NO_NEXT)
		{
			if (next == textDraw)
			{
				thisLast = last;
				last = next;
				next = YSI_g_sTDDisplay[next][E_TD_DISPLAY_NEXT];
			}
			else if (x == YSI_g_sTDDisplay[next][E_TD_DISPLAY_X] && y == YSI_g_sTDDisplay[next][E_TD_DISPLAY_Y])
			{
				// Hide existing text draws in the same location.  This
				// actually now seems like a bad idea!
				count = YSI_g_sTDDisplay[next][E_TD_DISPLAY_LIFE];
				cur = YSI_g_sTDDisplay[next][E_TD_DISPLAY_NEXT];
				if (count & 0x80000000)
				{
					if (last == TEXT_DRAW_NO_NEXT)
					{
						YSI_g_sTDData[style][E_TD_DATA_USE] = cur;
					}
					else
					{
						YSI_g_sTDDisplay[last][E_TD_DISPLAY_NEXT] = cur;
					}
					YSI_g_sTDDisplay[next][E_TD_DISPLAY_NEXT] = YSI_g_sUnused;
					YSI_g_sUnused = next;
					new
						Text:temp = YSI_g_sTDDisplay[next][E_TD_DISPLAY_REAL];
					YSI_g_sTDDisplay[next][E_TD_DISPLAY_REAL] = Text:INVALID_TEXT_DRAW;
					if (temp != Text:INVALID_TEXT_DRAW)
					{
						TextDrawDestroy(temp);
					}
				}
				else
				{
					TextDrawHideForAll(YSI_g_sTDDisplay[next][E_TD_DISPLAY_REAL]);
					last = next;
				}
				index = _:next / cellbits;
				mod = 1 << (_:next % cellbits);
				foreach (Player, playerid)
				{
					YSI_g_sPlayerDraws[playerid][index] &= Bit:mod;
				}
				next = cur;
			}
			else
			{
				last = next;
				next = YSI_g_sTDDisplay[next][E_TD_DISPLAY_NEXT];
			}
		}*/
		TextDrawShowForAll(real);
		new
			count = 0,
			index = Bit_Slot(textDraw),
			Bit:mod = Bit_Mask(textDraw),
			time = YSI_g_sTDData[style][E_TD_DATA_TIME],
			revision = YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_REVISION];
		foreach (Player, playerid)
		{
			YSI_g_sPlayerDraws[playerid][index] |= mod;
			++count;
			// TODO: Update.
			/*if (YSI_g_sTDTimers[textDraw][playerid])
			{
				KillTimer(YSI_g_sTDTimers[textDraw][playerid]);
			}*/
				//YSI_g_sTDTimers[textDraw][playerid] = SetTimerEx("TD_HideForPlayer", time, 0, "ii", playerid, _:textDraw);
			if (time)
			{
				TD_SetTimer(playerid, textDraw, time, revision);
			}
		}
		if (count)
		{
			// People can see it.
			YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_LIFE] = (YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_LIFE] & 0x80000000) | count;
		}
		else
		{
			TD_TryDestroy(textDraw);
		}
		return 1;
		//}
	}
	return 0;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_HideForAll
Params:
	Text:textDraw - Text to hide from all players.
Return:
	-
Notes:
	Destroys the real text draw if marked for garbage collection.
-*----------------------------------------------------------------------------*/

stock TD_HideForAll(Text:textDraw)
{
	if (Text:0 <= textDraw < Text:MAX_TEXT_DRAWS)
	{
		new
			Text:real = YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_REAL];
		if (!TD_TryDestroy(textDraw))
		{
			if (real != Text:INVALID_TEXT_DRAW)
			{
				YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_LIFE] = 0;
				new
					index = Bit_Slot(textDraw),
					Bit:inv = ~Bit_Mask(textDraw);//,
					//Bit:inv = ~mod;
				// Hide it for all players but don't destroy it.
				TextDrawHideForAll(real);
				++YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_REVISION];
				foreach (Player, playerid)
				{
					//if (YSI_g_sPlayerDraws[playerid][index] & mod)
					//{
						// Need to sort out the timers.
						// TODO: Update
						/*if (YSI_g_sTDTimers[textDraw][playerid])
						{
							KillTimer(YSI_g_sTDTimers[textDraw][playerid]);
							YSI_g_sTDTimers[textDraw][playerid] = 0;
						}*/
						YSI_g_sPlayerDraws[playerid][index] &= inv;
					//}
				}
			}
		}
	}
	return 1;
}

/*----------------------------------------------------------------------------*-
Function:
	TD_OnPlayerDisconnect
Params:
	playerid - Player who left.
	reason - Why they left.
Return:
	-
Notes:
	Required to fix bugs in the textdraw system by hiding all
	visible ones.
-*----------------------------------------------------------------------------*/

public OnPlayerDisconnect(playerid, reason)
{
	for (new i = 0; i < bits<MAX_TEXT_DRAWS>; i++)
	{
		new
			Bit:s = YSI_g_sPlayerDraws[playerid][i],
			j = 0,
			ix = i << 5;
		while (s)
		{
			// Get rid of data for textdraws which this player can see.  We
			// don't need to actually hide the textdraw as the player has left.
			if (s & Bit:1)
			{
				new
					Text:textDraw = Text:(ix + j);
				/*if (YSI_g_sTDTimers[textDraw][playerid])
				{
					// TODO: Update.
					KillTimer(YSI_g_sTDTimers[textDraw][playerid]);
					YSI_g_sTDTimers[textDraw][playerid] = 0;
				}*/
				if (--YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_LIFE] == 0x80000000)
				{
					TD_Destroy(textDraw);
				}
				//TD_TryDestroy(textDraw);
			}
			s >>>= Bit:1;
			++j;
		}
		YSI_g_sPlayerDraws[playerid][i] = Bit:0;
	}
	ALS_CALL<PlayerDisconnect>
}

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect TD_OnPlayerDisconnect
ALS_FORWARD<PlayerDisconnect>

/*----------------------------------------------------------------------------*-
Function:
	TD_Garbage
Params:
	Text:textDraw - Text to mark as garbage.
Return:
	-
Notes:
	Tells the system to remove a text draw when no-one can see it
	anymore to free up text draw slots.
-*----------------------------------------------------------------------------*/

stock TD_Garbage(Text:textDraw)
{
	if (Text:0 <= textDraw < Text:MAX_TEXT_DRAWS)
	{
		if (YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_LIFE] & 0x7FFFFFFF)
		{
			// Players can still see it.
			YSI_g_sTDDisplay[textDraw][E_TD_DISPLAY_LIFE] |= 0x80000000;
		}
		else
		{
			// No-one can see it.
			TD_Destroy(textDraw);
		}
	}
}

#undef ALS_PREFIX
//#endif
