//////////////////////////////////////////////////
//////////////////////////////////////////////////
///        Matraka's Checkpoint Streamer       ///
///                                            ///
/// Author: [MPA]matraka_IDG                   ///
/// Contact: msn_matraka@gtabrasil.net         ///
///                                            ///
///   ---===Infernus Development Group===---   ///
//////////////////////////////////////////////////
//////////////////////////////////////////////////

#include <a_samp>

/*Natives
native CPS_AddCheckpoint(Float:X,Float:Y,Float:Z,Float:size,Float:spawn_dist);
native CPS_IsPlayerInCheckpoint(playerid,cpid);
native CPS_IsPlayerInAnyCheckpoint(playerid,cpid);
native CPS_RemoveCheckpoint(cpid);
native CPS_GetPlayerCheckpoint(playerid);
*/

#define MAX_CHECKPOINTS 500

forward CPSERVICE_Handler();
enum cpinfo
{
	Float:cpX,
	Float:cpY,
	Float:cpZ,
	Float:cpsz,
	cpsd,
};
new CPSERVICE_active;
new Checkpoints[MAX_CHECKPOINTS][cpinfo];
new UsedCPSlot[MAX_CHECKPOINTS];
new CPSERVICE_actualcp[MAX_PLAYERS];

stock CPS_AddCheckpoint(Float:X,Float:Y,Float:Z,Float:size,spawn_dist)
{
	new cpid=1;
	while(UsedCPSlot[cpid] == 1) cpid++;
	if(CPSERVICE_active == 0){
	    SetTimer("CPSERVICE_Handler",500,true);
	    CPSERVICE_active=1;
	}
	UsedCPSlot[cpid]=1;
	Checkpoints[cpid][cpX]=X;
	Checkpoints[cpid][cpY]=Y;
	Checkpoints[cpid][cpZ]=Z;
	Checkpoints[cpid][cpsz]=size;
	Checkpoints[cpid][cpsd]=spawn_dist;
	return cpid;
}

stock CPS_IsPlayerInCheckpoint(playerid,cpid)
{
	if(!IsPlayerInCheckpoint(playerid)) return 0;
	if(CPSERVICE_actualcp[playerid] == cpid) return 1;
	else return 0;
}

stock CPS_IsPlayerInAnyCheckpoint(playerid)
{
	if(!IsPlayerInCheckpoint(playerid)) return 0;
	if(CPSERVICE_actualcp[playerid] == 0) return 0;
	else return 1;
}

stock CPS_GetPlayerCheckpoint(playerid) if(!IsPlayerInCheckpoint(playerid)) return 0; else return CPSERVICE_actualcp[playerid];

stock CPS_RemoveCheckpoint(cpid)
{
	if(cpid == 0 || UsedCPSlot[cpid] == 0) return 0;
	UsedCPSlot[cpid]=0;
	return 1;
}

public CPSERVICE_Handler()
{
	for(new i; i<MAX_PLAYERS; i++){
		new Float:prevdist = 100000.000;
		new prevcp;
		for(new cpid=1; cpid < MAX_CHECKPOINTS; cpid++){
			if(UsedCPSlot[cpid]) {
			    new Float:dist;
			    dist = CPSERVICE_getdist(i,Checkpoints[cpid][cpX],Checkpoints[cpid][cpY],Checkpoints[cpid][cpZ]);
				if(dist < prevdist){
		    		prevdist = dist;
			 		prevcp = cpid;
				}
			}
		}
		new cpid=prevcp;
		if(CPSERVICE_getdist(i,Checkpoints[cpid][cpX],Checkpoints[cpid][cpY],Checkpoints[cpid][cpZ]) < Checkpoints[cpid][cpsd]) {
		    if(CPSERVICE_actualcp[i] != cpid){
			    SetPlayerCheckpoint(i,Checkpoints[cpid][cpX],Checkpoints[cpid][cpY],Checkpoints[cpid][cpZ],Checkpoints[cpid][cpsz]);
			    CPSERVICE_actualcp[i] = cpid;
			}
		} else {
		    if(CPSERVICE_actualcp[i] != 0){
			    CPSERVICE_actualcp[i] = 0;
			    DisablePlayerCheckpoint(i);
			}
		}
	}
	return 1;
}

stock CPSERVICE_getdist(playerid,Float:x2,Float:y2,Float:z2)
{
	new Float:x1,Float:y1,Float:z1;
	new Float:tmpdis;
	GetPlayerPos(playerid,x1,y1,z1);
	tmpdis = floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));
	return floatround(tmpdis);
}
