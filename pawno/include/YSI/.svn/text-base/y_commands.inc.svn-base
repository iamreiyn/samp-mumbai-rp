/*----------------------------------------------------------------------------*-
					================================
					Y Sever Includes - Commands Core
					================================
Description:
	Runs commands registered with the system and calls the required functions.
	Also handles alternate names and prefixes.  Theory based very loosely on dcmd.
Legal:
	Version: MPL 1.1
	
	The contents of this file are subject to the Mozilla Public License Version 
	1.1 (the "License"); you may not use this file except in compliance with 
	the License. You may obtain a copy of the License at 
	http://www.mozilla.org/MPL/
	
	Software distributed under the License is distributed on an "AS IS" basis,
	WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
	for the specific language governing rights and limitations under the
	License.
	
	The Original Code is the SA:MP script information include.
	
	The Initial Developer of the Original Code is Alex "Y_Less" Cole.
	Portions created by the Initial Developer are Copyright (C) 2008
	the Initial Developer. All Rights Reserved.
	
	Contributors:
		ZeeX, koolk
	
	Thanks:
		Peter, Cam - Support.
		ZeeX - Very productive conversations.
		koolk - IsPlayerinAreaEx code.
		TheAlpha - Danish translation.
		breadfish - German translation.
		Fireburn - Dutch translation.
		yom - French translation.
		50p - Polish translation.
		Zamaroht - Spanish translation.
		Dracoblue, sintax, mabako, Xtreme, other coders - Producing other modes
			for me to strive to better.
		Pixels^ - Running XScripters where the idea was born.
		Matite - Pestering me to release it and using it.
	
	Very special thanks to:
		Thiadmer - PAWN.
		Kye/Kalcor - SA:MP.
		SA:MP Team past, present and future - SA:MP.
Version:
	0.1.4
Changelog:
	20/10/10:
		Fixed a bug with insensitive commands - my fault for not testing.
	06/01/08:
		Improved master and /help support.
	04/01/08:
		Fixed bad element in Command_SetDeniedReturn.
	12/08/07:
		Added master support.
	24/06/07:
		Modifed a few functions to use Bit_GetBit for speed.
	04/05/07:
		Completed command use support.
		Added invalid character protection.
	02/05/07:
		Added YSI_ prefix to all globals.
	14/04/07:
		Updated header documentation with more than changelog/functions.
		Added function name requesting.
	13/04/07:
		Added function documentation.
		Added wrapped functions for e_COMM_FLAG values missing them.
		Added header function list.
	12/04/07:
		Added command removal.
	11/04/07:
		Changed system slightly to handle names and alt names separately.  Still need
		a better way of ignoring names when alt names are used.
	10/04/07:
		First version.
Functions:
	Public:
		Command_Add - Adds a command to the array for processing.
		Command_Remove - Removes a command.
		Command_Name - Gets the name of a command in a property.
	Core:
		Command_Process - Called from OnPlayerCommandText to process entered commands.
		Command_Parse - Sorts added commands into a binary tree.
		Command_Hash - Hashes a word for command hashing.
		Command_ProcRem - Processes a help command in the master script.
	Stock:
		Command_SetDisconnectReturn - Sets the return value for unconnected players.
		Command_UseShortCuts - Toggles use of per-player command shortcuts.
		Command_SetDeniedReturn - Sets the return value for denied use commands.
		Command_UseDeniedMessage - Toggles the use of an error message for denied.
		Command_SetIllegalReturn - Sets the return value for illegal characters.
		Command_UseAltNames - Toggles the use of ini defined alternate names.
		Command_UsePrefix - Toggles the use of a global prefix.
		Command_UseSpace - Toggles the use of a space between prefix and command.
		Command_SetAltName - Sets the alternate name of a function.
		Command_SetPrefix - Sets the pfexix to be typed.
		Comamnd_SetPlayerUse - Sets wether or not a player can use a command.
		Comamnd_SetPlayerUseByID - Sets wether or not a player can use a command.
		Command_FindByName - Finds a command in a possibly sorted list.
	Static:
		Command_FindFast - Finds a function by binary search of function name.
		Command_FindAlt - Finds a function by binary search of alternate name.
		Command_SetSorted - Marks the binary tree as sorted.
		Command_FindSlow - Finds a function by linear search of function name.
		Command_Find - Finds a function from entered text.
		Command_Prefix - Checks the entered prefix.
		Command_ReturnName - Returns the name of a function.
		Command_GetPlayerCount - Gets the number of commands a player can use.
	Inline:
		Command_Command - Not used, constructor.
		Command_IsCleared - Checks a player is cleared to use a command.
		Command_DisconnectReturn - Gets the return value for disconnected players.
		Command_UsingShortCuts - Checks if short cuts are being used.
		Command_DeniedReturn - Gets the return value for prohibited commands.
		Command_IllegalReturn - Gets the return value for invalid characters.
		Command_DeniedMessage - Checks if a level error message should be sent.
		Command_IsSorted - Checks if the binary tree has been initialised.
		Command_UsingAltNames - Checks if alt names are being used.
		Command_UsingPrefix - Checks if the prefix is being used.
		Command_UsingSpace - Checks if the space option is being used.
		Command_CallFunction - Calls the required function.
		ycmd - Adds a command to the system.
	API:
		-
Callbacks:
	-
Definitions:
	MAX_COMMAND_LENGTH - The maximum length of a command string.
	COMMAND_NOT_FOUND - Indicates that a searched for string is not a function.
Enums:
	e_COMM_FLAG - Bit mappings for command options.
	E_COMMANDS - Structure of the array holding the string data.
Macros:
	Command_(%1) - Forwards and declares a standard command for calling.
	ycmd(%1) - Adds a command to the array (wrapper for Command_Add).
Tags:
	e_COMM_FLAG - Flag type.
Variables:
	Global:
		-
	Static:
		YSI_g_sCommands - Holds all the textual data of the commands.
		YSI_g_sSearchTree - Tree of hashes for function names.
		YSI_g_sAltTree - Tree of hashes for alternate names.
		YSI_g_sPrefix - The command prefix.
		YSI_g_sPrefixLength - Length of the prefix.
		YSI_g_sCommandIndex - Pointer to the next free index in the function array.
		YSI_g_sAltCount - The number of commands with altnames.
		YSI_g_sCommandFlags - Bit array of command options.
Commands:
	commands - Lists all commands available to you.
Compile options:
	COMMAND_SENSITIVE - Make commands case sensitive.
	COMMAND_ACCURATE - Can use '@' in command names.
	MAX_COMMANDS - The maximum number of commands which can be used.
-*----------------------------------------------------------------------------*/

#include <YSI\internal\y_version>

#if !defined MAX_COMMANDS
	#define MAX_COMMANDS                (1024)
#endif

#define _GROUP_MAKE_NAME_CMD<%0...%1>   %0Command%1
#define _GROUP_MAKE_LIMIT_CMD           MAX_COMMANDS

#include <YSI\y_master>
#include <YSI\y_groups>

#include <YSI\y_debug>

#include <YSI\y_bintree>
#include <YSI\y_scripting>
#include <YSI\y_playerarray>
#include <YSI\y_utils>

// Define the CMD: macro.  This uses the prefix "@yC_" as it's 32 bits so allows
// for fast command string searching in the publics table and makes the commands
// public without the need for the public keyword.
/*#if YSIM_HAS_MASTER
	#if YSIM_IS_CLIENT
		#define YCMD:%1(%2) static stock yC@_%1(%2)
	#else
		#if YSIM_IS_SERVER
			#define YCMD:%1(%2) forward @yC_%1(a,b[],c);@yC_%1(a,b[],c)U@(8,YSIM_RETURN,yC@_%1(a,b,c));static yC@_%1(%2)
		#else
			#define YCMD:%1(%2) forward @yC_%1(a,b[],c);@yC_%1(a,b[],c)<>{}@yC_%1(a,b[],c)<_YCM:y>U@(8,YSIM_RETURN,yC@_%1(a,b,c));static yC@_%1(%2)
		#endif
	#endif
#else
	#define YCMD:%1(%2) forward @yC_%1(%2);@yC_%1(%2)
#endif*/

#define YCMD:%0(%1) RC:%0(%1)

// ZCMD compatibility.
#define CMD:%0(%1) RC:%0(%1,_h_e_l_p_)if(_h_e_l_p_)return 0;else
#define COMMAND CMD

// This is opposite Scripting_FastString as that's in C, not packed, order.
#define Command_FastString(%1,%2,%3,%4) \
	(((%1) << 24) | ((%2) << 16) | ((%3) << 8) | ((%4) << 0))

#define MAX_COMMAND_LENGTH              (32)

#define COMMAND_NOT_FOUND               (-1)

