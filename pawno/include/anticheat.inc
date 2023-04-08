/*
 *  Noble Roleplay Anticheat
 *  Last Update: 09/25/2016 @ 06:48 AM
*/

enum {
	CHEAT_WEAPON,
	CHEAT_AMMO,
	CHEAT_HEALTH,
	CHEAT_ARMOUR,
	CHEAT_NORELOAD,
	CHEAT_TELEPORT,
	CHEAT_AIRBREAK,
	CHEAT_VEHICLEWARP,
	CHEAT_VEHICLEHEALTH
};

enum E_ANTICHEAT_ENUM {
	acTimer,
	acWeapons[13],
	acAmmo[13],
	acImmunity,
	acAirbreakTime,
	acFired,
	Float:acHealth,
	Float:acArmour,
	Float:acSpawnX,
	Float:acSpawnY,
	Float:acSpawnZ,
	Float:acPosX,
	Float:acPosY,
	Float:acPosZ,
	acCurrentWeapon,
	acCurrentVehicle,
	acVehicleTime,
	acVehicleSpam
};

static
	Anticheat[MAX_PLAYERS][E_ANTICHEAT_ENUM],
	Float:VehicleHealth[MAX_VEHICLES] = {1000.0, ...},
	VehicleDamage[MAX_VEHICLES][4]
;

static const acWeaponSlotIDs[] = {
	0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 10, 10, 10, 10, 10, 10, 8, 8, 8, 0,
	0, 0, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5, 4, 6, 6, 7, 7, 7, 7, 8, 12,
	9, 9, 9, 11, 11, 11
};

static const Float:acRepairShops[][] = {
	{2065.1960, -1831.4946, 13.5469},
	{1025.0665, -1024.4612, 32.1016},
	{720.1285, -457.2187, 16.3359},
	{-100.0488, 1117.3574, 19.7417},
	{-1420.5437, 2585.5051, 55.8433},
	{-2425.8203, 1022.0131, 50.3977},
	{-1904.3649, 284.2363, 41.0469},
	{1974.4723, 2162.3350, 11.0703}
};

forward OnPlayerCheatDetected(playerid, type);

stock AC_PutPlayerInVehicle(playerid, vehicleid, seatid)
{
	if(IsPlayerConnected(playerid))
	{
	    if(GetVehicleModel(vehicleid))
	    {
	        GetVehiclePos(vehicleid, Anticheat[playerid][acPosX], Anticheat[playerid][acPosY], Anticheat[playerid][acPosZ]);
	        Anticheat[playerid][acCurrentVehicle] = vehicleid;
		}
		else
		{
		    Anticheat[playerid][acCurrentVehicle] = 0;
		}

		Anticheat[playerid][acImmunity] = gettime() + 1;
	}

	return PutPlayerInVehicle(playerid, vehicleid, seatid);
}

stock AC_SetPlayerHealth(playerid, Float:value)
{
	if(IsPlayerConnected(playerid))
	{
	    Anticheat[playerid][acHealth] = value;
	    Anticheat[playerid][acImmunity] = gettime() + 1;
	}

	return SetPlayerHealth(playerid, value);
}

stock AC_SetPlayerArmour(playerid, Float:value)
{
	if(IsPlayerConnected(playerid))
	{
	    Anticheat[playerid][acArmour] = value;
	    Anticheat[playerid][acImmunity] = gettime() + 1;
	}

	return SetPlayerArmour(playerid, value);
}

stock AC_SetPlayerAmmo(playerid, weaponid, ammo)
{
	if(Anticheat[playerid][acWeapons][acWeaponSlotIDs[weaponid]] == weaponid)
	{
	    Anticheat[playerid][acAmmo][acWeaponSlotIDs[weaponid]] = ammo;
	    Anticheat[playerid][acImmunity] = gettime() + 1;
	}

	return SetPlayerAmmo(playerid, weaponid, ammo);
}

