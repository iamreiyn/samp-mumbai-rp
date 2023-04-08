/*
=======================
This Include Is Made By
=======>Sandra<========
=======================
*/

#include <a_samp>

#define SpawnPosFile "SpawnPositions.txt"
#define MAX_RANDOM_POSITIONS 100

//Countdown
new IsCountdownStarted;
new IsPlayerCountdownStarted[MAX_PLAYERS];
new PlayerCountdownCount[MAX_PLAYERS];
new CountdownCount;
new PlayerCountdownTimer[MAX_PLAYERS];
new CountdownTimer;

//PocketMoney:
new IsPocketMoneyEnabled;
new IsPocketMoneyMessageEnabled = 1;
new PocketMoneyAmount;
new PocketMoneyTimer;

//RandomSpawn
new RPCount;
enum rsinfo
{
	Float:RSX,
	Float:RSY,
	Float:RSZ,
	Float:RSA,
	RSinterior,
	RSvirtualworld,
}
new RandomSpawnInfo[MAX_RANDOM_POSITIONS][rsinfo];


//Other
enum resprayinfo
{
	Float:ResprayX,
	Float:ResprayY,
	Float:ResprayZ,
	Float:ResprayA
}
new ResprayInfo[MAX_VEHICLES][resprayinfo];
enum splayerinfo
{
	Float:SavedX,
	Float:SavedY,
	Float:SavedZ,
	Float:SavedA,
	SavedInterior
}
new SPlayerInfo[MAX_PLAYERS][splayerinfo];



/*
native ======CountDown================();
native CreateCountdown(time, sound);
native CreatePlayerCountdown(playerid, time, sound);
native StopCountdown();
native StopPlayerCountdown(playerid);
native ======PocketMoney==============();
native EnablePocketMoney(amount, frequency);
native DisablePocketMoney();
native SetPocketMoneyAmount(amount);
native SetPocketMoneyFrequency(frequency);
native TogglePocketMoneyMessage(toggle);
native =====Random Spawn=============();
native AddSpawnPos(Float:X, Float:Y, Float:Z, Float:Angle, Interior, VirtualWorld);
native RandomSpawnPlayer(playerid);
native ======Other====================();
native SkydivePlayer(playerid, hight);
native Cardive(carid, hight);
native FlipCar(carid);
native ResprayCar(carid);
native SavePlayerPos(playerid);
native LoadPlayerPos(playerid);

*/


stock CreateCountdown(time, sound)
{
	if(IsCountdownStarted == 0)
	{
	    for(new i; i<MAX_PLAYERS; i++)
	    {
	        if(IsPlayerConnected(i))
	        {
		        if(IsPlayerCountdownStarted[i] == 1)
		        {
		            KillTimer(PlayerCountdownTimer[i]);
		            PlayerCountdownCount[i] = 0;
		            IsPlayerCountdownStarted[i] = 0;
				}
			}
		}
		CountdownTimer = SetTimerEx("Countdown", 1000, 1, "d", sound);
		CountdownCount = time;
		IsCountdownStarted = 1;
	}
}
stock CreatePlayerCountdown(playerid, time, sound)
{
	if(IsPlayerCountdownStarted[playerid] == 0 && IsCountdownStarted == 0)
	{
		PlayerCountdownTimer[playerid] = SetTimerEx("PlayerCountdown", 1000, 1, "id", playerid, sound);
		PlayerCountdownCount[playerid] = time;
		IsPlayerCountdownStarted[playerid] = 1;
	}
}
stock StopCountdown()
{
	KillTimer(CountdownTimer);
	GameTextForAll(" ", 10, 3);
    CountdownCount = 0;
    IsCountdownStarted = 0;
}
stock StopPlayerCountdown(playerid)
{
	KillTimer(PlayerCountdownTimer[playerid]);
	GameTextForPlayer(playerid, " ", 10, 3);
    PlayerCountdownCount[playerid] = 0;
    IsPlayerCountdownStarted[playerid] = 0;
}

