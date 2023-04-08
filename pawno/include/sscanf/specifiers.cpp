/*  
 *  Version: MPL 1.1
 *  
 *  The contents of this file are subject to the Mozilla Public License Version 
 *  1.1 (the "License"); you may not use this file except in compliance with 
 *  the License. You may obtain a copy of the License at 
 *  http://www.mozilla.org/MPL/
 *  
 *  Software distributed under the License is distributed on an "AS IS" basis,
 *  WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 *  for the specific language governing rights and limitations under the
 *  License.
 *  
 *  The Original Code is the sscanf 2.0 SA:MP plugin.
 *  
 *  The Initial Developer of the Original Code is Alex "Y_Less" Cole.
 *  Portions created by the Initial Developer are Copyright (C) 2010
 *  the Initial Developer. All Rights Reserved.
 *  
 *  Contributor(s):
 *  
 *  Special Thanks to:
 *  
 *  SA:MP Team past, present and future
 */

#include <string.h>
#include <stdlib.h>

#include "sscanf.h"
#include "utils.h"
#include "data.h"
#include "specifiers.h"

extern logprintf_t
	logprintf;

extern unsigned int
	g_iTrueMax,
	g_iInvalid;

extern int
	g_iServerVersion;

bool
	DoI(char ** input, int * ret)
{
	*ret = GetDec(input);
	return GetReturn(input);
}

bool
	DoN(char ** input, int * ret)
{
	*ret = GetNumber(input);
	return GetReturn(input);
}

bool
	DoH(char ** input, int * ret)
{
	*ret = GetHex(input);
	return GetReturn(input);
}

bool
	DoO(char ** input, int * ret)
{
	*ret = GetOct(input);
	return GetReturn(input);
}

bool
	DoF(char ** input, double * ret)
{
	*ret = strtod(*input, input);
	return GetReturn(input);
}

bool
	DoC(char ** input, char * ret)
{
	*ret = **input;
	++(*input);
	if (*ret == '\\')
	{
		if (IsSpacer(**input))
		{
			// '\ '
			*ret = **input;
			++(*input);
		}
		else if (**input == '\\')
		{
			// '\\'
			++(*input);
		}
	}
	return GetReturn(input);
}

bool
	DoL(char ** input, bool * ret)
{
	*ret = GetLogical(input);
	return true;
}

bool
	DoB(char ** input, int * ret)
{
	*ret = (int)GetBool(input);
	return GetReturn(input);
}

bool
	DoG(char ** input, double * ret)
{
	char *
		string = *input;
	int
		temp = 0;
	switch (*string)
	{
		case 'N':
		case 'n':
			if (strichecks(string, "NAN_E"))
			{
				*input += 5;
				temp = FLOAT_NAN_E;
			}
			else if (strichecks(string, "NAN"))
			{
				*input += 3;
				temp = FLOAT_NAN;
			}
			else if (strichecks(string, "NEG_INFINITY"))
			{
				*input += 12;
				temp = FLOAT_NEG_INFINITY;
			}
			else if (strichecks(string, "NEGATIVE_INFINITY"))
			{
				*input += 17;
				temp = FLOAT_NEG_INFINITY;
			}
			*ret = (double)(*((float *)&temp));
			break;
		case 'I':
		case 'i':
			if (strichecks(string, "INFINITY"))
			{
				*input += 8;
				temp = FLOAT_INFINITY;
				*ret = (double)(*((float *)&temp));
			}
			break;
		case '-':
			if (strichecks(string + 1, "INFINITY"))
			{
				*input += 9;
				temp = FLOAT_NEG_INFINITY;
				*ret = (double)(*((float *)&temp));
				break;
			}
			// FALLTHROUGH
		default:
			// Read in the value and save the pointer - may as well use
			// existing, pre set up variables.
			*ret = strtod(string, input);
			break;
	}
	return GetReturn(input);
}

