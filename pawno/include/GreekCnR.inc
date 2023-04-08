/*
+-----------------------------------------------------------------------+
¦                        GreekCnR Anti-Cheat                            ¦
¦                                  by                                   ¦
¦                               JuVe2009                                ¦
¦                                                                       ¦
¦ This Anti-Cheat script is made by me, JuVe2009 + CrazyDog.Well        ¦
¦ Anti-Cheat system "PunkBuster" inspired me to make a new              ¦
¦ Anti-Cheat script for SA:MP. It contains many functions against       ¦
¦ normal cheats and cheats from specific cheat tools. It's against      ¦
¦ (command) spam, too. It doesn't contain codes which result many       ¦
¦ codes which would cause kicks/bans of innocent players.               ¦
¦ There is no real check for godmode and no server-based health/armour  ¦
¦ because it's just stupid. Because there are so much possibilities to  ¦
¦ get health without SetPlayerHealth. This would cause very much wrong  ¦
¦ kicks/bans. The only code which could ban innocents is the teleport   ¦
¦ code and the carjack code. It could kick extreme laggy players.       ¦
¦ If GreekCnR kicks/bans too much innocent players, disable the codes   ¦
¦ which kick/ban too much innocent players. You can easily configurate  ¦
¦ JunkBuster in the file "JunkBuster.cfg" in the folder "JunkBuster"    ¦
¦ in the folder "scriptfiles". Use "/jbcfg" ingame if you are           ¦
¦ (rcon)admin to update the configuration.                              ¦
¦ Define in "BadWords.cfg" the forbidden words, define in               ¦
¦ "ForbiddenWeapons.cfg" to forbidden weapons.                          ¦
¦                                                                       ¦
¦ I call this script a 'Plug & Play'-script! Why? In this version       ¦
¦ You only need to include the script and compile your gamemode.        ¦
¦ Everything important is done by the script itself. You DON'T need to  ¦
¦ change anything! (Except for some functions when they are already     ¦
¦ defined.                                                              ¦
¦                                                                       ¦
¦ This script has been made by JuVe2009! You are NOT allowed to:        ¦
¦ - Remove this text                                                    ¦
¦ - Rename GreekCnR                                                     ¦
¦ - Re-release this script                                              ¦
¦ - Say it's your own script                                            ¦
¦                                                                       ¦
¦ But you are allowed to add more functions and use it on your server.  ¦
¦                                                                       ¦
¦ Thanks to DracoBlue for Dini and ~Cueball~ for his zone include.      ¦
+-----------------------------------------------------------------------+
*/

#if defined _JB_included
	#endinput
#endif
#define _JB_included

//==============================================================================

#include <a_samp>
#include <Dini>

//==============================================================================

//#define WARN_PLAYERS // Comment this if players shouldn't get warned when they connect.

#define CONFIG_FILE "GreekCnR/GreekCnR.cfg"
#define BAD_WORDS_FILE "GreekCnR/BadWords.cfg"
#define FORBIDDEN_WEAPONS_FILE "GreekCnR/ForbiddenWeapons.cfg"
#define JB_LOG_FILE "GreekCnR/GreekCnR.log"
#define BLACKLIST_FILE "GreekCnR/Blacklist.txt"
#define WHITELIST_FILE "GreekCnR/Whitelist.txt"
#define IP_BAN_FILE "GreekCnR/IpBans.txt"
#define TEMP_BAN_FILE "GreekCnR/TempBans.txt"
#define BAD_RCON_LOGIN_FILE "GreekCnR/BadRconLogin.txt"

#define MAX_JB_VARIABLES 24
#define MAX_BAD_WORDS 100
#define MAX_FORBIDDEN_WEAPONS 20
#define MAX_PING_CHECKS 3
#define MAX_WEAPONS 47
#define MAX_CHECKS 3

#define WEAPON_HACK 0
#define MONEY_HACK 1
#define JETPACK 2
#define HEALTH_HACK 3
#define ARMOUR_HACK 4
#define DRIVE_BY 5
#define SPAM 6
#define COMMAND_SPAM 7
#define BAD_WORDS 8
#define CAR_JACK_HACK 9
#define TELEPORT_HACK 10
#define MAX_PING 11
#define SPECTATE_HACK 12
#define BLACKLIST 13
#define IP_BANS 14
#define TEMP_BANS 15
#define SPAWNKILL 16
#define CAPS_LOCK 17
#define SPEED_3D 18
#define MAX_SPEED 19
#define ADMIN_IMMUNITY 20
#define ADVERTISEMENT 21
#define FREEZE_UPDATE 22
#define SPAWN_TIME 23

#define RED 0xFF0000FF
#define GREEN 0x00FF00FF
#define GREEN_BLUE 0x00D799FF

#define DIALOG_CFG 28354
#define DIALOG_VARLIST 28355
#define DIALOG_SETVAR 28356

new FALSE=false;
new TRUE=true;
#pragma unused TRUE

#define JB_SendFormattedMessage(%0,%1,%2,%3) do{new _string[128]; format(_string,sizeof(_string),%2,%3); SendClientMessage(%0,%1,_string);} while(FALSE)
#define JB_SendFormattedMessageToAll(%0,%1,%2) do{new _string[128]; format(_string,sizeof(_string),%1,%2); SendClientMessageToAll(%0,_string);} while(FALSE)
#define JB_LogEx(%0,%1) do{new _string[256]; format(_string,sizeof(_string),%0,%1); JB_Log(_string);} while(FALSE)
#define GetVehicleName(%0) VehicleName[GetVehicleModel(%0)-400]
#define JB_Speed(%0,%1,%2,%3) floatround(floatsqroot(JB_Variables[SPEED_3D]?(%0*%0+%1*%1+%2*%2):(%0*%0+%1*%1))*%3*1.6)

//==============================================================================

new JB_Warnings[MAX_PLAYERS][MAX_JB_VARIABLES];
new JB_Variables[MAX_JB_VARIABLES]=
{
	true,//WeaponHack
	true,//MoneyHack
	true,//Jetpack
	true,//HealthHack
	true,//ArmourHack
	true,//DriveBy
	true,//Spam
	true,//CommandSpam
	true,//BadWords
	true,//CarJackHack
	true,//TeleportHack
	500,//MaxPing
	true,//SpectateHack
	true,//Blacklist
	true,//IpBans
	true,//TempBans
	3,//SpawnKill
	true,//CapsLock
	false,//3DSpeed
	230,//MaxSpeed
	true,//AdminImmunity
	false,//Advertisement
	false,//FreezeUpdate
	10//SpawnTime
};

new JB_VariableNames[MAX_JB_VARIABLES][32]=
{
	"WeaponHack",
	"MoneyHack",
	"Jetpack",
	"HealthHack",
	"ArmourHack",
	"DriveBy",
	"Spam",
	"CommandSpam",
	"BadWords",
	"CarJackHack",
	"TeleportHack",
	"MaxPing",
	"SpectateHack",
	"Blacklist",
	"IpBans",// also contains IP-bans
	"TempBans",
	"SpawnKill",//Set this to the max spawnkills you want to allow
	"CapsLock",
	"3DSpeed",
	"MaxSpeed",
	"AdminImmunity",
	"Advertisement",
	"FreezeUpdate",
	"SpawnTime"
};

new JB_VarDescription[MAX_JB_VARIABLES][512]=
{
	"If enabled GreekCnR will ban for forbidden weapons.\nSet to 0 to disable, set to 1 to enable.",//WeaponHack
	"Enable to manage to players money serverside. Cheating money will be impossible.\nBut gambling for money or stunt bonus, too.\nSet to 0 to disable, set to 1 to enable.",//MoneyHack
	"If enabled GreekCnR will ban for jetpacks.",//Jetpack
	"If enabled GreekCnR will ban players who's health value is higher than 100.\nSet to 0 to disable, set to 1 to enable.",//HealthHack
	"If enabled GreekCnR will ban players who's armour value is higher than 100.\nSet to 0 to disable, set to 1 to enable.",//ArmourHack
	"Enable to forbid forbid drive-by. GreekCnR will kill drive-byers.\nSet to 0 to disable, set to 1 to enable.",//DriveBy
	"Will mute, kick or ban for chat spam.\nSet to 0 to disable, set to 1 to enable.",//Spam
	"Will kick or ban for command spam.\nSet to 0 to disable, set to 1 to enable.",//CommandSpam
	"Enable to block bad words like 'motherfucker'.\nSet to 0 to disable, set to 1 to enable.",//BadWords
	"Enable to prevent carjacks performed with hacks.\nSet to 0 to disable, set to 1 to enable.",//CarJackHack
	"Enable to prevent teleport with cheat tools.\nSet to 0 to disable, set to 1 to enable.",//TeleportHack
	"Set max ping. GreekCnR will calculate average ping for players and kick them if their ping is higher.\n Set to 0 to disable.\nIf you want to enable it, it's recommended to set higher than 300.",//MaxPing
	"Enable to ban for illegal spectating with cheat tools.\nSet to 0 to disable, set to 1 to enable.",//SpectateHack
	"Enable the blacklist. Players with blacklisted names will get banned when connecting.\nSet to 0 to disable, set to 1 to enable.",//Blacklist
	"Alternative to the native IP ban system.\nYou can make exceptions for some players by adding them to the whitelist.\nIf their IP is banned they still can play if they are on whitelist.\nYou can rangeban players without banning every player with the banned IP.\nSet to 0 to disable, set to 1 to enable.",//IpBans
	"Enable temporary bans.\nSet to 0 to disable, set to 1 to enable.",//TempBans
	"Prevent players from spawnkilling other players.\nSet to 0 to disable.\nHigher then 0 will define how many spawnkill warnings a player will get before he will get kicked.",//SpawnKill
	"Block capslock.\nSet to 0 to disable, set to 1 to enable.",//CapsLock
	"Calculate speed with 3 dimensions (x,y,z) or only in 2 (x,y) if disabled.\nIt's recommended to disable this function.",//3DSpeed
	"Set the max speed in KM/H. It's used for anti speedhack.\nSet to 0 to disable anti speedhack.\nIt's recommended to set higher than 200.",//MaxSpeed
	"If enabled admins wont get checked for any cheats and are immune to anything. (Anti spam, max ping, ...)\nSet to 0 to disable, set to 1 to enable.\nIt's recommended to enable.",//AdminImmunity
	"Block advertisement.\nSet to 0 to disable, set to 1 to enable.",//Advertisement
	"Manage if player is freezed or not with JunkBuster.",//FreezeUpdate
	"Defines how long in seconds a player will be spawnkill protected after spawning.\nSet a value of your choice."//SpawnTime
};

enum JB_pInfo
{
	JB_pMoney,
	JB_pLastMessage[128],
	JB_pMessageRepeated,
	JB_pMessages,
	JB_pCommands,
	JB_pMuted,
	JB_pFreezed,
	JB_pPing[MAX_PING_CHECKS],
	JB_pPingCheckProgress,
	JB_pVehicleEntered,
	JB_pSpawnKillProtected,
	JB_pSpeedhacking
}
new JB_PlayerInfo[MAX_PLAYERS][JB_pInfo];

new WeaponForbiddenForPlayer[MAX_PLAYERS][MAX_WEAPONS];
new KickBan[MAX_PLAYERS];// Do not use this.
new FullyConnected[MAX_PLAYERS];// Player will only get checked if he spawned a first time.

new Float:CurrentPos[MAX_PLAYERS][3];
new NoTeleportCheck[MAX_PLAYERS];

new BadWords[MAX_BAD_WORDS][32];
new BadWordsCount;
new ForbiddenWeapons[MAX_FORBIDDEN_WEAPONS];
new ForbiddenWeaponsCount;

new Blacklist[100][MAX_PLAYER_NAME];
new Whitelist[100][MAX_PLAYER_NAME];
new IpBans[50][4];
new IpBanned[50];
enum tbInfo
{
	tbName[MAX_PLAYER_NAME],
	tbIp[16],
	tbTime
}
new TempBanInfo[250][tbInfo];

new Planes[]=
{
    413,417,425,447,460,469,476,487,488,497,511,512,513,519,520,548,553,563,577,592,593
};

new VehicleName[][] =
{
   "Landstalker",
   "Bravura",
   "Buffalo",
   "Linerunner",
   "Pereniel",
   "Sentinel",
   "Dumper",
   "Firetruck",
   "Trashmaster",
   "Stretch",
   "Manana",
   "Infernus",
   "Voodoo",
   "Pony",
   "Mule",
   "Cheetah",
   "Ambulance",
   "Leviathan",
   "Moonbeam",
   "Esperanto",
   "Taxi",
   "Washington",
   "Bobcat",
   "Mr Whoopee",
   "BF Injection",
   "Hunter",
   "Premier",
   "Enforcer",
   "Securicar",
   "Banshee",
   "Predator",
   "Bus",
   "Rhino",
   "Barracks",
   "Hotknife",
   "Trailer",
   "Previon",
   "Coach",
   "Cabbie",
   "Stallion",
   "Rumpo",
   "RC Bandit",
   "Romero",
   "Packer",
   "Monster Truck",
   "Admiral",
   "Squalo",
   "Seasparrow",
   "Pizzaboy",
   "Tram",
   "Trailer",
   "Turismo",
   "Speeder",
   "Reefer",
   "Tropic",
   "Flatbed",
   "Yankee",
   "Caddy",
   "Solair",
   "Berkley's RC Van",
   "Skimmer",
   "PCJ-600",
   "Faggio",
   "Freeway",
   "RC Baron",
   "RC Raider",
   "Glendale",
   "Oceanic",
   "Sanchez",
   "Sparrow",
   "Patriot",
   "Quad",
   "Coastguard",
   "Dinghy",
   "Hermes",
   "Sabre",
   "Rustler",
   "ZR-350",
   "Walton",
   "Regina",
   "Comet",
   "BMX",
   "Burrito",
   "Camper",
   "Marquis",
   "Baggage",
   "Dozer",
   "Maverick",
   "News Chopper",
   "Rancher",
   "FBI Rancher",
   "Virgo",
   "Greenwood",
   "Jetmax",
   "Hotring",
   "Sandking",
   "Blista Compact",
   "Police Maverick",
   "Boxville",
   "Benson",
   "Mesa",
   "RC Goblin",
   "Hotring Racer",
   "Hotring Racer",
   "Bloodring Banger",
   "Rancher",
   "Super GT",
   "Elegant",
   "Journey",
   "Bike",
   "Mountain Bike",
   "Beagle",
   "Cropdust",
   "Stunt",
   "Tanker",
   "RoadTrain",
   "Nebula",
   "Majestic",
   "Buccaneer",
   "Shamal",
   "Hydra",
   "FCR-900",
   "NRG-500",
   "HPV1000",
   "Cement Truck",
   "Tow Truck",
   "Fortune",
   "Cadrona",
   "FBI Truck",
   "Willard",
   "Forklift",
   "Tractor",
   "Combine",
   "Feltzer",
   "Remington",
   "Slamvan",
   "Blade",
   "Freight",
   "Streak",
   "Vortex",
   "Vincent",
   "Bullet",
   "Clover",
   "Sadler",
   "Firetruck",
   "Hustler",
   "Intruder",
   "Primo",
   "Cargobob",
   "Tampa",
   "Sunrise",
   "Merit",
   "Utility",
   "Nevada",
   "Yosemite",
   "Windsor",
   "Monster Truck",
   "Monster Truck",
   "Uranus",
   "Jester",
   "Sultan",
   "Stratum",
   "Elegy",
   "Raindance",
   "RC Tiger",
   "Flash",
   "Tahoma",
   "Savanna",
   "Bandito",
   "Freight",
   "Trailer",
   "Kart",
   "Mower",
   "Duneride",
   "Sweeper",
   "Broadway",
   "Tornado",
   "AT-400",
   "DFT-30",
   "Huntley",
   "Stafford",
   "BF-400",
   "Newsvan",
   "Tug",
   "Trailer",
   "Emperor",
   "Wayfarer",
   "Euros",
   "Hotdog",
   "Club",
   "Trailer",
   "Trailer",
   "Andromada",
   "Dodo",
   "RC Cam",
   "Launch",
   "Police Car (LSPD)",
   "Police Car (SFPD)",
   "Police Car (LVPD)",
   "Police Ranger",
   "Picador",
   "S.W.A.T. Van",
   "Alpha",
   "Phoenix",
   "Glendale",
   "Sadler",
   "Luggage Trailer",
   "Luggage Trailer",
   "Stair Trailer",
   "Boxville",
   "Farm Plow",
   "Utility Trailer"
};