stock AC_GivePlayerWeapon(playerid, weaponid, ammo)
{
    if(IsPlayerConnected(playerid))
	{
		Anticheat[playerid][acWeapons][acWeaponSlotIDs[weaponid]] = weaponid;
        Anticheat[playerid][acAmmo][acWeaponSlotIDs[weaponid]] += ammo;
        Anticheat[playerid][acImmunity] = gettime() + 1;
	}

	return GivePlayerWeapon(playerid, weaponid, ammo);
}

stock AC_ResetPlayerWeapons(playerid)
{
	new
	    ret = ResetPlayerWeapons(playerid);

    if(ret)
	{
	    for(new i = 0; i < 13; i ++)
	    {
	        Anticheat[playerid][acWeapons][i] = 0;
	        Anticheat[playerid][acAmmo][i] = 0;
		}

		Anticheat[playerid][acImmunity] = gettime() + 1;
	}

	return ret;
}

stock AC_SetPlayerArmedWeapon(playerid, weaponid)
{
    new
		ret = SetPlayerArmedWeapon(playerid, weaponid);

	if(ret)
	{
	    Anticheat[playerid][acCurrentWeapon] = weaponid;
	    Anticheat[playerid][acFired] = 0;
	    Anticheat[playerid][acImmunity] = gettime() + 1;
	}

	return ret;
}

stock AC_SetPlayerPos(playerid, Float:x, Float:y, Float:z)
{
	new
	    ret = SetPlayerPos(playerid, x, y, z);

	if(ret)
	{
	    Anticheat[playerid][acPosX] = x;
	    Anticheat[playerid][acPosY] = y;
	    Anticheat[playerid][acPosZ] = z;
	    Anticheat[playerid][acImmunity] = gettime() + 1;
	}

	return ret;
}

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
		        Anticheat[i][acImmunity] = gettime() + 1;
		        break;
		    }
		}
	}

	return ret;
}

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

stock AC_SetVehicleHealth(vehicleid, Float:health)
{
	if(GetVehicleModel(vehicleid))
	{
	    VehicleHealth[vehicleid] = health;
	}

	for(new i = 0; i <= GetPlayerPoolSize(); i ++)
	{
	    if(GetPlayerState(i) == PLAYER_STATE_DRIVER && IsPlayerInVehicle(i, vehicleid))
	    {
	        Anticheat[i][acImmunity] = gettime() + 1;
	        break;
		}
	}

	return SetVehicleHealth(vehicleid, health);
}

stock AC_RepairVehicle(vehicleid)
{
	if(GetVehicleModel(vehicleid))
	{
	    VehicleHealth[vehicleid] = 1000.0;
	    VehicleDamage[vehicleid][0] = 0;
        VehicleDamage[vehicleid][1] = 0;
        VehicleDamage[vehicleid][2] = 0;
        VehicleDamage[vehicleid][3] = 0;
	}

	for(new i = 0; i <= GetPlayerPoolSize(); i ++)
	{
	    if(GetPlayerState(i) == PLAYER_STATE_DRIVER && IsPlayerInVehicle(i, vehicleid))
	    {
	        Anticheat[i][acImmunity] = gettime() + 1;
	        break;
		}
	}

	return RepairVehicle(vehicleid);
}

stock AC_UpdateVehicleDamageStatus(vehicleid, panels, doors, lights, tires)
{
	if(GetVehicleModel(vehicleid))
	{
	    VehicleDamage[vehicleid][0] = panels;
	    VehicleDamage[vehicleid][1] = doors;
	    VehicleDamage[vehicleid][2] = lights;
	    VehicleDamage[vehicleid][3] = tires;
	}

	return UpdateVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
}

static AC_PlayerHasWeapon(playerid, weaponid)
{
	switch(weaponid)
	{
	    case 0, 2, 40, 46:
	    {
	        return 1;
		}
	}

	for(new i = 0; i < 13; i ++)
	{
	    if(Anticheat[playerid][acWeapons][i] == weaponid)
	    {
	        return 1;
		}
	}

	return 0;
}

