forward OnPlayerIntChange(playerid, oldint, newint);
forward OnPlayerWorldChange(playerid, oldworld, newworld);
forward ChangePlayerWorld(playerid, newworld);
forward ChangePlayerInt(playerid, newint);

public ChangePlayerInt(playerid, newint)
{
	new oldint = GetPlayerInterior(playerid);
	OnPlayerIntChange(playerid, oldint, newint);
}

public ChangePlayerWorld(playerid, newworld)
{
	new oldworld = GetPlayerVirtualWorld(playerid);
	OnPlayerWorldChange(playerid, oldworld, newworld);
}