bool
	DoS(char ** input, char ** ret, int length, bool all)
{
	// Don't reallocate the memory, just set pointers to the current data and
	// add nulls to terminate.
	int
		i = 0;
	// Save the pointer to the start of the data.
	*ret = *input;
	// Check if we want the whole remaining string or just the next word.
	char
		* string = *input,
		* outp = string;
	if (all)
	{
		// Everything.
		while (!IsEnd(*string))
		{
			++i;
			// Cap at "length" characters long.
			if (i == length)
			{
				// Could let the loop exit properly as it would next time, but
				// there's no point - it's just extra work and we know it's OK.
				// We set the null before incrementing to ensure it's included
				// in the output.
				logprintf("sscanf warning: String buffer overflow.");
				// Removed the break - discard the rest of the string.
				//break;
			}
			else if (i < length)
			{
				if (*string == '\\')
				{
					// You can only escape the escape character or spaces.
					// Spaces aren't technically used here, but they COULD be
					// used in the current string in other circumstances, so
					// they may be present even when not needed.
					if (*(string + 1) == '\\' || IsSpacer(*(string + 1)))
					{
						++string;
					}
				}
				if (outp != string)
				{
					// Compress the string only if we have a discrepancy
					// between input and output pos.
					*outp = *string;
				}
				++outp;
			}
			++string;
		}
	}
	else if (IsDefaultDelimiter())
	{
		while (!IsWhitespace(*string))
		{
			++i;
			if (i == length)
			{
				logprintf("sscanf warning: String buffer overflow.");
			}
			else if (i < length)
			{
				if (*string == '\\')
				{
					if (*(string + 1) == '\\' || IsWhitespace(*(string + 1)))
					{
						++string;
					}
				}
				if (outp != string)
				{
					*outp = *string;
				}
				++outp;
			}
			++string;
		}
	}
	else
	{
		// Just a single word.  Note that if your delimiter is a backspace you
		// can't escape it - this is not a bug, just don't try use it as a
		// delimiter and still expect to be able to use it in a string.
		while (!IsEnd(*string) && !IsDelimiter(*string))
		{
			++i;
			if (i == length)
			{
				logprintf("sscanf warning: String buffer overflow.");
			}
			else if (i < length)
			{
				if (*string == '\\')
				{
					// Escape spaces, backspace and delimiters - this code is
					// context independent so you can use a string with or
					// without a delimiter and can still escape spaces.
					if (*(string + 1) == '\\' || IsSpacer(*(string + 1)))
					{
						++string;
					}
				}
				if (outp != string)
				{
					*outp = *string;
				}
				++outp;
			}
			++string;
		}
	}
	if (!IsEnd(*string))
	{
		// Skip the final character.
		*input = string + 1;
	}
	else
	{
		// Save the return.
		*input = string;
	}
	// Add a null terminator.
	*outp = '\0';
	// Can't really fail on a string as everything goes!
	return true;
}

bool
	DoU(char ** input, int * ret)
{
	char
		* end = NULL,
		* string = *input;
	unsigned int
		val = GetUserString(string, &end);
	if (!(val < g_iTrueMax && IsPlayerConnected(val)))
	{
		int
			* conn = GetConnected(),
			len = end - string;
		val = 0;
		char
			tmp = *end,
			* name = GetNames();
		*end = '\0';
		while (val < g_iTrueMax)
		{
			if (*conn++ && !strincmp(name, string, len))
			{
				break;
			}
			name += MAX_PLAYER_NAME + 1;
			++val;
		}
		*end = tmp;
	}
	*input = end;
	if (val == g_iTrueMax)
	{
		*ret = g_iInvalid;
	}
	else
	{
		*ret = val;
	}
	return true;
}

