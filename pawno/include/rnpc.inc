/**
 *	RNPC - Recordfile NPCs
 *  Version 0.4.1
 *	made by Mauzen
 */
#define RNPC_VERSION					"0.4.1"
#define RNPC_BUILD						14
#define RNPC_DATE						"03.12.2014"
#define RNPC_VERSION_DLPAGE				"www.mauzen.org/rnpc"
#define RNPC_VERSION_STARTURL			"www.mauzen.org/rnpc/rnpc_start.php"
#define RNPC_VERSION_UPDATEURL			"www.mauzen.org/rnpc/rnpc_update.php"

// Identify messages as RNPC commands
// (alternative communication protocol for future versions)
#define RNPC_COMM_ID				520
 
 
#define PLAYER_RECORDING_TYPE_NONE		0
#define PLAYER_RECORDING_TYPE_DRIVER	1
#define PLAYER_RECORDING_TYPE_ONFOOT	2

#define RNPC_SPEED_SPRINT				(0.0095)
#define RNPC_SPEED_RUN					(0.0057)
#define RNPC_SPEED_WALK					(0.0015)

#define MAP_ANDREAS_MODE_NONE			0
#define MAP_ANDREAS_MODE_MINIMAL		1
#define MAP_ANDREAS_MODE_MEDIUM			2	// currently unused
#define MAP_ANDREAS_MODE_FULL			3
#define MAP_ANDREAS_MODE_NOBUFFER		4

// RNPC_PEND_ACTION defines (Connection relevant states)
#define RNPC_ACTION_READY					(-1)
#define RNPC_NOT_EXISTING					(0)
#define RNPC_CONNECTION_PENDING				(1)
#define RNPC_CONNECTED						(2)
#define RNPC_STOPPING						(4)		// Stop-playback performed

// Adjustable stuff
#define RNPC_VEHICLE_DMG_MOD				(160.0)  // velocity * this value = vehicle hit damage


// AddPause compatibility mode
#if defined RNPC_PAUSE_REALTIME
	#define RNPC_PAUSE_COMP 0
#else
	#define RNPC_PAUSE_COMP 1
#endif

// @since 0.2
native RNPC_CreateBuild(npcid, type, slot=0);
native RNPC_FinishBuild(clear=1);
native RNPC_AddMovement(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2, Float:speed=RNPC_SPEED_RUN, use_zmap=0);
native RNPC_ConcatMovement(Float:x, Float:y, Float:z, Float:speed=RNPC_SPEED_RUN, use_zmap=0);
native RNPC_AddPause(time, comp=RNPC_PAUSE_COMP);

native RNPC_SetUpdateRate(rate);

native RNPC_SetLRKeys(lr);
native RNPC_SetUDKeys(ud);
native RNPC_SetKeys(keys);
native RNPC_SetQuat1(Float:w);
native RNPC_SetQuat2(Float:x);
native RNPC_SetQuat3(Float:y);
native RNPC_SetQuat4(Float:z);
native RNPC_SetHealth(hp);
native RNPC_SetArmour(arm);
native RNPC_SetSpecialAction(sp);
native RNPC_SetWeaponID(weaponid);
native RNPC_SetAnimID(anim);
native RNPC_SetAnimParams(params);
native RNPC_SetAngleQuats(Float:a, Float:h, Float:b);

native MapAndreas_Init(mode, name[]="", len=sizeof(name));
native MapAndreas_FindZ_For2DCoord(Float:X, Float:Y, &Float:Z);
native MapAndreas_FindAverageZ(Float:X, Float:Y, &Float:Z);
native MapAndreas_Unload();
native MapAndreas_SetZ_For2DCoord(Float:X, Float:Y, Float:Z);
native MapAndreas_SaveCurrentHMap(name[]);

// @since 0.2.1
native RNPC_GetBuildLength();

