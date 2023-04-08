#include <a_samp>

#define MAX_PICKUPS 10000

forward CreateStreamPickup(model,type,Float:x,Float:y,Float:z,range);
forward StreamPickups();
forward Pickup_AnyPlayerToPoint(Float:radi, Float:x, Float:y, Float:z);
forward DestroyStreamPickup(ID);
forward ChangeStreamPickupModel(ID,newmodel);
forward ChangeStreamPickupType(ID,newtype);
forward IsStreamPickup(ID);
forward Pickup_PlayerToPoint(playerid, Float:radi, Float:x, Float:y, Float:z);
forward ValidStreamPickupPickUp(playerid, pickupid);


enum pickupINFO
{
	pickupCreated,
	pickupVisible,
	pickupID,
	pickupRange,
	Float:pickupX,
	Float:pickupY,
	Float:pickupZ,
 	pickupType,
	pickupModel
}
new Pickup[MAX_PICKUPS+1][pickupINFO];

public CreateStreamPickup(model,type,Float:x,Float:y,Float:z,range)
{
	new FoundID = 0;
	new ID;

	for ( new i = 0; FoundID <= 0 ; i++)
	{
	    if( Pickup[i][pickupCreated] == 0 )
	    {
	        if( FoundID == 0 )
	        {
	     	   ID = i;
	     	   FoundID = 1;
	        }
	    }
	    if( i > MAX_PICKUPS )
	    {
		    FoundID = 2;
		}
	}
	if( FoundID == 2 )
	{
	    print("Pickup limit reached! Pickup not created!");
	    return -1;
	}
	Pickup[ID][pickupCreated] = 1;
	Pickup[ID][pickupVisible] = 0;
	Pickup[ID][pickupModel] = model;
	Pickup[ID][pickupType] = type;
	Pickup[ID][pickupX] = x;
	Pickup[ID][pickupY] = y;
	Pickup[ID][pickupZ] = z;
	Pickup[ID][pickupRange] = range;
	return ID;

}
public DestroyStreamPickup(ID)
{
	Pickup[ID][pickupCreated] = 0;
	DestroyPickup(Pickup[ID][pickupID]);
}
public StreamPickups()
{
	for(new i = 0; i < MAX_PICKUPS; i++)
	{
	    if( Pickup[i][pickupCreated] == 1 )
	    {
			if( Pickup_AnyPlayerToPoint(Pickup[i][pickupRange],Pickup[i][pickupX],Pickup[i][pickupY],Pickup[i][pickupZ]) )
			{
			    if( Pickup[i][pickupVisible] == 0 )
			    {
			        Pickup[i][pickupID] = CreatePickup(Pickup[i][pickupModel],Pickup[i][pickupType],Pickup[i][pickupX],Pickup[i][pickupY],Pickup[i][pickupZ]);
			        Pickup[i][pickupVisible] = 1;
				}
			}
			else
			{
			    if( Pickup[i][pickupVisible] == 1 )
			    {
			        DestroyPickup(Pickup[i][pickupID]);
					Pickup[i][pickupVisible] = 0;
			    }
			}
	    }
	}
}
public Pickup_AnyPlayerToPoint(Float:radi, Float:x, Float:y, Float:z)
{
	for ( new i = 0; i < MAX_PLAYERS; i++ )
	{
	    if(IsPlayerConnected(i))
		{
            if( Pickup_PlayerToPoint(i, Float:radi, Float:x, Float:y, Float:z) ) return 1;
		}
	}
    return 0;
}
public Pickup_PlayerToPoint(playerid, Float:radi, Float:x, Float:y, Float:z)
{
	new Float:oldposx, Float:oldposy, Float:oldposz;
	new Float:tempposx, Float:tempposy, Float:tempposz;
	GetPlayerPos(playerid, oldposx, oldposy, oldposz);
	tempposx = (oldposx -x);
	tempposy = (oldposy -y);
	tempposz = (oldposz -z);
	if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
	{
		return 1;
	}
	return 0;
}
public ChangeStreamPickupModel(ID,newmodel)
{
	DestroyPickup(Pickup[ID][pickupID]);
	Pickup[ID][pickupVisible] = 0;
	Pickup[ID][pickupModel] = newmodel;
}
public ChangeStreamPickupType(ID,newtype)
{
	DestroyPickup(Pickup[ID][pickupID]);
	Pickup[ID][pickupVisible] = 0;
	Pickup[ID][pickupType] = newtype;
}
public IsStreamPickup(ID)
{
	for( new i = 0; i < MAX_PICKUPS; i++ )
	{
	    if( Pickup[i][pickupID] == ID && Pickup[i][pickupCreated] == 1 )
	    {
	        return i;
	    }
	}
	return -1;
}
public ValidStreamPickupPickUp(playerid, pickupid)
{
	if( Pickup_PlayerToPoint(playerid, 2.0, Pickup[pickupid][pickupX], Pickup[pickupid][pickupY], Pickup[pickupid][pickupZ]) ) return 1; return 0;
}