stock EnablePocketMoney(amount, frequency)
{
	if(IsPocketMoneyEnabled==0)
	{
	    PocketMoneyTimer = SetTimer("PocketMoney", (frequency*1000), 1);
	    IsPocketMoneyEnabled = 1;
	    PocketMoneyAmount = amount;

	}
}
stock DisablePocketMoney()
{
	if(IsPocketMoneyEnabled==1)
	{
	    KillTimer(PocketMoneyTimer);
	    IsPocketMoneyEnabled = 0;
    }
}
stock SetPocketMoneyAmount(amount)
{
    PocketMoneyAmount = amount;
}

stock SetPocketMoneyFrequency(frequency)
{
	KillTimer(PocketMoneyTimer);
	PocketMoneyTimer = SetTimer("PocketMoney", (frequency*1000), 1);
}

stock TogglePocketMoneyMessage(toggle)
{
    IsPocketMoneyMessageEnabled = toggle;
}

stock SkydivePlayer(playerid, hight)
{
	new Float:SDX, Float:SDY, Float:SDZ;
	GetPlayerPos(playerid, SDX, SDY, SDZ);
	GivePlayerWeapon(playerid, 46, 1);
	SetPlayerPos(playerid, SDX, SDY, (SDZ+hight));
}
stock Cardive(carid, hight)
{
	new Float:SDX, Float:SDY, Float:SDZ;
	GetVehiclePos(carid, SDX, SDY, SDZ);
	SetVehiclePos(carid, SDX, SDY, (SDZ+hight));
}
stock FlipCar(carid)
{
	new Float:FCX, Float:FCY, Float:FCZ, Float:FCA;
	GetVehiclePos(carid, FCX, FCY, FCZ);
	GetVehicleZAngle(carid, FCA);
	SetVehiclePos(carid, FCX, FCY, (FCZ+1.0));
	SetVehicleZAngle(carid, FCA);
}
stock ResprayCar(carid)
{
	GetVehiclePos(carid, ResprayInfo[carid][ResprayX], ResprayInfo[carid][ResprayY], ResprayInfo[carid][ResprayZ]);
	GetVehicleZAngle(carid, ResprayInfo[carid][ResprayA]);
	SetTimerEx("ResprayDone", 4000, 0, "i", carid);
	SetVehiclePos(carid, 1024.8990,-1024.7573,31.7264);
	SetVehicleZAngle(carid, 0);
}

stock SavePlayerPos(playerid)
{
	GetPlayerPos(playerid, SPlayerInfo[playerid][SavedX], SPlayerInfo[playerid][SavedY], SPlayerInfo[playerid][SavedZ]);GetVehiclePos(playerid,SPlayerInfo[playerid][SavedX], SPlayerInfo[playerid][SavedY], SPlayerInfo[playerid][SavedZ]);
	GetPlayerFacingAngle(playerid, SPlayerInfo[playerid][SavedA]);GetVehicleZAngle(playerid, SPlayerInfo[playerid][SavedA]);
	SPlayerInfo[playerid][SavedInterior] = GetPlayerInterior(playerid);
}
stock LoadPlayerPos(playerid)
{
                 SetPlayerInterior(playerid, SPlayerInfo[playerid][SavedInterior]);
                 SetPlayerPos(playerid, SPlayerInfo[playerid][SavedX], SPlayerInfo[playerid][SavedY], SPlayerInfo[playerid][SavedZ]);SetVehiclePos(playerid, SPlayerInfo[playerid][SavedX], SPlayerInfo[playerid][SavedY], SPlayerInfo[playerid][SavedZ]);SetPlayerFacingAngle(playerid, SPlayerInfo[playerid][SavedA]);SetVehicleZAngle(playerid, SPlayerInfo[playerid][SavedA]);
                 
}