/*
These coordinates are taken from m0d_n00beit(Credits to HiM,friend of JuVe2009).
Yes, I'm always testing the newest versions. You can't create a useful
anti-cheat which detects many cheats, if you don't check out the cheat tools.
Fuck those suckers. If someone teleports there, he MUST be a cheater
and GreekCnR will ban him.
*/
new Float:CheatPositions[][3]=
{
	{403.58, 2486.33, 17.23},// Airport Garage in Verdant Meadows
	{1578.24, 1245.20, 11.57},// Airport Plane Garage in Las Venturas
	{1641.14, -1526.87, 14.30},// Commerce Region, Loading Bay Garage
	{1836.93, -1856.28, 14.13},// Eight Ball Autos near El Corona
	{2645.61, -2029.15, 14.28},// LowRider Tuning Garage in Willowfield
	{-1787.25, 1202.00, 25.84},// Michelles Pay 'n' Spray in Downtown
	{1041.26, -1036.77, 32.48},// Transfender in Temple
	{2387.55, 1035.70, 11.56},// Transfender in come-a-lot
	{-1935.77, 228.79, 34.16},// Transfender near Wang Cars in Doherty
	{2006.11, 2292.87, 11.57},// Welding Wedding Bomb-workshop in Emerald Isle
	{-2707.48, 218.65, 4.93},// Wheel Archangels in Ocean Flats
	{720.10, -470.93, 17.07},// Pay 'n' Spray in Dillimore
	{-1420.21, 2599.45, 56.43},// Pay 'n' Spray in El Quebrados
	{-100.16, 1100.79, 20.34},// Pay 'n' Spray in Fort Carson
	{2078.44, -1831.44, 14.13},// Pay 'n' Spray in Idlewood
	{-2426.89, 1036.61, 51.14},// Pay 'n' Spray in Juniper Hollow
	{1957.96, 2161.96, 11.56},// Pay 'n' Spray in Redsands East
	{488.29, -1724.85, 12.01},// Pay 'n' Spray in Santa Maria Beach
	{1025.08, -1037.28, 32.28},// Pay 'n' Spray in Temple
	{2393.70, 1472.80, 11.42},// Pay 'n' Spray near Royal Casino
	{-1904.97, 268.51, 41.04},// Pay 'n' Spray near Wang Cars in Doherty
	{-1617.58, 688.69, -4.50},// Police Garage in DownTown
	{-2105.79, 905.11, 77.07},// Player Garage: Calton Heights
	{423.69, 2545.99, 17.07},// Player Garage: Derdant Meadows
	{785.79, -513.12, 17.44},// Player Garage: Dillimore
	{-2027.34, 141.02, 29.57},// Player Garage: Doherty
	{1698.10, -2095.88, 14.29},// Player Garage: El Corona
	{-361.10, 1185.23, 20.49},// Player Garage: Fort Carson
	{-2463.27, -124.86, 26.41},// Player Garage: Hashbury
	{2505.64, -1683.72, 14.25},// Player Garage: Johnson House
	{1350.76, -615.56, 109.88},// Player Garage: Mulholland
	{2231.64, 156.93, 27.63},// Player Garage: Palomino Creek
	{-2695.51, 810.70, 50.57},// Player Garage: Paradiso
	{1293.61, 2529.54, 11.42},// Player Garage: Prickle Pine
	{1401.34, 1903.08, 11.99},// Player Garage: Redland West
	{2436.50, 698.43, 11.60},// Player Garage: Rockshore West
	{322.65, -1780.30, 5.55},// Player Garage: Santa Maria Beach
	{917.46, 2012.14, 11.65}// Player Garage: Whitewood Estates
};

//From Cueball's "Zones By ~Cueball~ - V 2.0" (added JB_ tag so there should no redefinitions exist when compiling)
enum JB_SAZONE_MAIN { //Betamaster
		JB_SAZONE_NAME[28],
		Float:JB_SAZONE_AREA[6]
};

