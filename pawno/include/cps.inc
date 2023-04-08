/* CPS by DragSta */

/* natives
native CreateCheckpoint(playerid, Float:cpX, Float:cpY, Float:cpZ, Float:cpS, Float:viewdiss);
native DestroyCheckpoint(cPid);
native SyncCheckpoints(playerid);
native StartSystem();
native ClearVars(playerid);
native CheckpointCheck(playerid);
native TogglePlayerCheckpoint(playerid, Cpid, bool:toggle);
*/

#include <a_samp>

#define CP_TIMER_INTERVAL 300

#define ClearVars(%1); 		 for(new i; i < MAX_STREAMED_CPS; i ++) pCPActive[ %1 ][ i ] = false;
#define SyncCheckpoints(%1); for(new i; i < MAX_STREAMED_CPS; i ++) { if(gCheckPoints[ i ][ global ]) { for(new k; k < MAX_PLAYERS; k ++) { pShown[ k ][ i ] = true; } } }
#define CheckpointCheck(%1); if(pCPID[ %1 ] != INVALID_CP_VALUE) { OnPlayerEnterStreamedCheckpoint(%1, pCPID[ %1 ]); return 1; }
#define VERSION 			 "0.1a"
#define INVALID_CP_VALUE 	 -255
#define INVALID_CP_VALUEF 	 -255.0
#define MAX_STREAMED_CPS 	 200

forward OnPlayerEnterStreamedCheckpoint(playerid, streamid);

new cpID = -1;
enum CP_ENUM
{
	cpid,
	Float:Xx,
	Float:Yy,
	Float:Zz,
	Float:Size,
	bool:active,
	Float:viewdis,
	bool:global
};
new gCheckPoints[MAX_STREAMED_CPS][CP_ENUM];

new bool:pCPActive[MAX_PLAYERS][MAX_STREAMED_CPS];
new bool:pShown[MAX_PLAYERS][MAX_STREAMED_CPS];
new pCPID[MAX_PLAYERS];

stock CreateCheckpoint(playerid, Float:cpX, Float:cpY, Float:cpZ, Float:cpS, Float:viewdiss)
{
    cpID ++;
	gCheckPoints[ cpID ][ cpid ] 	 = cpID;
	gCheckPoints[ cpID ][ Xx ] 	 	 = cpX;
	gCheckPoints[ cpID ][ Yy ]	 	 = cpY;
	gCheckPoints[ cpID ][ Zz ] 	 	 = cpZ;
	gCheckPoints[ cpID ][ Size ] 	 = cpS;
	gCheckPoints[ cpID ][ active ]   = true;
	gCheckPoints[ cpID ][ viewdis ]  = viewdiss;
	if(playerid == -1)
	{
		gCheckPoints[ cpID ][ global ]  = true;
		for(new i; i < MAX_PLAYERS; i ++)
		{
		    pShown[ i ][ cpID ] = true;
		}
	}
	else if(playerid != -1)
	{
		pShown[ playerid ][ cpID ] = true;
		gCheckPoints[ cpID ][ global ]  = false;
		for(new i; i < MAX_PLAYERS; i ++)
		{
		    if(i != playerid)
		    {
		    	pShown[ i ][ cpID ] = false;
			}
		}
	}
	return cpID;
}

stock TogglePlayerCheckpoint(playerid, Cpid, bool:toggle)
{
	pShown[ playerid ][ Cpid ] = toggle;
	return 1;
}

stock DestroyCheckpoint(cPid)
{
	gCheckPoints[ cPid ][ cpid ] 	 = 	INVALID_CP_VALUE;
	gCheckPoints[ cPid ][ Xx ]	 	 =	INVALID_CP_VALUEF;
	gCheckPoints[ cPid ][ Yy ] 	 	 = 	INVALID_CP_VALUEF;
	gCheckPoints[ cPid ][ Zz ] 	 	 = 	INVALID_CP_VALUEF;
	gCheckPoints[ cPid ][ Size ] 	 = 	INVALID_CP_VALUEF;
	gCheckPoints[ cPid ][ active ]   = 	false;
	gCheckPoints[ cPid ][ viewdis ]  =  INVALID_CP_VALUEF;
	return 1;
}

stock StartSystem()
{
	SetTimer("CPUpdate", CP_TIMER_INTERVAL, 1);
	return 1;
}

forward CPUpdate();
public CPUpdate()
{
	new Float:pPos[3];
	for(new i; i < MAX_PLAYERS; i ++)
	{
		if(IsPlayerConnected(i))
		{
		    GetPlayerPos(i, pPos[ 0 ], pPos[ 1 ], pPos[ 2 ]);
			for(new j; j < MAX_STREAMED_CPS; j ++)
			{
			    if(gCheckPoints[ j ][ active ])
			    {
			    	if(pShown[ i ][ j ] && DistanceBetweenPoints(pPos[ 0 ], pPos[ 1 ], pPos[ 2 ], gCheckPoints[ j ][ Xx ], gCheckPoints[ j ][ Yy ], gCheckPoints[ j ][ Zz ]) <= gCheckPoints[ j ][ viewdis ])
			    	{
			    	    if(!pCPActive[ i ][ j ])
			    	    {
			    	    	SetPlayerCheckpoint(i, gCheckPoints[ j ][ Xx ], gCheckPoints[ j ][ Yy ], gCheckPoints[ j ][ Zz ], gCheckPoints[ j ][ Size ]);
			    	    	pCPActive[ i ][ j ] = true;
			    	    	pCPID[ i ] = j;
						}
					}
					else
					{
						if(pCPActive[ i ][ j ])
						{
						    DisablePlayerCheckpoint(i);
						    pCPActive[ i ][ j ] = false;
							pCPID[ i ] = INVALID_CP_VALUE;
						}
     				}
				}
			}
		}
	}
}

//forward Float:DistanceBetweenPoints(Float:x11, Float:y11, Float:z11, Float:x22, Float:y22, Float:z22);
Float:DistanceBetweenPoints(Float:x11, Float:y11, Float:z11, Float:x22, Float:y22, Float:z22)
	return floatsqroot(floatpower(floatabs(floatsub(x22,x11)),2)+floatpower(floatabs(floatsub(y22,y11)),2)+floatpower(floatabs(floatsub(z22,z11)),2));
