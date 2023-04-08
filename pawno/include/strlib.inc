/*
	strlib library for string manipulation.
	Created by David Weston

	Version: 1.3
	Licence: http://www.typefish.co.uk/licences/
*/


/* Stuff that needs to be included. */
#include <a_samp>


/* Pretty key definitions */
#if defined _strlib_included
	#endinput
#endif
#define _strlib_included
#define _strlib_sma_string 128
#define _strlib_med_string 256
#define _strlib_big_string 512


/* Natives for tricking PAWNO. */
/*
	native str_replace(sSearch[], sReplace[], const sSubject[], &iCount = 0)
	native str_ireplace(sSearch[], sReplace[], const sSubject[], &iCount = 0)
	native str_pad(const sSource[], iPadLength, cPadChar = ' ')
	native str_repeat(const sSource[], iMultiplier)
	native str_rot13(const sSource[])
	native strtr(const sSource[], sRemove[], sReplace[])
	native substr(const sSource[], iStart, iLength = sizeof(sSource))
	native trim(const sSource[])
	native rtrim(const sSource[])
	native ltrim(const sSource[])
	native implode(const aPieces[][], const sGlue[] = " ")
	native explode(aExplode[][], sSource[], sDelimiter[] = " ")
	native explodea(aExplode[][], sSource[], sDelimiter[] = " ")
	native str_in_array(sNeedle[], aHaystack[][])
*/


/*
	str_replace:
		Case sensitive string replace

	Arguments:
		sSearch[]       String to search for
		sReplace[]      String to replace with
		sSubject[]      Original string
		(op) &iCount    How many times 'sSearch' has been replaced.

	Returns:
		Replaced string.
*/
stock str_replace(sSearch[], sReplace[], const sSubject[], &iCount = 0)
{
	new
		iLengthTarget = strlen(sSearch),
		iLengthReplace = strlen(sReplace),
		iLengthSource = strlen(sSubject),
		iItterations = (iLengthSource - iLengthTarget) + 1;

	new
		sTemp[128],
		sReturn[_strlib_med_string];

	strcat(sReturn, sSubject, _strlib_med_string);
	iCount = 0;

	for(new iIndex; iIndex < iItterations; ++iIndex)
	{
		strmid(sTemp, sReturn, iIndex, (iIndex + iLengthTarget), (iLengthTarget + 1));

		if(!strcmp(sTemp, sSearch, false))
		{
			strdel(sReturn, iIndex, (iIndex + iLengthTarget));
			strins(sReturn, sReplace, iIndex, iLengthReplace);

			iIndex += iLengthTarget;
			iCount++;
		}
	}

	return sReturn;
}


/*
	str_ireplace:
		Case insensitive string replace

	Arguments:
		sSearch[]       String to search for
		sReplace[]      String to replace with
		sSubject[]      Original string
		(op) &iCount    How many times 'sSearch' has been replaced.

	Returns:
		Replaced string.
*/
stock str_ireplace(sSearch[], sReplace[], const sSubject[], &iCount = 0)
{
	new
		iLengthTarget = strlen(sSearch),
		iLengthReplace = strlen(sReplace),
		iLengthSource = strlen(sSubject),
		iItterations = (iLengthSource - iLengthTarget) + 1;

	new
		sTemp[128],
		sReturn[_strlib_med_string];

	strcat(sReturn, sSubject, _strlib_med_string);
	iCount = 0;

	for(new iIndex; iIndex < iItterations; ++iIndex)
	{
		strmid(sTemp, sReturn, iIndex, (iIndex + iLengthTarget), (iLengthTarget + 1));

		if(!strcmp(sTemp, sSearch, true))
		{
			strdel(sReturn, iIndex, (iIndex + iLengthTarget));
			strins(sReturn, sReplace, iIndex, iLengthReplace);

			iIndex += iLengthTarget;
			iCount++;
		}
	}

	return sReturn;
}


/*
	str_pad:
		Pad a string with characters until the defined amount.

	Arguments:
		sSource[]         String input to pad.
		iPadLength       Pad to amount. If less than sSource, sSource is returned.
		(op) cPadChar    Character to use as padding.

	Returns:
		Padded string.
*/
stock str_pad(const sSource[], iPadLength, cPadChar = ' ')
{
	new
		iInputLength = strlen(sSource),
		sReturn[_strlib_med_string];

	strcat(sReturn, sSource, _strlib_med_string);

	if((iInputLength >= iPadLength) && (iPadLength > 255))
	{
		return sReturn;
	}

	while(iInputLength < iPadLength)
	{
		sReturn[iInputLength] = cPadChar;
		++iInputLength;
	}

	return sReturn;
}


