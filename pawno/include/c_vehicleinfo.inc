/*

 [ criticaL's Vehicle Info ]

 - Version       : 0.1
 - Author        : criticaL aka Robban
 - Date          : 30 April 2007

 - Function list :

   cAddStaticVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2)
   cAddStaticVehicleEx(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2, respawn_delay)
   cGetVehicleModelID(vehicleid, &modelid)
   cGetVehicleSpawnPos(vehicleid, &Float:spawn_x, &Float:spawn_y, &Float:spawn_z, &Float:z_angle)

 - Description   :

   With those simple functions you can get modelid out of a vehicleid which is not "possible" in the
   current version of SA-MP, and you can get spawn position of the vehicle aswell.

   It is very simple to use, just put a "c" infront of the regular AddStaticVehicle and
   AddStaticVehicleEx.

   NOTE: You will only be able to get information out of a vehicleid if you have used
         my functions, not the regular AddStaticVehicle and AddStaticVehicleEx!

         And if you use the regular functions, you will fuck the vehicleid order up, so
         only use cAddStaticVehicle and cAddStaticvehicleEx.

         ---------------------

         Report any bugs to me, I didn't have much time to test it. ;)

 - Remember      : You haven't made this shit, so don't take any credits for it!

*/

#if defined _criticalvehicle_included
	#endinput
#endif

#define _criticalvehicle_included
#include <a_samp>

/*
native cAddStaticVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2);
native cAddStaticVehicleEx(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2, respawn_delay);
native cGetVehicleModelID(vehicleid, &modelid);
native cGetVehicleSpawnPos(vehicleid, &Float:spawn_x, &Float:spawn_y, &Float:spawn_z, &Float:z_angle);
*/

enum cVehicle_info
{
	cVi_modelid,
	Float:cVi_spawn_x,
	Float:cVi_spawn_y,
	Float:cVi_spawn_z,
	Float:cVi_z_angle,
}

static cVehicles[MAX_VEHICLES][cVehicle_info];
static cVehicle_count;

stock cAddStaticVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2)
{
	cVehicle_count ++;
	
	cVehicles[cVehicle_count][cVi_modelid] = modelid;
	cVehicles[cVehicle_count][cVi_spawn_x] = spawn_x;
	cVehicles[cVehicle_count][cVi_spawn_y] = spawn_y;
	cVehicles[cVehicle_count][cVi_spawn_z] = spawn_z;
	cVehicles[cVehicle_count][cVi_z_angle] = z_angle;
	
	AddStaticVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2);
}

stock cAddStaticVehicleEx(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2, respawn_delay)
{
	cVehicle_count ++;
	
	cVehicles[cVehicle_count][cVi_modelid] = modelid;
	cVehicles[cVehicle_count][cVi_spawn_x] = spawn_x;
	cVehicles[cVehicle_count][cVi_spawn_y] = spawn_y;
	cVehicles[cVehicle_count][cVi_spawn_z] = spawn_z;
	cVehicles[cVehicle_count][cVi_z_angle] = z_angle;
	
	AddStaticVehicleEx(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2, respawn_delay);
}

stock cGetVehicleModelID(vehicleid, &modelid)
{
	if (vehicleid < 1 || vehicleid > MAX_VEHICLES || vehicleid > cVehicle_count) return 0;

	modelid = cVehicles[vehicleid][cVi_modelid];

	return 1;
}

stock cGetVehicleSpawnPos(vehicleid, &Float:spawn_x, &Float:spawn_y, &Float:spawn_z, &Float:z_angle)
{
	if (vehicleid < 1 || vehicleid > MAX_VEHICLES || vehicleid > cVehicle_count) return 0;

	spawn_x = cVehicles[vehicleid][cVi_spawn_x];
	spawn_y = cVehicles[vehicleid][cVi_spawn_y];
	spawn_z = cVehicles[vehicleid][cVi_spawn_z];
	z_angle = cVehicles[vehicleid][cVi_z_angle];

	return 1;
}