// Emmet's selection menu include for Limitless Roleplay.
// Essentially the "eSelection 2.0" - created on 12/29/2016 @ 7:14 AM.

#if !defined MAX_SELECTION_MENU_ITEMS
	#define MAX_SELECTION_MENU_ITEMS    (312)
#endif

enum e_SELECTION_MENU
{
	PlayerText: pMenuTitle,
	PlayerText: pMenuPage,
	PlayerText: pMenuBoxes[24],
	bool:       pDisplayed,
				pExtra,
				pPage,
				pPages,
				pItems,
				pTime,
				pIgnore,
				pList[MAX_SELECTION_MENU_ITEMS]
};

static
	Text: selectorBaseTD[5],
		  selectorMenu[MAX_PLAYERS][e_SELECTION_MENU];

// This is the callback which selection menu responses will be called to.
forward OnPlayerSelectionMenuResponse(playerid, extraid, response, listitem, modelid);

selector_InitMain()
{
	// Why fill up player textdraw slots when you can just use plain old textdraws for these ones?

    selectorBaseTD[0] = TextDrawCreate(519.000000, 119.000000, "_");
	TextDrawBackgroundColor(selectorBaseTD[0], 255);
	TextDrawFont(selectorBaseTD[0], 1);
	TextDrawLetterSize(selectorBaseTD[0], 0.500000, 1.100000);
	TextDrawColor(selectorBaseTD[0], -1);
	TextDrawSetOutline(selectorBaseTD[0], 0);
	TextDrawSetProportional(selectorBaseTD[0], 1);
	TextDrawSetShadow(selectorBaseTD[0], 1);
	TextDrawUseBox(selectorBaseTD[0], 1);
	TextDrawBoxColor(selectorBaseTD[0], 125);
	TextDrawTextSize(selectorBaseTD[0], 156.000000, 0.000000);

	selectorBaseTD[1] = TextDrawCreate(519.000000, 119.000000, "_");
	TextDrawBackgroundColor(selectorBaseTD[1], 255);
	TextDrawFont(selectorBaseTD[1], 1);
	TextDrawLetterSize(selectorBaseTD[1], 0.500000, 32.050010);
	TextDrawColor(selectorBaseTD[1], -1);
	TextDrawSetOutline(selectorBaseTD[1], 0);
	TextDrawSetProportional(selectorBaseTD[1], 1);
	TextDrawSetShadow(selectorBaseTD[1], 1);
	TextDrawUseBox(selectorBaseTD[1], 1);
	TextDrawBoxColor(selectorBaseTD[1], 0xAFAFAFFF);
	TextDrawTextSize(selectorBaseTD[1], 156.000000, 0.000000);

	selectorBaseTD[2] = TextDrawCreate(457.500000, 393.000000, "Back");
	TextDrawAlignment(selectorBaseTD[2], 2);
	TextDrawBackgroundColor(selectorBaseTD[2], 255);
	TextDrawFont(selectorBaseTD[2], 2);
	TextDrawLetterSize(selectorBaseTD[2], 0.180000, 1.300000);
	TextDrawColor(selectorBaseTD[2], -1);
	TextDrawSetOutline(selectorBaseTD[2], 1);
	TextDrawSetProportional(selectorBaseTD[2], 1);
	TextDrawUseBox(selectorBaseTD[2], 1);
	TextDrawBoxColor(selectorBaseTD[2], 136);
	TextDrawTextSize(selectorBaseTD[2], 10.000000, 32.000000);
	TextDrawSetSelectable(selectorBaseTD[2], 1);

	selectorBaseTD[3] = TextDrawCreate(494.000000, 393.000000, "Next");
	TextDrawAlignment(selectorBaseTD[3], 2);
	TextDrawBackgroundColor(selectorBaseTD[3], 255);
	TextDrawFont(selectorBaseTD[3], 2);
	TextDrawLetterSize(selectorBaseTD[3], 0.180000, 1.300000);
	TextDrawColor(selectorBaseTD[3], -1);
	TextDrawSetOutline(selectorBaseTD[3], 1);
	TextDrawSetProportional(selectorBaseTD[3], 1);
	TextDrawUseBox(selectorBaseTD[3], 1);
	TextDrawBoxColor(selectorBaseTD[3], 136);
	TextDrawTextSize(selectorBaseTD[3], 10.000000, 32.000000);
	TextDrawSetSelectable(selectorBaseTD[3], 1);

	selectorBaseTD[4] = TextDrawCreate(511.000000, 119.000000, "~r~X");
	TextDrawAlignment(selectorBaseTD[4], 2);
	TextDrawBackgroundColor(selectorBaseTD[4], 255);
	TextDrawFont(selectorBaseTD[4], 2);
	TextDrawLetterSize(selectorBaseTD[4], 0.220000, 1.100000);
	TextDrawColor(selectorBaseTD[4], -1);
	TextDrawSetOutline(selectorBaseTD[4], 1);
	TextDrawSetProportional(selectorBaseTD[4], 1);
	TextDrawUseBox(selectorBaseTD[4], 1);
	TextDrawBoxColor(selectorBaseTD[4], 255);
	TextDrawTextSize(selectorBaseTD[4], 10.000000, 10.000000);
	TextDrawSetSelectable(selectorBaseTD[4], 1);
}

