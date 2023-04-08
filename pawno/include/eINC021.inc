#pragma tabsize 0
#include <dutils>
#include <dudb>
new bool:SaveVehiclesaa = false;
forward terminatephone();
new textcolaa = 0x80808096;
new bool:conectmessaa = false;
new HasConnectedMessageaa[256] = "";
new HasDisconnectedMessageaa[256] = "";
new PhoneMessageaa[256] = "";
new bool:usephones = false;
new terminatekey = KEY_ACTION;
new PickupGroupaa[400];
new fuelaa[MAX_VEHICLES];
new bool:doorlockaa[MAX_VEHICLES];
new bool:FuelSystemaa;
new FuelDTimeaa = 20000;
new WordFuel[256] = "Fuel";
new Unitsaa[256] = "l";
new usefuelaa[MAX_VEHICLES];
new spawnfuel = 20;
forward Dfuelaa(vehicleid,playerid);
#define dcmd(%1,%2,%3) if ((strcmp((%3)[1], #%1, true, (%2)) == 0) && ((((%3)[(%2) + 1] == 0) && (dcmd_%1(playerid, "")))||(((%3)[(%2) + 1] == 32) && (dcmd_%1(playerid, (%3)[(%2) + 2]))))) return 1
new PlayerWeapon[MAX_PLAYERS],PlayerAmmo[MAX_PLAYERS];
new PlayerWeapon2[MAX_PLAYERS],PlayerAmmo2[MAX_PLAYERS];
new PlayerWeapon3[MAX_PLAYERS],PlayerAmmo3[MAX_PLAYERS];
new PlayerWeapon4[MAX_PLAYERS],PlayerAmmo4[MAX_PLAYERS];
new PlayerWeapon5[MAX_PLAYERS],PlayerAmmo5[MAX_PLAYERS];
new PlayerWeapon6[MAX_PLAYERS],PlayerAmmo6[MAX_PLAYERS];
new PlayerWeapon7[MAX_PLAYERS],PlayerAmmo7[MAX_PLAYERS];
new PlayerWeapon8[MAX_PLAYERS],PlayerAmmo8[MAX_PLAYERS];
// CAR COLORS DEFINES
#define CARCOL_WHITE 1
#define CARCOL_SILVER 8
#define CARCOL_GREY 15
#define CARCOL_BLACK 0
#define CARCOL_GREEN 86
#define CARCOL_DARKGREEN 44
#define CARCOL_RED 3
#define CARCOL_DARKRED 43
#define CARCOL_BLUE 7
#define CARCOL_DARKBLUE 79
#define CARCOL_GOLD 6
#define CARCOL_BROWN 123
#define CARCOL_DARKBROWN 66
#define CARCOL_PINK 126
#define CARCOL_VIOLET 5

// TEXT COLORS DEFINES
#define TEXTCOL_WHITE 0xFFFFFF96
#define TEXTCOL_SILVER 0xD2D2D296
#define TEXTCOL_GREY 0x80808096
#define TEXTCOL_BLACK 0x00000096
#define TEXTCOL_GREEN 0x98B13496
#define TEXTCOL_DARKGREEN 0x00800096
#define TEXTCOL_RED 0xFF000096
#define TEXTCOL_DARKRED 0xA6000096
#define TEXTCOL_BLUE 0x6FA7FB96
#define TEXTCOL_DARKBLUE 0x0000A896
#define TEXTCOL_GOLD 0xE3B92496
#define TEXTCOL_BROWN 0xC1762B96
#define TEXTCOL_DARKBROWN 0x80400096
#define TEXTCOL_PINK 0xFF80FF96
#define TEXTCOL_VIOLET 0xAD5BFF96


//VEHICLE MODELS DEFINES
#define BF400 581
#define POLICE_BIKE 523
#define FAGGIO 462
#define FCR900 521
#define FREEWAY 463
#define NRG500 522
#define PCJ600 461
#define PIZZABOY 448
#define SANCHEZ 468
#define WAYFARER 586

#define BIKE 509
#define BMX 481
#define MTBIKE 510

#define COASTG 472
#define DINGHY 473
#define JETMAX 493
#define LAUNCH 595
#define MARQUIS 484
#define PREDATOR 430
#define REEFER 453
#define SPEEDER 452
#define SQUALO 446
#define TROPIC 454

