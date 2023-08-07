# MUMBAI ROLEPLAY Gamemode script
This repository is <b>archived</b> and is no more being maintained by me, feel free to fork your own and edit as you wish.<br>
If you have any questions related to this script then feel free to contact me on Discord (<b>@renisal</b>)

![Preview of our players tab](https://cdn.discordapp.com/attachments/796834189940228106/1087070669231116409/Screenshot_56.png "Players")

- Address: play.prospectrp.net:7777<br>
- Website: https://www.prospectrp.net<br>
- Forums: https://forum.prospectrp.net
- Some Screenshots: https://imgur.com/a/pKLjYCr (mixed with Prospect RP)

This is gamemode script of the Mumbai Roleplay SA-MP server, a multiplayer mod for Grand Theft Auto San Andreas and with a working database and no errors as of 8th April, 2023. Optimized for **SA-MP mobile client** as well.<br>

A community that ran for several years, formerly known as Prospect Roleplay, although this is not the official gamemode of Prospect Roleplay. This script and project is no longer being maintained, therefore I won't be able to help in debugging anymore.
No major bugs in this script are reported or known to me as of the time of release.

**Credits:** Renisal for Lead Development, Kye, the SA-MP forums, Pedro for his Speedometer, Limitless Roleplay for the base script, and all the developers of the plugins used!<br><br>

Server Setup
----------------------

I have included both plugins for Windows and Linux servers, to set up a quick testing environment on your computer:

- Install XAMMP
- Start the Apache and MySQL server
- Open Phpmyadmin and create a new database
- Put the details of the database in your script
- Run the server


SA-MP 0.3 Server Setup
----------------------

Once the configuration is complete, run> ./samp03svr & to start the server process.

CONFIGURATION:

Example server.cfg:
	echo Executing Server Config...
	lanmode 0
	maxplayers 32
	port 7777
	hostname Unnamed Server
	announce 0
	gamemode0 lvdm 1
	gamemode1 rivershell 1
	weburl www.sa-mp.com
	rcon_password changeme

To configure the server, you must edit the values in server.cfg. They 
are explained below:

hostname
--------
	Parameters:
		string
	
	Description:
		Specifies the hostname shown in the server browser
		
port
----
	Parameters:
		int
	
	Description:
		Specifies the port to listen on.
		This port is used for game connections, rcon 
connections, and for querying.
	
maxplayers
----------
	Parameters:
		int
	
	Description:
		Specifies the maximum amount of players.
		
lanmode
-------
	Parameters:
		int (0 or 1)
		
	Description:
		Turns lanmode on (1) or off (0). Lanmode (as the name 
suggests) is for use on LAN games, where bandwidth is not a problem. 
Lanmode sends data at a higher rate, for a smoother game.
		

announce
-------
	Parameters:
		int (0 or 1)
		
	Description:
		Announces your server to the 'Internet' server list in 
the SA:MP browser. On (1) or Off (0).

weburl
------
	Parameters:
		string
	
	Description:
		Specifies the URL shown in the server browser, which is 
associated to the server.
		
rcon_password
-------------
	Parameters:
		string
		
	Description:
		Specifies the password needed to connect to rcon, or 
login to rcon ingame.
		
gamemode0 - gamemode15
----------------------
	Parameters:
		string
		int
		
	Description:
		Specifies the rotation settings. The first parameter 
sets the game mode name. The second is the number of times it will 
repeat.
		You can use gamemode0 to specify the first gamemode, 
gamemode1 to specify the second, etc.