stock ShowPlayerSelectionMenu(playerid, extraid, name[], const items[] = {-1}, size = sizeof(items))
{
	// 164.000000, 134.000000
	// 222.000000, 198.000000

	if(!IsPlayerConnected(playerid))
		return false;

	if(size > MAX_SELECTION_MENU_ITEMS)
	    return false;

	if(selectorMenu[playerid][pDisplayed])
	{
		HidePlayerSelectionMenu(playerid);
	}

	new
	    Float:x = 106.00,
	    Float:y = 134.00,
		index = 0;

	// This textdraw shows the name of the menu in the header.
    selectorMenu[playerid][pMenuTitle] = CreatePlayerTextDraw(playerid, 160.000000, 117.000000, name);
	PlayerTextDrawBackgroundColor(playerid, selectorMenu[playerid][pMenuTitle], 255);
	PlayerTextDrawFont(playerid, selectorMenu[playerid][pMenuTitle], 2);
	PlayerTextDrawLetterSize(playerid, selectorMenu[playerid][pMenuTitle], 0.230000, 1.399999);
	PlayerTextDrawColor(playerid, selectorMenu[playerid][pMenuTitle], -1);
	PlayerTextDrawSetOutline(playerid, selectorMenu[playerid][pMenuTitle], 1);
	PlayerTextDrawSetProportional(playerid, selectorMenu[playerid][pMenuTitle], 1);

	// This textdraw shows the current page the menu is on.
    selectorMenu[playerid][pMenuPage] = CreatePlayerTextDraw(playerid, 340.000000, 116.000000, "1/5");
	PlayerTextDrawAlignment(playerid, selectorMenu[playerid][pMenuPage], 2);
	PlayerTextDrawBackgroundColor(playerid, selectorMenu[playerid][pMenuPage], 255);
	PlayerTextDrawFont(playerid, selectorMenu[playerid][pMenuPage], 2);
	PlayerTextDrawLetterSize(playerid, selectorMenu[playerid][pMenuPage], 0.220000, 1.500000);
	PlayerTextDrawColor(playerid, selectorMenu[playerid][pMenuPage], -1);
	PlayerTextDrawSetOutline(playerid, selectorMenu[playerid][pMenuPage], 1);
	PlayerTextDrawSetProportional(playerid, selectorMenu[playerid][pMenuPage], 1);

	for(new i = 0; i < size; i ++)
	{
	    if(items[i] == -1)
	    {
	        // Here's some code to fix a bug where indeterminate array sizes would still add invalid models to the menu.
	        size = i + 1;
	        break;
		}
	}

	for(new i = 0; i < 24; i ++)
	{
	    if(i < size && items[i] >= 0)
	    {
	        if((i > 0) && (i % 6) == 0)
	        {
	            // Start at the first column.
	            x  = 106.0;
	            // Start on the next row.
	            y += 64.0;
	        }

            selectorMenu[playerid][pMenuBoxes][index] = CreatePlayerTextDraw(playerid, x += 58.0, y, "_");
			PlayerTextDrawBackgroundColor(playerid, selectorMenu[playerid][pMenuBoxes][index], 136);
			PlayerTextDrawFont(playerid, selectorMenu[playerid][pMenuBoxes][index], 5);
			PlayerTextDrawLetterSize(playerid, selectorMenu[playerid][pMenuBoxes][index], 0.470000, 2.000000);
			PlayerTextDrawSetProportional(playerid, selectorMenu[playerid][pMenuBoxes][index], 1);
			PlayerTextDrawSetShadow(playerid, selectorMenu[playerid][pMenuBoxes][index], 1);
			PlayerTextDrawUseBox(playerid, selectorMenu[playerid][pMenuBoxes][index], 1);
			PlayerTextDrawBoxColor(playerid, selectorMenu[playerid][pMenuBoxes][index], 0);
			PlayerTextDrawTextSize(playerid, selectorMenu[playerid][pMenuBoxes][index], 57.000000, 63.000000);
			PlayerTextDrawSetPreviewModel(playerid, selectorMenu[playerid][pMenuBoxes][index], items[i]);
			PlayerTextDrawSetPreviewRot(playerid, selectorMenu[playerid][pMenuBoxes][index], -16.0000, 0.0000, -55.0000, 1.0000);
			PlayerTextDrawSetSelectable(playerid, selectorMenu[playerid][pMenuBoxes][index], 1);
			PlayerTextDrawShow(playerid, selectorMenu[playerid][pMenuBoxes][index++]);
	    }
	    else
	    {
	        selectorMenu[playerid][pMenuBoxes][index] = PlayerText:INVALID_3DTEXT_ID;
	    }
	}

	for(new i = 0; i < MAX_SELECTION_MENU_ITEMS; i ++)
	{
	    if(i < 5)
			TextDrawShowForPlayer(playerid, selectorBaseTD[i]);

		if(i < size)
	    	selectorMenu[playerid][pList][i] = items[i];
		else
		    selectorMenu[playerid][pList][i] = -1;
	}

    selectorMenu[playerid][pDisplayed] = true;
    selectorMenu[playerid][pIgnore]    = false;
    selectorMenu[playerid][pExtra] 	   = extraid;
    selectorMenu[playerid][pPage]      = 1;
    selectorMenu[playerid][pPages]     = (size % 24 == 0) ? size / 24 : (size / 24) + 1;
    selectorMenu[playerid][pItems]     = size;
    selectorMenu[playerid][pTime]      = NetStats_GetConnectedTime(playerid);

    PlayerTextDrawShow(playerid, selectorMenu[playerid][pMenuTitle]);
	//PlayerTextDrawShow(playerid, selectorMenu[playerid][pMenuPage]);
	SelectTextDraw(playerid, -1);
	return true;
}