static AC_IsVehicleBoat(vehicleid)
{
	switch(GetVehicleModel(vehicleid))
	{
	    case 430, 446, 452, 453, 454, 472, 473, 484, 493, 595:
	    {
	        return 1;
		}
	}

	return 0;
}

static AC_IsPlayerAtRepairShop(playerid)
{
	for(new i = 0; i < sizeof(acRepairShops); i ++)
	{
	    if(IsPlayerInRangeOfPoint(playerid, 5.0, acRepairShops[i][0], acRepairShops[i][1], acRepairShops[i][2]))
	    {
	        return 1;
		}
	}

	return 0;
}

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

forward AC_UpdateTimer(playerid);
public AC_UpdateTimer(playerid)
{
	new
	    vehicleid = GetPlayerVehicleID(playerid),
	    weapon,
	    ammo;

	if(GetPlayerState(playerid) == PLAYER_STATE_SPECTATING)
	{
	    return 0;
	}

	for(new i = 0; i < 13; i ++)
	{
	    GetPlayerWeaponData(playerid, i, weapon, ammo);

	    if(weapon > 0 && AC_PlayerHasWeapon(playerid, weapon))
	    {
	        if(Anticheat[playerid][acAmmo][i] != ammo && Anticheat[playerid][acAmmo][i] != 0)
	        {
	            if(ammo > Anticheat[playerid][acAmmo][i] && gettime() > Anticheat[playerid][acImmunity])
	            {
	                if(!(1 <= weapon <= 15) && !(43 <= weapon <= 46) && weapon != 40)
	                {
						CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_AMMO);
						SetPlayerAmmo(playerid, weapon, Anticheat[playerid][acAmmo][i]);
					}
				}
	        }

	        Anticheat[playerid][acWeapons][i] = weapon;
          	Anticheat[playerid][acAmmo][i] = ammo;
		}
	}

	if(Anticheat[playerid][acCurrentVehicle] != vehicleid)
	{
		if((vehicleid != 0 && Anticheat[playerid][acCurrentVehicle] != 0) && Anticheat[playerid][acVehicleTime] > gettime())
		{
		    if(!(AC_IsVehicleBoat(vehicleid) && AC_IsVehicleBoat(Anticheat[playerid][acCurrentVehicle]) && GetVehicleModel(vehicleid) == Anticheat[playerid][acCurrentVehicle]))
		    {
				Anticheat[playerid][acVehicleSpam]++;

				if(Anticheat[playerid][acVehicleSpam] >= 2)
				{
					CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_VEHICLEWARP);
					Anticheat[playerid][acVehicleSpam] = 0;
				}
			}
		}

		Anticheat[playerid][acCurrentVehicle] = vehicleid;
		Anticheat[playerid][acVehicleTime] = gettime() + 1;
	}
	
	GetPlayerPos(playerid, Anticheat[playerid][acPosX], Anticheat[playerid][acPosY], Anticheat[playerid][acPosZ]);

	return 1;
}

public OnPlayerConnect(playerid)
{
    for(new i = 0; i < 13; i ++)
	{
	    Anticheat[playerid][acWeapons][i] = 0;
	    Anticheat[playerid][acAmmo][i] = 0;
	}

	Anticheat[playerid][acTimer] = SetTimerEx("AC_UpdateTimer", 500, true, "i", playerid);
	Anticheat[playerid][acImmunity] = 0;
	Anticheat[playerid][acAirbreakTime] = 0;
	Anticheat[playerid][acFired] = 0;
	Anticheat[playerid][acHealth] = 100.0;
	Anticheat[playerid][acArmour] = 0.0;
	Anticheat[playerid][acPosX] = 0.0;
	Anticheat[playerid][acPosY] = 0.0;
	Anticheat[playerid][acPosZ] = 0.0;
	Anticheat[playerid][acSpawnX] = 0.0;
	Anticheat[playerid][acSpawnY] = 0.0;
	Anticheat[playerid][acSpawnZ] = 0.0;
    Anticheat[playerid][acCurrentWeapon] = 0;
    Anticheat[playerid][acCurrentVehicle] = 0;
    Anticheat[playerid][acVehicleTime] = 0;
	Anticheat[playerid][acVehicleSpam] = 0;

	#if defined AC_OnPlayerConnect
	    return AC_OnPlayerConnect(playerid);
	#else
	    return 1;
	#endif
}

