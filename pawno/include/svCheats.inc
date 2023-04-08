//-----------------------------------------------------------------------------------|
//                                    [svCheats]                                     |
//                                                                                   |
//                                                                                   |
//   - You may not remove these credits                                              |
//   - You may not claim this script as yours                                        |
//                                                                                   |
//                                                                                   |
//                                                                                   |
// [VERSION 1.9]                                               Created by SuperViper |
//-----------------------------------------------------------------------------------|

#include <a_samp>
#include <sscanf2>

// ==================================== SETTINGS ================================== //|
//                                                                                  //|
/* Comment if you would like to use regular 'for' loops instead of foreach */       //|
#define USE_FOREACH                                                                 //|
//                                                                                  //|
/* Comment if you would like to use regular 'ALS' hooks instead of y_hooks */       //|
//#define USE_YHOOKS                                                                  //|
//                                                                                  //|
/* Comment if you would like to use regular 'strcmp' commands instead of ZCMD */    //|
#define USE_ZCMD                                                                    //|
//                                                                                  //|
/* Change this amount to set how fast the timer (in ms) to detect cheats runs */    //|
#define TIMER_TIME 1250                                                             //|
//                                                                                  //|
/* Comment this if you would like to disable the /acstats command */    			//|
#define ACSTATS_USED                                                                //|
//                                                                                  //|
/* Comment this if you would like to disable the /hh command */    					//|
#define HH_USED 		(1)                                                         //|
//                                                                                  //|
/* Comment the anticheat(s) that you dont want and change the security level */     //|
#define HIGH_PING 		(2)                                                         //|
#define WEAPON_SPAWN    (1)                                                         //|
#define SPEED_HACK 		(1)                                                         //|
#define JETPACK_HACK 	(1)                                                         //|
#define DRVBY_RESTRICT  (-1)                                                        //|
#define DDRIVEBY_OFF 	(-1)                                                        //|
#define SWEARING_OFF 	(-1)                                                        //|
//#define AIRBREAK_HACK (1)                                                         //|
#define BUNNYHOP_OFF 	(1)                                                         //|
#define FLY_HACK    	(1)                                                         //|
#define TELEPORT_HACK 	(1)                                                         //|
#define VEHICLE_REPAIR 	(1)                                                         //|
#define CHATSPAM_OFF    (-1)                                                        //|
#define AFK_DISABLED 	(2)                                                         //|
#define TABBED_DISABLED (2)                                                         //|
#define NINJAJACK_CHEAT (-1)                                                        //|
#define HEALTH_HACK		(1)                                                         //|
#define CARRAM_OFF  	(-1)                                                        //|
#define HELIBLADE_OFF  	(-1)                                                        //|
#define VEHMOD_HACK  	(1)                                                         //|
#define SERVERAD_CHEAT  (-1)                                                        //|
#define FAKEPLAYER_HACK (-1)                                                        //|
#define FAKEKLL_HACK    (-1)                                                        //|
#define REMOTEJACK_HACK (-1)                                                        //|
#define INVALIDMOD_HACK (-1)                                                        //|
#define GOIN_LOCKED_VEH (-1)                                                        //|
#define SPAMKILL_CHEAT  (-1)                                                        //|
//                                                                                  //|
//                                                                                  //|
//                                                                                  //|
/* Change the anticheat settings to best fit your server ----------------------- */ //|
//----------------------------------------------------------------------------------//|
#define MAX_PING 		(750) // Maximum server ping                                //|
//----------------------------------------------------------------------------------//|
#define USED_INTERIORS  "1 2" // Used interiors separated by a space                //|
//----------------------------------------------------------------------------------//|
#define MAX_SPEED 		(198) // Maximum vehicle speed                              //|
//----------------------------------------------------------------------------------//|
#define DRIVEBY_WEAPONS "28 29 32" // Driveby allowed weapons separated by a space  //|
//----------------------------------------------------------------------------------//|
#define BUNNYHOP_AMOUNT (6) // Amount of jumps before it's called bunny hopping     //|
//----------------------------------------------------------------------------------//|
#define CHATSPAM_LINES  (4) // Amount of lines sent before it's called spam         //|
//----------------------------------------------------------------------------------//|
#define AFK_MINUTES 	(10) // Amount of minutes before a person is AFK            //|
//----------------------------------------------------------------------------------//|
#define SERVER_IP       "127.0.0.1" // IP of your server                            //|
#define SERVER_DOMAIN   "samp.servername.com" // Optional server domain             //|
//----------------------------------------------------------------------------------//|
new CurseWords[][] = {"ass", "bitch", "shit", "fuck", "nigger", "cunt", "whore"};   //|
//----------------------------------------------------------------------------------//|
#define DETECT_KILLS    (5) // Amount of kills in X seconds for spamkill detection  //|
#define DETECT_SECONDS  (20) // Amount of seconds in X kills for spamkill detection //|
//----------------------------------------------------------------------------------//|
// ================================================================================ //|
//                         DO NOT TOUCH ANYTHING BELOW THIS                         //|
// ================================================================================ //|

#if defined USE_FOREACH
	#tryinclude <foreach>
#endif

#if defined USE_YHOOKS
	#tryinclude <YSI\y_hooks>
#endif

#if defined USE_ZCMD
	#tryinclude <zcmd>
#endif

#if defined AIRBREAK_HACK
	#tryinclude <MapAndreas>
#endif

#define SVCS_svCheats

#define CHEAT_HIGH_PING 		(1)
#define CHEAT_WEAPON_SPAWN 		(2)
#define CHEAT_SPEED_HACK 		(3)
#define CHEAT_JETPACK_HACK 		(4)
#define CHEAT_DRIVEBY 			(5)
#define CHEAT_DDRIVEBY 			(6)
#define CHEAT_SWEARING 			(7)
#define CHEAT_AIRBREAK_HACK 	(8)
#define CHEAT_BUNNYHOP 			(9)
#define CHEAT_FLY_HACK 			(10)
#define CHEAT_TELEPORT_HACK 	(11)
#define CHEAT_VEHICLE_REPAIR 	(12)
#define CHEAT_CHATSPAM 			(13)
#define CHEAT_AFK 				(14)
#define CHEAT_TABBED            (15)
#define CHEAT_GODMODE           (16)
#define CHEAT_NINJAJACK         (17)
#define CHEAT_HEALTHHACK        (18)
#define CHEAT_CARRAM            (19)
#define CHEAT_HELIBLADE         (20)
#define CHEAT_VEHMOD            (21)
#define CHEAT_SERVERAD          (22)
#define CHEAT_FAKEPLAYER        (23)
#define CHEAT_FAKEKILL          (24)
#define CHEAT_REMOTEJACK        (25)
#define CHEAT_INVALIDMOD        (26)
#define CHEAT_LOCKEDVEH         (27)
#define CHEAT_SPAMKILL          (28)

forward svCheats_Detector();
forward svCheats_OnPlayerCheatUpdate(playerid, cheatid);

enum e_svCheats_HH
{
	svCheckedBy,
	bool: svInVehicle,
	svVehicleID,
	svVehicleSeat,
	Float: svOldPlayerPos[4],
	svInterior,
	svVirtualWorld,
	Float: svHealth,
	Float: svArmor,
}

enum e_svCheats_RemoteJack
{
	Float: svLofPos[3],
	svLastJackState,
}

enum e_svCheats_IPJoin
{
	svIP_Add,
 	svTimestamp,
}

new svCheats_SecurityLevel[MAX_PLAYERS], bool: svCheats_Debugging, bool: svCheats_Spawned[MAX_PLAYERS];
new bool: svCheats_GrantedJetpack[MAX_PLAYERS], Float: svCheats_VehicleHealth[MAX_VEHICLES] = 1000.0;
new svCheats_JumpCounters[MAX_PLAYERS], svCheats_JumpCounterTimer[MAX_PLAYERS];
new svCheats_PlayerWeapons[MAX_PLAYERS][13], svCheats_SpamCounters[MAX_PLAYERS];
new svCheats_AFKTime[MAX_PLAYERS], svCheats_LastAFKUpdate[MAX_PLAYERS], bool: svCheats_ReportedAFK[MAX_PLAYERS];
new Float: svCheats_oldPos[MAX_PLAYERS][3];
new svCheats_TabbedUpdates[MAX_PLAYERS], bool: svCheats_ReportedTabbed[MAX_PLAYERS], bool: svCheats_TabbedDisabled[MAX_PLAYERS];
new svCheats_HH[MAX_PLAYERS][e_svCheats_HH];
new svCheats_PossibleNinjaJack[MAX_PLAYERS];
new Float: svCheats_PlayerHealth[MAX_PLAYERS], Float: svCheats_PlayerArmor[MAX_PLAYERS], bool: svCheats_HealthHackDisabled[MAX_PLAYERS];
new svCheats_RemoteJack[MAX_PLAYERS][e_svCheats_RemoteJack];
new svCheats_IPJoin[37][e_svCheats_IPJoin], svCheats_ajs = 0;
new bool: svCheats_SkipPlayerLVCheck[MAX_PLAYERS];
new svCheats_KillAmount[MAX_PLAYERS];
new svCheats_AmountDetected;

Float: svCheats_GetDistance(Float: x1, Float: y1, Float: z1, Float: x2, Float: y2, Float: z2)
{
	return floatsqroot(floatpower(x1 - x2, 2.0) + floatpower(y1 - y2, 2.0) + floatpower(z1 - z2, 2.0));
}

#if defined USE_YHOOKS
#if defined FILTERSCRIPT
hook OnFilterScriptInit()
{
    new File: svCheats_Stats;

	if(!fexist("svCheats_Stats.txt"))
	{
	    svCheats_Stats = fopen("svCheats_Stats.txt", io_append);
	    fwrite(svCheats_Stats, "0");
	}
	else
	{
		new amountDetected[5];
		svCheats_Stats = fopen("svCheats_Stats.txt", io_read);
		fread(svCheats_Stats, amountDetected);
		svCheats_AmountDetected = strval(amountDetected);
	}

	fclose(svCheats_Stats);
    SetTimer("svCheats_Detector", TIMER_TIME, 1);
	return 1;
}

hook OnFilterScriptExit()
{
    new amountDetected[5], File: svCheats_Stats = fopen("svCheats_Stats.txt", io_write);
	format(amountDetected, sizeof(amountDetected), "%d", svCheats_AmountDetected);
	fwrite(svCheats_Stats, amountDetected);
	fclose(svCheats_Stats);
	return 1;
}
#else
hook OnGameModeInit()
{
	new File: svCheats_Stats;
	
	if(!fexist("svCheats_Stats.txt"))
	{
	    svCheats_Stats = fopen("svCheats_Stats.txt", io_append);
	    fwrite(svCheats_Stats, "0");
	}
	else
	{
		new amountDetected[5];
		svCheats_Stats = fopen("svCheats_Stats.txt", io_read);
		fread(svCheats_Stats, amountDetected);
		svCheats_AmountDetected = strval(amountDetected);
	}
	
	fclose(svCheats_Stats);
    SetTimer("svCheats_Detector", TIMER_TIME, 1);
	return 1;
}

hook OnGameModeExit()
{
    new amountDetected[5], File: svCheats_Stats = fopen("svCheats_Stats.txt", io_write);
	format(amountDetected, sizeof(amountDetected), "%d", svCheats_AmountDetected);
	fwrite(svCheats_Stats, amountDetected);
	fclose(svCheats_Stats);
	return 1;
}
#endif
hook OnPlayerConnect(playerid)
{
	svCheats_SecurityLevel[playerid] = 0;
	
	#if defined FAKEPLAYER_HACK
 	new playersIP[17];
  	GetPlayerIp(playerid, playersIP, 17);
   	if(strcmp(playersIP, "255.255.255.255") == 0 || (strcmp(SERVER_IP, "127.0.0.1") && strcmp(playersIP, "127.0.0.1") == 0 && !IsPlayerNPC(playerid)))
   	{
		svCheats_CallDetection(playerid, CHEAT_FAKEPLAYER);
    }
    
    svCheats_log_new_join(playerid);
    if(svCheats_NJTR(playerid, 5000) >= 3)
    {
        svCheats_CallDetection(playerid, CHEAT_FAKEPLAYER);
    }
	#endif

	#if defined JETPACK_HACK
	svCheats_GrantedJetpack[playerid] = false;
	#endif

	#if defined BUNNYHOP_OFF
	svCheats_JumpCounters[playerid] = 0;
	svCheats_JumpCounterTimer[playerid] = -1;
	#endif

	#if defined CHATSPAM_OFF
	svCheats_SpamCounters[playerid] = 0;
	#endif

	#if defined WEAPON_SPAWN
	for(new i = 0; i < 13; i++)
	{
	    svCheats_PlayerWeapons[playerid][i] = 0;
	}
	#endif
	
	#if defined AFK_DISABLED
	svCheats_AFKTime[playerid] = 0;
	svCheats_LastAFKUpdate[playerid] = GetTickCount();
	svCheats_ReportedAFK[playerid] = false;
	#endif
	
	#if defined TABBED_DISABLED
	svCheats_TabbedUpdates[playerid] = 0;
	svCheats_ReportedTabbed[playerid] = false;
	svCheats_TabbedDisabled[playerid] = true;
	#endif
	
	svCheats_HH[playerid][svCheckedBy] = INVALID_PLAYER_ID;
	
	#if defined NINJAJACK_CHEAT
	svCheats_PossibleNinjaJack[playerid] = INVALID_PLAYER_ID;
	#endif
	
	#if defined GOIN_LOCKED_VEH
	svCheats_SkipPlayerLVCheck[playerid] = false;
	#endif
	
	#if defined SPAMKLL_CHEAT
	svCheats_KillAmount[playerid] = 0;
	#endif
	
	svCheats_Spawned[playerid] = false;
	return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	#if defined BUNNYHOP_OFF
		if(newkeys & KEY_JUMP)
		{
		    if(svCheats_SecurityLevel[playerid] < BUNNYHOP_OFF || BUNNYHOP_OFF == -1)
		    {
			    new ai = GetPlayerAnimationIndex(playerid);
			    if(ai != 1061 && ai != 1062 && ai != 1064 && ai != 1066 && ai != 1195 && ai != 1997 && ai != 1538 || ai != 1538 || ai != 1543)
			    {
					svCheats_JumpCounters[playerid]++;

					if(svCheats_JumpCounterTimer[playerid] > -1)
					{
					    KillTimer(svCheats_JumpCounterTimer[playerid]);
					    svCheats_JumpCounterTimer[playerid] = -1;
					}

					if(svCheats_JumpCounters[playerid] == BUNNYHOP_AMOUNT)
					{
					    svCheats_JumpCounters[playerid] = 0;
					    svCheats_CallDetection(playerid, CHEAT_BUNNYHOP);
					    svCheats_AmountDetected++;
					}
					else
					{
						svCheats_JumpCounterTimer[playerid] = SetTimerEx("svCheats_JumpCountersDown", 2000, 0, "i", playerid);
					}
			    }
		    }
		}
	#endif
	
	#if defined WEAPON_SPAWN
		if(newkeys & KEY_FIRE)
		{
		    if(svCheats_SecurityLevel[playerid] < WEAPON_SPAWN || WEAPON_SPAWN == -1)
		    {
			    new w = GetPlayerWeapon(playerid);
			    if(w > 0 && w < 46)
			    {
					if(svCheats_PlayerWeapons[playerid][svCheats_GetWeaponSlot(w)] != w)
					{
					    svCheats_CallDetection(playerid, CHEAT_WEAPON_SPAWN);
					    svCheats_AmountDetected++;
					}
			    }
		    }
		}
	#endif
	return 1;
}