bool
	DoQ(char ** input, int * ret)
{
	if (g_iServerVersion < SERVER_VERSION_0300)
	{
		logprintf("sscanf warning: This server version does not support bots.");
		return DoU(input, ret);
	}
	char
		* end = NULL,
		* string = *input;
	// Get the string.
	unsigned int
		val = GetUserString(string, &end);
	// We only have a less than check here as valid IDs start at 0, and
	// GetUserString can't return numbers less than 0, it's physically
	// impossible for it to do so as there's no code there for it to happen.
	// Check that the player is a valid ID, connected and a non-player
	// character, and if one of those checks FAILS, do the code below.  We
	// could attempt to write a C++ equivalent to foreach here, but this should
	// be pretty fast anyway as it uses direct memory access.
	if (!(val < g_iTrueMax && IsPlayerConnected(val) && IsPlayerNPC(val)))
	{
		// Find the NPC by name.
		int
			* conn = GetConnected(),
			* npc = GetNPCs(),
			len = end - string;
		val = 0;
		// Save the end character for the name.
		char
			tmp = *end,
			* name = GetNames();
		// Make the input string shorter for comparison.
		*end = '\0';
		while (val < g_iTrueMax)
		{
			// Loop through all the players and check that they're connected,
			// an NPC and that their name is correct.
			if (*conn && *npc && !strincmp(name, string, len))
			{
				// Found them.
				break;
			}
			// Can't do *npc++ above as it's not always reached and we need it
			// to be incremented.
			++conn;
			++npc;
			// Increase the name pointer, 1 is for NULL.
			name += MAX_PLAYER_NAME + 1;
			++val;
		}
		*end = tmp;
	}
	// Save the pointer to the end of the name.
	*input = end;
	// Optimised from the PAWN version.  If it gets to here without having
	// found a valid player then 'val' will be g_iTrueMax.
	if (val == g_iTrueMax)
	{
		// Return INVALID_PLAYER_ID.  Ideally we would just return g_iTrueMax,
		// which can never be a connected player, but some people may use an if
		// check of "if (giveplayer == INVALID_PLAYER_ID)", which means,
		// despite the fact that it may be slower, we need to do it this way.
		// I've only myself to blame really - I told people to do it that way
		// as it's faster in PAWN, so overall this way will be faster as it
		// avoids additional calls in PAWN, but makes the C code fractionally,
		// insignificantly, slower.  0.2 and 0.3 use different values for
		// INVALID_PLAYER_ID (which is going to annoy all those people who
		// steadfastly refused to use the macro for no apparent reason) so we
		// need to support both.
		*ret = g_iInvalid;
	}
	else
	{
		*ret = val;
	}
	return true;
}

bool
	DoR(char ** input, int * ret)
{
	if (g_iServerVersion < SERVER_VERSION_0300)
	{
		logprintf("sscanf warning: This server version does not support bots.");
		return DoU(input, ret);
	}
	char
		* end = NULL,
		* string = *input;
	unsigned int
		val = GetUserString(string, &end);
	if (!(val < g_iTrueMax && IsPlayerConnected(val) && !IsPlayerNPC(val)))
	{
		int
			* conn = GetConnected(),
			* npc = GetNPCs(),
			len = end - string;
		val = 0;
		char
			tmp = *end,
			* name = GetNames();
		*end = '\0';
		while (val < g_iTrueMax)
		{
			if (*conn && !*npc && !strincmp(name, string, len))
			{
				break;
			}
			++conn;
			++npc;
			name += MAX_PLAYER_NAME + 1;
			++val;
		}
		*end = tmp;
	}
	*input = end;
	if (val == g_iTrueMax)
	{
		*ret = g_iInvalid;
	}
	else
	{
		*ret = val;
	}
	return true;
}

bool
	DoID(char ** input, int * ret)
{
	if (!FindDefaultStart(input))
	{
		return false;
	}
	*ret = GetDec(input);
	return GetReturnDefault(input);
}

bool
	DoND(char ** input, int * ret)
{
	if (!FindDefaultStart(input))
	{
		return false;
	}
	*ret = GetNumber(input);
	return GetReturnDefault(input);
}

bool
	DoHD(char ** input, int * ret)
{
	if (!FindDefaultStart(input))
	{
		return false;
	}
	*ret = GetHex(input);
	return GetReturnDefault(input);
}

bool
	DoOD(char ** input, int * ret)
{
	if (!FindDefaultStart(input))
	{
		return false;
	}
	*ret = GetOct(input);
	return GetReturnDefault(input);
}

bool
	DoFD(char ** input, double * ret)
{
	if (!FindDefaultStart(input))
	{
		return false;
	}
	*ret = strtod(*input, input);
	return GetReturnDefault(input);
}

bool
	DoCD(char ** input, char * ret)
{
	if (!FindDefaultStart(input))
	{
		return false;
	}
	*ret = **input;
	++(*input);
	if (*ret == '\\')
	{
		if (IsSpacer(**input))
		{
			// '\ '
			*ret = **input;
			++(*input);
		}
		else if (**input == '\\')
		{
			// '\\'
			++(*input);
		}
	}
	return GetReturnDefault(input);
}

