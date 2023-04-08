// Teleport and airbreak detection for Limitless Roleplay

enum acEnum
{
	Float:	acPosX,
	Float:	acPosY,
	Float:	acPosZ,
	Float:	acSpawnX,
	Float:	acSpawnY,
	Float:	acSpawnZ,
 			acAirbreakTime,
			acImmunity
};

static Anticheat[MAX_PLAYERS][acEnum];

// List of mod shop locations. Using a modshop counts as teleporting.
static const Float:modShopLocations[][] =
{
    {10.0,  -1936.0861, 237.4443,   34.3125},
	{10.0,  -2714.6309, 217.3955,   4.2965},
	{10.0,  2386.7686,  1042.1649,  10.8203},
	{10.0,  2644.9480,  -2037.6088, 13.5500},
	{10.0,  1041.2783,  -1027.8124, 32.1016},
	{50.0,  616.0253,   -8.0157,    1000.9219},
	{50.0,  615.2108,   -75.3288,   997.9922},
	{50.0,  612.9303,   -124.1615,  997.9922}
};

forward OnPlayerTeleport(playerid, Float:distance);
forward OnPlayerAirbreak(playerid);

static AC_RangeCheck(Float:x1, Float:y1, Float:z1, Float:radius, Float:x2, Float:y2, Float:z2)
{
	x1 -= x2;
	y1 -= y2;
	z1 -= z2;

	return ((x1 * x1) + (y1 * y1) + (z1 * z1)) < (radius * radius);
}

static Float:AC_GetSpeed(playerid)
{
	new
		Float:vx,
		Float:vy,
		Float:vz;

	if(IsPlayerInAnyVehicle(playerid))
	{
		GetVehicleVelocity(GetPlayerVehicleID(playerid), vx, vy, vz);
	}
	else
	{
	    GetPlayerVelocity(playerid, vx, vy, vz);
	}

	return floatsqroot((vx * vx) + (vy * vy) + (vz * vz));
}

static AC_IsPlayerNearModShop(playerid)
{
	if(IsPlayerInAnyVehicle(playerid))
	{
		for(new i = 0; i < sizeof(modShopLocations); i ++)
		{
		    if(IsPlayerInRangeOfPoint(playerid, modShopLocations[i][0], modShopLocations[i][1], modShopLocations[i][2], modShopLocations[i][3]))
		    {
		        return 1;
			}
		}
	}
	
	return 0;
}

stock AC_PutPlayerInVehicle(playerid, vehicleid, seatid)
{
	if(IsPlayerConnected(playerid))
	{
	    if(GetVehicleModel(vehicleid))
	    {
	        GetVehiclePos(vehicleid, Anticheat[playerid][acPosX], Anticheat[playerid][acPosY], Anticheat[playerid][acPosZ]);
		}

		Anticheat[playerid][acImmunity] = gettime() + 5;
	}

	return PutPlayerInVehicle(playerid, vehicleid, seatid);
}

#if defined _ALS_PutPlayerInVehicle
	#undef PutPlayerInVehicle
#else
	#define _ALS_PutPlayerInVehicle
#endif

#define PutPlayerInVehicle AC_PutPlayerInVehicle

stock AC_SetPlayerPos(playerid, Float:x, Float:y, Float:z)
{
	new
	    ret = SetPlayerPos(playerid, x, y, z);

	if(ret)
	{
	    Anticheat[playerid][acPosX] = x;
	    Anticheat[playerid][acPosY] = y;
	    Anticheat[playerid][acPosZ] = z;
	    Anticheat[playerid][acImmunity] = gettime() + 5;
	}

	return ret;
}

#if defined _ALS_SetPlayerPos
	#undef SetPlayerPos
#else
	#define _ALS_SetPlayerPos
#endif

#define SetPlayerPos AC_SetPlayerPos

stock AC_SetVehiclePos(vehicleid, Float:x, Float:y, Float:z)
{
	new
	    ret = SetVehiclePos(vehicleid, x, y, z);

	if(ret)
	{
		for(new i = 0, l = GetPlayerPoolSize(); i <= l; i ++)
		{
		    if(GetPlayerState(i) == PLAYER_STATE_DRIVER && IsPlayerInVehicle(i, vehicleid))
		    {
		        Anticheat[i][acPosX] = x;
		        Anticheat[i][acPosY] = y;
		        Anticheat[i][acPosZ] = z;
		        Anticheat[i][acImmunity] = gettime() + 5;
		        break;
		    }
		}
	}

	return ret;
}

#if defined _ALS_SetVehiclePos
	#undef SetVehiclePos
#else
	#define _ALS_SetVehiclePos
#endif

#define SetVehiclePos AC_SetVehiclePos

