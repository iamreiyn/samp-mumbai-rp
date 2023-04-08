/*
Rychla tvorba interieru

Include by bzuco
*/

//==============================================================================
//custom shop system by bzuco
#define MAX_SHOP 100
#define PICKUP_ENTER_TYPE 1318//biela sipka
#define BINT_247_1 1//velky shop
#define BINT_247_2 2//velky shop
#define BINT_247_3 3//medium shop
#define BINT_247_4 4//medium shop
#define BINT_247_5 5//medium shop
#define BINT_247_6 6//medium shop

#define BINT_AMMU_1 7//ammu shop
#define BINT_AMMU_2 8//ammu shop
#define BINT_AMMU_3 9//ammu shop
#define BINT_AMMU_4 10//ammu shop
#define BINT_AMMU_5 11//ammu shop

#define BINT_MOTELROOM_1 12//izba motel
#define BINT_MOTELJEFERSON_2 13//izba motel

#define BINT_BETS 			14//stavkova kancelaria
#define BINT_SEX 			15//sex shop
#define BINT_FACTORY 		16//meat processing factory
#define BINT_RCZERO 		17//rczero shop
#define BINT_BINCO 			18//binco shop
#define BINT_DIDIER 		19//didier sachs shop
#define BINT_PROLAPS 		20//prolaps shop
#define BINT_SUBURBAN 		21//suburban shop
#define BINT_VICTIM 		22//victim shop
#define BINT_ZIP 			23//zip shop
#define BINT_DANCECLUB 		24//dance club
#define BINT_CHEAP_BAR 		25//lacny bar
#define BINT_VILLAGE_BAR    26//village bar
#define BINT_DINNINGROOM    27//dinning room
#define BINT_DINNINGROOM2   28//tajna jedalen
#define BINT_BURGER		   	29//burger
#define BINT_CLUCKINBELL    30//cluckinbell
#define BINT_PIZZA		    31//pizza
#define BINT_DONUTSSHOP     32//donutsshop
#define BINT_SHERRIF        33//sherif
#define BINT_GANTONGYM      34//ganton gym
#define BINT_SFGYM          35//SF Gym
#define BINT_LVGYM          36//LV Gym
#define BINT_BIGSPREADRANCH 37//BigSpreadRanch
#define BINT_XXXHOUSE       38//XXX
#define BINT_XXXHOUSELV     39//XXX LV
#define BINT_XXXHOUSEHID    40//XXX hidden
#define BINT_BARBER         41//barber (holic)
#define BINT_TATOO         	42//tatoo

