/*
 * S32_Business - Create business with just one line (MySQL)!
 * Copyright(c)System32
 * This file is provided as is (no warranties)
 
 
 * How I made a house system I need business to!
 * Functions: 21
 * Commands: 5
 * Callbacks: 2
 * Credits:
     * System32 - Almost everything!
     * The Guy - Helped me a lot, thank you!
     * Y_Less - y_hooks, y_commands, sscanf & foreach!
     * G-Stylezz (BlueG) - MySQL plugin!
 * That is basically it, have fun with this include and easy scripting!
 */
 
#if !defined _inc_a_samp
	#include <a_samp>
#endif
#if !defined _inc_a_mysql
	#include <a_mysql>
#endif
#if !defined _inc_foreach
	#include <foreach>
#endif
#include <YSI\y_hooks>
#include <YSI\y_commands>

#define MAX_BUSINESS 150
#define business_version "v1.0.0"
#define BUSINES_PAYMENT 1000
#if !defined MAX_BUSINESS
	#error Please define the max business (#define MAX_BUSINESS)
#endif


#define COLOR_LIME                                              0x10F441AA
#define COLOR_KRED                                              0xFF0000FF
#define COLOR_YELLOW                                            0xFFFF00AA

enum bInfo
{
	bOwner[24],
	Float: bEnterX,
	Float: bEnterY,
	Float: bEnterZ,
	Float: bExitX,
	Float: bExitY,
	Float: bExitZ,
	bInterior,
	bPrice,
	bVirtualWorld,
	bOwned,
	bLocked,
	bMoney,
	Text3D: bLabel,
	bPickup
};
new BusinessInfo[MAX_BUSINESS][bInfo];

new Iterator:Business<MAX_BUSINESS>, bstring[128], BQuery[1000], BusinessID, bsavingstring[500], PaymentTimer;
new bool: PlayerEnteredHisBusiness[MAX_PLAYERS] = false;

forward OnPlayerEnterBusiness(playerid, businessid);
forward OnPlayerExitBusiness(playerid, businessid);
forward PaymentUp();


//*****************************           *****************************
//***************************** FUNCTIONS *****************************
//*****************************           *****************************




/*

 • Function: CreateBusiness(Float: EnterX, Float: EnterY, Float: EnterZ, Interior, Float: InteriorX, Float: InteriorY, Float: InteriorZ, Price, VirtualWorld, RentPrice)
 • Data storage: MySQL (G-Stylezzz's plugin)
 • Usage: Creating business, use this in OnGameModeInit or OnFilterScriptInit!
 • Parameters:
        EnterX, EnterY, EnterZ: Coordinates where you can enter business, also on that coordiantes will create pickup and 3D text!
        ExitX, ExitY, ExitZ: Coordinates where you can exit business, this coordinates are coordiantes of interior, you can find interiors on http://weedarr.wikidot.com/interior or http://wiki.sa-mp.com/wiki/InteriorIDs
		Interior: ID of interior you want, see the web page on the parameter above
		Price: Price for buying business
		VirtulWorld: Always increase this because if you have 2 same interior and player are in the (Example one is in his house, second is in his too) they will see themself, It will look that they have same house! (Bad explained :/)
 • Example: CreateBusiness(-2395.9585,-601.2695,132.6484, 3, 384.808624,173.804992,1008.382812, 7000, 0);

*/

