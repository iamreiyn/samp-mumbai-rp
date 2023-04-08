/* ARNPC Advanced Recordfree NPC - Created by TheArcher
								 - Thanks to Mauzen, Joe Staff & Y_Less
			-Beta version
*/

#include <a_samp>
#include <rnpc>
#if !defined _INC_y_hooks
	#include <YSI\y_hooks>
#endif

/* Fake natives 

// core
native CreateRNPC(npcname[])
native DestroyRNPC(npcid)
native IsPlayerRNPC(npcid)
native GetRNPCID(npcid)
native GetRNPCState(npcid)
native GetRNPCName(npcid)

// vehicle controls
native PutRNPCInVehicle(npcid, vehicleid, seatid) // not working with 0.2.1 plugin
native RemoveRNPCFromVehicle(npcid) // not working with 0.2.1 plugin
native SetRNPCVehicleSiren(npcid,vstate)
native GetRNPCVehicleSiren(npcid)

// on foot controls
native SetRNPCPos(npcid, Float:x, Float:y, Float:z)
native GetRNPCPos(npcid, &Float:x, &Float:y, &Float:z)
native MoveRNPC(npcid, Float:x, Float:y, Float:z, Float:speed) // taken from the original rnpc include
native SetRNPCFacingAngle(npcid, Float:angle)
native SetRNPCHealth(npcid, health) // remember the health value must be an integer and not working with 0.3 plugin
native GetRNPCHealth(npcid)
native SetRNPCArmour(npcid, armour) // remember the armour value must be an integer and not working with 0.3 plugin
native GetRNPCArmour(npcid)
native SetRNPCWeapon(npcid, weaponid)
native GetRNPCWeapon(npcid)
native SetRNPCSkillLevel(npcid, skill, level)

// npc actions
native RNPCWalkTo(npcid,Float:X,Float:Y,Float:Z);
native RNPCRunTo(npcid,Float:X,Float:Y,Float:Z);
native RNPCSprintTo(npcid,Float:X,Float:Y,Float:Z);
native RNPCAimAt(npcid,Float:X,Float:Y);
native RNPCShotAt(npcid,Float:X,Float:Y);
native RNPCStopUseWeapon(npcid);
native RNPCDriveTo(npcid,Float:X,Float:Y,Float:Z,Float:speed);
native RNPCFollowPlayer(npcid, targetid, movemode = RNPC_SPEED_SPRINT)

// .rec part
native RNPC_StartPlayback(npcid, rec[])
native RNPC_StopPlayback(npcid)
native RNPC_StartBuildPlayback(npcid, slot=0, vehicleid=0)

*/

#if !defined MAX_RNPC
	#define MAX_RNPC        (500) // Be sure that the value is the same as "maxnpc" from server.cfg file
#endif

#define RNPC_STATE_ONFOOT						1
#define RNPC_STATE_DRIVER						2
#define RNPC_STATE_PASSANGER					3 // bugged from the plugin

#define RNPC_FOLLOWING_TIME						(300) // rememeber its ms

#define RNPC_SIREN_STATE_ON						(1)
#define RNPC_SIREN_STATE_OFF					(0)

forward OnRNPCCreated(npcid);
forward OnRNPCDestroyed(npcid);
forward OnRNPCSpawn(npcid);
//forward OnRNPCPlaybackFinished(npcid); // it's usable but already called so DO NOT uncomment this
forward OnRNPCDeath(npcid);

//new bool:RNPC_Connected[MAX_RNPC] = false;

// Here's is sightly Mauzen's include modified, credits goes to him :)
enum RNPC_enum {
	bool:RNPC_Connected = false,
	RNPC_ID,
	RNPC_CONNECTION,
	RNPC_NAME[24],
	RNPC_SKIN, // Since GetPlayerSkin is not detected on NPC I will do it using this variable and storing a value on it.
	RNPC_HEALTH,
	RNPC_ARMOUR,
	Float:RNPC_ANGLE,
	RNPC_WEAPONID,
	RNPC_SIREN_STATE
};

// Initial data
new rnpc_Data[MAX_RNPC][RNPC_enum];

