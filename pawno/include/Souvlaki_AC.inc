//*****************************************//
//		Souvlaki - Anti Cheat
//*****************************************//
//  	Edit of Seifensive - AntiCheat

//INCLUDES
#include <a_samp>
//COLORS
#define ADMIN_RED 0xFF6347FF

#define MAX_WEAPONS                 47
#define MONEY_HACK                  5000 // Maximum money amount found as extra between current cash and script cash
#define MAX_AMMO_HACK               20  // Maximum bullets found as extra between normal ammo and scripted one. (69 = s0beit)
#define KICK                        0
#define BAN                         0

enum acInfo
{
        acWeapon[13],
        acWAmmo[MAX_WEAPONS],
}
new AC[MAX_PLAYERS][acInfo];
new HACKER = KICK;
new gPlayerLoggedx[MAX_PLAYERS];

//new TOGGLE_WEAPON_DETECTION = 1;
//new TOGGLE_JETPACK_DETECTION = 0;

forward HackingDetected(playerid, reason[]);
forward WeaponDetection();

forward AC_OnInit();
forward AC_OnPlayerConnect(playerid);
forward AC_OnPlayerDisconnect(playerid, reason);
forward AC_CheckPlayer(playerid);
forward AC_gPlayerLoggedx(playerid,x);

public WeaponDetection()
{
	for(new i=0; i<MAX_PLAYERS; i++)
		AC_CheckPlayer(i);
}
public HackingDetected(playerid, reason[])
{
	if(gPlayerLoggedx[playerid]==1)
	{
        	new string[128];
        	new name[MAX_PLAYER_NAME];
        	GetPlayerName(playerid, name, sizeof(name));
        	if (HACKER == BAN)
        	{
        	    format(string, sizeof(string), ">> AntiCheat: %s check him for: %s", name, reason);
        	}
        	else if (HACKER == KICK)
        	{
         	   format(string, sizeof(string), ">> AntiCheat: %s check him for: %s", name, reason);
        	}
	}
}

public AC_CheckPlayer(playerid)
{
	if (IsPlayerConnected(playerid))
	{
			new w = GetPlayerWeapon(playerid);
            if (AC[playerid][acWeapon][GetWeapSlotID(w)]!= w)
	        {
				if (GetPlayerAmmo(playerid) > AC[playerid][acWAmmo][w])
	            {
	            	if ((GetPlayerAmmo(playerid) - AC[playerid][acWAmmo][w]) >= MAX_AMMO_HACK)
	            	{
	                	HackingDetected(playerid, "Weapon Hack");
	           		}
	        	}
			}
	}
}

public AC_OnInit()
{
	SetTimer("WeaponDetection",6000,1);
}

public AC_OnPlayerConnect(playerid)
{
    for(new i = 0; i <= 12; i++) AC[playerid][acWeapon][i] = 0;
    for(new w = 0; w < MAX_WEAPONS; w++) AC[playerid][acWAmmo][w] = 0;
}

public AC_OnPlayerDisconnect(playerid, reason)
{
    for(new i = 0; i <= 12; i++) AC[playerid][acWeapon][i] = 0;
    for(new w = 0; w < MAX_WEAPONS; w++) AC[playerid][acWAmmo][w] = 0;
}

stock GetWeapSlotID(weaponid)
{
        switch (weaponid)
        {
            case 0,1: return 0;
            case 2..9: return 1;
            case 10..15: return 10;
            case 16..18,39: return 8;
            case 22..24: return 2;
            case 25..27: return 3;
            case 28,29,32: return 4;
            case 33,34: return 6;
            case 35..38: return 7;
            case 41..43: return 9;
            case 44..46: return 11;
            default: return 12;
        }
        return 0;
}

stock IsValidWeapon(weaponid)
{
        if (weaponid > 0) return 1;
        return 0;
}

AC_GivePlayerWeapon(playerid, weaponid, ammos)
{
        AC[playerid][acWeapon][GetWeapSlotID(weaponid)] = weaponid;
        AC[playerid][acWAmmo][weaponid] = ammos;
        GivePlayerWeapon(playerid, weaponid, ammos);
}

stock AC_ResetPlayerWeapons(playerid)
{
	for(new i = 0; i <= 12; i++) AC[playerid][acWeapon][i] = 0;
	for(new w = 0; w < MAX_WEAPONS; w++) AC[playerid][acWAmmo][w] = 0;
	ResetPlayerWeapons(playerid);
}

stock GetPlayerWeaponData2(playerid,slot,&wid,&ammo)
{
    GetPlayerWeaponData(playerid,slot,wid,ammo);
    if(!ammo) wid = -1;
    return 1;
}

public AC_gPlayerLoggedx(playerid,x)
{
	gPlayerLoggedx[playerid]=x;
}

forward AC_RemovePlayerWeapon(playerid, weaponid);

public AC_RemovePlayerWeapon(playerid, weaponid)
{
	AC[playerid][acWeapon][GetWeapSlotID(weaponid)] = 0;
    AC[playerid][acWAmmo][weaponid] = 0;
	new plyWeapons[12] = 0;
	new plyAmmo[12] = 0;
	for(new slot = 0; slot != 12; slot++)
	{
		new wep, ammo;
		GetPlayerWeaponData2(playerid, slot, wep, ammo);

		if(wep != weaponid && ammo != 0)
		{
			GetPlayerWeaponData2(playerid, slot, plyWeapons[slot], plyAmmo[slot]);
		}
	}

	AC_ResetPlayerWeapons(playerid);
	for(new slot = 0; slot != 12; slot++)
	{
	    if(plyAmmo[slot] != 0)
	    {
			AC_GivePlayerWeapon(playerid, plyWeapons[slot], plyAmmo[slot]);
		}
	}
	return 1;
}
