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

#include <a_samp>

#include <YSI\y_master>
#include <YSI\y_bit>

#include <YSI\y_debug>

//#include <YSI\y_hooks>
#include <YSI\y_scripting>

#include <YSI\y_iterate>

#define ALS_PREFIX Group

#include <YSI\y_als>

//#define _YSI_HAS_GROUP_SYSTEM

//#define _GROUP_MAKE_NAME<%0...%1> %0_%1
// Dummy value
//#define _GROUP_MAKE_LIMIT               0

// Dummy values.
#undef _GROUP_MAKE_NAME
#undef _GROUP_MAKE_LIMIT
#define _GROUP_MAKE_NAME<%0...%1>       %0_%1
#define _GROUP_MAKE_LIMIT               0

// Example:
//  #define _GROUP_MAKE_NAME<%0...%1> %0Checkpoint%1
/*#if !defined _GROUP_MAKE_NAME
	#error Please define _GROUP_MAKE_NAME before including y_groupsone.
#endif
#if !defined _GROUP_MAKE_LIMIT
	#error Please define _GROUP_MAKE_LIMIT before including y_groupsone.
#endif*/

// Define local variable names.  This will go in the single call file.
//#define _GROUP_LOCAL_NAME               _GROUP_MAKE_NAME<i...>
#define _GROUP_GROUP_NAME               _GROUP_MAKE_NAME<YSI_gs_Group...Data>
#define _GROUP_GLOBAL_NAME              _GROUP_MAKE_NAME<YSI_gs_GroupGlobal...>

#define _GROUP_SET_PLAYER               _GROUP_MAKE_NAME<..._SetPlayer>

/*#define _GROUP_UPDATE                   _GROUP_MAKE_NAME<Group_UpdatePlayer...>
#define _GROUP_UPDATE_ALL               _GROUP_MAKE_NAME<Group_UpdateAll...>

#define _GROUP_GROUP_FUNC               _GROUP_MAKE_NAME<Group_Set...>
#define _GROUP_GLOBAL_FUNC              _GROUP_MAKE_NAME<Group_SetGlobal...>

#define _GROUP_GLOBAL_DEF               _GROUP_MAKE_NAME<Group_SetGlobal...Default>
#define _GROUP_GROUP_DEF                _GROUP_MAKE_NAME<Group_Set...Default>

#define _GROUP_ON_PLAYER_CONNECT        _GROUP_MAKE_NAME<@yH_PlayerConnect_...@yG>

#define _GROUP_DEFAULTS                 _GROUP_MAKE_NAME<Group_...Defaults>

#define _GROUP_INIT                     _GROUP_MAKE_NAME<Group_...Init>*/

#define _GROUP_CREATE                   _GROUP_MAKE_NAME<@yG_Init...>
#define _GROUP_UPDATE_PLAYER            _GROUP_MAKE_NAME<@yG_Upd...>
//#define _GROUP_ON_PLAYER_CONNECT        _GROUP_MAKE_NAME<@yG_..._PlayerConnect>
//#define _GROUP_ON_PLAYER_CONNECT        RH:_GROUP_MAKE_NAME<...@yG_OnPlayerConnect>

#define _GROUP_OPC_OTHER_CALLED   _GROUP_MAKE_NAME<_@yGPlayerConnect_...>
#define _GROUP_OPC_IS_CALLED   _GROUP_MAKE_NAME<_yG@PlayerConnect_...>
#define _GROUP_OPC_PUBLIC      _GROUP_MAKE_NAME<@yG_PlayerConnect_...>

#if !defined MAX_GROUP_NAME
	#define MAX_GROUP_NAME              (24)
#endif

#if !defined MAX_GROUPS
	// 1 less than a nice number (with good reason).
	#define MAX_GROUPS                  (Group:127)
#endif

enum e_GROUP_FLAGS (<<= 1)
{
	e_GROUP_FLAGS_GANG = 1,
	// I can't remember why I had this!
	//e_GROUP_FLAGS_CHAT,
	e_GROUP_FLAGS_ACTIVE,
	e_GROUP_FLAGS_COLOR = 0xFFFFFF00
}

