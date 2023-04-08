stock VIH_AddStaticVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2)
{
        new vehicleid = AddStaticVehicle(modelid, spawn_x, spawn_y, spawn_z, z_angle, color1, color2);
        Iter_Add(Vehicle, vehicleid);
        return vehicleid;
}
#if defined _ALS_AddStaticVehicle
        #undef AddStaticVehicle
#else
        #define _ALS_AddStaticVehicle
#endif
#define AddStaticVehicle VIH_AddStaticVehicle

stock VIH_AddStaticVehicleEx(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2, respawn_delay, addsiren = 0)
{
        new vehicleid = AddStaticVehicleEx(modelid, spawn_x, spawn_y, spawn_z, z_angle, color1, color2, respawn_delay, addsiren);
        Iter_Add(Vehicle, vehicleid);
        return vehicleid;
}
#if defined _ALS_AddStaticVehicleEx
        #undef AddStaticVehicleEx
#else
        #define _ALS_AddStaticVehicleEx
#endif
#define AddStaticVehicleEx VIH_AddStaticVehicleEx

stock VIH_CreateVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2, respawn_delay, siren = 0)
{
        new vehicleid = CreateVehicle(modelid, spawn_x, spawn_y, spawn_z, z_angle, color1, color2, respawn_delay, siren);
        Iter_Add(Vehicle, vehicleid);
        return vehicleid;
}
#if defined _ALS_CreateVehicle
        #undef CreateVehicle
#else
        #define _ALS_CreateVehicle
#endif
#define CreateVehicle VIH_CreateVehicle

stock VIH_DestroyVehicle(vehicleid)
{
        Iter_Remove(Vehicle, vehicleid);
        return DestroyVehicle(vehicleid);
}
#if defined _ALS_DestroyVehicle
        #undef DestroyVehicle
#else
        #define _ALS_DestroyVehicle
#endif
#define DestroyVehicle VIH_DestroyVehicle


stock PlayAudioStream_Ex(playerid, url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, usepos = 0)
{
	if(IsValidYoutubeUrl(url))
	{
	    PlayYoutubeStreamForPlayer(playerid, url, posX, posY, posZ, distance, usepos);
	}
	else
	{
		PlayAudioStreamForPlayer(playerid, url, posX, posY, posZ, distance, usepos);
	}
}
#if defined _ALS_PlayAudioStreamForPlayer
        #undef PlayAudioStreamForPlayer
#else
        #define _ALS_PlayAudioStreamForPlayer
#endif
#define PlayAudioStreamForPlayer PlayAudioStream_Ex