hook OnPlayerText(playerid, text[])
{
	#if defined SWEARING_OFF
	    if(svCheats_SecurityLevel[playerid] < SWEARING_OFF || SWEARING_OFF == -1)
	    {
			for(new c = 0; c < sizeof(CurseWords); c++)
			{
				if(strfind(text, CurseWords[c], true) > -1)
				{
				    svCheats_CallDetection(playerid, CHEAT_SWEARING);
				    svCheats_AmountDetected++;
				    return 0;
				}
			}
		}
	#endif
	
	#if defined CHATSPAM_OFF
	    if(svCheats_SecurityLevel[playerid] < CHATSPAM_OFF || CHATSPAM_OFF == -1)
	    {
	        svCheats_SpamCounters[playerid]++;
	        
	        if(svCheats_SpamCounters[playerid] == CHATSPAM_LINES)
	        {
	            svCheats_SpamCounters[playerid] = 0;
				svCheats_CallDetection(playerid, CHEAT_CHATSPAM);
				svCheats_AmountDetected++;
				return 0;
	        }
	    }
	#endif
	
	#if defined AFK_DISABLED
	    if(svCheats_SecurityLevel[playerid] < AFK_DISABLED || AFK_DISABLED == -1)
	    {
	        svCheats_AFKTime[playerid] = 0;
	        svCheats_ReportedAFK[playerid] = false;
	    }
	#endif
	
	#if defined SERVERAD_CHEAT
	    if(svCheats_SecurityLevel[playerid] < SERVERAD_CHEAT || SERVERAD_CHEAT == -1)
	    {
	        new dotCount, numCount;
	        
			for(new i = 0; i < strlen(text); i++)
			{
			    if(text[i] == '.')
			    {
			        dotCount++;
			    }
			    else if(text[i] >= '0' && text[i] <= '9')
			    {
			        numCount++;
			    }
			}
			
			if(dotCount >= 2 && (numCount >= 7 || strfind(text, "samp.") > -1))
			{
			    if(strfind(text, SERVER_IP) == -1 && strfind(text, SERVER_DOMAIN, true) == -1)
			    {
					svCheats_CallDetection(playerid, CHEAT_SERVERAD);
				}
			}
	    }
	#endif
	return 0;
}

#if defined VEHICLE_REPAIR
hook OnVehicleSpawn(vehicleid)
{
	svCheats_VehicleHealth[vehicleid] = 1000.0;
	return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
	if(newstate == PLAYER_STATE_DRIVER)
	{
	    #if defined VEHICLE_REPAIR
     		new vehicleid = GetPlayerVehicleID(playerid);
     		GetVehicleHealth(vehicleid, svCheats_VehicleHealth[vehicleid]);
	    #endif

	    #if defined NINJAJACK_OFF
			#if defined USE_FOREACH
				foreach(new i: Player)
				{
				    if(svCheats_PossibleNinjaJack[i] == playerid)
				    {
				        svCheats_PossibleNinjaJack[i] = INVALID_PLAYER_ID;
				        break;
				    }
				}
			#else
			    for(new i = 0; i < MAX_PLAYERS; i++)
				{
				    if(IsPlayerConnected(i))
					{
					    if(svCheats_PossibleNinjaJack[i] == playerid)
					    {
					        svCheats_PossibleNinjaJack[i] = INVALID_PLAYER_ID;
					        break;
					    }
				    }
				}
			#endif
	    #endif
	}
	
	if(newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
	{
	    #if defined GOIN_LOCKED_VEH
	        if(svCheats_SecurityLevel[playerid] < GOIN_LOCKED_VEH || GOIN_LOCKED_VEH == -1)
	        {
	            if(svCheats_SkipPlayerLVCheck[playerid] == false)
	            {
	                new engine, lights, alarm, doors, bonnet, boot, objective;
	                GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);
	                if(doors)
	                {
	                    svCheats_CallDetection(playerid, CHEAT_LOCKEDVEH);
	                }
	            }
	            else
	            {
	                svCheats_SkipPlayerLVCheck[playerid] = false;
	            }
	        }
	    #endif
	}
	return 1;
}
#endif

#if defined CHEAT_TABBED
hook OnPlayerUpdate(playerid)
{
	svCheats_TabbedUpdates[playerid] = 0;
	svCheats_ReportedTabbed[playerid] = false;
	
	#if defined CHEAT_REMOTEJACK
		new playersVehicle = GetPlayerVehicleID(playerid);

	    if(!IsPlayerInAnyVehicle(playerid))
	    {
	    	GetPlayerPos(playerid, svCheats_RemoteJack[playerid][svLofPos][0], svCheats_RemoteJack[playerid][svLofPos][1], svCheats_RemoteJack[playerid][svLofPos][2]);
		}

	    if((playersVehicle != svCheats_RemoteJack[playerid][svLastJackState]) && playersVehicle != 0 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{
	        new Float: playersPos[3], Float: distancejack = svCheats_GetDistance(playersPos[0], playersPos[1], playersPos[2], svCheats_RemoteJack[playerid][svLofPos][0], svCheats_RemoteJack[playerid][svLofPos][1], svCheats_RemoteJack[playerid][svLofPos][2]), thiscaride = GetVehicleModel(playersVehicle), Float: distanceth = 10;
	        GetVehiclePos(playersVehicle, playersPos[0], playersPos[1], playersPos[2]);

	        if(thiscaride == 577 || thiscaride == 592)
	        {
				distanceth = 25.0;
			}

	        if(distancejack > distanceth)
			{
	            svCheats_CallDetection(playerid, CHEAT_REMOTEJACK);
	        }

	        GetPlayerPos(playerid, svCheats_RemoteJack[playerid][svLofPos][0], svCheats_RemoteJack[playerid][svLofPos][1], svCheats_RemoteJack[playerid][svLofPos][2]);

	        svCheats_RemoteJack[playerid][svLastJackState] = playersVehicle;
	    }
	#endif
	return 1;
}

hook OnPlayerSpawn(playerid)
{
	svCheats_TabbedDisabled[playerid] = false;
	svCheats_Spawned[playerid] = true;
	svCheats_GrantedJetpack[playerid] = false;
	
	#if defined HEALTH_HACK
	svCheats_PlayerHealth[playerid] = 1000;
	svCheats_PlayerArmor[playerid] = 0;
	svCheats_HealthHackDisabled[playerid] = false;
	#endif
	return 1;
}
#endif

hook OnPlayerDeath(playerid, killerid, reason)
{
	svCheats_TabbedDisabled[playerid] = true;
	svCheats_HealthHackDisabled[playerid] = true;

	if(killerid == INVALID_PLAYER_ID)
	{
		if(svCheats_PossibleNinjaJack[playerid] != INVALID_PLAYER_ID)
		{
		    svCheats_CallDetection(svCheats_PossibleNinjaJack[playerid], CHEAT_NINJAJACK);
		    svCheats_PossibleNinjaJack[playerid] = INVALID_PLAYER_ID;
		}
	}
	else
	{
		#if defined FAKEKILL_HACK
		    if(svCheats_SecurityLevel[killerid] < FAKEKILL_HACK || FAKEKILL_HACK == -1)
		    {
		        if(!IsPlayerStreamedInForPlayer(playerid, killerid))
		        {
		            svCheats_CallDetection(killerid, CHEAT_FAKEKILL);
		        }
		    }
		#endif
		
		#if defined SPAMKILL_CHEAT
		    if(svCheats_SecurityLevel[killerid] < SPAMKILL_CHEAT || SPAMKILL_CHEAT == -1)
		    {
		        svCheats_KillAmount[killerid]++;
		        if(svCheats_KillAmount[killerid] >= DETECT_KILLS)
		        {
		            svCheats_CallDetection(killerid, CHEAT_SPAMKILL);
		        }
		        SetTimerEx("svCheats_KillAmountDown", DETECT_SECONDS * 1000, 0, "i", killerid);
		    }
		#endif
	}
	return 1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	#if defined DRVBY_RESTRICT
		if(svCheats_SecurityLevel[playerid] < DRVBY_RESTRICT || DRVBY_RESTRICT == -1)
	 	{
	  		if(ispassenger)
			{
	    		new w = GetPlayerWeapon(playerid);
	      		if(w > 0)
	       		{
					new allowedWeapons[10], bool: allowed;
	    			sscanf(DRIVEBY_WEAPONS, "a<i>[10]", allowedWeapons);

					for(new i = 0; i < sizeof(allowedWeapons); i++)
					{
						if(w == allowedWeapons[i])
	  					{
	   						allowed = true;
	        				break;
	            		}
	   				}

					if(allowed == false)
					{
						SetPlayerArmedWeapon(playerid, 0);
	  					svCheats_CallDetection(playerid, CHEAT_DRIVEBY);
	  					svCheats_AmountDetected++;
	   				}
				}
			}
	  	}
	#endif

	#if defined DDRIVEBY_OFF
 		if(svCheats_SecurityLevel[playerid] < DDRIVEBY_OFF || DDRIVEBY_OFF == -1)
   		{
     		if(!ispassenger)
       		{
				new w = GetPlayerWeapon(playerid);
				if(w > 0)
				{
    				SetPlayerArmedWeapon(playerid, 0);
        			svCheats_CallDetection(playerid, CHEAT_DDRIVEBY);
        			svCheats_AmountDetected++;
				}
    		}
    	}
	#endif
	
	#if defined NINJAJACK_CHEAT
	    if(svCheats_SecurityLevel[playerid] < NINJAJACK_CHEAT || NINJAJACK_CHEAT == -1)
	    {
	        if(!ispassenger)
	        {
	            #if defined USE_FOREACH
	                foreach(new i: Player)
	                {
	                    if(GetPlayerVehicleID(i) == vehicleid && GetPlayerState(i) == PLAYER_STATE_DRIVER)
	                    {
	                        svCheats_PossibleNinjaJack[i] = playerid;
	                        break;
	                    }
	                }
	            #else
	                for(new i = 0; i < MAX_PLAYERS; i++)
	                {
	                    if(IsPlayerConnected(i))
	                    {
		                    if(GetPlayerVehicleID(i) == vehicleid && GetPlayerState(i) == PLAYER_STATE_DRIVER)
		                    {
		                        svCheats_PossibleNinjaJack[i] = playerid;
		                        break;
		                    }
	                    }
	                }
	            #endif
	        }
	    }
	#endif
	
	#if defined GOIN_LOCKED_VEH
		svCheats_SkipPlayerLVCheck[playerid] = true;
	#endif
	
	return 1;
}

#if defined USE_ZCMD
#if defined HH_USED
COMMAND:hh(playerid, params[])
{
	if(svCheats_SecurityLevel[playerid] < HH_USED)
 	{
  		return SendClientMessage(playerid, -1, "You are not authorized to use this command.");
    }

    new svCheats_giveplayerid;
    if(sscanf(params, "u", svCheats_giveplayerid))
    {
        return SendClientMessage(playerid, -1, "USAGE: /hh [player]");
    }

	if(svCheats_ReportedTabbed[svCheats_giveplayerid] == true)
 	{
  		return SendClientMessage(playerid, -1, "You may not health hack check tabbed players.");
    }

	if(svCheats_HH[svCheats_giveplayerid][svCheckedBy] != INVALID_PLAYER_ID)
 	{
  		return SendClientMessage(playerid, -1, "That player is already being checked for health hacks.");
    }

	new string[128], playersName[MAX_PLAYER_NAME], Float: playersPos[3];

	GetPlayerName(svCheats_giveplayerid, playersName, sizeof(playersName));
	format(string, sizeof(string), "Checking %s for health hacks...", playersName);
	SendClientMessage(playerid, -1, string);

	GetPlayerPos(svCheats_giveplayerid, playersPos[0], playersPos[1], playersPos[2]);
	SetPlayerCameraLookAt(svCheats_giveplayerid, playersPos[0], playersPos[1], playersPos[2]);
	SetPlayerCameraPos(svCheats_giveplayerid, playersPos[0], playersPos[1], playersPos[2] + 5);

	for(new i = 0; i < 3; i++)
	{
		svCheats_HH[svCheats_giveplayerid][svOldPlayerPos][i] = playersPos[i];
	}

	GetPlayerFacingAngle(svCheats_giveplayerid, svCheats_HH[svCheats_giveplayerid][svOldPlayerPos][3]);

	svCheats_HH[svCheats_giveplayerid][svInterior] = GetPlayerInterior(svCheats_giveplayerid);
	svCheats_HH[svCheats_giveplayerid][svVirtualWorld] = GetPlayerVirtualWorld(svCheats_giveplayerid);

	if(IsPlayerInAnyVehicle(svCheats_giveplayerid))
	{
 		svCheats_HH[svCheats_giveplayerid][svInVehicle] = true;
   		svCheats_HH[svCheats_giveplayerid][svVehicleID] = GetPlayerVehicleID(svCheats_giveplayerid);
	    svCheats_HH[svCheats_giveplayerid][svVehicleSeat] = GetPlayerVehicleSeat(svCheats_giveplayerid);
	}
	else
	{
 		svCheats_HH[svCheats_giveplayerid][svInVehicle] = false;
	}

	GetPlayerHealth(svCheats_giveplayerid, svCheats_HH[svCheats_giveplayerid][svHealth]);
	GetPlayerArmour(svCheats_giveplayerid, svCheats_HH[svCheats_giveplayerid][svArmor]);

	svCheats_HH[svCheats_giveplayerid][svCheckedBy] = playerid;

	SetPlayerInterior(svCheats_giveplayerid, 0);
	SetPlayerPos(svCheats_giveplayerid, 0.0, 0.0, 8.0);
	SetPlayerHealth(svCheats_giveplayerid, 100.0);
	SetPlayerArmour(svCheats_giveplayerid, 0.0);

	SetTimerEx("svCheats_HealthHackCheck", 1350 + GetPlayerPing(svCheats_giveplayerid), 0, "i", svCheats_giveplayerid);
 	return 1;
}
#endif

#if defined ACSTATS_USED
COMMAND:acstats(playerid, params[])
{
	new string[50];
	format(string, sizeof(string), "(svCheats) Cheaters Detected: %d", svCheats_AmountDetected);
	SendClientMessage(playerid, -1, string);
	return 1;
}
#endif
#else
hook OnPlayerCommandText(playerid, cmdtext[])
{
    #if defined CHATSPAM_OFF
	    if(svCheats_SecurityLevel[playerid] < CHATSPAM_OFF || CHATSPAM_OFF == -1)
	    {
	        svCheats_SpamCounters[playerid]++;

	        if(svCheats_SpamCounters[playerid] == CHATSPAM_LINES)
	        {
	            svCheats_SpamCounters[playerid] = 0;
				svCheats_CallDetection(playerid, CHEAT_CHATSPAM);
				svCheats_AmountDetected++;
				return 0;
	        }
	    }
	#endif
	
	#if defined HH_USED
		new svCheats_cmd[5];
		sscanf(cmdtext, "s[5]", svCheats_cmd);
		if(strcmp(svCheats_cmd, "/hh", true) == 0)
		{
		    if(svCheats_SecurityLevel[playerid] < HH_USED)
		    {
		        return SendClientMessage(playerid, -1, "You are not authorized to use this command.");
		    }

		    new svCheats_giveplayerid;
		    if(sscanf(cmdtext, "{s[5]}u", svCheats_giveplayerid))
		    {
		        return SendClientMessage(playerid, -1, "USAGE: /hh [player]");
		    }

		    if(svCheats_ReportedTabbed[svCheats_giveplayerid] == true)
		    {
		        return SendClientMessage(playerid, -1, "You may not health hack check tabbed players.");
		    }

		    if(svCheats_HH[svCheats_giveplayerid][svCheckedBy] != INVALID_PLAYER_ID)
		    {
		        return SendClientMessage(playerid, -1, "That player is already being checked for health hacks.");
		    }

			new string[128], playersName[MAX_PLAYER_NAME], Float: playersPos[3];

			GetPlayerName(svCheats_giveplayerid, playersName, sizeof(playersName));
			format(string, sizeof(string), "Checking %s for health hacks...", playersName);
			SendClientMessage(playerid, -1, string);

			GetPlayerPos(svCheats_giveplayerid, playersPos[0], playersPos[1], playersPos[2]);
			SetPlayerCameraLookAt(svCheats_giveplayerid, playersPos[0], playersPos[1], playersPos[2]);
			SetPlayerCameraPos(svCheats_giveplayerid, playersPos[0], playersPos[1], playersPos[2] + 5);

			for(new i = 0; i < 3; i++)
			{
				svCheats_HH[svCheats_giveplayerid][svOldPlayerPos][i] = playersPos[i];
			}

			GetPlayerFacingAngle(svCheats_giveplayerid, svCheats_HH[svCheats_giveplayerid][svOldPlayerPos][3]);

			svCheats_HH[svCheats_giveplayerid][svInterior] = GetPlayerInterior(svCheats_giveplayerid);
			svCheats_HH[svCheats_giveplayerid][svVirtualWorld] = GetPlayerVirtualWorld(svCheats_giveplayerid);

			if(IsPlayerInAnyVehicle(svCheats_giveplayerid))
			{
			    svCheats_HH[svCheats_giveplayerid][svInVehicle] = true;
			    svCheats_HH[svCheats_giveplayerid][svVehicleID] = GetPlayerVehicleID(svCheats_giveplayerid);
			    svCheats_HH[svCheats_giveplayerid][svVehicleSeat] = GetPlayerVehicleSeat(svCheats_giveplayerid);
			}
			else
			{
			    svCheats_HH[svCheats_giveplayerid][svInVehicle] = false;
			}

			GetPlayerHealth(svCheats_giveplayerid, svCheats_HH[svCheats_giveplayerid][svHealth]);
			GetPlayerArmour(svCheats_giveplayerid, svCheats_HH[svCheats_giveplayerid][svArmor]);

			svCheats_HH[svCheats_giveplayerid][svCheckedBy] = playerid;

			SetPlayerInterior(svCheats_giveplayerid, 0);
			SetPlayerPos(svCheats_giveplayerid, 0.0, 0.0, 8.0);
			SetPlayerHealth(svCheats_giveplayerid, 100.0);
			SetPlayerArmour(svCheats_giveplayerid, 0.0);

			SetTimerEx("svCheats_HealthHackCheck", 1350 + GetPlayerPing(svCheats_giveplayerid), 0, "i", svCheats_giveplayerid);
		    return 1;
		}
	#endif
	
	#if defined ACSTATS_USED
	if(strcmp(cmdtext, "/acstats", true) == 0)
	{
		new string[50];
		format(string, sizeof(string), "(svCheats) Cheaters Detected: %d", svCheats_AmountDetected);
		SendClientMessage(playerid, -1, string);
		return 1;
	}
	#endif
	return 0;
}
#endif

hook OnPlayerTakeDamage(playerid, issuerid, Float: amount, weaponid)
{
	if(issuerid == INVALID_PLAYER_ID)
	{
	    if(svCheats_HH[playerid][svCheckedBy] != INVALID_PLAYER_ID)
	    {
	        new string[128], playersName[MAX_PLAYER_NAME], giveplayerid = svCheats_HH[playerid][svCheckedBy];

		    GetPlayerName(playerid, playersName, sizeof(playersName));
			format(string, sizeof(string), "The health hack check on %s has been finished and the result is {F81414}negative{FFFFFF}.", playersName);
			SendClientMessage(giveplayerid, -1, string);

			svCheats_HH[playerid][svCheckedBy] = INVALID_PLAYER_ID;

			SetPlayerVirtualWorld(playerid, svCheats_HH[playerid][svVirtualWorld]);
			SetPlayerInterior(playerid, svCheats_HH[playerid][svInterior]);
			SetPlayerPos(playerid, svCheats_HH[playerid][svOldPlayerPos][0], svCheats_HH[playerid][svOldPlayerPos][1], svCheats_HH[playerid][svOldPlayerPos][2]);
			SetPlayerFacingAngle(playerid, svCheats_HH[playerid][svOldPlayerPos][3]);

			if(svCheats_HH[playerid][svInVehicle] == true)
			{
			    PutPlayerInVehicle(playerid, svCheats_HH[playerid][svVehicleID], svCheats_HH[playerid][svVehicleSeat]);
			}

			SetPlayerHealth(playerid, svCheats_HH[playerid][svHealth]);
			SetPlayerArmour(playerid, svCheats_HH[playerid][svArmor]);

			SetCameraBehindPlayer(playerid);
	    }
	}
	else
	{
	    #if defined CARRAM_OFF
	        if(svCheats_SecurityLevel[playerid] < CARRAM_OFF || CARRAM_OFF == -1)
	        {
	            if(weaponid == 49)
	            {
	                svCheats_CallDetection(playerid, CHEAT_CARRAM);
	            }
	        }
	    #endif
	    
	    #if defined HELIBLADE_OFF
	        if(svCheats_SecurityLevel[playerid] < HELIBLADE_OFF || HELIBLADE_OFF == -1)
	        {
	            if(weaponid == 50)
	            {
	                svCheats_CallDetection(playerid, CHEAT_HELIBLADE);
	            }
	        }
	    #endif
	}
	
	#if defined HEALTH_HACK
		if(!svCheats_PlayerArmor[playerid] || issuerid == INVALID_PLAYER_ID)
		{
		    svCheats_PlayerHealth[playerid] -= amount;
		}
		else
		{
		    if(svCheats_PlayerArmor[playerid] - amount >= 0)
		    {
		        svCheats_PlayerArmor[playerid] -= amount;
		    }
		    else
		    {
		        svCheats_PlayerHealth[playerid] -= (amount - svCheats_PlayerArmor[playerid]);
		        svCheats_PlayerArmor[playerid] = 0;
		    }
		}
	#endif
	return CallRemoteFunction("svCheats_OnPlayerTakeDamage", "ddfd", playerid, issuerid, amount, weaponid);
}

#if defined TELEPORT_HACK
hook OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
	if(svCheats_SecurityLevel[playerid] < TELEPORT_HACK || TELEPORT_HACK == -1)
 	{
		if(!IsPlayerInRangeOfPoint(playerid, 10.0, svCheats_oldPos[playerid][0], svCheats_oldPos[playerid][1], svCheats_oldPos[playerid][2]))
		{
  			if(IsPlayerInRangeOfPoint(playerid, 10.0, fX, fY, fZ))
	    	{
      			svCheats_CallDetection(playerid, CHEAT_TELEPORT_HACK);
		    }
		}
	}
	return 1;
}
#endif

