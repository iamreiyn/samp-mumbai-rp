#if defined _OnPlayerPause_included
    #endinput
#endif
#define _OnPlayerPause_included

#include <a_samp>

#define MinTimeWithoutUpdates 6 // Time in seconds after which a player will be considered as paused.
//#define PRINTPAUSE // Define this if you want this script to print messages on your server console. This
//  is useful for example for admin filterscripts.

new stock TimeOfLastUpdate[MAX_PLAYERS];
new stock bool:Paused[MAX_PLAYERS];
new stock bool:InClassSelection[MAX_PLAYERS];

stock IsPlayerPaused(playerid)
{
    if(Paused[playerid] == true)
    {
        return 1;
    }
    return 0;
}

stock IsPlayerInClassSelection(playerid)
{
    if(InClassSelection[playerid] == true)
    {
        return 1;
    }
    return 0;
}

#define MinTimeWithoutUpdates2 (MinTimeWithoutUpdates * 1000)

forward SearchForNewlyPausedPlayers();
public SearchForNewlyPausedPlayers()
{
    new CurrentTime, PlayerState;
    CurrentTime = GetTickCount();
    for(new i = 0; i < MAX_PLAYERS; i ++)
    {
        if(Paused[i] == false)
        // If the player is already paused, there's no point in calling OnPlayerPause again.
        {
            if(InClassSelection[i] == false)
            // When a player enters the class selection screen, he stops sending updates just
            //  like when he pauses, so we need to know if he's selecting class.
            {
                if(IsPlayerConnected(i))
                {
                    if( (CurrentTime - TimeOfLastUpdate[i]) >= MinTimeWithoutUpdates2 )
                    {
                        PlayerState = GetPlayerState(i);
                        if( (PlayerState == PLAYER_STATE_ONFOOT) || (PlayerState == PLAYER_STATE_DRIVER) || (PlayerState == PLAYER_STATE_PASSENGER) )
                        {
                            OnPlayerPause(i);
                        }
                    }
                }
            }
        }
    }
    return 1;
}

forward OnPlayerPause(playerid);
forward OnPlayerUnpause(playerid);

static gOnPlPa_HasCB[7];

public OnGameModeInit()
{
    SetTimer("SearchForNewlyPausedPlayers", 500, true);

    gOnPlPa_HasCB[0] = funcidx("OnPlPa_OnPlayerConnect") != -1;
    gOnPlPa_HasCB[1] = funcidx("OnPlPa_OnPlayerDisconnect") != -1;
    gOnPlPa_HasCB[2] = funcidx("OnPlPa_OnPlayerRequestClass") != -1;
    gOnPlPa_HasCB[3] = funcidx("OnPlPa_OnPlayerSpawn") != -1;
    gOnPlPa_HasCB[4] = funcidx("OnPlPa_OnPlayerUpdate") != -1;
    gOnPlPa_HasCB[5] = funcidx("OnPlPa_OnPlayerPause") != -1;
    gOnPlPa_HasCB[6] = funcidx("OnPlPa_OnPlayerUnpause") != -1;
    if (funcidx("OnPlPa_OnGameModeInit") != -1)
    {
        return CallLocalFunction("OnPlPa_OnGameModeInit", "");
    }

    return 1;
}

#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif
#define OnGameModeInit OnPlPa_OnGameModeInit
forward OnPlPa_OnGameModeInit();

public OnPlayerConnect(playerid)
{
    Paused[playerid] = false;
    InClassSelection[playerid] = false;

    if (gOnPlPa_HasCB[0])
    {
        return CallLocalFunction("OnPlPa_OnPlayerConnect", "i",playerid);
    }
    return 1;
}
#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect OnPlPa_OnPlayerConnect
forward OnPlPa_OnPlayerConnect(playerid);

public OnPlayerDisconnect(playerid,  reason)
{
    Paused[playerid] = false;
    InClassSelection[playerid] = false;

    if (gOnPlPa_HasCB[1])
    {
        return CallLocalFunction("OnPlPa_OnPlayerDisconnect", "ii",playerid,  reason);
    }
    return 1;
}
#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect OnPlPa_OnPlayerDisconnect
forward OnPlPa_OnPlayerDisconnect(playerid,  reason);

