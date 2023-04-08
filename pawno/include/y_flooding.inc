/*----------------------------------------------------------------------------*-
					===================================
					Y Sever Includes - Connections Core
					===================================
Description:
	Allows a limited number of connections from a single IP.
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
Changelog:
	15/11/10:
		Updated to YSI 1.0.
	11/03/08:
		First version.
Functions:
	Public:
		-
	Core:
		OnPlayerConnect - Called to check IPs.
		OnScriptInit - Sets the OnPlayerConnect function flag.
	Stock:
		-
	Static:
		-
	Inline:
		-
	API:
		SetMaxConnections - Sets the max allowed connections from an IP.
Callbacks:
	-
Definitions:
	-
Enums:
	e_FLOOD_ACTION - What to do if too many connections form.
Macros:
	-
Tags:
	-
Variables:
	Global:
		-
	Static:
		YSI_g_sPlayerIPs - People's stored IPs for speed.
		YSI_g_sMaxConnections - Data for the script.
Commands:
	-
Compile options:
	-
Operators:
	-
-*----------------------------------------------------------------------------*/

#include <YSI\internal\y_version>

enum e_FLOOD_ACTION (+= 0x00010000)
{
	e_FLOOD_ACTION_COUNT = 0x0000FFFF
	e_FLOOD_ACTION_ACTION = 0x000F0000,
	e_FLOOD_ACTION_NOTHING = 0,
	e_FLOOD_ACTION_BLOCK,
	e_FLOOD_ACTION_KICK,
	e_FLOOD_ACTION_BAN,
	e_FLOOD_ACTION_OPC = 0x80000000,
}

static
	YSI_g_sPlayerIPs[MAX_PLAYERS],
	e_FLOOD_ACTION:YSI_g_sMaxConnections = e_FLOOD_ACTION_COUNT | e_FLOOD_ACTION_BLOCK;

/*----------------------------------------------------------------------------*-
Function:
	SetMaxConnections
Params:
	max - Maximum number of connections allowed from the same IP.
	e_FLOOD_ACTION:action - What to do if there's too many.
Return:
	-
Notes:
	Sets the maximum connections allowed from a single IP.
-*----------------------------------------------------------------------------*/

stock SetMaxConnections(max = -1, e_FLOOD_ACTION:action = e_FLOOD_ACTION_BLOCK)
{
	YSI_g_sMaxConnections = (e_FLOOD_ACTION:max & e_FLOOD_ACTION_COUNT) | action | (YSI_g_sMaxConnections & e_FLOOD_ACTION_OPC);
}

/*----------------------------------------------------------------------------*-
Function:
	OnScriptInit
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
	if (funcidx("YFLD_OnPlayerConnect") != -1)
	{
		YSI_g_sMaxConnections |= e_FLOOD_ACTION_OPC;
	}
	CallLocalFunction("YFLD_OnScriptInit", "");
	return 1;
}

#if defined FILTERSCRIPT
	#if defined _ALS_OnFilterScriptInit
		#undef OnFilterScriptInit
	#else
		#define _ALS_OnFilterScriptInit
	#endif
	#define OnFilterScriptInit YFLD_OnScriptInit
#else
	#if defined _ALS_OnGameModeInit
		#undef OnGameModeInit
	#else
		#define _ALS_OnGameModeInit
	#endif
	#define OnGameModeInit YFLD_OnScriptInit
#endif

forward YFLD_OnScriptInit();

/*----------------------------------------------------------------------------*-
Function:
	Conn_OnPlayerConnect
Params:
	playerid - Player who joined.
Return:
	-
Notes:
	Checks for too many connections from the same IP address and acts
	accordingly.
	
	Could be edited to only loop through players once but I'm not sure the
	extra code required would be faster anyway, definately not easier.
-*----------------------------------------------------------------------------*/

public OnPlayerConnect(playerid)
{
	if (YSI_g_sMaxConnections & e_FLOOD_ACTION_OPC)
	{
		CallLocalFunction("YFLD_OnPlayerConnect", "i", playerid);
	}
	if ((YSI_g_sMaxConnections & e_FLOOD_ACTION_COUNT) != e_FLOOD_ACTION_COUNT)
	{
		new
			count = 0,
			IP = GetIP(playerid);
		YSI_g_sPlayerIPs[playerid] = IP;
		foreach (Player, i)
		{
			if (YSI_g_sPlayerIPs[i] == IP)
			{
				++count;
			}
		}
		if (count > _:(YSI_g_sMaxConnections & e_FLOOD_ACTION_COUNT))
		{
			P:0("*** Internal Alert: Max Connections exceeded");
			switch (YSI_g_sMaxConnections & e_FLOOD_ACTION_ACTION)
			{
				case e_FLOOD_ACTION_BLOCK:
				{
					// Kick the latest player.
					Kick(playerid);
					return 0;
				}
				case e_FLOOD_ACTION_KICK:
				{
					// Kick all the players.
				}
				case e_FLOOD_ACTION_BAN:
				{
					// Ban the IP.
					BanEx(playerid, "YSI max connections auto-ban");
				}
				default:
				{
					// Do nothing.
					return 1;
				}
			}
		}
		foreach (Player, i)
		{
			if (YSI_g_sPlayerIPs[i] == IP)
			{
				Kick(i);
			}
		}
		return 0;
	}
	return 1;
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect YFLD_OnPlayerConnect

forward YFLD_OnPlayerConnect(playerid);
