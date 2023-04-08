#define MAX_TEXT_SIZE 128
#define MAX_MSG 25
#define MSG_FILE "messages.ini"

forward RandMsg();
new MsgIndex[MAX_MSG][MAX_TEXT_SIZE];
new pOnMsg[MAX_PLAYERS];
new Cooldown = 60;
new Prefix[30];
new send[MAX_TEXT_SIZE];
new Timer;
new PlayerData[MAX_PLAYERS+1][pEnum];
public OnFilterScriptInit()
{
	print("\n--------------------------------------");
	print(" Advanced Dynamic Random Messages v1.2 Loaded");
	print(" Editor: Shinja");
	print("--------------------------------------\n");
	if(!fexist(MSG_FILE))
	{
		fcreate(MSG_FILE);
		new string[6];
	 	format(string,6,"%d",Cooldown);
	   	fstrset(MSG_FILE,"Cooldown",string);
	   	format(Prefix, 30, "{FFE100}[S:Random MSGs]");
	   	fstrset(MSG_FILE,"Prefix",Prefix);
   	}
	else ReloadConfig();
	ReloadMessages();
	Timer = SetTimer("RandMsg", Cooldown*1000, true);
	return 1;
}

public OnFilterScriptExit() { KillTimer(Timer); return 1; }

public RandMsg()
{
	new rand = random(GetMessagesCount());
	if(rand == GetMessagesCount()) rand--;
	format(send, MAX_TEXT_SIZE, "%s {FFFFFF}%s", Prefix, MsgIndex[rand]);
	SendClientMessageToAll(-1, send);
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid)
	{
		case 111:
		{
		    if(response)
		    {
		        switch(listitem)
		        {
					case 0: ShowPlayerDialog(playerid, 112, DIALOG_STYLE_INPUT, "{2BFF00}Add New Message", "{23CF00}You have selected to add a new message", "Add", "Back");
                    case 1: ShowPlayerDialog(playerid, 114, DIALOG_STYLE_INPUT, "{2BFF00}Cooldown - Seconds", "{23CF00}You have selected to change cooldown", "Change", "Back");
                    case 2: ShowPlayerDialog(playerid, 115, DIALOG_STYLE_INPUT, "{2BFF00}Prefix", "{23CF00}You have selected to change the prefix", "Change", "Back");
					default:
					{
                        new msg[20]; format(msg, sizeof(msg), "Message%d", listitem-2);
						new str[200]; format(str, sizeof(str), "{23CF00}You have selected to edit a message\n{9E9E9E}Message %d: {99C98F}%s", listitem-2, fstr(MSG_FILE, msg));
                        ShowPlayerDialog(playerid, 113, DIALOG_STYLE_INPUT, "{2BFF00}Edit Message", str, "Edit", "Back");
                        pOnMsg[playerid] = listitem-2;
					}
				}
			}
			return 1;
		}
		case 112:
		{
		    if(!response) return ShowPlayerDialog(playerid, 111, DIALOG_STYLE_TABLIST, "{1BA300}Random Messages Settings", GetMessages(), "Select", "Cancel");
			if(strlen(inputtext) < 6) return ShowPlayerDialog(playerid, 112, DIALOG_STYLE_INPUT, "{2BFF00}Add New Message", "{23CF00}You have selected to add a new message\n{FF0000}A message must contain atleast 6 characters", "Add", "Back");
			new msg[20]; format(msg, sizeof(msg), "Message%d", GetMessagesCount()+1);
			fstrset(MSG_FILE, msg, inputtext);
			ReloadMessages();
			ShowPlayerDialog(playerid, 111, DIALOG_STYLE_TABLIST, "{1BA300}Random Messages Settings", GetMessages(), "Select", "Cancel");
			return 1;
		}
		case 114:
		{
		    if(!response) return ShowPlayerDialog(playerid, 111, DIALOG_STYLE_TABLIST, "{1BA300}Random Messages Settings", GetMessages(), "Select", "Cancel");
			if(!(IsNumeric(inputtext))) return ShowPlayerDialog(playerid, 114, DIALOG_STYLE_INPUT, "{2BFF00}Cooldown - Seconds", "{23CF00}You have selected to change cooldown\n{FF0000}A cooldown must be numeric", "Change", "Back");
			Cooldown = strval(inputtext);
			new string[6];
			format(string,6,"%d",Cooldown);
   			fstrset(MSG_FILE,"Cooldown",string);
			KillTimer(Timer);
			Timer = SetTimer("RandMsg", Cooldown*1000, true);
			ShowPlayerDialog(playerid, 111, DIALOG_STYLE_TABLIST, "{1BA300}Random Messages Settings", GetMessages(), "Select", "Cancel");
			return 1;
		}
		case 115:
		{
		    if(!response) return ShowPlayerDialog(playerid, 111, DIALOG_STYLE_TABLIST, "{1BA300}Random Messages Settings", GetMessages(), "Select", "Cancel");
			if(strlen(inputtext) < 3) return ShowPlayerDialog(playerid, 115, DIALOG_STYLE_INPUT, "{2BFF00}Prefix", "{23CF00}You have selected to change the prefix\n{FF0000}A prefix must contain atleast 3 characters", "Change", "Back");
   			fstrset(MSG_FILE,"Prefix",inputtext);
   			format(Prefix, 30, "%s", inputtext);
			ShowPlayerDialog(playerid, 111, DIALOG_STYLE_TABLIST, "{1BA300}Random Messages Settings", GetMessages(), "Select", "Cancel");
			return 1;
		}
		case 113:
		{
		    if(!response) return ShowPlayerDialog(playerid, 111, DIALOG_STYLE_TABLIST, "{1BA300}Random Messages Settings", GetMessages(), "Select", "Cancel");
            new msg[20]; format(msg, sizeof(msg), "Message%d", pOnMsg[playerid]);
			new str[200]; format(str, sizeof(str), "{23CF00}You have selected to edit a message\n{9E9E9E}Message %d: {99C98F}%s\n{FF0000}A message must contain atleast 6 characters", pOnMsg[playerid], fstr(MSG_FILE, msg));
  			if(strlen(inputtext) < 6) return ShowPlayerDialog(playerid, 113, DIALOG_STYLE_INPUT, "{2BFF00}Edit Message", str, "Edit", "Back");
			fstrset(MSG_FILE, msg, inputtext);
			ReloadMessages();
			ShowPlayerDialog(playerid, 111, DIALOG_STYLE_TABLIST, "{1BA300}Random Messages Settings", GetMessages(), "Select", "Cancel");
			return 1;
		}
	}
    return 0;
}