public OnPlayerDisconnect(playerid, reason)
{
	KillTimer(Anticheat[playerid][acTimer]);

	#if defined AC_OnPlayerDisconnect
	    return AC_OnPlayerDisconnect(playerid, reason);
	#else
	    return 1;
	#endif
}

public OnPlayerSpawn(playerid)
{
    Anticheat[playerid][acImmunity] = gettime() + 5;
	Anticheat[playerid][acHealth] = 100.0;
 	Anticheat[playerid][acArmour] = 0.0;

    #if defined AC_OnPlayerSpawn
	    return AC_OnPlayerSpawn(playerid);
	#else
	    return 1;
	#endif
}

public OnPlayerUpdate(playerid)
{
	if(GetPlayerState(playerid) != PLAYER_STATE_SPECTATING && GetPlayerState(playerid) != PLAYER_STATE_NONE)
	{
		new
			Float:health,
			Float:armour,
			weaponid = GetPlayerWeapon(playerid),
			vehicleid = GetPlayerVehicleID(playerid);

		GetPlayerHealth(playerid, health);
		GetPlayerArmour(playerid, armour);

		if(gettime() > Anticheat[playerid][acImmunity])
		{
			if(!IsPlayerInRangeOfPoint(playerid, 75.0, Anticheat[playerid][acPosX], Anticheat[playerid][acPosY], Anticheat[playerid][acPosZ]) && !IsPlayerInRangeOfPoint(playerid, 5.0, Anticheat[playerid][acSpawnX], Anticheat[playerid][acSpawnY], Anticheat[playerid][acSpawnZ]))
			{
			    new
					Float:x,
					Float:y,
					Float:z;

				GetPlayerPos(playerid, x, y, z);

				if(!AC_RangeCheck(Anticheat[playerid][acPosX], Anticheat[playerid][acPosY], Anticheat[playerid][acPosZ], 3.0, Anticheat[playerid][acSpawnX], Anticheat[playerid][acSpawnY], Anticheat[playerid][acSpawnZ]) && x != 0.0 && y != 0.0 && z != 0.0 && GetPlayerState(playerid) != PLAYER_STATE_PASSENGER)
				{
			 		CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_TELEPORT);
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

						if((0.082 <= speed <= 0.129 && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) || (0.0009 <= speed <= 0.0013 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER))
						{
						    // When airbreaking in the air, a player's velocity levels tend to stay at a regular speed, as they were moving onfoot.
							CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_AIRBREAK);
	     					Anticheat[playerid][acAirbreakTime] = gettime() + 1;
						}
					}
			    }
			}
			if(floatround(health) > floatround(Anticheat[playerid][acHealth]))
			{
			    if(!(Anticheat[playerid][acHealth] == 0.0 && health == 100.0) && health != 0.0)
			    {
					SetPlayerHealth(playerid, Anticheat[playerid][acHealth]);
					CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_HEALTH);
				}
			}
			if(floatround(armour) > floatround(Anticheat[playerid][acArmour]))
			{
				SetPlayerArmour(playerid, Anticheat[playerid][acArmour]);
				CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_ARMOUR);
			}
			if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
			{
			    GetVehicleHealth(vehicleid, health);

			    if(floatround(health) > floatround(VehicleHealth[vehicleid]) && !AC_IsPlayerAtRepairShop(playerid))
			    {
			        SetVehicleHealth(vehicleid, VehicleHealth[vehicleid]);
			        UpdateVehicleDamageStatus(vehicleid, VehicleDamage[vehicleid][0], VehicleDamage[vehicleid][1], VehicleDamage[vehicleid][2], VehicleDamage[vehicleid][3]);
			        CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_VEHICLEHEALTH);
			    }
			}
		}

	    if(Anticheat[playerid][acCurrentWeapon] != weaponid)
		{
		    if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && !AC_PlayerHasWeapon(playerid, weaponid) && gettime() > Anticheat[playerid][acImmunity])
		    {
		        CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_WEAPON);
		        SetPlayerArmedWeapon(playerid, 0);
			}

			Anticheat[playerid][acCurrentWeapon] = weaponid;
		    Anticheat[playerid][acFired] = 0;
		}
		if(GetPlayerWeaponState(playerid) == WEAPONSTATE_RELOADING)
		{
		    Anticheat[playerid][acFired] = 0;
		}

		GetPlayerPos(playerid, Anticheat[playerid][acPosX], Anticheat[playerid][acPosY], Anticheat[playerid][acPosZ]);

		if(gettime() > Anticheat[playerid][acImmunity])
		{
		    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
			{
			    GetVehicleHealth(vehicleid, VehicleHealth[vehicleid]);
		    	GetVehicleDamageStatus(vehicleid, VehicleDamage[vehicleid][0], VehicleDamage[vehicleid][1], VehicleDamage[vehicleid][2], VehicleDamage[vehicleid][3]);
			}

		    GetPlayerHealth(playerid, Anticheat[playerid][acHealth]);
			GetPlayerArmour(playerid, Anticheat[playerid][acArmour]);
		}
	}

	#if defined AC_OnPlayerUpdate
	    return AC_OnPlayerUpdate(playerid);
	#else
	    return 1;
	#endif
}

