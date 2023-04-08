#if defined _dns_included
        #endinput
#endif
#define _dns_included

native dns(host[], extra = 0);
native rdns(ip[], extra = 0);
native DNS_PollEvents();

forward OnDNS(host[], ip[], extra);
forward OnReverseDNS(ip[], host[], extra);

stock GetPlayerHost(playerid)
{
        new
                ip[16];
        GetPlayerIp(playerid, ip, sizeof(ip));
        rdns(ip, playerid);
        return 1;
}