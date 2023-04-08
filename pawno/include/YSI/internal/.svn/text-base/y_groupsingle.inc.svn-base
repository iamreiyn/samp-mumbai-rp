/*----------------------------------------------------------------------------*-
					=======================================
					 y_groups - Player group abstractions! 
					=======================================
Description:
	Admin levels, gangs, teams etc - they're all "groups" of people, this
	provides an abstraction for all of these collections.
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

#undef _inc_y_groupsingle

//#undef GROUP_LOCAL
//#undef Group

/*#if YSIM_HAS_MASTER
	#if YSIM_IS_CLIENT
		//#define Group:%0_InitialiseFromGroups(%1)
		stock _GROUP_INITIALISE(x) <YSI_has_groups:n>
		{
			#pragma unused x
		}
		
		stock _GROUP_INITIALISE(x) <>
		{
			#pragma unused x
		}
	#else
		#if YSIM_IS_SERVER
			//#define Group:%0_InitialiseFromGroups(%1) forward _GROUP_INITIALISE(x);_GROUP_INITIALISE(%1)<YSI_has_groups:n>__GROUP_INITIALISE(%1);_GROUP_INITIALISE(%1)<>__GROUP_INITIALISE(%1);static stock __GROUP_INITIALISE(%1)
			stock bool:_GROUP_INITIALISE(x) <YSI_has_groups:n>
			{
				#pragma unused x
				return false;
			}
			
			stock bool:_GROUP_INITIALISE(x) <>
			{
				#pragma unused x
				return false;
			}
		#else
			#if YSIM_IS_STUB
				#error y_groupsingle called with YSIM_IS_STUB.
			#else
				//#define Group:%0_InitialiseFromGroups(%1) forward _GROUP_INITIALISE(x);_GROUP_INITIALISE(%1)<YSI_has_groups:n>__GROUP_INITIALISE(%1);_GROUP_INITIALISE(%1)<>__GROUP_INITIALISE(%1);static stock __GROUP_INITIALISE(%1)
			#endif
		#endif
	#endif
#else
	//#define Group:%0_InitialiseFromGroups(%1) forward _GROUP_INITIALISE(x);_GROUP_INITIALISE(%1)<YSI_has_groups:n>__GROUP_INITIALISE(%1);_GROUP_INITIALISE(%1)<>__GROUP_INITIALISE(%1);static stock __GROUP_INITIALISE(%1)
#endif*/

#if !defined _YSI_HAS_GROUP_SYSTEM
	forward bool:_GROUP_INITIALISE(x = _GROUP_MAKE_LIMIT);
#endif

stock bool:_GROUP_INITIALISE(x = _GROUP_MAKE_LIMIT) <YSI_has_groups:n>
{
	#pragma unused x
	return false;
}

stock bool:_GROUP_INITIALISE(x = _GROUP_MAKE_LIMIT) <>
{
	#pragma unused x
	return false;
}