// @since 0.3
native RNPC_SetSirenState(siren);
native RNPC_SetDriverHealth(health);
native RNPC_SetInternalPos(Float:x, Float:y, Float:z);
native RNPC_SetAcceleration(Float:acc);
native RNPC_SetDeceleration(Float:dec);		// Unused yet
native RNPC_AddMovementAlt(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2, Float:speed=RNPC_SPEED_RUN, bool:lock=true);

// @since 0.3.4
native RNPC_CreateCustomBuild(type, name[]);

// fake-functions
#define RNPC_SetAutorepeat(%1,%2)				new rtxt[10]; format(rtxt, 10, "RNPC:%d", 110 + %2); SendClientMessage(%1, -1, rtxt)
#define RNPC_PauseRecordingPlayback(%1)			SendClientMessage(%1, -1, "RNPC:103")
#define RNPC_ResumeRecordingPlayback(%1)		SendClientMessage(%1, -1, "RNPC:104")
#define RNPC_ToggleVehicleCollisionCheck(%1,%2) new rtxt[10]; format(rtxt, 10, "RNPC:%d", 115 - %2); SendClientMessage(%1, -1, rtxt)
#define	RNPC_StopPlayback(%1)					SendClientMessage(%1, -1, "RNPC:102")
#define RNPC_SetShootable(%1,%2)				rnpcData[%1][RNPC_SHOOTABLE] = %2
#define GetRNPCHealth(%1)						rnpcData[%1][RNPC_HEALTH]
#define IsPlayerRNPC(%1)						(IsPlayerNPC(%1) && (rnpcPend{%1} != RNPC_NOT_EXISTING))


// Redirecting SendClientMessage when debugmode is enabled
#if defined RNPC_DEBUG
	stock RNPC_TEMP_SendClientMessage(playerid, color, text[], len=sizeof(text)) {
		#pragma unused len
		// if (IsPlayerRNPC(playerid))
		// not needed here as this include doesnt communicate with real players anyways
		printf("RNPC %d <-- [CMD] %s", playerid, text);
		SendClientMessage(playerid, color, text);
	}
	#define SendClientMessage RNPC_TEMP_SendClientMessage
#endif
// --------------------------------------------------------

// Custom callbacks
forward OnRNPCPlaybackFinished(npcid);
forward OnRNPCPlaybackStopped(npcid);
forward OnRNPCDeath(npcid, killerid, reason);
forward OnRNPCVehicleHit(npcid, driverid, vehicleid, times);


// To store pending connections and actions
new rnpcPend[MAX_PLAYERS char];
// Currently played record slot
new rnpcCurSlot[MAX_PLAYERS char];

/**
 *	Connects a new RNPC, returning his predicted ID.
 *	@since 	V0.1
 */
stock ConnectRNPC(name[])
{
	// Find the first free playerslot
	new slot = -1;
	for (new i = 0; i < MAX_PLAYERS; i++) {
		// Make sure theres no NPC connecting to that slot yet
		if (!IsPlayerConnected(i) && rnpcPend{i} == RNPC_NOT_EXISTING) {
			slot = i;
			rnpcPend{i} = RNPC_CONNECTION_PENDING;
			break;
		}
	}
	ConnectNPC(name, "RNPC");
	
	return slot;
}

/**
 *	Moves a RNPC to the given position.
 *	@since 	V0.1
 */
stock MoveRNPC(npcid, Float:x, Float:y, Float:z, Float:speed, use_zmap=0)
{
	if (!IsPlayerRNPC(npcid)) return false;
	
	new Float:nx, Float:ny, Float:nz;
	new slot;
	if (IsPlayerInAnyVehicle(npcid)) {
		GetVehiclePos(GetPlayerVehicleID(npcid), nx, ny, nz);
		slot = RNPC_CreateBuild_s(npcid, PLAYER_RECORDING_TYPE_DRIVER, 95);
		RNPC_AddMovement(nx, ny, nz, x, y, z, speed, use_zmap);
		RNPC_FinishBuild();
	} else {
		GetPlayerPos(npcid, nx, ny, nz);
		slot = RNPC_CreateBuild_s(npcid, PLAYER_RECORDING_TYPE_ONFOOT, 95);
		RNPC_AddMovement(nx, ny, nz, x, y, z, speed, use_zmap);
		RNPC_FinishBuild();
	}
	RNPC_StartBuildPlayback(npcid, slot);
	
	return true;
}