#define CARGOBOB 548
#define HUNTER 425
#define LEVIATHN 417
#define MAVERICK 487
#define POLMAV 497
#define RAINDANC 563
#define RCGOBLIN 501
#define RCRAIDER 465
#define SEASPAR 447
#define SPARROW 469
#define VCNMAV 488

#define DUMPER 406
#define DUNREIDE 573
#define MONSTER 444
#define MONSTERA 556
#define MONSTERB 557

#define ADMIRAL 445
#define ALPHA 602
#define AMBULAN 416
#define BAGGAGE 485
#define BANDITO 568
#define BANSHEE 429
#define BARRACKS 433
#define BENSON 499
#define BFINJECT 424
#define BLADE 536
#define BLISTAC 496
#define BLOODRA 504
#define BOBCAT 422
#define BOXBURG 422
#define BOXVILLE 498
#define BRAVURA 401
#define BROADWAY 575
#define BUCCANEE 518
#define BUFFALO 402
#define BULLET 541
#define BURRITO 482
#define BUS 431
#define CABBIE 438
#define CADDY 457
#define CADRONA 527
#define CAMPER 483
#define CAMPER 483
#define CEMENT 483
#define CHEETAH 415
#define CLOVER 542
#define CLUB 589
#define COACH 437
#define COMBINE 532
#define COMET 480
#define COPCARLA 596
#define COPCARRU 599
#define COPCARSF 597
#define COPCARVG 598
#define DFT30 578
#define DOZER 486
#define ELEGANT 507
#define ELEGY 562
#define EMPEROR 585
#define ENFORCER 527
#define ESPERANT 419
#define EUROS 587
#define FBIRANCH 490
#define FBITRUCK 407
#define FELTZER 533
#define FIRELA 544
#define FIRETRUCK 407
#define FLASH 565
#define FLATBED 455
#define FORKLIFT 530
#define FORTUNE 526
#define GLENDALE 466
#define GLENSHIT 604
#define GREENWOO 492
#define HERMES 474
#define HOTDOG 588
#define HOTKNIFE 434
#define HOTRINA 502
#define HOTRINB 503
#define HOTRING 494
#define HUNTLEY 579
#define HUSTLER 545
#define INFERNUS 411
#define INTRUDER 546
#define JESTER 559
#define JOURNEY 508
#define KART 571
#define LANDSTAL 400
#define LINERUN 403
#define MAJESTIC 517
#define MANANA 410
#define MARIT 551
#define MESA 500
#define MOONBEAM 418
#define MOWER 572
#define MRWHOOP 423
#define MULE 414
#define NEBULA 516
#define NEWSVAN 582
#define OCEANIC 467
#define PACKER 443
#define PATRIOT 470
#define PEREN 404
#define PETRO 514
#define PHOENIX 603
#define PICADRO 600
#define PONY 413
#define PREMIER 426
#define PREVION 436
#define PRIMO 547
#define RANCHER 489
#define RCBANDIT 441
#define RCCAM 594
#define RCTIGER 564
#define RDTRAIN 515
#define REGINA 479
#define REMINGTN 534
#define RHINO 432
#define RNCHLURE 505
#define ROMERO 442
#define RUMPO 440
#define SABRE 475
#define SABLER 543
#define SADLSHIT 605
#define SANDKING 495
#define SAVANNA 567
#define SECURICA 428
#define SENTINEL 405
#define SLAMVAN 535
#define SOLAIR 458
#define STAFFORD 580
#define STALLION 439
#define STRATUM 561
#define STRETCH 409
#define SULTAN 560
#define SUNRISE 550
#define SUPERGT 506
#define SWATVAN 601
#define SWEEPER 574
#define TAHOMA 566
#define TAMPA 549
#define TAXI 420
#define TOPFUN 459
#define TORNADO 576
#define TOWTRUCK 525
#define TRACTOR 531
#define TRASH 408
#define TUG 583
#define TURISMO 451
#define URANUS 558
#define UTILITY 552
#define VINCENT 540
#define VIRGO 491
#define VOODOO 412
#define WALTON 478
#define WASHING 421
#define WILLARD 529
#define WINDSOR 555
#define YANKEE 456
#define YOSEMITE
#define ZR350 477

#define ANDROM 592
#define AT400 577
#define BEAGLE 511
#define CROPDUST 512
#define DODO 593
#define HYDRA 520
#define NEVADA 553
#define RCBARON 464
#define RUSTLER 476
#define SHAMAL 519
#define SKIMMER 460
#define STUNT 513
#define VORTEX 539

#define QUAD 471

