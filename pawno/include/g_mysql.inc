/*

	 		/$$   /$$  /$$$$$$          /$$$$$$$  /$$$$$$$
			| $$$ | $$ /$$__  $$        | $$__  $$| $$__  $$
			| $$$$| $$| $$  \__/        | $$  \ $$| $$  \ $$
			| $$ $$ $$| $$ /$$$$ /$$$$$$| $$$$$$$/| $$$$$$$/
			| $$  $$$$| $$|_  $$|______/| $$__  $$| $$____/
			| $$\  $$$| $$  \ $$        | $$  \ $$| $$
			| $$ \  $$|  $$$$$$/        | $$  | $$| $$
			|__/  \__/ \______/         |__/  |__/|__/

					  Next Generation Role Play
		(created by Next Generation Gaming Development Team)

		Combined:
		(***) GhoulSlayeR

		Developed to be included with NG-RP Gamemode, it will not run on it's own accord. 
*/

#include <a_mysql>

// MySQL Configuration
#define SQL_HOST "localhost"
#define SQL_DB "ngrp"
#define SQL_USER "ngrp"
#define SQL_PASS "w3J7CyfLfWYm2XXc"

// Threads
#define NO_THREAD -1
#define LOADUSERDATA_THREAD 1
#define SENDUSERDATA_THREAD 2
#define LOGIN_THREAD 3

new MainPipeline;