static const JB_gSAZones[][JB_SAZONE_MAIN] = {  // Majority of names and area coordinates adopted from JuVe2009's and Zapalot's 'Devilsides Script' v0.2
	//	NAME                            AREA (Xmin,Ymin,Zmin,Xmax,Ymax,Zmax)
	{"The Big Ear",	                {-410.00,1403.30,-3.00,-137.90,1681.20,200.00}},
	{"Aldea Malvada",               {-1372.10,2498.50,0.00,-1277.50,2615.30,200.00}},
	{"Angel Pine",                  {-2324.90,-2584.20,-6.10,-1964.20,-2212.10,200.00}},
	{"Arco del Oeste",              {-901.10,2221.80,0.00,-592.00,2571.90,200.00}},
	{"Avispa Country Club",         {-2646.40,-355.40,0.00,-2270.00,-222.50,200.00}},
	{"Avispa Country Club",         {-2831.80,-430.20,-6.10,-2646.40,-222.50,200.00}},
	{"Avispa Country Club",         {-2361.50,-417.10,0.00,-2270.00,-355.40,200.00}},
	{"Avispa Country Club",         {-2667.80,-302.10,-28.80,-2646.40,-262.30,71.10}},
	{"Avispa Country Club",         {-2470.00,-355.40,0.00,-2270.00,-318.40,46.10}},
	{"Avispa Country Club",         {-2550.00,-355.40,0.00,-2470.00,-318.40,39.70}},
	{"Back o Beyond",               {-1166.90,-2641.10,0.00,-321.70,-1856.00,200.00}},
	{"Battery Point",               {-2741.00,1268.40,-4.50,-2533.00,1490.40,200.00}},
	{"Bayside",                     {-2741.00,2175.10,0.00,-2353.10,2722.70,200.00}},
	{"Bayside Marina",              {-2353.10,2275.70,0.00,-2153.10,2475.70,200.00}},
	{"Beacon Hill",                 {-399.60,-1075.50,-1.40,-319.00,-977.50,198.50}},
	{"Blackfield",                  {964.30,1203.20,-89.00,1197.30,1403.20,110.90}},
	{"Blackfield",                  {964.30,1403.20,-89.00,1197.30,1726.20,110.90}},
	{"Blackfield Chapel",           {1375.60,596.30,-89.00,1558.00,823.20,110.90}},
	{"Blackfield Chapel",           {1325.60,596.30,-89.00,1375.60,795.00,110.90}},
	{"Blackfield Intersection",     {1197.30,1044.60,-89.00,1277.00,1163.30,110.90}},
	{"Blackfield Intersection",     {1166.50,795.00,-89.00,1375.60,1044.60,110.90}},
	{"Blackfield Intersection",     {1277.00,1044.60,-89.00,1315.30,1087.60,110.90}},
	{"Blackfield Intersection",     {1375.60,823.20,-89.00,1457.30,919.40,110.90}},
	{"Blueberry",                   {104.50,-220.10,2.30,349.60,152.20,200.00}},
	{"Blueberry",                   {19.60,-404.10,3.80,349.60,-220.10,200.00}},
	{"Blueberry Acres",             {-319.60,-220.10,0.00,104.50,293.30,200.00}},
	{"Caligula's Palace",           {2087.30,1543.20,-89.00,2437.30,1703.20,110.90}},
	{"Caligula's Palace",           {2137.40,1703.20,-89.00,2437.30,1783.20,110.90}},
	{"Calton Heights",              {-2274.10,744.10,-6.10,-1982.30,1358.90,200.00}},
	{"Chinatown",                   {-2274.10,578.30,-7.60,-2078.60,744.10,200.00}},
	{"City Hall",                   {-2867.80,277.40,-9.10,-2593.40,458.40,200.00}},
	{"Come-A-Lot",                  {2087.30,943.20,-89.00,2623.10,1203.20,110.90}},
	{"Commerce",                    {1323.90,-1842.20,-89.00,1701.90,-1722.20,110.90}},
	{"Commerce",                    {1323.90,-1722.20,-89.00,1440.90,-1577.50,110.90}},
	{"Commerce",                    {1370.80,-1577.50,-89.00,1463.90,-1384.90,110.90}},
	{"Commerce",                    {1463.90,-1577.50,-89.00,1667.90,-1430.80,110.90}},
	{"Commerce",                    {1583.50,-1722.20,-89.00,1758.90,-1577.50,110.90}},
	{"Commerce",                    {1667.90,-1577.50,-89.00,1812.60,-1430.80,110.90}},
	{"Conference Center",           {1046.10,-1804.20,-89.00,1323.90,-1722.20,110.90}},
	{"Conference Center",           {1073.20,-1842.20,-89.00,1323.90,-1804.20,110.90}},
	{"Cranberry Station",           {-2007.80,56.30,0.00,-1922.00,224.70,100.00}},
	{"Creek",                       {2749.90,1937.20,-89.00,2921.60,2669.70,110.90}},
	{"Dillimore",                   {580.70,-674.80,-9.50,861.00,-404.70,200.00}},
	{"Doherty",                     {-2270.00,-324.10,-0.00,-1794.90,-222.50,200.00}},
	{"Doherty",                     {-2173.00,-222.50,-0.00,-1794.90,265.20,200.00}},
	{"Downtown",                    {-1982.30,744.10,-6.10,-1871.70,1274.20,200.00}},
	{"Downtown",                    {-1871.70,1176.40,-4.50,-1620.30,1274.20,200.00}},
	{"Downtown",                    {-1700.00,744.20,-6.10,-1580.00,1176.50,200.00}},
	{"Downtown",                    {-1580.00,744.20,-6.10,-1499.80,1025.90,200.00}},
	{"Downtown",                    {-2078.60,578.30,-7.60,-1499.80,744.20,200.00}},
	{"Downtown",                    {-1993.20,265.20,-9.10,-1794.90,578.30,200.00}},
	{"Downtown Los Santos",         {1463.90,-1430.80,-89.00,1724.70,-1290.80,110.90}},
	{"Downtown Los Santos",         {1724.70,-1430.80,-89.00,1812.60,-1250.90,110.90}},
	{"Downtown Los Santos",         {1463.90,-1290.80,-89.00,1724.70,-1150.80,110.90}},
	{"Downtown Los Santos",         {1370.80,-1384.90,-89.00,1463.90,-1170.80,110.90}},
	{"Downtown Los Santos",         {1724.70,-1250.90,-89.00,1812.60,-1150.80,110.90}},
	{"Downtown Los Santos",         {1370.80,-1170.80,-89.00,1463.90,-1130.80,110.90}},
	{"Downtown Los Santos",         {1378.30,-1130.80,-89.00,1463.90,-1026.30,110.90}},
	{"Downtown Los Santos",         {1391.00,-1026.30,-89.00,1463.90,-926.90,110.90}},
	{"Downtown Los Santos",         {1507.50,-1385.20,110.90,1582.50,-1325.30,335.90}},
	{"East Beach",                  {2632.80,-1852.80,-89.00,2959.30,-1668.10,110.90}},
	{"East Beach",                  {2632.80,-1668.10,-89.00,2747.70,-1393.40,110.90}},
	{"East Beach",                  {2747.70,-1668.10,-89.00,2959.30,-1498.60,110.90}},
	{"East Beach",                  {2747.70,-1498.60,-89.00,2959.30,-1120.00,110.90}},
	{"East Los Santos",             {2421.00,-1628.50,-89.00,2632.80,-1454.30,110.90}},
	{"East Los Santos",             {2222.50,-1628.50,-89.00,2421.00,-1494.00,110.90}},
	{"East Los Santos",             {2266.20,-1494.00,-89.00,2381.60,-1372.00,110.90}},
	{"East Los Santos",             {2381.60,-1494.00,-89.00,2421.00,-1454.30,110.90}},
	{"East Los Santos",             {2281.40,-1372.00,-89.00,2381.60,-1135.00,110.90}},
	{"East Los Santos",             {2381.60,-1454.30,-89.00,2462.10,-1135.00,110.90}},
	{"East Los Santos",             {2462.10,-1454.30,-89.00,2581.70,-1135.00,110.90}},
	{"Easter Basin",                {-1794.90,249.90,-9.10,-1242.90,578.30,200.00}},
	{"Easter Basin",                {-1794.90,-50.00,-0.00,-1499.80,249.90,200.00}},
	{"Easter Bay Airport",          {-1499.80,-50.00,-0.00,-1242.90,249.90,200.00}},
	{"Easter Bay Airport",          {-1794.90,-730.10,-3.00,-1213.90,-50.00,200.00}},
	{"Easter Bay Airport",          {-1213.90,-730.10,0.00,-1132.80,-50.00,200.00}},
	{"Easter Bay Airport",          {-1242.90,-50.00,0.00,-1213.90,578.30,200.00}},
	{"Easter Bay Airport",          {-1213.90,-50.00,-4.50,-947.90,578.30,200.00}},
	{"Easter Bay Airport",          {-1315.40,-405.30,15.40,-1264.40,-209.50,25.40}},
	{"Easter Bay Airport",          {-1354.30,-287.30,15.40,-1315.40,-209.50,25.40}},
	{"Easter Bay Airport",          {-1490.30,-209.50,15.40,-1264.40,-148.30,25.40}},
	{"Easter Bay Chemicals",        {-1132.80,-768.00,0.00,-956.40,-578.10,200.00}},
	{"Easter Bay Chemicals",        {-1132.80,-787.30,0.00,-956.40,-768.00,200.00}},
	{"El Castillo del Diablo",      {-464.50,2217.60,0.00,-208.50,2580.30,200.00}},
	{"El Castillo del Diablo",      {-208.50,2123.00,-7.60,114.00,2337.10,200.00}},
	{"El Castillo del Diablo",      {-208.50,2337.10,0.00,8.40,2487.10,200.00}},
	{"El Corona",                   {1812.60,-2179.20,-89.00,1970.60,-1852.80,110.90}},
	{"El Corona",                   {1692.60,-2179.20,-89.00,1812.60,-1842.20,110.90}},
	{"El Quebrados",                {-1645.20,2498.50,0.00,-1372.10,2777.80,200.00}},
	{"Esplanade East",              {-1620.30,1176.50,-4.50,-1580.00,1274.20,200.00}},
	{"Esplanade East",              {-1580.00,1025.90,-6.10,-1499.80,1274.20,200.00}},
	{"Esplanade East",              {-1499.80,578.30,-79.60,-1339.80,1274.20,20.30}},
	{"Esplanade North",             {-2533.00,1358.90,-4.50,-1996.60,1501.20,200.00}},
	{"Esplanade North",             {-1996.60,1358.90,-4.50,-1524.20,1592.50,200.00}},
	{"Esplanade North",             {-1982.30,1274.20,-4.50,-1524.20,1358.90,200.00}},
	{"Fallen Tree",                 {-792.20,-698.50,-5.30,-452.40,-380.00,200.00}},
	{"Fallow Bridge",               {434.30,366.50,0.00,603.00,555.60,200.00}},
	{"Fern Ridge",                  {508.10,-139.20,0.00,1306.60,119.50,200.00}},
	{"Financial",                   {-1871.70,744.10,-6.10,-1701.30,1176.40,300.00}},
	{"Fisher's Lagoon",             {1916.90,-233.30,-100.00,2131.70,13.80,200.00}},
	{"Flint Intersection",          {-187.70,-1596.70,-89.00,17.00,-1276.60,110.90}},
	{"Flint Range",                 {-594.10,-1648.50,0.00,-187.70,-1276.60,200.00}},
	{"Fort Carson",                 {-376.20,826.30,-3.00,123.70,1220.40,200.00}},
	{"Foster Valley",               {-2270.00,-430.20,-0.00,-2178.60,-324.10,200.00}},
	{"Foster Valley",               {-2178.60,-599.80,-0.00,-1794.90,-324.10,200.00}},
	{"Foster Valley",               {-2178.60,-1115.50,0.00,-1794.90,-599.80,200.00}},
	{"Foster Valley",               {-2178.60,-1250.90,0.00,-1794.90,-1115.50,200.00}},
	{"Frederick Bridge",            {2759.20,296.50,0.00,2774.20,594.70,200.00}},
	{"Gant Bridge",                 {-2741.40,1659.60,-6.10,-2616.40,2175.10,200.00}},
	{"Gant Bridge",                 {-2741.00,1490.40,-6.10,-2616.40,1659.60,200.00}},
	{"Ganton",                      {2222.50,-1852.80,-89.00,2632.80,-1722.30,110.90}},
	{"Ganton",                      {2222.50,-1722.30,-89.00,2632.80,-1628.50,110.90}},
	{"Garcia",                      {-2411.20,-222.50,-0.00,-2173.00,265.20,200.00}},
	{"Garcia",                      {-2395.10,-222.50,-5.30,-2354.00,-204.70,200.00}},
	{"Garver Bridge",               {-1339.80,828.10,-89.00,-1213.90,1057.00,110.90}},
	{"Garver Bridge",               {-1213.90,950.00,-89.00,-1087.90,1178.90,110.90}},
	{"Garver Bridge",               {-1499.80,696.40,-179.60,-1339.80,925.30,20.30}},
	{"Glen Park",                   {1812.60,-1449.60,-89.00,1996.90,-1350.70,110.90}},
	{"Glen Park",                   {1812.60,-1100.80,-89.00,1994.30,-973.30,110.90}},
	{"Glen Park",                   {1812.60,-1350.70,-89.00,2056.80,-1100.80,110.90}},
	{"Green Palms",                 {176.50,1305.40,-3.00,338.60,1520.70,200.00}},
	{"Greenglass College",          {964.30,1044.60,-89.00,1197.30,1203.20,110.90}},
	{"Greenglass College",          {964.30,930.80,-89.00,1166.50,1044.60,110.90}},
	{"Hampton Barns",               {603.00,264.30,0.00,761.90,366.50,200.00}},
	{"Hankypanky Point",            {2576.90,62.10,0.00,2759.20,385.50,200.00}},
	{"Harry Gold Parkway",          {1777.30,863.20,-89.00,1817.30,2342.80,110.90}},
	{"Hashbury",                    {-2593.40,-222.50,-0.00,-2411.20,54.70,200.00}},
	{"Hilltop Farm",                {967.30,-450.30,-3.00,1176.70,-217.90,200.00}},
	{"Hunter Quarry",               {337.20,710.80,-115.20,860.50,1031.70,203.70}},
	{"Idlewood",                    {1812.60,-1852.80,-89.00,1971.60,-1742.30,110.90}},
	{"Idlewood",                    {1812.60,-1742.30,-89.00,1951.60,-1602.30,110.90}},
	{"Idlewood",                    {1951.60,-1742.30,-89.00,2124.60,-1602.30,110.90}},
	{"Idlewood",                    {1812.60,-1602.30,-89.00,2124.60,-1449.60,110.90}},
	{"Idlewood",                    {2124.60,-1742.30,-89.00,2222.50,-1494.00,110.90}},
	{"Idlewood",                    {1971.60,-1852.80,-89.00,2222.50,-1742.30,110.90}},
	{"Jefferson",                   {1996.90,-1449.60,-89.00,2056.80,-1350.70,110.90}},
	{"Jefferson",                   {2124.60,-1494.00,-89.00,2266.20,-1449.60,110.90}},
	{"Jefferson",                   {2056.80,-1372.00,-89.00,2281.40,-1210.70,110.90}},
	{"Jefferson",                   {2056.80,-1210.70,-89.00,2185.30,-1126.30,110.90}},
	{"Jefferson",                   {2185.30,-1210.70,-89.00,2281.40,-1154.50,110.90}},
	{"Jefferson",                   {2056.80,-1449.60,-89.00,2266.20,-1372.00,110.90}},
	{"Julius Thruway East",         {2623.10,943.20,-89.00,2749.90,1055.90,110.90}},
	{"Julius Thruway East",         {2685.10,1055.90,-89.00,2749.90,2626.50,110.90}},
	{"Julius Thruway East",         {2536.40,2442.50,-89.00,2685.10,2542.50,110.90}},
	{"Julius Thruway East",         {2625.10,2202.70,-89.00,2685.10,2442.50,110.90}},
	{"Julius Thruway North",        {2498.20,2542.50,-89.00,2685.10,2626.50,110.90}},
	{"Julius Thruway North",        {2237.40,2542.50,-89.00,2498.20,2663.10,110.90}},
	{"Julius Thruway North",        {2121.40,2508.20,-89.00,2237.40,2663.10,110.90}},
	{"Julius Thruway North",        {1938.80,2508.20,-89.00,2121.40,2624.20,110.90}},
	{"Julius Thruway North",        {1534.50,2433.20,-89.00,1848.40,2583.20,110.90}},
	{"Julius Thruway North",        {1848.40,2478.40,-89.00,1938.80,2553.40,110.90}},
	{"Julius Thruway North",        {1704.50,2342.80,-89.00,1848.40,2433.20,110.90}},
	{"Julius Thruway North",        {1377.30,2433.20,-89.00,1534.50,2507.20,110.90}},
	{"Julius Thruway South",        {1457.30,823.20,-89.00,2377.30,863.20,110.90}},
	{"Julius Thruway South",        {2377.30,788.80,-89.00,2537.30,897.90,110.90}},
	{"Julius Thruway West",         {1197.30,1163.30,-89.00,1236.60,2243.20,110.90}},
	{"Julius Thruway West",         {1236.60,2142.80,-89.00,1297.40,2243.20,110.90}},
	{"Juniper Hill",                {-2533.00,578.30,-7.60,-2274.10,968.30,200.00}},
	{"Juniper Hollow",              {-2533.00,968.30,-6.10,-2274.10,1358.90,200.00}},
	{"K.A.C.C. Military Fuels",     {2498.20,2626.50,-89.00,2749.90,2861.50,110.90}},
	{"Kincaid Bridge",              {-1339.80,599.20,-89.00,-1213.90,828.10,110.90}},
	{"Kincaid Bridge",              {-1213.90,721.10,-89.00,-1087.90,950.00,110.90}},
	{"Kincaid Bridge",              {-1087.90,855.30,-89.00,-961.90,986.20,110.90}},
	{"King's",                      {-2329.30,458.40,-7.60,-1993.20,578.30,200.00}},
	{"King's",                      {-2411.20,265.20,-9.10,-1993.20,373.50,200.00}},
	{"King's",                      {-2253.50,373.50,-9.10,-1993.20,458.40,200.00}},
	{"LVA Freight Depot",           {1457.30,863.20,-89.00,1777.40,1143.20,110.90}},
	{"LVA Freight Depot",           {1375.60,919.40,-89.00,1457.30,1203.20,110.90}},
	{"LVA Freight Depot",           {1277.00,1087.60,-89.00,1375.60,1203.20,110.90}},
	{"LVA Freight Depot",           {1315.30,1044.60,-89.00,1375.60,1087.60,110.90}},
	{"LVA Freight Depot",           {1236.60,1163.40,-89.00,1277.00,1203.20,110.90}},
	{"Las Barrancas",               {-926.10,1398.70,-3.00,-719.20,1634.60,200.00}},
	{"Las Brujas",                  {-365.10,2123.00,-3.00,-208.50,2217.60,200.00}},
	{"Las Colinas",                 {1994.30,-1100.80,-89.00,2056.80,-920.80,110.90}},
	{"Las Colinas",                 {2056.80,-1126.30,-89.00,2126.80,-920.80,110.90}},
	{"Las Colinas",                 {2185.30,-1154.50,-89.00,2281.40,-934.40,110.90}},
	{"Las Colinas",                 {2126.80,-1126.30,-89.00,2185.30,-934.40,110.90}},
	{"Las Colinas",                 {2747.70,-1120.00,-89.00,2959.30,-945.00,110.90}},
	{"Las Colinas",                 {2632.70,-1135.00,-89.00,2747.70,-945.00,110.90}},
	{"Las Colinas",                 {2281.40,-1135.00,-89.00,2632.70,-945.00,110.90}},
	{"Las Payasadas",               {-354.30,2580.30,2.00,-133.60,2816.80,200.00}},
	{"Las Venturas Airport",        {1236.60,1203.20,-89.00,1457.30,1883.10,110.90}},
	{"Las Venturas Airport",        {1457.30,1203.20,-89.00,1777.30,1883.10,110.90}},
	{"Las Venturas Airport",        {1457.30,1143.20,-89.00,1777.40,1203.20,110.90}},
	{"Las Venturas Airport",        {1515.80,1586.40,-12.50,1729.90,1714.50,87.50}},
	{"Last Dime Motel",             {1823.00,596.30,-89.00,1997.20,823.20,110.90}},
	{"Leafy Hollow",                {-1166.90,-1856.00,0.00,-815.60,-1602.00,200.00}},
	{"Liberty City",                {-1000.00,400.00,1300.00,-700.00,600.00,1400.00}},
	{"Lil' Probe Inn",              {-90.20,1286.80,-3.00,153.80,1554.10,200.00}},
	{"Linden Side",                 {2749.90,943.20,-89.00,2923.30,1198.90,110.90}},
	{"Linden Station",              {2749.90,1198.90,-89.00,2923.30,1548.90,110.90}},
	{"Linden Station",              {2811.20,1229.50,-39.50,2861.20,1407.50,60.40}},
	{"Little Mexico",               {1701.90,-1842.20,-89.00,1812.60,-1722.20,110.90}},
	{"Little Mexico",               {1758.90,-1722.20,-89.00,1812.60,-1577.50,110.90}},
	{"Los Flores",                  {2581.70,-1454.30,-89.00,2632.80,-1393.40,110.90}},
	{"Los Flores",                  {2581.70,-1393.40,-89.00,2747.70,-1135.00,110.90}},
	{"Los Santos International",    {1249.60,-2394.30,-89.00,1852.00,-2179.20,110.90}},
	{"Los Santos International",    {1852.00,-2394.30,-89.00,2089.00,-2179.20,110.90}},
	{"Los Santos International",    {1382.70,-2730.80,-89.00,2201.80,-2394.30,110.90}},
	{"Los Santos International",    {1974.60,-2394.30,-39.00,2089.00,-2256.50,60.90}},
	{"Los Santos International",    {1400.90,-2669.20,-39.00,2189.80,-2597.20,60.90}},
	{"Los Santos International",    {2051.60,-2597.20,-39.00,2152.40,-2394.30,60.90}},
	{"Marina",                      {647.70,-1804.20,-89.00,851.40,-1577.50,110.90}},
	{"Marina",                      {647.70,-1577.50,-89.00,807.90,-1416.20,110.90}},
	{"Marina",                      {807.90,-1577.50,-89.00,926.90,-1416.20,110.90}},
	{"Market",              	{787.40,-1416.20,-89.00,1072.60,-1310.20,110.90}},
	{"Market",                      {952.60,-1310.20,-89.00,1072.60,-1130.80,110.90}},
	{"Market",                      {1072.60,-1416.20,-89.00,1370.80,-1130.80,110.90}},
	{"Market",                      {926.90,-1577.50,-89.00,1370.80,-1416.20,110.90}},
	{"Market Station",              {787.40,-1410.90,-34.10,866.00,-1310.20,65.80}},
	{"Martin Bridge",               {-222.10,293.30,0.00,-122.10,476.40,200.00}},
	{"Missionary Hill",             {-2994.40,-811.20,0.00,-2178.60,-430.20,200.00}},
	{"Montgomery",                  {1119.50,119.50,-3.00,1451.40,493.30,200.00}},
	{"Montgomery",                  {1451.40,347.40,-6.10,1582.40,420.80,200.00}},
	{"Montgomery Intersection",     {1546.60,208.10,0.00,1745.80,347.40,200.00}},
	{"Montgomery Intersection",     {1582.40,347.40,0.00,1664.60,401.70,200.00}},
	{"Mulholland",                  {1414.00,-768.00,-89.00,1667.60,-452.40,110.90}},
	{"Mulholland",                  {1281.10,-452.40,-89.00,1641.10,-290.90,110.90}},
	{"Mulholland",                  {1269.10,-768.00,-89.00,1414.00,-452.40,110.90}},
	{"Mulholland",                  {1357.00,-926.90,-89.00,1463.90,-768.00,110.90}},
	{"Mulholland",                  {1318.10,-910.10,-89.00,1357.00,-768.00,110.90}},
	{"Mulholland",                  {1169.10,-910.10,-89.00,1318.10,-768.00,110.90}},
	{"Mulholland",                  {768.60,-954.60,-89.00,952.60,-860.60,110.90}},
	{"Mulholland",                  {687.80,-860.60,-89.00,911.80,-768.00,110.90}},
	{"Mulholland",                  {737.50,-768.00,-89.00,1142.20,-674.80,110.90}},
	{"Mulholland",                  {1096.40,-910.10,-89.00,1169.10,-768.00,110.90}},
	{"Mulholland",                  {952.60,-937.10,-89.00,1096.40,-860.60,110.90}},
	{"Mulholland",                  {911.80,-860.60,-89.00,1096.40,-768.00,110.90}},
	{"Mulholland",                  {861.00,-674.80,-89.00,1156.50,-600.80,110.90}},
	{"Mulholland Intersection",     {1463.90,-1150.80,-89.00,1812.60,-768.00,110.90}},
	{"North Rock",                  {2285.30,-768.00,0.00,2770.50,-269.70,200.00}},
	{"Ocean Docks",                 {2373.70,-2697.00,-89.00,2809.20,-2330.40,110.90}},
	{"Ocean Docks",                 {2201.80,-2418.30,-89.00,2324.00,-2095.00,110.90}},
	{"Ocean Docks",                 {2324.00,-2302.30,-89.00,2703.50,-2145.10,110.90}},
	{"Ocean Docks",                 {2089.00,-2394.30,-89.00,2201.80,-2235.80,110.90}},
	{"Ocean Docks",                 {2201.80,-2730.80,-89.00,2324.00,-2418.30,110.90}},
	{"Ocean Docks",                 {2703.50,-2302.30,-89.00,2959.30,-2126.90,110.90}},
	{"Ocean Docks",                 {2324.00,-2145.10,-89.00,2703.50,-2059.20,110.90}},
	{"Ocean Flats",                 {-2994.40,277.40,-9.10,-2867.80,458.40,200.00}},
	{"Ocean Flats",                 {-2994.40,-222.50,-0.00,-2593.40,277.40,200.00}},
	{"Ocean Flats",                 {-2994.40,-430.20,-0.00,-2831.80,-222.50,200.00}},
	{"Octane Springs",              {338.60,1228.50,0.00,664.30,1655.00,200.00}},
	{"Old Venturas Strip",          {2162.30,2012.10,-89.00,2685.10,2202.70,110.90}},
	{"Palisades",                   {-2994.40,458.40,-6.10,-2741.00,1339.60,200.00}},
	{"Palomino Creek",              {2160.20,-149.00,0.00,2576.90,228.30,200.00}},
	{"Paradiso",                    {-2741.00,793.40,-6.10,-2533.00,1268.40,200.00}},
	{"Pershing Square",             {1440.90,-1722.20,-89.00,1583.50,-1577.50,110.90}},
	{"Pilgrim",                     {2437.30,1383.20,-89.00,2624.40,1783.20,110.90}},
	{"Pilgrim",                     {2624.40,1383.20,-89.00,2685.10,1783.20,110.90}},
	{"Pilson Intersection",         {1098.30,2243.20,-89.00,1377.30,2507.20,110.90}},
	{"Pirates in Men's Pants",      {1817.30,1469.20,-89.00,2027.40,1703.20,110.90}},
	{"Playa del Seville",           {2703.50,-2126.90,-89.00,2959.30,-1852.80,110.90}},
	{"Prickle Pine",                {1534.50,2583.20,-89.00,1848.40,2863.20,110.90}},
	{"Prickle Pine",          	{1117.40,2507.20,-89.00,1534.50,2723.20,110.90}},
	{"Prickle Pine",         	{1848.40,2553.40,-89.00,1938.80,2863.20,110.90}},
	{"Prickle Pine",                {1938.80,2624.20,-89.00,2121.40,2861.50,110.90}},
	{"Queens",                      {-2533.00,458.40,0.00,-2329.30,578.30,200.00}},
	{"Queens",                      {-2593.40,54.70,0.00,-2411.20,458.40,200.00}},
	{"Queens",                      {-2411.20,373.50,0.00,-2253.50,458.40,200.00}},
	{"Randolph Industrial Estate",  {1558.00,596.30,-89.00,1823.00,823.20,110.90}},
	{"Redsands East",               {1817.30,2011.80,-89.00,2106.70,2202.70,110.90}},
	{"Redsands East",               {1817.30,2202.70,-89.00,2011.90,2342.80,110.90}},
	{"Redsands East",               {1848.40,2342.80,-89.00,2011.90,2478.40,110.90}},
	{"Redsands West",               {1236.60,1883.10,-89.00,1777.30,2142.80,110.90}},
	{"Redsands West",               {1297.40,2142.80,-89.00,1777.30,2243.20,110.90}},
	{"Redsands West",               {1377.30,2243.20,-89.00,1704.50,2433.20,110.90}},
	{"Redsands West",               {1704.50,2243.20,-89.00,1777.30,2342.80,110.90}},
	{"Regular Tom",                 {-405.70,1712.80,-3.00,-276.70,1892.70,200.00}},
	{"Richman",                     {647.50,-1118.20,-89.00,787.40,-954.60,110.90}},
	{"Richman",                     {647.50,-954.60,-89.00,768.60,-860.60,110.90}},
	{"Richman",                     {225.10,-1369.60,-89.00,334.50,-1292.00,110.90}},
	{"Richman",                     {225.10,-1292.00,-89.00,466.20,-1235.00,110.90}},
	{"Richman",                     {72.60,-1404.90,-89.00,225.10,-1235.00,110.90}},
	{"Richman",                     {72.60,-1235.00,-89.00,321.30,-1008.10,110.90}},
	{"Richman",                     {321.30,-1235.00,-89.00,647.50,-1044.00,110.90}},
	{"Richman",                     {321.30,-1044.00,-89.00,647.50,-860.60,110.90}},
	{"Richman",                     {321.30,-860.60,-89.00,687.80,-768.00,110.90}},
	{"Richman",                     {321.30,-768.00,-89.00,700.70,-674.80,110.90}},
	{"Robada Intersection",         {-1119.00,1178.90,-89.00,-862.00,1351.40,110.90}},
	{"Roca Escalante",              {2237.40,2202.70,-89.00,2536.40,2542.50,110.90}},
	{"Roca Escalante",              {2536.40,2202.70,-89.00,2625.10,2442.50,110.90}},
	{"Rockshore East",              {2537.30,676.50,-89.00,2902.30,943.20,110.90}},
	{"Rockshore West",              {1997.20,596.30,-89.00,2377.30,823.20,110.90}},
	{"Rockshore West",              {2377.30,596.30,-89.00,2537.30,788.80,110.90}},
	{"Rodeo",                       {72.60,-1684.60,-89.00,225.10,-1544.10,110.90}},
	{"Rodeo",                       {72.60,-1544.10,-89.00,225.10,-1404.90,110.90}},
	{"Rodeo",                       {225.10,-1684.60,-89.00,312.80,-1501.90,110.90}},
	{"Rodeo",                       {225.10,-1501.90,-89.00,334.50,-1369.60,110.90}},
	{"Rodeo",                       {334.50,-1501.90,-89.00,422.60,-1406.00,110.90}},
	{"Rodeo",                       {312.80,-1684.60,-89.00,422.60,-1501.90,110.90}},
	{"Rodeo",                       {422.60,-1684.60,-89.00,558.00,-1570.20,110.90}},
	{"Rodeo",                       {558.00,-1684.60,-89.00,647.50,-1384.90,110.90}},
	{"Rodeo",                       {466.20,-1570.20,-89.00,558.00,-1385.00,110.90}},
	{"Rodeo",                       {422.60,-1570.20,-89.00,466.20,-1406.00,110.90}},
	{"Rodeo",                       {466.20,-1385.00,-89.00,647.50,-1235.00,110.90}},
	{"Rodeo",                       {334.50,-1406.00,-89.00,466.20,-1292.00,110.90}},
	{"Royal Casino",                {2087.30,1383.20,-89.00,2437.30,1543.20,110.90}},
	{"San Andreas Sound",           {2450.30,385.50,-100.00,2759.20,562.30,200.00}},
	{"Santa Flora",                 {-2741.00,458.40,-7.60,-2533.00,793.40,200.00}},
	{"Santa Maria Beach",           {342.60,-2173.20,-89.00,647.70,-1684.60,110.90}},
	{"Santa Maria Beach",           {72.60,-2173.20,-89.00,342.60,-1684.60,110.90}},
	{"Shady Cabin",                 {-1632.80,-2263.40,-3.00,-1601.30,-2231.70,200.00}},
	{"Shady Creeks",                {-1820.60,-2643.60,-8.00,-1226.70,-1771.60,200.00}},
	{"Shady Creeks",                {-2030.10,-2174.80,-6.10,-1820.60,-1771.60,200.00}},
	{"Sobell Rail Yards",           {2749.90,1548.90,-89.00,2923.30,1937.20,110.90}},
	{"Spinybed",                    {2121.40,2663.10,-89.00,2498.20,2861.50,110.90}},
	{"Starfish Casino",             {2437.30,1783.20,-89.00,2685.10,2012.10,110.90}},
	{"Starfish Casino",             {2437.30,1858.10,-39.00,2495.00,1970.80,60.90}},
	{"Starfish Casino",             {2162.30,1883.20,-89.00,2437.30,2012.10,110.90}},
	{"Temple",                      {1252.30,-1130.80,-89.00,1378.30,-1026.30,110.90}},
	{"Temple",                      {1252.30,-1026.30,-89.00,1391.00,-926.90,110.90}},
	{"Temple",                      {1252.30,-926.90,-89.00,1357.00,-910.10,110.90}},
	{"Temple",                      {952.60,-1130.80,-89.00,1096.40,-937.10,110.90}},
	{"Temple",                      {1096.40,-1130.80,-89.00,1252.30,-1026.30,110.90}},
	{"Temple",                      {1096.40,-1026.30,-89.00,1252.30,-910.10,110.90}},
	{"The Camel's Toe",             {2087.30,1203.20,-89.00,2640.40,1383.20,110.90}},
	{"The Clown's Pocket",          {2162.30,1783.20,-89.00,2437.30,1883.20,110.90}},
	{"The Emerald Isle",            {2011.90,2202.70,-89.00,2237.40,2508.20,110.90}},
	{"The Farm",                    {-1209.60,-1317.10,114.90,-908.10,-787.30,251.90}},
	{"The Four Dragons Casino",     {1817.30,863.20,-89.00,2027.30,1083.20,110.90}},
	{"The High Roller",             {1817.30,1283.20,-89.00,2027.30,1469.20,110.90}},
	{"The Mako Span",               {1664.60,401.70,0.00,1785.10,567.20,200.00}},
	{"The Panopticon",              {-947.90,-304.30,-1.10,-319.60,327.00,200.00}},
	{"The Pink Swan",               {1817.30,1083.20,-89.00,2027.30,1283.20,110.90}},
	{"The Sherman Dam",             {-968.70,1929.40,-3.00,-481.10,2155.20,200.00}},
	{"The Strip",                   {2027.40,863.20,-89.00,2087.30,1703.20,110.90}},
	{"The Strip",                   {2106.70,1863.20,-89.00,2162.30,2202.70,110.90}},
	{"The Strip",                   {2027.40,1783.20,-89.00,2162.30,1863.20,110.90}},
	{"The Strip",                   {2027.40,1703.20,-89.00,2137.40,1783.20,110.90}},
	{"The Visage",                  {1817.30,1863.20,-89.00,2106.70,2011.80,110.90}},
	{"The Visage",                  {1817.30,1703.20,-89.00,2027.40,1863.20,110.90}},
	{"Unity Station",               {1692.60,-1971.80,-20.40,1812.60,-1932.80,79.50}},
	{"Valle Ocultado",              {-936.60,2611.40,2.00,-715.90,2847.90,200.00}},
	{"Verdant Bluffs",              {930.20,-2488.40,-89.00,1249.60,-2006.70,110.90}},
	{"Verdant Bluffs",              {1073.20,-2006.70,-89.00,1249.60,-1842.20,110.90}},
	{"Verdant Bluffs",              {1249.60,-2179.20,-89.00,1692.60,-1842.20,110.90}},
	{"Verdant Meadows",             {37.00,2337.10,-3.00,435.90,2677.90,200.00}},
	{"Verona Beach",                {647.70,-2173.20,-89.00,930.20,-1804.20,110.90}},
	{"Verona Beach",                {930.20,-2006.70,-89.00,1073.20,-1804.20,110.90}},
	{"Verona Beach",                {851.40,-1804.20,-89.00,1046.10,-1577.50,110.90}},
	{"Verona Beach",                {1161.50,-1722.20,-89.00,1323.90,-1577.50,110.90}},
	{"Verona Beach",                {1046.10,-1722.20,-89.00,1161.50,-1577.50,110.90}},
	{"Vinewood",                    {787.40,-1310.20,-89.00,952.60,-1130.80,110.90}},
	{"Vinewood",                    {787.40,-1130.80,-89.00,952.60,-954.60,110.90}},
	{"Vinewood",                    {647.50,-1227.20,-89.00,787.40,-1118.20,110.90}},
	{"Vinewood",                    {647.70,-1416.20,-89.00,787.40,-1227.20,110.90}},
	{"Whitewood Estates",           {883.30,1726.20,-89.00,1098.30,2507.20,110.90}},
	{"Whitewood Estates",           {1098.30,1726.20,-89.00,1197.30,2243.20,110.90}},
	{"Willowfield",                 {1970.60,-2179.20,-89.00,2089.00,-1852.80,110.90}},
	{"Willowfield",                 {2089.00,-2235.80,-89.00,2201.80,-1989.90,110.90}},
	{"Willowfield",                 {2089.00,-1989.90,-89.00,2324.00,-1852.80,110.90}},
	{"Willowfield",                 {2201.80,-2095.00,-89.00,2324.00,-1989.90,110.90}},
	{"Willowfield",                 {2541.70,-1941.40,-89.00,2703.50,-1852.80,110.90}},
	{"Willowfield",                 {2324.00,-2059.20,-89.00,2541.70,-1852.80,110.90}},
	{"Willowfield",                 {2541.70,-2059.20,-89.00,2703.50,-1941.40,110.90}},
	{"Yellow Bell Station",         {1377.40,2600.40,-21.90,1492.40,2687.30,78.00}},
	// Main Zones
	{"Los Santos",                  {44.60,-2892.90,-242.90,2997.00,-768.00,900.00}},
	{"Las Venturas",                {869.40,596.30,-242.90,2997.00,2993.80,900.00}},
	{"Bone County",                 {-480.50,596.30,-242.90,869.40,2993.80,900.00}},
	{"Tierra Robada",               {-2997.40,1659.60,-242.90,-480.50,2993.80,900.00}},
	{"Tierra Robada",               {-1213.90,596.30,-242.90,-480.50,1659.60,900.00}},
	{"San Fierro",                  {-2997.40,-1115.50,-242.90,-1213.90,1659.60,900.00}},
	{"Red County",                  {-1213.90,-768.00,-242.90,2997.00,596.30,900.00}},
	{"Flint County",                {-1213.90,-2892.90,-242.90,44.60,-768.00,900.00}},
	{"Whetstone",                   {-2997.40,-2892.90,-242.90,-1213.90,-1115.50,900.00}}
};

