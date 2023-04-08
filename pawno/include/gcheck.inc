/*
				+--------------------------------------------+
				|	     Script creado por Gantzyo.          |
				|                                            |
				|	 Si necesitas ayuda contacta conmigo     |
				|         en www.pawnoscripting.com          |
				|                                            |
				|	   Todos los derechos reservados.        |
				+--------------------------------------------+
*/

#include <a_samp>
#if defined _G_Checkpoint_included
	#endinput
#endif
#define _G_Checkpoint_included
#pragma library G_Checkpoint
#define TOTAL_CP 50 //Cambia 50 por el maximo de Checkpoints permitidos
#define SIN_CREAR 0
#define CREADO 1
#define NO_AUTOMATICO 0
#define AUTOMATICO 1

new CP[MAX_PLAYERS],bool:SetCP[MAX_PLAYERS];
new Float:cpX[TOTAL_CP],Float:cpY[TOTAL_CP],Float:cpZ[TOTAL_CP],Float:Radio[TOTAL_CP],Float:Distancia[TOTAL_CP],Interior[TOTAL_CP],CPCreado[TOTAL_CP],VW[TOTAL_CP],Automatico[TOTAL_CP];
new CPColocados = 0;
new bool:GC_Init = false;
new GCP_Timer;

forward CPTimer();
forward OnPlayerEnterCP(playerid,CheckpointID);

