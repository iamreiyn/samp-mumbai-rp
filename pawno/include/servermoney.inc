/* *****************************************
 Name: Server Side money Script [GM]
 By: X_Cutter
 Date: September 2009 UPDATED: October 2009
 Use: Avoid money hacks
 Version: 3
 SA-MP: Should work on any version.
 Made for: 0.2X / 0.3a
***************************************** */
/*CREDITS: Romanius for the callback hooking idea*/


/*
 Use: Include this to your gamemode right under #include <a_samp> by
 writing #include <servermoneyGM>
*/


#define CallLoop(%1,%2) for(new %1; %1 < %2; %1++)
#define CALLBACK_AMOUNT 500

new SERVERSIDETIMER;
new ServerSideCash[MAX_PLAYERS];

public OnGameModeInit()
{
	ServerMoneyInit();
	return GMInit();
}

public OnGameModeExit()
{
	ServerMoneyExit();
	return;
}

forward GMInit();
forward GMExit();

ServerMoneyInit()
{
	SERVERSIDETIMER=SetTimer("ServerMoneyCB",1000,true);
	return 1;
}

ServerMoneyExit() 
{
	KillTimer(SERVERSIDETIMER);
	return 1;
}


forward ServerMoneyCB();

public ServerMoneyCB()
{
	CallLoop(ServerSidep,MAX_PLAYERS)
	{
		if(IsPlayerConnected(ServerSidep))
		{
			if(GetPlayerMoney(ServerSidep) != ServerSideCash[ServerSidep])
			{
				new H4xc4sh=GetPlayerMoney(ServerSidep);
				H4xc4sh=H4xc4sh-ServerSideCash[ServerSidep];
				if(H4xc4sh > CALLBACK_AMOUNT) OnPlayerHaveExtraCash(ServerSidep,H4xc4sh);
			}
			GivePlayerMoney(ServerSidep,-GetPlayerMoney(ServerSidep));
			GivePlayerMoney(ServerSidep,ServerSideCash[ServerSidep]);
		}
		
	}
	return 1;
}


forward GivePlayerMoneyEx(playerid,cashgiven);
public GivePlayerMoneyEx(playerid,cashgiven)
{
	ServerSideCash[playerid]=ServerSideCash[playerid]+cashgiven;
	return 1;
}

forward ResetPlayerMoneyEx(playerid);
public ResetPlayerMoneyEx(playerid)
{
	ServerSideCash[playerid]=0;
	return 1;
}

forward GetPlayerMoneyEx(playerid);
public GetPlayerMoneyEx(playerid)
{
	return ServerSideCash[playerid];
}

forward OnPlayerHaveExtraCash(playerid,extraamount);

#define GetPlayerMoney GetPlayerMoneyEx
#define GivePlayerMoney GivePlayerMoneyEx
#define ResetPlayerMoney ResetPlayerMoneyEx

#define OnGameModeInit GMInit
#define OnGameModeExit GMExit