stock HidePlayerSelectionMenu(playerid)
{
	if(!IsPlayerConnected(playerid) || !selectorMenu[playerid][pDisplayed])
	    return false;

	for(new i = 0; i < MAX_SELECTION_MENU_ITEMS; i ++)
	{
	    if(i < 24)
			PlayerTextDrawDestroy(playerid, selectorMenu[playerid][pMenuBoxes][i]);
	    if(i < 5)
	        TextDrawHideForPlayer(playerid, selectorBaseTD[i]);

	    selectorMenu[playerid][pList][i] = -1;
	}

	selectorMenu[playerid][pDisplayed] = false;
	selectorMenu[playerid][pIgnore]    = true;
	selectorMenu[playerid][pExtra]     = -1;
	selectorMenu[playerid][pPage]      = 0;

	PlayerTextDrawDestroy(playerid, selectorMenu[playerid][pMenuTitle]);
	PlayerTextDrawDestroy(playerid, selectorMenu[playerid][pMenuPage]);
	CancelSelectTextDraw(playerid);
	return true;
}

static SetPlayerSelectionMenuPage(playerid, page)
{
	if(!IsPlayerConnected(playerid) || !selectorMenu[playerid][pDisplayed])
	    return false;

	if(!(1 <= page <= selectorMenu[playerid][pPages]))
	    return false;

	new start = (page - 1) * 24;

	for(new i = 0; i < 24; i ++)
	{
	    PlayerTextDrawHide(playerid, selectorMenu[playerid][pMenuBoxes][i]);

	    if(start < selectorMenu[playerid][pItems])
	    {
			PlayerTextDrawSetPreviewModel(playerid, selectorMenu[playerid][pMenuBoxes][i], selectorMenu[playerid][pList][start++]);
            PlayerTextDrawShow(playerid, selectorMenu[playerid][pMenuBoxes][i]);
		}
	}

	selectorMenu[playerid][pPage] = page;
	return true;
}

forward EnableSelectionMenuCursor(playerid);
public EnableSelectionMenuCursor(playerid)
{
	if(selectorMenu[playerid][pDisplayed])
	{
	    SelectTextDraw(playerid, -1);
	}
}

public OnFilterScriptInit()
{
	selector_InitMain();

	#if defined SM_OnFilterScriptInit
	    return SM_OnFilterScriptInit();
	#else
	    return 1;
	#endif
}

#if defined _ALS_OnFilterScriptInit
	#undef OnFilterScriptInit
#else
	#define _ALS_OnFilterScriptInit
#endif

#define OnFilterScriptInit SM_OnFilterScriptInit

#if defined SM_OnFilterScriptInit
	forward SM_OnFilterScriptInit();
#endif

public OnGameModeInit()
{
    selector_InitMain();

	#if defined SM_OnGameModeInit
	    return SM_OnGameModeInit();
	#else
	    return 1;
	#endif
}

#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif

#define OnGameModeInit SM_OnGameModeInit

#if defined SM_OnGameModeInit
	forward SM_OnGameModeInit();