stock CreateRNPC(name[])
{
	new slot = -1;
	for (new i = 0; i < MAX_RNPC; i++) {
		if (!IsPlayerConnected(i) && rnpc_Data[i][RNPC_Connected] == false) {
			slot = i;
			break;
		}
	}
	rnpc_Data[slot][RNPC_CONNECTION] = ConnectNPC(name, "RNPC");
	rnpc_Data[slot][RNPC_Connected] = true;
	rnpc_Data[slot][RNPC_ID] = slot;
	format(rnpc_Data[slot][RNPC_NAME], 24, "%s", name);
	
	SetTimerEx("Fix_RNPCConnect", 450, false, "i", slot); //
	return slot;
}

forward Fix_RNPCConnect(npcid);
public Fix_RNPCConnect(npcid) CallLocalFunction("OnRNPCCreated", "i", npcid); // Fixes the issue when the script detects the NPC connected before it does

stock DestroyRNPC(npcid)
{
	if(IsPlayerRNPC(npcid)) {
		RNPC_CreateBuild(npcid, PLAYER_RECORDING_TYPE_ONFOOT);
		RNPC_FinishBuild();
		RNPC_StartBuildPlayback(npcid);
		rnpc_Data[npcid][RNPC_HEALTH] = 0;
		rnpc_Data[npcid][RNPC_ARMOUR] = 0;
		rnpc_Data[npcid][RNPC_ANGLE] = 0.0;
		rnpc_Data[npcid][RNPC_WEAPONID] = 0;
		rnpc_Data[npcid][RNPC_SIREN_STATE] = 0;
		Kick(rnpc_Data[npcid][RNPC_CONNECTION]);
	}
}

//stock IsPlayerRNPC(npcid) return rnpc_Data[npcid][RNPC_Connected] ? true : false;
stock IsPlayerRNPC(npcid)
	return (IsPlayerConnected(npcid) && rnpc_Data[npcid][RNPC_Connected] == true && IsPlayerNPC(npcid));

stock GetRNPCID(npcid) return rnpc_Data[npcid][RNPC_ID];

stock GetRNPCState(npcid) {
	if(IsPlayerRNPC(npcid)) return GetPlayerState(npcid), \
	printf(" ARNPC Debug: npcid %d has the state %d", npcid, GetPlayerState(npcid));
	return -1;
}

stock PutRNPCInVehicle(npcid, vehicleid, seatid)
{
	if(IsPlayerRNPC(npcid))
		SetTimerEx("PutRNPCInVehicle_Fix", 500, 0, "iii", npcid, vehicleid, seatid); 
	printf(" ARNPC Debug: npcid %d was put in vehicleid %d and seatid %d ", npcid, vehicleid, seatid);
}

stock RemoveRNPCFromVehicle(npcid)
{
	if(IsPlayerRNPC(npcid)) {
		if(IsPlayerInAnyVehicle(npcid)) {
			RemovePlayerFromVehicle(npcid);
		}
	}	
}		

forward PutRNPCInVehicle_Fix(npcid, vehicleid, seatid);
public PutRNPCInVehicle_Fix(npcid, vehicleid, seatid) { //Thanks to Mauzen once again :3
    // Make him enter the vehicle again, this fixed some problems for me
    // when the vehicle is far away and not streamed in for the npc
    PutPlayerInVehicle(npcid, vehicleid, seatid);
    RNPC_CreateBuild(npcid, PLAYER_RECORDING_TYPE_DRIVER);
    RNPC_AddPause(250);
    RNPC_FinishBuild();
    RNPC_StartBuildPlayback(npcid);
}

stock SetRNPCPos(npcid, Float:x, Float:y, Float:z)
{
	if(IsPlayerRNPC(npcid))
		SetPlayerPos(npcid, x,y,z);
}

