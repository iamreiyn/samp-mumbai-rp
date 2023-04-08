#include <a_samp>

#if defined _DOO_included
	#endinput
#endif
#define _DOO_included

#define MAX_STREAM_OBJECTS 8000
#define ALL_WORLDS -1
#define MAX_STREAM_COUNT 22
#define STREAM_UPDATE_DISTANCE (15.0)

enum oInfo
{
	oCreated,
	oModel,
	Float:oPos[3],
	Float:oRotation[3],
	Float:oDistance,
	oWorld,
	oMoving,
	Float:oMoveDistance,
	Float:oOldPos[3],
	Float:oStartMoveTickCount,
	Float:oMoveSpeed,
	oMoveTimer
};

enum pObjectInfo
{
	pObjectID[MAX_STREAM_OBJECTS],
	pObjectCount,
	pStreamedObjects,
	pObjectsStreamed,
	Float:pLastStreamPos[3]
};

new ObjectInfo[MAX_STREAM_OBJECTS][oInfo];
new PlayerObjectInfo[MAX_PLAYERS][pObjectInfo];

forward CreateStreamObject(modelid, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ, Float:distance,worldid);
forward DestroyStreamObject(objectid);
forward StreamObjects(playerid);
forward StreamObjectsEx(playerid,Float:x,Float:y,Float:z);
forward MoveStreamObject(objectid,Float:x,Float:y,Float:z,Float:speed);
forward StopStreamObject(objectid);
forward DOO_SetPlayerPos(playerid,Float:x,Float:y,Float:z);
forward DOO_SetVehiclePos(vehicleid,Float:x,Float:y,Float:z);
forward SetStreamObjectRot(objectid, Float:rX, Float:rY, Float:rZ);
forward SetStreamObjectPos(objectid, Float:x, Float:y, Float:z);
forward SetObjectViewDistance(objectid,Float:distance);
forward OnStreamObjectMoved(objectid);
forward StreamObjectMoved(objectid);
forward GetStreamObjectPos(objectid, &Float:x, &Float:y, &Float:z);
forward GetStreamObjectRot(objectid, &Float:rX, &Float:rY, &Float:rZ);
forward Float:GetStreamObjectXPos(objectid);
forward Float:GetStreamObjectYPos(objectid);
forward Float:GetStreamObjectZPos(objectid);
forward Float:GetStreamObjectXRot(objectid);
forward Float:GetStreamObjectYRot(objectid);
forward Float:GetStreamObjectZRot(objectid);

DOO_OnPlayerConnect(playerid)
{
	PlayerObjectInfo[playerid][pObjectCount]=0;
	PlayerObjectInfo[playerid][pStreamedObjects]=0;
	PlayerObjectInfo[playerid][pObjectsStreamed]=false;
    for(new i=0;i<MAX_STREAM_OBJECTS;i++)
	    PlayerObjectInfo[playerid][pObjectID][i]=INVALID_OBJECT_ID;
}

DOO_OnPlayerDisconnect(playerid)
{
	for(new i=0;i<MAX_STREAM_OBJECTS;i++)
	    PlayerObjectInfo[playerid][pObjectID][i]=INVALID_OBJECT_ID;

	for(new i=0;i<MAX_OBJECTS;i++)
	    if(IsValidPlayerObject(playerid,i))
	        DestroyPlayerObject(playerid,i);
}

DOO_OnPlayerUpdate(playerid)
{
	PlayerObjectInfo[playerid][pStreamedObjects]++;
	if(PlayerObjectInfo[playerid][pStreamedObjects]>=MAX_STREAM_COUNT)
	{
		PlayerObjectInfo[playerid][pStreamedObjects]=0;
		if(PlayerObjectInfo[playerid][pObjectsStreamed])//Prevent lag
		    PlayerObjectInfo[playerid][pObjectsStreamed]=false;
		else if(!IsPlayerInRangeOfPoint(playerid,STREAM_UPDATE_DISTANCE,PlayerObjectInfo[playerid][pLastStreamPos][0],PlayerObjectInfo[playerid][pLastStreamPos][1],PlayerObjectInfo[playerid][pLastStreamPos][2]))
  			StreamObjects(playerid);
	}
}

