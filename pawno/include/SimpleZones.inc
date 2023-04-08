#include <a_samp>

#define defcolor 0xFF000096

forward GangZoneCreateEx(ID, color, name[], Float:minx, Float:miny, Float:maxx, Float:maxy);
forward GangZoneDestroyEx(ID);
forward GangZoneFlash(ID,flashcolor,seconds);
forward OnFlashEnd(ID);
forward ZoneFlash();
forward IsPlayerInTurf(playerid,id);
forward OnTurfInit();
forward OnTurfConnect(playerid);

enum zInfo
{
	zCreated,
	zColor[255],
	zName[128],
    Float:zMinX,
    Float:zMinY,
    Float:zMaxX,
    Float:zMaxY,
    zFlash,
    zFlashColor[255],
};
new ZoneInfo[1024][zInfo];

public GangZoneCreateEx(ID, color, name[], Float:minx, Float:miny, Float:maxx, Float:maxy)
{
    ID = GangZoneCreate(minx, miny, maxx, maxy);
    ZoneInfo[ID][zCreated] = 1;
    ZoneInfo[ID][zColor] = color;
    strmid(ZoneInfo[ID][zName], name, 0, strlen(name), 255);
    ZoneInfo[ID][zMinX] = minx;
    ZoneInfo[ID][zMinY] = miny;
    ZoneInfo[ID][zMaxX] = maxx;
    ZoneInfo[ID][zMaxY] = maxy;
}

public GangZoneDestroyEx(ID)
{
    GangZoneDestroy(ID);
    ZoneInfo[ID][zCreated] = 0;
    ZoneInfo[ID][zColor] = 0;
    ZoneInfo[ID][zMinX] = 0.0;
    ZoneInfo[ID][zMinY] = 0.0;
    ZoneInfo[ID][zMaxX] = 0.0;
    ZoneInfo[ID][zMaxY] = 0.0;
    ZoneInfo[ID][zFlash] = 0;
    ZoneInfo[ID][zFlashColor] = 0;
}

public IsPlayerInTurf(playerid,id)
{
    new Float:X,Float:Y,Float:Z;
    GetPlayerPos(playerid, X, Y, Z);
    if((X >= ZoneInfo[id][zMinX] && Y >= ZoneInfo[id][zMinY]) && (X >= ZoneInfo[id][zMinX] && X <= ZoneInfo[id][zMaxX]))
    {
	    return 1;
	}
	return 0;
}

public GangZoneFlash(ID,flashcolor,seconds)
{
    GangZoneFlashForAll(ID,flashcolor);
    ZoneInfo[ID][zFlash] = seconds;
    ZoneInfo[ID][zFlashColor] = flashcolor;
}

public ZoneFlash()
{
    for(new z = 0; z < sizeof(ZoneInfo); z++)
	{
		if(ZoneInfo[z][zCreated] == 1)
		{
            if(ZoneInfo[z][zFlash] > 0)
		    {
		        ZoneInfo[z][zFlash] -= 1;
		        if(ZoneInfo[z][zFlash] == 0) { GangZoneStopFlashForAll(z); OnFlashEnd(z); }
		    }
		}
	}
}

public OnTurfInit()
{
   SetTimer("ZoneFlash", 1000, 1);
}

public OnTurfConnect(playerid)
{
    for(new z = 0; z < sizeof(ZoneInfo); z++)
	{
		if(ZoneInfo[z][zCreated] == 1)
		{
            GangZoneShowForPlayer(playerid,z,ZoneInfo[z][zColor]);
            if(ZoneInfo[z][zFlash] > 0)
		    {
                GangZoneFlashForPlayer(playerid,z,ZoneInfo[z][zFlashColor]);
		    }
		}
	}
}
