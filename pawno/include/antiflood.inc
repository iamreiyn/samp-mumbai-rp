#include <a_samp>
#define IP_LIMIT 2 // = Max connections from one single IP
#define SAME_IP_CONNECT 4 // = The number of connects from the same IP before banning the flooder
new Same_IP=0,Join_Stamp,ban_s[25],exceed=0;
#define Time_Limit 3500 // = The time span between connects, adjust it to your own specifications

public OnPlayerConnect(playerid)
{
	new ConnIP[16];
	GetPlayerIp(playerid,ConnIP,16);
	new compare_IP[16];
	new number_IP = 0;
	for(new i=0; i<MAX_PLAYERS; i++) {
		if(IsPlayerConnected(i)) {
		    GetPlayerIp(i,compare_IP,16);
		    if(!strcmp(compare_IP,ConnIP)) number_IP++;
		}
	}
	if((GetTickCount() - Join_Stamp) < Time_Limit)
	    exceed=1;
	else
	    exceed=0;
 	if(strcmp(ban_s, ConnIP, false) == 0 && exceed == 1 )
 	{
 	    Same_IP++;
 	    if(Same_IP > SAME_IP_CONNECT)
 	    {
	   		Ban(playerid);
 			Same_IP=0;
 	    }
 	}
 	else
 	{
 		Same_IP=0;
	}
	if(number_IP > IP_LIMIT)
	    Kick(playerid);
	GetStampIP(playerid);
	return 1;

}
stock GetStampIP(playerid){
	new S_IP[16];
	Join_Stamp=GetTickCount();
	GetPlayerIp(playerid,S_IP,16);
	format(ban_s, 16, "%s", S_IP);
}