stock CrearCheckpoint(Float:x,Float:y,Float:z,Float:radio,Float:distancia,VirtualWorld,InteriorID,Auto)
{
	if(!GC_Init) return 0;
	if(CPColocados > TOTAL_CP) return 0;
	new CheckpointID = 0;
	while(CPCreado[CheckpointID] == CREADO)
	{
		CheckpointID ++;
	}
	cpX[CheckpointID] = x;
	cpY[CheckpointID] = y;
	cpZ[CheckpointID] = z;
	Radio[CheckpointID] = radio;
	Distancia[CheckpointID] = distancia;
	VW[CheckpointID] = VirtualWorld;
	Interior[CheckpointID] = InteriorID;
	Automatico[CheckpointID] = Auto;
	CPCreado[CheckpointID] = CREADO;
	return CheckpointID;
}
stock BorrarCheckpoint(CheckpointID)
{
	if(!GC_Init) return 0;
	if(CPCreado[CheckpointID] == SIN_CREAR) return 0;
	CPCreado[CheckpointID] = SIN_CREAR;
	for(new i=0;i<MAX_PLAYERS;i++)
	{
		if(CP[i] == CheckpointID) CP[i] = -1;
	}
	return 1;
}
stock PonerCheckpoint(playerid,CheckpointID)
{
	if(!GC_Init) return 0;
	if(CPCreado[CheckpointID] == SIN_CREAR) return 0;
	if(Automatico[CheckpointID] == AUTOMATICO) return 0;
	if(Interior[CheckpointID] == -1 || GetPlayerInterior(playerid) == Interior[CheckpointID])
	{
		if(GetPlayerVirtualWorld(playerid) == VW[CheckpointID] || VW[CheckpointID] == -1)
		{
			SetPlayerCheckpoint(playerid,cpX[CheckpointID],cpY[CheckpointID],cpZ[CheckpointID],Radio[CheckpointID]);
			CP[playerid] = CheckpointID;
			return 1;
		}
	}
	return 0;
}
stock GCP_PonerCheckpoint(playerid,CheckpointID)
{
	if(!GC_Init) return 0;
	if(CPCreado[CheckpointID] == SIN_CREAR) return 0;
	if(Automatico[CheckpointID] == NO_AUTOMATICO) return 0;
	if(Interior[CheckpointID] == -1 || GetPlayerInterior(playerid) == Interior[CheckpointID])
	{
		if(GetPlayerVirtualWorld(playerid) == VW[CheckpointID] || VW[CheckpointID] == -1)
		{
			SetPlayerCheckpoint(playerid,cpX[CheckpointID],cpY[CheckpointID],cpZ[CheckpointID],Radio[CheckpointID]);
			CP[playerid] = CheckpointID;
			return 1;
		}
	}
	return 0;
}
stock JugadorEnCheckpoint(playerid,CheckpointID)
{
	if(!GC_Init) return 0;
	if(CPCreado[CheckpointID] == SIN_CREAR) return 0;
	if(CP[playerid] == CheckpointID && CP[playerid] > -1 && IsPlayerInCheckpoint(playerid)) return 1;
	return 0;
}
stock Float: GetDistanceToPoint(playerid,Float: X2,Float:Y2 ,Float: Z2)
{
	new Float:x1,Float:y1,Float:z1;
	GetPlayerPos(playerid,x1,y1,z1);
	return floatsqroot(floatpower(floatabs(floatsub(X2,x1)),2)+floatpower(floatabs(floatsub(Y2,y1)),2)+floatpower(floatabs(floatsub(Z2,z1)),2));
}
stock OnGCPInit()
{
	for(new i=0;i<MAX_PLAYERS;i++)
	{
		CP[i] = -1;
		SetCP[i] = false;
	}
	for(new c=0;c<TOTAL_CP;c++)
	{
		CPCreado[c] = SIN_CREAR;
	}
	GC_Init = true;
	GCP_Timer = SetTimer("CPTimer",1000,1);
	return 1;
}
stock OnGCPExit()
{
	for(new i=0;i<MAX_PLAYERS;i++)
	{
		CP[i] = -1;
		SetCP[i] = false;
	}
	for(new c=0;c<TOTAL_CP;c++)
	{
		CPCreado[c] = SIN_CREAR;
	}
	GC_Init = false;
	KillTimer(GCP_Timer);
	return 1;
}
stock GetPlayerCheckpoint(playerid)
{
	if(!GC_Init) return -1;
	if(JugadorEnCheckpoint(playerid,CP[playerid])) return CP[playerid];
	return -1;
}
public CPTimer()
{
	if(!GC_Init) return 0;
	new Float:tmp_Distancia[MAX_PLAYERS], Float:tmp_Distancia2[MAX_PLAYERS], tmp_Encontrado[MAX_PLAYERS];
	for(new playerid=0;playerid<MAX_PLAYERS;playerid++)
	{
		tmp_Distancia[playerid] = 10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.000;
		for(new c=0;c<TOTAL_CP;c++)
		{
			if(CP[playerid] == c && CPCreado[c] == SIN_CREAR)
			{
				DisablePlayerCheckpoint(playerid);
				CP[playerid] = -1;
			}
			if(CPCreado[c] == CREADO)
			{
				if(Automatico[c] == AUTOMATICO)
				{
					if(IsPlayerInRangeOfPoint(playerid,Distancia[c],cpX[c],cpY[c],cpZ[c]) && !JugadorEnCheckpoint(playerid,c) && !IsPlayerInCheckpoint(playerid))
					{
						tmp_Encontrado[playerid] = 1;
						tmp_Distancia2[playerid] = GetDistanceToPoint(playerid,cpX[c],cpY[c],cpZ[c]);
						if(tmp_Distancia2[playerid] < tmp_Distancia[playerid])
						{
							if(Interior[c] == -1 || GetPlayerInterior(playerid) == Interior[c])
							{
								if(GetPlayerVirtualWorld(playerid) == VW[c] || VW[c] == -1)
								{
									if(CP[playerid] != c)
									{
										CP[playerid] = c;
										tmp_Distancia[playerid] = GetDistanceToPoint(playerid,cpX[c],cpY[c],cpZ[c]);
									}
								}
							}
						}
					}
				}
			}
		}
		if(tmp_Encontrado[playerid] == 0) CP[playerid] = -1;
		if(tmp_Encontrado[playerid] == 1 && !IsPlayerInCheckpoint(playerid) && !SetCP[playerid]) GCP_PonerCheckpoint(playerid,CP[playerid]);
		if(tmp_Encontrado[playerid] == 0 && !IsPlayerInCheckpoint(playerid) && CP[playerid] == -1 && !SetCP[playerid]) DisablePlayerCheckpoint(playerid);
	}
	return 1;
}
stock SetPlayerRaceCP(playerid, type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, Float:size)
{
	if(!GC_Init) return 0;
	SetCP[playerid] = true;
	CP[playerid] = -1;
	return SetPlayerRaceCheckpoint(playerid, type, x, y, z, nextx, nexty, nextz, size);
}
stock DisablePlayerRaceCP(playerid)
{
	if(!GC_Init) return 0;
	SetCP[playerid] = false;
	return DisablePlayerRaceCheckpoint(playerid);
}
stock SetPlayerCP(playerid, Float:x, Float:y, Float:z, Float:size)
{
	if(!GC_Init) return 0;
	SetCP[playerid] = true;
	CP[playerid] = -1;
	return SetPlayerCheckpoint(playerid, x, y, z, size);
}
stock DisablePlayerCP(playerid)
{
	if(!GC_Init) return 0;
	SetCP[playerid] = false;
	return DisablePlayerCheckpoint(playerid);
}
/*
native OnGCPInit();
native OnGCPExit();
native CrearCheckpoint(Float:x,Float:y,Float:z,Float:radio,Float:distancia,InteriorID);
native BorrarCheckpoint(CheckpointID);
native PonerCheckpoint(playerid,CheckpointID);
native JugadorEnCheckpoint(playerid,CheckpointID);
native GetPlayerCheckpoint(playerid);
native SetPlayerCP(playerid, Float:x, Float:y, Float:z, Float:size);
native DisablePlayerCP(playerid);
native SetPlayerRaceCP(playerid, type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, Float:size);
native DisablePlayerRaceCP(playerid);
*/