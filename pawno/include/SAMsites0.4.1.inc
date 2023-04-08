/*
*       SA:MP Surface To Air Missiles (SAMsites)
*		Version: 0.4
*		(c) Copyright 2010 - 2011 by Awaran
*		@date Jan 18 2010
*       @re-distributed July 18 2010
*       @webaddress http://forum.sa-mp.com/showthread.php?t=115695
*
* Do not re-distribute. File is given 'AS IS' (no warranties)
*
* Always pay credits to authors
*
*

		The purpose of this include is to allow functionality of Surface
		To Air Missile launchers(SAMS) in San Andreas Multiplayer 0.3a.
		There is no saying that this current version(0.4) will work in
		future releases of San Andreas Multiplayer, however, future updates
		are a possibility. The said update '0.5 HARDCORE EDITION' has too
		many bugs to even allow connectivity to any server, the resourses
		the script needs is too great. There is no debug content in this
		release, nor will I release any such script that does contain
		any debug content.
*/

/*Configuration*/
#define MAX_SAMS 64
#define INVALID_SAM_ID 255
#define DEFAULT_MISSILE_SPEED 70
#define DEFAULT_SAM_RANGE 300
#define MISSILE_DRAG_TIME 25000 //milliseconds
#define SAM_RADAR_LIMIT 15.000

new sOBJECT[MAX_SAMS];
new resttime;
new samset;

enum SamS
{
	samida,
	Float:SX,
	Float:SY,
	Float:SZ,
	Float:speed,
	Float:range,
	chaseid,
	Fired,
	Ex,
	cancel,                    
};

new Sam[MAX_SAMS][SamS];
new Missile[MAX_SAMS];
new FireMissileKill[MAX_SAMS];
new FireMissileKill2[MAX_SAMS];
new DragKill[MAX_SAMS];
new Text3D:SamLabel[MAX_SAMS];
forward OnSamSiteUpdate(samid, playerid);

/* natives
native AddStaticSAM(Float:X, Float:Y, Float:Z);
native AddStaticSAMEx(Float:X, Float:Y, Float:Z, srange, sspeed);
native CreateSAM(Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ);
native CreateSAMEx(Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ, srange, sspeed);
native CreateSamLabel(samid, label[], color, Float:DrawDistance, LOS);
native SAM_start();
native SAM_cancel(samid);
*/

stock AddStaticSAM(Float:X, Float:Y, Float:Z)
{
	new samid = samset;
	if(samset > MAX_SAMS-1)
	{
		print("[SAM] Error - Script exceeds max limit");
		samid = INVALID_SAM_ID;
		return samid;
	}
	samset++;
	Sam[samid][samida] = samid;
	Sam[samid][SX] = X;
	Sam[samid][SY] = Y;
	Sam[samid][SZ] = Z;
    Sam[samid][speed] = DEFAULT_MISSILE_SPEED;
    Sam[samid][range] = DEFAULT_SAM_RANGE;
    Sam[samid][chaseid] = -1;
	Sam[samid][Fired] = 0;
	Sam[samid][Ex] = 0;
	printf("[SAM] SAM %d Created - %f,%f,%f -",samid,X,Y,Z);
	return samid;
}

stock AddStaticSAMEx(Float:X, Float:Y, Float:Z, Float:srange, Float:sspeed)
{
	new samid = samset;
	if(samset > MAX_SAMS-1)
	{
		print("[SAM] Error - Script exceeds max limit");
		samid = INVALID_SAM_ID;
		return samid;
	}
	samset++;
	Sam[samid][samida] = samid;
	Sam[samid][SX] = X;
	Sam[samid][SY] = Y;
	Sam[samid][SZ] = Z;
    Sam[samid][speed] = sspeed;
    Sam[samid][range] = srange;
    Sam[samid][chaseid] = -1;
    Sam[samid][Fired] = 0;
    Sam[samid][Ex] = 1;
    printf("[SAM] SAM %d Created - %f,%f,%f -",samid,X,Y,Z);
    return samid;
}

