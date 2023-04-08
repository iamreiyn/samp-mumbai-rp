
#include <a_samp>
#include <zcmd>
stock ShowMainMenu(playerid)
{
	new st[90];
	new viptext[60];
	switch(GetPVarInt(playerid, "VipLevel"))
	{
		case 0: viptext = "None";
		case 1: viptext = "{cd7f32}Bronze";
		case 2: viptext = "{c0c0c0}Silver";
		case 3: viptext = "{ffd700}Gold";
	}
	format(st, sizeof(st),"{ffffff}Level:{ffff00} %d{ffffff} | Exp: {ffff00}%d{ffffff} | Vip: %s", GetPVarInt(playerid, "Level"), GetPVarInt(playerid, "Respect"), viptext);
	return ShowPlayerDialog(playerid, 195, DIALOG_STYLE_LIST, st, "1) Statistica\n2) Options\n3) Usafrtxoeba\n4) Administracia\n5) Daxmareba\n6) Name change\n7) Forum-ze registracia\n Migwevebi\n9) Davalebebi\n10) Donate", "Next","Cancel");
}
CMD:help(playerid, params[])
{
    ShowMainMenu(playerid);
    SetPVarInt(playerid, "VipLevel", 2);
    return 1;
}
