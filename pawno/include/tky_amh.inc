//TKY Anti Money Hack! (GodFather Compile) by chenza

new ScriptMoney[MAX_PLAYERS];

forward TKY_GiveMoney(playerid, amounttogive);
forward TKY_ResetMoney(playerid);
forward TKY_GetMoney(playerid);

public TKY_GiveMoney(playerid, amounttogive)
{
	GivePlayerMoney(playerid, amounttogive);
	ScriptMoney[playerid] = (ScriptMoney[playerid] + amounttogive);
	return 1;
}

public TKY_ResetMoney(playerid)
{
	ResetPlayerMoney(playerid);
	ScriptMoney[playerid] = 0;
	return 1;
}

public TKY_GetMoney(playerid)
{
	ScriptMoney[playerid];
	return 1;
}