stock CreateSAM(Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ)
{
    new samid = samset;
    if(samset > MAX_SAMS-1)
	{
		print("[SAM] Error - Script exceeds max limit");
		samid = INVALID_SAM_ID;
		return samid;
	}
	samset++;
	Sam[samid][samida] = samid;
	Sam[samid][SX] = X;
	Sam[samid][SY] = Y;
	Sam[samid][SZ] = Z;
    Sam[samid][speed] = DEFAULT_MISSILE_SPEED;
    Sam[samid][range] = DEFAULT_SAM_RANGE;
    Sam[samid][chaseid] = -1;
    Sam[samid][Fired] = 0;
    sOBJECT[samid] = CreateObject(3884,X,Y,X,rX,rY,rZ);
    Sam[samid][Ex] = 0;
    printf("[SAM] SAM %d Created - %f,%f,%f -",samid,X,Y,Z);
    return samid;
}

stock CreateSAMEx(Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ, Float:srange, Float:sspeed)
{
	new samid = samset;
	if(samset > MAX_SAMS-1)
	{
		print("[SAM] Error - Script exceeds max limit");
		samid = INVALID_SAM_ID;
		return samid;
	}
	samset++;
	Sam[samid][samida] = samid;
	Sam[samid][SX] = X;
	Sam[samid][SY] = Y;
	Sam[samid][SZ] = Z;
    Sam[samid][speed] = sspeed;
    Sam[samid][range] = srange;
    Sam[samid][chaseid] = -1;
    Sam[samid][Fired] = 0;
    sOBJECT[samid] = CreateObject(3884,X,Y,X,rX,rY,rZ);
    Sam[samid][Ex] = 1;
    printf("[SAM] SAM %d Created - %f,%f,%f -",samid,X,Y,Z);
    return samid;
}

stock SAM_cancel(samid)
{
	Sam[samid][cancel] = 1;
}

stock SAM_start()
{
	resttime = SetTimer("SamLive",500,true);
	SetTimer("Restart",1800000,false);
	print("\n--------------------------------------");
	print(" Surface To Air Missiles System Loaded");
	print("                 0.4");
	print("--------------------------------------\n");
	return 1;
}

stock CreateSamLabel(samid, label[], color, Float:DrawDistance, LOS)
{
	if(samid == INVALID_SAM_ID) return false;
	new string[128];
	format(string,sizeof(string),"%s(%d)",label,samid);
	SamLabel[samid] = Create3DTextLabel(string,color,Sam[samid][SX],Sam[samid][SY],Sam[samid][SZ] + 2.00,DrawDistance,0,LOS);
	return true;
}

stock GetMaxSams()
{
	return samset;
}

forward SamLive();
public SamLive()
{
	for(new s = 0; s <GetMaxSams(); s++)
	{
	    if(s != INVALID_SAM_ID)
		{
	    	SamConfig(s);
		}
	}
}

forward SamConfig(samid);
public SamConfig(samid)
{
	for(new i = 0; i <MAX_PLAYERS; i++)
	{
	    if(IsPlayerConnected(i))
	    {
	        if(Sam[samid][Fired] == 0)
	        {
	            if(IsPlayerInAnyVehicle(i))
	            {
	                new veh = GetPlayerVehicleID(i);
	                if(IsAirVehicle(veh))
					{
					    if(Sam[samid][Ex] == 1)
					    {
					        if(IsVehicleInRangeOfPoint(veh,Sam[samid][range],Sam[samid][SX],Sam[samid][SY],Sam[samid][SZ]))
					        {
					            OnSamSiteUpdate(samid, i);
					            if(Sam[samid][cancel] == 1)
								{
									Sam[samid][cancel] = 0;
									return 1;
								}
					            Missile[samid] = CreateObject(354,Sam[samid][SX],Sam[samid][SY],Sam[samid][SZ],0,0,0);
					            Sam[samid][Fired] = 1;
					            Sam[samid][chaseid] = veh;
					            FireSam(samid,i,veh);
							}
						}
						else
						{
						    if(IsVehicleInRangeOfPoint(veh,DEFAULT_SAM_RANGE,Sam[samid][SX],Sam[samid][SY],Sam[samid][SZ]))
        					{
								OnSamSiteUpdate(samid, i);
								if(Sam[samid][cancel] == 1)
								{
									Sam[samid][cancel] = 0;
									return 1;
								}
	           		 			Missile[samid] = CreateObject(354,Sam[samid][SX],Sam[samid][SY],Sam[samid][SZ],0,0,0);
	          	  				Sam[samid][Fired] = 1;
	          	  				Sam[samid][chaseid] = veh;
	            				FireSam(samid,i,veh);
							}
						}
					}
				}
			}
		}
	}
	return 1;
}