//==============================================================================

forward GreekCnR();
forward ConfigGreekCnR();
forward SaveGreekCnRVars();
forward LoadBadWords();
forward LoadForbiddenWeapons();
forward JB_Kick(playerid,reason[]);
forward JB_Ban(playerid,reason[]);
forward JB_GivePlayerMoney(playerid,amount);
forward JB_GetPlayerMoney(playerid);
forward JB_SetPlayerMoney(playerid,amount);
forward JB_ResetPlayerMoney(playerid);
forward JB_PutPlayerInVehicle(playerid,vehicleid,seatid);
forward JB_GivePlayerWeapon(playerid,weaponid,ammo);
forward JB_SetPlayerPos(playerid,Float:x,Float:y,Float:z);
forward JB_SetVehiclePos(vehicleid,Float:x,Float:y,Float:z);
forward JB_SetPlayerHealth(playerid,Float:health);
forward JB_SetPlayerArmour(playerid,Float:armour);
forward JB_TogglePlayerControllable(playerid,toggle);
forward JB_SetVehicleVelocity(vehicleid,Float:x,Float:y,Float:z);
forward JB_SetPlayerSpecialAction(playerid,actionid);
forward MutePlayer(playerid,time,reason[]);
forward LoadBlacklist();
forward UpdateBlacklist();
forward AddNameToBlacklist(name[]);
forward RemoveNameFromBlacklist(name[]);
forward AddPlayerToBlacklist(playerid);
forward LoadWhitelist();
forward UpdateWhitelist();
forward AddNameToWhitelist(name[]);
forward RemoveNameFromWhitelist(name[]);
forward AddPlayerToWhitelist(playerid);
forward TempBan(playerid,hours,reason[]);
forward DeleteTempBan(name[]);
forward LoadTempBans();
forward SaveTempBans();
forward TempBanUpdate();
forward LoadIpBans();
forward SaveIpBans();
forward BanIp(ip_string[]);
forward UnbanIp(ip_string[]);
forward SetPlayerSpawnKillProtected(playerid,set);
forward GlobalUpdate();
forward SpamUpdate();
forward IsPlayerAdminCall(playerid);

//Plug & Play:
forward PnP_OnPlayerStateChange(playerid, newstate, oldstate);
forward PnP_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
forward PnP_OnPlayerCommandText(playerid, cmdtext[]);
forward PnP_OnPlayerText(playerid, text[]);
forward PnP_OnPlayerConnect(playerid);
forward PnP_OnPlayerDisconnect(playerid,reason);
forward PnP_OnGameModeInit();
forward PnP_OnGameModeExit();
forward PnP_OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid);
forward PnP_OnPlayerDeath(playerid,killerid,reason);
forward PnP_OnPlayerSpawn(playerid);
forward PnP_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
forward PnP_OnRconLoginAttempt( ip[], password[], success );

//==============================================================================

public JB_SetVehicleVelocity(vehicleid,Float:x,Float:y,Float:z)
{
	if(vehicleid!=INVALID_VEHICLE_ID)
	{
	    new tspeed=JB_Speed(x,y,z,110.0);
		if(JB_Variables[MAX_SPEED] && tspeed>JB_Variables[MAX_SPEED])
		{
		    JB_LogEx("Could not set velocity for vehicle %d because max speed is %d KM/H. (%d KM/H blocked)",vehicleid,JB_Variables[MAX_SPEED],tspeed);
		    return 0;
		}
		return SetVehicleVelocity(vehicleid,x,y,z);
	}
	return 0;
}

public JB_SetPlayerSpecialAction(playerid,actionid)
{
	if(IsPlayerConnected(playerid))
	{
	    if(actionid==SPECIAL_ACTION_USEJETPACK && JB_Variables[JETPACK] && (!JB_IsPlayerAdmin(playerid) || !JB_Variables[ADMIN_IMMUNITY]))
	    {
	        JB_LogEx("Could not give '%s' a jetpack because it's forbidden.",ReturnPlayerName(playerid));
	        return 0;
	    }
	    
	    return SetPlayerSpecialAction(playerid,actionid);
	}
	return 0;
}

public JB_PutPlayerInVehicle(playerid,vehicleid,seatid)
{
	if(IsPlayerConnected(playerid) && vehicleid!=INVALID_VEHICLE_ID)
	{
	    if(PutPlayerInVehicle(playerid,vehicleid,seatid))
	    {
	        NoTeleportCheck[playerid]=3;
	    	JB_PlayerInfo[playerid][JB_pVehicleEntered]=vehicleid;
  			return 1;
		}
	}
	return 0;
}

public JB_GivePlayerMoney(playerid,amount)
{
	if(IsPlayerConnected(playerid))
	{
	    GivePlayerMoney(playerid,amount);
	    JB_PlayerInfo[playerid][JB_pMoney]+=amount;
	    return 1;
	}
	return 0;
}

public JB_ResetPlayerMoney(playerid)
{
	if(IsPlayerConnected(playerid))
	{
	    ResetPlayerMoney(playerid);
	    JB_PlayerInfo[playerid][JB_pMoney]=0;
	    return 1;
	}
	return 0;
}