stock AddSpawnPos(Float:X, Float:Y, Float:Z, Float:Angle, Interior, VirtualWorld)
{
	RandomSpawnInfo[RPCount][RSX] = X;
	RandomSpawnInfo[RPCount][RSY] = Y;
	RandomSpawnInfo[RPCount][RSZ] = Z;
	RandomSpawnInfo[RPCount][RSA] = Angle;
	RandomSpawnInfo[RPCount][RSinterior] = Interior;
	RandomSpawnInfo[RPCount][RSvirtualworld] = VirtualWorld;
	RPCount++;
}

stock RandomSpawnPlayer(playerid)
{
	new randompos = random(RPCount);
	SetPlayerVirtualWorld(playerid, RandomSpawnInfo[randompos][RSvirtualworld]);
	SetPlayerInterior(playerid, RandomSpawnInfo[randompos][RSinterior]);
	SetPlayerPos(playerid, RandomSpawnInfo[randompos][RSX], RandomSpawnInfo[randompos][RSY], RandomSpawnInfo[randompos][RSZ]);
	SetPlayerFacingAngle(playerid, RandomSpawnInfo[randompos][RSA]);
	SetCameraBehindPlayer(playerid);
}

forward Countdown(sound);
public Countdown(sound)
{
    if(CountdownCount == 0)
	{
	    if(sound == 1)
		{
		    for(new i; i<MAX_PLAYERS; i++)
		    {
		        if(IsPlayerConnected(i))
		        {
		            PlayerPlaySound(i, 1057, 0.0, 0.0, 0.0);
				}
			}
		}
	    GameTextForAll("~r~GoGoGo", 2000, 3);
	    KillTimer(CountdownTimer);
	    IsCountdownStarted = 0;
	}
	else
	{
	    if(sound == 1)
		{
		    for(new i; i<MAX_PLAYERS; i++)
		    {
		        if(IsPlayerConnected(i))
		        {
		            PlayerPlaySound(i, 1056, 0.0, 0.0, 0.0);
				}
			}
		}
		new cdstring[128];
		format(cdstring, sizeof(cdstring), "~y~%d", CountdownCount);
		GameTextForAll(cdstring, 1500, 3);
		CountdownCount--;
	}
}

forward PlayerCountdown(playerid, sound);
public PlayerCountdown(playerid, sound)
{
    if(PlayerCountdownCount[playerid] == 0)
	{
	    if(sound == 1) PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);
	    GameTextForPlayer(playerid,"~n~~n~~r~GoGoGo", 2000, 3);
	    KillTimer(PlayerCountdownTimer[playerid]);
	    IsPlayerCountdownStarted[playerid] = 0;
	}
	else
	{
	    if(sound == 1) PlayerPlaySound(playerid, 1056, 0.0, 0.0, 0.0);
		new pcdstring[128];
	    format(pcdstring, sizeof(pcdstring), "~n~~g~%d", PlayerCountdownCount[playerid]);
		GameTextForPlayer(playerid, pcdstring, 1500, 3);
		PlayerCountdownCount[playerid]--;
	}
}

forward PocketMoney(playerid);
public PocketMoney(playerid)
{
    if(IsPocketMoneyMessageEnabled == 1)
    {
    new pmstring[128];
    format(pmstring, sizeof(pmstring), "~r~Pocket ~y~Money ~n~ ~y~%s~g~$",PocketMoneyAmount);
    GameTextForAll(pmstring,2000,5);
    }
    if(IsPlayerConnected(playerid))
    {
    GivePlayerMoney(playerid,  PocketMoneyAmount);
    }
	
}

forward ResprayDone(carid);
public ResprayDone(carid)
{
	SetVehiclePos(carid, ResprayInfo[carid][ResprayX], ResprayInfo[carid][ResprayY], ResprayInfo[carid][ResprayZ]);
	SetVehicleZAngle(carid, ResprayInfo[carid][ResprayA]);
}
