/*------------------------------------------------------------------------------
                               Interiores by Caco

   Para crear tu interior pon esto en OnFilterScriptInit() o en OnGameModeInit()

CreateInterior(Float:Pickupx, Float:Pickupy, Float:Pickupz, Float:Telex, Float:Teley, Float:Telez, interior);


------------------------------------------------------------------------------*/

#include <a_samp>

#define MAX_INTERIORS   2000
#define INTERIOR_PICKUP 1318   // 1239 pickup info | 1318 arrow | 1559 diamond

#define COLOR_INTERIOR  0xdad83bff

//------------------------------------------------------------------------------

enum IntInfo
{
    Float:PickupX, 
    Float:PickupY, 
    Float:PickupZ, 
    Float:TeleX, 
    Float:TeleY, 
    Float:TeleZ, 
    Interior, 
}

new InteriorInfo[MAX_INTERIORS][IntInfo];

new IntCount = -1;
new PickupID[MAX_INTERIORS];
new InInterior[MAX_PLAYERS] = -1;

//------------------------------------------------------------------------------

public OnPlayerPickUpPickup(playerid, pickupid)
{
  for(new i; i<MAX_INTERIORS; i++)
  {
    if(pickupid == PickupID[i])
    {
    SetPlayerPos(playerid, InteriorInfo[i][TeleX], InteriorInfo[i][TeleY], InteriorInfo[i][TeleZ]);
    SetPlayerInterior(playerid, InteriorInfo[i][Interior]);
    InInterior[playerid] = i;
    SetPlayerVirtualWorld(playerid, 0);
    return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------

stock CreateInterior(Float:Pickupx, Float:Pickupy, Float:Pickupz, Float:Telex, Float:Teley, Float:Telez, interior)
{
  IntCount ++;
  new ID = IntCount;
  InteriorInfo[ID][PickupX] = Pickupx;
  InteriorInfo[ID][PickupY] = Pickupy;
  InteriorInfo[ID][PickupZ] = Pickupz;
  InteriorInfo[ID][TeleX] = Telex;
  InteriorInfo[ID][TeleY] = Teley;
  InteriorInfo[ID][TeleZ] = Telez;
  InteriorInfo[ID][Interior] = interior;
  PickupID[ID] = CreatePickup(INTERIOR_PICKUP, 1318, Pickupx, Pickupy, Pickupz + 0.75, -1);
  //Create3DTextLabel("Interior", COLOR_INTERIOR, Pickupx, Pickupy, Pickupz + 0.75, 15.0, 0, 1);
}

//------------------------------------------------------------------------------
