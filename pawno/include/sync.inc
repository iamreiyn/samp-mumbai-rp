// sync.inc - Sync shooting framework for Limitless Roleplay
// Created by Emmet on 01/01/2017 @ 8:18 AM.

static
	lastShotFrom[MAX_PLAYERS],
	lastShotReason[MAX_PLAYERS char];

forward OnPlayerDamageHandled(playerid, damagedid, Float:amount, weaponid);

static ProcessDamage(playerid, issuerid, Float:amount, weaponid)
{
	new Float:health, Float:armour;

	GetPlayerHealth(playerid, health);
	GetPlayerArmour(playerid, armour);

	// Player has armour.
	if(armour > 0.0)
	{
	    if(armour >= amount)
	    {
	        armour -= amount;
		}
		else
		{
		    // Player's armour isn't enough to cover the damage. So we'll take some of their health.
		    health -= amount - armour;
		    armour = 0;
	    }
	}

	// Health deductions.
	else if(health > 0.0)
	{
	    if(health >= amount)
	    {
	        health -= amount;
		}
		else
		{
		    // Kill the player obviously.
		    health = 0;
	    }
	}

	// Apply the changes.
	SetPlayerHealth(playerid, health < 0.0 ? 0.0 : health);
	SetPlayerArmour(playerid, armour < 0.0 ? 0.0 : armour);
	
	if(health <= 0.0)
	{
	    // OnPlayerDeath isn't normally called when teamkilling happens.
	    // In this case we use CallREMOTEFunction to call it in the gamemode.
	    CallLocalFunction("OnPlayerDeath", "iii", playerid, issuerid, weaponid);
	}
}

public OnPlayerSpawn(playerid)
{
	if(GetPlayerTeam(playerid) != 10)
	{
	    // If you set the player in a team script-wise then they can't damage each other.
		SetPlayerTeam(playerid, 10);
	}
	
	lastShotFrom[playerid] = INVALID_PLAYER_ID;
 	lastShotReason[playerid] = 0;
	
	#if defined SYNC_OnPlayerSpawn
	    return SYNC_OnPlayerSpawn(playerid);
	#else
	    return 1;
	#endif
}

#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif

#define OnPlayerSpawn SYNC_OnPlayerSpawn

#if defined SYNC_OnPlayerSpawn
	forward SYNC_OnPlayerSpawn(playerid);
#endif

public OnPlayerDisconnect(playerid, reason)
{
	for(new i = 0; i <= GetPlayerPoolSize(); i ++)
	{
	    if(IsPlayerConnected(i) && lastShotFrom[i] == playerid)
	    {
	        lastShotFrom[i] = INVALID_PLAYER_ID;
	        lastShotReason[i] = 0;
		}
	}

	#if defined SYNC_OnPlayerDisconnect
	    return SYNC_OnPlayerDisconnect(playerid, reason);
	#else
	    return 1;
	#endif
}

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect SYNC_OnPlayerDisconnect

#if defined SYNC_OnPlayerDisconnect
	forward SYNC_OnPlayerDisconnect(playerid, reason);
#endif

public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid)
{
	if(issuerid != INVALID_PLAYER_ID && IsPlayerConnected(playerid))
	{
	    if(funcidx("OnPlayerDamageHandled") == -1 || CallLocalFunction("OnPlayerDamageHandled", "iifi", issuerid, playerid, amount, weaponid))
	    {
			ProcessDamage(playerid, issuerid, amount, weaponid);
		}
	}

	lastShotFrom[playerid] = issuerid;
    lastShotReason[playerid] = weaponid;

	#if defined SYNC_OnPlayerTakeDamage
	    return SYNC_OnPlayerTakeDamage
	#else
	    return 1;
	#endif
}

#if defined _ALS_OnPlayerTakeDamage
	#undef OnPlayerTakeDamage
#else
	#define _ALS_OnPlayerTakeDamage
#endif

#define OnPlayerTakeDamage SYNC_OnPlayerTakeDamage

#if defined SYNC_OnPlayerTakeDamage
	forward SYNC_OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid);
#endif
