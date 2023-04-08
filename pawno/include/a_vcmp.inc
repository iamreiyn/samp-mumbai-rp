/*  VC:MP Functions
 *
 *  (c) Copyright 2005-2006, VC:MP/SA:MP Team
 * 
 */

#if defined _vcmp_included
	#endinput
#endif
#define _vcmp_included
#pragma library samp

#include <core>
#include <float>
#include <string>
#include <file>
#include <time>
#include <datagram>

// --------------------------------------------------
// Natives
// --------------------------------------------------

// Util
native print(const string[]);
native printf(const format[], {Float,_}:...);
native format(output[], len, const format[], {Float,_}:...);
native SendClientMessage(playerid, color, const format[]);
native SendClientMessageToAll(color, const format[]);
native SendDeathMessage(killed,weapon,killer,type,bodypart);
native SetDeathMessage(bool);
native GameTextForAll(const string[]);
native GameTextForPlayer(playerid,const string[]);
native GameTextForAllBottom(const string[]);
native GameTextForPlayerBottom(playerid,const string[]);
native SetTimer(funcname[], interval, repeating);
native KillTimer(timerid);
native GetTickCount();
native GetMaxPlayers();
native SetMaxPlayers(maxplayers);

// Game
native SetGameModeText(const string[]);
native SetTeamCount(count);
native AddPlayerClass(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
native AddPlayerClassEx(teamid, modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
native AddStaticVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2);
native AddStaticPickup(id,type,Float:X,Float:Y,Float:Z,amount);
native SetWorldBounds(Float:x_max,Float:x_min,Float:y_max,Float:y_min);
native ShowPlayerMarkers(show);
native GameModeExit();
native SetWorldTime(hour);
native GetWeaponName(weaponid, const weapon[], len);
native SetGravity(Gravity);
native ResetNormalGravity();
native SetGamespeed(Gamespeed);
native ResetNormalGamespeed();
native ToggleWhiteScanlinesForAll(set);
native ToggleWhiteScanlinesForPlayer(playerid, set);
native ToggleGreenScanlinesForAll(set);
native ToggleGreenScanlinesForPlayer(playerid, set);
native ToggleWidescreenForAll(set);
native ToggleWidescreenForPlayer(playerid, set);
native SetWaterLevel(Float:L);



// Admin
native IsPlayerAdmin(playerid);
native Kick(playerid);
native Ban(playerid);

// Player
native SetPlayerStartPos(Float:x, Float:y, Float:z);
native SetPlayerTeam(playerid, teamid);
native SetPlayerFriendlyFire(ff);
native GetPlayerTeam(playerid);
native SetPlayerSkin(playerid, skinid);
native SetPlayerScore(playerid,score);
native GetPlayerScore(playerid);
native GetPlayerPos(playerid, &Float:x, &Float:y, &Float:z);
native SetPlayerPos(playerid, Float:x, Float:y, Float:z, Float:r, inter);
native GetPlayerHealth(playerid, &Float:health);
native SetPlayerHealth(playerid, Float:health);
native GetPlayerArmour(playerid, &Float:armour);
native SetPlayerArmour(playerid, Float:armour);
native GetPlayerWeapon(playerid);
native SetPlayerWeapon(playerid, weaponid, ammo);
native PutPlayerInVehicle(playerid, vehicleid);
native RemovePlayerFromVehicle(playerid);
native IsPlayerInVehicle(playerid, vehicleid);
native IsPlayerInAnyVehicle(playerid);
native IsPlayerDriver_Passanger(playerid);
native GetPlayerName(playerid, const name[], len);
native GetPlayerVehicleID(playerid);
native SetCameraPos(Float:x, Float:y, Float:z);
native SetCameraLookAt(Float:x, Float:y, Float:z);
native TogglePlayerControllable(playerid, toggle);
native SetPlayerAnimation(playerid, anim);
native SetPlayerDrunk(playerid, visuals, handling);
native GivePlayerMoney(playerid,money);
native SetPlayerMoney(id,amount);
native SetPlayerFacingAngle(playerid,Float:ang);
native GetPlayerFacingAngle(playerid,&Float:ang);
native GetPlayerMoney(playerid);
native ResetPlayerMoney(playerid);
native IsPlayerConnected(playerid);
native GetPlayerState(playerid);
native ResetPlayerWeapons(playerid);
native GivePlayerWeapon(playerid, weaponid, ammo);
native GetPlayerIp(playerid, const name[], len);
native GetPlayerPing(playerid);
native GetPlayerIDFromName(const name[]);
native SetPlayerDriveOnWater(set);
native SetWeaponDamage(weaponid,damage);
native SetSpikes(playerid,bool);
native SetWantedLevel(playerid,level);
native DisableDriveby(playerid,bool);
native PerfectHandling(bool);
native Flyingcars(bool);
native Taxiboostjump(bool);
native FastSwitch(bool);
native Jumpswitch(bool);
native Syncframelimiter(bool);
native EnableStuntBike(playerid,bool);
native EnableShootInAir(playerid,bool);

// Vehicle
native CreateVehicle(modelid, Float:x, Float:y, Float:z, Float:angle, color1, color2);
native DeleteVehicle(vehicleid);
native GetVehiclePos(vehicleid, &Float:x, &Float:y, &Float:z);
native SetVehiclePos(vehicleid, Float:x, Float:y, Float:z,Float:rot);
native SetVehicleHealth(vehicleid, Float:health);
native GetVehicleHealth(vehicleid, &Float:health);
native SetVehicleToRespawn(vehicleid);
native ChangeVehicleColor(vehicleid, color1, color2);
native SetVehicleDoorsStatus(vehicleid,bool);
native SetVehicleTyre(vehicleid,bool);
native KillVehicleEngine(vehicleid);
native PutDirectlyInVehicle(playerid,vehicleid);
native SetVehicleAlarm(vehicleid,bool);
native SetVehicleLights(vehicleid,bool);

// Rcon
native SendRconEvent(const format[], {Float,_}:...);
native SendRconCommand(const format[], {Float,_}:...);

// --------------------------------------------------
// Defines
// --------------------------------------------------

// States
#define PLAYER_STATE_NONE						0
#define PLAYER_STATE_ONFOOT						1
#define PLAYER_STATE_DRIVER						2
#define PLAYER_STATE_PASSENGER					3
#define PLAYER_STATE_EXIT_VEHICLE				4 // (used internally)
#define PLAYER_STATE_ENTER_VEHICLE_DRIVER		5 // (used internally)
#define PLAYER_STATE_ENTER_VEHICLE_PASSENGER	6 // (used internally)
#define PLAYER_STATE_WASTED						7
#define PLAYER_STATE_SPAWNED					8

// Misc
#define MAX_PLAYER_NAME							24
#define MAX_PLAYERS								100
#define MAX_VEHICLES							254
#define INVALID_PLAYER_ID						255
#define NO_TEAM									255

// Weapons
#define WEAPON_UNARMED					0
#define WEAPON_BRASSKNUCKLE				1
#define WEAPON_SCREWDRIVER				2
#define WEAPON_GOLFCLUB					3
#define WEAPON_NITESTICK				4
#define WEAPON_KNIFECUR					5
#define WEAPON_BASEBALL_BAT				6
#define WEAPON_HAMMER					7
#define WEAPON_CLEAVER					8
#define WEAPON_MACHETE					9
#define WEAPON_KATANA					10
#define WEAPON_CHAINSAW					11
#define WEAPON_GRENADE					12
#define WEAPON_TEARGAS					14
#define WEAPON_MOLOTOV					15
#define WEAPON_MISSILE					16
#define WEAPON_COLT45					17
#define WEAPON_PYTHON					18
#define WEAPON_CHROMEGUN				19
#define WEAPON_SHOTGSPA					20
#define WEAPON_BUDDYSHOT				21
#define WEAPON_TEC9						22
#define WEAPON_UZI						23
#define WEAPON_INGRAMSL					24
#define WEAPON_MP5LNG					25
#define WEAPON_M4						26
#define WEAPON_RUGER					27
#define WEAPON_SNIPER					28
#define WEAPON_LASER					29
#define WEAPON_ROCKETLA					30
#define WEAPON_FLAME					31
#define WEAPON_M60						32
#define WEAPON_MINIGUN					33
#define WEAPON_BOMB						34
#define WEAPON_HELICANNON				35
#define WEAPON_CAMERA					36
#define WEAPON_COLLISION				39
#define WEAPON_FALL						41
#define WEAPON_DRIVEBY					42
#define WEAPON_DROWN					43
#define WEAPON_WATER					50
#define WEAPON_EXPLOSION				51
/*
// --------------------------------------------------
// Forwards (Callback declarations)
// --------------------------------------------------

forward OnGameModeInit();
forward OnGameModeExit();
forward OnFilterScriptInit();
forward OnFilterScriptExit();
forward OnPlayerConnect(playerid);
forward OnPlayerDisconnect(playerid, reason);
forward OnPlayerSpawn(playerid, classid);
forward OnPlayerDeath(playerid, killerid, reason, bodypart);
forward OnPlayerText(playerid, text[]);
forward OnPlayerCommandText(playerid, cmdtext[]);
forward OnPlayerRequestClass(playerid, classid);
forward OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
forward OnPlayerExitVehicle(playerid, vehicleid);
forward OnPickedUp(pickupid, playerid);
forward OnRconCommand(cmdtext[]);
*/
