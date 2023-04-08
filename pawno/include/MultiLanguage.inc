/*
	MultiLanguage by Littlejohny (c) 2009
	Don't remove the Credits, thanks !
*/

#if defined _MultiLanguage_included
  #endinput
#endif

#include <a_samp>
#include <dini>

#define _MultiLanguage_included
#pragma library MultiLanguage

/*
native SetPlayerLanguage(playerid, language);
native GetPlayerLanguage(playerid);
native IsPlayerLanguage(playerid, language);
native
native
native SendLanguageText(playerid, color, string1[], string2[]);
native SendLanguageTextToAll(color, string1[], string2[]);
native GameLanguageText(playerid, color, string1[], string2[], time, style);
native GameLanguageTextForAll(color, string1[], string2[], time, style);
native
native SavePlayerLanguage(playerid);
native LoadPlayerLanguage(playerid);
native
native GetName(playerid);
*/

new TheLanguage[MAX_PLAYERS] = 1; // sets the Player at the first connection to Language 1

stock SetPlayerLanguage(playerid, language) // Sets the Player to a Language
{
	if(language == 1)
	{
	    if(TheLanguage[playerid] == 1) return 0;
	    TheLanguage[playerid] = 1;
	}
	else if(language == 2)
	{
	    if(TheLanguage[playerid] == 2) return 0;
	    TheLanguage[playerid] = 2;
	}
 	return 1;
}

stock SavePlayerLanguage(playerid) // Saves the Language
{
    new file[256];
    if(LanguageFileExist(playerid))
	{
 		file = GetPlayerLanguageFile(playerid);
    	dini_IntSet(file, "Language", TheLanguage[playerid]);
    }
 	return 1;
}

stock LoadPlayerLanguage(playerid) // Loads the Language
{
	new file[256];
    if(!LanguageFileExist(playerid))
	{
		file = GetPlayerLanguageFile(playerid);
	    dini_Create(file);
	    dini_IntSet(file, "Language", TheLanguage[playerid]);
	}
    else if(LanguageFileExist(playerid))
	{
 		file = GetPlayerLanguageFile(playerid);
    	dini_IntSet(file, "Language", TheLanguage[playerid]);
    }
 	return 1;
}

stock LanguageFileExist(playerid) // Exist the Language File ?
{
	if(dini_Exists(GetPlayerLanguageFile(playerid)))
	{
		return true;
	} else {
	    return false;
	}
}

stock GetPlayerLanguageFile(playerid) // Gets the Language File of a Player
{
	new string[256];
	format(string,sizeof(string),"/Language/%s.ini", GetName(playerid));
	return string;
}

stock GetName(playerid) // Gets the Name of a Player
{
	new name[MAX_PLAYER_NAME];
	GetPlayerName(playerid,name,sizeof(name));
	return name;
}

stock SendLanguageText(playerid, color, const string1[], const string2[])
{
	if(TheLanguage[playerid] == 1) // Language 1
	{
		SendClientMessage(playerid, color, string1);
	}
	else if(TheLanguage[playerid] == 2) // Language 2
	{
		SendClientMessage(playerid, color, string2);
	}
	return 1;
}

stock SendLanguageTextToAll(color, const string1[], const string2[])
{
    for(new i = 0; i < MAX_PLAYERS; i++)
	{
		if(TheLanguage[i] == 1) // Language 1
		{
			SendClientMessage(i, color, string1);
		}
		else if(TheLanguage[i] == 2) // Language 2
		{
			SendClientMessage(i, color, string2);
		}
	}
	return 1;
}

stock GameLanguageText(playerid, const string1[], const string2[], time, style)
{
	if(TheLanguage[playerid] == 1) // Language 1
	{
		GameTextForPlayer(playerid, string1, time, style);
	}
	else if(TheLanguage[playerid] == 2) // Language 2
	{
		GameTextForPlayer(playerid, string2, time, style);
	}
	return 1;
}

stock GameLanguageTextForAll(const string1[], const string2[], time, style)
{
    for(new i = 0; i < MAX_PLAYERS; i++)
	{
		if(TheLanguage[i] == 1) // Language 1
		{
			GameTextForPlayer(i,string1, time, style);
		}
		else if(TheLanguage[i] == 2) // Language 2
		{
			GameTextForPlayer(i,string2, time, style);
		}
	}
	return 1;
}

stock GetPlayerLanguage(playerid) // Gets the Language of a Player
{
	return TheLanguage[playerid];
}

stock IsPlayerLanguage(playerid) // Sets the Player to a Language
{
	new language = TheLanguage[playerid];
	if(language == 1)
	{
	    return true;
	}
	else if(language == 2)
	{
	    return true;
	}
 	return false;
}