/**
 *	Prevents writing to currently active files.
 *	IMPORTANT: consider the returned slot to be sure to play the correct one afterwards.
 */
stock RNPC_CreateBuild_s(npcid, type, slot=0) {
	if (rnpcCurSlot{npcid} == slot) {
		slot = (slot + 1) % 100;
	}
	RNPC_CreateBuild(npcid, type, slot);
	return slot;
}

/**
 *  Tells the NPC to start playback of any rec file
 *	@since	V0.1.1
 */
stock RNPC_StartPlayback(npcid, rec[])
{
	if (!IsPlayerRNPC(npcid)) return false;
	
	new form[40];
	format(form, 40, "RNPC:109:%s", rec);
	SendClientMessage(npcid, -1, form);
	
	return true;
}

/**
 *  Tells the NPC to start playback of a RNPC build
 *	@since V0.2
 */
stock RNPC_StartBuildPlayback(npcid, slot=0, vehicleid=0)
{
	// If enabled, wait a bit till the NPC actually entered the vehicle
	if (vehicleid) {
		PutPlayerInVehicle(npcid, vehicleid, 0);
		SetTimerEx("DelayStart", 100, 0, "iii", npcid, vehicleid, slot);
	}
	rnpcCurSlot{npcid} = slot;
	new cmd[16];
	format(cmd, 16, "RNPC:101:%d", slot);
	SendClientMessage(npcid, -1, cmd);	
}

/**
 *  Delayed second start to fix vehicle playback problems
 *  @since V0.3
 */
forward DelayStart(npcid, vehicleid, slot);
public DelayStart(npcid, vehicleid, slot)
{
	PutPlayerInVehicle(npcid, vehicleid, 0);
	new cmd[16];
	format(cmd, 16, "RNPC:101:%d", slot);
	SendClientMessage(npcid, -1, cmd);
}

/**
 *
 * @since V0.3
 */
//stock RNPC_StopPlayback(npcid)
//{
	// Moved to fake functions
//}


// Damage management ---------------------------------------------

enum RNPC_DATA_ENUM {
	Float:	RNPC_HEALTH,				// Stores a healthvalue for the NPC
			RNPC_DEAD,					// Determines if the NPC is dead
			RNPC_LAST_DAMAGER,			// Last guy who attacked the NPC
			RNPC_LAST_REASON,			// Last damage reason
			RNPC_SHOOTABLE,				// If true, the NPC will get default GTA damage from guns
			RNPC_VEHICLEHIT,
			RNPC_VEHICLEHIT_RESETTIMER	// Timer to reset the vehiclehit status and resume playback
};

new rnpcData[MAX_PLAYERS][RNPC_DATA_ENUM];


stock SetRNPCHealth(npcid, Float:health, issuer=INVALID_PLAYER_ID, reason=53) {
	rnpcData[npcid][RNPC_HEALTH] = health;
	
	rnpcData[npcid][RNPC_LAST_DAMAGER] = issuer;
	rnpcData[npcid][RNPC_LAST_REASON] = reason;
	
	if (rnpcData[npcid][RNPC_HEALTH] <= 0.0) {
		// Kill the NPC if hes not already dead		
		
		if (!rnpcData[npcid][RNPC_DEAD]) {			
			// Stop playback
			RNPC_StopPlayback(npcid);
		}		
		// --> When stopped, apply death animation
	}
}