#if defined COMMAND_SENSITIVE
	#define TOLOWER(%0) (%0)
	#define COMMAND_END_CMP (0)
#else
	#if defined COMMAND_ACCURATE
		#define TOLOWER(%0) tolower(%0)
		#define COMMAND_END_CMP (0)
	#else
		#define TOLOWER(%0) ((%0) | 0x20)
		#define COMMAND_END_CMP (0x20)
	#endif
#endif

// Don't forget the Scripting_FastString below if you change this.
#define COMMAND_FUNCTION_PREFIX         (Command_FastString('@', 'y', 'C', '_'))

// Reset both of these when you remove a command.
#define _Command_IsValid(%0) ((Command_GetPointer(%0)==(%0))||(YSI_g_sCommands[(%0)][E_COMMANDS_MASTERS]==-1))
#define Command_IsValid(%0) ((0<=(%0)<MAX_COMMANDS)&&_Command_IsValid(%0))

enum e_COMM_FLAG (<<= 1)
{
	e_COMM_FLAG_PROVIDER = 0x000000FF,
	e_COMM_FLAG_SORTED = 0x00000100,
	e_COMM_FLAG_PERMISSION_WARN,
	e_COMM_FLAG_USE_ALTNAMES,
	e_COMM_FLAG_PERMISSION_RET,
	e_COMM_FLAG_USE_PREFIX,
	e_COMM_FLAG_USE_SPACE,
	e_COMM_FLAG_USE_SHORTCUTS,
	e_COMM_FLAG_DISCONNECT,
	e_COMM_FLAG_ILLEGAL,
	e_COMM_FLAG_OPCT,
	e_COMM_FLAG_OPC,
	e_COMM_FLAG_COLLISION,
	e_COMM_FLAG_UNKNOWN,
	e_COMM_FLAG_MULPRO
}

enum E_COMMANDS
{
	E_COMMANDS_FUNCTION[MAX_COMMAND_LENGTH char],
	PlayerArray:E_COMMANDS_PLAYERS<MAX_PLAYERS>,
	E_COMMANDS_FUNC_POINTER,
	E_COMMANDS_MASTERS
}

static stock
	YSI_g_sCommands[MAX_COMMANDS][E_COMMANDS],
	BinaryTree:YSI_g_sSearchTree<MAX_COMMANDS>,
	e_COMM_FLAG:YSI_g_sCommandFlags = e_COMM_FLAG:0xFF,
	YSI_g_sCommandIndex,
	YSI_g_sCommandCount,
	//YSI_g_sCommandDialog[MAX_PLAYERS] = {-1, ...},
	YSI_g_sMaster23,
	YSI_g_sPlayerProvider[MAX_PLAYERS char] = {-1, ...};

/*Group:Command_InitialiseFromGroups(x)
{
	//Bit_SetAll(YSI_g_sCommands[x][E_COMMANDS_PLAYERS], true, bits<MAX_PLAYERS>);
	PA_Init(YSI_g_sCommands[x][E_COMMANDS_PLAYERS], true, bits<MAX_PLAYERS>);
}*/

/*----------------------------------------------------------------------------*-
Function:
	Command_Name
Params:
	index - Index of the command to operate on.
Return:
	-
Notes:
	Gets the name of a function from the array.
-*----------------------------------------------------------------------------*/

#define Command_Name(%1) \
	(YSI_g_sCommands[(%1)][E_COMMANDS_FUNCTION][1])

/*----------------------------------------------------------------------------*-
Function:
	Command_GetFuncName
Params:
	index - Index of the command to operate on.
Return:
	-
Notes:
	Gets the full function name for a slot - note that this may not be the right
	function if this slot points to another one.
-*----------------------------------------------------------------------------*/

#define Command_GetFuncName(%1) \
	(YSI_g_sCommands[(%1)][E_COMMANDS_FUNCTION])

/*----------------------------------------------------------------------------*-
Function:
	Command_GetPointer
Params:
	index - Index of the command to operate on.
Return:
	-
Notes:
	Gets the pointer for a function from the array.
-*----------------------------------------------------------------------------*/

#define Command_GetPointer(%1) \
	(YSI_g_sCommands[(%1)][E_COMMANDS_FUNC_POINTER]&0x00FFFFFF)

/*----------------------------------------------------------------------------*-
Function:
	Command_GetProvider
Params:
	index - Index of the command to operate on.
Return:
	-
Notes:
	Gets the unique script in which this version of the command is.
-*----------------------------------------------------------------------------*/

#define Command_Provider(%1) \
	(YSI_g_sCommands[(%1)][E_COMMANDS_FUNC_POINTER]>>>24)

/*----------------------------------------------------------------------------*-
Function:
	Command_GetProvider
Params:
	index - Index of the command to operate on.
Return:
	-
Notes:
	Gets the unique script in which this version of the command is.
-*----------------------------------------------------------------------------*/

#define Command_DefaultProvider() \
	(YSI_g_sCommandFlags & e_COMM_FLAG_PROVIDER)

/*----------------------------------------------------------------------------*-
Function:
	Command_GetFunction
Params:
	index - Index of the command to operate on.
Return:
	-
Notes:
	Gets the real function for this slot.
-*----------------------------------------------------------------------------*/

#define Command_GetFunction(%1) \
	(Command_GetFuncName(Command_GetPointer((%1))))

/*----------------------------------------------------------------------------*-
Function:
	Command_CheckPlayer
Params:
	index - Index of the command to operate on.
	playerid - The player to check for.
Return:
	-
Notes:
	Gets wether a player can use a command.
-*----------------------------------------------------------------------------*/

#define Command_CheckPlayer(%1,%2) \
	(YSI_g_sCommands[(%1)][E_COMMANDS_PLAYERS][Bit_Slot(%2)+1]&Bit_Mask(%2))
	//(PA=([E_COMMANDS_PLAYERS], (%2)))
	//(Bit_Get(YSI_g_sCommands[(%1)][E_COMMANDS_PLAYERS], (%2)))

/*----------------------------------------------------------------------------*-
Function:
	Command_DeniedReturn
Params:
	-
Return:
	e_COMM_FLAG_PERMISSION_RET
Notes:
	-
-*----------------------------------------------------------------------------*/

#define Command_DeniedReturn() \
	(YSI_g_sCommandFlags & e_COMM_FLAG_PERMISSION_RET)

/*----------------------------------------------------------------------------*-
Function:
	Command_SetDeniedReturn
Params:
	-
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

RF@v:Command_SetDeniedReturn[i](bool:set)
{
	if (set)
	{
		YSI_g_sCommandFlags |= e_COMM_FLAG_PERMISSION_RET;
	}
	else
	{
		YSI_g_sCommandFlags &= ~e_COMM_FLAG_PERMISSION_RET;
	}
}

RF@v:Command_SetProvider[i](p)
{
	YSI_g_sCommandFlags = (YSI_g_sCommandFlags & ~e_COMM_FLAG_PROVIDER) | (e_COMM_FLAG:p & e_COMM_FLAG_PROVIDER) | e_COMM_FLAG_MULPRO;
}

RF:Command_GetProvider[]()
{
	return _:Command_DefaultProvider();
}

RF@v:Command_SetPlayerProvider[ii](playerid,p)
{
	if (0 <= playerid < MAX_PLAYERS)
	{
		YSI_g_sPlayerProvider{playerid} = p & 0xFF;
	}
}

RF:Command_GetPlayerProvider[i](playerid)
{
	return YSI_g_sPlayerProvider{playerid};
}

/*----------------------------------------------------------------------------*-
Function:
	Command_GetDeniedReturn
Params:
	-
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

RF@t:bool:Command_GetDeniedReturn[]()
{
	return bool:Command_DeniedReturn();
}

/*----------------------------------------------------------------------------*-
Function:
	Command_HasCollisions
Params:
	-
Return:
	e_COMM_FLAG_COLLISION
Notes:
	-
-*----------------------------------------------------------------------------*/

#define Command_HasCollisions() \
	(YSI_g_sCommandFlags & e_COMM_FLAG_COLLISION)

/*----------------------------------------------------------------------------*-
Function:
	Command_HasCollisions
Params:
	-
Return:
	e_COMM_FLAG_MULPRO
Notes:
	-
-*----------------------------------------------------------------------------*/

#define Command_HasMultipleProviders() \
	(YSI_g_sCommandFlags & e_COMM_FLAG_MULPRO)

/*----------------------------------------------------------------------------*-
Function:
	Command_SetCollisions
Params:
	-
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

#define Command_SetCollisions() \
	YSI_g_sCommandFlags |= e_COMM_FLAG_COLLISION

/*----------------------------------------------------------------------------*-
Function:
	Command_IllegalReturn
Params:
	-
Return:
	e_COMM_FLAG_ILLEGAL
Notes:
	-
-*----------------------------------------------------------------------------*/