// Callbacks
public OnQueryFinish(query[], resultid, extraid, connectionHandle)
{
	switch(resultid)
	{
		case LOADUSERDATA_THREAD:
		{
			new string[256];
			mysql_store_result(MainPipeline);
			
			if(mysql_retrieve_row())
			{	
				mysql_fetch_field_row(PlayerInfo[extraid][pIP], "IP", MainPipeline);
				mysql_fetch_field_row(string, "ConnectedTime", MainPipeline); PlayerInfo[extraid][pConnectTime] = strval(string);
				mysql_fetch_field_row(string, "Sex", MainPipeline); PlayerInfo[extraid][pSex] = strval(string);
				mysql_fetch_field_row(string, "Band", MainPipeline); PlayerInfo[extraid][pBanned] = strval(string);
				mysql_fetch_field_row(string, "PermBand", MainPipeline); PlayerInfo[extraid][pPermaBanned] = strval(string);
				mysql_fetch_field_row(string, "Warnings", MainPipeline); PlayerInfo[extraid][pWarns] = strval(string);
				mysql_fetch_field_row(string, "Disabled", MainPipeline); PlayerInfo[extraid][pDisabled] = strval(string);
				mysql_fetch_field_row(string, "Level", MainPipeline); PlayerInfo[extraid][pLevel] = strval(string);
				mysql_fetch_field_row(string, "AdminLevel", MainPipeline); PlayerInfo[extraid][pAdmin] = strval(string);
				mysql_fetch_field_row(string, "DonateRank", MainPipeline); PlayerInfo[extraid][pDonateRank] = strval(string);
				mysql_fetch_field_row(string, "Respect", MainPipeline); PlayerInfo[extraid][pExp] = strval(string);
				mysql_fetch_field_row(string, "Money", MainPipeline); SetPVarInt(extraid, "Cash", strval(string));
				mysql_fetch_field_row(string, "Bank", MainPipeline); PlayerInfo[extraid][pAccount] = strval(string);
				mysql_fetch_field_row(string, "pHealth", MainPipeline); PlayerInfo[extraid][pHealth] = floatstr(string);
				mysql_fetch_field_row(string, "pArmor", MainPipeline); PlayerInfo[extraid][pArmor] = floatstr(string);
				mysql_fetch_field_row(string, "pSHealth", MainPipeline); PlayerInfo[extraid][pSHealth] = floatstr(string);
				mysql_fetch_field_row(string, "Int", MainPipeline); PlayerInfo[extraid][pInt] = strval(string);
				mysql_fetch_field_row(string, "Local", MainPipeline); PlayerInfo[extraid][pLocal] = strval(string);
				mysql_fetch_field_row(string, "VirtualWorld", MainPipeline); PlayerInfo[extraid][pVW] = strval(string);
				mysql_fetch_field_row(string, "Model", MainPipeline); PlayerInfo[extraid][pModel] = strval(string);
				mysql_fetch_field_row(string, "SPos_x", MainPipeline); PlayerInfo[extraid][pPos_x] = floatstr(string);
				mysql_fetch_field_row(string, "SPos_y", MainPipeline); PlayerInfo[extraid][pPos_y] = floatstr(string);
				mysql_fetch_field_row(string, "SPos_z", MainPipeline); PlayerInfo[extraid][pPos_z] = floatstr(string);
				mysql_fetch_field_row(string, "SPos_r", MainPipeline); PlayerInfo[extraid][pPos_r] = floatstr(string);
				mysql_fetch_field_row(string, "BanAppealer", MainPipeline); PlayerInfo[extraid][pBanAppealer] = strval(string);
				mysql_fetch_field_row(string, "ShopTech", MainPipeline); PlayerInfo[extraid][pShopTech] = strval(string);
				mysql_fetch_field_row(string, "Undercover", MainPipeline); PlayerInfo[extraid][pUndercover] = strval(string);
				mysql_fetch_field_row(string, "TogReports", MainPipeline); PlayerInfo[extraid][pTogReports] = strval(string);
				mysql_fetch_field_row(string, "Radio", MainPipeline); PlayerInfo[extraid][pRadio] = strval(string);
				mysql_fetch_field_row(string, "RadioFreq", MainPipeline); PlayerInfo[extraid][pRadioFreq] = strval(string);
				mysql_fetch_field_row(string, "UpgradePoints", MainPipeline); PlayerInfo[extraid][gPupgrade] = strval(string);
				mysql_fetch_field_row(string, "Origin", MainPipeline); PlayerInfo[extraid][pOrigin] = strval(string);
				mysql_fetch_field_row(string, "Muted", MainPipeline); PlayerInfo[extraid][pMuted] = strval(string);
				mysql_fetch_field_row(string, "Crimes", MainPipeline); PlayerInfo[extraid][pCrimes] = strval(string);
				mysql_fetch_field_row(string, "Accent", MainPipeline); PlayerInfo[extraid][pAccent] = strval(string);
				mysql_fetch_field_row(string, "CHits", MainPipeline); PlayerInfo[extraid][pCHits] = strval(string);
				mysql_fetch_field_row(string, "FHits", MainPipeline); PlayerInfo[extraid][pFHits] = strval(string);
				mysql_fetch_field_row(string, "Arrested", MainPipeline); PlayerInfo[extraid][pArrested] = strval(string);
				mysql_fetch_field_row(string, "Phonebook", MainPipeline); PlayerInfo[extraid][pPhoneBook] = strval(string);
				mysql_fetch_field_row(string, "LottoNr", MainPipeline); PlayerInfo[extraid][pLottoNr] = strval(string);
				mysql_fetch_field_row(string, "Fishes", MainPipeline); PlayerInfo[extraid][pFishes] = strval(string);
				mysql_fetch_field_row(string, "BiggestFish", MainPipeline); PlayerInfo[extraid][pBiggestFish] = strval(string);
				mysql_fetch_field_row(string, "Job", MainPipeline); PlayerInfo[extraid][pJob] = strval(string);
				mysql_fetch_field_row(string, "Job2", MainPipeline); PlayerInfo[extraid][pJob2] = strval(string);
				mysql_fetch_field_row(string, "Paycheck", MainPipeline); PlayerInfo[extraid][pPayCheck] = strval(string);
				mysql_fetch_field_row(string, "HeadValue", MainPipeline); PlayerInfo[extraid][pHeadValue] = strval(string);
				mysql_fetch_field_row(string, "Jailed", MainPipeline); PlayerInfo[extraid][pJailed] = strval(string);
				mysql_fetch_field_row(string, "JailTime", MainPipeline); PlayerInfo[extraid][pJailTime] = strval(string);
				mysql_fetch_field_row(string, "WRestricted", MainPipeline); PlayerInfo[extraid][pWRestricted] = strval(string);
				mysql_fetch_field_row(string, "Materials", MainPipeline); PlayerInfo[extraid][pMats] = strval(string);
				mysql_fetch_field_row(string, "Packages", MainPipeline); SetPVarInt(extraid, "Packages", strval(string));
				mysql_fetch_field_row(string, "Crates", MainPipeline); PlayerInfo[extraid][pCrates] = strval(string);
				mysql_fetch_field_row(string, "Pot", MainPipeline); PlayerInfo[extraid][pPot] = strval(string);
				mysql_fetch_field_row(string, "Crack", MainPipeline); PlayerInfo[extraid][pCrack] = strval(string);
				mysql_fetch_field_row(string, "Leader", MainPipeline); PlayerInfo[extraid][pLeader] = strval(string);
				mysql_fetch_field_row(string, "Member", MainPipeline); PlayerInfo[extraid][pMember] = strval(string);
				mysql_fetch_field_row(string, "Division", MainPipeline); PlayerInfo[extraid][pDivision] = strval(string);
				mysql_fetch_field_row(string, "FMember", MainPipeline); PlayerInfo[extraid][pFMember] = strval(string);
				mysql_fetch_field_row(string, "Rank", MainPipeline); PlayerInfo[extraid][pRank] = strval(string);
				mysql_fetch_field_row(string, "DetSkill", MainPipeline); PlayerInfo[extraid][pDetSkill] = strval(string);
				mysql_fetch_field_row(string, "SexSkill", MainPipeline); PlayerInfo[extraid][pSexSkill] = strval(string);
				mysql_fetch_field_row(string, "BoxSkill", MainPipeline); PlayerInfo[extraid][pBoxSkill] = strval(string);
				mysql_fetch_field_row(string, "LawSkill", MainPipeline); PlayerInfo[extraid][pLawSkill] = strval(string);
				mysql_fetch_field_row(string, "MechSkill", MainPipeline); PlayerInfo[extraid][pMechSkill] = strval(string);
				mysql_fetch_field_row(string, "JackSkill", MainPipeline); PlayerInfo[extraid][pJackSkill] = strval(string);
				mysql_fetch_field_row(string, "CarSkill", MainPipeline); PlayerInfo[extraid][pCarSkill] = strval(string);
				mysql_fetch_field_row(string, "TruckSkill", MainPipeline); PlayerInfo[extraid][pTruckSkill] = strval(string);
				mysql_fetch_field_row(string, "NewsSkill", MainPipeline); PlayerInfo[extraid][pNewsSkill] = strval(string);
				mysql_fetch_field_row(string, "DrugsSkill", MainPipeline); PlayerInfo[extraid][pDrugsSkill] = strval(string);
				mysql_fetch_field_row(string, "ArmsSkill", MainPipeline); PlayerInfo[extraid][pArmsSkill] = strval(string);
				mysql_fetch_field_row(string, "SmugglerSkill", MainPipeline); PlayerInfo[extraid][pSmugSkill] = strval(string);
				mysql_fetch_field_row(string, "FishSkill", MainPipeline); PlayerInfo[extraid][pFishSkill] = strval(string);
				mysql_fetch_field_row(string, "FightingStyle", MainPipeline); PlayerInfo[extraid][pFightStyle] = strval(string);
				mysql_fetch_field_row(string, "HouseInvite", MainPipeline); PlayerInfo[extraid][pHouseInvite] = strval(string);
				mysql_fetch_field_row(string, "Clothes", MainPipeline); PlayerInfo[extraid][pClothes] = strval(string);
				mysql_fetch_field_row(string, "PhoneNr", MainPipeline); PlayerInfo[extraid][pPnumber] = strval(string);
				mysql_fetch_field_row(string, "Apartment", MainPipeline); PlayerInfo[extraid][pPhousekey] = strval(string);
				mysql_fetch_field_row(string, "Apartment2", MainPipeline); PlayerInfo[extraid][pPhousekey2] = strval(string);
				mysql_fetch_field_row(string, "Renting", MainPipeline); PlayerInfo[extraid][pRenting] = strval(string);
				mysql_fetch_field_row(string, "Vehicles", MainPipeline); PlayerInfo[extraid][pVehicles] = strval(string);
				mysql_fetch_field_row(string, "VehFile", MainPipeline); PlayerInfo[extraid][pVehFile] = strval(string);
				mysql_fetch_field_row(string, "VehActive", MainPipeline); PlayerInfo[extraid][pVehActive] = strval(string);
				mysql_fetch_field_row(string, "Type1", MainPipeline); PlayerInfo[extraid][pType1] = strval(string);
				mysql_fetch_field_row(string, "Type2", MainPipeline); PlayerInfo[extraid][pType2] = strval(string);
				mysql_fetch_field_row(string, "Type3", MainPipeline); PlayerInfo[extraid][pType3] = strval(string);
				mysql_fetch_field_row(string, "Type4", MainPipeline); PlayerInfo[extraid][pType4] = strval(string);
				mysql_fetch_field_row(string, "Type5", MainPipeline); PlayerInfo[extraid][pType5] = strval(string);
				mysql_fetch_field_row(string, "CarLic", MainPipeline); PlayerInfo[extraid][pCarLic] = strval(string);
				mysql_fetch_field_row(string, "FlyLic", MainPipeline); PlayerInfo[extraid][pFlyLic] = strval(string);
				mysql_fetch_field_row(string, "BoatLic", MainPipeline); PlayerInfo[extraid][pBoatLic] = strval(string);
				mysql_fetch_field_row(string, "FishLic", MainPipeline); PlayerInfo[extraid][pFishLic] = strval(string);
				mysql_fetch_field_row(string, "CheckCash", MainPipeline); PlayerInfo[extraid][pCheckCash] = strval(string);
				mysql_fetch_field_row(string, "Checks", MainPipeline); PlayerInfo[extraid][pChecks] = strval(string);
				mysql_fetch_field_row(string, "GunLic", MainPipeline); PlayerInfo[extraid][pGunLic] = strval(string);
				
				for(new i = 0; i < 12; i++)
				{
					new gun[32];
					format(gun, sizeof(gun), "Gun%d", i);
					mysql_fetch_field_row(string, gun, MainPipeline);
					PlayerInfo[extraid][pGuns][i] = strval(string);
				}
				
				mysql_fetch_field_row(string, "CarTime", MainPipeline); PlayerInfo[extraid][pCarTime] = strval(string);
				mysql_fetch_field_row(string, "DrugsTime", MainPipeline); PlayerInfo[extraid][pDrugsTime] = strval(string);
				mysql_fetch_field_row(string, "LawyerTime", MainPipeline); PlayerInfo[extraid][pLawyerTime] = strval(string);
				mysql_fetch_field_row(string, "LawyerFreeTime", MainPipeline); PlayerInfo[extraid][pLawyerFreeTime] = strval(string);
				mysql_fetch_field_row(string, "MechTime", MainPipeline); PlayerInfo[extraid][pMechTime] = strval(string);
				mysql_fetch_field_row(string, "SexTime", MainPipeline); PlayerInfo[extraid][pSexTime] = strval(string);
				mysql_fetch_field_row(string, "PayDay", MainPipeline); PlayerInfo[extraid][pPayDay] = strval(string);
				mysql_fetch_field_row(string, "PayDayHad", MainPipeline); PlayerInfo[extraid][pPayDayHad] = strval(string);
				mysql_fetch_field_row(string, "CDPlayer", MainPipeline); PlayerInfo[extraid][pCDPlayer] = strval(string);
				mysql_fetch_field_row(string, "Dice", MainPipeline); PlayerInfo[extraid][pDice] = strval(string);
				mysql_fetch_field_row(string, "Spraycan", MainPipeline); PlayerInfo[extraid][pSpraycan] = strval(string);
				mysql_fetch_field_row(string, "Rope", MainPipeline); PlayerInfo[extraid][pRope] = strval(string);
				mysql_fetch_field_row(string, "Cigars", MainPipeline); PlayerInfo[extraid][pCigar] = strval(string);
				mysql_fetch_field_row(string, "Sprunk", MainPipeline); PlayerInfo[extraid][pSprunk] = strval(string);
				mysql_fetch_field_row(string, "Bombs", MainPipeline); PlayerInfo[extraid][pBombs] = strval(string);
				mysql_fetch_field_row(string, "Wins", MainPipeline); PlayerInfo[extraid][pWins] = strval(string);
				mysql_fetch_field_row(string, "Loses", MainPipeline); PlayerInfo[extraid][pLoses] = strval(string);
				mysql_fetch_field_row(string, "Tutorial", MainPipeline); PlayerInfo[extraid][pTut] = strval(string);
				mysql_fetch_field_row(string, "OnDuty", MainPipeline); PlayerInfo[extraid][pDuty] = strval(string);
				mysql_fetch_field_row(string, "Hospital", MainPipeline); SetPVarInt(extraid, "Hospital", strval(string));
				mysql_fetch_field_row(string, "Adjustable", MainPipeline); PlayerInfo[extraid][pAdjustable] = strval(string);
				mysql_fetch_field_row(string, "Married", MainPipeline); PlayerInfo[extraid][pMarried] = strval(string);
				mysql_fetch_field_row(PlayerInfo[extraid][pMarriedTo], "MarriedTo", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pContractBy], "ContractBy", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pContractDetail], "ContractDetail", MainPipeline);
				mysql_fetch_field_row(string, "WantedLevel", MainPipeline); PlayerInfo[extraid][pWantedLevel] = strval(string);
				mysql_fetch_field_row(string, "Insurance", MainPipeline); PlayerInfo[extraid][pInsurance] = strval(string);
				mysql_fetch_field_row(string, "NewMuted", MainPipeline); PlayerInfo[extraid][pNMute] = strval(string);
				mysql_fetch_field_row(string, "NewMutedTotal", MainPipeline); PlayerInfo[extraid][pNMuteTotal] = strval(string);
				mysql_fetch_field_row(string, "AdMuted", MainPipeline); PlayerInfo[extraid][pADMute] = strval(string);
				mysql_fetch_field_row(string, "AdMutedTotal", MainPipeline); PlayerInfo[extraid][pADMuteTotal] = strval(string);
				mysql_fetch_field_row(string, "HelpMute", MainPipeline); PlayerInfo[extraid][pHelpMute] = strval(string);
				mysql_fetch_field_row(string, "Helper", MainPipeline); PlayerInfo[extraid][pHelper] = strval(string);
				mysql_fetch_field_row(string, "ReportMuted", MainPipeline); PlayerInfo[extraid][pRMuted] = strval(string);
				mysql_fetch_field_row(string, "ReportMutedTotal", MainPipeline); PlayerInfo[extraid][pRMutedTotal] = strval(string);
				mysql_fetch_field_row(string, "ReportMutedTime", MainPipeline); PlayerInfo[extraid][pRMutedTime] = strval(string);
				mysql_fetch_field_row(string, "VIPMuted", MainPipeline); PlayerInfo[extraid][pVMuted] = strval(string);
				mysql_fetch_field_row(string, "VIPMutedTime", MainPipeline); PlayerInfo[extraid][pVMutedTime] = strval(string);
				mysql_fetch_field_row(string, "GiftTime", MainPipeline); PlayerInfo[extraid][pGiftTime] = strval(string);
				mysql_fetch_field_row(string, "AdvisorDutyHours", MainPipeline); PlayerInfo[extraid][pDutyHours] = strval(string);
				mysql_fetch_field_row(string, "AcceptedHelp", MainPipeline); PlayerInfo[extraid][pAcceptedHelp] = strval(string);
				mysql_fetch_field_row(string, "AcceptReport", MainPipeline); PlayerInfo[extraid][pAcceptReport] = strval(string);
				mysql_fetch_field_row(string, "TrashReport", MainPipeline); PlayerInfo[extraid][pTrashReport] = strval(string);
				mysql_fetch_field_row(string, "FactionModerator", MainPipeline); PlayerInfo[extraid][pFactionModerator] = strval(string);
				mysql_fetch_field_row(string, "GangModerator", MainPipeline); PlayerInfo[extraid][pGangModerator] = strval(string);
				mysql_fetch_field_row(string, "GangWarn", MainPipeline); PlayerInfo[extraid][pGangWarn] = strval(string);
				mysql_fetch_field_row(string, "FactionBanned", MainPipeline); PlayerInfo[extraid][pFactionBanned] = strval(string);
				mysql_fetch_field_row(string, "CSFBanned", MainPipeline); PlayerInfo[extraid][pCSFBanned] = strval(string);
				mysql_fetch_field_row(string, "pVIPInviteDay", MainPipeline); PlayerInfo[extraid][pVIPInviteDay] = strval(string);
				mysql_fetch_field_row(string, "TempVIP", MainPipeline); PlayerInfo[extraid][pTempVIP] = strval(string);
				mysql_fetch_field_row(string, "BuddyInvite", MainPipeline); PlayerInfo[extraid][pBuddyInvited] = strval(string);
				mysql_fetch_field_row(string, "Tokens", MainPipeline); PlayerInfo[extraid][pTokens] = strval(string);
				mysql_fetch_field_row(string, "PTokens", MainPipeline); PlayerInfo[extraid][pPaintTokens] = strval(string);
				mysql_fetch_field_row(string, "TriageTime", MainPipeline); PlayerInfo[extraid][pTriageTime] = strval(string);
				mysql_fetch_field_row(PlayerInfo[extraid][pPrisonedBy], "PrisonedBy", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pPrisonReason], "PrisonReason", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pFlag], "Flag", MainPipeline);
				mysql_fetch_field_row(string, "TaxiLicense", MainPipeline); PlayerInfo[extraid][pTaxiLicense] = strval(string);
				mysql_fetch_field_row(string, "TicketTime", MainPipeline); PlayerInfo[extraid][pTicketTime] = strval(string);
				mysql_fetch_field_row(string, "Screwdriver", MainPipeline); PlayerInfo[extraid][pScrewdriver] = strval(string);
				mysql_fetch_field_row(string, "Smslog", MainPipeline); PlayerInfo[extraid][pSmslog] = strval(string);
				mysql_fetch_field_row(string, "Wristwatch", MainPipeline); PlayerInfo[extraid][pWristwatch] = strval(string);
				mysql_fetch_field_row(string, "Surveillance", MainPipeline); PlayerInfo[extraid][pSurveillance] = strval(string);
				mysql_fetch_field_row(string, "Tire", MainPipeline); PlayerInfo[extraid][pTire] = strval(string);
				mysql_fetch_field_row(string, "Firstaid", MainPipeline); PlayerInfo[extraid][pFirstaid] = strval(string);
				mysql_fetch_field_row(string, "Rccam", MainPipeline); PlayerInfo[extraid][pRccam] = strval(string);
				mysql_fetch_field_row(string, "Receiver", MainPipeline); PlayerInfo[extraid][pReceiver] = strval(string);
				mysql_fetch_field_row(string, "GPS", MainPipeline); PlayerInfo[extraid][pGPS] = strval(string);
				mysql_fetch_field_row(string, "Sweep", MainPipeline); PlayerInfo[extraid][pSweep] = strval(string);
				mysql_fetch_field_row(string, "SweepLeft", MainPipeline); PlayerInfo[extraid][pSweepLeft] = strval(string);
				mysql_fetch_field_row(string, "Bugged", MainPipeline); PlayerInfo[extraid][pBugged] = strval(string);
				mysql_fetch_field_row(PlayerInfo[extraid][pSmslog0], "Smslog0", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pSmslog1], "Smslog1", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pSmslog2], "Smslog2", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pSmslog3], "Smslog3", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pSmslog4], "Smslog4", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pSmslog5], "Smslog5", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pSmslog6], "Smslog6", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pSmslog7], "Smslog7", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pSmslog8], "Smslog8", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pSmslog9], "Smslog9", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pKillLog0], "KillLog0", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pKillLog1], "KillLog1", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pKillLog2], "KillLog2", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pKillLog3], "KillLog3", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pKillLog4], "KillLog4", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pKillLog5], "KillLog5", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pKillLog6], "KillLog6", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pKillLog7], "KillLog7", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pKillLog8], "KillLog8", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pKillLog9], "KillLog9", MainPipeline);
				mysql_fetch_field_row(string, "pWExists", MainPipeline); PlayerInfo[extraid][pWExists] = strval(string);
				mysql_fetch_field_row(string, "pWX", MainPipeline); PlayerInfo[extraid][pWX] = floatstr(string);
				mysql_fetch_field_row(string, "pWY", MainPipeline); PlayerInfo[extraid][pWY] = floatstr(string);
				mysql_fetch_field_row(string, "pWZ", MainPipeline); PlayerInfo[extraid][pWZ] = floatstr(string);
				mysql_fetch_field_row(string, "pWVW", MainPipeline); PlayerInfo[extraid][pWVW] = strval(string);
				mysql_fetch_field_row(string, "pWInt", MainPipeline); PlayerInfo[extraid][pWInt] = strval(string);
				mysql_fetch_field_row(string, "pWValue", MainPipeline); PlayerInfo[extraid][pWValue] = strval(string);
				mysql_fetch_field_row(string, "pWSeeds", MainPipeline); PlayerInfo[extraid][pWSeeds] = strval(string);
				mysql_fetch_field_row(string, "Warrants", MainPipeline); PlayerInfo[extraid][pWarrant] = strval(string);
				mysql_fetch_field_row(string, "JudgeJailTime", MainPipeline); PlayerInfo[extraid][pJudgeJailTime] = strval(string);
				mysql_fetch_field_row(string, "JudgeJailType", MainPipeline); PlayerInfo[extraid][pJudgeJailType] = strval(string);
				mysql_fetch_field_row(string, "ProbationTime", MainPipeline); PlayerInfo[extraid][pProbationTime] = strval(string);
				mysql_fetch_field_row(string, "DMIndicators", MainPipeline); PlayerInfo[extraid][pDMIndicators] = strval(string);
				mysql_fetch_field_row(string, "DMKills", MainPipeline); PlayerInfo[extraid][pDMKills] = strval(string);
				mysql_fetch_field_row(PlayerInfo[extraid][pDMReport0], "DMReport0", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pDMReport1], "DMReport1", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pDMReport2], "DMReport2", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pDMReport3], "DMReport3", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pDMReport4], "DMReport4", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pDMReport5], "DMReport5", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pDMReport6], "DMReport6", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pDMReport7], "DMReport7", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pDMReport8], "DMReport8", MainPipeline);
				mysql_fetch_field_row(PlayerInfo[extraid][pDMReport9], "DMReport9", MainPipeline);
				mysql_fetch_field_row(string, "Order", MainPipeline); PlayerInfo[extraid][pOrder] = strval(string);
				mysql_fetch_field_row(string, "OBlocked", MainPipeline); PlayerInfo[extraid][pOBlocked] = strval(string);
				mysql_fetch_field_row(string, "CallsAccepted", MainPipeline); PlayerInfo[extraid][pCallsAccepted] = strval(string);
				mysql_fetch_field_row(string, "PatientsDelivered", MainPipeline); PlayerInfo[extraid][pPatientsDelivered] = strval(string);
				mysql_fetch_field_row(string, "LiveBanned", MainPipeline); PlayerInfo[extraid][pLiveBanned] = strval(string);
				mysql_fetch_field_row(string, "FreezeBank", MainPipeline); PlayerInfo[extraid][pFreezeBank] = strval(string);
				mysql_fetch_field_row(string, "Speedo", MainPipeline); PlayerInfo[extraid][pSpeedo] = strval(string);
				
				
				for(new i = 0; i < MAX_PLAYERVEHICLES; i++)
				{
					new vehstring[128];
					format(vehstring, sizeof(vehstring), "pv%dPosX", i); 
					mysql_fetch_field_row(string, vehstring, MainPipeline);
					PlayerVehicleInfo[extraid][i][pvPosX] = floatstr(string);
					
					format(vehstring, sizeof(vehstring), "pv%dPosY", i); 
					mysql_fetch_field_row(string, vehstring, MainPipeline);
					PlayerVehicleInfo[extraid][i][pvPosY] = floatstr(string);
					
					format(vehstring, sizeof(vehstring), "pv%dPosZ", i); 
					mysql_fetch_field_row(string, vehstring, MainPipeline);
					PlayerVehicleInfo[extraid][i][pvPosZ] = floatstr(string);
					
					format(vehstring, sizeof(vehstring), "pv%dPosAngle", i); 
					mysql_fetch_field_row(string, vehstring, MainPipeline);
					PlayerVehicleInfo[extraid][i][pvPosAngle] = floatstr(string);
					
					format(vehstring, sizeof(vehstring), "pv%dModelId", i); 
					mysql_fetch_field_row(string, vehstring, MainPipeline);
					PlayerVehicleInfo[extraid][i][pvModelId] = strval(string);
					
					format(vehstring, sizeof(vehstring), "pv%dLock", i); 
					mysql_fetch_field_row(string, vehstring, MainPipeline);
					PlayerVehicleInfo[extraid][i][pvLock] = strval(string);
					
					format(vehstring, sizeof(vehstring), "pv%dLocked", i); 
					mysql_fetch_field_row(string, vehstring, MainPipeline);
					PlayerVehicleInfo[extraid][i][pvLocked] = strval(string);
					
					format(vehstring, sizeof(vehstring), "pv%dPaintJob", i); 
					mysql_fetch_field_row(string, vehstring, MainPipeline);
					PlayerVehicleInfo[extraid][i][pvPaintJob] = strval(string);
					
					format(vehstring, sizeof(vehstring), "pv%dColor1", i); 
					mysql_fetch_field_row(string, vehstring, MainPipeline);
					PlayerVehicleInfo[extraid][i][pvColor1] = strval(string);
					
					format(vehstring, sizeof(vehstring), "pv%dColor2", i); 
					mysql_fetch_field_row(string, vehstring, MainPipeline);
					PlayerVehicleInfo[extraid][i][pvColor2] = strval(string);
					
					format(vehstring, sizeof(vehstring), "pv%dPrice", i); 
					mysql_fetch_field_row(string, vehstring, MainPipeline);
					PlayerVehicleInfo[extraid][i][pvPrice] = strval(string);
					
					format(vehstring, sizeof(vehstring), "pv%dTicket", i); 
					mysql_fetch_field_row(string, vehstring, MainPipeline);
					PlayerVehicleInfo[extraid][i][pvTicket] = strval(string);
					
					format(vehstring, sizeof(vehstring), "pv%dWeapon0", i); 
					mysql_fetch_field_row(string, vehstring, MainPipeline);
					PlayerVehicleInfo[extraid][i][pvWeapons][0] = strval(string);
					
					format(vehstring, sizeof(vehstring), "pv%dWeapon1", i); 
					mysql_fetch_field_row(string, vehstring, MainPipeline);
					PlayerVehicleInfo[extraid][i][pvWeapons][1] = strval(string);
					
					format(vehstring, sizeof(vehstring), "pv%dWeapon2", i); 
					mysql_fetch_field_row(string, vehstring, MainPipeline);
					PlayerVehicleInfo[extraid][i][pvWeapons][2] = strval(string);
					
					format(vehstring, sizeof(vehstring), "pv%dWepUpgrade", i); 
					mysql_fetch_field_row(string, vehstring, MainPipeline);
					PlayerVehicleInfo[extraid][i][pvWepUpgrade] = strval(string);
					
					format(vehstring, sizeof(vehstring), "pv%dFuel", i); 
					mysql_fetch_field_row(string, vehstring, MainPipeline);
					PlayerVehicleInfo[extraid][i][pvFuel] = floatstr(string);
					
					format(vehstring, sizeof(vehstring), "pv%dImpound", i); 
					mysql_fetch_field_row(string, vehstring, MainPipeline);
					PlayerVehicleInfo[extraid][i][pvImpounded] = strval(string);
					
					for(new m = 0; m < MAX_MODS; m++)
					{
						format(vehstring, sizeof(vehstring), "pv%dMod%d", i, m);
						mysql_fetch_field_row(string, vehstring, MainPipeline);
						PlayerVehicleInfo[extraid][i][pvMods][m] = strval(string);
					}
				}
				
				for(new i = 0; i < MAX_PLAYERTOYS; i++)
				{		
					new toys[128];
					format(toys, sizeof(toys), "pt%dModelID", i);
					mysql_fetch_field_row(string, toys, MainPipeline);
					PlayerToyInfo[extraid][i][ptModelID] = strval(string);
					
					format(toys, sizeof(toys), "pt%dBone", i);
					mysql_fetch_field_row(string, toys, MainPipeline);
					PlayerToyInfo[extraid][i][ptBone] = strval(string);
					
					format(toys, sizeof(toys), "pt%dPosX", i);
					mysql_fetch_field_row(string, toys, MainPipeline);
					PlayerToyInfo[extraid][i][ptPosX] = floatstr(string);
					
					format(toys, sizeof(toys), "pt%dPosY", i);
					mysql_fetch_field_row(string, toys, MainPipeline);
					PlayerToyInfo[extraid][i][ptPosY] = floatstr(string);
					
					format(toys, sizeof(toys), "pt%dPosY", i);
					mysql_fetch_field_row(string, toys, MainPipeline);
					PlayerToyInfo[extraid][i][ptPosY] = floatstr(string);
					
					format(toys, sizeof(toys), "pt%dPosZ", i);
					mysql_fetch_field_row(string, toys, MainPipeline);
					PlayerToyInfo[extraid][i][ptPosZ] = floatstr(string);
					
					format(toys, sizeof(toys), "pt%dRotX", i);
					mysql_fetch_field_row(string, toys, MainPipeline);
					PlayerToyInfo[extraid][i][ptRotX] = floatstr(string);
					
					format(toys, sizeof(toys), "pt%dRotY", i);
					mysql_fetch_field_row(string, toys, MainPipeline);
					PlayerToyInfo[extraid][i][ptRotY] = floatstr(string);
					
					format(toys, sizeof(toys), "pt%dRotZ", i);
					mysql_fetch_field_row(string, toys, MainPipeline);
					PlayerToyInfo[extraid][i][ptRotZ] = floatstr(string);
				}
			}
			
			mysql_free_result(MainPipeline);
			
			OnPlayerLoad(extraid);
		}
		case SENDUSERDATA_THREAD:
		{
		}
		case LOGIN_THREAD:
		{
			mysql_store_result(MainPipeline);
			new result = mysql_num_rows(MainPipeline);
			mysql_free_result(MainPipeline);
			
			if(IsPlayerConnected(extraid))
			{
				if(result > 0)
				{
					SafeLogin(extraid, 1);
				}
				else
				{
					SafeLogin(extraid, 2);
				}
			}
		}
	}
}