#define ARTICT1 435
#define ARTICT2 450
#define ARTICT3 591
#define BAGBOXA 606
#define BAGBOXB 607
#define FARMTR1 610
#define PETROTR 584
#define TUGSTAIR 608
#define UTILTRL 611

#define FREIBOX 590
#define FREIFLAT 569
#define FREIGHT 537
#define STREAK 538
#define STREAKC 570
#define TRAM 449

/*  Easy Functions
 *
 *  (c) 2007, KANiS
 *  You can copy, but not sell or rent this include!
 *  This comment must always be included!

// --------------------------------------------------
// Natives
// --------------------------------------------------

native =Place================();
native IsPlayerInPlace(playerid, Float:x_min, Float:x_max, Float:y_min, Float:y_max, Float:z_max, Float:z_min);
native IsVehicleInPlace(vehicleid, Float:x_min, Float:x_max, Float:y_min, Float:y_max, Float:z_max, Float:z_min);
native =Player=Stats=========();
native SaveAllStats(playerid, password[]);
native LoadAllStats(playerid, password[]);
native =Vehicles=============();
native GivePlayerVehicle(playerid,vehicle_model,color_1, color_2,respawn_time_in_seconds);
native VehicleDoorsLocked(vehicleid,toggle);
native IsVehicleDoorsLocked(vehicleid);
native =Fuel=System==========();
native UseFuelSystem(toggle);
native SetUpFuelSystem(TheWordFuel[],Units[],SpawnFuel,FuelDownTime);
native GiveVehicleFuel(vehicleid,fuel);
native GetVehicleFuel(vehicleid);
native =Pickups==============();
native AddStaticPicupEx(model,type,Float:x,Float:y,Float:z,groupid);
native GetPickupGroup(pickupid);
native ==Player==============();
native TeleportPlayer(playerid,x,y,z,angle,destination_interior);
native GivePlayerJetPack(playerid);
native GivePlayerVehicle(playerid,vehicle_model,color_1, color_2,respawn_time_in_seconds);
native StopPlayerSound(playerid);
native =Configuration========();
native UseConnectMessages(MessageTextColor,HasConnectedMessage[],HasDisconnectedMessage[]);
native UseMobilePhoneOnPm(PhoneMessage[],KeyToTerminateCall);
*/

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger){

	TogglePlayerControllable(playerid,true);
	if(doorlockaa[vehicleid]==true){
	new Float:xaa,Float:yaa,Float:zaa;
	GetPlayerPos(playerid,xaa,yaa,zaa);
	SetPlayerPos(playerid,xaa,yaa,zaa);
	}else{
		//Fuel is not used if player is on a bike or is a passenger!
		new vehiclemodelaa = GetVehicleModel(vehicleid);
		if (FuelSystemaa == true && vehiclemodelaa !=509 && vehiclemodelaa !=481 && vehiclemodelaa !=510 && ispassenger){
		    if(fuelaa[vehicleid]==0){TogglePlayerControllable(playerid,false);
				}else{
				new Messageaa[256];
				format(Messageaa,sizeof(Messageaa),"~n~~n~~n~~n~~n~~r~                                 %s:~w~ %i %s",WordFuel,fuelaa[vehicleid],Unitsaa);
				GameTextForPlayer(playerid,Messageaa,FuelDTimeaa,5);
				usefuelaa[vehicleid]=SetTimerEx("Dfuelaa",FuelDTimeaa,1,"ii",vehicleid,playerid);
				}

		}

	}
}

public Dfuelaa(vehicleid,playerid){
if(FuelSystemaa==true){
new Messageaa[256];
if(fuelaa[vehicleid]==0){TogglePlayerControllable(playerid,false);
KillTimer(usefuelaa[vehicleid]);
}else{
fuelaa[vehicleid]=fuelaa[vehicleid]-1;
format(Messageaa,sizeof(Messageaa),"~n~~n~~n~~n~~n~~r~                                 %s:~w~ %i %s",WordFuel,fuelaa[vehicleid],Unitsaa);
GameTextForPlayer(playerid,Messageaa,FuelDTimeaa,5);
}}else{KillTimer(usefuelaa[vehicleid]);}}

