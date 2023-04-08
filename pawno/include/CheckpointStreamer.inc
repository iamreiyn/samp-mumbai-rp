/*
	YYYYYYYYY           YYYYYYYYY        CCCCCCCCCCCCCCCCCCCCCCCCCCC    PPPPPPPPPPPPPPPPPPPPPPPPPPP
	Y::::::::Y         Y::::::::Y       C::::::::::::::::::::::::::C    P::::::::::::::::::::::::::P
         Y::::::::Y       Y::::::::Y       C:::::::::::::::::::::::::::C    P:::::::::::::::::::::::::::P
          Y::::::::Y     Y::::::::Y       C:::::::::CCCCCCCCCCCCCCCCCCCC    P:::::::::PPPPPPPPPPP::::::::P
           Y::::::::Y   Y::::::::Y       C:::::::::C                        P:::::::::P         P:::::::::P
            Y::::::::Y Y::::::::Y       C:::::::::C                         P:::::::::P         P:::::::::P
             Y::::::::Y::::::::Y       C:::::::::C                          P:::::::::P         P:::::::::P
              Y:::::::Y:::::::Y       C:::::::::C                           P:::::::::PPPPPPPPPPP::::::::P
               Y::::::Y::::::Y       C:::::::::C                            P:::::::::::::::::::::::::::P
                Y:::::Y:::::Y        C:::::::::C                            P::::::::::::::::::::::::::P
               	Y::::::::::Y         C:::::::::C                            P:::::::::PPPPPPPPPPPPPPPPP
               	Y::::::::::Y         C:::::::::C                            P:::::::::P
               	Y::::::::::Y          C:::::::::C                           P:::::::::P
               	Y::::::::::Y           C:::::::::C                          P:::::::::P
               	Y::::::::::Y            C:::::::::C                         P:::::::::P
               	Y::::::::::Y             C:::::::::CCCCCCCCCCCCCCCCCCCCC    P:::::::::P
               	Y::::::::::Y              C::::::::::::::::::::::::::::C    P:::::::::P
               	Y::::::::::Y               C:::::::::::::::::::::::::::C    P:::::::::P
               	YYYYYYYYYYYY                CCCCCCCCCCCCCCCCCCCCCCCCCCCC    PPPPPPPPPPP

			Yaheli's Checkpoint Streamer v1.0 - OnPlayerUpdate checkpoint streamer for SA:MP
			© Yaheli Avni 2009 © ALL RIGHTS RESERVED

*/

#include <a_samp>

#define MAX_P 						200 // Set to the maximum ammount of players on your server
#define MAX_CP 						50 // Set the the maximum ammount of Checkpoints you will have
#define UPDATE_AMMOUNT              23  // Set to the ammount of player updates this is called in (eg. eveyr 23 OnPlayerUpdateCalles the checkpoints are updates)
  										// OnPlayerUpdate is called 5-20 times a second depending on multiple factors.
#define PRINT_ERROR_MESSAGES 		false // Set to 'true' to enable printing of all error messages

#define INVALID_CP_X 5555.0

forward StreamCheckpointsForPlayer(playerid);
forward YCP_OnPlayerUpdate(playerid);
forward OnPlayerEnterStreamCheckpoint(playerid, checkpointid);
forward OnPlayerExitStreamCheckpoint(playerid, checkpointid);

new
	CPCount,
	PlayerUpdates[MAX_P],
	CPShown[MAX_P],
	bool:InCP[MAX_P];

/*
native SetStreamCheckpoint(Float:x,  Float:y, Float:z, Float:size, Float:View_Distance);
native DisableStreamCheckpoint(checkpointid);
native SetPlayerStreamCheckpoint(playerid, Float:x,  Float:y, Float:z, Float:size, Float:View_Distance);
native DisablePlayerStreamCheckpoint(playerid, checkpointid);
native SetStreamCheckpointPos(checkpointid, Float:x, Float:y, Float:z);
native SetStreamCheckpointSize(checkpointid, Float:radius);
native SetStreamCheckpointViewDistance(checkpointid, Float:View_Distance);
native StreamCheckpointsForPlayer(playerid);
native GetDistanceToCheckpoint(Float:X, Float:Y, Float:Z, checkpointid);
native IsPlayerInStreamCheckpoint(playerid, checkpointid);
*/

enum CPInfo
{
	Float:cX,
	Float:cY,
	Float:cZ,
	Float:Radius,
	Float:ViewDistance,
	ForPlayer = INVALID_PLAYER_ID
}
new Checkpoints[MAX_CP][CPInfo];

stock SetStreamCheckpoint(Float:x,  Float:y, Float:z, Float:size, Float:View_Distance)
{
	CPCount++;
	Checkpoints[CPCount][cX] = x;
	Checkpoints[CPCount][cY] = y;
	Checkpoints[CPCount][cZ] = z;
	Checkpoints[CPCount][Radius] = size;
	Checkpoints[CPCount][ViewDistance] = View_Distance;
	return CPCount;
}

stock DisableStreamCheckpoint(checkpointid)
{
	Checkpoints[checkpointid][cX] = INVALID_CP_X;
	for(new i; i < MAX_P; i++)
	{
		if(CPShown[i] == checkpointid)
		{
		    DisablePlayerCheckpoint(i);
		   	CPShown[i] = 0;
		}
	}
	return 0;
}


stock SetPlayerStreamCheckpoint(playerid, Float:x,  Float:y, Float:z, Float:size, Float:View_Distance)
{
    CPCount++;
	Checkpoints[CPCount][cX] = x;
	Checkpoints[CPCount][cY] = y;
	Checkpoints[CPCount][cZ] = z;
	Checkpoints[CPCount][Radius] = size;
	Checkpoints[CPCount][ViewDistance] = View_Distance;
	Checkpoint[CPCount][ForPlayer] = playerid;
	return CPCount;
}