public OnQueryError(errorid, error[], resultid, extraid, callback[], query[], connectionHandle)
{
	printf("[MySQL] Query Error - (Thread: %d) (ExtraID: %d) (ErrorID: %d)", resultid, extraid, errorid);
	print("[MySQL] Check /logs/querydump.log to review the query that threw the error.");
	Log("logs/querydump.log", query);
	
	if(resultid != -1)
	{
		if(errorid == 2013 || errorid == 2014 || errorid == 2006 || errorid == 2027 || errorid == 2055)
		{
			print("[MySQL] Connection Error Detected in Threaded Query, Attempting to Re-send Query.");
			mysql_query(query, resultid, extraid, MainPipeline);
		}
	}
}

// Custom Functions
// g_mysql_Init()
// Description: Called with Gamemode Init.
stock g_mysql_Init()
{
	mysql_debug(1);
	MainPipeline = mysql_connect(SQL_HOST, SQL_USER, SQL_DB, SQL_PASS);
	
	printf("[MySQL] (All Pipelines) Connecting to MySQL Database Server %s...", SQL_HOST); 
	
	if(mysql_ping(MainPipeline) == -1)
	{
		printf("[MySQL] (MainPipeline) Fatal Error! Could not connect to MySQL: Host %s - DB: %s - User: %s", SQL_HOST, SQL_DB, SQL_USER);
		print("[MySQL] Note: Make sure that you have provided the correct connection credentials."); 
		SendRconCommand("exit");
	}
	print("[MySQL] (MainPipeline) Connection successful toward MySQL Database Server!"); 
	
	return 1;
}