stock IsPosInDistance(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2, Float:radius)// PlayerToPoint edit
{
    new Float:tmpx,Float:tmpy, Float:tmpz;
    tmpx = (x1-x2);
    tmpy = (y1-y2);
    tmpz = (z1-z2);
    if (((tmpx < radius) && (tmpx > -radius)) && ((tmpy < radius) && (tmpy > -radius)) && ((tmpz < radius) && (tmpz > -radius)))
	    return true;
    return false;
}

public StreamObjects(playerid)
{
	if(IsPlayerConnected(playerid))
	{
		new worldid=GetPlayerVirtualWorld(playerid),Float:currentx,Float:currenty,Float:currentz;
		GetPlayerPos(playerid,PlayerObjectInfo[playerid][pLastStreamPos][0],PlayerObjectInfo[playerid][pLastStreamPos][1],PlayerObjectInfo[playerid][pLastStreamPos][2]);
		for(new i=0;i<MAX_STREAM_OBJECTS;i++)
		{
		    if(ObjectInfo[i][oCreated])
		    {
		        GetStreamObjectPos(i,currentx,currenty,currentz);
			    if(IsPlayerInRangeOfPoint(playerid,ObjectInfo[i][oDistance],currentx,currenty,currentz) && (ObjectInfo[i][oWorld]==ALL_WORLDS || ObjectInfo[i][oWorld]==worldid))
			    {
					if(PlayerObjectInfo[playerid][pObjectID][i]==INVALID_OBJECT_ID && PlayerObjectInfo[playerid][pObjectCount]<MAX_OBJECTS)
					{
					    PlayerObjectInfo[playerid][pObjectID][i]=CreatePlayerObject(playerid,ObjectInfo[i][oModel],currentx,currenty,currentz,ObjectInfo[i][oRotation][0],ObjectInfo[i][oRotation][1],ObjectInfo[i][oRotation][2]);
					    PlayerObjectInfo[playerid][pObjectCount]++;

					    if(ObjectInfo[i][oMoving])
					        MovePlayerObject(playerid,PlayerObjectInfo[playerid][pObjectID][i],ObjectInfo[i][oPos][0],ObjectInfo[i][oPos][1],ObjectInfo[i][oPos][2],ObjectInfo[i][oMoveSpeed]);
					}
			    }
			    else
			    {
			        if(PlayerObjectInfo[playerid][pObjectID][i]!=INVALID_OBJECT_ID)
			        {
			            DestroyPlayerObject(playerid,PlayerObjectInfo[playerid][pObjectID][i]);
			            PlayerObjectInfo[playerid][pObjectID][i]=INVALID_OBJECT_ID;
			            PlayerObjectInfo[playerid][pObjectCount]--;
			        }
			    }
		    }
		}
		return 1;
	}
	return 0;
}

public StreamObjectsEx(playerid,Float:x,Float:y,Float:z)
{
	if(IsPlayerConnected(playerid))
	{
		new worldid=GetPlayerVirtualWorld(playerid),Float:currentx,Float:currenty,Float:currentz;
		PlayerObjectInfo[playerid][pLastStreamPos][0]=x;
		PlayerObjectInfo[playerid][pLastStreamPos][1]=y;
		PlayerObjectInfo[playerid][pLastStreamPos][2]=z;
		for(new i=0;i<MAX_STREAM_OBJECTS;i++)
		{
		    if(ObjectInfo[i][oCreated])
		    {
		        GetStreamObjectPos(i,currentx,currenty,currentz);
			    if(IsPosInDistance(x,y,z,currentx,currenty,currentz,ObjectInfo[i][oDistance]) && (ObjectInfo[i][oWorld]==ALL_WORLDS || ObjectInfo[i][oWorld]==worldid))
				{
					if(PlayerObjectInfo[playerid][pObjectID][i]==INVALID_OBJECT_ID && PlayerObjectInfo[playerid][pObjectCount]<MAX_OBJECTS)
					{
					    PlayerObjectInfo[playerid][pObjectID][i]=CreatePlayerObject(playerid,ObjectInfo[i][oModel],currentx,currenty,currentz,ObjectInfo[i][oRotation][0],ObjectInfo[i][oRotation][1],ObjectInfo[i][oRotation][2]);
					    PlayerObjectInfo[playerid][pObjectCount]++;

					    if(ObjectInfo[i][oMoving])
					        MovePlayerObject(playerid,PlayerObjectInfo[playerid][pObjectID][i],ObjectInfo[i][oPos][0],ObjectInfo[i][oPos][1],ObjectInfo[i][oPos][2],ObjectInfo[i][oMoveSpeed]);
					}
			    }
			    else
			    {
			        if(PlayerObjectInfo[playerid][pObjectID][i]!=INVALID_OBJECT_ID)
			        {
			            DestroyPlayerObject(playerid,PlayerObjectInfo[playerid][pObjectID][i]);
			            PlayerObjectInfo[playerid][pObjectID][i]=INVALID_OBJECT_ID;
			            PlayerObjectInfo[playerid][pObjectCount]--;
			        }
			    }
		    }
		}
		return 1;
	}
	return 0;
}