enum sInfo
{
	Float:enterX,
	Float:enterY,
	Float:enterZ,
	Float:exitX,
	Float:exitY,
	Float:exitZ,
	interior,
	used,
	shoptype
}
new shopdata[MAX_SHOP][sInfo];
//==============================================================================
/*Táto funkcia zisí èi už je vytvorený v danom interiery pickup aby nebolo zbytocne vytvorenych v interiery viac pickupov*/
forward IsInThisInteriorPickup(id);
public IsInThisInteriorPickup(id)
{
	new value;
	for(new shopid;shopid<MAX_SHOP;shopid++)
	{
		if(shopdata[shopid][used]==1)
	    {
	        if(shopdata[shopid][shoptype]==id)
	        {
	            value = 1;
	        }
	    }
  	}
	return value;
}
forward AddShop(type,Float:x,Float:y,Float:z);
public AddShop(type,Float:x,Float:y,Float:z)
{
	new idshop;
	for(new shopid;shopid<MAX_SHOP;shopid++)
	{
	    if(shopdata[shopid][used]==0)
	    {
			switch(type)
			{
			    case BINT_247_1:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

					new test = IsInThisInteriorPickup(BINT_247_1);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,-25.6419,-186.1670,1003.5469);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=17;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=-25.6419;
			    	shopdata[shopid][exitY]=-186.1670;
			    	shopdata[shopid][exitZ]=1003.5469;
			    	shopdata[shopid][shoptype]=BINT_247_1;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_247_2:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_247_2);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,6.0912,-29.2719,1003.5494);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=10;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=6.0912;
			    	shopdata[shopid][exitY]=-29.2719;
			    	shopdata[shopid][exitZ]=1003.5494;
			    	shopdata[shopid][shoptype]=BINT_247_2;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_247_3:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_247_3);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,-30.9467,-89.6096,1003.5469);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=18;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=-30.9467;
			    	shopdata[shopid][exitY]=-89.6096;
			    	shopdata[shopid][exitZ]=1003.5469;
			    	shopdata[shopid][shoptype]=BINT_247_3;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_247_4:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_247_4);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,-25.7916,-139.9180,1003.5469);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=16;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=-25.7916;
			    	shopdata[shopid][exitY]=-139.9180;
			    	shopdata[shopid][exitZ]=1003.5469;
			    	shopdata[shopid][shoptype]=BINT_247_4;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_247_5:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_247_5);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,-27.3123,-29.2776,1003.5573);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=4;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=-27.3123;
			    	shopdata[shopid][exitY]=-29.2776;
			    	shopdata[shopid][exitZ]=1003.5573;
			    	shopdata[shopid][shoptype]=BINT_247_5;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_247_6:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_247_6);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,-26.6916,-55.7149,1003.5469);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=6;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=-26.6916;
			    	shopdata[shopid][exitY]=-55.7149;
			    	shopdata[shopid][exitZ]=1003.5469;
			    	shopdata[shopid][shoptype]=BINT_247_6;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_AMMU_1:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_AMMU_1);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,286.1490,-40.6444,1001.5156);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=1;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=286.1490;
			    	shopdata[shopid][exitY]=-40.6444;
			    	shopdata[shopid][exitZ]=1001.5156;
			    	shopdata[shopid][shoptype]=BINT_AMMU_1;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_AMMU_2:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_AMMU_2);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,285.8018,-83.2642,1001.5156);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=4;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=285.8018;
			    	shopdata[shopid][exitY]=-83.2642;
			    	shopdata[shopid][exitZ]=1001.5156;
			    	shopdata[shopid][shoptype]=BINT_AMMU_2;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_AMMU_3:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_AMMU_3);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,296.8138,-109.8164,1001.5156);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=6;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=296.8138;
			    	shopdata[shopid][exitY]=-109.8164;
			    	shopdata[shopid][exitZ]=1001.5156;
			    	shopdata[shopid][shoptype]=BINT_AMMU_3;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_AMMU_4:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_AMMU_4);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,315.8210,-142.4320,999.6016);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=7;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=315.8210;
			    	shopdata[shopid][exitY]=-142.4320;
			    	shopdata[shopid][exitZ]=999.6016;
			    	shopdata[shopid][shoptype]=BINT_AMMU_4;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_AMMU_5:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_AMMU_5);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,316.5250,-168.7070,999.5938);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=6;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=316.5250;
			    	shopdata[shopid][exitY]=-168.7070;
			    	shopdata[shopid][exitZ]=999.5938;
			    	shopdata[shopid][shoptype]=BINT_AMMU_5;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_MOTELROOM_1:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_MOTELROOM_1);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,444.4757,509.4438,1001.4195);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=12;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=444.4757;
			    	shopdata[shopid][exitY]=509.4438;
			    	shopdata[shopid][exitZ]=1001.4195;
			    	shopdata[shopid][shoptype]=BINT_MOTELROOM_1;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_MOTELJEFERSON_2:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_MOTELJEFERSON_2);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,2216.3398,-1150.5099,1025.7969);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=3;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=2216.3398;
			    	shopdata[shopid][exitY]=-1150.5099;
			    	shopdata[shopid][exitZ]=1025.7969;
			    	shopdata[shopid][shoptype]=BINT_MOTELJEFERSON_2;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_BETS:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_BETS);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,833.8190,7.4180,1004.1797);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=15;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=833.8190;
			    	shopdata[shopid][exitY]=7.4180;
			    	shopdata[shopid][exitZ]=1004.1797;
			    	shopdata[shopid][shoptype]=BINT_BETS;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_SEX:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_SEX);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,-100.5604,-22.7961,1000.7188);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=3;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=-100.5604;
			    	shopdata[shopid][exitY]=-22.7961;
			    	shopdata[shopid][exitZ]=1000.7188;
			    	shopdata[shopid][shoptype]=BINT_SEX;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_FACTORY:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_FACTORY);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,964.3770,2157.3298,1011.0303);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=1;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=964.3770;
			    	shopdata[shopid][exitY]=2157.3298;
			    	shopdata[shopid][exitZ]=1011.0303;
			    	shopdata[shopid][shoptype]=BINT_FACTORY;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_RCZERO:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_RCZERO);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,-2239.5698,130.0210,1035.4141);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=6;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=-2239.5698;
			    	shopdata[shopid][exitY]=130.0210;
			    	shopdata[shopid][exitZ]=1035.4141;
			    	shopdata[shopid][shoptype]=BINT_RCZERO;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_BINCO:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_BINCO);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,207.7380,-109.0200,1005.1328);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=15;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=207.7380;
			    	shopdata[shopid][exitY]=-109.0200;
			    	shopdata[shopid][exitZ]=1005.1328;
			    	shopdata[shopid][shoptype]=BINT_BINCO;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_DIDIER:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_DIDIER);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,204.3330,-166.6950,1000.5234);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=14;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=204.3330;
			    	shopdata[shopid][exitY]=-166.6950;
			    	shopdata[shopid][exitZ]=1000.5234;
			    	shopdata[shopid][shoptype]=BINT_DIDIER;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_PROLAPS:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_PROLAPS);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,207.0550,-138.8050,1003.5078);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=3;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=207.0550;
			    	shopdata[shopid][exitY]=-138.8050;
			    	shopdata[shopid][exitZ]=1003.5078;
			    	shopdata[shopid][shoptype]=BINT_PROLAPS;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_SUBURBAN:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_SUBURBAN);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,203.7780,-48.4924,1001.8047);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=1;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=203.7780;
			    	shopdata[shopid][exitY]=-48.4924;
			    	shopdata[shopid][exitZ]=1001.8047;
			    	shopdata[shopid][shoptype]=BINT_SUBURBAN;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_VICTIM:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_VICTIM);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,226.2940,-7.4315,1002.2109);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=5;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=226.2940;
			    	shopdata[shopid][exitY]=-7.4315;
			    	shopdata[shopid][exitZ]=1002.2109;
			    	shopdata[shopid][shoptype]=BINT_VICTIM;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_ZIP:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_ZIP);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,161.3910,-93.1592,1001.8047);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=18;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=161.3910;
			    	shopdata[shopid][exitY]=-93.1592;
			    	shopdata[shopid][exitZ]=1001.8047;
			    	shopdata[shopid][shoptype]=BINT_ZIP;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_DANCECLUB:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_DANCECLUB);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,493.3910,-22.7228,1000.6797);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=17;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=493.3910;
			    	shopdata[shopid][exitY]=-22.7228;
			    	shopdata[shopid][exitZ]=1000.6797;
			    	shopdata[shopid][shoptype]=BINT_DANCECLUB;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_CHEAP_BAR:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_CHEAP_BAR);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,501.9810,-69.1502,998.7578);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=11;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=501.9810;
			    	shopdata[shopid][exitY]=-69.1502;
			    	shopdata[shopid][exitZ]=998.7578;
			    	shopdata[shopid][shoptype]=BINT_CHEAP_BAR;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_VILLAGE_BAR:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_VILLAGE_BAR);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,-227.0280,1401.2300,27.7656);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=18;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=-227.0280;
			    	shopdata[shopid][exitY]=1401.2300;
			    	shopdata[shopid][exitZ]=27.7656;
			    	shopdata[shopid][shoptype]=BINT_VILLAGE_BAR;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_DINNINGROOM:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_DINNINGROOM);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,460.1000,-88.4285,999.5547);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=4;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=460.1000;
			    	shopdata[shopid][exitY]=-88.4285;
			    	shopdata[shopid][exitZ]=999.5547;
			    	shopdata[shopid][shoptype]=BINT_DINNINGROOM;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_DINNINGROOM2:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_DINNINGROOM2);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,681.4544,-451.4634,-25.6172);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=1;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=681.4544;
			    	shopdata[shopid][exitY]=-451.4634;
			    	shopdata[shopid][exitZ]=-25.6172;
			    	shopdata[shopid][shoptype]=BINT_DINNINGROOM2;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_BURGER:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_BURGER);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,365.1427,-73.3908,1001.5078);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=10;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=365.1427;
			    	shopdata[shopid][exitY]=-73.3908;
			    	shopdata[shopid][exitZ]=1001.5078;
			    	shopdata[shopid][shoptype]=BINT_BURGER;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_CLUCKINBELL:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_CLUCKINBELL);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,365.6730,-10.7132,1001.8516);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=9;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=365.6730;
			    	shopdata[shopid][exitY]=-10.7132;
			    	shopdata[shopid][exitZ]=1001.8516;
			    	shopdata[shopid][shoptype]=BINT_CLUCKINBELL;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_PIZZA:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_PIZZA);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,372.3520,-131.6510,1001.4922);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=5;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=372.3520;
			    	shopdata[shopid][exitY]=-131.6510;
			    	shopdata[shopid][exitZ]=1001.4922;
			    	shopdata[shopid][shoptype]=BINT_PIZZA;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_DONUTSSHOP:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_DONUTSSHOP);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,377.0982,-192.4379,1000.6328);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=17;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=377.0982;
			    	shopdata[shopid][exitY]=-192.4379;
			    	shopdata[shopid][exitZ]=1000.6328;
			    	shopdata[shopid][shoptype]=BINT_DONUTSSHOP;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_SHERRIF:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_SHERRIF);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,322.0931,303.0943,999.1484);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=5;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=322.0931;
			    	shopdata[shopid][exitY]=303.0943;
			    	shopdata[shopid][exitZ]=999.1484;
			    	shopdata[shopid][shoptype]=BINT_SHERRIF;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_GANTONGYM:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_GANTONGYM);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,772.1120,-3.8986,1000.7288);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=5;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=772.1120;
			    	shopdata[shopid][exitY]=-3.8986;
			    	shopdata[shopid][exitZ]=1000.7288;
			    	shopdata[shopid][shoptype]=BINT_GANTONGYM;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_SFGYM:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_SFGYM);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,774.2140,-48.9243,1000.5859);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=6;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=774.2140;
			    	shopdata[shopid][exitY]=-48.9243;
			    	shopdata[shopid][exitZ]=1000.5859;
			    	shopdata[shopid][shoptype]=BINT_SFGYM;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_LVGYM:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_LVGYM);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,773.5800,-77.0967,1000.6550);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=7;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=773.5800;
			    	shopdata[shopid][exitY]=-77.0967;
			    	shopdata[shopid][exitZ]=1000.6550;
			    	shopdata[shopid][shoptype]=BINT_LVGYM;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_BIGSPREADRANCH:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_BIGSPREADRANCH);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,1212.3992,-27.3520,1000.9531);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=3;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=1212.3992;
			    	shopdata[shopid][exitY]=-27.3520;
			    	shopdata[shopid][exitZ]=1000.9531;
			    	shopdata[shopid][shoptype]=BINT_BIGSPREADRANCH;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_XXXHOUSE:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_XXXHOUSE);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,744.8810,1437.0841,1102.7031);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=6;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=744.8810;
			    	shopdata[shopid][exitY]=1437.0841;
			    	shopdata[shopid][exitZ]=1102.7031;
			    	shopdata[shopid][shoptype]=BINT_XXXHOUSE;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_XXXHOUSELV:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_XXXHOUSELV);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,1204.8099,-11.5868,1000.9219);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=2;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=1204.8099;
			    	shopdata[shopid][exitY]=-11.5868;
			    	shopdata[shopid][exitZ]=1000.9219;
			    	shopdata[shopid][shoptype]=BINT_XXXHOUSELV;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_XXXHOUSEHID:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_XXXHOUSEHID);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,941.6579,-15.7538,1000.9297);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=3;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=941.6579;
			    	shopdata[shopid][exitY]=-15.7538;
			    	shopdata[shopid][exitZ]=1000.9297;
			    	shopdata[shopid][shoptype]=BINT_XXXHOUSEHID;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_BARBER:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_BARBER);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,411.6260,-21.4333,1001.8047);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=2;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=411.6260;
			    	shopdata[shopid][exitY]=-21.4333;
			    	shopdata[shopid][exitZ]=1001.8047;
			    	shopdata[shopid][shoptype]=BINT_BARBER;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			    case BINT_TATOO:
			    {
			    	AddStaticPickup(PICKUP_ENTER_TYPE,1,x,y,z);

			    	new test = IsInThisInteriorPickup(BINT_BARBER);
					if(test==0)AddStaticPickup(PICKUP_ENTER_TYPE,1,-204.4400,-8.4696,1002.2734);

			    	shopdata[shopid][used]=1;
			    	shopdata[shopid][interior]=17;
			    	shopdata[shopid][enterX]=x;
			    	shopdata[shopid][enterY]=y;
			    	shopdata[shopid][enterZ]=z;
			    	shopdata[shopid][exitX]=-204.4400;
			    	shopdata[shopid][exitY]=-8.4696;
			    	shopdata[shopid][exitZ]=1002.2734;
			    	shopdata[shopid][shoptype]=BINT_TATOO;

			    	idshop=shopid;
			    	shopid=MAX_SHOP;
			    }
			}
		}
	}
	return idshop;
}
forward OnPlayerEnterShop(playerid);
public OnPlayerEnterShop(playerid)
{
	for(new shopid;shopid<MAX_SHOP;shopid++)
	{
	    if(shopdata[shopid][used]==1)
	    {
	    	if (PlayerToPointBint(3.0, playerid,shopdata[shopid][enterX],shopdata[shopid][enterY],shopdata[shopid][enterZ]))
	    	{
	    	    SetPlayerInterior(playerid,shopdata[shopid][interior]);
	    	    SetPlayerPos(playerid,shopdata[shopid][exitX],shopdata[shopid][exitY],shopdata[shopid][exitZ]);
	    	    SetPlayerVirtualWorld(playerid,shopid+1);
	    	}
	    }
 	}
	return 1;
}
forward OnPlayerExitShop(playerid);
public OnPlayerExitShop(playerid)
{
	new shopid = GetPlayerVirtualWorld(playerid)-1;
	if (PlayerToPointBint(3.0, playerid,shopdata[shopid][exitX],shopdata[shopid][exitY],shopdata[shopid][exitZ]))
	{
   		SetPlayerPos(playerid,shopdata[shopid][enterX],shopdata[shopid][enterY],shopdata[shopid][enterZ]);
	    SetPlayerVirtualWorld(playerid,0);
	    SetPlayerInterior(playerid,0);
 	}else{
 	    GameTextForPlayer(playerid,"Tu niesu ziadne dvere!",3000,6);
 	}
	return 1;
}
stock PlayerToPointBint(Float:radi, playerid, Float:x, Float:y, Float:z)
{
    if(IsPlayerConnected(playerid))
	{
		new Float:oldposx, Float:oldposy, Float:oldposz;
		new Float:tempposx, Float:tempposy, Float:tempposz;
		GetPlayerPos(playerid, oldposx, oldposy, oldposz);
		tempposx = (oldposx -x);
		tempposy = (oldposy -y);
		tempposz = (oldposz -z);
		//printf("DEBUG: X:%f Y:%f Z:%f",posx,posy,posz);
		if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
		{
			return 1;
		}
	}
	return 0;
}