public OnPlayerExitVehicle(playerid, vehicleid){
new sttaa = GetPlayerState(playerid);
if (FuelSystemaa == true && sttaa != 3){
KillTimer(usefuelaa[vehicleid]);
GameTextForPlayer(playerid,"",1,5);
}
if (SaveVehiclesaa == true){
new masinid[256];
format(masinid,256,"%i",vehicleid-1);
if (!udb_Exists(masinid)){ udb_Create(masinid,"allpass");}
format(masinid,256,"Vehicle_%i",vehicleid-1);
new Float:x,Float:y,Float:z,Float:a;
GetVehiclePos(vehicleid, x, y, z);
GetVehicleZAngle(vehicleid, a);
dUserSetINT(masinid).("x", floatround(x));
dUserSetINT(masinid).("y", floatround(y));
dUserSetINT(masinid).("z", floatround(z));
dUserSetINT(masinid).("a", floatround(a));
}}

public OnVehicleSpawn(vehicleid){
fuelaa[vehicleid]=spawnfuel;
doorlockaa[vehicleid]=false;
if (SaveVehiclesaa == true){
for(new i=0;i<700;i++) {
new inter[256];
format(inter,256,"Vehicle_%i",i-1);
if (udb_Exists(inter)){
SetVehiclePos(i,dUserINT(inter).("x"),dUserINT(inter).("y"),dUserINT(inter).("z"));
SetVehicleZAngle(i,dUserINT(inter).("a"));
}}}}

stock UseVehiclePosSaveSystem(toggle)
{SaveVehiclesaa = toggle;}

public OnGameModeInit() {SetTimer("terminatephone",1000,1);}

public OnPlayerConnect(playerid)
{   if(conectmessaa==true){
	new nameaa[256], mesaa[256];
	GetPlayerName(playerid,nameaa,256);
	format(mesaa,sizeof(mesaa),"%s %s",nameaa, HasConnectedMessageaa);
	SendClientMessageToAll(textcolaa,mesaa);
}}

public OnPlayerDisconnect(playerid, reason)
{	if(conectmessaa==true){
	new nameaa[256], mesaa[256];
	GetPlayerName(playerid,nameaa,256);
	format(mesaa,sizeof(mesaa),"%s %s",nameaa,HasDisconnectedMessageaa);
}}

public OnPlayerPrivmsg(playerid, recieverid, text[])
{
if(usephones==true){
	new statea = GetPlayerState(playerid);
	new stateb = GetPlayerState(recieverid);
	new posa = GetPlayerSpecialAction(playerid);
	new posb = GetPlayerSpecialAction(recieverid);
	if (statea != 2 && statea != 3 && posa != SPECIAL_ACTION_USECELLPHONE){SendClientMessage(playerid,0x98B13496,PhoneMessageaa); SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USECELLPHONE);}
	if (stateb != 2 && stateb != 3 && posb != SPECIAL_ACTION_USECELLPHONE){SendClientMessage(recieverid,0x98B13496,PhoneMessageaa); SetPlayerSpecialAction(recieverid,SPECIAL_ACTION_USECELLPHONE);}
}}

public terminatephone() {
new lKeys, Mike1, Mike2;
for(new i = 0; i < MAX_PLAYERS; i++) {
GetPlayerKeys(i, lKeys, Mike1, Mike2);
if (lKeys & terminatekey) {
new pose = GetPlayerSpecialAction(i);
if(pose == SPECIAL_ACTION_USECELLPHONE){SetPlayerSpecialAction(i,SPECIAL_ACTION_STOPUSECELLPHONE);}
}}}

stock VehicleDoorsLocked(vehicleid,toggle){
doorlockaa[vehicleid]=toggle;
}

stock SetUpFuelSystem(TheWordFuel[],Units[],SpawnFuel,FuelDownTime){
WordFuel[256] = TheWordFuel[];
Unitsaa[256] = Units[];
spawnfuel = SpawnFuel;
FuelDTimeaa = FuelDownTime;
}

stock UseFuelSystem(toggle){
FuelSystemaa = toggle;
}

stock GiveVehicleFuel(vehicleid,fuel){
fuelaa[vehicleid]=fuelaa[vehicleid]+fuel;
}

stock IsVehicleDoorsLocked(vehicleid){
return doorlockaa[vehicleid];
}

stock GetVehicleFuel(vehicleid){
return fuelaa[vehicleid];
}

stock AddStaticPicupEx(model,type,Float:x,Float:y,Float:z,groupid){
new pickupidsaa = AddStaticPickup(model,type,Float:x,Float:y,Float:z);
PickupGroupaa[pickupidsaa] = groupid;
}

stock GetPickupGroup(pickupid){
return PickupGroupaa[pickupid];}


