#include <a_samp>

#if defined _YSI2_included
	#endinput
#endif
#define _YSI2_included

// Check if they've included the PAWN version
#if defined _YSI_included
	// Check if they're using the PAWN object streamer
	#if defined _YSI_VISUAL_OBJECTS
		#error "Please use either the YSI plugin or the YSI pawn object streamer, not both"
		#endinput
	#endif
#endif

/*
	native
native OBJECT_FUNCTIONS();
	native
*/
native CreateDynamicObject(modelid, Float:X, Float:Y, Float:Z, Float:rX = 0.0, Float:rY = 0.0, Float:rZ = 0.0);
native CreatePlayerDynamicObject(playerid, modelid, Float:X, Float:Y, Float:Z, Float:rX = 0.0, Float:rY = 0.0, Float:rZ = 0.0);
native SetDynamicObjectPos(objectid, Float:X, Float:Y, Float:Z);
native GetDynamicObjectPos(objectid, &Float:X, &Float:Y, &Float:Z);
native SetDynamicObjectRot(objectid, Float:RotX, Float:RotY, Float:RotZ);
native GetDynamicObjectRot(objectid, &Float:RotX, &Float:RotY, &Float:RotZ);
native IsValidDynamicObject(objectid);
native DestroyDynamicObject(objectid);
native MoveDynamicObject(objectid, Float:X, Float:Y, Float:Z, Float:Speed);
native StopDynamicObject(objectid);

/*
	native
native AREA_FUNCTIONS();
	native
*/
native Area_AddCube(Float:minx, Float:miny, Float:minz, Float:maxx, Float:maxy, Float:maxz);
native Area_AddBox(Float:minx, Float:miny, Float:maxx, Float:maxy);

/*
	native
native GENERIC_FUNCTIONS();
	native
*/
native SetModeRestartTime(Float:seconds = 12.0);

/*
Forwards
*/

forward OnPlayerEnterArea(playerid, areaid);
forward OnPlayerLeaveArea(playerid, areaid);