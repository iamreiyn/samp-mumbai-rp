/*
================================================================================
-------------------------------------------------
LuX Administration System v1.0

Functions Include (1.0)
-------------------------------------------------
================================================================================
*/

#if defined _lfuncs_included
  #endinput
#endif

#define _lfuncs_included

#include <a_samp>
    
#define MAX_FORBIDDEN_WEAPONS 20
#define MAX_WEAPONS 47
#define MAX_CTELES 100
#define CTELE_LINE 10
#define CTELE_TIMER 1800000

#define RED 0xFB0000AA

new WeaponForbiddenForPlayer[MAX_PLAYERS][MAX_WEAPONS];
new ForbiddenWeapons[MAX_FORBIDDEN_WEAPONS];
new ForbiddenWeaponsCount;

enum CreatedTeles
{
	Float:PosX,
	Float:PosY,
	Float:PosZ,
	Float:PosA,
	PosInt[30],
	TName[30],
	TValid,
}

new CTeleInfo[MAX_CTELES][CreatedTeles];

stock PlayerName2(playerid)
  {
	new name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, name, sizeof(name));
	return name;
}

stock pName(playerid)
{
	new name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, name, sizeof(name));
	return name;
}


stock PlayerSoundForAll(SoundID)
{
	for(new i = 0; i < MAX_PLAYERS; i++)
	PlayerPlaySound(i, SoundID, 0.0, 0.0, 0.0);
}

stock TimeStamp()
{
	new time = GetTickCount() / 1000;
	return time;
}

stock GetWeaponIDFromName(WeaponName[])
{
	if(strfind("molotov",WeaponName,true)!=-1)
	return 18;
	for(new i = 0; i <= 46; i++)
	{
	switch(i)
	{
	case 0,19,20,21,44,45: continue;
	default:
	{
	new name[32]; GetWeaponName(i,name,32);
	if(strfind(name,WeaponName,true) != -1)
	return i;
	}
	}
	}
	return -1;
}

stock IsPlayerLAdmin(playerid)
{
new name[MAX_PLAYER_NAME];
GetPlayerName(playerid, name, sizeof(name));
new file[256], tmp, tmp2;
format(file,256,"/LuxAdmin/Accounts/%s.sav",udb_encode(name));
tmp = dini_Int(file,"level");
tmp2 = dini_Int(file,"loggedin");

if( (IsPlayerConnected(playerid)) && (tmp > 0) && (tmp2 == 1))
return true;
else return false;
}

stock IsPlayerAdminLevel(playerid, level)
{
new name[MAX_PLAYER_NAME];
GetPlayerName(playerid, name, sizeof(name));
new file[256], tmp, tmp2;
format(file,256,"/LuxAdmin/Accounts/%s.sav",udb_encode(name));
tmp = dini_Int(file,"level");
tmp2 = dini_Int(file,"loggedin");
printf("tmp = %d, tmp2(logged) = %d, level = %d", tmp, tmp2, level);
if( (IsPlayerConnected(playerid)) && (tmp >= level) && (tmp2 != 0))
return true;
else return false;
}

stock IsValidWeapon(weaponid)
{
    if (weaponid > 0 && weaponid < 19 || weaponid > 21 && weaponid < 47) return 1;
    return 0;
}

//--------------------------
stock IsForbiddenWeapon(weaponid)
{
	if(weaponid)
	{
	for(new i=0;i<ForbiddenWeaponsCount;i++)
 	if(ForbiddenWeapons[i]==weaponid)
  	return true;
	}
	return false;
}

stock ForbidWeaponForPlayer(playerid,weaponid,forbid)
{
	if(IsPlayerConnected(playerid))
	{
	    WeaponForbiddenForPlayer[playerid][weaponid]=forbid;
		return 1;
	}
	return 0;
}

stock ResetForbiddenWeaponsForPlayer(playerid)
{
	if(IsPlayerConnected(playerid))
	{
    	for(new i=0;i<MAX_WEAPONS;i++)
		ForbidWeaponForPlayer(playerid,i,false);

		for(new i=0;i<MAX_FORBIDDEN_WEAPONS;i++)
		ForbidWeaponForPlayer(playerid,ForbiddenWeapons[i],true);
		return 1;
	}
	return 0;
}

stock L_NewLine(string[])
{
	new len = strlen(string);
	if (string[0]==0) return ;
	if ((string[len - 1] == '\n') || (string[len - 1] == '\r')) {
		string[len - 1] = 0;
		if (string[0]==0) return ;
		if ((string[len - 2] == '\n') || (string[len - 2] == '\r')) string[len - 2] = 0;
	}
}
//----------------------------------------------------

