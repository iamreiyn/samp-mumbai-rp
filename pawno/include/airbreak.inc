/*
 *  airbreak.inc - Airbreak detection!
 *  Created by Emmet of SA-MP forums.
 *
 *  Notes:
 *  This will need a lot of testing. This wasn't tested thoroughly.
 *  There is a callback that is called when a player airbreaks.
 *
 *  This Source Code Form is subject to the terms of the Mozilla Public
 *  License, v. 2.0. If a copy of the MPL was not distributed with this
 *  file, You can obtain one at [url]http://mozilla.org/MPL/2.0/[/url].
 *
 *  You may not sell this include.
 *  You may not claim this as your own.
 *  You may not redistribute without permission.
 *  You are free to do anything else with it.
*/
#if defined _airbreak_included
    #endinput
#endif
#define _airbreak_included

#include <a_samp>

#define MAX_VEHICLE_AIRBREAK  (200.0)
#define MAX_AIRBREAK_DISTANCE (15.0)

enum E_AIRBREAK_DATA
{
    Float:E_PLAYER_X[MAX_PLAYERS],
    Float:E_PLAYER_Y[MAX_PLAYERS],
    Float:E_PLAYER_Z[MAX_PLAYERS],
    E_AIRBREAK_TIMER
};
new E_AIRBREAK_ENUM[E_AIRBREAK_DATA];

new stock airbreakIndexes[] =
{
    1231, 1266, 1234, 1189,
    1235, 1136, 1196, 1197,
    1198, 1159, 1133, 1130,
    1129, 1208, 1156
};

#if defined FILTERSCRIPT
public OnFilterScriptInit()
{
    E_AIRBREAK_ENUM[E_AIRBREAK_TIMER] = SetTimer("AirbreakCheck", 1000, true);
    return CallLocalFunction("ab_OnFilterScriptInit", "");
}
#else
public OnGameModeInit()
{
    E_AIRBREAK_ENUM[E_AIRBREAK_TIMER] = SetTimer("AirbreakCheck", 1000, true);
    return CallLocalFunction("ab_OnGameModeInit", "");
}
#endif

stock Float:GetVehicleSpeed2(playerid)
{
    if (!IsPlayerInAnyVehicle(playerid)) return 0.0;
    new
        Float:vX,
        Float:vY,
        Float:vZ
    ;
    GetVehicleVelocity(GetPlayerVehicleID(playerid), vX, vY, vZ);
    return floatsqroot(floatpower(vX, 2) + floatpower(vY, 2) + floatpower(vZ, 2)) * 100;
}

forward AirbreakCheck();
public AirbreakCheck()
{
    new Float:x, Float:y, Float:z, index, Float:dist[4];
    for (new i = 0; i < MAX_PLAYERS; i ++)
    {
        if (!IsPlayerConnected(i)) continue;
        if (GetPVarInt(i, "CheckDelay"))
        {
            SetPVarInt(i, "CheckDelay", GetPVarInt(i, "CheckDelay") - 1);
            continue;
        }
        if (IsPlayerInAnyVehicle(i))
        {
            GetVehiclePos(GetPlayerVehicleID(i), x, y, z);
        }
        else GetPlayerPos(i, x, y, z);
        index = GetPlayerAnimationIndex(i);

        dist[0] = (E_AIRBREAK_ENUM[E_PLAYER_X][i] < x) ? E_AIRBREAK_ENUM[E_PLAYER_X][i] - x : x - E_AIRBREAK_ENUM[E_PLAYER_X][i];
        dist[1] = (E_AIRBREAK_ENUM[E_PLAYER_Y][i] < y) ? E_AIRBREAK_ENUM[E_PLAYER_Y][i] - y : y - E_AIRBREAK_ENUM[E_PLAYER_Y][i];
        dist[2] = (E_AIRBREAK_ENUM[E_PLAYER_Z][i] < z) ? E_AIRBREAK_ENUM[E_PLAYER_Z][i] - z : z - E_AIRBREAK_ENUM[E_PLAYER_Z][i];
        dist[3] = floatsqroot(floatpower(dist[0], 2.0) + floatpower(dist[1], 2.0) + floatpower(dist[2], 2.0));

        if (x == E_AIRBREAK_ENUM[E_PLAYER_X][i] && y == E_AIRBREAK_ENUM[E_PLAYER_Y][i] && z == E_AIRBREAK_ENUM[E_PLAYER_Z][i])
        {
            // Player is most likely AFK, so let's forget about checking that player.
            continue;
        }
        if (dist[3] > MAX_AIRBREAK_DISTANCE && !IsPlayerInAnyVehicle(i))
        {
            if (GetPlayerState(i) == PLAYER_STATE_ONFOOT)
            {
                for (new l = 0; l < sizeof(airbreakIndexes); l ++)
                {
                    if (index == airbreakIndexes[l])
                    {
                        if (!floatcmp(E_AIRBREAK_ENUM[E_PLAYER_Z][i], z))
                        {
                            if (funcidx("OnPlayerAirbreak") != -1)
                                CallLocalFunction("OnPlayerAirbreak", "d", i);
                        }
                    }
                }
            }
        }
        else if (dist[3] > MAX_VEHICLE_AIRBREAK && IsPlayerInAnyVehicle(i))
        {
            if (GetPlayerState(i) == PLAYER_STATE_DRIVER)
            {
                if (GetVehicleSpeed(i) >= 0.02 && GetVehicleSpeed(i) <= 0.15)
                {
                    if (funcidx("OnPlayerAirbreak") != -1)
                        CallLocalFunction("OnPlayerAirbreak", "d", i);
                }
            }
        }
        E_AIRBREAK_ENUM[E_PLAYER_X][i] = x;
        E_AIRBREAK_ENUM[E_PLAYER_Y][i] = y;
        E_AIRBREAK_ENUM[E_PLAYER_Z][i] = z;
    }
    return 1;
}

