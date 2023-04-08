/*<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
^		    Title: LuxurY Checkpoint Streamer (LCS)                            ^
^		    Version: 1.1.1                                                     ^
^		    Reliase: final                                                     ^
^		    Date: 6 August 2008                                                ^
^		    Developer: [LDT]LuxurY                                             ^
<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>*/

#include <a_samp>

#define MAX_DYNCHECK 1024
#define MAX_CHDIS 50.0 //uses to disable checkpoint if distanse is above 50

forward LCS_OnPlayerEnterCheckpoint( playerid , checkpointid );
forward LCS_OnPlayerLeaveCheckpoint( playerid , checkpointid );
forward LCS_ChCh( );

new
	Float:dyncheckcoords[MAX_DYNCHECK][4],
	LCScount,
	playertmpch[MAX_PLAYERS],
	tmpi[MAX_PLAYERS],
	lockch[MAX_PLAYERS][2];

stock LCS_Load( )
{
	SetTimer( "LCS_ChCh" , 1000 , 1 );
	for ( new i = 0; i < MAX_PLAYERS; i++ )
	{
		playertmpch[i] = -1;
		lockch[i][1] = -1;
	}
	return 1;
}

stock LCS_SetPlayerStaticCheck( playerid , checkpointid )
{
	if ( LCS_IsValidCheckpoint( checkpointid ) == 1 )
	{
		new
			Float:tx,
			Float:ty,
			Float:tz,
			Float:ts;
			
		LCS_GetCheckpointData( checkpointid , tx , ty , tz , ts );
		SetPlayerCheckpoint( i , tx , ty , tz , ts );
		lockch[playerid][0] = 1;
		lockch[playerid][1] = checkpointid;
	}
	return 1;
}

stock LCS_IsPlayerInCheckpoint( playerid , checkpointid )
{
	new
		result,
		ChiD = LCS_GetClosestCheckpoint( playerid );
		
	if ( ChiD == checkpointid && IsPlayerInCheckpoint( playerid ) == 1 )
	{
		result = 1;
	}
	if ( lockch[playerid][0] == 1 && lockch[playerid][1] == checkpointid && IsPlayerInCheckpoint( playerid ) == 1 )
	{
		result = 1;
	}
	return result;
}

stock LCS_SetCheckpointData( checkpointid , Float:x , Float:y , Float:z , Float:size )
{
	if ( LCS_IsValidCheckpoint( checkpointid ) == 1 )
	{
		dyncheckcoords[checkpointid][0] = x;
		dyncheckcoords[checkpointid][1] = y;
		dyncheckcoords[checkpointid][2] = z;
		dyncheckcoords[checkpointid][3] = size;
		for ( new i = 0, i < MAX_PLAYERS; i++ )
		{
			if ( checkpointid == playertmpch[i] )
			{
				DisablePlayerCheckpoint( i );
				new
					Float:tx,
					Float:ty,
					Float:tz,
					Float:ts;
				LCS_GetCheckpointData( checkpointid , tx , ty , tz , ts );
				SetPlayerCheckpoint( i , tx , ty , tz , ts );
			}
		}
	}
	return 1;
}

stock LCS_GetPlayerCheckpointIn( playerid )
{
	new
		result = -1,
		ChiD = LCS_GetClosestCheckpoint( playerid );
		
	if ( IsPlayerInCheckpoint( playerid ) == 1 )
	{
		if ( lockch[playerid][0] == 1 )
		{
			result = lockch[playerid][1];
		}
		else
		{
			result = ChiD;
		}
	}
	return result;
}

stock LCS_IsPlayerInAnyCheckpoint( playerid )
{
	new
		result;
	if ( IsPlayerInCheckpoint( playerid ) == 1 && LCS_GetClosestCheckpoint( playerid ) != -1 )
	{
		result = 1;
	}
	return result;
}

stock LCS_IsAnyPlayerInCheckpoint( checkpointid )
{
	new
		result;
	for ( new i = 0; i < MAX_PLAYERS; i++ )
	{
		if ( LCS_IsPlayerInCheckpoint( i , checkpointid ) == 1 )
		{
			result = 1;
		}
	}
	return result;
}

stock LCS_RemovePlayerStaticCheck( playerid )
{
	if ( lockch[playerid][0] == 1 )
	{
		DisablePlayerCheckpoint( playerid );
		lockch[playerid][0] = 0;
		lockch[playerid][1] = -1;
	}
	return 1;
}

