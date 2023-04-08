#define INFO(%0,%1) SCM(%0, 0x6EF83CFF, ""YELLOW"INFO | "WHITE" "%1)
#define ERROR(%0,%1) SCM(%0, 0xF81414FF, ""RED"ERROR | "WHITE" "%1)
#define USAGE(%0,%1) SCM(%0, 0xC0C0C0FF, ""GRAY"USAGE | "WHITE" "%1)
#define SERVER(%0,%1) SCMTA(0xC0C0C0FF, ""SERVERBLUE"SERVER | "WHITE"  "%1)

#define SPVW    SetPlayerVirtualWorld
#define SCMTA   SendClientMessageToAll
#define SCM     SendClientMessage
#define SPD     ShowPlayerDialog
#define SPP     SetPlayerPos
#define GPP     GetPlayerPos
#define SPH     SetPlayerHealth
#define GPH     GetPlayerHealth

#define SERVERBLUE  "{00A2D7}"
#define WHITE       "{FFFFFF}"
#define YELLOW      "{6EF83C}"
#define GRAY        "{C0C0C0}"
#define RED         "{F81414}"
#define HGREEN		"{04CC29}"
#define OGREEN      "{00D1AE}"

new ACTimer,
AirBreak_Warn			[MAX_PLAYERS],
Float:AirBreak_Pos		[MAX_PLAYERS][3],
Float:Vehicle_Pos 		[MAX_VEHICLES][4],
AirBreak_Speed			[MAX_PLAYERS],
AirBreak_Height			[MAX_PLAYERS];
RImmunity				[MAX_PLAYERS],
VehHP					[MAX_PLAYERS],

veh_created = 0;

