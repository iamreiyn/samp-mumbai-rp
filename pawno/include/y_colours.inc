/*----------------------------------------------------------------------------*-
					==========================
					 y_colours - X11 colours!
					==========================
Description:
	This holds the colour information that used to be part of the text system
	but which is far more useful than just for text.  This now supports the full
	set of X11 colours, both by name and by definition.  You can also define
	your own if you so choose (up to 32 - should be enough given that this
	includes the X11 colours).
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

#include <YSI\y_stringhash>

#if !defined MAX_TEXT_COLOURS
	#define MAX_TEXT_COLOURS	        (32)
#endif

#if !defined NO_X11_COLOURS && !defined NO_X11_COLORS
	#define MK_RGB(%0,%1,%2)            ((%0) << 24 | (%1) << 16 | (%0) << 8)
	
	#define X11_SNOW                    MK_RGB(255, 250, 250)
	#define X11_GHOSTWHITE              MK_RGB(248, 248, 255)
	#define X11_GHOST_WHITE             MK_RGB(248, 248, 255)
	#define X11_WHITESMOKE              MK_RGB(245, 245, 245)
	#define X11_WHITE_SMOKE             MK_RGB(245, 245, 245)
	#define X11_GAINSBORO               MK_RGB(220, 220, 220)
	#define X11_FLORALWHITE             MK_RGB(255, 250, 240)
	#define X11_FLORAL_WHITE            MK_RGB(255, 250, 240)
	#define X11_OLDLACE                 MK_RGB(253, 245, 230)
	#define X11_OLD_LACE                MK_RGB(253, 245, 230)
	#define X11_LINEN                   MK_RGB(250, 240, 230)
	#define X11_ANTIQUEWHITE            MK_RGB(250, 235, 215)
	#define X11_ANTIQUE_WHITE           MK_RGB(250, 235, 215)
	#define X11_PAPAYAWHIP              MK_RGB(255, 239, 213)
	#define X11_PAPAYA_WHIP             MK_RGB(255, 239, 213)
	#define X11_BLANCHEDALMOND          MK_RGB(255, 235, 205)
	#define X11_BLANCHED_ALMOND         MK_RGB(255, 235, 205)
	#define X11_BISQUE                  MK_RGB(255, 228, 196)
	#define X11_PEACHPUFF               MK_RGB(255, 218, 185)
	#define X11_PEACH_PUFF              MK_RGB(255, 218, 185)
	#define X11_NAVAJOWHITE             MK_RGB(255, 222, 173)
	#define X11_NAVAJO_WHITE            MK_RGB(255, 222, 173)
	#define X11_MOCCASIN                MK_RGB(255, 228, 181)
	#define X11_CORNSILK                MK_RGB(255, 248, 220)
	#define X11_IVORY                   MK_RGB(255, 255, 240)
	#define X11_LEMONCHIFFON            MK_RGB(255, 250, 205)
	#define X11_LEMON_CHIFFON           MK_RGB(255, 250, 205)
	#define X11_SEASHELL                MK_RGB(255, 245, 238)
	#define X11_HONEYDEW                MK_RGB(240, 255, 240)
	#define X11_MINTCREAM               MK_RGB(245, 255, 250)
	#define X11_MINT_CREAM              MK_RGB(245, 255, 250)
	#define X11_AZURE                   MK_RGB(240, 255, 255)
	#define X11_ALICEBLUE               MK_RGB(240, 248, 255)
	#define X11_ALICE_BLUE              MK_RGB(240, 248, 255)
	#define X11_LAVENDER                MK_RGB(230, 230, 250)
	#define X11_LAVENDERBLUSH           MK_RGB(255, 240, 245)
	#define X11_LAVENDER_BLUSH          MK_RGB(255, 240, 245)
	#define X11_MISTYROSE               MK_RGB(255, 228, 225)
	#define X11_MISTY_ROSE              MK_RGB(255, 228, 225)
	#define X11_WHITE                   MK_RGB(255, 255, 255)
	#define X11_BLACK                   MK_RGB(  0,   0,   0)
	#define X11_DARKSLATEGRAY           MK_RGB( 47,  79,  79)
	#define X11_DARK_SLATE_GRAY         MK_RGB( 47,  79,  79)
	#define X11_DARKSLATEGREY           MK_RGB( 47,  79,  79)
	#define X11_DARK_SLATE_GREY         MK_RGB( 47,  79,  79)
	#define X11_DIMGRAY                 MK_RGB(105, 105, 105)
	#define X11_DIM_GRAY                MK_RGB(105, 105, 105)
	#define X11_DIMGREY                 MK_RGB(105, 105, 105)
	#define X11_DIM_GREY                MK_RGB(105, 105, 105)
	#define X11_SLATEGRAY               MK_RGB(112, 128, 144)
	#define X11_SLATE_GRAY              MK_RGB(112, 128, 144)
	#define X11_SLATEGREY               MK_RGB(112, 128, 144)
	#define X11_SLATE_GREY              MK_RGB(112, 128, 144)
	#define X11_LIGHTSLATEGRAY          MK_RGB(119, 136, 153)
	#define X11_LIGHT_SLATE_GRAY        MK_RGB(119, 136, 153)
	#define X11_LIGHTSLATEGREY          MK_RGB(119, 136, 153)
	#define X11_LIGHT_SLATE_GREY        MK_RGB(119, 136, 153)
	#define X11_GRAY                    MK_RGB(190, 190, 190)
	#define X11_GREY                    MK_RGB(190, 190, 190)
	#define X11_LIGHTGREY               MK_RGB(211, 211, 211)
	#define X11_LIGHT_GREY              MK_RGB(211, 211, 211)
	#define X11_LIGHTGRAY               MK_RGB(211, 211, 211)
	#define X11_LIGHT_GRAY              MK_RGB(211, 211, 211)
	#define X11_MIDNIGHTBLUE            MK_RGB( 25,  25, 112)
	#define X11_MIDNIGHT_BLUE           MK_RGB( 25,  25, 112)
	#define X11_NAVY                    MK_RGB(  0,   0, 128)
	#define X11_NAVYBLUE                MK_RGB(  0,   0, 128)
	#define X11_NAVY_BLUE               MK_RGB(  0,   0, 128)
	#define X11_CORNFLOWERBLUE          MK_RGB(100, 149, 237)
	#define X11_CORNFLOWER_BLUE         MK_RGB(100, 149, 237)
	#define X11_DARKSLATEBLUE           MK_RGB( 72,  61, 139)
	#define X11_DARK_SLATE_BLUE         MK_RGB( 72,  61, 139)
	#define X11_SLATEBLUE               MK_RGB(106,  90, 205)
	#define X11_SLATE_BLUE              MK_RGB(106,  90, 205)
	#define X11_MEDIUMSLATEBLUE         MK_RGB(123, 104, 238)
	#define X11_MEDIUM_SLATE_BLUE       MK_RGB(123, 104, 238)
	#define X11_LIGHTSLATEBLUE          MK_RGB(132, 112, 255)
	#define X11_LIGHT_SLATE_BLUE        MK_RGB(132, 112, 255)
	#define X11_MEDIUMBLUE              MK_RGB(  0,   0, 205)
	#define X11_MEDIUM_BLUE             MK_RGB(  0,   0, 205)
	#define X11_ROYALBLUE               MK_RGB( 65, 105, 225)
	#define X11_ROYAL_BLUE              MK_RGB( 65, 105, 225)
	#define X11_BLUE                    MK_RGB(  0,   0, 255)
	#define X11_DODGERBLUE              MK_RGB( 30, 144, 255)
	#define X11_DODGER_BLUE             MK_RGB( 30, 144, 255)
	#define X11_DEEPSKYBLUE             MK_RGB(  0, 191, 255)
	#define X11_DEEP_SKY_BLUE           MK_RGB(  0, 191, 255)
	#define X11_SKYBLUE                 MK_RGB(135, 206, 235)
	#define X11_SKY_BLUE                MK_RGB(135, 206, 235)
	#define X11_LIGHTSKYBLUE            MK_RGB(135, 206, 250)
	#define X11_LIGHT_SKY_BLUE          MK_RGB(135, 206, 250)
	#define X11_STEELBLUE               MK_RGB( 70, 130, 180)
	#define X11_STEEL_BLUE              MK_RGB( 70, 130, 180)
	#define X11_LIGHTSTEELBLUE          MK_RGB(176, 196, 222)
	#define X11_LIGHT_STEEL_BLUE        MK_RGB(176, 196, 222)
	#define X11_LIGHTBLUE               MK_RGB(173, 216, 230)
	#define X11_LIGHT_BLUE              MK_RGB(173, 216, 230)
	#define X11_POWDERBLUE              MK_RGB(176, 224, 230)
	#define X11_POWDER_BLUE             MK_RGB(176, 224, 230)
	#define X11_PALETURQUOISE           MK_RGB(175, 238, 238)
	#define X11_PALE_TURQUOISE          MK_RGB(175, 238, 238)
	#define X11_DARKTURQUOISE           MK_RGB(  0, 206, 209)
	#define X11_DARK_TURQUOISE          MK_RGB(  0, 206, 209)
	#define X11_MEDIUMTURQUOISE         MK_RGB( 72, 209, 204)
	#define X11_MEDIUM_TURQUOISE        MK_RGB( 72, 209, 204)
	#define X11_TURQUOISE               MK_RGB( 64, 224, 208)
	#define X11_CYAN                    MK_RGB(  0, 255, 255)
	#define X11_LIGHTCYAN               MK_RGB(224, 255, 255)
	#define X11_LIGHT_CYAN              MK_RGB(224, 255, 255)
	#define X11_CADETBLUE               MK_RGB( 95, 158, 160)
	#define X11_CADET_BLUE              MK_RGB( 95, 158, 160)
	#define X11_MEDIUMAQUAMARINE        MK_RGB(102, 205, 170)
	#define X11_MEDIUM_AQUAMARINE       MK_RGB(102, 205, 170)
	#define X11_AQUAMARINE              MK_RGB(127, 255, 212)
	#define X11_DARKGREEN               MK_RGB(  0, 100,   0)
	#define X11_DARK_GREEN              MK_RGB(  0, 100,   0)
	#define X11_DARKOLIVEGREEN          MK_RGB( 85, 107,  47)
	#define X11_DARK_OLIVE_GREEN        MK_RGB( 85, 107,  47)
	#define X11_DARKSEAGREEN            MK_RGB(143, 188, 143)
	#define X11_DARK_SEA_GREEN          MK_RGB(143, 188, 143)
	#define X11_SEAGREEN                MK_RGB( 46, 139,  87)
	#define X11_SEA_GREEN               MK_RGB( 46, 139,  87)
	#define X11_MEDIUMSEAGREEN          MK_RGB( 60, 179, 113)
	#define X11_MEDIUM_SEA_GREEN        MK_RGB( 60, 179, 113)
	#define X11_LIGHTSEAGREEN           MK_RGB( 32, 178, 170)
	#define X11_LIGHT_SEA_GREEN         MK_RGB( 32, 178, 170)
	#define X11_PALEGREEN               MK_RGB(152, 251, 152)
	#define X11_PALE_GREEN              MK_RGB(152, 251, 152)
	#define X11_SPRINGGREEN             MK_RGB(  0, 255, 127)
	#define X11_SPRING_GREEN            MK_RGB(  0, 255, 127)
	#define X11_LAWNGREEN               MK_RGB(124, 252,   0)
	#define X11_LAWN_GREEN              MK_RGB(124, 252,   0)
	#define X11_GREEN                   MK_RGB(  0, 255,   0)
	#define X11_CHARTREUSE              MK_RGB(127, 255,   0)
	#define X11_MEDIUMSPRINGGREEN       MK_RGB(  0, 250, 154)
	#define X11_MEDIUM_SPRING_GREEN     MK_RGB(  0, 250, 154)
	#define X11_GREENYELLOW             MK_RGB(173, 255,  47)
	#define X11_GREEN_YELLOW            MK_RGB(173, 255,  47)
	#define X11_LIMEGREEN               MK_RGB( 50, 205,  50)
	#define X11_LIME_GREEN              MK_RGB( 50, 205,  50)
	#define X11_YELLOWGREEN             MK_RGB(154, 205,  50)
	#define X11_YELLOW_GREEN            MK_RGB(154, 205,  50)
	#define X11_FORESTGREEN             MK_RGB( 34, 139,  34)
	#define X11_FOREST_GREEN            MK_RGB( 34, 139,  34)
	#define X11_OLIVEDRAB               MK_RGB(107, 142,  35)
	#define X11_OLIVE_DRAB              MK_RGB(107, 142,  35)
	#define X11_DARKKHAKI               MK_RGB(189, 183, 107)
	#define X11_DARK_KHAKI              MK_RGB(189, 183, 107)
	#define X11_KHAKI                   MK_RGB(240, 230, 140)
	#define X11_PALEGOLDENROD           MK_RGB(238, 232, 170)
	#define X11_PALE_GOLDENROD          MK_RGB(238, 232, 170)
	#define X11_LIGHTGOLDENRODYELLOW    MK_RGB(250, 250, 210)
	#define X11_LIGHT_GOLDENROD_YELLOW  MK_RGB(250, 250, 210)
	#define X11_LIGHTYELLOW             MK_RGB(255, 255, 224)
	#define X11_LIGHT_YELLOW            MK_RGB(255, 255, 224)
	#define X11_YELLOW                  MK_RGB(255, 255,   0)
	#define X11_GOLD                    MK_RGB(255, 215,   0)
	#define X11_LIGHTGOLDENROD          MK_RGB(238, 221, 130)
	#define X11_LIGHT_GOLDENROD         MK_RGB(238, 221, 130)
	#define X11_GOLDENROD               MK_RGB(218, 165,  32)
	#define X11_DARKGOLDENROD           MK_RGB(184, 134,  11)
	#define X11_DARK_GOLDENROD          MK_RGB(184, 134,  11)
	#define X11_ROSYBROWN               MK_RGB(188, 143, 143)
	#define X11_ROSY_BROWN              MK_RGB(188, 143, 143)
	#define X11_INDIANRED               MK_RGB(205,  92,  92)
	#define X11_INDIAN_RED              MK_RGB(205,  92,  92)
	#define X11_SADDLEBROWN             MK_RGB(139,  69,  19)
	#define X11_SADDLE_BROWN            MK_RGB(139,  69,  19)
	#define X11_SIENNA                  MK_RGB(160,  82,  45)
	#define X11_PERU                    MK_RGB(205, 133,  63)
	#define X11_BURLYWOOD               MK_RGB(222, 184, 135)
	#define X11_BEIGE                   MK_RGB(245, 245, 220)
	#define X11_WHEAT                   MK_RGB(245, 222, 179)
	#define X11_SANDYBROWN              MK_RGB(244, 164,  96)
	#define X11_SANDY_BROWN             MK_RGB(244, 164,  96)
	#define X11_TAN                     MK_RGB(210, 180, 140)
	#define X11_CHOCOLATE               MK_RGB(210, 105,  30)
	#define X11_FIREBRICK               MK_RGB(178,  34,  34)
	#define X11_BROWN                   MK_RGB(165,  42,  42)
	#define X11_DARKSALMON              MK_RGB(233, 150, 122)
	#define X11_DARK_SALMON             MK_RGB(233, 150, 122)
	#define X11_SALMON                  MK_RGB(250, 128, 114)
	#define X11_LIGHTSALMON             MK_RGB(255, 160, 122)
	#define X11_LIGHT_SALMON            MK_RGB(255, 160, 122)
	#define X11_ORANGE                  MK_RGB(255, 165,   0)
	#define X11_DARKORANGE              MK_RGB(255, 140,   0)
	#define X11_DARK_ORANGE             MK_RGB(255, 140,   0)
	#define X11_CORAL                   MK_RGB(255, 127,  80)
	#define X11_LIGHTCORAL              MK_RGB(240, 128, 128)
	#define X11_LIGHT_CORAL             MK_RGB(240, 128, 128)
	#define X11_TOMATO                  MK_RGB(255,  99,  71)
	#define X11_ORANGERED               MK_RGB(255,  69,   0)
	#define X11_ORANGE_RED              MK_RGB(255,  69,   0)
	#define X11_RED                     MK_RGB(255,   0,   0)
	#define X11_HOTPINK                 MK_RGB(255, 105, 180)
	#define X11_HOT_PINK                MK_RGB(255, 105, 180)
	#define X11_DEEPPINK                MK_RGB(255,  20, 147)
	#define X11_DEEP_PINK               MK_RGB(255,  20, 147)
	#define X11_PINK                    MK_RGB(255, 192, 203)
	#define X11_LIGHTPINK               MK_RGB(255, 182, 193)
	#define X11_LIGHT_PINK              MK_RGB(255, 182, 193)
	#define X11_PALEVIOLETRED           MK_RGB(219, 112, 147)
	#define X11_PALE_VIOLET_RED         MK_RGB(219, 112, 147)
	#define X11_MAROON                  MK_RGB(176,  48,  96)
	#define X11_MEDIUMVIOLETRED         MK_RGB(199,  21, 133)
	#define X11_MEDIUM_VIOLET_RED       MK_RGB(199,  21, 133)
	#define X11_VIOLETRED               MK_RGB(208,  32, 144)
	#define X11_VIOLET_RED              MK_RGB(208,  32, 144)
	#define X11_MAGENTA                 MK_RGB(255,   0, 255)
	#define X11_VIOLET                  MK_RGB(238, 130, 238)
	#define X11_PLUM                    MK_RGB(221, 160, 221)
	#define X11_ORCHID                  MK_RGB(218, 112, 214)
	#define X11_MEDIUMORCHID            MK_RGB(186,  85, 211)
	#define X11_MEDIUM_ORCHID           MK_RGB(186,  85, 211)
	#define X11_DARKORCHID              MK_RGB(153,  50, 204)
	#define X11_DARK_ORCHID             MK_RGB(153,  50, 204)
	#define X11_DARKVIOLET              MK_RGB(148,   0, 211)
	#define X11_DARK_VIOLET             MK_RGB(148,   0, 211)
	#define X11_BLUEVIOLET              MK_RGB(138,  43, 226)
	#define X11_BLUE_VIOLET             MK_RGB(138,  43, 226)
	#define X11_PURPLE                  MK_RGB(160,  32, 240)
	#define X11_MEDIUMPURPLE            MK_RGB(147, 112, 219)
	#define X11_MEDIUM_PURPLE           MK_RGB(147, 112, 219)
	#define X11_THISTLE                 MK_RGB(216, 191, 216)
	#define X11_SNOW1                   MK_RGB(255, 250, 250)
	#define X11_SNOW_1                  MK_RGB(255, 250, 250)
	#define X11_SNOW2                   MK_RGB(238, 233, 233)
	#define X11_SNOW_2                  MK_RGB(238, 233, 233)
	#define X11_SNOW3                   MK_RGB(205, 201, 201)
	#define X11_SNOW_3                  MK_RGB(205, 201, 201)
	#define X11_SNOW4                   MK_RGB(139, 137, 137)
	#define X11_SNOW_4                  MK_RGB(139, 137, 137)
	#define X11_SEASHELL1               MK_RGB(255, 245, 238)
	#define X11_SEASHELL_1              MK_RGB(255, 245, 238)
	#define X11_SEASHELL2               MK_RGB(238, 229, 222)
	#define X11_SEASHELL_2              MK_RGB(238, 229, 222)
	#define X11_SEASHELL3               MK_RGB(205, 197, 191)
	#define X11_SEASHELL_3              MK_RGB(205, 197, 191)
	#define X11_SEASHELL4               MK_RGB(139, 134, 130)
	#define X11_SEASHELL_4              MK_RGB(139, 134, 130)
	#define X11_ANTIQUEWHITE1           MK_RGB(255, 239, 219)
	#define X11_ANTIQUE_WHITE_1         MK_RGB(255, 239, 219)
	#define X11_ANTIQUEWHITE2           MK_RGB(238, 223, 204)
	#define X11_ANTIQUE_WHITE_2         MK_RGB(238, 223, 204)
	#define X11_ANTIQUEWHITE3           MK_RGB(205, 192, 176)
	#define X11_ANTIQUE_WHITE_3         MK_RGB(205, 192, 176)
	#define X11_ANTIQUEWHITE4           MK_RGB(139, 131, 120)
	#define X11_ANTIQUE_WHITE_4         MK_RGB(139, 131, 120)
	#define X11_BISQUE1                 MK_RGB(255, 228, 196)
	#define X11_BISQUE_1                MK_RGB(255, 228, 196)
	#define X11_BISQUE2                 MK_RGB(238, 213, 183)
	#define X11_BISQUE_2                MK_RGB(238, 213, 183)
	#define X11_BISQUE3                 MK_RGB(205, 183, 158)
	#define X11_BISQUE_3                MK_RGB(205, 183, 158)
	#define X11_BISQUE4                 MK_RGB(139, 125, 107)
	#define X11_BISQUE_4                MK_RGB(139, 125, 107)
	#define X11_PEACHPUFF1              MK_RGB(255, 218, 185)
	#define X11_PEACH_PUFF_1            MK_RGB(255, 218, 185)
	#define X11_PEACHPUFF2              MK_RGB(238, 203, 173)
	#define X11_PEACH_PUFF_2            MK_RGB(238, 203, 173)
	#define X11_PEACHPUFF3              MK_RGB(205, 175, 149)
	#define X11_PEACH_PUFF_3            MK_RGB(205, 175, 149)
	#define X11_PEACHPUFF4              MK_RGB(139, 119, 101)
	#define X11_PEACH_PUFF_4            MK_RGB(139, 119, 101)
	#define X11_NAVAJOWHITE1            MK_RGB(255, 222, 173)
	#define X11_NAVAJO_WHITE_1          MK_RGB(255, 222, 173)
	#define X11_NAVAJOWHITE2            MK_RGB(238, 207, 161)
	#define X11_NAVAJO_WHITE_2          MK_RGB(238, 207, 161)
	#define X11_NAVAJOWHITE3            MK_RGB(205, 179, 139)
	#define X11_NAVAJO_WHITE_3          MK_RGB(205, 179, 139)
	#define X11_NAVAJOWHITE4            MK_RGB(139, 121,  94)
	#define X11_NAVAJO_WHITE_4          MK_RGB(139, 121,  94)
	#define X11_LEMONCHIFFON1           MK_RGB(255, 250, 205)
	#define X11_LEMON_CHIFFON_1         MK_RGB(255, 250, 205)
	#define X11_LEMONCHIFFON2           MK_RGB(238, 233, 191)
	#define X11_LEMON_CHIFFON_2         MK_RGB(238, 233, 191)
	#define X11_LEMONCHIFFON3           MK_RGB(205, 201, 165)
	#define X11_LEMON_CHIFFON_3         MK_RGB(205, 201, 165)
	#define X11_LEMONCHIFFON4           MK_RGB(139, 137, 112)
	#define X11_LEMON_CHIFFON_4         MK_RGB(139, 137, 112)
	#define X11_CORNSILK1               MK_RGB(255, 248, 220)
	#define X11_CORNSILK_1              MK_RGB(255, 248, 220)
	#define X11_CORNSILK2               MK_RGB(238, 232, 205)
	#define X11_CORNSILK_2              MK_RGB(238, 232, 205)
	#define X11_CORNSILK3               MK_RGB(205, 200, 177)
	#define X11_CORNSILK_3              MK_RGB(205, 200, 177)
	#define X11_CORNSILK4               MK_RGB(139, 136, 120)
	#define X11_CORNSILK_4              MK_RGB(139, 136, 120)
	#define X11_IVORY1                  MK_RGB(255, 255, 240)
	#define X11_IVORY_1                 MK_RGB(255, 255, 240)
	#define X11_IVORY2                  MK_RGB(238, 238, 224)
	#define X11_IVORY_2                 MK_RGB(238, 238, 224)
	#define X11_IVORY3                  MK_RGB(205, 205, 193)
	#define X11_IVORY_3                 MK_RGB(205, 205, 193)
	#define X11_IVORY4                  MK_RGB(139, 139, 131)
	#define X11_IVORY_4                 MK_RGB(139, 139, 131)
	#define X11_HONEYDEW1               MK_RGB(240, 255, 240)
	#define X11_HONEYDEW_1              MK_RGB(240, 255, 240)
	#define X11_HONEYDEW2               MK_RGB(224, 238, 224)
	#define X11_HONEYDEW_2              MK_RGB(224, 238, 224)
	#define X11_HONEYDEW3               MK_RGB(193, 205, 193)
	#define X11_HONEYDEW_3              MK_RGB(193, 205, 193)
	#define X11_HONEYDEW4               MK_RGB(131, 139, 131)
	#define X11_HONEYDEW_4              MK_RGB(131, 139, 131)
	#define X11_LAVENDERBLUSH1          MK_RGB(255, 240, 245)
	#define X11_LAVENDER_BLUSH_1        MK_RGB(255, 240, 245)
	#define X11_LAVENDERBLUSH2          MK_RGB(238, 224, 229)
	#define X11_LAVENDER_BLUSH_2        MK_RGB(238, 224, 229)
	#define X11_LAVENDERBLUSH3          MK_RGB(205, 193, 197)
	#define X11_LAVENDER_BLUSH_3        MK_RGB(205, 193, 197)
	#define X11_LAVENDERBLUSH4          MK_RGB(139, 131, 134)
	#define X11_LAVENDER_BLUSH_4        MK_RGB(139, 131, 134)
	#define X11_MISTYROSE1              MK_RGB(255, 228, 225)
	#define X11_MISTY_ROSE_1            MK_RGB(255, 228, 225)
	#define X11_MISTYROSE2              MK_RGB(238, 213, 210)
	#define X11_MISTY_ROSE_2            MK_RGB(238, 213, 210)
	#define X11_MISTYROSE3              MK_RGB(205, 183, 181)
	#define X11_MISTY_ROSE_3            MK_RGB(205, 183, 181)
	#define X11_MISTYROSE4              MK_RGB(139, 125, 123)
	#define X11_MISTY_ROSE_4            MK_RGB(139, 125, 123)
	#define X11_AZURE1                  MK_RGB(240, 255, 255)
	#define X11_AZURE_1                 MK_RGB(240, 255, 255)
	#define X11_AZURE2                  MK_RGB(224, 238, 238)
	#define X11_AZURE_2                 MK_RGB(224, 238, 238)
	#define X11_AZURE3                  MK_RGB(193, 205, 205)
	#define X11_AZURE_3                 MK_RGB(193, 205, 205)
	#define X11_AZURE4                  MK_RGB(131, 139, 139)
	#define X11_AZURE_4                 MK_RGB(131, 139, 139)
	#define X11_SLATEBLUE1              MK_RGB(131, 111, 255)
	#define X11_SLATE_BLUE_1            MK_RGB(131, 111, 255)
	#define X11_SLATEBLUE2              MK_RGB(122, 103, 238)
	#define X11_SLATE_BLUE_2            MK_RGB(122, 103, 238)
	#define X11_SLATEBLUE3              MK_RGB(105,  89, 205)
	#define X11_SLATE_BLUE_3            MK_RGB(105,  89, 205)
	#define X11_SLATEBLUE4              MK_RGB( 71,  60, 139)
	#define X11_SLATE_BLUE_4            MK_RGB( 71,  60, 139)
	#define X11_ROYALBLUE1              MK_RGB( 72, 118, 255)
	#define X11_ROYAL_BLUE_1            MK_RGB( 72, 118, 255)
	#define X11_ROYALBLUE2              MK_RGB( 67, 110, 238)
	#define X11_ROYAL_BLUE_2            MK_RGB( 67, 110, 238)
	#define X11_ROYALBLUE3              MK_RGB( 58,  95, 205)
	#define X11_ROYAL_BLUE_3            MK_RGB( 58,  95, 205)
	#define X11_ROYALBLUE4              MK_RGB( 39,  64, 139)
	#define X11_ROYAL_BLUE_4            MK_RGB( 39,  64, 139)
	#define X11_BLUE1                   MK_RGB(  0,   0, 255)
	#define X11_BLUE_1                  MK_RGB(  0,   0, 255)
	#define X11_BLUE2                   MK_RGB(  0,   0, 238)
	#define X11_BLUE_2                  MK_RGB(  0,   0, 238)
	#define X11_BLUE3                   MK_RGB(  0,   0, 205)
	#define X11_BLUE_3                  MK_RGB(  0,   0, 205)
	#define X11_BLUE4                   MK_RGB(  0,   0, 139)
	#define X11_BLUE_4                  MK_RGB(  0,   0, 139)
	#define X11_DODGERBLUE1             MK_RGB( 30, 144, 255)
	#define X11_DODGER_BLUE_1           MK_RGB( 30, 144, 255)
	#define X11_DODGERBLUE2             MK_RGB( 28, 134, 238)
	#define X11_DODGER_BLUE_2           MK_RGB( 28, 134, 238)
	#define X11_DODGERBLUE3             MK_RGB( 24, 116, 205)
	#define X11_DODGER_BLUE_3           MK_RGB( 24, 116, 205)
	#define X11_DODGERBLUE4             MK_RGB( 16,  78, 139)
	#define X11_DODGER_BLUE_4           MK_RGB( 16,  78, 139)
	#define X11_STEELBLUE1              MK_RGB( 99, 184, 255)
	#define X11_STEEL_BLUE_1            MK_RGB( 99, 184, 255)
	#define X11_STEELBLUE2              MK_RGB( 92, 172, 238)
	#define X11_STEEL_BLUE_2            MK_RGB( 92, 172, 238)
	#define X11_STEELBLUE3              MK_RGB( 79, 148, 205)
	#define X11_STEEL_BLUE_3            MK_RGB( 79, 148, 205)
	#define X11_STEELBLUE4              MK_RGB( 54, 100, 139)
	#define X11_STEEL_BLUE_4            MK_RGB( 54, 100, 139)
	#define X11_DEEPSKYBLUE1            MK_RGB(  0, 191, 255)
	#define X11_DEEP_SKY_BLUE_1         MK_RGB(  0, 191, 255)
	#define X11_DEEPSKYBLUE2            MK_RGB(  0, 178, 238)
	#define X11_DEEP_SKY_BLUE_2         MK_RGB(  0, 178, 238)
	#define X11_DEEPSKYBLUE3            MK_RGB(  0, 154, 205)
	#define X11_DEEP_SKY_BLUE_3         MK_RGB(  0, 154, 205)
	#define X11_DEEPSKYBLUE4            MK_RGB(  0, 104, 139)
	#define X11_DEEP_SKY_BLUE_4         MK_RGB(  0, 104, 139)
	#define X11_SKYBLUE1                MK_RGB(135, 206, 255)
	#define X11_SKY_BLUE_1              MK_RGB(135, 206, 255)
	#define X11_SKYBLUE2                MK_RGB(126, 192, 238)
	#define X11_SKY_BLUE_2              MK_RGB(126, 192, 238)
	#define X11_SKYBLUE3                MK_RGB(108, 166, 205)
	#define X11_SKY_BLUE_3              MK_RGB(108, 166, 205)
	#define X11_SKYBLUE4                MK_RGB( 74, 112, 139)
	#define X11_SKY_BLUE_4              MK_RGB( 74, 112, 139)
	#define X11_LIGHTSKYBLUE1           MK_RGB(176, 226, 255)
	#define X11_LIGHT_SKY_BLUE_1        MK_RGB(176, 226, 255)
	#define X11_LIGHTSKYBLUE2           MK_RGB(164, 211, 238)
	#define X11_LIGHT_SKY_BLUE_2        MK_RGB(164, 211, 238)
	#define X11_LIGHTSKYBLUE3           MK_RGB(141, 182, 205)
	#define X11_LIGHT_SKY_BLUE_3        MK_RGB(141, 182, 205)
	#define X11_LIGHTSKYBLUE4           MK_RGB( 96, 123, 139)
	#define X11_LIGHT_SKY_BLUE_4        MK_RGB( 96, 123, 139)
	#define X11_SLATEGRAY1              MK_RGB(198, 226, 255)
	#define X11_SLATE_GRAY_1            MK_RGB(198, 226, 255)
	#define X11_SLATEGRAY2              MK_RGB(185, 211, 238)
	#define X11_SLATE_GRAY_2            MK_RGB(185, 211, 238)
	#define X11_SLATEGRAY3              MK_RGB(159, 182, 205)
	#define X11_SLATE_GRAY_3            MK_RGB(159, 182, 205)
	#define X11_SLATEGRAY4              MK_RGB(108, 123, 139)
	#define X11_SLATE_GRAY_4            MK_RGB(108, 123, 139)
	#define X11_LIGHTSTEELBLUE1         MK_RGB(202, 225, 255)
	#define X11_LIGHT_STEEL_BLUE_1      MK_RGB(202, 225, 255)
	#define X11_LIGHTSTEELBLUE2         MK_RGB(188, 210, 238)
	#define X11_LIGHT_STEEL_BLUE_2      MK_RGB(188, 210, 238)
	#define X11_LIGHTSTEELBLUE3         MK_RGB(162, 181, 205)
	#define X11_LIGHT_STEEL_BLUE_3      MK_RGB(162, 181, 205)
	#define X11_LIGHTSTEELBLUE4         MK_RGB(110, 123, 139)
	#define X11_LIGHT_STEEL_BLUE_4      MK_RGB(110, 123, 139)
	#define X11_LIGHTBLUE1              MK_RGB(191, 239, 255)
	#define X11_LIGHT_BLUE_1            MK_RGB(191, 239, 255)
	#define X11_LIGHTBLUE2              MK_RGB(178, 223, 238)
	#define X11_LIGHT_BLUE_2            MK_RGB(178, 223, 238)
	#define X11_LIGHTBLUE3              MK_RGB(154, 192, 205)
	#define X11_LIGHT_BLUE_3            MK_RGB(154, 192, 205)
	#define X11_LIGHTBLUE4              MK_RGB(104, 131, 139)
	#define X11_LIGHT_BLUE_4            MK_RGB(104, 131, 139)
	#define X11_LIGHTCYAN1              MK_RGB(224, 255, 255)
	#define X11_LIGHT_CYAN_1            MK_RGB(224, 255, 255)
	#define X11_LIGHTCYAN2              MK_RGB(209, 238, 238)
	#define X11_LIGHT_CYAN_2            MK_RGB(209, 238, 238)
	#define X11_LIGHTCYAN3              MK_RGB(180, 205, 205)
	#define X11_LIGHT_CYAN_3            MK_RGB(180, 205, 205)
	#define X11_LIGHTCYAN4              MK_RGB(122, 139, 139)
	#define X11_LIGHT_CYAN_4            MK_RGB(122, 139, 139)
	#define X11_PALETURQUOISE1          MK_RGB(187, 255, 255)
	#define X11_PALE_TURQUOISE_1        MK_RGB(187, 255, 255)
	#define X11_PALETURQUOISE2          MK_RGB(174, 238, 238)
	#define X11_PALE_TURQUOISE_2        MK_RGB(174, 238, 238)
	#define X11_PALETURQUOISE3          MK_RGB(150, 205, 205)
	#define X11_PALE_TURQUOISE_3        MK_RGB(150, 205, 205)
	#define X11_PALETURQUOISE4          MK_RGB(102, 139, 139)
	#define X11_PALE_TURQUOISE_4        MK_RGB(102, 139, 139)
	#define X11_CADETBLUE1              MK_RGB(152, 245, 255)
	#define X11_CADET_BLUE_1            MK_RGB(152, 245, 255)
	#define X11_CADETBLUE2              MK_RGB(142, 229, 238)
	#define X11_CADET_BLUE_2            MK_RGB(142, 229, 238)
	#define X11_CADETBLUE3              MK_RGB(122, 197, 205)
	#define X11_CADET_BLUE_3            MK_RGB(122, 197, 205)
	#define X11_CADETBLUE4              MK_RGB( 83, 134, 139)
	#define X11_CADET_BLUE_4            MK_RGB( 83, 134, 139)
	#define X11_TURQUOISE1              MK_RGB(  0, 245, 255)
	#define X11_TURQUOISE_1             MK_RGB(  0, 245, 255)
	#define X11_TURQUOISE2              MK_RGB(  0, 229, 238)
	#define X11_TURQUOISE_2             MK_RGB(  0, 229, 238)
	#define X11_TURQUOISE3              MK_RGB(  0, 197, 205)
	#define X11_TURQUOISE_3             MK_RGB(  0, 197, 205)
	#define X11_TURQUOISE4              MK_RGB(  0, 134, 139)
	#define X11_TURQUOISE_4             MK_RGB(  0, 134, 139)
	#define X11_CYAN1                   MK_RGB(  0, 255, 255)
	#define X11_CYAN_1                  MK_RGB(  0, 255, 255)
	#define X11_CYAN2                   MK_RGB(  0, 238, 238)
	#define X11_CYAN_2                  MK_RGB(  0, 238, 238)
	#define X11_CYAN3                   MK_RGB(  0, 205, 205)
	#define X11_CYAN_3                  MK_RGB(  0, 205, 205)
	#define X11_CYAN4                   MK_RGB(  0, 139, 139)
	#define X11_CYAN_4                  MK_RGB(  0, 139, 139)
	#define X11_DARKSLATEGRAY1          MK_RGB(151, 255, 255)
	#define X11_DARK_SLATE_GRAY_1       MK_RGB(151, 255, 255)
	#define X11_DARKSLATEGRAY2          MK_RGB(141, 238, 238)
	#define X11_DARK_SLATE_GRAY_2       MK_RGB(141, 238, 238)
	#define X11_DARKSLATEGRAY3          MK_RGB(121, 205, 205)
	#define X11_DARK_SLATE_GRAY_3       MK_RGB(121, 205, 205)
	#define X11_DARKSLATEGRAY4          MK_RGB( 82, 139, 139)
	#define X11_DARK_SLATE_GRAY_4       MK_RGB( 82, 139, 139)
	#define X11_AQUAMARINE1             MK_RGB(127, 255, 212)
	#define X11_AQUAMARINE_1            MK_RGB(127, 255, 212)
	#define X11_AQUAMARINE2             MK_RGB(118, 238, 198)
	#define X11_AQUAMARINE_2            MK_RGB(118, 238, 198)
	#define X11_AQUAMARINE3             MK_RGB(102, 205, 170)
	#define X11_AQUAMARINE_3            MK_RGB(102, 205, 170)
	#define X11_AQUAMARINE4             MK_RGB( 69, 139, 116)
	#define X11_AQUAMARINE_4            MK_RGB( 69, 139, 116)
	#define X11_DARKSEAGREEN1           MK_RGB(193, 255, 193)
	#define X11_DARK_SEA_GREEN_1        MK_RGB(193, 255, 193)
	#define X11_DARKSEAGREEN2           MK_RGB(180, 238, 180)
	#define X11_DARK_SEA_GREEN_2        MK_RGB(180, 238, 180)
	#define X11_DARKSEAGREEN3           MK_RGB(155, 205, 155)
	#define X11_DARK_SEA_GREEN_3        MK_RGB(155, 205, 155)
	#define X11_DARKSEAGREEN4           MK_RGB(105, 139, 105)
	#define X11_DARK_SEA_GREEN_4        MK_RGB(105, 139, 105)
	#define X11_SEAGREEN1               MK_RGB( 84, 255, 159)
	#define X11_SEA_GREEN_1             MK_RGB( 84, 255, 159)
	#define X11_SEAGREEN2               MK_RGB( 78, 238, 148)
	#define X11_SEA_GREEN_2             MK_RGB( 78, 238, 148)
	#define X11_SEAGREEN3               MK_RGB( 67, 205, 128)
	#define X11_SEA_GREEN_3             MK_RGB( 67, 205, 128)
	#define X11_SEAGREEN4               MK_RGB( 46, 139,  87)
	#define X11_SEA_GREEN_4             MK_RGB( 46, 139,  87)
	#define X11_PALEGREEN1              MK_RGB(154, 255, 154)
	#define X11_PALE_GREEN_1            MK_RGB(154, 255, 154)
	#define X11_PALEGREEN2              MK_RGB(144, 238, 144)
	#define X11_PALE_GREEN_2            MK_RGB(144, 238, 144)
	#define X11_PALEGREEN3              MK_RGB(124, 205, 124)
	#define X11_PALE_GREEN_3            MK_RGB(124, 205, 124)
	#define X11_PALEGREEN4              MK_RGB( 84, 139,  84)
	#define X11_PALE_GREEN_4            MK_RGB( 84, 139,  84)
	#define X11_SPRINGGREEN1            MK_RGB(  0, 255, 127)
	#define X11_SPRING_GREEN_1          MK_RGB(  0, 255, 127)
	#define X11_SPRINGGREEN2            MK_RGB(  0, 238, 118)
	#define X11_SPRING_GREEN_2          MK_RGB(  0, 238, 118)
	#define X11_SPRINGGREEN3            MK_RGB(  0, 205, 102)
	#define X11_SPRING_GREEN_3          MK_RGB(  0, 205, 102)
	#define X11_SPRINGGREEN4            MK_RGB(  0, 139,  69)
	#define X11_SPRING_GREEN_4          MK_RGB(  0, 139,  69)
	#define X11_GREEN1                  MK_RGB(  0, 255,   0)
	#define X11_GREEN_1                 MK_RGB(  0, 255,   0)
	#define X11_GREEN2                  MK_RGB(  0, 238,   0)
	#define X11_GREEN_2                 MK_RGB(  0, 238,   0)
	#define X11_GREEN3                  MK_RGB(  0, 205,   0)
	#define X11_GREEN_3                 MK_RGB(  0, 205,   0)
	#define X11_GREEN4                  MK_RGB(  0, 139,   0)
	#define X11_GREEN_4                 MK_RGB(  0, 139,   0)
	#define X11_CHARTREUSE1             MK_RGB(127, 255,   0)
	#define X11_CHARTREUSE_1            MK_RGB(127, 255,   0)
	#define X11_CHARTREUSE2             MK_RGB(118, 238,   0)
	#define X11_CHARTREUSE_2            MK_RGB(118, 238,   0)
	#define X11_CHARTREUSE3             MK_RGB(102, 205,   0)
	#define X11_CHARTREUSE_3            MK_RGB(102, 205,   0)
	#define X11_CHARTREUSE4             MK_RGB( 69, 139,   0)
	#define X11_CHARTREUSE_4            MK_RGB( 69, 139,   0)
	#define X11_OLIVEDRAB1              MK_RGB(192, 255,  62)
	#define X11_OLIVE_DRAB_1            MK_RGB(192, 255,  62)
	#define X11_OLIVEDRAB2              MK_RGB(179, 238,  58)
	#define X11_OLIVE_DRAB_2            MK_RGB(179, 238,  58)
	#define X11_OLIVEDRAB3              MK_RGB(154, 205,  50)
	#define X11_OLIVE_DRAB_3            MK_RGB(154, 205,  50)
	#define X11_OLIVEDRAB4              MK_RGB(105, 139,  34)
	#define X11_OLIVE_DRAB_4            MK_RGB(105, 139,  34)
	#define X11_DARKOLIVEGREEN1         MK_RGB(202, 255, 112)
	#define X11_DARK_OLIVE_GREEN_1      MK_RGB(202, 255, 112)
	#define X11_DARKOLIVEGREEN2         MK_RGB(188, 238, 104)
	#define X11_DARK_OLIVE_GREEN_2      MK_RGB(188, 238, 104)
	#define X11_DARKOLIVEGREEN3         MK_RGB(162, 205,  90)
	#define X11_DARK_OLIVE_GREEN_3      MK_RGB(162, 205,  90)
	#define X11_DARKOLIVEGREEN4         MK_RGB(110, 139,  61)
	#define X11_DARK_OLIVE_GREEN_4      MK_RGB(110, 139,  61)
	#define X11_KHAKI1                  MK_RGB(255, 246, 143)
	#define X11_KHAKI_1                 MK_RGB(255, 246, 143)
	#define X11_KHAKI2                  MK_RGB(238, 230, 133)
	#define X11_KHAKI_2                 MK_RGB(238, 230, 133)
	#define X11_KHAKI3                  MK_RGB(205, 198, 115)
	#define X11_KHAKI_3                 MK_RGB(205, 198, 115)
	#define X11_KHAKI4                  MK_RGB(139, 134,  78)
	#define X11_KHAKI_4                 MK_RGB(139, 134,  78)
	#define X11_LIGHTGOLDENROD1         MK_RGB(255, 236, 139)
	#define X11_LIGHT_GOLDENROD_1       MK_RGB(255, 236, 139)
	#define X11_LIGHTGOLDENROD2         MK_RGB(238, 220, 130)
	#define X11_LIGHT_GOLDENROD_2       MK_RGB(238, 220, 130)
	#define X11_LIGHTGOLDENROD3         MK_RGB(205, 190, 112)
	#define X11_LIGHT_GOLDENROD_3       MK_RGB(205, 190, 112)
	#define X11_LIGHTGOLDENROD4         MK_RGB(139, 129,  76)
	#define X11_LIGHT_GOLDENROD_4       MK_RGB(139, 129,  76)
	#define X11_LIGHTYELLOW1            MK_RGB(255, 255, 224)
	#define X11_LIGHT_YELLOW_1          MK_RGB(255, 255, 224)
	#define X11_LIGHTYELLOW2            MK_RGB(238, 238, 209)
	#define X11_LIGHT_YELLOW_2          MK_RGB(238, 238, 209)
	#define X11_LIGHTYELLOW3            MK_RGB(205, 205, 180)
	#define X11_LIGHT_YELLOW_3          MK_RGB(205, 205, 180)
	#define X11_LIGHTYELLOW4            MK_RGB(139, 139, 122)
	#define X11_LIGHT_YELLOW_4          MK_RGB(139, 139, 122)
	#define X11_YELLOW1                 MK_RGB(255, 255,   0)
	#define X11_YELLOW_1                MK_RGB(255, 255,   0)
	#define X11_YELLOW2                 MK_RGB(238, 238,   0)
	#define X11_YELLOW_2                MK_RGB(238, 238,   0)
	#define X11_YELLOW3                 MK_RGB(205, 205,   0)
	#define X11_YELLOW_3                MK_RGB(205, 205,   0)
	#define X11_YELLOW4                 MK_RGB(139, 139,   0)
	#define X11_YELLOW_4                MK_RGB(139, 139,   0)
	#define X11_GOLD1                   MK_RGB(255, 215,   0)
	#define X11_GOLD_1                  MK_RGB(255, 215,   0)
	#define X11_GOLD2                   MK_RGB(238, 201,   0)
	#define X11_GOLD_2                  MK_RGB(238, 201,   0)
	#define X11_GOLD3                   MK_RGB(205, 173,   0)
	#define X11_GOLD_3                  MK_RGB(205, 173,   0)
	#define X11_GOLD4                   MK_RGB(139, 117,   0)
	#define X11_GOLD_4                  MK_RGB(139, 117,   0)
	#define X11_GOLDENROD1              MK_RGB(255, 193,  37)
	#define X11_GOLDENROD_1             MK_RGB(255, 193,  37)
	#define X11_GOLDENROD2              MK_RGB(238, 180,  34)
	#define X11_GOLDENROD_2             MK_RGB(238, 180,  34)
	#define X11_GOLDENROD3              MK_RGB(205, 155,  29)
	#define X11_GOLDENROD_3             MK_RGB(205, 155,  29)
	#define X11_GOLDENROD4              MK_RGB(139, 105,  20)
	#define X11_GOLDENROD_4             MK_RGB(139, 105,  20)
	#define X11_DARKGOLDENROD1          MK_RGB(255, 185,  15)
	#define X11_DARK_GOLDENROD_1        MK_RGB(255, 185,  15)
	#define X11_DARKGOLDENROD2          MK_RGB(238, 173,  14)
	#define X11_DARK_GOLDENROD_2        MK_RGB(238, 173,  14)
	#define X11_DARKGOLDENROD3          MK_RGB(205, 149,  12)
	#define X11_DARK_GOLDENROD_3        MK_RGB(205, 149,  12)
	#define X11_DARKGOLDENROD4          MK_RGB(139, 101,   8)
	#define X11_DARK_GOLDENROD_4        MK_RGB(139, 101,   8)
	#define X11_ROSYBROWN1              MK_RGB(255, 193, 193)
	#define X11_ROSY_BROWN_1            MK_RGB(255, 193, 193)
	#define X11_ROSYBROWN2              MK_RGB(238, 180, 180)
	#define X11_ROSY_BROWN_2            MK_RGB(238, 180, 180)
	#define X11_ROSYBROWN3              MK_RGB(205, 155, 155)
	#define X11_ROSY_BROWN_3            MK_RGB(205, 155, 155)
	#define X11_ROSYBROWN4              MK_RGB(139, 105, 105)
	#define X11_ROSY_BROWN_4            MK_RGB(139, 105, 105)
	#define X11_INDIANRED1              MK_RGB(255, 106, 106)
	#define X11_INDIAN_RED_1            MK_RGB(255, 106, 106)
	#define X11_INDIANRED2              MK_RGB(238,  99,  99)
	#define X11_INDIAN_RED_2            MK_RGB(238,  99,  99)
	#define X11_INDIANRED3              MK_RGB(205,  85,  85)
	#define X11_INDIAN_RED_3            MK_RGB(205,  85,  85)
	#define X11_INDIANRED4              MK_RGB(139,  58,  58)
	#define X11_INDIAN_RED_4            MK_RGB(139,  58,  58)
	#define X11_SIENNA1                 MK_RGB(255, 130,  71)
	#define X11_SIENNA_1                MK_RGB(255, 130,  71)
	#define X11_SIENNA2                 MK_RGB(238, 121,  66)
	#define X11_SIENNA_2                MK_RGB(238, 121,  66)
	#define X11_SIENNA3                 MK_RGB(205, 104,  57)
	#define X11_SIENNA_3                MK_RGB(205, 104,  57)
	#define X11_SIENNA4                 MK_RGB(139,  71,  38)
	#define X11_SIENNA_4                MK_RGB(139,  71,  38)
	#define X11_BURLYWOOD1              MK_RGB(255, 211, 155)
	#define X11_BURLYWOOD_1             MK_RGB(255, 211, 155)
	#define X11_BURLYWOOD2              MK_RGB(238, 197, 145)
	#define X11_BURLYWOOD_2             MK_RGB(238, 197, 145)
	#define X11_BURLYWOOD3              MK_RGB(205, 170, 125)
	#define X11_BURLYWOOD_3             MK_RGB(205, 170, 125)
	#define X11_BURLYWOOD4              MK_RGB(139, 115,  85)
	#define X11_BURLYWOOD_4             MK_RGB(139, 115,  85)
	#define X11_WHEAT1                  MK_RGB(255, 231, 186)
	#define X11_WHEAT_1                 MK_RGB(255, 231, 186)
	#define X11_WHEAT2                  MK_RGB(238, 216, 174)
	#define X11_WHEAT_2                 MK_RGB(238, 216, 174)
	#define X11_WHEAT3                  MK_RGB(205, 186, 150)
	#define X11_WHEAT_3                 MK_RGB(205, 186, 150)
	#define X11_WHEAT4                  MK_RGB(139, 126, 102)
	#define X11_WHEAT_4                 MK_RGB(139, 126, 102)
	#define X11_TAN1                    MK_RGB(255, 165,  79)
	#define X11_TAN_1                   MK_RGB(255, 165,  79)
	#define X11_TAN2                    MK_RGB(238, 154,  73)
	#define X11_TAN_2                   MK_RGB(238, 154,  73)
	#define X11_TAN3                    MK_RGB(205, 133,  63)
	#define X11_TAN_3                   MK_RGB(205, 133,  63)
	#define X11_TAN4                    MK_RGB(139,  90,  43)
	#define X11_TAN_4                   MK_RGB(139,  90,  43)
	#define X11_CHOCOLATE1              MK_RGB(255, 127,  36)
	#define X11_CHOCOLATE_1             MK_RGB(255, 127,  36)
	#define X11_CHOCOLATE2              MK_RGB(238, 118,  33)
	#define X11_CHOCOLATE_2             MK_RGB(238, 118,  33)
	#define X11_CHOCOLATE3              MK_RGB(205, 102,  29)
	#define X11_CHOCOLATE_3             MK_RGB(205, 102,  29)
	#define X11_CHOCOLATE4              MK_RGB(139,  69,  19)
	#define X11_CHOCOLATE_4             MK_RGB(139,  69,  19)
	#define X11_FIREBRICK1              MK_RGB(255,  48,  48)
	#define X11_FIREBRICK_1             MK_RGB(255,  48,  48)
	#define X11_FIREBRICK2              MK_RGB(238,  44,  44)
	#define X11_FIREBRICK_2             MK_RGB(238,  44,  44)
	#define X11_FIREBRICK3              MK_RGB(205,  38,  38)
	#define X11_FIREBRICK_3             MK_RGB(205,  38,  38)
	#define X11_FIREBRICK4              MK_RGB(139,  26,  26)
	#define X11_FIREBRICK_4             MK_RGB(139,  26,  26)
	#define X11_BROWN1                  MK_RGB(255,  64,  64)
	#define X11_BROWN_1                 MK_RGB(255,  64,  64)
	#define X11_BROWN2                  MK_RGB(238,  59,  59)
	#define X11_BROWN_2                 MK_RGB(238,  59,  59)
	#define X11_BROWN3                  MK_RGB(205,  51,  51)
	#define X11_BROWN_3                 MK_RGB(205,  51,  51)
	#define X11_BROWN4                  MK_RGB(139,  35,  35)
	#define X11_BROWN_4                 MK_RGB(139,  35,  35)
	#define X11_SALMON1                 MK_RGB(255, 140, 105)
	#define X11_SALMON_1                MK_RGB(255, 140, 105)
	#define X11_SALMON2                 MK_RGB(238, 130,  98)
	#define X11_SALMON_2                MK_RGB(238, 130,  98)
	#define X11_SALMON3                 MK_RGB(205, 112,  84)
	#define X11_SALMON_3                MK_RGB(205, 112,  84)
	#define X11_SALMON4                 MK_RGB(139,  76,  57)
	#define X11_SALMON_4                MK_RGB(139,  76,  57)
	#define X11_LIGHTSALMON1            MK_RGB(255, 160, 122)
	#define X11_LIGHT_SALMON_1          MK_RGB(255, 160, 122)
	#define X11_LIGHTSALMON2            MK_RGB(238, 149, 114)
	#define X11_LIGHT_SALMON_2          MK_RGB(238, 149, 114)
	#define X11_LIGHTSALMON3            MK_RGB(205, 129,  98)
	#define X11_LIGHT_SALMON_3          MK_RGB(205, 129,  98)
	#define X11_LIGHTSALMON4            MK_RGB(139,  87,  66)
	#define X11_LIGHT_SALMON_4          MK_RGB(139,  87,  66)
	#define X11_ORANGE1                 MK_RGB(255, 165,   0)
	#define X11_ORANGE_1                MK_RGB(255, 165,   0)
	#define X11_ORANGE2                 MK_RGB(238, 154,   0)
	#define X11_ORANGE_2                MK_RGB(238, 154,   0)
	#define X11_ORANGE3                 MK_RGB(205, 133,   0)
	#define X11_ORANGE_3                MK_RGB(205, 133,   0)
	#define X11_ORANGE4                 MK_RGB(139,  90,   0)
	#define X11_ORANGE_4                MK_RGB(139,  90,   0)
	#define X11_DARKORANGE1             MK_RGB(255, 127,   0)
	#define X11_DARK_ORANGE_1           MK_RGB(255, 127,   0)
	#define X11_DARKORANGE2             MK_RGB(238, 118,   0)
	#define X11_DARK_ORANGE_2           MK_RGB(238, 118,   0)
	#define X11_DARKORANGE3             MK_RGB(205, 102,   0)
	#define X11_DARK_ORANGE_3           MK_RGB(205, 102,   0)
	#define X11_DARKORANGE4             MK_RGB(139,  69,   0)
	#define X11_DARK_ORANGE_4           MK_RGB(139,  69,   0)
	#define X11_CORAL1                  MK_RGB(255, 114,  86)
	#define X11_CORAL_1                 MK_RGB(255, 114,  86)
	#define X11_CORAL2                  MK_RGB(238, 106,  80)
	#define X11_CORAL_2                 MK_RGB(238, 106,  80)
	#define X11_CORAL3                  MK_RGB(205,  91,  69)
	#define X11_CORAL_3                 MK_RGB(205,  91,  69)
	#define X11_CORAL4                  MK_RGB(139,  62,  47)
	#define X11_CORAL_4                 MK_RGB(139,  62,  47)
	#define X11_TOMATO1                 MK_RGB(255,  99,  71)
	#define X11_TOMATO_1                MK_RGB(255,  99,  71)
	#define X11_TOMATO2                 MK_RGB(238,  92,  66)
	#define X11_TOMATO_2                MK_RGB(238,  92,  66)
	#define X11_TOMATO3                 MK_RGB(205,  79,  57)
	#define X11_TOMATO_3                MK_RGB(205,  79,  57)
	#define X11_TOMATO4                 MK_RGB(139,  54,  38)
	#define X11_TOMATO_4                MK_RGB(139,  54,  38)
	#define X11_ORANGERED1              MK_RGB(255,  69,   0)
	#define X11_ORANGE_RED_1            MK_RGB(255,  69,   0)
	#define X11_ORANGERED2              MK_RGB(238,  64,   0)
	#define X11_ORANGE_RED_2            MK_RGB(238,  64,   0)
	#define X11_ORANGERED3              MK_RGB(205,  55,   0)
	#define X11_ORANGE_RED_3            MK_RGB(205,  55,   0)
	#define X11_ORANGERED4              MK_RGB(139,  37,   0)
	#define X11_ORANGE_RED_4            MK_RGB(139,  37,   0)
	#define X11_RED1                    MK_RGB(255,   0,   0)
	#define X11_RED_1                   MK_RGB(255,   0,   0)
	#define X11_RED2                    MK_RGB(238,   0,   0)
	#define X11_RED_2                   MK_RGB(238,   0,   0)
	#define X11_RED3                    MK_RGB(205,   0,   0)
	#define X11_RED_3                   MK_RGB(205,   0,   0)
	#define X11_RED4                    MK_RGB(139,   0,   0)
	#define X11_RED_4                   MK_RGB(139,   0,   0)
	#define X11_DEEPPINK1               MK_RGB(255,  20, 147)
	#define X11_DEEP_PINK_1             MK_RGB(255,  20, 147)
	#define X11_DEEPPINK2               MK_RGB(238,  18, 137)
	#define X11_DEEP_PINK_2             MK_RGB(238,  18, 137)
	#define X11_DEEPPINK3               MK_RGB(205,  16, 118)
	#define X11_DEEP_PINK_3             MK_RGB(205,  16, 118)
	#define X11_DEEPPINK4               MK_RGB(139,  10,  80)
	#define X11_DEEP_PINK_4             MK_RGB(139,  10,  80)
	#define X11_HOTPINK1                MK_RGB(255, 110, 180)
	#define X11_HOT_PINK_1              MK_RGB(255, 110, 180)
	#define X11_HOTPINK2                MK_RGB(238, 106, 167)
	#define X11_HOT_PINK_2              MK_RGB(238, 106, 167)
	#define X11_HOTPINK3                MK_RGB(205,  96, 144)
	#define X11_HOT_PINK_3              MK_RGB(205,  96, 144)
	#define X11_HOTPINK4                MK_RGB(139,  58,  98)
	#define X11_HOT_PINK_4              MK_RGB(139,  58,  98)
	#define X11_PINK1                   MK_RGB(255, 181, 197)
	#define X11_PINK_1                  MK_RGB(255, 181, 197)
	#define X11_PINK2                   MK_RGB(238, 169, 184)
	#define X11_PINK_2                  MK_RGB(238, 169, 184)
	#define X11_PINK3                   MK_RGB(205, 145, 158)
	#define X11_PINK_3                  MK_RGB(205, 145, 158)
	#define X11_PINK4                   MK_RGB(139,  99, 108)
	#define X11_PINK_4                  MK_RGB(139,  99, 108)
	#define X11_LIGHTPINK1              MK_RGB(255, 174, 185)
	#define X11_LIGHT_PINK_1            MK_RGB(255, 174, 185)
	#define X11_LIGHTPINK2              MK_RGB(238, 162, 173)
	#define X11_LIGHT_PINK_2            MK_RGB(238, 162, 173)
	#define X11_LIGHTPINK3              MK_RGB(205, 140, 149)
	#define X11_LIGHT_PINK_3            MK_RGB(205, 140, 149)
	#define X11_LIGHTPINK4              MK_RGB(139,  95, 101)
	#define X11_LIGHT_PINK_4            MK_RGB(139,  95, 101)
	#define X11_PALEVIOLETRED1          MK_RGB(255, 130, 171)
	#define X11_PALE_VIOLET_RED_1       MK_RGB(255, 130, 171)
	#define X11_PALEVIOLETRED2          MK_RGB(238, 121, 159)
	#define X11_PALE_VIOLET_RED_2       MK_RGB(238, 121, 159)
	#define X11_PALEVIOLETRED3          MK_RGB(205, 104, 137)
	#define X11_PALE_VIOLET_RED_3       MK_RGB(205, 104, 137)
	#define X11_PALEVIOLETRED4          MK_RGB(139,  71,  93)
	#define X11_PALE_VIOLET_RED_4       MK_RGB(139,  71,  93)
	#define X11_MAROON1                 MK_RGB(255,  52, 179)
	#define X11_MAROON_1                MK_RGB(255,  52, 179)
	#define X11_MAROON2                 MK_RGB(238,  48, 167)
	#define X11_MAROON_2                MK_RGB(238,  48, 167)
	#define X11_MAROON3                 MK_RGB(205,  41, 144)
	#define X11_MAROON_3                MK_RGB(205,  41, 144)
	#define X11_MAROON4                 MK_RGB(139,  28,  98)
	#define X11_MAROON_4                MK_RGB(139,  28,  98)
	#define X11_VIOLETRED1              MK_RGB(255,  62, 150)
	#define X11_VIOLET_RED_1            MK_RGB(255,  62, 150)
	#define X11_VIOLETRED2              MK_RGB(238,  58, 140)
	#define X11_VIOLET_RED_2            MK_RGB(238,  58, 140)
	#define X11_VIOLETRED3              MK_RGB(205,  50, 120)
	#define X11_VIOLET_RED_3            MK_RGB(205,  50, 120)
	#define X11_VIOLETRED4              MK_RGB(139,  34,  82)
	#define X11_VIOLET_RED_4            MK_RGB(139,  34,  82)
	#define X11_MAGENTA1                MK_RGB(255,   0, 255)
	#define X11_MAGENTA_1               MK_RGB(255,   0, 255)
	#define X11_MAGENTA2                MK_RGB(238,   0, 238)
	#define X11_MAGENTA_2               MK_RGB(238,   0, 238)
	#define X11_MAGENTA3                MK_RGB(205,   0, 205)
	#define X11_MAGENTA_3               MK_RGB(205,   0, 205)
	#define X11_MAGENTA4                MK_RGB(139,   0, 139)
	#define X11_MAGENTA_4               MK_RGB(139,   0, 139)
	#define X11_ORCHID1                 MK_RGB(255, 131, 250)
	#define X11_ORCHID_1                MK_RGB(255, 131, 250)
	#define X11_ORCHID2                 MK_RGB(238, 122, 233)
	#define X11_ORCHID_2                MK_RGB(238, 122, 233)
	#define X11_ORCHID3                 MK_RGB(205, 105, 201)
	#define X11_ORCHID_3                MK_RGB(205, 105, 201)
	#define X11_ORCHID4                 MK_RGB(139,  71, 137)
	#define X11_ORCHID_4                MK_RGB(139,  71, 137)
	#define X11_PLUM1                   MK_RGB(255, 187, 255)
	#define X11_PLUM_1                  MK_RGB(255, 187, 255)
	#define X11_PLUM2                   MK_RGB(238, 174, 238)
	#define X11_PLUM_2                  MK_RGB(238, 174, 238)
	#define X11_PLUM3                   MK_RGB(205, 150, 205)
	#define X11_PLUM_3                  MK_RGB(205, 150, 205)
	#define X11_PLUM4                   MK_RGB(139, 102, 139)
	#define X11_PLUM_4                  MK_RGB(139, 102, 139)
	#define X11_MEDIUMORCHID1           MK_RGB(224, 102, 255)
	#define X11_MEDIUM_ORCHID_1         MK_RGB(224, 102, 255)
	#define X11_MEDIUMORCHID2           MK_RGB(209,  95, 238)
	#define X11_MEDIUM_ORCHID_2         MK_RGB(209,  95, 238)
	#define X11_MEDIUMORCHID3           MK_RGB(180,  82, 205)
	#define X11_MEDIUM_ORCHID_3         MK_RGB(180,  82, 205)
	#define X11_MEDIUMORCHID4           MK_RGB(122,  55, 139)
	#define X11_MEDIUM_ORCHID_4         MK_RGB(122,  55, 139)
	#define X11_DARKORCHID1             MK_RGB(191,  62, 255)
	#define X11_DARK_ORCHID_1           MK_RGB(191,  62, 255)
	#define X11_DARKORCHID2             MK_RGB(178,  58, 238)
	#define X11_DARK_ORCHID_2           MK_RGB(178,  58, 238)
	#define X11_DARKORCHID3             MK_RGB(154,  50, 205)
	#define X11_DARK_ORCHID_3           MK_RGB(154,  50, 205)
	#define X11_DARKORCHID4             MK_RGB(104,  34, 139)
	#define X11_DARK_ORCHID_4           MK_RGB(104,  34, 139)
	#define X11_PURPLE1                 MK_RGB(155,  48, 255)
	#define X11_PURPLE_1                MK_RGB(155,  48, 255)
	#define X11_PURPLE2                 MK_RGB(145,  44, 238)
	#define X11_PURPLE_2                MK_RGB(145,  44, 238)
	#define X11_PURPLE3                 MK_RGB(125,  38, 205)
	#define X11_PURPLE_3                MK_RGB(125,  38, 205)
	#define X11_PURPLE4                 MK_RGB( 85,  26, 139)
	#define X11_PURPLE_4                MK_RGB( 85,  26, 139)
	#define X11_MEDIUMPURPLE1           MK_RGB(171, 130, 255)
	#define X11_MEDIUM_PURPLE_1         MK_RGB(171, 130, 255)
	#define X11_MEDIUMPURPLE2           MK_RGB(159, 121, 238)
	#define X11_MEDIUM_PURPLE_2         MK_RGB(159, 121, 238)
	#define X11_MEDIUMPURPLE3           MK_RGB(137, 104, 205)
	#define X11_MEDIUM_PURPLE_3         MK_RGB(137, 104, 205)
	#define X11_MEDIUMPURPLE4           MK_RGB( 93,  71, 139)
	#define X11_MEDIUM_PURPLE_4         MK_RGB( 93,  71, 139)
	#define X11_THISTLE1                MK_RGB(255, 225, 255)
	#define X11_THISTLE_1               MK_RGB(255, 225, 255)
	#define X11_THISTLE2                MK_RGB(238, 210, 238)
	#define X11_THISTLE_2               MK_RGB(238, 210, 238)
	#define X11_THISTLE3                MK_RGB(205, 181, 205)
	#define X11_THISTLE_3               MK_RGB(205, 181, 205)
	#define X11_THISTLE4                MK_RGB(139, 123, 139)
	#define X11_THISTLE_4               MK_RGB(139, 123, 139)
	#define X11_GRAY0                   MK_RGB(  0,   0,   0)
	#define X11_GRAY_0                  MK_RGB(  0,   0,   0)
	#define X11_GREY0                   MK_RGB(  0,   0,   0)
	#define X11_GREY_0                  MK_RGB(  0,   0,   0)
	#define X11_GRAY1                   MK_RGB(  3,   3,   3)
	#define X11_GRAY_1                  MK_RGB(  3,   3,   3)
	#define X11_GREY1                   MK_RGB(  3,   3,   3)
	#define X11_GREY_1                  MK_RGB(  3,   3,   3)
	#define X11_GRAY2                   MK_RGB(  5,   5,   5)
	#define X11_GRAY_2                  MK_RGB(  5,   5,   5)
	#define X11_GREY2                   MK_RGB(  5,   5,   5)
	#define X11_GREY_2                  MK_RGB(  5,   5,   5)
	#define X11_GRAY3                   MK_RGB(  8,   8,   8)
	#define X11_GRAY_3                  MK_RGB(  8,   8,   8)
	#define X11_GREY3                   MK_RGB(  8,   8,   8)
	#define X11_GREY_3                  MK_RGB(  8,   8,   8)
	#define X11_GRAY4                   MK_RGB( 10,  10,  10)
	#define X11_GRAY_4                  MK_RGB( 10,  10,  10)
	#define X11_GREY4                   MK_RGB( 10,  10,  10)
	#define X11_GREY_4                  MK_RGB( 10,  10,  10)
	#define X11_GRAY5                   MK_RGB( 13,  13,  13)
	#define X11_GRAY_5                  MK_RGB( 13,  13,  13)
	#define X11_GREY5                   MK_RGB( 13,  13,  13)
	#define X11_GREY_5                  MK_RGB( 13,  13,  13)
	#define X11_GRAY6                   MK_RGB( 15,  15,  15)
	#define X11_GRAY_6                  MK_RGB( 15,  15,  15)
	#define X11_GREY6                   MK_RGB( 15,  15,  15)
	#define X11_GREY_6                  MK_RGB( 15,  15,  15)
	#define X11_GRAY7                   MK_RGB( 18,  18,  18)
	#define X11_GRAY_7                  MK_RGB( 18,  18,  18)
	#define X11_GREY7                   MK_RGB( 18,  18,  18)
	#define X11_GREY_7                  MK_RGB( 18,  18,  18)
	#define X11_GRAY8                   MK_RGB( 20,  20,  20)
	#define X11_GRAY_8                  MK_RGB( 20,  20,  20)
	#define X11_GREY8                   MK_RGB( 20,  20,  20)
	#define X11_GREY_8                  MK_RGB( 20,  20,  20)
	#define X11_GRAY9                   MK_RGB( 23,  23,  23)
	#define X11_GRAY_9                  MK_RGB( 23,  23,  23)
	#define X11_GREY9                   MK_RGB( 23,  23,  23)
	#define X11_GREY_9                  MK_RGB( 23,  23,  23)
	#define X11_GRAY10                  MK_RGB( 26,  26,  26)
	#define X11_GRAY_10                 MK_RGB( 26,  26,  26)
	#define X11_GREY10                  MK_RGB( 26,  26,  26)
	#define X11_GREY_10                 MK_RGB( 26,  26,  26)
	#define X11_GRAY11                  MK_RGB( 28,  28,  28)
	#define X11_GRAY_11                 MK_RGB( 28,  28,  28)
	#define X11_GREY11                  MK_RGB( 28,  28,  28)
	#define X11_GREY_11                 MK_RGB( 28,  28,  28)
	#define X11_GRAY12                  MK_RGB( 31,  31,  31)
	#define X11_GRAY_12                 MK_RGB( 31,  31,  31)
	#define X11_GREY12                  MK_RGB( 31,  31,  31)
	#define X11_GREY_12                 MK_RGB( 31,  31,  31)
	#define X11_GRAY13                  MK_RGB( 33,  33,  33)
	#define X11_GRAY_13                 MK_RGB( 33,  33,  33)
	#define X11_GREY13                  MK_RGB( 33,  33,  33)
	#define X11_GREY_13                 MK_RGB( 33,  33,  33)
	#define X11_GRAY14                  MK_RGB( 36,  36,  36)
	#define X11_GRAY_14                 MK_RGB( 36,  36,  36)
	#define X11_GREY14                  MK_RGB( 36,  36,  36)
	#define X11_GREY_14                 MK_RGB( 36,  36,  36)
	#define X11_GRAY15                  MK_RGB( 38,  38,  38)
	#define X11_GRAY_15                 MK_RGB( 38,  38,  38)
	#define X11_GREY15                  MK_RGB( 38,  38,  38)
	#define X11_GREY_15                 MK_RGB( 38,  38,  38)
	#define X11_GRAY16                  MK_RGB( 41,  41,  41)
	#define X11_GRAY_16                 MK_RGB( 41,  41,  41)
	#define X11_GREY16                  MK_RGB( 41,  41,  41)
	#define X11_GREY_16                 MK_RGB( 41,  41,  41)
	#define X11_GRAY17                  MK_RGB( 43,  43,  43)
	#define X11_GRAY_17                 MK_RGB( 43,  43,  43)
	#define X11_GREY17                  MK_RGB( 43,  43,  43)
	#define X11_GREY_17                 MK_RGB( 43,  43,  43)
	#define X11_GRAY18                  MK_RGB( 46,  46,  46)
	#define X11_GRAY_18                 MK_RGB( 46,  46,  46)
	#define X11_GREY18                  MK_RGB( 46,  46,  46)
	#define X11_GREY_18                 MK_RGB( 46,  46,  46)
	#define X11_GRAY19                  MK_RGB( 48,  48,  48)
	#define X11_GRAY_19                 MK_RGB( 48,  48,  48)
	#define X11_GREY19                  MK_RGB( 48,  48,  48)
	#define X11_GREY_19                 MK_RGB( 48,  48,  48)
	#define X11_GRAY20                  MK_RGB( 51,  51,  51)
	#define X11_GRAY_20                 MK_RGB( 51,  51,  51)
	#define X11_GREY20                  MK_RGB( 51,  51,  51)
	#define X11_GREY_20                 MK_RGB( 51,  51,  51)
	#define X11_GRAY21                  MK_RGB( 54,  54,  54)
	#define X11_GRAY_21                 MK_RGB( 54,  54,  54)
	#define X11_GREY21                  MK_RGB( 54,  54,  54)
	#define X11_GREY_21                 MK_RGB( 54,  54,  54)
	#define X11_GRAY22                  MK_RGB( 56,  56,  56)
	#define X11_GRAY_22                 MK_RGB( 56,  56,  56)
	#define X11_GREY22                  MK_RGB( 56,  56,  56)
	#define X11_GREY_22                 MK_RGB( 56,  56,  56)
	#define X11_GRAY23                  MK_RGB( 59,  59,  59)
	#define X11_GRAY_23                 MK_RGB( 59,  59,  59)
	#define X11_GREY23                  MK_RGB( 59,  59,  59)
	#define X11_GREY_23                 MK_RGB( 59,  59,  59)
	#define X11_GRAY24                  MK_RGB( 61,  61,  61)
	#define X11_GRAY_24                 MK_RGB( 61,  61,  61)
	#define X11_GREY24                  MK_RGB( 61,  61,  61)
	#define X11_GREY_24                 MK_RGB( 61,  61,  61)
	#define X11_GRAY25                  MK_RGB( 64,  64,  64)
	#define X11_GRAY_25                 MK_RGB( 64,  64,  64)
	#define X11_GREY25                  MK_RGB( 64,  64,  64)
	#define X11_GREY_25                 MK_RGB( 64,  64,  64)
	#define X11_GRAY26                  MK_RGB( 66,  66,  66)
	#define X11_GRAY_26                 MK_RGB( 66,  66,  66)
	#define X11_GREY26                  MK_RGB( 66,  66,  66)
	#define X11_GREY_26                 MK_RGB( 66,  66,  66)
	#define X11_GRAY27                  MK_RGB( 69,  69,  69)
	#define X11_GRAY_27                 MK_RGB( 69,  69,  69)
	#define X11_GREY27                  MK_RGB( 69,  69,  69)
	#define X11_GREY_27                 MK_RGB( 69,  69,  69)
	#define X11_GRAY28                  MK_RGB( 71,  71,  71)
	#define X11_GRAY_28                 MK_RGB( 71,  71,  71)
	#define X11_GREY28                  MK_RGB( 71,  71,  71)
	#define X11_GREY_28                 MK_RGB( 71,  71,  71)
	#define X11_GRAY29                  MK_RGB( 74,  74,  74)
	#define X11_GRAY_29                 MK_RGB( 74,  74,  74)
	#define X11_GREY29                  MK_RGB( 74,  74,  74)
	#define X11_GREY_29                 MK_RGB( 74,  74,  74)
	#define X11_GRAY30                  MK_RGB( 77,  77,  77)
	#define X11_GRAY_30                 MK_RGB( 77,  77,  77)
	#define X11_GREY30                  MK_RGB( 77,  77,  77)
	#define X11_GREY_30                 MK_RGB( 77,  77,  77)
	#define X11_GRAY31                  MK_RGB( 79,  79,  79)
	#define X11_GRAY_31                 MK_RGB( 79,  79,  79)
	#define X11_GREY31                  MK_RGB( 79,  79,  79)
	#define X11_GREY_31                 MK_RGB( 79,  79,  79)
	#define X11_GRAY32                  MK_RGB( 82,  82,  82)
	#define X11_GRAY_32                 MK_RGB( 82,  82,  82)
	#define X11_GREY32                  MK_RGB( 82,  82,  82)
	#define X11_GREY_32                 MK_RGB( 82,  82,  82)
	#define X11_GRAY33                  MK_RGB( 84,  84,  84)
	#define X11_GRAY_33                 MK_RGB( 84,  84,  84)
	#define X11_GREY33                  MK_RGB( 84,  84,  84)
	#define X11_GREY_33                 MK_RGB( 84,  84,  84)
	#define X11_GRAY34                  MK_RGB( 87,  87,  87)
	#define X11_GRAY_34                 MK_RGB( 87,  87,  87)
	#define X11_GREY34                  MK_RGB( 87,  87,  87)
	#define X11_GREY_34                 MK_RGB( 87,  87,  87)
	#define X11_GRAY35                  MK_RGB( 89,  89,  89)
	#define X11_GRAY_35                 MK_RGB( 89,  89,  89)
	#define X11_GREY35                  MK_RGB( 89,  89,  89)
	#define X11_GREY_35                 MK_RGB( 89,  89,  89)
	#define X11_GRAY36                  MK_RGB( 92,  92,  92)
	#define X11_GRAY_36                 MK_RGB( 92,  92,  92)
	#define X11_GREY36                  MK_RGB( 92,  92,  92)
	#define X11_GREY_36                 MK_RGB( 92,  92,  92)
	#define X11_GRAY37                  MK_RGB( 94,  94,  94)
	#define X11_GRAY_37                 MK_RGB( 94,  94,  94)
	#define X11_GREY37                  MK_RGB( 94,  94,  94)
	#define X11_GREY_37                 MK_RGB( 94,  94,  94)
	#define X11_GRAY38                  MK_RGB( 97,  97,  97)
	#define X11_GRAY_38                 MK_RGB( 97,  97,  97)
	#define X11_GREY38                  MK_RGB( 97,  97,  97)
	#define X11_GREY_38                 MK_RGB( 97,  97,  97)
	#define X11_GRAY39                  MK_RGB( 99,  99,  99)
	#define X11_GRAY_39                 MK_RGB( 99,  99,  99)
	#define X11_GREY39                  MK_RGB( 99,  99,  99)
	#define X11_GREY_39                 MK_RGB( 99,  99,  99)
	#define X11_GRAY40                  MK_RGB(102, 102, 102)
	#define X11_GRAY_40                 MK_RGB(102, 102, 102)
	#define X11_GREY40                  MK_RGB(102, 102, 102)
	#define X11_GREY_40                 MK_RGB(102, 102, 102)
	#define X11_GRAY41                  MK_RGB(105, 105, 105)
	#define X11_GRAY_41                 MK_RGB(105, 105, 105)
	#define X11_GREY41                  MK_RGB(105, 105, 105)
	#define X11_GREY_41                 MK_RGB(105, 105, 105)
	#define X11_GRAY42                  MK_RGB(107, 107, 107)
	#define X11_GRAY_42                 MK_RGB(107, 107, 107)
	#define X11_GREY42                  MK_RGB(107, 107, 107)
	#define X11_GREY_42                 MK_RGB(107, 107, 107)
	#define X11_GRAY43                  MK_RGB(110, 110, 110)
	#define X11_GRAY_43                 MK_RGB(110, 110, 110)
	#define X11_GREY43                  MK_RGB(110, 110, 110)
	#define X11_GREY_43                 MK_RGB(110, 110, 110)
	#define X11_GRAY44                  MK_RGB(112, 112, 112)
	#define X11_GRAY_44                 MK_RGB(112, 112, 112)
	#define X11_GREY44                  MK_RGB(112, 112, 112)
	#define X11_GREY_44                 MK_RGB(112, 112, 112)
	#define X11_GRAY45                  MK_RGB(115, 115, 115)
	#define X11_GRAY_45                 MK_RGB(115, 115, 115)
	#define X11_GREY45                  MK_RGB(115, 115, 115)
	#define X11_GREY_45                 MK_RGB(115, 115, 115)
	#define X11_GRAY46                  MK_RGB(117, 117, 117)
	#define X11_GRAY_46                 MK_RGB(117, 117, 117)
	#define X11_GREY46                  MK_RGB(117, 117, 117)
	#define X11_GREY_46                 MK_RGB(117, 117, 117)
	#define X11_GRAY47                  MK_RGB(120, 120, 120)
	#define X11_GRAY_47                 MK_RGB(120, 120, 120)
	#define X11_GREY47                  MK_RGB(120, 120, 120)
	#define X11_GREY_47                 MK_RGB(120, 120, 120)
	#define X11_GRAY48                  MK_RGB(122, 122, 122)
	#define X11_GRAY_48                 MK_RGB(122, 122, 122)
	#define X11_GREY48                  MK_RGB(122, 122, 122)
	#define X11_GREY_48                 MK_RGB(122, 122, 122)
	#define X11_GRAY49                  MK_RGB(125, 125, 125)
	#define X11_GRAY_49                 MK_RGB(125, 125, 125)
	#define X11_GREY49                  MK_RGB(125, 125, 125)
	#define X11_GREY_49                 MK_RGB(125, 125, 125)
	#define X11_GRAY50                  MK_RGB(127, 127, 127)
	#define X11_GRAY_50                 MK_RGB(127, 127, 127)
	#define X11_GREY50                  MK_RGB(127, 127, 127)
	#define X11_GREY_50                 MK_RGB(127, 127, 127)
	#define X11_GRAY51                  MK_RGB(130, 130, 130)
	#define X11_GRAY_51                 MK_RGB(130, 130, 130)
	#define X11_GREY51                  MK_RGB(130, 130, 130)
	#define X11_GREY_51                 MK_RGB(130, 130, 130)
	#define X11_GRAY52                  MK_RGB(133, 133, 133)
	#define X11_GRAY_52                 MK_RGB(133, 133, 133)
	#define X11_GREY52                  MK_RGB(133, 133, 133)
	#define X11_GREY_52                 MK_RGB(133, 133, 133)
	#define X11_GRAY53                  MK_RGB(135, 135, 135)
	#define X11_GRAY_53                 MK_RGB(135, 135, 135)
	#define X11_GREY53                  MK_RGB(135, 135, 135)
	#define X11_GREY_53                 MK_RGB(135, 135, 135)
	#define X11_GRAY54                  MK_RGB(138, 138, 138)
	#define X11_GRAY_54                 MK_RGB(138, 138, 138)
	#define X11_GREY54                  MK_RGB(138, 138, 138)
	#define X11_GREY_54                 MK_RGB(138, 138, 138)
	#define X11_GRAY55                  MK_RGB(140, 140, 140)
	#define X11_GRAY_55                 MK_RGB(140, 140, 140)
	#define X11_GREY55                  MK_RGB(140, 140, 140)
	#define X11_GREY_55                 MK_RGB(140, 140, 140)
	#define X11_GRAY56                  MK_RGB(143, 143, 143)
	#define X11_GRAY_56                 MK_RGB(143, 143, 143)
	#define X11_GREY56                  MK_RGB(143, 143, 143)
	#define X11_GREY_56                 MK_RGB(143, 143, 143)
	#define X11_GRAY57                  MK_RGB(145, 145, 145)
	#define X11_GRAY_57                 MK_RGB(145, 145, 145)
	#define X11_GREY57                  MK_RGB(145, 145, 145)
	#define X11_GREY_57                 MK_RGB(145, 145, 145)
	#define X11_GRAY58                  MK_RGB(148, 148, 148)
	#define X11_GRAY_58                 MK_RGB(148, 148, 148)
	#define X11_GREY58                  MK_RGB(148, 148, 148)
	#define X11_GREY_58                 MK_RGB(148, 148, 148)
	#define X11_GRAY59                  MK_RGB(150, 150, 150)
	#define X11_GRAY_59                 MK_RGB(150, 150, 150)
	#define X11_GREY59                  MK_RGB(150, 150, 150)
	#define X11_GREY_59                 MK_RGB(150, 150, 150)
	#define X11_GRAY60                  MK_RGB(153, 153, 153)
	#define X11_GRAY_60                 MK_RGB(153, 153, 153)
	#define X11_GREY60                  MK_RGB(153, 153, 153)
	#define X11_GREY_60                 MK_RGB(153, 153, 153)
	#define X11_GRAY61                  MK_RGB(156, 156, 156)
	#define X11_GRAY_61                 MK_RGB(156, 156, 156)
	#define X11_GREY61                  MK_RGB(156, 156, 156)
	#define X11_GREY_61                 MK_RGB(156, 156, 156)
	#define X11_GRAY62                  MK_RGB(158, 158, 158)
	#define X11_GRAY_62                 MK_RGB(158, 158, 158)
	#define X11_GREY62                  MK_RGB(158, 158, 158)
	#define X11_GREY_62                 MK_RGB(158, 158, 158)
	#define X11_GRAY63                  MK_RGB(161, 161, 161)
	#define X11_GRAY_63                 MK_RGB(161, 161, 161)
	#define X11_GREY63                  MK_RGB(161, 161, 161)
	#define X11_GREY_63                 MK_RGB(161, 161, 161)
	#define X11_GRAY64                  MK_RGB(163, 163, 163)
	#define X11_GRAY_64                 MK_RGB(163, 163, 163)
	#define X11_GREY64                  MK_RGB(163, 163, 163)
	#define X11_GREY_64                 MK_RGB(163, 163, 163)
	#define X11_GRAY65                  MK_RGB(166, 166, 166)
	#define X11_GRAY_65                 MK_RGB(166, 166, 166)
	#define X11_GREY65                  MK_RGB(166, 166, 166)
	#define X11_GREY_65                 MK_RGB(166, 166, 166)
	#define X11_GRAY66                  MK_RGB(168, 168, 168)
	#define X11_GRAY_66                 MK_RGB(168, 168, 168)
	#define X11_GREY66                  MK_RGB(168, 168, 168)
	#define X11_GREY_66                 MK_RGB(168, 168, 168)
	#define X11_GRAY67                  MK_RGB(171, 171, 171)
	#define X11_GRAY_67                 MK_RGB(171, 171, 171)
	#define X11_GREY67                  MK_RGB(171, 171, 171)
	#define X11_GREY_67                 MK_RGB(171, 171, 171)
	#define X11_GRAY68                  MK_RGB(173, 173, 173)
	#define X11_GRAY_68                 MK_RGB(173, 173, 173)
	#define X11_GREY68                  MK_RGB(173, 173, 173)
	#define X11_GREY_68                 MK_RGB(173, 173, 173)
	#define X11_GRAY69                  MK_RGB(176, 176, 176)
	#define X11_GRAY_69                 MK_RGB(176, 176, 176)
	#define X11_GREY69                  MK_RGB(176, 176, 176)
	#define X11_GREY_69                 MK_RGB(176, 176, 176)
	#define X11_GRAY70                  MK_RGB(179, 179, 179)
	#define X11_GRAY_70                 MK_RGB(179, 179, 179)
	#define X11_GREY70                  MK_RGB(179, 179, 179)
	#define X11_GREY_70                 MK_RGB(179, 179, 179)
	#define X11_GRAY71                  MK_RGB(181, 181, 181)
	#define X11_GRAY_71                 MK_RGB(181, 181, 181)
	#define X11_GREY71                  MK_RGB(181, 181, 181)
	#define X11_GREY_71                 MK_RGB(181, 181, 181)
	#define X11_GRAY72                  MK_RGB(184, 184, 184)
	#define X11_GRAY_72                 MK_RGB(184, 184, 184)
	#define X11_GREY72                  MK_RGB(184, 184, 184)
	#define X11_GREY_72                 MK_RGB(184, 184, 184)
	#define X11_GRAY73                  MK_RGB(186, 186, 186)
	#define X11_GRAY_73                 MK_RGB(186, 186, 186)
	#define X11_GREY73                  MK_RGB(186, 186, 186)
	#define X11_GREY_73                 MK_RGB(186, 186, 186)
	#define X11_GRAY74                  MK_RGB(189, 189, 189)
	#define X11_GRAY_74                 MK_RGB(189, 189, 189)
	#define X11_GREY74                  MK_RGB(189, 189, 189)
	#define X11_GREY_74                 MK_RGB(189, 189, 189)
	#define X11_GRAY75                  MK_RGB(191, 191, 191)
	#define X11_GRAY_75                 MK_RGB(191, 191, 191)
	#define X11_GREY75                  MK_RGB(191, 191, 191)
	#define X11_GREY_75                 MK_RGB(191, 191, 191)
	#define X11_GRAY76                  MK_RGB(194, 194, 194)
	#define X11_GRAY_76                 MK_RGB(194, 194, 194)
	#define X11_GREY76                  MK_RGB(194, 194, 194)
	#define X11_GREY_76                 MK_RGB(194, 194, 194)
	#define X11_GRAY77                  MK_RGB(196, 196, 196)
	#define X11_GRAY_77                 MK_RGB(196, 196, 196)
	#define X11_GREY77                  MK_RGB(196, 196, 196)
	#define X11_GREY_77                 MK_RGB(196, 196, 196)
	#define X11_GRAY78                  MK_RGB(199, 199, 199)
	#define X11_GRAY_78                 MK_RGB(199, 199, 199)
	#define X11_GREY78                  MK_RGB(199, 199, 199)
	#define X11_GREY_78                 MK_RGB(199, 199, 199)
	#define X11_GRAY79                  MK_RGB(201, 201, 201)
	#define X11_GRAY_79                 MK_RGB(201, 201, 201)
	#define X11_GREY79                  MK_RGB(201, 201, 201)
	#define X11_GREY_79                 MK_RGB(201, 201, 201)
	#define X11_GRAY80                  MK_RGB(204, 204, 204)
	#define X11_GRAY_80                 MK_RGB(204, 204, 204)
	#define X11_GREY80                  MK_RGB(204, 204, 204)
	#define X11_GREY_80                 MK_RGB(204, 204, 204)
	#define X11_GRAY81                  MK_RGB(207, 207, 207)
	#define X11_GRAY_81                 MK_RGB(207, 207, 207)
	#define X11_GREY81                  MK_RGB(207, 207, 207)
	#define X11_GREY_81                 MK_RGB(207, 207, 207)
	#define X11_GRAY82                  MK_RGB(209, 209, 209)
	#define X11_GRAY_82                 MK_RGB(209, 209, 209)
	#define X11_GREY82                  MK_RGB(209, 209, 209)
	#define X11_GREY_82                 MK_RGB(209, 209, 209)
	#define X11_GRAY83                  MK_RGB(212, 212, 212)
	#define X11_GRAY_83                 MK_RGB(212, 212, 212)
	#define X11_GREY83                  MK_RGB(212, 212, 212)
	#define X11_GREY_83                 MK_RGB(212, 212, 212)
	#define X11_GRAY84                  MK_RGB(214, 214, 214)
	#define X11_GRAY_84                 MK_RGB(214, 214, 214)
	#define X11_GREY84                  MK_RGB(214, 214, 214)
	#define X11_GREY_84                 MK_RGB(214, 214, 214)
	#define X11_GRAY85                  MK_RGB(217, 217, 217)
	#define X11_GRAY_85                 MK_RGB(217, 217, 217)
	#define X11_GREY85                  MK_RGB(217, 217, 217)
	#define X11_GREY_85                 MK_RGB(217, 217, 217)
	#define X11_GRAY86                  MK_RGB(219, 219, 219)
	#define X11_GRAY_86                 MK_RGB(219, 219, 219)
	#define X11_GREY86                  MK_RGB(219, 219, 219)
	#define X11_GREY_86                 MK_RGB(219, 219, 219)
	#define X11_GRAY87                  MK_RGB(222, 222, 222)
	#define X11_GRAY_87                 MK_RGB(222, 222, 222)
	#define X11_GREY87                  MK_RGB(222, 222, 222)
	#define X11_GREY_87                 MK_RGB(222, 222, 222)
	#define X11_GRAY88                  MK_RGB(224, 224, 224)
	#define X11_GRAY_88                 MK_RGB(224, 224, 224)
	#define X11_GREY88                  MK_RGB(224, 224, 224)
	#define X11_GREY_88                 MK_RGB(224, 224, 224)
	#define X11_GRAY89                  MK_RGB(227, 227, 227)
	#define X11_GRAY_89                 MK_RGB(227, 227, 227)
	#define X11_GREY89                  MK_RGB(227, 227, 227)
	#define X11_GREY_89                 MK_RGB(227, 227, 227)
	#define X11_GRAY90                  MK_RGB(229, 229, 229)
	#define X11_GRAY_90                 MK_RGB(229, 229, 229)
	#define X11_GREY90                  MK_RGB(229, 229, 229)
	#define X11_GREY_90                 MK_RGB(229, 229, 229)
	#define X11_GRAY91                  MK_RGB(232, 232, 232)
	#define X11_GRAY_91                 MK_RGB(232, 232, 232)
	#define X11_GREY91                  MK_RGB(232, 232, 232)
	#define X11_GREY_91                 MK_RGB(232, 232, 232)
	#define X11_GRAY92                  MK_RGB(235, 235, 235)
	#define X11_GRAY_92                 MK_RGB(235, 235, 235)
	#define X11_GREY92                  MK_RGB(235, 235, 235)
	#define X11_GREY_92                 MK_RGB(235, 235, 235)
	#define X11_GRAY93                  MK_RGB(237, 237, 237)
	#define X11_GRAY_93                 MK_RGB(237, 237, 237)
	#define X11_GREY93                  MK_RGB(237, 237, 237)
	#define X11_GREY_93                 MK_RGB(237, 237, 237)
	#define X11_GRAY94                  MK_RGB(240, 240, 240)
	#define X11_GRAY_94                 MK_RGB(240, 240, 240)
	#define X11_GREY94                  MK_RGB(240, 240, 240)
	#define X11_GREY_94                 MK_RGB(240, 240, 240)
	#define X11_GRAY95                  MK_RGB(242, 242, 242)
	#define X11_GRAY_95                 MK_RGB(242, 242, 242)
	#define X11_GREY95                  MK_RGB(242, 242, 242)
	#define X11_GREY_95                 MK_RGB(242, 242, 242)
	#define X11_GRAY96                  MK_RGB(245, 245, 245)
	#define X11_GRAY_96                 MK_RGB(245, 245, 245)
	#define X11_GREY96                  MK_RGB(245, 245, 245)
	#define X11_GREY_96                 MK_RGB(245, 245, 245)
	#define X11_GRAY97                  MK_RGB(247, 247, 247)
	#define X11_GRAY_97                 MK_RGB(247, 247, 247)
	#define X11_GREY97                  MK_RGB(247, 247, 247)
	#define X11_GREY_97                 MK_RGB(247, 247, 247)
	#define X11_GRAY98                  MK_RGB(250, 250, 250)
	#define X11_GRAY_98                 MK_RGB(250, 250, 250)
	#define X11_GREY98                  MK_RGB(250, 250, 250)
	#define X11_GREY_98                 MK_RGB(250, 250, 250)
	#define X11_GRAY99                  MK_RGB(252, 252, 252)
	#define X11_GRAY_99                 MK_RGB(252, 252, 252)
	#define X11_GREY99                  MK_RGB(252, 252, 252)
	#define X11_GREY_99                 MK_RGB(252, 252, 252)
	#define X11_GRAY100                 MK_RGB(255, 255, 255)
	#define X11_GRAY_100                MK_RGB(255, 255, 255)
	#define X11_GREY100                 MK_RGB(255, 255, 255)
	#define X11_GREY_100                MK_RGB(255, 255, 255)
	#define X11_DARKGREY                MK_RGB(169, 169, 169)
	#define X11_DARK_GREY               MK_RGB(169, 169, 169)
	#define X11_DARKGRAY                MK_RGB(169, 169, 169)
	#define X11_DARK_GRAY               MK_RGB(169, 169, 169)
	#define X11_DARKBLUE                MK_RGB(  0,   0, 139)
	#define X11_DARK_BLUE               MK_RGB(  0,   0, 139)
	#define X11_DARKCYAN                MK_RGB(  0, 139, 139)
	#define X11_DARK_CYAN               MK_RGB(  0, 139, 139)
	#define X11_DARKMAGENTA             MK_RGB(139,   0, 139)
	#define X11_DARK_MAGENTA            MK_RGB(139,   0, 139)
	#define X11_DARKRED                 MK_RGB(139,   0,   0)
	#define X11_DARK_RED                MK_RGB(139,   0,   0)
	#define X11_LIGHTGREEN              MK_RGB(144, 238, 144)
	#define X11_LIGHT_GREEN             MK_RGB(144, 238, 144)
#endif

#define COLOUR_NAME_HASH(%0)            YHash((%0),false,hash_bernstein)
#define COLOR_NAME_HASH                 COLOUR_NAME_HASH

static stock
	YSI_g_sColours[MAX_TEXT_COLOURS][2];

#define SetColor SetColour
stock SetColour(const name[], color)
{
	return SetColourHash(COLOUR_NAME_HASH(name), color);
}

#define SetColorHash SetColourHash
stock SetColourHash(hash, color)
{
	color &= 0xFFFFFF00;
	#if !defined NO_X11_COLOURS && !defined NO_X11_COLORS
		new
			id = GetColourHash(hash);
		if (id != 0)
		{
			for (new i = 0; i != MAX_TEXT_COLOURS; ++i)
			{
				new
					iColor = YSI_g_sColours[i][0];
				if (iColor == hash)
				{
					YSI_g_sColours[i][1] = color;
					return i;
				}
				else if (iColor == 0)
				{
					// Tried to rename an X11 colour.
					return -1;
				}
			}
		}
	#endif
	for (new i = 0; i != MAX_TEXT_COLOURS; ++i)
	{
		new
			iColor = YSI_g_sColours[i][0];
		if (iColor == hash || iColor == 0)
		{
			YSI_g_sColours[i][0] = hash;
			YSI_g_sColours[i][1] = color;
			return i;
		}
	}
	return -1;
}

// This now uses REVERSE bernstein hash for switch compatibility.

#define GetColor GetColour
stock GetColour(const name[], alpha = 0xAA)
{
	return GetColourHash(COLOUR_NAME_HASH(name), alpha);
}

#define GetColorHash GetColourHash
stock GetColourHash(hash, alpha = 0xAA)
{
	alpha &= 0xFF;
	// Do the REVERSE hash from YHash
	#if !defined NO_X11_COLOURS && !defined NO_X11_COLORS
		switch (hash)
		{
			case _I(S,N,O,W):
				return alpha | X11_SNOW;
			case _I(G,H,O,S,T,W,H,I,T,E):
				return alpha | X11_GHOST_WHITE;
			case _I(G,H,O,S,T,_,W,H,I,T,E):
				return alpha | X11_GHOST_WHITE;
			case _I(G,H,O,S,T, ,W,H,I,T,E):
				return alpha | X11_GHOST_WHITE;
			case _I(W,H,I,T,E,S,M,O,K,E):
				return alpha | X11_WHITE_SMOKE;
			case _I(W,H,I,T,E,_,S,M,O,K,E):
				return alpha | X11_WHITE_SMOKE;
			case _I(W,H,I,T,E, ,S,M,O,K,E):
				return alpha | X11_WHITE_SMOKE;
			case _I(G,A,I,N,S,B,O,R,O):
				return alpha | X11_GAINSBORO;
			case _I(F,L,O,R,A,L,W,H,I,T,E):
				return alpha | X11_FLORAL_WHITE;
			case _I(F,L,O,R,A,L,_,W,H,I,T,E):
				return alpha | X11_FLORAL_WHITE;
			case _I(F,L,O,R,A,L, ,W,H,I,T,E):
				return alpha | X11_FLORAL_WHITE;
			case _I(O,L,D,L,A,C,E):
				return alpha | X11_OLD_LACE;
			case _I(O,L,D,_,L,A,C,E):
				return alpha | X11_OLD_LACE;
			case _I(O,L,D, ,L,A,C,E):
				return alpha | X11_OLD_LACE;
			case _I(L,I,N,E,N):
				return alpha | X11_LINEN;
			case _I(A,N,T,I,Q,U,E,W,H,I,T,E):
				return alpha | X11_ANTIQUE_WHITE;
			case _I(A,N,T,I,Q,U,E,_,W,H,I,T,E):
				return alpha | X11_ANTIQUE_WHITE;
			case _I(A,N,T,I,Q,U,E, ,W,H,I,T,E):
				return alpha | X11_ANTIQUE_WHITE;
			case _I(P,A,P,A,Y,A,W,H,I,P):
				return alpha | X11_PAPAYA_WHIP;
			case _I(P,A,P,A,Y,A,_,W,H,I,P):
				return alpha | X11_PAPAYA_WHIP;
			case _I(P,A,P,A,Y,A, ,W,H,I,P):
				return alpha | X11_PAPAYA_WHIP;
			case _I(B,L,A,N,C,H,E,D,A,L,M,O,N,D):
				return alpha | X11_BLANCHED_ALMOND;
			case _I(B,L,A,N,C,H,E,D,_,A,L,M,O,N,D):
				return alpha | X11_BLANCHED_ALMOND;
			case _I(B,L,A,N,C,H,E,D, ,A,L,M,O,N,D):
				return alpha | X11_BLANCHED_ALMOND;
			case _I(B,I,S,Q,U,E):
				return alpha | X11_BISQUE;
			case _I(P,E,A,C,H,P,U,F,F):
				return alpha | X11_PEACH_PUFF;
			case _I(P,E,A,C,H,_,P,U,F,F):
				return alpha | X11_PEACH_PUFF;
			case _I(P,E,A,C,H, ,P,U,F,F):
				return alpha | X11_PEACH_PUFF;
			case _I(N,A,V,A,J,O,W,H,I,T,E):
				return alpha | X11_NAVAJO_WHITE;
			case _I(N,A,V,A,J,O,_,W,H,I,T,E):
				return alpha | X11_NAVAJO_WHITE;
			case _I(N,A,V,A,J,O, ,W,H,I,T,E):
				return alpha | X11_NAVAJO_WHITE;
			case _I(M,O,C,C,A,S,I,N):
				return alpha | X11_MOCCASIN;
			case _I(C,O,R,N,S,I,L,K):
				return alpha | X11_CORNSILK;
			case _I(I,V,O,R,Y):
				return alpha | X11_IVORY;
			case _I(L,E,M,O,N,C,H,I,F,F,O,N):
				return alpha | X11_LEMON_CHIFFON;
			case _I(L,E,M,O,N,_,C,H,I,F,F,O,N):
				return alpha | X11_LEMON_CHIFFON;
			case _I(L,E,M,O,N, ,C,H,I,F,F,O,N):
				return alpha | X11_LEMON_CHIFFON;
			case _I(S,E,A,S,H,E,L,L):
				return alpha | X11_SEASHELL;
			case _I(H,O,N,E,Y,D,E,W):
				return alpha | X11_HONEYDEW;
			case _I(M,I,N,T,C,R,E,A,M):
				return alpha | X11_MINT_CREAM;
			case _I(M,I,N,T,_,C,R,E,A,M):
				return alpha | X11_MINT_CREAM;
			case _I(M,I,N,T, ,C,R,E,A,M):
				return alpha | X11_MINT_CREAM;
			case _I(A,Z,U,R,E):
				return alpha | X11_AZURE;
			case _I(A,L,I,C,E,B,L,U,E):
				return alpha | X11_ALICE_BLUE;
			case _I(A,L,I,C,E,_,B,L,U,E):
				return alpha | X11_ALICE_BLUE;
			case _I(A,L,I,C,E, ,B,L,U,E):
				return alpha | X11_ALICE_BLUE;
			case _I(L,A,V,E,N,D,E,R):
				return alpha | X11_LAVENDER;
			case _I(L,A,V,E,N,D,E,R,B,L,U,S,H):
				return alpha | X11_LAVENDER_BLUSH;
			case _I(L,A,V,E,N,D,E,R,_,B,L,U,S,H):
				return alpha | X11_LAVENDER_BLUSH;
			case _I(L,A,V,E,N,D,E,R, ,B,L,U,S,H):
				return alpha | X11_LAVENDER_BLUSH;
			case _I(M,I,S,T,Y,R,O,S,E):
				return alpha | X11_MISTY_ROSE;
			case _I(M,I,S,T,Y,_,R,O,S,E):
				return alpha | X11_MISTY_ROSE;
			case _I(M,I,S,T,Y, ,R,O,S,E):
				return alpha | X11_MISTY_ROSE;
			case _I(W,H,I,T,E):
				return alpha | X11_WHITE;
			case _I(B,L,A,C,K):
				return alpha | X11_BLACK;
			case _I(D,A,R,K,S,L,A,T,E,G,R,A,Y):
				return alpha | X11_DARK_SLATE_GRAY;
			case _I(D,A,R,K,_,S,L,A,T,E,_,G,R,A,Y):
				return alpha | X11_DARK_SLATE_GRAY;
			case _I(D,A,R,K, ,S,L,A,T,E, ,G,R,A,Y):
				return alpha | X11_DARK_SLATE_GRAY;
			case _I(D,A,R,K,S,L,A,T,E,G,R,E,Y):
				return alpha | X11_DARK_SLATE_GREY;
			case _I(D,A,R,K,_,S,L,A,T,E,_,G,R,E,Y):
				return alpha | X11_DARK_SLATE_GREY;
			case _I(D,A,R,K, ,S,L,A,T,E, ,G,R,E,Y):
				return alpha | X11_DARK_SLATE_GREY;
			case _I(D,I,M,G,R,A,Y):
				return alpha | X11_DIM_GRAY;
			case _I(D,I,M,_,G,R,A,Y):
				return alpha | X11_DIM_GRAY;
			case _I(D,I,M, ,G,R,A,Y):
				return alpha | X11_DIM_GRAY;
			case _I(D,I,M,G,R,E,Y):
				return alpha | X11_DIM_GREY;
			case _I(D,I,M,_,G,R,E,Y):
				return alpha | X11_DIM_GREY;
			case _I(D,I,M, ,G,R,E,Y):
				return alpha | X11_DIM_GREY;
			case _I(S,L,A,T,E,G,R,A,Y):
				return alpha | X11_SLATE_GRAY;
			case _I(S,L,A,T,E,_,G,R,A,Y):
				return alpha | X11_SLATE_GRAY;
			case _I(S,L,A,T,E, ,G,R,A,Y):
				return alpha | X11_SLATE_GRAY;
			case _I(S,L,A,T,E,G,R,E,Y):
				return alpha | X11_SLATE_GREY;
			case _I(S,L,A,T,E,_,G,R,E,Y):
				return alpha | X11_SLATE_GREY;
			case _I(S,L,A,T,E, ,G,R,E,Y):
				return alpha | X11_SLATE_GREY;
			case _I(L,I,G,H,T,S,L,A,T,E,G,R,A,Y):
				return alpha | X11_LIGHT_SLATE_GRAY;
			case _I(L,I,G,H,T,_,S,L,A,T,E,_,G,R,A,Y):
				return alpha | X11_LIGHT_SLATE_GRAY;
			case _I(L,I,G,H,T, ,S,L,A,T,E, ,G,R,A,Y):
				return alpha | X11_LIGHT_SLATE_GRAY;
			case _I(L,I,G,H,T,S,L,A,T,E,G,R,E,Y):
				return alpha | X11_LIGHT_SLATE_GREY;
			case _I(L,I,G,H,T,_,S,L,A,T,E,_,G,R,E,Y):
				return alpha | X11_LIGHT_SLATE_GREY;
			case _I(L,I,G,H,T, ,S,L,A,T,E, ,G,R,E,Y):
				return alpha | X11_LIGHT_SLATE_GREY;
			case _I(G,R,A,Y):
				return alpha | X11_GRAY;
			case _I(G,R,E,Y):
				return alpha | X11_GREY;
			case _I(L,I,G,H,T,G,R,E,Y):
				return alpha | X11_LIGHT_GREY;
			case _I(L,I,G,H,T,_,G,R,E,Y):
				return alpha | X11_LIGHT_GREY;
			case _I(L,I,G,H,T, ,G,R,E,Y):
				return alpha | X11_LIGHT_GREY;
			case _I(L,I,G,H,T,G,R,A,Y):
				return alpha | X11_LIGHT_GRAY;
			case _I(L,I,G,H,T,_,G,R,A,Y):
				return alpha | X11_LIGHT_GRAY;
			case _I(L,I,G,H,T, ,G,R,A,Y):
				return alpha | X11_LIGHT_GRAY;
			case _I(M,I,D,N,I,G,H,T,B,L,U,E):
				return alpha | X11_MIDNIGHT_BLUE;
			case _I(M,I,D,N,I,G,H,T,_,B,L,U,E):
				return alpha | X11_MIDNIGHT_BLUE;
			case _I(M,I,D,N,I,G,H,T, ,B,L,U,E):
				return alpha | X11_MIDNIGHT_BLUE;
			case _I(N,A,V,Y):
				return alpha | X11_NAVY;
			case _I(N,A,V,Y,B,L,U,E):
				return alpha | X11_NAVY_BLUE;
			case _I(N,A,V,Y,_,B,L,U,E):
				return alpha | X11_NAVY_BLUE;
			case _I(N,A,V,Y, ,B,L,U,E):
				return alpha | X11_NAVY_BLUE;
			case _I(C,O,R,N,F,L,O,W,E,R,B,L,U,E):
				return alpha | X11_CORNFLOWER_BLUE;
			case _I(C,O,R,N,F,L,O,W,E,R,_,B,L,U,E):
				return alpha | X11_CORNFLOWER_BLUE;
			case _I(C,O,R,N,F,L,O,W,E,R, ,B,L,U,E):
				return alpha | X11_CORNFLOWER_BLUE;
			case _I(D,A,R,K,S,L,A,T,E,B,L,U,E):
				return alpha | X11_DARK_SLATE_BLUE;
			case _I(D,A,R,K,_,S,L,A,T,E,_,B,L,U,E):
				return alpha | X11_DARK_SLATE_BLUE;
			case _I(D,A,R,K, ,S,L,A,T,E, ,B,L,U,E):
				return alpha | X11_DARK_SLATE_BLUE;
			case _I(S,L,A,T,E,B,L,U,E):
				return alpha | X11_SLATE_BLUE;
			case _I(S,L,A,T,E,_,B,L,U,E):
				return alpha | X11_SLATE_BLUE;
			case _I(S,L,A,T,E, ,B,L,U,E):
				return alpha | X11_SLATE_BLUE;
			case _I(M,E,D,I,U,M,S,L,A,T,E,B,L,U,E):
				return alpha | X11_MEDIUM_SLATE_BLUE;
			case _I(M,E,D,I,U,M,_,S,L,A,T,E,_,B,L,U,E):
				return alpha | X11_MEDIUM_SLATE_BLUE;
			case _I(M,E,D,I,U,M, ,S,L,A,T,E, ,B,L,U,E):
				return alpha | X11_MEDIUM_SLATE_BLUE;
			case _I(L,I,G,H,T,S,L,A,T,E,B,L,U,E):
				return alpha | X11_LIGHT_SLATE_BLUE;
			case _I(L,I,G,H,T,_,S,L,A,T,E,_,B,L,U,E):
				return alpha | X11_LIGHT_SLATE_BLUE;
			case _I(L,I,G,H,T, ,S,L,A,T,E, ,B,L,U,E):
				return alpha | X11_LIGHT_SLATE_BLUE;
			case _I(M,E,D,I,U,M,B,L,U,E):
				return alpha | X11_MEDIUM_BLUE;
			case _I(M,E,D,I,U,M,_,B,L,U,E):
				return alpha | X11_MEDIUM_BLUE;
			case _I(M,E,D,I,U,M, ,B,L,U,E):
				return alpha | X11_MEDIUM_BLUE;
			case _I(R,O,Y,A,L,B,L,U,E):
				return alpha | X11_ROYAL_BLUE;
			case _I(R,O,Y,A,L,_,B,L,U,E):
				return alpha | X11_ROYAL_BLUE;
			case _I(R,O,Y,A,L, ,B,L,U,E):
				return alpha | X11_ROYAL_BLUE;
			case _I(B,L,U,E):
				return alpha | X11_BLUE;
			case _I(D,O,D,G,E,R,B,L,U,E):
				return alpha | X11_DODGER_BLUE;
			case _I(D,O,D,G,E,R,_,B,L,U,E):
				return alpha | X11_DODGER_BLUE;
			case _I(D,O,D,G,E,R, ,B,L,U,E):
				return alpha | X11_DODGER_BLUE;
			case _I(D,E,E,P,S,K,Y,B,L,U,E):
				return alpha | X11_DEEP_SKY_BLUE;
			case _I(D,E,E,P,_,S,K,Y,_,B,L,U,E):
				return alpha | X11_DEEP_SKY_BLUE;
			case _I(D,E,E,P, ,S,K,Y, ,B,L,U,E):
				return alpha | X11_DEEP_SKY_BLUE;
			case _I(S,K,Y,B,L,U,E):
				return alpha | X11_SKY_BLUE;
			case _I(S,K,Y,_,B,L,U,E):
				return alpha | X11_SKY_BLUE;
			case _I(S,K,Y, ,B,L,U,E):
				return alpha | X11_SKY_BLUE;
			case _I(L,I,G,H,T,S,K,Y,B,L,U,E):
				return alpha | X11_LIGHT_SKY_BLUE;
			case _I(L,I,G,H,T,_,S,K,Y,_,B,L,U,E):
				return alpha | X11_LIGHT_SKY_BLUE;
			case _I(L,I,G,H,T, ,S,K,Y, ,B,L,U,E):
				return alpha | X11_LIGHT_SKY_BLUE;
			case _I(S,T,E,E,L,B,L,U,E):
				return alpha | X11_STEEL_BLUE;
			case _I(S,T,E,E,L,_,B,L,U,E):
				return alpha | X11_STEEL_BLUE;
			case _I(S,T,E,E,L, ,B,L,U,E):
				return alpha | X11_STEEL_BLUE;
			case _I(L,I,G,H,T,S,T,E,E,L,B,L,U,E):
				return alpha | X11_LIGHT_STEEL_BLUE;
			case _I(L,I,G,H,T,_,S,T,E,E,L,_,B,L,U,E):
				return alpha | X11_LIGHT_STEEL_BLUE;
			case _I(L,I,G,H,T, ,S,T,E,E,L, ,B,L,U,E):
				return alpha | X11_LIGHT_STEEL_BLUE;
			case _I(L,I,G,H,T,B,L,U,E):
				return alpha | X11_LIGHT_BLUE;
			case _I(L,I,G,H,T,_,B,L,U,E):
				return alpha | X11_LIGHT_BLUE;
			case _I(L,I,G,H,T, ,B,L,U,E):
				return alpha | X11_LIGHT_BLUE;
			case _I(P,O,W,D,E,R,B,L,U,E):
				return alpha | X11_POWDER_BLUE;
			case _I(P,O,W,D,E,R,_,B,L,U,E):
				return alpha | X11_POWDER_BLUE;
			case _I(P,O,W,D,E,R, ,B,L,U,E):
				return alpha | X11_POWDER_BLUE;
			case _I(P,A,L,E,T,U,R,Q,U,O,I,S,E):
				return alpha | X11_PALE_TURQUOISE;
			case _I(P,A,L,E,_,T,U,R,Q,U,O,I,S,E):
				return alpha | X11_PALE_TURQUOISE;
			case _I(P,A,L,E, ,T,U,R,Q,U,O,I,S,E):
				return alpha | X11_PALE_TURQUOISE;
			case _I(D,A,R,K,T,U,R,Q,U,O,I,S,E):
				return alpha | X11_DARK_TURQUOISE;
			case _I(D,A,R,K,_,T,U,R,Q,U,O,I,S,E):
				return alpha | X11_DARK_TURQUOISE;
			case _I(D,A,R,K, ,T,U,R,Q,U,O,I,S,E):
				return alpha | X11_DARK_TURQUOISE;
			case _I(M,E,D,I,U,M,T,U,R,Q,U,O,I,S,E):
				return alpha | X11_MEDIUM_TURQUOISE;
			case _I(M,E,D,I,U,M,_,T,U,R,Q,U,O,I,S,E):
				return alpha | X11_MEDIUM_TURQUOISE;
			case _I(M,E,D,I,U,M, ,T,U,R,Q,U,O,I,S,E):
				return alpha | X11_MEDIUM_TURQUOISE;
			case _I(T,U,R,Q,U,O,I,S,E):
				return alpha | X11_TURQUOISE;
			case _I(C,Y,A,N):
				return alpha | X11_CYAN;
			case _I(L,I,G,H,T,C,Y,A,N):
				return alpha | X11_LIGHT_CYAN;
			case _I(L,I,G,H,T,_,C,Y,A,N):
				return alpha | X11_LIGHT_CYAN;
			case _I(L,I,G,H,T, ,C,Y,A,N):
				return alpha | X11_LIGHT_CYAN;
			case _I(C,A,D,E,T,B,L,U,E):
				return alpha | X11_CADET_BLUE;
			case _I(C,A,D,E,T,_,B,L,U,E):
				return alpha | X11_CADET_BLUE;
			case _I(C,A,D,E,T, ,B,L,U,E):
				return alpha | X11_CADET_BLUE;
			case _I(M,E,D,I,U,M,A,Q,U,A,M,A,R,I,N,E):
				return alpha | X11_MEDIUM_AQUAMARINE;
			case _I(M,E,D,I,U,M,_,A,Q,U,A,M,A,R,I,N,E):
				return alpha | X11_MEDIUM_AQUAMARINE;
			case _I(M,E,D,I,U,M, ,A,Q,U,A,M,A,R,I,N,E):
				return alpha | X11_MEDIUM_AQUAMARINE;
			case _I(A,Q,U,A,M,A,R,I,N,E):
				return alpha | X11_AQUAMARINE;
			case _I(D,A,R,K,G,R,E,E,N):
				return alpha | X11_DARK_GREEN;
			case _I(D,A,R,K,_,G,R,E,E,N):
				return alpha | X11_DARK_GREEN;
			case _I(D,A,R,K, ,G,R,E,E,N):
				return alpha | X11_DARK_GREEN;
			case _I(D,A,R,K,O,L,I,V,E,G,R,E,E,N):
				return alpha | X11_DARK_OLIVE_GREEN;
			case _I(D,A,R,K,_,O,L,I,V,E,_,G,R,E,E,N):
				return alpha | X11_DARK_OLIVE_GREEN;
			case _I(D,A,R,K, ,O,L,I,V,E, ,G,R,E,E,N):
				return alpha | X11_DARK_OLIVE_GREEN;
			case _I(D,A,R,K,S,E,A,G,R,E,E,N):
				return alpha | X11_DARK_SEA_GREEN;
			case _I(D,A,R,K,_,S,E,A,_,G,R,E,E,N):
				return alpha | X11_DARK_SEA_GREEN;
			case _I(D,A,R,K, ,S,E,A, ,G,R,E,E,N):
				return alpha | X11_DARK_SEA_GREEN;
			case _I(S,E,A,G,R,E,E,N):
				return alpha | X11_SEA_GREEN;
			case _I(S,E,A,_,G,R,E,E,N):
				return alpha | X11_SEA_GREEN;
			case _I(S,E,A, ,G,R,E,E,N):
				return alpha | X11_SEA_GREEN;
			case _I(M,E,D,I,U,M,S,E,A,G,R,E,E,N):
				return alpha | X11_MEDIUM_SEA_GREEN;
			case _I(M,E,D,I,U,M,_,S,E,A,_,G,R,E,E,N):
				return alpha | X11_MEDIUM_SEA_GREEN;
			case _I(M,E,D,I,U,M, ,S,E,A, ,G,R,E,E,N):
				return alpha | X11_MEDIUM_SEA_GREEN;
			case _I(L,I,G,H,T,S,E,A,G,R,E,E,N):
				return alpha | X11_LIGHT_SEA_GREEN;
			case _I(L,I,G,H,T,_,S,E,A,_,G,R,E,E,N):
				return alpha | X11_LIGHT_SEA_GREEN;
			case _I(L,I,G,H,T, ,S,E,A, ,G,R,E,E,N):
				return alpha | X11_LIGHT_SEA_GREEN;
			case _I(P,A,L,E,G,R,E,E,N):
				return alpha | X11_PALE_GREEN;
			case _I(P,A,L,E,_,G,R,E,E,N):
				return alpha | X11_PALE_GREEN;
			case _I(P,A,L,E, ,G,R,E,E,N):
				return alpha | X11_PALE_GREEN;
			case _I(S,P,R,I,N,G,G,R,E,E,N):
				return alpha | X11_SPRING_GREEN;
			case _I(S,P,R,I,N,G,_,G,R,E,E,N):
				return alpha | X11_SPRING_GREEN;
			case _I(S,P,R,I,N,G, ,G,R,E,E,N):
				return alpha | X11_SPRING_GREEN;
			case _I(L,A,W,N,G,R,E,E,N):
				return alpha | X11_LAWN_GREEN;
			case _I(L,A,W,N,_,G,R,E,E,N):
				return alpha | X11_LAWN_GREEN;
			case _I(L,A,W,N, ,G,R,E,E,N):
				return alpha | X11_LAWN_GREEN;
			case _I(G,R,E,E,N):
				return alpha | X11_GREEN;
			case _I(C,H,A,R,T,R,E,U,S,E):
				return alpha | X11_CHARTREUSE;
			case _I(M,E,D,I,U,M,S,P,R,I,N,G,G,R,E,E,N):
				return alpha | X11_MEDIUM_SPRING_GREEN;
			case _I(M,E,D,I,U,M,_,S,P,R,I,N,G,_,G,R,E,E,N):
				return alpha | X11_MEDIUM_SPRING_GREEN;
			case _I(M,E,D,I,U,M, ,S,P,R,I,N,G, ,G,R,E,E,N):
				return alpha | X11_MEDIUM_SPRING_GREEN;
			case _I(G,R,E,E,N,Y,E,L,L,O,W):
				return alpha | X11_GREEN_YELLOW;
			case _I(G,R,E,E,N,_,Y,E,L,L,O,W):
				return alpha | X11_GREEN_YELLOW;
			case _I(G,R,E,E,N, ,Y,E,L,L,O,W):
				return alpha | X11_GREEN_YELLOW;
			case _I(L,I,M,E,G,R,E,E,N):
				return alpha | X11_LIME_GREEN;
			case _I(L,I,M,E,_,G,R,E,E,N):
				return alpha | X11_LIME_GREEN;
			case _I(L,I,M,E, ,G,R,E,E,N):
				return alpha | X11_LIME_GREEN;
			case _I(Y,E,L,L,O,W,G,R,E,E,N):
				return alpha | X11_YELLOW_GREEN;
			case _I(Y,E,L,L,O,W,_,G,R,E,E,N):
				return alpha | X11_YELLOW_GREEN;
			case _I(Y,E,L,L,O,W, ,G,R,E,E,N):
				return alpha | X11_YELLOW_GREEN;
			case _I(F,O,R,E,S,T,G,R,E,E,N):
				return alpha | X11_FOREST_GREEN;
			case _I(F,O,R,E,S,T,_,G,R,E,E,N):
				return alpha | X11_FOREST_GREEN;
			case _I(F,O,R,E,S,T, ,G,R,E,E,N):
				return alpha | X11_FOREST_GREEN;
			case _I(O,L,I,V,E,D,R,A,B):
				return alpha | X11_OLIVE_DRAB;
			case _I(O,L,I,V,E,_,D,R,A,B):
				return alpha | X11_OLIVE_DRAB;
			case _I(O,L,I,V,E, ,D,R,A,B):
				return alpha | X11_OLIVE_DRAB;
			case _I(D,A,R,K,K,H,A,K,I):
				return alpha | X11_DARK_KHAKI;
			case _I(D,A,R,K,_,K,H,A,K,I):
				return alpha | X11_DARK_KHAKI;
			case _I(D,A,R,K, ,K,H,A,K,I):
				return alpha | X11_DARK_KHAKI;
			case _I(K,H,A,K,I):
				return alpha | X11_KHAKI;
			case _I(P,A,L,E,G,O,L,D,E,N,R,O,D):
				return alpha | X11_PALE_GOLDENROD;
			case _I(P,A,L,E,_,G,O,L,D,E,N,R,O,D):
				return alpha | X11_PALE_GOLDENROD;
			case _I(P,A,L,E, ,G,O,L,D,E,N,R,O,D):
				return alpha | X11_PALE_GOLDENROD;
			case _I(L,I,G,H,T,G,O,L,D,E,N,R,O,D,Y,E,L,L,O,W):
				return alpha | X11_LIGHT_GOLDENROD_YELLOW;
			case _I(L,I,G,H,T,_,G,O,L,D,E,N,R,O,D,_,Y,E,L,L,O,W):
				return alpha | X11_LIGHT_GOLDENROD_YELLOW;
			case _I(L,I,G,H,T, ,G,O,L,D,E,N,R,O,D, ,Y,E,L,L,O,W):
				return alpha | X11_LIGHT_GOLDENROD_YELLOW;
			case _I(L,I,G,H,T,Y,E,L,L,O,W):
				return alpha | X11_LIGHT_YELLOW;
			case _I(L,I,G,H,T,_,Y,E,L,L,O,W):
				return alpha | X11_LIGHT_YELLOW;
			case _I(L,I,G,H,T, ,Y,E,L,L,O,W):
				return alpha | X11_LIGHT_YELLOW;
			case _I(Y,E,L,L,O,W):
				return alpha | X11_YELLOW;
			case _I(G,O,L,D):
				return alpha | X11_GOLD;
			case _I(L,I,G,H,T,G,O,L,D,E,N,R,O,D):
				return alpha | X11_LIGHT_GOLDENROD;
			case _I(L,I,G,H,T,_,G,O,L,D,E,N,R,O,D):
				return alpha | X11_LIGHT_GOLDENROD;
			case _I(L,I,G,H,T, ,G,O,L,D,E,N,R,O,D):
				return alpha | X11_LIGHT_GOLDENROD;
			case _I(G,O,L,D,E,N,R,O,D):
				return alpha | X11_GOLDENROD;
			case _I(D,A,R,K,G,O,L,D,E,N,R,O,D):
				return alpha | X11_DARK_GOLDENROD;
			case _I(D,A,R,K,_,G,O,L,D,E,N,R,O,D):
				return alpha | X11_DARK_GOLDENROD;
			case _I(D,A,R,K, ,G,O,L,D,E,N,R,O,D):
				return alpha | X11_DARK_GOLDENROD;
			case _I(R,O,S,Y,B,R,O,W,N):
				return alpha | X11_ROSY_BROWN;
			case _I(R,O,S,Y,_,B,R,O,W,N):
				return alpha | X11_ROSY_BROWN;
			case _I(R,O,S,Y, ,B,R,O,W,N):
				return alpha | X11_ROSY_BROWN;
			case _I(I,N,D,I,A,N,R,E,D):
				return alpha | X11_INDIAN_RED;
			case _I(I,N,D,I,A,N,_,R,E,D):
				return alpha | X11_INDIAN_RED;
			case _I(I,N,D,I,A,N, ,R,E,D):
				return alpha | X11_INDIAN_RED;
			case _I(S,A,D,D,L,E,B,R,O,W,N):
				return alpha | X11_SADDLE_BROWN;
			case _I(S,A,D,D,L,E,_,B,R,O,W,N):
				return alpha | X11_SADDLE_BROWN;
			case _I(S,A,D,D,L,E, ,B,R,O,W,N):
				return alpha | X11_SADDLE_BROWN;
			case _I(S,I,E,N,N,A):
				return alpha | X11_SIENNA;
			case _I(P,E,R,U):
				return alpha | X11_PERU;
			case _I(B,U,R,L,Y,W,O,O,D):
				return alpha | X11_BURLYWOOD;
			case _I(B,E,I,G,E):
				return alpha | X11_BEIGE;
			case _I(W,H,E,A,T):
				return alpha | X11_WHEAT;
			case _I(S,A,N,D,Y,B,R,O,W,N):
				return alpha | X11_SANDY_BROWN;
			case _I(S,A,N,D,Y,_,B,R,O,W,N):
				return alpha | X11_SANDY_BROWN;
			case _I(S,A,N,D,Y, ,B,R,O,W,N):
				return alpha | X11_SANDY_BROWN;
			case _I(T,A,N):
				return alpha | X11_TAN;
			case _I(C,H,O,C,O,L,A,T,E):
				return alpha | X11_CHOCOLATE;
			case _I(F,I,R,E,B,R,I,C,K):
				return alpha | X11_FIREBRICK;
			case _I(B,R,O,W,N):
				return alpha | X11_BROWN;
			case _I(D,A,R,K,S,A,L,M,O,N):
				return alpha | X11_DARK_SALMON;
			case _I(D,A,R,K,_,S,A,L,M,O,N):
				return alpha | X11_DARK_SALMON;
			case _I(D,A,R,K, ,S,A,L,M,O,N):
				return alpha | X11_DARK_SALMON;
			case _I(S,A,L,M,O,N):
				return alpha | X11_SALMON;
			case _I(L,I,G,H,T,S,A,L,M,O,N):
				return alpha | X11_LIGHT_SALMON;
			case _I(L,I,G,H,T,_,S,A,L,M,O,N):
				return alpha | X11_LIGHT_SALMON;
			case _I(L,I,G,H,T, ,S,A,L,M,O,N):
				return alpha | X11_LIGHT_SALMON;
			case _I(O,R,A,N,G,E):
				return alpha | X11_ORANGE;
			case _I(D,A,R,K,O,R,A,N,G,E):
				return alpha | X11_DARK_ORANGE;
			case _I(D,A,R,K,_,O,R,A,N,G,E):
				return alpha | X11_DARK_ORANGE;
			case _I(D,A,R,K, ,O,R,A,N,G,E):
				return alpha | X11_DARK_ORANGE;
			case _I(C,O,R,A,L):
				return alpha | X11_CORAL;
			case _I(L,I,G,H,T,C,O,R,A,L):
				return alpha | X11_LIGHT_CORAL;
			case _I(L,I,G,H,T,_,C,O,R,A,L):
				return alpha | X11_LIGHT_CORAL;
			case _I(L,I,G,H,T, ,C,O,R,A,L):
				return alpha | X11_LIGHT_CORAL;
			case _I(T,O,M,A,T,O):
				return alpha | X11_TOMATO;
			case _I(O,R,A,N,G,E,R,E,D):
				return alpha | X11_ORANGE_RED;
			case _I(O,R,A,N,G,E,_,R,E,D):
				return alpha | X11_ORANGE_RED;
			case _I(O,R,A,N,G,E, ,R,E,D):
				return alpha | X11_ORANGE_RED;
			case _I(R,E,D):
				return alpha | X11_RED;
			case _I(H,O,T,P,I,N,K):
				return alpha | X11_HOT_PINK;
			case _I(H,O,T,_,P,I,N,K):
				return alpha | X11_HOT_PINK;
			case _I(H,O,T, ,P,I,N,K):
				return alpha | X11_HOT_PINK;
			case _I(D,E,E,P,P,I,N,K):
				return alpha | X11_DEEP_PINK;
			case _I(D,E,E,P,_,P,I,N,K):
				return alpha | X11_DEEP_PINK;
			case _I(D,E,E,P, ,P,I,N,K):
				return alpha | X11_DEEP_PINK;
			case _I(P,I,N,K):
				return alpha | X11_PINK;
			case _I(L,I,G,H,T,P,I,N,K):
				return alpha | X11_LIGHT_PINK;
			case _I(L,I,G,H,T,_,P,I,N,K):
				return alpha | X11_LIGHT_PINK;
			case _I(L,I,G,H,T, ,P,I,N,K):
				return alpha | X11_LIGHT_PINK;
			case _I(P,A,L,E,V,I,O,L,E,T,R,E,D):
				return alpha | X11_PALE_VIOLET_RED;
			case _I(P,A,L,E,_,V,I,O,L,E,T,_,R,E,D):
				return alpha | X11_PALE_VIOLET_RED;
			case _I(P,A,L,E, ,V,I,O,L,E,T, ,R,E,D):
				return alpha | X11_PALE_VIOLET_RED;
			case _I(M,A,R,O,O,N):
				return alpha | X11_MAROON;
			case _I(M,E,D,I,U,M,V,I,O,L,E,T,R,E,D):
				return alpha | X11_MEDIUM_VIOLET_RED;
			case _I(M,E,D,I,U,M,_,V,I,O,L,E,T,_,R,E,D):
				return alpha | X11_MEDIUM_VIOLET_RED;
			case _I(M,E,D,I,U,M, ,V,I,O,L,E,T, ,R,E,D):
				return alpha | X11_MEDIUM_VIOLET_RED;
			case _I(V,I,O,L,E,T,R,E,D):
				return alpha | X11_VIOLET_RED;
			case _I(V,I,O,L,E,T,_,R,E,D):
				return alpha | X11_VIOLET_RED;
			case _I(V,I,O,L,E,T, ,R,E,D):
				return alpha | X11_VIOLET_RED;
			case _I(M,A,G,E,N,T,A):
				return alpha | X11_MAGENTA;
			case _I(V,I,O,L,E,T):
				return alpha | X11_VIOLET;
			case _I(P,L,U,M):
				return alpha | X11_PLUM;
			case _I(O,R,C,H,I,D):
				return alpha | X11_ORCHID;
			case _I(M,E,D,I,U,M,O,R,C,H,I,D):
				return alpha | X11_MEDIUM_ORCHID;
			case _I(M,E,D,I,U,M,_,O,R,C,H,I,D):
				return alpha | X11_MEDIUM_ORCHID;
			case _I(M,E,D,I,U,M, ,O,R,C,H,I,D):
				return alpha | X11_MEDIUM_ORCHID;
			case _I(D,A,R,K,O,R,C,H,I,D):
				return alpha | X11_DARK_ORCHID;
			case _I(D,A,R,K,_,O,R,C,H,I,D):
				return alpha | X11_DARK_ORCHID;
			case _I(D,A,R,K, ,O,R,C,H,I,D):
				return alpha | X11_DARK_ORCHID;
			case _I(D,A,R,K,V,I,O,L,E,T):
				return alpha | X11_DARK_VIOLET;
			case _I(D,A,R,K,_,V,I,O,L,E,T):
				return alpha | X11_DARK_VIOLET;
			case _I(D,A,R,K, ,V,I,O,L,E,T):
				return alpha | X11_DARK_VIOLET;
			case _I(B,L,U,E,V,I,O,L,E,T):
				return alpha | X11_BLUE_VIOLET;
			case _I(B,L,U,E,_,V,I,O,L,E,T):
				return alpha | X11_BLUE_VIOLET;
			case _I(B,L,U,E, ,V,I,O,L,E,T):
				return alpha | X11_BLUE_VIOLET;
			case _I(P,U,R,P,L,E):
				return alpha | X11_PURPLE;
			case _I(M,E,D,I,U,M,P,U,R,P,L,E):
				return alpha | X11_MEDIUM_PURPLE;
			case _I(M,E,D,I,U,M,_,P,U,R,P,L,E):
				return alpha | X11_MEDIUM_PURPLE;
			case _I(M,E,D,I,U,M, ,P,U,R,P,L,E):
				return alpha | X11_MEDIUM_PURPLE;
			case _I(T,H,I,S,T,L,E):
				return alpha | X11_THISTLE;
			case _I(S,N,O,W,1):
				return alpha | X11_SNOW_1;
			case _I(S,N,O,W,_,1):
				return alpha | X11_SNOW_1;
			case _I(S,N,O,W, ,1):
				return alpha | X11_SNOW_1;
			case _I(S,N,O,W,2):
				return alpha | X11_SNOW_2;
			case _I(S,N,O,W,_,2):
				return alpha | X11_SNOW_2;
			case _I(S,N,O,W, ,2):
				return alpha | X11_SNOW_2;
			case _I(S,N,O,W,3):
				return alpha | X11_SNOW_3;
			case _I(S,N,O,W,_,3):
				return alpha | X11_SNOW_3;
			case _I(S,N,O,W, ,3):
				return alpha | X11_SNOW_3;
			case _I(S,N,O,W,4):
				return alpha | X11_SNOW_4;
			case _I(S,N,O,W,_,4):
				return alpha | X11_SNOW_4;
			case _I(S,N,O,W, ,4):
				return alpha | X11_SNOW_4;
			case _I(S,E,A,S,H,E,L,L,1):
				return alpha | X11_SEASHELL_1;
			case _I(S,E,A,S,H,E,L,L,_,1):
				return alpha | X11_SEASHELL_1;
			case _I(S,E,A,S,H,E,L,L, ,1):
				return alpha | X11_SEASHELL_1;
			case _I(S,E,A,S,H,E,L,L,2):
				return alpha | X11_SEASHELL_2;
			case _I(S,E,A,S,H,E,L,L,_,2):
				return alpha | X11_SEASHELL_2;
			case _I(S,E,A,S,H,E,L,L, ,2):
				return alpha | X11_SEASHELL_2;
			case _I(S,E,A,S,H,E,L,L,3):
				return alpha | X11_SEASHELL_3;
			case _I(S,E,A,S,H,E,L,L,_,3):
				return alpha | X11_SEASHELL_3;
			case _I(S,E,A,S,H,E,L,L, ,3):
				return alpha | X11_SEASHELL_3;
			case _I(S,E,A,S,H,E,L,L,4):
				return alpha | X11_SEASHELL_4;
			case _I(S,E,A,S,H,E,L,L,_,4):
				return alpha | X11_SEASHELL_4;
			case _I(S,E,A,S,H,E,L,L, ,4):
				return alpha | X11_SEASHELL_4;
			case _I(A,N,T,I,Q,U,E,W,H,I,T,E,1):
				return alpha | X11_ANTIQUE_WHITE_1;
			case _I(A,N,T,I,Q,U,E,_,W,H,I,T,E,_,1):
				return alpha | X11_ANTIQUE_WHITE_1;
			case _I(A,N,T,I,Q,U,E, ,W,H,I,T,E, ,1):
				return alpha | X11_ANTIQUE_WHITE_1;
			case _I(A,N,T,I,Q,U,E,W,H,I,T,E,2):
				return alpha | X11_ANTIQUE_WHITE_2;
			case _I(A,N,T,I,Q,U,E,_,W,H,I,T,E,_,2):
				return alpha | X11_ANTIQUE_WHITE_2;
			case _I(A,N,T,I,Q,U,E, ,W,H,I,T,E, ,2):
				return alpha | X11_ANTIQUE_WHITE_2;
			case _I(A,N,T,I,Q,U,E,W,H,I,T,E,3):
				return alpha | X11_ANTIQUE_WHITE_3;
			case _I(A,N,T,I,Q,U,E,_,W,H,I,T,E,_,3):
				return alpha | X11_ANTIQUE_WHITE_3;
			case _I(A,N,T,I,Q,U,E, ,W,H,I,T,E, ,3):
				return alpha | X11_ANTIQUE_WHITE_3;
			case _I(A,N,T,I,Q,U,E,W,H,I,T,E,4):
				return alpha | X11_ANTIQUE_WHITE_4;
			case _I(A,N,T,I,Q,U,E,_,W,H,I,T,E,_,4):
				return alpha | X11_ANTIQUE_WHITE_4;
			case _I(A,N,T,I,Q,U,E, ,W,H,I,T,E, ,4):
				return alpha | X11_ANTIQUE_WHITE_4;
			case _I(B,I,S,Q,U,E,1):
				return alpha | X11_BISQUE_1;
			case _I(B,I,S,Q,U,E,_,1):
				return alpha | X11_BISQUE_1;
			case _I(B,I,S,Q,U,E, ,1):
				return alpha | X11_BISQUE_1;
			case _I(B,I,S,Q,U,E,2):
				return alpha | X11_BISQUE_2;
			case _I(B,I,S,Q,U,E,_,2):
				return alpha | X11_BISQUE_2;
			case _I(B,I,S,Q,U,E, ,2):
				return alpha | X11_BISQUE_2;
			case _I(B,I,S,Q,U,E,3):
				return alpha | X11_BISQUE_3;
			case _I(B,I,S,Q,U,E,_,3):
				return alpha | X11_BISQUE_3;
			case _I(B,I,S,Q,U,E, ,3):
				return alpha | X11_BISQUE_3;
			case _I(B,I,S,Q,U,E,4):
				return alpha | X11_BISQUE_4;
			case _I(B,I,S,Q,U,E,_,4):
				return alpha | X11_BISQUE_4;
			case _I(B,I,S,Q,U,E, ,4):
				return alpha | X11_BISQUE_4;
			case _I(P,E,A,C,H,P,U,F,F,1):
				return alpha | X11_PEACH_PUFF_1;
			case _I(P,E,A,C,H,_,P,U,F,F,_,1):
				return alpha | X11_PEACH_PUFF_1;
			case _I(P,E,A,C,H, ,P,U,F,F, ,1):
				return alpha | X11_PEACH_PUFF_1;
			case _I(P,E,A,C,H,P,U,F,F,2):
				return alpha | X11_PEACH_PUFF_2;
			case _I(P,E,A,C,H,_,P,U,F,F,_,2):
				return alpha | X11_PEACH_PUFF_2;
			case _I(P,E,A,C,H, ,P,U,F,F, ,2):
				return alpha | X11_PEACH_PUFF_2;
			case _I(P,E,A,C,H,P,U,F,F,3):
				return alpha | X11_PEACH_PUFF_3;
			case _I(P,E,A,C,H,_,P,U,F,F,_,3):
				return alpha | X11_PEACH_PUFF_3;
			case _I(P,E,A,C,H, ,P,U,F,F, ,3):
				return alpha | X11_PEACH_PUFF_3;
			case _I(P,E,A,C,H,P,U,F,F,4):
				return alpha | X11_PEACH_PUFF_4;
			case _I(P,E,A,C,H,_,P,U,F,F,_,4):
				return alpha | X11_PEACH_PUFF_4;
			case _I(P,E,A,C,H, ,P,U,F,F, ,4):
				return alpha | X11_PEACH_PUFF_4;
			case _I(N,A,V,A,J,O,W,H,I,T,E,1):
				return alpha | X11_NAVAJO_WHITE_1;
			case _I(N,A,V,A,J,O,_,W,H,I,T,E,_,1):
				return alpha | X11_NAVAJO_WHITE_1;
			case _I(N,A,V,A,J,O, ,W,H,I,T,E, ,1):
				return alpha | X11_NAVAJO_WHITE_1;
			case _I(N,A,V,A,J,O,W,H,I,T,E,2):
				return alpha | X11_NAVAJO_WHITE_2;
			case _I(N,A,V,A,J,O,_,W,H,I,T,E,_,2):
				return alpha | X11_NAVAJO_WHITE_2;
			case _I(N,A,V,A,J,O, ,W,H,I,T,E, ,2):
				return alpha | X11_NAVAJO_WHITE_2;
			case _I(N,A,V,A,J,O,W,H,I,T,E,3):
				return alpha | X11_NAVAJO_WHITE_3;
			case _I(N,A,V,A,J,O,_,W,H,I,T,E,_,3):
				return alpha | X11_NAVAJO_WHITE_3;
			case _I(N,A,V,A,J,O, ,W,H,I,T,E, ,3):
				return alpha | X11_NAVAJO_WHITE_3;
			case _I(N,A,V,A,J,O,W,H,I,T,E,4):
				return alpha | X11_NAVAJO_WHITE_4;
			case _I(N,A,V,A,J,O,_,W,H,I,T,E,_,4):
				return alpha | X11_NAVAJO_WHITE_4;
			case _I(N,A,V,A,J,O, ,W,H,I,T,E, ,4):
				return alpha | X11_NAVAJO_WHITE_4;
			case _I(L,E,M,O,N,C,H,I,F,F,O,N,1):
				return alpha | X11_LEMON_CHIFFON_1;
			case _I(L,E,M,O,N,_,C,H,I,F,F,O,N,_,1):
				return alpha | X11_LEMON_CHIFFON_1;
			case _I(L,E,M,O,N, ,C,H,I,F,F,O,N, ,1):
				return alpha | X11_LEMON_CHIFFON_1;
			case _I(L,E,M,O,N,C,H,I,F,F,O,N,2):
				return alpha | X11_LEMON_CHIFFON_2;
			case _I(L,E,M,O,N,_,C,H,I,F,F,O,N,_,2):
				return alpha | X11_LEMON_CHIFFON_2;
			case _I(L,E,M,O,N, ,C,H,I,F,F,O,N, ,2):
				return alpha | X11_LEMON_CHIFFON_2;
			case _I(L,E,M,O,N,C,H,I,F,F,O,N,3):
				return alpha | X11_LEMON_CHIFFON_3;
			case _I(L,E,M,O,N,_,C,H,I,F,F,O,N,_,3):
				return alpha | X11_LEMON_CHIFFON_3;
			case _I(L,E,M,O,N, ,C,H,I,F,F,O,N, ,3):
				return alpha | X11_LEMON_CHIFFON_3;
			case _I(L,E,M,O,N,C,H,I,F,F,O,N,4):
				return alpha | X11_LEMON_CHIFFON_4;
			case _I(L,E,M,O,N,_,C,H,I,F,F,O,N,_,4):
				return alpha | X11_LEMON_CHIFFON_4;
			case _I(L,E,M,O,N, ,C,H,I,F,F,O,N, ,4):
				return alpha | X11_LEMON_CHIFFON_4;
			case _I(C,O,R,N,S,I,L,K,1):
				return alpha | X11_CORNSILK_1;
			case _I(C,O,R,N,S,I,L,K,_,1):
				return alpha | X11_CORNSILK_1;
			case _I(C,O,R,N,S,I,L,K, ,1):
				return alpha | X11_CORNSILK_1;
			case _I(C,O,R,N,S,I,L,K,2):
				return alpha | X11_CORNSILK_2;
			case _I(C,O,R,N,S,I,L,K,_,2):
				return alpha | X11_CORNSILK_2;
			case _I(C,O,R,N,S,I,L,K, ,2):
				return alpha | X11_CORNSILK_2;
			case _I(C,O,R,N,S,I,L,K,3):
				return alpha | X11_CORNSILK_3;
			case _I(C,O,R,N,S,I,L,K,_,3):
				return alpha | X11_CORNSILK_3;
			case _I(C,O,R,N,S,I,L,K, ,3):
				return alpha | X11_CORNSILK_3;
			case _I(C,O,R,N,S,I,L,K,4):
				return alpha | X11_CORNSILK_4;
			case _I(C,O,R,N,S,I,L,K,_,4):
				return alpha | X11_CORNSILK_4;
			case _I(C,O,R,N,S,I,L,K, ,4):
				return alpha | X11_CORNSILK_4;
			case _I(I,V,O,R,Y,1):
				return alpha | X11_IVORY_1;
			case _I(I,V,O,R,Y,_,1):
				return alpha | X11_IVORY_1;
			case _I(I,V,O,R,Y, ,1):
				return alpha | X11_IVORY_1;
			case _I(I,V,O,R,Y,2):
				return alpha | X11_IVORY_2;
			case _I(I,V,O,R,Y,_,2):
				return alpha | X11_IVORY_2;
			case _I(I,V,O,R,Y, ,2):
				return alpha | X11_IVORY_2;
			case _I(I,V,O,R,Y,3):
				return alpha | X11_IVORY_3;
			case _I(I,V,O,R,Y,_,3):
				return alpha | X11_IVORY_3;
			case _I(I,V,O,R,Y, ,3):
				return alpha | X11_IVORY_3;
			case _I(I,V,O,R,Y,4):
				return alpha | X11_IVORY_4;
			case _I(I,V,O,R,Y,_,4):
				return alpha | X11_IVORY_4;
			case _I(I,V,O,R,Y, ,4):
				return alpha | X11_IVORY_4;
			case _I(H,O,N,E,Y,D,E,W,1):
				return alpha | X11_HONEYDEW_1;
			case _I(H,O,N,E,Y,D,E,W,_,1):
				return alpha | X11_HONEYDEW_1;
			case _I(H,O,N,E,Y,D,E,W, ,1):
				return alpha | X11_HONEYDEW_1;
			case _I(H,O,N,E,Y,D,E,W,2):
				return alpha | X11_HONEYDEW_2;
			case _I(H,O,N,E,Y,D,E,W,_,2):
				return alpha | X11_HONEYDEW_2;
			case _I(H,O,N,E,Y,D,E,W, ,2):
				return alpha | X11_HONEYDEW_2;
			case _I(H,O,N,E,Y,D,E,W,3):
				return alpha | X11_HONEYDEW_3;
			case _I(H,O,N,E,Y,D,E,W,_,3):
				return alpha | X11_HONEYDEW_3;
			case _I(H,O,N,E,Y,D,E,W, ,3):
				return alpha | X11_HONEYDEW_3;
			case _I(H,O,N,E,Y,D,E,W,4):
				return alpha | X11_HONEYDEW_4;
			case _I(H,O,N,E,Y,D,E,W,_,4):
				return alpha | X11_HONEYDEW_4;
			case _I(H,O,N,E,Y,D,E,W, ,4):
				return alpha | X11_HONEYDEW_4;
			case _I(L,A,V,E,N,D,E,R,B,L,U,S,H,1):
				return alpha | X11_LAVENDER_BLUSH_1;
			case _I(L,A,V,E,N,D,E,R,_,B,L,U,S,H,_,1):
				return alpha | X11_LAVENDER_BLUSH_1;
			case _I(L,A,V,E,N,D,E,R, ,B,L,U,S,H, ,1):
				return alpha | X11_LAVENDER_BLUSH_1;
			case _I(L,A,V,E,N,D,E,R,B,L,U,S,H,2):
				return alpha | X11_LAVENDER_BLUSH_2;
			case _I(L,A,V,E,N,D,E,R,_,B,L,U,S,H,_,2):
				return alpha | X11_LAVENDER_BLUSH_2;
			case _I(L,A,V,E,N,D,E,R, ,B,L,U,S,H, ,2):
				return alpha | X11_LAVENDER_BLUSH_2;
			case _I(L,A,V,E,N,D,E,R,B,L,U,S,H,3):
				return alpha | X11_LAVENDER_BLUSH_3;
			case _I(L,A,V,E,N,D,E,R,_,B,L,U,S,H,_,3):
				return alpha | X11_LAVENDER_BLUSH_3;
			case _I(L,A,V,E,N,D,E,R, ,B,L,U,S,H, ,3):
				return alpha | X11_LAVENDER_BLUSH_3;
			case _I(L,A,V,E,N,D,E,R,B,L,U,S,H,4):
				return alpha | X11_LAVENDER_BLUSH_4;
			case _I(L,A,V,E,N,D,E,R,_,B,L,U,S,H,_,4):
				return alpha | X11_LAVENDER_BLUSH_4;
			case _I(L,A,V,E,N,D,E,R, ,B,L,U,S,H, ,4):
				return alpha | X11_LAVENDER_BLUSH_4;
			case _I(M,I,S,T,Y,R,O,S,E,1):
				return alpha | X11_MISTY_ROSE_1;
			case _I(M,I,S,T,Y,_,R,O,S,E,_,1):
				return alpha | X11_MISTY_ROSE_1;
			case _I(M,I,S,T,Y, ,R,O,S,E, ,1):
				return alpha | X11_MISTY_ROSE_1;
			case _I(M,I,S,T,Y,R,O,S,E,2):
				return alpha | X11_MISTY_ROSE_2;
			case _I(M,I,S,T,Y,_,R,O,S,E,_,2):
				return alpha | X11_MISTY_ROSE_2;
			case _I(M,I,S,T,Y, ,R,O,S,E, ,2):
				return alpha | X11_MISTY_ROSE_2;
			case _I(M,I,S,T,Y,R,O,S,E,3):
				return alpha | X11_MISTY_ROSE_3;
			case _I(M,I,S,T,Y,_,R,O,S,E,_,3):
				return alpha | X11_MISTY_ROSE_3;
			case _I(M,I,S,T,Y, ,R,O,S,E, ,3):
				return alpha | X11_MISTY_ROSE_3;
			case _I(M,I,S,T,Y,R,O,S,E,4):
				return alpha | X11_MISTY_ROSE_4;
			case _I(M,I,S,T,Y,_,R,O,S,E,_,4):
				return alpha | X11_MISTY_ROSE_4;
			case _I(M,I,S,T,Y, ,R,O,S,E, ,4):
				return alpha | X11_MISTY_ROSE_4;
			case _I(A,Z,U,R,E,1):
				return alpha | X11_AZURE_1;
			case _I(A,Z,U,R,E,_,1):
				return alpha | X11_AZURE_1;
			case _I(A,Z,U,R,E, ,1):
				return alpha | X11_AZURE_1;
			case _I(A,Z,U,R,E,2):
				return alpha | X11_AZURE_2;
			case _I(A,Z,U,R,E,_,2):
				return alpha | X11_AZURE_2;
			case _I(A,Z,U,R,E, ,2):
				return alpha | X11_AZURE_2;
			case _I(A,Z,U,R,E,3):
				return alpha | X11_AZURE_3;
			case _I(A,Z,U,R,E,_,3):
				return alpha | X11_AZURE_3;
			case _I(A,Z,U,R,E, ,3):
				return alpha | X11_AZURE_3;
			case _I(A,Z,U,R,E,4):
				return alpha | X11_AZURE_4;
			case _I(A,Z,U,R,E,_,4):
				return alpha | X11_AZURE_4;
			case _I(A,Z,U,R,E, ,4):
				return alpha | X11_AZURE_4;
			case _I(S,L,A,T,E,B,L,U,E,1):
				return alpha | X11_SLATE_BLUE_1;
			case _I(S,L,A,T,E,_,B,L,U,E,_,1):
				return alpha | X11_SLATE_BLUE_1;
			case _I(S,L,A,T,E, ,B,L,U,E, ,1):
				return alpha | X11_SLATE_BLUE_1;
			case _I(S,L,A,T,E,B,L,U,E,2):
				return alpha | X11_SLATE_BLUE_2;
			case _I(S,L,A,T,E,_,B,L,U,E,_,2):
				return alpha | X11_SLATE_BLUE_2;
			case _I(S,L,A,T,E, ,B,L,U,E, ,2):
				return alpha | X11_SLATE_BLUE_2;
			case _I(S,L,A,T,E,B,L,U,E,3):
				return alpha | X11_SLATE_BLUE_3;
			case _I(S,L,A,T,E,_,B,L,U,E,_,3):
				return alpha | X11_SLATE_BLUE_3;
			case _I(S,L,A,T,E, ,B,L,U,E, ,3):
				return alpha | X11_SLATE_BLUE_3;
			case _I(S,L,A,T,E,B,L,U,E,4):
				return alpha | X11_SLATE_BLUE_4;
			case _I(S,L,A,T,E,_,B,L,U,E,_,4):
				return alpha | X11_SLATE_BLUE_4;
			case _I(S,L,A,T,E, ,B,L,U,E, ,4):
				return alpha | X11_SLATE_BLUE_4;
			case _I(R,O,Y,A,L,B,L,U,E,1):
				return alpha | X11_ROYAL_BLUE_1;
			case _I(R,O,Y,A,L,_,B,L,U,E,_,1):
				return alpha | X11_ROYAL_BLUE_1;
			case _I(R,O,Y,A,L, ,B,L,U,E, ,1):
				return alpha | X11_ROYAL_BLUE_1;
			case _I(R,O,Y,A,L,B,L,U,E,2):
				return alpha | X11_ROYAL_BLUE_2;
			case _I(R,O,Y,A,L,_,B,L,U,E,_,2):
				return alpha | X11_ROYAL_BLUE_2;
			case _I(R,O,Y,A,L, ,B,L,U,E, ,2):
				return alpha | X11_ROYAL_BLUE_2;
			case _I(R,O,Y,A,L,B,L,U,E,3):
				return alpha | X11_ROYAL_BLUE_3;
			case _I(R,O,Y,A,L,_,B,L,U,E,_,3):
				return alpha | X11_ROYAL_BLUE_3;
			case _I(R,O,Y,A,L, ,B,L,U,E, ,3):
				return alpha | X11_ROYAL_BLUE_3;
			case _I(R,O,Y,A,L,B,L,U,E,4):
				return alpha | X11_ROYAL_BLUE_4;
			case _I(R,O,Y,A,L,_,B,L,U,E,_,4):
				return alpha | X11_ROYAL_BLUE_4;
			case _I(R,O,Y,A,L, ,B,L,U,E, ,4):
				return alpha | X11_ROYAL_BLUE_4;
			case _I(B,L,U,E,1):
				return alpha | X11_BLUE_1;
			case _I(B,L,U,E,_,1):
				return alpha | X11_BLUE_1;
			case _I(B,L,U,E, ,1):
				return alpha | X11_BLUE_1;
			case _I(B,L,U,E,2):
				return alpha | X11_BLUE_2;
			case _I(B,L,U,E,_,2):
				return alpha | X11_BLUE_2;
			case _I(B,L,U,E, ,2):
				return alpha | X11_BLUE_2;
			case _I(B,L,U,E,3):
				return alpha | X11_BLUE_3;
			case _I(B,L,U,E,_,3):
				return alpha | X11_BLUE_3;
			case _I(B,L,U,E, ,3):
				return alpha | X11_BLUE_3;
			case _I(B,L,U,E,4):
				return alpha | X11_BLUE_4;
			case _I(B,L,U,E,_,4):
				return alpha | X11_BLUE_4;
			case _I(B,L,U,E, ,4):
				return alpha | X11_BLUE_4;
			case _I(D,O,D,G,E,R,B,L,U,E,1):
				return alpha | X11_DODGER_BLUE_1;
			case _I(D,O,D,G,E,R,_,B,L,U,E,_,1):
				return alpha | X11_DODGER_BLUE_1;
			case _I(D,O,D,G,E,R, ,B,L,U,E, ,1):
				return alpha | X11_DODGER_BLUE_1;
			case _I(D,O,D,G,E,R,B,L,U,E,2):
				return alpha | X11_DODGER_BLUE_2;
			case _I(D,O,D,G,E,R,_,B,L,U,E,_,2):
				return alpha | X11_DODGER_BLUE_2;
			case _I(D,O,D,G,E,R, ,B,L,U,E, ,2):
				return alpha | X11_DODGER_BLUE_2;
			case _I(D,O,D,G,E,R,B,L,U,E,3):
				return alpha | X11_DODGER_BLUE_3;
			case _I(D,O,D,G,E,R,_,B,L,U,E,_,3):
				return alpha | X11_DODGER_BLUE_3;
			case _I(D,O,D,G,E,R, ,B,L,U,E, ,3):
				return alpha | X11_DODGER_BLUE_3;
			case _I(D,O,D,G,E,R,B,L,U,E,4):
				return alpha | X11_DODGER_BLUE_4;
			case _I(D,O,D,G,E,R,_,B,L,U,E,_,4):
				return alpha | X11_DODGER_BLUE_4;
			case _I(D,O,D,G,E,R, ,B,L,U,E, ,4):
				return alpha | X11_DODGER_BLUE_4;
			case _I(S,T,E,E,L,B,L,U,E,1):
				return alpha | X11_STEEL_BLUE_1;
			case _I(S,T,E,E,L,_,B,L,U,E,_,1):
				return alpha | X11_STEEL_BLUE_1;
			case _I(S,T,E,E,L, ,B,L,U,E, ,1):
				return alpha | X11_STEEL_BLUE_1;
			case _I(S,T,E,E,L,B,L,U,E,2):
				return alpha | X11_STEEL_BLUE_2;
			case _I(S,T,E,E,L,_,B,L,U,E,_,2):
				return alpha | X11_STEEL_BLUE_2;
			case _I(S,T,E,E,L, ,B,L,U,E, ,2):
				return alpha | X11_STEEL_BLUE_2;
			case _I(S,T,E,E,L,B,L,U,E,3):
				return alpha | X11_STEEL_BLUE_3;
			case _I(S,T,E,E,L,_,B,L,U,E,_,3):
				return alpha | X11_STEEL_BLUE_3;
			case _I(S,T,E,E,L, ,B,L,U,E, ,3):
				return alpha | X11_STEEL_BLUE_3;
			case _I(S,T,E,E,L,B,L,U,E,4):
				return alpha | X11_STEEL_BLUE_4;
			case _I(S,T,E,E,L,_,B,L,U,E,_,4):
				return alpha | X11_STEEL_BLUE_4;
			case _I(S,T,E,E,L, ,B,L,U,E, ,4):
				return alpha | X11_STEEL_BLUE_4;
			case _I(D,E,E,P,S,K,Y,B,L,U,E,1):
				return alpha | X11_DEEP_SKY_BLUE_1;
			case _I(D,E,E,P,_,S,K,Y,_,B,L,U,E,_,1):
				return alpha | X11_DEEP_SKY_BLUE_1;
			case _I(D,E,E,P, ,S,K,Y, ,B,L,U,E, ,1):
				return alpha | X11_DEEP_SKY_BLUE_1;
			case _I(D,E,E,P,S,K,Y,B,L,U,E,2):
				return alpha | X11_DEEP_SKY_BLUE_2;
			case _I(D,E,E,P,_,S,K,Y,_,B,L,U,E,_,2):
				return alpha | X11_DEEP_SKY_BLUE_2;
			case _I(D,E,E,P, ,S,K,Y, ,B,L,U,E, ,2):
				return alpha | X11_DEEP_SKY_BLUE_2;
			case _I(D,E,E,P,S,K,Y,B,L,U,E,3):
				return alpha | X11_DEEP_SKY_BLUE_3;
			case _I(D,E,E,P,_,S,K,Y,_,B,L,U,E,_,3):
				return alpha | X11_DEEP_SKY_BLUE_3;
			case _I(D,E,E,P, ,S,K,Y, ,B,L,U,E, ,3):
				return alpha | X11_DEEP_SKY_BLUE_3;
			case _I(D,E,E,P,S,K,Y,B,L,U,E,4):
				return alpha | X11_DEEP_SKY_BLUE_4;
			case _I(D,E,E,P,_,S,K,Y,_,B,L,U,E,_,4):
				return alpha | X11_DEEP_SKY_BLUE_4;
			case _I(D,E,E,P, ,S,K,Y, ,B,L,U,E, ,4):
				return alpha | X11_DEEP_SKY_BLUE_4;
			case _I(S,K,Y,B,L,U,E,1):
				return alpha | X11_SKY_BLUE_1;
			case _I(S,K,Y,_,B,L,U,E,_,1):
				return alpha | X11_SKY_BLUE_1;
			case _I(S,K,Y, ,B,L,U,E, ,1):
				return alpha | X11_SKY_BLUE_1;
			case _I(S,K,Y,B,L,U,E,2):
				return alpha | X11_SKY_BLUE_2;
			case _I(S,K,Y,_,B,L,U,E,_,2):
				return alpha | X11_SKY_BLUE_2;
			case _I(S,K,Y, ,B,L,U,E, ,2):
				return alpha | X11_SKY_BLUE_2;
			case _I(S,K,Y,B,L,U,E,3):
				return alpha | X11_SKY_BLUE_3;
			case _I(S,K,Y,_,B,L,U,E,_,3):
				return alpha | X11_SKY_BLUE_3;
			case _I(S,K,Y, ,B,L,U,E, ,3):
				return alpha | X11_SKY_BLUE_3;
			case _I(S,K,Y,B,L,U,E,4):
				return alpha | X11_SKY_BLUE_4;
			case _I(S,K,Y,_,B,L,U,E,_,4):
				return alpha | X11_SKY_BLUE_4;
			case _I(S,K,Y, ,B,L,U,E, ,4):
				return alpha | X11_SKY_BLUE_4;
			case _I(L,I,G,H,T,S,K,Y,B,L,U,E,1):
				return alpha | X11_LIGHT_SKY_BLUE_1;
			case _I(L,I,G,H,T,_,S,K,Y,_,B,L,U,E,_,1):
				return alpha | X11_LIGHT_SKY_BLUE_1;
			case _I(L,I,G,H,T, ,S,K,Y, ,B,L,U,E, ,1):
				return alpha | X11_LIGHT_SKY_BLUE_1;
			case _I(L,I,G,H,T,S,K,Y,B,L,U,E,2):
				return alpha | X11_LIGHT_SKY_BLUE_2;
			case _I(L,I,G,H,T,_,S,K,Y,_,B,L,U,E,_,2):
				return alpha | X11_LIGHT_SKY_BLUE_2;
			case _I(L,I,G,H,T, ,S,K,Y, ,B,L,U,E, ,2):
				return alpha | X11_LIGHT_SKY_BLUE_2;
			case _I(L,I,G,H,T,S,K,Y,B,L,U,E,3):
				return alpha | X11_LIGHT_SKY_BLUE_3;
			case _I(L,I,G,H,T,_,S,K,Y,_,B,L,U,E,_,3):
				return alpha | X11_LIGHT_SKY_BLUE_3;
			case _I(L,I,G,H,T, ,S,K,Y, ,B,L,U,E, ,3):
				return alpha | X11_LIGHT_SKY_BLUE_3;
			case _I(L,I,G,H,T,S,K,Y,B,L,U,E,4):
				return alpha | X11_LIGHT_SKY_BLUE_4;
			case _I(L,I,G,H,T,_,S,K,Y,_,B,L,U,E,_,4):
				return alpha | X11_LIGHT_SKY_BLUE_4;
			case _I(L,I,G,H,T, ,S,K,Y, ,B,L,U,E, ,4):
				return alpha | X11_LIGHT_SKY_BLUE_4;
			case _I(S,L,A,T,E,G,R,A,Y,1):
				return alpha | X11_SLATE_GRAY_1;
			case _I(S,L,A,T,E,_,G,R,A,Y,_,1):
				return alpha | X11_SLATE_GRAY_1;
			case _I(S,L,A,T,E, ,G,R,A,Y, ,1):
				return alpha | X11_SLATE_GRAY_1;
			case _I(S,L,A,T,E,G,R,A,Y,2):
				return alpha | X11_SLATE_GRAY_2;
			case _I(S,L,A,T,E,_,G,R,A,Y,_,2):
				return alpha | X11_SLATE_GRAY_2;
			case _I(S,L,A,T,E, ,G,R,A,Y, ,2):
				return alpha | X11_SLATE_GRAY_2;
			case _I(S,L,A,T,E,G,R,A,Y,3):
				return alpha | X11_SLATE_GRAY_3;
			case _I(S,L,A,T,E,_,G,R,A,Y,_,3):
				return alpha | X11_SLATE_GRAY_3;
			case _I(S,L,A,T,E, ,G,R,A,Y, ,3):
				return alpha | X11_SLATE_GRAY_3;
			case _I(S,L,A,T,E,G,R,A,Y,4):
				return alpha | X11_SLATE_GRAY_4;
			case _I(S,L,A,T,E,_,G,R,A,Y,_,4):
				return alpha | X11_SLATE_GRAY_4;
			case _I(S,L,A,T,E, ,G,R,A,Y, ,4):
				return alpha | X11_SLATE_GRAY_4;
			case _I(L,I,G,H,T,S,T,E,E,L,B,L,U,E,1):
				return alpha | X11_LIGHT_STEEL_BLUE_1;
			case _I(L,I,G,H,T,_,S,T,E,E,L,_,B,L,U,E,_,1):
				return alpha | X11_LIGHT_STEEL_BLUE_1;
			case _I(L,I,G,H,T, ,S,T,E,E,L, ,B,L,U,E, ,1):
				return alpha | X11_LIGHT_STEEL_BLUE_1;
			case _I(L,I,G,H,T,S,T,E,E,L,B,L,U,E,2):
				return alpha | X11_LIGHT_STEEL_BLUE_2;
			case _I(L,I,G,H,T,_,S,T,E,E,L,_,B,L,U,E,_,2):
				return alpha | X11_LIGHT_STEEL_BLUE_2;
			case _I(L,I,G,H,T, ,S,T,E,E,L, ,B,L,U,E, ,2):
				return alpha | X11_LIGHT_STEEL_BLUE_2;
			case _I(L,I,G,H,T,S,T,E,E,L,B,L,U,E,3):
				return alpha | X11_LIGHT_STEEL_BLUE_3;
			case _I(L,I,G,H,T,_,S,T,E,E,L,_,B,L,U,E,_,3):
				return alpha | X11_LIGHT_STEEL_BLUE_3;
			case _I(L,I,G,H,T, ,S,T,E,E,L, ,B,L,U,E, ,3):
				return alpha | X11_LIGHT_STEEL_BLUE_3;
			case _I(L,I,G,H,T,S,T,E,E,L,B,L,U,E,4):
				return alpha | X11_LIGHT_STEEL_BLUE_4;
			case _I(L,I,G,H,T,_,S,T,E,E,L,_,B,L,U,E,_,4):
				return alpha | X11_LIGHT_STEEL_BLUE_4;
			case _I(L,I,G,H,T, ,S,T,E,E,L, ,B,L,U,E, ,4):
				return alpha | X11_LIGHT_STEEL_BLUE_4;
			case _I(L,I,G,H,T,B,L,U,E,1):
				return alpha | X11_LIGHT_BLUE_1;
			case _I(L,I,G,H,T,_,B,L,U,E,_,1):
				return alpha | X11_LIGHT_BLUE_1;
			case _I(L,I,G,H,T, ,B,L,U,E, ,1):
				return alpha | X11_LIGHT_BLUE_1;
			case _I(L,I,G,H,T,B,L,U,E,2):
				return alpha | X11_LIGHT_BLUE_2;
			case _I(L,I,G,H,T,_,B,L,U,E,_,2):
				return alpha | X11_LIGHT_BLUE_2;
			case _I(L,I,G,H,T, ,B,L,U,E, ,2):
				return alpha | X11_LIGHT_BLUE_2;
			case _I(L,I,G,H,T,B,L,U,E,3):
				return alpha | X11_LIGHT_BLUE_3;
			case _I(L,I,G,H,T,_,B,L,U,E,_,3):
				return alpha | X11_LIGHT_BLUE_3;
			case _I(L,I,G,H,T, ,B,L,U,E, ,3):
				return alpha | X11_LIGHT_BLUE_3;
			case _I(L,I,G,H,T,B,L,U,E,4):
				return alpha | X11_LIGHT_BLUE_4;
			case _I(L,I,G,H,T,_,B,L,U,E,_,4):
				return alpha | X11_LIGHT_BLUE_4;
			case _I(L,I,G,H,T, ,B,L,U,E, ,4):
				return alpha | X11_LIGHT_BLUE_4;
			case _I(L,I,G,H,T,C,Y,A,N,1):
				return alpha | X11_LIGHT_CYAN_1;
			case _I(L,I,G,H,T,_,C,Y,A,N,_,1):
				return alpha | X11_LIGHT_CYAN_1;
			case _I(L,I,G,H,T, ,C,Y,A,N, ,1):
				return alpha | X11_LIGHT_CYAN_1;
			case _I(L,I,G,H,T,C,Y,A,N,2):
				return alpha | X11_LIGHT_CYAN_2;
			case _I(L,I,G,H,T,_,C,Y,A,N,_,2):
				return alpha | X11_LIGHT_CYAN_2;
			case _I(L,I,G,H,T, ,C,Y,A,N, ,2):
				return alpha | X11_LIGHT_CYAN_2;
			case _I(L,I,G,H,T,C,Y,A,N,3):
				return alpha | X11_LIGHT_CYAN_3;
			case _I(L,I,G,H,T,_,C,Y,A,N,_,3):
				return alpha | X11_LIGHT_CYAN_3;
			case _I(L,I,G,H,T, ,C,Y,A,N, ,3):
				return alpha | X11_LIGHT_CYAN_3;
			case _I(L,I,G,H,T,C,Y,A,N,4):
				return alpha | X11_LIGHT_CYAN_4;
			case _I(L,I,G,H,T,_,C,Y,A,N,_,4):
				return alpha | X11_LIGHT_CYAN_4;
			case _I(L,I,G,H,T, ,C,Y,A,N, ,4):
				return alpha | X11_LIGHT_CYAN_4;
			case _I(P,A,L,E,T,U,R,Q,U,O,I,S,E,1):
				return alpha | X11_PALE_TURQUOISE_1;
			case _I(P,A,L,E,_,T,U,R,Q,U,O,I,S,E,_,1):
				return alpha | X11_PALE_TURQUOISE_1;
			case _I(P,A,L,E, ,T,U,R,Q,U,O,I,S,E, ,1):
				return alpha | X11_PALE_TURQUOISE_1;
			case _I(P,A,L,E,T,U,R,Q,U,O,I,S,E,2):
				return alpha | X11_PALE_TURQUOISE_2;
			case _I(P,A,L,E,_,T,U,R,Q,U,O,I,S,E,_,2):
				return alpha | X11_PALE_TURQUOISE_2;
			case _I(P,A,L,E, ,T,U,R,Q,U,O,I,S,E, ,2):
				return alpha | X11_PALE_TURQUOISE_2;
			case _I(P,A,L,E,T,U,R,Q,U,O,I,S,E,3):
				return alpha | X11_PALE_TURQUOISE_3;
			case _I(P,A,L,E,_,T,U,R,Q,U,O,I,S,E,_,3):
				return alpha | X11_PALE_TURQUOISE_3;
			case _I(P,A,L,E, ,T,U,R,Q,U,O,I,S,E, ,3):
				return alpha | X11_PALE_TURQUOISE_3;
			case _I(P,A,L,E,T,U,R,Q,U,O,I,S,E,4):
				return alpha | X11_PALE_TURQUOISE_4;
			case _I(P,A,L,E,_,T,U,R,Q,U,O,I,S,E,_,4):
				return alpha | X11_PALE_TURQUOISE_4;
			case _I(P,A,L,E, ,T,U,R,Q,U,O,I,S,E, ,4):
				return alpha | X11_PALE_TURQUOISE_4;
			case _I(C,A,D,E,T,B,L,U,E,1):
				return alpha | X11_CADET_BLUE_1;
			case _I(C,A,D,E,T,_,B,L,U,E,_,1):
				return alpha | X11_CADET_BLUE_1;
			case _I(C,A,D,E,T, ,B,L,U,E, ,1):
				return alpha | X11_CADET_BLUE_1;
			case _I(C,A,D,E,T,B,L,U,E,2):
				return alpha | X11_CADET_BLUE_2;
			case _I(C,A,D,E,T,_,B,L,U,E,_,2):
				return alpha | X11_CADET_BLUE_2;
			case _I(C,A,D,E,T, ,B,L,U,E, ,2):
				return alpha | X11_CADET_BLUE_2;
			case _I(C,A,D,E,T,B,L,U,E,3):
				return alpha | X11_CADET_BLUE_3;
			case _I(C,A,D,E,T,_,B,L,U,E,_,3):
				return alpha | X11_CADET_BLUE_3;
			case _I(C,A,D,E,T, ,B,L,U,E, ,3):
				return alpha | X11_CADET_BLUE_3;
			case _I(C,A,D,E,T,B,L,U,E,4):
				return alpha | X11_CADET_BLUE_4;
			case _I(C,A,D,E,T,_,B,L,U,E,_,4):
				return alpha | X11_CADET_BLUE_4;
			case _I(C,A,D,E,T, ,B,L,U,E, ,4):
				return alpha | X11_CADET_BLUE_4;
			case _I(T,U,R,Q,U,O,I,S,E,1):
				return alpha | X11_TURQUOISE_1;
			case _I(T,U,R,Q,U,O,I,S,E,_,1):
				return alpha | X11_TURQUOISE_1;
			case _I(T,U,R,Q,U,O,I,S,E, ,1):
				return alpha | X11_TURQUOISE_1;
			case _I(T,U,R,Q,U,O,I,S,E,2):
				return alpha | X11_TURQUOISE_2;
			case _I(T,U,R,Q,U,O,I,S,E,_,2):
				return alpha | X11_TURQUOISE_2;
			case _I(T,U,R,Q,U,O,I,S,E, ,2):
				return alpha | X11_TURQUOISE_2;
			case _I(T,U,R,Q,U,O,I,S,E,3):
				return alpha | X11_TURQUOISE_3;
			case _I(T,U,R,Q,U,O,I,S,E,_,3):
				return alpha | X11_TURQUOISE_3;
			case _I(T,U,R,Q,U,O,I,S,E, ,3):
				return alpha | X11_TURQUOISE_3;
			case _I(T,U,R,Q,U,O,I,S,E,4):
				return alpha | X11_TURQUOISE_4;
			case _I(T,U,R,Q,U,O,I,S,E,_,4):
				return alpha | X11_TURQUOISE_4;
			case _I(T,U,R,Q,U,O,I,S,E, ,4):
				return alpha | X11_TURQUOISE_4;
			case _I(C,Y,A,N,1):
				return alpha | X11_CYAN_1;
			case _I(C,Y,A,N,_,1):
				return alpha | X11_CYAN_1;
			case _I(C,Y,A,N, ,1):
				return alpha | X11_CYAN_1;
			case _I(C,Y,A,N,2):
				return alpha | X11_CYAN_2;
			case _I(C,Y,A,N,_,2):
				return alpha | X11_CYAN_2;
			case _I(C,Y,A,N, ,2):
				return alpha | X11_CYAN_2;
			case _I(C,Y,A,N,3):
				return alpha | X11_CYAN_3;
			case _I(C,Y,A,N,_,3):
				return alpha | X11_CYAN_3;
			case _I(C,Y,A,N, ,3):
				return alpha | X11_CYAN_3;
			case _I(C,Y,A,N,4):
				return alpha | X11_CYAN_4;
			case _I(C,Y,A,N,_,4):
				return alpha | X11_CYAN_4;
			case _I(C,Y,A,N, ,4):
				return alpha | X11_CYAN_4;
			case _I(D,A,R,K,S,L,A,T,E,G,R,A,Y,1):
				return alpha | X11_DARK_SLATE_GRAY_1;
			case _I(D,A,R,K,_,S,L,A,T,E,_,G,R,A,Y,_,1):
				return alpha | X11_DARK_SLATE_GRAY_1;
			case _I(D,A,R,K, ,S,L,A,T,E, ,G,R,A,Y, ,1):
				return alpha | X11_DARK_SLATE_GRAY_1;
			case _I(D,A,R,K,S,L,A,T,E,G,R,A,Y,2):
				return alpha | X11_DARK_SLATE_GRAY_2;
			case _I(D,A,R,K,_,S,L,A,T,E,_,G,R,A,Y,_,2):
				return alpha | X11_DARK_SLATE_GRAY_2;
			case _I(D,A,R,K, ,S,L,A,T,E, ,G,R,A,Y, ,2):
				return alpha | X11_DARK_SLATE_GRAY_2;
			case _I(D,A,R,K,S,L,A,T,E,G,R,A,Y,3):
				return alpha | X11_DARK_SLATE_GRAY_3;
			case _I(D,A,R,K,_,S,L,A,T,E,_,G,R,A,Y,_,3):
				return alpha | X11_DARK_SLATE_GRAY_3;
			case _I(D,A,R,K, ,S,L,A,T,E, ,G,R,A,Y, ,3):
				return alpha | X11_DARK_SLATE_GRAY_3;
			case _I(D,A,R,K,S,L,A,T,E,G,R,A,Y,4):
				return alpha | X11_DARK_SLATE_GRAY_4;
			case _I(D,A,R,K,_,S,L,A,T,E,_,G,R,A,Y,_,4):
				return alpha | X11_DARK_SLATE_GRAY_4;
			case _I(D,A,R,K, ,S,L,A,T,E, ,G,R,A,Y, ,4):
				return alpha | X11_DARK_SLATE_GRAY_4;
			case _I(A,Q,U,A,M,A,R,I,N,E,1):
				return alpha | X11_AQUAMARINE_1;
			case _I(A,Q,U,A,M,A,R,I,N,E,_,1):
				return alpha | X11_AQUAMARINE_1;
			case _I(A,Q,U,A,M,A,R,I,N,E, ,1):
				return alpha | X11_AQUAMARINE_1;
			case _I(A,Q,U,A,M,A,R,I,N,E,2):
				return alpha | X11_AQUAMARINE_2;
			case _I(A,Q,U,A,M,A,R,I,N,E,_,2):
				return alpha | X11_AQUAMARINE_2;
			case _I(A,Q,U,A,M,A,R,I,N,E, ,2):
				return alpha | X11_AQUAMARINE_2;
			case _I(A,Q,U,A,M,A,R,I,N,E,3):
				return alpha | X11_AQUAMARINE_3;
			case _I(A,Q,U,A,M,A,R,I,N,E,_,3):
				return alpha | X11_AQUAMARINE_3;
			case _I(A,Q,U,A,M,A,R,I,N,E, ,3):
				return alpha | X11_AQUAMARINE_3;
			case _I(A,Q,U,A,M,A,R,I,N,E,4):
				return alpha | X11_AQUAMARINE_4;
			case _I(A,Q,U,A,M,A,R,I,N,E,_,4):
				return alpha | X11_AQUAMARINE_4;
			case _I(A,Q,U,A,M,A,R,I,N,E, ,4):
				return alpha | X11_AQUAMARINE_4;
			case _I(D,A,R,K,S,E,A,G,R,E,E,N,1):
				return alpha | X11_DARK_SEA_GREEN_1;
			case _I(D,A,R,K,_,S,E,A,_,G,R,E,E,N,_,1):
				return alpha | X11_DARK_SEA_GREEN_1;
			case _I(D,A,R,K, ,S,E,A, ,G,R,E,E,N, ,1):
				return alpha | X11_DARK_SEA_GREEN_1;
			case _I(D,A,R,K,S,E,A,G,R,E,E,N,2):
				return alpha | X11_DARK_SEA_GREEN_2;
			case _I(D,A,R,K,_,S,E,A,_,G,R,E,E,N,_,2):
				return alpha | X11_DARK_SEA_GREEN_2;
			case _I(D,A,R,K, ,S,E,A, ,G,R,E,E,N, ,2):
				return alpha | X11_DARK_SEA_GREEN_2;
			case _I(D,A,R,K,S,E,A,G,R,E,E,N,3):
				return alpha | X11_DARK_SEA_GREEN_3;
			case _I(D,A,R,K,_,S,E,A,_,G,R,E,E,N,_,3):
				return alpha | X11_DARK_SEA_GREEN_3;
			case _I(D,A,R,K, ,S,E,A, ,G,R,E,E,N, ,3):
				return alpha | X11_DARK_SEA_GREEN_3;
			case _I(D,A,R,K,S,E,A,G,R,E,E,N,4):
				return alpha | X11_DARK_SEA_GREEN_4;
			case _I(D,A,R,K,_,S,E,A,_,G,R,E,E,N,_,4):
				return alpha | X11_DARK_SEA_GREEN_4;
			case _I(D,A,R,K, ,S,E,A, ,G,R,E,E,N, ,4):
				return alpha | X11_DARK_SEA_GREEN_4;
			case _I(S,E,A,G,R,E,E,N,1):
				return alpha | X11_SEA_GREEN_1;
			case _I(S,E,A,_,G,R,E,E,N,_,1):
				return alpha | X11_SEA_GREEN_1;
			case _I(S,E,A, ,G,R,E,E,N, ,1):
				return alpha | X11_SEA_GREEN_1;
			case _I(S,E,A,G,R,E,E,N,2):
				return alpha | X11_SEA_GREEN_2;
			case _I(S,E,A,_,G,R,E,E,N,_,2):
				return alpha | X11_SEA_GREEN_2;
			case _I(S,E,A, ,G,R,E,E,N, ,2):
				return alpha | X11_SEA_GREEN_2;
			case _I(S,E,A,G,R,E,E,N,3):
				return alpha | X11_SEA_GREEN_3;
			case _I(S,E,A,_,G,R,E,E,N,_,3):
				return alpha | X11_SEA_GREEN_3;
			case _I(S,E,A, ,G,R,E,E,N, ,3):
				return alpha | X11_SEA_GREEN_3;
			case _I(S,E,A,G,R,E,E,N,4):
				return alpha | X11_SEA_GREEN_4;
			case _I(S,E,A,_,G,R,E,E,N,_,4):
				return alpha | X11_SEA_GREEN_4;
			case _I(S,E,A, ,G,R,E,E,N, ,4):
				return alpha | X11_SEA_GREEN_4;
			case _I(P,A,L,E,G,R,E,E,N,1):
				return alpha | X11_PALE_GREEN_1;
			case _I(P,A,L,E,_,G,R,E,E,N,_,1):
				return alpha | X11_PALE_GREEN_1;
			case _I(P,A,L,E, ,G,R,E,E,N, ,1):
				return alpha | X11_PALE_GREEN_1;
			case _I(P,A,L,E,G,R,E,E,N,2):
				return alpha | X11_PALE_GREEN_2;
			case _I(P,A,L,E,_,G,R,E,E,N,_,2):
				return alpha | X11_PALE_GREEN_2;
			case _I(P,A,L,E, ,G,R,E,E,N, ,2):
				return alpha | X11_PALE_GREEN_2;
			case _I(P,A,L,E,G,R,E,E,N,3):
				return alpha | X11_PALE_GREEN_3;
			case _I(P,A,L,E,_,G,R,E,E,N,_,3):
				return alpha | X11_PALE_GREEN_3;
			case _I(P,A,L,E, ,G,R,E,E,N, ,3):
				return alpha | X11_PALE_GREEN_3;
			case _I(P,A,L,E,G,R,E,E,N,4):
				return alpha | X11_PALE_GREEN_4;
			case _I(P,A,L,E,_,G,R,E,E,N,_,4):
				return alpha | X11_PALE_GREEN_4;
			case _I(P,A,L,E, ,G,R,E,E,N, ,4):
				return alpha | X11_PALE_GREEN_4;
			case _I(S,P,R,I,N,G,G,R,E,E,N,1):
				return alpha | X11_SPRING_GREEN_1;
			case _I(S,P,R,I,N,G,_,G,R,E,E,N,_,1):
				return alpha | X11_SPRING_GREEN_1;
			case _I(S,P,R,I,N,G, ,G,R,E,E,N, ,1):
				return alpha | X11_SPRING_GREEN_1;
			case _I(S,P,R,I,N,G,G,R,E,E,N,2):
				return alpha | X11_SPRING_GREEN_2;
			case _I(S,P,R,I,N,G,_,G,R,E,E,N,_,2):
				return alpha | X11_SPRING_GREEN_2;
			case _I(S,P,R,I,N,G, ,G,R,E,E,N, ,2):
				return alpha | X11_SPRING_GREEN_2;
			case _I(S,P,R,I,N,G,G,R,E,E,N,3):
				return alpha | X11_SPRING_GREEN_3;
			case _I(S,P,R,I,N,G,_,G,R,E,E,N,_,3):
				return alpha | X11_SPRING_GREEN_3;
			case _I(S,P,R,I,N,G, ,G,R,E,E,N, ,3):
				return alpha | X11_SPRING_GREEN_3;
			case _I(S,P,R,I,N,G,G,R,E,E,N,4):
				return alpha | X11_SPRING_GREEN_4;
			case _I(S,P,R,I,N,G,_,G,R,E,E,N,_,4):
				return alpha | X11_SPRING_GREEN_4;
			case _I(S,P,R,I,N,G, ,G,R,E,E,N, ,4):
				return alpha | X11_SPRING_GREEN_4;
			case _I(G,R,E,E,N,1):
				return alpha | X11_GREEN_1;
			case _I(G,R,E,E,N,_,1):
				return alpha | X11_GREEN_1;
			case _I(G,R,E,E,N, ,1):
				return alpha | X11_GREEN_1;
			case _I(G,R,E,E,N,2):
				return alpha | X11_GREEN_2;
			case _I(G,R,E,E,N,_,2):
				return alpha | X11_GREEN_2;
			case _I(G,R,E,E,N, ,2):
				return alpha | X11_GREEN_2;
			case _I(G,R,E,E,N,3):
				return alpha | X11_GREEN_3;
			case _I(G,R,E,E,N,_,3):
				return alpha | X11_GREEN_3;
			case _I(G,R,E,E,N, ,3):
				return alpha | X11_GREEN_3;
			case _I(G,R,E,E,N,4):
				return alpha | X11_GREEN_4;
			case _I(G,R,E,E,N,_,4):
				return alpha | X11_GREEN_4;
			case _I(G,R,E,E,N, ,4):
				return alpha | X11_GREEN_4;
			case _I(C,H,A,R,T,R,E,U,S,E,1):
				return alpha | X11_CHARTREUSE_1;
			case _I(C,H,A,R,T,R,E,U,S,E,_,1):
				return alpha | X11_CHARTREUSE_1;
			case _I(C,H,A,R,T,R,E,U,S,E, ,1):
				return alpha | X11_CHARTREUSE_1;
			case _I(C,H,A,R,T,R,E,U,S,E,2):
				return alpha | X11_CHARTREUSE_2;
			case _I(C,H,A,R,T,R,E,U,S,E,_,2):
				return alpha | X11_CHARTREUSE_2;
			case _I(C,H,A,R,T,R,E,U,S,E, ,2):
				return alpha | X11_CHARTREUSE_2;
			case _I(C,H,A,R,T,R,E,U,S,E,3):
				return alpha | X11_CHARTREUSE_3;
			case _I(C,H,A,R,T,R,E,U,S,E,_,3):
				return alpha | X11_CHARTREUSE_3;
			case _I(C,H,A,R,T,R,E,U,S,E, ,3):
				return alpha | X11_CHARTREUSE_3;
			case _I(C,H,A,R,T,R,E,U,S,E,4):
				return alpha | X11_CHARTREUSE_4;
			case _I(C,H,A,R,T,R,E,U,S,E,_,4):
				return alpha | X11_CHARTREUSE_4;
			case _I(C,H,A,R,T,R,E,U,S,E, ,4):
				return alpha | X11_CHARTREUSE_4;
			case _I(O,L,I,V,E,D,R,A,B,1):
				return alpha | X11_OLIVE_DRAB_1;
			case _I(O,L,I,V,E,_,D,R,A,B,_,1):
				return alpha | X11_OLIVE_DRAB_1;
			case _I(O,L,I,V,E, ,D,R,A,B, ,1):
				return alpha | X11_OLIVE_DRAB_1;
			case _I(O,L,I,V,E,D,R,A,B,2):
				return alpha | X11_OLIVE_DRAB_2;
			case _I(O,L,I,V,E,_,D,R,A,B,_,2):
				return alpha | X11_OLIVE_DRAB_2;
			case _I(O,L,I,V,E, ,D,R,A,B, ,2):
				return alpha | X11_OLIVE_DRAB_2;
			case _I(O,L,I,V,E,D,R,A,B,3):
				return alpha | X11_OLIVE_DRAB_3;
			case _I(O,L,I,V,E,_,D,R,A,B,_,3):
				return alpha | X11_OLIVE_DRAB_3;
			case _I(O,L,I,V,E, ,D,R,A,B, ,3):
				return alpha | X11_OLIVE_DRAB_3;
			case _I(O,L,I,V,E,D,R,A,B,4):
				return alpha | X11_OLIVE_DRAB_4;
			case _I(O,L,I,V,E,_,D,R,A,B,_,4):
				return alpha | X11_OLIVE_DRAB_4;
			case _I(O,L,I,V,E, ,D,R,A,B, ,4):
				return alpha | X11_OLIVE_DRAB_4;
			case _I(D,A,R,K,O,L,I,V,E,G,R,E,E,N,1):
				return alpha | X11_DARK_OLIVE_GREEN_1;
			case _I(D,A,R,K,_,O,L,I,V,E,_,G,R,E,E,N,_,1):
				return alpha | X11_DARK_OLIVE_GREEN_1;
			case _I(D,A,R,K, ,O,L,I,V,E, ,G,R,E,E,N, ,1):
				return alpha | X11_DARK_OLIVE_GREEN_1;
			case _I(D,A,R,K,O,L,I,V,E,G,R,E,E,N,2):
				return alpha | X11_DARK_OLIVE_GREEN_2;
			case _I(D,A,R,K,_,O,L,I,V,E,_,G,R,E,E,N,_,2):
				return alpha | X11_DARK_OLIVE_GREEN_2;
			case _I(D,A,R,K, ,O,L,I,V,E, ,G,R,E,E,N, ,2):
				return alpha | X11_DARK_OLIVE_GREEN_2;
			case _I(D,A,R,K,O,L,I,V,E,G,R,E,E,N,3):
				return alpha | X11_DARK_OLIVE_GREEN_3;
			case _I(D,A,R,K,_,O,L,I,V,E,_,G,R,E,E,N,_,3):
				return alpha | X11_DARK_OLIVE_GREEN_3;
			case _I(D,A,R,K, ,O,L,I,V,E, ,G,R,E,E,N, ,3):
				return alpha | X11_DARK_OLIVE_GREEN_3;
			case _I(D,A,R,K,O,L,I,V,E,G,R,E,E,N,4):
				return alpha | X11_DARK_OLIVE_GREEN_4;
			case _I(D,A,R,K,_,O,L,I,V,E,_,G,R,E,E,N,_,4):
				return alpha | X11_DARK_OLIVE_GREEN_4;
			case _I(D,A,R,K, ,O,L,I,V,E, ,G,R,E,E,N, ,4):
				return alpha | X11_DARK_OLIVE_GREEN_4;
			case _I(K,H,A,K,I,1):
				return alpha | X11_KHAKI_1;
			case _I(K,H,A,K,I,_,1):
				return alpha | X11_KHAKI_1;
			case _I(K,H,A,K,I, ,1):
				return alpha | X11_KHAKI_1;
			case _I(K,H,A,K,I,2):
				return alpha | X11_KHAKI_2;
			case _I(K,H,A,K,I,_,2):
				return alpha | X11_KHAKI_2;
			case _I(K,H,A,K,I, ,2):
				return alpha | X11_KHAKI_2;
			case _I(K,H,A,K,I,3):
				return alpha | X11_KHAKI_3;
			case _I(K,H,A,K,I,_,3):
				return alpha | X11_KHAKI_3;
			case _I(K,H,A,K,I, ,3):
				return alpha | X11_KHAKI_3;
			case _I(K,H,A,K,I,4):
				return alpha | X11_KHAKI_4;
			case _I(K,H,A,K,I,_,4):
				return alpha | X11_KHAKI_4;
			case _I(K,H,A,K,I, ,4):
				return alpha | X11_KHAKI_4;
			case _I(L,I,G,H,T,G,O,L,D,E,N,R,O,D,1):
				return alpha | X11_LIGHT_GOLDENROD_1;
			case _I(L,I,G,H,T,_,G,O,L,D,E,N,R,O,D,_,1):
				return alpha | X11_LIGHT_GOLDENROD_1;
			case _I(L,I,G,H,T, ,G,O,L,D,E,N,R,O,D, ,1):
				return alpha | X11_LIGHT_GOLDENROD_1;
			case _I(L,I,G,H,T,G,O,L,D,E,N,R,O,D,2):
				return alpha | X11_LIGHT_GOLDENROD_2;
			case _I(L,I,G,H,T,_,G,O,L,D,E,N,R,O,D,_,2):
				return alpha | X11_LIGHT_GOLDENROD_2;
			case _I(L,I,G,H,T, ,G,O,L,D,E,N,R,O,D, ,2):
				return alpha | X11_LIGHT_GOLDENROD_2;
			case _I(L,I,G,H,T,G,O,L,D,E,N,R,O,D,3):
				return alpha | X11_LIGHT_GOLDENROD_3;
			case _I(L,I,G,H,T,_,G,O,L,D,E,N,R,O,D,_,3):
				return alpha | X11_LIGHT_GOLDENROD_3;
			case _I(L,I,G,H,T, ,G,O,L,D,E,N,R,O,D, ,3):
				return alpha | X11_LIGHT_GOLDENROD_3;
			case _I(L,I,G,H,T,G,O,L,D,E,N,R,O,D,4):
				return alpha | X11_LIGHT_GOLDENROD_4;
			case _I(L,I,G,H,T,_,G,O,L,D,E,N,R,O,D,_,4):
				return alpha | X11_LIGHT_GOLDENROD_4;
			case _I(L,I,G,H,T, ,G,O,L,D,E,N,R,O,D, ,4):
				return alpha | X11_LIGHT_GOLDENROD_4;
			case _I(L,I,G,H,T,Y,E,L,L,O,W,1):
				return alpha | X11_LIGHT_YELLOW_1;
			case _I(L,I,G,H,T,_,Y,E,L,L,O,W,_,1):
				return alpha | X11_LIGHT_YELLOW_1;
			case _I(L,I,G,H,T, ,Y,E,L,L,O,W, ,1):
				return alpha | X11_LIGHT_YELLOW_1;
			case _I(L,I,G,H,T,Y,E,L,L,O,W,2):
				return alpha | X11_LIGHT_YELLOW_2;
			case _I(L,I,G,H,T,_,Y,E,L,L,O,W,_,2):
				return alpha | X11_LIGHT_YELLOW_2;
			case _I(L,I,G,H,T, ,Y,E,L,L,O,W, ,2):
				return alpha | X11_LIGHT_YELLOW_2;
			case _I(L,I,G,H,T,Y,E,L,L,O,W,3):
				return alpha | X11_LIGHT_YELLOW_3;
			case _I(L,I,G,H,T,_,Y,E,L,L,O,W,_,3):
				return alpha | X11_LIGHT_YELLOW_3;
			case _I(L,I,G,H,T, ,Y,E,L,L,O,W, ,3):
				return alpha | X11_LIGHT_YELLOW_3;
			case _I(L,I,G,H,T,Y,E,L,L,O,W,4):
				return alpha | X11_LIGHT_YELLOW_4;
			case _I(L,I,G,H,T,_,Y,E,L,L,O,W,_,4):
				return alpha | X11_LIGHT_YELLOW_4;
			case _I(L,I,G,H,T, ,Y,E,L,L,O,W, ,4):
				return alpha | X11_LIGHT_YELLOW_4;
			case _I(Y,E,L,L,O,W,1):
				return alpha | X11_YELLOW_1;
			case _I(Y,E,L,L,O,W,_,1):
				return alpha | X11_YELLOW_1;
			case _I(Y,E,L,L,O,W, ,1):
				return alpha | X11_YELLOW_1;
			case _I(Y,E,L,L,O,W,2):
				return alpha | X11_YELLOW_2;
			case _I(Y,E,L,L,O,W,_,2):
				return alpha | X11_YELLOW_2;
			case _I(Y,E,L,L,O,W, ,2):
				return alpha | X11_YELLOW_2;
			case _I(Y,E,L,L,O,W,3):
				return alpha | X11_YELLOW_3;
			case _I(Y,E,L,L,O,W,_,3):
				return alpha | X11_YELLOW_3;
			case _I(Y,E,L,L,O,W, ,3):
				return alpha | X11_YELLOW_3;
			case _I(Y,E,L,L,O,W,4):
				return alpha | X11_YELLOW_4;
			case _I(Y,E,L,L,O,W,_,4):
				return alpha | X11_YELLOW_4;
			case _I(Y,E,L,L,O,W, ,4):
				return alpha | X11_YELLOW_4;
			case _I(G,O,L,D,1):
				return alpha | X11_GOLD_1;
			case _I(G,O,L,D,_,1):
				return alpha | X11_GOLD_1;
			case _I(G,O,L,D, ,1):
				return alpha | X11_GOLD_1;
			case _I(G,O,L,D,2):
				return alpha | X11_GOLD_2;
			case _I(G,O,L,D,_,2):
				return alpha | X11_GOLD_2;
			case _I(G,O,L,D, ,2):
				return alpha | X11_GOLD_2;
			case _I(G,O,L,D,3):
				return alpha | X11_GOLD_3;
			case _I(G,O,L,D,_,3):
				return alpha | X11_GOLD_3;
			case _I(G,O,L,D, ,3):
				return alpha | X11_GOLD_3;
			case _I(G,O,L,D,4):
				return alpha | X11_GOLD_4;
			case _I(G,O,L,D,_,4):
				return alpha | X11_GOLD_4;
			case _I(G,O,L,D, ,4):
				return alpha | X11_GOLD_4;
			case _I(G,O,L,D,E,N,R,O,D,1):
				return alpha | X11_GOLDENROD_1;
			case _I(G,O,L,D,E,N,R,O,D,_,1):
				return alpha | X11_GOLDENROD_1;
			case _I(G,O,L,D,E,N,R,O,D, ,1):
				return alpha | X11_GOLDENROD_1;
			case _I(G,O,L,D,E,N,R,O,D,2):
				return alpha | X11_GOLDENROD_2;
			case _I(G,O,L,D,E,N,R,O,D,_,2):
				return alpha | X11_GOLDENROD_2;
			case _I(G,O,L,D,E,N,R,O,D, ,2):
				return alpha | X11_GOLDENROD_2;
			case _I(G,O,L,D,E,N,R,O,D,3):
				return alpha | X11_GOLDENROD_3;
			case _I(G,O,L,D,E,N,R,O,D,_,3):
				return alpha | X11_GOLDENROD_3;
			case _I(G,O,L,D,E,N,R,O,D, ,3):
				return alpha | X11_GOLDENROD_3;
			case _I(G,O,L,D,E,N,R,O,D,4):
				return alpha | X11_GOLDENROD_4;
			case _I(G,O,L,D,E,N,R,O,D,_,4):
				return alpha | X11_GOLDENROD_4;
			case _I(G,O,L,D,E,N,R,O,D, ,4):
				return alpha | X11_GOLDENROD_4;
			case _I(D,A,R,K,G,O,L,D,E,N,R,O,D,1):
				return alpha | X11_DARK_GOLDENROD_1;
			case _I(D,A,R,K,_,G,O,L,D,E,N,R,O,D,_,1):
				return alpha | X11_DARK_GOLDENROD_1;
			case _I(D,A,R,K, ,G,O,L,D,E,N,R,O,D, ,1):
				return alpha | X11_DARK_GOLDENROD_1;
			case _I(D,A,R,K,G,O,L,D,E,N,R,O,D,2):
				return alpha | X11_DARK_GOLDENROD_2;
			case _I(D,A,R,K,_,G,O,L,D,E,N,R,O,D,_,2):
				return alpha | X11_DARK_GOLDENROD_2;
			case _I(D,A,R,K, ,G,O,L,D,E,N,R,O,D, ,2):
				return alpha | X11_DARK_GOLDENROD_2;
			case _I(D,A,R,K,G,O,L,D,E,N,R,O,D,3):
				return alpha | X11_DARK_GOLDENROD_3;
			case _I(D,A,R,K,_,G,O,L,D,E,N,R,O,D,_,3):
				return alpha | X11_DARK_GOLDENROD_3;
			case _I(D,A,R,K, ,G,O,L,D,E,N,R,O,D, ,3):
				return alpha | X11_DARK_GOLDENROD_3;
			case _I(D,A,R,K,G,O,L,D,E,N,R,O,D,4):
				return alpha | X11_DARK_GOLDENROD_4;
			case _I(D,A,R,K,_,G,O,L,D,E,N,R,O,D,_,4):
				return alpha | X11_DARK_GOLDENROD_4;
			case _I(D,A,R,K, ,G,O,L,D,E,N,R,O,D, ,4):
				return alpha | X11_DARK_GOLDENROD_4;
			case _I(R,O,S,Y,B,R,O,W,N,1):
				return alpha | X11_ROSY_BROWN_1;
			case _I(R,O,S,Y,_,B,R,O,W,N,_,1):
				return alpha | X11_ROSY_BROWN_1;
			case _I(R,O,S,Y, ,B,R,O,W,N, ,1):
				return alpha | X11_ROSY_BROWN_1;
			case _I(R,O,S,Y,B,R,O,W,N,2):
				return alpha | X11_ROSY_BROWN_2;
			case _I(R,O,S,Y,_,B,R,O,W,N,_,2):
				return alpha | X11_ROSY_BROWN_2;
			case _I(R,O,S,Y, ,B,R,O,W,N, ,2):
				return alpha | X11_ROSY_BROWN_2;
			case _I(R,O,S,Y,B,R,O,W,N,3):
				return alpha | X11_ROSY_BROWN_3;
			case _I(R,O,S,Y,_,B,R,O,W,N,_,3):
				return alpha | X11_ROSY_BROWN_3;
			case _I(R,O,S,Y, ,B,R,O,W,N, ,3):
				return alpha | X11_ROSY_BROWN_3;
			case _I(R,O,S,Y,B,R,O,W,N,4):
				return alpha | X11_ROSY_BROWN_4;
			case _I(R,O,S,Y,_,B,R,O,W,N,_,4):
				return alpha | X11_ROSY_BROWN_4;
			case _I(R,O,S,Y, ,B,R,O,W,N, ,4):
				return alpha | X11_ROSY_BROWN_4;
			case _I(I,N,D,I,A,N,R,E,D,1):
				return alpha | X11_INDIAN_RED_1;
			case _I(I,N,D,I,A,N,_,R,E,D,_,1):
				return alpha | X11_INDIAN_RED_1;
			case _I(I,N,D,I,A,N, ,R,E,D, ,1):
				return alpha | X11_INDIAN_RED_1;
			case _I(I,N,D,I,A,N,R,E,D,2):
				return alpha | X11_INDIAN_RED_2;
			case _I(I,N,D,I,A,N,_,R,E,D,_,2):
				return alpha | X11_INDIAN_RED_2;
			case _I(I,N,D,I,A,N, ,R,E,D, ,2):
				return alpha | X11_INDIAN_RED_2;
			case _I(I,N,D,I,A,N,R,E,D,3):
				return alpha | X11_INDIAN_RED_3;
			case _I(I,N,D,I,A,N,_,R,E,D,_,3):
				return alpha | X11_INDIAN_RED_3;
			case _I(I,N,D,I,A,N, ,R,E,D, ,3):
				return alpha | X11_INDIAN_RED_3;
			case _I(I,N,D,I,A,N,R,E,D,4):
				return alpha | X11_INDIAN_RED_4;
			case _I(I,N,D,I,A,N,_,R,E,D,_,4):
				return alpha | X11_INDIAN_RED_4;
			case _I(I,N,D,I,A,N, ,R,E,D, ,4):
				return alpha | X11_INDIAN_RED_4;
			case _I(S,I,E,N,N,A,1):
				return alpha | X11_SIENNA_1;
			case _I(S,I,E,N,N,A,_,1):
				return alpha | X11_SIENNA_1;
			case _I(S,I,E,N,N,A, ,1):
				return alpha | X11_SIENNA_1;
			case _I(S,I,E,N,N,A,2):
				return alpha | X11_SIENNA_2;
			case _I(S,I,E,N,N,A,_,2):
				return alpha | X11_SIENNA_2;
			case _I(S,I,E,N,N,A, ,2):
				return alpha | X11_SIENNA_2;
			case _I(S,I,E,N,N,A,3):
				return alpha | X11_SIENNA_3;
			case _I(S,I,E,N,N,A,_,3):
				return alpha | X11_SIENNA_3;
			case _I(S,I,E,N,N,A, ,3):
				return alpha | X11_SIENNA_3;
			case _I(S,I,E,N,N,A,4):
				return alpha | X11_SIENNA_4;
			case _I(S,I,E,N,N,A,_,4):
				return alpha | X11_SIENNA_4;
			case _I(S,I,E,N,N,A, ,4):
				return alpha | X11_SIENNA_4;
			case _I(B,U,R,L,Y,W,O,O,D,1):
				return alpha | X11_BURLYWOOD_1;
			case _I(B,U,R,L,Y,W,O,O,D,_,1):
				return alpha | X11_BURLYWOOD_1;
			case _I(B,U,R,L,Y,W,O,O,D, ,1):
				return alpha | X11_BURLYWOOD_1;
			case _I(B,U,R,L,Y,W,O,O,D,2):
				return alpha | X11_BURLYWOOD_2;
			case _I(B,U,R,L,Y,W,O,O,D,_,2):
				return alpha | X11_BURLYWOOD_2;
			case _I(B,U,R,L,Y,W,O,O,D, ,2):
				return alpha | X11_BURLYWOOD_2;
			case _I(B,U,R,L,Y,W,O,O,D,3):
				return alpha | X11_BURLYWOOD_3;
			case _I(B,U,R,L,Y,W,O,O,D,_,3):
				return alpha | X11_BURLYWOOD_3;
			case _I(B,U,R,L,Y,W,O,O,D, ,3):
				return alpha | X11_BURLYWOOD_3;
			case _I(B,U,R,L,Y,W,O,O,D,4):
				return alpha | X11_BURLYWOOD_4;
			case _I(B,U,R,L,Y,W,O,O,D,_,4):
				return alpha | X11_BURLYWOOD_4;
			case _I(B,U,R,L,Y,W,O,O,D, ,4):
				return alpha | X11_BURLYWOOD_4;
			case _I(W,H,E,A,T,1):
				return alpha | X11_WHEAT_1;
			case _I(W,H,E,A,T,_,1):
				return alpha | X11_WHEAT_1;
			case _I(W,H,E,A,T, ,1):
				return alpha | X11_WHEAT_1;
			case _I(W,H,E,A,T,2):
				return alpha | X11_WHEAT_2;
			case _I(W,H,E,A,T,_,2):
				return alpha | X11_WHEAT_2;
			case _I(W,H,E,A,T, ,2):
				return alpha | X11_WHEAT_2;
			case _I(W,H,E,A,T,3):
				return alpha | X11_WHEAT_3;
			case _I(W,H,E,A,T,_,3):
				return alpha | X11_WHEAT_3;
			case _I(W,H,E,A,T, ,3):
				return alpha | X11_WHEAT_3;
			case _I(W,H,E,A,T,4):
				return alpha | X11_WHEAT_4;
			case _I(W,H,E,A,T,_,4):
				return alpha | X11_WHEAT_4;
			case _I(W,H,E,A,T, ,4):
				return alpha | X11_WHEAT_4;
			case _I(T,A,N,1):
				return alpha | X11_TAN_1;
			case _I(T,A,N,_,1):
				return alpha | X11_TAN_1;
			case _I(T,A,N, ,1):
				return alpha | X11_TAN_1;
			case _I(T,A,N,2):
				return alpha | X11_TAN_2;
			case _I(T,A,N,_,2):
				return alpha | X11_TAN_2;
			case _I(T,A,N, ,2):
				return alpha | X11_TAN_2;
			case _I(T,A,N,3):
				return alpha | X11_TAN_3;
			case _I(T,A,N,_,3):
				return alpha | X11_TAN_3;
			case _I(T,A,N, ,3):
				return alpha | X11_TAN_3;
			case _I(T,A,N,4):
				return alpha | X11_TAN_4;
			case _I(T,A,N,_,4):
				return alpha | X11_TAN_4;
			case _I(T,A,N, ,4):
				return alpha | X11_TAN_4;
			case _I(C,H,O,C,O,L,A,T,E,1):
				return alpha | X11_CHOCOLATE_1;
			case _I(C,H,O,C,O,L,A,T,E,_,1):
				return alpha | X11_CHOCOLATE_1;
			case _I(C,H,O,C,O,L,A,T,E, ,1):
				return alpha | X11_CHOCOLATE_1;
			case _I(C,H,O,C,O,L,A,T,E,2):
				return alpha | X11_CHOCOLATE_2;
			case _I(C,H,O,C,O,L,A,T,E,_,2):
				return alpha | X11_CHOCOLATE_2;
			case _I(C,H,O,C,O,L,A,T,E, ,2):
				return alpha | X11_CHOCOLATE_2;
			case _I(C,H,O,C,O,L,A,T,E,3):
				return alpha | X11_CHOCOLATE_3;
			case _I(C,H,O,C,O,L,A,T,E,_,3):
				return alpha | X11_CHOCOLATE_3;
			case _I(C,H,O,C,O,L,A,T,E, ,3):
				return alpha | X11_CHOCOLATE_3;
			case _I(C,H,O,C,O,L,A,T,E,4):
				return alpha | X11_CHOCOLATE_4;
			case _I(C,H,O,C,O,L,A,T,E,_,4):
				return alpha | X11_CHOCOLATE_4;
			case _I(C,H,O,C,O,L,A,T,E, ,4):
				return alpha | X11_CHOCOLATE_4;
			case _I(F,I,R,E,B,R,I,C,K,1):
				return alpha | X11_FIREBRICK_1;
			case _I(F,I,R,E,B,R,I,C,K,_,1):
				return alpha | X11_FIREBRICK_1;
			case _I(F,I,R,E,B,R,I,C,K, ,1):
				return alpha | X11_FIREBRICK_1;
			case _I(F,I,R,E,B,R,I,C,K,2):
				return alpha | X11_FIREBRICK_2;
			case _I(F,I,R,E,B,R,I,C,K,_,2):
				return alpha | X11_FIREBRICK_2;
			case _I(F,I,R,E,B,R,I,C,K, ,2):
				return alpha | X11_FIREBRICK_2;
			case _I(F,I,R,E,B,R,I,C,K,3):
				return alpha | X11_FIREBRICK_3;
			case _I(F,I,R,E,B,R,I,C,K,_,3):
				return alpha | X11_FIREBRICK_3;
			case _I(F,I,R,E,B,R,I,C,K, ,3):
				return alpha | X11_FIREBRICK_3;
			case _I(F,I,R,E,B,R,I,C,K,4):
				return alpha | X11_FIREBRICK_4;
			case _I(F,I,R,E,B,R,I,C,K,_,4):
				return alpha | X11_FIREBRICK_4;
			case _I(F,I,R,E,B,R,I,C,K, ,4):
				return alpha | X11_FIREBRICK_4;
			case _I(B,R,O,W,N,1):
				return alpha | X11_BROWN_1;
			case _I(B,R,O,W,N,_,1):
				return alpha | X11_BROWN_1;
			case _I(B,R,O,W,N, ,1):
				return alpha | X11_BROWN_1;
			case _I(B,R,O,W,N,2):
				return alpha | X11_BROWN_2;
			case _I(B,R,O,W,N,_,2):
				return alpha | X11_BROWN_2;
			case _I(B,R,O,W,N, ,2):
				return alpha | X11_BROWN_2;
			case _I(B,R,O,W,N,3):
				return alpha | X11_BROWN_3;
			case _I(B,R,O,W,N,_,3):
				return alpha | X11_BROWN_3;
			case _I(B,R,O,W,N, ,3):
				return alpha | X11_BROWN_3;
			case _I(B,R,O,W,N,4):
				return alpha | X11_BROWN_4;
			case _I(B,R,O,W,N,_,4):
				return alpha | X11_BROWN_4;
			case _I(B,R,O,W,N, ,4):
				return alpha | X11_BROWN_4;
			case _I(S,A,L,M,O,N,1):
				return alpha | X11_SALMON_1;
			case _I(S,A,L,M,O,N,_,1):
				return alpha | X11_SALMON_1;
			case _I(S,A,L,M,O,N, ,1):
				return alpha | X11_SALMON_1;
			case _I(S,A,L,M,O,N,2):
				return alpha | X11_SALMON_2;
			case _I(S,A,L,M,O,N,_,2):
				return alpha | X11_SALMON_2;
			case _I(S,A,L,M,O,N, ,2):
				return alpha | X11_SALMON_2;
			case _I(S,A,L,M,O,N,3):
				return alpha | X11_SALMON_3;
			case _I(S,A,L,M,O,N,_,3):
				return alpha | X11_SALMON_3;
			case _I(S,A,L,M,O,N, ,3):
				return alpha | X11_SALMON_3;
			case _I(S,A,L,M,O,N,4):
				return alpha | X11_SALMON_4;
			case _I(S,A,L,M,O,N,_,4):
				return alpha | X11_SALMON_4;
			case _I(S,A,L,M,O,N, ,4):
				return alpha | X11_SALMON_4;
			case _I(L,I,G,H,T,S,A,L,M,O,N,1):
				return alpha | X11_LIGHT_SALMON_1;
			case _I(L,I,G,H,T,_,S,A,L,M,O,N,_,1):
				return alpha | X11_LIGHT_SALMON_1;
			case _I(L,I,G,H,T, ,S,A,L,M,O,N, ,1):
				return alpha | X11_LIGHT_SALMON_1;
			case _I(L,I,G,H,T,S,A,L,M,O,N,2):
				return alpha | X11_LIGHT_SALMON_2;
			case _I(L,I,G,H,T,_,S,A,L,M,O,N,_,2):
				return alpha | X11_LIGHT_SALMON_2;
			case _I(L,I,G,H,T, ,S,A,L,M,O,N, ,2):
				return alpha | X11_LIGHT_SALMON_2;
			case _I(L,I,G,H,T,S,A,L,M,O,N,3):
				return alpha | X11_LIGHT_SALMON_3;
			case _I(L,I,G,H,T,_,S,A,L,M,O,N,_,3):
				return alpha | X11_LIGHT_SALMON_3;
			case _I(L,I,G,H,T, ,S,A,L,M,O,N, ,3):
				return alpha | X11_LIGHT_SALMON_3;
			case _I(L,I,G,H,T,S,A,L,M,O,N,4):
				return alpha | X11_LIGHT_SALMON_4;
			case _I(L,I,G,H,T,_,S,A,L,M,O,N,_,4):
				return alpha | X11_LIGHT_SALMON_4;
			case _I(L,I,G,H,T, ,S,A,L,M,O,N, ,4):
				return alpha | X11_LIGHT_SALMON_4;
			case _I(O,R,A,N,G,E,1):
				return alpha | X11_ORANGE_1;
			case _I(O,R,A,N,G,E,_,1):
				return alpha | X11_ORANGE_1;
			case _I(O,R,A,N,G,E, ,1):
				return alpha | X11_ORANGE_1;
			case _I(O,R,A,N,G,E,2):
				return alpha | X11_ORANGE_2;
			case _I(O,R,A,N,G,E,_,2):
				return alpha | X11_ORANGE_2;
			case _I(O,R,A,N,G,E, ,2):
				return alpha | X11_ORANGE_2;
			case _I(O,R,A,N,G,E,3):
				return alpha | X11_ORANGE_3;
			case _I(O,R,A,N,G,E,_,3):
				return alpha | X11_ORANGE_3;
			case _I(O,R,A,N,G,E, ,3):
				return alpha | X11_ORANGE_3;
			case _I(O,R,A,N,G,E,4):
				return alpha | X11_ORANGE_4;
			case _I(O,R,A,N,G,E,_,4):
				return alpha | X11_ORANGE_4;
			case _I(O,R,A,N,G,E, ,4):
				return alpha | X11_ORANGE_4;
			case _I(D,A,R,K,O,R,A,N,G,E,1):
				return alpha | X11_DARK_ORANGE_1;
			case _I(D,A,R,K,_,O,R,A,N,G,E,_,1):
				return alpha | X11_DARK_ORANGE_1;
			case _I(D,A,R,K, ,O,R,A,N,G,E, ,1):
				return alpha | X11_DARK_ORANGE_1;
			case _I(D,A,R,K,O,R,A,N,G,E,2):
				return alpha | X11_DARK_ORANGE_2;
			case _I(D,A,R,K,_,O,R,A,N,G,E,_,2):
				return alpha | X11_DARK_ORANGE_2;
			case _I(D,A,R,K, ,O,R,A,N,G,E, ,2):
				return alpha | X11_DARK_ORANGE_2;
			case _I(D,A,R,K,O,R,A,N,G,E,3):
				return alpha | X11_DARK_ORANGE_3;
			case _I(D,A,R,K,_,O,R,A,N,G,E,_,3):
				return alpha | X11_DARK_ORANGE_3;
			case _I(D,A,R,K, ,O,R,A,N,G,E, ,3):
				return alpha | X11_DARK_ORANGE_3;
			case _I(D,A,R,K,O,R,A,N,G,E,4):
				return alpha | X11_DARK_ORANGE_4;
			case _I(D,A,R,K,_,O,R,A,N,G,E,_,4):
				return alpha | X11_DARK_ORANGE_4;
			case _I(D,A,R,K, ,O,R,A,N,G,E, ,4):
				return alpha | X11_DARK_ORANGE_4;
			case _I(C,O,R,A,L,1):
				return alpha | X11_CORAL_1;
			case _I(C,O,R,A,L,_,1):
				return alpha | X11_CORAL_1;
			case _I(C,O,R,A,L, ,1):
				return alpha | X11_CORAL_1;
			case _I(C,O,R,A,L,2):
				return alpha | X11_CORAL_2;
			case _I(C,O,R,A,L,_,2):
				return alpha | X11_CORAL_2;
			case _I(C,O,R,A,L, ,2):
				return alpha | X11_CORAL_2;
			case _I(C,O,R,A,L,3):
				return alpha | X11_CORAL_3;
			case _I(C,O,R,A,L,_,3):
				return alpha | X11_CORAL_3;
			case _I(C,O,R,A,L, ,3):
				return alpha | X11_CORAL_3;
			case _I(C,O,R,A,L,4):
				return alpha | X11_CORAL_4;
			case _I(C,O,R,A,L,_,4):
				return alpha | X11_CORAL_4;
			case _I(C,O,R,A,L, ,4):
				return alpha | X11_CORAL_4;
			case _I(T,O,M,A,T,O,1):
				return alpha | X11_TOMATO_1;
			case _I(T,O,M,A,T,O,_,1):
				return alpha | X11_TOMATO_1;
			case _I(T,O,M,A,T,O, ,1):
				return alpha | X11_TOMATO_1;
			case _I(T,O,M,A,T,O,2):
				return alpha | X11_TOMATO_2;
			case _I(T,O,M,A,T,O,_,2):
				return alpha | X11_TOMATO_2;
			case _I(T,O,M,A,T,O, ,2):
				return alpha | X11_TOMATO_2;
			case _I(T,O,M,A,T,O,3):
				return alpha | X11_TOMATO_3;
			case _I(T,O,M,A,T,O,_,3):
				return alpha | X11_TOMATO_3;
			case _I(T,O,M,A,T,O, ,3):
				return alpha | X11_TOMATO_3;
			case _I(T,O,M,A,T,O,4):
				return alpha | X11_TOMATO_4;
			case _I(T,O,M,A,T,O,_,4):
				return alpha | X11_TOMATO_4;
			case _I(T,O,M,A,T,O, ,4):
				return alpha | X11_TOMATO_4;
			case _I(O,R,A,N,G,E,R,E,D,1):
				return alpha | X11_ORANGE_RED_1;
			case _I(O,R,A,N,G,E,_,R,E,D,_,1):
				return alpha | X11_ORANGE_RED_1;
			case _I(O,R,A,N,G,E, ,R,E,D, ,1):
				return alpha | X11_ORANGE_RED_1;
			case _I(O,R,A,N,G,E,R,E,D,2):
				return alpha | X11_ORANGE_RED_2;
			case _I(O,R,A,N,G,E,_,R,E,D,_,2):
				return alpha | X11_ORANGE_RED_2;
			case _I(O,R,A,N,G,E, ,R,E,D, ,2):
				return alpha | X11_ORANGE_RED_2;
			case _I(O,R,A,N,G,E,R,E,D,3):
				return alpha | X11_ORANGE_RED_3;
			case _I(O,R,A,N,G,E,_,R,E,D,_,3):
				return alpha | X11_ORANGE_RED_3;
			case _I(O,R,A,N,G,E, ,R,E,D, ,3):
				return alpha | X11_ORANGE_RED_3;
			case _I(O,R,A,N,G,E,R,E,D,4):
				return alpha | X11_ORANGE_RED_4;
			case _I(O,R,A,N,G,E,_,R,E,D,_,4):
				return alpha | X11_ORANGE_RED_4;
			case _I(O,R,A,N,G,E, ,R,E,D, ,4):
				return alpha | X11_ORANGE_RED_4;
			case _I(R,E,D,1):
				return alpha | X11_RED_1;
			case _I(R,E,D,_,1):
				return alpha | X11_RED_1;
			case _I(R,E,D, ,1):
				return alpha | X11_RED_1;
			case _I(R,E,D,2):
				return alpha | X11_RED_2;
			case _I(R,E,D,_,2):
				return alpha | X11_RED_2;
			case _I(R,E,D, ,2):
				return alpha | X11_RED_2;
			case _I(R,E,D,3):
				return alpha | X11_RED_3;
			case _I(R,E,D,_,3):
				return alpha | X11_RED_3;
			case _I(R,E,D, ,3):
				return alpha | X11_RED_3;
			case _I(R,E,D,4):
				return alpha | X11_RED_4;
			case _I(R,E,D,_,4):
				return alpha | X11_RED_4;
			case _I(R,E,D, ,4):
				return alpha | X11_RED_4;
			case _I(D,E,E,P,P,I,N,K,1):
				return alpha | X11_DEEP_PINK_1;
			case _I(D,E,E,P,_,P,I,N,K,_,1):
				return alpha | X11_DEEP_PINK_1;
			case _I(D,E,E,P, ,P,I,N,K, ,1):
				return alpha | X11_DEEP_PINK_1;
			case _I(D,E,E,P,P,I,N,K,2):
				return alpha | X11_DEEP_PINK_2;
			case _I(D,E,E,P,_,P,I,N,K,_,2):
				return alpha | X11_DEEP_PINK_2;
			case _I(D,E,E,P, ,P,I,N,K, ,2):
				return alpha | X11_DEEP_PINK_2;
			case _I(D,E,E,P,P,I,N,K,3):
				return alpha | X11_DEEP_PINK_3;
			case _I(D,E,E,P,_,P,I,N,K,_,3):
				return alpha | X11_DEEP_PINK_3;
			case _I(D,E,E,P, ,P,I,N,K, ,3):
				return alpha | X11_DEEP_PINK_3;
			case _I(D,E,E,P,P,I,N,K,4):
				return alpha | X11_DEEP_PINK_4;
			case _I(D,E,E,P,_,P,I,N,K,_,4):
				return alpha | X11_DEEP_PINK_4;
			case _I(D,E,E,P, ,P,I,N,K, ,4):
				return alpha | X11_DEEP_PINK_4;
			case _I(H,O,T,P,I,N,K,1):
				return alpha | X11_HOT_PINK_1;
			case _I(H,O,T,_,P,I,N,K,_,1):
				return alpha | X11_HOT_PINK_1;
			case _I(H,O,T, ,P,I,N,K, ,1):
				return alpha | X11_HOT_PINK_1;
			case _I(H,O,T,P,I,N,K,2):
				return alpha | X11_HOT_PINK_2;
			case _I(H,O,T,_,P,I,N,K,_,2):
				return alpha | X11_HOT_PINK_2;
			case _I(H,O,T, ,P,I,N,K, ,2):
				return alpha | X11_HOT_PINK_2;
			case _I(H,O,T,P,I,N,K,3):
				return alpha | X11_HOT_PINK_3;
			case _I(H,O,T,_,P,I,N,K,_,3):
				return alpha | X11_HOT_PINK_3;
			case _I(H,O,T, ,P,I,N,K, ,3):
				return alpha | X11_HOT_PINK_3;
			case _I(H,O,T,P,I,N,K,4):
				return alpha | X11_HOT_PINK_4;
			case _I(H,O,T,_,P,I,N,K,_,4):
				return alpha | X11_HOT_PINK_4;
			case _I(H,O,T, ,P,I,N,K, ,4):
				return alpha | X11_HOT_PINK_4;
			case _I(P,I,N,K,1):
				return alpha | X11_PINK_1;
			case _I(P,I,N,K,_,1):
				return alpha | X11_PINK_1;
			case _I(P,I,N,K, ,1):
				return alpha | X11_PINK_1;
			case _I(P,I,N,K,2):
				return alpha | X11_PINK_2;
			case _I(P,I,N,K,_,2):
				return alpha | X11_PINK_2;
			case _I(P,I,N,K, ,2):
				return alpha | X11_PINK_2;
			case _I(P,I,N,K,3):
				return alpha | X11_PINK_3;
			case _I(P,I,N,K,_,3):
				return alpha | X11_PINK_3;
			case _I(P,I,N,K, ,3):
				return alpha | X11_PINK_3;
			case _I(P,I,N,K,4):
				return alpha | X11_PINK_4;
			case _I(P,I,N,K,_,4):
				return alpha | X11_PINK_4;
			case _I(P,I,N,K, ,4):
				return alpha | X11_PINK_4;
			case _I(L,I,G,H,T,P,I,N,K,1):
				return alpha | X11_LIGHT_PINK_1;
			case _I(L,I,G,H,T,_,P,I,N,K,_,1):
				return alpha | X11_LIGHT_PINK_1;
			case _I(L,I,G,H,T, ,P,I,N,K, ,1):
				return alpha | X11_LIGHT_PINK_1;
			case _I(L,I,G,H,T,P,I,N,K,2):
				return alpha | X11_LIGHT_PINK_2;
			case _I(L,I,G,H,T,_,P,I,N,K,_,2):
				return alpha | X11_LIGHT_PINK_2;
			case _I(L,I,G,H,T, ,P,I,N,K, ,2):
				return alpha | X11_LIGHT_PINK_2;
			case _I(L,I,G,H,T,P,I,N,K,3):
				return alpha | X11_LIGHT_PINK_3;
			case _I(L,I,G,H,T,_,P,I,N,K,_,3):
				return alpha | X11_LIGHT_PINK_3;
			case _I(L,I,G,H,T, ,P,I,N,K, ,3):
				return alpha | X11_LIGHT_PINK_3;
			case _I(L,I,G,H,T,P,I,N,K,4):
				return alpha | X11_LIGHT_PINK_4;
			case _I(L,I,G,H,T,_,P,I,N,K,_,4):
				return alpha | X11_LIGHT_PINK_4;
			case _I(L,I,G,H,T, ,P,I,N,K, ,4):
				return alpha | X11_LIGHT_PINK_4;
			case _I(P,A,L,E,V,I,O,L,E,T,R,E,D,1):
				return alpha | X11_PALE_VIOLET_RED_1;
			case _I(P,A,L,E,_,V,I,O,L,E,T,_,R,E,D,_,1):
				return alpha | X11_PALE_VIOLET_RED_1;
			case _I(P,A,L,E, ,V,I,O,L,E,T, ,R,E,D, ,1):
				return alpha | X11_PALE_VIOLET_RED_1;
			case _I(P,A,L,E,V,I,O,L,E,T,R,E,D,2):
				return alpha | X11_PALE_VIOLET_RED_2;
			case _I(P,A,L,E,_,V,I,O,L,E,T,_,R,E,D,_,2):
				return alpha | X11_PALE_VIOLET_RED_2;
			case _I(P,A,L,E, ,V,I,O,L,E,T, ,R,E,D, ,2):
				return alpha | X11_PALE_VIOLET_RED_2;
			case _I(P,A,L,E,V,I,O,L,E,T,R,E,D,3):
				return alpha | X11_PALE_VIOLET_RED_3;
			case _I(P,A,L,E,_,V,I,O,L,E,T,_,R,E,D,_,3):
				return alpha | X11_PALE_VIOLET_RED_3;
			case _I(P,A,L,E, ,V,I,O,L,E,T, ,R,E,D, ,3):
				return alpha | X11_PALE_VIOLET_RED_3;
			case _I(P,A,L,E,V,I,O,L,E,T,R,E,D,4):
				return alpha | X11_PALE_VIOLET_RED_4;
			case _I(P,A,L,E,_,V,I,O,L,E,T,_,R,E,D,_,4):
				return alpha | X11_PALE_VIOLET_RED_4;
			case _I(P,A,L,E, ,V,I,O,L,E,T, ,R,E,D, ,4):
				return alpha | X11_PALE_VIOLET_RED_4;
			case _I(M,A,R,O,O,N,1):
				return alpha | X11_MAROON_1;
			case _I(M,A,R,O,O,N,_,1):
				return alpha | X11_MAROON_1;
			case _I(M,A,R,O,O,N, ,1):
				return alpha | X11_MAROON_1;
			case _I(M,A,R,O,O,N,2):
				return alpha | X11_MAROON_2;
			case _I(M,A,R,O,O,N,_,2):
				return alpha | X11_MAROON_2;
			case _I(M,A,R,O,O,N, ,2):
				return alpha | X11_MAROON_2;
			case _I(M,A,R,O,O,N,3):
				return alpha | X11_MAROON_3;
			case _I(M,A,R,O,O,N,_,3):
				return alpha | X11_MAROON_3;
			case _I(M,A,R,O,O,N, ,3):
				return alpha | X11_MAROON_3;
			case _I(M,A,R,O,O,N,4):
				return alpha | X11_MAROON_4;
			case _I(M,A,R,O,O,N,_,4):
				return alpha | X11_MAROON_4;
			case _I(M,A,R,O,O,N, ,4):
				return alpha | X11_MAROON_4;
			case _I(V,I,O,L,E,T,R,E,D,1):
				return alpha | X11_VIOLET_RED_1;
			case _I(V,I,O,L,E,T,_,R,E,D,_,1):
				return alpha | X11_VIOLET_RED_1;
			case _I(V,I,O,L,E,T, ,R,E,D, ,1):
				return alpha | X11_VIOLET_RED_1;
			case _I(V,I,O,L,E,T,R,E,D,2):
				return alpha | X11_VIOLET_RED_2;
			case _I(V,I,O,L,E,T,_,R,E,D,_,2):
				return alpha | X11_VIOLET_RED_2;
			case _I(V,I,O,L,E,T, ,R,E,D, ,2):
				return alpha | X11_VIOLET_RED_2;
			case _I(V,I,O,L,E,T,R,E,D,3):
				return alpha | X11_VIOLET_RED_3;
			case _I(V,I,O,L,E,T,_,R,E,D,_,3):
				return alpha | X11_VIOLET_RED_3;
			case _I(V,I,O,L,E,T, ,R,E,D, ,3):
				return alpha | X11_VIOLET_RED_3;
			case _I(V,I,O,L,E,T,R,E,D,4):
				return alpha | X11_VIOLET_RED_4;
			case _I(V,I,O,L,E,T,_,R,E,D,_,4):
				return alpha | X11_VIOLET_RED_4;
			case _I(V,I,O,L,E,T, ,R,E,D, ,4):
				return alpha | X11_VIOLET_RED_4;
			case _I(M,A,G,E,N,T,A,1):
				return alpha | X11_MAGENTA_1;
			case _I(M,A,G,E,N,T,A,_,1):
				return alpha | X11_MAGENTA_1;
			case _I(M,A,G,E,N,T,A, ,1):
				return alpha | X11_MAGENTA_1;
			case _I(M,A,G,E,N,T,A,2):
				return alpha | X11_MAGENTA_2;
			case _I(M,A,G,E,N,T,A,_,2):
				return alpha | X11_MAGENTA_2;
			case _I(M,A,G,E,N,T,A, ,2):
				return alpha | X11_MAGENTA_2;
			case _I(M,A,G,E,N,T,A,3):
				return alpha | X11_MAGENTA_3;
			case _I(M,A,G,E,N,T,A,_,3):
				return alpha | X11_MAGENTA_3;
			case _I(M,A,G,E,N,T,A, ,3):
				return alpha | X11_MAGENTA_3;
			case _I(M,A,G,E,N,T,A,4):
				return alpha | X11_MAGENTA_4;
			case _I(M,A,G,E,N,T,A,_,4):
				return alpha | X11_MAGENTA_4;
			case _I(M,A,G,E,N,T,A, ,4):
				return alpha | X11_MAGENTA_4;
			case _I(O,R,C,H,I,D,1):
				return alpha | X11_ORCHID_1;
			case _I(O,R,C,H,I,D,_,1):
				return alpha | X11_ORCHID_1;
			case _I(O,R,C,H,I,D, ,1):
				return alpha | X11_ORCHID_1;
			case _I(O,R,C,H,I,D,2):
				return alpha | X11_ORCHID_2;
			case _I(O,R,C,H,I,D,_,2):
				return alpha | X11_ORCHID_2;
			case _I(O,R,C,H,I,D, ,2):
				return alpha | X11_ORCHID_2;
			case _I(O,R,C,H,I,D,3):
				return alpha | X11_ORCHID_3;
			case _I(O,R,C,H,I,D,_,3):
				return alpha | X11_ORCHID_3;
			case _I(O,R,C,H,I,D, ,3):
				return alpha | X11_ORCHID_3;
			case _I(O,R,C,H,I,D,4):
				return alpha | X11_ORCHID_4;
			case _I(O,R,C,H,I,D,_,4):
				return alpha | X11_ORCHID_4;
			case _I(O,R,C,H,I,D, ,4):
				return alpha | X11_ORCHID_4;
			case _I(P,L,U,M,1):
				return alpha | X11_PLUM_1;
			case _I(P,L,U,M,_,1):
				return alpha | X11_PLUM_1;
			case _I(P,L,U,M, ,1):
				return alpha | X11_PLUM_1;
			case _I(P,L,U,M,2):
				return alpha | X11_PLUM_2;
			case _I(P,L,U,M,_,2):
				return alpha | X11_PLUM_2;
			case _I(P,L,U,M, ,2):
				return alpha | X11_PLUM_2;
			case _I(P,L,U,M,3):
				return alpha | X11_PLUM_3;
			case _I(P,L,U,M,_,3):
				return alpha | X11_PLUM_3;
			case _I(P,L,U,M, ,3):
				return alpha | X11_PLUM_3;
			case _I(P,L,U,M,4):
				return alpha | X11_PLUM_4;
			case _I(P,L,U,M,_,4):
				return alpha | X11_PLUM_4;
			case _I(P,L,U,M, ,4):
				return alpha | X11_PLUM_4;
			case _I(M,E,D,I,U,M,O,R,C,H,I,D,1):
				return alpha | X11_MEDIUM_ORCHID_1;
			case _I(M,E,D,I,U,M,_,O,R,C,H,I,D,_,1):
				return alpha | X11_MEDIUM_ORCHID_1;
			case _I(M,E,D,I,U,M, ,O,R,C,H,I,D, ,1):
				return alpha | X11_MEDIUM_ORCHID_1;
			case _I(M,E,D,I,U,M,O,R,C,H,I,D,2):
				return alpha | X11_MEDIUM_ORCHID_2;
			case _I(M,E,D,I,U,M,_,O,R,C,H,I,D,_,2):
				return alpha | X11_MEDIUM_ORCHID_2;
			case _I(M,E,D,I,U,M, ,O,R,C,H,I,D, ,2):
				return alpha | X11_MEDIUM_ORCHID_2;
			case _I(M,E,D,I,U,M,O,R,C,H,I,D,3):
				return alpha | X11_MEDIUM_ORCHID_3;
			case _I(M,E,D,I,U,M,_,O,R,C,H,I,D,_,3):
				return alpha | X11_MEDIUM_ORCHID_3;
			case _I(M,E,D,I,U,M, ,O,R,C,H,I,D, ,3):
				return alpha | X11_MEDIUM_ORCHID_3;
			case _I(M,E,D,I,U,M,O,R,C,H,I,D,4):
				return alpha | X11_MEDIUM_ORCHID_4;
			case _I(M,E,D,I,U,M,_,O,R,C,H,I,D,_,4):
				return alpha | X11_MEDIUM_ORCHID_4;
			case _I(M,E,D,I,U,M, ,O,R,C,H,I,D, ,4):
				return alpha | X11_MEDIUM_ORCHID_4;
			case _I(D,A,R,K,O,R,C,H,I,D,1):
				return alpha | X11_DARK_ORCHID_1;
			case _I(D,A,R,K,_,O,R,C,H,I,D,_,1):
				return alpha | X11_DARK_ORCHID_1;
			case _I(D,A,R,K, ,O,R,C,H,I,D, ,1):
				return alpha | X11_DARK_ORCHID_1;
			case _I(D,A,R,K,O,R,C,H,I,D,2):
				return alpha | X11_DARK_ORCHID_2;
			case _I(D,A,R,K,_,O,R,C,H,I,D,_,2):
				return alpha | X11_DARK_ORCHID_2;
			case _I(D,A,R,K, ,O,R,C,H,I,D, ,2):
				return alpha | X11_DARK_ORCHID_2;
			case _I(D,A,R,K,O,R,C,H,I,D,3):
				return alpha | X11_DARK_ORCHID_3;
			case _I(D,A,R,K,_,O,R,C,H,I,D,_,3):
				return alpha | X11_DARK_ORCHID_3;
			case _I(D,A,R,K, ,O,R,C,H,I,D, ,3):
				return alpha | X11_DARK_ORCHID_3;
			case _I(D,A,R,K,O,R,C,H,I,D,4):
				return alpha | X11_DARK_ORCHID_4;
			case _I(D,A,R,K,_,O,R,C,H,I,D,_,4):
				return alpha | X11_DARK_ORCHID_4;
			case _I(D,A,R,K, ,O,R,C,H,I,D, ,4):
				return alpha | X11_DARK_ORCHID_4;
			case _I(P,U,R,P,L,E,1):
				return alpha | X11_PURPLE_1;
			case _I(P,U,R,P,L,E,_,1):
				return alpha | X11_PURPLE_1;
			case _I(P,U,R,P,L,E, ,1):
				return alpha | X11_PURPLE_1;
			case _I(P,U,R,P,L,E,2):
				return alpha | X11_PURPLE_2;
			case _I(P,U,R,P,L,E,_,2):
				return alpha | X11_PURPLE_2;
			case _I(P,U,R,P,L,E, ,2):
				return alpha | X11_PURPLE_2;
			case _I(P,U,R,P,L,E,3):
				return alpha | X11_PURPLE_3;
			case _I(P,U,R,P,L,E,_,3):
				return alpha | X11_PURPLE_3;
			case _I(P,U,R,P,L,E, ,3):
				return alpha | X11_PURPLE_3;
			case _I(P,U,R,P,L,E,4):
				return alpha | X11_PURPLE_4;
			case _I(P,U,R,P,L,E,_,4):
				return alpha | X11_PURPLE_4;
			case _I(P,U,R,P,L,E, ,4):
				return alpha | X11_PURPLE_4;
			case _I(M,E,D,I,U,M,P,U,R,P,L,E,1):
				return alpha | X11_MEDIUM_PURPLE_1;
			case _I(M,E,D,I,U,M,_,P,U,R,P,L,E,_,1):
				return alpha | X11_MEDIUM_PURPLE_1;
			case _I(M,E,D,I,U,M, ,P,U,R,P,L,E, ,1):
				return alpha | X11_MEDIUM_PURPLE_1;
			case _I(M,E,D,I,U,M,P,U,R,P,L,E,2):
				return alpha | X11_MEDIUM_PURPLE_2;
			case _I(M,E,D,I,U,M,_,P,U,R,P,L,E,_,2):
				return alpha | X11_MEDIUM_PURPLE_2;
			case _I(M,E,D,I,U,M, ,P,U,R,P,L,E, ,2):
				return alpha | X11_MEDIUM_PURPLE_2;
			case _I(M,E,D,I,U,M,P,U,R,P,L,E,3):
				return alpha | X11_MEDIUM_PURPLE_3;
			case _I(M,E,D,I,U,M,_,P,U,R,P,L,E,_,3):
				return alpha | X11_MEDIUM_PURPLE_3;
			case _I(M,E,D,I,U,M, ,P,U,R,P,L,E, ,3):
				return alpha | X11_MEDIUM_PURPLE_3;
			case _I(M,E,D,I,U,M,P,U,R,P,L,E,4):
				return alpha | X11_MEDIUM_PURPLE_4;
			case _I(M,E,D,I,U,M,_,P,U,R,P,L,E,_,4):
				return alpha | X11_MEDIUM_PURPLE_4;
			case _I(M,E,D,I,U,M, ,P,U,R,P,L,E, ,4):
				return alpha | X11_MEDIUM_PURPLE_4;
			case _I(T,H,I,S,T,L,E,1):
				return alpha | X11_THISTLE_1;
			case _I(T,H,I,S,T,L,E,_,1):
				return alpha | X11_THISTLE_1;
			case _I(T,H,I,S,T,L,E, ,1):
				return alpha | X11_THISTLE_1;
			case _I(T,H,I,S,T,L,E,2):
				return alpha | X11_THISTLE_2;
			case _I(T,H,I,S,T,L,E,_,2):
				return alpha | X11_THISTLE_2;
			case _I(T,H,I,S,T,L,E, ,2):
				return alpha | X11_THISTLE_2;
			case _I(T,H,I,S,T,L,E,3):
				return alpha | X11_THISTLE_3;
			case _I(T,H,I,S,T,L,E,_,3):
				return alpha | X11_THISTLE_3;
			case _I(T,H,I,S,T,L,E, ,3):
				return alpha | X11_THISTLE_3;
			case _I(T,H,I,S,T,L,E,4):
				return alpha | X11_THISTLE_4;
			case _I(T,H,I,S,T,L,E,_,4):
				return alpha | X11_THISTLE_4;
			case _I(T,H,I,S,T,L,E, ,4):
				return alpha | X11_THISTLE_4;
			case _I(G,R,A,Y,0):
				return alpha | X11_GRAY_0;
			case _I(G,R,A,Y,_,0):
				return alpha | X11_GRAY_0;
			case _I(G,R,A,Y, ,0):
				return alpha | X11_GRAY_0;
			case _I(G,R,E,Y,0):
				return alpha | X11_GREY_0;
			case _I(G,R,E,Y,_,0):
				return alpha | X11_GREY_0;
			case _I(G,R,E,Y, ,0):
				return alpha | X11_GREY_0;
			case _I(G,R,A,Y,1):
				return alpha | X11_GRAY_1;
			case _I(G,R,A,Y,_,1):
				return alpha | X11_GRAY_1;
			case _I(G,R,A,Y, ,1):
				return alpha | X11_GRAY_1;
			case _I(G,R,E,Y,1):
				return alpha | X11_GREY_1;
			case _I(G,R,E,Y,_,1):
				return alpha | X11_GREY_1;
			case _I(G,R,E,Y, ,1):
				return alpha | X11_GREY_1;
			case _I(G,R,A,Y,2):
				return alpha | X11_GRAY_2;
			case _I(G,R,A,Y,_,2):
				return alpha | X11_GRAY_2;
			case _I(G,R,A,Y, ,2):
				return alpha | X11_GRAY_2;
			case _I(G,R,E,Y,2):
				return alpha | X11_GREY_2;
			case _I(G,R,E,Y,_,2):
				return alpha | X11_GREY_2;
			case _I(G,R,E,Y, ,2):
				return alpha | X11_GREY_2;
			case _I(G,R,A,Y,3):
				return alpha | X11_GRAY_3;
			case _I(G,R,A,Y,_,3):
				return alpha | X11_GRAY_3;
			case _I(G,R,A,Y, ,3):
				return alpha | X11_GRAY_3;
			case _I(G,R,E,Y,3):
				return alpha | X11_GREY_3;
			case _I(G,R,E,Y,_,3):
				return alpha | X11_GREY_3;
			case _I(G,R,E,Y, ,3):
				return alpha | X11_GREY_3;
			case _I(G,R,A,Y,4):
				return alpha | X11_GRAY_4;
			case _I(G,R,A,Y,_,4):
				return alpha | X11_GRAY_4;
			case _I(G,R,A,Y, ,4):
				return alpha | X11_GRAY_4;
			case _I(G,R,E,Y,4):
				return alpha | X11_GREY_4;
			case _I(G,R,E,Y,_,4):
				return alpha | X11_GREY_4;
			case _I(G,R,E,Y, ,4):
				return alpha | X11_GREY_4;
			case _I(G,R,A,Y,5):
				return alpha | X11_GRAY_5;
			case _I(G,R,A,Y,_,5):
				return alpha | X11_GRAY_5;
			case _I(G,R,A,Y, ,5):
				return alpha | X11_GRAY_5;
			case _I(G,R,E,Y,5):
				return alpha | X11_GREY_5;
			case _I(G,R,E,Y,_,5):
				return alpha | X11_GREY_5;
			case _I(G,R,E,Y, ,5):
				return alpha | X11_GREY_5;
			case _I(G,R,A,Y,6):
				return alpha | X11_GRAY_6;
			case _I(G,R,A,Y,_,6):
				return alpha | X11_GRAY_6;
			case _I(G,R,A,Y, ,6):
				return alpha | X11_GRAY_6;
			case _I(G,R,E,Y,6):
				return alpha | X11_GREY_6;
			case _I(G,R,E,Y,_,6):
				return alpha | X11_GREY_6;
			case _I(G,R,E,Y, ,6):
				return alpha | X11_GREY_6;
			case _I(G,R,A,Y,7):
				return alpha | X11_GRAY_7;
			case _I(G,R,A,Y,_,7):
				return alpha | X11_GRAY_7;
			case _I(G,R,A,Y, ,7):
				return alpha | X11_GRAY_7;
			case _I(G,R,E,Y,7):
				return alpha | X11_GREY_7;
			case _I(G,R,E,Y,_,7):
				return alpha | X11_GREY_7;
			case _I(G,R,E,Y, ,7):
				return alpha | X11_GREY_7;
			case _I(G,R,A,Y,8):
				return alpha | X11_GRAY_8;
			case _I(G,R,A,Y,_,8):
				return alpha | X11_GRAY_8;
			case _I(G,R,A,Y, ,8):
				return alpha | X11_GRAY_8;
			case _I(G,R,E,Y,8):
				return alpha | X11_GREY_8;
			case _I(G,R,E,Y,_,8):
				return alpha | X11_GREY_8;
			case _I(G,R,E,Y, ,8):
				return alpha | X11_GREY_8;
			case _I(G,R,A,Y,9):
				return alpha | X11_GRAY_9;
			case _I(G,R,A,Y,_,9):
				return alpha | X11_GRAY_9;
			case _I(G,R,A,Y, ,9):
				return alpha | X11_GRAY_9;
			case _I(G,R,E,Y,9):
				return alpha | X11_GREY_9;
			case _I(G,R,E,Y,_,9):
				return alpha | X11_GREY_9;
			case _I(G,R,E,Y, ,9):
				return alpha | X11_GREY_9;
			case _I(G,R,A,Y,1,0):
				return alpha | X11_GRAY_10;
			case _I(G,R,A,Y,_,1,0):
				return alpha | X11_GRAY_10;
			case _I(G,R,A,Y, ,1,0):
				return alpha | X11_GRAY_10;
			case _I(G,R,E,Y,1,0):
				return alpha | X11_GREY_10;
			case _I(G,R,E,Y,_,1,0):
				return alpha | X11_GREY_10;
			case _I(G,R,E,Y, ,1,0):
				return alpha | X11_GREY_10;
			case _I(G,R,A,Y,1,1):
				return alpha | X11_GRAY_11;
			case _I(G,R,A,Y,_,1,1):
				return alpha | X11_GRAY_11;
			case _I(G,R,A,Y, ,1,1):
				return alpha | X11_GRAY_11;
			case _I(G,R,E,Y,1,1):
				return alpha | X11_GREY_11;
			case _I(G,R,E,Y,_,1,1):
				return alpha | X11_GREY_11;
			case _I(G,R,E,Y, ,1,1):
				return alpha | X11_GREY_11;
			case _I(G,R,A,Y,1,2):
				return alpha | X11_GRAY_12;
			case _I(G,R,A,Y,_,1,2):
				return alpha | X11_GRAY_12;
			case _I(G,R,A,Y, ,1,2):
				return alpha | X11_GRAY_12;
			case _I(G,R,E,Y,1,2):
				return alpha | X11_GREY_12;
			case _I(G,R,E,Y,_,1,2):
				return alpha | X11_GREY_12;
			case _I(G,R,E,Y, ,1,2):
				return alpha | X11_GREY_12;
			case _I(G,R,A,Y,1,3):
				return alpha | X11_GRAY_13;
			case _I(G,R,A,Y,_,1,3):
				return alpha | X11_GRAY_13;
			case _I(G,R,A,Y, ,1,3):
				return alpha | X11_GRAY_13;
			case _I(G,R,E,Y,1,3):
				return alpha | X11_GREY_13;
			case _I(G,R,E,Y,_,1,3):
				return alpha | X11_GREY_13;
			case _I(G,R,E,Y, ,1,3):
				return alpha | X11_GREY_13;
			case _I(G,R,A,Y,1,4):
				return alpha | X11_GRAY_14;
			case _I(G,R,A,Y,_,1,4):
				return alpha | X11_GRAY_14;
			case _I(G,R,A,Y, ,1,4):
				return alpha | X11_GRAY_14;
			case _I(G,R,E,Y,1,4):
				return alpha | X11_GREY_14;
			case _I(G,R,E,Y,_,1,4):
				return alpha | X11_GREY_14;
			case _I(G,R,E,Y, ,1,4):
				return alpha | X11_GREY_14;
			case _I(G,R,A,Y,1,5):
				return alpha | X11_GRAY_15;
			case _I(G,R,A,Y,_,1,5):
				return alpha | X11_GRAY_15;
			case _I(G,R,A,Y, ,1,5):
				return alpha | X11_GRAY_15;
			case _I(G,R,E,Y,1,5):
				return alpha | X11_GREY_15;
			case _I(G,R,E,Y,_,1,5):
				return alpha | X11_GREY_15;
			case _I(G,R,E,Y, ,1,5):
				return alpha | X11_GREY_15;
			case _I(G,R,A,Y,1,6):
				return alpha | X11_GRAY_16;
			case _I(G,R,A,Y,_,1,6):
				return alpha | X11_GRAY_16;
			case _I(G,R,A,Y, ,1,6):
				return alpha | X11_GRAY_16;
			case _I(G,R,E,Y,1,6):
				return alpha | X11_GREY_16;
			case _I(G,R,E,Y,_,1,6):
				return alpha | X11_GREY_16;
			case _I(G,R,E,Y, ,1,6):
				return alpha | X11_GREY_16;
			case _I(G,R,A,Y,1,7):
				return alpha | X11_GRAY_17;
			case _I(G,R,A,Y,_,1,7):
				return alpha | X11_GRAY_17;
			case _I(G,R,A,Y, ,1,7):
				return alpha | X11_GRAY_17;
			case _I(G,R,E,Y,1,7):
				return alpha | X11_GREY_17;
			case _I(G,R,E,Y,_,1,7):
				return alpha | X11_GREY_17;
			case _I(G,R,E,Y, ,1,7):
				return alpha | X11_GREY_17;
			case _I(G,R,A,Y,1,8):
				return alpha | X11_GRAY_18;
			case _I(G,R,A,Y,_,1,8):
				return alpha | X11_GRAY_18;
			case _I(G,R,A,Y, ,1,8):
				return alpha | X11_GRAY_18;
			case _I(G,R,E,Y,1,8):
				return alpha | X11_GREY_18;
			case _I(G,R,E,Y,_,1,8):
				return alpha | X11_GREY_18;
			case _I(G,R,E,Y, ,1,8):
				return alpha | X11_GREY_18;
			case _I(G,R,A,Y,1,9):
				return alpha | X11_GRAY_19;
			case _I(G,R,A,Y,_,1,9):
				return alpha | X11_GRAY_19;
			case _I(G,R,A,Y, ,1,9):
				return alpha | X11_GRAY_19;
			case _I(G,R,E,Y,1,9):
				return alpha | X11_GREY_19;
			case _I(G,R,E,Y,_,1,9):
				return alpha | X11_GREY_19;
			case _I(G,R,E,Y, ,1,9):
				return alpha | X11_GREY_19;
			case _I(G,R,A,Y,2,0):
				return alpha | X11_GRAY_20;
			case _I(G,R,A,Y,_,2,0):
				return alpha | X11_GRAY_20;
			case _I(G,R,A,Y, ,2,0):
				return alpha | X11_GRAY_20;
			case _I(G,R,E,Y,2,0):
				return alpha | X11_GREY_20;
			case _I(G,R,E,Y,_,2,0):
				return alpha | X11_GREY_20;
			case _I(G,R,E,Y, ,2,0):
				return alpha | X11_GREY_20;
			case _I(G,R,A,Y,2,1):
				return alpha | X11_GRAY_21;
			case _I(G,R,A,Y,_,2,1):
				return alpha | X11_GRAY_21;
			case _I(G,R,A,Y, ,2,1):
				return alpha | X11_GRAY_21;
			case _I(G,R,E,Y,2,1):
				return alpha | X11_GREY_21;
			case _I(G,R,E,Y,_,2,1):
				return alpha | X11_GREY_21;
			case _I(G,R,E,Y, ,2,1):
				return alpha | X11_GREY_21;
			case _I(G,R,A,Y,2,2):
				return alpha | X11_GRAY_22;
			case _I(G,R,A,Y,_,2,2):
				return alpha | X11_GRAY_22;
			case _I(G,R,A,Y, ,2,2):
				return alpha | X11_GRAY_22;
			case _I(G,R,E,Y,2,2):
				return alpha | X11_GREY_22;
			case _I(G,R,E,Y,_,2,2):
				return alpha | X11_GREY_22;
			case _I(G,R,E,Y, ,2,2):
				return alpha | X11_GREY_22;
			case _I(G,R,A,Y,2,3):
				return alpha | X11_GRAY_23;
			case _I(G,R,A,Y,_,2,3):
				return alpha | X11_GRAY_23;
			case _I(G,R,A,Y, ,2,3):
				return alpha | X11_GRAY_23;
			case _I(G,R,E,Y,2,3):
				return alpha | X11_GREY_23;
			case _I(G,R,E,Y,_,2,3):
				return alpha | X11_GREY_23;
			case _I(G,R,E,Y, ,2,3):
				return alpha | X11_GREY_23;
			case _I(G,R,A,Y,2,4):
				return alpha | X11_GRAY_24;
			case _I(G,R,A,Y,_,2,4):
				return alpha | X11_GRAY_24;
			case _I(G,R,A,Y, ,2,4):
				return alpha | X11_GRAY_24;
			case _I(G,R,E,Y,2,4):
				return alpha | X11_GREY_24;
			case _I(G,R,E,Y,_,2,4):
				return alpha | X11_GREY_24;
			case _I(G,R,E,Y, ,2,4):
				return alpha | X11_GREY_24;
			case _I(G,R,A,Y,2,5):
				return alpha | X11_GRAY_25;
			case _I(G,R,A,Y,_,2,5):
				return alpha | X11_GRAY_25;
			case _I(G,R,A,Y, ,2,5):
				return alpha | X11_GRAY_25;
			case _I(G,R,E,Y,2,5):
				return alpha | X11_GREY_25;
			case _I(G,R,E,Y,_,2,5):
				return alpha | X11_GREY_25;
			case _I(G,R,E,Y, ,2,5):
				return alpha | X11_GREY_25;
			case _I(G,R,A,Y,2,6):
				return alpha | X11_GRAY_26;
			case _I(G,R,A,Y,_,2,6):
				return alpha | X11_GRAY_26;
			case _I(G,R,A,Y, ,2,6):
				return alpha | X11_GRAY_26;
			case _I(G,R,E,Y,2,6):
				return alpha | X11_GREY_26;
			case _I(G,R,E,Y,_,2,6):
				return alpha | X11_GREY_26;
			case _I(G,R,E,Y, ,2,6):
				return alpha | X11_GREY_26;
			case _I(G,R,A,Y,2,7):
				return alpha | X11_GRAY_27;
			case _I(G,R,A,Y,_,2,7):
				return alpha | X11_GRAY_27;
			case _I(G,R,A,Y, ,2,7):
				return alpha | X11_GRAY_27;
			case _I(G,R,E,Y,2,7):
				return alpha | X11_GREY_27;
			case _I(G,R,E,Y,_,2,7):
				return alpha | X11_GREY_27;
			case _I(G,R,E,Y, ,2,7):
				return alpha | X11_GREY_27;
			case _I(G,R,A,Y,2,8):
				return alpha | X11_GRAY_28;
			case _I(G,R,A,Y,_,2,8):
				return alpha | X11_GRAY_28;
			case _I(G,R,A,Y, ,2,8):
				return alpha | X11_GRAY_28;
			case _I(G,R,E,Y,2,8):
				return alpha | X11_GREY_28;
			case _I(G,R,E,Y,_,2,8):
				return alpha | X11_GREY_28;
			case _I(G,R,E,Y, ,2,8):
				return alpha | X11_GREY_28;
			case _I(G,R,A,Y,2,9):
				return alpha | X11_GRAY_29;
			case _I(G,R,A,Y,_,2,9):
				return alpha | X11_GRAY_29;
			case _I(G,R,A,Y, ,2,9):
				return alpha | X11_GRAY_29;
			case _I(G,R,E,Y,2,9):
				return alpha | X11_GREY_29;
			case _I(G,R,E,Y,_,2,9):
				return alpha | X11_GREY_29;
			case _I(G,R,E,Y, ,2,9):
				return alpha | X11_GREY_29;
			case _I(G,R,A,Y,3,0):
				return alpha | X11_GRAY_30;
			case _I(G,R,A,Y,_,3,0):
				return alpha | X11_GRAY_30;
			case _I(G,R,A,Y, ,3,0):
				return alpha | X11_GRAY_30;
			case _I(G,R,E,Y,3,0):
				return alpha | X11_GREY_30;
			case _I(G,R,E,Y,_,3,0):
				return alpha | X11_GREY_30;
			case _I(G,R,E,Y, ,3,0):
				return alpha | X11_GREY_30;
			case _I(G,R,A,Y,3,1):
				return alpha | X11_GRAY_31;
			case _I(G,R,A,Y,_,3,1):
				return alpha | X11_GRAY_31;
			case _I(G,R,A,Y, ,3,1):
				return alpha | X11_GRAY_31;
			case _I(G,R,E,Y,3,1):
				return alpha | X11_GREY_31;
			case _I(G,R,E,Y,_,3,1):
				return alpha | X11_GREY_31;
			case _I(G,R,E,Y, ,3,1):
				return alpha | X11_GREY_31;
			case _I(G,R,A,Y,3,2):
				return alpha | X11_GRAY_32;
			case _I(G,R,A,Y,_,3,2):
				return alpha | X11_GRAY_32;
			case _I(G,R,A,Y, ,3,2):
				return alpha | X11_GRAY_32;
			case _I(G,R,E,Y,3,2):
				return alpha | X11_GREY_32;
			case _I(G,R,E,Y,_,3,2):
				return alpha | X11_GREY_32;
			case _I(G,R,E,Y, ,3,2):
				return alpha | X11_GREY_32;
			case _I(G,R,A,Y,3,3):
				return alpha | X11_GRAY_33;
			case _I(G,R,A,Y,_,3,3):
				return alpha | X11_GRAY_33;
			case _I(G,R,A,Y, ,3,3):
				return alpha | X11_GRAY_33;
			case _I(G,R,E,Y,3,3):
				return alpha | X11_GREY_33;
			case _I(G,R,E,Y,_,3,3):
				return alpha | X11_GREY_33;
			case _I(G,R,E,Y, ,3,3):
				return alpha | X11_GREY_33;
			case _I(G,R,A,Y,3,4):
				return alpha | X11_GRAY_34;
			case _I(G,R,A,Y,_,3,4):
				return alpha | X11_GRAY_34;
			case _I(G,R,A,Y, ,3,4):
				return alpha | X11_GRAY_34;
			case _I(G,R,E,Y,3,4):
				return alpha | X11_GREY_34;
			case _I(G,R,E,Y,_,3,4):
				return alpha | X11_GREY_34;
			case _I(G,R,E,Y, ,3,4):
				return alpha | X11_GREY_34;
			case _I(G,R,A,Y,3,5):
				return alpha | X11_GRAY_35;
			case _I(G,R,A,Y,_,3,5):
				return alpha | X11_GRAY_35;
			case _I(G,R,A,Y, ,3,5):
				return alpha | X11_GRAY_35;
			case _I(G,R,E,Y,3,5):
				return alpha | X11_GREY_35;
			case _I(G,R,E,Y,_,3,5):
				return alpha | X11_GREY_35;
			case _I(G,R,E,Y, ,3,5):
				return alpha | X11_GREY_35;
			case _I(G,R,A,Y,3,6):
				return alpha | X11_GRAY_36;
			case _I(G,R,A,Y,_,3,6):
				return alpha | X11_GRAY_36;
			case _I(G,R,A,Y, ,3,6):
				return alpha | X11_GRAY_36;
			case _I(G,R,E,Y,3,6):
				return alpha | X11_GREY_36;
			case _I(G,R,E,Y,_,3,6):
				return alpha | X11_GREY_36;
			case _I(G,R,E,Y, ,3,6):
				return alpha | X11_GREY_36;
			case _I(G,R,A,Y,3,7):
				return alpha | X11_GRAY_37;
			case _I(G,R,A,Y,_,3,7):
				return alpha | X11_GRAY_37;
			case _I(G,R,A,Y, ,3,7):
				return alpha | X11_GRAY_37;
			case _I(G,R,E,Y,3,7):
				return alpha | X11_GREY_37;
			case _I(G,R,E,Y,_,3,7):
				return alpha | X11_GREY_37;
			case _I(G,R,E,Y, ,3,7):
				return alpha | X11_GREY_37;
			case _I(G,R,A,Y,3,8):
				return alpha | X11_GRAY_38;
			case _I(G,R,A,Y,_,3,8):
				return alpha | X11_GRAY_38;
			case _I(G,R,A,Y, ,3,8):
				return alpha | X11_GRAY_38;
			case _I(G,R,E,Y,3,8):
				return alpha | X11_GREY_38;
			case _I(G,R,E,Y,_,3,8):
				return alpha | X11_GREY_38;
			case _I(G,R,E,Y, ,3,8):
				return alpha | X11_GREY_38;
			case _I(G,R,A,Y,3,9):
				return alpha | X11_GRAY_39;
			case _I(G,R,A,Y,_,3,9):
				return alpha | X11_GRAY_39;
			case _I(G,R,A,Y, ,3,9):
				return alpha | X11_GRAY_39;
			case _I(G,R,E,Y,3,9):
				return alpha | X11_GREY_39;
			case _I(G,R,E,Y,_,3,9):
				return alpha | X11_GREY_39;
			case _I(G,R,E,Y, ,3,9):
				return alpha | X11_GREY_39;
			case _I(G,R,A,Y,4,0):
				return alpha | X11_GRAY_40;
			case _I(G,R,A,Y,_,4,0):
				return alpha | X11_GRAY_40;
			case _I(G,R,A,Y, ,4,0):
				return alpha | X11_GRAY_40;
			case _I(G,R,E,Y,4,0):
				return alpha | X11_GREY_40;
			case _I(G,R,E,Y,_,4,0):
				return alpha | X11_GREY_40;
			case _I(G,R,E,Y, ,4,0):
				return alpha | X11_GREY_40;
			case _I(G,R,A,Y,4,1):
				return alpha | X11_GRAY_41;
			case _I(G,R,A,Y,_,4,1):
				return alpha | X11_GRAY_41;
			case _I(G,R,A,Y, ,4,1):
				return alpha | X11_GRAY_41;
			case _I(G,R,E,Y,4,1):
				return alpha | X11_GREY_41;
			case _I(G,R,E,Y,_,4,1):
				return alpha | X11_GREY_41;
			case _I(G,R,E,Y, ,4,1):
				return alpha | X11_GREY_41;
			case _I(G,R,A,Y,4,2):
				return alpha | X11_GRAY_42;
			case _I(G,R,A,Y,_,4,2):
				return alpha | X11_GRAY_42;
			case _I(G,R,A,Y, ,4,2):
				return alpha | X11_GRAY_42;
			case _I(G,R,E,Y,4,2):
				return alpha | X11_GREY_42;
			case _I(G,R,E,Y,_,4,2):
				return alpha | X11_GREY_42;
			case _I(G,R,E,Y, ,4,2):
				return alpha | X11_GREY_42;
			case _I(G,R,A,Y,4,3):
				return alpha | X11_GRAY_43;
			case _I(G,R,A,Y,_,4,3):
				return alpha | X11_GRAY_43;
			case _I(G,R,A,Y, ,4,3):
				return alpha | X11_GRAY_43;
			case _I(G,R,E,Y,4,3):
				return alpha | X11_GREY_43;
			case _I(G,R,E,Y,_,4,3):
				return alpha | X11_GREY_43;
			case _I(G,R,E,Y, ,4,3):
				return alpha | X11_GREY_43;
			case _I(G,R,A,Y,4,4):
				return alpha | X11_GRAY_44;
			case _I(G,R,A,Y,_,4,4):
				return alpha | X11_GRAY_44;
			case _I(G,R,A,Y, ,4,4):
				return alpha | X11_GRAY_44;
			case _I(G,R,E,Y,4,4):
				return alpha | X11_GREY_44;
			case _I(G,R,E,Y,_,4,4):
				return alpha | X11_GREY_44;
			case _I(G,R,E,Y, ,4,4):
				return alpha | X11_GREY_44;
			case _I(G,R,A,Y,4,5):
				return alpha | X11_GRAY_45;
			case _I(G,R,A,Y,_,4,5):
				return alpha | X11_GRAY_45;
			case _I(G,R,A,Y, ,4,5):
				return alpha | X11_GRAY_45;
			case _I(G,R,E,Y,4,5):
				return alpha | X11_GREY_45;
			case _I(G,R,E,Y,_,4,5):
				return alpha | X11_GREY_45;
			case _I(G,R,E,Y, ,4,5):
				return alpha | X11_GREY_45;
			case _I(G,R,A,Y,4,6):
				return alpha | X11_GRAY_46;
			case _I(G,R,A,Y,_,4,6):
				return alpha | X11_GRAY_46;
			case _I(G,R,A,Y, ,4,6):
				return alpha | X11_GRAY_46;
			case _I(G,R,E,Y,4,6):
				return alpha | X11_GREY_46;
			case _I(G,R,E,Y,_,4,6):
				return alpha | X11_GREY_46;
			case _I(G,R,E,Y, ,4,6):
				return alpha | X11_GREY_46;
			case _I(G,R,A,Y,4,7):
				return alpha | X11_GRAY_47;
			case _I(G,R,A,Y,_,4,7):
				return alpha | X11_GRAY_47;
			case _I(G,R,A,Y, ,4,7):
				return alpha | X11_GRAY_47;
			case _I(G,R,E,Y,4,7):
				return alpha | X11_GREY_47;
			case _I(G,R,E,Y,_,4,7):
				return alpha | X11_GREY_47;
			case _I(G,R,E,Y, ,4,7):
				return alpha | X11_GREY_47;
			case _I(G,R,A,Y,4,8):
				return alpha | X11_GRAY_48;
			case _I(G,R,A,Y,_,4,8):
				return alpha | X11_GRAY_48;
			case _I(G,R,A,Y, ,4,8):
				return alpha | X11_GRAY_48;
			case _I(G,R,E,Y,4,8):
				return alpha | X11_GREY_48;
			case _I(G,R,E,Y,_,4,8):
				return alpha | X11_GREY_48;
			case _I(G,R,E,Y, ,4,8):
				return alpha | X11_GREY_48;
			case _I(G,R,A,Y,4,9):
				return alpha | X11_GRAY_49;
			case _I(G,R,A,Y,_,4,9):
				return alpha | X11_GRAY_49;
			case _I(G,R,A,Y, ,4,9):
				return alpha | X11_GRAY_49;
			case _I(G,R,E,Y,4,9):
				return alpha | X11_GREY_49;
			case _I(G,R,E,Y,_,4,9):
				return alpha | X11_GREY_49;
			case _I(G,R,E,Y, ,4,9):
				return alpha | X11_GREY_49;
			case _I(G,R,A,Y,5,0):
				return alpha | X11_GRAY_50;
			case _I(G,R,A,Y,_,5,0):
				return alpha | X11_GRAY_50;
			case _I(G,R,A,Y, ,5,0):
				return alpha | X11_GRAY_50;
			case _I(G,R,E,Y,5,0):
				return alpha | X11_GREY_50;
			case _I(G,R,E,Y,_,5,0):
				return alpha | X11_GREY_50;
			case _I(G,R,E,Y, ,5,0):
				return alpha | X11_GREY_50;
			case _I(G,R,A,Y,5,1):
				return alpha | X11_GRAY_51;
			case _I(G,R,A,Y,_,5,1):
				return alpha | X11_GRAY_51;
			case _I(G,R,A,Y, ,5,1):
				return alpha | X11_GRAY_51;
			case _I(G,R,E,Y,5,1):
				return alpha | X11_GREY_51;
			case _I(G,R,E,Y,_,5,1):
				return alpha | X11_GREY_51;
			case _I(G,R,E,Y, ,5,1):
				return alpha | X11_GREY_51;
			case _I(G,R,A,Y,5,2):
				return alpha | X11_GRAY_52;
			case _I(G,R,A,Y,_,5,2):
				return alpha | X11_GRAY_52;
			case _I(G,R,A,Y, ,5,2):
				return alpha | X11_GRAY_52;
			case _I(G,R,E,Y,5,2):
				return alpha | X11_GREY_52;
			case _I(G,R,E,Y,_,5,2):
				return alpha | X11_GREY_52;
			case _I(G,R,E,Y, ,5,2):
				return alpha | X11_GREY_52;
			case _I(G,R,A,Y,5,3):
				return alpha | X11_GRAY_53;
			case _I(G,R,A,Y,_,5,3):
				return alpha | X11_GRAY_53;
			case _I(G,R,A,Y, ,5,3):
				return alpha | X11_GRAY_53;
			case _I(G,R,E,Y,5,3):
				return alpha | X11_GREY_53;
			case _I(G,R,E,Y,_,5,3):
				return alpha | X11_GREY_53;
			case _I(G,R,E,Y, ,5,3):
				return alpha | X11_GREY_53;
			case _I(G,R,A,Y,5,4):
				return alpha | X11_GRAY_54;
			case _I(G,R,A,Y,_,5,4):
				return alpha | X11_GRAY_54;
			case _I(G,R,A,Y, ,5,4):
				return alpha | X11_GRAY_54;
			case _I(G,R,E,Y,5,4):
				return alpha | X11_GREY_54;
			case _I(G,R,E,Y,_,5,4):
				return alpha | X11_GREY_54;
			case _I(G,R,E,Y, ,5,4):
				return alpha | X11_GREY_54;
			case _I(G,R,A,Y,5,5):
				return alpha | X11_GRAY_55;
			case _I(G,R,A,Y,_,5,5):
				return alpha | X11_GRAY_55;
			case _I(G,R,A,Y, ,5,5):
				return alpha | X11_GRAY_55;
			case _I(G,R,E,Y,5,5):
				return alpha | X11_GREY_55;
			case _I(G,R,E,Y,_,5,5):
				return alpha | X11_GREY_55;
			case _I(G,R,E,Y, ,5,5):
				return alpha | X11_GREY_55;
			case _I(G,R,A,Y,5,6):
				return alpha | X11_GRAY_56;
			case _I(G,R,A,Y,_,5,6):
				return alpha | X11_GRAY_56;
			case _I(G,R,A,Y, ,5,6):
				return alpha | X11_GRAY_56;
			case _I(G,R,E,Y,5,6):
				return alpha | X11_GREY_56;
			case _I(G,R,E,Y,_,5,6):
				return alpha | X11_GREY_56;
			case _I(G,R,E,Y, ,5,6):
				return alpha | X11_GREY_56;
			case _I(G,R,A,Y,5,7):
				return alpha | X11_GRAY_57;
			case _I(G,R,A,Y,_,5,7):
				return alpha | X11_GRAY_57;
			case _I(G,R,A,Y, ,5,7):
				return alpha | X11_GRAY_57;
			case _I(G,R,E,Y,5,7):
				return alpha | X11_GREY_57;
			case _I(G,R,E,Y,_,5,7):
				return alpha | X11_GREY_57;
			case _I(G,R,E,Y, ,5,7):
				return alpha | X11_GREY_57;
			case _I(G,R,A,Y,5,8):
				return alpha | X11_GRAY_58;
			case _I(G,R,A,Y,_,5,8):
				return alpha | X11_GRAY_58;
			case _I(G,R,A,Y, ,5,8):
				return alpha | X11_GRAY_58;
			case _I(G,R,E,Y,5,8):
				return alpha | X11_GREY_58;
			case _I(G,R,E,Y,_,5,8):
				return alpha | X11_GREY_58;
			case _I(G,R,E,Y, ,5,8):
				return alpha | X11_GREY_58;
			case _I(G,R,A,Y,5,9):
				return alpha | X11_GRAY_59;
			case _I(G,R,A,Y,_,5,9):
				return alpha | X11_GRAY_59;
			case _I(G,R,A,Y, ,5,9):
				return alpha | X11_GRAY_59;
			case _I(G,R,E,Y,5,9):
				return alpha | X11_GREY_59;
			case _I(G,R,E,Y,_,5,9):
				return alpha | X11_GREY_59;
			case _I(G,R,E,Y, ,5,9):
				return alpha | X11_GREY_59;
			case _I(G,R,A,Y,6,0):
				return alpha | X11_GRAY_60;
			case _I(G,R,A,Y,_,6,0):
				return alpha | X11_GRAY_60;
			case _I(G,R,A,Y, ,6,0):
				return alpha | X11_GRAY_60;
			case _I(G,R,E,Y,6,0):
				return alpha | X11_GREY_60;
			case _I(G,R,E,Y,_,6,0):
				return alpha | X11_GREY_60;
			case _I(G,R,E,Y, ,6,0):
				return alpha | X11_GREY_60;
			case _I(G,R,A,Y,6,1):
				return alpha | X11_GRAY_61;
			case _I(G,R,A,Y,_,6,1):
				return alpha | X11_GRAY_61;
			case _I(G,R,A,Y, ,6,1):
				return alpha | X11_GRAY_61;
			case _I(G,R,E,Y,6,1):
				return alpha | X11_GREY_61;
			case _I(G,R,E,Y,_,6,1):
				return alpha | X11_GREY_61;
			case _I(G,R,E,Y, ,6,1):
				return alpha | X11_GREY_61;
			case _I(G,R,A,Y,6,2):
				return alpha | X11_GRAY_62;
			case _I(G,R,A,Y,_,6,2):
				return alpha | X11_GRAY_62;
			case _I(G,R,A,Y, ,6,2):
				return alpha | X11_GRAY_62;
			case _I(G,R,E,Y,6,2):
				return alpha | X11_GREY_62;
			case _I(G,R,E,Y,_,6,2):
				return alpha | X11_GREY_62;
			case _I(G,R,E,Y, ,6,2):
				return alpha | X11_GREY_62;
			case _I(G,R,A,Y,6,3):
				return alpha | X11_GRAY_63;
			case _I(G,R,A,Y,_,6,3):
				return alpha | X11_GRAY_63;
			case _I(G,R,A,Y, ,6,3):
				return alpha | X11_GRAY_63;
			case _I(G,R,E,Y,6,3):
				return alpha | X11_GREY_63;
			case _I(G,R,E,Y,_,6,3):
				return alpha | X11_GREY_63;
			case _I(G,R,E,Y, ,6,3):
				return alpha | X11_GREY_63;
			case _I(G,R,A,Y,6,4):
				return alpha | X11_GRAY_64;
			case _I(G,R,A,Y,_,6,4):
				return alpha | X11_GRAY_64;
			case _I(G,R,A,Y, ,6,4):
				return alpha | X11_GRAY_64;
			case _I(G,R,E,Y,6,4):
				return alpha | X11_GREY_64;
			case _I(G,R,E,Y,_,6,4):
				return alpha | X11_GREY_64;
			case _I(G,R,E,Y, ,6,4):
				return alpha | X11_GREY_64;
			case _I(G,R,A,Y,6,5):
				return alpha | X11_GRAY_65;
			case _I(G,R,A,Y,_,6,5):
				return alpha | X11_GRAY_65;
			case _I(G,R,A,Y, ,6,5):
				return alpha | X11_GRAY_65;
			case _I(G,R,E,Y,6,5):
				return alpha | X11_GREY_65;
			case _I(G,R,E,Y,_,6,5):
				return alpha | X11_GREY_65;
			case _I(G,R,E,Y, ,6,5):
				return alpha | X11_GREY_65;
			case _I(G,R,A,Y,6,6):
				return alpha | X11_GRAY_66;
			case _I(G,R,A,Y,_,6,6):
				return alpha | X11_GRAY_66;
			case _I(G,R,A,Y, ,6,6):
				return alpha | X11_GRAY_66;
			case _I(G,R,E,Y,6,6):
				return alpha | X11_GREY_66;
			case _I(G,R,E,Y,_,6,6):
				return alpha | X11_GREY_66;
			case _I(G,R,E,Y, ,6,6):
				return alpha | X11_GREY_66;
			case _I(G,R,A,Y,6,7):
				return alpha | X11_GRAY_67;
			case _I(G,R,A,Y,_,6,7):
				return alpha | X11_GRAY_67;
			case _I(G,R,A,Y, ,6,7):
				return alpha | X11_GRAY_67;
			case _I(G,R,E,Y,6,7):
				return alpha | X11_GREY_67;
			case _I(G,R,E,Y,_,6,7):
				return alpha | X11_GREY_67;
			case _I(G,R,E,Y, ,6,7):
				return alpha | X11_GREY_67;
			case _I(G,R,A,Y,6,8):
				return alpha | X11_GRAY_68;
			case _I(G,R,A,Y,_,6,8):
				return alpha | X11_GRAY_68;
			case _I(G,R,A,Y, ,6,8):
				return alpha | X11_GRAY_68;
			case _I(G,R,E,Y,6,8):
				return alpha | X11_GREY_68;
			case _I(G,R,E,Y,_,6,8):
				return alpha | X11_GREY_68;
			case _I(G,R,E,Y, ,6,8):
				return alpha | X11_GREY_68;
			case _I(G,R,A,Y,6,9):
				return alpha | X11_GRAY_69;
			case _I(G,R,A,Y,_,6,9):
				return alpha | X11_GRAY_69;
			case _I(G,R,A,Y, ,6,9):
				return alpha | X11_GRAY_69;
			case _I(G,R,E,Y,6,9):
				return alpha | X11_GREY_69;
			case _I(G,R,E,Y,_,6,9):
				return alpha | X11_GREY_69;
			case _I(G,R,E,Y, ,6,9):
				return alpha | X11_GREY_69;
			case _I(G,R,A,Y,7,0):
				return alpha | X11_GRAY_70;
			case _I(G,R,A,Y,_,7,0):
				return alpha | X11_GRAY_70;
			case _I(G,R,A,Y, ,7,0):
				return alpha | X11_GRAY_70;
			case _I(G,R,E,Y,7,0):
				return alpha | X11_GREY_70;
			case _I(G,R,E,Y,_,7,0):
				return alpha | X11_GREY_70;
			case _I(G,R,E,Y, ,7,0):
				return alpha | X11_GREY_70;
			case _I(G,R,A,Y,7,1):
				return alpha | X11_GRAY_71;
			case _I(G,R,A,Y,_,7,1):
				return alpha | X11_GRAY_71;
			case _I(G,R,A,Y, ,7,1):
				return alpha | X11_GRAY_71;
			case _I(G,R,E,Y,7,1):
				return alpha | X11_GREY_71;
			case _I(G,R,E,Y,_,7,1):
				return alpha | X11_GREY_71;
			case _I(G,R,E,Y, ,7,1):
				return alpha | X11_GREY_71;
			case _I(G,R,A,Y,7,2):
				return alpha | X11_GRAY_72;
			case _I(G,R,A,Y,_,7,2):
				return alpha | X11_GRAY_72;
			case _I(G,R,A,Y, ,7,2):
				return alpha | X11_GRAY_72;
			case _I(G,R,E,Y,7,2):
				return alpha | X11_GREY_72;
			case _I(G,R,E,Y,_,7,2):
				return alpha | X11_GREY_72;
			case _I(G,R,E,Y, ,7,2):
				return alpha | X11_GREY_72;
			case _I(G,R,A,Y,7,3):
				return alpha | X11_GRAY_73;
			case _I(G,R,A,Y,_,7,3):
				return alpha | X11_GRAY_73;
			case _I(G,R,A,Y, ,7,3):
				return alpha | X11_GRAY_73;
			case _I(G,R,E,Y,7,3):
				return alpha | X11_GREY_73;
			case _I(G,R,E,Y,_,7,3):
				return alpha | X11_GREY_73;
			case _I(G,R,E,Y, ,7,3):
				return alpha | X11_GREY_73;
			case _I(G,R,A,Y,7,4):
				return alpha | X11_GRAY_74;
			case _I(G,R,A,Y,_,7,4):
				return alpha | X11_GRAY_74;
			case _I(G,R,A,Y, ,7,4):
				return alpha | X11_GRAY_74;
			case _I(G,R,E,Y,7,4):
				return alpha | X11_GREY_74;
			case _I(G,R,E,Y,_,7,4):
				return alpha | X11_GREY_74;
			case _I(G,R,E,Y, ,7,4):
				return alpha | X11_GREY_74;
			case _I(G,R,A,Y,7,5):
				return alpha | X11_GRAY_75;
			case _I(G,R,A,Y,_,7,5):
				return alpha | X11_GRAY_75;
			case _I(G,R,A,Y, ,7,5):
				return alpha | X11_GRAY_75;
			case _I(G,R,E,Y,7,5):
				return alpha | X11_GREY_75;
			case _I(G,R,E,Y,_,7,5):
				return alpha | X11_GREY_75;
			case _I(G,R,E,Y, ,7,5):
				return alpha | X11_GREY_75;
			case _I(G,R,A,Y,7,6):
				return alpha | X11_GRAY_76;
			case _I(G,R,A,Y,_,7,6):
				return alpha | X11_GRAY_76;
			case _I(G,R,A,Y, ,7,6):
				return alpha | X11_GRAY_76;
			case _I(G,R,E,Y,7,6):
				return alpha | X11_GREY_76;
			case _I(G,R,E,Y,_,7,6):
				return alpha | X11_GREY_76;
			case _I(G,R,E,Y, ,7,6):
				return alpha | X11_GREY_76;
			case _I(G,R,A,Y,7,7):
				return alpha | X11_GRAY_77;
			case _I(G,R,A,Y,_,7,7):
				return alpha | X11_GRAY_77;
			case _I(G,R,A,Y, ,7,7):
				return alpha | X11_GRAY_77;
			case _I(G,R,E,Y,7,7):
				return alpha | X11_GREY_77;
			case _I(G,R,E,Y,_,7,7):
				return alpha | X11_GREY_77;
			case _I(G,R,E,Y, ,7,7):
				return alpha | X11_GREY_77;
			case _I(G,R,A,Y,7,8):
				return alpha | X11_GRAY_78;
			case _I(G,R,A,Y,_,7,8):
				return alpha | X11_GRAY_78;
			case _I(G,R,A,Y, ,7,8):
				return alpha | X11_GRAY_78;
			case _I(G,R,E,Y,7,8):
				return alpha | X11_GREY_78;
			case _I(G,R,E,Y,_,7,8):
				return alpha | X11_GREY_78;
			case _I(G,R,E,Y, ,7,8):
				return alpha | X11_GREY_78;
			case _I(G,R,A,Y,7,9):
				return alpha | X11_GRAY_79;
			case _I(G,R,A,Y,_,7,9):
				return alpha | X11_GRAY_79;
			case _I(G,R,A,Y, ,7,9):
				return alpha | X11_GRAY_79;
			case _I(G,R,E,Y,7,9):
				return alpha | X11_GREY_79;
			case _I(G,R,E,Y,_,7,9):
				return alpha | X11_GREY_79;
			case _I(G,R,E,Y, ,7,9):
				return alpha | X11_GREY_79;
			case _I(G,R,A,Y,8,0):
				return alpha | X11_GRAY_80;
			case _I(G,R,A,Y,_,8,0):
				return alpha | X11_GRAY_80;
			case _I(G,R,A,Y, ,8,0):
				return alpha | X11_GRAY_80;
			case _I(G,R,E,Y,8,0):
				return alpha | X11_GREY_80;
			case _I(G,R,E,Y,_,8,0):
				return alpha | X11_GREY_80;
			case _I(G,R,E,Y, ,8,0):
				return alpha | X11_GREY_80;
			case _I(G,R,A,Y,8,1):
				return alpha | X11_GRAY_81;
			case _I(G,R,A,Y,_,8,1):
				return alpha | X11_GRAY_81;
			case _I(G,R,A,Y, ,8,1):
				return alpha | X11_GRAY_81;
			case _I(G,R,E,Y,8,1):
				return alpha | X11_GREY_81;
			case _I(G,R,E,Y,_,8,1):
				return alpha | X11_GREY_81;
			case _I(G,R,E,Y, ,8,1):
				return alpha | X11_GREY_81;
			case _I(G,R,A,Y,8,2):
				return alpha | X11_GRAY_82;
			case _I(G,R,A,Y,_,8,2):
				return alpha | X11_GRAY_82;
			case _I(G,R,A,Y, ,8,2):
				return alpha | X11_GRAY_82;
			case _I(G,R,E,Y,8,2):
				return alpha | X11_GREY_82;
			case _I(G,R,E,Y,_,8,2):
				return alpha | X11_GREY_82;
			case _I(G,R,E,Y, ,8,2):
				return alpha | X11_GREY_82;
			case _I(G,R,A,Y,8,3):
				return alpha | X11_GRAY_83;
			case _I(G,R,A,Y,_,8,3):
				return alpha | X11_GRAY_83;
			case _I(G,R,A,Y, ,8,3):
				return alpha | X11_GRAY_83;
			case _I(G,R,E,Y,8,3):
				return alpha | X11_GREY_83;
			case _I(G,R,E,Y,_,8,3):
				return alpha | X11_GREY_83;
			case _I(G,R,E,Y, ,8,3):
				return alpha | X11_GREY_83;
			case _I(G,R,A,Y,8,4):
				return alpha | X11_GRAY_84;
			case _I(G,R,A,Y,_,8,4):
				return alpha | X11_GRAY_84;
			case _I(G,R,A,Y, ,8,4):
				return alpha | X11_GRAY_84;
			case _I(G,R,E,Y,8,4):
				return alpha | X11_GREY_84;
			case _I(G,R,E,Y,_,8,4):
				return alpha | X11_GREY_84;
			case _I(G,R,E,Y, ,8,4):
				return alpha | X11_GREY_84;
			case _I(G,R,A,Y,8,5):
				return alpha | X11_GRAY_85;
			case _I(G,R,A,Y,_,8,5):
				return alpha | X11_GRAY_85;
			case _I(G,R,A,Y, ,8,5):
				return alpha | X11_GRAY_85;
			case _I(G,R,E,Y,8,5):
				return alpha | X11_GREY_85;
			case _I(G,R,E,Y,_,8,5):
				return alpha | X11_GREY_85;
			case _I(G,R,E,Y, ,8,5):
				return alpha | X11_GREY_85;
			case _I(G,R,A,Y,8,6):
				return alpha | X11_GRAY_86;
			case _I(G,R,A,Y,_,8,6):
				return alpha | X11_GRAY_86;
			case _I(G,R,A,Y, ,8,6):
				return alpha | X11_GRAY_86;
			case _I(G,R,E,Y,8,6):
				return alpha | X11_GREY_86;
			case _I(G,R,E,Y,_,8,6):
				return alpha | X11_GREY_86;
			case _I(G,R,E,Y, ,8,6):
				return alpha | X11_GREY_86;
			case _I(G,R,A,Y,8,7):
				return alpha | X11_GRAY_87;
			case _I(G,R,A,Y,_,8,7):
				return alpha | X11_GRAY_87;
			case _I(G,R,A,Y, ,8,7):
				return alpha | X11_GRAY_87;
			case _I(G,R,E,Y,8,7):
				return alpha | X11_GREY_87;
			case _I(G,R,E,Y,_,8,7):
				return alpha | X11_GREY_87;
			case _I(G,R,E,Y, ,8,7):
				return alpha | X11_GREY_87;
			case _I(G,R,A,Y,8,8):
				return alpha | X11_GRAY_88;
			case _I(G,R,A,Y,_,8,8):
				return alpha | X11_GRAY_88;
			case _I(G,R,A,Y, ,8,8):
				return alpha | X11_GRAY_88;
			case _I(G,R,E,Y,8,8):
				return alpha | X11_GREY_88;
			case _I(G,R,E,Y,_,8,8):
				return alpha | X11_GREY_88;
			case _I(G,R,E,Y, ,8,8):
				return alpha | X11_GREY_88;
			case _I(G,R,A,Y,8,9):
				return alpha | X11_GRAY_89;
			case _I(G,R,A,Y,_,8,9):
				return alpha | X11_GRAY_89;
			case _I(G,R,A,Y, ,8,9):
				return alpha | X11_GRAY_89;
			case _I(G,R,E,Y,8,9):
				return alpha | X11_GREY_89;
			case _I(G,R,E,Y,_,8,9):
				return alpha | X11_GREY_89;
			case _I(G,R,E,Y, ,8,9):
				return alpha | X11_GREY_89;
			case _I(G,R,A,Y,9,0):
				return alpha | X11_GRAY_90;
			case _I(G,R,A,Y,_,9,0):
				return alpha | X11_GRAY_90;
			case _I(G,R,A,Y, ,9,0):
				return alpha | X11_GRAY_90;
			case _I(G,R,E,Y,9,0):
				return alpha | X11_GREY_90;
			case _I(G,R,E,Y,_,9,0):
				return alpha | X11_GREY_90;
			case _I(G,R,E,Y, ,9,0):
				return alpha | X11_GREY_90;
			case _I(G,R,A,Y,9,1):
				return alpha | X11_GRAY_91;
			case _I(G,R,A,Y,_,9,1):
				return alpha | X11_GRAY_91;
			case _I(G,R,A,Y, ,9,1):
				return alpha | X11_GRAY_91;
			case _I(G,R,E,Y,9,1):
				return alpha | X11_GREY_91;
			case _I(G,R,E,Y,_,9,1):
				return alpha | X11_GREY_91;
			case _I(G,R,E,Y, ,9,1):
				return alpha | X11_GREY_91;
			case _I(G,R,A,Y,9,2):
				return alpha | X11_GRAY_92;
			case _I(G,R,A,Y,_,9,2):
				return alpha | X11_GRAY_92;
			case _I(G,R,A,Y, ,9,2):
				return alpha | X11_GRAY_92;
			case _I(G,R,E,Y,9,2):
				return alpha | X11_GREY_92;
			case _I(G,R,E,Y,_,9,2):
				return alpha | X11_GREY_92;
			case _I(G,R,E,Y, ,9,2):
				return alpha | X11_GREY_92;
			case _I(G,R,A,Y,9,3):
				return alpha | X11_GRAY_93;
			case _I(G,R,A,Y,_,9,3):
				return alpha | X11_GRAY_93;
			case _I(G,R,A,Y, ,9,3):
				return alpha | X11_GRAY_93;
			case _I(G,R,E,Y,9,3):
				return alpha | X11_GREY_93;
			case _I(G,R,E,Y,_,9,3):
				return alpha | X11_GREY_93;
			case _I(G,R,E,Y, ,9,3):
				return alpha | X11_GREY_93;
			case _I(G,R,A,Y,9,4):
				return alpha | X11_GRAY_94;
			case _I(G,R,A,Y,_,9,4):
				return alpha | X11_GRAY_94;
			case _I(G,R,A,Y, ,9,4):
				return alpha | X11_GRAY_94;
			case _I(G,R,E,Y,9,4):
				return alpha | X11_GREY_94;
			case _I(G,R,E,Y,_,9,4):
				return alpha | X11_GREY_94;
			case _I(G,R,E,Y, ,9,4):
				return alpha | X11_GREY_94;
			case _I(G,R,A,Y,9,5):
				return alpha | X11_GRAY_95;
			case _I(G,R,A,Y,_,9,5):
				return alpha | X11_GRAY_95;
			case _I(G,R,A,Y, ,9,5):
				return alpha | X11_GRAY_95;
			case _I(G,R,E,Y,9,5):
				return alpha | X11_GREY_95;
			case _I(G,R,E,Y,_,9,5):
				return alpha | X11_GREY_95;
			case _I(G,R,E,Y, ,9,5):
				return alpha | X11_GREY_95;
			case _I(G,R,A,Y,9,6):
				return alpha | X11_GRAY_96;
			case _I(G,R,A,Y,_,9,6):
				return alpha | X11_GRAY_96;
			case _I(G,R,A,Y, ,9,6):
				return alpha | X11_GRAY_96;
			case _I(G,R,E,Y,9,6):
				return alpha | X11_GREY_96;
			case _I(G,R,E,Y,_,9,6):
				return alpha | X11_GREY_96;
			case _I(G,R,E,Y, ,9,6):
				return alpha | X11_GREY_96;
			case _I(G,R,A,Y,9,7):
				return alpha | X11_GRAY_97;
			case _I(G,R,A,Y,_,9,7):
				return alpha | X11_GRAY_97;
			case _I(G,R,A,Y, ,9,7):
				return alpha | X11_GRAY_97;
			case _I(G,R,E,Y,9,7):
				return alpha | X11_GREY_97;
			case _I(G,R,E,Y,_,9,7):
				return alpha | X11_GREY_97;
			case _I(G,R,E,Y, ,9,7):
				return alpha | X11_GREY_97;
			case _I(G,R,A,Y,9,8):
				return alpha | X11_GRAY_98;
			case _I(G,R,A,Y,_,9,8):
				return alpha | X11_GRAY_98;
			case _I(G,R,A,Y, ,9,8):
				return alpha | X11_GRAY_98;
			case _I(G,R,E,Y,9,8):
				return alpha | X11_GREY_98;
			case _I(G,R,E,Y,_,9,8):
				return alpha | X11_GREY_98;
			case _I(G,R,E,Y, ,9,8):
				return alpha | X11_GREY_98;
			case _I(G,R,A,Y,9,9):
				return alpha | X11_GRAY_99;
			case _I(G,R,A,Y,_,9,9):
				return alpha | X11_GRAY_99;
			case _I(G,R,A,Y, ,9,9):
				return alpha | X11_GRAY_99;
			case _I(G,R,E,Y,9,9):
				return alpha | X11_GREY_99;
			case _I(G,R,E,Y,_,9,9):
				return alpha | X11_GREY_99;
			case _I(G,R,E,Y, ,9,9):
				return alpha | X11_GREY_99;
			case _I(G,R,A,Y,1,0,0):
				return alpha | X11_GRAY_100;
			case _I(G,R,A,Y,_,1,0,0):
				return alpha | X11_GRAY_100;
			case _I(G,R,A,Y, ,1,0,0):
				return alpha | X11_GRAY_100;
			case _I(G,R,E,Y,1,0,0):
				return alpha | X11_GREY_100;
			case _I(G,R,E,Y,_,1,0,0):
				return alpha | X11_GREY_100;
			case _I(G,R,E,Y, ,1,0,0):
				return alpha | X11_GREY_100;
			case _I(D,A,R,K,G,R,E,Y):
				return alpha | X11_DARK_GREY;
			case _I(D,A,R,K,_,G,R,E,Y):
				return alpha | X11_DARK_GREY;
			case _I(D,A,R,K, ,G,R,E,Y):
				return alpha | X11_DARK_GREY;
			case _I(D,A,R,K,G,R,A,Y):
				return alpha | X11_DARK_GRAY;
			case _I(D,A,R,K,_,G,R,A,Y):
				return alpha | X11_DARK_GRAY;
			case _I(D,A,R,K, ,G,R,A,Y):
				return alpha | X11_DARK_GRAY;
			case _I(D,A,R,K,B,L,U,E):
				return alpha | X11_DARK_BLUE;
			case _I(D,A,R,K,_,B,L,U,E):
				return alpha | X11_DARK_BLUE;
			case _I(D,A,R,K, ,B,L,U,E):
				return alpha | X11_DARK_BLUE;
			case _I(D,A,R,K,C,Y,A,N):
				return alpha | X11_DARK_CYAN;
			case _I(D,A,R,K,_,C,Y,A,N):
				return alpha | X11_DARK_CYAN;
			case _I(D,A,R,K, ,C,Y,A,N):
				return alpha | X11_DARK_CYAN;
			case _I(D,A,R,K,M,A,G,E,N,T,A):
				return alpha | X11_DARK_MAGENTA;
			case _I(D,A,R,K,_,M,A,G,E,N,T,A):
				return alpha | X11_DARK_MAGENTA;
			case _I(D,A,R,K, ,M,A,G,E,N,T,A):
				return alpha | X11_DARK_MAGENTA;
			case _I(D,A,R,K,R,E,D):
				return alpha | X11_DARK_RED;
			case _I(D,A,R,K,_,R,E,D):
				return alpha | X11_DARK_RED;
			case _I(D,A,R,K, ,R,E,D):
				return alpha | X11_DARK_RED;
			case _I(L,I,G,H,T,G,R,E,E,N):
				return alpha | X11_LIGHT_GREEN;
			case _I(L,I,G,H,T,_,G,R,E,E,N):
				return alpha | X11_LIGHT_GREEN;
			case _I(L,I,G,H,T, ,G,R,E,E,N):
				return alpha | X11_LIGHT_GREEN;
		}
	#endif
	// Do the default code here.
	for (new i = 0; i != MAX_TEXT_COLOURS; ++i)
	{
		new
			iColor = YSI_g_sColours[i][0];
		if (iColor == hash)
		{
			return alpha | YSI_g_sColours[i][1];
		}
		else if (iColor == 0)
		{
			return 0;
		}
	}
	return 0;
}