CMD:msettings(playerid)
{
	if(!PlayerData[playerid][pAdmin] < JUNIOR_ADMIN) return 0;
	ShowPlayerDialog(playerid, 111, DIALOG_STYLE_TABLIST, "{1BA300}Random Messages Settings", GetMessages(), "Select", "Cancel");
	return 1;
}

stock GetMessages()
{
	new string[1280], get[MAX_TEXT_SIZE], msg[20];
	format(string, sizeof(string), "{FA9E00}Add\t{2BFF00}Empty\n{FA9E00}Cooldown\t{2BFF00}%d Seconds\n{FA9E00}Prefix\t{2BFF00}%s\n", Cooldown, Prefix);
	for(new i=0, j=MAX_MSG; i<j; i++)
	{
		format(msg, sizeof(msg), "Message%d", i+1);
		if(!flineexist(MSG_FILE, msg)) break;
		format(get, sizeof(get), "{9E9E9E}%s\t%s\n", msg, fstr(MSG_FILE, msg));
		strcat(string, get);
	}
	return string;
}

stock ReloadMessages()
{
    new msg[20];
	for(new i, j=MAX_MSG; i<j; i++)
	{
 		format(msg, sizeof(msg), "Message%d", i+1);
		if(!flineexist(MSG_FILE, msg)) break;
		format(MsgIndex[i], MAX_TEXT_SIZE, "%s", fstr(MSG_FILE, msg));
	}
}

stock ReloadConfig()
{
	format(Prefix, 30, "%s",fstr(MSG_FILE, "Prefix"));
	Cooldown = strval(fstr(MSG_FILE, "Cooldown"));
}