public JB_GetPlayerMoney(playerid)
{
	new amount;
	if(IsPlayerConnected(playerid))
	{
	    if(!JB_Variables[MONEY_HACK] || GetPlayerMoney(playerid)<JB_PlayerInfo[playerid][JB_pMoney])
	        amount=GetPlayerMoney(playerid);
		else
		    amount=JB_PlayerInfo[playerid][JB_pMoney];
	}
	return amount;
}

public JB_SetPlayerMoney(playerid,amount)
{
	if(IsPlayerConnected(playerid))
	{
	    ResetPlayerMoney(playerid);
	    GivePlayerMoney(playerid,amount);
	    JB_PlayerInfo[playerid][JB_pMoney]=amount;
	    return 1;
	}
	return 0;
}

public JB_SetPlayerPos(playerid,Float:x,Float:y,Float:z)
{
	if(IsPlayerConnected(playerid))
	{
	    if(SetPlayerPos(playerid,x,y,z))
	    {
	        CurrentPos[playerid][0]=x;
	        CurrentPos[playerid][1]=y;
	        CurrentPos[playerid][2]=z;
	        NoTeleportCheck[playerid]=3;//Do not check position for 3 seconds to prevent lag kick.
	        return 1;
	    }
	}
	return 0;
}

public JB_SetVehiclePos(vehicleid,Float:x,Float:y,Float:z)
{
	if(vehicleid!=INVALID_VEHICLE_ID)
	{
	    if(SetVehiclePos(vehicleid,x,y,z))
	    {
			for(new i=0;i<MAX_PLAYERS;i++)
			{
			    if(IsPlayerConnected(i) && GetPlayerVehicleID(i)==vehicleid)
			    {
			        CurrentPos[i][0]=x;
			        CurrentPos[i][1]=y;
			        CurrentPos[i][2]=z;
			        NoTeleportCheck[i]=4;//Do not check position for 4 seconds to prevent lag kick.
			    }
			}
			return 1;
		}
	}
	return 0;
}

public JB_GivePlayerWeapon(playerid,weaponid,ammo)
{
	if(!IsForbiddenWeapon(weaponid) || (IsForbiddenWeapon(weaponid) && !WeaponForbiddenForPlayer[playerid][weaponid]) || (JB_IsPlayerAdmin(playerid) && JB_Variables[ADMIN_IMMUNITY]))
	{
	    GivePlayerWeapon(playerid,weaponid,ammo);
	    return 1;
	}
	new weapon[32];
	GetWeaponName(weaponid,weapon,sizeof(weapon));
	JB_LogEx("Could not give '%s' weapon %s (%d) because it is forbidden!",ReturnPlayerName(playerid),weapon,weaponid);
	return 0;
}

public JB_SetPlayerHealth(playerid,Float:health)
{
	new Float:tmp_health=health;
	if(tmp_health<0)
	    tmp_health=0;
	else if(tmp_health>100 && JB_Variables[HEALTH_HACK])
	    tmp_health=100;
	return SetPlayerHealth(playerid,tmp_health);
}

public JB_SetPlayerArmour(playerid,Float:armour)
{
	new Float:tmp_armour=armour;
	if(tmp_armour<0)
	    tmp_armour=0;
	else if(tmp_armour>100 && JB_Variables[ARMOUR_HACK])
	    tmp_armour=100;
	return SetPlayerArmour(playerid,tmp_armour);
}

public JB_TogglePlayerControllable(playerid,toggle)
{
 	if(toggle)
	    JB_PlayerInfo[playerid][JB_pFreezed]=false;
	else
	    JB_PlayerInfo[playerid][JB_pFreezed]=true;
	return TogglePlayerControllable(playerid,toggle);
}

public SetPlayerSpawnKillProtected(playerid,set)
{
	if(IsPlayerConnected(playerid))
	{
	    if(set)
	    	JB_PlayerInfo[playerid][JB_pSpawnKillProtected]=JB_Variables[SPAWN_TIME];
		else
            JB_PlayerInfo[playerid][JB_pSpawnKillProtected]=0;
	    return 1;
	}
	return 0;
}

//==============================================================================

public MutePlayer(playerid,time,reason[])//Time is seconds.
{
	if(IsPlayerConnected(playerid) && time)
	{
	    JB_PlayerInfo[playerid][JB_pMuted]=time;
	    JB_LogEx("%s has been muted for %d second(s) because of %s.",ReturnPlayerName(playerid),time,reason);
	    JB_SendFormattedMessageToAll(RED,"GreekCnR: Muting player '%s' (%d) for %d second(s). Reason: %s",ReturnPlayerName(playerid),playerid,time,reason);
	    return 1;
	}
	return 0;
}

public JB_Kick(playerid,reason[])
{
	if(IsPlayerConnected(playerid))
	{
	    new string[128];
	    format(string,sizeof(string),"~r~Kick notification:~n~%s",reason);
	    GameTextForPlayer(playerid,string,60000,4);

	    TogglePlayerControllable(playerid,false);
	    JB_SendFormattedMessageToAll(RED,"GreekCnR: Kicking player '%s'. Reason: %s",ReturnPlayerName(playerid),reason);
	    JB_LogEx("%s (%s) has been kicked for %s.",ReturnPlayerName(playerid),ReturnPlayerIp(playerid),reason);
	    Kick(playerid);
	    return 1;
	}
	return 0;
}

public JB_Ban(playerid,reason[])
{
	if(IsPlayerConnected(playerid))
	{
	    new string[128];
	    format(string,sizeof(string),"~r~Ban notification:~n~%s",reason);
	    GameTextForPlayer(playerid,string,60000,4);

	    TogglePlayerControllable(playerid,false);
	    JB_SendFormattedMessageToAll(RED,"GreekCnR: Banning player '%s'. Reason: %s",ReturnPlayerName(playerid),reason);
	    JB_LogEx("%s (%s) has been banned for %s.",ReturnPlayerName(playerid),ReturnPlayerIp(playerid),reason);
	    BanEx(playerid,reason);
	    return 1;
	}
	return 0;
}

stock JB_Log(log[])
{
    printf("[GreekCnR] %s",log);
	new string[256];
	format(string,sizeof(string),"%s | %s | %s\r\n",ReturnDate(),ReturnTime(),log);
	new File:f=fopen(JB_LOG_FILE,io_append);
	fwrite(f,string);
	return fclose(f);
}

//==============================================================================

stock IsCheatPosition(Float:x,Float:y,Float:z)
{
	for(new i=0;i<sizeof(CheatPositions);i++)
	    if(JB_GetSquareDistance(x,y,z,CheatPositions[i][0],CheatPositions[i][1],CheatPositions[i][2])<1.5)
	        return true;
	return false;
}

stock IsPlayerInPlane(playerid)
{
	new m=GetVehicleModel(GetPlayerVehicleID(playerid));
	for(new i=0;i<sizeof(Planes);i++)
	    if(m==Planes[i])
	        return true;
	return false;
}

stock IsPlayerInValidState(playerid)
{
	new pstate=GetPlayerState(playerid);
    if(pstate>0 && pstate<=6)
		return true;
	return false;
}

stock AdvertisementCheck(string[])
{
	if(JB_Variables[ADVERTISEMENT] && string[0])
	{
		if(!strfind(string,"www.",false) || !strfind(string,"http://",false) || !strfind(string,".com",false) || !strfind(string,".net",false)
			|| !strfind(string,".de",false) || !strfind(string,".org",false))
		    return true;

		new c=1,idx,tmp[32],ip[4];
		for(new i=0;i<strlen(string);i++)
		    if(string[i]==' ')
		        c++;

		for(new i=0;i<c;i++)
		{
		    idx=0;
		    tmp=JB_strtok(string,idx);
		    idx=0;
		    tmp=JB_strtok(tmp,idx,':');
			ip=Split(tmp);
			if(ip[0] && ip[1] && ip[2] && ip[3]) // We have found and IP :o
			    return true;
		}
	}
	return false;
}

stock BadWordsCheck(text[])
{
	/*
	    Example: The bad word is "noob". In BadWords.cfg it must be written as "nob".
	    This code will prevent this word in all form:
	    - "no.ob"
	    - "no     ob"
		- "nooooooooooooooooooob"
		- etc.
	*/
	new c,string[128];
	for(new i=0;i<strlen(text);i++)
	{
	    if((text[i]>='a' && text[i]<='z') || (text[i]>='A' && text[i]<='Z'))
		{
		    if(!c || (c && string[c-1]!=text[i]))
		    {
				string[c]=text[i];
				c++;
			}
		}
		if(c>=sizeof(string))
			break;
	}

	for(new i=0;i<BadWordsCount;i++)
	    if(strfind(string,BadWords[i],true)!=-1)
	        return true;
	return false;
}

stock CapsLockCheck(text[])
{
	new len=strlen(text);
	if(len>3)
	{
	    new c;
	    for(new i=0;i<len;i++)
	        if(text[i]>='A' && text[i]<='Z')
				c++;

		if(c)
			if(c>=len/4*3)
		    	return true;
	}
	return false;
}

stock IsForbiddenWeapon(weaponid)
{
	if(weaponid && JB_Variables[WEAPON_HACK])
	{
	    for(new i=0;i<ForbiddenWeaponsCount;i++)
	        if(ForbiddenWeapons[i]==weaponid)
	            return true;
	}
	return false;
}

stock ForbidWeaponForPlayer(playerid,weaponid,forbid)
{
	if(IsPlayerConnected(playerid))
	{
	    WeaponForbiddenForPlayer[playerid][weaponid]=forbid;
		return 1;
	}
	return 0;
}

stock ResetForbiddenWeaponsForPlayer(playerid) // Forbid like in configuration
{
	if(IsPlayerConnected(playerid))
	{
    	for(new i=0;i<MAX_WEAPONS;i++)
			ForbidWeaponForPlayer(playerid,i,false);

		for(new i=0;i<MAX_FORBIDDEN_WEAPONS;i++)
			ForbidWeaponForPlayer(playerid,ForbiddenWeapons[i],true);
		return 1;
	}
	return 0;
}

stock GreekCnRReport(playerid,report[],details[])
{
	if(IsPlayerConnected(playerid))
	{
		new string[128];
		format(string,sizeof(string),"GreekCnR: Suspected player with %s: %s (%d), %s.",report,ReturnPlayerName(playerid),playerid,details);
		for(new i=0;i<MAX_PLAYERS;i++)
		    if(IsPlayerConnected(i))
			    if(JB_IsPlayerAdmin(i) && i!=playerid)
			        SendClientMessage(i,RED,string);

		return JB_Log(string[12]);
	}
	return 0;
}

stock JB_IsPlayerAdmin(playerid)
	return (IsPlayerAdmin(playerid) || CallRemoteFunction("IsPlayerAdminCall","i",playerid));

/*
Put for example this into your gamemode (Godfather):

public IsPlayerAdminCall(playerid)
	return (PlayerInfo[playerid][pAdmin] >= 1);

You can link your admin system with GreekCnR,
if you use this function.
*/

//==============================================================================

public GlobalUpdate()
{
	for(new i=0;i<MAX_PLAYERS;i++)
	{
	    if(IsPlayerConnected(i))
	    {
	        /*
			This should prevent ban of innocents
			Example:
				Someone plays 3 hours and in this 3 hours, GreekCnR thinks 3 times (for example every hours) he
				is a speedhacker or some shit like this because for a short time he lags.
				And the innocent player will get banned. This function prevents moments like this - real cheaters
				will not use the speedhack or teleport cheats once in an hour.
				Speedhack also bans airbreakers. They will get banned soon if they airbreak.
			*/
	        if(JB_Warnings[i][TELEPORT_HACK])
	            JB_Warnings[i][TELEPORT_HACK]--;
	            
			if(JB_Warnings[i][MAX_SPEED])
			    JB_Warnings[i][MAX_SPEED]--;
	    }
	}
	return 1;
}

public SpamUpdate()
{
	for(new i=0;i<MAX_PLAYERS;i++)
	{
	    if(IsPlayerConnected(i))
	    {
			if(JB_PlayerInfo[i][JB_pMessages])
				JB_PlayerInfo[i][JB_pMessages]--;
			
            if(JB_PlayerInfo[i][JB_pCommands])
			    JB_PlayerInfo[i][JB_pCommands]--;
		}
	}
	return 1;
}

//==============================================================================
						/*   MAIN FUNCTION OF ANTI-CHEAT   */

public GreekCnR()
{
	new Float:health,Float:armour,var,reason[64];
	new Float:x,Float:y,Float:z;
	for(new i=0;i<MAX_PLAYERS;i++)
	{
	    if(!IsPlayerNPC(i) && FullyConnected[i] && GetPlayerPos(i,x,y,z))
	    {
	        if(JB_PlayerInfo[i][JB_pMuted])
	            JB_PlayerInfo[i][JB_pMuted]--;
	            
			if(JB_PlayerInfo[i][JB_pSpawnKillProtected])
			    JB_PlayerInfo[i][JB_pSpawnKillProtected]--;

			if(JB_Variables[MONEY_HACK])
			    if(GetPlayerMoney(i)>JB_PlayerInfo[i][JB_pMoney])
			        JB_SetPlayerMoney(i,JB_PlayerInfo[i][JB_pMoney]);

            if(JB_PlayerInfo[i][JB_pSpeedhacking]>=3)
			{
			    TogglePlayerControllable(i,true);
			    JB_PlayerInfo[i][JB_pSpeedhacking]=0;
			}

			if(JB_PlayerInfo[i][JB_pFreezed] && JB_Variables[FREEZE_UPDATE])//Prevent  that cheaters unfreeze themselves.
			    TogglePlayerControllable(i,false);

			if(IsPlayerInValidState(i) && (!JB_IsPlayerAdmin(i) || !JB_Variables[ADMIN_IMMUNITY]))
			{
			    if(!NoTeleportCheck[i])
			    {
			        if(JB_Variables[TELEPORT_HACK] && z<900 && CurrentPos[i][2]<900)//Prevent kick when entering buildings.
			        {
						if(JB_GetSquareDistance(x,y,z,CurrentPos[i][0],CurrentPos[i][1],CurrentPos[i][2])>(500*500) && GetPlayerState(i)!=PLAYER_STATE_PASSENGER && GetPlayerSurfingVehicleID(i)==INVALID_VEHICLE_ID)
						{
						    JB_Warnings[i][TELEPORT_HACK]++;
					        if(JB_Warnings[i][TELEPORT_HACK]>=3)
					        {
								JB_Kick(i,"Using teleport cheats [Code 1]");
								continue;
							}
							else if(JB_Variables[TELEPORT_HACK] && IsCheatPosition(x,y,z))
							{
							    JB_Ban(i,"Using teleport cheats [Code 2]");
								continue;
							}
							else
							{
							    JB_GetPlayer2DZone(i,reason,sizeof(reason));
							    GreekCnRReport(i,"teleport cheats",reason);
							}
						}
					}

					if(GetPlayerState(i)==PLAYER_STATE_DRIVER && JB_Variables[MAX_SPEED])
					{
					    var=JB_GetPlayerSpeed(i);
						if(var>JB_Variables[MAX_SPEED] && !IsPlayerInPlane(i))
						{
						    JB_PlayerInfo[i][JB_pSpeedhacking]++;
						    if(JB_PlayerInfo[i][JB_pSpeedhacking]==3)
							{
							    JB_Warnings[i][MAX_SPEED]++;
							    TogglePlayerControllable(i,false);
							    if(JB_Warnings[i][MAX_SPEED]<3)
							    {
								    format(reason,sizeof(reason),"%d KM/H with %s",var,GetVehicleName(GetPlayerVehicleID(i)));
								    GreekCnRReport(i,"speedhack",reason);
							    }
							    else
							    {
							        JB_Ban(i,"Speedhack");
							        continue;
							    }
							}
						}
						else
						    JB_PlayerInfo[i][JB_pSpeedhacking]=0;
					}
			    }
  				else
			  		NoTeleportCheck[i]--;

			    var=GetPlayerWeapon(i);
			    if(IsForbiddenWeapon(var) && WeaponForbiddenForPlayer[i][var])
			    {
					GetWeaponName(var,reason,sizeof(reason));
			        format(reason,sizeof(reason),"Using weapon cheats (%s)",reason);
					JB_Ban(i,reason);
			        continue;
			    }

			    if(GetPlayerSpecialAction(i)==SPECIAL_ACTION_USEJETPACK && JB_Variables[JETPACK])
			    {
					JB_Ban(i,"Using jetpack");
			        continue;
			    }

				if(JB_Variables[HEALTH_HACK])
				{
				    GetPlayerHealth(i,health);
				    if(health>100)
				    {
				        JB_Ban(i,"Health hack");
				        continue;
				    }
				}

				if(JB_Variables[ARMOUR_HACK])
				{
				    GetPlayerArmour(i,armour);
				    if(armour>100)
				    {
				        JB_Ban(i,"Armour hack");
				        continue;
				    }
				}
			}

			if(GetPlayerState(i) && (!JB_IsPlayerAdmin(i) || !JB_Variables[ADMIN_IMMUNITY]))
			{
				JB_PlayerInfo[i][JB_pPing][JB_PlayerInfo[i][JB_pPingCheckProgress]]=GetPlayerPing(i);
				JB_PlayerInfo[i][JB_pPingCheckProgress]++;
				if(JB_PlayerInfo[i][JB_pPingCheckProgress]==MAX_PING_CHECKS)
				{
				    if(JB_Variables[MAX_PING])
				    {
						var=0;
						for(new j=0;j<MAX_PING_CHECKS;j++)
						    var+=JB_PlayerInfo[i][JB_pPing][j];
						var/=MAX_PING_CHECKS;
						if(var>JB_Variables[MAX_PING])
						{
							format(reason,sizeof(reason),"Too high ping. [%d/%d]",var,JB_Variables[MAX_PING]);
							JB_Kick(i,reason);
							continue;
						}
				    }
				    JB_PlayerInfo[i][JB_pPingCheckProgress]=0;
				}
			}

			GetPlayerPos(i,CurrentPos[i][0],CurrentPos[i][1],CurrentPos[i][2]);
	    }
	}
	return 1;
}


