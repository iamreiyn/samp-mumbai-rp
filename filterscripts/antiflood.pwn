#include <a_samp>
#include <core>
#include <float>

new globFA0;


public CheckIfFlood(playerid)
{
	new var0[1000];
	for(new var1, var1 = 0; var1 < 1000; )
	{
		GetPlayerIp(playerid, var0, 1000);
		if(!strcmp(globFA0, var0))
		{
			(0 + (playerid << 2))++;
		}
	}
	if((0 + (playerid << 2)) > 3)
	{
		Ban(playerid);
	}
	return 1;
}

public OnPlayerConnect(playerid)
{
	GetPlayerIp(playerid, globFA0, 30);
	0 + (playerid << 2) = 0;
	SetTimerEx("CheckIfFlood", 1000, true, "i", playerid);
	return 1;
}