stock GetMessagesCount()
{
	new count, msg[20];
	for(new i, j=MAX_MSG; i<j; i++)
	{
		format(msg, sizeof(msg), "Message%d", i+1);
		if(!flineexist(MSG_FILE, msg)) break;
		count++;
	}
	return count;
}

stock IsNumeric(const string[])
{
	for (new i = 0, j = strlen(string); i < j; i++)
 	{
		if (string[i] > '9' || string[i] < '0') return 0;
  	}
   	return 1;
}

//Some file functions
stock fcreate(file[]) {
	if (fexist(file)) return false;
	new File:f=fopen(file,io_write);
	if (f) {
		fclose(f);
		return true;
	}
	return false;
}

stock flineexist(file[],line[]) {
	if(strlen(line)==0 || strlen(line)+2>255) return false;
	new File:f=fopen(file,io_read);
	if(!f) return false;
	new tmp[255];
	while(fread(f,tmp))
	{
		if(tmp[strlen(line)]=='=' && !strcmp(tmp, line, true, strlen(line)))
		{
			fclose(f);
			return true;
		}
	}
	fclose(f);
	return false;
}

stock fstr(file[],line[]) {
	new tmp[255];
	if(strlen(line)==0 || strlen(line)+2>255) return tmp;
	new File:f=fopen(file,io_read);
	if(!f) return tmp;
	while(fread(f,tmp))
	{
		if(tmp[strlen(line)]=='=' && !strcmp(tmp, line, true, strlen(line)))
		{
			DINI_StripNewLine(tmp);
			strmid(tmp, tmp, strlen(line) + 1, strlen(tmp), 255);
			fclose(f);
			return tmp;
		}
	}
	fclose(f);
	return tmp;
}

stock fstrset(file[],line[],value[]) {
	if(strlen(line)==0 || strlen(line)+strlen(value)+2>255) return false;
	new File:f, File:f2;
	new tmp[255];
	new bool:wasset=false;
	format(tmp,sizeof(tmp),"%s.part",file);
	fremove(tmp);
	f=fopen(file,io_read);
	if(!f) return false;
	f2=fopen(tmp,io_write);
	if(!f2)
	{
		fclose(f);
		return false;
	}
	while(fread(f,tmp))
	{
		if(!wasset && tmp[strlen(line)]=='=' && !strcmp(tmp, line, true, strlen(line)))
		{
			format(tmp,sizeof(tmp),"%s=%s",line,value);
			wasset=true;
		}
		else
		{
			DINI_StripNewLine(tmp);
		}
		fwrite(f2,tmp);
		fwrite(f2,"\r\n");
	}
	if(!wasset)
	{
		format(tmp,sizeof(tmp),"%s=%s",line,value);
		fwrite(f2,tmp);
		fwrite(f2,"\r\n");
	}
	fclose(f);
	fclose(f2);
	format(tmp,sizeof(tmp),"%s.part",file);
	if(DINI_fcopytextfile(tmp,file)) return fremove(tmp);
	return false;
}

//from dini (Dracoblue)
stock DINI_StripNewLine(string[]) {
	new len = strlen(string);
	if (string[0]==0) return ;
	if ((string[len - 1] == '\n') || (string[len - 1] == '\r')) {
		string[len - 1] = 0;
		if (string[0]==0) return ;
		if ((string[len - 2] == '\n') || (string[len - 2] == '\r')) string[len - 2] = 0;
	}
}

stock DINI_fcopytextfile(oldname[],newname[]) {
	new File:ohnd,File:nhnd;
	if (!fexist(oldname)) return false;
	ohnd=fopen(oldname,io_read);
	if (!ohnd) return false;
	nhnd=fopen(newname,io_write);
	if (!nhnd) {
		fclose(ohnd);
		return false;
	}
	new tmpres[255];
	while (fread(ohnd,tmpres)) {
		DINI_StripNewLine(tmpres);
		format(tmpres,sizeof(tmpres),"%s\r\n",tmpres);
		fwrite(nhnd,tmpres);
	}
	fclose(ohnd);
	fclose(nhnd);
	return true;
}