//==============================================================================

stock Split(ip_string[])
{
	new ip[4],string[16];
	format(string,sizeof(string),ip_string);

	for(new i=0;i<strlen(string);i++)
		if(string[i]=='.')
		    string[i]=' ';

	new idx,tmp[32];
	for(new i=0;i<4;i++)
	{
	    tmp=JB_strtok(string,idx);
	    if(tmp[0]=='*')
	        ip[i]=-1;
		else
			ip[i]=strval(tmp);
	}
	return ip;
}

stock IpBanCheck(playerid)
{
	new ip[4];
	ip=Split(ReturnPlayerIp(playerid));
	for(new i=0;i<sizeof(IpBans);i++)
	    if(IpBanned[i])
			if(IsSameIpEx(IpBans[i],ip))
			    return 1;
	return 0;
}

stock IsSameIp(ip1[4],ip2[4])
{
 	for(new i=0;i<4;i++)
		if(ip1[i]!=ip2[i])
		    return 0;
	return 1;
}

stock IsSameIpEx(ip1[4],ip2[4])// Check for range-ban
{
	for(new i=0;i<4;i++)
		if(ip1[i]!=ip2[i] && ip1[i]!=-1 && ip2[i]!=-1)
		    return 0;
	return 1;
}


public BanIp(ip_string[])
{
    new ip[4];
	ip=Split(ip_string);
	for(new i=0;i<sizeof(IpBans);i++)
	{
	    if(!IpBanned[i])
	    {
			IpBanned[i]=true;
			IpBans[i]=ip;
			JB_LogEx("IP %s has been banned.",ip_string);

			for(new j=0;j<MAX_PLAYERS;j++)
			    if(IsPlayerConnected(j))
			        if(IsSameIpEx(ip,Split(ReturnPlayerIp(j))))
			            JB_Kick(j,"IP has been banned");
			return 1;
	    }
	}
	JB_LogEx("Could not ban IP %s!",ip_string);
	return 0;
}

public UnbanIp(ip_string[])
{
	new ip[4];
	ip=Split(ip_string);
	for(new i=0;i<sizeof(IpBans);i++)
	{
	    if(IsSameIp(IpBans[i],ip))
	    {
			IpBanned[i]=false;
			JB_LogEx("IP %s has been unbanned.",ip_string);
			return 1;
	    }
	}
	JB_LogEx("Could not unban IP %s!",ip_string);
	return 0;
}

public SaveIpBans()
{
 	fremove(IP_BAN_FILE);
	new File:f=fopen(IP_BAN_FILE, io_append),string[32];
	for(new i=0;i<sizeof(IpBans);i++)
	{
		if(IpBanned[i])
		{
		    string[0]=0;
			for(new j=0;j<4;j++)
			{
			    if(IpBans[i][j]==-1)
			        format(string,sizeof(string),"%s.*",string);
				else
				    format(string,sizeof(string),"%s.%d",string,IpBans[i][j]);
			}
			format(string,sizeof(string),"%s\r\n",string[1]);
			fwrite(f,string);
		}
	}
	fclose(f);
	return 1;
}

public LoadIpBans()
{
    if(dini_Exists(IP_BAN_FILE))
	{
	    for(new i=0;i<sizeof(IpBans);i++)
	        IpBanned[i]=false;

	    new File:f=fopen(IP_BAN_FILE, io_read),c,string[16];
	    while(fread(f,string,sizeof(string)) && c<sizeof(IpBans))
	    {
	        JB_StripNewLine(string);
	        if(strlen(string))
	        {
				IpBans[c]=Split(string);
				IpBanned[c]=true;
				c++;
			}
	    }
	    fclose(f);
		JB_LogEx("%d IP-bans have been loaded.",c);
	    return 1;
	}
	JB_Log("Could not load IP-bans!");
	return 0;
}

//==============================================================================

public LoadBlacklist()
{
	if(dini_Exists(BLACKLIST_FILE))
	{
	    for(new i=0;i<sizeof(Blacklist);i++)
	        Blacklist[i][0]=0;

	    new File:f=fopen(BLACKLIST_FILE, io_read),c,string[MAX_PLAYER_NAME];
	    while(fread(f,string,sizeof(string)) && c<sizeof(Blacklist))
	    {
	        JB_StripNewLine(string);
	        if(strlen(string))
	        {
	            Blacklist[c]=string;
	            c++;
	        }
	    }
	    fclose(f);
		JB_LogEx("%d blacklist entries have been loaded.",c);
	    return 1;
	}
	JB_Log("Could not load blacklist!");
	return 0;
}

public UpdateBlacklist()
{
	fremove(BLACKLIST_FILE);
	new string[MAX_PLAYER_NAME+2];
	new File:f=fopen(BLACKLIST_FILE,io_append);
	for(new i=0;i<sizeof(Blacklist);i++)
	{
	    if(Blacklist[i][0])
	    {
			format(string,sizeof(string),"%s\r\n",Blacklist[i]);
			fwrite(f,string);
		}
	}
	JB_Log("Blacklist has been updated.");
	return fclose(f);
}

public AddNameToBlacklist(name[])
{
	new success;
	for(new i=0;i<sizeof(Blacklist);i++)
	{
	    if(!Blacklist[i][0])
	    {
			format(Blacklist[i],MAX_PLAYER_NAME,name);
			success=true;
			break;
	    }
	}

	if(success)
	{
		if(UpdateBlacklist())
		{
			JB_LogEx("Player '%s' has successfully been added to blacklist.",name);
		    return 1;
		}
	}
	JB_LogEx("Could not add player '%s' to blacklist!",name);
	return 0;
}

public RemoveNameFromBlacklist(name[])
{
	new success;
	for(new i=0;i<sizeof(Blacklist);i++)
	{
	    if(Blacklist[i][0])
	    {
			if(!strcmp(Blacklist[i],name,false))
			{
			    Blacklist[i][0]=0;
				success=true;
				break;
			}
	    }
	}

	if(success)
	{
		if(UpdateBlacklist())
		{
			JB_LogEx("Player '%s' has successfully been removed from blacklist.",name);
		    return 1;
		}
	}
	JB_LogEx("Could not remove player '%s' from blacklist!",name);
	return 0;
}

public AddPlayerToBlacklist(playerid)
{
	if(AddNameToBlacklist(ReturnPlayerName(playerid)))
		return JB_Ban(playerid,"Blacklist");
	return 0;
}

stock IsPlayerOnBlacklist(playerid)
{
	new name[MAX_PLAYER_NAME];
	name=ReturnPlayerName(playerid);
	for(new i=0;i<sizeof(Blacklist);i++)
	{
	    if(Blacklist[i][0])
	        if(!strcmp(name,Blacklist[i],false))
	            return true;
	}
	return false;
}

//==============================================================================

public LoadWhitelist()
{
	if(dini_Exists(WHITELIST_FILE))
	{
	    for(new i=0;i<sizeof(Whitelist);i++)
	        Whitelist[i][0]=0;

	    new File:f=fopen(WHITELIST_FILE, io_read),c,string[MAX_PLAYER_NAME];
	    while(fread(f,string,sizeof(string)) && c<sizeof(Whitelist))
	    {
	        JB_StripNewLine(string);
	        if(strlen(string))
	        {
	            Whitelist[c]=string;
	            c++;
	        }
	    }
	    fclose(f);
		JB_LogEx("%d whitelist entries have been loaded.",c);
	    return 1;
	}
	JB_Log("Could not load whitelist!");
	return 0;
}

public UpdateWhitelist()
{
	fremove(WHITELIST_FILE);
	new string[MAX_PLAYER_NAME+2];
	new File:f=fopen(WHITELIST_FILE,io_append);
	for(new i=0;i<sizeof(Whitelist);i++)
	{
	    if(Whitelist[i][0])
	    {
			format(string,sizeof(string),"%s\r\n",Whitelist[i]);
			fwrite(f,string);
		}
	}
	JB_Log("Whitelist has been updated.");
	return fclose(f);
}

public AddNameToWhitelist(name[])
{
	new success;
	for(new i=0;i<sizeof(Whitelist);i++)
	{
	    if(!Whitelist[i][0])
	    {
			format(Whitelist[i],MAX_PLAYER_NAME,name);
			success=true;
			break;
	    }
	}

	if(success)
	{
		if(UpdateWhitelist())
		{
			JB_LogEx("Player '%s' has successfully been added to whitelist.",name);
		    return 1;
		}
	}
	JB_LogEx("Could not add player '%s' to whitelist!",name);
	return 0;
}

public RemoveNameFromWhitelist(name[])
{
	new success;
	for(new i=0;i<sizeof(Whitelist);i++)
	{
	    if(Whitelist[i][0])
	    {
			if(!strcmp(Whitelist[i],name,false))
			{
			    Whitelist[i][0]=0;
				success=true;
				break;
			}
	    }
	}

	if(success)
	{
		if(UpdateWhitelist())
		{
			JB_LogEx("Player '%s' has successfully been removed from whitelist.",name);
		    return 1;
		}
	}
	JB_LogEx("Could not remove player '%s' from whitelist!",name);
	return 0;
}

public AddPlayerToWhitelist(playerid)
{
	return AddNameToWhitelist(ReturnPlayerName(playerid));
}

stock IsPlayerOnWhitelist(playerid)
{
	new name[MAX_PLAYER_NAME];
	name=ReturnPlayerName(playerid);
	for(new i=0;i<sizeof(Whitelist);i++)
	{
	    if(Whitelist[i][0])
	        if(!strcmp(name,Whitelist[i],false))
	            return true;
	}
	return false;
}

//==============================================================================

stock TemporaryBanCheck(playerid)
{
	new name[MAX_PLAYER_NAME],ip[16];
	name=ReturnPlayerName(playerid);
	ip=ReturnPlayerIp(playerid);
	for(new i=0;i<sizeof(TempBanInfo);i++)
	{
	    if(TempBanInfo[i][tbTime])
	    {
	        if(!strcmp(TempBanInfo[i][tbName],name,false))
			{
				TempBanInfo[i][tbIp]=ip;
				JB_SendFormattedMessage(playerid,RED,"GreekCnR: You are temporary banned for %d hour(s) and now, you will be banned for one more day.",TempBanInfo[i][tbTime]);
                TempBanInfo[i][tbTime]+=24;// Banning player for one day longer because of ban evading.
                JB_LogEx("%s (%s) has been banned for Ban evading.",name,ip);
				BanEx(playerid,"Ban evading");
				return 1;
			}
	    }
	}
	return 0;
}

public TempBan(playerid,hours,reason[])
{
	if(hours)
	{
		new name[MAX_PLAYER_NAME],ip[16];
		name=ReturnPlayerName(playerid);
		ip=ReturnPlayerIp(playerid);
	    for(new i=0;i<sizeof(TempBanInfo);i++)
		{
			if(!TempBanInfo[i][tbTime])
			{
			    TempBanInfo[i][tbTime]=hours;
			    TempBanInfo[i][tbIp]=ip;
			    TempBanInfo[i][tbName]=name;
			    new string[32];
			    format(string,sizeof(string),"%s [%d hour(s)]",reason,hours);
				JB_Ban(playerid,string);
				return 1;
			}
		}
	}
	return 0;
}

public DeleteTempBan(name[])
{
	for(new i=0;i<sizeof(TempBanInfo);i++)
	{
		if(TempBanInfo[i][tbTime])
		{
		    if(!strcmp(TempBanInfo[i][tbName],name,false))
		    {
			    TempBanInfo[i][tbTime]=0;
				new string[16];
				format(string,sizeof(string),"unbanip %s",TempBanInfo[i][tbIp]);
				SendRconCommand(string);
				JB_LogEx("Player '%s' (%s) has been unbanned.",name,TempBanInfo[i][tbIp]);
				return 1;
			}
		}
	}
	return 0;
}

public LoadTempBans()
{
	if(dini_Exists(TEMP_BAN_FILE))
	{
	    new File:f=fopen(TEMP_BAN_FILE, io_read),c,string[64],idx;
	    while(fread(f,string,sizeof(string)) && c<sizeof(TempBanInfo))
	    {
	        JB_StripNewLine(string);
	        idx=0;
			if(strlen(string))
			{
			    TempBanInfo[c][tbTime]=strval(JB_strtok(string,idx));
				if(TempBanInfo[c][tbTime])
				{
				    format(TempBanInfo[c][tbIp],16,JB_strtok(string,idx));
				    format(TempBanInfo[c][tbName],16,JB_strtok(string,idx));
				    c++;
				}
			}
	    }
	    fclose(f);
	    JB_LogEx("%d temporary bans have been loaded.",c);
	    return 1;
	}
	JB_Log("Could not load temporary bans!");
	return 0;
}

public SaveTempBans()
{
 	fremove(TEMP_BAN_FILE);
	new File:f=fopen(TEMP_BAN_FILE, io_append),string[64];
	for(new i=0;i<sizeof(TempBanInfo);i++)
	{
		if(TempBanInfo[i][tbTime])
		{
		    format(string,sizeof(string),"%d %s %s\r\n",TempBanInfo[i][tbTime],TempBanInfo[i][tbIp],TempBanInfo[i][tbName]);
		    fwrite(f,string);
		}
	}
	fclose(f);
	return 1;
}

public TempBanUpdate()
{
    new string[32];
    for(new i=0;i<sizeof(TempBanInfo);i++)
	{
		if(TempBanInfo[i][tbTime])
		{
		    TempBanInfo[i][tbTime]--;
		    if(!TempBanInfo[i][tbTime])
		    {
				format(string,sizeof(string),"unbanip %s",TempBanInfo[i][tbIp]);
				SendRconCommand(string);
				JB_LogEx("Player '%s' (%s) has been unbanned.",TempBanInfo[i][tbName],TempBanInfo[i][tbIp]);
			}
		}
	}
	return 1;
}

//==============================================================================

public LoadBadWords()
{
	if(dini_Exists(BAD_WORDS_FILE))
	{
	    new File:f=fopen(BAD_WORDS_FILE, io_read),c,string[32];
	    while(fread(f,string,sizeof(string)) && c<MAX_BAD_WORDS)
	    {
	        JB_StripNewLine(string);
	        if(strlen(string))
	        {
	            BadWords[c]=string;
	            c++;
	        }
	    }
	    fclose(f);
	    BadWordsCount=c;
	    JB_LogEx("%d bad words have been loaded.",BadWordsCount);
	    return 1;
	}
	JB_Log("Could not load bad words!");
	return 0;
}

