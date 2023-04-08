#include <a_samp>
#define red 0
#define blue 1
#define green 2
#define yellow 3
#define pink 4
#define white 5
new CarNeon1[MAX_VEHICLES];
new CarNeon2[MAX_VEHICLES];

stock SetNeon(vehicleid,neonmode/*true if you want the neon to show, false if you want it hidden*/, neoncolor/*COLORS: red, blue, green, yellow, pink, white*/)
{
	switch(neonmode)
	{
		case true:
		{
            DestroyObject(CarNeon1[vehicleid]);
			DestroyObject(CarNeon2[vehicleid]);
			switch(neoncolor)
			{
				case red://red 18647
				{
				    CarNeon1[vehicleid] = CreateObject(18647, 0, 0, 0, 0, 0, 0);
        			CarNeon2[vehicleid] = CreateObject(18647, 0, 0, 0, 0, 0, 0);
				}
				case blue://blue 18648
				{
				    CarNeon1[vehicleid] = CreateObject(18648, 0, 0, 0, 0, 0, 0);
        			CarNeon2[vehicleid] = CreateObject(18648, 0, 0, 0, 0, 0, 0);
				}
				case green://green 18649
				{
				    CarNeon1[vehicleid] = CreateObject(18649, 0, 0, 0, 0, 0, 0);
        			CarNeon2[vehicleid] = CreateObject(18649, 0, 0, 0, 0, 0, 0);
				}
				case yellow://18650
				{
				    CarNeon1[vehicleid] = CreateObject(18650, 0, 0, 0, 0, 0, 0);
        			CarNeon2[vehicleid] = CreateObject(18650, 0, 0, 0, 0, 0, 0);
				}
				case pink://18651
				{
				    CarNeon1[vehicleid] = CreateObject(18651, 0, 0, 0, 0, 0, 0);
        			CarNeon2[vehicleid] = CreateObject(18651, 0, 0, 0, 0, 0, 0);
				}
				case white://18652
				{
				    CarNeon1[vehicleid] = CreateObject(18652, 0, 0, 0, 0, 0, 0);
        			CarNeon2[vehicleid] = CreateObject(18652, 0, 0, 0, 0, 0, 0);
				}
			}
			AttachObjectToVehicle(CarNeon1[vehicleid], vehicleid, 0.96,0, -0.50, 0, 0, 0);
			AttachObjectToVehicle(CarNeon2[vehicleid], vehicleid, -0.96,0, -0.50, 0, 0, 0);
		}
		case false:
		{
			DestroyObject(CarNeon1[vehicleid]);
			DestroyObject(CarNeon2[vehicleid]);

		}
	}
	return 1;
}