// Exact runover check, called after proximity alert by a NPC
// TODO: Move that calculation to the plugin for better speed
stock IsVehicleOnPlayer(playerid, vehicleid) {
	static Float:ro_xs, Float:ro_ys, Float:ro_zs;
	static Float:ro_xn, Float:ro_yn, Float:ro_zn;
	static Float:ro_xv, Float:ro_yv, Float:ro_zv, Float:ro_av;
	static Float:ro_tx, Float:ro_ty;
	// Gather position and size data
	GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_SIZE, ro_xs, ro_ys, ro_zs);
	GetPlayerPos(playerid, ro_xn, ro_yn, ro_zn);
	GetVehiclePos(vehicleid, ro_xv, ro_yv, ro_zv);
	GetVehicleZAngle(vehicleid, ro_av);
	//ro_av = 360 - ro_av;
	
	// Transform coordinate system
	ro_tx = floatabs((ro_xn - ro_xv) * floatcos(ro_av,degrees) + (ro_yn - ro_yv) * floatsin(ro_av,degrees));
	ro_ty = floatabs(-(ro_xn - ro_xv) * floatsin(ro_av,degrees) + (ro_yn - ro_yv) * floatcos(ro_av,degrees));
	
	return ((ro_zn - ro_zv) < 0.5) && (ro_tx < ro_xs / 2 && ro_ty < ro_ys / 2);	
}

// Used for timed respawn
forward RespawnRNPC(npcid);
public RespawnRNPC(npcid) {
	SpawnPlayer(npcid);
}


forward ResetVehicleHit(npcid);
public ResetVehicleHit(npcid) {
	// Reset hitstate and continue playbck
	rnpcData[npcid][RNPC_VEHICLEHIT] = 0;
	rnpcData[npcid][RNPC_VEHICLEHIT_RESETTIMER] = -1;
	RNPC_ResumeRecordingPlayback(npcid);
}


// Hooked callbacks ---------------------------------------------------

/**
 *	Serverside interface for RNPC communication
 */
// Support for ZCMD, modified version of Lorenc_'s experimental update
#if defined _zcmd_included
	#define OPCT_HOOKNAME		"RNPC_OnPlayerCommandReceived"
    public OnPlayerCommandReceived(playerid, cmdtext[])
#else
	#define OPCT_HOOKNAME		"RNPC_OnPlayerCommandText"
	public OnPlayerCommandText(playerid, cmdtext[])