enum E_GROUP_DATA
{
	E_GROUP_DATA_NAME[MAX_GROUP_NAME char],
	E_GROUP_DATA_HASH,
	e_GROUP_FLAGS:E_GROUP_DATA_FLAGS,
}

stock
	BitArray:YSI_gGroupPlayers[MAX_GROUPS]<MAX_PLAYERS>,
	YSI_gGroupData[MAX_GROUPS][E_GROUP_DATA];

ALS_DATA<>

#define GROUPS_MAX_LIBRARIES            4

static stock
	YSI_g_sNextUpdateFunc[32],
	YSI_g_sNextInitFunc[32],
	YSI_g_sGroupCount,
	bool:YSI_g_sHasOPC = false;

#define _Group_HasPlayer(%0,%1) \
	Bit_Get(YSI_gGroupPlayers[(%0)], (%1), MAX_PLAYERS)

#define _Group_GetColor(%0) \
	(_:(YSI_gGroupData[(%0)][E_GROUP_DATA_FLAGS] & e_GROUP_FLAGS_COLOR | e_GROUP_FLAGS:0xAA))

#define _Group_SetColor(%0,%1) \
	(YSI_gGroupData[(%0)][E_GROUP_DATA_FLAGS] |= e_GROUP_FLAGS:(%1) & e_GROUP_FLAGS_COLOR)

#define _Group_GetGang(%0) \
	(bool:(YSI_gGroupData[(%0)][E_GROUP_DATA_FLAGS] & e_GROUP_FLAGS_GANG))

#define _Group_LetGang(%0) \
	(YSI_gGroupData[(%0)][E_GROUP_DATA_FLAGS] |= e_GROUP_FLAGS_GANG)

#define _Group_VetGang(%0) \
	(YSI_gGroupData[(%0)][E_GROUP_DATA_FLAGS] &= ~e_GROUP_FLAGS_GANG)

#define _Group_IsActive(%0) \
	(YSI_gGroupData[(%0)][E_GROUP_DATA_FLAGS] & e_GROUP_FLAGS_ACTIVE)

//#define _Group_IsValid(%0) 
//	(0 <= (%0) < MAX_GROUPS && Group_IsActive(%0))

#define _Group_IsValid(%0) \
	(Group:0 <= (%0) < MAX_GROUPS && _Group_IsActive(%0))

#define Group_IsActive(%0) \
	(YSI_gGroupData[GROUP_FIX(%0)][E_GROUP_DATA_FLAGS] & e_GROUP_FLAGS_ACTIVE)

/*#define Group_IsValid(%0) \
	(GROUP_MASK <= (%0) < (GROUP_MASK + MAX_GROUPS) <=  && Group_IsActive(%0))*/

//#define Group_GetColor(%0) 
//	(YSI_gGroupData[(%0)][E_GROUP_DATA_FLAGS] & e_GROUP_FLAGS_COLOR | 0xAA);
//	(0 <= GROUP_FIX(%0) < MAX_GROUPS && Group_IsActive(%0))

#if defined FILTERSCRIPT
	public OnFilterScriptInit()
#else
	public OnGameModeInit()
