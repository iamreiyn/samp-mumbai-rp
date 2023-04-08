#define	WELCOME_DIALOG	7003

stock displayWelcomeMessage(playerid) {
	new msgstring[2048]; //2048
	new name[] = "name";
	
	format(msgstring, sizeof(msgstring), "{FFFFFF}Welcome to {00aa00}Prospect Roleplay{FFFFFF}.\nPlease take the time to briefly read over the rules to ensure that you have an enjoyable experience.", name);
	
	format(msgstring, sizeof(msgstring), "%s\n\n{FFFF91}Server Information:{FFFFFF}\nThis server is a roleplay server, which means you must be in character at all times.\nYour success in joining factions or gangs may be determined by your ability to roleplay. If you are new to\nthe concept be sure to visit our website for RP guides, tutorials and other useful information.", msgstring);
	
	format(msgstring, sizeof(msgstring), "%s\n\n{FFFF91}Rules:{FFFFFF}", msgstring);
	format(msgstring, sizeof(msgstring), "%s\nWe try encourage a healthy roleplay environment, please take the following rules into consideration:", msgstring);
	
	format(msgstring, sizeof(msgstring), "%s\n   - No deathmatching or shooting other players without in-character justification.", msgstring);
	format(msgstring, sizeof(msgstring), "%s\n   - No server advertising.", msgstring);
	format(msgstring, sizeof(msgstring), "%s\n   - No driver shooting or killing with vehicles (including helicopters).", msgstring);
	
	format(msgstring, sizeof(msgstring), "%s\n   - This server has a zero tolerance policy for hacking, by doing it you risk being permanently banned.", msgstring);
	
	format(msgstring, sizeof(msgstring), "%s\n\n{FFFF91}Joining the community:{FFFFFF}", msgstring);
	
	format(msgstring, sizeof(msgstring), "%s\nWe invite you to join our community at {8D8DFF}forum.prospectrp.net{FFFFFF}. Registering on the forum will allow you to", msgstring);
	format(msgstring, sizeof(msgstring), "%s\nsubmit faction, gang and many more applications as well as keep you informed of any updates and events.", msgstring);
	format(msgstring, sizeof(msgstring), "%s\nIf this is your first time playing here, it is highly recommended that you take the tutorial as it will\ngive you a brief overview of some of the key features and help you get up to speed quickly.", msgstring);
	
	ShowPlayerDialog(playerid, WELCOME_DIALOG, DIALOG_STYLE_MSGBOX, "Information", msgstring, "Play", "");
}