stock GetRNPCPos(npcid, &Float:x, &Float:y, &Float:z) 
{
	if((IsPlayerRNPC(npcid)) GetPlayerPos(npcid, x,y,z);
	printf(" ARNPC Debug: npcid %d has the pos %f %f %f", npcid, x,y,z);
}

stock SetRNPCSkin(npcid, skin)
{
	if(IsPlayerRNPC(npcid))
	{
		if(IsValidRNPCSkin(skin))
		{
			new temp_weapon = GetRNPCWeapon(npcid);
			if(IsPlayerInAnyVehicle(npcid)) {
				RNPC_CreateBuild(npcid, PLAYER_RECORDING_TYPE_DRIVER);
				SetPlayerSkin(npcid, skin);
				if(temp_weapon != 0) RNPC_SetWeaponID(temp_weapon);
				RNPC_FinishBuild();
			} else {
				RNPC_CreateBuild(npcid, PLAYER_RECORDING_TYPE_ONFOOT);
				SetPlayerSkin(npcid, skin);
				if(temp_weapon != 0) RNPC_SetWeaponID(temp_weapon);
				RNPC_FinishBuild();
			}
			RNPC_StartBuildPlayback(npcid);
			rnpc_Data[npcid][RNPC_SKIN] = skin;
		}	
	}
}

stock GetRNPCSkin(npcid) return rnpc_Data[npcid][RNPC_SKIN];

stock SetRNPCFacingAngle(npcid,Float:angle)
{
	if(IsPlayerRNPC(npcid))
	{
		if(IsPlayerInAnyVehicle(npcid)) return false; // prevent unusable angle facing in vehicles
		RNPC_CreateBuild(npcid, PLAYER_RECORDING_TYPE_ONFOOT);
		RNPC_SetAngleQuats(0.0, angle, 0.0);
		RNPC_FinishBuild();
		RNPC_StartBuildPlayback(npcid);
		rnpc_Data[npcid][RNPC_ANGLE] = angle;
		printf(" ARNPC Debug: NPCID %d has set the angle %f ", npcid, angle);
	}
	return true;
}
					
stock Float:GetNPCFacingAngle(npcid) // not working well yet
{
	if(rnpc_Data[npcid][RNPC_Connected] == true)
		return rnpc_Data[npcid][RNPC_ANGLE];
		//printf(" ARNPC Debug: NPCID %d has set the angle %f ", npcid, GetNPCFacingAngle(npcid));
	return 0.0;
}
	

// Took from a pastebin link (Idk who's original author :/ )
stock IsValidRNPCSkin(skinid)
{
    #define	MAX_BAD_SKINS 22
    new badSkins[MAX_BAD_SKINS] =
    {
        3, 4, 5, 6, 8, 42, 65, 74, 86,
        119, 149, 208, 265, 266, 267,
        268, 269, 270, 271, 272, 273, 289
    };
    if (skinid < 0 || skinid > 299) return false;
    for (new i = 0; i < MAX_BAD_SKINS; i++)
    {
        if (skinid == badSkins[i]) return false;
    }
    #undef MAX_BAD_SKINS
    return 1;
}

stock GetRNPCName(npcid) // Thanks to Lorenc_
{
    static p_Name[24] = "Invalid_NPC_ID";
    format(p_Name, 24, "%s", rnpc_Data[npcid][RNPC_NAME]);
    return p_Name;
}

stock GetRNPCSurfingVehicle(npcid) // I just tried something but lol not working.
{
	if(IsPlayerRNPC(npcid)) return GetPlayerSurfingVehicleID(npcid);
	return INVALID_PLAYER_ID;
}

stock SetRNPCHealth(npcid, hp) // Float is not support yet by rnpc plugin native yet
{
	if(IsPlayerRNPC(npcid))
	{
		RNPC_StopPlayback(npcid);
		new State = GetRNPCState(npcid);
		if(State == RNPC_STATE_ONFOOT)
		{
			RNPC_CreateBuild(npcid, PLAYER_RECORDING_TYPE_ONFOOT);
			RNPC_SetHealth(hp);
			RNPC_FinishBuild();
			if(hp <= 0) CallLocalFunction("OnRNPCDeath", "i", npcid);
		}
		else
		if(State == RNPC_STATE_DRIVER || RNPC_STATE_PASSANGER)
		{
			RNPC_CreateBuild(npcid, PLAYER_RECORDING_TYPE_DRIVER);
			RNPC_SetDriverHealth(hp);
			RNPC_FinishBuild();
			if(hp <= 0) CallLocalFunction("OnRNPCDeath", "i", npcid);
		}
		rnpc_Data[npcid][RNPC_HEALTH] = hp;
		RNPC_StartBuildPlayback(npcid);
	}
}	

stock SetRNPCArmour(npcid, armour) // Float is not support yet by rnpc plugin native yet
{
	if(IsPlayerRNPC(npcid))
	{
		RNPC_StopPlayback(npcid);
		new State = GetRNPCState(npcid);
		if(State == RNPC_STATE_ONFOOT)
		{
			RNPC_CreateBuild(npcid, PLAYER_RECORDING_TYPE_ONFOOT);
			RNPC_SetArmour(armour);
			RNPC_FinishBuild();
		}
		else
		if(State == RNPC_STATE_DRIVER || RNPC_STATE_PASSANGER)
		{
			RNPC_CreateBuild(npcid, PLAYER_RECORDING_TYPE_DRIVER);
			RNPC_SetArmour(armour);
			RNPC_FinishBuild();
		}
		rnpc_Data[npcid][RNPC_ARMOUR] = armour;
		RNPC_StartBuildPlayback(npcid);
	}
}	

stock GetRNPCHealth(npcid) return rnpc_Data[npcid][RNPC_HEALTH];
stock GetRNPCArmour(npcid) return rnpc_Data[npcid][RNPC_ARMOUR];

stock SetRNPCWeapon(npcid, weaponid)
{
	if(IsPlayerRNPC(npcid))
	{
		RNPC_CreateBuild(npcid, PLAYER_RECORDING_TYPE_ONFOOT);
		RNPC_SetWeaponID(weaponid);
		RNPC_FinishBuild();
		RNPC_StartBuildPlayback(npcid);
		rnpc_Data[npcid][RNPC_WEAPONID] = weaponid;
	}
}	

stock GetRNPCWeapon(npcid) return rnpc_Data[npcid][RNPC_WEAPONID];

stock RNPCWalkTo(npcid,Float:X,Float:Y,Float:Z)
{
	if(IsPlayerRNPC(npcid))
	{
		new Float:SPos[3];
		GetPlayerPos(npcid, SPos[0], SPos[1], SPos[2]);
		RNPC_CreateBuild(npcid, PLAYER_RECORDING_TYPE_ONFOOT);
		if(GetRNPCWeapon(npcid) != 0) RNPC_SetWeaponID(GetRNPCWeapon(npcid));
		RNPC_AddMovement(SPos[0], SPos[1], SPos[2], X, Y, Z, RNPC_SPEED_WALK);
		RNPC_FinishBuild();
		RNPC_StartBuildPlayback(npcid);
	}
}	

stock RNPCRunTo(npcid,Float:X,Float:Y,Float:Z)
{
	if(IsPlayerRNPC(npcid))
	{
		new Float:SPos[3];
		GetPlayerPos(npcid, SPos[0], SPos[1], SPos[2]);
		RNPC_CreateBuild(npcid, PLAYER_RECORDING_TYPE_ONFOOT);
		if(GetRNPCWeapon(npcid) != 0) RNPC_SetWeaponID(GetRNPCWeapon(npcid));
		RNPC_AddMovement(SPos[0], SPos[1], SPos[2], X, Y, Z, RNPC_SPEED_RUN);
		RNPC_FinishBuild();
		RNPC_StartBuildPlayback(npcid);
	}
}

stock RNPCSprintTo(npcid,Float:X,Float:Y,Float:Z)
{
	if(IsPlayerRNPC(npcid))
	{
		new Float:SPos[3];
		GetPlayerPos(npcid, SPos[0], SPos[1], SPos[2]);
		RNPC_CreateBuild(npcid, PLAYER_RECORDING_TYPE_ONFOOT);
		if(GetRNPCWeapon(npcid) != 0) RNPC_SetWeaponID(GetRNPCWeapon(npcid));
		RNPC_AddMovement(SPos[0], SPos[1], SPos[2], X, Y, Z, RNPC_SPEED_SPRINT);
		RNPC_FinishBuild();
		RNPC_StartBuildPlayback(npcid);
	}
}

stock RNPCFollowPlayer(npcid, targetid, Float:movemode = RNPC_SPEED_SPRINT)
{
	if(IsPlayerRNPC(npcid)) SetTimerEx("FollowPlayer", RNPC_FOLLOWING_TIME, true, "iif", npcid, targetid, movemode);
}

forward FollowPlayer(npcid, targetid, Float:movemode);
public FollowPlayer(npcid, targetid, Float:movemode)
{
	static Float:x, Float:y, Float:z;
    GetPlayerPos(targetid, x, y, z);
	switch(movemode)
	{
		case RNPC_SPEED_SPRINT: MoveRNPC(npcid, x, y, z, RNPC_SPEED_SPRINT);
		case RNPC_SPEED_RUN: MoveRNPC(npcid, x, y, z, RNPC_SPEED_RUN);
		case RNPC_SPEED_WALK: MoveRNPC(npcid, x, y, z, RNPC_SPEED_WALK);
	}
}

stock SetRNPCSkillLevel(npcid, skill, level)
{
	if(IsPlayerRNPC(npcid))
		SetPlayerSkillLevel(npcid, skill, level);
}

stock SetRNPCVehicleSiren(npcid,vstate)
{
	if(IsPlayerRNPC(npcid))
	{
		RNPC_CreateBuild(npcid, PLAYER_RECORDING_TYPE_DRIVER);
		switch(vstate) {
			case RNPC_SIREN_STATE_OFF: RNPC_SetSirenState(RNPC_SIREN_STATE_OFF), rnpc_Data[npcid][RNPC_SIREN_STATE] = 0;
			case RNPC_SIREN_STATE_ON: RNPC_SetSirenState(RNPC_SIREN_STATE_ON), rnpc_Data[npcid][RNPC_SIREN_STATE] = 1;
		}
		RNPC_FinishBuild();
		RNPC_StartBuildPlayback(npcid);
	}
}

stock GetRNPCVehicleSiren(npcid) return rnpc_Data[npcid][RNPC_SIREN_STATE];

stock RNPCShotAt(npcid, Float:x, Float:y)
{
	if(IsPlayerRNPC(npcid))
	{
		if(GetRNPCWeapon(npcid) != 0) {
			new Float:ox, Float:oy, Float:oz;
            GetPlayerPos(npcid, ox, oy, oz);
			new Float:angle = atan2(ox - x, oy - y) + randomNums(175, 180);
			RNPC_CreateBuild(npcid, PLAYER_RECORDING_TYPE_ONFOOT);
			RNPC_SetWeaponID(GetRNPCWeapon(npcid));
			RNPC_SetAngleQuats(0.0, angle, 0.0);
			RNPC_SetKeys(KEY_FIRE);
			RNPC_FinishBuild();
			RNPC_StartBuildPlayback(npcid);
		}
	}		
}

stock RNPCAimAt(npcid, Float:x, Float:y)
{
	if(IsPlayerRNPC(npcid))
	{
		if(GetRNPCWeapon(npcid) != 0) {
			new Float:ox, Float:oy, Float:oz;
            GetPlayerPos(npcid, ox, oy, oz);
			new Float:angle = atan2(ox - x, oy - y) + 177.0;
			RNPC_CreateBuild(npcid, PLAYER_RECORDING_TYPE_ONFOOT);
			RNPC_SetWeaponID(GetRNPCWeapon(npcid));
			RNPC_SetAngleQuats(0.0, angle, 0.0);
			RNPC_SetKeys(128);
			RNPC_FinishBuild();
			RNPC_StartBuildPlayback(npcid);
		}
	}		
}

stock RNPCStopUseWeapon(npcid)
{
	if(IsPlayerRNPC(npcid))
	{
		RNPC_CreateBuild(npcid, PLAYER_RECORDING_TYPE_ONFOOT);
		RNPC_SetWeaponID(GetRNPCWeapon(npcid));
		RNPC_SetKeys(0);
		RNPC_FinishBuild();
		RNPC_StartBuildPlayback(npcid);
	}
}

// extra functions

// Thanks Y_Less :)
stock randomNums(min, max)
{  
    new rand = random(max-min)+min;    
    return rand;
}

//took SuperViper version
stock Float: GetDistanceBetweenRNPC(p1, p2)
{
	new Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2;
	GetPlayerPos(p1,x1,y1,z1);
	GetPlayerPos(p2,x2,y2,z2);
	return floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));
}