stock CreateBusiness(Float: EnterX, Float: EnterY, Float: EnterZ, Interior, Float: ExitX, Float: ExitY, Float: ExitZ, Price, VirtualWorld)
{
    format(BQuery, sizeof(BQuery), "SELECT * FROM `business` WHERE `BusinessID` = %d", BusinessID);
    mysql_query(BQuery);
    mysql_store_result();
 	if(mysql_num_rows() == 0)
    {
        format(BusinessInfo[BusinessID][bOwner], 24, "None");
		BusinessInfo[BusinessID][bEnterX] = EnterX;
		BusinessInfo[BusinessID][bEnterY] = EnterY;
		BusinessInfo[BusinessID][bEnterZ] = EnterZ;
		BusinessInfo[BusinessID][bExitX] = ExitX;
		BusinessInfo[BusinessID][bExitY] = ExitY;
		BusinessInfo[BusinessID][bExitZ] = ExitZ;
		BusinessInfo[BusinessID][bInterior] = Interior;
		BusinessInfo[BusinessID][bVirtualWorld] = VirtualWorld;
		BusinessInfo[BusinessID][bPrice] = Price;
        format(bstring, sizeof(bstring), "For sale!\nPrice: %d\nBusiness ID: %d\nType /buybusiness to buy business!", Price, BusinessID);
        format(BQuery, sizeof(BQuery), "INSERT INTO `business` (`User`, `EnterX`, `EnterY`, `EnterZ`, `ExitX`, `ExitY`, `ExitZ`, `Interior`, `Price`, `VirtualWorld`, `Owned`, `Locked`, `Money`, `BusinessID`) VALUES");
		format(BQuery, sizeof(BQuery), "%s ('None', %f, %f, %f, %f, %f, %f, %d, %d, %d, 0, 0, 0, %d)", BQuery, BusinessInfo[BusinessID][bEnterX], BusinessInfo[BusinessID][bEnterY], BusinessInfo[BusinessID][bEnterZ], BusinessInfo[BusinessID][bExitX], BusinessInfo[BusinessID][bExitY], BusinessInfo[BusinessID][bExitZ], BusinessInfo[BusinessID][bInterior], BusinessInfo[BusinessID][bPrice], BusinessInfo[BusinessID][bVirtualWorld], BusinessID);
	    mysql_query(BQuery);
        BusinessInfo[BusinessID][bLabel] = Create3DTextLabel(bstring, 0x21DD00FF, EnterX, EnterY, EnterZ, 40.0, 0);
        BusinessInfo[BusinessID][bPickup] = CreatePickup(1272, 23, EnterX, EnterY, EnterZ, 0);
	}
	else
	{
        if(mysql_fetch_row_format(BQuery, "|"))
        {
   			mysql_fetch_field_row(bsavingstring, "User"); format(BusinessInfo[BusinessID][bOwner], 24, "%s", bsavingstring);
            mysql_fetch_field_row(bsavingstring, "EnterX"); BusinessInfo[BusinessID][bEnterX] = floatstr(bsavingstring);
            mysql_fetch_field_row(bsavingstring, "EnterY"); BusinessInfo[BusinessID][bEnterY] = floatstr(bsavingstring);
			mysql_fetch_field_row(bsavingstring, "EnterZ"); BusinessInfo[BusinessID][bEnterZ] = floatstr(bsavingstring);
			mysql_fetch_field_row(bsavingstring, "ExitX"); BusinessInfo[BusinessID][bExitX] = floatstr(bsavingstring);
			mysql_fetch_field_row(bsavingstring, "ExitY"); BusinessInfo[BusinessID][bExitY] = floatstr(bsavingstring);
			mysql_fetch_field_row(bsavingstring, "ExitZ"); BusinessInfo[BusinessID][bExitZ] = floatstr(bsavingstring);
			mysql_fetch_field_row(bsavingstring, "Interior"); BusinessInfo[BusinessID][bInterior] = strval(bsavingstring);
			mysql_fetch_field_row(bsavingstring, "Price"); BusinessInfo[BusinessID][bPrice] = strval(bsavingstring);
			mysql_fetch_field_row(bsavingstring, "VirtualWorld"); BusinessInfo[BusinessID][bVirtualWorld] = strval(bsavingstring);
			mysql_fetch_field_row(bsavingstring, "Owned"); BusinessInfo[BusinessID][bOwned] = strval(bsavingstring);
			mysql_fetch_field_row(bsavingstring, "Locked"); BusinessInfo[BusinessID][bLocked] = strval(bsavingstring);
			mysql_fetch_field_row(bsavingstring, "Money"); BusinessInfo[BusinessID][bMoney] = strval(bsavingstring);
			if(BusinessInfo[BusinessID][bOwned] == 1)
			{
 				format(bstring, sizeof(bstring), "Owner: %s\nBusiness ID: %d", BusinessInfo[BusinessID][bOwner], BusinessID);
			    BusinessInfo[BusinessID][bLabel] = Create3DTextLabel(bstring, 0x21DD00FF, BusinessInfo[BusinessID][bEnterX], BusinessInfo[BusinessID][bEnterY], BusinessInfo[BusinessID][bEnterZ], 40.0, 0);
                BusinessInfo[BusinessID][bPickup] = CreatePickup(1239, 23, BusinessInfo[BusinessID][bEnterX], BusinessInfo[BusinessID][bEnterY], BusinessInfo[BusinessID][bEnterZ], 0);
			}
			else
			{
			    format(bstring, sizeof(bstring), "For sale!\nPrice: %d\nBusiness ID: %d\nType /buybusiness to buy business!", Price, BusinessID);
			    BusinessInfo[BusinessID][bLabel] = Create3DTextLabel(bstring, 0x21DD00FF, BusinessInfo[BusinessID][bEnterX], BusinessInfo[BusinessID][bEnterY], BusinessInfo[BusinessID][bEnterZ], 40.0, 0);
                BusinessInfo[BusinessID][bPickup] = CreatePickup(1272, 23, BusinessInfo[BusinessID][bEnterX], BusinessInfo[BusinessID][bEnterY], BusinessInfo[BusinessID][bEnterZ], 0);
			}
  		}
	}
    mysql_free_result();
	Iter_Add(Business, BusinessID);
	BusinessID++;
	if(BusinessID > MAX_BUSINESS)
	{
		print("You reached maximum number of houses! Please enlarge the #define MAX_HOUSES\nPlease Contact Management!");
	}
	return 1;
}

/*

 • Function: GetBusinessUser(businessid)
 • Usage: Getting name of user of specific business!
 • Parameters:
        businessid: ID of business that you want to get user (owner)
 • Example: format(string, sizeof(string), "Business user of business id %d is %s", businessid, GetHouseUser(businessid));

*/

