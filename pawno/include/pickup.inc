new Float:PickupIDs[400][3];
#define FIX_PICKUPS if(!IsPickedUp(playerid,pickupid)) pickupid = GetPickupNearPlayer(playerid,5.0);

stock CreatePickupA(model,type,Float:x,Float:y,Float:z)
{
	new tmp;
	tmp = CreatePickup(model,type,Float:x,Float:y,Float:z);
	PickupIDs[tmp][0]=x; PickupIDs[tmp][1]=y; PickupIDs[tmp][2]=z;
	return tmp;
}

stock IsPickedUp(playerid,pickupid)
{
	if(!PlayerToPointM(5,playerid,PickupIDs[pickupid][0],PickupIDs[pickupid][1],PickupIDs[pickupid][2])) return 0;
	return 1;
}
	

stock GetPickupNearPlayer(playerid,Float:radi) //Half Andre's function
{
	new Float:oldposx, Float:oldposy, Float:oldposz;
	GetPlayerPos(playerid, oldposx, oldposy, oldposz);

	for(new npickup=0; npickup<400; npickup++)
	{		
		new Float:tempposx, Float:tempposy, Float:tempposz;
		tempposx = (oldposx -PickupIDs[npickup][0]);
		tempposy = (oldposy -PickupIDs[npickup][1]);
		tempposz = (oldposz -PickupIDs[npickup][2]);

		if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
		{
			return npickup;
		}
	}
	return -1;
}
	
stock PlayerToPointM(Float:radi, playerid, Float:x, Float:y, Float:z) //By Andre, thanks.
{
    if(IsPlayerConnected(playerid))
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
	}
	return 0;
}