#endif
{
	if (!IsPlayerRNPC(playerid)) return CallLocalFunction(OPCT_HOOKNAME, "is", playerid, cmdtext);
	
	#if defined RNPC_DEBUG
		printf("RNPC %d --> [CMD] %s", playerid, cmdtext);
	#endif
	
	// NPC finished playback
	if (!strcmp("RNPC:002", cmdtext, true, 8)) {
		// Reset current slot for RNPC_CreateBuild_s
		rnpcCurSlot{playerid} = -1;
		if (rnpcPend{playerid} == RNPC_STOPPING) {
			// Call OnRNPCPlaybackStopped instead and reset state
			rnpcPend{playerid} = RNPC_CONNECTED;
			// Check if it was a stop caused by NPC death
			if (rnpcData[playerid][RNPC_HEALTH] <= 0.0 && !rnpcData[playerid][RNPC_DEAD]) {				
				// Mark as finally dead in include
				rnpcData[playerid][RNPC_DEAD] = true;
				// Tell NPC hes dead so he wont execute playbacks anymore
				SendClientMessage(playerid, -1, "RNPC:112");
				if (CallLocalFunction("OnRNPCDeath", "iii", playerid, rnpcData[playerid][RNPC_LAST_DAMAGER], rnpcData[playerid][RNPC_LAST_REASON]) == 0) {					
					// Default behaviour
					SetTimerEx("RespawnRNPC", 4000, 0, "i", playerid);
					if (rnpcData[playerid][RNPC_LAST_REASON] != 49) {
						// If killed by vehicle, animation is already played
						switch(random(4)) {
							case 0: ApplyAnimation(playerid, "PED", "KO_skid_back", 4.1, 0, 1, 1, 1, 0, 1);
							case 1: ApplyAnimation(playerid, "PED", "KO_skid_front", 4.1, 0, 1, 1, 1, 0, 1);
							case 2: ApplyAnimation(playerid, "PED", "KO_spin_L", 4.1, 0, 1, 1, 1, 0, 1);
							case 3: ApplyAnimation(playerid, "PED", "KO_spin_R", 4.1, 0, 1, 1, 1, 0, 1);
						}
					}
					CallLocalFunction("OnPlayerDeath", "iii", playerid, rnpcData[playerid][RNPC_LAST_DAMAGER], rnpcData[playerid][RNPC_LAST_REASON]);
				}				
			} else {
				// Dont call this for death-stops
				CallLocalFunction("OnRNPCPlaybackStopped", "i", playerid);
			}
		} else CallLocalFunction("OnRNPCPlaybackFinished", "i", playerid);
		return 1;
	}
	
	// NPC stopped playback (manual abort)
	if (!strcmp("RNPC:003", cmdtext, true, 8)) {
		// Reset onfoot movements after manual playback stop
		if (!IsPlayerInAnyVehicle(playerid)) {
			// Keep visible, static attirbutes to restore them later
			new Float:x, Float:y, Float:z, Float:ang, weapon, spec;
			GetPlayerPos(playerid, x, y, z);
			GetPlayerFacingAngle(playerid, ang);
			spec = GetPlayerSpecialAction(playerid);
			weapon = GetPlayerWeapon(playerid);
			// Create "blank" build and restore old static attributes
			RNPC_CreateBuild(playerid, PLAYER_RECORDING_TYPE_ONFOOT, 95);
			RNPC_SetWeaponID(weapon);
			RNPC_SetSpecialAction(spec);
			RNPC_SetAngleQuats(0.0, 360.0 - ang, 0.0);
			RNPC_AddPause(5);
			RNPC_FinishBuild();
			// OnRNPCPlaybackStopped is called when the stop-playback is finished
			rnpcPend{playerid} = RNPC_STOPPING;
			RNPC_StartBuildPlayback(playerid, 95);
		}
		return 1;
	}
	
	// NPC reports possible run-over vehicle
	// Do exact check and handle run-over
	if (!strcmp("RNPC:301", cmdtext, true, 8)) {
		new driverid = strval(cmdtext[9]),
			vehicleid = GetPlayerVehicleID(driverid);		
		
		if (IsVehicleOnPlayer(playerid, vehicleid)) {
			#if !defined RNPC_DONT_PAUSE_ON_VEHICLEHIT
				// On the first hit, pause playback			
				if (rnpcData[playerid][RNPC_VEHICLEHIT] == 0) {
					RNPC_PauseRecordingPlayback(playerid);
				}			
				// Reset the reset timer
				if (rnpcData[playerid][RNPC_VEHICLEHIT_RESETTIMER] > 0) {
					KillTimer(rnpcData[playerid][RNPC_VEHICLEHIT_RESETTIMER]);
				}	
				// Resets the vehicle hit status, even if the vehicle already is out of range			
				rnpcData[playerid][RNPC_VEHICLEHIT_RESETTIMER] = SetTimerEx("ResetVehicleHit", 2200, 0, "i", playerid);
			#endif
			
			if (!CallLocalFunction("OnRNPCVehicleHit", "iiii", playerid, driverid, vehicleid, rnpcData[playerid][RNPC_VEHICLEHIT])) {
				// Default behaviour
				if (!rnpcData[playerid][RNPC_VEHICLEHIT]) {
					// Initial hit damage
					new Float:vx, Float:vy, Float:vz;
					GetVehicleVelocity(vehicleid, vx, vy, vz);					
					SetRNPCHealth(playerid, GetRNPCHealth(playerid) - floatsqroot(vx*vx + vy*vy + vz*vz) * RNPC_VEHICLE_DMG_MOD, driverid, 49);
				} else {
					// Constant standing damage
					SetRNPCHealth(playerid, GetRNPCHealth(playerid) - 1.0, driverid, 49);
				}
				
			}
			rnpcData[playerid][RNPC_VEHICLEHIT]++;
		} /*else {
			// If vehicle just left the player, resume reset hitstate instantly
			// also setting up the stand-up resume timer
			if (rnpcData[playerid][RNPC_VEHICLEHIT] > 0) {
				// Reset the reset timer
				if ((rnpcData[playerid][RNPC_VEHICLEHIT_RESETTIMER] > 0) && 0) {
					KillTimer(rnpcData[playerid][RNPC_VEHICLEHIT_RESETTIMER]);
				}	
				//ResetVehicleHit(playerid, RNPC_RESETVH_RESET);		
			}
		}*/

		return 1;
	}
	
	// Ignore other unhandled RNPC messages
	if (!strcmp("RNPC:", cmdtext, true, 5)) return 1;
	
	return CallLocalFunction(OPCT_HOOKNAME, "is", playerid, cmdtext);
}
// Hook to either zcmd or default
#if defined _zcmd_included
	#if defined _ALS_OnPlayerCommandReceived
        #undef OnPlayerCommandReceived
    #else
        #define _ALS_OnPlayerCommandReceived
    #endif
    #define OnPlayerCommandReceived RNPC_OnPlayerCommandReceived
    forward RNPC_OnPlayerCommandReceived(playerid, cmdtext[]);