stock UseConnectMessages(MessageTextColor,HasConnectedMessage[],HasDisconnectedMessage[])
{
textcolaa = MessageTextColor;
conectmessaa = true;
HasConnectedMessageaa[256] = HasConnectedMessage;
HasDisconnectedMessageaa[256] = HasDisconnectedMessage;

}

stock UseMobilePhoneOnPm(PhoneMessage[],KeyToTerminateCall)
{terminatekey = KeyToTerminateCall;
PhoneMessageaa[256] = PhoneMessage}

stock GivePlayerJetPack(playerid)
{SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USEJETPACK);}

stock SaveAllStats(playerid,password[]) {
if (!udb_Exists(inter)){udb_Create(masinid,password);}
new pname[MAX_PLAYER_NAME];
new Float:x,Float:y,Float:z,Float:za,Float:a,Float:h;
new name[MAX_PLAYER_NAME]; GetPlayerName(playerid,name,sizeof(name));
GetPlayerArmour(playerid, Float:a);
GetPlayerHealth(playerid, Float:h);
GetPlayerFacingAngle(playerid,Float:za);
GetPlayerName(playerid,pname,sizeof(pname));
GetPlayerPos(playerid,x,y,z);
for(new w=0;w<13;w++){
GetPlayerWeaponData(playerid,1,PlayerWeapon[playerid],PlayerAmmo[playerid]);
GetPlayerWeaponData(playerid,2,PlayerWeapon2[playerid],PlayerAmmo2[playerid]);
GetPlayerWeaponData(playerid,3,PlayerWeapon3[playerid],PlayerAmmo3[playerid]);
GetPlayerWeaponData(playerid,4,PlayerWeapon4[playerid],PlayerAmmo4[playerid]);
GetPlayerWeaponData(playerid,5,PlayerWeapon5[playerid],PlayerAmmo5[playerid]);
GetPlayerWeaponData(playerid,6,PlayerWeapon6[playerid],PlayerAmmo6[playerid]);
GetPlayerWeaponData(playerid,7,PlayerWeapon7[playerid],PlayerAmmo7[playerid]);
GetPlayerWeaponData(playerid,8,PlayerWeapon8[playerid],PlayerAmmo8[playerid]);
dUserSetINT(pname).("X",floatround(x));
dUserSetINT(pname).("Y",floatround(y));
dUserSetINT(pname).("Z",floatround(z));
dUserSetINT(pname).("Za",floatround(za));
dUserSetINT(pname).("Armour",floatround(a));
dUserSetINT(pname).("Health",floatround(h));
dUserSetINT(pname).("Skin",floatround(GetPlayerSkin(playerid)));
dUserSetINT(pname).("Interior",floatround(GetPlayerInterior(playerid)));
dUserSetINT(pname).("Weapon1",floatround(PlayerWeapon[playerid]));
dUserSetINT(pname).("Ammo1",floatround(PlayerAmmo[playerid]));
dUserSetINT(pname).("Weapon2",floatround(PlayerWeapon2[playerid]));
dUserSetINT(pname).("Ammo2",floatround(PlayerAmmo2[playerid]));
dUserSetINT(pname).("Weapon3",floatround(PlayerWeapon3[playerid]));
dUserSetINT(pname).("Ammo3",floatround(PlayerAmmo3[playerid]));
dUserSetINT(pname).("Weapon4",floatround(PlayerWeapon4[playerid]));
dUserSetINT(pname).("Ammo4",floatround(PlayerAmmo4[playerid]));
dUserSetINT(pname).("Weapon5",floatround(PlayerWeapon5[playerid]));
dUserSetINT(pname).("Ammo5",floatround(PlayerAmmo5[playerid]));
dUserSetINT(pname).("Weapon6",floatround(PlayerWeapon5[playerid]));
dUserSetINT(pname).("Ammo6",floatround(PlayerAmmo5[playerid]));
dUserSetINT(pname).("Weapon7",floatround(PlayerWeapon5[playerid]));
dUserSetINT(pname).("Ammo7",floatround(PlayerAmmo5[playerid]));
dUserSetINT(pname).("Weapon8",floatround(PlayerWeapon5[playerid]));
dUserSetINT(pname).("Ammo8",floatround(PlayerAmmo5[playerid]));
}
new M = GetPlayerMoney(playerid);
dUserSetINT(pname).("Money",M);
new W = GetPlayerWantedLevel(playerid);
dUserSetINT(pname).("WLevel",W);

return 0;
}