public CreateStreamObject(modelid, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ, Float:distance,worldid)
{
	for(new i=0;i<MAX_STREAM_OBJECTS;i++)
	{
	    if(!ObjectInfo[i][oCreated])
	    {
	        ObjectInfo[i][oModel]=modelid;
	        ObjectInfo[i][oPos][0]=X;
	        ObjectInfo[i][oPos][1]=Y;
	        ObjectInfo[i][oPos][2]=Z;
	        ObjectInfo[i][oRotation][0]=rX;
	        ObjectInfo[i][oRotation][1]=rY;
	        ObjectInfo[i][oRotation][2]=rZ;
			ObjectInfo[i][oDistance]=distance;
			ObjectInfo[i][oWorld]=worldid;
			ObjectInfo[i][oCreated]=true;
			ObjectInfo[i][oMoving]=false;
	        return i;
	    }
	}
	return INVALID_OBJECT_ID;
}

public DestroyStreamObject(objectid)
{
	if(IsValidStreamObject(objectid))
    {
        for(new i=0;i<MAX_PLAYERS;i++)
		{
		    if(IsPlayerConnected(i) && PlayerObjectInfo[i][pObjectID][objectid]!=INVALID_OBJECT_ID)
		    {
		        DestroyPlayerObject(i,PlayerObjectInfo[i][pObjectID][objectid]);
		        PlayerObjectInfo[i][pObjectID][objectid]=INVALID_OBJECT_ID;
		        PlayerObjectInfo[i][pObjectCount]--;
		    }
		}
		
		if(ObjectInfo[objectid][oMoving])
		    KillTimer(ObjectInfo[objectid][oMoveTimer]);
		ObjectInfo[objectid][oCreated]=false;
		return 1;
    }
	return 0;
}

public SetObjectViewDistance(objectid,Float:distance)
{
	if(IsValidStreamObject(objectid))
	{
	    ObjectInfo[objectid][oDistance]=distance;
	    return 1;
	}
	return 0;
}

stock IsValidStreamObject(objectid)
{
	if(objectid>=0 && objectid<MAX_STREAM_OBJECTS)
	    if(ObjectInfo[objectid][oCreated])
	        return true;
	return false;
}

public MoveStreamObject(objectid,Float:x,Float:y,Float:z,Float:speed)
{
    if(IsValidStreamObject(objectid) && speed>0.0)
    {
        new Float:oldx,Float:oldy,Float:oldz;
		GetStreamObjectPos(objectid,oldx,oldy,oldz);
		
		ObjectInfo[objectid][oOldPos][0]=oldx;
		ObjectInfo[objectid][oOldPos][1]=oldy;
		ObjectInfo[objectid][oOldPos][2]=oldz;
		
		oldx-=x;
		oldy-=y;
		oldz-=z;
		ObjectInfo[objectid][oMoveDistance]=floatsqroot((oldx*oldx)+(oldy*oldy)+(oldz*oldz));
		
		if(ObjectInfo[objectid][oMoveDistance]==0.0)
		    return 0;
		    
		if(ObjectInfo[objectid][oMoving])
		    KillTimer(ObjectInfo[objectid][oMoveTimer]);
		
		for(new i=0;i<MAX_PLAYERS;i++)
		    if(IsPlayerConnected(i) && PlayerObjectInfo[i][pObjectID][objectid]!=INVALID_OBJECT_ID)
		        MovePlayerObject(i,PlayerObjectInfo[i][pObjectID][objectid],x,y,z,speed);
		        
        new time=floatround((ObjectInfo[objectid][oMoveDistance]*1000)/speed);
        ObjectInfo[objectid][oMoveSpeed]=speed;
        ObjectInfo[objectid][oMoving]=true;
        ObjectInfo[objectid][oMoveTimer]=SetTimerEx("StreamObjectMoved",time,false,"i",objectid);
        ObjectInfo[objectid][oStartMoveTickCount]=GetTickCount();
		ObjectInfo[objectid][oPos][0]=x;
		ObjectInfo[objectid][oPos][1]=y;
		ObjectInfo[objectid][oPos][2]=z;
		return time;
    }
	return 0;
}