public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
    if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
	    new
			ammo = 0;

		switch(weaponid)
		{
		    case 22:
				ammo = 40;
		    case 23:
				ammo = 22;
		    case 26:
				ammo = 8;
		    case 24, 27:
				ammo = 12;
		    case 28, 32:
				ammo = 115;
		    case 29, 30:
				ammo = 40;
		    case 31:
				ammo = 60;
  		}

  		if(ammo > 0)
  		{
	        Anticheat[playerid][acFired]++;

		    if(Anticheat[playerid][acFired] >= ammo)
		    {
				CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_NORELOAD);
                Anticheat[playerid][acFired] = 0;
			}
		}
	}

	#if defined AC_OnPlayerWeaponShot
	    return AC_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, fX, fY, fZ);
	#else
	    return 1;
	#endif
}

public OnVehicleSpawn(vehicleid)
{
	VehicleHealth[vehicleid] = 1000.0;
	VehicleDamage[vehicleid][0] = 0;
	VehicleDamage[vehicleid][1] = 0;
	VehicleDamage[vehicleid][2] = 0;
	VehicleDamage[vehicleid][3] = 0;

	#if defined AC_OnVehicleSpawn
	    return AC_OnVehicleSpawn(vehicleid);
	#else
	    return 1;
	#endif
}

public OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z)
{
	GetVehicleHealth(vehicleid, VehicleHealth[vehicleid]);
	GetVehicleDamageStatus(vehicleid, VehicleDamage[vehicleid][0], VehicleDamage[vehicleid][1], VehicleDamage[vehicleid][2], VehicleDamage[vehicleid][3]);

	#if defined AC_OnUnoccupiedVehicleUpdate
		return AC_OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, new_x, new_y, new_z, vel_x, vel_y, vel_z);
	#else
	    return 1;
	#endif
}

#if defined _ALS_PutPlayerInVehicle
	#undef PutPlayerInVehicle
#else
	#define _ALS_PutPlayerInVehicle
#endif

#if defined _ALS_SetPlayerHealth
	#undef SetPlayerHealth
#else
	#define _ALS_SetPlayerHealth
#endif

#if defined _ALS_SetPlayerArmour
	#undef SetPlayerArmour
#else
	#define _ALS_SetPlayerArmour
#endif

#if defined _ALS_SetPlayerAmmo
	#undef SetPlayerAmmo
#else
	#define _ALS_SetPlayerAmmo
#endif

#if defined _ALS_GivePlayerWeapon
	#undef GivePlayerWeapon