#define Command_IllegalReturn() \
	(YSI_g_sCommandFlags & e_COMM_FLAG_ILLEGAL)

/*----------------------------------------------------------------------------*-
Function:
	Command_SetIllegalReturn
Params:
	-
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

RF@v:Command_SetIllegalReturn[i](bool:set)
{
	if (set)
	{
		YSI_g_sCommandFlags |= e_COMM_FLAG_ILLEGAL;
	}
	else
	{
		YSI_g_sCommandFlags &= ~e_COMM_FLAG_ILLEGAL;
	}
}

/*----------------------------------------------------------------------------*-
Function:
	Command_GetIllegalReturn
Params:
	-
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

RF@t:bool:Command_GetIllegalReturn[]()
{
	return bool:Command_IllegalReturn();
}

/*----------------------------------------------------------------------------*-
Function:
	Command_IllegalReturn
Params:
	-
Return:
	e_COMM_FLAG_ILLEGAL
Notes:
	-
-*----------------------------------------------------------------------------*/

#define Command_UnknownReturn() \
	(YSI_g_sCommandFlags & e_COMM_FLAG_UNKNOWN)

/*----------------------------------------------------------------------------*-
Function:
	Command_SetIllegalReturn
Params:
	-
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

RF@v:Command_SetUnknownReturn[i](bool:set)
{
	if (set)
	{
		YSI_g_sCommandFlags |= e_COMM_FLAG_UNKNOWN;
	}
	else
	{
		YSI_g_sCommandFlags &= ~e_COMM_FLAG_UNKNOWN;
	}
}

/*----------------------------------------------------------------------------*-
Function:
	Command_GetIllegalReturn
Params:
	-
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

RF@t:bool:Command_GetUnknownReturn[]()
{
	return bool:Command_UnknownReturn();
}

/*----------------------------------------------------------------------------*-
Function:
	Command_DisconnectReturn
Params:
	-
Return:
	e_COMM_FLAG_DISCONNECT
Notes:
	-
-*----------------------------------------------------------------------------*/

#define Command_DisconnectReturn() \
	(YSI_g_sCommandFlags & e_COMM_FLAG_DISCONNECT)

/*----------------------------------------------------------------------------*-
Function:
	Command_SetDisconnectReturn
Params:
	-
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

RF@v:Command_SetDisconnectReturn[i](bool:set)
{
	if (set)
	{
		YSI_g_sCommandFlags |= e_COMM_FLAG_DISCONNECT;
	}
	else
	{
		YSI_g_sCommandFlags &= ~e_COMM_FLAG_DISCONNECT;
	}
}

/*----------------------------------------------------------------------------*-
Function:
	Command_GetDisconnectReturn
Params:
	-
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

RF@t:bool:Command_GetDisconnectReturn[]()
{
	return bool:Command_DisconnectReturn();
}

/*----------------------------------------------------------------------------*-
Function:
	Command_DeniedDisplay
Params:
	-
Return:
	e_COMM_FLAG_PERMISSION_WARN
Notes:
	-
-*----------------------------------------------------------------------------*/

#define Command_DeniedDisplay() \
	(YSI_g_sCommandFlags & e_COMM_FLAG_PERMISSION_WARN)

/*----------------------------------------------------------------------------*-
Function:
	Command_SetDeniedDisplay
Params:
	-
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

RF@v:Command_SetDeniedDisplay[i](bool:set)
{
	if (set)
	{
		YSI_g_sCommandFlags |= e_COMM_FLAG_PERMISSION_WARN;
	}
	else
	{
		YSI_g_sCommandFlags &= ~e_COMM_FLAG_PERMISSION_WARN;
	}
}

/*----------------------------------------------------------------------------*-
Function:
	Command_GetDeniedDisplay
Params:
	-
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

RF@t:bool:Command_GetDeniedDisplay[]()
{
	return bool:Command_DeniedDisplay();
}

/*----------------------------------------------------------------------------*-
Function:
	Command_GetNameInt
Params:
	f - Command to get the name of.
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

/*RF:Command_GetNameInt[i](f)
{
	if (f >= 0 && f < YSI_g_sCommandIndex)
	{
		setproperty(8, "", YSIM_STRING, Command_Name(f));
		return 1;
	}
	return 0;
}*/

/*----------------------------------------------------------------------------*-
Function:
	Command_GetName
Params:
	funcid - Command to get the name of.
Return:
	-
Notes:

native Command_GetName(funcid);

-*----------------------------------------------------------------------------*/

/*stock Command_GetName(funcid)
{
	new
		buffer[32] = "";
	if (Command_GetNameInt(funcid))
	{
		getproperty(8, "", YSIM_STRING, buffer);
		strunpack(buffer, buffer);
	}
	return buffer;
}*/

/*----------------------------------------------------------------------------*-
Function:
	Command_IsSorted
Params:
	-
Return:
	e_COMM_FLAG_SORTED
Notes:
	-
-*----------------------------------------------------------------------------*/

#define Command_IsSorted() \
	(YSI_g_sCommandFlags & e_COMM_FLAG_SORTED)

/*----------------------------------------------------------------------------*-
Function:
	Command_Generate
Params:
	-
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

RF@v:Command_Generate[]()
{
	P:2("Command_Generate called");
	if (!Command_IsSorted())
	{
		P:3("Command_Generate: Count = %d", YSI_g_sCommandCount);
		new
			data[MAX_COMMANDS][E_BINTREE_INPUT];
		// This is only called once, so we know YSI_g_sCommandCount will be
		// accurate WRT the locations of commands.
		for (new i = 0; i != YSI_g_sCommandCount; ++i)
		{
			data[i][E_BINTREE_INPUT_POINTER] = i;
			new
				hash = Command_PackHash(Command_Name(i));
			// Check for an existing command with this hash.
			if (!Command_HasCollisions())
			{
				for (new j = 0; j != i; ++j)
				{
					if (hash == data[j][E_BINTREE_INPUT_VALUE])
					{
						Command_SetCollisions();
						break;
					}
				}
			}
			C:3(else printf("Command_Generate: Hash = %d", hash););
			P:3("Command_Generate: Hash = %d", hash);
			data[i][E_BINTREE_INPUT_VALUE] = hash;
		}
		Bintree_Generate(YSI_g_sSearchTree, data, YSI_g_sCommandCount);
		P:4("Command_Generate: %d %d %d %d %d", YSI_g_sSearchTree[0][E_BINTREE_TREE_VALUE], YSI_g_sSearchTree[0][E_BINTREE_TREE_LEFT], YSI_g_sSearchTree[0][E_BINTREE_TREE_RIGHT], YSI_g_sSearchTree[0][E_BINTREE_TREE_PARENT], YSI_g_sSearchTree[0][E_BINTREE_TREE_POINTER]);
		// Set sorted to true.
		YSI_g_sCommandFlags |= e_COMM_FLAG_SORTED;
	}
}

/*----------------------------------------------------------------------------*-
Function:
	OnScriptInit
Params:
	-
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

#if defined FILTERSCRIPT
	public OnFilterScriptInit()
#else
	public OnGameModeInit()
#endif
{
	// Set the default provider as any script.
	//YSI_g_sCommandFlags = 0xFF;
	P:1("Command_OnScriptInit called");
	// Initialise the tree.
	#if YSIM_NOT_CLIENT
		Bintree_Reset(YSI_g_sSearchTree);
		YSI_g_sMaster23 = getproperty(8, "x@");
	#endif
	// Make a list of unused commands.
	for (new i = 0; i != MAX_COMMANDS - 1; ++i)
	{
		YSI_g_sCommands[i][E_COMMANDS_FUNC_POINTER] = i + 1;
	}
	YSI_g_sCommands[MAX_COMMANDS - 1][E_COMMANDS_FUNC_POINTER] = -1;
	// Loop through all the possible commands.  Note that this may need to add
	// commands to the remote command system if this is not the master system.
	// The way the master system is designed means that we will know if we are
	// master or not by the time this function is called.
	new
		buffer[32],
		idx;
	// This is the only place where Scripting_FastString is used instead of
	// Commands_FastString as the strings in the AMX are not the same as packed
	// strings - they are in different memory orders.
	while ((idx = Scripting_GetPublicFast(idx, buffer, (Scripting_FastString('@', 'y', 'C', '_')))))
	{
		Command_Add(buffer, _@);
		P:2("Command_OnScriptInit: Adding %s", buffer);
	}
	Command_Generate();
	// Now that all commands have been added to the array, sort it.
	// Now call the next constructor.
	if (funcidx("Command_OnPlayerCommandText") != -1)
	{
		YSI_g_sCommandFlags |= e_COMM_FLAG_OPCT;
	}
	if (funcidx("Command_OnPlayerConnect") != -1)
	{
		YSI_g_sCommandFlags |= e_COMM_FLAG_OPC;
	}
	CallLocalFunction("Command_OnScriptInit", "");
}

#if defined FILTERSCRIPT
	#if defined _ALS_OnFilterScriptInit
		#undef OnFilterScriptInit
	#else
		#define _ALS_OnFilterScriptInit
	#endif
	#define OnFilterScriptInit Command_OnScriptInit
#else
	#if defined _ALS_OnGameModeInit
		#undef OnGameModeInit
	#else
		#define _ALS_OnGameModeInit
	#endif
	#define OnGameModeInit Command_OnScriptInit
#endif
forward Command_OnScriptInit();

/*----------------------------------------------------------------------------*-
Function:
	OnScriptClose
Params:
	script - ID of the closing script.
Return:
	-
Notes:
	Called when a script under the control of the master system ends.
-*----------------------------------------------------------------------------*/

