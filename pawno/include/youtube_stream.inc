#if defined _youtube_included
	#endinput
#endif
#define _youtube_included
/**
 * Play an youtube 'audio stream'
 * 
 * @note usually the API fails in newly videos...
 *
 * @version		1.0.2
 * @author		Dayvison
 * @date		05-10-2016
 */
//#define YOUTUBE_USE_TEXTDRAW
#define USE_REGEX

#include <a_http>
#if defined USE_REGEX
	#tryinclude <regex> // [Plugin] Regular expression by Fro1sha: http://forum.sa-mp.com/showthread.php?t=247893
	#if !defined _regex_included && !defined regex_match_exid
		#undef USE_REGEX
		#error "Can't find regex plugin"
 	#endif
#endif

#if defined YOUTUBE_USE_TEXTDRAW
	#define USE_TIMER
#endif
#if !defined USE_TIMER
	#if defined OnFinishYoutubeUrl
		#define USE_TIMER
	#endif
#endif

static
#if defined YOUTUBE_USE_TEXTDRAW	
	PlayerText:youtube_textdraw[MAX_PLAYERS],
#endif
#if defined USE_TIMER
	youtube_timer[MAX_PLAYERS],
#endif
	youtube_title[MAX_PLAYERS][128 char],
	youtube_len[MAX_PLAYERS],
	Float:youtube_posX[MAX_PLAYERS],
	Float:youtube_posY[MAX_PLAYERS],
	Float:youtube_posZ[MAX_PLAYERS],
	Float:youtube_distance[MAX_PLAYERS],
	youtube_usepos[MAX_PLAYERS]
;
#if defined OnPlayYoutubeUrl
/**
 * Called when youtube url an played.
 *
 * @param      playerid  The playerid
 * @param      title     The title of url(if invalid \0)
 * @param      len       The length of url(if invalid 0)
 * @param      response  The response of url 
 * 							Response codes:
 * 							1 Sucess
 * 							-1 Invalid url
 * 							-2 Invalid page
 */
	forward OnPlayYoutubeUrl(playerid, title[], len, response);
#endif
#if defined OnPlayYoutubeUrl
/**
 * Called when youtube url as finished.
 *
 * @param      playerid  The playerid
 * @param      title     The title of url
 * @param      len       The length of url
 */
	forward OnFinishYoutubeUrl(playerid, title[], len);
#endif

#if defined USE_REGEX
/**
 * Determines if valid youtube url.
 *
 * @param      url   The url
 *
 * @author		Dayvison
 * @date		04-10-2016
 * @return		True if is a valid url, false not.
 */
stock IsValidYoutubeUrl(const url[])
{
	static RegEx:rHex;
	if(!rHex)
	{		
		rHex = regex_build(\"((http(s)?:\/\/)?)(www\.)?((youtube\.com\/)|(youtu.be\/))[\S]+");
	}
	return regex_match_exid(url, rHex);
}
#endif
/**
 * Converts an youtu.be url to youtube.com
 *
 * @param      Url   The url to convert
 * @param      size  The size
 *
 * @author		Dayvison
 * @date		04-10-2016
 * @return		True on convert have sucess, false not.
 */
stock ConvertYoutubeUrl(Url[], size = sizeof(Url))
{
	new find;
	if((find = strfind(Url, "youtu.be/")) == -1)
		return false;
	strdel(Url, 0, find + 4);
	format(Url, size, "https://www.youtube.com/watch?v=", Url);
	return true;
}

/**
 * Play an youtube 'audio stream' for a player.
 *
 * @param      playerid  The ID of the player to play the audio for.
 * @param      url       The url to play.
 * @param      posX      The X position at which to play the audio. Default 0.0. Has no effect unless usepos is set to 1.
 * @param      posY      The Y position at which to play the audio. Default 0.0. Has no effect unless usepos is set to 1.
 * @param      posZ      The Z position at which to play the audio. Default 0.0. Has no effect unless usepos is set to 1.
 * @param      distance  The distance over which the audio will be heard. Has no effect unless usepos is set to 1.
 * @param      usepos    Use the positions and distance specified. Default disabled (0).
 *
 * @author		Dayvison
 * @date		04-10-2016
 * @return		True on sucess, or false on failure. if USE_REGEX active is more efficient
 */