hook OnVehicleMod(playerid, vehicleid, componentid)
{
	#if defined VEHMOD_HACK
		if(svCheats_SecurityLevel[playerid] < VEHMOD_HACK || VEHMOD_HACK == -1)
		{
			if(!GetPlayerInterior(playerid))
			{
			    svCheats_CallDetection(playerid, CHEAT_VEHMOD);
			}
		}
	#endif
	
	#if defined INVALIDMOD_HACK
	    if(!svCheats_IsAllowedCarMod(GetVehicleModel(vehicleid), componentid))
		{
	        svCheats_CallDetection(playerid, CHEAT_INVALIDMOD);
	    }
	#endif
	return 1;
}
#else
#if defined FILTERSCRIPT
forward svCheats_OnFilterScriptInit();
public OnFilterScriptInit()
{
    new File: svCheats_Stats;

	if(!fexist("svCheats_Stats.txt"))
	{
	    svCheats_Stats = fopen("svCheats_Stats.txt", io_append);
	    fwrite(svCheats_Stats, "0");
	}
	else
	{
		new amountDetected[5];
		svCheats_Stats = fopen("svCheats_Stats.txt", io_read);
		fread(svCheats_Stats, amountDetected);
		svCheats_AmountDetected = strval(amountDetected);
	}

	fclose(svCheats_Stats);
    SetTimer("svCheats_Detector", TIMER_TIME, 1);
	return CallRemoteFunction("svCheats_OnFilterScriptInit", "");
}

#if defined _ALS_OnFilterScriptInit
    #undef OnFilterScriptInit
#else
    #define _ALS_OnFilterScriptInit
#endif
#define OnFilterScriptInit svCheats_OnFilterScriptInit

forward svCheats_OnFilterScriptExit();
public OnFilterScriptExit()
{
    new amountDetected[5], File: svCheats_Stats = fopen("svCheats_Stats.txt", io_write);
	format(amountDetected, sizeof(amountDetected), "%d", svCheats_AmountDetected);
	fwrite(svCheats_Stats, amountDetected);
	fclose(svCheats_Stats);
	return CallRemoteFunction("svCheats_OnFilterScriptExit", "");
}

#if defined _ALS_OnFilterScriptExit
    #undef OnFilterScriptExit
#else
    #define _ALS_OnFilterScriptExit
#endif
#define OnFilterScriptExit svCheats_OnFilterScriptExit
#else
forward svCheats_OnGameModeInit();
public OnGameModeInit()
{
    new File: svCheats_Stats;

	if(!fexist("svCheats_Stats.txt"))
	{
	    svCheats_Stats = fopen("svCheats_Stats.txt", io_append);
	    fwrite(svCheats_Stats, "0");
	}
	else
	{
		new amountDetected[5];
		svCheats_Stats = fopen("svCheats_Stats.txt", io_read);
		fread(svCheats_Stats, amountDetected);
		svCheats_AmountDetected = strval(amountDetected);
	}

	fclose(svCheats_Stats);
	SetTimer("svCheats_Detector", TIMER_TIME, 1);
	return CallRemoteFunction("svCheats_OnGameModeInit", "");
}

#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif
#define OnGameModeInit svCheats_OnGameModeInit

forward svCheats_OnGameModeExit();
public OnGameModeExit()
{
	new amountDetected[5], File: svCheats_Stats = fopen("svCheats_Stats.txt", io_write);
	format(amountDetected, sizeof(amountDetected), "%d", svCheats_AmountDetected);
	fwrite(svCheats_Stats, amountDetected);
	fclose(svCheats_Stats);
	return CallRemoteFunction("svCheats_OnGameModeExit", "");
}

#if defined _ALS_OnGameModeExit
    #undef OnGameModeExit
#else
    #define _ALS_OnGameModeExit
#endif
#define OnGameModeExit svCheats_OnGameModeExit
#endif

forward svCheats_OnPlayerDeath(playerid, killerid, reason);
public OnPlayerDeath(playerid, killerid, reason)
{
	svCheats_TabbedDisabled[playerid] = true;
	svCheats_HealthHackDisabled[playerid] = true;

	if(killerid == INVALID_PLAYER_ID)
	{
		if(svCheats_PossibleNinjaJack[playerid] != INVALID_PLAYER_ID)
		{
		    svCheats_CallDetection(svCheats_PossibleNinjaJack[playerid], CHEAT_NINJAJACK);
		    svCheats_PossibleNinjaJack[playerid] = INVALID_PLAYER_ID;
		}
	}
	else
	{
	    #if defined FAKEKILL_HACK
		    if(svCheats_SecurityLevel[killerid] < FAKEKILL_HACK || FAKEKILL_HACK == -1)
		    {
		        if(!IsPlayerStreamedInForPlayer(playerid, killerid))
		        {
		            svCheats_CallDetection(killerid, CHEAT_FAKEKILL);
		        }
		    }
		#endif
		
		#if defined SPAMKILL_CHEAT
		    if(svCheats_SecurityLevel[killerid] < SPAMKILL_CHEAT || SPAMKILL_CHEAT == -1)
		    {
		        svCheats_KillAmount[killerid]++;
		        if(svCheats_KillAmount[killerid] >= DETECT_KILLS)
		        {
		            svCheats_CallDetection(killerid, CHEAT_SPAMKILL);
		        }
		        SetTimerEx("svCheats_KillAmountDown", DETECT_SECONDS * 1000, 0, "i", killerid);
		    }
		#endif
	}
	return CallRemoteFunction("svCheats_OnPlayerDeath", "ddd", playerid, killerid, reason);
}

#if defined _ALS_OnPlayerDeath
    #undef OnPlayerDeath
