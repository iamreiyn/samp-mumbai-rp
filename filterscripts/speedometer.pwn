#include <a_samp>
#include <zcmd>
new PlayerText:cWspeedo[MAX_PLAYERS][10];
new carfuel[MAX_VEHICLES] = {100, ...}; // Connect with your Fuel system to make it work otherwise it will be stuck at 100%
new PlayerSpeedo[MAX_PLAYERS]; // 0 = KM/H, 1 = MP/H
public OnFilterScriptInit()
{
	print("Prospect Roleplay - Vehicle Speedometer loaded.");
	return 1;
}
new const modelNames[212][] = {
    "Landstalker", "Bravura", "Buffalo", "Linerunner", "Perrenial", "Sentinel", "Dumper", "Firetruck", "Trashmaster",
    "Stretch", "Manana", "Infernus", "Voodoo", "Pony", "Mule", "Cheetah", "Ambulance", "Leviathan", "Moonbeam",
    "Esperanto", "Taxi", "Washington", "Bobcat", "Whoopee", "BF Injection", "Hunter", "Premier", "Enforcer",
    "Securicar", "Banshee", "Predator", "Bus", "Rhino", "Barracks", "Hotknife", "Article Trailer", "Previon", "Coach",
    "Cabbie", "Stallion", "Rumpo", "RC Bandit", "Romero", "Packer", "Monster", "Admiral", "Squalo", "Seasparrow",
    "Pizzaboy", "Tram", "Article Trailer 2", "Turismo", "Speeder", "Reefer", "Tropic", "Flatbed", "Yankee", "Caddy", "Solair",
    "Berkley's RC Van", "Skimmer", "PCJ-600", "Faggio", "Freeway", "RC Baron", "RC Raider", "Glendale", "Oceanic",
    "Sanchez", "Sparrow", "Patriot", "Quad", "Coastguard", "Dinghy", "Hermes", "Sabre", "Rustler", "ZR-350", "Walton",
    "Regina", "Comet", "BMX", "Burrito", "Camper", "Marquis", "Baggage", "Dozer", "Maverick", "News Chopper", "Rancher",
    "FBI Rancher", "Virgo", "Greenwood", "Jetmax", "Hotring", "Sandking", "Blista Compact", "Police Maverick",
    "Boxville", "Benson", "Mesa", "RC Goblin", "Hotring Racer A", "Hotring Racer B", "Bloodring Banger", "Rancher",
    "Super GT", "Elegant", "Journey", "Bike", "Mountain Bike", "Beagle", "Cropduster", "Stuntplane", "Tanker", "Roadtrain",
    "Nebula", "Majestic", "Buccaneer", "Shamal", "Hydra", "FCR-900", "NRG-500", "HPV1000", "Cement Truck", "Tow Truck",
    "Fortune", "Cadrona", "SWAT Truck", "Willard", "Forklift", "Tractor", "Combine", "Feltzer", "Remington", "Slamvan",
    "Blade", "Streak", "Freight", "Vortex", "Vincent", "Bullet", "Clover", "Sadler", "Firetruck", "Hustler", "Intruder",
    "Primo", "Cargobob", "Tampa", "Sunrise", "Merit", "Utility", "Nevada", "Yosemite", "Windsor", "Monster", "Monster",
    "Uranus", "Jester", "Sultan", "Stratum", "Elegy", "Raindance", "RC Tiger", "Flash", "Tahoma", "Savanna", "Bandito",
    "Freight Flat", "Streak Carriage", "Kart", "Mower", "Dune", "Sweeper", "Broadway", "Tornado", "AT-400", "DFT-30",
    "Huntley", "Stafford", "BF-400", "News Van", "Tug", "Petrol Trailer", "Emperor", "Wayfarer", "Euros", "Hotdog", "Club",
    "Freight Box", "Article Trailer 3", "Andromada", "Dodo", "RC Cam", "Launch", "LSPD Car", "SFPD Car", "LVPD Car",
    "Police Rancher", "Picador", "S.W.A.T", "Alpha", "Phoenix", "Glendale", "Sadler", "Luggage", "Luggage", "Stairs",
    "Boxville", "Tiller", "Utility Trailer"
};
Float:GetVehicleSpeed(vehicleid)
{
	new
	    Float:x,
	    Float:y,
	    Float:z;

	if(GetVehicleVelocity(vehicleid, x, y, z))
	{
		return floatsqroot((x * x) + (y * y) + (z * z)) * 181.5;
	}

	return 0.0;
}
Float:GetVehicleSpeedMPH(vehicleid)
{
	new
	    Float:x,
	    Float:y,
	    Float:z;

	if(GetVehicleVelocity(vehicleid, x, y, z))
	{
		return floatsqroot((x * x) + (y * y) + (z * z)) * 100;
	}

	return 0.0;
}
IsAbicycle(vehid)
{
	switch(GetVehicleModel(vehid))
	{
		case 481, 509, 510: return true;
	}
	return false;
}
GetVehicleName(vehicleid)
{
	new
		modelid = GetVehicleModel(vehicleid),
		name[32];

	if(400 <= modelid <= 611)
	    strcat(name, modelNames[modelid - 400]);
	else
	    name = "Unknown";

	return name;
}
public OnPlayerConnect(playerid)
{
    PlayerSpeedo[playerid] = 0; // default speed KM/H
	//------------------------------------------------------------------------//
	cWspeedo[playerid][0] = CreatePlayerTextDraw(playerid, 525.111389, 394.088836, "box");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][0], 0.000000, -0.044444);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][0], 623.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][0], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][0], -1);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][0], 1);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][0], 0x000000AA);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][0], 255);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][0], 0);

	cWspeedo[playerid][1] = CreatePlayerTextDraw(playerid, 627.777770, 365.715454, "box");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][1], 0.000000, 6.133327);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][1], 621.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][1], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][1], -1);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][1], 1);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][1], 0x000000AA);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][1], 255);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][1], 0);

	cWspeedo[playerid][2] = CreatePlayerTextDraw(playerid, 565.889099, 341.168945, "");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][2], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][2], 60.000000, 73.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][2], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][2], -1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][2], 0);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][2], 5);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][2], 0);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][2], 0);
	PlayerTextDrawSetPreviewModel(playerid, cWspeedo[playerid][2], 411);
	PlayerTextDrawSetPreviewRot(playerid, cWspeedo[playerid][2], 0.000000, 0.000000, -30.000000, 1.000000);
	PlayerTextDrawSetPreviewVehCol(playerid, cWspeedo[playerid][2], 1, 1);

	cWspeedo[playerid][3] = CreatePlayerTextDraw(playerid, 524.222167, 395.582153, "220");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][3], 0.342222, 1.316266);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][3], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][3], -1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][3], 1);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][3], 255);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][3], 3);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][3], 1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][3], 0);

	cWspeedo[playerid][4] = CreatePlayerTextDraw(playerid, 523.777770, 382.142395, "infernus");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][4], 0.172888, 0.903111);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][4], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][4], -1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][4], 1);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][4], 255);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][4], 2);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][4], 1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][4], 0);

	cWspeedo[playerid][5] = CreatePlayerTextDraw(playerid, 526.000244, 408.026733, "KM/H");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][5], 0.175555, 0.669155);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][5], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][5], -1378294017);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][5], 255);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][5], 1);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][5], 1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][5], 0);

	cWspeedo[playerid][6] = CreatePlayerTextDraw(playerid, 572.933105, 396.080047, "100");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][6], 0.301333, 1.171911);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][6], 2);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][6], -1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][6], 1);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][6], 255);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][6], 3);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][6], 1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][6], 0);

	cWspeedo[playerid][7] = CreatePlayerTextDraw(playerid, 572.509460, 407.528869, "FUEL");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][7], 0.151111, 0.689067);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][7], 2);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][7], -1378294017);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][7], 255);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][7], 1);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][7], 1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][7], 0);

	cWspeedo[playerid][8] = CreatePlayerTextDraw(playerid, 621.111633, 396.080108, "999.0");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][8], 0.231555, 1.052444);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][8], 3);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][8], -1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][8], 1);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][8], 255);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][8], 3);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][8], 1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][8], 0);

	cWspeedo[playerid][9] = CreatePlayerTextDraw(playerid, 618.444335, 406.533325, "HEALTH");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][9], 0.145778, 0.699022);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][9], 3);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][9], -1378294017);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][9], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][9], 255);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][9], 1);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][9], 1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][9], 0);

	//-------------------------------------------------------------------------//

	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	for(new i = 0; i < 10; i ++) {
        PlayerTextDrawDestroy(playerid, cWspeedo[playerid][i]);
		cWspeedo[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
	}
	return 1;
}


