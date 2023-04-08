#if defined _fep_included
	#endinput
#endif
#define _fep_included

#include <a_samp>

//------------------------------------------------------------------------------

#define ForEachPlayer(%0) 		for(new index_%0=0, %0=ConnectedPlayerList[0]; index_%0<ConnectedPlayers; index_%0++, %0=ConnectedPlayerList[index_%0])
#define GetConnectedPlayers()   ConnectedPlayers

//------------------------------------------------------------------------------

new ConnectedPlayers;
new ConnectedPlayerList[MAX_PLAYERS+1];//Loop would bug when server is full D: (Without +1)

//------------------------------------------------------------------------------

public OnPlayerConnect(playerid)
{
	if(!IsPlayerNPC(playerid))
		AddPlayer(playerid);
	return CallLocalFunction("FEP_OnPlayerConnect","i",playerid);
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect FEP_OnPlayerConnect
forward FEP_OnPlayerConnect(playerid);

public OnPlayerDisconnect(playerid,reason)
{
    RemovePlayer(playerid);
	return CallLocalFunction("FEP_OnPlayerDisconnect","ii",playerid,reason);
}

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect FEP_OnPlayerDisconnect
forward FEP_OnPlayerDisconnect(playerid,reason);

//------------------------------------------------------------------------------

stock AddPlayer(playerid)
{
	if(ConnectedPlayers>=MAX_PLAYERS || playerid<0 || playerid>=MAX_PLAYERS)
	    return 0;

	ConnectedPlayerList[ConnectedPlayers++]=playerid;
	return 1;
}

stock RemovePlayer(playerid)
{
	for(new i=0;i<ConnectedPlayers;i++)
	{
	    if(ConnectedPlayerList[i]==playerid)
	    {
	        ConnectedPlayers--;
	        ConnectedPlayerList[i]=ConnectedPlayerList[ConnectedPlayers];
	        return 1;
	    }
	}
	return 0;
}
