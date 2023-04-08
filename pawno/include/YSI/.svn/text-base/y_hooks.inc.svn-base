/*----------------------------------------------------------------------------*-
					==============================
					 y_hooks - Hook any callback!
					==============================
Description:
	Automatically hooks any callbacks with a very simple syntax.
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
#include <a_samp>

#include <YSI\y_scripting>
#include <YSI\y_utils>

#define ALS_PREFIX S@@

#include <YSI\y_als>
#include <YSI\y_stringhash>
#include <YSI\internal\y_shortfunc>

#include <YSI\y_debug>

//#define Hook:%1_On%2(%3) forward %1_@%2(%3); public %1_@%2(%3)
#define Hook:%1_On%2(%3) @yH_%2_%1(%3);@yH_%2_%1(%3)

#define HOOK_FUNC_SEARCH                 (Scripting_FastString('@', 'y', 'H', '_'))

#define HOOKS_INSERT<%0> tmp=_:gs_aHookFunctionPointers[ALS_On%0],gs_aHookFunctionPointers[ALS_On%0]=Bit:((tmp!=_:-1?tmp&0xFFFF:idx-1)|idx<<16);

//#define HOOKS_CALL<%0,%1>(%2) new t=_:gs_aHookFunctionPointers[ALS_On%0];if(t!=-1){new e=t>>>16;t&=0xFFFF;do t=Scripting_GetPublic(t,gs_szFunctionBuffer,"@yH_"#%0),P@(gs_szFunctionBuffer,#%1#x,%2);while(t!=e);}
#define HOOKS_C_INT<%0,%1>(%2) new t=_:gs_aHookFunctionPointers[ALS_On%0];if(t!=-1){new e=t>>>16;t&=0xFFFF;do t=Scripting_GetPublic(t,gs_szFunctionBuffer,"@yH_"#%0),P@(gs_szFunctionBuffer,#%1#x,%2);while(t!=e);}

#define HUK_C_GameModeInit              HOOKS_C_INT<GameModeInit             ,>()
#define HUK_C_GameModeExit              HOOKS_C_INT<GameModeExit             ,>()
#define HUK_C_FilterScriptInit          HOOKS_C_INT<FilterScriptInit         ,>()
#define HUK_C_FilterScriptExit          HOOKS_C_INT<FilterScriptExit         ,>()
#define HUK_C_PlayerConnect             HOOKS_C_INT<PlayerConnect            ,i>(playerid)
#define HUK_C_PlayerDisconnect          HOOKS_C_INT<PlayerDisconnect         ,ii>(playerid,reason)
#define HUK_C_PlayerSpawn               HOOKS_C_INT<PlayerSpawn              ,i>(playerid)
#define HUK_C_PlayerDeath               HOOKS_C_INT<PlayerDeath              ,iii>(playerid,killerid,reason)
#define HUK_C_VehicleSpawn              HOOKS_C_INT<VehicleSpawn             ,i>(vehicleid)
#define HUK_C_VehicleDeath              HOOKS_C_INT<VehicleDeath             ,ii>(vehicleid,killerid)
#define HUK_C_PlayerText                HOOKS_C_INT<PlayerText               ,is>(playerid,text)
#define HUK_C_PlayerCommandText         HOOKS_C_INT<PlayerCommandText        ,is>(playerid,cmdtext)
#define HUK_C_PlayerRequestClass        HOOKS_C_INT<PlayerRequestClass       ,ii>(playerid,classid)
#define HUK_C_PlayerEnterVehicle        HOOKS_C_INT<PlayerEnterVehicle       ,iii>(playerid,vehicleid,ispassenger)
#define HUK_C_PlayerExitVehicle         HOOKS_C_INT<PlayerExitVehicle        ,ii>(playerid,vehicleid)
#define HUK_C_PlayerStateChange         HOOKS_C_INT<PlayerStateChange        ,iii>(playerid,newstate,oldstate)
#define HUK_C_PlayerEnterCheckpoint     HOOKS_C_INT<PlayerEnterCheckpoint    ,i>(playerid)
#define HUK_C_PlayerLeaveCheckpoint     HOOKS_C_INT<PlayerLeaveCheckpoint    ,i>(playerid)
#define HUK_C_PlayerEnterRaceCheckpoint HOOKS_C_INT<PlayerEnterRaceCheckpoint,i>(playerid)
#define HUK_C_PlayerLeaveRaceCheckpoint HOOKS_C_INT<PlayerLeaveRaceCheckpoint,i>(playerid)
#define HUK_C_RconCommand               HOOKS_C_INT<RconCommand              ,s>(cmd)
#define HUK_C_PlayerRequestSpawn        HOOKS_C_INT<PlayerRequestSpawn       ,i>(playerid)
#define HUK_C_ObjectMoved               HOOKS_C_INT<ObjectMoved              ,i>(objectid)
#define HUK_C_PlayerObjectMoved         HOOKS_C_INT<PlayerObjectMoved        ,ii>(playerid,objectid)
#define HUK_C_PlayerPickUpPickup        HOOKS_C_INT<PlayerPickUpPickup       ,ii>(playerid,pickupid)
#define HUK_C_VehicleMod                HOOKS_C_INT<VehicleMod               ,iii>(playerid,vehicleid,componentid)
#define HUK_C_EnterExitModShop          HOOKS_C_INT<EnterExitModShop         ,iii>(playerid,enterexit,interiorid)
#define HUK_C_VehiclePaintjob           HOOKS_C_INT<VehiclePaintjob          ,iii>(playerid,vehicleid,paintjobid)
#define HUK_C_VehicleRespray            HOOKS_C_INT<VehicleRespray           ,iiii>(playerid,vehicleid,color1,color2)
#define HUK_C_VehicleDamageStatusUpdate HOOKS_C_INT<VehicleDamageStatusUpdate,ii>(playerid,playerid)
#define HUK_C_PlayerSelectedMenuRow     HOOKS_C_INT<PlayerSelectedMenuRow    ,ii>(playerid,row)
#define HUK_C_PlayerExitedMenu          HOOKS_C_INT<PlayerExitedMenu         ,i>(playerid)
#define HUK_C_PlayerInteriorChange      HOOKS_C_INT<PlayerInteriorChange     ,iii>(playerid,newinteriorid,oldinteriorid)
#define HUK_C_PlayerKeyStateChange      HOOKS_C_INT<PlayerKeyStateChange     ,iii>(playerid,newkeys,oldkeys)
#define HUK_C_RconLoginAttempt          HOOKS_C_INT<RconLoginAttempt         ,ssi>(ip,password,success)
#define HUK_C_PlayerUpdate              HOOKS_C_INT<PlayerUpdate             ,i>(playerid)
#define HUK_C_PlayerStreamIn            HOOKS_C_INT<PlayerStreamIn           ,ii>(playerid,forplayerid)
#define HUK_C_PlayerStreamOut           HOOKS_C_INT<PlayerStreamOut          ,ii>(playerid,forplayerid)
#define HUK_C_VehicleStreamIn           HOOKS_C_INT<VehicleStreamIn          ,ii>(vehicleid,forplayerid)
#define HUK_C_VehicleStreamOut          HOOKS_C_INT<VehicleStreamOut         ,ii>(vehicleid,forplayerid)
//#define HUK_C_DialogResponse            HOOKS_C_INT<DialogResponse           ,ii>(playerid,dialogid,response,listitem,inputtext)
#define HUK_C_PlayerClickPlayer         HOOKS_C_INT<PlayerClickPlayer        ,iii>(playerid,clickedplayerid,source)
//#define HUK_C_DialogResponse if(inputtext[0]){HOOKS_C_INT<DialogResponse,iiiis>(playerid,dialogid,response,listitem,inputtext)}else{HOOKS_C_INT<DialogResponse,iiiis>(playerid,dialogid,response,listitem,NULL)}

//#define CALL_WRAPPER<%0> HUK_C_%0 ALS_CALL_%0
#define HOOKS_CALL<%0> HUK_C_%0 ALS_C_%0

#define HOOKS_MAX_UPDATES               (4)

static
	gs_aHookFunctionPointers[ALS] = {Bit:-1, ...},
	gs_szFunctionBuffer[32],
	gs_aOnPlayerUpdateHooks[HOOKS_MAX_UPDATES] = {-1, ...}/*,
	gs_pCodeStart*/;

ALS_DATA<>

/*static Hooks_GetNext(&idx)
{
	idx = Scripting_GetPublicFast(idx, gs_szFunctionBuffer, HOOK_FUNC_SEARCH);
	if (idx == 0)
	{
		return -1;
	}
	return YHash(gs_szFunctionBuffer[4], true, hash_bernstein, strfind(gs_szFunctionBuffer[4], "_"));
}*/

/*----------------------------------------------------------------------------*-
Function:
	Hooks_GenFuncList
Params:
	-
Return:
	-
Notes:
	Generates a set of data describing every callback for speed later.
-*----------------------------------------------------------------------------*/

static Hooks_GenFuncList()
{
	// Check for old style hooks using the new ALS library.
	ALS_DETECT<GameModeInit>
	#if 1
	ALS_DETECT<GameModeExit>
	ALS_DETECT<FilterScriptInit>
	ALS_DETECT<FilterScriptExit>
	ALS_DETECT<PlayerConnect>
	ALS_DETECT<PlayerDisconnect>
	ALS_DETECT<PlayerSpawn>
	ALS_DETECT<PlayerDeath>
	ALS_DETECT<VehicleSpawn>
	ALS_DETECT<VehicleDeath>
	ALS_DETECT<PlayerText>
	ALS_DETECT<PlayerCommandText>
	ALS_DETECT<PlayerRequestClass>
	ALS_DETECT<PlayerEnterVehicle>
	ALS_DETECT<PlayerExitVehicle>
	ALS_DETECT<PlayerStateChange>
	ALS_DETECT<PlayerEnterCheckpoint>
	ALS_DETECT<PlayerLeaveCheckpoint>
	ALS_DETECT<PlayerEnterRaceCheckpoint>
	ALS_DETECT<PlayerLeaveRaceCheckpoint>
	ALS_DETECT<RconCommand>
	ALS_DETECT<PlayerRequestSpawn>
	ALS_DETECT<ObjectMoved>
	ALS_DETECT<PlayerObjectMoved>
	ALS_DETECT<PlayerPickUpPickup>
	ALS_DETECT<VehicleMod>
	ALS_DETECT<EnterExitModShop>
	ALS_DETECT<VehiclePaintjob>
	ALS_DETECT<VehicleRespray>
	ALS_DETECT<VehicleDamageStatusUpdate>
	ALS_DETECT<PlayerSelectedMenuRow>
	ALS_DETECT<PlayerExitedMenu>
	ALS_DETECT<PlayerInteriorChange>
	ALS_DETECT<PlayerKeyStateChange>
	ALS_DETECT<RconLoginAttempt>
	ALS_DETECT<PlayerUpdate>
	ALS_DETECT<PlayerStreamIn>
	ALS_DETECT<PlayerStreamOut>
	ALS_DETECT<VehicleStreamIn>
	ALS_DETECT<VehicleStreamOut>
	ALS_DETECT<DialogResponse>
	ALS_DETECT<PlayerClickPlayer>
	#endif
	// Check for new style hooks.  This gets the bounds of functions, to make
	// later calls very slightly faster!
	new
		idx = 0,
		tmp;
	// For some reason compile time initialisation didn't work...
	for (new ALS:i; i != ALS; ++i)
	{
		gs_aHookFunctionPointers[i] = -1;
	}
	for ( ; ; )
	{
		idx = Scripting_GetPublicFast(idx, gs_szFunctionBuffer, HOOK_FUNC_SEARCH);
		if (idx == 0)
		{
			break;
		}
		//return YHash(gs_szFunctionBuffer[4], true, bernstein, strfind(gs_szFunctionBuffer[4], "_"));
		//switch (Hooks_GetNext(idx))
		switch (YHash(gs_szFunctionBuffer[4], true, hash_bernstein, strfind(gs_szFunctionBuffer[4], "_")))
		{
			case _H(G,a,m,e,M,o,d,e,I,n,i,t):
				HOOKS_INSERT<GameModeInit>
			case _H(G,a,m,e,M,o,d,e,E,x,i,t):
				HOOKS_INSERT<GameModeExit>
			case _H(F,i,l,t,e,r,S,c,r,i,p,t,I,n,i,t):
				HOOKS_INSERT<FilterScriptInit>
			case _H(F,i,l,t,e,r,S,c,r,i,p,t,E,x,i,t):
				HOOKS_INSERT<FilterScriptExit>
			case _H(P,l,a,y,e,r,C,o,n,n,e,c,t):
				HOOKS_INSERT<PlayerConnect>
			case _H(P,l,a,y,e,r,D,i,s,c,o,n,n,e,c,t):
				HOOKS_INSERT<PlayerDisconnect>
			case _H(P,l,a,y,e,r,S,p,a,w,n):
				HOOKS_INSERT<PlayerSpawn>
			case _H(P,l,a,y,e,r,D,e,a,t,h):
				HOOKS_INSERT<PlayerDeath>
			case _H(V,e,h,i,c,l,e,S,p,a,w,n):
				HOOKS_INSERT<VehicleSpawn>
			case _H(V,e,h,i,c,l,e,D,e,a,t,h):
				HOOKS_INSERT<VehicleDeath>
			case _H(P,l,a,y,e,r,T,e,x,t):
				HOOKS_INSERT<PlayerText>
			case _H(P,l,a,y,e,r,C,o,m,m,a,n,d,T,e,x,t):
				HOOKS_INSERT<PlayerCommandText>
			case _H(P,l,a,y,e,r,R,e,q,u,e,s,t,C,l,a,s,s):
				HOOKS_INSERT<PlayerRequestClass>
			case _H(P,l,a,y,e,r,E,n,t,e,r,V,e,h,i,c,l,e,):
				HOOKS_INSERT<PlayerEnterVehicle>
			case _H(P,l,a,y,e,r,E,x,i,t,V,e,h,i,c,l,e,):
				HOOKS_INSERT<PlayerExitVehicle>
			case _H(P,l,a,y,e,r,S,t,a,t,e,C,h,a,n,g,e):
				HOOKS_INSERT<PlayerStateChange>
			case _H(P,l,a,y,e,r,E,n,t,e,r,C,h,e,c,k,p,o,i,n,t), _H(P,l,a,y,e,r,E,n,t,e,r,C,P):
				HOOKS_INSERT<PlayerEnterCheckpoint>
			case _H(P,l,a,y,e,r,L,e,a,v,e,C,h,e,c,k,p,o,i,n,t), _H(P,l,a,y,e,r,L,e,a,v,e,C,P):
				HOOKS_INSERT<PlayerLeaveCheckpoint>
			case _H(P,l,a,y,e,r,E,n,t,e,r,R,a,c,e,C,h,e,c,k,p,o,i,n,t), _H(P,l,a,y,e,r,E,n,t,e,r,R,C,P):
				HOOKS_INSERT<PlayerEnterRaceCheckpoint>
			case _H(P,l,a,y,e,r,L,e,a,v,e,R,a,c,e,C,h,e,c,k,p,o,i,n,t), _H(P,l,a,y,e,r,L,e,a,v,e,R,C,P):
				HOOKS_INSERT<PlayerLeaveRaceCheckpoint>
			case _H(R,c,o,n,C,o,m,m,a,n,d):
				HOOKS_INSERT<RconCommand>
			case _H(P,l,a,y,e,r,R,e,q,u,e,s,t,S,p,a,w,n):
				HOOKS_INSERT<PlayerRequestSpawn>
			case _H(O,b,j,e,c,t,M,o,v,e,d):
				HOOKS_INSERT<ObjectMoved>
			case _H(P,l,a,y,e,r,O,b,j,e,c,t,M,o,v,e,d):
				HOOKS_INSERT<PlayerObjectMoved>
			case _H(P,l,a,y,e,r,P,i,c,k,U,p,P,i,c,k,u,p):
				HOOKS_INSERT<PlayerPickUpPickup>
			case _H(V,e,h,i,c,l,e,M,o,d):
				HOOKS_INSERT<VehicleMod>
			case _H(E,n,t,e,r,E,x,i,t,M,o,d,S,h,o,p):
				HOOKS_INSERT<EnterExitModShop>
			case _H(V,e,h,i,c,l,e,P,a,i,n,t,j,o,b):
				HOOKS_INSERT<VehiclePaintjob>
			case _H(V,e,h,i,c,l,e,R,e,s,p,r,a,y):
				HOOKS_INSERT<VehicleRespray>
			case _H(V,e,h,i,c,l,e,D,a,m,a,g,e,S,t,a,t,u,s,U,p,d,a,t,e), _H(V,e,h,i,c,l,e,D,a,m,a,g,e,U,p,d,a,t,e):
				HOOKS_INSERT<VehicleDamageStatusUpdate>
			case _H(P,l,a,y,e,r,S,e,l,e,c,t,e,d,M,e,n,u,R,o,w), _H(P,l,a,y,e,r,S,e,l,e,c,t,e,d,M,e,n,u):
				HOOKS_INSERT<PlayerSelectedMenuRow>
			case _H(P,l,a,y,e,r,E,x,i,t,e,d,M,e,n,u):
				HOOKS_INSERT<PlayerExitedMenu>
			case _H(P,l,a,y,e,r,I,n,t,e,r,i,o,r,C,h,a,n,g,e):
				HOOKS_INSERT<PlayerInteriorChange>
			case _H(P,l,a,y,e,r,K,e,y,S,t,a,t,e,C,h,a,n,g,e):
				HOOKS_INSERT<PlayerKeyStateChange>
			case _H(R,c,o,n,L,o,g,i,n,A,t,t,e,m,p,t):
				HOOKS_INSERT<RconLoginAttempt>
			case _H(P,l,a,y,e,r,S,t,r,e,a,m,I,n):
				HOOKS_INSERT<PlayerStreamIn>
			case _H(P,l,a,y,e,r,S,t,r,e,a,m,O,u,t):
				HOOKS_INSERT<PlayerStreamOut>
			case _H(V,e,h,i,c,l,e,S,t,r,e,a,m,I,n):
				HOOKS_INSERT<VehicleStreamIn>
			case _H(V,e,h,i,c,l,e,S,t,r,e,a,m,O,u,t):
				HOOKS_INSERT<VehicleStreamOut>
			case _H(D,i,a,l,o,g,R,e,s,p,o,n,s,e):
				HOOKS_INSERT<DialogResponse>
			case _H(P,l,a,y,e,r,C,l,i,c,k,P,l,a,y,e,r):
				HOOKS_INSERT<PlayerClickPlayer>
			case -1:
				// Do nothing - end condition.
				break;
			case _H(P,l,a,y,e,r,U,p,d,a,t,e):
			{
				//HOOKS_INSERT<PlayerUpdate>
				// This uses different code to improve speed a little bit.
				tmp = _:gs_aHookFunctionPointers[ALS_OnPlayerUpdate];
				if (tmp == -1)
				{
					gs_aHookFunctionPointers[ALS_OnPlayerUpdate] = Bit:0;
					// Save the index of the first OnPlayerUpdate function.
					gs_aOnPlayerUpdateHooks[0] = idx - 1;
					//gs_aOnPlayerUpdateHooks[0] = Scripting_GetPublicPointer(gs_szFunctionBuffer);
				}
				else
				{
					// f = First, the upper limit.
					// s = Second, the lower limit.
					// Note that this only supports 65535 public functions, but
					// I suspect the compiler may get a little upset before you
					// reach that number - and if it doesn't you're going to
					// end up with a HUGE AMX!
					// f should always be larger than s in a normal system, even
					// if it's only 1 larger.
					new
						s = tmp & 0xFFFF;
					if (tmp & 0xFFFF0000)
					{
						// Given up counting - too many for quick
						// resolution.
						gs_aHookFunctionPointers[ALS_OnPlayerUpdate] = Bit:(s | idx << 16);
					}
					else
					{
						// Counting.
						if (++s == HOOKS_MAX_UPDATES)
						{
							// Reached the limit of the number of quick hooks
							// for OnPlayerUpdate supported.
							gs_aHookFunctionPointers[ALS_OnPlayerUpdate] = Bit:(idx - 1 | idx << 16);
						}
						else
						{
							gs_aOnPlayerUpdateHooks[s] = idx - 1;
							//gs_aOnPlayerUpdateHooks[s] = Scripting_GetPublicPointer(gs_szFunctionBuffer);
							gs_aHookFunctionPointers[ALS_OnPlayerUpdate] = Bit:s;
						}
					}
				}
				//gs_aHookFunctionPointers[ALS_OnPlayerUpdate] = Bit:((tmp!=_:-1?tmp&0xFFFF:idx-1)|idx<<16);
			}
		}
	}
	// Now, skip functions we don't need...  This is actually self modifying
	// code, so if you don't use any of the Hook: features, they are never even
	// called.  The functionality of this script depends entirely on the rest of
	// the script.  This can't be made in to a macro because #OnWhatever needs
	// to stringise the value in the current define if it exists, whereas doing
	// #On%0 would just make a string of "OnWhatever".
	if (gs_aHookFunctionPointers[ALS_OnGameModeInit] == Bit:-1) Scripting_RedirectPublic(#OnGameModeInit, Scripting_GetPublicPointer("S@@_OnGameModeInit"));
	// Now the same again.
	#if 1
	if (gs_aHookFunctionPointers[ALS_OnGameModeExit] == Bit:-1) Scripting_RedirectPublic(#OnGameModeExit, Scripting_GetPublicPointer("S@@_OnGameModeExit"));
	if (gs_aHookFunctionPointers[ALS_OnFilterScriptInit] == Bit:-1) Scripting_RedirectPublic(#OnFilterScriptInit, Scripting_GetPublicPointer("S@@_OnFilterScriptInit"));
	if (gs_aHookFunctionPointers[ALS_OnFilterScriptExit] == Bit:-1) Scripting_RedirectPublic(#OnFilterScriptExit, Scripting_GetPublicPointer("S@@_OnFilterScriptExit"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerConnect] == Bit:-1) Scripting_RedirectPublic(#OnPlayerConnect, Scripting_GetPublicPointer("S@@_OnPlayerConnect"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerDisconnect] == Bit:-1) Scripting_RedirectPublic(#OnPlayerDisconnect, Scripting_GetPublicPointer("S@@_OnPlayerDisconnect"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerSpawn] == Bit:-1) Scripting_RedirectPublic(#OnPlayerSpawn, Scripting_GetPublicPointer("S@@_OnPlayerSpawn"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerDeath] == Bit:-1) Scripting_RedirectPublic(#OnPlayerDeath, Scripting_GetPublicPointer("S@@_OnPlayerDeath"));
	if (gs_aHookFunctionPointers[ALS_OnVehicleSpawn] == Bit:-1) Scripting_RedirectPublic(#OnVehicleSpawn, Scripting_GetPublicPointer("S@@_OnVehicleSpawn"));
	if (gs_aHookFunctionPointers[ALS_OnVehicleDeath] == Bit:-1) Scripting_RedirectPublic(#OnVehicleDeath, Scripting_GetPublicPointer("S@@_OnVehicleDeath"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerText] == Bit:-1) Scripting_RedirectPublic(#OnPlayerText, Scripting_GetPublicPointer("S@@_OnPlayerText"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerCommandText] == Bit:-1) Scripting_RedirectPublic(#OnPlayerCommandText, Scripting_GetPublicPointer("S@@_OnPlayerCommandText"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerRequestClass] == Bit:-1) Scripting_RedirectPublic(#OnPlayerRequestClass, Scripting_GetPublicPointer("S@@_OnPlayerRequestClass"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerEnterVehicle] == Bit:-1) Scripting_RedirectPublic(#OnPlayerEnterVehicle, Scripting_GetPublicPointer("S@@_OnPlayerEnterVehicle"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerExitVehicle] == Bit:-1) Scripting_RedirectPublic(#OnPlayerExitVehicle, Scripting_GetPublicPointer("S@@_OnPlayerExitVehicle"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerStateChange] == Bit:-1) Scripting_RedirectPublic(#OnPlayerStateChange, Scripting_GetPublicPointer("S@@_OnPlayerStateChange"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerEnterCheckpoint] == Bit:-1) Scripting_RedirectPublic(#OnPlayerEnterCheckpoint, Scripting_GetPublicPointer("S@@_OnPlayerEnterCheckpoint"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerLeaveCheckpoint] == Bit:-1) Scripting_RedirectPublic(#OnPlayerLeaveCheckpoint, Scripting_GetPublicPointer("S@@_OnPlayerLeaveCheckpoint"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerEnterRaceCheckpoint] == Bit:-1) Scripting_RedirectPublic(#OnPlayerEnterRaceCheckpoint, Scripting_GetPublicPointer("S@@_OnPlayerEnterRaceCheckpoint"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerLeaveRaceCheckpoint] == Bit:-1) Scripting_RedirectPublic(#OnPlayerLeaveRaceCheckpoint, Scripting_GetPublicPointer("S@@_OnPlayerLeaveRaceCheckpoint"));
	if (gs_aHookFunctionPointers[ALS_OnRconCommand] == Bit:-1) Scripting_RedirectPublic(#OnRconCommand, Scripting_GetPublicPointer("S@@_OnRconCommand"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerRequestSpawn] == Bit:-1) Scripting_RedirectPublic(#OnPlayerRequestSpawn, Scripting_GetPublicPointer("S@@_OnPlayerRequestSpawn"));
	if (gs_aHookFunctionPointers[ALS_OnObjectMoved] == Bit:-1) Scripting_RedirectPublic(#OnObjectMoved, Scripting_GetPublicPointer("S@@_OnObjectMoved"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerObjectMoved] == Bit:-1) Scripting_RedirectPublic(#OnPlayerObjectMoved, Scripting_GetPublicPointer("S@@_OnPlayerObjectMoved"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerPickUpPickup] == Bit:-1) Scripting_RedirectPublic(#OnPlayerPickUpPickup, Scripting_GetPublicPointer("S@@_OnPlayerPickUpPickup"));
	if (gs_aHookFunctionPointers[ALS_OnVehicleMod] == Bit:-1) Scripting_RedirectPublic(#OnVehicleMod, Scripting_GetPublicPointer("S@@_OnVehicleMod"));
	if (gs_aHookFunctionPointers[ALS_OnEnterExitModShop] == Bit:-1) Scripting_RedirectPublic(#OnEnterExitModShop, Scripting_GetPublicPointer("S@@_OnEnterExitModShop"));
	if (gs_aHookFunctionPointers[ALS_OnVehiclePaintjob] == Bit:-1) Scripting_RedirectPublic(#OnVehiclePaintjob, Scripting_GetPublicPointer("S@@_OnVehiclePaintjob"));
	if (gs_aHookFunctionPointers[ALS_OnVehicleRespray] == Bit:-1) Scripting_RedirectPublic(#OnVehicleRespray, Scripting_GetPublicPointer("S@@_OnVehicleRespray"));
	if (gs_aHookFunctionPointers[ALS_OnVehicleDamageStatusUpdate] == Bit:-1) Scripting_RedirectPublic(#OnVehicleDamageStatusUpdate, Scripting_GetPublicPointer("S@@_OnVehicleDamageStatusUpdate"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerSelectedMenuRow] == Bit:-1) Scripting_RedirectPublic(#OnPlayerSelectedMenuRow, Scripting_GetPublicPointer("S@@_OnPlayerSelectedMenuRow"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerExitedMenu] == Bit:-1) Scripting_RedirectPublic(#OnPlayerExitedMenu, Scripting_GetPublicPointer("S@@_OnPlayerExitedMenu"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerInteriorChange] == Bit:-1) Scripting_RedirectPublic(#OnPlayerInteriorChange, Scripting_GetPublicPointer("S@@_OnPlayerInteriorChange"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerKeyStateChange] == Bit:-1) Scripting_RedirectPublic(#OnPlayerKeyStateChange, Scripting_GetPublicPointer("S@@_OnPlayerKeyStateChange"));
	if (gs_aHookFunctionPointers[ALS_OnRconLoginAttempt] == Bit:-1) Scripting_RedirectPublic(#OnRconLoginAttempt, Scripting_GetPublicPointer("S@@_OnRconLoginAttempt"));
	//if (gs_aHookFunctionPointers[ALS_OnPlayerUpdate] == Bit:-1) Scripting_RedirectPublic(#OnPlayerUpdate, Scripting_GetPublicPointer("S@@_OnPlayerUpdate"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerStreamIn] == Bit:-1) Scripting_RedirectPublic(#OnPlayerStreamIn, Scripting_GetPublicPointer("S@@_OnPlayerStreamIn"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerStreamOut] == Bit:-1) Scripting_RedirectPublic(#OnPlayerStreamOut, Scripting_GetPublicPointer("S@@_OnPlayerStreamOut"));
	if (gs_aHookFunctionPointers[ALS_OnVehicleStreamIn] == Bit:-1) Scripting_RedirectPublic(#OnVehicleStreamIn, Scripting_GetPublicPointer("S@@_OnVehicleStreamIn"));
	if (gs_aHookFunctionPointers[ALS_OnVehicleStreamOut] == Bit:-1) Scripting_RedirectPublic(#OnVehicleStreamOut, Scripting_GetPublicPointer("S@@_OnVehicleStreamOut"));
	if (gs_aHookFunctionPointers[ALS_OnDialogResponse] == Bit:-1) Scripting_RedirectPublic(#OnDialogResponse, Scripting_GetPublicPointer("S@@_OnDialogResponse"));
	if (gs_aHookFunctionPointers[ALS_OnPlayerClickPlayer] == Bit:-1) Scripting_RedirectPublic(#OnPlayerClickPlayer, Scripting_GetPublicPointer("S@@_OnPlayerClickPlayer"));
	#endif
	// The OnPlayerUpdate code is special.
	tmp = _:gs_aHookFunctionPointers[ALS_OnPlayerUpdate];
	if (tmp == -1)
	{
		Scripting_RedirectPublic(#OnPlayerUpdate, Scripting_GetPublicPointer("S@@_OnPlayerUpdate"));
	}
	else
	{
		if (!(tmp & 0xFFFF))
		{
			// Some fast find functions, but no normal ones.
			gs_aHookFunctionPointers[ALS_OnPlayerUpdate] = Bit:-1;
		}
	}
}

#pragma tabsize 0

// Hook OnGameModeInit using the old system to call the new system.
public OnGameModeInit()
{
	#if !defined FILTERSCRIPT
		// Generate the list of functions
		Hooks_GenFuncList();
	#endif
	HOOKS_CALL<GameModeInit>
	//HOOKS_CALL<GameModeInit,>()
	//ALS_CALL<OnGameModeInit,>()
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit S@@_OnGameModeInit
ALS_FORWARD<GameModeInit>

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if (inputtext[0])
	{
		HOOKS_C_INT<DialogResponse,iiiis>(playerid,dialogid,response,listitem,inputtext)
		ALS_C_INT<DialogResponse,1,iiiis>(playerid,dialogid,response,listitem,inputtext)
	}
	else
	{
		HOOKS_C_INT<DialogResponse,iiiis>(playerid,dialogid,response,listitem,NULL)
		ALS_C_INT<DialogResponse,1,iiiis>(playerid,dialogid,response,listitem,NULL)
	}
	//HOOKS_CALL<DialogResponse>
}
#if defined _ALS_OnDialogResponse
	#undef OnDialogResponse
#else
	#define _ALS_OnDialogResponse
#endif
#define OnDialogResponse S@@_OnDialogResponse
ALS_FORWARD<DialogResponse>

public OnPlayerUpdate(playerid)
{
	P:1("Hooks_OnPlayerUpdate called");
	// This is the special one.
	for (new i = 0; i != HOOKS_MAX_UPDATES; ++i)
	{
		P:2("Hooks_OnPlayerUpdate: i = %d", i);
		new
			tmp = gs_aOnPlayerUpdateHooks[i];
		if (tmp == -1)
		{
			ALS_CALL<PlayerUpdate>
		}
		// This function can return any public, it's not limited to getting
		// OnPlayerUpdate functions, but the passed index means it will reach a
		// matching function, which will be an update function, instantly.
		Scripting_GetPublicFast(tmp, gs_szFunctionBuffer, HOOK_FUNC_SEARCH);
		CallLocalFunction(gs_szFunctionBuffer,"i", playerid);
	}
	P:2("Hooks_OnPlayerUpdate ended");
	// This uses the normal call wrapper.
	HOOKS_CALL<PlayerUpdate>
}
#if defined _ALS_OnPlayerUpdate
	#undef OnPlayerUpdate
#else
	#define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate S@@_OnPlayerUpdate
ALS_FORWARD<PlayerUpdate>

public OnFilterScriptInit()
{
	#if defined FILTERSCRIPT
		// Generate the list of functions
		Hooks_GenFuncList();
	#endif
	HOOKS_CALL<FilterScriptInit>
}
#if defined _ALS_OnFilterScriptInit
	#undef OnFilterScriptInit
#else
	#define _ALS_OnFilterScriptInit
#endif
#define OnFilterScriptInit S@@_OnFilterScriptInit
ALS_FORWARD<FilterScriptInit>

// =============================================================================
// =============================================================================
// |||                                                                       |||
// |||   NOTE:                                                               |||
// |||                                                                       |||
// |||     EVERYTHING BEYOND THIS POINT IS BORING AND CAN BE IGNORED -       |||
// |||     IT'S JUST THE SAME CODE OVER AND OVER FOR EVERY CALLBACK:         |||
// |||                                                                       |||
// |||                                                                       |||
// |||       public OnPlayerConnect(playerid)                                |||
// |||       {                                                               |||
// |||           HOOKS_CALL<PlayerConnect>                                   |||
// |||       }                                                               |||
// |||       #if defined _ALS_OnPlayerConnect                                |||
// |||           #undef OnPlayerConnect                                      |||
// |||       #else                                                           |||
// |||           #define _ALS_OnPlayerConnect                                |||
// |||       #endif                                                          |||
// |||       #define OnPlayerConnect S@@_OnPlayerConnect                     |||
// |||       ALS_FORWARD<PlayerConnect>                                      |||
// |||                                                                       |||
// |||                                                                       |||
// |||     THE "#if 1" WILL ALLOW YOU TO HIDE ALL THE CODE IN AN             |||
// |||     EDITOR WITH CODE FOLDING, FOR EXAMPLE NOTEPAD++                   |||
// |||                                                                       |||
// =============================================================================
// =============================================================================

#if 1

public OnGameModeExit()
{
	HOOKS_CALL<GameModeExit>
}
#if defined _ALS_OnGameModeExit
	#undef OnGameModeExit
#else
	#define _ALS_OnGameModeExit
#endif
#define OnGameModeExit S@@_OnGameModeExit
ALS_FORWARD<GameModeExit>

public OnFilterScriptExit()
{
	HOOKS_CALL<FilterScriptExit>
}
#if defined _ALS_OnFilterScriptExit
	#undef OnFilterScriptExit
#else
	#define _ALS_OnFilterScriptExit
#endif
#define OnFilterScriptExit S@@_OnFilterScriptExit
ALS_FORWARD<FilterScriptExit>

public OnPlayerConnect(playerid)
{
	HOOKS_CALL<PlayerConnect>
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect S@@_OnPlayerConnect
ALS_FORWARD<PlayerConnect>

public OnPlayerDisconnect(playerid, reason)
{
	HOOKS_CALL<PlayerDisconnect>
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect S@@_OnPlayerDisconnect
ALS_FORWARD<PlayerDisconnect>

public OnPlayerSpawn(playerid)
{
	HOOKS_CALL<PlayerSpawn>
}
#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn S@@_OnPlayerSpawn
ALS_FORWARD<PlayerSpawn>

public OnPlayerDeath(playerid, killerid, reason)
{
	HOOKS_CALL<PlayerDeath>
}
#if defined _ALS_OnPlayerDeath
	#undef OnPlayerDeath
#else
	#define _ALS_OnPlayerDeath
#endif
#define OnPlayerDeath S@@_OnPlayerDeath
ALS_FORWARD<PlayerDeath>

public OnVehicleSpawn(vehicleid)
{
	HOOKS_CALL<VehicleSpawn>
}
#if defined _ALS_OnVehicleSpawn
	#undef OnVehicleSpawn
#else
	#define _ALS_OnVehicleSpawn
#endif
#define OnVehicleSpawn S@@_OnVehicleSpawn
ALS_FORWARD<VehicleSpawn>

public OnVehicleDeath(vehicleid, killerid)
{
	HOOKS_CALL<VehicleDeath>
}
#if defined _ALS_OnVehicleDeath
	#undef OnVehicleDeath
#else
	#define _ALS_OnVehicleDeath
#endif
#define OnVehicleDeath S@@_OnVehicleDeath
ALS_FORWARD<VehicleDeath>

public OnPlayerText(playerid, text[])
{
	HOOKS_CALL<PlayerText>
}
#if defined _ALS_OnPlayerText
	#undef OnPlayerText
#else
	#define _ALS_OnPlayerText
#endif
#define OnPlayerText S@@_OnPlayerText
ALS_FORWARD<PlayerText>

public OnPlayerCommandText(playerid, cmdtext[])
{
	HOOKS_CALL<PlayerCommandText>
}
#if defined _ALS_OnPlayerCommandText
	#undef OnPlayerCommandText
#else
	#define _ALS_OnPlayerCommandText
#endif
#define OnPlayerCommandText S@@_OnPlayerCommandText
ALS_FORWARD<PlayerCommandText>

public OnPlayerRequestClass(playerid, classid)
{
	HOOKS_CALL<PlayerRequestClass>
}
#if defined _ALS_OnPlayerRequestClass
	#undef OnPlayerRequestClass
#else
	#define _ALS_OnPlayerRequestClass
#endif
#define OnPlayerRequestClass S@@_OnPlayerRequestClass
ALS_FORWARD<PlayerRequestClass>

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	HOOKS_CALL<PlayerEnterVehicle>
}
#if defined _ALS_OnPlayerEnterVehicle
	#undef OnPlayerEnterVehicle
#else
	#define _ALS_OnPlayerEnterVehicle
#endif
#define OnPlayerEnterVehicle S@@_OnPlayerEnterVehicle
ALS_FORWARD<PlayerEnterVehicle>

public OnPlayerExitVehicle(playerid, vehicleid)
{
	HOOKS_CALL<PlayerExitVehicle>
}
#if defined _ALS_OnPlayerExitVehicle
	#undef OnPlayerExitVehicle
#else
	#define _ALS_OnPlayerExitVehicle
#endif
#define OnPlayerExitVehicle S@@_OnPlayerExitVehicle
ALS_FORWARD<PlayerExitVehicle>

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	HOOKS_CALL<PlayerStateChange>
}
#if defined _ALS_OnPlayerStateChange
	#undef OnPlayerStateChange
#else
	#define _ALS_OnPlayerStateChange
#endif
#define OnPlayerStateChange S@@_OnPlayerStateChange
ALS_FORWARD<PlayerStateChange>

public OnPlayerEnterCheckpoint(playerid)
{
	HOOKS_CALL<PlayerEnterCheckpoint>
}
#if defined _ALS_OnPlayerEnterCheckpoint
	#undef OnPlayerEnterCheckpoint
#else
	#define _ALS_OnPlayerEnterCheckpoint
#endif
#define OnPlayerEnterCheckpoint S@@_OnPlayerEnterCheckpoint
ALS_FORWARD<PlayerEnterCheckpoint>

public OnPlayerLeaveCheckpoint(playerid)
{
	HOOKS_CALL<PlayerLeaveCheckpoint>
}
#if defined _ALS_OnPlayerLeaveCheckpoint
	#undef OnPlayerLeaveCheckpoint
#else
	#define _ALS_OnPlayerLeaveCheckpoint
#endif
#define OnPlayerLeaveCheckpoint S@@_OnPlayerLeaveCheckpoint
ALS_FORWARD<PlayerLeaveCheckpoint>

public OnPlayerEnterRaceCheckpoint(playerid)
{
	HOOKS_CALL<PlayerEnterRaceCheckpoint>
}
#if defined _ALS_OnPlayerEnterRaceCP
	#undef OnPlayerEnterRaceCheckpoint
#else
	#define _ALS_OnPlayerEnterRaceCP
#endif
#define OnPlayerEnterRaceCheckpoint S@@_OnPlayerEnterRaceCheckpoint
ALS_FORWARD<PlayerEnterRaceCheckpoint>

public OnPlayerLeaveRaceCheckpoint(playerid)
{
	HOOKS_CALL<PlayerLeaveRaceCheckpoint>
}
#if defined _ALS_OnPlayerLeaveRaceCP
	#undef OnPlayerLeaveRaceCheckpoint
#else
	#define _ALS_OnPlayerLeaveRaceCP
#endif
#define OnPlayerLeaveRaceCheckpoint S@@_OnPlayerLeaveRaceCheckpoint
ALS_FORWARD<PlayerLeaveRaceCheckpoint>

public OnRconCommand(cmd[])
{
	HOOKS_CALL<RconCommand>
}
#if defined _ALS_OnRconCommand
	#undef OnRconCommand
#else
	#define _ALS_OnRconCommand
#endif
#define OnRconCommand S@@_OnRconCommand
ALS_FORWARD<RconCommand>

public OnPlayerRequestSpawn(playerid)
{
	HOOKS_CALL<PlayerRequestSpawn>
}
#if defined _ALS_OnPlayerRequestSpawn
	#undef OnPlayerRequestSpawn
#else
	#define _ALS_OnPlayerRequestSpawn
#endif
#define OnPlayerRequestSpawn S@@_OnPlayerRequestSpawn
ALS_FORWARD<PlayerRequestSpawn>

public OnObjectMoved(objectid)
{
	HOOKS_CALL<ObjectMoved>
}
#if defined _ALS_OnObjectMoved
	#undef OnObjectMoved
#else
	#define _ALS_OnObjectMoved
#endif
#define OnObjectMoved S@@_OnObjectMoved
ALS_FORWARD<ObjectMoved>

public OnPlayerObjectMoved(playerid, objectid)
{
	HOOKS_CALL<PlayerObjectMoved>
}
#if defined _ALS_OnPlayerObjectMoved
	#undef OnPlayerObjectMoved
#else
	#define _ALS_OnPlayerObjectMoved
#endif
#define OnPlayerObjectMoved S@@_OnPlayerObjectMoved
ALS_FORWARD<PlayerObjectMoved>

public OnPlayerPickUpPickup(playerid, pickupid)
{
	HOOKS_CALL<PlayerPickUpPickup>
}
#if defined _ALS_OnPlayerPickUpPickup
	#undef OnPlayerPickUpPickup
#else
	#define _ALS_OnPlayerPickUpPickup
#endif
#define OnPlayerPickUpPickup S@@_OnPlayerPickUpPickup
ALS_FORWARD<PlayerPickUpPickup>

public OnVehicleMod(playerid, vehicleid, componentid)
{
	HOOKS_CALL<VehicleMod>
}
#if defined _ALS_OnVehicleMod
	#undef OnVehicleMod
#else
	#define _ALS_OnVehicleMod
#endif
#define OnVehicleMod S@@_OnVehicleMod
ALS_FORWARD<VehicleMod>

public OnEnterExitModShop(playerid, enterexit, interiorid)
{
	HOOKS_CALL<EnterExitModShop>
}
#if defined _ALS_OnEnterExitModShop
	#undef OnEnterExitModShop
#else
	#define _ALS_OnEnterExitModShop
#endif
#define OnEnterExitModShop S@@_OnEnterExitModShop
ALS_FORWARD<EnterExitModShop>

public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
	HOOKS_CALL<VehiclePaintjob>
}
#if defined _ALS_OnVehiclePaintjob
	#undef OnVehiclePaintjob
#else
	#define _ALS_OnVehiclePaintjob
#endif
#define OnVehiclePaintjob S@@_OnVehiclePaintjob
ALS_FORWARD<VehiclePaintjob>

public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
	HOOKS_CALL<VehicleRespray>
}
#if defined _ALS_OnVehicleRespray
	#undef OnVehicleRespray
#else
	#define _ALS_OnVehicleRespray
#endif
#define OnVehicleRespray S@@_OnVehicleRespray
ALS_FORWARD<VehicleRespray>

public OnVehicleDamageStatusUpdate(vehicleid, playerid)
{
	HOOKS_CALL<VehicleDamageStatusUpdate>
}
#if defined _ALS_OnVehicleDamageStatusUpd
	#undef OnVehicleDamageStatusUpdate
#else
	#define _ALS_OnVehicleDamageStatusUpd
#endif
#define OnVehicleDamageStatusUpdate S@@_OnVehicleDamageStatusUpdate
ALS_FORWARD<VehicleDamageStatusUpdate>

public OnPlayerSelectedMenuRow(playerid, row)
{
	HOOKS_CALL<PlayerSelectedMenuRow>
}
#if defined _ALS_OnPlayerSelectedMenuRow
	#undef OnPlayerSelectedMenuRow
#else
	#define _ALS_OnPlayerSelectedMenuRow
#endif
#define OnPlayerSelectedMenuRow S@@_OnPlayerSelectedMenuRow
ALS_FORWARD<PlayerSelectedMenuRow>

public OnPlayerExitedMenu(playerid)
{
	HOOKS_CALL<PlayerExitedMenu>
}
#if defined _ALS_OnPlayerExitedMenu
	#undef OnPlayerExitedMenu
#else
	#define _ALS_OnPlayerExitedMenu
#endif
#define OnPlayerExitedMenu S@@_OnPlayerExitedMenu
ALS_FORWARD<PlayerExitedMenu>

public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
	HOOKS_CALL<PlayerInteriorChange>
}
#if defined _ALS_OnPlayerInteriorChange
	#undef OnPlayerInteriorChange
#else
	#define _ALS_OnPlayerInteriorChange
#endif
#define OnPlayerInteriorChange S@@_OnPlayerInteriorChange
ALS_FORWARD<PlayerInteriorChange>

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	HOOKS_CALL<PlayerKeyStateChange>
}
#if defined _ALS_OnPlayerKeyStateChange
	#undef OnPlayerKeyStateChange
#else
	#define _ALS_OnPlayerKeyStateChange
#endif
#define OnPlayerKeyStateChange S@@_OnPlayerKeyStateChange
ALS_FORWARD<PlayerKeyStateChange>

public OnRconLoginAttempt(ip[], password[], success)
{
	HOOKS_CALL<RconLoginAttempt>
}
#if defined _ALS_OnRconLoginAttempt
	#undef OnRconLoginAttempt
#else
	#define _ALS_OnRconLoginAttempt
#endif
#define OnRconLoginAttempt S@@_OnRconLoginAttempt
ALS_FORWARD<RconLoginAttempt>

public OnPlayerStreamIn(playerid, forplayerid)
{
	HOOKS_CALL<PlayerStreamIn>
}
#if defined _ALS_OnPlayerStreamIn
	#undef OnPlayerStreamIn
#else
	#define _ALS_OnPlayerStreamIn
#endif
#define OnPlayerStreamIn S@@_OnPlayerStreamIn
ALS_FORWARD<PlayerStreamIn>

public OnPlayerStreamOut(playerid, forplayerid)
{
	HOOKS_CALL<PlayerStreamOut>
}
#if defined _ALS_OnPlayerStreamOut
	#undef OnPlayerStreamOut
#else
	#define _ALS_OnPlayerStreamOut
#endif
#define OnPlayerStreamOut S@@_OnPlayerStreamOut
ALS_FORWARD<PlayerStreamOut>

public OnVehicleStreamIn(vehicleid, forplayerid)
{
	HOOKS_CALL<VehicleStreamIn>
}
#if defined _ALS_OnVehicleStreamIn
	#undef OnVehicleStreamIn
#else
	#define _ALS_OnVehicleStreamIn
#endif
#define OnVehicleStreamIn S@@_OnVehicleStreamIn
ALS_FORWARD<VehicleStreamIn>

public OnVehicleStreamOut(vehicleid, forplayerid)
{
	HOOKS_CALL<VehicleStreamOut>
}
#if defined _ALS_OnVehicleStreamOut
	#undef OnVehicleStreamOut
#else
	#define _ALS_OnVehicleStreamOut
#endif
#define OnVehicleStreamOut S@@_OnVehicleStreamOut
ALS_FORWARD<VehicleStreamOut>

public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	HOOKS_CALL<PlayerClickPlayer>
}
#if defined _ALS_OnDPlayerClickPlayer
	#undef OnPlayerClickPlayer
#else
	#define _ALS_OnPlayerClickPlayer
#endif
#define OnPlayerClickPlayer S@@_OnPlayerClickPlayer
ALS_FORWARD<PlayerClickPlayer>

#endif

#pragma tabsize 4

#undef ALS_PREFIX
