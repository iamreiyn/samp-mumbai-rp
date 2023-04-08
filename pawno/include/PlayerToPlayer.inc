#include <a_samp>
#include <a_players>


stock SetPlayerFacePlayer(playerid, faceplayerid)
{
    new Float:Px, Float:Py, Float: Pa;
    GetPlayerPos(playerid, Px, Py, Pa);
    new Float:fpX, Float:fpY, Float: fpZ;
    GetPlayerPos(faceplayerid, fpX, fpY, fpZ);
    Pa = floatabs(atan((fpY-Py)/(fpX-Px)));
    if(fpX <= Px && fpY >= Py) Pa = floatsub(180, Pa);
    else if(fpX < Px && fpY < Py) Pa = floatadd(Pa, 180);
    else if(fpX >= Px && fpY <= Py) Pa = floatsub(360.0, Pa);
    Pa = floatsub(Pa, 90.0);
    if(Pa >= 360.0) Pa = floatsub(Pa, 360.0);
    if(!IsPlayerInAnyVehicle(playerid)) SetPlayerFacingAngle(playerid, Pa);
    else SetVehicleZAngle(GetPlayerVehicleID(playerid), Pa);
}

new Float:_IPLAP[13];
stock IsPlayerLookingAtPlayer(playerid,playerid2)
{
	GetPlayerPos(playerid,_IPLAP[0],_IPLAP[1],_IPLAP[2]);

	GetPlayerCameraUpVector(playerid,_IPLAP[3],_IPLAP[4],_IPLAP[5]);
	_IPLAP[0]+=_IPLAP[3];
	_IPLAP[1]+=_IPLAP[4];
	_IPLAP[2]+=_IPLAP[5];

	GetPlayerCameraFrontVector(playerid,_IPLAP[6],_IPLAP[7],_IPLAP[8]);

	GetPlayerPos(playerid2,_IPLAP[9],_IPLAP[10],_IPLAP[11]);

	_IPLAP[12]=floatsqroot( ((_IPLAP[9]-_IPLAP[0])*(_IPLAP[9]-_IPLAP[0])) + ((_IPLAP[10]-_IPLAP[1])*(_IPLAP[10]-_IPLAP[1])) + ((_IPLAP[11]-_IPLAP[2])*(_IPLAP[11]-_IPLAP[2])) );

	_IPLAP[0]=_IPLAP[6]*_IPLAP[12]+_IPLAP[0];
	_IPLAP[1]=_IPLAP[7]*_IPLAP[12]+_IPLAP[1];
	_IPLAP[2]=_IPLAP[8]*_IPLAP[12]+_IPLAP[2];

	if( (_IPLAP[0]>(_IPLAP[9]-0.25)) && (_IPLAP[0]<(_IPLAP[9]+0.25)) && (_IPLAP[1]>(_IPLAP[10]-0.25)) && (_IPLAP[1]<(_IPLAP[10]+0.25)) && (_IPLAP[2]>(_IPLAP[11])) && (_IPLAP[2]<(_IPLAP[11]+2.0)) ) return 1;
	return 0;
}
stock IsPlayerLookingAtPoint(playerid,Float:X,Float:Y,Float:Z)
{
	GetPlayerPos(playerid,_IPLAP[0],_IPLAP[1],_IPLAP[2]);

	GetPlayerCameraUpVector(playerid,_IPLAP[3],_IPLAP[4],_IPLAP[5]);
	_IPLAP[0]+=_IPLAP[3];
	_IPLAP[1]+=_IPLAP[4];
	_IPLAP[2]+=_IPLAP[5];

	GetPlayerCameraFrontVector(playerid,_IPLAP[6],_IPLAP[7],_IPLAP[8]);

	GetPlayerPos(playerid2,_IPLAP[9],_IPLAP[10],_IPLAP[11]);

	_IPLAP[12]=floatsqroot( ((X-_IPLAP[0])*(X-_IPLAP[0])) + ((Y-_IPLAP[1])*(Y-_IPLAP[1])) + ((Z-_IPLAP[2])*(Z-_IPLAP[2])) );

	_IPLAP[0]=_IPLAP[6]*_IPLAP[12]+_IPLAP[0];
	_IPLAP[1]=_IPLAP[7]*_IPLAP[12]+_IPLAP[1];
	_IPLAP[2]=_IPLAP[8]*_IPLAP[12]+_IPLAP[2];

	if( (_IPLAP[0]>(X-0.25)) && (_IPLAP[0]<(X+0.25)) && (_IPLAP[1]>(Y-0.25)) && (_IPLAP[1]<(Y+0.25)) && (_IPLAP[2]>(Z)) && (_IPLAP[2]<(Z+2.0)) ) return 1;
	return 0;
}