public OnEnterExitModShop(playerid, enterexit)
{
    if (enterexit)
    {
        SetPVarInt(playerid, "CheckDelay", 2);
    }
    else DeletePVar(playerid, "CheckDelay");
    return CallLocalFunction("ab_OnEnterExitModShop", "dd", playerid, enterexit);
}
#if defined _ALS_OnEnterExitModShop
    #undef OnEnterExitModShop
#else
    #define _ALS_OnEnterExitModShop
#endif
#define OnEnterExitModShop ab_OnEnterExitModShop

stock ab_SetPlayerPos(playerid, Float:x, Float:y, Float:z)
{
    E_AIRBREAK_ENUM[E_PLAYER_X][playerid] = x;
    E_AIRBREAK_ENUM[E_PLAYER_Y][playerid] = y;
    E_AIRBREAK_ENUM[E_PLAYER_Z][playerid] = z;
    SetPVarInt(playerid, "CheckDelay", 2);
    return SetPlayerPos(playerid, x, y, z);
}

stock ab_SetVehiclePos(vehicleid, Float:x, Float:y, Float:z)
{
    for (new i = 0; i < MAX_PLAYERS; i ++)
    {
        if (IsPlayerConnected(i) && IsPlayerInVehicle(i, vehicleid))
        {
            E_AIRBREAK_ENUM[E_PLAYER_X][i] = x;
            E_AIRBREAK_ENUM[E_PLAYER_Y][i] = y;
            E_AIRBREAK_ENUM[E_PLAYER_Z][i] = z;
            SetPVarInt(i, "CheckDelay", 2);
        }
    }
    return SetVehiclePos(vehicleid, x, y, z);
}

stock ab_PutPlayerInVehicle(playerid, vehicleid, seatid)
{
    new Float:x, Float:y, Float:z;
    GetVehiclePos(vehicleid, x, y, z);
    E_AIRBREAK_ENUM[E_PLAYER_X][playerid] = x;
    E_AIRBREAK_ENUM[E_PLAYER_Y][playerid] = y;
    E_AIRBREAK_ENUM[E_PLAYER_Z][playerid] = z;
    SetPVarInt(playerid, "CheckDelay", 2);
    return PutPlayerInVehicle(playerid, vehicleid, seatid);
}

#if defined FILTERSCRIPT
    #if defined _ALS_OnFilterScriptInit
        #undef OnFilterScriptInit
    #else
        #define _ALS_OnFilterScriptInit
    #endif
    #define OnFilterScriptInit ab_OnFilterScriptInit
    forward ab_OnFilterScriptInit();
#else
    #if defined _ALS_OnGameModeInit
        #undef OnGameModeInit
    #else
        #define _ALS_OnGameModeInit
    #endif
    #define OnGameModeInit ab_OnGameModeInit
    forward ab_OnGameModeInit();
#endif

#define SetPlayerPos ab_SetPlayerPos
#define SetVehiclePos ab_SetVehiclePos
#define PutPlayerInVehicle ab_PutPlayerInVehicle
forward OnPlayerAirbreak(playerid);