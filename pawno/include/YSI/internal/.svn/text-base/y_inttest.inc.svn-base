/*----------------------------------------------------------------------------*-
					=================================
					 y_inttest - Internal test code!
					=================================
Description:
	Internal test code - do not use...
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
	29/11/10:
		First version
-*----------------------------------------------------------------------------*/

#if !defined _YSI_ALLOW_INTERNAL_TEST
	#endinput
#endif

#define MAX_INTERNALX_TEST_ITEMS         42

#define _GROUP_MAKE_NAME_INTTEST<%0...%1>       %0InttestX%1
#define _GROUP_MAKE_LIMIT_INTTEST               MAX_INTERNALX_TEST_ITEMS

#include <YSI\y_master>
#include <YSI\y_groups>

#include <YSI\y_playerarray>

static
	//BitArray:gPlayers[MAX_INTERNALX_TEST_ITEMS]<MAX_PLAYERS>,
	PlayerArray:gPlayers[MAX_INTERNALX_TEST_ITEMS]<MAX_PLAYERS>,
	gElements[MAX_INTERNALX_TEST_ITEMS] = {-1, ...};

//inttestxxx
//checkpoint
RF:InttestX_Create[i](val)
{
	new
		i = 0;
	while (i != MAX_INTERNALX_TEST_ITEMS && gElements[i] != -1)
	{
		++i;
	}
	if (i == MAX_INTERNALX_TEST_ITEMS)
	{
		return -1;
	}
	NO_GROUPS(i)
	{
		//Bit_SetAll(
		PA_Init(gPlayers[i], true, bits<MAX_PLAYERS>);
	}
	gElements[i] = val;
	return i;
}

RF@v:InttestX_SetPlayer[iii](element, playerid, bool:set)
//Inttest_SetPlayer(element, playerid, set)
{
	if (set) PA+(gPlayers[element], playerid);
	else PA-(gPlayers[element], playerid);
}

#define YSI_GROUPS_LAST 9
#include <YSI\internal\y_grouprevert>