new Float:MaxVehSpeed[213] = 
{
  //MAX SPEED             //ACCELERATION
	160.0, 					//25.0 
	160.0, 					//15.0 
	200.0, 					//28.0 
	120.0, 					//25.0 
	150.0, 					//18.0 
	165.0, 					//24.0 
	110.0, 					//25.0
	170.0, 					//27.0 
	110.0, 					//20.0 
	180.0, 					//18.0 
	160.0, 					//19.0
	240.0, 					//30.0 
	160.0, 					//23.0 
	160.0, 					//15.0 
	140.0, 					//18.0 
	230.0, 					//30.0 
	155.0, 					//24.0
	200.0, 					//16.0
	150.0, 					//15.0 
	160.0, 					//18.0 
	180.0, 					//19.0 
	180.0, 					//21.0 
	165.0, 					//20.0 
	145.0, 					//14.0
	170.0, 					//30.0
	200.0,					//16.0 
	200.0, 					//22.0 
	170.0, 					//20.0 
	170.0, 					//15.0 
	200.0, 					//33.0
	190.0,					//1.7
	130.0, 					//14.0 
	80.0,  					//40.0 
	180.0, 					//20.0 
	200.0, 					//28.0 
	120.0, 					//18.0 
	160.0, 					//18.0 
	160.0,					//18.0 
	160.0, 					//24.0 
	160.0, 					//23.0 
	160.0, 					//18.0 
	75.0,  					//35.0 
	150.0, 					//16.0
	150.0, 					//13.0 
	110.0, 					//45.0 
	165.0, 					//22.0
	190.0, 					//3.0
	200.0, 					//16.0
	190.0, 					//30.0
	150.0, 					//25.0 
	120.0, 					//18.0 
	240.0, 					//30.0
	190.0, 					//2.5  
	190.0, 					//0.7
	190.0, 					//1.4
	140.0, 					//25.0 
	160.0, 					//14.0 
	160.0, 					//15.0 
	165.0, 					//20.0 
	160.0, 					//15.0
	200.0,  				//1.7
	190.0, 					//50.0
	190.0,					//30.0
	190.0, 					//40.0
	75.0,  					//1.0
	75.0,  					//35.0
	160.0, 					//22.0 
	160.0, 					//16.0
	190.0, 					//50.0
	200.0, 					//16.0 
	170.0, 					//25.0
	160.0, 					//25.0
	190.0, 					//1.6  
	190.0, 					//1.2 
	160.0, 					//18.0 
	160.0, 					//24.0 
	200.0, 					//16.0
	200.0, 					//28.0 
	150.0, 					//14.0 
	165.0, 					//16.0 
	200.0, 					//30.0 
	120.0, 					//18.0
	150.0,					//25.0 
	120.0, 					//16.0
	190.0, 					//0.5
	160.0, 					//20.0 
	100.0, 					//35.0
	200.0, 					//16.0
	200.0, 					//16.0
	170.0, 					//20.0 
	170.0, 					//22.0 
	160.0,					//18.0 
	160.0, 					//20.0
	190.0, 					//3.0
	220.0, 					//26.0 
	170.0, 					//28.0 
	200.0, 					//26.0
	200.0, 					//16.0
	140.0, 					//14.0 
	140.0, 					//14.0 
	160.0, 					//24.0
	75.0,  					//35.0
	220.0, 					//26.0
	220.0, 					//26.0
	160.0, 					//24.0
	170.0, 					//20.0
	230.0, 					//26.0 	
	165.0, 					//20.0 
	140.0, 					//14.0
	190.0, 					//50.0
	190.0, 					//50.0
	200.0, 					//16.0 
	200.0, 					//16.0  
	200.0,					//16.0
	120.0, 					//25.0 
	120.0, 					//25.0 
	165.0, 					//20.0 
	165.0, 					//22.0 
	160.0, 					//24.0
	200.0, 					//16.0 	
	200.0, 					//16.0
	190.0, 					//50.0 
	190.0, 					//60.0 
	190.0, 					//50.0
	110.0, 					//20.0 
	160.0, 					//25.0 
	160.0, 					//20.0 
	160.0, 					//20.0 
	170.0, 					//25.0 
	160.0, 					//18.0
	60.0, 					//20.0 
	70.0, 					//20.0 
	140.0, 					//25.0
	200.0,					//28.0 
	160.0, 					//23.0
	160.0, 					//40.0 
	160.0, 					//24.0 
	110.0, 					//20.0
	110.0, 					//20.0
	150.0,  				//2.0
	160.0, 					//18.0 
	230.0, 					//30.0  
	160.0, 					//24.0 
	165.0, 					//25.0
	170.0, 					//27.0
	160.0, 					//22.0 
	160.0, 					//18.0 
	160.0, 					//18.0
	200.0, 					//16.0
	160.0, 					//24.0 
	160.0, 					//17.0 
	165.0, 					//22.0 
	160.0, 					//18.0 	
	200.0, 					//16.0
	170.0, 					//25.0
	180.0, 					//30.0 
	110.0, 					//45.0 
	110.0, 					//45.0 
	200.0, 					//20.0 
	200.0, 					//28.0 
	200.0, 					//28.0
	200.0, 					//20.0 
	200.0, 					//28.0
	200.0, 					//16.0
	75.0,  					//35.0 		
	200.0, 					//24.0 
	160.0, 					//24.0 
	160.0, 					//24.0 
	170.0, 					//35.0
	110.0, 					//20.0
	110.0, 					//20.0 
	90.0,					//18.0 
	60.0, 					//12.0 
	110.0, 					//35.0 
	60.0, 					//12.0 
	160.0,					//20.0 
	160.0, 					//20.0
	200.0,					//16.0
	110.0,					//20.0 
	160.0, 					//25.0 
	165.0, 					//24.0
	190.0, 					//50.0
	160.0, 					//15.0
	170.0, 					//15.0 
	120.0, 					//18.0 
	165.0, 					//21.0
	190.0, 					//40.0
	200.0, 					//24.0 
	140.0, 					//14.0 
	200.0, 					//30.0
	110.0, 					//20.0
	120.0,					//18.0
	200.0, 					//16.0 
	200.0, 					//16.0
	60.0, 					//50.0
	190.0, 					//1.5
	200.0, 					//25.0 
	200.0, 					//25.0 
	200.0, 					//25.0 
	160.0, 					//30.0
	165.0, 					//25.0 
	110.0, 					//24.0 
	200.0, 					//23.0 
	200.0, 					//26.0
	0.0,					//0.0
	0.0,					//0.0
	160.0, 					//20.0
	160.0, 					//20.0
	160.0, 					//20.0 
	140.0, 					//14.0 
	160.0, 					//20.0
	60.0,  					//20.0
};

public OnGameModeInit()
{
    ACTimer = SetTimer("AntiCheat", 1000, true);
    return 1;
}

public OnGameModeExit()
{
    KillTimer(ACTimer);
    return 1;
}

public OnPlayerConnect(playerid)
{
    AirBreak_Warn[playerid] = 0;
    AirBreak_Speed[playerid] = 0;
    AirBreak_Height[playerid] = 0;
    return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
    AirBreak_Speed[playerid] = 0;
	GetPlayerPos(playerid, AirBreak_Pos[playerid][0], AirBreak_Pos[playerid][0], AirBreak_Pos[playerid][0]);
    return 1;
}

public OnVehicleSpawn(vehicleid)
{
	m_SetVehicleHealth(vehicleid, 999.0);
	return 1;
}

