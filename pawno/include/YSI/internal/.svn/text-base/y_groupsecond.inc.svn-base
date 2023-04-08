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
	
	#undef _inc_y_groupsecond
	
	// This is actually the second half of a function!
	//_GROUP_INIT(group);
	//_GROUP_MAKE_NAME<Group_...Init>(group);
	#if YSIM_HAS_MASTER
		#if YSIM_IS_CLIENT
		#else
			#if YSIM_IS_SERVER
				_GROUP_OPC_IS_CALLED(playerid);
			#else
				#if YSIM_IS_STUB
					#error y_groupsecond called with YSIM_IS_STUB.
				#else
					_GROUP_OPC_IS_CALLED(playerid);
				#endif
			#endif
		#endif
	#else
		_GROUP_OPC_IS_CALLED(playerid);
	#endif
	// This is also NOT a master controlled function as the group master may be
	// different to a system using the group system's master.
	#pragma tabsize 4
	_GROUP_OPC_OTHER_CALLED(playerid);
}

forward _GROUP_OPC_PUBLIC(playerid);

// This file contains generic code for setting all the stats to do with a single
// element type.  Groups can be defined for any element (classes, objects etc)
// and each one will specialise this file to give different functions.

#if !defined _GROUP_MAKE_NAME
	#error Please define _GROUP_MAKE_NAME before including y_groups.
#endif

#if !defined _GROUP_MAKE_LIMIT
	#error Please define _GROUP_MAKE_LIMIT before including y_groups.
#endif

// Start of the multi-use file.
static stock
	BitArray:_GROUP_GLOBAL_NAME<_GROUP_MAKE_LIMIT>,
	BitArray:_GROUP_GROUP_NAME[MAX_GROUPS]<_GROUP_MAKE_LIMIT>,
	BitArray:_GROUP_DEFAULTS<_:MAX_GROUPS + 1>,
	YSI_g_sNextUpdateFunc[32],
	YSI_g_sNextInitFunc[32],
	bool:YSI_g_sHasOPC = false;

// Initialise permissions for a new player based on the default settings.  This
// is one of the few places where direct master system intervention is required
// due to the horrible combination of function naming macros.
// TODO: Uncomment when the better y_hooks library is integrated.