stock GetBusinessUser(businessid)
{
	new bowner1[24];
	format(bowner1, sizeof(bowner1), "%s", BusinessInfo[businessid][bOwner]);
	return bowner1;
}



/*

 • Function: GetBusinessEnterPos(houseid)
 • Usage: Getting the enter position (XYZ) of specific business!
 • Parameters:
        businessid: ID of business that you want to get enter position
 • Example: format(string, sizeof(string), "Business enter XYZ of business id %d is %s", businessid, GetBusinessEnterPos(businessid));

*/

stock GetBusinessEnterPos(businessid)
{
    new getxyz1[128];
    format(getxyz1, sizeof(getxyz1), "%f, %f, %f", BusinessInfo[businessid][bEnterX], BusinessInfo[businessid][bEnterY], BusinessInfo[businessid][bEnterZ]);
    return getxyz1;
}



/*

  • Function: GetBusinessExitPos(houseid)
 • Usage: Getting the exit position (XYZ) of specific business!
 • Parameters:
        businessid: ID of business that you want to get exit position
 • Example: format(string, sizeof(string), "Business exit XYZ of business id %d is %s", businessid, GetBusinessExitPos(businessid));

*/

stock GetBusinessExitPos(businessid)
{
    new getxyz[128];
    format(getxyz, sizeof(getxyz), "%f, %f, %f", BusinessInfo[businessid][bExitX], BusinessInfo[businessid][bExitY], BusinessInfo[businessid][bExitZ]);
    return getxyz;
}



/*

 • Function: GetBusinessEnterX(businessid)
 • Usage: Getting the enter X position of specific business!
 • Parameters:
        businessid: ID of business that you want to get enter X position
 • Example: format(string, sizeof(string), "Business enter X of business id %d is %s", businessid, GetBusinessEnterX(businessid));

*/

stock GetBusinessEnterX(businessid)
{
    new getx1[128];
    format(getx1, sizeof(getx1), "%f", BusinessInfo[businessid][bEnterX]);
    return getx1;
}



/*

 • Function: GetBusinessEnterY(businessid)
 • Usage: Getting the enter Y position of specific business!
 • Parameters:
        businessid: ID of business that you want to get enter Y position
 • Example: format(string, sizeof(string), "Business enter Y of business id %d is %s", businessid, GetBusinessEnterY(businessid));

*/

stock GetBusinessEnterY(businessid)
{
    new gety1[128];
    format(gety1, sizeof(gety1), "%f", BusinessInfo[businessid][bEnterY]);
    return gety1;
}



/*

 • Function: GetBusinessEnterZ(businessid)
 • Usage: Getting the enter Z position of specific business!
 • Parameters:
        businessid: ID of business that you want to get enter Z position
 • Example: format(string, sizeof(string), "Business enter Z of business id %d is %s", businessid, GetBusinessEnterZ(businessid));

*/

stock GetBusinessEnterZ(businessid)
{
    new getz1[128];
    format(getz1, sizeof(getz1), "%f", BusinessInfo[businessid][bEnterZ]);
    return getz1;
}



/*

 • Function: GetBusinessExitX(businessid)
 • Usage: Getting the exit X position of specific business!
 • Parameters:
        businessid: ID of business that you want to get exit X position
 • Example: format(string, sizeof(string), "Business exit X of business id %d is %s", businessid, GetBusinessExitX(businessid));

*/

stock GetBusinessExitX(businessid)
{
    new getx1[128];
    format(getx1, sizeof(getx1), "%f", BusinessInfo[businessid][bExitX]);
    return getx1;
}



/*

 • Function: GetBusinessExitY(businessid)
 • Usage: Getting the exit Y position of specific business!
 • Parameters:
        businessid: ID of business that you want to get exit Y position
 • Example: format(string, sizeof(string), "Business exit Y of business id %d is %s", businessid, GetBusinessExitY(businessid));

*/

stock GetBusinessExitY(businessid)
{
    new gety1[128];
    format(gety1, sizeof(gety1), "%f", BusinessInfo[businessid][bExitY]);
    return gety1;
}



/*

 • Function: GetBusinessExitZ(businessid)
 • Usage: Getting the exit Z position of specific business!
 • Parameters:
        businessid: ID of business that you want to get exit Z position
 • Example: format(string, sizeof(string), "Business exit Z of business id %d is %s", businessid, GetBusinessExitZ(businessid));

*/

stock GetBusinessExitZ(businessid)
{
    new getz1[128];
    format(getz1, sizeof(getz1), "%f", BusinessInfo[businessid][bExitZ]);
    return getz1;
}



/*

 • Function: GetBusinessPrice(businessid)
 • Usage: Getting the price of specific business!
 • Parameters:
        businessid: ID of business that you want to get price
 • Example: format(string, sizeof(string), "Business price of business id %d is %s", businessid, GetBusinessPrice(businessid));

*/

stock GetBusinessPrice(businessid) return BusinessInfo[businessid][bPrice];



/*

 • Function: GetBusinessInterior(businessid)
 • Usage: Getting the interior of specific business!
 • Parameters:
        businessid: ID of business that you want to get interior
 • Example: format(string, sizeof(string), "Business interior of business id %d is %s", businessid, GetBusinessInterior(businessid));

*/