#else
    #define _ALS_OnPlayerDeath
#endif
#define OnPlayerDeath svCheats_OnPlayerDeath

forward svCheats_OnPlayerConnect(playerid);
public OnPlayerConnect(playerid)
{
	svCheats_SecurityLevel[playerid] = 0;
	
	#if defined FAKEPLAYER_HACK
 	new playersIP[17];
  	GetPlayerIp(playerid, playersIP, 17);
   	if(strcmp(playersIP, "255.255.255.255") == 0 || (strcmp(SERVER_IP, "127.0.0.1") && strcmp(playersIP, "127.0.0.1") == 0 && !IsPlayerNPC(playerid)))
   	{
		svCheats_CallDetection(playerid, CHEAT_FAKEPLAYER);
    }
    
	svCheats_log_new_join(playerid);
    if(svCheats_NJTR(playerid, 5000) >= 3)
    {
        svCheats_CallDetection(playerid, CHEAT_FAKEPLAYER);
    }
	#endif
	
	#if defined JETPACK_HACK
	svCheats_GrantedJetpack[playerid] = false;
	#endif
	
	#if defined BUNNYHOP_OFF
	svCheats_JumpCounters[playerid] = 0;
	svCheats_JumpCounterTimer[playerid] = -1;
	#endif
	
	#if defined CHATSPAM_OFF
	svCheats_SpamCounters[playerid] = 0;
	#endif
	
	#if defined WEAPON_SPAWN
	for(new i = 0; i < 13; i++)
	{
	    svCheats_PlayerWeapons[playerid][i] = 0;
	}
	#endif
	
	#if defined AFK_DISABLED
	svCheats_AFKTime[playerid] = 0;
	svCheats_LastAFKUpdate[playerid] = GetTickCount();
	svCheats_ReportedAFK[playerid] = false;
	#endif
	
	#if defined TABBED_DISABLED
	svCheats_TabbedUpdates[playerid] = 0;
	svCheats_ReportedTabbed[playerid] = false;
	svCheats_TabbedDisabled[playerid] = true;
	#endif
	
	svCheats_HH[playerid][svCheckedBy] = INVALID_PLAYER_ID;
	
	#if defined NINJAJACK_CHEAT
	svCheats_PossibleNinjaJack[playerid] = INVALID_PLAYER_ID;
	#endif
	
	#if defined GOIN_LOCKED_VEH
	svCheats_SkipPlayerLVCheck[playerid] = false;
	#endif
	
	#if defined SPAMKLL_CHEAT
	svCheats_KillAmount[playerid] = 0;
	#endif
	
	svCheats_Spawned[playerid] = false;
	return CallRemoteFunction("svCheats_OnPlayerConnect", "d", playerid);
}

#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect svCheats_OnPlayerConnect

forward svCheats_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	#if defined BUNNYHOP_OFF
		if(newkeys & KEY_JUMP)
		{
		    if(svCheats_SecurityLevel[playerid] < BUNNYHOP_OFF || BUNNYHOP_OFF == -1)
		    {
			    new ai = GetPlayerAnimationIndex(playerid);
			    if(ai != 1061 && ai != 1062 && ai != 1064 && ai != 1066 && ai != 1195 && ai != 1997 && ai != 1538 || ai != 1538 || ai != 1543)
			    {
					svCheats_JumpCounters[playerid]++;

					if(svCheats_JumpCounterTimer[playerid] > -1)
					{
					    KillTimer(svCheats_JumpCounterTimer[playerid]);
					    svCheats_JumpCounterTimer[playerid] = -1;
					}

					if(svCheats_JumpCounters[playerid] == BUNNYHOP_AMOUNT)
					{
					    svCheats_JumpCounters[playerid] = 0;
					    svCheats_CallDetection(playerid, CHEAT_BUNNYHOP);
					    svCheats_AmountDetected++;
					}
					else
					{
						svCheats_JumpCounterTimer[playerid] = SetTimerEx("svCheats_JumpCountersDown", 2000, 0, "i", playerid);
					}
			    }
		    }
		}
	#endif

	#if defined WEAPON_SPAWN
		if(newkeys & KEY_FIRE)
		{
		    if(svCheats_SecurityLevel[playerid] < WEAPON_SPAWN || WEAPON_SPAWN == -1)
		    {
			    new w = GetPlayerWeapon(playerid);
			    if(w > 0 && w < 46)
			    {
					if(svCheats_PlayerWeapons[playerid][svCheats_GetWeaponSlot(w)] != w)
					{
					    svCheats_CallDetection(playerid, CHEAT_WEAPON_SPAWN);
					    svCheats_AmountDetected++;
					}
			    }
		    }
		}
	#endif
	return CallRemoteFunction("svCheats_OnPlayerKeyStateChange", "ddd", playerid, newkeys, oldkeys);
}

#if defined _ALS_OnPlayerKeyStateChange
    #undef OnPlayerKeyStateChange
#else
    #define _ALS_OnPlayerKeyStateChange
#endif
#define OnPlayerKeyStateChange svCheats_OnPlayerKeyStateChange

forward svCheats_OnPlayerText(playerid, text[]);
public OnPlayerText(playerid, text[])
{
    #if defined SWEARING_OFF
	    if(svCheats_SecurityLevel[playerid] < SWEARING_OFF || SWEARING_OFF == -1)
	    {
			for(new c = 0; c < sizeof(CurseWords); c++)
			{
				if(strfind(text, CurseWords[c], true) > -1)
				{
				    svCheats_CallDetection(playerid, CHEAT_SWEARING);
				    svCheats_AmountDetected++;
					return 0;
				}
			}
		}
	#endif
	
	#if defined CHATSPAM_OFF
	    if(svCheats_SecurityLevel[playerid] < CHATSPAM_OFF || CHATSPAM_OFF == -1)
	    {
	        svCheats_SpamCounters[playerid]++;

	        if(svCheats_SpamCounters[playerid] == CHATSPAM_LINES)
	        {
	            svCheats_SpamCounters[playerid] = 0;
				svCheats_CallDetection(playerid, CHEAT_CHATSPAM);
				svCheats_AmountDetected++;
				return 0;
	        }
	    }
	#endif
	
	#if defined AFK_DISABLED
	    if(svCheats_SecurityLevel[playerid] < AFK_DISABLED || AFK_DISABLED == -1)
	    {
	        svCheats_AFKTime[playerid] = 0;
	        svCheats_ReportedAFK[playerid] = false;
	    }
	#endif
	
	#if defined SERVERAD_CHEAT
	    if(svCheats_SecurityLevel[playerid] < SERVERAD_CHEAT || SERVERAD_CHEAT == -1)
	    {
	        new dotCount, numCount;

			for(new i = 0; i < strlen(text); i++)
			{
			    if(text[i] == '.')
			    {
			        dotCount++;
			    }
			    else if(text[i] >= '0' && text[i] <= '9')
			    {
			        numCount++;
			    }
			}

			if(dotCount >= 3 && (numCount >= 7 || strfind(text, "samp.") > -1))
			{
			    if(strfind(text, SERVER_IP) == -1 && strfind(text, SERVER_DOMAIN, true) == -1)
			    {
					svCheats_CallDetection(playerid, CHEAT_SERVERAD);
				}
			}
	    }
	#endif
	return CallRemoteFunction("svCheats_OnPlayerText", "ds", playerid, text);
}

#if defined _ALS_OnPlayerText
    #undef OnPlayerText
#else
    #define _ALS_OnPlayerText
#endif
#define OnPlayerText svCheats_OnPlayerText

#if defined VEHICLE_REPAIR
forward svCheats_OnVehicleSpawn(vehicleid);
public OnVehicleSpawn(vehicleid)
{
	svCheats_VehicleHealth[vehicleid] = 1000.0;
	return CallRemoteFunction("svCheats_OnVehicleSpawn", "d", vehicleid);
}

#if defined _ALS_OnVehicleSpawn
    #undef OnVehicleSpawn
#else
    #define _ALS_OnVehicleSpawn
#endif
#define OnVehicleSpawn svCheats_OnVehicleSpawn

forward svCheats_OnPlayerStateChange(playerid, newstate, oldstate);
public OnPlayerStateChange(playerid, newstate, oldstate)
{
	if(newstate == PLAYER_STATE_DRIVER)
	{
	    #if defined VEHICLE_REPAIR
     		new vehicleid = GetPlayerVehicleID(playerid);
     		GetVehicleHealth(vehicleid, svCheats_VehicleHealth[vehicleid]);
	    #endif
	    
	    #if defined NINJAJACK_OFF
			#if defined USE_FOREACH
				foreach(new i: Player)
				{
				    if(svCheats_PossibleNinjaJack[i] == playerid)
				    {
				        svCheats_PossibleNinjaJack[i] = INVALID_PLAYER_ID;
				        break;
				    }
				}
			#else
			    for(new i = 0; i < MAX_PLAYERS; i++)
				{
				    if(IsPlayerConnected(i))
					{
					    if(svCheats_PossibleNinjaJack[i] == playerid)
					    {
					        svCheats_PossibleNinjaJack[i] = INVALID_PLAYER_ID;
					        break;
					    }
				    }
				}
			#endif
	    #endif
	}
	
	if(newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
	{
	    #if defined GOIN_LOCKED_VEH
	        if(svCheats_SecurityLevel[playerid] < GOIN_LOCKED_VEH || GOIN_LOCKED_VEH == -1)
	        {
	            if(svCheats_SkipPlayerLVCheck[playerid] == false)
	            {
	                new engine2, lights2, alarm2, doors2, bonnet2, boot2, objective2;
	                GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine2, lights2, alarm2, doors2, bonnet2, boot2, objective2);
	                if(doors2)
	                {
	                    svCheats_CallDetection(playerid, CHEAT_LOCKEDVEH);
	                }
	            }
	            else
	            {
	                svCheats_SkipPlayerLVCheck[playerid] = false;
	            }
	        }
	    #endif
	}
	return CallRemoteFunction("svCheats_OnPlayerStateChange", "ddd", playerid, newstate, oldstate);
}

#if defined _ALS_OnPlayerStateChange
    #undef OnPlayerStateChange
#else
    #define _ALS_OnPlayerStateChange
#endif
#define OnPlayerStateChange svCheats_OnPlayerStateChange
#endif

#if defined CHEAT_TABBED
forward svCheats_OnPlayerUpdate(playerid);
public OnPlayerUpdate(playerid)
{
	svCheats_TabbedUpdates[playerid] = 0;
	svCheats_ReportedTabbed[playerid] = false;
	
	#if defined CHEAT_REMOTEJACK
		new playersVehicle = GetPlayerVehicleID(playerid);

	    if(!IsPlayerInAnyVehicle(playerid))
	    {
	    	GetPlayerPos(playerid, svCheats_RemoteJack[playerid][svLofPos][0], svCheats_RemoteJack[playerid][svLofPos][1], svCheats_RemoteJack[playerid][svLofPos][2]);
		}

	    if((playersVehicle != svCheats_RemoteJack[playerid][svLastJackState]) && playersVehicle != 0 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{
	        new Float: playersPos[3], Float: distancejack = svCheats_GetDistance(playersPos[0], playersPos[1], playersPos[2], svCheats_RemoteJack[playerid][svLofPos][0], svCheats_RemoteJack[playerid][svLofPos][1], svCheats_RemoteJack[playerid][svLofPos][2]), thiscaride = GetVehicleModel(playersVehicle), Float: distanceth = 10;
	        GetVehiclePos(playersVehicle, playersPos[0], playersPos[1], playersPos[2]);

	        if(thiscaride == 577 || thiscaride == 592)
	        {
				distanceth = 25.0;
			}

	        if(distancejack > distanceth)
			{
	            svCheats_CallDetection(playerid, CHEAT_REMOTEJACK);
	        }

	        GetPlayerPos(playerid, svCheats_RemoteJack[playerid][svLofPos][0], svCheats_RemoteJack[playerid][svLofPos][1], svCheats_RemoteJack[playerid][svLofPos][2]);

	        svCheats_RemoteJack[playerid][svLastJackState] = playersVehicle;
	    }
	#endif
	return CallRemoteFunction("svCheats_OnPlayerUpdate", "d", playerid);
}

#if defined _ALS_OnPlayerUpdate
    #undef OnPlayerUpdate
#else
    #define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate svCheats_OnPlayerUpdate

forward svCheats_OnPlayerSpawn(playerid);
public OnPlayerSpawn(playerid)
{
	svCheats_TabbedDisabled[playerid] = false;
	svCheats_Spawned[playerid] = true;
	
	#if defined HEALTH_HACK
	svCheats_PlayerHealth[playerid] = 1000;
	svCheats_PlayerArmor[playerid] = 0;
	svCheats_HealthHackDisabled[playerid] = false;
	#endif
	return CallRemoteFunction("svCheats_OnPlayerSpawn", "d", playerid);
}

#if defined _ALS_OnPlayerSpawn
    #undef OnPlayerSpawn
#else
    #define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn svCheats_OnPlayerSpawn

forward svCheats_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	#if defined DRVBY_RESTRICT
		if(svCheats_SecurityLevel[playerid] < DRVBY_RESTRICT || DRVBY_RESTRICT == -1)
	 	{
	  		if(ispassenger)
			{
	    		new w = GetPlayerWeapon(playerid);
	      		if(w > 0)
	       		{
					new allowedWeapons[10], bool: allowed;
	    			sscanf(DRIVEBY_WEAPONS, "a<i>[10]", allowedWeapons);

					for(new i = 0; i < sizeof(allowedWeapons); i++)
					{
						if(w == allowedWeapons[i])
	  					{
	   						allowed = true;
	        				break;
	            		}
	   				}

					if(allowed == false)
					{
						SetPlayerArmedWeapon(playerid, 0);
	  					svCheats_CallDetection(playerid, CHEAT_DRIVEBY);
	  					svCheats_AmountDetected++;
	   				}
				}
			}
	  	}
	#endif

	#if defined DDRIVEBY_OFF
 		if(svCheats_SecurityLevel[playerid] < DDRIVEBY_OFF || DDRIVEBY_OFF == -1)
   		{
     		if(!ispassenger)
       		{
				new w = GetPlayerWeapon(playerid);
				if(w > 0)
				{
    				SetPlayerArmedWeapon(playerid, 0);
        			svCheats_CallDetection(playerid, CHEAT_DDRIVEBY);
        			svCheats_AmountDetected++;
				}
    		}
    	}
	#endif
	
	#if defined NINJAJACK_CHEAT
	    if(svCheats_SecurityLevel[playerid] < NINJAJACK_CHEAT || NINJAJACK_CHEAT == -1)
	    {
	        if(!ispassenger)
	        {
	            #if defined USE_FOREACH
	                foreach(new i: Player)
	                {
	                    if(GetPlayerVehicleID(i) == vehicleid && GetPlayerState(i) == PLAYER_STATE_DRIVER)
	                    {
	                        svCheats_PossibleNinjaJack[i] = playerid;
	                        break;
	                    }
	                }
	            #else
	                for(new i = 0; i < MAX_PLAYERS; i++)
	                {
	                    if(IsPlayerConnected(i))
	                    {
		                    if(GetPlayerVehicleID(i) == vehicleid && GetPlayerState(i) == PLAYER_STATE_DRIVER)
		                    {
		                        svCheats_PossibleNinjaJack[i] = playerid;
		                        break;
		                    }
	                    }
	                }
	            #endif
	        }
	    }
	#endif
	
	#if defined GOIN_LOCKED_VEH
		svCheats_SkipPlayerLVCheck[playerid] = true;
	#endif
	
	return CallRemoteFunction("svCheats_OnPlayerEnterVehicle", "ddd", playerid, vehicleid, ispassenger);
}

