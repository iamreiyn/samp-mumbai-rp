/*
	gCamera - Speedcamera in SA-MP WITH FLASH EFFECT!
	V1.1 - Released on 10-04-2011 (Updated at 12-04-2011)
	Filterscript version with ingame speedcam generator!
	©Gamer931215
	I want to thank my friend HighFlyer in this release for some tips and testing it (like textlabels, using a streamer, etc) !

	Use at own risk, do NOT re-release,mirror,sell it or even worse: clame this as your own!
*/
#include <a_samp>
#include <zcmd>
#include <YSI/y_ini>
//===================================================================================================
//                                         	   Settings
//===================================================================================================
//                   SETTING:                           VALUE:              	Discription:

#define				 CAMERA_LIMIT				 		100                     //Max loaded cameras (keep this as low as possible for the best performance)
#define				 CAMERA_UPDATE_INTERVAL		 		750                     //update interval of all speedcams (in miliseconds)
#define				 CAMERA_FLASH_TIME			 		1200                    //ammount of miliseconds until the "flash" effect gets removed again
#define				 CAMERA_DIALOG_RANGE          		1337                    //dialog ID range (Example: 0 will take dialogid's 0 - 9)
#define              CAMERA_USEMPH                      0                       //toggles camera using mph by default (0=kmh, 1=mph)
#define              CAMERA_LABEL_COLOR                 0xFF000FFF              //The default color of the camera's label
#define              CAMERA_PERSPECTIVE                 false                    //Sets playercamera temporary at the camera's position while flashing

//streamer options (will be used if STREAMER_ENABLED is set on true)
#define              STREAMER_ENABLED					false                   //uses a streamer (true/false)
#define              STREAMER_ADD                   	CreateDynamicObject     //put here at the value the command your streamer uses to make an object (CreateDynamicObject by default)
#define              STREAMER_REMOVE                    DestroyDynamicObject    //put here at the value the command your streamer uses to remove an object (STREAMER_REMOVE by default)
#if STREAMER_ENABLED == true                                                    //ignore this line
    #include             								streamer				//put your include name here