stock GetBusinessInterior(businessid) return BusinessInfo[businessid][bInterior];



/*

 • Function: GetBusinessVirtualWorld(businessid)
 • Usage: Getting the virtualworld of specific business!
 • Parameters:
        businessid: ID of business that you want to get virtualworld
 • Example: format(string, sizeof(string), "Business virtualworld of business id %d is %s", businessid, GetBusinessVirtualWorld(businessid));

*/

stock GetBusinessVirtualWorld(businessid) return BusinessInfo[businessid][bVirtualWorld];



/*

 • Function: GetBusinessMoney(businessid)
 • Usage: Getting the money of specific business!
 • Parameters:
        businessid: ID of business that you want to get money
 • Example: format(string, sizeof(string), "Business money of business id %d is %s", businessid, GetBusinessMoney(businessid));

*/

stock GetBusinessMoney(businessid) return BusinessInfo[businessid][bMoney];



/*

 • Function: GetTotalBusiness(businessid)
 • Usage: Getting the total business, use this in OnGameModeInit after all business!
 • Example: printf("Total business: %d", GetTotalBusiness());

*/

stock GetTotalBusiness() return Iter_Count(Business);



/*

 • Function: IsBusinessOwned(businessid)
 • Usage: Checking if is bussines owned of specific business!
 • Parameters:
        businessid: ID of business that you want to check if is owned
 • Example: if(IsBusinessOwned(businessid)) SendClientMessage(playerid, -1, "Business is owned!");
            else SendClientMessage(palyerid, -1, "Business is not owned!");

*/

stock IsBusinessOwned(businessid)
{
	if(BusinessInfo[businessid][bOwned] == 1) return 1;
	else return 0;
}



/*

 • Function: IsBusinessLocked(businessid)
 • Usage: Checking if is business locked of specific business!
 • Parameters:
        businessid: ID of business that you want to check if is locked
 • Example: if(IsBusinessOwned(businessid)) SendClientMessage(playerid, -1, "Business is locked!");
            else SendClientMessage(palyerid, -1, "Business is not locked!");

*/

stock IsBusinessLocked(businessid)
{
	if(BusinessInfo[businessid][bLocked] == 1) return 1;
	else return 0;
}



/*

 • Function: IsBusinessExist(businessid)
 • Usage: Checking if is exist of specific business!
 • Parameters:
        businessid: ID of business that you want to check if is exist
 • Example: if(IsBusinessExist(businessid)) SendClientMessage(playerid, -1, "Business exist!");
            else SendClientMessage(palyerid, -1, "Business doesn't exist!");

*/

stock IsBusinessExist(businessid)
{
	format(BQuery, sizeof(BQuery), "SELECT BusinessID FROM `business` WHERE `BusinessID` = %d", businessid);
	mysql_query(BQuery);
	mysql_store_result();
	if(mysql_num_rows() == 1)
	{
	    mysql_free_result();
	    return 1;
	}
	else
	{
 		mysql_free_result();
		return 0;
	}
}

/*

 • Function: IsPlayerBuyBusiness(playerid, businessid)
 • Usage: Checking if is player buyed business (used when you try to buy business but you already have house)!
 • Parameters:
        playerid: ID of player that you want preform check
        businessid: ID of business that you want to check if is player buy business
 • Example: if(IsPlayerBuyBusiness(playerid, businessid)) return SendClientMessage(playerid, -1, "You buy this business already!");
	        else SendClientMessage(playerid, -1, "You didn't buy this business!");

*/

stock IsPlayerBuyBusiness(playerid, businessid)
{
	format(BQuery, sizeof(BQuery), "SELECT User FROM `business` WHERE `User` = '%s' AND `BusinessID` = %d", GetName(playerid), businessid);
	mysql_query(BQuery);
	mysql_store_result();
	if(mysql_num_rows() == 1)
	{
		mysql_free_result();
		return 1;
	}
	else
	{
		mysql_free_result();
		return 0;
	}
}

/*

 • Function: IsPlayerBuyBusiness(playerid, businessid)
 • Usage: Checking if is player buyed any business!
 • Parameters:
        playerid: ID of player that you want preform check
 • Example: if(IsPlayerBuyAnyBusiness(playerid)) return SendClientMessage(playerid, -1, "You buy any business already!");
	        else SendClientMessage(playerid, -1, "You didn't buy any business!");

*/

stock IsPlayerBuyAnyBusiness(playerid)
{
	format(BQuery, sizeof(BQuery), "SELECT User FROM `business` WHERE `User` = '%s'", GetName(playerid));
	mysql_query(BQuery);
	mysql_store_result();
	if(mysql_num_rows() == 1)
	{
		mysql_free_result();
		return 1;
	}
	else
	{
		mysql_free_result();
		return 0;
	}
}