#if defined _ALS_OnPlayerEnterVehicle
    #undef OnPlayerEnterVehicle
#else
    #define _ALS_OnPlayerEnterVehicle
#endif
#define OnPlayerEnterVehicle svCheats_OnPlayerEnterVehicle

#if defined USE_ZCMD
#if defined HH_USED
COMMAND:hh(playerid, params[])
{
	if(svCheats_SecurityLevel[playerid] < HH_USED)
 	{
  		return SendClientMessage(playerid, -1, "You are not authorized to use this command.");
    }

    new svCheats_giveplayerid;
    if(sscanf(params, "u", svCheats_giveplayerid))
    {
        return SendClientMessage(playerid, -1, "USAGE: /hh [player]");
    }

	if(svCheats_ReportedTabbed[svCheats_giveplayerid] == true)
 	{
  		return SendClientMessage(playerid, -1, "You may not health hack check tabbed players.");
    }

	if(svCheats_HH[svCheats_giveplayerid][svCheckedBy] != INVALID_PLAYER_ID)
 	{
  		return SendClientMessage(playerid, -1, "That player is already being checked for health hacks.");
    }

	new string[128], playersName[MAX_PLAYER_NAME], Float: playersPos[3];

	GetPlayerName(svCheats_giveplayerid, playersName, sizeof(playersName));
	format(string, sizeof(string), "Checking %s for health hacks...", playersName);
	SendClientMessage(playerid, -1, string);

	GetPlayerPos(svCheats_giveplayerid, playersPos[0], playersPos[1], playersPos[2]);
	SetPlayerCameraLookAt(svCheats_giveplayerid, playersPos[0], playersPos[1], playersPos[2]);
	SetPlayerCameraPos(svCheats_giveplayerid, playersPos[0], playersPos[1], playersPos[2] + 5);

	for(new i = 0; i < 3; i++)
	{
		svCheats_HH[svCheats_giveplayerid][svOldPlayerPos][i] = playersPos[i];
	}

	GetPlayerFacingAngle(svCheats_giveplayerid, svCheats_HH[svCheats_giveplayerid][svOldPlayerPos][3]);

	svCheats_HH[svCheats_giveplayerid][svInterior] = GetPlayerInterior(svCheats_giveplayerid);
	svCheats_HH[svCheats_giveplayerid][svVirtualWorld] = GetPlayerVirtualWorld(svCheats_giveplayerid);

	if(IsPlayerInAnyVehicle(svCheats_giveplayerid))
	{
 		svCheats_HH[svCheats_giveplayerid][svInVehicle] = true;
   		svCheats_HH[svCheats_giveplayerid][svVehicleID] = GetPlayerVehicleID(svCheats_giveplayerid);
	    svCheats_HH[svCheats_giveplayerid][svVehicleSeat] = GetPlayerVehicleSeat(svCheats_giveplayerid);
	}
	else
	{
 		svCheats_HH[svCheats_giveplayerid][svInVehicle] = false;
	}

	GetPlayerHealth(svCheats_giveplayerid, svCheats_HH[svCheats_giveplayerid][svHealth]);
	GetPlayerArmour(svCheats_giveplayerid, svCheats_HH[svCheats_giveplayerid][svArmor]);

	svCheats_HH[svCheats_giveplayerid][svCheckedBy] = playerid;

	SetPlayerInterior(svCheats_giveplayerid, 0);
	SetPlayerPos(svCheats_giveplayerid, 0.0, 0.0, 8.0);
	SetPlayerHealth(svCheats_giveplayerid, 100.0);
	SetPlayerArmour(svCheats_giveplayerid, 0.0);

	SetTimerEx("svCheats_HealthHackCheck", 1350 + GetPlayerPing(svCheats_giveplayerid), 0, "i", svCheats_giveplayerid);
 	return 1;
}
#endif

#if defined ACSTATS_USED
COMMAND:acstats(playerid, params[])
{
	new string[50];
	format(string, sizeof(string), "(svCheats) Cheaters Detected: %d", svCheats_AmountDetected);
	SendClientMessage(playerid, -1, string);
	return 1;
}
#endif
#else
forward svCheats_OnPlayerCommandText(playerid, cmdtext[]);
public OnPlayerCommandText(playerid, cmdtext[])
{
    #if defined CHATSPAM_OFF
	    if(svCheats_SecurityLevel[playerid] < CHATSPAM_OFF || CHATSPAM_OFF == -1)
	    {
	        svCheats_SpamCounters[playerid]++;

	        if(svCheats_SpamCounters[playerid] == CHATSPAM_LINES)
	        {
	            svCheats_SpamCounters[playerid] = 0;
				svCheats_CallDetection(playerid, CHEAT_CHATSPAM);
				svCheats_AmountDetected++;
				return 0;
	        }
	    }
	#endif
	
	#if defined HH_USED
		new svCheats_cmd[5];
		sscanf(cmdtext, "s[5]", svCheats_cmd);
		if(strcmp(svCheats_cmd, "/hh", true) == 0)
		{
		    if(svCheats_SecurityLevel[playerid] < HH_USED)
		    {
		        return SendClientMessage(playerid, -1, "You are not authorized to use this command.");
		    }

		    new svCheats_giveplayerid;
		    if(sscanf(cmdtext, "{s[5]}u", svCheats_giveplayeid))
		    {
		        return SendClientMessage(playerid, -1, "USAGE: /hh [player]");
		    }

		    if(svCheats_ReportedTabbed[svCheats_giveplayerid] == true)
		    {
		        return SendClientMessage(playerid, -1, "You may not health hack check tabbed players.");
		    }

		    if(svCheats_HH[svCheats_giveplayerid][svCheckedBy] != INVALID_PLAYER_ID)
		    {
		        return SendClientMessage(playerid, -1, "That player is already being checked for health hacks.");
		    }

			new string[128], playersName[MAX_PLAYER_NAME], Float: playersPos[3];

			GetPlayerName(svCheats_giveplayerid, playersName, sizeof(playersName));
			format(string, sizeof(string), "Checking %s for health hacks...", playersName);
			SendClientMessage(playerid, -1, string);

			GetPlayerPos(svCheats_giveplayerid, playersPos[0], playersPos[1], playersPos[2]);
			SetPlayerCameraLookAt(svCheats_giveplayerid, playersPos[0], playersPos[1], playersPos[2]);
			SetPlayerCameraPos(svCheats_giveplayerid, playersPos[0], playersPos[1], playersPos[2] + 5);

			for(new i = 0; i < 3; i++)
			{
				svCheats_HH[svCheats_giveplayerid][svOldPlayerPos][i] = playersPos[i];
			}

			GetPlayerFacingAngle(svCheats_giveplayerid, svCheats_HH[svCheats_giveplayerid][svOldPlayerPos][3]);

			svCheats_HH[svCheats_giveplayerid][svInterior] = GetPlayerInterior(svCheats_giveplayerid);
			svCheats_HH[svCheats_giveplayerid][svVirtualWorld] = GetPlayerVirtualWorld(svCheats_giveplayerid);

			if(IsPlayerInAnyVehicle(svCheats_giveplayerid))
			{
			    svCheats_HH[svCheats_giveplayerid][svInVehicle] = true;
			    svCheats_HH[svCheats_giveplayerid][svVehicleID] = GetPlayerVehicleID(svCheats_giveplayerid);
			    svCheats_HH[svCheats_giveplayerid][svVehicleSeat] = GetPlayerVehicleSeat(svCheats_giveplayerid);
			}
			else
			{
			    svCheats_HH[svCheats_giveplayerid][svInVehicle] = false;
			}

			GetPlayerHealth(svCheats_giveplayerid, svCheats_HH[svCheats_giveplayerid][svHealth]);
			GetPlayerArmour(svCheats_giveplayerid, svCheats_HH[svCheats_giveplayerid][svArmor]);

			svCheats_HH[svCheats_giveplayerid][svCheckedBy] = playerid;

			SetPlayerInterior(svCheats_giveplayerid, 0);
			SetPlayerPos(svCheats_giveplayerid, 0.0, 0.0, 8.0);
			SetPlayerHealth(svCheats_giveplayerid, 100.0);
			SetPlayerArmour(svCheats_giveplayerid, 0.0);

			SetTimerEx("svCheats_HealthHackCheck", 1350 + GetPlayerPing(svCheats_giveplayerid), 0, "i", svCheats_giveplayerid);
		    return 1;
		}
	#endif
	
	#if defined ACSTATS_USED
	if(strcmp(cmdtext, "/acstats", true) == 0)
	{
		new string[50];
		format(string, sizeof(string), "(svCheats) Cheaters Detected: %d", svCheats_AmountDetected);
		SendClientMessage(playerid, -1, string);
		return 1;
	}
	#endif
	return CallRemoteFunction("svCheats_OnPlayerCommandText", "ds", playerid, cmdtext);
}

#if defined _ALS_OnPlayerCommandText
    #undef OnPlayerCommandText
#else
    #define _ALS_OnPlayerCommandText
#endif
#define OnPlayerCommandText svCheats_OnPlayerCommandText
#endif

forward svCheats_OnPlayerTakeDamage(playerid, issuerid, Float: amount, weaponid);
public OnPlayerTakeDamage(playerid, issuerid, Float: amount, weaponid)
{
	if(issuerid == INVALID_PLAYER_ID)
	{
	    if(svCheats_HH[playerid][svCheckedBy] != INVALID_PLAYER_ID)
	    {
	        new string[128], playersName[MAX_PLAYER_NAME], giveplayerid = svCheats_HH[playerid][svCheckedBy];

		    GetPlayerName(playerid, playersName, sizeof(playersName));
			format(string, sizeof(string), "The health hack check on %s has been finished and the result is {F81414}negative{FFFFFF}.", playersName);
			SendClientMessage(giveplayerid, -1, string);

			svCheats_HH[playerid][svCheckedBy] = INVALID_PLAYER_ID;

			SetPlayerVirtualWorld(playerid, svCheats_HH[playerid][svVirtualWorld]);
			SetPlayerInterior(playerid, svCheats_HH[playerid][svInterior]);
			SetPlayerPos(playerid, svCheats_HH[playerid][svOldPlayerPos][0], svCheats_HH[playerid][svOldPlayerPos][1], svCheats_HH[playerid][svOldPlayerPos][2]);
			SetPlayerFacingAngle(playerid, svCheats_HH[playerid][svOldPlayerPos][3]);

			if(svCheats_HH[playerid][svInVehicle] == true)
			{
			    PutPlayerInVehicle(playerid, svCheats_HH[playerid][svVehicleID], svCheats_HH[playerid][svVehicleSeat]);
			}

			SetPlayerHealth(playerid, svCheats_HH[playerid][svHealth]);
			SetPlayerArmour(playerid, svCheats_HH[playerid][svArmor]);

			SetCameraBehindPlayer(playerid);
	    }
	}
	else
	{
	    #if defined CARRAM_OFF
	        if(svCheats_SecurityLevel[playerid] < CARRAM_OFF || CARRAM_OFF == -1)
	        {
	            if(weaponid == 49)
	            {
	                svCheats_CallDetection(playerid, CHEAT_CARRAM);
	            }
	        }
	    #endif

	    #if defined HELIBLADE_OFF
	        if(svCheats_SecurityLevel[playerid] < HELIBLADE_OFF || HELIBLADE_OFF == -1)
	        {
	            if(weaponid == 50)
	            {
	                svCheats_CallDetection(playerid, CHEAT_HELIBLADE);
	            }
	        }
	    #endif
	}
	
	#if defined HEALTH_HACK
		if(!svCheats_PlayerArmor[playerid] || issuerid == INVALID_PLAYER_ID)
		{
		    svCheats_PlayerHealth[playerid] -= amount;
		}
		else
		{
		    if(svCheats_PlayerArmor[playerid] - amount >= 0)
		    {
		        svCheats_PlayerArmor[playerid] -= amount;
		    }
		    else
		    {
		        svCheats_PlayerHealth[playerid] -= (amount - svCheats_PlayerArmor[playerid]);
		        svCheats_PlayerArmor[playerid] = 0;
		    }
		}
	#endif
	return CallRemoteFunction("svCheats_OnPlayerTakeDamage", "ddfd", playerid, issuerid, amount, weaponid);
}

#if defined _ALS_OnPlayerTakeDamage
    #undef OnPlayerTakeDamage
#else
    #define _ALS_OnPlayerTakeDamage
#endif
#define OnPlayerTakeDamage svCheats_OnPlayerTakeDamage

#if defined TELEPORT_HACK
forward svCheats_OnPlayerClickMap(playerid, Float: fX, Float: fY, Float: fZ);
public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
	if(svCheats_SecurityLevel[playerid] < TELEPORT_HACK || TELEPORT_HACK == -1)
 	{
		if(!IsPlayerInRangeOfPoint(playerid, 10.0, svCheats_oldPos[playerid][0], svCheats_oldPos[playerid][1], svCheats_oldPos[playerid][2]))
		{
  			if(IsPlayerInRangeOfPoint(playerid, 10.0, fX, fY, fZ))
	    	{
      			svCheats_CallDetection(playerid, CHEAT_TELEPORT_HACK);
		    }
		}
	}
	return CallRemoteFunction("svCheats_OnPlayerClickMap", "dfff", playerid, fX, fY, fZ);
}

#if defined _ALS_OnPlayerClickMap
    #undef OnPlayerClickMap
#else
    #define _ALS_OnPlayerClickMap
#endif
#define OnPlayerClickMap svCheats_OnPlayerClickMap
#endif