#if YSIM_NOT_CLIENT
	#if YSIM_CLOUD
		public OnScriptClose(script) <>
		{
			CallLocalFunction("Command_OnScriptClose", "i", script);
		}
		
		public OnScriptClose(script) <_YCM:y>
	#elseif YSIM_IS_STUB
		#error y_commands called with YSIM_IS_STUB.
	#else
		public OnScriptClose(script)
	#endif
	{
		new
			mask = ~(1 << script);
		for (new i = 0; i != MAX_COMMANDS; ++i)
		{
			if (Command_GetPointer(i) == i && (YSI_g_sCommands[i][E_COMMANDS_MASTERS] &= mask) == 0)
			{
				for (new j = 0; j != MAX_COMMANDS; ++j)
				{
					// Remove all alternate names.
					if (Command_GetPointer(j) == i)
					{
						YSI_g_sCommands[j][E_COMMANDS_FUNC_POINTER] = YSI_g_sCommandIndex;
						YSI_g_sCommandIndex = j;
						YSI_g_sCommands[j][E_COMMANDS_MASTERS] = 0;
						//Bintree_Delete(YSI_g_sSearchTree, j, YSI_g_sCommandCount);
						Command_RemoveFromBintree(j);
						--YSI_g_sCommandCount;
						//Bintree_Add(YSI_g_sSearchTree, YSI_g_sCommandIndex, hash, YSI_g_sCommandIndex);
					}
				}
			}
			/*new
				p = i;
			while (YSI_g_sCommands[p][E_COMMANDS_MASTERS] == -1)
			{
				p = Command_GetPointer(p);
			}
			if (YSI_g_sCommands[p][E_COMMANDS_FUNC_POINTER] == p && (YSI_g_sCommands[p][E_COMMANDS_MASTERS] &= mask) == 0)
			{
				// Remove all alternate versions of commands - done backwards by
				// an alternate command checking its parent.  Can also handle
				// alternate versions of alternate commands (note this is the
				// only code that can currently).
				YSI_g_sCommands[i][E_COMMANDS_MASTERS] = 0;
				YSI_g_sCommands[i][E_COMMANDS_FUNC_POINTER] = YSI_g_sCommandIndex;
				YSI_g_sCommandIndex = i;
				// Mark it as invalid in this instance.
				YSI_g_sCommands[i][E_COMMANDS_MASTERS] = 0;
				// Reduce the number of commands.
				--YSI_g_sCommandCount;
			}*/
		}
		YSI_g_sMaster23 = getproperty(8, "x@");
		// I can add better removal code later.  Done ^
		CallLocalFunction("Command_OnScriptClose", "i", script);
	}
	
	// Don't need ALS here as we did it supporting it at the start.
	#undef OnScriptClose
	#define OnScriptClose Command_OnScriptClose
	forward Command_OnScriptClose(script);
#endif

/*----------------------------------------------------------------------------*-
Function:
	OnPlayerConnect
Params:
	-
Return:
	-
Notes:
	-
-*----------------------------------------------------------------------------*/

// TODO: Rewrite!
//RA:Command_OnPlayerConnect(playerid)

#if YSIM_NOT_CLIENT
	#if YSIM_CLOUD
		public OnPlayerConnect(playerid) <>
		{
			YSI_g_sPlayerProvider{playerid} = 0xFF;
			if (YSI_g_sCommandFlags & e_COMM_FLAG_OPC)
			{
				return CallLocalFunction("Command_OnPlayerConnect", "i", playerid);
			}
			return 1;
		}
		
		public OnPlayerConnect(playerid) <_YCM:y>
	#elseif YSIM_IS_STUB
		#error y_commands called with YSIM_IS_STUB.
	#else
		public OnPlayerConnect(playerid)
	#endif
	{
		//#if YSIM_NOT_CLIENT
		//YSI_g_sCommandDialog[playerid] = -1;
		YSI_g_sPlayerProvider{playerid} = 0xFF;
		NO_GROUPS()
		{
			new
				slot = Bit_Slot(playerid) + 1,
				Bit:mask = Bit_Mask(playerid); //Bit:(1 << (playerid & (cellbits - 1)));
			for (new i = 0; i != MAX_COMMANDS; ++i)
			{
				YSI_g_sCommands[i][E_COMMANDS_PLAYERS][slot] |= mask;
				//PA+(YSI_g_sCommands[i][E_COMMANDS_PLAYERS], mask);
			}
		}
		//#endif
		// Groups will ALWAYS be called after this function - so this can reset
		// player permissions however it likes with the group system then being
		// able to override anything set in here.
		if (YSI_g_sCommandFlags & e_COMM_FLAG_OPC)
		{
			return CallLocalFunction("Command_OnPlayerConnect", "i", playerid);
		}
		return 1;
		//ALS_CALL<PlayerConnect, i>(playerid)
	}
	
	#if defined _ALS_OnPlayerConnect
		#undef OnPlayerConnect
	#else
		#define _ALS_OnPlayerConnect
	#endif
	#define OnPlayerConnect Command_OnPlayerConnect
	forward Command_OnPlayerConnect(playerid);
#endif

/*----------------------------------------------------------------------------*-
Function:
	Command_
Params:
	command - Command to declare.
Return:
	-
Notes:
	Deprecated!
-*----------------------------------------------------------------------------*/

#define Command_(%1) \
	CMD:%1(playerid,params[],help)

/*----------------------------------------------------------------------------*-
Function:
	ycmd
Params:
	command[] - Command to register.
Return:
	-
Notes:
	Deprecated!
-*----------------------------------------------------------------------------*/

#define ycmd(%1);

/*----------------------------------------------------------------------------*-
Function:
	Command_FindFast
Params:
	data[] - Function name to find.
	value - Hash of function name.
Return:
	Position in functions array or COMMAND_NOT_FOUND.
Notes:
	-
-*----------------------------------------------------------------------------*/

static stock Command_FindFast(data[], value, provider = 0xFF)
{
	new
		leaf,
		pointer;
	P:5("Command_FindFast: Searching for %s", data);
	while ((pointer = Bintree_FindValue(YSI_g_sSearchTree, value, leaf)) != BINTREE_NOT_FOUND)
	{
		new
			p = YSI_g_sCommands[pointer][E_COMMANDS_FUNC_POINTER];
		if (Command_HasMultipleProviders() && (p & 0xFF000000 != 0xFF000000) && (p >>> 24 != provider)) continue;
		// Don't do an strcmp if there are no collisions.
		if (!Command_HasCollisions()) return pointer;
		//if (!strcmp(YSI_g_sCommands[i][E_COMMANDS_FUNCTION][1], funcname) &&
		if (!strcmp(Command_Name(pointer), data)) return pointer;
		//if (!strcmp(Command_Name(pointer), data) && (Command_GetProvider(pointer) == 0xFF || Command_GetProvider(pointer) == provider)) return pointer;
	}
	P:5("Command_FindFast: Not found");
	return COMMAND_NOT_FOUND;
}

static stock Command_FindFastStrict(data[], value, provider)
{
	new
		leaf,
		pointer;
	P:5("Command_FindFast: Searching for %s", data);
	while ((pointer = Bintree_FindValue(YSI_g_sSearchTree, value, leaf)) != BINTREE_NOT_FOUND)
	{
		if (Command_HasMultipleProviders() && (YSI_g_sCommands[pointer][E_COMMANDS_FUNC_POINTER] >>> 24 != provider)) continue;
		// Don't do an strcmp if there are no collisions.
		if (!Command_HasCollisions()) return pointer;
		if (!strcmp(Command_Name(pointer), data)) return pointer;
	}
	P:5("Command_FindFast: Not found");
	return COMMAND_NOT_FOUND;
}

/*----------------------------------------------------------------------------*-
Function:
	Command_FindSlow
Params:
	funcname[] - Function to find.
Return:
	-
Notes:
	Searches through the array for function linearly - used to set altnames
	before the data has been sorted.
-*----------------------------------------------------------------------------*/