/*

 • Function: IsPlayerBusinessOwner(playerid, businessid)
 • Usage: Checking if is player owner of specific business!
 • Parameters:
        playerid: ID of player that you want preform check
        businessid: ID of vusiness that you want to check if is player owner
 • Example: if(IsPlayerBusinessOwner(playerid, businessid)) return SendClientMessage(playerid, -1, "You are owner of the business!");
	        else SendClientMessage(playerid, -1, "You are not owner of the business!");

*/

stock IsPlayerBusinessOwner(playerid, businessid)
{
	if(!strcmp(BusinessInfo[businessid][bOwner], GetName(playerid), false)) return 1;
	else return 0;
}

//----Stocks for easier scripting!----
/*stock GetName(playerid)
{
	new pName[MAX_PLAYER_NAME];
	GetPlayerName(playerid, pName, MAX_PLAYER_NAME);
	return pName;
}*/
//----End of stocks!----


//*****************************          *****************************
//***************************** COMMANDS *****************************
//*****************************          *****************************



/*

 • Command: /buyhouse
 • Processor: y_commands (YCMD)
 • Usage: Buying business (Player must be in range of business he want to buy!)

*/

YCMD:buybusiness(playerid, params[], help)
{
	#pragma unused help
	#pragma unused params
    foreach(business, i)
    {
        if(IsPlayerInRangeOfPoint(playerid, 3.0, BusinessInfo[i][bEnterX], BusinessInfo[i][bEnterY], BusinessInfo[i][bEnterZ]))
        {
            if(BusinessInfo[i][bOwned] == 1) return SendClientMessage(playerid, COLOR_KRED, "Business is already owned!");
            if(GetPlayerMoney(playerid) < BusinessInfo[i][bPrice]) return SendClientMessage(playerid, COLOR_KRED, "You don't have enough money!");

			new BQuery2[200];
			format(BQuery2, sizeof(BQuery2), "SELECT User FROM `business` WHERE `User` = '%s'", GetName(playerid));
			mysql_query(BQuery2);
			mysql_store_result();
			if(mysql_num_rows() == 1) return SendClientMessage(playerid, COLOR_KRED, "You have business already!");
			mysql_free_result();

			format(BusinessInfo[i][bOwner], 24, "%s", GetName(playerid));
			BusinessInfo[i][bOwned] = 1;
			DestroyPickup(BusinessInfo[i][bPickup]);
			BusinessInfo[i][bPickup] = CreatePickup(1239, 23, BusinessInfo[i][bEnterX], BusinessInfo[i][bEnterY], BusinessInfo[i][bEnterZ], 0);
			format(bstring, sizeof(bstring), "Owner: %s\nBusiness ID: %d", BusinessInfo[i][bOwner], i);
			Update3DTextLabelText(BusinessInfo[i][bLabel], 0x21DD00FF, bstring);
			GivePlayerMoney(playerid, -BusinessInfo[i][bPrice]);
			SendClientMessage(playerid, COLOR_LIME, "Business bought!");

 			format(BQuery, sizeof(BQuery), "UPDATE `business` SET `User` = '%s', `Owned` = 1 WHERE `BusinessID` = %d", GetName(playerid), i);
			mysql_query(BQuery);
		}
	}
	return 1;
}

/*

 • Command: /sellbusiness
 • Processor: y_commands (YCMD)
 • Usage: Selling business (Player must be in range of business he want to sell!)

*/

YCMD:sellbusiness(playerid, params[], help)
{
	#pragma unused help
	#pragma unused params
	foreach(Business, i)
	{
	    if(IsPlayerInRangeOfPoint(playerid, 3.0, BusinessInfo[i][bEnterX], BusinessInfo[i][bEnterY], BusinessInfo[i][bEnterZ]))
        {
         	if(!strcmp(BusinessInfo[i][bOwner], GetName(playerid), false))
	        {
                format(BusinessInfo[i][bOwner], 24, "None");
				BusinessInfo[i][bOwned] = 0;
				BusinessInfo[i][bLocked] = 0;
		 		DestroyPickup(BusinessInfo[i][bPickup]);
				BusinessInfo[i][bPickup] = CreatePickup(1272, 23, BusinessInfo[i][bEnterX], BusinessInfo[i][bEnterY], BusinessInfo[i][bEnterZ], 0);
				format(bstring, sizeof(bstring), "For sale!\nPrice: %d\nBusiness ID: %d\nType /buybusiness to buy business!", BusinessInfo[i][bPrice], i);
				Update3DTextLabelText(BusinessInfo[i][bLabel], 0x21DD00FF, bstring);
				GivePlayerMoney(playerid, BusinessInfo[i][bPrice]);
				SendClientMessage(playerid, COLOR_LIME, "Business sold!");

				format(BQuery, sizeof(BQuery), "UPDATE `business` SET `User` = 'None', `Owned` = 0, `Locked` = 0 WHERE `BusinessID` = %d", i);
				mysql_query(BQuery);
			}
		}
	}
	return 1;
}

/*

 • Command: /lockbusiness
 • Processor: y_commands (YCMD)
 • Usage: Locking business (Player must be in range of his business to lock it!)

*/

