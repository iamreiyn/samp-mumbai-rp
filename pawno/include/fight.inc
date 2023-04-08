#include <a_samp>

// ---- STYLES
#define FIGHT_NORMAL 	0
#define FIGHT_BOXING 	1
#define FIGHT_KARATE 	2
#define FIGHT_GANGSTER 	3
//---- HIT SOUND
#define SOUND 			1130
//---- WAIT TIME
#define WAIT_ANIM_END 1000
//---- ApplyAnimation param
//----------------------------- speed,loop,lockXY,freeze,lenght
#define ANIM_PARAM 4.1, 0, 1, 1, 0, 0

forward KickWaitNull(playerid);

new FightStyle[MAX_PLAYERS];
new KickState[MAX_PLAYERS];
new KickWait[MAX_PLAYERS];

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(newkeys & KEY_FIRE && newkeys != KEY_SPRINT && IsValidWeapon(playerid) && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		if(GetPlayerFightingStyle(playerid) == FIGHT_KARATE)
		{
			if(KickWait[playerid] == 0)
			{
				if(KickState[playerid] == 3) KickState[playerid] = 0;
				if(KickState[playerid] == 0)
				{
					KickState[playerid] = 1;
					ApplyAnimation(playerid,"FIGHT_C","FightC_1",ANIM_PARAM);
					KickWait[playerid] = 1;
					SetTimerEx("KickWaitNull", WAIT_ANIM_END, 0, "i", playerid);
					HurtClosestPlayer(playerid);
					return 1;
				}
				if(KickState[playerid] == 1)
				{
					KickState[playerid] = 2;
					ApplyAnimation(playerid,"FIGHT_C","FightC_2",ANIM_PARAM);
					KickWait[playerid] = 1;
					SetTimerEx("KickWaitNull", WAIT_ANIM_END, 0, "i", playerid);
					HurtClosestPlayer(playerid);
					return 1;
				}
				if(KickState[playerid] == 2)
				{
					KickState[playerid] = 3;
					ApplyAnimation(playerid,"FIGHT_C","FightC_3",ANIM_PARAM);
					KickWait[playerid] = 1;
					SetTimerEx("KickWaitNull", WAIT_ANIM_END, 0, "i", playerid);
					HurtClosestPlayer(playerid);
					return 1;
				}
			}
			else
			{
				return 1;
			}
		}
		else if(GetPlayerFightingStyle(playerid) == FIGHT_BOXING)
		{
			if(KickWait[playerid] == 0)
			{
				if(KickState[playerid] == 3) KickState[playerid] = 0;
				if(KickState[playerid] == 0)
				{
					KickState[playerid] = 1;
					ApplyAnimation(playerid,"FIGHT_B","FightB_1",ANIM_PARAM);
					KickWait[playerid] = 1;
					SetTimerEx("KickWaitNull", WAIT_ANIM_END, 0, "i", playerid);
					HurtClosestPlayer(playerid);
					return 1;
				}
				if(KickState[playerid] == 1)
				{
					KickState[playerid] = 2;
					ApplyAnimation(playerid,"FIGHT_B","FightB_2",ANIM_PARAM);
					KickWait[playerid] = 1;
					SetTimerEx("KickWaitNull", WAIT_ANIM_END, 0, "i", playerid);
					HurtClosestPlayer(playerid);
					return 1;
				}
				if(KickState[playerid] == 2)
				{
					KickState[playerid] = 3;
					ApplyAnimation(playerid,"FIGHT_B","FightB_3",ANIM_PARAM);
					KickWait[playerid] = 1;
					SetTimerEx("KickWaitNull", WAIT_ANIM_END, 0, "i", playerid);
					HurtClosestPlayer(playerid);
					return 1;
				}
			}
			else
			{
				return 1;
			}
		}
		else if(GetPlayerFightingStyle(playerid) == FIGHT_GANGSTER)
		{
			if(KickWait[playerid] == 0)
			{
				if(KickState[playerid] == 3) KickState[playerid] = 0;
				if(KickState[playerid] == 0)
				{
					KickState[playerid] = 1;
					ApplyAnimation(playerid,"FIGHT_D","FightD_1",ANIM_PARAM);
					KickWait[playerid] = 1;
					SetTimerEx("KickWaitNull", WAIT_ANIM_END, 0, "i", playerid);
					HurtClosestPlayer(playerid);
					return 1;
				}
				if(KickState[playerid] == 1)
				{
					KickState[playerid] = 2;
					ApplyAnimation(playerid,"FIGHT_D","FightD_2",ANIM_PARAM);
					KickWait[playerid] = 1;
					SetTimerEx("KickWaitNull", WAIT_ANIM_END, 0, "i", playerid);
					HurtClosestPlayer(playerid);
					return 1;
				}
				if(KickState[playerid] == 2)
				{
					KickState[playerid] = 3;
					ApplyAnimation(playerid,"FIGHT_D","FightD_3",ANIM_PARAM);
					KickWait[playerid] = 1;
					SetTimerEx("KickWaitNull", WAIT_ANIM_END, 0, "i", playerid);
					HurtClosestPlayer(playerid);
					return 1;
				}
			}
			else
			{
				return 1;
			}		
		}
	}
	return 1;
}
			
