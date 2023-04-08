/*
	easyDialog.inc - Dialogs made easier!

	With this useful include, scripters can easily create
	dialogs and show them to players.

	This include will prevent dialog spoofing, ID collision
	and a lot more.

	Created by Emmet on Friday, January 24, 2014.
*/
#define Dialog:%0(%1) \
	forward dialog_%0(%1); public dialog_%0(%1)

#define Dialog_Show(%0,%1,%2) \
	Dialog_Open(%0, #%1, %2)

#if !defined isnull
	#define isnull(%1) \
		((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

static stock
	g_DG_DialogFunction[MAX_PLAYERS][32 char]
;

forward OnDialogPerformed(playerid, dialog[], response, success);

forward @dialog_format(); @dialog_format() {
	format("", 1, "");
}

stock Dialog_Opened(playerid)
	return (GetPVarInt(playerid, "DIALOG_OPENED"));

stock Dialog_Close(playerid)
{
	DeletePVar(playerid, "DIALOG_OPENED");
	g_DG_DialogFunction[playerid]{0} = 0;

	ShowPlayerDialog(playerid, -1, DIALOG_STYLE_MSGBOX, " ", " ", " ", "");
	return 0;
}

stock Dialog_Open(playerid, function[], style, caption[], info[], button1[], button2[], {Float,_}:...)
{
	static
	    string[1024],
		start,
		end;

	if (numargs() > 7)
	{
	    #emit ADDR.pri button2
	    #emit STOR.pri start

	    for (end = start + (numargs() << 2) - 28; end > start; end -= 4)
	    {
	        #emit LREF.pri end
	        #emit PUSH.pri
		}
		#emit PUSH.S info
		#emit PUSH.C 1024
		#emit PUSH.C string

		#emit LOAD.S.pri 8
		#emit CONST.alt 16
		#emit SUB
		#emit PUSH.pri

		#emit SYSREQ.C format
		#emit LCTRL 5
		#emit SCTRL 4

		ShowPlayerDialog(playerid, 32700, style, caption, string, button1, button2);
	}
	else
	{
		ShowPlayerDialog(playerid, 32700, style, caption, info, button1, button2);
	}
	SetPVarInt(playerid, "DIALOG_OPENED", 1);
	strpack(g_DG_DialogFunction[playerid], function);
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	new
	    input[128];

	strcat(input, inputtext);

	for (new i = 0, len = strlen(input); i != len; i ++)
	{
	    if (input[i] != '%')
			continue;

		input[i] = '#';
	}
	if ((dialogid == 32700 && g_DG_DialogFunction[playerid]{0}))
	{
		new
		    func[40];

		strcat(func, "dialog_");
		strcat(func, g_DG_DialogFunction[playerid]);
		
		Dialog_Close(playerid);
		
		if (funcidx("OnDialogPerformed") == -1 || CallLocalFunction("OnDialogPerformed", "dsdd", playerid, func[7], response, funcidx(func) != -1) != 0) {
	 		CallLocalFunction(func, "ddds", playerid, response, listitem, (!input[0]) ? ("\1") : (input));
		}
	}
	#if defined DG_OnDialogResponse
	    DG_OnDialogResponse(playerid, dialogid, response, listitem, input);
	#endif
	return 0;
}

#if defined _ALS_OnDialogResponse
	#undef OnDialogResponse
#else
	#define _ALS_OnDialogResponse
#endif

#define OnDialogResponse DG_OnDialogResponse

#if defined DG_OnDialogResponse
	forward DG_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif
