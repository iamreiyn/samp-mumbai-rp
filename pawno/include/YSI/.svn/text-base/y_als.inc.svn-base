/*----------------------------------------------------------------------------*-
					==============================
					 y_als - Useful codes for ALS
					==============================
Description:
	Provides a number of macros for making ALS (Advanced Library System)
	callback hooking simpler.
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
	21/10/10:
		First version
-*----------------------------------------------------------------------------*/

#include <YSI\internal\y_version>

// Allow multiple inclusions.
#undef _inc_y_als

#if !defined _Y_ALS_INCLUDED
	// This is an include guard with a purpose!
	
	#include <YSI\y_bit>
	#include <YSI\internal\y_shortfunc>
	
	enum ALS
	{
		Bit:ALS_OnGameModeInit,
		Bit:ALS_OnGameModeExit,
		Bit:ALS_OnFilterScriptInit,
		Bit:ALS_OnFilterScriptExit,
		Bit:ALS_OnPlayerConnect,
		Bit:ALS_OnPlayerDisconnect,
		Bit:ALS_OnPlayerSpawn,
		Bit:ALS_OnPlayerDeath,
		Bit:ALS_OnVehicleSpawn,
		Bit:ALS_OnVehicleDeath,
		Bit:ALS_OnPlayerText,
		Bit:ALS_OnPlayerCommandText,
		Bit:ALS_OnPlayerRequestClass,
		Bit:ALS_OnPlayerEnterVehicle,
		Bit:ALS_OnPlayerExitVehicle,
		Bit:ALS_OnPlayerStateChange,
		Bit:ALS_OnPlayerEnterCheckpoint,
		Bit:ALS_OnPlayerLeaveCheckpoint,
		Bit:ALS_OnPlayerEnterRaceCheckpoint,
		Bit:ALS_OnPlayerLeaveRaceCheckpoint,
		Bit:ALS_OnRconCommand,
		Bit:ALS_OnPlayerRequestSpawn,
		Bit:ALS_OnObjectMoved,
		Bit:ALS_OnPlayerObjectMoved,
		Bit:ALS_OnPlayerPickUpPickup,
		Bit:ALS_OnVehicleMod,
		Bit:ALS_OnEnterExitModShop,
		Bit:ALS_OnVehiclePaintjob,
		Bit:ALS_OnVehicleRespray,
		Bit:ALS_OnVehicleDamageStatusUpdate,
		Bit:ALS_OnPlayerSelectedMenuRow,
		Bit:ALS_OnPlayerExitedMenu,
		Bit:ALS_OnPlayerInteriorChange,
		Bit:ALS_OnPlayerKeyStateChange,
		Bit:ALS_OnRconLoginAttempt,
		Bit:ALS_OnPlayerUpdate,
		Bit:ALS_OnPlayerStreamIn,
		Bit:ALS_OnPlayerStreamOut,
		Bit:ALS_OnVehicleStreamIn,
		Bit:ALS_OnVehicleStreamOut,
		Bit:ALS_OnDialogResponse,
		Bit:ALS_OnPlayerClickPlayer
	}
	
	#define ALS_DATA<> static stock BitArray:gs_ALS<_:ALS>;
	
	#define ALS_DETECT<%0> if(funcidx(#ALS_PREFIX"_On"#%0)!=-1)Bit_Let(gs_ALS,_:ALS_On%0);
	
	//#define ALS_DETECT_SHORT<On%0> if(funcidx(#ALS_PREFIX"_"#%0)!=-1)Bit_Let(gs_ALS,_:ALS_On%0);
	
	//#define ALS_CALL_INT<%0,%2>(%3) return Bit_GetBit(Bit:gs_ALS,_:ALS_On%0)?P@(#ALS_PREFIX"_On"#%0,#%2#x,%3):1;
	
	#define ALS_C_INT<%0,%1,%2>(%3) return Bit_GetBit(Bit:gs_ALS,_:ALS_On%0)?P@(#ALS_PREFIX"_On"#%0,#%2#x,%3):%1;
	#define ALS_F_INT<%0>(%1) forward On%0(%1);
	
	// Forward declarations.
	#define ALS_F_GameModeInit              ALS_F_INT<GameModeInit             >()
	#define ALS_F_GameModeExit              ALS_F_INT<GameModeExit             >()
	#define ALS_F_FilterScriptInit          ALS_F_INT<FilterScriptInit         >()
	#define ALS_F_FilterScriptExit          ALS_F_INT<FilterScriptExit         >()
	#define ALS_F_PlayerConnect             ALS_F_INT<PlayerConnect            >(playerid)
	#define ALS_F_PlayerDisconnect          ALS_F_INT<PlayerDisconnect         >(playerid,reason)
	#define ALS_F_PlayerSpawn               ALS_F_INT<PlayerSpawn              >(playerid)
	#define ALS_F_PlayerDeath               ALS_F_INT<PlayerDeath              >(playerid,killerid,reason)
	#define ALS_F_VehicleSpawn              ALS_F_INT<VehicleSpawn             >(vehicleid)
	#define ALS_F_VehicleDeath              ALS_F_INT<VehicleDeath             >(vehicleid,killerid)
	#define ALS_F_PlayerText                ALS_F_INT<PlayerText               >(playerid,text[])
	#define ALS_F_PlayerCommandText         ALS_F_INT<PlayerCommandText        >(playerid,cmdtext[])
	#define ALS_F_PlayerRequestClass        ALS_F_INT<PlayerRequestClass       >(playerid,classid)
	#define ALS_F_PlayerEnterVehicle        ALS_F_INT<PlayerEnterVehicle       >(playerid,vehicleid,ispassenger)
	#define ALS_F_PlayerExitVehicle         ALS_F_INT<PlayerExitVehicle        >(playerid,vehicleid)
	#define ALS_F_PlayerStateChange         ALS_F_INT<PlayerStateChange        >(playerid,newstate,oldstate)
	#define ALS_F_PlayerEnterCheckpoint     ALS_F_INT<PlayerEnterCheckpoint    >(playerid)
	#define ALS_F_PlayerLeaveCheckpoint     ALS_F_INT<PlayerLeaveCheckpoint    >(playerid)
	#define ALS_F_PlayerEnterRaceCheckpoint ALS_F_INT<PlayerEnterRaceCheckpoint>(playerid)
	#define ALS_F_PlayerLeaveRaceCheckpoint ALS_F_INT<PlayerLeaveRaceCheckpoint>(playerid)
	#define ALS_F_RconCommand               ALS_F_INT<RconCommand              >(cmd[])
	#define ALS_F_PlayerRequestSpawn        ALS_F_INT<PlayerRequestSpawn       >(playerid)
	#define ALS_F_ObjectMoved               ALS_F_INT<ObjectMoved              >(objectid)
	#define ALS_F_PlayerObjectMoved         ALS_F_INT<PlayerObjectMoved        >(playerid,objectid)
	#define ALS_F_PlayerPickUpPickup        ALS_F_INT<PlayerPickUpPickup       >(playerid,pickupid)
	#define ALS_F_VehicleMod                ALS_F_INT<VehicleMod               >(playerid,vehicleid,componentid)
	#define ALS_F_EnterExitModShop          ALS_F_INT<EnterExitModShop         >(playerid,enterexit,interiorid)
	#define ALS_F_VehiclePaintjob           ALS_F_INT<VehiclePaintjob          >(playerid,vehicleid,paintjobid)
	#define ALS_F_VehicleRespray            ALS_F_INT<VehicleRespray           >(playerid,vehicleid,color1,color2)
	#define ALS_F_VehicleDamageStatusUpdate ALS_F_INT<VehicleDamageStatusUpdate>(playerid,vehicleid)
	#define ALS_F_PlayerSelectedMenuRow     ALS_F_INT<PlayerSelectedMenuRow    >(playerid,row)
	#define ALS_F_PlayerExitedMenu          ALS_F_INT<PlayerExitedMenu         >(playerid)
	#define ALS_F_PlayerInteriorChange      ALS_F_INT<PlayerInteriorChange     >(playerid,newinteriorid,oldinteriorid)
	#define ALS_F_PlayerKeyStateChange      ALS_F_INT<PlayerKeyStateChange     >(playerid,newkeys,oldkeys)
	#define ALS_F_RconLoginAttempt          ALS_F_INT<RconLoginAttempt         >(ip[],password[],success)
	#define ALS_F_PlayerUpdate              ALS_F_INT<PlayerUpdate             >(playerid)
	#define ALS_F_PlayerStreamIn            ALS_F_INT<PlayerStreamIn           >(playerid,forplayerid)
	#define ALS_F_PlayerStreamOut           ALS_F_INT<PlayerStreamOut          >(playerid,forplayerid)
	#define ALS_F_VehicleStreamIn           ALS_F_INT<VehicleStreamIn          >(vehicleid,forplayerid)
	#define ALS_F_VehicleStreamOut          ALS_F_INT<VehicleStreamOut         >(vehicleid,forplayerid)
	#define ALS_F_DialogResponse            ALS_F_INT<DialogResponse           >(playerid,dialogid,response,listitem,inputtext[])
	#define ALS_F_PlayerClickPlayer         ALS_F_INT<PlayerClickPlayer        >(playerid,clickedplayerid,source)
	
	// Chain call declarations.
	#define ALS_C_GameModeInit              ALS_C_INT<GameModeInit             ,1,>()
	#define ALS_C_GameModeExit              ALS_C_INT<GameModeExit             ,1,>()
	#define ALS_C_FilterScriptInit          ALS_C_INT<FilterScriptInit         ,1,>()
	#define ALS_C_FilterScriptExit          ALS_C_INT<FilterScriptExit         ,1,>()
	#define ALS_C_PlayerConnect             ALS_C_INT<PlayerConnect            ,1,i>(playerid)
	#define ALS_C_PlayerDisconnect          ALS_C_INT<PlayerDisconnect         ,1,ii>(playerid,reason)
	#define ALS_C_PlayerSpawn               ALS_C_INT<PlayerSpawn              ,1,i>(playerid)
	#define ALS_C_PlayerDeath               ALS_C_INT<PlayerDeath              ,1,iii>(playerid,killerid,reason)
	#define ALS_C_VehicleSpawn              ALS_C_INT<VehicleSpawn             ,1,i>(vehicleid)
	#define ALS_C_VehicleDeath              ALS_C_INT<VehicleDeath             ,1,ii>(vehicleid,killerid)
	#define ALS_C_PlayerText                ALS_C_INT<PlayerText               ,1,is>(playerid,text)
	#define ALS_C_PlayerCommandText         ALS_C_INT<PlayerCommandText        ,0,is>(playerid,cmdtext)
	#define ALS_C_PlayerRequestClass        ALS_C_INT<PlayerRequestClass       ,1,ii>(playerid,classid)
	#define ALS_C_PlayerEnterVehicle        ALS_C_INT<PlayerEnterVehicle       ,1,iii>(playerid,vehicleid,ispassenger)
	#define ALS_C_PlayerExitVehicle         ALS_C_INT<PlayerExitVehicle        ,1,ii>(playerid,vehicleid)
	#define ALS_C_PlayerStateChange         ALS_C_INT<PlayerStateChange        ,1,iii>(playerid,newstate,oldstate)
	#define ALS_C_PlayerEnterCheckpoint     ALS_C_INT<PlayerEnterCheckpoint    ,1,i>(playerid)
	#define ALS_C_PlayerLeaveCheckpoint     ALS_C_INT<PlayerLeaveCheckpoint    ,1,i>(playerid)
	#define ALS_C_PlayerEnterRaceCheckpoint ALS_C_INT<PlayerEnterRaceCheckpoint,1,i>(playerid)
	#define ALS_C_PlayerLeaveRaceCheckpoint ALS_C_INT<PlayerLeaveRaceCheckpoint,1,i>(playerid)
	#define ALS_C_RconCommand               ALS_C_INT<RconCommand              ,1,s>(cmd)
	#define ALS_C_PlayerRequestSpawn        ALS_C_INT<PlayerRequestSpawn       ,1,i>(playerid)
	#define ALS_C_ObjectMoved               ALS_C_INT<ObjectMoved              ,1,i>(objectid)
	#define ALS_C_PlayerObjectMoved         ALS_C_INT<PlayerObjectMoved        ,1,ii>(playerid,objectid)
	#define ALS_C_PlayerPickUpPickup        ALS_C_INT<PlayerPickUpPickup       ,1,ii>(playerid,pickupid)
	#define ALS_C_VehicleMod                ALS_C_INT<VehicleMod               ,1,iii>(playerid,vehicleid,componentid)
	#define ALS_C_EnterExitModShop          ALS_C_INT<EnterExitModShop         ,1,iii>(playerid,enterexit,interiorid)
	#define ALS_C_VehiclePaintjob           ALS_C_INT<VehiclePaintjob          ,1,iii>(playerid,vehicleid,paintjobid)
	#define ALS_C_VehicleRespray            ALS_C_INT<VehicleRespray           ,1,iiii>(playerid,vehicleid,color1,color2)
	#define ALS_C_VehicleDamageStatusUpdate ALS_C_INT<VehicleDamageStatusUpdate,1,ii>(playerid,playerid)
	#define ALS_C_PlayerSelectedMenuRow     ALS_C_INT<PlayerSelectedMenuRow    ,1,ii>(playerid,row)
	#define ALS_C_PlayerExitedMenu          ALS_C_INT<PlayerExitedMenu         ,1,i>(playerid)
	#define ALS_C_PlayerInteriorChange      ALS_C_INT<PlayerInteriorChange     ,1,iii>(playerid,newinteriorid,oldinteriorid)
	#define ALS_C_PlayerKeyStateChange      ALS_C_INT<PlayerKeyStateChange     ,1,iii>(playerid,newkeys,oldkeys)
	#define ALS_C_RconLoginAttempt          ALS_C_INT<RconLoginAttempt         ,1,ssi>(ip,password,success)
	#define ALS_C_PlayerUpdate              ALS_C_INT<PlayerUpdate             ,1,i>(playerid)
	#define ALS_C_PlayerStreamIn            ALS_C_INT<PlayerStreamIn           ,1,ii>(playerid,forplayerid)
	#define ALS_C_PlayerStreamOut           ALS_C_INT<PlayerStreamOut          ,1,ii>(playerid,forplayerid)
	#define ALS_C_VehicleStreamIn           ALS_C_INT<VehicleStreamIn          ,1,ii>(vehicleid,forplayerid)
	#define ALS_C_VehicleStreamOut          ALS_C_INT<VehicleStreamOut         ,1,ii>(vehicleid,forplayerid)
	//#define ALS_C_DialogResponse            ALS_C_INT<DialogResponse           ,1,ii>(playerid,dialogid,response,listitem,inputtext)
	#define ALS_C_PlayerClickPlayer         ALS_C_INT<PlayerClickPlayer        ,1,iii>(playerid,clickedplayerid,source)
	#define ALS_C_DialogResponse if(inputtext[0]){ALS_C_INT<DialogResponse,1,iiiis>(playerid,dialogid,response,listitem,inputtext)}else{ALS_C_INT<DialogResponse,1,iiiis>(playerid,dialogid,response,listitem,NULL)}
	
	#define ALS_CALL<%0> ALS_C_%0
	#define ALS_FORWARD<%0> ALS_F_%0
	
	#define _Y_ALS_INCLUDED
#endif

#if !defined ALS_PREFIX
	//#error You must define a callback prefix before including y_als.
	#define ALS_PREFIX Mode
#endif