forward AntiCheat();
public AntiCheat()
{
	foreach(new i: Player)
	{
		if(GetPlayerState(i) == PLAYER_STATE_ONFOOT)
		{
			new Float:X, Float:Y, Float:Z;
			GetPlayerVelocity(i, X, Y, Z);
       		if(floatround(X) > 0 || floatround(Y) > 0 || floatround(Z) > 0)
       		{
       			SCM(i, -1, ""RED"CHEAT | "WHITE"You have been kicked for using speed hack (ON-FOOT)");
				new string[128];
				format(string, sizeof(string), ""SERVERBLUE"SERVER | "WHITE"Player %s has been kicked for using speed hack (ON-FOOT)!", GetName(i));
				SCMTA(-1, string);
				DelayedKick(i);
				return 1;
       		}
    	}
        if(!IsPlayerNPC(i))
    	{
    		new speed, time = GetTickCount(), string[128];
    		if(GetPlayerSurfingVehicleID(i) == INVALID_VEHICLE_ID && GetPlayerSurfingObjectID(i) == INVALID_OBJECT_ID && GetPlayerPing(i) < 260 && GetSpeed(i) < 30 && (GetPlayerState(i) == PLAYER_STATE_DRIVER || GetPlayerState(i) == PLAYER_STATE_ONFOOT))
    		{
    			speed = floatround((GetPlayerDistanceFromPoint(i, AirBreak_Pos[i][0], AirBreak_Pos[i][1], AirBreak_Pos[i][2]) / float (time - AirBreak_Height[i])) * 1000.0);
    			GetPlayerPos(i, AirBreak_Pos[i][0], AirBreak_Pos[i][1], AirBreak_Pos[i][2]);
    			if(speed > 65 && AirBreak_Speed[i] > 65)
    			{
    				AirBreak_Warn[i] ++;
    				if(AirBreak_Warn[i] < 3)
    				{
    					format(string, sizeof(string), ""RED"CHEAT | "WHITE"Player %s might be using AIRBREAK", GetName(i));
    					AdminMessage(-1, string);
    					AirBreak_Speed[i] = 0;
    				}
    				else
    				{
    					SCM(i, -1, ""RED"CHEAT | "WHITE"You have been kicked for using Airbreak");
    					format(string, sizeof(string), ""SERVERBLUE"SERVER | "WHITE"Player %s has been kicked for using Airbreak", GetName(i));
    					SCMTA(-1, string);
    					DelayedKick(i);
    					return 1;
    				}
    			}
    			AirBreak_Speed[i] = speed;
    		}
    		else
    		{
    			GetPlayerPos(i, AirBreak_Pos[i][0], AirBreak_Pos[i][1], AirBreak_Pos[i][2]);
    			AirBreak_Speed[i] = 0;
    		}
    		AirBreak_Height[i] = time;
        }
    }
	if(GetPlayerState(i) == PLAYER_STATE_DRIVER)
    	{
    		SetTimer("FallingChecker", 1000, true);
    		new vid = GetPlayerVehicleID(i), mid = GetVehicleModel(vid), Float:speed = GetSpeed(i);
    		if(speed > MaxVehSpeed[mid - 400] && MaxVehSpeed[mid - 400] > 35) //change value 35 if you want. THis means if max speed of veh is 200. If player goes 235 it will detect him..
    		{
    			SCM(i, -1, ""RED"CHEAT | "WHITE"You have been kicked for using speed hack (IN-VEHICLE)");
				new string[128];
				format(string, sizeof(string), ""SERVERBLUE"SERVER | "WHITE"Player %s has been kicked for using speed hack (IN-VEHICLE)!", GetName(i));
				SCMTA(-1, string);
				DelayedKick(i);
				return 1;
    		}
    	}
	if(GetPlayerState(i) == PLAYER_STATE_DRIVER && GetPlayerPing(i) < 260)
    	{
    		new Float:vhp;
    		GetVehicleHealth(GetPlayerVehicleID(i), vhp);
    		if(NearTuning(i) || NearSpray(i))
    		{
    			if(vhp > 999.0)
    			{
    				RImmunity[i] = 1;
    				SetVehicleHealth(GetPlayerVehicleID(i), 999.0);
    			}
    		}
    		if(vhp > 999.0 && RImmunity[i] == 0)
    		{
    			if(!NearTuning(i) || NearSpray(i))
    			{
    				VehHP[i] ++;
    				{
    					if(VehHP[i] < 2)
    					{
							new string[128];
							format(string, sizeof(string), ""RED"CHEAT | "WHITE"Player %s might be using Vehicle-Repair Hack", GetName(i));
							AdminMessage(-1, string);
							m_SetVehicleHealth(GetPlayerVehicleID(i), 999.0);
    					}
    					if(VehHP[i] >= 2)
    					{
    						SCM(i, -1, ""RED"CHEAT | "WHITE"You have been kicked for using Vehicle-Repair Hack");
							new string[120];
							format(string, sizeof(string), ""SERVERBLUE"SERVER | "WHITE"Player %s has been kicked for using Vehicle-Repair Hack", GetName(i));
							SCMTA(-1, string);
							m_SetVehicleHealth(GetPlayerVehicleID(i), 999.0);
    						SetVehicleToRespawn(GetPlayerVehicleID(i));
							DelayedKick(i);
							return 1;
    					}
    				}
    			}
    		}
    	}
    	if(RImmunity[i] == 1)
    	{
    		RImmunity[i] = 0;
    		return 1;
    	}
    }
    return 1;
}

