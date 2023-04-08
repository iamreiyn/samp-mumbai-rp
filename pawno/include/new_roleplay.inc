/*  SA:MP Player Functions
 *
 *  (c) Copyright 2005-2006, SA:MP Team
 *
 */

#if defined _players_included
	#endinput
#endif
#define _players_included
#pragma library players


// Player info
native SetPlayerDrugs(playerid,drugs);
native GetPlayerDrugs(playerid);
native SetPlayerDrinks(playerid,drinks);
native GetPlayerDrinks(playerid);
native SetPlayerWorkouts(playerid,workouts);
native GetPlayerWorkouts(playerid);
native SetPlayerTickets(playerid,tickets);
native GetPlayerTickets(playerid);