#endif

public OnFilterScriptExit()
{
	// Destroy the base textdraws - they don't destroy on their own!
	for(new i = 0; i < 5; i ++)
	{
		TextDrawDestroy(selectorBaseTD[i]);
	}

	// Unlike gamemodes, filterscripts don't destroy per-player textdraws upon exit.
	for(new i = 0; i <= GetPlayerPoolSize(); i ++)
	{
	    if(IsPlayerConnected(i) && selectorMenu[i][pDisplayed])
	    {
	        HidePlayerSelectionMenu(i);
		}
	}

	#if defined SM_OnFilterScriptExit
	    return SM_OnFilterScriptExit();
	#else
	    return 1;
	#endif
}

#if defined _ALS_OnFilterScriptExit
	#undef OnFilterScriptExit
#else
	#define _ALS_OnFilterScriptExit
#endif

#define OnFilterScriptExit SM_OnFilterScriptExit

#if defined SM_OnFilterScriptExit
	forward SM_OnFilterScriptExit();
#endif

public OnPlayerDisconnect(playerid, reason)
{
    if(selectorMenu[playerid][pDisplayed])
	{
	    HidePlayerSelectionMenu(playerid);
	}

	#if defined SM_OnPlayerDisconnect
	    return SM_OnPlayerDisconnect(playerid, reason);
	#else
	    return 1;
	#endif
}

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect SM_OnPlayerDisconnect

#if defined SM_OnPlayerDisconnect
	forward SM_OnPlayerDisconnect(playerid, reason);
#endif

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    if(selectorMenu[playerid][pIgnore])
	{
	    selectorMenu[playerid][pIgnore] = 0;
	}
	else if(selectorMenu[playerid][pDisplayed])
	{
	    if(clickedid == Text:INVALID_TEXT_DRAW || clickedid == selectorBaseTD[4])
	    {
			if(funcidx("OnPlayerSelectionMenuResponse") == -1 || CallLocalFunction("OnPlayerSelectionMenuResponse", "iiiii", playerid, selectorMenu[playerid][pExtra], 0, -1, -1))
			{
		    	HidePlayerSelectionMenu(playerid);
			}
			else
			{
			    SetTimerEx("EnableSelectionMenuCursor", 200, false, "i", playerid);
			}
		}
	    else if(clickedid == selectorBaseTD[2] && selectorMenu[playerid][pPage] > 1)
	    {
	        SetPlayerSelectionMenuPage(playerid, selectorMenu[playerid][pPage] - 1);
		}
	    else if(clickedid == selectorBaseTD[3] && selectorMenu[playerid][pPage] < selectorMenu[playerid][pPages])
	    {
	        SetPlayerSelectionMenuPage(playerid, selectorMenu[playerid][pPage] + 1);
		}

		return 1;
	}

	#if defined SM_OnPlayerClickTextDraw
	    return SM_OnPlayerClickTextDraw(playerid, clickedid);
	#else
	    return 1;
	#endif
}

#if defined _ALS_OnPlayerClickTextDraw
	#undef OnPlayerClickTextDraw
#else
	#define _ALS_OnPlayerClickTextDraw
#endif

#define OnPlayerClickTextDraw SM_OnPlayerClickTextDraw

#if defined SM_OnPlayerClickTextDraw
	forward SM_OnPlayerClickTextDraw(playerid, Text:clickedid);
#endif

public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
    if(selectorMenu[playerid][pDisplayed] && NetStats_GetConnectedTime(playerid) - selectorMenu[playerid][pTime] > 400)
	{
	    for(new i = 0; i < 24; i ++)
	    {
			if(playertextid == selectorMenu[playerid][pMenuBoxes][i])
			{
			    new
					index =  ((selectorMenu[playerid][pPage] - 1) * 24) + i,
					extraid = selectorMenu[playerid][pExtra],
					modelid = selectorMenu[playerid][pList][index];

				HidePlayerSelectionMenu(playerid);
				CallLocalFunction("OnPlayerSelectionMenuResponse", "iiiii", playerid, extraid, 1, index, modelid);
				return 1;
			}
	    }
	}

	#if defined SM_OnPlayerClickPlayerTextDraw
	    return SM_OnPlayerClickPlayerTextDraw(playerid, playertextid);
	#else
	    return 1;
	#endif
}

#if defined _ALS_OnPlayerClickPlayerTD
	#undef OnPlayerClickPlayerTextDraw
#else
	#define _ALS_OnPlayerClickPlayerTD
#endif

#define OnPlayerClickPlayerTextDraw SM_OnPlayerClickPlayerTextDraw

#if defined SM_OnPlayerClickPlayerTextDraw
	forward SM_OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid);
#endif
