						//////////////////////
						///Anti Money Cheat///
						//////Created by://///
						//////°Fallout°///////
						//////////////////////


#include <a_samp>
#include <Dini>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//settings//

#define MAX_DIFFERENCE 1000

new AntiCheat = 1;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

forward F_OnInit();
forward F_OnPlayerConnect(playerid);
forward CheckMoney();
forward DifferenceDetected(playerid);

public F_OnInit()
{
    if(AntiCheat == 1)
    {
        SetTimer("CheckMoney", 4000, 1);
    }
}

public F_OnPlayerConnect(playerid)
{
    new file[128];
    format(file, sizeof(file), "F_AntiCheat/id_%i.ini", playerid);
    if (!dini_Exists(file))
    {
        dini_Create(file);
    }
    dini_IntSet(file, "Money", 0);
}

public CheckMoney()
{
    for(new i=0; i<GetMaxPlayers(); i++)
    {
        if (IsPlayerConnected(i))
        {
            new file[128];
            format(file, sizeof(file), "F_AntiCheat/id_%i.ini", i);
            new F_Money;
            F_Money = dini_Int(file, "Money");
            new cash = GetPlayerMoney(i);
            if (cash > F_Money)
            {
                if ((cash-F_Money) > MAX_DIFFERENCE)
                {
                    SetTimerEx("DifferenceDetected", 2000, 0, "i", i);
                }
            }
        }
    }
}

public DifferenceDetected(playerid)
{
    new file[128];
    format(file, sizeof(file), "F_AntiCheat/id_%i.ini", playerid);
    new F_Money;
    F_Money = dini_Int(file, "Money");
    new cash = GetPlayerMoney(playerid);
    if (cash > F_Money)
    {
        if ((cash-F_Money) > MAX_DIFFERENCE)
        {
            new hackedmoney;
            hackedmoney = cash - F_Money;
            GivePlayerMoney(playerid, -hackedmoney);
            new kickedstring[128];
            new kickedname[MAX_PLAYER_NAME];
            GetPlayerName(playerid, kickedname, sizeof(kickedname));
            format(kickedstring, sizeof(kickedstring), "%s was auto-kicked for: Money cheat. ($%i)", kickedname, hackedmoney);
            SendClientMessageToAll(0xAFAFAFAA, kickedstring);
            printf("%s was auto-kicked for: Money cheat. ($%i)", kickedname, hackedmoney);
            Kick(playerid);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

stock F_GivePlayerMoney(playerid, amount)
{
    new file[128];
    format(file, sizeof(file), "F_AntiCheat/id_%i.ini", playerid);
    new F_Money;
    F_Money = dini_Int(file, "Money");
    dini_IntSet(file, "Money", F_Money += amount);
    GivePlayerMoney(playerid, amount);
    return 1;
}

stock F_SetPlayerMoney(playerid, amount)
{
    new file[128];
    format(file, sizeof(file), "F_AntiCheat/id_%i.ini", playerid);
    dini_IntSet(file, "Money", amount);
    ResetPlayerMoney(playerid);
    GivePlayerMoney(playerid, amount);
    return 1;
}

stock F_ResetPlayerMoney(playerid)
{
    new file[128];
    format(file, sizeof(file), "F_AntiCheat/id_%i.ini", playerid);
    dini_IntSet(file, "Money", 0);
    ResetPlayerMoney(playerid);
    return 1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////