public StopStreamObject(objectid)
{
	if(IsValidStreamObject(objectid))
    {
        if(ObjectInfo[objectid][oMoving])
        {
	        for(new i=0;i<MAX_PLAYERS;i++)
			    if(IsPlayerConnected(i) && PlayerObjectInfo[i][pObjectID][objectid]!=INVALID_OBJECT_ID)
			        StopPlayerObject(i,PlayerObjectInfo[i][pObjectID][objectid]);
			        
			GetStreamObjectPos(objectid,ObjectInfo[objectid][oPos][0],ObjectInfo[objectid][oPos][1],ObjectInfo[objectid][oPos][2]);
			ObjectInfo[objectid][oMoving]=false;
			KillTimer(ObjectInfo[objectid][oMoveTimer]);
			StreamObjectMoved(objectid);
			return 1;
		}
    }
	return 0;
}

public StreamObjectMoved(objectid)
{
    if(IsValidStreamObject(objectid))
    {
        if(ObjectInfo[objectid][oMoving])
        {
            ObjectInfo[objectid][oMoving]=false;
            CallRemoteFunction("OnStreamObjectMoved","i",objectid);
            return 1;
        }
	}
	return 0;
}

public SetStreamObjectPos(objectid, Float:x, Float:y, Float:z)
{
    if(IsValidStreamObject(objectid))
    {
        if(!ObjectInfo[objectid][oMoving])
        {
	        for(new i=0;i<MAX_PLAYERS;i++)
			    if(IsPlayerConnected(i) && PlayerObjectInfo[i][pObjectID][objectid]!=INVALID_OBJECT_ID)
			        SetPlayerObjectPos(i, PlayerObjectInfo[i][pObjectID][objectid], x, y, z);
			        
	        ObjectInfo[objectid][oPos][0]=x;
			ObjectInfo[objectid][oPos][1]=y;
			ObjectInfo[objectid][oPos][2]=z;
			return 1;
		}
    }
    return 0;
}

public GetStreamObjectPos(objectid, &Float:x, &Float:y, &Float:z)
{
    if(IsValidStreamObject(objectid))
    {
        if(ObjectInfo[objectid][oMoving])
        {
            new Float:q=(ObjectInfo[objectid][oMoveSpeed]*(GetTickCount()-ObjectInfo[objectid][oStartMoveTickCount]))/1000.0;
            q=q/ObjectInfo[objectid][oMoveDistance];
			x=ObjectInfo[objectid][oOldPos][0]+((ObjectInfo[objectid][oPos][0]-ObjectInfo[objectid][oOldPos][0])*q);
			y=ObjectInfo[objectid][oOldPos][1]+((ObjectInfo[objectid][oPos][1]-ObjectInfo[objectid][oOldPos][1])*q);
			z=ObjectInfo[objectid][oOldPos][2]+((ObjectInfo[objectid][oPos][2]-ObjectInfo[objectid][oOldPos][2])*q);
        }
        else
        {
	        x=ObjectInfo[objectid][oPos][0];
			y=ObjectInfo[objectid][oPos][1];
			z=ObjectInfo[objectid][oPos][2];
		}
		return 1;
    }
	return 0;
}

public Float:GetStreamObjectXPos(objectid)
{
    if(IsValidStreamObject(objectid))
    {
        if(ObjectInfo[objectid][oMoving])
        {
            new Float:q=(ObjectInfo[objectid][oMoveSpeed]*(GetTickCount()-ObjectInfo[objectid][oStartMoveTickCount]))/1000.0;
            q=q/ObjectInfo[objectid][oMoveDistance];
			return ObjectInfo[objectid][oOldPos][0]+((ObjectInfo[objectid][oPos][0]-ObjectInfo[objectid][oOldPos][0])*q);
        }
        else
	        return ObjectInfo[objectid][oPos][0];
    }
	return 0.0;
}

