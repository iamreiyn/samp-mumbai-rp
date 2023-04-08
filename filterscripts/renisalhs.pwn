#include <a_samp>
#include <core>
#include <float>


public OnFilterScriptInit()
{
	ChangeHostName();
	print("P:RP's Custom Hostnames");
	return 1;
}

main()
{
	print("\n*********************************");
	print("      P:RP's Hostnames - Renisal    ");
	print("***********************************\n");
	return 0;
}

public ChangeHostName()
{
	SendRconCommand("hostname              Prospect Roleplay [Test Server]");
	return 0;
}