stock LoadAllStats(playerid,password[]) {
new pname[MAX_PLAYER_NAME];
GetPlayerName(playerid,pname,sizeof(pname));
if (udb_Exists(pname)){
udb_CheckLogin(pname,password){
SetPlayerPos(playerid,dUserINT(pname).("X"),dUserINT(pname).("Y"),dUserINT(pname).("Z"));
SetPlayerSkin(playerid,dUserINT(pname).("Skin"));
ResetPlayerMoney(playerid);
ResetPlayerWeapons(playerid);
GivePlayerWeapon(playerid,dUserINT(pname).("WA"),dUserINT(pname).("AA"));
GivePlayerWeapon(playerid,dUserINT(pname).("WB"),dUserINT(pname).("AB"));
GivePlayerWeapon(playerid,dUserINT(pname).("WC"),dUserINT(pname).("AC"));
SetPlayerFacingAngle(playerid,dUserINT(pname).("Za"));
GivePlayerMoney(playerid,dUserINT(pname).("Money"));
SetPlayerWantedLevel(playerid,dUserINT(pname).("WLevel"));
SetPlayerArmour(playerid,dUserINT(pname).("Armour"));
SetPlayerHealth(playerid,dUserINT(pname).("Health"));
SetPlayerInterior(playerid,dUserINT(pname).("Interior"));
GivePlayerWeapon(playerid,dUserINT(pname).("Weapon1"),dUserINT(pname).("Ammo1"));
GivePlayerWeapon(playerid,dUserINT(pname).("Weapon2"),dUserINT(pname).("Ammo2"));
GivePlayerWeapon(playerid,dUserINT(pname).("Weapon3"),dUserINT(pname).("Ammo3"));
GivePlayerWeapon(playerid,dUserINT(pname).("Weapon4"),dUserINT(pname).("Ammo4"));
GivePlayerWeapon(playerid,dUserINT(pname).("Weapon5"),dUserINT(pname).("Ammo5"));
GivePlayerWeapon(playerid,dUserINT(pname).("Weapon6"),dUserINT(pname).("Ammo6"));
GivePlayerWeapon(playerid,dUserINT(pname).("Weapon7"),dUserINT(pname).("Ammo7"));
GivePlayerWeapon(playerid,dUserINT(pname).("Weapon8"),dUserINT(pname).("Ammo8"));
return 1;
}}}

stock StopPlayerSound(playerid) {
PlayerPlaySound(playerid,1098,0,0,0);
return 0;
}

stock GivePlayerVehicle(playerid,vehicle_model,color_1, color_2,respawn_time_in_seconds) {
new Float:x,Float:y,Float:z,Float:a;
GetPlayerPos(playerid,x,y,z);
GetPlayerFacingAngle(playerid,a);
new rs_delay = respawn_time_in_seconds*1000;
CreateVehicle(vehicle_model,x,y,z,a,color_1,color_2,rs_delay);
}

stock TeleportPlayer(playerid,x,y,z,angle,destination_interior) {
if(IsPlayerInAnyVehicle(playerid))
{new VehID;
VehID = GetPlayerVehicleID(playerid);
SetVehiclePos(VehID,x,y,z);
SetVehicleZAngle(VehID,angle);
SetPlayerInterior(playerid,destination_interior);
LinkVehicleToInterior(VehID,destination_interior);
}else{
SetPlayerPos(playerid, x,y,z);
SetPlayerFacingAngle(playerid,angle);
SetPlayerInterior(playerid,destination_interior);
}}

stock IsPlayerInPlace(playerid, Float:x_min, Float:x_max, Float:y_min, Float:y_max, Float:z_min, Float:z_max) {
new Float:ix,Float:iy,Float:iz;
GetPlayerPos(playerid,ix,iy,iz);
if(ix <= x_min && ix >= x_max && iy <= y_min && iy >= y_max && iz >= z_min && iz <= z_max){
return true;
}else{
return false;
}}

stock IsVehicleInPlace(vehicleid, Float:x_min, Float:x_max, Float:y_min, Float:y_max, Float:z_min, Float:z_max) {
new Float:ix,Float:iy,Float:iz;
GetVehiclePos(vehicleid,ix,iy,iz);
if(ix <= x_min && ix >= x_max && iy <= y_min && iy >= y_max && iz >= z_min && iz <= z_max){
return true;
}else{
return false;
}}