// g_mysql_Exit()
// Description: Called with Gamemode Exit.
stock g_mysql_Exit()
{
	mysql_close(MainPipeline);
	return 1;
}


// g_mysql_SafeUpdating();
// Description: Sets SQL_SAFE_UPDATE to 0 before sending query.
stock g_mysql_SafeUpdating()
{
	mysql_query("SET SQL_SAFE_UPDATES=0;", NO_THREAD, 0, MainPipeline);
	return 1;
}

// g_mysql_ReturnEscaped(string unEscapedString)
// Description: Takes a unescaped string and returns an escaped one.
stock g_mysql_ReturnEscaped(unEscapedString[])
{
	new EscapedString[256];
	mysql_real_escape_string(unEscapedString, EscapedString);
	return EscapedString;
}

// g_mysql_GetAccString(string column, string accountName)
// Description: Returns a string from a specific account column.
// Notice: No threading support, for small queries.
stock g_mysql_GetAccString(column[], accountName[])
{
	new string[128], returnedstr[256];
	
	format(string, sizeof(string), "SELECT `%s` from accounts WHERE Username = '%s'", column, accountName);
	mysql_query(string, NO_THREAD, 0, MainPipeline);
	mysql_store_result(MainPipeline);
		
	if(mysql_retrieve_row())
	{
		mysql_fetch_field_row(returnedstr, column, MainPipeline);
	}
	
	mysql_free_result(MainPipeline);
	return returnedstr;
}