static stock Command_FindSlow(funcname[], provider = 0xFF)
{
	for (new i = 0; i != MAX_COMMANDS; ++i)
	{
		new
			p = YSI_g_sCommands[i][E_COMMANDS_FUNC_POINTER];
		if (((p & 0x00FFFFFF == i) || (YSI_g_sCommands[i][E_COMMANDS_MASTERS] == -1)) &&
			(!Command_HasMultipleProviders() || (p & 0xFF000000 == 0xFF000000) || (p >>> 24 == provider)) &&
			!strcmp(Command_Name(i), funcname))
		{
			return i;
		}
	}
	return COMMAND_NOT_FOUND;
}

/*----------------------------------------------------------------------------*-
Function:
	Command_FindSlowStrict
Params:
	funcname[] - Function to find.
Return:
	-
Notes:
	Searches through the array for function linearly - used to set altnames
	before the data has been sorted.
-*----------------------------------------------------------------------------*/

static stock Command_FindSlowStrict(funcname[], provider)
{
	for (new i = 0; i != MAX_COMMANDS; ++i)
	{
		new
			p = YSI_g_sCommands[i][E_COMMANDS_FUNC_POINTER];
		// This needs additional checks that the item is valid.
		if (((p & 0x00FFFFFF == i) || (YSI_g_sCommands[i][E_COMMANDS_MASTERS] == -1)) &&
			(!Command_HasMultipleProviders() || (p >>> 24 == provider)) &&
			!strcmp(Command_Name(i), funcname))
		{
			return i;
		}
	}
	return COMMAND_NOT_FOUND;
}

/*----------------------------------------------------------------------------*-
Function:
	Command_AddHash
Params:
	command[] - Command text to hash.
	dest[] - Array to copy to.
	idx - Point to start copying from.
Return:
	hash value.
Notes:
	Hashes a string and copies it to a destination at the same time.
-*----------------------------------------------------------------------------*/

static stock Command_AddHash(command[], dest[], idx)
{
	// Skip the function name prefix.
	new
		hash = -1,
		ch,
		dx = 1,
		end = idx + 28;
	// Copy and hash at the same time.
	do
	{
		/*ch = TOLOWER(command[idx++]);
		// Always NULL terminate.
		if ((dest[dx] = ch << 24) == COMMAND_END_CMP << 24)
		{
			// Fixes a bug with commands multiples of 4 chars long.
			dest[dx] = 0;
			break;
		}*/
		ch = TOLOWER(command[idx++]);
		if (ch == COMMAND_END_CMP) break;
		dest[dx] = ch << 24;
		hash = hash * 33 + ch; //Command_ToUpper(ch);
		ch = TOLOWER(command[idx++]);
		if (ch == COMMAND_END_CMP) break;
		dest[dx] |= ch << 16;
		hash = hash * 33 + ch; //Command_ToUpper(ch);
		ch = TOLOWER(command[idx++]);
		if (ch == COMMAND_END_CMP) break;
		dest[dx] |= ch << 8;
		hash = hash * 33 + ch; //Command_ToUpper(ch);
		ch = TOLOWER(command[idx++]);
		if (ch == COMMAND_END_CMP) break;
		dest[dx] |= ch << 0;
		hash = hash * 33 + ch; //Command_ToUpper(ch);
		++dx;
	}
	while (idx < end);
	return hash;
}

/*----------------------------------------------------------------------------*-
Function:
	Command_FastHash
Params:
	command[] - Command text to hash.
Return:
	hash value.
Notes:
	Just hashes the passed string.
-*----------------------------------------------------------------------------*/

static stock Command_FastHash(command[])
{
	new
		index = 0,
		hash = -1,
		ch;
	while ((ch = command[index++])) hash = hash * 33 + TOLOWER(ch);
	return hash;
}

/*----------------------------------------------------------------------------*-
Function:
	Command_PackHash
Params:
	command[] - Command text to hash.
Return:
	hash value.
Notes:
	Hashes packed strings.
-*----------------------------------------------------------------------------*/

static stock Command_PackHash(command[])
{
	new
		index = 0,
		hash = -1,
		ch;
	while ((ch = command[index++]))
	{
		P:4("Commands_PackHash: ch = 0x%04x%04x", ch >>> 16, ch & 0xFFFF);
		if (ch & 0xFF000000)
		{
			hash = hash * 33 + TOLOWER(ch >>> 24);
			P:5("Command_PackHash: Hash1 = %d", hash);
		}
		else
		{
			break;
		}
		if (ch & 0x00FF0000)
		{
			hash = hash * 33 + TOLOWER(ch >> 16 & 0xFF);
			P:5("Command_PackHash: Hash2 = %d", hash);
		}
		else
		{
			break;
		}
		if (ch & 0x0000FF00)
		{
			hash = hash * 33 + TOLOWER(ch >> 8 & 0xFF);
			P:5("Command_PackHash: Hash3 = %d", hash);
		}
		else
		{
			break;
		}
		if (ch & 0x000000FF)
		{
			hash = hash * 33 + TOLOWER(ch & 0xFF);
			P:5("Command_PackHash: Hash4 = %d", hash);
		}
		else
		{
			break;
		}
	}
	return hash;
}

/*----------------------------------------------------------------------------*-
Function:
	Command_Hash
Params:
	command[] - Command text to hash.
	&index - Start point and variable to store end point to.
	&length - Length of the hashed word.
Return:
	hash value.
Notes:
	Hashes a string using space delimiters and returns information such as the
	length of the string hased and the start point of the next word.
-*----------------------------------------------------------------------------*/

static stock Command_Hash(command[], &index, &length)
{
	new
		hash = -1,
		ch;
	length = index;
	while ((ch = command[index++]) > ' ') hash = hash * 33 + TOLOWER(ch);
	length = index - length - 1;
	while (ch)
	{
		if (ch > ' ')
		{
			break;
		}
		ch = command[index++];
	}
	--index;
	return hash;
}

/*----------------------------------------------------------------------------*-
Function:
	Command_Find
Params:
	function[] - Function name to find.
Return:
	Position in functions array or COMMAND_NOT_FOUND.
Notes:
	Used by API functions to avoid repeated sorting checks.
-*----------------------------------------------------------------------------*/

static stock Command_Find(function[], provider = -1)
{
	if (provider == -1)
	{
		provider = _:Command_DefaultProvider();
		// Find the ID of the command.
		if (Command_IsSorted())
		{
			return Command_FindFast(function, Command_FastHash(function), provider);
		}
		else
		{
			return Command_FindSlow(function, provider);
		}
	}
	else
	{
		provider &= 0xFF;
		// Find the ID of the command.
		if (Command_IsSorted())
		{
			return Command_FindFastStrict(function, Command_FastHash(function), provider);
		}
		else
		{
			return Command_FindSlowStrict(function, provider);
		}
	}
}

/*----------------------------------------------------------------------------*-
Function:
	Command_GetID
Params:
	function[] - Function name to find.
Return:
	The ID of the passed function.
Notes:
	-

native Command_GetID(function[])

-*----------------------------------------------------------------------------*/

RF@p:Command_GetID[s](function[])<function>
{
	return Command_Find(function);
}

/*----------------------------------------------------------------------------*-
Function:
	Command_SetPlayer
Params:
	command - Command to set for.
	playerid - Player to set.
	bool:set - Wether or not this player can use this command.
Return:
	-
Notes:
	-

native bool:Command_SetPlayer(command, playerid, bool:set);

-*----------------------------------------------------------------------------*/

RF@pv:Command_SetPlayer[iii](c,p,bool:s)<c,p,s>
{
//	if (c < 0 || c >= YSI_g_sCommandIndex)
	if (0 <= c < MAX_COMMANDS)
	{
		//Bit_Set(YSI_g_sCommands[c][E_COMMANDS_PLAYERS], p, s, bits<MAX_PLAYERS>);
		if (s) PA+(YSI_g_sCommands[c][E_COMMANDS_PLAYERS], p);
		else PA-(YSI_g_sCommands[c][E_COMMANDS_PLAYERS], p);
		// Not in range,
//		return false;
	}
//	return s;
}

/*----------------------------------------------------------------------------*-
Function:
	Command_SetPlayerNamed
Params:
	funcname[] - Command to set for.
	playerid - Player to set.
	set - Wether or not this player can use this command.
Return:
	-
Notes:
	Like Command_SetPlayer but for a function name.

native bool:Command_SetPlayerNamed(funcname[], playerid, bool:set);

-*----------------------------------------------------------------------------*/

RF@pv:Command_SetPlayerNamed[sii](f[],p,bool:s)<f,p,s>
{
	Command_SetPlayer(Command_Find(f), p, s);
}