/*
	str_repeat:
		Repeats a string 'iMultiplier' times.

	Arguments:
		sSource[]     String to be repeated
		iMultiplier  Amount of times to be repeated

	Returns:
		Repeated string.
*/
stock str_repeat(const sSource[], iMultiplier)
{
	new
		iInputLength = strlen(sSource),
		iItteration = (iInputLength * iMultiplier),
		iIndex,
		sReturn[_strlib_med_string];

	while(iIndex < iItteration)
	{
		strins(sReturn, sSource, iIndex);
		iIndex += iInputLength;
	}

	return sReturn;
}


/*
	str_rot13:
		Rotates alphabetical characters 13 characters along.

	Arguments:
		sSource[]     String to be rotated

	Returns:
		Rotated string.
*/
stock str_rot13(const sSource[])
{
	new
		iInputLength = strlen(sSource),
		sReturn[_strlib_med_string];

	for(new iIndex; iIndex < iInputLength; ++iIndex)
	{
		switch(sSource[iIndex])
		{
			case 65..77:
			{
				sReturn[iIndex] = sSource[iIndex] + 13;
			}
			case 78..90:
			{
				sReturn[iIndex] = sSource[iIndex] - 13;
			}
			case 97..109:
			{
				sReturn[iIndex] = sSource[iIndex] + 13;
			}
			case 110..122:
			{
				sReturn[iIndex] = sSource[iIndex] - 13;
			}
			default:
			{
				sReturn[iIndex] = sSource[iIndex];
			}
		}
	}

	return sReturn;
}


/*
	strtr:
		Removes 'sRemove' from the string and replaces
		that character from 'sReplace'.

	Arguments:
		sSource[]     String to be transformed
		sRemove[]    Characters to be removed (must be in same order as below!)
		sReplace[]   Characters to be replaced (must be in same order as above!)

	Returns:
		Trimmed string.
*/
stock strtr(const sSource[], sRemove[], sReplace[])
{
	new
		iCurrentChar = 0,
		iInputLength = strlen(sSource),
		iRemoveLength = strlen(sRemove);

	new
		iDeleteChar = -1,
		sReturn[_strlib_med_string];

	for(new iIndex; iIndex < iInputLength; ++iIndex)
	{
		for(new iChar; iChar < iRemoveLength; ++iChar)
		{
			if(sSource[iIndex] == sRemove[iChar])
			{
				iDeleteChar = iChar;
				break;
			}
		}

		switch(iDeleteChar)
		{
			case -1:
			{
				sReturn[iCurrentChar] = sSource[iIndex];
				iCurrentChar++;
			}
			default:
			{
				if(strlen(sReplace) > iDeleteChar)
				{
					sReturn[iCurrentChar] = sReplace[iDeleteChar];
					iCurrentChar++;
				}
				iDeleteChar = -1;
			}
		}
	}

	return sReturn;
}


/*
	trim:
		Removes whitespace, tabs, and new lines
		from the beginning and end of 'sSource'.

	Arguments:
		sSource[]     String to be trimmed

	Returns:
		Trimmed string.
*/
stock trim(const sSource[])
{
	new
		iBegin,
		iEnd,
		iInputLength = strlen(sSource),
		sReturn[_strlib_med_string];

	strcat(sReturn, sSource, _strlib_med_string);

	for(iBegin = 0; iBegin < iInputLength; ++iBegin)
	{
		switch(sReturn[iBegin])
		{
			case ' ', '\t', '\r', '\n':
			{
				continue;
			}
			default:
			{
				break;
			}
		}
	}

	for(iEnd = (iInputLength - 1); iEnd > iBegin; --iEnd)
	{
		switch(sReturn[iEnd])
		{
			case ' ', '\t', '\r', '\n':
			{
				continue;
			}
			default:
			{
				break;
			}
		}
	}

	strdel(sReturn, (iEnd + 1), iInputLength);
	strdel(sReturn, 0, iBegin);

	return sReturn;
}


/*
	ltrim:
		Removes whitespace, tabs, and new lines
		from the beginning of 'sSource'.

	Arguments:
		sSource[]     String to be trimmed

	Returns:
		Trimmed string.
*/
stock ltrim(const sSource[])
{
	new
		iBegin,
		iInputLength = strlen(sSource),
		sReturn[_strlib_med_string];

	strcat(sReturn, sSource, _strlib_med_string);

	for(iBegin = 0; iBegin < iInputLength; ++iBegin)
	{
		switch(sReturn[iBegin])
		{
			case ' ', '\t', '\r', '\n':
			{
				continue;
			}
			default:
			{
				break;
			}
		}
	}

	strdel(sReturn, 0, iBegin);
	return sReturn;
}


