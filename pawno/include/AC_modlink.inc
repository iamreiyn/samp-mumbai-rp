//LACY SYSTEM
forward AC_GiveMoney(playerid, amount);
forward AC_MoneyCheat_Allow(playerid, amount1);

public AC_GiveMoney(playerid, amount)
{
	if(amount > 0)
		AC_MoneyCheat_Allow(playerid, amount);
	GivePlayerMoney(playerid, amount);
}

public AC_MoneyCheat_Allow(playerid, amount1)
{
	new tmpname[256];
	new amount[256];

	format(tmpname, 256, "LACY_MoneyCheat_Allow_%d", playerid);
	if(existproperty(13, "", adler32hash(tmpname)))
	{
	    new tmp;
	    new value[255];
		getproperty(13, "", adler32hash(tmpname), value);
		strunpack(value,value);
	    tmp = strval(value);
	    amount1 = amount1+tmp;
	    format(amount, 256, "%d", amount1);
	    deleteproperty(13, "", adler32hash(tmpname));
	    setproperty(13, "", adler32hash(tmpname), amount);
	}
	else
	{
	    format(amount, 256, "%d", amount1);
	    setproperty(13, "", adler32hash(tmpname), amount);
	}
}

adler32hash(buf[]) {
 new length=strlen(buf);
 new s1 = 1;
 new s2 = 0;
 new n;
 for (n=0; n<length; n++) {
  s1 = (s1 + buf[n]) % 65521;
  s2 = (s2 + s1)     % 65521;
 }
 return (s2 << 16) + s1;
}