stock PlayYoutubeStreamForPlayer(playerid, url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, usepos = 0)
{
	if(!IsPlayerConnected(playerid))
		return false;
	#if defined USE_REGEX
	if(!IsValidYoutubeUrl(url))
	{
		if(!ConvertYoutubeUrl(url, 256))
			return false;
	}
	#else
	if(strfind(url, "youtu.be/") != -1)
		if(!ConvertYoutubeUrl(url, 256))
			return false;
	#endif
	static string[256];
	format(string, sizeof(string), "www.youtubeinmp3.com/fetch/?video=%s&autostart=1", url);
	PlayAudioStreamForPlayer(playerid, string, posX, posY, posZ, distance, usepos);
	youtube_posX[playerid]		= posX;
	youtube_posY[playerid]		= posY;
	youtube_posZ[playerid]		= posZ;
	youtube_distance[playerid]	= distance;
	youtube_usepos[playerid]	= usepos;
	youtube_title[playerid]{0} = '\0';
	youtube_len[playerid] = 0;
	return true;
}

/**
 * Stop an youtube 'audio stream' for a player.
 *
 * @param      playerid  The ID of the player to play the audio for.
 *
 * @author		Dayvison
 * @date		05-10-2016
 * @return		True on sucess, or false on failure.
 */
stock StopYoutubeStreamForPlayer(playerid)
	return StopAudioStreamForPlayer(playerid);

/**
 * Gets the youtube stream title.
 *
 * @param      playerid  The playerid
 * @param      dest      The destination
 * @param      size      The size
 *
 * @author		Dayvison
 * @date		05-10-2016
 * @return		1 on sucess, 0 on fails
 */
stock GetYoutubeStreamTitle(playerid, dest[], size = sizeof(dest))
{
	if(!IsPlayerConnected(playerid))
		return 0;
	strunpack(dest, youtube_title[playerid], size);
	return 1;
}

/**
 * Gets the youtube stream length.
 *
 * @param      playerid  The playerid
 *
 * @author		Dayvison
 * @date		05-10-2016
 * @return		The length of stream
 */
stock GetYoutubeStreamLen(playerid)
{
	if(!IsPlayerConnected(playerid))
		return 0;
	return youtube_len[playerid];
}

/**
 * Gets the youtube stream position x.
 *
 * @param      playerid  The playerid
 *
 * @author		Dayvison
 * @date		05-10-2016
 * @return		The position x
 */
stock GetYoutubeStreamPosX(playerid)
{
	if(!IsPlayerConnected(playerid))
		return 0.0;
	return youtube_posX[playerid];
}

/**
 * Gets the youtube stream position y.
 *
 * @param      playerid  The playerid
 *
 * @author		Dayvison
 * @date		05-10-2016
 * @return		The position y
 */
stock GetYoutubeStreamPosY(playerid)
{
	if(!IsPlayerConnected(playerid))
		return 0.0;
	return youtube_posY[playerid];
}

/**
 * Gets the youtube stream position z.
 *
 * @param      playerid  The playerid
 *
 * @author		Dayvison
 * @date		05-10-2016
 * @return		The position z
 */
stock GetYoutubeStreamPosZ(playerid)
{
	if(!IsPlayerConnected(playerid))
		return 0.0;
	return youtube_posZ[playerid];
}

/**
 * Gets the youtube stream distance.
 *
 * @param      playerid  The playerid
 *
 * @author		Dayvison
 * @date		05-10-2016
 * @return		The stream distance
 */
stock GetYoutubeStreamDistance(playerid)
{
	if(!IsPlayerConnected(playerid))
		return 0.0;
	return youtube_distance[playerid];
}

/**
 * Determines if youtube stream use position.
 *
 * @param      playerid  The playerid
 *
 * @author		Dayvison
 * @date		05-10-2016
 * @return		The usepos
 */
stock bool:IsYoutubeStreamUsePos(playerid)
{
	if(!IsPlayerConnected(playerid))
		return false;
	return youtube_usepos[playerid];
}

/*public YoutubeResponse(playerid, response, data[])
{
	if(response == 200)
	{
		if(strfind(data, "No video was found") != -1 || strfind(data, "<meta http-equiv=") != -1)
		{
			#if defined OnPlayYoutubeUrl
				OnPlayYoutubeUrl(playerid, "\0", 0, -1);
			#endif
			return;
		}
		new
			title[60],
			len[5];

		unformat(params, "P<</br>>is[32]f", a, b, c);
		youtube_len[playerid] = strval(len);

		PlayAudioStreamForPlayer(playerid, data, youtube_posX[playerid], youtube_posY[playerid], youtube_posZ[playerid], youtube_distance[playerid], youtube_usepos[playerid]);
	}
}*/