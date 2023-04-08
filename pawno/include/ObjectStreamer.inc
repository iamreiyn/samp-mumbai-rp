/*       (c) 2008 Pixels^      */
/*       To modify or redistribute you need my permission.    */

#define Radius 200
#define MAX_STREAM_OBJECTS 1000 //Set at 1000, you can change to whatever you want.

enum Management
{
	Float:X,
	Float:Y,
	Float:Z,
	Float:rX,
	Float:rY,
	Float:rZ,
	Model,
	Used,
	PlayerAttach,
	Float:AttachX,
	Float:AttachY,
	Float:AttachZ
}
new Object[MAX_STREAM_OBJECTS][Management];
new Player[MAX_PLAYERS][MAX_STREAM_OBJECTS];
new ObjectTotal;
new ObjectTimer;
new Float:oldposx, Float:oldposy, Float:oldposz;
new Float:tempposx, Float:tempposy, Float:tempposz;
forward p_OnGameModeInit();
forward ObjectStream();

stock p_OnGameModeInit()
	ObjectTimer = SetTimer("ObjectStream",500,1);

stock p_OnGameModeExit()
	KillTimer(ObjectTimer);

stock CreateDynamicObject(modelid, Float:X1, Float:Y1, Float:Z1, Float:rX1, Float:rY1, Float:rZ1)
{
	if(ObjectTotal >= MAX_STREAM_OBJECTS) return -1;
	ObjectTotal += 1;
	Object[ObjectTotal][X] = X1;
	Object[ObjectTotal][Y] = Y1;
	Object[ObjectTotal][Z] = Z1;
	Object[ObjectTotal][rX] = rX1;
	Object[ObjectTotal][rY] = rY1;
	Object[ObjectTotal][rZ] = rZ1;
	Object[ObjectTotal][Model] = modelid;
	Object[ObjectTotal][PlayerAttach] = -1;
	Object[ObjectTotal][Used] = 1;
	return ObjectTotal;
}

stock DestroyDynamicObject(dObjectID)
{
	Object[dObjectID][X] = 0;
	Object[dObjectID][Y] = 0;
	Object[dObjectID][Z] = 0;
	Object[dObjectID][rX] = 0;
	Object[dObjectID][rY] = 0;
	Object[dObjectID][rZ] = 0;
	Object[dObjectID][Model] = 0;
	Object[dObjectID][Used] = 0;
	Object[ObjectTotal][PlayerAttach] = -1;
	return 1;
}

stock IsValidDynamicObject(dObjectID)
	return Object[dObjectID][Used];

stock GetDynamicObjectPos(dObjectID, Float:X2, Float:Y2, Float:Z2)
{
	X2 = Object[dObjectID][X];
	Y2 = Object[dObjectID][Y];
	Z2 = Object[dObjectID][Z];
	return 1;
}

stock SetDynamicObjectPos(dObjectID, Float:X2, Float:Y2, Float:Z2)
{
	Object[dObjectID][X] = X2;
	Object[dObjectID][Y] = Y2;
	Object[dObjectID][Z] = Z2;
	for(new i=0; i<MAX_PLAYERS; i++) if(IsPlayerConnected(i))
	{
	    if(Player[i][dObjectID] != -1)
	    {
	        DestroyPlayerObject(i, Player[i][dObjectID]);
			Player[i][dObjectID] = CreatePlayerObject(i, Object[dObjectID][Model],Object[dObjectID][X], Object[dObjectID][Y], Object[dObjectID][Z], Object[dObjectID][rX], Object[dObjectID][rY], Object[dObjectID][rZ]);
	    }
	}
	return 1;
}

stock AttachDynamicObjectToPlayer(dObjectID, playerid, Float:OffsetX, Float:OffsetY, Float:OffsetZ)
{
	Object[dObjectID][PlayerAttach] = playerid;
	for(new i=0; i<MAX_PLAYERS; i++) if(IsPlayerConnected(i))
	{
	    if(Player[i][dObjectID] != -1)
		{
			Object[dObjectID][AttachX] = OffsetX;
			Object[dObjectID][AttachY] = OffsetY;
			Object[dObjectID][AttachZ] = OffsetZ;
	    	AttachPlayerObjectToPlayer(playerid,Player[i][dObjectID],playerid,OffsetX,OffsetY,OffsetZ,0,0,0);
		}
	}
	return 1;
}

stock DetachDynamicObjectFromPlayer(dObjectID, playerid)
{
	Object[dObjectID][PlayerAttach] = -1;
	for(new i=0; i<MAX_PLAYERS; i++) if(IsPlayerConnected(i))
	{
	    if(Player[i][dObjectID] != -1)
		{
		    DestroyPlayerObject(i,Player[i][dObjectID]);
		    Player[i][dObjectID] = -1;
		}
	}
	return 1;
}

stock MoveDynamicObject(dObjectID, Float:X2, Float:Y2, Float:Z2, Float:Speed)
{
	Object[dObjectID][X] = X2;
	Object[dObjectID][Y] = Y2;
	Object[dObjectID][Z] = Z2;
	for(new i=0; i<MAX_PLAYERS; i++) if(IsPlayerConnected(i))
	{
	    if(Player[i][dObjectID] != -1)
	        MovePlayerObject(i, Player[i][dObjectID], X2, Y2, Z2, Speed);
	}
}

stock StopDynamicObject(dObjectID)
{
	for(new i=0; i<MAX_PLAYERS; i++) if(IsPlayerConnected(i))
	{
	    if(Player[i][dObjectID] != -1)
	        StopPlayerObject(i, Player[i][dObjectID]);
	}
}

public ObjectStream()
{
	new x;
	for(new i=0; i<MAX_PLAYERS; i++) if(IsPlayerConnected(i))
	{
		for(x=0; x<ObjectTotal; x++)
		{
		    if(PlayerToPoint(Radius, i, Object[x][X], Object[x][Y], Object[x][Z]))
		    {
				if(Player[i][x] == -1 && Object[x][Used] == 1 && Object[x][PlayerAttach] == -1)
					Player[i][x] = CreatePlayerObject(i, Object[x][Model],Object[x][X], Object[x][Y], Object[x][Z], Object[x][rX], Object[x][rY], Object[x][rZ]);
				else if(Player[i][x] == -1 && Object[x][Used] == 1 && Object[x][PlayerAttach] != -1)
				{
					Player[i][x] = CreatePlayerObject(i, Object[x][Model],Object[x][X], Object[x][Y], Object[x][Z], Object[x][rX], Object[x][rY], Object[x][rZ]);
					AttachPlayerObjectToPlayer(i,Player[i][x],Object[x][PlayerAttach],Object[x][AttachX],Object[x][AttachY],Object[x][AttachZ],0,0,0);
				}
		    }
 		    if(!PlayerToPoint(Radius, i, Object[x][X], Object[x][Y], Object[x][Z]))
		    {
				if(Player[i][x] != -1 && Object[x][Used] == 1)
				{
					DestroyPlayerObject(i, Player[i][x]);
					Player[i][x] = -1;
				}
		    }
		}
	}
}

stock PlayerToPoint(Float:radi, playerid, Float:x, Float:y, Float:z)
{
	GetPlayerPos(playerid, oldposx, oldposy, oldposz);
	tempposx = (oldposx -x);
	tempposy = (oldposy -y);
	tempposz = (oldposz -z);
	if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
		return 1;
	return 0;
}