forward svCheats_OnVehicleMod(playerid, vehicleid, componentid);
public OnVehicleMod(playerid, vehicleid, componentid)
{
	#if defined VEHMOD_HACK
		if(svCheats_SecurityLevel[playerid] < VEHMOD_HACK || VEHMOD_HACK == -1)
		{
			if(!GetPlayerInterior(playerid))
			{
			    svCheats_CallDetection(playerid, CHEAT_VEHMOD);
			}
		}
	#endif
	
	#if defined INVALIDMOD_HACK
	    if(!svCheats_IsAllowedCarMod(GetVehicleModel(vehicleid), componentid))
		{
	        svCheats_CallDetection(playerid, CHEAT_INVALIDMOD);
	    }
	#endif
	return CallRemoteFunction("svCheats_OnVehicleMod", "ddd", playerid, vehicleid, componentid);
}

#if defined _ALS_OnVehicleMod
    #undef OnVehicleMod
#else
    #define _ALS_OnVehicleMod
#endif
#define OnVehicleMod svCheats_OnVehicleMod
#endif
#endif

new legalmods2[48][22] = {
	{400, 1024,1021,1020,1019,1018,1013,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
 	{401, 1145,1144,1143,1142,1020,1019,1017,1013,1007,1006,1005,1004,1003,1001,0000,0000,0000,0000},
  	{404, 1021,1020,1019,1017,1016,1013,1007,1002,1000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
   	{405, 1023,1021,1020,1019,1018,1014,1001,1000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
    {410, 1024,1023,1021,1020,1019,1017,1013,1007,1003,1001,0000,0000,0000,0000,0000,0000,0000,0000},
    {415, 1023,1019,1018,1017,1007,1003,1001,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
    {418, 1021,1020,1016,1006,1002,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
    {420, 1021,1019,1005,1004,1003,1001,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
    {421, 1023,1021,1020,1019,1018,1016,1014,1000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
    {422, 1021,1020,1019,1017,1013,1007,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
    {426, 1021,1019,1006,1005,1004,1003,1001,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
    {436, 1022,1021,1020,1019,1017,1013,1007,1006,1003,1001,0000,0000,0000,0000,0000,0000,0000,0000},
    {439, 1145,1144,1143,1142,1023,1017,1013,1007,1003,1001,0000,0000,0000,0000,0000,0000,0000,0000},
    {477, 1021,1020,1019,1018,1017,1007,1006,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
    {478, 1024,1022,1021,1020,1013,1012,1005,1004,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
    {489, 1024,1020,1019,1018,1016,1013,1006,1005,1004,1002,1000,0000,0000,0000,0000,0000,0000,0000},
    {491, 1145,1144,1143,1142,1023,1021,1020,1019,1018,1017,1014,1007,1003,0000,0000,0000,0000,0000},
    {492, 1016,1006,1005,1004,1000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
    {496, 1143,1142,1023,1020,1019,1017,1011,1007,1006,1003,1002,1001,0000,0000,0000,0000,0000,0000},
    {500, 1024,1021,1020,1019,1013,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
    {516, 1021,1020,1019,1018,1017,1016,1015,1007,1004,1002,1000,0000,0000,0000,0000,0000,0000,0000},
    {517, 1145,1144,1143,1142,1023,1020,1019,1018,1017,1016,1007,1003,1002,0000,0000,0000,0000,0000},
    {518, 1145,1144,1143,1142,1023,1020,1018,1017,1013,1007,1006,1005,1003,1001,0000,0000,0000,0000},
    {527, 1021,1020,1018,1017,1015,1014,1007,1001,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
    {529, 1023,1020,1019,1018,1017,1012,1011,1007,1006,1003,1001,0000,0000,0000,0000,0000,0000,0000},
    {534, 1185,1180,1179,1178,1127,1126,1125,1124,1123,1122,1106,1101,1100,0000,0000,0000,0000,0000},
    {535, 1121,1120,1119,1118,1117,1116,1115,1114,1113,1110,1109,0000,0000,0000,0000,0000,0000,0000},
    {536, 1184,1183,1182,1181,1128,1108,1107,1105,1104,1103,0000,0000,0000,0000,0000,0000,0000,0000},
    {540, 1145,1144,1143,1142,1024,1023,1020,1019,1018,1017,1007,1006,1004,1001,0000,0000,0000,0000},
    {542, 1145,1144,1021,1020,1019,1018,1015,1014,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
    {546, 1145,1144,1143,1142,1024,1023,1019,1018,1017,1007,1006,1004,1002,1001,0000,0000,0000,0000},
    {547, 1143,1142,1021,1020,1019,1018,1016,1003,1000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
    {549, 1145,1144,1143,1142,1023,1020,1019,1018,1017,1012,1011,1007,1003,1001,0000,0000,0000,0000},
    {550, 1145,1144,1143,1142,1023,1020,1019,1018,1006,1005,1004,1003,1001,0000,0000,0000,0000,0000},
    {551, 1023,1021,1020,1019,1018,1016,1006,1005,1003,1002,0000,0000,0000,0000,0000,0000,0000,0000},
    {558, 1168,1167,1166,1165,1164,1163,1095,1094,1093,1092,1091,1090,1089,1088,0000,0000,0000,0000},
    {559, 1173,1162,1161,1160,1159,1158,1072,1071,1070,1069,1068,1067,1066,1065,0000,0000,0000,0000},
    {560, 1170,1169,1141,1140,1139,1138,1033,1032,1031,1030,1029,1028,1027,1026,0000,0000,0000,0000},
    {561, 1157,1156,1155,1154,1064,1063,1062,1061,1060,1059,1058,1057,1056,1055,1031,1030,1027,1026},
    {562, 1172,1171,1149,1148,1147,1146,1041,1040,1039,1038,1037,1036,1035,1034,0000,0000,0000,0000},
    {565, 1153,1152,1151,1150,1054,1053,1052,1051,1050,1049,1048,1047,1046,1045,0000,0000,0000,0000},
    {567, 1189,1188,1187,1186,1133,1132,1131,1130,1129,1102,0000,0000,0000,0000,0000,0000,0000,0000},
    {575, 1177,1176,1175,1174,1099,1044,1043,1042,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
    {576, 1193,1192,1191,1190,1137,1136,1135,1134,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
    {580, 1023,1020,1018,1017,1007,1006,1001,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
    {589, 1145,1144,1024,1020,1018,1017,1016,1013,1007,1006,1005,1004,1000,0000,0000,0000,0000,0000},
    {600, 1022,1020,1018,1017,1013,1007,1006,1005,1004,0000,0000,0000,0000,0000,0000,0000,0000,0000},
    {603, 1145,1144,1143,1142,1024,1023,1020,1019,1018,1017,1007,1006,1001,0000,0000,0000,0000,0000}
};

forward svCheats_HealthHackCheck(giveplayerid);
public svCheats_HealthHackCheck(giveplayerid)
{
	if(svCheats_HH[giveplayerid][svCheckedBy] != INVALID_PLAYER_ID)
	{
	    new string[128], playersName[MAX_PLAYER_NAME], playerid = svCheats_HH[giveplayerid][svCheckedBy];
	    
	    GetPlayerName(giveplayerid, playersName, sizeof(playersName));
		format(string, sizeof(string), "The health hack check on %s has been finished and the result is {6EF83C}positive{FFFFFF}.", playersName);
		SendClientMessage(playerid, -1, string);
		
		svCheats_HH[giveplayerid][svCheckedBy] = INVALID_PLAYER_ID;
		
		SetPlayerVirtualWorld(giveplayerid, svCheats_HH[giveplayerid][svVirtualWorld]);
		SetPlayerInterior(giveplayerid, svCheats_HH[giveplayerid][svInterior]);
		SetPlayerPos(giveplayerid, svCheats_HH[giveplayerid][svOldPlayerPos][0], svCheats_HH[giveplayerid][svOldPlayerPos][1], svCheats_HH[giveplayerid][svOldPlayerPos][2]);
		SetPlayerFacingAngle(giveplayerid, svCheats_HH[giveplayerid][svOldPlayerPos][3]);
		
		if(svCheats_HH[giveplayerid][svInVehicle] == true)
		{
		    PutPlayerInVehicle(giveplayerid, svCheats_HH[giveplayerid][svVehicleID], svCheats_HH[giveplayerid][svVehicleSeat]);
		}
		
		SetPlayerHealth(giveplayerid, svCheats_HH[giveplayerid][svHealth]);
		SetPlayerArmour(giveplayerid, svCheats_HH[giveplayerid][svArmor]);
		
		SetCameraBehindPlayer(giveplayerid);
		
		svCheats_CallDetection(giveplayerid, CHEAT_GODMODE);
  		svCheats_AmountDetected++;
	}
	return 1;
}

forward svCheats_JumpCountersDown(playerid);
public svCheats_JumpCountersDown(playerid)
{
	svCheats_JumpCounters[playerid]--;
	svCheats_JumpCounterTimer[playerid] = -1;
	return 1;
}

forward svCheats_KillAmountDown(playerid);
public svCheats_KillAmountDown(playerid)
{
	return svCheats_KillAmount[playerid]--;
}

svCheats_CallDetection(playerid, cheatid)
{
	return CallRemoteFunction("svCheats_OnPlayerCheatUpdate", "dd", playerid, cheatid);
}

svCheats_GetWeaponSlot(weaponid)
{
	switch(weaponid)
	{
		case 0, 1:
		{
			return 0;
		}
		case 2, 3, 4, 5, 6, 7, 8, 9:
		{
			return 1;
		}
		case 22, 23, 24:
		{
			return 2;
		}
		case 25, 26, 27:
		{
			return 3;
		}
		case 28, 29, 32:
		{
			return 4;
		}
		case 30, 31:
		{
			return 5;
		}
		case 33, 34:
		{
			return 6;
		}
		case 35, 36, 37, 38:
		{
			return 7;
		}
		case 16, 17, 18, 39, 40:
		{
			return 8;
		}
		case 41, 42, 43:
		{
			return 9;
		}
		case 10, 11, 12, 13, 14, 15:
		{
			return 10;
		}
  		case 44, 45, 46:
		{
			return 11;
		}
	}
	return 0;
}

svCheats_IsPlayerAtRepairPoint(playerid)
{
	if(GetPlayerCameraMode(playerid) == 15) return 1;
	if(IsPlayerInRangeOfPoint(playerid, 25.0, 2067.00, -1831.65, 13.55)) return 1;
	if(IsPlayerInRangeOfPoint(playerid, 25.0, 1024.97, -1023.88, 32.10)) return 1;
	if(IsPlayerInRangeOfPoint(playerid, 25.0, 1041.19, -1022.50, 32.11)) return 1;
	if(IsPlayerInRangeOfPoint(playerid, 25.0, 720.25, -457.17, 16.34)) return 1;
	if(IsPlayerInRangeOfPoint(playerid, 25.0, 2386.66, 1045.68, 10.82)) return 1;
	if(IsPlayerInRangeOfPoint(playerid, 25.0, 1972.50, 2163.03, 11.07)) return 1;
	if(IsPlayerInRangeOfPoint(playerid, 25.0, -1420.58, 2586.17, 55.84)) return 1;
	if(IsPlayerInRangeOfPoint(playerid, 25.0, -1904.90, 283.96, 41.05)) return 1;
	if(IsPlayerInRangeOfPoint(playerid, 25.0, -2719.46, 217.77, 4.48)) return 1;
	return 0;
}

svCheats_IsPlayerAtHealingPoint(playerid)
{
	if(IsPlayerInRangeOfPoint(playerid, 50.0, 286.148, -40.644, 1001.569)) return 1;
	if(IsPlayerInRangeOfPoint(playerid, 50.0, 286.148, -82.547, 1001.569)) return 1;
	if(IsPlayerInRangeOfPoint(playerid, 50.0, 296.148, -108.644, 1001.569)) return 1;
	if(IsPlayerInRangeOfPoint(playerid, 50.0, 316.524, -167.706, 999.661)) return 1;
	if(IsPlayerInRangeOfPoint(playerid, 4.0, -2420.219, 984.578, 44.297)) return 1;
 	if(IsPlayerInRangeOfPoint(playerid, 4.0, -2420.180, 985.945, 44.297)) return 1;
  	if(IsPlayerInRangeOfPoint(playerid, 4.0, 2225.203, -1153.422, 1025.906)) return 1;
   	if(IsPlayerInRangeOfPoint(playerid, 4.0, 2576.703, -1284.430, 1061.094)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 2155.906, 1606.773, 1000.055)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 2209.906, 1607.195, 1000.055)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 2222.203, 1606.773, 1000.055)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 495.969, -24.320, 1000.734)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 501.828, -1.430, 1000.734)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 373.828, -178.141, 1000.734)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 330.680, 178.500, 1020.070)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 331.922, 178.500, 1020.070)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 350.906, 206.086, 1008.477)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 361.563, 158.617, 1008.477)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 371.594, 178.453, 1020.070)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 374.891, 188.977, 1008.477)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 2155.844, 1607.875, 1000.063)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 2202.453, 1617.008, 1000.063)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 2209.242, 1621.211, 1000.063)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 2222.367, 1602.641, 1000.063)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 500.563, -1.367, 1000.734)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 379.039, -178.883, 1000.734)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 2480.86,-1959.27,12.9609)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 1634.11,-2237.53,12.8906)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 2139.52,-1161.48,23.3594)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 2153.23,-1016.15,62.2344)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, -1350.12,493.859,10.5859)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, -2229.19,286.414,34.7031)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 1659.46,1722.86,10.2188)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 2647.7,1129.66,10.2188)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 2845.73,1295.05,10.7891)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 1398.84,2222.61,10.4219)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, -1455.12,2591.66,55.2344)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, -76.0312,1227.99,19.125)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 662.43,-552.164,15.7109)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, -253.742,2599.76,62.2422)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 2271.73,-76.4609,25.9609)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 1789.21,-1369.27,15.1641)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 1729.79,-1943.05,12.9453)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 2060.12,-1897.64,12.9297)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 1928.73,-1772.45,12.9453)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 2325.98,-1645.13,14.2109)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 2352.18,-1357.16,23.7734)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 1154.73,-1460.89,15.1562)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, -1350.12,492.289,10.5859)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, -2118.97,-423.648,34.7266)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, -2118.62,-422.414,34.7266)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, -2097.27,-398.336,34.7266)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, -2092.09,-490.055,34.7266)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, -2063.27,-490.055,34.7266)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, -2005.65,-490.055,34.7266)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, -2034.46,-490.055,34.7266)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, -2068.56,-398.336,34.7266)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, -2039.85,-398.336,34.7266)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, -2011.14,-398.336,34.7266)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, -1980.79,142.664,27.0703)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 2319.99,2532.85,10.2188)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 1520.15,1055.27,10.00)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 2503.14,1243.7,10.2188)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 2085.77,2071.36,10.4531)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, -862.828,1536.61,21.9844)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, -14.7031,1175.36,18.9531)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, -253.742,2597.95,62.2422)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 201.016,-107.617,0.898438)) return 1;
    if(IsPlayerInRangeOfPoint(playerid, 4.0, 1277.84,372.516,18.9531)) return 1;
    return 0;
}