public OnPlayerRequestClass(playerid,  classid)
{
    #if defined PRINTPAUSE
        if(InClassSelection[playerid] == false)
        {
            new NickName[MAX_PLAYER_NAME + 1];
            GetPlayerName( playerid, NickName, sizeof(NickName) );
            printf("[class] %s (id: %i) has entered class selection screen", NickName, playerid);
        }
    #endif
    InClassSelection[playerid] = true;

    if (gOnPlPa_HasCB[2])
    {
        return CallLocalFunction("OnPlPa_OnPlayerRequestClass", "ii",playerid,  classid);
    }
    return 1;
}
#if defined _ALS_OnPlayerRequestClass
    #undef OnPlayerRequestClass
#else
    #define _ALS_OnPlayerRequestClass
#endif
#define OnPlayerRequestClass OnPlPa_OnPlayerRequestClass
forward OnPlPa_OnPlayerRequestClass(playerid,  classid);

public OnPlayerSpawn(playerid)
{
    InClassSelection[playerid] = false;
    #if defined PRINTPAUSE
        new NickName[MAX_PLAYER_NAME + 1];
        GetPlayerName( playerid, NickName, sizeof(NickName) );
        printf("[spawn] %s (id: %i) has spawned", NickName, playerid);
    #endif

    if (gOnPlPa_HasCB[3])
    {
        return CallLocalFunction("OnPlPa_OnPlayerSpawn", "i",playerid);
    }
    return 1;
}
#if defined _ALS_OnPlayerSpawn
    #undef OnPlayerSpawn
#else
    #define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn OnPlPa_OnPlayerSpawn
forward OnPlPa_OnPlayerSpawn(playerid);

public OnPlayerUpdate(playerid)
{
    TimeOfLastUpdate[playerid] = GetTickCount();
    if(Paused[playerid] == true)
    // If the player was paused and now he sends an update, it's because he has just resumed his game.
    {
        OnPlayerUnpause(playerid);
    }

    if (gOnPlPa_HasCB[4])
    {
        return CallLocalFunction("OnPlPa_OnPlayerUpdate", "i",playerid);
    }
    return 1;
}
#if defined _ALS_OnPlayerUpdate
    #undef OnPlayerUpdate
#else
    #define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate OnPlPa_OnPlayerUpdate
forward OnPlPa_OnPlayerUpdate(playerid);

public OnPlayerPause(playerid)
{
    Paused[playerid] = true;
    #if defined PRINTPAUSE
        new NickName[MAX_PLAYER_NAME + 1];
        GetPlayerName( playerid, NickName, sizeof(NickName) );
        printf("[pause] %s (id: %i) has paused", NickName, playerid);
    #endif

    if (gOnPlPa_HasCB[5])
    {
        return CallLocalFunction("OnPlPa_OnPlayerPause", "i",playerid);
    }
    return 1;
}
#if defined _ALS_OnPlayerPause
    #undef OnPlayerPause
#else
    #define _ALS_OnPlayerPause
#endif
#define OnPlayerPause OnPlPa_OnPlayerPause
forward OnPlPa_OnPlayerPause(playerid);

public OnPlayerUnpause(playerid)
{
    Paused[playerid] = false;
    #if defined PRINTPAUSE
        new NickName[MAX_PLAYER_NAME + 1];
        GetPlayerName( playerid, NickName, sizeof(NickName) );
        printf("[resume] %s (id: %i) has returned from pausing", NickName, playerid);
    #endif

    if (gOnPlPa_HasCB[6])
    {
        return CallLocalFunction("OnPlPa_OnPlayerUnpause", "i",playerid);
    }
    return 1;
}
#if defined _ALS_OnPlayerUnpause
    #undef OnPlayerUnpause
#else
    #define _ALS_OnPlayerUnpause
#endif
#define OnPlayerUnpause OnPlPa_OnPlayerUnpause
forward OnPlPa_OnPlayerUnpause(playerid);