stock DisablePlayerStreamCheckpoint(playerid, checkpointid)
{
    Checkpoints[checkpointid][cX] = INVALID_CP_X;
	if(CPShown[playerid] == checkpointid)
	{
	    DisablePlayerCheckpoint(playerid);
	   	CPShown[i] = 0;
	}
	return 0;
}
stock Float:GetDistanceToCheckpoint(Float:X, Float:Y, Float:Z, checkpointid)
    return floatsqroot((((X - Checkpoints[checkpointid][cX]) * (X - Checkpoints[checkpointid][cX])) + ((Y - Checkpoints[checkpointid][cY]) * (Y - Checkpoints[checkpointid][cY]) + ((Z - Checkpoints[checkpointid][cZ]) * (Z - Checkpoints[checkpointid][cZ])))));

stock YCP_OnGameModeInit()
{
	CPCount = 0;
	for(new i; i < MAX_CP; i++)
	{
	    Checkpoints[i][cX] = 0;
	    Checkpoints[i][cY] = 0;
	    Checkpoints[i][cZ] = 0;
	    Checkpoints[i][Radius] = 0;
	    Checkpoints[i][ViewDistance] = 0;
	}
}

stock YCP_OnPlayerConnect(playerid)
{
	CPShown[playerid] = 0;
	PlayerUpdates[playerid] = 0;
	InCP[playerid] = false;
	return 1;
}

public YCP_OnPlayerUpdate(playerid)
{
	PlayerUpdates[playerid]++;
	if(PlayerUpdates[playerid] >= UPDATE_AMMOUNT && CPCount)
	{
	    StreamCheckpointsForPlayer(playerid);
	    PlayerUpdates[playerid] = 0;
	}
	return 1;
}

stock YCP_OnPlayerEnterCheckpoint(playerid)
{
	OnPlayerEnterStreamCheckpoint(playerid, CPShown[playerid]);
}

public StreamCheckpointsForPlayer(playerid)
{
 	if(InCP[playerid] && !IsPlayerInCheckpoint(playerid))
	{
	    InCP[playerid] = false;
		CallRemoteFunction("OnPlayerExitStreamCheckpoint", "ii", playerid, CPShown[playerid]);
	}

    new Float:X, Float:Y, Float:Z;
	GetPlayerPos(playerid, X, Y, Z);
	for(new i; i < MAX_CP; i++)
	{
	    if(Checkpoints[i][ForPlayer] != INVALID_PLAYER_ID && Checkpoints[i][ForPlayer] != playerid)
	    {
	        return 1;
		}
	    new Float:Dist = GetDistanceToCheckpoint(X, Y, Z, i);

	    if(Dist < Checkpoints[i][ViewDistance] && Checkpoints[i][cX] != INVALID_CP_X)
	    {
	        if(!CPShown[playerid])
	        {
	            SetPlayerCheckpoint(playerid, Checkpoints[i][cX], Checkpoints[i][cY], Checkpoints[i][cZ], Checkpoints[i][Radius]);
	        	CPShown[playerid] = i;
			}
			else
			{
			    if(Dist < GetDistanceToCheckpoint(X, Y, Z, CPShown[playerid]) && i != CPShown[playerid])
			    {
			        DisablePlayerCheckpoint(playerid);
			        SetPlayerCheckpoint(playerid, Checkpoints[i][cX], Checkpoints[i][cY], Checkpoints[i][cZ], Checkpoints[i][Radius]);
			        CPShown[playerid] = i;
				}
			    #if PRINT_ERROR_MESSAGES
			    if(CPShown[playerid] != i) printf("[YCP]ERROR: Checkpoint %d could not be shown because a different checkpoint is already being shown.", i);
                #endif
			}
		}

		if(Dist > Checkpoints[i][ViewDistance] && CPShown[playerid] == i)
		{
		    DisablePlayerCheckpoint(playerid);
		    CPShown[playerid] = 0;
		}
	}
	return 1;
}

stock SetStreamCheckpointPos(checkpointid, Float:x, Float:y, Float:z)
{
	for(new i; i < MAX_P; i++)
	{
	    if(CPShown[i] == checkpointid)
	    {
	        DisablePlayerCheckpoint(i);
	        SetPlayerCheckpoint(i, x, y, z, Checkpoints[checkpointid][Radius]);
		}
	}

	Checkpoints[checkpointid][cX] = x;
	Checkpoints[checkpointid][cY] = y;
	Checkpoints[checkpointid][cZ] = z;
	return 1;
}

stock SetStreamCheckpointSize(checkpointid, Float:radius)
{
	InCP[playerid] = true;

	for(new i; i < MAX_P; i++)
	{
	    if(CPShown[i] == checkpointid)
	    {
	        DisablePlayerCheckpoint(i);
	        SetPlayerCheckpoint(i, Checkpoints[checkpointid][cX], Checkpoints[checkpointid][cY], Checkpoints[checkpointid][cZ], radius);
		}
	}

	Checkpoints[checkpointid][Radius] = radius;
	return 1;
}

stock SetStreamCheckpointViewDistance(checkpointid, Float:View_Distance)
	Checkpoints[checkpointid][ViewDistance] = View_Distance;

stock IsPlayerInStreamCheckpoint(playerid, checkpointid)
{
	if(!CPShown[playerid] || CPShown[playerid] != checkpointid || !IsPlayerInCheckpoint(playerid)) return false;
	return true;
}