/*----------------------------------------------------------------------------*-
Function:
	Command_GetPlayer
Params:
	command - Command to get for.
	playerid - Player to get.
Return:
	Wether this player can use this command.
Notes:
	-

native bool:Command_GetPlayer(command, playerid);

-*----------------------------------------------------------------------------*/

RF@t:bool:Command_GetPlayer[ii](command, playerid)
{
	if (0 <= command < MAX_COMMANDS)
	{
		return bool:Command_CheckPlayer(command, playerid);
	}
	// Not in range,
	return false;
}

/*----------------------------------------------------------------------------*-
Function:
	Command_GetPlayerNamed
Params:
	funcname[] - Command to get for.
	playerid - Player to get.
Return:
	-
Notes:
	Like Command_GetPlayer but for a function name.

native bool:Command_GetPlayerNamed(funcname[], playerid);

-*----------------------------------------------------------------------------*/

RF@pt:bool:Command_GetPlayerNamed[si](func[], playerid)<func, playerid>
{
	return Command_GetPlayer(Command_Find(func), playerid);
}

/*----------------------------------------------------------------------------*-
Function:
	Command_Remove
Params:
	func - The slot of the command to remove.
Return:
	-
Notes:

native Command_Remove(func);

-*----------------------------------------------------------------------------*/

static stock Command_RemoveFromBintree(func)
{
	if (!Command_IsSorted()) return;
	// This function has to find the right index in the binary tree, as that's
	// not in the same order at all.
	new
		leaf,
		hash = Command_PackHash(Command_Name(func));
	// Find where in the binary tree this is referenced from.
	while (Bintree_FindValue(YSI_g_sSearchTree, hash, _, leaf) != BINTREE_NOT_FOUND)
	{
		if (YSI_g_sSearchTree[leaf][E_BINTREE_TREE_POINTER] == func)
		{
			P:2("Command_RemoveFromBintree: Delete branch");
			Bintree_Delete(YSI_g_sSearchTree, leaf, YSI_g_sCommandCount);
			return;
		}
	}
}

RF:Command_Remove[i](func)
{
	P:2("Command_Remove called (%d)", func);
	if (0 <= func < MAX_COMMANDS)
	{
		if (Command_GetPointer(func) == func)
		{
			for (new i = 0; i != MAX_COMMANDS; ++i)
			{
				// Remove all alternate names.
				if (Command_GetPointer(i) == func)
				{
					// Add this to the list of unused functions.
					YSI_g_sCommands[i][E_COMMANDS_FUNC_POINTER] = YSI_g_sCommandIndex;
					YSI_g_sCommandIndex = i;
					// Mark it as invalid in this instance.
					YSI_g_sCommands[i][E_COMMANDS_MASTERS] = 0;
					// Reduce the number of commands.
					//Bintree_Delete(YSI_g_sSearchTree, i, YSI_g_sCommandCount);
					Command_RemoveFromBintree(i);
					--YSI_g_sCommandCount;
				}
			}
		}
		else if (YSI_g_sCommands[func][E_COMMANDS_MASTERS] == -1)
		{
			// Remove a single alternate name.
			YSI_g_sCommands[func][E_COMMANDS_FUNC_POINTER] = YSI_g_sCommandIndex;
			YSI_g_sCommandIndex = func;
			YSI_g_sCommands[func][E_COMMANDS_MASTERS] = 0;
			//Bintree_Delete(YSI_g_sSearchTree, func, YSI_g_sCommandCount);
			Command_RemoveFromBintree(func);
			--YSI_g_sCommandCount;
		}
		return 1;
	}
	return 0;
}

RF@p:Command_RemoveNamed[s](func[])<func>
{
	P:2("Command_RemoveNamed called (%s)", func);
	return Command_Remove(Command_Find(func));
}

/*----------------------------------------------------------------------------*-
Function:
	Command_Add
Params:
	funcname[] - The function to add to the array.
	script - The script ID with the function.
Return:
	-
Notes:
	If the list of commands have already been sorted into the binary tree the
	new commands will be appended, otherwise they will just be added to the
	array.

native Command_Add(funcname[], script);

-*----------------------------------------------------------------------------*/

RF@pv:Command_Add[si](f[],s)<f,s>
{
	P:2("Command_Add called");
	if (YSI_g_sCommandCount < MAX_COMMANDS && YSI_g_sCommandIndex != -1)
	{
		new
			hash = Command_AddHash(f, YSI_g_sCommands[YSI_g_sCommandIndex][E_COMMANDS_FUNCTION], 4),
			provider = _:Command_DefaultProvider();
		if (Command_IsSorted())
		{
			new
				idx = Command_FindFastStrict(f[4], hash, provider);
			if (idx != COMMAND_NOT_FOUND)
			{
				YSI_g_sCommands[idx][E_COMMANDS_MASTERS] |= 1 << s;
				return;
			}
			if (!Command_HasCollisions())
			{
				// Check for an existing command with this hash.
				if (Bintree_FindValue(YSI_g_sSearchTree, hash) != BINTREE_NOT_FOUND)
				{
					Command_SetCollisions();
				}
			}
			// Command doesn't exist already - good!
			Bintree_Add(YSI_g_sSearchTree, YSI_g_sCommandIndex, hash, YSI_g_sCommandIndex);
		}
		else
		{
			new
				idx = Command_FindSlowStrict(f[4], provider);
			if (idx != COMMAND_NOT_FOUND)
			{
				YSI_g_sCommands[idx][E_COMMANDS_MASTERS] |= 1 << s;
				return;
			}
		}
		YSI_g_sCommands[YSI_g_sCommandIndex][E_COMMANDS_FUNCTION][0] = COMMAND_FUNCTION_PREFIX;
		//Bit_SetAll(YSI_g_sCommands[YSI_g_sCommandIndex][E_COMMANDS_PLAYERS], true, bits<MAX_PLAYERS>);
		//Command_InitialiseFromGroups(YSI_g_sCommandIndex);
		NO_GROUPS(YSI_g_sCommandIndex)
		{
			PA_Init(YSI_g_sCommands[YSI_g_sCommandIndex][E_COMMANDS_PLAYERS], true);
		}
		// Swap these.
		YSI_g_sCommands[YSI_g_sCommandIndex][E_COMMANDS_MASTERS] = 1 << s;
		hash = YSI_g_sCommandIndex;
		// Set this command as usable in any script.
		YSI_g_sCommandIndex = YSI_g_sCommands[hash][E_COMMANDS_FUNC_POINTER];
		YSI_g_sCommands[hash][E_COMMANDS_FUNC_POINTER] = hash | (provider << 24);
		// Now some complex debug rubbish.
		P:2("Command_Add: Command added in %d", YSI_g_sCommandIndex);
		P:4("Command_Add: %08x%08x%08x%08x", YSI_g_sCommands[YSI_g_sCommandIndex][E_COMMANDS_FUNCTION][0], YSI_g_sCommands[YSI_g_sCommandIndex][E_COMMANDS_FUNCTION][1], YSI_g_sCommands[YSI_g_sCommandIndex][E_COMMANDS_FUNCTION][2], YSI_g_sCommands[YSI_g_sCommandIndex][E_COMMANDS_FUNCTION][3]);
		C:4(new str[32];strpack(str, f);printf("Command_Add: %08x%08x%08x%08x", str[0], str[1], str[2], str[3]););
		++YSI_g_sCommandCount;
	}
	/*else
	{
		// Not all hope is lost - check if this command name already exists.
		if (Command_IsSorted())
		{
			new
				pos = Command_FindFast(funcname[4], Command_FastHash(funcname[4]));
			if (pos != COMMAND_NOT_FOUND)
			{
				// Found it already in the array.
				return pos;
			}
		}
		else
		{
			new
				pos = Command_FindSlow(funcname[4]);
			if (pos != COMMAND_NOT_FOUND)
			{
				// Command already exists.
				return pos;
			}
		}
	}
	return COMMAND_NOT_FOUND;*/
}

/*----------------------------------------------------------------------------*-
Function:
	Command_AddAlt
Params:
	funcidx - The function this is an alternate to.
	altname[] - The new name.
Return:
	-
Notes:
	If the list of commands have already been sorted into the binary tree the
	new commands will be appended, otherwise they will just be added to the
	array.

native Command_AddAlt(funcidx, altname[]);

-*----------------------------------------------------------------------------*/