// g_mysql_GetAccInt(string column, string accountName)
// Description: Returns a int from a specific account column.
// Notice: No threading support, for small queries.
stock g_mysql_GetAccInt(column[], accountName[])
{
	new string[128], returnedint;
	format(string, sizeof(string), "SELECT `%s` from accounts WHERE Username = '%s'", column, accountName);
	mysql_query(string, NO_THREAD, 0, MainPipeline);
	mysql_store_result(MainPipeline);
	returnedint = mysql_fetch_int(MainPipeline);	
	mysql_free_result(MainPipeline);
	return returnedint;
}

// g_mysql_GetAccFloat(string column, string accountName)
// Description: Returns a float from a specific account column.
// Notice: No threading support, for small queries.
stock g_mysql_GetAccFloat(column[], accountName[])
{
	new string[128], Float:returnedfloat;
	format(string, sizeof(string), "SELECT `%s` from accounts WHERE Username = '%s'", column, accountName);
	mysql_query(string, NO_THREAD, 0, MainPipeline);
	mysql_store_result(MainPipeline);
	mysql_fetch_float(returnedfloat, MainPipeline);
	mysql_free_result(MainPipeline);
	return returnedfloat;
}

// g_mysql_SetAccString(string column, string accountName, string str)
// Description: Sets a string in a specific account column.
// Notice: Useful for small queries.
stock g_mysql_SetAccString(column[], accountName[], str[])
{
	new string[128];
	g_mysql_SafeUpdating();
	mysql_real_escape_string(str, str);
	format(string, sizeof(string), "UPDATE `accounts` SET `%s` = '%s' WHERE Username = '%s'", column, str, accountName);
	mysql_query(string, SENDUSERDATA_THREAD, 0, MainPipeline);
	
	return 1;
}

// g_mysql_SetAccInt(string column, string accountName, int interger)
// Description: Sets a string in a specific account column.
// Notice: Useful for small queries.
stock g_mysql_SetAccInt(column[], accountName[], interger)
{
	new string[128];
	g_mysql_SafeUpdating();
	format(string, sizeof(string), "UPDATE `accounts` SET `%s` = %d WHERE Username = '%s'", column, interger, accountName);
	mysql_query(string, SENDUSERDATA_THREAD, 0, MainPipeline);
	
	return 0;
}

// g_mysql_SetAccFloat(string column, string accountName, float floatingpoint)
// Description: Sets a string in a specific account column.
// Notice: Useful for small queries.
stock g_mysql_SetAccFloat(column[], accountName[], Float:floatingpoint)
{
	new string[128];
	g_mysql_SafeUpdating();
	format(string, sizeof(string), "UPDATE `accounts` SET `%s` = %f WHERE Username = '%s'", column, floatingpoint, accountName);
	mysql_query(string, SENDUSERDATA_THREAD, 0, MainPipeline);
	return 0;
}  

// g_mysql_CheckConnection()
stock g_mysql_CheckConnection()
{
	mysql_ping(MainPipeline);
	return 1;
}

// g_mysql_AccountLoginCheck(playerid)
forward g_mysql_AccountLoginCheck(playerid);
public g_mysql_AccountLoginCheck(playerid)
{
	new string[128];
	format(string, sizeof(string), "SELECT Username from accounts WHERE Username = '%s'", GetPlayerNameExt(playerid));
	mysql_query(string, LOGIN_THREAD, playerid, MainPipeline);
	
	// Reset the GUI
	SetPlayerJoinCamera(playerid);
	ClearChatbox(playerid);
	SetPlayerVirtualWorld(playerid, 0);
	return 1;
}

// g_mysql_DoesAccountExist(string accountName[])
// Description: Checks if a Username matches inside the MySQL Database.
stock g_mysql_DoesAccountExist(accountName[])
{
	new string[128];
	format(string, sizeof(string), "SELECT Username from accounts WHERE Username = '%s'", accountName);
	mysql_query(string, NO_THREAD, 0, MainPipeline);
	mysql_store_result(MainPipeline);
	new result = mysql_num_rows(MainPipeline);
	mysql_free_result(MainPipeline);
		
	if(result > 0)
	{
		return 1;
	}
	
	return 0;
}

// g_mysql_CreateAccount(string accountName[], string accountKey[])
// Description: Creates a new account in the database.
// Note: Not a heavy used function, leave in sanity check.
stock g_mysql_CreateAccount(accountName[], accountKey[])
{
	new string[128];
	
	if(!g_mysql_DoesAccountExist(accountName))
	{
		format(string, sizeof(string), "INSERT INTO `accounts` (`Username`, `Key`) VALUES ('%s','%s')", accountName, accountKey);
		mysql_query(string, NO_THREAD, 0, MainPipeline);
		return 1;
	}
	
	return 0;
}

// g_mysql_DeleteAccount(string accountName[])
// Description: Deletes an account in the database.
// Note: Not a heavy used function, leave in sanity check.
stock g_mysql_DeleteAccount(accountName[])
{
	new string[128];
	
	if(g_mysql_DoesAccountExist(accountName))
	{
		format(string, sizeof(string), "DELETE FROM `accounts` WHERE `Username`='%s';", accountName);
		mysql_query(string, NO_THREAD, 0, MainPipeline);
		return 1;
	}
	
	return 0;
}

// g_mysql_LoadAccount(playerid)
// Description: Loads an account from database into memory.
stock g_mysql_LoadAccount(playerid)
{
	new string[128];
	
	format(string, sizeof(string), "SELECT * FROM `accounts` WHERE `Username` = '%s'", GetPlayerNameExt(playerid));
	mysql_query(string, LOADUSERDATA_THREAD, playerid, MainPipeline);
	
	return 1;
}

