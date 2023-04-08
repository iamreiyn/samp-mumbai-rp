/*
							Seifision - Seif's scripted camera shake for SA-MP 0.2
*/
/*x---------------------------------Important-------------------------------------x*/
//**INCLUDES**//
#include <a_samp>
//**PRAGMAS**//

//**MISC**//
#define VISION_TYPE1      1
#define VISION_TYPE2      2
/*x---------------------------------Defining-------------------------------------x*/
//**VARIABLES**//
new Float:PlayerVisX[MAX_PLAYERS];
new Float:PlayerVisY[MAX_PLAYERS];
new Float:PlayerVisZ[MAX_PLAYERS];
new bool:Vision[MAX_PLAYERS];
new VisTime[MAX_PLAYERS];
new VisTurn[MAX_PLAYERS];
// **NATIVES** //

/*x---------------------------------CallBacks-------------------------------------x*/
stock SetPlayerShakeVision(playerid, type)
{
	if (!IsPlayerConnected(playerid)) return 1;
	Vision[playerid] = true;
	GetPlayerPos(playerid, PlayerVisX[playerid],PlayerVisY[playerid],PlayerVisZ[playerid]);
	VisTime[playerid] = 0;
	VisTurn[playerid] = 1;
	SetTimerEx("VisionTimer", 100, 0, "id", playerid, type);
	return 1;
}

stock DisablePlayerShakeVision(playerid)
{
    if (!IsPlayerConnected(playerid)) return 1;
	Vision[playerid] = false;
	SetCameraBehindPlayer(playerid);
	return 1;
}

forward VisionTimer(playerid, type);
public  VisionTimer(playerid, type)
{
	new Float:X,Float:Y,Float:Z,Float:A;
	if (IsPlayerInAnyVehicle(playerid))
	{
	    GetVehiclePos(GetPlayerVehicleID(playerid), X, Y, Z);
		GetVehicleZAngle(GetPlayerVehicleID(playerid), A);
	}
	else
	{
	    GetPlayerPos(playerid, X, Y, Z);
		GetPlayerFacingAngle(playerid, A);
	}
	if (type == VISION_TYPE1)
	{
	    if (VisTurn[playerid] == 1)
	    {
	        new Float:time = float(VisTime[playerid])/2;
	        X += (time * floatsin(-(A+90), degrees));
	        Y += (time * floatcos(-(A+90), degrees));
	        SetPlayerCameraPos(playerid, X, Y, Z+0.7);
	        X -= (time * floatsin(-(A+90), degrees));
	        Y -= (time * floatcos(-(A+90), degrees));
			SetPlayerCameraLookAt(playerid, X, Y, Z+0.7);
			X += (time * floatsin(-(A+90), degrees));
	        Y += (time * floatcos(-(A+90), degrees));
			VisTime[playerid]++;
			if (VisTime[playerid] == 2) VisTurn[playerid] = 2;
		}
		else if (VisTurn[playerid] == 2)
	    {
	        new Float:time = float(VisTime[playerid])/2;
	       	X -= (time * floatsin(-(A-90), degrees));
	        Y -= (time * floatcos(-(A-90), degrees));
	        SetPlayerCameraPos(playerid, X, Y, Z+0.7);
	        X += (time * floatsin(-(A-90), degrees));
	        Y += (time * floatcos(-(A-90), degrees));
			SetPlayerCameraLookAt(playerid, X, Y, Z+0.7);
			X -= (time * floatsin(-(A-90), degrees));
	        Y -= (time * floatcos(-(A-90), degrees));
			VisTime[playerid]--;
			if (VisTime[playerid] == -2) VisTurn[playerid] = 1;
		}
		X -= (3.0 * floatsin(-A, degrees));
		Y -= (3.0 * floatcos(-A, degrees));
		SetPlayerCameraPos(playerid, X, Y, Z+0.7);
		X += (3.0 * floatsin(-A, degrees));
		Y += (3.0 * floatcos(-A, degrees));
		SetPlayerCameraLookAt(playerid, X, Y, Z+0.7);
	}
	else if (type == VISION_TYPE2)
	{
	    if (VisTurn[playerid] == 1)
	    {
	        new Float:time = float(VisTime[playerid])/2;
	        X += (time * floatsin(-(A+90), degrees));
	        Y += (time * floatcos(-(A+90), degrees));
	        SetPlayerCameraPos(playerid, X, Y, Z+0.7);
	        X -= (time * floatsin(-(A+90), degrees));
	        Y -= (time * floatcos(-(A+90), degrees));
	        Z += time;
			SetPlayerCameraLookAt(playerid, X, Y, Z+0.7);
			X += (time * floatsin(-(A+90), degrees));
	        Y += (time * floatcos(-(A+90), degrees));
			VisTime[playerid]++;
			if (VisTime[playerid] == 2) VisTurn[playerid] = 2;
		}
		else if (VisTurn[playerid] == 2)
	    {
	        new Float:time = float(VisTime[playerid])/2;
	       	X -= (time * floatsin(-(A-90), degrees));
	        Y -= (time * floatcos(-(A-90), degrees));
	        SetPlayerCameraPos(playerid, X, Y, Z+0.7);
	        X += (time * floatsin(-(A-90), degrees));
	        Y += (time * floatcos(-(A-90), degrees));
	        Z -= time;
			SetPlayerCameraLookAt(playerid, X, Y, Z+0.7);
			X -= (time * floatsin(-(A-90), degrees));
	        Y -= (time * floatcos(-(A-90), degrees));
			VisTime[playerid]--;
			if (VisTime[playerid] == -2) VisTurn[playerid] = 1;
		}
		X -= (3.0 * floatsin(-A, degrees));
		Y -= (3.0 * floatcos(-A, degrees));
		SetPlayerCameraPos(playerid, X, Y, Z+0.7);
		X += (3.0 * floatsin(-A, degrees));
		Y += (3.0 * floatcos(-A, degrees));
		SetPlayerCameraLookAt(playerid, X, Y, Z+0.7);
	}
	if (Vision[playerid] == true) SetTimerEx("VisionTimer", 100, 0, "id", playerid, type);
	else DisablePlayerShakeVision(playerid);
}