stock IsValidWeapon(playerid)
{
	if(GetPlayerWeapon(playerid) == 0 || GetPlayerWeapon(playerid) == 1) return 1;
	return 0;
}

public KickWaitNull(playerid)
{
	ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0);
	KickWait[playerid] = 0;
}


stock GetPlayerFightingStyle(playerid)
{
	return FightStyle[playerid];
}

stock SetPlayerFightingStyle(playerid, style)
{
	FightStyle[playerid] = style;
}

stock SetFightingStyleForAll(style)
{
	for(new playerid = 0; playerid < GetMaxPlayers(); playerid++)
	{
		FightStyle[playerid] = style;
	}
}

stock HurtClosestPlayer(playerid)
{
	for(new i = 0; i < GetMaxPlayers(); i++)
	{
		if(IsPlayerConnected(i) && i != playerid)
		{
			if(GetDistanceBetweenPlayers(playerid, i) <= 1)
			{
				new Float:h;
				GetPlayerHealth(i, h);
				SetPlayerHealth(i, h-5);
				
				TurnPlayerFaceToPlayer(i, playerid)

				if(KickState[playerid] == 1)
				{
					if(GetPlayerFightingStyle(playerid) == FIGHT_BOXING) ApplyAnimation(i,"FIGHT_B","HitB_1",ANIM_PARAM);
					if(GetPlayerFightingStyle(playerid) == FIGHT_KARATE) ApplyAnimation(i,"FIGHT_C","HitC_1",ANIM_PARAM);
					if(GetPlayerFightingStyle(playerid) == FIGHT_GANGSTER) ApplyAnimation(i,"FIGHT_D","HitD_1",ANIM_PARAM);
					PlaySound(playerid, SOUND);
					PlaySound(i, SOUND);
					return 1;
				}
				if(KickState[playerid] == 2)
				{
					if(GetPlayerFightingStyle(playerid) == FIGHT_BOXING) ApplyAnimation(i,"FIGHT_B","HitB_2",ANIM_PARAM);
					if(GetPlayerFightingStyle(playerid) == FIGHT_KARATE) ApplyAnimation(i,"FIGHT_C","HitC_2",ANIM_PARAM);
					if(GetPlayerFightingStyle(playerid) == FIGHT_GANGSTER) ApplyAnimation(i,"FIGHT_D","HitD_2",ANIM_PARAM);
					PlaySound(playerid, SOUND);
					PlaySound(i, SOUND);
					return 1;
				}
				if(KickState[playerid] == 3)
				{
					if(GetPlayerFightingStyle(playerid) == FIGHT_BOXING) ApplyAnimation(i,"FIGHT_B","HitB_3",ANIM_PARAM);
					if(GetPlayerFightingStyle(playerid) == FIGHT_KARATE) ApplyAnimation(i,"FIGHT_C","HitC_3",ANIM_PARAM);
					if(GetPlayerFightingStyle(playerid) == FIGHT_GANGSTER) ApplyAnimation(i,"FIGHT_D","HitD_3",ANIM_PARAM);
					PlaySound(playerid, SOUND);
					PlaySound(i, SOUND);
					return 1;
				}
			}
		}
	}
	return 1;
}

stock TurnPlayerFaceToPlayer(playerid, facingtoid)
{
	new Float:angle;
	new Float:misc = 5.0;
	new Float:x, Float:y, Float:z;
	new Float:ix, Float:iy, Float:iz;
	GetPlayerPos(facingtoid, x, y, z);
	GetPlayerPos(playerid, ix, iy, iz);
	angle = 180.0-atan2(ix-x,iy-y);
	angle += misc;
	misc *= -1;
	SetPlayerFacingAngle(playerid, angle+misc);
}

stock PlaySound(playerid, soundid)
{
	PlayerPlaySound(playerid, soundid, 0, 0, 0);
}

stock GetDistanceBetweenPlayers(playerid, playerid2)
{
    new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2;
    new Float:tmpdis;
    GetPlayerPos(playerid, x1, y1, z1);
    GetPlayerPos(playerid2, x2, y2, z2);
    tmpdis = floatsqroot(floatpower(floatabs(floatsub(x2, x1)), 2) + floatpower(floatabs(floatsub(y2, y1)), 2) + floatpower(floatabs(floatsub(z2, z1)), 2));
    return floatround(tmpdis);
}