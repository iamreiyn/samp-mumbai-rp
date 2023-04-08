#include <a_samp>
#if defined _G_Util_included
	#endinput
#endif
#define _G_Util_included
#pragma library G_Util
stock MoverJugador(playerid,Float:x,Float:y,Float:z,Float:angulo,Mundo,Int)
{
	if(!IsPlayerInAnyVehicle(playerid))
	{
		SetPlayerPos(playerid,x,y,z);
		SetPlayerFacingAngle(playerid,angulo);
		SetPlayerInterior(playerid,Int);
		SetPlayerVirtualWorld(playerid,Mundo);
	}
	else
	{
		SetVehiclePos(GetPlayerVehicleID(playerid),x,y,z);
		SetVehicleZAngle(GetPlayerVehicleID(playerid),angulo);
		SetPlayerInterior(playerid,Int);
		LinkVehicleToInterior(GetPlayerVehicleID(playerid),Int);
		SetPlayerVirtualWorld(playerid,Mundo);
		SetVehicleVirtualWorld(GetPlayerVehicleID(playerid),Mundo);
	}
}
stock RepararVehiculo(vehicleid)
{
	SetVehicleHealth(vehicleid,1000);
}
stock RepararJugadorVehiculo(playerid)
{
	RepararVehiculo(GetPlayerVehicleID(playerid));
}
stock FlipVehiculo(vehicleid)
{
	new Float:angulo,Float:vvida;
	GetVehicleZAngle(vehicleid,angulo);
	GetVehicleHealth(vehicleid,vvida);
	if(vvida < 250)
	{
		SetVehicleHealth(vehicleid,1000);
	}
	SetVehicleZAngle(vehicleid,angulo);
}
stock FlipJugadorVehiculo(playerid)
{
	FlipVehiculo(GetPlayerVehicleID(playerid));
}
stock GivePlayerHealth(playerid,Float:health)
{
	new Float:pvida;
	GetPlayerHealth(playerid,pvida);
	SetPlayerHealth(playerid,pvida+health);
}
stock GivePlayerArmour(playerid,Float:armour)
{
	new Float:armadura;
	GetPlayerArmour(playerid,armadura);
	SetPlayerArmour(playerid,armadura+armour);
}
stock GivePlayerAmmo(playerid,weapon,ammo)
{
	new arma[2], weaponslot;
	if((weapon < 0) || (weapon > 18 || weapon < 22) || (weapon > 46)) return 0;
	if((weapon > 0 && < 16) || (weapon < 47 && weapon > 43) || (weapon == 40))
	{	
		GivePlayerWeapon(playerid,weapon,ammo);
	}
	else
	{
		if((weapon > 15 && weapon < 19) || (weapon == 39)) weaponslot = 8;
		if(weapon > 21 && weapon < 25) weaponslot = 2;
		if(weapon > 24 && weapon < 28) weaponslot = 3;
		if(weapon > 27 && weapon < 33) weaponslot = 4;
		if(weapon > 29 && weapon < 32) weaponslot = 5;
		if(weapon > 32 && weapon < 35) weaponslot = 6;
		if(weapon > 34 && weapon < 39) weaponslot = 7;
		if(weapon > 40 && weapon < 44) weaponslot = 9;
		GetPlayerWeaponData(playerid,weaponslot,arma[0],arma[1]);
		GivePlayerWeapon(playerid,weapon,arma[1]+ammo);
	}
}
stock GivePlayerScore(playerid,score)
{
	new puntos;
	puntos = GetPlayerScore(playerid);
	SetPlayerScore(playerid,puntos+score);
}
stock GivePlayerWantedLevel(playerid,level)
{
	new nivel;
	nivel = GetPlayerWantedLevel(playerid);
	SetPlayerWantedLevel(playerid,nivel+level);
}
stock JugadorEnCoche(playerid)
{
	new m = GetVehicleModel(GetPlayerVehicleID(playerid));
	if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		if(m==445||m==602||m==416||m==485||m==568||m==429||m==433||m==499||m==424||m==536||m==496||m==504||m==422||
		   m==609||m==498||m==401||m==575||m==518||m==402||m==541||m==482||m==431||m==438||m==457||m==527||m==483||
		   m==524||m==415||m==542||m==589||m==437||m==532||m==480||m==596||m==599||m==597||m==598||m==578||m==486||
		   m==507||m==562||m==585||m==427||m==419||m==587||m==490||m==528||m==533||m==544||m==407||m==565||m==455||
		   m==530||m==526||m==466||m==604||m==492||m==474||m==588||m==434||m==502||m==503||m==494||m==579||m==545||
		   m==411||m==546||m==559||m==508||m==571||m==400||m==403||m==517||m==410||m==551||m==500||m==418||m==572||
		   m==423||m==414||m==516||m==582||m==467||m==443||m==470||m==404||m==514||m==603||m==600||m==413||m==426||
		   m==436||m==547||m==489||m==441||m==594||m==564||m==515||m==479||m==534||m==432||m==505||m==442||m==440||
		   m==475||m==543||m==605||m==495||m==567||m==428||m==405||m==535||m==458||m==580||m==439||m==561||m==409||
		   m==560||m==550||m==506||m==601||m==574||m==566||m==549||m==420||m==459||m==576||m==525||m==531||m==408||
		   m==583||m==451||m==558||m==552||m==540||m==491||m==412||m==578||m==421||m==529||m==555||m==456||m==554||
		   m==477||m==406||m==573||m==444||m==556||m==557||m==435||m==450||m==591||m==606||m==607||m==610||m==584||
		   m==608||m==611) return 1;
	}
	return 0;
}
stock JugadorEnMoto(playerid)
{
	new m = GetVehicleModel(GetPlayerVehicleID(playerid));
	if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		if(m==522||m==462||m==521||m==461||m==463||m==581||m==448||m==586||m==523||m==468||m==471) return 1;
	}
	return 0;
}
stock JugadorEnAvion(playerid)
{
	new m = GetVehicleModel(GetPlayerVehicleID(playerid));
	if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		if(m==520||m==476||m==593||m==553||m==513||m==512||m==577||m==592||m==511||m==539||m==464||m==460||m==519) return 1;
	}
	return 0;
}
stock JugadorEnHelicoptero(playerid)
{
	new m = GetVehicleModel(GetPlayerVehicleID(playerid));
	if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		if(m==548||m==425||m==417||m==487||m==497||m==563||m==501||m==465||m==447||m==469||m==488) return 1;
	}
	return 0;
}
stock JugadorEnBarco(playerid)
{
	new m = GetVehicleModel(GetPlayerVehicleID(playerid));
	if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		if(m==472||m==473||m==493||m==595||m==484||m==430||m==453||m==452||m==446||m==454) return 1;
	}
	return 0;
}
stock JugadorEnTren(playerid)
{
	new m = GetVehicleModel(GetPlayerVehicleID(playerid));
	if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		if(m==590||m==569||m==537||m==538||m==570||m==449) return 1;
	}
	return 0;
}
stock JugadorEnBici(playerid)
{
	new m = GetVehicleModel(GetPlayerVehicleID(playerid));
	if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		if(m==481||m==509||m==510) return 1;
	}
	return 0;
}
stock EsNumerico(const string[]) {//Codigo sacado de dutils
	new length=strlen(string);
	if (length==0) return false;
	for (new i = 0; i < length; i++) {
		if (
		(string[i] > '9' || string[i] < '0' && string[i]!='-' && string[i]!='+') // No es un numero,'+' o '-'
		|| (string[i]=='-' && i!=0)                                             // Un '-' pero no es el primero.
		|| (string[i]=='+' && i!=0)                                             // Un '+' pero no es el primero.
		) return false;
	}
	if (length==1 && (string[0]=='-' || string[0]=='+')) return false;
	return true;
}
stock JugadorNombre(playerid) {//Codigo sacado de LAdmin
  new nombre[MAX_PLAYER_NAME];
  GetPlayerName(playerid, nombre, sizeof(nombre));
  return nombre;
}
/*
native MoverJugador(playerid,Float:x,Float:y,Float:z,Float:angulo,Mundo,Int);
native RepararVehiculo(vehicleid);
native RepararJugadorVehiculo(playerid);
native FlipVehiculo(vehicleid);
native FlipJugadorVehiculo(playerid);
native GivePlayerHealth(playerid,Float:health);
native GivePlayerArmor(playerid,armour);
native GivePlayerAmmo(playerid,weapon,ammo);
native GivePlayerScore(playerid,score);
native GivePlayerWantedLevel(playerid,level);
native JugadorEnCoche(playerid);
native JugadorEnMoto(playerid);
native JugadorEnAvion(playerid);
native JugadorEnHelicoptero(playerid);
native JugadorEnBarco(playerid);
native JugadorEnTren(playerid);
native JugadorEnBici(playerid);
native EsNumerico(const string[]);
native JugadorNombre(playerid);
*/