#include <a_samp>

#define horizontal 1
#define vertical 2

#define KEY_RELEASE 0

forward OnPlayerWalkKey(playerid, mode, key);

enum Info
{

	bool:pUp,
	bool:pDown,
	bool:pLeft,
	bool:pRight
}

new WalkInfo[MAX_PLAYERS][Info];

stock WalkKeyLeave(playerid)
{
	WalkInfo[playerid][pUp] = false;
	WalkInfo[playerid][pDown] = false;
	WalkInfo[playerid][pLeft] = false;
	WalkInfo[playerid][pRight] = false;
}

stock WalkKeyUpdate(playerid)
{
	new keys, updown, leftright;
	GetPlayerKeys(playerid, keys, updown, leftright);
	if(updown == KEY_UP)
	{
		if(WalkInfo[playerid][pUp] == false)
		{
			OnPlayerWalkKey(playerid, vertical, KEY_UP);
			WalkInfo[playerid][pUp] = true;
		}
	}
	if(updown == KEY_DOWN)
	{
		if(WalkInfo[playerid][pDown] == false)
		{
			OnPlayerWalkKey(playerid, vertical, KEY_DOWN);
			WalkInfo[playerid][pDown] = true;
		}
	}
	if(leftright == KEY_LEFT)
	{
		if(WalkInfo[playerid][pLeft] == false)
		{
			OnPlayerWalkKey(playerid, horizontal, KEY_LEFT);
			WalkInfo[playerid][pLeft] = true;
		}
	}
	if(leftright == KEY_RIGHT)
	{
		if(WalkInfo[playerid][pRight] == false)
		{
			OnPlayerWalkKey(playerid, horizontal, KEY_RIGHT);
			WalkInfo[playerid][pRight] = true;
		}
	}
	
	
	// NOT, change back
	if(updown != KEY_UP)
	{
		if(WalkInfo[playerid][pUp] == true)
		{
			OnPlayerWalkKey(playerid, vertical, KEY_RELEASE);
			WalkInfo[playerid][pUp] = false;
		}
	}
	if(updown != KEY_DOWN)
	{
		if(WalkInfo[playerid][pDown] == true)
		{
			OnPlayerWalkKey(playerid, vertical, KEY_RELEASE);
			WalkInfo[playerid][pDown] = true;
		}
	}
	if(leftright != KEY_LEFT)
	{
		if(WalkInfo[playerid][pLeft] == true)
		{
			OnPlayerWalkKey(playerid, horizontal, KEY_RELEASE);
			WalkInfo[playerid][pLeft] = true;
		}
	}
	if(leftright != KEY_RIGHT)
	{
		if(WalkInfo[playerid][pRight] == false)
		{
			OnPlayerWalkKey(playerid, horizontal, KEY_RELEASE);
			WalkInfo[playerid][pRight] = true;
		}
	}
	return 1;
}