bool
	DoBD(char ** input, int * ret)
{
	if (!FindDefaultStart(input))
	{
		return false;
	}
	*ret = (int)GetBool(input);
	return GetReturnDefault(input);
}

bool
	DoGD(char ** input, double * ret)
{
	if (!FindDefaultStart(input))
	{
		return false;
	}
	char *
		string = *input;
	int
		temp = 0;
	switch (*string)
	{
		case 'N':
		case 'n':
			if (strichecks(string, "NAN_E"))
			{
				*input += 5;
				temp = FLOAT_NAN_E;
			}
			else if (strichecks(string, "NAN"))
			{
				*input += 3;
				temp = FLOAT_NAN;
			}
			else if (strichecks(string, "NEG_INFINITY"))
			{
				*input += 12;
				temp = FLOAT_NEG_INFINITY;
			}
			else if (strichecks(string, "NEGATIVE_INFINITY"))
			{
				*input += 17;
				temp = FLOAT_NEG_INFINITY;
			}
			*ret = (double)(*((float *)&temp));
			break;
		case 'I':
		case 'i':
			if (strichecks(string, "INFINITY"))
			{
				*input += 8;
				temp = FLOAT_INFINITY;
				*ret = (double)(*((float *)&temp));
			}
			break;
		case '-':
			if (strichecks(string + 1, "INFINITY"))
			{
				*input += 9;
				temp = FLOAT_NEG_INFINITY;
				*ret = (double)(*((float *)&temp));
				break;
			}
			// FALLTHROUGH
		default:
			// Read in the value and save the pointer - may as well use
			// existing, pre set up variables.
			*ret = strtod(string, input);
			break;
	}
	return GetReturnDefault(input);
}

bool
	DoSD(char ** input, char ** ret, int * length)
{
	if (!FindDefaultStart(input))
	{
		return false;
	}
	// Don't reallocate the memory, just set pointers to the current data and
	// add nulls to terminate.
	int
		i = 0;
	// Save the pointer to the start of the data.
	*ret = *input;
	// Check if we want the whole remaining string or just the next word.
	char
		* string = *input,
		* outp = string;
	while (!IsEnd(*string) && !IsDelimiter(*string))
	{
		++i;
		if (*string == '\\')
		{
			// Escape spaces, backspace and delimiters - this code is
			// context independent so you can use a string with or
			// without a delimiter and can still escape spaces.
			if (*(string + 1) == '\\' || IsWhitespace(*(string + 1)) || IsDelimiter(*(string + 1)))
			{
				++string;
			}
		}
		if (outp != string)
		{
			*outp = *string;
		}
		++outp;
		++string;
	}
	if (IsDelimiter(*string))
	{
		// Skip the final character.
		*input = string + 1;
		// NOW get the length.
		*length = GetLength(input, false);
	}
	else
	{
		logprintf("sscanf warning: Unclosed default value.");
		// Save the return.
		*input = string;
		logprintf("sscanf warning: Strings without a length are deprecated, please add a destination size.");
		*length = SSCANF_MAX_LENGTH;
	}
	// Add a null terminator.
	if (i >= *length)
	{
		logprintf("sscanf warning: String buffer overflow.");
		*(ret + (*length - 1)) = '\0';
	}
	else
	{
		*outp = '\0';
	}
	return true;
}

bool
	DoUD(char ** input, int * ret)
{
	if (!FindDefaultStart(input))
	{
		return false;
	}
	DoU(input, ret);
	return GetReturnDefault(input);
}

bool
	DoQD(char ** input, int * ret)
{
	if (!FindDefaultStart(input))
	{
		return false;
	}
	DoQ(input, ret);
	return GetReturnDefault(input);
}

bool
	DoRD(char ** input, int * ret)
{
	if (!FindDefaultStart(input))
	{
		return false;
	}
	DoR(input, ret);
	return GetReturnDefault(input);
}

bool
	DoLD(char ** input, bool * ret)
{
	if (!FindDefaultStart(input))
	{
		return false;
	}
	DoL(input, ret);
	return GetReturnDefault(input);
}
