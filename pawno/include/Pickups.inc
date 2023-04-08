====================================
          Easy Pickups

By: Trey Fresh aka Fresh Killa
====================================

#include <a_samp>
#include <dini>
#include <dutils>
#include <dudb>
#pragma unused ret_memcpy


native HealthPickup(Float:X, Float:Y, Float:Z);
native ArmourPickup(Float:X, Float:Y, Float:Z);
native PillPickup(Float:X, Float:Y, Float:Z);

stock HealthPickup(Float:X, Float:Y, Float:Z)
{

    CreatePickup(1240,2,Float:X, Float:Y, Float:Z));

}

stock ArmourPickup(Float:X, Float:Y, Float:Z)
{

    CreatePickup(1242,2,Float:X, Float:Y, Float:Z));

}

stock PillPickup(Float:X, Float:Y, Float:Z)
{

    CreatePickup(1241,2,Float:X, Float:Y, Float:Z));

}