// sightly modify version of JernejL
stock Float:DistanceCameraTargetToLocation(Float:CamX, Float:CamY, Float:CamZ, Float:ObjX, Float:ObjY, Float:ObjZ, Float:FrX, Float:FrY, Float:FrZ) 
{

        new Float:TGTDistance;

        // get distance from camera to target
        TGTDistance = sqrt((CamX - ObjX) * (CamX - ObjX) + (CamY - ObjY) * (CamY - ObjY) + (CamZ - ObjZ) * (CamZ - ObjZ));

        new Float:tmpX, Float:tmpY, Float:tmpZ;

        tmpX = FrX * TGTDistance + CamX;
        tmpY = FrY * TGTDistance + CamY;
        tmpZ = FrZ * TGTDistance + CamZ;

        return sqrt((tmpX - ObjX) * (tmpX - ObjX) + (tmpY - ObjY) * (tmpY - ObjY) + (tmpZ - ObjZ) * (tmpZ - ObjZ));
}

//Hooking part

forward OnPlayerConnect_Fix(playerid);
public OnPlayerConnect_Fix(playerid)
{
	RNPC_CreateBuild(playerid, PLAYER_RECORDING_TYPE_ONFOOT);
	RNPC_SetHealth(100);
	RNPC_SetArmour(100);
	RNPC_SetAngleQuats(0.0, 90.0, 0.0);
	RNPC_FinishBuild();
	RNPC_StartBuildPlayback(playerid);
	rnpc_Data[playerid][RNPC_HEALTH] = 100;
	rnpc_Data[playerid][RNPC_ARMOUR] = 100;
	rnpc_Data[playerid][RNPC_ANGLE] = 90.0;
	rnpc_Data[playerid][RNPC_WEAPONID] = 0;
	rnpc_Data[playerid][RNPC_SIREN_STATE] = 0;
}