#endif
{
	state YSI_has_groups:y;
	ALS_DETECT<PlayerDisconnect>
	ALS_DETECT<PlayerConnect>
	YSI_g_sHasOPC = funcidx(#_GROUP_OPC_PUBLIC) != -1;
	P:3(#_GROUP_OPC_PUBLIC " does%s exist", YSI_g_sHasOPC ? ("") : (" not"));
	P:5("Group_OnScriptInit: OPC = %d", YSI_g_sHasOPC);
	new
		a = Scripting_GetPublic(0, YSI_g_sNextUpdateFunc, "@yG_Upd"),
		idx = Scripting_GetPublic(0, YSI_g_sNextInitFunc, "@yG_Init");
	if (idx)
	{
		CallLocalFunction(YSI_g_sNextInitFunc, "ii", -1, (a << 16) | idx);
	}
	CallLocalFunction("Group_OnScriptInit", "");
}

#if defined FILTERSCRIPT
	#if defined _ALS_OnFilterScriptInit
		#undef OnFilterScriptInit
	#else
		#define _ALS_OnFilterScriptInit
	#endif
	#define OnFilterScriptInit Group_OnScriptInit
#else
	#if defined _ALS_OnGameModeInit
		#undef OnGameModeInit
	#else
		#define _ALS_OnGameModeInit
	#endif
	#define OnGameModeInit Group_OnScriptInit
#endif
forward Group_OnScriptInit();

// This needs an OnPlayerConnect hook, but an ALS one - I'll sort that later.
RA:Group_OnPlayerDisconnect(playerid, reason)
{
	new
		s = Bit_Slot(playerid),
		Bit:m = ~Bit_Mask(playerid);
	for (new Group:i; i != MAX_GROUPS; ++i)
	{
		// Pre-calculate the slot and mask.
		YSI_gGroupPlayers[i][s] &= m;
	}
	//CallLocalFunction("Group_OnPlayerConnect", "i", playerid);
	ALS_CALL<PlayerDisconnect>
}

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect Group_OnPlayerDisconnect

ALS_FORWARD<PlayerDisconnect>

// This needs an OnPlayerConnect hook, but an ALS one - I'll sort that later.
public OnPlayerConnect(playerid)
{
	P:3("Group_OnPlayerConnect called");
	if (YSI_g_sHasOPC) CallLocalFunction(#_GROUP_OPC_PUBLIC, "i", playerid);
	//CallLocalFunction("Group_OnPlayerConnect", "i", playerid);
	ALS_CALL<PlayerConnect>
}

forward _GROUP_OPC_PUBLIC(playerid);

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect Group_OnPlayerConnect

ALS_FORWARD<PlayerConnect>

RF@vp:Group_SetPlayer[iii](Group:g,p,bool:s)<g,p,s>
{
	//g &= ~GROUP_MASK;
	GROUP_FIX(g);
	if (_Group_IsValid(g) && 0 <= p < MAX_PLAYERS)
	{
		Bit_Set(YSI_gGroupPlayers[g], p, s, bits<MAX_PLAYERS>);
		P:4("Group_SetPlayer: %d %d", g, _:YSI_gGroupPlayers[g][0]);
		if (YSI_g_sNextUpdateFunc[0])
		{
			CallLocalFunction(YSI_g_sNextUpdateFunc, "iii", p, g, s);
		}
	}
}

RF@pt:bool:Group_GetPlayer[ii](Group:g,p)<g,p>
{
	GROUP_FIX(g);
	if (_Group_IsValid(g) && 0 <= p < MAX_PLAYERS)
	{
		return Bit_Get(YSI_gGroupPlayers[g], p);
		//Bit_Set(YSI_gGroupPlayers[g], p, s, bits<MAX_PLAYERS>);
	}
	return false;
}

RF@vp:Group_SetName[is](Group:g,n[])<g,n>
{
	GROUP_FIX(g);
	if (_Group_IsValid(g))
	{
		strpack(YSI_gGroupData[g][E_GROUP_DATA_NAME], n, MAX_GROUP_NAME char);
	}
}

RS@p:Group_GetName[i](Group:g)<g>
{
	new
		ret[YSI_MAX_STRING];
	GROUP_FIX(g);
	if (_Group_IsValid(g))
	{
		//return Bit_Get(YSI_gGroupPlayers[g], p);
		//Bit_Set(YSI_gGroupPlayers[g], p, s, bits<MAX_PLAYERS>);
		strunpack(ret, YSI_gGroupData[g][E_GROUP_DATA_NAME], YSI_MAX_STRING);
	}
	return ret;
}

RF@vp:Group_SetGang[is](Group:g,bool:n)<g,n>
{
	GROUP_FIX(g);
	if (_Group_IsValid(g))
	{
		if (n)
		{
			_Group_LetGang(g);
		}
		else
		{
			_Group_VetGang(g);
		}
	}
}

RF@pt:bool:Group_GetGang[i](Group:g)<g>
{
	GROUP_FIX(g);
	if (_Group_IsValid(g))
	{
		return _Group_GetGang(g);
	}
	return false;
}

RF@vp:Group_SetColour[ii](Group:g,c)<g,c>
{
	GROUP_FIX(g);
	if (_Group_IsValid(g))
	{
		_Group_SetColor(g, c);
	}
}

RF@p:Group_GetColour[i](Group:g)<g>
{
	GROUP_FIX(g);
	if (_Group_IsValid(g))
	{
		return _Group_GetColor(g);
		//Bit_Set(YSI_gGroupPlayers[g], p, s, bits<MAX_PLAYERS>);
	}
	return 0;
}

#define Group_SetColor Group_SetColour
#define Group_GetColor Group_GetColour

RF@pt:Group:Group_Create[s](name[])<name>
{
	P:3("Group_Create called in %d", _@);
	new
		Group:i;
	while (i != MAX_GROUPS && _Group_IsActive(i))
	{
		++i;
	}
	if (i == MAX_GROUPS) return GROUP_GLOBAL;
	strpack(YSI_gGroupData[i][E_GROUP_DATA_NAME], name, MAX_GROUP_NAME char);
	++YSI_g_sGroupCount;
	YSI_gGroupData[i][E_GROUP_DATA_FLAGS] = e_GROUP_FLAGS_ACTIVE;
	// Now initialise all the little bits.  CallREMOTEFunction to get ALL
	// scripts which may control part of the group system.
	//CallRemoteFunction(#_GROUP_CREATE, "ii", _:i, -1);
	if (YSI_g_sNextInitFunc[0])
	{
		CallLocalFunction(YSI_g_sNextInitFunc, "ii", _:i, -1);
	}
	return i | GROUP_MASK;
}

//forward _GROUP_CREATE(group);

stock YSI_gSGroup(Group:group)
{
	GROUP_FIX(group);
	if (!_Group_IsValid(group))
	{
		return -1;
	}
	static const
		scDeBruijn[] =
			{
				0,  1,  28, 2,  29, 14, 24, 3,  30, 22, 20, 15, 25, 17, 4,  8,
				31, 27, 13, 23, 21, 19, 16, 7,  26, 12, 18, 6,  11, 5,  10, 9
			};
	new
		cur;
	for (new i = 0; i != bits<MAX_PLAYERS>; ++i)
	{
		if ((cur = _:YSI_gGroupPlayers[group][i]))
		{
			// http://supertech.csail.mit.edu/papers/debruijn.pdf
			return (i * cellbits) + scDeBruijn[((cur & -cur) * 0x077CB531) >>> 27];
		}
	}
	return -1;
}

stock YSI_gAGroupFunc(Group:group, start)
{
	GROUP_FIX(group);
	if (!_Group_IsValid(group))
	{
		return -1;
	}
	static const
		scDeBruijn[] =
			{
				0,  1,  28, 2,  29, 14, 24, 3,  30, 22, 20, 15, 25, 17, 4,  8,
				31, 27, 13, 23, 21, 19, 16, 7,  26, 12, 18, 6,  11, 5,  10, 9
			};
	new
		cur,
		i = Bit_Slot(start);
	if ((cur = (_:YSI_gGroupPlayers[group][i] & (~((1 << (start + 1)) - 1)))))
	{
		return (i * cellbits) + scDeBruijn[((cur & -cur) * 0x077CB531) >>> 27];
	}
	++i;
	while (i != bits<MAX_PLAYERS>)
	{
		if ((cur = _:YSI_gGroupPlayers[group][i]))
		{
			return (i * cellbits) + scDeBruijn[((cur & -cur) * 0x077CB531) >>> 27];
		}
		++i;
	}
	return -1;
}

/*stock Group:operator-(Group:group, Group:playerid)
{
	Group_SetPlayer(group, playerid, false);
	return group;
}

stock Group:operator+(Group:group, playerid)
{
	Group_SetPlayer(group, playerid, false);
	return group;
}

stock Group:operator==(Group:group, playerid)
{
	return Group_GetPlayer(group, playerid);
}*/

#define YSI_gAGroup(%0)[%1] YSI_gAGroupFunc(%0,%1)

#define _YSIM_RESET_USER
#include <YSI\y_master>

#undef ALS_PREFIX
