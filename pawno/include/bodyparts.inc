/*
									Body Part Detection - Detect a player's body part
									                By Seif
*/
/*x---------------------------------Important-------------------------------------x*/
//**INCLUDES**//
#include <a_samp>

#if !defined function
	#define function%0(%1) forward %0(%1); public %0(%1)
#endif
/*x---------------------------------Defining-------------------------------------x*/
#define MAX_DISTANCE_UNIT   100.0   // maximum distance a player can shoot from
//**BODY PARTS**//
#define BODY_PART_HEAD  1
#define BODY_PART_TORSO 2
#define BODY_PART_LEGS  3

//#define SCRIPT_DEBUG
/*x---------------------------------CallBacks-------------------------------------x*/
/*/
	native IsPlayerAimingBodyPart(playerid, bodypart);
	native IsPlayerAimingTargetBodyPart(playerid, targetid, bodypart);
*/
/*
											---[IsPlayerAimingBodyPart]---
			»playerid: the player
			»bodypart: the body part you want to check
			*Return: 1 if true, 0 if false
		*-------------------------------------------------------------------*
		| Checks if the player is aiming at any player's certain body part.	|
		*-------------------------------------------------------------------*
*/
#if defined SCRIPT_DEBUG
	new shootpick[100];
#endif
function IsPlayerAimingBodyPart(playerid, bodypart)
{
    #if defined SCRIPT_DEBUG
		new c;
	#endif
	// Get the camera's positions
	new Float:x, Float:y, Float:z, Float:a;
	new Float:vx, Float:vy, Float:vz;
	new Float:cx, Float:cy, Float:cz;
	new Float:offset;
	new Float:radius;
	GetPlayerCameraFrontVector(playerid, vx, vy, vz);
	GetPlayerCameraPos(playerid, cx, cy, cz);
	GetPlayerFacingAngle(playerid, a);
	// Check if the player is aiming in a certain distance
	for(new Float:d; d < MAX_DISTANCE_UNIT; d += 0.5)
	{
		switch (GetPlayerWeapon(playerid))
		{
		    case 24, 29, 22, 23, 25, 26, 27, 28, 32: offset = 0.11;
		    case 30, 31: offset = 0.07;
		    case 33: offset = 0.045;
		    default: offset = 0.0;
		}
	    switch (GetPlayerWeapon(playerid))
	    {
	        case 22, 26, 28, 32:
	        {
			    // duals, where you don't need to change your angle to change aim direction --  Not very accurate, but considering they spray, it should be good
			    x = vx*d+cx;
			    y = vy*d+cy;
	        }
	        default:
	        {
	    		// this is for weapons where your angle moves when you change your aim(deagle, sdpistol, m4, etc)
	            x = cx + (d * floatsin(-a, degrees));
	    		y = cy + (d * floatcos(-a, degrees));
	        }
	    }

	    z = (vz+offset)*d+cz;
	    switch (bodypart)
	    {
	        case BODY_PART_HEAD: z -= 0.0, radius = 0.3;  // the offsets are made for head shots
	        case BODY_PART_TORSO: z += 0.6, radius = 0.5;
	        case BODY_PART_LEGS: z += 1.2, radius = 0.4;
	    }

		#if defined SCRIPT_DEBUG
	        if (IsValidObject(shootpick[c])) DestroyObject(shootpick[c]);
			shootpick[c] = CreateObject(1274, x, y, z, 0.0, 0.0, 0.0);
			c++;
		#endif
		
	    for(new i, m = GetMaxPlayers(); i < m; i++)
	    {
			if (!IsPlayerConnected(i)) continue;
			if (playerid == i) continue;
			if (GetPlayerSpecialAction(i) == SPECIAL_ACTION_DUCK)
			{
				if (IsPlayerInRangeOfPoint(i, radius+0.2, x, y, z+1.2-1.3-(bodypart==BODY_PART_TORSO?0.42:0.0)))
				{
					return i;
				}
			}
			else if (IsPlayerInRangeOfPoint(i, radius, x, y, z-0.8))
			{
				return i;
			}
		}
	}
	return INVALID_PLAYER_ID;
}

/*
											---[IsPlayerAimingTargetBodyPart]---
			»playerid: the player
			»targetid: the target
			»bodypart: the body part you want to check
			*Return: 1 if true, 0 if false
		*-------------------------------------------------------------------*
		| Checks if the player is aiming at target's specific body part.	|
		*-------------------------------------------------------------------*
*/
function IsPlayerAimingTargetBodyPart(playerid, targetid, bodypart)
{
    #if defined SCRIPT_DEBUG
		new c;
	#endif
	// Get the camera's positions
	new Float:x, Float:y, Float:z, Float:a;
	new Float:vx, Float:vy, Float:vz;
	new Float:cx, Float:cy, Float:cz;
	new Float:offset;
	new Float:radius;
	GetPlayerCameraFrontVector(playerid, vx, vy, vz);
	GetPlayerCameraPos(playerid, cx, cy, cz);
	GetPlayerFacingAngle(playerid, a);
	// Check if the player is aiming in a certain distance
	for(new Float:d; d < MAX_DISTANCE_UNIT; d += 0.5)
	{
		switch (GetPlayerWeapon(playerid))
		{
		    case 24, 29, 22, 23, 25, 26, 27, 28, 32: offset = 0.11;
		    case 30, 31: offset = 0.07;
		    case 33, 34: offset = 0.0;
		}
	    switch (GetPlayerWeapon(playerid))
	    {
	        case 22, 26, 28, 32:
	        {
			    // duals, where you don't need to change your angle to change aim direction --  Not very accurate, but considering they spray, it should be good
			    x = vx*d+cx;
			    y = vy*d+cy;
	        }
	        default:
	        {
	    		// this is for weapons where your angle moves when you change your aim(deagle, sdpistol, m4, etc)
	            x = cx + (d * floatsin(-a, degrees));
	    		y = cy + (d * floatcos(-a, degrees));
	        }
	    }

	    z = (vz+offset)*d+cz;
	    switch (bodypart)
	    {
	        case BODY_PART_HEAD: z -= 0.0, radius = 0.3;  // the offsets are made for head shots
	        case BODY_PART_TORSO: z += 0.6, radius = 0.5;
	        case BODY_PART_LEGS: z += 1.2, radius = 0.4;
	    }

		#if defined SCRIPT_DEBUG
	        if (IsValidObject(shootpick[c])) DestroyObject(shootpick[c]);
			shootpick[c] = CreateObject(1274, x, y, z, 0.0, 0.0, 0.0);
			c++;
		#endif

		if (GetPlayerSpecialAction(targetid) == SPECIAL_ACTION_DUCK)
		{
			if (IsPlayerInRangeOfPoint(targetid, radius+0.2, x, y, z+1.2-1.3-(bodypart==BODY_PART_TORSO?0.42:0.0)))
			{
				return 1;
			}
		}
		else if (IsPlayerInRangeOfPoint(targetid, radius, x, y, z-0.8))
		{
			return 1;
		}
	}
	return 0;
}
