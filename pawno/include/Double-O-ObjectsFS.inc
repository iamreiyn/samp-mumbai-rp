#include <a_samp>

#if defined _DOO_included
	#endinput
#endif
#define _DOO_included

#define MAX_STREAM_OBJECTS 7500
#define ALL_WORLDS -1

forward OnStreamObjectMoved(objectid);

forward FS_StreamObjects(playerid);
public FS_StreamObjects(playerid)
	return CallRemoteFunction("StreamObjects","i",playerid);
#define StreamObjects FS_StreamObjects

forward FS_StreamObjectsEx(playerid,Float:x,Float:y,Float:z);
public FS_StreamObjectsEx(playerid,Float:x,Float:y,Float:z)
	return CallRemoteFunction("StreamObjectsEx","ifff",playerid,x,y,z);
#define StreamObjectsEx FS_StreamObjectsEx

forward FS_CreateStreamObject(modelid, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ,Float:distance,worldid);
public FS_CreateStreamObject(modelid, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ,Float:distance,worldid)
	return CallRemoteFunction("CreateStreamObject","ifffffffi",modelid,X,Y,Z,rX,rY,rZ,distance,worldid);
#define CreateStreamObject FS_CreateStreamObject

forward FS_DestroyStreamObject(objectid);
public FS_DestroyStreamObject(objectid)
	return CallRemoteFunction("DestroyStreamObject","i",objectid);
#define DestroyStreamObject FS_DestroyStreamObject

forward FS_SetObjectViewDistance(objectid,Float:distance);
public FS_SetObjectViewDistance(objectid,Float:distance)
	return CallRemoteFunction("SetObjectViewDistance","if",objectid,distance);
#define SetObjectViewDistance FS_SetObjectViewDistance

forward FS_IsValidStreamObject(objectid);
public FS_IsValidStreamObject(objectid)
	return CallRemoteFunction("IsValidStreamObject","i",objectid);
#define IsValidStreamObject FS_IsValidStreamObject

forward FS_MoveStreamObject(objectid,Float:x,Float:y,Float:z,Float:speed);
public FS_MoveStreamObject(objectid,Float:x,Float:y,Float:z,Float:speed)
	return CallRemoteFunction("MoveStreamObject","iffff",objectid,x,y,z,speed);
#define MoveStreamObject FS_MoveStreamObject

forward FS_StopStreamObject(objectid);
public FS_StopStreamObject(objectid)
	return CallRemoteFunction("StopStreamObject","i",objectid);
#define StopStreamObject FS_StopStreamObject

forward FS_SetStreamObjectPos(objectid, Float:x, Float:y, Float:z);
public FS_SetStreamObjectPos(objectid, Float:x, Float:y, Float:z)
	return CallRemoteFunction("SetStreamObjectPos","ifff",objectid,x,y,z);
#define SetStreamObjectPos FS_SetStreamObjectPos

forward FS_GetStreamObjectPos(objectid, &Float:x, &Float:y, &Float:z);
public FS_GetStreamObjectPos(objectid, &Float:x, &Float:y, &Float:z)
{
	x=Float:CallRemoteFunction("GetStreamObjectXPos","i",objectid);
	y=Float:CallRemoteFunction("GetStreamObjectYPos","i",objectid);
	z=Float:CallRemoteFunction("GetStreamObjectZPos","i",objectid);
	return 1;
}
#define GetStreamObjectPos FS_GetStreamObjectPos

forward FS_SetStreamObjectRot(objectid, Float:rX, Float:rY, Float:rZ);
public FS_SetStreamObjectRot(objectid, Float:rX, Float:rY, Float:rZ)
	return CallRemoteFunction("SetStreamObjectRot","ifff",objectid,rX,rY,rZ);
#define SetStreamObjectRot FS_SetStreamObjectRot

forward FS_GetStreamObjectRot(objectid, &Float:rX, &Float:rY, &Float:rZ);
public FS_GetStreamObjectRot(objectid, &Float:rX, &Float:rY, &Float:rZ)
{
	rX=Float:CallRemoteFunction("GetStreamObjectrXRot","i",objectid);
	rY=Float:CallRemoteFunction("GetStreamObjectrYRot","i",objectid);
	rZ=Float:CallRemoteFunction("GetStreamObjectrZRot","i",objectid);
	return 1;
}
#define GetStreamObjectRot FS_GetStreamObjectRot

forward FS_DOO_SetVehiclePos(vehicleid,Float:x,Float:y,Float:z);
public FS_DOO_SetVehiclePos(vehicleid,Float:x,Float:y,Float:z)
	return CallRemoteFunction("DOO_SetVehiclePos","ifff",vehicleid,x,y,z);
#define DOO_SetVehiclePos FS_DOO_SetVehiclePos
