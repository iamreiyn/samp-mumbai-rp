/*
================================================================================
-------------------------------------------------
LuX Administration System v1.0
-------------------------------------------------
================================================================================
*/

#if defined _ladmin_included
  #endinput
#endif
#define _ladmin_included
#pragma library ladmin

#include <a_samp>
#include <ldudb>

stock IsPlayerLuxAdmin(playerid)
{
new name[MAX_PLAYER_NAME];
GetPlayerName(playerid, name, sizeof(name));
new file[256], tmp, tmp2;

format(file,256,"/LuxAdmin/Accounts/%s.sav",udb_encode(name));
tmp = dini_Int(file,"Level");
tmp2 = dini_Int(file,"Loggedin");

if( (IsPlayerConnected(playerid)) && (tmp > 0) && (tmp2 == 1) )
return true;
else return false;
}

stock IsPlayerLuxAdminLevel(playerid, level)
{
new name[MAX_PLAYER_NAME];
GetPlayerName(playerid, name, sizeof(name));

new file[256], tmp, tmp2;

format(file,256,"/LuxAdmin/Accounts/%s.sav",udb_encode(name));
tmp = dini_Int(file,"Level");
tmp2 = dini_Int(file,"Loggedin");
printf("tmp = %d, tmp2(logged) = %d, level = %d", tmp, tmp2, level);
if((IsPlayerConnected(playerid)) && (tmp >= level) && (tmp2 != 0))
return true;
else return false;
}