CMD:fv(playerid)
{
	if(PlayerInfo[playerid][Admin] < 1) //change this so it fits your system
	{
	    ERROR(playerid, "You are not allowed to use this command");
	    return 1;
	}
	if(!IsPlayerInAnyVehicle(playerid))
	{
	    ERROR(playerid, "You need to be in vehicle to use this command");
	    return 1;
	}
	new string[128];
	RepairVehicle(GetPlayerVehicleID(playerid));
	m_SetVehicleHealth(GetPlayerVehicleID(i), 999.0);
	INFO(playerid, "Vehicle repaired");
	return 1;
}

forward _KickPlayerDelayed(playerid);
public _KickPlayerDelayed(playerid)
{
	Kick(playerid);
	return 1;
}

GetSpeed(playerid)
{
    new Float:X, Float:Y, Float:Z, Float:A;
    if(IsPlayerInAnyVehicle(playerid))
    GetVehicleVelocity(GetPlayerVehicleID(playerid), X, Y, Z);
    else GetPlayerVelocity(playerid, X, Y, Z);
    A = floatsqroot((X * X)+(Y * Y)+(Z * Z)) * 178.8617875;
    return floatround(A);
}

AdminMessage(color, string[])
{
	foreach(new i: Player)
	{
		if(IsPlayerConnected(i) && PlayerInfo[i][Admin] >= 1)
		{
		    SCM(i, color, string);
		}
	}
	return 0;
}

NearTuning(playerid)
{
	if(IsPlayerInRangeOfPoint(playerid, 25.0, 1041.5073,-1030.9069,31.7923)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 25.0, 2645.1272,-2033.8993,13.2808)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 25.0, -1935.9835,231.4505,33.8772)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 25.0, -2713.1533,216.9000,3.9767)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 25.0, 617.5360,-1.9900,1000.6378)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 25.0, 2386.6309,1037.3684,10.8203)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 25.0, 615.2858,-124.2390,997.6057)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 25.0, 616.7612,-74.8120,997.8828)) return 1;
	else return 0;
}
/////////////////////////////////////////////////////////////////////////////////
NearSpray(playerid)
{
	if(IsPlayerInRangeOfPoint(playerid, 15.0, 2389.6, 1483.26, 9.81843)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 15.0, -2430.13, 1013.71, 49.3413)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 15.0, -1908.93, 292.353, 40.0413)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 15.0, 491.103, -1747.55, 9.45516)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 15.0, 1021.81, -1018.71, 30.9081)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 15.0, 2056.6, -1835.9, 12.5443)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 15.0, 2640.78, -2049.99, 12.543)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 15.0, -1941.04, 251.714, 33.4274)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 15.0, -2728.53, 212.295, 3.45112)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 15.0, -1424.11, 2576.61, 54.8156)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 15.0, -103.636, 1112.42, 18.7017)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 15.0, 715.806, -462.403, 14.9635)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 15.0, 1025.0094,-1025.0917,32.1016)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 15.0, 1968.23, 2157.88, 9.59696)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 15.0, 1851.0931,-1856.4600,13.1099)) return 1; //bomb place
	return 0;
}

m_CreateVehicle(vehicletype, Float:x, Float:y, Float:z, Float:rotation, color1, color2, respawn_delay)
{
	if(veh_created <= MAX_VEHICLES)
	{
		new o;
		o = CreateVehicle(vehicletype, x, y, z, rotation, color1, color2, respawn_delay);
		m_SetVehicleHealth(o, 999.0);
		SetVehicleParamsCarWindows(o, 1, 1, 1, 1);
		Vehicle_Pos[o][0] = x;
		Vehicle_Pos[o][1] = y;
		Vehicle_Pos[o][2] = z;
		Vehicle_Pos[o][3] = rotation;
		veh_created ++;
		return o;
	}
	return 1;
}

m_SetVehicleHealth(vehicleid, Float:hp)
{
	if(hp > 999.0) SetVehicleHealth(vehicleid, 999.0);
	else SetVehicleHealth(vehicleid, hp);
	return 1;
}