forward FireSam(samid, playerid, vehicleid);
public FireSam(samid, playerid, vehicleid)
{
	if(Sam[samid][chaseid] != vehicleid) return 1;
	FireMissileKill[samid] = SetTimerEx("Fire",500,true,"iii",playerid, samid, vehicleid);
	FireMissileKill2[samid] = SetTimerEx("Destroy",300,true,"iii",playerid,samid,vehicleid);
	DragKill[samid] = SetTimerEx("Drag",MISSILE_DRAG_TIME,false,"i",samid);
	return 1;
}

forward Fire(playerid, samid, vehicleid);
public Fire(playerid, samid, vehicleid)
{
	if(!IsPlayerConnected(playerid))
	{
	    KillTimer(FireMissileKill[samid]);
	    KillTimer(FireMissileKill2[samid]);
	    KillTimer(DragKill[samid]);
	    Drag(samid);
	    return 1;
	}
	if(vehicleid == Sam[samid][chaseid])
	{
	    new Float:X,
	        Float:Y,
	        Float:Z;
		GetVehiclePos(vehicleid,X,Y,Z);
		if(Sam[samid][Ex] == 1)
		{
		    StopObject(Missile[samid]);
		    MoveObject(Missile[samid],X,Y,Z,Sam[samid][speed]);
		}
		else
		{
		    StopObject(Missile[samid]);
		    MoveObject(Missile[samid],X,Y,Z,DEFAULT_MISSILE_SPEED);
		}
	}
	return 1;
}

forward Destroy(playerid, samid, vehicleid);
public Destroy(playerid, samid, vehicleid)
{
	new Float:OX,
		Float:OY,
		Float:OZ;
	GetObjectPos(Missile[samid],OX,OY,OZ);
	if(IsVehicleInRangeOfPoint(vehicleid,3,OX,OY,OZ))
	{
	    CreateExplosion(OX,OY,OZ,2,10);
	    CreateExplosion(OX,OY,OZ,2,10);
	    CreateExplosion(OX,OY,OZ,2,10);
		KillTimer(FireMissileKill[samid]);
		KillTimer(FireMissileKill2[samid]);
		DecreaseVehicleHealth(vehicleid, 50.0);
		KillTimer(DragKill[samid]);
		SetTimerEx("FireSet",5000,false,"i",samid);
		DestroyObject(Missile[samid]);
	}
	return 1;
}

forward FireSet(samid);
public FireSet(samid)
{
	Sam[samid][Fired] = 0;
}

forward Drag(samid);
public Drag(samid)
{
	new Float:OX,
	    Float:OY,
	    Float:OZ;
	GetObjectPos(Missile[samid],OX,OY,OZ);
	CreateExplosion(OX,OY,OZ,2,2.00);
    CreateExplosion(OX,OY,OZ,2,2.00);
    CreateExplosion(OX,OY,OZ,2,2.00);
    Sam[samid][Fired] = 0;
    DestroyObject(Missile[samid]);
}

forward Restart();
public Restart()
{
	KillTimer(resttime);
	SAM_start();
}

stock IsAirVehicle(carid)
{
    new AirVeh[] = { 592, 577, 511, 512, 593, 520, 553, 476, 519, 460, 513, 548, 425, 417, 487, 488, 497, 563, 447, 469 };
    for(new i = 0; i < sizeof(AirVeh); i++)
    {
        if(GetVehicleModel(carid) == AirVeh[i]) return 1;
    }
    return 0;
}

stock DecreaseVehicleHealth(vehicleid, Float:decreaseby)
{
	new Float:voldhp;
	GetVehicleHealth(vehicleid, voldhp);
	return SetVehicleHealth(vehicleid,voldhp - decreaseby);
}

IsVehicleInRangeOfPoint(vehicleid, Float:vrange, Float:x, Float:y, Float:z)
{
	new Float:oldpos[3],
	    Float:temppos[3];
	GetVehiclePos(vehicleid, oldpos[0], oldpos[1], oldpos[2]);
	temppos[0] = (oldpos[0] -x);
	temppos[1] = (oldpos[1] -y);
	temppos[2] = (oldpos[2] -z);
	if(((temppos[0] < vrange) && (temppos[0] > -vrange)) && ((temppos[1] < vrange) && (temppos[1] > -vrange)) && ((temppos[2] < vrange) && (temppos[2] > -vrange)))
	{
	    return true;
	}
	return false;
}

