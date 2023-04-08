/*
	OPJV - OnPlayerJackVehicle by Gamer931215
	Inspired by OnPlayerShootPlayer and OnPlayerDamageVehicle by Wups

	Free to use/distribute as long you keep these credits on top!
*/

#include <a_samp>

#if defined OPJV_INC
	#endinput
#endif
#define OPJV_INC
#define HOLDING(%0) \
    ((newkeys & (%0)) == (%0))
#define RELEASED(%0) \
    (((newkeys & (%0)) != (%0)) && ((oldkeys & (%0)) == (%0)))
#define PRESSED(%0) \
    (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))
#tryinclude <foreach>

#if !defined foreach
    #define foreach(%1,%2) for (new %2 = 0; %2 < MAX_PLAYERS; %2++) if (IsPlayerConnected(%2))
    #define __SSCANF_FOREACH__
#endif

enum _pInfo
{
	bool:IsPlayerHoldingNinjaKeys,
	PlayerJackingPlayerid
}
new JackDetails[MAX_PLAYERS][_pInfo];
forward OnPlayerJackVehicle(playerid,victimid,vehicleid,bool:ninjajack);
forward OnPlayerGotJacked(playerid,jackerid,vehicleid);

public OnPlayerConnect(playerid)
{
	JackDetails[playerid][PlayerJackingPlayerid] = -1;
	JackDetails[playerid][IsPlayerHoldingNinjaKeys] = false;
	return CallLocalFunction("OPJV_OnPlayerConnect","i",playerid);
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect OPJV_OnPlayerConnect
forward OPJV_OnPlayerConnect(playerid);

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	if(!ispassenger)
	{
	    foreach(Player,i)
		{
		    if(!IsPlayerConnected(i) || !IsPlayerInAnyVehicle(i)) continue;
			if(playerid != i && GetPlayerVehicleID(i) == vehicleid && GetPlayerState(i) == PLAYER_STATE_DRIVER)
			{
			    JackDetails[i][PlayerJackingPlayerid] = playerid;
				CallLocalFunction("OnPlayerJackVehicle","iiib",playerid,i,vehicleid,JackDetails[playerid][IsPlayerHoldingNinjaKeys]);
				SetTimerEx("OPJV_ResetPlayerJack",15000,false,"i",i);
			}
		}
	}
	return CallLocalFunction("OPJV_OnPlayerEnterVehicle","iii",playerid,vehicleid,ispassenger);
}
#if defined _ALS_OnPlayerEnterVehicle
	#undef OnPlayerEnterVehicle
#else
	#define _ALS_OnPlayerEnterVehicle
#endif
#define OnPlayerEnterVehicle OPJV_OnPlayerEnterVehicle
forward OPJV_OnPlayerEnterVehicle(playerid,vehicleid,ispassenger);

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (HOLDING(KEY_SPRINT) || PRESSED(KEY_SPRINT) || RELEASED(KEY_SPRINT))
    {
        if(JackDetails[playerid][IsPlayerHoldingNinjaKeys] == false)
        {
            JackDetails[playerid][IsPlayerHoldingNinjaKeys] = true;
            SetTimerEx("OPJV_ResetPlayerKeys",2000,false,"i",playerid);
        }
    }
    return CallLocalFunction("OPJV_OnPlayerKeyStateChange","iii",playerid,newkeys,oldkeys);
}
#if defined _ALS_OnPlayerKeyStateChange
	#undef OnPlayerKeyStateChange
#else
	#define _ALS_OnPlayerKeyStateChange
#endif
#define OnPlayerKeyStateChange OPJV_OnPlayerKeyStateChange
forward OPJV_OnPlayerKeyStateChange(playerid,newkeys,oldkeys);

public OnPlayerStateChange(playerid,newstate,oldstate)
{
	if(oldstate == PLAYER_STATE_DRIVER && JackDetails[playerid][PlayerJackingPlayerid] > -1 && GetPlayerVehicleID(JackDetails[playerid][PlayerJackingPlayerid]) == GetPlayerVehicleID(playerid))
	{
	    CallLocalFunction("OnPlayerGotJacked","iii",playerid,JackDetails[playerid][PlayerJackingPlayerid],GetPlayerVehicleID(playerid));
	}
	return CallLocalFunction("OPJV_OnPlayerStateChange","iii",playerid,newstate,oldstate);
}
#if defined _ALS_OnPlayerStateChange
	#undef OnPlayerStateChange
#else
	#define _ALS_OnPlayerStateChange
#endif
#define OnPlayerStateChange OPJV_OnPlayerStateChange
forward OPJV_OnPlayerStateChange(playerid,newstate,oldstate);

forward OPJV_ResetPlayerJack(playerid);
public OPJV_ResetPlayerJack(playerid)
{
    JackDetails[playerid][PlayerJackingPlayerid] = -1;
}

forward OPJV_ResetPlayerKeys(playerid);
public OPJV_ResetPlayerKeys(playerid)
{
    JackDetails[playerid][IsPlayerHoldingNinjaKeys] = false;
}