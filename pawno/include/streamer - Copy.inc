/*
    SA-MP Streamer Plugin v2.3.3
    Copyright © 2009 Incognito

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#if defined _streamer_included
	#endinput
#endif
#define _streamer_included
#pragma library streamer

// Natives (settings)

native Streamer_TickRate(rate);
native Streamer_MaxObjects(objects);
native Streamer_MaxPickups(pickups);
native Streamer_MaxCPs(checkpoints);
native Streamer_MaxRaceCPs(checkpoints);
native Streamer_MaxMapIcons(icons);
native Streamer_Max3DTextLabels(labels);
native Streamer_VisibleObjects(objects);
native Streamer_VisiblePickups(pickups);
native Streamer_VisibleMapIcons(icons);
native Streamer_Visible3DTextLabels(labels);

// Natives (updates)

native Streamer_UpdateObjects(playerid);
native Streamer_UpdatePickups();
native Streamer_UpdateCPs(playerid);
native Streamer_UpdateRaceCPs(playerid);
native Streamer_UpdateMapIcons(playerid);
native Streamer_Update3DTextLabels(playerid);

// Natives (objects)

native CreateDynamicObject(modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, playerid = -1, Float:distance = 200.0);
native DestroyDynamicObject(objectid);
native SetDynamicObjectPos(objectid, Float:x, Float:y, Float:z);
native GetDynamicObjectPos(objectid, &Float:x, &Float:y, &Float:z);
native SetDynamicObjectRot(objectid, Float:rx, Float:ry, Float:rz);
native GetDynamicObjectRot(objectid, &Float:rx, &Float:ry, &Float:rz);
native IsValidDynamicObject(objectid);
native MoveDynamicObject(objectid, Float:x, Float:y, Float:z, Float:speed);
native StopDynamicObject(objectid);
native DestroyAllDynamicObjects();
native CountDynamicObjects();

// Natives (pickups)

native CreateDynamicPickup(modelid, type, Float:x, Float:y, Float:z, worldid = -1, interiorid = -1, playerid = -1, Float:distance = 100.0);
native DestroyDynamicPickup(pickupid);
native DestroyAllDynamicPickups();
native CountDynamicPickups();

// Natives (checkpoints)

native CreateDynamicCP(Float:x, Float:y, Float:z, Float:size, worldid = -1, interiorid = -1, playerid = -1, Float:distance = 100.0);
native DestroyDynamicCP(checkpointid);
native TogglePlayerDynamicCP(playerid, checkpointid, toggle);
native TogglePlayerAllDynamicCPs(playerid, toggle);
native IsPlayerInDynamicCP(playerid, checkpointid);
native DestroyAllDynamicCPs();
native CountDynamicCPs();

// Natives (race checkpoints)

native CreateDynamicRaceCP(type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, Float:size, worldid = -1, interiorid = -1, playerid = -1, Float:distance = 100.0);
native DestroyDynamicRaceCP(checkpointid);
native TogglePlayerDynamicRaceCP(playerid, checkpointid, toggle);
native TogglePlayerAllDynamicRaceCPs(playerid, toggle);
native IsPlayerInDynamicRaceCP(playerid, checkpointid);
native DestroyAllDynamicRaceCPs();
native CountDynamicRaceCPs();

// Natives (map icons)

native CreateDynamicMapIcon(Float:x, Float:y, Float:z, markertype, color, worldid = -1, interiorid = -1, playerid = -1, Float:distance = 100.0);
native DestroyDynamicMapIcon(iconid);
native DestroyAllDynamicMapIcons();
native CountDynamicMapIcons();

// Natives (3D text labels)

native Text3D:CreateDynamic3DTextLabel(text[], color, Float:x, Float:y, Float:z, Float:drawdistance, attachedplayer = INVALID_PLAYER_ID, attachedvehicle = INVALID_VEHICLE_ID, testlos = 0, worldid = -1, interiorid = -1, playerid = -1, Float:distance = 100.0);
native DestroyDynamic3DTextLabel(Text3D:id);
native UpdateDynamic3DTextLabelText(Text3D:id, color, text[]);
native DestroyAllDynamic3DTextLabels();
native CountDynamic3DTextLabels();

// Natives (internals)

native Streamer_AddPlayer(playerid);
native Streamer_RemovePlayer(playerid);
native Streamer_CheckPickup(playerid, pickupid);
native Streamer_RegisterInterface();

// Callbacks

forward OnDynamicObjectMoved(objectid);
forward OnPlayerPickUpDynamicPickup(playerid, pickupid);
forward OnPlayerEnterDynamicCP(playerid, checkpointid);
forward OnPlayerLeaveDynamicCP(playerid, checkpointid);
forward OnPlayerEnterDynamicRaceCP(playerid, checkpointid);
forward OnPlayerLeaveDynamicRaceCP(playerid, checkpointid);

// Automatic setup system
// Utilizes callback hooks

static
	bool:Streamer_g_OPC = false,
	bool:Streamer_g_OPDC = false,
	bool:Streamer_g_OPPP = false,
	bool:Streamer_g_RI = false;

public OnFilterScriptInit()
{
	if (!Streamer_g_RI)
	{
		Streamer_g_OPC = funcidx("Streamer_OnPlayerConnect") != -1;
		Streamer_g_OPDC = funcidx("Streamer_OnPlayerDisconnect") != -1;
		Streamer_g_OPPP = funcidx("Streamer_OnPlayerPickUpPickup") != -1;
		Streamer_g_RI = true;
		Streamer_RegisterInterface();
	}
	if (funcidx("Streamer_OnFilterScriptInit") != -1)
	{
		return CallLocalFunction("Streamer_OnFilterScriptInit", "");
	}
	return 1;
}

#if defined _ALS_OnFilterScriptInit
	#undef OnFilterScriptInit
#else
	#define _ALS_OnFilterScriptInit
#endif
#define OnFilterScriptInit Streamer_OnFilterScriptInit
forward Streamer_OnFilterScriptInit();

public OnGameModeInit()
{
	if (!Streamer_g_RI)
	{
		Streamer_g_OPC = funcidx("Streamer_OnPlayerConnect") != -1;
		Streamer_g_OPDC = funcidx("Streamer_OnPlayerDisconnect") != -1;
		Streamer_g_OPPP = funcidx("Streamer_OnPlayerPickUpPickup") != -1;
		Streamer_g_RI = true;
		Streamer_RegisterInterface();
	}
	if (funcidx("Streamer_OnGameModeInit") != -1)
	{
		return CallLocalFunction("Streamer_OnGameModeInit", "");
	}
	return 1;
}

#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit Streamer_OnGameModeInit
forward Streamer_OnGameModeInit();

public OnPlayerConnect(playerid)
{
	Streamer_AddPlayer(playerid);
	if (Streamer_g_OPC)
	{
		return CallLocalFunction("Streamer_OnPlayerConnect", "d", playerid);
	}
	return 1;
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect Streamer_OnPlayerConnect
forward Streamer_OnPlayerConnect(playerid);

public OnPlayerDisconnect(playerid, reason)
{
	Streamer_RemovePlayer(playerid);
	if (Streamer_g_OPDC)
	{
		return CallLocalFunction("Streamer_OnPlayerDisconnect", "dd", playerid, reason);
	}
	return 1;
}

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect Streamer_OnPlayerDisconnect
forward Streamer_OnPlayerDisconnect(playerid, reason);

public OnPlayerPickUpPickup(playerid, pickupid)
{
	Streamer_CheckPickup(playerid, pickupid);
	if (Streamer_g_OPPP)
	{
		return CallLocalFunction("Streamer_OnPlayerPickUpPickup", "dd", playerid, pickupid);
	}
	return 1;
}

#if defined _ALS_OnPlayerPickUpPickup
	#undef OnPlayerPickUpPickup
#else
	#define _ALS_OnPlayerPickUpPickup
#endif
#define OnPlayerPickUpPickup Streamer_OnPlayerPickUpPickup
forward Streamer_OnPlayerPickUpPickup(playerid, pickupid);

// Public function containing every native used by the streamer
// Necessary in order to invoke PAWN correctly in the plugin

forward Streamer_PublicFunction();
public Streamer_PublicFunction()
{
	new
		Float:value;
	CreatePickup(0, 0, 0.0, 0.0, 0.0, 0);
	CreatePlayer3DTextLabel(0, "", 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0);
	CreatePlayerObject(0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	DeletePlayer3DTextLabel(0, PlayerText3D:0);
	DestroyPickup(0);
	DestroyPlayerObject(0, 0);
	DisablePlayerCheckpoint(0);
	DisablePlayerRaceCheckpoint(0);
	GetPlayerInterior(0);
	GetPlayerObjectPos(0, 0, value, value, value);
	GetPlayerObjectRot(0, 0, value, value, value);
	GetPlayerPos(0, value, value, value);
	GetPlayerVirtualWorld(0);
	GetVehiclePos(0, value, value, value);
	MovePlayerObject(0, 0, 0.0, 0.0, 0.0, 0.0);
	RemovePlayerMapIcon(0, 0);
	SetPlayerCheckpoint(0, 0.0, 0.0, 0.0, 0.0);
	SetPlayerMapIcon(0, 0, 0.0, 0.0, 0.0, 0, 0);
	SetPlayerObjectPos(0, 0, 0.0, 0.0, 0.0);
	SetPlayerObjectRot(0, 0, 0.0, 0.0, 0.0);
	SetPlayerRaceCheckpoint(0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	StopPlayerObject(0, 0);
	UpdatePlayer3DTextLabelText(0, PlayerText3D:0, 0, "");
	return 1;
}