public LoadForbiddenWeapons()
{
	if(dini_Exists(FORBIDDEN_WEAPONS_FILE))
	{
	    new File:f=fopen(FORBIDDEN_WEAPONS_FILE, io_read),c,string[32];
	    while(fread(f,string,sizeof(string)) && c<MAX_FORBIDDEN_WEAPONS)
	    {
	        JB_StripNewLine(string);
	        if(strlen(string))
	        {
	            ForbiddenWeapons[c]=strval(string);
	            c++;
	        }
	    }
	    fclose(f);
	    ForbiddenWeaponsCount=c;
	    JB_LogEx("%d forbidden weapons have been loaded.",ForbiddenWeaponsCount);
	    return 1;
	}
	JB_Log("Could not load forbidden weapons!");
	return 0;
}

public ConfigGreekCnR()
{
	if(!dini_Exists(CONFIG_FILE))
	    dini_Create(CONFIG_FILE);

    for(new i=0;i<MAX_JB_VARIABLES;i++)
    {
        if(dini_Isset(CONFIG_FILE,JB_VariableNames[i]))
            JB_Variables[i]=dini_Int(CONFIG_FILE,JB_VariableNames[i]);
		else
		    dini_IntSet(CONFIG_FILE,JB_VariableNames[i],JB_Variables[i]);
	}

    print("\n");
    JB_Log("Current GreekCnR configuration:");
    for(new i=0;i<MAX_JB_VARIABLES;i++)
        JB_LogEx("- %s = %d",JB_VariableNames[i],JB_Variables[i]);

	print("\n");

	LoadIpBans();
	LoadTempBans();
	LoadWhitelist();
	LoadBlacklist();
    LoadBadWords();
    LoadForbiddenWeapons();
    JB_Log("GreekCnR has been configurated.");
	return 1;
}

public SaveGreekCnRVars()
{
    if(!dini_Exists(CONFIG_FILE))
	    dini_Create(CONFIG_FILE);

    for(new i=0;i<MAX_JB_VARIABLES;i++)
    	dini_IntSet(CONFIG_FILE,JB_VariableNames[i],JB_Variables[i]);
	
	JB_Log("Current GreekCnR configuration:");
    for(new i=0;i<MAX_JB_VARIABLES;i++)
        JB_LogEx("- %s = %d",JB_VariableNames[i],JB_Variables[i]);

	print("\n");
    JB_Log("GreekCnR configuration has been saved to file.");
	return 1;
}

//==============================================================================

stock ReturnTime()
{
	new jb_time[16],jb_h,jb_m,jb_s;
	gettime(jb_h,jb_m,jb_s);
	format(jb_time,sizeof(jb_time),"%02d:%02d:%02d",jb_h,jb_m,jb_s);
	return jb_time;
}

stock ReturnDate()
{
	new jb_date[32],jb_day,jb_month,jb_year;
	getdate(jb_year,jb_month,jb_day);
	format(jb_date,sizeof(jb_date),"%d. %s %d",jb_day,GetMonth(jb_month),jb_year);
	return jb_date;
}

stock GetMonth(month)
{
	new string[32];
	string="Unknown month";
	switch(month)
	{
	    case 1:
	        string="January";
		case 2:
		    string="February";
        case 3:
		    string="March";
        case 4:
		    string="April";
        case 5:
		    string="May";
		case 6:
		    string="June";
		case 7:
		    string="July";
		case 8:
		    string="August";
		case 9:
		    string="Septembre";
		case 10:
		    string="Octobre";
		case 11:
		    string="Novembre";
		case 12:
		    string="Decembre";
	}
	return string;
}

stock ReturnPlayerName(playerid)
{
	new name[MAX_PLAYER_NAME];
	GetPlayerName(playerid,name,sizeof(name));
	return name;
}

stock ReturnPlayerIp(playerid)
{
	new ip[16];
	GetPlayerIp(playerid,ip,sizeof(ip));
	return ip;
}

stock JB_strtok(const string[], &index,seperator=' ')
{
	new length = strlen(string);
	new offset = index;
	new result[32];
	while ((index < length) && (string[index] != seperator) && ((index - offset) < (sizeof(result) - 1)))
	{
		result[index - offset] = string[index];
		index++;
	}

	result[index - offset] = EOS;
	if ((index < length) && (string[index] == seperator))
	{
		index++;
	}
	return result;
}

stock JB_IsNumeric(string[])
{
	for (new i = 0, j = strlen(string); i < j; i++)
		if ((string[i] > '9' || string[i] < '0') && string[i]!='-' ) return 0;
	return 1;
}

stock JB_StripNewLine(string[])
{
	new len = strlen(string);
	if (string[0]==0) return ;
	if ((string[len - 1] == '\n') || (string[len - 1] == '\r')) {
		string[len - 1] = 0;
		if (string[0]==0) return ;
		if ((string[len - 2] == '\n') || (string[len - 2] == '\r')) string[len - 2] = 0;
	}
}

//==============================================================================

stock JB_GetPlayerSpeed(playerid)
{
	new Float:x,Float:y,Float:z;
	if(IsPlayerInAnyVehicle(playerid))
	    GetVehicleVelocity(GetPlayerVehicleID(playerid),x,y,z);
	else
	    GetPlayerVelocity(playerid,x,y,z);

	return JB_Speed(x,y,z,100.0);
}

stock JB_GetSquareDistance(Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2)
{
	x1-=x2;
	y1-=y2;
	z1-=z2;
	x1*=x1;
	y1*=y1;
	z1*=z1;
	return floatround(x1+y1+z1);
}

//==============================================================================

//From Cueball's "Zones By ~Cueball~ - V 2.0" (added JB_ tag so there should no redefinitions exist when compiling)
stock JB_GetPlayer2DZone(playerid, zone[], len) //Credits to Cueball, Betamaster, Mabako, and Simon (for finetuning).
{
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
 	for(new i = 0; i != sizeof(JB_gSAZones); i++ )
 	{
		if(x >= JB_gSAZones[i][JB_SAZONE_AREA][0] && x <= JB_gSAZones[i][JB_SAZONE_AREA][3] && y >= JB_gSAZones[i][JB_SAZONE_AREA][1] && y <= JB_gSAZones[i][JB_SAZONE_AREA][4])
		{
		    format(zone, len, JB_gSAZones[i][JB_SAZONE_NAME], 0);
		    return i;

		}
	}
	return 0;
}

//==============================================================================

ShowPlayerConfigDialog(playerid)
{
	ShowPlayerDialog(playerid,DIALOG_CFG,DIALOG_STYLE_LIST,"GreekCnR","Set a variable\nLoad configuration from file\nSave configuration to file","Choose","Close");
}

ShowPlayerVarlistDialog(playerid)
{
    new string[512];
    for(new i=0;i<MAX_JB_VARIABLES;i++)
		format(string,sizeof(string),"%s%s = %d\n",string,JB_VariableNames[i],JB_Variables[i]);

    ShowPlayerDialog(playerid,DIALOG_VARLIST,DIALOG_STYLE_LIST,"GreekCnR variables",string,"Choose","Go back");
}

ShowPlayerSetvarDialog(playerid,var)
{
	new string[64];
	format(string,sizeof(string),"GreekCnR variable: %s = %d",JB_VariableNames[var],JB_Variables[var]);
	ShowPlayerDialog(playerid,DIALOG_SETVAR+var,DIALOG_STYLE_INPUT,string,JB_VarDescription[var],"Set var","Go back");
}

//==============================================================================

public OnPlayerSpawn(playerid)
{
    FullyConnected[playerid]=true;
    NoTeleportCheck[playerid]=3;
    JB_PlayerInfo[playerid][JB_pFreezed]=false;
    return CallLocalFunction("PnP_OnPlayerSpawn","i",playerid);
}

public OnPlayerDeath(playerid,killerid,reason)
{
	if(killerid!=INVALID_PLAYER_ID)
	{
	    new Float:x1,Float:y1,Float:z1;
	    new Float:x2,Float:y2,Float:z2;
		new Float:distance=floatsqroot(JB_GetSquareDistance(x1,y1,z1,x2,y2,z2));
	    if(JB_Variables[DRIVE_BY])
	    {
			if(distance<25.0 && GetPlayerState(killerid)==PLAYER_STATE_DRIVER && (reason==WEAPON_UZI || reason==WEAPON_MP5 || reason==WEAPON_TEC9))
			{
			    SetPlayerHealth(killerid,0.0);
			    SendClientMessage(killerid,RED,"GreekCnR: You have been killed for drive-by!");
			}
		}

		if(JB_Variables[SPAWNKILL])
		{
		    if(distance<30.0)
		    {
		        if(JB_PlayerInfo[playerid][JB_pSpawnKillProtected])
		        {
		            JB_Warnings[killerid][SPAWNKILL]++;
		            if(JB_Warnings[killerid][SPAWNKILL]>=JB_Variables[SPAWNKILL])
						JB_Kick(killerid,"Excessive spawnkilling");
					else
						JB_SendFormattedMessage(killerid,RED,"GreekCnR: Do not spawnkill! (Warning %d/%d)",JB_Warnings[killerid][SPAWNKILL],JB_Variables[SPAWNKILL]);
				}
			}
	 	}
 	}
	return CallLocalFunction("PnP_OnPlayerDeath","iii",playerid,killerid,reason);
}

public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
	NoTeleportCheck[playerid]=3;
	return CallLocalFunction("PnP_OnPlayerInteriorChange","iii",playerid, newinteriorid, oldinteriorid);
}

public OnGameModeInit()
{
	if(!CallLocalFunction("PnP_OnGameModeInit",""))
	{
	    JB_Log("[WARNING!]");
	    JB_Log("GreekCnR is not used in gamemode or OnGameModeInit returns 0.");
	    JB_Log("Make sure you use GreekCnR.inc in your gamemode. If you want to");
        JB_Log("use GreekCnR in filterscripts, too, include  GreekCnRFS.inc in");
        JB_Log("your filterscript.");
        JB_Log("It's recommended to include GreekCnR.inc in your gamemode");
	}
	
	dini_Remove(BAD_RCON_LOGIN_FILE);
	dini_Create(BAD_RCON_LOGIN_FILE);
	
	#if defined WARN_PLAYERS
	    SendRconCommand("mapname GreekCnR Anti-Cheat");
	#endif
	ConfigGreekCnR();
	SetTimer("GreekCnR",1000,true);
	SetTimer("GlobalUpdate",60*1000*4,true);// Every 4 minutes
	SetTimer("SpamUpdate",3500,true);
	SetTimer("TempBanUpdate",1000*60*60,true);// Every hour
	JB_Log("GreekCnR has successfully been loaded.");
	return 1;
}

public OnGameModeExit()
{
	SaveIpBans();
	SaveTempBans();
    return CallLocalFunction("PnP_OnGameModeExit","");
}

public OnPlayerConnect(playerid)
{
	KickBan[playerid]=false;
	FullyConnected[playerid]=false;

	if(TemporaryBanCheck(playerid) && JB_Variables[TEMP_BANS])
	{
	    KickBan[playerid]=true;
	    return 0;
	}

	if(IpBanCheck(playerid) && !IsPlayerOnWhitelist(playerid) && JB_Variables[IP_BANS])
	{
	    KickBan[playerid]=true;
	    SendClientMessage(playerid,RED,"GreekCnR: You are banned from this server!");
	    JB_LogEx("%s (%s) has been kicked for Banned IP.",ReturnPlayerName(playerid),ReturnPlayerIp(playerid));
	    Kick(playerid);
	    return 0;
	}

	if(IsPlayerOnBlacklist(playerid) && JB_Variables[BLACKLIST])
	{
	    KickBan[playerid]=true;
	    SendClientMessage(playerid,RED,"GreekCnR: You are banned from this server!");
	    JB_LogEx("%s (%s) has been banned for Ban evading.",ReturnPlayerName(playerid),ReturnPlayerIp(playerid));
	    BanEx(playerid,"Ban evading");
	    return 0;
	}

	for(new i=0;i<MAX_JB_VARIABLES;i++)
	    JB_Warnings[playerid][i]=0;

	ResetForbiddenWeaponsForPlayer(playerid);
	JB_PlayerInfo[playerid][JB_pLastMessage][0]=0;
	JB_PlayerInfo[playerid][JB_pMessageRepeated]=0;
	JB_PlayerInfo[playerid][JB_pMessages]=0;
	JB_PlayerInfo[playerid][JB_pCommands]=0;
    NoTeleportCheck[playerid]=0;
    JB_PlayerInfo[playerid][JB_pPingCheckProgress]=0;
	JB_PlayerInfo[playerid][JB_pVehicleEntered]=INVALID_VEHICLE_ID;
	JB_PlayerInfo[playerid][JB_pMuted]=0;
	JB_PlayerInfo[playerid][JB_pFreezed]=false;
	#if defined WARN_PLAYERS
		SendClientMessage(playerid,GREEN_BLUE,"> This server is running GreekCnR Anti-Cheat!");
		SendClientMessage(playerid,GREEN_BLUE,"> You may not cheat otherwise you'll get kicked/banned.");
	#endif
	return CallLocalFunction("PnP_OnPlayerConnect","i",playerid);
}

public OnPlayerDisconnect(playerid,reason)
{
    FullyConnected[playerid]=false;
	if(KickBan[playerid])
	    return 0;
	return CallLocalFunction("PnP_OnPlayerDisconnect","ii",playerid,reason);
}

public OnPlayerText(playerid, text[])
{
	if(JB_PlayerInfo[playerid][JB_pMuted] && JB_Variables[SPAM])
	{
	    JB_SendFormattedMessage(playerid,RED,"GreekCnR: You are not allowed to chat for %d second(s) because you have been muted!",JB_PlayerInfo[playerid][JB_pMuted]);
	    return 0;
	}

	if(JB_PlayerInfo[playerid][JB_pLastMessage][0])
	{
	    if(!strcmp(text,JB_PlayerInfo[playerid][JB_pLastMessage],false))
	        JB_PlayerInfo[playerid][JB_pMessageRepeated]++;
		else
		    JB_PlayerInfo[playerid][JB_pMessageRepeated]=0;
	}
	else
	    JB_PlayerInfo[playerid][JB_pMessageRepeated]=0;
	
	format(JB_PlayerInfo[playerid][JB_pLastMessage],128,text);
    JB_PlayerInfo[playerid][JB_pMessages]++;
    if(!JB_PlayerInfo[playerid][JB_pMuted] && JB_Variables[SPAM] && (!JB_IsPlayerAdmin(playerid) || !JB_Variables[ADMIN_IMMUNITY]))
    {
        if(JB_PlayerInfo[playerid][JB_pMessages]>15)
	    {
	        JB_Ban(playerid,"Extreme spam");
	        return 0;
	    }
	    else if(JB_PlayerInfo[playerid][JB_pMessages]>10)
	    {
	        JB_Kick(playerid,"Massive spam");
	        return 0;
	    }
	    else if(JB_PlayerInfo[playerid][JB_pMessages]>4 || JB_PlayerInfo[playerid][JB_pMessageRepeated]>=3)
	    {
	        JB_PlayerInfo[playerid][JB_pMessageRepeated]=0;
	        MutePlayer(playerid,2*60,"Spam");
		    return 0;
		}
	}
    
    if(CapsLockCheck(text) && JB_Variables[CAPS_LOCK])
	{
	    SendClientMessage(playerid,RED,"GreekCnR: You are not allowed to use Caps Lock! Press [Caps Lock] to disable it.");
	    return 0;
	}

	if(AdvertisementCheck(text) && !JB_IsPlayerAdmin(playerid))
	{
	    JB_Kick(playerid,"Advertisement");
	    return 0;
	}

	if(BadWordsCheck(text) && JB_Variables[BAD_WORDS])
	{
	    SendClientMessage(playerid,RED,"GreekCnR: You are not allowed to use such words!");
	    return 0;
	}
	return CallLocalFunction("PnP_OnPlayerText","is",playerid,text);
}