/*
	rtrim:
		Removes whitespace, tabs, and new lines
		from the end of 'sSource'.

	Arguments:
		sSource[]     String to be trimmed

	Returns:
		Trimmed string.
*/
stock rtrim(const sSource[])
{
	new
		iEnd,
		iInputLength = strlen(sSource),
		sReturn[_strlib_med_string];

	strcat(sReturn, sSource, _strlib_med_string);

	for(iEnd = (iInputLength - 1); iEnd > 0; --iEnd)
	{
		switch(sReturn[iEnd])
		{
			case ' ', '\t', '\r', '\n':
			{
				continue;
			}
			default:
			{
				break;
			}
		}
	}

	strdel(sReturn, (iEnd + 1), iInputLength);
	return sReturn;
}


/*
	substr:
		Gets a substring from a string.

	Arguments:
		sSource[]     String to be substring'd.
		iStart        Position for the start of substring.
		iLength       Position for the end of substring.
		                (if negative, cells away from end)

	Returns:
		Substring.
*/
stock substr(const sSource[], iStart, iLength = sizeof sSource)
{
	new
		sReturn[_strlib_med_string];

	if(iLength < 0)
	{
		strmid(sReturn, sSource, iStart, strlen(sSource) + iLength);
		return sReturn;
	}
	else
	{
		strmid(sReturn, sSource, iStart, (iStart + iLength));
		return sReturn;
	}
}


/*
	implode:
		Returns a string where the array has been stuck back together
		again.

	Arguments:
		aPieces[][]   The array to glue back together.
		sGlue         The string to use as the glue.

	Returns:
		The imploded string.
*/
stock implode(const aPieces[][], const sGlue[] = " ", iVertices = sizeof aPieces)
{
	new
		sReturn[_strlib_med_string];

	while(iVertices != -1)
	{
		strins(sReturn, aPieces[iVertices], 0);

		if(iVertices != 0)
		{
			strins(sReturn, sGlue, 0);
		}

		--iVertices;
	}

	return sReturn;
}


/*
	explode:
		Creates an array of values from 'sSource', where only the exact amount of
		values matching sizeof(aExplode) are returned.

	Arguments:
		aExplode[][]  The exploded array
		sSource[]     Source string.
		sDelimiter    The string to use as the delimiter.

	Returns:
		Returns -1 on failure, otherwise success.
*/
stock explode(aExplode[][], const sSource[], const sDelimiter[] = " ", iVertices = sizeof aExplode, iLength = sizeof aExplode[])
{
	new
		iNode,
		iPointer,
		iPrevious = -1,
		iDelimiter = strlen(sDelimiter);

	while(iNode < iVertices)
	{
		iPointer = strfind(sSource, sDelimiter, false, iPointer);

		if(iPointer == -1)
		{
			strmid(aExplode[iNode], sSource, iPrevious, strlen(sSource), iLength);
			break;
		}
		else
		{
			strmid(aExplode[iNode], sSource, iPrevious, iPointer, iLength);
		}

		iPrevious = (iPointer += iDelimiter);
		++iNode;
	}

	return iPrevious;
}


/*
	explodea:
		Creates an array of values from 'sSource', where any overrun is stored in
		the final node.

	Arguments:
		aExplode[][]  The exploded array
		sSource[]     Source string.
		sDelimiter    The string to use as the delimiter.

	Returns:
		Returns -1 on failure, otherwise success.
*/
stock explodea(aExplode[][], const sSource[], const sDelimiter[] = " ", iVertices = sizeof aExplode, iLength = sizeof aExplode[])
{
	new
		iNode,
		iPointer,
		iPrevious = -1,
		iSource = strlen(sSource),
		iDelimiter = strlen(sDelimiter);

	while(iNode < iVertices)
	{
		iPointer = strfind(sSource, sDelimiter, false, iPointer);

		strmid(aExplode[iNode], sSource, iPrevious, (iNode == (iVertices - 1) ? iSource : iPointer), iLength);

		iPrevious = (iPointer += iDelimiter);
		++iNode;
	}

	return iPrevious;
}


/*
	str_in_array:
		Checks if a string matches any of the strings in the array.

	Arguments:
		sNeedle[]     String that is being matched.
		aHaystack[][] Array with strings to be searched,

	Returns:
		Returns true on a match.
*/
stock bool:str_in_array(const sNeedle[], const aHaystack[][], const iHaystack = sizeof aHaystack)
{
	new iNode = 0;

	while(iNode < iHaystack)
	{
		if(!strcmp(sNeedle, aHaystack[iNode], true))
		{
			return true;
		}

		++iNode;
	}

	return false;
}