stock AC_SetSpawnInfo(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
	if(IsPlayerConnected(playerid))
	{
	    Anticheat[playerid][acSpawnX] = x;
	    Anticheat[playerid][acSpawnY] = y;
	    Anticheat[playerid][acSpawnZ] = z;
	}

	return SetSpawnInfo(playerid, team, skin, x, y, z, rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
}

#if defined _ALS_SetSpawnInfo
	#undef SetSpawnInfo
#else
	#define _ALS_SetSpawnInfo
#endif

#define SetSpawnInfo AC_SetSpawnInfo

public OnEnterExitModShop(playerid, enterexit, interiorid)
{
	GetPlayerPos(playerid, Anticheat[playerid][acPosX], Anticheat[playerid][acPosY], Anticheat[playerid][acPosZ]);
	Anticheat[playerid][acImmunity] = gettime() + 5;

	#if defined AC_OnEnterExitModShop
	    return AC_OnEnterExitModShop(playerid, enterexit, interiorid);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnEnterExitModShop
	#undef OnEnterExitModShop
#else
	#define _ALS_OnEnterExitModShop
#endif

#define OnEnterExitModShop AC_OnEnterExitModShop

#if defined AC_OnEnterExitModShop
	forward AC_OnEnterExitModShop(playerid, enterexit, interiorid);
#endif

public OnPlayerSpawn(playerid)
{
    Anticheat[playerid][acImmunity] = gettime() + 5;

    #if defined AC_OnPlayerSpawn
        return AC_OnPlayerSpawn(playerid);
	#else
	    return 1;
	#endif
}

#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif

#define OnPlayerSpawn AC_OnPlayerSpawn

#if defined AC_OnPlayerSpawn
	forward AC_OnPlayerSpawn(playerid);
#endif

public OnPlayerUpdate(playerid)
{
	if(GetPlayerState(playerid) != PLAYER_STATE_SPECTATING && GetPlayerState(playerid) != PLAYER_STATE_NONE)
	{
		if(gettime() > Anticheat[playerid][acImmunity])
		{
			if(!IsPlayerInRangeOfPoint(playerid, 100.0, Anticheat[playerid][acPosX], Anticheat[playerid][acPosY], Anticheat[playerid][acPosZ]) && !IsPlayerInRangeOfPoint(playerid, 5.0, Anticheat[playerid][acSpawnX], Anticheat[playerid][acSpawnY], Anticheat[playerid][acSpawnZ]))
			{
			    new
					Float:x,
					Float:y,
					Float:z;

				GetPlayerPos(playerid, x, y, z);

				if(!AC_RangeCheck(Anticheat[playerid][acPosX], Anticheat[playerid][acPosY], Anticheat[playerid][acPosZ], 3.0, Anticheat[playerid][acSpawnX], Anticheat[playerid][acSpawnY], Anticheat[playerid][acSpawnZ]) && x != 0.0 && y != 0.0 && z != 0.0 && GetPlayerState(playerid) != PLAYER_STATE_PASSENGER && !AC_IsPlayerNearModShop(playerid))
				{
   					CallLocalFunction("OnPlayerTeleport", "if", playerid, GetPlayerDistanceFromPoint(playerid, Anticheat[playerid][acPosX], Anticheat[playerid][acPosY], Anticheat[playerid][acPosZ]));
				}
			}
			else if(gettime() > Anticheat[playerid][acAirbreakTime] && !IsPlayerInRangeOfPoint(playerid, 10.0, Anticheat[playerid][acPosX], Anticheat[playerid][acPosY], Anticheat[playerid][acPosZ]))
			{
				if((GetPlayerState(playerid) == PLAYER_STATE_ONFOOT || GetPlayerState(playerid) == PLAYER_STATE_DRIVER) && GetPlayerSurfingVehicleID(playerid) == INVALID_VEHICLE_ID && GetPlayerSurfingObjectID(playerid) == INVALID_OBJECT_ID)
				{
				    // Player is 10.0 meters away from their position. Let's check their velocity!

				    new
				        Float:px,
				        Float:py,
				        Float:pz;

					GetPlayerPos(playerid, px, py, pz);

					px = floatabs(Anticheat[playerid][acPosX] - px);
					py = floatabs(Anticheat[playerid][acPosY] - py);
					pz = floatabs(Anticheat[playerid][acPosZ] - pz);

	                // Player seems to have moved a great distance. Let's do more checking.
		            if(((0.5 <= px < 13.9) && (0.5 <= py <= 13.9)) || (4.2 <= pz <= 19.2))
					{
						new
						    Float:speed = AC_GetSpeed(playerid);

						if((0.082 <= speed <= 0.215 && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) || (0.0009 <= speed <= 0.0013 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER))
						{
						    // When airbreaking in the air, a player's velocity levels tend to stay at a regular speed, as they were moving onfoot.
							CallLocalFunction("OnPlayerAirbreak", "i", playerid);
	     					Anticheat[playerid][acAirbreakTime] = gettime() + 1;
						}
					}
			    }
			}
		}

		GetPlayerPos(playerid, Anticheat[playerid][acPosX], Anticheat[playerid][acPosY], Anticheat[playerid][acPosZ]);
	}

	#if defined AC_OnPlayerUpdate
	    return AC_OnPlayerUpdate(playerid);
	#else
	    return 1;
	#endif
}

#if defined _ALS_OnPlayerUpdate
	#undef OnPlayerUpdate
#else
	#define _ALS_OnPlayerUpdate
#endif

#define OnPlayerUpdate AC_OnPlayerUpdate

#if defined AC_OnPlayerUpdate
	forward AC_OnPlayerUpdate(playerid);
#endif