//Fix the bug if the NPC is going to disconnect somehow
hook: public OnPlayerConnect(playerid)
{
	if(!IsPlayerRNPC(playerid)) return 0;
	SetTimerEx("OnPlayerConnect_Fix", 500, 0, "i", playerid);
	printf(" OnPlayerConnect hook has called ");
	return 1;
}	

hook: public OnPlayerDisconnect(playerid, reason)
{
    if(IsPlayerRNPC(playerid)) 
	{
		rnpc_Data[playerid][RNPC_Connected] = false;
		rnpc_Data[playerid][RNPC_HEALTH] = 0;
		rnpc_Data[playerid][RNPC_ARMOUR] = 0;
		rnpc_Data[playerid][RNPC_ANGLE] = 0.0;
		rnpc_Data[playerid][RNPC_WEAPONID] = 0;
		CallLocalFunction("OnRNPCDestroyed", "i", playerid);
	}	
	print(" ARNPC Debug: OnPlayerDisconnect hook called for NPC");
}

hook: public OnPlayerSpawn(playerid)
{
	if(IsPlayerRNPC(playerid))	CallLocalFunction("OnRNPCSpawn", "i", playerid);
	print(" ARNPC Debug: OnPlayerSpawn hook called");
}

// Not fully tested yet.
hook: public OnRconCommand(cmd[])
{
    if(strfind(cmd,"gmx",true) != -1)
	{
		for(new i = 0; i < MAX_RNPC; i++)
		{
			if(!IsPlayerRNPC(i)) continue;
			DestroyRNPC(i);
		}
	}
	return 0;
}