#endif                                                                          //ignore this line
//===================================================================================================
//                                         	  Variables
//===================================================================================================
#define DIALOG_MAIN CAMERA_DIALOG_RANGE
#define DIALOG_RANGE CAMERA_DIALOG_RANGE +1
#define DIALOG_LIMIT CAMERA_DIALOG_RANGE +2
#define DIALOG_FINE CAMERA_DIALOG_RANGE +3
#define DIALOG_EDIT CAMERA_DIALOG_RANGE +4
#define DIALOG_EANGLE CAMERA_DIALOG_RANGE +5
#define DIALOG_ELIMIT CAMERA_DIALOG_RANGE +6
#define DIALOG_ERANGE CAMERA_DIALOG_RANGE +7
#define DIALOG_EFINE CAMERA_DIALOG_RANGE +8
#define DIALOG_ETYPE CAMERA_DIALOG_RANGE +9
#define DIALOG_LABEL CAMERA_DIALOG_RANGE +10
#define COLOR_RED 0xFF1E00FF
#define COLOR_GREEN 0x05FF00FF
enum _camera
{Float:_x,Float:_y,Float:_z,Float:_rot,_range,_limit,_fine,_usemph,_objectid,bool:_active,bool:_activelabel,_labeltxt[128],Text3D:_label}
new SpeedCameras[CAMERA_LIMIT][_camera],loaded_cameras = 0,Text:flash;
//stocks for attaching labels to camera (must be defined before use, thats why this one is at the top)
stock Text3D:AttachLabelToCamera(cameraid,text[])
{
	new position,buffer[128];format(buffer,sizeof buffer,"%s",text);
	for(new i = 0;strfind(buffer,"\\n",true) != -1;i++)
	{
	    position = strfind(buffer,"\\n",true);
	    strdel(buffer,position,position +2);
	    strins(buffer,"\r\n",position,sizeof(buffer));
	}
	return Create3DTextLabel(buffer,CAMERA_LABEL_COLOR,SpeedCameras[cameraid][_x],SpeedCameras[cameraid][_y],SpeedCameras[cameraid][_z] +7,100,0,0);
}
stock UpdateCameraLabel(Text3D:labelid,text[])
{
	new position,buffer[128];format(buffer,sizeof buffer,"%s",text);
	for(new i = 0;strfind(buffer,"\\n",true) != -1;i++)
	{
	    position = strfind(buffer,"\\n",true);
	    strdel(buffer,position,position +2);
	    strins(buffer,"\r\n",position,sizeof(buffer));
	}
	return	Update3DTextLabelText(labelid,CAMERA_LABEL_COLOR,buffer);
}
//===================================================================================================
//                                            Initialize
//===================================================================================================
public OnFilterScriptInit()
{
	SetTimer("UpdateCameras",CAMERA_UPDATE_INTERVAL,true);
	flash = TextDrawCreate(-20.000000,2.000000,"|");
	TextDrawUseBox(flash,1);
	TextDrawBoxColor(flash,0xffffff66);
	TextDrawTextSize(flash,660.000000,22.000000);
	TextDrawAlignment(flash,0);
	TextDrawBackgroundColor(flash,0x000000ff);
	TextDrawFont(flash,3);
	TextDrawLetterSize(flash,1.000000,52.200000);
	TextDrawColor(flash,0xffffffff);
	TextDrawSetOutline(flash,1);
	TextDrawSetProportional(flash,1);
	TextDrawSetShadow(flash,1);
	print("====================================");
	print("|            gCamera V1.0          |");
	print("|            ©Gamer931215          |");
	print("====================================");
	print("Initializing...");
	LoadCameras();
	return 1;
}
public OnFilterScriptExit()
{
	print("====================================");
	print("|            gCamera V1.0          |");
	print("|            ©Gamer931215          |");
	print("====================================");
	RemoveCameras();
	print("All cameras have been removed.");
	return 1;
}
//===================================================================================================
//                                             Commands
//===================================================================================================
COMMAND:gcam(playerid,params[])
{
	if(!IsPlayerAdmin(playerid)) return 0;
	ShowPlayerDialog(playerid,DIALOG_MAIN,DIALOG_STYLE_LIST,"{00A5FF}gCamera {FFFFFF}- {FFDC00}Main menu","{37FF00}Create speedcamera\n\nGet closest speedcamera ID\nEdit closest speedcamera\n{FF1400}Delete closest speedcamera\n{FF1400}Delete all speedcameras","OK","Cancel");
	return 1;
}