public Float:GetStreamObjectYPos(objectid)
{
    if(IsValidStreamObject(objectid))
    {
        if(ObjectInfo[objectid][oMoving])
        {
            new Float:q=(ObjectInfo[objectid][oMoveSpeed]*(GetTickCount()-ObjectInfo[objectid][oStartMoveTickCount]))/1000.0;
            q=q/ObjectInfo[objectid][oMoveDistance];
			return ObjectInfo[objectid][oOldPos][1]+((ObjectInfo[objectid][oPos][1]-ObjectInfo[objectid][oOldPos][1])*q);
        }
        else
	        return ObjectInfo[objectid][oPos][1];
    }
	return 0.0;
}

public Float:GetStreamObjectZPos(objectid)
{
    if(IsValidStreamObject(objectid))
    {
        if(ObjectInfo[objectid][oMoving])
        {
            new Float:q=(ObjectInfo[objectid][oMoveSpeed]*(GetTickCount()-ObjectInfo[objectid][oStartMoveTickCount]))/1000.0;
            q=q/ObjectInfo[objectid][oMoveDistance];
			return ObjectInfo[objectid][oOldPos][2]+((ObjectInfo[objectid][oPos][2]-ObjectInfo[objectid][oOldPos][2])*q);
        }
        else
	        return ObjectInfo[objectid][oPos][2];
    }
	return 0.0;
}

public SetStreamObjectRot(objectid, Float:rX, Float:rY, Float:rZ)
{
	if(IsValidStreamObject(objectid))
    {
        for(new i=0;i<MAX_PLAYERS;i++)
		    if(IsPlayerConnected(i) && PlayerObjectInfo[i][pObjectID][objectid]!=INVALID_OBJECT_ID)
		        SetPlayerObjectRot(i, PlayerObjectInfo[i][pObjectID][objectid], rX, rY, rZ);
        ObjectInfo[objectid][oRotation][0]=rX;
		ObjectInfo[objectid][oRotation][1]=rY;
		ObjectInfo[objectid][oRotation][2]=rZ;
		return 1;
    }
	return 0;
}

public GetStreamObjectRot(objectid, &Float:rX, &Float:rY, &Float:rZ)
{
    if(IsValidStreamObject(objectid))
    {
        rX=ObjectInfo[objectid][oRotation][0];
		rY=ObjectInfo[objectid][oRotation][1];
		rZ=ObjectInfo[objectid][oRotation][2];
		return 1;
    }
	return 0;
}

public Float:GetStreamObjectXRot(objectid)
{
    if(IsValidStreamObject(objectid))
    	return ObjectInfo[objectid][oRotation][0];
	return 0.0;
}

public Float:GetStreamObjectYRot(objectid)
{
    if(IsValidStreamObject(objectid))
    	return ObjectInfo[objectid][oRotation][1];
	return 0.0;
}

public Float:GetStreamObjectZRot(objectid)
{
    if(IsValidStreamObject(objectid))
    	return ObjectInfo[objectid][oRotation][2];
	return 0.0;
}

public DOO_SetPlayerPos(playerid,Float:x,Float:y,Float:z)
{
	if(IsPlayerConnected(playerid))
	{
		StreamObjectsEx(playerid,x,y,z);
		PlayerObjectInfo[playerid][pObjectsStreamed]=true;
		return SetPlayerPos(playerid,x,y,z);
	}
	return 0;
}

public DOO_SetVehiclePos(vehicleid,Float:x,Float:y,Float:z)
{
	if(vehicleid!=INVALID_VEHICLE_ID)
	{
		for(new i=0;i<MAX_PLAYERS;i++)
		{
		    if(IsPlayerConnected(i) && GetPlayerVehicleID(i)==vehicleid)
		    {
		        StreamObjectsEx(i,x,y,z);
		        PlayerObjectInfo[i][pObjectsStreamed]=true;
			}
		}
		return SetVehiclePos(vehicleid,x,y,z);
	}
	return 0;
}