stock TempBanCheck(playerid)
{
	new ip[15];
	new str[128];
	new load[4][32];
	new ban_day, ban_month, ban_year, ban_ip[15];
	GetPlayerIp(playerid, ip, sizeof ip);
	new year, month, day;
	getdate(year, month, day);
	new File:file = fopen("LuxAdmin/Config/TempBans.ban",io_read);
	if (file)
	{
	    while (fread(file, str, sizeof str))
	    {
	        split(str, load, '|');

	        ban_day = strval(load[0]);
	        ban_month = strval(load[1]);
	        ban_year = strval(load[2]);
	        strmid(ban_ip, load[3], 0, strlen(load[3])-1, 15);
	    	if (!(year >= ban_year && month >= ban_month && day >= ban_day) && !strcmp(ban_ip, ip, true))
	    	{
	    	    format(str, sizeof str, "|- You are temporarily banned from this server until: %d/%d/%d -|", ban_day, ban_month, ban_year);
	    	    SendClientMessage(playerid, RED, str);
	    	    return Kick(playerid);
	    	}
		}
	}
	return true;
}

stock IsMonth31(month)
{
 	switch (month)
	{
	    case 1: return 1;
	    case 3: return 1;
	    case 5: return 1;
	    case 7: return 1;
	    case 8: return 1;
	    case 10: return 1;
	    case 12: return 1;
	    default: return 0;
	}
	return 0;
}

stock IsMonth29(year)
{
 	new y = 2000;
 	for(new i = 4; i < 3000; i += 4) if ((y+i) == year) return 1;
 	return 0;
}

stock strtok2(const string[], &idx)
{
    new length = strlen(string);
	while ((idx < length) && (string[idx] <= ' '))
	{
		idx++;
	}
	new offset = idx;
	new result[128];
	while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
	{
		result[idx - offset] = string[idx];
		idx++;
	}
	result[idx - offset] = EOS;
	return result;
}
//----------------------------------------------------

stock ReturnPlayerID(PlayerName[])
{
	for(new i = 0; i < MAX_PLAYERS; i++)
	{
	if(IsPlayerConnected(i))
	{
	if(strfind(pName(i),PlayerName,true)!=-1)
	return i;
	}
	}
	return INVALID_PLAYER_ID;
}
stock CheckFolders()
    {
	if(!fexist("LuxAdmin/"))
	{
    print("\n ERROR!");
    print(" Folder 'LuxAdmin' not localized!\n");
	return 1;
	}
	if(!fexist("LuxAdmin/Logs/")){
    print("\n ERROR!");
    print(" Folder 'Logs' not localized!\n");
    }
	if(!fexist("LuxAdmin/Config/")){
    print("\n ERROR!");
    print(" Folder 'Config' not localized!\n");
	}
	if(!fexist("LuxAdmin/Accounts/")){
    print("\n ERROR!");
    print(" Folder 'Accounts' not localized!\n");
	return 1;
    }
    return 1;
}

stock IsNumeric(string[])
{
	for (new i = 0, j = strlen(string);
	i < j; i++)
	{
	if (string[i] > '9' || string[i] < '0')
	return 0;
	}
	return 1;
}

stock IsValidSkin(SkinID)
{
	if((SkinID == 0)||(SkinID == 7)||(SkinID >= 9 && SkinID <= 41)||(SkinID >= 43 && SkinID <= 64)||(SkinID >= 66 && SkinID <= 73)||(SkinID >= 75 && SkinID <= 85)||(SkinID >= 87 && SkinID <= 118)||(SkinID >= 120 && SkinID <= 148)||(SkinID >= 150 && SkinID <= 207)||(SkinID >= 209 && SkinID <= 264)||(SkinID >= 274 && SkinID <= 288)||(SkinID >= 290 && SkinID <= 299)) return true;
	else return false;
}


stock LoadCreatedTeles()
{
	if(fexist("LuxAdmin/Config/CreatedTeles.cfg"))
	{
	new File:TPFile = fopen("LuxAdmin/Config/CreatedTeles.cfg", io_read);
	new tpstring[256];
 	new Field[6][128];
	new NbTP = 0;
	while(fread(TPFile, tpstring, sizeof(tpstring)))
	{
 		if(NbTP >= MAX_CTELES) break;
  		if(split(tpstring, Field, ',') == 6)
    	{
  			strmid(CTeleInfo[NbTP][TName],   Field[0],0,strlen(Field[0]),30);
			CTeleInfo[NbTP][PosX]	= floatstr(Field[1]);
			CTeleInfo[NbTP][PosY]	= floatstr(Field[2]);
			CTeleInfo[NbTP][PosZ]	= floatstr(Field[3]);
			CTeleInfo[NbTP][PosA]	= floatstr(Field[4]);
			CTeleInfo[NbTP][PosInt]	= strlen(Field[5]);
			CTeleInfo[NbTP][TValid]  		 = 1;
			NbTP++;
			}
		}
	fclose(TPFile);
	print("\n");
	}
	else printf("\nERROR: File 'CreatedTeleports' NOT Loaded!\n");
	return 1;
	}