//===================================================================================================
//                      					  Callbacks
//===================================================================================================
public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(!response) {
		DeletePVar(playerid,"range");
		DeletePVar(playerid,"limit");
		DeletePVar(playerid,"fine");
		DeletePVar(playerid,"selected");
		return 1;
	}
	switch(dialogid)
	{
		//======================================================
		//                  	Main menu
		//======================================================
	    case DIALOG_MAIN:
	    {
	        switch(listitem)
	        {
				case 0: ShowPlayerDialog(playerid,DIALOG_RANGE,DIALOG_STYLE_INPUT,"Insert a range","Please insert a range (recommended: 20-30)","OK","Cancel");
				case 1:
				{
					new cam = GetClosestCamera(playerid);
					if(cam == -1) return SendClientMessage(playerid,COLOR_RED,"No nearby cameras found!");
					SendClientMessageEx(playerid,COLOR_GREEN,"sis","The closest cameraID is ID: ",cam,".");
				}
				case 2:
				{
					new cam = GetClosestCamera(playerid);
					if(cam == -1) return SendClientMessage(playerid,COLOR_RED,"No nearby cameras found!");
					SetPVarInt(playerid,"selected",cam);
					ShowPlayerDialog(playerid,DIALOG_EDIT,DIALOG_STYLE_LIST,"{00A5FF}gCamera {FFFFFF}- {FFDC00}Editor","Change angle\nChange range\nChange speedlimit\nChange fine\nToggle mph mode\nAdd/Remove/Edit textlabel\n{FF1400}Delete camera","OK","Cancel");
				}
				case 3:
				{
					new cam = GetClosestCamera(playerid);
					if(cam == -1) return SendClientMessage(playerid,COLOR_RED,"No nearby cameras found!");
					DestroySpeedCam(cam);
				 	SendClientMessage(playerid,COLOR_GREEN,"Camera has been removed.");
				 	DeletePVar(playerid,"selected");
				}
				case 4:
				{
					for(new i = 0;i<loaded_cameras +1;i++)
					{
					    if(SpeedCameras[i][_active] == true)
					    {
					        DestroySpeedCam(i);
					    }
					}
					SendClientMessage(playerid,COLOR_GREEN,"All speedcameras have been removed.");
				}
	        }
	    }
		//======================================================
		//                  Making a speedcam
		//======================================================
	    case DIALOG_RANGE:
	    {
	        if(!strlen(inputtext)) return ShowPlayerDialog(playerid,DIALOG_RANGE,DIALOG_STYLE_INPUT,"Insert a range","Please insert a range (recommended: 20-30)","OK","Cancel");
	        SetPVarInt(playerid,"range",strval(inputtext));
	        ShowPlayerDialog(playerid,DIALOG_LIMIT,DIALOG_STYLE_INPUT,"Insert a speedlimit","Please insert a speedlimit","OK","Cancel");
	    }
	    case DIALOG_LIMIT:
	    {
	        if(!strlen(inputtext)) return ShowPlayerDialog(playerid,DIALOG_LIMIT,DIALOG_STYLE_INPUT,"Insert a speedlimit","Please insert a speedlimit","OK","Cancel");
	        SetPVarInt(playerid,"limit",strval(inputtext));
	        ShowPlayerDialog(playerid,DIALOG_FINE,DIALOG_STYLE_INPUT,"Insert a fine","Please insert a fine","OK","Cancel");
	    }
	    case DIALOG_FINE:
	    {
	        if(!strlen(inputtext)) return ShowPlayerDialog(playerid,DIALOG_FINE,DIALOG_STYLE_INPUT,"Insert a fine","Please insert a fine","OK","Cancel");
	        SetPVarInt(playerid,"fine",strval(inputtext));
			new Float:x,Float:y,Float:z,Float:angle;
			GetPlayerPos(playerid,x,y,z);GetPlayerFacingAngle(playerid,angle);
			angle = angle + 180;if(angle > 360){angle = angle - 360;}
			new id = CreateSpeedCam(x,y,z -3,angle,GetPVarInt(playerid,"range"),GetPVarInt(playerid,"limit"),GetPVarInt(playerid,"fine"),CAMERA_USEMPH);
			SetPlayerPos(playerid,x,y+2,z);
			DeletePVar(playerid,"range");
			DeletePVar(playerid,"limit");
			DeletePVar(playerid,"fine");
			SetPVarInt(playerid,"selected",id);
			ShowPlayerDialog(playerid,DIALOG_EDIT,DIALOG_STYLE_LIST,"{00A5FF}gCamera {FFFFFF}- {FFDC00}Editor","Change angle\nChange range\nChange speedlimit\nChange fine\nToggle mph mode\nAdd/Remove/Edit textlabel\n{FF1400}Delete camera","OK","Cancel");
	    }

		//======================================================
		//                  	Edit menu
		//======================================================
		case DIALOG_EDIT:
		{
		    switch(listitem)
		    {
		        case 0: ShowPlayerDialog(playerid,DIALOG_EANGLE,DIALOG_STYLE_INPUT,"{00A5FF}gCamera {FFFFFF}- {FFDC00}Editor - Angle","Please enter a new angle","OK","Cancel");
		        case 1: ShowPlayerDialog(playerid,DIALOG_ERANGE,DIALOG_STYLE_INPUT,"{00A5FF}gCamera {FFFFFF}- {FFDC00}Editor - Range","Please enter a new range","OK","Cancel");
		        case 2: ShowPlayerDialog(playerid,DIALOG_ELIMIT,DIALOG_STYLE_INPUT,"{00A5FF}gCamera {FFFFFF}- {FFDC00}Editor - Speedlimit","Please enter a new speedlimit","OK","Cancel");
		        case 3: ShowPlayerDialog(playerid,DIALOG_EFINE,DIALOG_STYLE_INPUT,"{00A5FF}gCamera {FFFFFF}- {FFDC00}Editor - Fine","Please enter a new fine","OK","Cancel");
		        case 4: ShowPlayerDialog(playerid,DIALOG_ETYPE,DIALOG_STYLE_INPUT,"{00A5FF}gCamera {FFFFFF}- {FFDC00}Editor - Mph/Kmh","enter 1 to use mph and 0 for kmh","OK","Cancel");
		        case 5: ShowPlayerDialog(playerid,DIALOG_LABEL,DIALOG_STYLE_INPUT,"{00A5FF}gCamera {FFFFFF}- {FFDC00}Editor - Textlabel","Please fill in the text you want to attach, or leave it empty to remove an existing label!","OK","Cancel");
				case 6:
				{
					DestroySpeedCam(GetPVarInt(playerid,"selected"));
				 	SendClientMessage(playerid,COLOR_GREEN,"Camera has been removed.");
				 	DeletePVar(playerid,"selected");
				}
		    }
		}

		//======================================================
		//                 Editing a speedcam
		//======================================================
		case DIALOG_EANGLE:
		{
		    if(!strlen(inputtext)) return ShowPlayerDialog(playerid,DIALOG_EANGLE,DIALOG_STYLE_INPUT,"{00A5FF}gCamera {FFFFFF}- {FFDC00}Editor - Angle","Please enter a new angle","OK","Cancel");
		    new id = GetPVarInt(playerid,"selected");
		    new rot = strval(inputtext);
		    rot = rot + 180;
		    if (rot > 360)
		    {
		        rot = rot - 360;
		    }
            SpeedCameras[id][_rot] = rot;
            SetObjectRot(SpeedCameras[id][_objectid],0,0,rot);
            SaveCamera(id);
		    SendClientMessageEx(playerid,COLOR_GREEN,"sisis","The angle of cameraID ",id," has succesfully been updated to ",strval(inputtext),".");
		}
		case DIALOG_ERANGE:
		{
		    if(!strlen(inputtext)) return ShowPlayerDialog(playerid,DIALOG_ERANGE,DIALOG_STYLE_INPUT,"{00A5FF}gCamera {FFFFFF}- {FFDC00}Editor - Range","Please enter a new range","OK","Cancel");
		    new id = GetPVarInt(playerid,"selected");
			SpeedCameras[id][_range] = strval(inputtext);
			SaveCamera(id);
		    SendClientMessageEx(playerid,COLOR_GREEN,"sisis","The range of cameraID ",id," has succesfully been updated to ",strval(inputtext),".");
		}
		case DIALOG_ELIMIT:
		{
		    if(!strlen(inputtext)) return ShowPlayerDialog(playerid,DIALOG_ELIMIT,DIALOG_STYLE_INPUT,"{00A5FF}gCamera {FFFFFF}- {FFDC00}Editor - Speedlimit","Please enter a new Speedlimit","OK","Cancel");
		    new id = GetPVarInt(playerid,"selected");
			SpeedCameras[id][_limit] = strval(inputtext);
			SaveCamera(id);
		    SendClientMessageEx(playerid,COLOR_GREEN,"sisis","The speedlimit of cameraID ",id," has succesfully been updated to ",strval(inputtext),".");
		}
		case DIALOG_EFINE:
		{
		    if(!strlen(inputtext)) return ShowPlayerDialog(playerid,DIALOG_EFINE,DIALOG_STYLE_INPUT,"{00A5FF}gCamera {FFFFFF}- {FFDC00}Editor - Fine","Please enter a new fine","OK","Cancel");
		    new id = GetPVarInt(playerid,"selected");
		    SpeedCameras[id][_fine] = strval(inputtext);
		    SaveCamera(id);
		    SendClientMessageEx(playerid,COLOR_GREEN,"sisis","The fine of cameraID ",GetPVarInt(playerid,"selected")," has succesfully been updated to ",strval(inputtext),".");
		}
		case DIALOG_ETYPE:
		{
		    if(!strlen(inputtext) || strval(inputtext) != 0 && strval(inputtext) != 1) return ShowPlayerDialog(playerid,DIALOG_ETYPE,DIALOG_STYLE_INPUT,"{00A5FF}gCamera {FFFFFF}- {FFDC00}Editor - Mph/Kmh","enter 1 to use mph and 0 for kmh","OK","Cancel");
		    new id = GetPVarInt(playerid,"selected");
		    SpeedCameras[id][_usemph] = strval(inputtext);
		    if(strval(inputtext) == 1)
		    {
		        SendClientMessageEx(playerid,COLOR_GREEN,"sis","CameraID ",GetPVarInt(playerid,"selected")," does now meassure speed in mph.");
		    } else {
		        SendClientMessageEx(playerid,COLOR_GREEN,"sis","CameraID ",GetPVarInt(playerid,"selected")," does now meassure speed in kmh.");
		    }
		}
		case DIALOG_LABEL:
		{
		    new id = GetPVarInt(playerid,"selected");
		    if(!strlen(inputtext))
		    {
		        if(SpeedCameras[id][_activelabel] == true)
		        {
					Delete3DTextLabel(SpeedCameras[id][_label]);
					SpeedCameras[id][_activelabel] = false;
					SpeedCameras[id][_labeltxt] = 0;
		        }
		        SendClientMessageEx(playerid,COLOR_GREEN,"sis","The textlabel of cameraID ",GetPVarInt(playerid,"selected")," has succesfully been removed.");
		    } else {
		        if(SpeedCameras[id][_activelabel] == true)
		        {
		            format(SpeedCameras[id][_labeltxt],128,"%s",inputtext);
		            UpdateCameraLabel(SpeedCameras[id][_label],inputtext);
		        } else {
			        SpeedCameras[id][_activelabel] = true;
			        format(SpeedCameras[id][_labeltxt],128,"%s",inputtext);
			        SpeedCameras[id][_label] = AttachLabelToCamera(id,inputtext);
				}
				SendClientMessageEx(playerid,COLOR_GREEN,"sisss","The textlabel of cameraID ",GetPVarInt(playerid,"selected")," has succesfully been updated to ",inputtext,".");
		    }
		    SaveCamera(id);
		}
	}
	return 1;
}
//===================================================================================================
//                      					  Functions
//===================================================================================================
stock LoadCameras()
{
	new file[64];
	for(new i = 0;i<CAMERA_LIMIT;i++)
	{
	    format(file,sizeof file,"/SpeedCameras/%i.txt",i);
	    if(fexist(file))
	    {
	        INI_ParseFile(file,"LoadCam",.bExtra = true,.extra = i);
	        #if STREAMER_ENABLED == true
				SpeedCameras[i][_objectid] = STREAMER_ADD(18880,SpeedCameras[i][_x],SpeedCameras[i][_y],SpeedCameras[i][_z],0,0,SpeedCameras[i][_rot]);
			#else
			    SpeedCameras[i][_objectid] = CreateObject(18880,SpeedCameras[i][_x],SpeedCameras[i][_y],SpeedCameras[i][_z],0,0,SpeedCameras[i][_rot]);
			#endif
			SpeedCameras[i][_active] = true;
			if(SpeedCameras[i][_activelabel] == true)
			{
				SpeedCameras[i][_label] = AttachLabelToCamera(i,SpeedCameras[i][_labeltxt]);
			}
			loaded_cameras++;
	    }
	}
	printf("gCamera has succesfully loaded %i camera(s).",loaded_cameras);
}
forward LoadCam(cameraid,name[],value[]);
public LoadCam(cameraid,name[],value[])
{
	INI_Float("_x",SpeedCameras[cameraid][_x]);
	INI_Float("_y",SpeedCameras[cameraid][_y]);
	INI_Float("_z",SpeedCameras[cameraid][_z]);
	INI_Float("_rot",SpeedCameras[cameraid][_rot]);
	INI_Int("_range",SpeedCameras[cameraid][_range]);
	INI_Int("_limit",SpeedCameras[cameraid][_limit]);
	INI_Int("_fine",SpeedCameras[cameraid][_fine]);
	INI_Int("_usemph",SpeedCameras[cameraid][_usemph]);
	INI_Bool("_activelabel",SpeedCameras[cameraid][_activelabel]);
	INI_String("_labeltxt",SpeedCameras[cameraid][_labeltxt],128);
	return 1;
}
stock RemoveCameras()
{
	for(new i = 0;i<loaded_cameras +1;i++)
	{
	    if(SpeedCameras[i][_active] == true)
	    {
	        #if STREAMER_ENABLED == true
	            STREAMER_REMOVE(SpeedCameras[i][_objectid]);
	        #else
	        	DestroyObject(SpeedCameras[i][_objectid]);
	        #endif
	        if(SpeedCameras[i][_activelabel] == true)
	        {
				Delete3DTextLabel(SpeedCameras[i][_label]);
	        }
	    }
	}
	return 1;
}
stock generate_id()
{
	new file[64];
	for(new i = 0;i<CAMERA_LIMIT;i++)
	{
		format(file,sizeof file,"/SpeedCameras/%i.txt",i);
		if(!fexist(file)) return i;
	}
	return -1;
}
stock CreateSpeedCam(Float:x,Float:y,Float:z,Float:rot,range,limit,fine,use_mph = 0)
{
	new newid = generate_id();
	if(newid == -1)
	{
	    print("gSpeedcam: ERROR! Cannot create speedcam, max ammount of speedcameras has been reached!");
	    return 1;
	}
	if (newid == loaded_cameras || newid > loaded_cameras)
	{
	    loaded_cameras++;
	}
	SpeedCameras[newid][_x] = x;
	SpeedCameras[newid][_y] = y;
	SpeedCameras[newid][_z] = z;
	SpeedCameras[newid][_rot] = rot;
	SpeedCameras[newid][_range] = range;
	SpeedCameras[newid][_limit] = limit;
	SpeedCameras[newid][_fine] = fine;
	SpeedCameras[newid][_usemph] = use_mph;
	#if STREAMER_ENABLED == true
		SpeedCameras[newid][_objectid] = STREAMER_ADD(18880,x,y,z,0,0,rot);
	#else
		SpeedCameras[newid][_objectid] = CreateObject(18880,x,y,z,0,0,rot);
	#endif
	SpeedCameras[newid][_active] = true;
	SpeedCameras[newid][_activelabel] = false;
	SpeedCameras[newid][_labeltxt] = 0;
	new file[64];format(file,sizeof file,"/SpeedCameras/%i.txt",newid);
	new INI:handler = INI_Open(file);
	INI_WriteFloat(handler,"_x",SpeedCameras[newid][_x]);
	INI_WriteFloat(handler,"_y",SpeedCameras[newid][_y]);
	INI_WriteFloat(handler,"_z",SpeedCameras[newid][_z]);
	INI_WriteFloat(handler,"_rot",SpeedCameras[newid][_rot]);
	INI_WriteInt(handler,"_range",SpeedCameras[newid][_range]);
	INI_WriteInt(handler,"_limit",SpeedCameras[newid][_limit]);
	INI_WriteInt(handler,"_fine",SpeedCameras[newid][_fine]);
	INI_WriteInt(handler,"_usemph",SpeedCameras[newid][_usemph]);
	INI_WriteBool(handler,"_activelabel",SpeedCameras[newid][_activelabel]);
	INI_WriteString(handler,"_labeltxt",SpeedCameras[newid][_labeltxt]);
	INI_Close(handler);
	return newid;
}
stock SaveCamera(cameraid)
{
	new file[64];format(file,sizeof file,"/SpeedCameras/%i.txt",cameraid);
	new INI:handler = INI_Open(file);
	INI_WriteFloat(handler,"_x",SpeedCameras[cameraid][_x]);
	INI_WriteFloat(handler,"_y",SpeedCameras[cameraid][_y]);
	INI_WriteFloat(handler,"_z",SpeedCameras[cameraid][_z]);
	INI_WriteFloat(handler,"_rot",SpeedCameras[cameraid][_rot]);
	INI_WriteInt(handler,"_range",SpeedCameras[cameraid][_range]);
	INI_WriteInt(handler,"_limit",SpeedCameras[cameraid][_limit]);
	INI_WriteInt(handler,"_fine",SpeedCameras[cameraid][_fine]);
	INI_WriteInt(handler,"_usemph",SpeedCameras[cameraid][_usemph]);
	INI_WriteBool(handler,"_activelabel",SpeedCameras[cameraid][_activelabel]);
	INI_WriteString(handler,"_labeltxt",SpeedCameras[cameraid][_labeltxt]);
	INI_Close(handler);
}
stock DestroySpeedCam(cameraid)
{
    SpeedCameras[cameraid][_active] = false;
	#if STREAMER_ENABLED == true
		STREAMER_REMOVE(SpeedCameras[cameraid][_objectid]);
	#else
		DestroyObject(SpeedCameras[cameraid][_objectid]);
	#endif
	if(SpeedCameras[cameraid][_activelabel] == true)
	{
		Delete3DTextLabel(SpeedCameras[cameraid][_label]);
	}
	SpeedCameras[cameraid][_activelabel] = false;
	SpeedCameras[cameraid][_labeltxt] = 0;
    new file[64];format(file,sizeof file,"/SpeedCameras/%i.txt",cameraid);
    if(fexist(file)){fremove(file);}
	return 1;
}
stock SetSpeedCamRange(cameraid,limit)
{
	SpeedCameras[cameraid][_limit] = limit;
	return 1;
}
stock SetSpeedCamFine(cameraid,fine)
{
    SpeedCameras[cameraid][_fine] = fine;
	return 1;
}
stock Float:GetDistanceBetweenPoints(Float:x,Float:y,Float:tx,Float:ty)
{
  new Float:temp1, Float:temp2;
  temp1 = x-tx;temp2 = y-ty;
  return floatsqroot(temp1*temp1+temp2*temp2);
}