RF@p:Command_AddAlt[is](oidx, altname[])<oidx, altname>
{
	if (!Command_IsValid(oidx))
	{
		return COMMAND_NOT_FOUND;
	}
	new
		provider = _:Command_DefaultProvider();
	if (YSI_g_sCommandCount < MAX_COMMANDS && YSI_g_sCommandIndex != -1)
	{
		new
			hash = Command_AddHash(altname, YSI_g_sCommands[YSI_g_sCommandIndex][E_COMMANDS_FUNCTION], 0);
		if (Command_IsSorted())
		{
			// Find the function this mirrors.
			//oidx = Command_FindFast(function, Command_FastHash(function));
			new
				pos = Command_FindFastStrict(altname, hash, provider);
			if (pos != COMMAND_NOT_FOUND)
			{
				if (Command_GetPointer(pos) != oidx)
				{
					// Same altname, different function.
					return COMMAND_NOT_FOUND;
				}
				return pos;
			}
			// Command doesn't exist already - good!
			Bintree_Add(YSI_g_sSearchTree, YSI_g_sCommandIndex, hash, YSI_g_sCommandIndex);
		}
		else
		{
			new
				pos = Command_FindSlowStrict(altname, provider);
			if (pos != COMMAND_NOT_FOUND)
			{
				if (Command_GetPointer(pos) != oidx)
				{
					// Same altname, different function.
					return COMMAND_NOT_FOUND;
				}
				// Command already exists.
				return pos;
			}
		}
		YSI_g_sCommands[YSI_g_sCommandIndex][E_COMMANDS_FUNCTION][0] = COMMAND_FUNCTION_PREFIX;
		//Bit_SetAll(YSI_g_sCommands[YSI_g_sCommandIndex][E_COMMANDS_PLAYERS], true, bits<MAX_PLAYERS>);
		//Command_InitialiseFromGroups(YSI_g_sCommandIndex);
		NO_GROUPS(YSI_g_sCommandIndex)
		{
			PA_Init(YSI_g_sCommands[YSI_g_sCommandIndex][E_COMMANDS_PLAYERS], true);
		}
		++YSI_g_sCommandCount;
		// This doesn't have real masters.
		YSI_g_sCommands[YSI_g_sCommandIndex][E_COMMANDS_MASTERS] = -1;
		hash = YSI_g_sCommandIndex;
		YSI_g_sCommandIndex = YSI_g_sCommands[hash][E_COMMANDS_FUNC_POINTER];
		YSI_g_sCommands[hash][E_COMMANDS_FUNC_POINTER] = oidx | (provider << 24);
		return hash;
	}
	else
	{
		// Not all hope is lost - check if this command name already exists.
		new
			pos;
		if (Command_IsSorted())
		{
			pos = Command_FindFastStrict(altname, Command_FastHash(altname), provider);
		}
		else
		{
			pos = Command_FindSlowStrict(altname, provider);
		}
		if (pos != COMMAND_NOT_FOUND)
		{
			// Found it already in the array.  Check if the element it points to
			// has the correct name so we know this is the correct pair, not
			// just the correct single element.  I.e. check that this is the
			// correct original/altname combo, not the right altname on a
			// different original name.
			if (oidx == Command_GetPointer(pos))
			{
				return pos;
			}
		}
	}
	return COMMAND_NOT_FOUND;
}

/*----------------------------------------------------------------------------*-
Function:
	Command_AddAltNamed
Params:
	function[] - The function this is an alternate to.
	altname[] - The new name.
Return:
	-
Notes:
	Add an alternate command for an existing command.

native Command_AddAltNamed(function[], altname[]);

-*----------------------------------------------------------------------------*/

RF@p:Command_AddAltNamed[ss](function[], altname[])<function, altname>
{
	return Command_AddAlt(Command_Find(function), altname);
}

/*----------------------------------------------------------------------------*-
Function:
	Command_Debug
Params:
	-
Return:
	-
Notes:
	Print some random information about commands if _DEBUG is set.
-*----------------------------------------------------------------------------*/

stock Command_Debug()
{
	#if _DEBUG > 0
		printf("Command_Debug: Start");
		for (new i = 0; i != MAX_COMMANDS; ++i)
		{
			if (Command_IsValid(i))
			{
				printf("Command_Debug: Loop start %d", i);
				new buffer[MAX_COMMAND_LENGTH];
				strunpack(buffer, Command_Name(i));
				printf("%08x%08x%08x", YSI_g_sCommands[i][E_COMMANDS_FUNCTION][0], YSI_g_sCommands[i][E_COMMANDS_FUNCTION][1], YSI_g_sCommands[i][E_COMMANDS_FUNCTION][2]);
				new pointer = Command_GetPointer(i);
				printf("Command %d:", i);
				printf("\t%s", buffer);
				printf("\t%d", pointer);
				printf("\t%d %d %d", YSI_g_sSearchTree[i][E_BINTREE_TREE_LEFT], YSI_g_sSearchTree[i][E_BINTREE_TREE_RIGHT], YSI_g_sSearchTree[i][E_BINTREE_TREE_VALUE]);
				CallLocalFunction(Command_GetFunction(Command_GetPointer(i)), "isi", 0, "hi", 0);
				printf("Command_Debug: Loop end");
			}
		}
		printf("Command_Debug: End");
	#endif
}

/*----------------------------------------------------------------------------*-
Function:
	OnPlayerCommandText
Params:
	playerid - Player who entered the command.
	cmdtext[] - Text entered.
Return:
	true - success or hidden fail, false - fail.
Notes:
	Calls the Command_Process function if this is not a client.
-*----------------------------------------------------------------------------*/

#if YSIM_NOT_CLIENT
	#if YSIM_CLOUD
		public OnPlayerCommandText(playerid, cmdtext[]) <>
		{
			if (YSI_g_sCommandFlags & e_COMM_FLAG_OPCT)
			{
				return CallLocalFunction("Command_OnPlayerCommandText", "is", playerid, cmdtext);
			}
			return 0;
		}
		
		public OnPlayerCommandText(playerid, cmdtext[]) <_YCM:y>
	#elseif YSIM_IS_STUB
		#error y_commands called with YSIM_IS_STUB.
	#else
		public OnPlayerCommandText(playerid, cmdtext[])
	#endif
	{
		if (Command_Process(playerid, cmdtext, 0))
		{
			return 1;
		}
		if (YSI_g_sCommandFlags & e_COMM_FLAG_OPCT)
		{
			return CallLocalFunction("Command_OnPlayerCommandText", "is", playerid, cmdtext);
		}
		return 0;
	}
	
	#if defined _ALS_OnPlayerCommandText
		#undef OnPlayerCommandText
	#else
		#define _ALS_OnPlayerCommandText
	#endif
	#define OnPlayerCommandText Command_OnPlayerCommandText
	forward Command_OnPlayerCommandText(playerid, cmdtext[]);
#endif

/*----------------------------------------------------------------------------*-
Function:
	Command_ReProcess
Params:
	playerid - Player who entered the command.
	cmdtext[] - Text entered.
	help - Called from the help commmand or OnPlayerCommandText.
Return:
	true - success or hidden fail, false - fail.
Notes:
	-
-*----------------------------------------------------------------------------*/

RF@p:Command_ReProcess[isi](p,c[],h)<p,c,h>
{
	return Command_Process(p,c,h);
}

/*----------------------------------------------------------------------------*-
Function:
	Command_Process
Params:
	playerid - Player who entered the command.
	cmdtext[] - Text entered.
	help - Called from the help commmand or OnPlayerCommandText.
Return:
	true - success or hidden fail, false - fail.
Notes:
	-
-*----------------------------------------------------------------------------*/

#define Command_CallR(%1,%2) \
	CallRemoteFunction(Command_GetFunction((%1)), "isii", playerid, %2, help, master)

#define Command_CallL(%1,%2) \
	CallLocalFunction(Command_GetFunction((%1)), "isi", playerid, %2, help)