// g_mysql_SaveAccount(playerid)
// Description: Saves an account from memory into the database.
stock g_mysql_SaveAccount(playerid)
{
	new query[4096], accountName[MAX_PLAYER_NAME];
	GetPlayerName(playerid, accountName, MAX_PLAYER_NAME);
		
	g_mysql_SafeUpdating();
	
	format(query, sizeof(query), "UPDATE `accounts` SET \
		`IP` = '%s', \
		`Registered` = %d, \
		`ConnectedTime` = %d, \
		`Sex` = %d, \
		`Age` = %d, \
		`Band` = %d, \
		`PermBand` = %d, \
		`Warnings` = %d, \
		`Disabled` = %d, \
		`Level` = %d, \
		`AdminLevel` = %d, \
		`DonateRank` = %d, \
		`Respect` = %d, \
		`Money` = %d, \
		`Bank` = %d,",
		PlayerInfo[playerid][pIP],
		PlayerInfo[playerid][pReg],
		PlayerInfo[playerid][pConnectTime],
		PlayerInfo[playerid][pSex],
		PlayerInfo[playerid][pAge],
		PlayerInfo[playerid][pBanned],
		PlayerInfo[playerid][pPermaBanned],
		PlayerInfo[playerid][pWarns],
		PlayerInfo[playerid][pDisabled],
		PlayerInfo[playerid][pLevel],
		PlayerInfo[playerid][pAdmin],
		PlayerInfo[playerid][pDonateRank],
		PlayerInfo[playerid][pExp],
		GetPVarInt(playerid, "Cash"),
		PlayerInfo[playerid][pAccount]
	);
	
	format(query, sizeof(query), "%s \
		`pHealth` = %f, \
		`pArmor` = %f, \
		`pSHealth` = %f, \
		`Int` = %d, \
		`Local` = %d, \
		`VirtualWorld` = %d, \
		`Model` = %d, \
		`SPos_x` = %f, \
		`SPos_y` = %f, \
		`SPos_z` = %f, \
		`SPos_r` = %f, \
		`BanAppealer` = %d, \
		`ShopTech` = %d, \
		`Undercover` = %d, \
		`TogReports` = %d,",
		query,
		PlayerInfo[playerid][pHealth],
		PlayerInfo[playerid][pArmor],
		PlayerInfo[playerid][pSHealth],
		PlayerInfo[playerid][pInt],
		PlayerInfo[playerid][pLocal],
		PlayerInfo[playerid][pVW],
		PlayerInfo[playerid][pModel],
		PlayerInfo[playerid][pPos_x],
		PlayerInfo[playerid][pPos_y],
		PlayerInfo[playerid][pPos_z],
		PlayerInfo[playerid][pPos_r],
		PlayerInfo[playerid][pBanAppealer],
		PlayerInfo[playerid][pShopTech],
		PlayerInfo[playerid][pUndercover],
		PlayerInfo[playerid][pTogReports]
	);
	
	format(query, sizeof(query), "%s \
		`Radio` = %d, \
		`RadioFreq` = %d, \
		`UpgradePoints` = %d, \
		`Origin` = %d, \
		`Muted` = %d, \
		`Crimes` = %d, \
		`Accent` = %d, \
		`CHits` = %d, \
		`FHits` = %d, \
		`Arrested` = %d, \
		`Phonebook` = %d, \
		`LottoNr` = %d, \
		`Fishes` = %d, \
		`BiggestFish` = %d, \
		`Job` = %d,",
		query,
		PlayerInfo[playerid][pRadio],
		PlayerInfo[playerid][pRadioFreq],
		PlayerInfo[playerid][gPupgrade],
		PlayerInfo[playerid][pOrigin],
		PlayerInfo[playerid][pMuted],
		PlayerInfo[playerid][pCrimes],
		PlayerInfo[playerid][pAccent],
		PlayerInfo[playerid][pCHits],
		PlayerInfo[playerid][pFHits],
		PlayerInfo[playerid][pArrested],
		PlayerInfo[playerid][pPhoneBook],
		PlayerInfo[playerid][pLottoNr],
		PlayerInfo[playerid][pFishes],
		PlayerInfo[playerid][pBiggestFish],
		PlayerInfo[playerid][pJob]
	);
	
	format(query, sizeof(query), "%s \
		`Job2` = %d, \
		`Paycheck` = %d, \
		`HeadValue` = %d, \
		`Jailed` = %d, \
		`JailTime` = %d, \
		`WRestricted` = %d, \
		`Materials` = %d, \
		`Packages` = %d, \
		`Crates` = %d, \
		`Pot` = %d, \
		`Crack` = %d, \
		`Leader` = %d, \
		`Member` = %d, \
		`Division` = %d, \
		`FMember` = %d,",
		query,
		PlayerInfo[playerid][pJob2],
		PlayerInfo[playerid][pPayCheck],
		PlayerInfo[playerid][pHeadValue],
		PlayerInfo[playerid][pJailed],
		PlayerInfo[playerid][pJailTime],
		PlayerInfo[playerid][pWRestricted],
		PlayerInfo[playerid][pMats],
		GetPVarInt(playerid, "Packages"),
		PlayerInfo[playerid][pCrates],
		PlayerInfo[playerid][pPot],
		PlayerInfo[playerid][pCrack],
		PlayerInfo[playerid][pLeader],
		PlayerInfo[playerid][pMember],
		PlayerInfo[playerid][pDivision],
		PlayerInfo[playerid][pFMember]
	);
	
	format(query, sizeof(query), "%s \
		`Rank` = %d, \
		`DetSkill` = %d, \
		`SexSkill` = %d, \
		`BoxSkill` = %d, \
		`LawSkill` = %d, \
		`MechSkill` = %d, \
		`JackSkill` = %d, \
		`CarSkill` = %d, \
		`TruckSkill` = %d, \
		`NewsSkill` = %d, \
		`DrugsSkill` = %d, \
		`ArmsSkill` = %d, \
		`SmugglerSkill` = %d, \
		`FishSkill` = %d, \
		`CheckCash` = %d,",
		query,
		PlayerInfo[playerid][pRank],
		PlayerInfo[playerid][pDetSkill],
		PlayerInfo[playerid][pSexSkill],
		PlayerInfo[playerid][pBoxSkill],
		PlayerInfo[playerid][pLawSkill],
		PlayerInfo[playerid][pMechSkill],
		PlayerInfo[playerid][pJackSkill],
		PlayerInfo[playerid][pCarSkill],
		PlayerInfo[playerid][pTruckSkill],
		PlayerInfo[playerid][pNewsSkill],
		PlayerInfo[playerid][pDrugsSkill],
		PlayerInfo[playerid][pArmsSkill],
		PlayerInfo[playerid][pSmugSkill],
		PlayerInfo[playerid][pFishSkill],
		PlayerInfo[playerid][pCheckCash]
	);
	
	format(query, sizeof(query), "%s \
		`Checks` = %d, \
		`GunLic` = %d, \
		`CarTime` = %d \
		WHERE `Username` = '%s'",
		query,
		PlayerInfo[playerid][pChecks],
		PlayerInfo[playerid][pGunLic],
		PlayerInfo[playerid][pCarTime],
		accountName
	);
	
	mysql_query(query, SENDUSERDATA_THREAD, playerid, MainPipeline);
	
	format(query, sizeof(query), "UPDATE `accounts` SET \
		`DrugsTime` = %d, \
		`LawyerTime` = %d, \
		`LawyerFreeTime` = %d, \
		`MechTime` = %d, \
		`SexTime` = %d, \
		`PayDay` = %d, \
		`PayDayHad` = %d, \
		`CDPlayer` = %d, \
		`Dice` = %d, \
		`Spraycan` = %d, \
		`Rope` = %d, \
		`Cigars` = %d, \
		`Sprunk` = %d, \
		`Bombs` = %d, \
		`Wins` = %d,",
		PlayerInfo[playerid][pDrugsTime],
		PlayerInfo[playerid][pLawyerTime],
		PlayerInfo[playerid][pLawyerFreeTime],
		PlayerInfo[playerid][pMechTime],
		PlayerInfo[playerid][pSexTime],
		PlayerInfo[playerid][pPayDay],
		PlayerInfo[playerid][pPayDayHad],
		PlayerInfo[playerid][pCDPlayer],
		PlayerInfo[playerid][pDice],
		PlayerInfo[playerid][pSpraycan],
		PlayerInfo[playerid][pRope],
		PlayerInfo[playerid][pCigar],
		PlayerInfo[playerid][pSprunk],
		PlayerInfo[playerid][pBombs],
		PlayerInfo[playerid][pWins]
	);
	
	for(new i = 0; i < 12; i++)
	{
		format(query, sizeof(query), "%s `Gun%d` = %d,", query, i, PlayerInfo[playerid][pGuns][i]);
	}
	
	format(query, sizeof(query), "%s \
		`Loses` = %d, \
		`Tutorial` = %d, \
		`OnDuty` = %d, \
		`Hospital` = %d, \
		`Adjustable` = %d, \
		`Married` = %d, \
		`MarriedTo` = '%s', \
		`ContractBy` = '%s', \
		`ContractDetail` = '%s', \
		`WantedLevel` = %d, \
		`Insurance` = %d, \
		`NewMuted` = %d, \
		`NewMutedTotal` = %d, \
		`AdMuted` = %d, \
		`AdMutedTotal` = %d,",
		query,
		PlayerInfo[playerid][pLoses],
		PlayerInfo[playerid][pTut],
		PlayerInfo[playerid][pDuty],
		GetPVarInt(playerid, "Hospital"),
		PlayerInfo[playerid][pAdjustable],
		PlayerInfo[playerid][pMarried],
		PlayerInfo[playerid][pMarriedTo],
		PlayerInfo[playerid][pContractBy],
		g_mysql_ReturnEscaped(PlayerInfo[playerid][pContractDetail]),
		PlayerInfo[playerid][pWantedLevel],
		PlayerInfo[playerid][pInsurance],
		PlayerInfo[playerid][pNMute],
		PlayerInfo[playerid][pNMuteTotal],
		PlayerInfo[playerid][pADMute],
		PlayerInfo[playerid][pADMuteTotal]
	);
	
	format(query, sizeof(query), "%s \
		`HelpMute` = %d, \
		`Helper` = %d, \
		`ReportMuted` = %d, \
		`ReportMutedTotal` = %d, \
		`ReportMutedTime` = %d, \
		`VIPMuted` = %d, \
		`VIPMutedTime` = %d, \
		`GiftTime` = %d, \
		`AdvisorDutyHours` = %d, \
		`AcceptedHelp` = %d, \
		`AcceptReport` = %d, \
		`TrashReport` = %d, \
		`FactionModerator` = %d, \
		`GangModerator` = %d, \
		`GangWarn` = %d,",
		query,
		PlayerInfo[playerid][pHelpMute],
		PlayerInfo[playerid][pHelper],
		PlayerInfo[playerid][pRMuted],
		PlayerInfo[playerid][pRMutedTotal],
		PlayerInfo[playerid][pRMutedTime],
		PlayerInfo[playerid][pVMuted],
		PlayerInfo[playerid][pVMutedTime],
		PlayerInfo[playerid][pGiftTime],
		PlayerInfo[playerid][pDutyHours],
		PlayerInfo[playerid][pAcceptedHelp],
		PlayerInfo[playerid][pAcceptReport],
		PlayerInfo[playerid][pTrashReport],
		PlayerInfo[playerid][pFactionModerator],
		PlayerInfo[playerid][pGangModerator],
		PlayerInfo[playerid][pGangWarn]
	);
	
	format(query, sizeof(query), "%s \
		`FactionBanned` = %d, \
		`CSFBanned` = %d, \
		`VIPInviteDay` = %d, \
		`TempVIP` = %d, \
		`BuddyInvite` = %d, \
		`Tokens` = %d, \
		`PTokens` = %d, \
		`TriageTime` = %d, \
		`PrisonedBy` = '%s', \
		`PrisonReason` = '%s', \
		`Flag` = '%s', \
		`TaxiLicense` = %d, \
		`TicketTime` = %d, \
		`Screwdriver` = %d, \
		`Smslog` = %d, \
		`Speedo` = %d \
		WHERE `Username` = '%s'",
		query,
		PlayerInfo[playerid][pFactionBanned],
		PlayerInfo[playerid][pCSFBanned],
		PlayerInfo[playerid][pVIPInviteDay],
		PlayerInfo[playerid][pTempVIP],
		PlayerInfo[playerid][pBuddyInvited],
		PlayerInfo[playerid][pTokens],
		PlayerInfo[playerid][pPaintTokens],
		PlayerInfo[playerid][pTriageTime],
		PlayerInfo[playerid][pPrisonedBy],
		g_mysql_ReturnEscaped(PlayerInfo[playerid][pPrisonReason]),
		g_mysql_ReturnEscaped(PlayerInfo[playerid][pFlag]),
		PlayerInfo[playerid][pTaxiLicense],
		PlayerInfo[playerid][pTicketTime],
		PlayerInfo[playerid][pScrewdriver],
		PlayerInfo[playerid][pSmslog],
		PlayerInfo[playerid][pSpeedo],
		accountName
	);
		
	mysql_query(query, SENDUSERDATA_THREAD, playerid, MainPipeline);
	
	format(query, sizeof(query), "UPDATE `accounts` SET \
		`Wristwatch` = %d, \
		`Surveillance` = %d, \
		`Tire` = %d, \
		`Firstaid` = %d, \
		`Rccam` = %d, \
		`Receiver` = %d, \
		`GPS` = %d, \
		`Sweep` = %d, \
		`SweepLeft` = %d, \
		`Bugged` = %d,",
		PlayerInfo[playerid][pWristwatch],
		PlayerInfo[playerid][pSurveillance],
		PlayerInfo[playerid][pTire],
		PlayerInfo[playerid][pFirstaid],
		PlayerInfo[playerid][pRccam],
		PlayerInfo[playerid][pReceiver],
		PlayerInfo[playerid][pGPS],
		PlayerInfo[playerid][pSweep],
		PlayerInfo[playerid][pSweepLeft],
		PlayerInfo[playerid][pBugged]
	);
	
	format(query, sizeof(query), "%s \
		`Smslog0` = '%s', \
		`Smslog1` = '%s', \
		`Smslog2` = '%s', \
		`Smslog3` = '%s', \
		`Smslog4` = '%s', \
		`Smslog5` = '%s', \
		`Smslog6` = '%s', \
		`Smslog7` = '%s', \
		`Smslog8` = '%s', \
		`Smslog9` = '%s',",
		query,
		g_mysql_ReturnEscaped(PlayerInfo[playerid][pSmslog0]),
		g_mysql_ReturnEscaped(PlayerInfo[playerid][pSmslog1]),
		g_mysql_ReturnEscaped(PlayerInfo[playerid][pSmslog2]),
		g_mysql_ReturnEscaped(PlayerInfo[playerid][pSmslog3]),
		g_mysql_ReturnEscaped(PlayerInfo[playerid][pSmslog4]),
		g_mysql_ReturnEscaped(PlayerInfo[playerid][pSmslog5]),
		g_mysql_ReturnEscaped(PlayerInfo[playerid][pSmslog6]),
		g_mysql_ReturnEscaped(PlayerInfo[playerid][pSmslog7]),
		g_mysql_ReturnEscaped(PlayerInfo[playerid][pSmslog8]),
		g_mysql_ReturnEscaped(PlayerInfo[playerid][pSmslog9])
	);
	
	format(query, sizeof(query), "%s \
		`KillLog0` = '%s', \
		`KillLog1` = '%s', \
		`KillLog2` = '%s', \
		`KillLog3` = '%s', \
		`KillLog4` = '%s', \
		`KillLog5` = '%s', \
		`KillLog6` = '%s', \
		`KillLog7` = '%s', \
		`KillLog8` = '%s', \
		`KillLog9` = '%s',",
		query,
		PlayerInfo[playerid][pKillLog0],
		PlayerInfo[playerid][pKillLog1],
		PlayerInfo[playerid][pKillLog2],
		PlayerInfo[playerid][pKillLog3],
		PlayerInfo[playerid][pKillLog4],
		PlayerInfo[playerid][pKillLog5],
		PlayerInfo[playerid][pKillLog6],
		PlayerInfo[playerid][pKillLog7],
		PlayerInfo[playerid][pKillLog8],
		PlayerInfo[playerid][pKillLog9]
	);
	
	format(query, sizeof(query), "%s \
		`pWExists` = %d, \
		`pWX` = %f, \
		`pWY` = %f, \
		`pWZ` = %f, \
		`pWVW` = %d, \
		`pWInt` = %d, \
		`pWValue` = %d, \
		`pWSeeds` = %d, \
		`Warrants` = %d, \
		`JudgeJailTime` = %d, \
		`JudgeJailType` = %d, \
		`BeingSentenced` = %d, \
		`ProbationTime` = %d, \
		`DMIndicators` = %d, \
		`DMKills` = %d,",
		query,
		PlayerInfo[playerid][pWExists],
		PlayerInfo[playerid][pWX],
		PlayerInfo[playerid][pWY],
		PlayerInfo[playerid][pWZ],
		PlayerInfo[playerid][pWVW],
		PlayerInfo[playerid][pWInt],
		PlayerInfo[playerid][pWValue],
		PlayerInfo[playerid][pWSeeds],
		PlayerInfo[playerid][pWarrant],
		PlayerInfo[playerid][pJudgeJailTime],
		PlayerInfo[playerid][pJudgeJailType],
		PlayerInfo[playerid][pBeingSentenced],
		PlayerInfo[playerid][pProbationTime],
		PlayerInfo[playerid][pDMIndicators],
		PlayerInfo[playerid][pDMKills]
	);
	
	format(query, sizeof(query), "%s \
		`DMReport0` = '%s', \
		`DMReport1` = '%s', \
		`DMReport2` = '%s', \
		`DMReport3` = '%s', \
		`DMReport4` = '%s', \
		`DMReport5` = '%s', \
		`DMReport6` = '%s', \
		`DMReport7` = '%s', \
		`DMReport8` = '%s', \
		`DMReport9` = '%s',",
		query,
		g_mysql_ReturnEscaped(PlayerInfo[playerid][pDMReport0]),
		g_mysql_ReturnEscaped(PlayerInfo[playerid][pDMReport1]),
		g_mysql_ReturnEscaped(PlayerInfo[playerid][pDMReport2]),
		g_mysql_ReturnEscaped(PlayerInfo[playerid][pDMReport3]),
		g_mysql_ReturnEscaped(PlayerInfo[playerid][pDMReport4]),
		g_mysql_ReturnEscaped(PlayerInfo[playerid][pDMReport5]),
		g_mysql_ReturnEscaped(PlayerInfo[playerid][pDMReport6]),
		g_mysql_ReturnEscaped(PlayerInfo[playerid][pDMReport7]),
		g_mysql_ReturnEscaped(PlayerInfo[playerid][pDMReport8]),
		g_mysql_ReturnEscaped(PlayerInfo[playerid][pDMReport9])
	);
	
	format(query, sizeof(query), "%s \
		`Order` = %d, \
		`OBlocked` = %d, \
		`CallsAccepted` = %d, \
		`PatientsDelivered` = %d, \
		`LiveBanned` = %d, \
		`FreezeBank` = %d \
		WHERE `Username` = '%s'",
		query,
		PlayerInfo[playerid][pOrder],
		PlayerInfo[playerid][pOBlocked],
		PlayerInfo[playerid][pCallsAccepted],
		PlayerInfo[playerid][pPatientsDelivered],
		PlayerInfo[playerid][pLiveBanned],
		PlayerInfo[playerid][pFreezeBank],
		accountName
	);
	
	mysql_query(query, SENDUSERDATA_THREAD, playerid, MainPipeline);
	
	format(query, sizeof(query), "UPDATE `accounts` SET ");
	for(new i = 0; i < MAX_PLAYERVEHICLES; i++)
	{
		format(query, sizeof(query), "%s `pv%dPosX` = %f,", query, i, PlayerVehicleInfo[playerid][i][pvPosX]);
		format(query, sizeof(query), "%s `pv%dPosY` = %f,", query, i, PlayerVehicleInfo[playerid][i][pvPosY]);
		format(query, sizeof(query), "%s `pv%dPosZ` = %f,", query, i, PlayerVehicleInfo[playerid][i][pvPosZ]);
		format(query, sizeof(query), "%s `pv%dPosAngle` = %f,", query, i, PlayerVehicleInfo[playerid][i][pvPosAngle]);
		format(query, sizeof(query), "%s `pv%dModelId` = %d,", query, i, PlayerVehicleInfo[playerid][i][pvModelId]);
		format(query, sizeof(query), "%s `pv%dLock` = %d,", query, i, PlayerVehicleInfo[playerid][i][pvLock]);
		format(query, sizeof(query), "%s `pv%dLocked` = %d,", query, i, PlayerVehicleInfo[playerid][i][pvLocked]);
		format(query, sizeof(query), "%s `pv%dPaintJob` = %d,", query, i, PlayerVehicleInfo[playerid][i][pvPaintJob]);
		format(query, sizeof(query), "%s `pv%dColor1` = %d,", query, i, PlayerVehicleInfo[playerid][i][pvColor1]);
		format(query, sizeof(query), "%s `pv%dColor2` = %d,", query, i, PlayerVehicleInfo[playerid][i][pvColor2]);
		format(query, sizeof(query), "%s `pv%dPrice` = %d,", query, i, PlayerVehicleInfo[playerid][i][pvPrice]);
		format(query, sizeof(query), "%s `pv%dWeapon0` = %d,", query, i, PlayerVehicleInfo[playerid][i][pvWeapons][0]);
		format(query, sizeof(query), "%s `pv%dWeapon1` = %d,", query, i, PlayerVehicleInfo[playerid][i][pvWeapons][1]);
		format(query, sizeof(query), "%s `pv%dWeapon2` = %d,", query, i, PlayerVehicleInfo[playerid][i][pvWeapons][2]);
		format(query, sizeof(query), "%s `pv%dLock` = %d,", query, i, PlayerVehicleInfo[playerid][i][pvLock]);
		format(query, sizeof(query), "%s `pv%dWepUpgrade` = %d,", query, i, PlayerVehicleInfo[playerid][i][pvWepUpgrade]);
		format(query, sizeof(query), "%s `pv%dFuel` = %f,", query, i, PlayerVehicleInfo[playerid][i][pvFuel]);
		format(query, sizeof(query), "%s `pv%dImpound` = %d,", query, i, PlayerVehicleInfo[playerid][i][pvImpounded]);
		
		for(new m = 0; m < MAX_MODS; m++)
		{
			if(m == MAX_MODS-1 && MAX_PLAYERVEHICLES-1 == i)
			{
				format(query, sizeof(query), "%s `pv%dMod%d` = %d WHERE `Username` = '%s'", query, i, m, PlayerVehicleInfo[playerid][i][pvMods][m], g_mysql_ReturnEscaped(accountName));
			}
			else
			{
				format(query, sizeof(query), "%s `pv%dMod%d` = %d,", query, i, m, PlayerVehicleInfo[playerid][i][pvMods][m]);
			}
		}
	}
	
	mysql_query(query, SENDUSERDATA_THREAD, playerid, MainPipeline);
	
	format(query, sizeof(query), "UPDATE `accounts` SET ");
	for(new i = 0; i < MAX_PLAYERTOYS; i++)
	{
		format(query, sizeof(query), "%s `pt%dModelID` = %d,", query, i, PlayerToyInfo[playerid][i][ptModelID]);
		format(query, sizeof(query), "%s `pt%dBone` = %d,", query, i, PlayerToyInfo[playerid][i][ptBone]);
		format(query, sizeof(query), "%s `pt%dPosX` = %f,", query, i, PlayerToyInfo[playerid][i][ptPosX]);
		format(query, sizeof(query), "%s `pt%dPosY` = %f,", query, i, PlayerToyInfo[playerid][i][ptPosY]);
		format(query, sizeof(query), "%s `pt%dPosZ` = %f,", query, i, PlayerToyInfo[playerid][i][ptPosZ]);
		format(query, sizeof(query), "%s `pt%dRotX` = %f,", query, i, PlayerToyInfo[playerid][i][ptRotX]);
		format(query, sizeof(query), "%s `pt%dRotY` = %f,", query, i, PlayerToyInfo[playerid][i][ptRotY]);
		if(MAX_PLAYERTOYS-1 == i)
		{
			format(query, sizeof(query), "%s `pt%dRotZ` = %f WHERE `Username` = '%s'", query, i, PlayerToyInfo[playerid][i][ptRotZ], g_mysql_ReturnEscaped(accountName));
		}
		else
		{
			format(query, sizeof(query), "%s `pt%dRotZ` = %f,", query, i, PlayerToyInfo[playerid][i][ptRotZ]);
		}
	}
	
	mysql_query(query, SENDUSERDATA_THREAD, playerid, MainPipeline);

	return 1;
}