stock GetClosestCamera(playerid)
{
	new Float:distance = 10,Float:temp,Float:x,Float:y,Float:z,current = -1;GetPlayerPos(playerid,x,y,z);
	for(new i = 0;i<loaded_cameras +1;i++)
	{
	    if(SpeedCameras[i][_active] == true)
	    {
			temp = GetDistanceBetweenPoints(x,y,SpeedCameras[i][_x],SpeedCameras[i][_y]);
			if(temp < distance)
			{
				distance = temp;
				current = i;
			}
		}
	}
	return current;
}

stock Float:GetVehicleSpeed(vehicleid,UseMPH = 0)
{
	new Float:speed_x,Float:speed_y,Float:speed_z,Float:temp_speed;
	GetVehicleVelocity(vehicleid,speed_x,speed_y,speed_z);
	if(UseMPH == 0)
	{
	    temp_speed = floatsqroot(((speed_x*speed_x)+(speed_y*speed_y))+(speed_z*speed_z))*136.666667;
	} else {
	    temp_speed = floatsqroot(((speed_x*speed_x)+(speed_y*speed_y))+(speed_z*speed_z))*85.4166672;
	}
	floatround(temp_speed,floatround_round);return temp_speed;
}
stock SendClientMessageEx(playerid,color,type[],{Float,_}:...)
{
	new string[128];
	for(new i = 0;i<numargs() -2;i++)
	{
	    switch(type[i])
	    {
	        case 's':
	        {
				new result[128];
				for(new a= 0;getarg(i +3,a) != 0;a++)
				{
				    result[a] = getarg(i +3,a);
				}
				if(!strlen(string))
				{
				    format(string,sizeof string,"%s",result);
				} else format(string,sizeof string,"%s%s",string,result);
	        }

	        case 'i':
	        {
	            new result = getarg(i +3);
				if(!strlen(string))
				{
				    format(string,sizeof string,"%i",result);
				} else format(string,sizeof string,"%s%i",string,result);
	        }

	        case 'f':
	        {
				new Float:result = Float:getarg(i +3);
				if(!strlen(string))
				{
				    format(string,sizeof string,"%f",result);
				} else format(string,sizeof string,"%s%f",string,result);
	        }
	    }
	}
    SendClientMessage(playerid,color,string);
    return 1;
}
//===================================================================================================
//                                              Timers
//===================================================================================================
forward UpdateCameras();
public UpdateCameras()
{
	for(new a = 0;a<MAX_PLAYERS;a++)
	{
	    if(!IsPlayerConnected(a)) continue;
	    if(!IsPlayerInAnyVehicle(a)) continue;
	    if(GetPVarInt(a,"PlayerHasBeenFlashed") == 1)
		{
			continue;
		} else if (GetPVarInt(a,"PlayerHasBeenFlashed") == 2)
		{
			DeletePVar(a,"PlayerHasBeenFlashed");
			continue;
		}
	    for(new b = 0;b<loaded_cameras +1;b++)
	    {
	        if(SpeedCameras[b][_active] == false) continue;
	        if(IsPlayerInRangeOfPoint(a,SpeedCameras[b][_range],SpeedCameras[b][_x],SpeedCameras[b][_y],SpeedCameras[b][_z]))
	        {
	            new speed = floatround(GetVehicleSpeed(GetPlayerVehicleID(a),SpeedCameras[b][_usemph]));
	            new limit = SpeedCameras[b][_limit];
	            if(speed > limit)
	            {
	                TextDrawShowForPlayer(a,flash);
	                #if CAMERA_PERSPECTIVE == true
	                SetPlayerCameraPos(a,SpeedCameras[b][_x],SpeedCameras[b][_y],SpeedCameras[b][_z] + 5);
	                new Float:x,Float:y,Float:z;GetPlayerPos(a,x,y,z);
	                SetPlayerCameraLookAt(a,x,y,z);
	                #endif
	                SetPVarInt(a,"PlayerHasBeenFlashed",1);
	                SetTimerEx("RemoveFlash",CAMERA_FLASH_TIME,false,"i",a);
					if(GetPlayerState(a) == PLAYER_STATE_DRIVER)
					{
							if(SpeedCameras[b][_usemph] == 0)
							{
								SendClientMessageEx(a,0xFF1E00FF,"sisis","You are driving too fast! you got busted driving ",speed,"kmh where you were allowed to drive ",limit, "kmh.");
								SendClientMessageEx(a,0xFF1E00FF,"sis","You got yourself a fine of $",SpeedCameras[b][_fine],".");
							} else {
								SendClientMessageEx(a,0xFF1E00FF,"sisis","You are driving too fast! you got busted driving ",speed,"mph where you were allowed to drive ",limit, "mph.");
								SendClientMessageEx(a,0xFF1E00FF,"sis","You got yourself a fine of $",SpeedCameras[b][_fine],".");
							}
							GivePlayerMoney(a, - SpeedCameras[b][_fine]);
					}
	            }
	        }
	    }
	}
}
forward RemoveFlash(playerid);
public RemoveFlash(playerid)
{
	TextDrawHideForPlayer(playerid,flash);
	SetPVarInt(playerid,"PlayerHasBeenFlashed",2);
	#if CAMERA_PERSPECTIVE == true
	SetCameraBehindPlayer(playerid);
	#endif
}