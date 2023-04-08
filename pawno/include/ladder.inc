#include <a_samp>

#define SHORT_LADDER 1428
#define LONG_LADDER 1437

#define LADDER_ROTATION 15.4699, 0.8594

#define MAX_LADDERS 20 //recommended 20, highest=MAX_OBJECTS


enum lInfo
{
	Float:lX,
	Float:lY,
	Float:lZ,
	Float:lEX,
	Float:lEY,
	Float:lEZ
}

new LadderInfo[MAX_LADDERS][lInfo];

new AmountOfLadders = 0;
new Climbing[MAX_PLAYERS];
new IsAtLadder[MAX_PLAYERS] = -1;

forward LadderTimer();

stock FireLadderSystem()
{
	SetTimer("LadderTimer", 1000, 0);
}

stock LadderOnConnect(playerid)
{
	Climbing[playerid] = 0;
	IsAtLadder[playerid] = -1;
}

stock SetSmallLadder(Float:x, Float:y, Float:z, Float:endx, Float:endy, Float:endz, Float:rot)
{
	AmountOfLadders++;
	LadderInfo[AmountOfLadders][lX] = x;
	LadderInfo[AmountOfLadders][lY] = y;
	LadderInfo[AmountOfLadders][lZ] = z;
	LadderInfo[AmountOfLadders][lEX] = endx;
	LadderInfo[AmountOfLadders][lEY] = endy;
	LadderInfo[AmountOfLadders][lEZ] = endz;
	for(new i = 0; i < GetMaxPlayers(); i++)
	{
		CreatePlayerObject(i, SHORT_LADDER, x, y, z, LADDER_ROTATION, rot);
	}
	printf("ladder %d created: startx=%.2f starty=%.2f startz=%.2f", AmountOfLadders, LadderInfo[AmountOfLadders][lX], LadderInfo[AmountOfLadders][lY], LadderInfo[AmountOfLadders][lZ]);
	return 1;
}
stock SetLongLadder(Float:x, Float:y, Float:z, Float:endx, Float:endy, Float:endz, Float:rot)
{
	AmountOfLadders++;
	LadderInfo[AmountOfLadders][lX] = x;
	LadderInfo[AmountOfLadders][lY] = y;
	LadderInfo[AmountOfLadders][lZ] = z;
	LadderInfo[AmountOfLadders][lEX] = endx;
	LadderInfo[AmountOfLadders][lEY] = endy;
	LadderInfo[AmountOfLadders][lEZ] = endz;
	for(new i = 0; i < GetMaxPlayers(); i++)
	{
		CreatePlayerObject(i, LONG_LADDER, x, y, z, LADDER_ROTATION, rot);
	}
	return 1;
}

public LadderTimer()
{
	for(new i = 0; i < GetMaxPlayers(); i++)
	{
//		if(IsPlayerConnected(i))
//		{
			for(new l = 0; l < AmountOfLadders; l++)
			{
				new str[50];
				format(str, sizeof str, "AmountOfLadders: %d", AmountOfLadders);
				SendClientMessageToAll(0xFFFFFFAA, str);
				format(str, sizeof str, "Ladder %d: X:%.2f Y:%.2f Z:%.2f", AmountOfLadders, LadderInfo[l][lX], LadderInfo[l][lY], LadderInfo[l][lZ]);
				SendClientMessageToAll(0xFFFFFFAA, str);
				print(str);
				if(PlayerToPointLadder(2.5, i, LadderInfo[l][lX], LadderInfo[l][lY], LadderInfo[l][lZ]))
				{
					SendClientMessageToAll(0xFFFFFFAA, "@ladder");
					if(IsAtLadder[i] == -1)
					{
						IsAtLadder[i] = l;
						SendClientMessage(i, 0xFFFFFFAA, "Press Jump key to climb the ladder.");
					}
				}
				else
				{
					IsAtLadder[i] = -1;
				}
			}
			if(Climbing[i] == 1)
			{
				for(new l = 0; l < AmountOfLadders; l++)
				{
					new Float:x, Float:y, Float:z;
					GetLadderEndPos(l, x, y, z);
					if(PlayerToPointLadder(1, i, x, y, z))
					{
						SetPlayerPos(i, x, y, z);
						Climbing[i] = 0;
					}
				}
			}
//		}
	}
	SetTimer("LadderTimer", 1000, 0);
}

stock Ladder_Key(playerid, newkeys)
{
	if(newkeys & KEY_JUMP)
	{
		if(IsAtLadder[playerid] >= 0)
		{
			TurnPlayerFaceToLadder(playerid, IsAtLadder[playerid]);
			Climbing[playerid] = 1;
			ApplyAnimation(playerid,"DOZER","DOZER_Align_LHS", 4.1, 1, 1, 1, 0, 3000);
		}
	}
}

stock TurnPlayerFaceToLadder(playerid, ladderid)
{
	new Float:angle;
	new Float:misc = 5.0;
	new Float:x, Float:y, Float:z;
	new Float:ix, Float:iy, Float:iz;
	GetLadderStartPos(ladderid, x, y, z);
	GetPlayerPos(playerid, ix, iy, iz);
	angle = 180.0-atan2(ix-x,iy-y);
	angle += misc;
	misc *= -1;
	SetPlayerFacingAngle(playerid, angle+misc-90.0);
}

stock GetLadderStartPos(ladderid, &Float:x, &Float:y, &Float:z)
{
	x = LadderInfo[ladderid][lX];
	y = LadderInfo[ladderid][lY];
	z = LadderInfo[ladderid][lZ];
	return 1;
}

stock GetLadderEndPos(ladderid, &Float:x, &Float:y, &Float:z)
{
	x = LadderInfo[ladderid][lEX];
	y = LadderInfo[ladderid][lEY];
	z = LadderInfo[ladderid][lEZ];
	return 1;
}

PlayerToPointLadder(Float:radi, playerid, Float:x, Float:y, Float:z)
{
	new Float:oldposx, Float:oldposy, Float:oldposz;
	new Float:tempposx, Float:tempposy, Float:tempposz;
	GetPlayerPos(playerid, oldposx, oldposy, oldposz);
	new str[50];
	format(str, sizeof str, "Plr: X:%.2f, Y:%.2f, Z:%.2f", oldposx, oldposy, oldposz);
	SendClientMessageToAll(0xFFFFFFAA, str);
//	print(str);
	tempposx = (oldposx -x);
	tempposy = (oldposy -y);
	tempposz = (oldposz -z);
	if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
	{
		return 1;
	}
	return 0;
}