// g_mysql_ReturnPassword(string accountName[])
// Description: Returns the account's password.
stock g_mysql_ReturnPassword(accountName[])
{
	new string[128], key[64];
	
	if(g_mysql_DoesAccountExist(accountName))
	{
		format(string, sizeof(string), "SELECT `Key` from accounts WHERE Username = '%s'", accountName);
		mysql_query(string, NO_THREAD, 0, MainPipeline);
		mysql_store_result(MainPipeline);
		
		if(mysql_retrieve_row())
		{
			mysql_fetch_field_row(key, "Key", MainPipeline);
		}
		
		mysql_free_result(MainPipeline);
	}
	
	return key;
}

// g_mysql_ConvertAccount(string accountName[])
// Description: Converts a flatfile within /users/ toward the MySQL database and then deletes it.
stock g_mysql_ConvertAccount(accountName[])
{
	new string[128];
	
	if(doesAccountExist(accountName))
	{
		if(g_mysql_DoesAccountExist(accountName))
		{
			return 0;
		}
	
		format(string, sizeof(string), "users/%s.ini", accountName);
		new File: Profile = fopen(string, io_read);
		if(Profile)
		{
			new key[256], val[256], Data[256], Query[1024];
			
			format(string, sizeof(string), "INSERT INTO `accounts` (`Username`) VALUES ('%s')", accountName);
			mysql_query(string, SENDUSERDATA_THREAD, 0, MainPipeline);
			
			g_mysql_SafeUpdating();
			printf("[MySQL] Converting %s's Profile from File to MySQL Database.", accountName);
			
			format(Query, sizeof(Query), "UPDATE `accounts` SET");
			while(fread(Profile, Data, sizeof(Data)))
			{
				key = ini_GetKey(Data);
				val = ini_GetValue(Data);
				StripNewLine(val);
				
				format(Query, sizeof(Query), "%s `%s`='%s',", Query, key, val);
				
				if(strlen(Query) >= 768)
				{
					format(Query, sizeof(Query), "%s `Username`='%s' WHERE `Username`='%s'", Query, accountName, accountName);
					mysql_query(Query, SENDUSERDATA_THREAD, 0, MainPipeline);
					format(Query, sizeof(Query), "UPDATE `accounts` SET ");
				}
			}
			fclose(Profile);
			
			format(Query, sizeof(Query), "%s `Username`='%s' WHERE `Username`='%s'", Query, accountName, accountName);
			mysql_query(Query, SENDUSERDATA_THREAD, 0, MainPipeline);
				
			printf("[MySQL] %s's Profile Conversion has been completed!", accountName);
			return 1;
		}
	}
	return 0;
}