YCMD:lockbusiness(playerid, params[], help)
{
	#pragma unused help
	#pragma unused params
	foreach(Business, i)
	{
	    if(IsPlayerInRangeOfPoint(playerid, 3.0, BusinessInfo[i][bEnterX], BusinessInfo[i][bEnterY], BusinessInfo[i][bEnterZ]) || IsPlayerInRangeOfPoint(playerid, 3.0, BusinessInfo[i][bExitX], BusinessInfo[i][bExitY], BusinessInfo[i][bExitZ]))
        {
		    if(!strcmp(BusinessInfo[i][bOwner], GetName(playerid), false))
		    {
				BusinessInfo[i][bLocked] = 1;
			 	GameTextForPlayer(playerid, "Business ~r~locked!", 2000, 5);

				format(BQuery, sizeof(BQuery), "UPDATE `business` SET `Locked` = 1 WHERE `BusinessID` = %d", i);
				mysql_query(BQuery);
			}
		}
	}
	return 1;
}

/*

 • Command: /unlockbusiness
 • Processor: y_commands (YCMD)
 • Usage: Unlocking business (Player must be in range of his business to unlock it!)

*/

YCMD:unlockbusiness(playerid, params[], help)
{
	#pragma unused help
	#pragma unused params
	foreach(Business, i)
	{
	    if(IsPlayerInRangeOfPoint(playerid, 3.0, BusinessInfo[i][bEnterX], BusinessInfo[i][bEnterY], BusinessInfo[i][bEnterZ]) || IsPlayerInRangeOfPoint(playerid, 3.0, BusinessInfo[i][bExitX], BusinessInfo[i][bExitY], BusinessInfo[i][bExitZ]))
        {
		    if(!strcmp(BusinessInfo[i][bOwner], GetName(playerid), false))
		    {
				BusinessInfo[i][bLocked] = 0;
			 	GameTextForPlayer(playerid, "Business ~g~unlocked!", 2000, 5);

				format(BQuery, sizeof(BQuery), "UPDATE `business` SET `Locked` = 0 WHERE `BusinessID` = %d", i);
				mysql_query(BQuery);
			}
		}
	}
	return 1;
}

/*

 • Command: /businesscontrol
 • Processor: y_commands (YCMD)
 • Usage: Controling your business: lock business, unlock business, storing money in business, taking money from business (Player must be in his house to control it!)

*/

YCMD:businesscontrol(playerid, params[], help)
{
	#pragma unused help
	#pragma unused params
    foreach(Business, i)
	{
        if(IsPlayerInRangeOfPoint(playerid, 20.0, BusinessInfo[i][bExitX], BusinessInfo[i][bExitY], BusinessInfo[i][bExitZ]))
        {
			if(!strcmp(BusinessInfo[i][bOwner], GetName(playerid), false))
			{
				if(PlayerEnteredHisBusiness[playerid] == true)
				{
					ShowPlayerDialog(playerid, 6560, DIALOG_STYLE_LIST, "   Control your business!", "Lock business\nUnlock business\nStore money\nTake money", "Ok", "Exit");
				}
				else SendClientMessage(playerid, COLOR_KRED, "You must enter your business!");
			}
		}
	}
	return 1;
}


public PaymentUp()
{
	foreach(Business, i)
	{
		new BQuery2[200];
		format(BQuery2, sizeof(BQuery2), "SELECT BusinessID FROM `business` WHERE `BusinessID` = '%d'", i);
		mysql_query(BQuery2);
		mysql_store_result();
		if(mysql_num_rows() == 1)
		{
		    if(BusinessInfo[i][bOwned] == 1)
		    {
			    BusinessInfo[i][bMoney] += BUSINES_PAYMENT;
			    format(BQuery, sizeof(BQuery), "UPDATE `business` SET `Money` = %d WHERE `BusinessID` = %d", BusinessInfo[i][bMoney], i);
			    mysql_query(BQuery);
		    }
		}
		mysql_free_result();
	}
	return 1;
}


//*****************************           *****************************
//***************************** CALLBACKS *****************************
//*****************************           *****************************



/*

 • Callback: OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])  (Hooked using y_hook)
 • Action: Dialogs for house controling, later will be more for dynamic creating house!

*/