stock LCS_GetPlayerStaticCheck( playerid )
{
	return lockch[playerid][1];
}

stock LCS_CreateCheckpoint( Float:x , Float:y , Float:z , Float:size )
{
	dyncheckcoords[LCScount][0] = x;
	dyncheckcoords[LCScount][1] = y;
	dyncheckcoords[LCScount][2] = z;
	dyncheckcoords[LCScount][3] = size;
	LCScount++;
	LCScount %= MAX_DYNCHECK;
	return LCScount-1;
}

stock LCS_IsValidCheckpoint( checkpointid )
{
	new
		result;
	if ( dyncheckcoords[checkpointid][0] == 0 && dyncheckcoords[checkpointid][1] == 0 && dyncheckcoords[checkpointid][2] == 0 && dyncheckcoords[checkpointid][3] == 0 )
	{
		result = 0;
	}
	else
	{
		result = 1;
	}
	return result;
}

stock LCS_DestroyCheckpoint( checkpointid )
{
	if ( LCS_IsValidCheckpoint( checkpointid ) == 1 )
	{
		dyncheckcoords[LCScount][0] = 0;
		dyncheckcoords[LCScount][1] = 0;
		dyncheckcoords[LCScount][2] = 0;
		dyncheckcoords[LCScount][3] = 0;
	}
	return checkpointid;
}

stock LCS_GetCheckpointData( checkpointid , &Float:x , &Float:y , &Float:z , &Float:size )
{
	x = dyncheckcoords[checkpointid][0];
	y = dyncheckcoords[checkpointid][1];
	z = dyncheckcoords[checkpointid][2];
	size = dyncheckcoords[checkpointid][3];
}

stock LCS_GetDistanceBetweenPAC( playerid , checkpointid )
{
	new
		Float:dis,
		Float:x1,
		Float:y1,
		Float:z1,
		Float:x2,
		Float:y2,
		Float:z2,
		Float:size;
	GetPlayerPos( playerid , x1 , y1 , z1 );
	LCS_GetCheckpointData( checkpointid , x2 , y2 , z2 , size );
	dis = floatsqroot( floatpower( floatabs( floatsub( x2 , x1 ) ) , 2 ) + floatpower( floatabs( floatsub( y2 , y1 ) ) , 2 ) + floatpower( floatabs( floatsub( z2 , z1 ) ) , 2 ) );
	return floatround( dis );
}

stock LCS_GetClosestCheckpoint( playerid )
{
	new
		check = -1,
		Float:distmp = 99999.0,
		Float:distmp2;
	for( new i = 0; i < LCScount; i++ )
	{
		distmp2 = LCS_GetDistanceBetweenPAC( playerid , i );
		if( distmp2 < distmp )
		{
			distmp = distmp2;
			check = i;
		}
	}
	return check;
}

public LCS_ChCh( )
{
	for( new i = 0; i < MAX_PLAYERS; i++ )
	{
		if ( IsPlayerConnected( i ) == 1 )
		{
			if ( lockch[i][0] == 0 )
			{
				tmpi[i] = LCS_GetClosestCheckpoint( i );
				if ( tmpi[i] != playertmpch[i] && tmpi[i] != -1 && LCS_IsValidCheckpoint( tmpi[i] ) == 1 )
				{
					playertmpch[i] = tmpi[i];
					DisablePlayerCheckpoint( i );
					new
						Float:tx,
						Float:ty,
						Float:tz,
						Float:ts;
					LCS_GetCheckpointData( tmpi[i] , tx , ty , tz , ts );
					SetPlayerCheckpoint( i , tx , ty , tz , ts );
				}
				new
					distmp = LCS_GetDistanceBetweenPAC( i , tmpi[i] );
				if ( distmp > MAX_CHDIS )
				{
					DisablePlayerCheckpoint( i );
					playertmpch[i] = -1;
				}
			}
		}
	}
	return 1;
}

public OnPlayerEnterCheckpoint( playerid )
{
	new
		ChiD = LCS_GetClosestCheckpoint( playerid );
	LCS_OnPlayerEnterCheckpoint( playerid , ChiD );
	return 1;
}

public OnPlayerLeaveCheckpoint(playerid)
{
	new
		ChiD = LCS_GetClosestCheckpoint( playerid );
	LCS_OnPlayerLeaveCheckpoint( playerid , ChiD );
	return 1;
}