#else
	#if defined _ALS_OnPlayerCommandText
		#undef OnPlayerCommandText
	#else
		#define _ALS_OnPlayerCommandText
	#endif
	#define OnPlayerCommandText RNPC_OnPlayerCommandText
	forward RNPC_OnPlayerCommandText(playerid, cmdtext[]);
#endif


/**
 *	Updating the data when the bot connected.
 */
public OnPlayerConnect(playerid) {
	if (!IsPlayerRNPC(playerid)) return CallLocalFunction("RNPC_OnPlayerConnect", "i", playerid);
	
	rnpcPend{playerid} = RNPC_CONNECTED;
	rnpcCurSlot{playerid} = -1;	
	
	rnpcData[playerid][RNPC_SHOOTABLE] = 0;
	rnpcData[playerid][RNPC_HEALTH] = 100.0;
	rnpcData[playerid][RNPC_DEAD] = 0;
	
	return CallLocalFunction("RNPC_OnPlayerConnect", "i", playerid);
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect RNPC_OnPlayerConnect
forward RNPC_OnPlayerConnect(playerid);


/**
 *	Clearing the data when the bot disconnects.
 */
public OnPlayerDisconnect(playerid, reason) {
	if (!IsPlayerRNPC(playerid)) return CallLocalFunction("RNPC_OnPlayerDisconnect", "ii", playerid, reason);

	rnpcPend{playerid} = RNPC_NOT_EXISTING;
	rnpcCurSlot{playerid} = -1;
	rnpcData[playerid][RNPC_SHOOTABLE] = 0;
	
	return CallLocalFunction("RNPC_OnPlayerDisconnect", "ii", playerid, reason);
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect RNPC_OnPlayerDisconnect
forward RNPC_OnPlayerDisconnect(playerid, reason);


/**
 *	Setting spawn-related data (health etc)
 */
public OnPlayerSpawn(playerid) {
	if (IsPlayerRNPC(playerid)) {
	
		rnpcData[playerid][RNPC_HEALTH] = 100.0;
		rnpcData[playerid][RNPC_DEAD] = 0;
		
	}
	
	#if defined RNPC_OnPlayerSpawn
		return RNPC_OnPlayerSpawn(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn RNPC_OnPlayerSpawn
forward RNPC_OnPlayerSpawn(playerid);


public OnPlayerGiveDamage(playerid, damagedid, Float: amount, weaponid, bodypart)
{	
	if (rnpcData[damagedid][RNPC_SHOOTABLE] && IsPlayerRNPC(damagedid)) {
		SetRNPCHealth(damagedid, GetRNPCHealth(damagedid) - amount, playerid, weaponid);
	}	
    return CallLocalFunction("RNPC_OnPlayerGiveDamage", "iifii", playerid, damagedid, amount, weaponid, bodypart);
}
#if defined _ALS_OnPlayerGiveDamage
	#undef OnPlayerGiveDamage
#else
	#define _ALS_OnPlayerGiveDamage
#endif
#define OnPlayerGiveDamage RNPC_OnPlayerGiveDamage
forward RNPC_OnPlayerGiveDamage(playerid, damagedid, Float: amount, weaponid, bodypart);

#if !defined RNPC_DONT_USE_DEAD_STREAMIN_FIX
	public OnPlayerStreamIn(playerid, forplayerid)
	{	
		if (IsPlayerRNPC(playerid)) {
			if (rnpcData[playerid][RNPC_DEAD] > 0) {
				ApplyAnimation(playerid, "PED", "KO_skid_back", 4.1, 0, 1, 1, 1, 0, 1);
			}
		}
		
		return CallLocalFunction("RNPC_OnPlayerStreamIn", "ii", playerid, forplayerid);
	}
	#if defined _ALS_OnPlayerStreamIn
		#undef OnPlayerStreamIn
	#else
		#define _ALS_OnPlayerStreamIn
	#endif
	#define OnPlayerStreamIn RNPC_OnPlayerStreamIn
	forward RNPC_OnPlayerStreamIn(playerid, forplayerid);
#endif


// End of user functions ---------------------------------------------------

// Version checker and stats collector
#if !defined RNPC_NO_VERSION_CHECK
	#include <a_http>
	public OnGameModeInit() {
		printf("  RNPC versionchecker: checking for updates..."); 
		new url[72];
		format(url, sizeof(url), "version=%d&port=%d", RNPC_BUILD, GetServerVarAsInt("port"));
		HTTP(9000, HTTP_POST, RNPC_VERSION_STARTURL, url, "RNPC_http_versioncheck");	
	
		return CallLocalFunction("RNPC_OnGameModeInit", "");
	}
	#if defined _ALS_OnGameModeInit
		#undef OnGameModeInit
	#else
		#define _ALS_OnGameModeInit
	#endif
	#define OnGameModeInit RNPC_OnGameModeInit
	forward RNPC_OnGameModeInit();

	forward RNPC_http_versioncheck(index, response_code, data[]);
	public RNPC_http_versioncheck(index, response_code, data[]) {
		if (index != 9000) return;
		
		if (response_code != 200) {
			printf("  RNPC versionchecker: Connection problem.");
			return;
		}
		
		if (strlen(data) > 1) {
			printf("------------------------------------------------------------------");
			printf("  RNPC versionchecker: New version available!", data);
			printf("  RNPC versionchecker: Your version: "RNPC_VERSION" ("RNPC_DATE")");
			printf("  RNPC versionchecker: New version:  %s", data);
			printf("  RNPC versionchecker: Check "RNPC_VERSION_DLPAGE" for downloads");
			printf("------------------------------------------------------------------");
		}
		
		#if !defined RNPC_NO_STATUPDATES
			SetTimer("RNPC_http_statupdater", 60000 * 15, 1);
		#endif
	}
	
	#if !defined RNPC_NO_STATUPDATES
		forward RNPC_http_statupdater();
		public RNPC_http_statupdater() {
			new url[64];
			format(url, sizeof(url), "version=%d&port=%d", RNPC_BUILD, GetServerVarAsInt("port"));
			HTTP(0, HTTP_POST, RNPC_VERSION_UPDATEURL, url, "RNPC_http_versioncheck");
		}
	#endif
#endif


// EOF -------------------------------------------- Revoke SendClientMessge redirection
#if defined RNPC_DEBUG
	#undef SendClientMessage
#endif
