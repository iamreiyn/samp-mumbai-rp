/*----------------------------------------------------------------------------*-
					========================================
					 y_playerarray - Bit arrays of players! 
					========================================
Description:
	This code provides arrays of players who can do things.  This is for support
	of the text system which can take arrays of player ids, bit arrays or just a
	single ID.
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

#include <YSI\internal\y_version>

#include <YSI\y_bit>
#include <a_samp>

#define PA_TYPE_NONE                    (-1)
#define PA_TYPE_BOOL                    (-2)
#define PA_TYPE_ID                      (-3)
#define PA_TYPE_PA                      (-4)

#define PlayerArray:%0<%1> Bit:%0[%1]//={Bit:-1}

#define PA_DEC<%0> static stock PlayerArray:_YSI_g_sPlayerDataA[%0]<MAX_PLAYERS>;//const _YSI_g_sPlayerDataS=%0;
#define PA_INT<%0,%2> PA_Init(_YSI_g_sPlayerDataA[(%0)],(%2));
#define PA_ADD<%0,%1> PA+(_YSI_g_sPlayerDataA[(%0)],(%1));
#define PA_REM<%0,%1> PA-(_YSI_g_sPlayerDataA[(%0)],(%1));
#define PA_SET<%0,%1,%2> (%2)?(PA+(_YSI_g_sPlayerDataA[(%0)],(%1))):(PA-(_YSI_g_sPlayerDataA[(%0)],(%1)));

//#define PA_Init() {Bit:-1}

stock PA_Init(Bit:a[], bool:init = false, s = bits<MAX_PLAYERS>)
{
	--s;
	new
		Bit:m = init ? (Bit:-1) : (Bit:0);
	a[0] = Bit:PA_TYPE_PA;
	while (s)
	{
		a[s--] = m;
	}
}

//#define PA_Get(%1,%2) bool:(%1[Bit_Slot(%2)+1]&Bit_Mask(%2))

/*stock PA_Assign(PlayerArray:array<>, slot, value, count = bitsof (array))
{
	if (slot >= count) return;
	if (set) array[Bit_Slot(slot) + 1] |= Bit_Mask(slot);
	else array[Bit_Slot(slot) + 1] &= ~Bit_Mask(slot);
}*/

stock Bit:operator+(Bit:oper2, PlayerArray:oper1)
{
	return oper2 | Bit_Mask(_:oper1);
}

stock Bit:operator-(Bit:oper2, PlayerArray:oper1)
{
	return oper2 & ~Bit_Mask(_:oper1);
}

stock bool:operator==(Bit:oper2, PlayerArray:oper1)
{
	return bool:(oper2 & Bit_Mask(_:oper1));
}

stock bool:operator!=(Bit:oper2, PlayerArray:oper1)
{
	return !(oper2 & Bit_Mask(_:oper1));
}

/*stock Bit:operator&(Bit:oper2, PlayerArray:oper1)
{
	#pragma unused oper1
	return oper2;
}

stock Bit:operator|(Bit:oper2, PlayerArray:oper1)
{
	#pragma unused oper1
	return oper2 & Bit_Mask(_:oper1);
}*/

//#define PA%0(%1,%2) (Bit:(%1[Bit_Slot(%2)+1]%0=PlayerArray:(%2))&Bit_Mask(%2))
#define PA%0(%1,%2) (%1[Bit_Slot(%2)+1]%0=PlayerArray:(%2))

/*stock PA_Set(PlayerArray:array<>, slot, bool:set, count = bitsof (array))
{
	if (slot >= count) return;
	if (set) array[Bit_Slot(slot) + 1] |= Bit_Mask(slot);
	else array[Bit_Slot(slot) + 1] &= ~Bit_Mask(slot);
}*/

#undef PlayerArray
#define PlayerArray:%0<%1> Bit:%0[bits<%1>+1]//={Bit:-1}