#else
	#define _ALS_GivePlayerWeapon
#endif

#if defined _ALS_ResetPlayerWeapons
	#undef ResetPlayerWeapons
#else
	#define _ALS_ResetPlayerWeapons
#endif

#if defined _ALS_SetPlayerArmedWeapon
	#undef SetPlayerArmedWeapon
#else
	#define _ALS_SetPlayerArmedWeapon
#endif

#if defined _ALS_SetPlayerPos
	#undef SetPlayerPos
#else
	#define _ALS_SetPlayerPos
#endif

#if defined _ALS_SetVehiclePos
	#undef SetVehiclePos
#else
	#define _ALS_SetVehiclePos
#endif

#if defined _ALS_SetSpawnInfo
	#undef SetSpawnInfo
#else
	#define _ALS_SetSpawnInfo
#endif

#if defined _ALS_SetVehicleHealth
	#undef SetVehicleHealth
#else
	#define _ALS_SetVehicleHealth
#endif

#if defined _ALS_RepairVehicle
	#undef RepairVehicle
#else
	#define _ALS_RepairVehicle
#endif

#if defined _ALS_UpdateVehicleDamageStatus
	#undef UpdateVehicleDamageStatus
#else
	#define _ALS_UpdateVehicleDamageStatus
#endif

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif

#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif

#if defined _ALS_OnPlayerUpdate
	#undef OnPlayerUpdate
#else
	#define _ALS_OnPlayerUpdate
#endif

#if defined _ALS_OnVehicleSpawn
	#undef OnVehicleSpawn
#else
	#define _ALS_OnVehicleSpawn
#endif

#if defined _ALS_OnUnoccupiedVehicleUpdate
	#undef OnUnoccupiedVehicleUpdate
#else
	#define _ALS_OnUnoccupiedVehicleUpdate
#endif

#define PutPlayerInVehicle 			AC_PutPlayerInVehicle
#define SetPlayerHealth 			AC_SetPlayerHealth
#define SetPlayerArmour 			AC_SetPlayerArmour
#define SetPlayerAmmo 				AC_SetPlayerAmmo
#define GivePlayerWeapon 			AC_GivePlayerWeapon
#define ResetPlayerWeapons 			AC_ResetPlayerWeapons
#define SetPlayerArmedWeapon 		AC_SetPlayerArmedWeapon
#define SetPlayerPos 				AC_SetPlayerPos
#define SetVehiclePos 				AC_SetVehiclePos
#define SetSpawnInfo            	AC_SetSpawnInfo
#define SetVehicleHealth        	AC_SetVehicleHealth
#define RepairVehicle           	AC_RepairVehicle
#define UpdateVehicleDamageStatus   AC_UpdateVehicleDamageStatus
#define OnPlayerConnect         	AC_OnPlayerConnect
#define OnPlayerDisconnect      	AC_OnPlayerDisconnect
#define OnPlayerSpawn           	AC_OnPlayerSpawn
#define OnPlayerUpdate          	AC_OnPlayerUpdate
#define OnPlayerWeaponShot      	AC_OnPlayerWeaponShot
#define OnVehicleSpawn          	AC_OnVehicleSpawn
#define OnUnoccupiedVehicleUpdate 	AC_OnUnoccupiedVehicleUpdate

#if defined AC_OnPlayerConnect
	forward AC_OnPlayerConnect(playerid);
#endif

#if defined AC_OnPlayerDisconnect
	forward AC_OnPlayerDisconnect(playerid, reason);
#endif

#if defined AC_OnPlayerSpawn
	forward AC_OnPlayerSpawn(playerid);
#endif

#if defined AC_OnPlayerUpdate
	forward AC_OnPlayerUpdate(playerid);
#endif

#if defined AC_OnPlayerWeaponShot
	forward AC_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ);
#endif

#if defined AC_OnVehicleSpawn
	forward AC_OnVehicleSpawn(vehicleid);
#endif

#if defined AC_OnUnoccupiedVehicleUpdate
	forward AC_OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z);
#endif