_GROUP_OPC_OTHER_CALLED(playerid)
{
	if (YSI_g_sHasOPC) CallLocalFunction(#_GROUP_OPC_PUBLIC, "i", playerid);
}

#if YSIM_CLOUD
	_GROUP_OPC_IS_CALLED(playerid)<>
	{
		#pragma unused playerid
	}
	
	_GROUP_OPC_IS_CALLED(playerid)<_YCM:y>
#else
	stock _GROUP_OPC_IS_CALLED(playerid)
#endif
{
	P:3(#_GROUP_OPC_IS_CALLED " called in %d", _@);
	for (new j = 0; j != _GROUP_MAKE_LIMIT; ++j)
	{
		// Set and unset all the global items.
		_GROUP_SET_PLAYER(j, playerid, Bit_Get(_GROUP_GLOBAL_NAME, j));
		P:5(#_GROUP_SET_PLAYER ": Set %d %d %d", j, playerid, Bit_Get(_GROUP_GLOBAL_NAME, j));
	}
}

#if YSIM_HAS_MASTER
	#if YSIM_IS_CLIENT
		#define __GF<%0...%1>[%2](%3)<%4> stock _GROUP_MAKE_NAME<%0...%1>(%3)U@(8,YSIM_CALLER,_@),W@(#@#_GROUP_MAKE_NAME<%0...%1>,#%2#x,%4),U@(8,YSIM_CALLER,-1);stock _GROUP_MAKE_NAME<_%0...%1>(%3)
	#else
		#if YSIM_IS_SERVER
			#define __GF<%0...%1>[%2](%3)<%4> forward _GROUP_MAKE_NAME<@%0...%1>(%3);_GROUP_MAKE_NAME<@%0...%1>(%3)_GROUP_MAKE_NAME<%0...%1>(%4);_GROUP_MAKE_NAME<%0...%1>(%3)
		#else
			#if YSIM_IS_STUB
				#error y_groupsecond called with YSIM_IS_STUB.
			#else
				#define __GF<%0...%1>[%2](%3)<%4> forward _GROUP_MAKE_NAME<@%0...%1>(%3);_GROUP_MAKE_NAME<@%0...%1>(%3)<>{}_GROUP_MAKE_NAME<@%0...%1>(%3)<_YCM:y>_GROUP_MAKE_NAME<%0...%1>(%4);_GROUP_MAKE_NAME<%0...%1>(%3)<>Y@(),W@(#@#_GROUP_MAKE_NAME<%0...%1>,#%2#x,%4),T@();_GROUP_MAKE_NAME<%0...%1>(%3)<_YCM:y>
			#endif
		#endif
	#endif
#else
	#define __GF<%0...%1>[%2](%3)<%4> stock _GROUP_MAKE_NAME<%0...%1>(%3)
#endif

_GROUP_CREATE(group,idx);

#if YSIM_HAS_MASTER
	#if YSIM_IS_CLIENT
		// Note: not the same.
		_GROUP_MAKE_NAME<_yG@Init...>(group,idx)
	#else
		#if YSIM_IS_SERVER
			_GROUP_CREATE(group,idx)
		#else
			#if !YSIM_IS_STUB
				_GROUP_CREATE(group,idx)<>
				{
					P:3(#_GROUP_MAKE_NAME<@yG_Init...> " called in %d", _@);
					if (group == -1)
					{
						YSI_g_sHasOPC = funcidx(#_GROUP_OPC_PUBLIC) != -1;
						P:3(#_GROUP_OPC_PUBLIC " does%s exist", YSI_g_sHasOPC ? ("") : ("not"));
						new
							a = Scripting_GetPublic(idx >>> 16, YSI_g_sNextUpdateFunc, "@yG_Upd"),
							b = Scripting_GetPublic(idx & 0xFFFF, YSI_g_sNextInitFunc, "@yG_Init");
						if (b)
						{
							CallLocalFunction(YSI_g_sNextInitFunc, "ii", -1, (a << 16) | b);
						}
					}
				}
				
				_GROUP_CREATE(group,idx)<_YCM:y>
			#endif
		#endif
	#endif
#else
	_GROUP_CREATE(group,idx)
#endif
{
	P:3(#_GROUP_MAKE_NAME<@yG_Init...> " called in %d", _@);
	if (group == -1)
	{
		Bit_SetAll(_GROUP_GLOBAL_NAME, true, bits<_GROUP_MAKE_LIMIT>);
		Bit_Let(_GROUP_DEFAULTS, _:MAX_GROUPS);
		// Initialise the next item
		YSI_g_sHasOPC = funcidx(#_GROUP_OPC_PUBLIC) != -1;
		P:3(#_GROUP_OPC_PUBLIC " does%s exist", YSI_g_sHasOPC ? ("") : (" not"));
		new
			a = Scripting_GetPublic(idx >>> 16, YSI_g_sNextUpdateFunc, "@yG_Upd"),
			b = Scripting_GetPublic(idx & 0xFFFF, YSI_g_sNextInitFunc, "@yG_Init");
		if (b)
		{
			CallLocalFunction(YSI_g_sNextInitFunc, "ii", -1, (a << 16) | b);
		}
	}
	else if (group < _:MAX_GROUPS)
	{
		// This is called when a new group is created, it sets the default default
		// values - i.e. sets everything to true.
		Bit_SetAll(_GROUP_GROUP_NAME[Group:group], false, bits<_GROUP_MAKE_LIMIT>);
		Bit_Vet(_GROUP_DEFAULTS, group);
		if (YSI_g_sNextInitFunc[0])
		{
			CallLocalFunction(YSI_g_sNextInitFunc, "ii", group, -1);
		}
	}
}

#if !defined _YSI_GROUPS_FIRST_HALF
	forward bool:_GROUP_INITIALISE(x = _GROUP_MAKE_LIMIT);
#endif

stock bool:_GROUP_INITIALISE(x = _GROUP_MAKE_LIMIT) <YSI_has_groups:y>
{
	// A new item has been added to the system - update all players according to
	// the default settings for a group.
	//_GROUP_UPDATE_ALL(_GROUP_LOCAL_NAME);
	if (x != _GROUP_MAKE_LIMIT)
	{
		P:3(#_GROUP_INITIALISE "<YSI_has_groups:y> called in %d", _@);
		_GROUP_MAKE_NAME<Group_UpdateAll...>(x, true);
	}
	return true;
}

// Called to set all players to a new element.  Can ignore defaults for
// specialised setups such as classes.
__GF<Group_UpdateAll...>[i](_GROUP_LOCAL_NAME,bool:d)<_GROUP_LOCAL_NAME,d>
{
	// Set the permissions from the defaults for each groups.
	new
		s = Bit_Slot(_GROUP_LOCAL_NAME),
		Bit:m = Bit_Mask(_GROUP_LOCAL_NAME),
		Bit:v = ~m;
	if (d)
	{
		for (new Group:i; i != MAX_GROUPS; ++i)
		{
			if (Bit_Get(_GROUP_DEFAULTS, i)) _GROUP_GROUP_NAME[i][s] |= m;
			else _GROUP_GROUP_NAME[i][s] &= v;
		}
		// Set the default settings.
		if (Bit_Get(_GROUP_DEFAULTS, MAX_GROUPS)) _GROUP_GLOBAL_NAME[s] |= m;
		else _GROUP_GLOBAL_NAME[s] &= v;
		// Now update all the existing players.
		foreach (Player, i) _GROUP_MAKE_NAME<Group_UpdatePlayer...>(_GROUP_LOCAL_NAME, i);
	}
	else
	{
		P:3(#_GROUP_MAKE_NAME<Group_UpdateAll...> " called as 0");
		for (new Group:i; i != MAX_GROUPS; ++i) _GROUP_GROUP_NAME[i][s] &= v;
		_GROUP_GLOBAL_NAME[s] &= v;
	}
}

static stock _GROUP_MAKE_NAME<Group_UpdatePlayer...>(_GROUP_LOCAL_NAME,playerid)
{
	if (Bit_Get(_GROUP_GLOBAL_NAME, _GROUP_LOCAL_NAME))
	{
		_GROUP_SET_PLAYER(_GROUP_LOCAL_NAME, playerid, true);
		return;
	}
	new
		ps = Bit_Slot(playerid),
		Bit:pm = Bit_Mask(playerid),
		es = Bit_Slot(_GROUP_LOCAL_NAME),
		Bit:em = Bit_Mask(_GROUP_LOCAL_NAME);
	for (new Group:i; i != MAX_GROUPS; ++i)
	{
		if (_Group_IsActive(i) && YSI_gGroupPlayers[i][ps] & pm && _GROUP_GROUP_NAME[i][es] & em)
		//if (Group_IsActive(i) && Group_HasPlayer(i, playerid) && Bit_Get(_GROUP_GROUP_NAME[i], _GROUP_LOCAL_NAME))
		{
			_GROUP_SET_PLAYER(_GROUP_LOCAL_NAME, playerid, true);
			return;
		}
	}
	_GROUP_SET_PLAYER(_GROUP_LOCAL_NAME, playerid, false);
}

_GROUP_UPDATE_PLAYER(playerid, group, set);

#if YSIM_HAS_MASTER
	#if YSIM_IS_CLIENT
		// Note: not the same.
		_GROUP_MAKE_NAME<_yG@Upd...>(playerid, group, set)
	#else
		#if YSIM_IS_SERVER
			_GROUP_UPDATE_PLAYER(playerid, group, set)
		#else
			#if !YSIM_IS_STUB
				_GROUP_UPDATE_PLAYER(playerid, group, set)<>
				{
					if (YSI_g_sNextUpdateFunc[0])
					{
						CallLocalFunction(YSI_g_sNextUpdateFunc, "iii", playerid, group, set);
					}
				}
				
				_GROUP_UPDATE_PLAYER(playerid, group, set)<_YCM:y>
			#endif
		#endif
	#endif
#else
	_GROUP_UPDATE_PLAYER(playerid, group, set)
#endif
{
	if (set)
	{
		// Joined a group - add everything they will need.
		for (new j = 0; j != _GROUP_MAKE_LIMIT; ++j)
		{
			if (Bit_Get(_GROUP_GROUP_NAME[group], j))
			{
				_GROUP_SET_PLAYER(j, playerid, true);
			}
		}
	}
	else
	{
		// Left a group - full update.
		for (new j = 0; j != _GROUP_MAKE_LIMIT; ++j)
		{
			_GROUP_MAKE_NAME<Group_UpdatePlayer...>(j, playerid);
		}
	}
}

__GF<Group_Set...Default>[ii](Group:g,bool:s)<g,s>
{
	GROUP_FIX(g);
	if (g == GROUP_GLOBAL & ~GROUP_MASK)
	{
		_GROUP_MAKE_NAME<Group_SetGlobal...Default>(s);
	}
	else if (_Group_IsValid(g))
	{
		Bit_SetAll(_GROUP_GROUP_NAME[g], s, bits<_GROUP_MAKE_LIMIT>);
		if (s)
		{
			Bit_Let(_GROUP_DEFAULTS, _:g);
			foreach (Player, i)
			{
				if (_Group_HasPlayer(g, i))
				{
					for (new j = 0; j != _GROUP_MAKE_LIMIT; ++j)
					{
						_GROUP_SET_PLAYER(j, i, true);
					}
				}
			}
		}
		else
		{
			Bit_Vet(_GROUP_DEFAULTS, _:g);
			foreach (Player, i)
			{
				if (_Group_HasPlayer(g, i))
				{
					for (new j = 0; j != _GROUP_MAKE_LIMIT; ++j)
					{
						_GROUP_MAKE_NAME<Group_UpdatePlayer...>(j, i);
					}
				}
			}
		}
	}
}

__GF<Group_SetGlobal...Default>[i](bool:s)<s>
{
	Bit_SetAll(_GROUP_GLOBAL_NAME, s, bits<_GROUP_MAKE_LIMIT>);
	if (s)
	{
		Bit_Let(_GROUP_DEFAULTS, _:MAX_GROUPS);
		foreach (Player, i)
		{
			for (new j = 0; j != _GROUP_MAKE_LIMIT; ++j)
			{
				_GROUP_SET_PLAYER(j, i, true);
			}
		}
	}
	else
	{
		Bit_Vet(_GROUP_DEFAULTS, _:MAX_GROUPS);
		foreach (Player, i)
		{
			for (new j = 0; j != _GROUP_MAKE_LIMIT; ++j)
			{
				_GROUP_MAKE_NAME<Group_UpdatePlayer...>(j, i);
			}
		}
	}
}

__GF<Group_SetGlobal...>[ii](_GROUP_LOCAL_NAME,bool:s)<_GROUP_LOCAL_NAME,s>
{
	// Set wether the global group can use this item.
	//Bit_Set(_GROUP_GLOBAL_NAME, _GROUP_LOCAL_NAME, set, bits<_GROUP_MAKE_LIMIT>);
	if (s)
	{
		Bit_Let(_GROUP_GLOBAL_NAME, _GROUP_LOCAL_NAME);
		foreach (Player, i)
		{
			_GROUP_SET_PLAYER(_GROUP_LOCAL_NAME, i, true);
		}
	}
	else
	{
		Bit_Vet(_GROUP_GLOBAL_NAME, _GROUP_LOCAL_NAME);
		foreach (Player, i)
		{
			_GROUP_MAKE_NAME<Group_UpdatePlayer...>(_GROUP_LOCAL_NAME, i);
		}
	}
}

__GF<Group_Set...>[iii](Group:g,_GROUP_LOCAL_NAME,bool:s)<g,_GROUP_LOCAL_NAME,s>
{
	// Set wether a group can use this item.
	if (0 <= _GROUP_LOCAL_NAME < _GROUP_MAKE_LIMIT)
	{
		GROUP_FIX(g);
		if (g == GROUP_GLOBAL & ~GROUP_MASK)
		{
			//_GROUP_GLOBAL_FUNC(_GROUP_LOCAL_NAME, set);
			_GROUP_MAKE_NAME<Group_SetGlobal...>(_GROUP_LOCAL_NAME, s);
		}
		else if (_Group_IsValid(g))
		{
			//Bit_Set(_GROUP_GROUP_NAME[group], _GROUP_LOCAL_NAME, set, bits<_GROUP_MAKE_LIMIT>);
			if (s)
			{
				Bit_Let(_GROUP_GROUP_NAME[g], _GROUP_LOCAL_NAME);
				foreach (Player, i)
				{
					if (_Group_HasPlayer(g, i))
					{
						_GROUP_SET_PLAYER(_GROUP_LOCAL_NAME, i, true);
					}
				}
			}
			else
			{
				Bit_Vet(_GROUP_GROUP_NAME[g], _GROUP_LOCAL_NAME);
				foreach (Player, i)
				{
					if (_Group_HasPlayer(g, i))
					{
						//_GROUP_UPDATE(_GROUP_LOCAL_NAME, i);
						_GROUP_MAKE_NAME<Group_UpdatePlayer...>(_GROUP_LOCAL_NAME, i);
					}
				}
			}
		}
	}
}

#undef __GF