public OnPlayerCommandText(playerid, cmdtext[])
{
	JB_PlayerInfo[playerid][JB_pCommands]++;
	if(JB_Variables[COMMAND_SPAM] && (!JB_IsPlayerAdmin(playerid) || !JB_Variables[ADMIN_IMMUNITY]))
    {
        if(JB_PlayerInfo[playerid][JB_pCommands]>15)
	    {
	        JB_Ban(playerid,"Extreme command spam");
	        return 1;
	    }
	    else if(JB_PlayerInfo[playerid][JB_pCommands]>5)
	    {
	        JB_Kick(playerid,"Command spam");
	        return 1;
	    }
    }
			    
	new cmd[32],tmp[32],idx,pid;
	cmd=JB_strtok(cmdtext,idx);

	if(IsPlayerAdmin(playerid))
	{
	    if(!strcmp("/jbcmds",cmd,true))
	    {
	        SendClientMessage(playerid,GREEN_BLUE,"Available commands:");
	        SendClientMessage(playerid,GREEN," /jbcfg, /blackadd <ID/name>, /blackdel <name>, /whiteadd <name>, /whitedel <name>");
	        SendClientMessage(playerid,GREEN," /tban <ID> <time in hours> <reason>, /tunban <name>, /banIP <IP>, /unbanIP <IP>");
	        SendClientMessage(playerid,GREEN," /jbvarlist, /jbsetvar <variable name> <0/1(/max ping)>");
	        return 1;
	    }

		if(!strcmp("/jbcfg",cmd,true))
		{
		    ShowPlayerConfigDialog(playerid);
			return 1;
		}

		if(!strcmp("/blackadd",cmd,true))
		{
		    tmp=JB_strtok(cmdtext,idx);
		    if(strlen(tmp))
		    {
				if(!JB_IsNumeric(tmp))
				{
				    if(AddNameToBlacklist(tmp))
				        JB_SendFormattedMessage(playerid,GREEN,"GreekCnR: Player '%s' has successfully been added to blacklist!",tmp);
					else
					    JB_SendFormattedMessage(playerid,RED,"GreekCnR: Could not add player '%s' to blacklist!",tmp);
					return 1;
				}
				else
				{
				    pid=strval(tmp);
				    if(pid!=playerid)
				    {
					    if(AddPlayerToBlacklist(pid))
					        JB_SendFormattedMessage(playerid,GREEN,"GreekCnR: Player '%s' has successfully been added to blacklist!",tmp);
						else
						    JB_SendFormattedMessage(playerid,RED,"GreekCnR: Could not add player '%s' to blacklist!",tmp);
						return 1;
					}
				}
			}
			SendClientMessage(playerid,RED,"Usage: /blackadd <ID/name>");
			return 1;
		}

		if(!strcmp("/blackdel",cmd,true))
		{
		    tmp=JB_strtok(cmdtext,idx);
		    if(strlen(tmp))
		    {
			    if(RemoveNameFromBlacklist(tmp))
			        JB_SendFormattedMessage(playerid,GREEN,"GreekCnR: Player '%s' has successfully been removed from blacklist!",tmp);
				else
				    JB_SendFormattedMessage(playerid,RED,"GreekCnR: Could not remove player '%s' from blacklist!",tmp);
				return 1;
			}
			SendClientMessage(playerid,RED,"Usage: /blackdel <name>");
			return 1;
		}

		if(!strcmp("/whiteadd",cmd,true))
		{
		    tmp=JB_strtok(cmdtext,idx);
      		if(strlen(tmp))
		    {
       			if(AddNameToWhitelist(tmp))
			        JB_SendFormattedMessage(playerid,GREEN,"GreekCnR: Player '%s' has successfully been added to whitelist!",tmp);
				else
				    JB_SendFormattedMessage(playerid,RED,"GreekCnR: Could not add player '%s' to whitelist!",tmp);
				return 1;
			}
			SendClientMessage(playerid,RED,"Usage: /whiteadd <name>");
			return 1;
		}

		if(!strcmp("/whitedel",cmd,true))
		{
		    tmp=JB_strtok(cmdtext,idx);
		    if(strlen(tmp))
		    {
			    if(RemoveNameFromWhitelist(tmp))
			        JB_SendFormattedMessage(playerid,GREEN,"GreekCnR: Player '%s' has successfully been removed from whitelist!",tmp);
				else
				    JB_SendFormattedMessage(playerid,RED,"GreekCnR: Could not remove player '%s' from whitelist!",tmp);
				return 1;
			}
			SendClientMessage(playerid,RED,"Usage: /whitedel <name>");
			return 1;
		}

		if(!strcmp("/jbvarlist",cmd,true))
		{
		    new string[128];
		    SendClientMessage(playerid,GREEN_BLUE,"GreekCnR variables:");
		    for(new i=0;i<MAX_JB_VARIABLES;i++)
		    {
			    if(pid<3)
			    {
					format(string,sizeof(string),"%s, %s = %d",string,JB_VariableNames[i],JB_Variables[i]);
					pid++;
			    }
			    else
			    {
			        format(string,sizeof(string)," %s, %s = %d",string[1],JB_VariableNames[i],JB_Variables[i]);
			        SendClientMessage(playerid,GREEN,string);
			        string[0]=0;
			        pid=0;
				}
			}

			if(pid)
			{
			    format(string,sizeof(string)," %s",string[1]);
		        SendClientMessage(playerid,GREEN,string);
		        format(string,sizeof(string),"\0");
			}
			return 1;
		}

		if(!strcmp("/jbsetvar",cmd,true))
		{

		    tmp=JB_strtok(cmdtext,idx);
		    if(strlen(tmp))
		    {
		        new var[32];
		    	var=tmp;
		    	tmp=JB_strtok(cmdtext,idx);
		    	if(strlen(tmp) && JB_IsNumeric(tmp))
		    	{
		    		pid=strval(tmp);
		    		if(pid>=0)
		    		{
		    		    for(new i=0;i<MAX_JB_VARIABLES;i++)
		    		    {
		    		        if(!strcmp(var,JB_VariableNames[i],true))
		    		        {
		    		            JB_Variables[i]=pid;
		    		            JB_SendFormattedMessage(playerid,GREEN,"GreekCnR: GreekCnR variable '%s' has successfully been set to %d.",JB_VariableNames[i],JB_Variables[i]);
                                JB_LogEx("%s has set variable '%s' to %d.",ReturnPlayerName(playerid),JB_VariableNames[i],JB_Variables[i]);
								return 1;
							}
		    		    }
		    		}
				}
		    }
		    SendClientMessage(playerid,RED,"Usage: /jbsetvar <variable name> <0/1(/max ping)>");
			return 1;
		}

		if(!strcmp("/tban",cmd,true))
		{
		    new time,idx2=strlen(cmd)+2;
		    tmp=JB_strtok(cmdtext,idx);
		    idx2+=strlen(tmp);
		    if(strlen(tmp))
		    {
		        if(JB_IsNumeric(tmp))
		        {
		            pid=strval(tmp);
		            if(IsPlayerConnected(pid))
		            {
						tmp=JB_strtok(cmdtext,idx);
						idx2+=strlen(tmp);
						if(strlen(tmp))
						{
							if(JB_IsNumeric(tmp))
							{
							    time=strval(tmp);
							    if(strlen(cmdtext[idx2]) && time)
								{
							        TempBan(pid,time,cmdtext[idx2]);
							        return 1;
							    }
							}
						}
		            }
		        }
		    }
		    SendClientMessage(playerid,RED,"Usage: /tban <ID> <time in hours> <reason>");
			return 1;
		}

		if(!strcmp("/tunban",cmd,true))
		{
		    tmp=JB_strtok(cmdtext,idx);
		    if(strlen(tmp))
		    {
		        if(DeleteTempBan(tmp))
		            JB_SendFormattedMessage(playerid,GREEN,"GreekCnR: Temporary ban of player '%s' has successfully been deleted.",tmp);
				else
				    JB_SendFormattedMessage(playerid,RED,"GreekCnR: Could not delete temporary ban of player '%s'!",tmp);
				return 1;
		    }
		    SendClientMessage(playerid,RED,"Usage: /tunban <name>");
			return 1;
		}

		if(!strcmp("/banip",cmd,true))
		{
		    tmp=JB_strtok(cmdtext,idx);
		    if(strlen(tmp))
		    {
				new ip[4];
				ip=Split(tmp);
		        if(ip[0])
		        {
		            if(BanIp(tmp))
		                JB_SendFormattedMessage(playerid,GREEN,"GreekCnR: IP %s has successfully been banned!",tmp);
					else
					    JB_SendFormattedMessage(playerid,RED,"GreekCnR: Could not ban IP %s!",tmp);
					return 1;
		        }
		    }
		    SendClientMessage(playerid,RED,"Usage: /banIP <IP>");
			return 1;
		}

		if(!strcmp("/unbanip",cmd,true))
		{
		    tmp=JB_strtok(cmdtext,idx);
		    if(strlen(tmp))
		    {
				new ip[4];
				ip=Split(tmp);
		        if(ip[0])
		        {
		            if(UnbanIp(tmp))
		                JB_SendFormattedMessage(playerid,GREEN,"GreekCnR: IP %s has successfully been unbanned!",tmp);
					else
					    JB_SendFormattedMessage(playerid,RED,"GreekCnR: Could not unban IP %s!",tmp);
					return 1;
		        }
		    }
		    SendClientMessage(playerid,RED,"Usage: /unbanIP <IP>");
			return 1;
		}
	}
	return CallLocalFunction("PnP_OnPlayerCommandText","is",playerid,cmdtext);
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    new Float:x,Float:y,Float:z;
    new Float:vx,Float:vy,Float:vz;
    GetPlayerPos(playerid,x,y,z);
    GetVehiclePos(vehicleid,vx,vy,vz);
    if(JB_GetSquareDistance(x,y,z,vx,vy,vz)>(350*350))
        GreekCnRReport(playerid,"spawning vehicles",GetVehicleName(vehicleid));//Counting warnings would be non-sense.

	JB_PlayerInfo[playerid][JB_pVehicleEntered]=vehicleid;
	return CallLocalFunction("PnP_OnPlayerEnterVehicle","iii",playerid, vehicleid, ispassenger);
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	if(JB_Variables[SPECTATE_HACK] && newstate==PLAYER_STATE_SPECTATING && !JB_IsPlayerAdmin(playerid))
	    JB_Ban(playerid,"Spectate hack");

	new vehicleid=GetPlayerVehicleID(playerid);
	if(newstate==PLAYER_STATE_DRIVER && JB_PlayerInfo[playerid][JB_pVehicleEntered]!=vehicleid && (!JB_IsPlayerAdmin(playerid) || !JB_Variables[ADMIN_IMMUNITY]))
	{
		new used;
		for(new i=0;i<MAX_PLAYERS;i++)
		{
		    if(IsPlayerConnected(i) && i!=playerid)
		    {
		        if(GetPlayerState(i)==PLAYER_STATE_DRIVER)
		        {
		            if(GetPlayerVehicleID(i)==vehicleid)
		            {
		                used=true;
		                break;
		            }
		        }
			}
		}
		
		if(used)
		{
			JB_Warnings[playerid][CAR_JACK_HACK]++;
			if(JB_Variables[CAR_JACK_HACK])
			{
			    if(JB_Warnings[playerid][CAR_JACK_HACK]>=3)
		    		JB_Kick(playerid,"Carjack hack");
			}
			else
			    GreekCnRReport(playerid,"carjack hack","no details");
		}
	}

	if(oldstate==PLAYER_STATE_PASSENGER)
	    NoTeleportCheck[playerid]=3;//Do not check position for 3 seconds to prevent lag kick.

	JB_PlayerInfo[playerid][JB_pVehicleEntered]=INVALID_VEHICLE_ID;
	return CallLocalFunction("PnP_OnPlayerStateChange","iii",playerid, newstate, oldstate);
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	new len=strlen(inputtext);
	for(new i=0;i<len;i++)
	    if(inputtext[i]=='%')
	        inputtext[i]='#';
	        
	if(IsPlayerAdmin(playerid))
	{
		if(dialogid==DIALOG_CFG)
		{
			if(response)
			{
			    switch(listitem)
			    {
			        case 0:
			            ShowPlayerVarlistDialog(playerid);

			        case 1:
			        {
			            ConfigGreekCnR();
			    		SendClientMessage(playerid,GREEN,"GreekCnR: Configuration has been loaded from file.");
			    		ShowPlayerConfigDialog(playerid);
			        }

			        case 2:
			        {
			            SaveGreekCnRVars();
			    		SendClientMessage(playerid,GREEN,"GreekCnR: Configuration has been saved to file.");
			    		ShowPlayerConfigDialog(playerid);
			        }
			    }
			}
			return 1;
		}

		if(dialogid==DIALOG_VARLIST)
		{
		    if(response)
		    	ShowPlayerSetvarDialog(playerid,listitem);
		    else
		        ShowPlayerConfigDialog(playerid);
			return 1;
		}
		
		if(dialogid>=DIALOG_SETVAR && dialogid<(DIALOG_SETVAR+MAX_JB_VARIABLES-1))
		{
		    if(response)
		    {
		        new var=dialogid-DIALOG_SETVAR,setvar=strval(inputtext);
		        if(!inputtext[0] || !JB_IsNumeric(inputtext) || setvar<0)
			        ShowPlayerSetvarDialog(playerid,var);
				else
				{
                    JB_Variables[var]=setvar;
		            JB_SendFormattedMessage(playerid,GREEN,"GreekCnR: GreekCnR variable '%s' has successfully been set to %d.",JB_VariableNames[var],JB_Variables[var]);
					JB_LogEx("%s has set variable '%s' to %d.",ReturnPlayerName(playerid),JB_VariableNames[var],JB_Variables[var]);
					ShowPlayerVarlistDialog(playerid);
				}
		    }
		    else
			    ShowPlayerVarlistDialog(playerid);
		    return 1;
		}
	}
	
	if(!len)
		return CallLocalFunction("PnP_OnDialogResponse","iiiis",playerid, dialogid, response, listitem, "#");
    return CallLocalFunction("PnP_OnDialogResponse","iiiis",playerid, dialogid, response, listitem, inputtext);
}

public OnRconLoginAttempt( ip[], password[], success)
{
	if(!success)
	{
	    new attempts=dini_Int(BAD_RCON_LOGIN_FILE,ip);
		attempts++;
		if(attempts>=3)
		{
		    new cmd[32];
		    format(cmd,sizeof(cmd),"banip %s",ip);
		    SendRconCommand(cmd);
		    JB_LogEx("Banning IP %s for too many failed RCON-logins.",ip);
		}
		JB_LogEx("IP %s tried to log in as RCON-admin with password '%s'.",ip,password);
		dini_IntSet(BAD_RCON_LOGIN_FILE,ip,attempts);
	}
	else
	    JB_LogEx("IP %s has logged in as RCON-admin",ip);
	return CallLocalFunction("PnP_OnRconLoginAttempt","ssi",ip,password,success);
}

#define GetPlayerMoney JB_GetPlayerMoney
#define ResetPlayerMoney JB_ResetPlayerMoney
#define GivePlayerMoney JB_GivePlayerMoney
#define SetPlayerMoney JB_SetPlayerMoney
#define PutPlayerInVehicle JB_PutPlayerInVehicle
#define GivePlayerWeapon JB_GivePlayerWeapon
#define SetPlayerPos JB_SetPlayerPos
#define SetVehiclePos JB_SetVehiclePos
#define SetPlayerHealth JB_SetPlayerHealth
#define SetPlayerArmour JB_SetPlayerArmour
#define TogglePlayerControllable JB_TogglePlayerControllable
#define SetVehicleVelocity JB_SetVehicleVelocity
#define SetPlayerSpecialAction JB_SetPlayerSpecialAction

//Plug & Play:
#define OnPlayerStateChange PnP_OnPlayerStateChange
#define OnPlayerEnterVehicle PnP_OnPlayerEnterVehicle
#define OnPlayerCommandText PnP_OnPlayerCommandText
#define OnPlayerText PnP_OnPlayerText
#define OnPlayerConnect PnP_OnPlayerConnect
#define OnPlayerDisconnect PnP_OnPlayerDisconnect
#define OnGameModeInit PnP_OnGameModeInit
#define OnGameModeExit PnP_OnGameModeExit
#define OnPlayerInteriorChange PnP_OnPlayerInteriorChange
#define OnPlayerDeath PnP_OnPlayerDeath
#define OnPlayerSpawn PnP_OnPlayerSpawn
#define OnDialogResponse PnP_OnDialogResponse
#define OnRconLoginAttempt PnP_OnRconLoginAttempt