Hook:B1_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case 6560:
		{
		    if(!response) return 0;
		    switch(listitem)
		    {
		        case 0:
		        {
			     	foreach(Business, i)
					{
					    if(IsPlayerInRangeOfPoint(playerid, 20.0, BusinessInfo[i][bExitX], BusinessInfo[i][bExitY], BusinessInfo[i][bExitZ]))
				        {
						    if(!strcmp(BusinessInfo[i][bOwner], GetName(playerid), false))
						    {
								BusinessInfo[i][bLocked] = 1;
							 	GameTextForPlayer(playerid, "Business ~r~locked!", 2000, 5);
							 	ShowPlayerDialog(playerid, 6560, DIALOG_STYLE_LIST, "   Control your business!", "Lock business\nUnlock business\nStore money\nTake money", "Ok", "Exit");

								format(BQuery, sizeof(BQuery), "UPDATE `business` SET `Locked` = 1 WHERE `BusinessID` = %d", i);
								mysql_query(BQuery);
							}
						}
					}
		        }
	    	    case 1:
		        {
			     	foreach(Business, i)
					{
					    if(IsPlayerInRangeOfPoint(playerid, 20.0, BusinessInfo[i][bExitX], BusinessInfo[i][bExitY], BusinessInfo[i][bExitZ]))
				        {
						    if(!strcmp(BusinessInfo[i][bOwner], GetName(playerid), false))
						    {
								BusinessInfo[i][bLocked] = 0;
							 	GameTextForPlayer(playerid, "Business ~g~unlocked!", 2000, 5);
							 	ShowPlayerDialog(playerid, 6560, DIALOG_STYLE_LIST, "   Control your business!", "Lock business\nUnlock business\nStore money\nTake money", "Ok", "Exit");

								format(BQuery, sizeof(BQuery), "UPDATE `business` SET `Locked` = 0 WHERE `BusinessID` = %d", i);
								mysql_query(BQuery);
							}
						}
					}
		        }
		        case 2:
		        {
			     	foreach(Business, i)
					{
					    if(IsPlayerInRangeOfPoint(playerid, 20.0, BusinessInfo[i][bExitX], BusinessInfo[i][bExitY], BusinessInfo[i][bExitZ]))
				        {
						    if(!strcmp(BusinessInfo[i][bOwner], GetName(playerid), false))
						    {
						        format(bstring, sizeof(bstring), "Current stored money: %d\n\nType ammount of money that you want to store", BusinessInfo[i][bMoney]);
						        ShowPlayerDialog(playerid, 6561, DIALOG_STYLE_INPUT, "   Store money", bstring, "Ok", "Exit");
						    }
						}
					}
		        }
     		    case 3:
		        {
			     	foreach(Business, i)
					{
					    if(IsPlayerInRangeOfPoint(playerid, 20.0, BusinessInfo[i][bExitX], BusinessInfo[i][bExitY], BusinessInfo[i][bExitZ]))
				        {
						    if(!strcmp(BusinessInfo[i][bOwner], GetName(playerid), false))
						    {
						        format(bstring, sizeof(bstring), "Current stored money: %d\n\nType ammount of money that you want to take", BusinessInfo[i][bMoney]);
						        ShowPlayerDialog(playerid, 6562, DIALOG_STYLE_INPUT, "   Store money", bstring, "Ok", "Exit");
						    }
						}
					}
		        }
		    }
	    }
	    case 6561:
	    {
		    if(!response) return ShowPlayerDialog(playerid, 6560, DIALOG_STYLE_LIST, "   Control your business!", "Lock business\nUnlock business\nStore money\nTake money", "Ok", "Exit");
       		foreach(Business, i)
			{
	            if(IsPlayerInRangeOfPoint(playerid, 20.0, BusinessInfo[i][bExitX], BusinessInfo[i][bExitY], BusinessInfo[i][bExitZ]))
	            {
	            	if(!strcmp(BusinessInfo[i][bOwner], GetName(playerid), false))
					{
						new moneystring1[128];
						format(moneystring1, sizeof(moneystring1), "Current stored money: %d\n\nType ammount of money that you want to store", BusinessInfo[i][bMoney]);
						if(!strlen(inputtext)) return ShowPlayerDialog(playerid, 6561, DIALOG_STYLE_INPUT, "   Store money", bstring, "Ok", "Exit");
						if(GetPlayerMoney(playerid) < strval(inputtext))
						{
							SendClientMessage(playerid, COLOR_KRED, "You don't have enoguh money to store!");
							ShowPlayerDialog(playerid, 6561, DIALOG_STYLE_INPUT, "   Store money", bstring, "Ok", "Exit");
							return 1;
						}
						if(strval(inputtext) > 10000000)
						{
							SendClientMessage(playerid, COLOR_KRED, "You can store maximum 10000000!");
							ShowPlayerDialog(playerid, 6561, DIALOG_STYLE_INPUT, "   Store money", bstring, "Ok", "Exit");
							return 1;
						}
						BusinessInfo[i][bMoney] += strval(inputtext);
						GivePlayerMoney(playerid, -strval(inputtext));
						format(bstring, sizeof(bstring), "You store %d$! Current stored money: %d", strval(inputtext), BusinessInfo[i][bMoney]);
						SendClientMessage(playerid, COLOR_YELLOW, bstring);
						ShowPlayerDialog(playerid, 6560, DIALOG_STYLE_LIST, "   Control your business!", "Lock business\nUnlock business\nStore money\nTake money", "Ok", "Exit");

			           	format(BQuery, sizeof(BQuery), "UPDATE `business` SET `Money` = %d WHERE `BusinessID` = %d", BusinessInfo[i][bMoney], i);
						mysql_query(BQuery);
					}
				}
			}
	    }
	    case 6562:
	    {
		    if(!response) return ShowPlayerDialog(playerid, 6560, DIALOG_STYLE_LIST, "   Control your business!", "Lock business\nUnlock business\nStore money\nTake money", "Ok", "Exit");
       		foreach(Business, i)
			{
	            if(IsPlayerInRangeOfPoint(playerid, 20.0, BusinessInfo[i][bExitX], BusinessInfo[i][bExitY], BusinessInfo[i][bExitZ]))
	            {
	            	if(!strcmp(BusinessInfo[i][bOwner], GetName(playerid), false))
					{
						new moneystring1[128];
						format(moneystring1, sizeof(moneystring1), "Current stored money: %d\n\nType ammount of money that you want to store", BusinessInfo[i][bMoney]);
						if(!strlen(inputtext)) return ShowPlayerDialog(playerid, 6561, DIALOG_STYLE_INPUT, "   Store money", bstring, "Ok", "Exit");
						if(strval(inputtext) > BusinessInfo[i][bMoney])
						{
						    SendClientMessage(playerid, COLOR_KRED, "Business doesn't have so much money!");
						    ShowPlayerDialog(playerid, 6562, DIALOG_STYLE_INPUT, "   Store money", bstring, "Ok", "Exit");
						    return 1;
						}
						BusinessInfo[i][bMoney] -= strval(inputtext);
						GivePlayerMoney(playerid, strval(inputtext));
						format(bstring, sizeof(bstring), "You take %d$! Current stored money: %d", strval(inputtext), BusinessInfo[i][bMoney]);
						SendClientMessage(playerid, COLOR_YELLOW, bstring);
						ShowPlayerDialog(playerid, 6560, DIALOG_STYLE_LIST, "   Control your business!", "Lock business\nUnlock business\nStore money\nTake money", "Ok", "Exit");

			           	format(BQuery, sizeof(BQuery), "UPDATE `business` SET `Money` = %d WHERE `BusinessID` = %d", BusinessInfo[i][bMoney], i);
						mysql_query(BQuery);
					}
				}
			}
	    }
	}
	return 1;
}