static stock Command_Process(playerid, cmdtext[], help)
{
	// Support for very old problems!
	// TODO: Add back.
	P:2("Command_Process called: %d %s", playerid, cmdtext);
	#if !_DEBUG && !defined _YSI_SPECIAL_DEBUG
		// For testing purposes.
		if (!IsPlayerConnected(playerid))
		{
			return Command_DisconnectReturn();
		}
	#endif
	P:4("Command_Process: Connected");
	new
		idx,
		prelen = help ? 0 : 1,
		index = prelen;
	/*// Shortcuts.
	if (cmdtext[2] <= ' ')
	{
		// Get a player's shortcut information for this letter.
	}
	else*/
	{
		// No more faffing about with random alternate code - it's all done in
		// one nice function instead of having to handle both separately.
		new
			length,
			hash = Command_Hash(cmdtext, index, length);
		P:3("Command_Process: Hash = %d, Length = %d", hash, length);
		// NOTE: No prefix support here.
		cmdtext[length + prelen] = '\0';
		P:3("Command_Process: Provider: %d", YSI_g_sPlayerProvider{playerid});
		idx = Command_FindFast(cmdtext[prelen], hash, YSI_g_sPlayerProvider{playerid});
		// TODO: Replace!
		//idx = Command_FindSlow(cmdtext[prelen]);//, hash);
	}
	P:3("Command_Process: Index = %d", idx);
	if (idx != COMMAND_NOT_FOUND)
	{
		// Get the master data for the underlying command, not the possibly
		// changed name.
		new
			pointer = Command_GetPointer(idx),
			master = YSI_g_sCommands[pointer][E_COMMANDS_MASTERS];
		if (!master)
		{
			// No scripts can serve the code.
			return Command_UnknownReturn();
		}
		P:4("Command_Process: Found %d", idx);
		// Found a command with this name - check the permissions.
		//if (Bit_Get(YSI_g_sCommands[idx][E_COMMANDS_PLAYERS], playerid))
		if (Command_CheckPlayer(idx, playerid))
		{
			P:4("Command_Process: Allowed");
			// Allowed to use the command, get the real function.  Note that
			// this may well be the same as "idx", but we loose no time.
			#if YSIM_HAS_MASTER
				P:4("Command_Process: %08x%08x%08x%08x", YSI_g_sCommands[idx][E_COMMANDS_FUNCTION][0], YSI_g_sCommands[idx][E_COMMANDS_FUNCTION][1], YSI_g_sCommands[idx][E_COMMANDS_FUNCTION][2], YSI_g_sCommands[idx][E_COMMANDS_FUNCTION][3]);
				if (master & 1 << YSI_g_sMaster23)
				{
					master = YSI_g_sMaster23;
				}
				else
				{
					// Find the lowest set bit.
					static const
						scDeBruijn[] =
							{
								0,  1,  28, 2,  29, 14, 24, 3,  30, 22, 20, 15, 25, 17, 4,  8, 
								31, 27, 13, 23, 21, 19, 16, 7,  26, 12, 18, 6,  11, 5,  10, 9
							};
					// http://supertech.csail.mit.edu/papers/debruijn.pdf
					master = scDeBruijn[((master & -master) * 0x077CB531) >>> 27];
				}
				P:3("Command_Process: master = %d", master);
				if (cmdtext[index])
				{
					// Call it!
					Command_CallR(pointer, cmdtext[index]);
				}
				else
				{
					Command_CallR(pointer, NULL);
				}
				// Get the real return.
				P:1("Command_Process: return: %d", getproperty(8, YSIM_RETURN));
				return getproperty(8, YSIM_RETURN);
			#else
				if (cmdtext[index])
				{
					// Call it!
					return Command_CallL(pointer, cmdtext[index]);
				}
				else
				{
					return Command_CallL(pointer, NULL);
				}
			#endif
		}
		else
		{
			return Command_DeniedReturn();
		}
	}
	P:5("Command_Process: Not found");
	return Command_UnknownReturn();
}

/*----------------------------------------------------------------------------*-
Function:
	Command_GetName
Params:
	funcid - Command to get the name of.
Return:
	-
Notes:

native Command_GetName(funcid);

-*----------------------------------------------------------------------------*/

RS:Command_GetName[i](funcid)
{
	new
		buffer[YSI_MAX_STRING] = "";
	if (Command_IsValid(funcid))
	{
		strunpack(buffer, Command_Name(funcid));
	}
	return buffer;
}

/*----------------------------------------------------------------------------*-
Function:
	Command_GetDisplay
Params:
	f - Command to get the real name of.
	p - Player to get the name for.
Return:
	The name of a command for a single player.
Notes:
	-

native Command_GetDisplay(funcid, playerid);

-*----------------------------------------------------------------------------*/

RS:Command_GetDisplay[ii](funcid, playerid)
{
	new
		buffer[YSI_MAX_STRING] = "";
	if (Command_IsValid(funcid))
	{
		// Don't recalculate this every loop.
		new
			slot = Bit_Slot(playerid) + 1,
			Bit:mask = Bit_Mask(playerid);
		// Check if they can use the original version.
		if (YSI_g_sCommands[funcid][E_COMMANDS_PLAYERS][slot] & mask)
		{
			//setproperty(8, "", YSIM_STRING, Command_Name(f));
			strunpack(buffer, Command_Name(funcid));
			return buffer;
			//return 1;
		}
		// Search for a command pointing to that command which the player can use.
		for (new i = 0; i != MAX_COMMANDS; ++i)
		{
			if (Command_GetPointer(i) == funcid && (YSI_g_sCommands[i][E_COMMANDS_PLAYERS][slot] & mask))
			{
				//setproperty(8, "", YSIM_STRING, Command_Name(i));
				strunpack(buffer, Command_Name(i));
				return buffer;
			}
		}
	}
	return buffer;
}

/*----------------------------------------------------------------------------*-
Function:
	Command_GetDisplayNamed
Params:
	f[] - Command to get the real name of.
	p - Player to get the name for.
Return:
	The name of a named function for one player.
Notes:
	Remote function call for Command_GetDisplayNameNamed - avoids needing to
	expose users to the master system's odd way of returning strings.  This is
	the only part I've not yet fixed up to be nice and hidden.

native Command_GetDisplayNamed(funcid[], playerid);

-*----------------------------------------------------------------------------*/

RS@p:Command_GetDisplayNamed[si](func[], playerid)<func, playerid>
{
	P:1("Command_GetDisplayNamed called %d", _@);
	new
		pointer = Command_Find(func),
		buffer[YSI_MAX_STRING] = "";
	if (pointer != COMMAND_NOT_FOUND)
	{
		// Don't recalculate this every loop.
		new
			slot = Bit_Slot(playerid) + 1, //playerid >>> CELLSHIFT) + 1,
			Bit:mask = Bit_Mask(playerid); //Bit:(1 << (playerid & (cellbits - 1)));
		// Check if they can use the original version.
		if (YSI_g_sCommands[pointer][E_COMMANDS_PLAYERS][slot] & mask)
		{
			//setproperty(8, "", YSIM_STRING, Command_Name(pointer));
			strunpack(buffer, Command_Name(pointer));
			return buffer;
		}
		// Search for a command pointing to that command which the player can use.
		for (new i = 0; i != MAX_COMMANDS; ++i)
		{
			if (Command_GetPointer(i) == pointer && (YSI_g_sCommands[i][E_COMMANDS_PLAYERS][slot] & mask))
			{
				//setproperty(8, "", YSIM_STRING, Command_Name(i));
				strunpack(buffer, Command_Name(i));
				return buffer;
			}
		}
	}
	return buffer;
}

/*----------------------------------------------------------------------------*-
Function:
	Command_GetPlayerCommandCount
Params:
	playerid - Player to count for.
Return:
	-
Notes:
	Gets the number of comamnds this player can use.

native Command_GetPlayerCommandCount(playerid);

-*----------------------------------------------------------------------------*/

RF:Command_GetPlayerCommandCount[i](playerid)
{
	new
		slot = Bit_Slot(playerid) + 1,
		Bit:mask = Bit_Mask(playerid),
		count = 0;
	for (new i = 0; i != MAX_COMMANDS; ++i)
	{
		if (_Command_IsValid(i) && YSI_g_sCommands[i][E_COMMANDS_PLAYERS][slot] & mask)
		{
			++count;
		}
	}
	return count;
}

/*----------------------------------------------------------------------------*-
Function:
	Command_GetNext
Params:
	index - Index of the next command for this player.
	playerid - Player to get the name for.
Return:
	The name of a command for a single player.
Notes:
	-

native Command_GetNext(index, playerid);

-*----------------------------------------------------------------------------*/

RS:Command_GetNext[ii](index, playerid)
{
	new
		buffer[YSI_MAX_STRING] = "";
	if (0 <= index < MAX_COMMANDS)
	{
		// Don't recalculate this every loop.
		new
			slot = Bit_Slot(playerid) + 1,
			Bit:mask = Bit_Mask(playerid);
		for (new i = 0; i != MAX_COMMANDS; ++i)
		{
			if (_Command_IsValid(i) && YSI_g_sCommands[i][E_COMMANDS_PLAYERS][slot] & mask)
			{
				// Skip already displayed ones.
				if (index)
				{
					--index;
				}
				else
				{
					strunpack(buffer, Command_Name(i));
					return buffer;
				}
			}
		}
	}
	return buffer;
}

//#tryinclude <YSI\y_groups>

//#undef _YCM

#if defined _YSIM_MANUAL_SET
	// This is to allow callback chaining.  When the user includes y_groups and
	// other libraries, the function names will be reset to their custom ones
	// after every inclusion, however if you then include another YSI library
	// you need to revert to the previous library names to get the chaining to
	// work.
	#define YSI_GROUPS_LAST 25
	#include <YSI\internal\y_grouprevert>
#else
	// Define a numbered master to use for user commands, without them needing
	// to know about the master system.  This should default to cloud mode,
	// unless global settings have been applied.
	#define MASTER 23
	#include <YSI\y_master>
	//#define _YSIM_FAKE_MANUAL_SET
#endif