svCheats_GetSwimmingPointZ(playerid)
{
	if(IsPlayerInRangeOfPoint(playerid, 50.0, 1962.15, -1198.71, 17.45)) return 19;
	if(IsPlayerInRangeOfPoint(playerid, 100.0, -1127.58, 2764.43, 40.00)) return 43;
	if(IsPlayerInRangeOfPoint(playerid, 100.0, -988.19, 2486.89, 40.00)) return 43;
	if(IsPlayerInRangeOfPoint(playerid, 100.0, -924.33, 2306.59, 40.00)) return 43;
	if(IsPlayerInRangeOfPoint(playerid, 100.0, -1104.15, 2175.83, 40.00)) return 43;
	if(IsPlayerInRangeOfPoint(playerid, 100.0, -1307.06, 2119.33, 40.00)) return 43;
	if(IsPlayerInRangeOfPoint(playerid, 100.0, -831.85, 2122.23, 40.00)) return 43;
	if(IsPlayerInRangeOfPoint(playerid, 100.0, -595.76, 2138.34, 40.00)) return 43;
	if(IsPlayerInRangeOfPoint(playerid, 100.0, -569.24, 2274.40, 40.00)) return 43;
	if(IsPlayerInRangeOfPoint(playerid, 12.0, 1095.800, -674.950, 111.908)) return 113;
 	if(IsPlayerInRangeOfPoint(playerid, 12.0, 224.500, -1185.725, 73.908)) return 76;
  	if(IsPlayerInRangeOfPoint(playerid, 12.0, 193.700, -1230.608, 76.603)) return 79;
   	if(IsPlayerInRangeOfPoint(playerid, 12.0, 1277.500, -805.200, 86.581)) return 88;
    if(IsPlayerInRangeOfPoint(playerid, 12.0, 2582.0, 2387.0, 16.0)) return 18;
	return 10;
}

svCheats_GetVehicleSpeed(vehicleid)
{
    new Float: vVel[3];
	GetVehicleVelocity(vehicleid, vVel[0], vVel[1], vVel[2]);
	return floatround(floatsqroot((vVel[0]*vVel[1]+vVel[2]*vVel[2]))*100.0*1.6);
}

svCheats_IllegalCarNitroIde(carmodel)
{
    new illegalvehs[29] = { 581, 523, 462, 521, 463, 522, 461, 448, 468, 586, 509, 481, 510, 472, 473, 493, 595, 484, 430, 453, 452, 446, 454, 590, 569, 537, 538, 570, 449 };

    for(new i = 0; i < sizeof(illegalvehs); i++)
	{
        if(carmodel == illegalvehs[i])
        {
            return 1;
		}
    }
    return 0;
}

svCheats_IsComponentWheel(componentid)
{
    new wheelmodels[17] = {1025,1073,1074,1075,1076,1077,1078,1079,1080,1081,1082,1083,1084,1085,1096,1097,1098};

    for(new i = 0; i < sizeof(wheelmodels); i++)
	{
        if(componentid == wheelmodels[i])
        {
            return 1;
		}
    }

    return 0;
}

svCheats_IsAllowedCarMod(vehicleide, componentid)
{
    new bool: modok = false;

    if(svCheats_IsComponentWheel(componentid) || componentid == 1086 || componentid == 1087 || (componentid >= 1008 && componentid <= 1010))
	{
        if(!svCheats_IllegalCarNitroIde(vehicleide))
        {
            modok = true;
		}
    }
	else
	{
        for(new i = 0; i < sizeof(legalmods2); i++)
		{
            if(legalmods2[i][0] == vehicleide)
			{
                for(new j = 1; j < 22; j++)
				{
                    if(legalmods2[i][j] == componentid)
                    {
                        modok = true;
					}
                }

            }

        }

    }

    return modok;
}

svCheats_Intabs(innumber)
{
    if(innumber < 0)
    {
        return -innumber;
	}

    return innumber;
}

svCheats_Distance1Dint(fPos1, fPos2)
{
    if(fPos1 > fPos2)
    {
        return svCheats_Intabs(fPos1 - fPos2);
	}
    else
    {
        return svCheats_Intabs(fPos2 - fPos1);
	}

}

svCheats_GetTimeDistance(a, b)
{
    if(a < 0 && b > 0)
	{
        new dist;
        dist = svCheats_Distance1Dint(a, b);
        if(dist > 2147483647)
        {
            return svCheats_Distance1Dint(a - 2147483647, b - 2147483647);
		}
        else
        {
            return dist;
		}
    }
	else
	{
        return svCheats_Distance1Dint(a, b);

    }

}

svCheats_inet_aton(ip[])
{
    new ipv = strval(ip) << 24, pos = 0;

    while (pos < 15 && ip[pos++] != '.') {}
    ipv += strval(ip[pos]) << 16;
    while (pos < 15 && ip[pos++] != '.') {}
    ipv += strval(ip[pos]) << 8;
    while (pos < 15 && ip[pos++] != '.') {}
    ipv += strval(ip[pos]);

    return ipv;
}

svCheats_log_new_join(playerid) {

    new ip[18];
    GetPlayerIp(playerid, ip, sizeof(ip));
    new ipv = svCheats_inet_aton(ip);

    svCheats_IPJoin[svCheats_ajs][svIP_Add] = ipv;
    svCheats_IPJoin[svCheats_ajs][svTimestamp] = tickcount();

    svCheats_ajs++;

    if(svCheats_ajs >= 37)
    {
        svCheats_ajs = 0;
	}

}

svCheats_NJTR(playerid, max_time) {

    new ip[18];
    GetPlayerIp(playerid, ip, sizeof(ip));

    new ipv = svCheats_inet_aton(ip);
    new counted = 0;

    for(new i = 0; i < sizeof(svCheats_IPJoin); i++)
	{
        if(svCheats_IPJoin[i][svIP_Add] != ipv)
        {
            continue;
		}

        if(svCheats_GetTimeDistance(tickcount(), svCheats_IPJoin[i][svTimestamp]) <= max_time)
        {
            counted++;
		}

    }

    return counted;
}