/*

 • Callback: OnPlayerKeyStateChange(playerid, newkeys, oldkeys)  (Hooked using y_hook)
 • Action: Player can enter house (If is not locked!) using F or Enter (by default in GTA:SA)

*/

Hook:B2_OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(newkeys & KEY_SECONDARY_ATTACK && !IsPlayerInAnyVehicle(playerid))
    {
        foreach(Business, i)
        {
            if(IsPlayerInRangeOfPoint(playerid, 3.0, BusinessInfo[i][bEnterX], BusinessInfo[i][bEnterY], BusinessInfo[i][bEnterZ]))
            {
                if(BusinessInfo[i][bLocked] == 0)
                {
                    if(!strcmp(BusinessInfo[i][bOwner], GetName(playerid), false))
		    		{
		    		    PlayerEnteredHisBusiness[playerid] = true;
		    		}
	            	SetPlayerInterior(playerid, BusinessInfo[i][bInterior]);
	                SetPlayerVirtualWorld(playerid, BusinessInfo[i][bVirtualWorld]);
	                SetPlayerPos(playerid, BusinessInfo[i][bExitX], BusinessInfo[i][bExitY], BusinessInfo[i][bExitZ]);
					return CallLocalFunction("OnPlayerEnterBusiness", "dd", playerid, i);
				}
				else SendClientMessage(playerid, COLOR_KRED, "Business is locked!");
            }
            else if(IsPlayerInRangeOfPoint(playerid, 3.0, BusinessInfo[i][bExitX], BusinessInfo[i][bExitY], BusinessInfo[i][bExitZ]) && GetPlayerInterior(playerid) == BusinessInfo[i][bInterior] && GetPlayerVirtualWorld(playerid) == BusinessInfo[i][bVirtualWorld])
            {
                if(BusinessInfo[i][bLocked] == 0)
                {
                    if(!strcmp(BusinessInfo[i][bOwner], GetName(playerid), false))
		    		{
		    		    PlayerEnteredHisBusiness[playerid] = false;
		    		}
	            	SetPlayerInterior(playerid, 0);
	                SetPlayerVirtualWorld(playerid, 0);
	                SetPlayerPos(playerid, BusinessInfo[i][bEnterX], BusinessInfo[i][bEnterY], BusinessInfo[i][bEnterZ]);
	                return CallLocalFunction("OnPlayerExitBusiness", "dd", playerid, i);
    			}
				else SendClientMessage(playerid, COLOR_KRED, "Business is locked!");
            }
        }
    }
    return 1;
}

Hook:B3_OnGameModeInit()
{
	PaymentTimer = SetTimer("PaymentUp", 3600000, 1);
	return 1;
}

Hook:B4_OnGameModeExit()
{
	KillTimer(PaymentTimer);
	return 1;
}

Hook:B5_OnPlayerConnect(playerid)
{
	new credits1[128];
	format(credits1, sizeof(credits1), "This server use S32_Business %s by System32!", business_version);
	SendClientMessage(playerid, COLOR_LIME, credits1);
	
	PlayerEnteredHisBusiness[playerid] = false;
	return 1;
}

Hook:B6_OnPlayerDisconnect(playerid)
{
	PlayerEnteredHisBusiness[playerid] = false;
	return 1;
}
