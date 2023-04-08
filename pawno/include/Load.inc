
#include <a_samp>

new Loaded[MAX_PLAYERS];
forward LoadPlayers();

stock Pause(playerid)
{
	TogglePlayerControllable(playerid,false);
   
	Loaded[playerid] = 1;
   	new Float:x, Float:y, Float:z;
   	GetPlayerPos(playerid, x, y, z);
 	SetPlayerPos(playerid,x,y,z+1);
    SetTimer("LoadPlayers",3100,false);

}

public LoadPlayers()
{
	for(new i = 0; i < MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i))
		{
			if(Loaded[i] == 1)
			{
			TogglePlayerControllable(i,true);
			Loaded[i] = 0;
			}
		}
	}
}