// GPD.inc

/*
	native GetPlayerDialog(playerid);
*/

#if !defined INVALID_DIALOG_ID
	#define INVALID_DIALOG_ID       (-1)
#endif

static
	s_iOpenedDialogID[MAX_PLAYERS];
	
stock GetPlayerDialog(playerid)
{
	return s_iOpenedDialogID[playerid];
}
	
stock DL_ShowPlayerDialog(playerid, dialogid, style, caption[], info[], button1[], button2[])
{
	new
		ret = ShowPlayerDialog(playerid, dialogid, style, caption, info, button1, button2);

	if((dialogid != -1 && style >= 0) && strcmp(caption, " ") != 0 && strcmp(info, " ") != 0)
	{
		s_iOpenedDialogID[playerid] = dialogid;
	}

	return ret;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	s_iOpenedDialogID[playerid] = -1;

	#if defined DL_OnDialogResponse
	    return DL_OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
	    return 1;
	#endif
}

#if defined _ALS_ShowPlayerDialog
	#undef ShowPlayerDialog
#else
	#define _ALS_ShowPlayerDialog
#endif

#define ShowPlayerDialog DL_ShowPlayerDialog

#if defined _ALS_OnDialogResponse
	#undef OnDialogResponse
#else
	#define _ALS_OnDialogResponse
#endif

#define OnDialogResponse DL_OnDialogResponse

#if defined DL_OnDialogResponse
	forward DL_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