public OnPlayerStateChange(playerid, newstate, oldstate)
{
	if(newstate == PLAYER_STATE_DRIVER)
	{
	    new vehicleid = GetPlayerVehicleID(playerid);
		if(!IsAbicycle(vehicleid))
		{
	        new vstr[30];
			format(vstr, sizeof(vstr), "%s", GetVehicleName(vehicleid));
			PlayerTextDrawSetString(playerid, cWspeedo[playerid][4], vstr);

	        PlayerTextDrawSetPreviewModel(playerid, cWspeedo[playerid][2], GetVehicleModel(GetPlayerVehicleID(playerid)));
		    PlayerTextDrawShow(playerid, cWspeedo[playerid][2]);

			for(new i = 0; i < 10; i++) {
				PlayerTextDrawShow(playerid, cWspeedo[playerid][i]);
			}
		}
	}
	else if(oldstate == PLAYER_STATE_DRIVER)
	{
        for(new i = 0; i < 10; i++) {
			PlayerTextDrawHide(playerid, cWspeedo[playerid][i]);
		}
	}
	return 1;
}

public OnPlayerUpdate(playerid)
{
	new vehicle = GetPlayerVehicleID(playerid);
	if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && !IsAbicycle(vehicle)) // Making sure the player is in a vehicle as driver
	{
	    if(PlayerSpeedo[playerid] == 0)
	    {
			new Float:H;
			GetVehicleHealth(vehicle, H);
			new speed[24];
			format(speed, sizeof(speed), "%.0f", GetVehicleSpeed(vehicle));
			PlayerTextDrawSetString(playerid, cWspeedo[playerid][3], speed);
			new vehfuel[24];
			format(vehfuel, sizeof(vehfuel), "%d", carfuel[vehicle]);
			PlayerTextDrawSetString(playerid, cWspeedo[playerid][6], vehfuel);
	        new vehiclehealth[24];
	        format(vehiclehealth, sizeof(vehiclehealth), "%.0f", H);
			PlayerTextDrawSetString(playerid, cWspeedo[playerid][8], vehiclehealth);
		}
		else if(PlayerSpeedo[playerid] == 1)
		{
			new Float:H;
			GetVehicleHealth(vehicle, H);
			new speed[24];
			format(speed, sizeof(speed), "%.0f", GetVehicleSpeedMPH(vehicle));
			PlayerTextDrawSetString(playerid, cWspeedo[playerid][3], speed);
			new vehfuel[24];
			format(vehfuel, sizeof(vehfuel), "%d", carfuel[vehicle]);
			PlayerTextDrawSetString(playerid, cWspeedo[playerid][6], vehfuel);
	        new vehiclehealth[24];
	        format(vehiclehealth, sizeof(vehiclehealth), "%.0f", H);
			PlayerTextDrawSetString(playerid, cWspeedo[playerid][8], vehiclehealth);
			PlayerTextDrawSetString(playerid, cWspeedo[playerid][5], "MP/H");
		}
	}
	return 1;
}

//-----------------------------------------------------------------------------//
CMD:switchspeedo(playerid, params[])
{
	#pragma unused params
	if(PlayerSpeedo[playerid] == 0)
	{
        PlayerSpeedo[playerid] = 1;
        SendClientMessage(playerid, -1, "Your speed has been switched to MP/H");
	}
	else
	{
        PlayerSpeedo[playerid] = 0;
		SendClientMessage(playerid, -1, "Your speed has been switched to KM/H");
	}
	return 1;
}