public svCheats_Detector()
{
	#if defined USE_FOREACH
	    foreach(new playerid: Player)
	    {
	        #if defined HIGH_PING
	    		if(svCheats_SecurityLevel[playerid] < HIGH_PING || HIGH_PING == -1)
	    		{
	    		    if(GetPlayerPing(playerid) > MAX_PING)
	    		    {
	    		        svCheats_CallDetection(playerid, CHEAT_HIGH_PING);
	    		        svCheats_AmountDetected++;
	    		    }
	    		}
			#endif
			
			#if defined SPEED_HACK
			    if(svCheats_SecurityLevel[playerid] < SPEED_HACK || SPEED_HACK == -1)
			    {
			        if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
			        {
			            new vehicleid = GetPlayerVehicleID(playerid);
			            if(svCheats_GetVehicleSpeed(vehicleid) > MAX_SPEED)
			            {
			                if(GetVehicleModel(vehicleid) != 520)
			                {
			                    new Float: vehicleVelocity[3];
			                    GetVehicleVelocity(vehicleid, vehicleVelocity[0], vehicleVelocity[1], vehicleVelocity[2]);
			                    if(vehicleVelocity[2] > -0.5)
			                    {
				                    svCheats_CallDetection(playerid, CHEAT_SPEED_HACK);
				                    svCheats_AmountDetected++;
			                    }
			                }
			            }
			        }
			    }
			#endif
			
			#if defined JETPACK_HACK
				if(svCheats_SecurityLevel[playerid] < JETPACK_HACK || JETPACK_HACK == -1)
				{
				    if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK)
				    {
				        if(svCheats_GrantedJetpack[playerid] == false && svCheats_ReportedTabbed[playerid] == false)
				        {
				            svCheats_CallDetection(playerid, CHEAT_JETPACK_HACK);
				            svCheats_AmountDetected++;
				        }
				    }
				    else
				    {
				        svCheats_GrantedJetpack[playerid] = false;
				    }
				}
			#endif
			
			#if defined AIRBREAK_HACK
			    if(svCheats_SecurityLevel[playerid] < AIRBREAK_HACK || AIRBREAK_HACK == -1)
			    {
			        new ai = GetPlayerAnimationIndex(playerid);
			        if(ai == 1231 || ai == 1266)
			        {
			            new Float: playersPos[3];
			            GetPlayerPos(playerid, playersPos[0], playersPos[1], playersPos[2]);
			            if(playersPos[2] > svCheats_GetSwimmingPointZ(playerid))
			            {
			                if(!IsPlayerInRangeOfPoint(playerid, 200.0, 602.74, 871.44, -20.65) && !IsPlayerInRangeOfPoint(playerid, 300.0, 1678.38, -2291.18, -1.00))
			                {
			                    if(GetPointZPos(playersPos[0], playersPos[1]) < playersPos[2] - 15.0)
			                    {
			                        svCheats_CallDetection(playerid, CHEAT_AIRBREAK_HACK);
			                        svCheats_AmountDetected++;
			                    }
			                }
			            }
			        }
			    }
			#endif
			
			#if defined FLY_HACK
			    if(svCheats_SecurityLevel[playerid] < FLY_HACK || FLY_HACK == -1)
			    {
			        if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
			        {
						new ai = GetPlayerAnimationIndex(playerid);
						if(ai == 1538 || ai == 1538 || ai == 1543)
						{
							if(!GetPlayerInterior(playerid))
							{
							    new Float: playersPos[3];
							    GetPlayerPos(playerid, playersPos[0], playersPos[1], playersPos[2]);
							    if(playersPos[2] > svCheats_GetSwimmingPointZ(playerid))
							    {
							        svCheats_CallDetection(playerid, CHEAT_FLY_HACK);
							        svCheats_AmountDetected++;
							    }
						    }
						}
			        }
			    }
			#endif
			
			#if defined TELEPORT_HACK
				if(svCheats_SecurityLevel[playerid] < TELEPORT_HACK || TELEPORT_HACK == -1)
				{
				    if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
				    {
						new interior = GetPlayerInterior(playerid);
						if(interior > 0)
						{
							new allowedInteriors[10], bool: allowed;
							sscanf(USED_INTERIORS, "a<i>[10]", allowedInteriors);
							
							for(new i = 0; i < sizeof(allowedInteriors); i++)
							{
							    if(allowedInteriors[i] == interior)
							    {
							        allowed = true;
							        break;
							    }
							}
							
							if(allowed == false)
							{
							    svCheats_CallDetection(playerid, CHEAT_TELEPORT_HACK);
							    svCheats_AmountDetected++;
							}
						}
				    }
				}
			#endif
			
			#if defined VEHICLE_REPAIR
			    if(svCheats_SecurityLevel[playerid] < VEHICLE_REPAIR || VEHICLE_REPAIR == -1)
			    {
			        if(svCheats_ReportedTabbed[playerid] == false)
			        {
				        if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
				        {
				            new vehicleid = GetPlayerVehicleID(playerid), Float: vHealth;
				            GetVehicleHealth(vehicleid, vHealth);
				            if(vHealth > svCheats_VehicleHealth[vehicleid])
				            {
				                if(!svCheats_IsPlayerAtRepairPoint(playerid))
				                {
				                	svCheats_CallDetection(playerid, CHEAT_VEHICLE_REPAIR);
				                	svCheats_AmountDetected++;
				                }
				            }
				            svCheats_VehicleHealth[vehicleid] = vHealth;
				        }
			        }
			    }
			#endif
			
			#if defined CHATSPAM_OFF
			    if(svCheats_SecurityLevel[playerid] < CHATSPAM_OFF || CHATSPAM_OFF == -1)
			    {
				    svCheats_SpamCounters[playerid]--;

				    if(svCheats_SpamCounters[playerid] < 0)
				    {
				        svCheats_SpamCounters[playerid] = 0;
				    }
			    }
			#endif
			
			#if defined AFK_DISABLED
   				if(svCheats_SecurityLevel[playerid] < AFK_DISABLED || AFK_DISABLED == -1)
			    {
       				if(svCheats_ReportedAFK[playerid] == false)
			        {
           				new Float: playersPos[3];
			            GetPlayerPos(playerid, playersPos[0], playersPos[1], playersPos[2]);
						if(playersPos[0] != svCheats_oldPos[playerid][0] || playersPos[1] != svCheats_oldPos[playerid][1] || playersPos[2] != svCheats_oldPos[playerid][2])
						{
		    				svCheats_AFKTime[playerid] = 0;
          				}
            			else
			            {
					    	svCheats_AFKTime[playerid] += GetTickCount() - svCheats_LastAFKUpdate[playerid];
		    			}

						svCheats_LastAFKUpdate[playerid] = GetTickCount();

						svCheats_oldPos[playerid][0] = playersPos[0], svCheats_oldPos[playerid][1] = playersPos[1], svCheats_oldPos[playerid][2] = playersPos[2];

						if(svCheats_ReportedAFK[playerid] == false)
		    			{
	        				new AFKMinutes = svCheats_AFKTime[playerid] / 60000;
				    		if(AFKMinutes >= AFK_MINUTES)
					    	{
   								svCheats_ReportedAFK[playerid] = true;
		    	    			svCheats_CallDetection(playerid, CHEAT_AFK);
				    	    	svCheats_AmountDetected++;
					    	}
				    	}
		    		}
		    	}
			#endif
			
			#if defined TABBED_DISABLED
			    if(svCheats_SecurityLevel[playerid] < TABBED_DISABLED || TABBED_DISABLED == -1)
			    {
			        if(svCheats_ReportedTabbed[playerid] == false && svCheats_TabbedDisabled[playerid] == false)
			        {
			            if(GetPlayerCameraMode(playerid) != 55 && (GetPlayerState(playerid) < 4 || GetPlayerState(playerid) > 6))
			            {
							svCheats_TabbedUpdates[playerid]++;

							if(svCheats_TabbedUpdates[playerid] > 1)
							{
							    svCheats_TabbedUpdates[playerid] = 0;
							    svCheats_ReportedTabbed[playerid] = true;
							    svCheats_CallDetection(playerid, CHEAT_TABBED);
							    svCheats_AmountDetected++;
							}
						}
					}
				}
			#endif
			
			#if defined HEALTH_HACK
			    if(svCheats_SecurityLevel[playerid] < HEALTH_HACK || HEALTH_HACK == -1)
			    {
			        if(svCheats_HealthHackDisabled[playerid] == false && svCheats_ReportedTabbed[playerid] == false)
			        {
		        		new Float: Health, Float: Armor;
			        	GetPlayerHealth(playerid, Health);
			        	GetPlayerArmour(playerid, Armor);
			        	if(!svCheats_IsPlayerAtHealingPoint(playerid))
			        	{
				        	if(svCheats_PlayerHealth[playerid] < Health || svCheats_PlayerArmor[playerid] < Armor)
				        	{
	           					svCheats_CallDetection(playerid, CHEAT_HEALTHHACK);
				            	svCheats_AmountDetected++;
				        	}
			        	}
			        	svCheats_PlayerHealth[playerid] = Health;
			        	svCheats_PlayerArmor[playerid] = Armor;
		        	}
			    }
			#endif
	    }
	#else
	    for(new playerid = 0; playerid < MAX_PLAYERS; playerid++)
	    {
	        if(IsPlayerConnected(playerid))
	        {
				 #if defined HIGH_PING
		    		if(svCheats_SecurityLevel[playerid] < HIGH_PING || HIGH_PING == -1)
		    		{
		    		    if(GetPlayerPing(playerid) > MAX_PING)
		    		    {
		    		        svCheats_CallDetection(playerid, CHEAT_HIGH_PING);
		    		        svCheats_AmountDetected++;
		    		    }
		    		}
				#endif

				#if defined SPEED_HACK
				    if(svCheats_SecurityLevel[playerid] < SPEED_HACK || SPEED_HACK == -1)
				    {
				        if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
				        {
				            new vehicleid = GetPlayerVehicleID(playerid);
				            if(svCheats_GetVehicleSpeed(vehicleid) > MAX_SPEED)
				            {
				                if(GetVehicleModel(vehicleid) != 520)
				                {
				                    new Float: vehicleVelocity[3];
				                    GetVehicleVelocity(vehicleid, vehicleVelocity[0], vehicleVelocity[1], vehicleVelocity[2]);
				                    if(vehicleVelocity[2] > -0.5)
				                    {
					                    svCheats_CallDetection(playerid, CHEAT_SPEED_HACK);
					                    svCheats_AmountDetected++;
				                    }
				                }
				            }
				        }
				    }
				#endif

				#if defined JETPACK_HACK
					if(svCheats_SecurityLevel[playerid] < JETPACK_HACK || JETPACK_HACK == -1)
					{
					    if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK)
					    {
					        if(svCheats_GrantedJetpack[playerid] == false && svCheats_ReportedTabbed[playerid] == false)
					        {
					            svCheats_CallDetection(playerid, CHEAT_JETPACK_HACK);
					            svCheats_AmountDetected++;
					        }
					    }
					    else
					    {
					        svCheats_GrantedJetpack[playerid] = false;
					    }
					}
				#endif

				#if defined AIRBREAK_HACK
				    if(svCheats_SecurityLevel[playerid] < AIRBREAK_HACK || AIRBREAK_HACK == -1)
				    {
				        new ai = GetPlayerAnimationIndex(playerid);
				        if(ai == 1231 || ai == 1266)
				        {
				            new Float: playersPos[3];
				            GetPlayerPos(playerid, playersPos[0], playersPos[1], playersPos[2]);
				            if(playersPos[2] > svCheats_GetSwimmingPointZ(playerid))
				            {
				                if(!IsPlayerInRangeOfPoint(playerid, 200.0, 602.74, 871.44, -20.65) && !IsPlayerInRangeOfPoint(playerid, 300.0, 1678.38, -2291.18, -1.00))
				                {
				                    if(GetPointZPos(playersPos[0], playersPos[1]) < playersPos[2] - 15.0)
				                    {
				                        svCheats_CallDetection(playerid, CHEAT_AIRBREAK_HACK);
				                        svCheats_AmountDetected++;
				                    }
				                }
				            }
				        }
				    }
				#endif

				#if defined FLY_HACK
				    if(svCheats_SecurityLevel[playerid] < FLY_HACK || FLY_HACK == -1)
				    {
				        if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
				        {
							new ai = GetPlayerAnimationIndex(playerid);
							if(ai == 1538 || ai == 1538 || ai == 1543)
							{
							    if(!GetPlayerInterior(playerid))
							    {
								    new Float: playersPos[3];
								    GetPlayerPos(playerid, playersPos[0], playersPos[1], playersPos[2]);
								    if(playersPos[2] > svCheats_GetSwimmingPointZ(playerid))
								    {
								        svCheats_CallDetection(playerid, CHEAT_FLY_HACK);
								        svCheats_AmountDetected++;
								    }
							    }
							}
				        }
				    }
				#endif

				#if defined TELEPORT_HACK
					if(svCheats_SecurityLevel[playerid] < TELEPORT_HACK || TELEPORT_HACK == -1)
					{
					    if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
					    {
							new interior = GetPlayerInterior(playerid);
							if(interior > 0)
							{
								new allowedInteriors[10], bool: allowed;
								sscanf(USED_INTERIORS, "a<i>[10]", allowedInteriors);

								for(new i = 0; i < sizeof(allowedInteriors); i++)
								{
								    if(allowedInteriors[i] == interior)
								    {
								        allowed = true;
								        break;
								    }
								}

								if(allowed == false)
								{
								    svCheats_CallDetection(playerid, CHEAT_TELEPORT_HACK);
								    svCheats_AmountDetected++;
								}
							}
					    }
					}
				#endif

				#if defined VEHICLE_REPAIR
				    if(svCheats_SecurityLevel[playerid] < VEHICLE_REPAIR || VEHICLE_REPAIR == -1)
				    {
				        if(svCheats_ReportedTabbed[playerid] == false)
				        {
					        if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
					        {
					            new vehicleid = GetPlayerVehicleID(playerid), Float: vHealth;
					            GetVehicleHealth(vehicleid, vHealth);
					            if(vHealth > svCheats_VehicleHealth[vehicleid])
					            {
					                if(!svCheats_IsPlayerAtRepairPoint(playerid))
					                {
					                	svCheats_CallDetection(playerid, CHEAT_VEHICLE_REPAIR);
					                	svCheats_AmountDetected++;
					                }
					            }
					            svCheats_VehicleHealth[vehicleid] = vHealth;
					        }
				        }
				    }
				#endif

				#if defined CHATSPAM_OFF
				    if(svCheats_SecurityLevel[playerid] < CHATSPAM_OFF || CHATSPAM_OFF == -1)
				    {
					    svCheats_SpamCounters[playerid]--;

					    if(svCheats_SpamCounters[playerid] < 0)
					    {
					        svCheats_SpamCounters[playerid] = 0;
					    }
				    }
				#endif

				#if defined AFK_DISABLED
	   				if(svCheats_SecurityLevel[playerid] < AFK_DISABLED || AFK_DISABLED == -1)
				    {
	       				if(svCheats_ReportedAFK[playerid] == false)
				        {
	           				new Float: playersPos[3];
				            GetPlayerPos(playerid, playersPos[0], playersPos[1], playersPos[2]);
							if(playersPos[0] != svCheats_oldPos[playerid][0] || playersPos[1] != svCheats_oldPos[playerid][1] || playersPos[2] != svCheats_oldPos[playerid][2])
							{
			    				svCheats_AFKTime[playerid] = 0;
	          				}
	            			else
				            {
						    	svCheats_AFKTime[playerid] += GetTickCount() - svCheats_LastAFKUpdate[playerid];
			    			}

							svCheats_LastAFKUpdate[playerid] = GetTickCount();

							svCheats_oldPos[playerid][0] = playersPos[0], svCheats_oldPos[playerid][1] = playersPos[1], svCheats_oldPos[playerid][2] = playersPos[2];

							if(svCheats_ReportedAFK[playerid] == false)
			    			{
		        				new AFKMinutes = svCheats_AFKTime[playerid] / 60000;
					    		if(AFKMinutes >= AFK_MINUTES)
						    	{
	   								svCheats_ReportedAFK[playerid] = true;
			    	    			svCheats_CallDetection(playerid, CHEAT_AFK);
					    	    	svCheats_AmountDetected++;
						    	}
					    	}
			    		}
			    	}
				#endif

				#if defined TABBED_DISABLED
				    if(svCheats_SecurityLevel[playerid] < TABBED_DISABLED || TABBED_DISABLED == -1)
				    {
				        if(svCheats_ReportedTabbed[playerid] == false && svCheats_TabbedDisabled[playerid] == false)
				        {
				            if(GetPlayerCameraMode(playerid) != 55 && (GetPlayerState(playerid) < 4 || GetPlayerState(playerid) > 6))
				            {
								svCheats_TabbedUpdates[playerid]++;

								if(svCheats_TabbedUpdates[playerid] > 1)
								{
								    svCheats_TabbedUpdates[playerid] = 0;
								    svCheats_ReportedTabbed[playerid] = true;
								    svCheats_CallDetection(playerid, CHEAT_TABBED);
								    svCheats_AmountDetected++;
								}
							}
						}
					}
				#endif

    			#if defined HEALTH_HACK
				    if(svCheats_SecurityLevel[playerid] < HEALTH_HACK || HEALTH_HACK == -1)
				    {
				        if(svCheats_HealthHackDisabled[playerid] == false && svCheats_ReportedTabbed[playerid] == false)
				        {
					        new Float: Health, Float: Armor;
					        GetPlayerHealth(playerid, Health);
					        GetPlayerArmour(playerid, Armor);
					        if(!svCheats_IsPlayerAtHealingPoint(playerid))
					        {
						        if(svCheats_PlayerHealth[playerid] < Health || svCheats_PlayerArmor[playerid] < Armor)
						        {
						            svCheats_CallDetection(playerid, CHEAT_HEALTHHACK);
						            svCheats_AmountDetected++;
						        }
					        }
					        svCheats_PlayerHealth[playerid] = Health;
					        svCheats_PlayerArmor[playerid] = Armor;
			        	}
				    }
				#endif
			}
		}
	#endif
	return 1;
}

stock svCheats_Debug(bool: togDebug)
{
	if(togDebug == true)
	{
	    print("(svCheats) Debugging has been turned on");
	}
	else if(togDebug == false)
	{
	    print("(svCheats) Debugging has been turned off");
	}
	
	return svCheats_Debugging = togDebug;
}

stock svCheats_SetPlayerSecurityLevel(playerid, secLevel)
{
	if(svCheats_Debugging == true)
	{
	    printf("(svCheats) SetPlayerSecurityLevel(playerid = %d, secLevel = %d)", playerid, secLevel);
	}
	
	return svCheats_SecurityLevel[playerid] = secLevel;
}

stock svCheats_GetPlayerSecurityLevel(playerid)
{
    if(svCheats_Debugging == true)
	{
	    printf("(svCheats) GetPlayerSecurityLevel(playerid = %d)", playerid);
	}
	
	return svCheats_SecurityLevel[playerid];
}

stock svCheats_SetVehicleHealth(vehicleid, Float: vHealth)
{
    if(svCheats_Debugging == true)
	{
	    printf("(svCheats) SetVehicleHealth(vehicleid = %d, vHealth = %f)", vehicleid, vHealth);
	}

	svCheats_VehicleHealth[vehicleid] = vHealth;
	return SetVehicleHealth(vehicleid, vHealth);
}

#if defined _ALS_SetVehicleHealth
        #undef SetVehicleHealth
#else
        #define _ALS_SetVehicleHealth
#endif
#define SetVehicleHealth svCheats_SetVehicleHealth

stock svCheats_GivePlayerWeapon(playerid, weaponid, ammo)
{
	if(svCheats_Debugging == true)
	{
	    printf("(svCheats) GivePlayerWeapon(playerid = %d, weaponid = %d, ammo = %d)", playerid, weaponid, ammo);
	}

	svCheats_PlayerWeapons[playerid][GetWeaponSlot(weaponid)] = weaponid;
	return GivePlayerWeapon(playerid, weaponid, ammo);
}

#if defined _ALS_GivePlayerWeapon
	#undef GivePlayerWeapon
#else
	#define _ALS_GivePlayerWeapon
#endif
#define GivePlayerWeapon svCheats_GivePlayerWeapon

stock svCheats_SetPlayerHealth(playerid, Float: pHealth)
{
    if(svCheats_Debugging == true)
	{
	    printf("(svCheats) SetPlayerHealth(playerid = %d, pHealth = %f)", playerid, pHealth);
	}

	svCheats_PlayerHealth[playerid] = pHealth;
	return SetPlayerHealth(playerid, pHealth);
}

#if defined _ALS_SetPlayerHealth
	#undef SetPlayerHealth
#else
	#define _ALS_SetPlayerHealth
#endif
//#define SetPlayerHealth svCheats_SetPlayerHealth

stock svCheats_SetPlayerArmour(playerid, Float: pArmour)
{
    if(svCheats_Debugging == true)
	{
	    printf("(svCheats) SetPlayerArmour(playerid = %d, pArmour = %f)", playerid, pArmour);
	}

	svCheats_PlayerArmor[playerid] = pArmour;
	return SetPlayerArmour(playerid, pArmour);
}

#if defined _ALS_SetPlayerArmour
	#undef SetPlayerArmour
#else
	#define _ALS_SetPlayerArmour
#endif
//#define SetPlayerArmour svCheats_SetPlayerArmour

stock svCheats_SetPlayerSpecialAction(playerid, actionid)
{
	if(actionid == SPECIAL_ACTION_USEJETPACK)
	{
		svCheats_GrantedJetpack[playerid] = true;
	}
	else if(actionid == SPECIAL_ACTION_NONE)
	{
	    svCheats_GrantedJetpack[playerid] = false;
	}
	return SetPlayerSpecialAction(playerid, actionid);
}

#if defined _ALS_SetPlayerSpecialAction
	#undef SetPlayerSpecialAction
#else
	#define _ALS_SetPlayerSpecialAction
#endif
#define SetPlayerSpecialAction svCheats_SetPlayerSpecialAction

stock svCheats_ClearAnimations(playerid)
{
	svCheats_GrantedJetpack[playerid] = false;
	return ClearAnimations(playerid);
}

#if defined _ALS_ClearAnimations
	#undef ClearAnimations
#else
	#define _ALS_ClearAnimations
#endif
#define ClearAnimations svCheats_ClearAnimations
