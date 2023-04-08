

#define COLOR_CMD 0xDDDD2357
new Float:FF[MAX_PLAYERS];
new o1[MAX_PLAYERS];
new o2[MAX_PLAYERS];
new o3[MAX_PLAYERS];
new o4[MAX_PLAYERS];
new o5[MAX_PLAYERS];
new PlayerFreezed[MAX_PLAYERS];
new L = 0;//O - Русский,1 - English.
new AnimsON = 1;//1 - ON, 0 - OFF

/*
public OnPlayerConnect(playerid)
{
FF[playerid] = 4.1;
o1[playerid] = 0;
o2[playerid] = 1;
o3[playerid] = 1;
o4[playerid] = 1;
o5[playerid] = 1;
return 1;
}*/


forward OnPlayerAnimCommandText(playerid, cmdtext[]);
public OnPlayerAnimCommandText(playerid, cmdtext[])
{
new a;
new idx;
new cmd[256];
cmd = strtokcmd(cmdtext, idx);
if(strcmp(cmdtext, "/animhelp", true) == 0)
{
SendPsychoText(playerid,    COLOR_CMD," Система анимаций.Часть 1."," Anim System Part 1");
SendClientMessage(playerid, COLOR_CMD," /animped /dance /handsup /animclothes /animcoach /animcolt /animcopa /animcod /animcrack");
SendClientMessage(playerid, COLOR_CMD," /animairport /animat /animbar /animball /animfire /animbeach /animms /animbikev /animbmx ");
SendClientMessage(playerid, COLOR_CMD," /animbikedbz /animbp /animinf /animbiked /animbh /animfood /animbikelp  /animbikes /animcar");
SendClientMessage(playerid, COLOR_CMD," /animchase /animbox /animbomber /animbsp /animcamera /animgym /animpara /animgangs /animcarchat ");
SendClientMessage(playerid, COLOR_CMD," /animlookers  /animcasino /animbuddy /animbus /animcarry /animintshop /animjst /animkart /animkissing");
SendClientMessage(playerid, COLOR_CMD," /animknife /animlapdan /animdend /animmedic /animmtb /animmusc /animotb /animnevada /animpark /animsaw");
SendClientMessage(playerid, COLOR_CMD," /animchoppa /animcrib /animjump /animdealer /animdildo /animdodge /animdozer /animdrivebys /animfat");
SendClientMessage(playerid, COLOR_CMD," /animfightb /animfightc /animfightd /animfighte /animfinale /animfinale2 /animflamef");
SendClientMessage(playerid, COLOR_CMD," /animflowers /animghands /animfw /animghetto /animgog /animgraffity /animgreya /animgren");
return 1;
}
if(strcmp(cmdtext, "/animhelp2", true) == 0)
{
SendPsychoText(playerid, COLOR_CMD,"Система анимаций.Часть 2.","Anim System Part 2");
SendClientMessage(playerid, COLOR_CMD," /animhaircut /animheist  /animinthouse /animintoffice /animplayerdbf /animplayidles /animpolice");
SendClientMessage(playerid, COLOR_CMD," /animpool /animpoor /animpython /animquad /animquadbz /animrapping  /animrifle /animriot /animrobbank ");
SendClientMessage(playerid, COLOR_CMD," /animrocket /animrustler /animryder /animscrat /animshamal /animshop /animskate /animshotgun");
SendClientMessage(playerid, COLOR_CMD," /animvortex /animtec /animtrain /animsil /animtattoo  /animsmoking /animsniper /animspray /animstrip");
SendClientMessage(playerid, COLOR_CMD," /animbath /animswat /animsweet /animswim /animsword /animtank /animtruck /animuzi  /animvan /animvending");
SendClientMessage(playerid, COLOR_CMD," /animway /animweap /animsex /animbjob /animphone");
return 1;
}
if(strcmp(cmdtext, "/animhelp3", true) == 0)
{
SendPsychoText(playerid, COLOR_CMD," Система анимаций.Часть 3."," Anim System Part 3");
SendClientMessage(playerid, COLOR_CMD," /animcpo1 /animcpo2 /animcpo3 /animcpo4 /animcpo5 /animstop /animstandart");
return 1;
}
if(strcmp(cmd, "/animcpo1", true) == 0)
{
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 0 || a > 1) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animcpo1 [0-1] (Стандартно 0)"," USAGE: /animcpo1 [0-1](Standart 0)");
return 1;
}
if(a == 0){o1[playerid] = 0;SendPsychoText(playerid,COLOR_CMD," Готово."," Done.");
}else if(a == 1){o1[playerid] = 1;SendPsychoText(playerid,COLOR_CMD," Готово."," Done.");}
return 1;
}
if(strcmp(cmd, "/animcpo2", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 0 || a > 1) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animcpo2 [0-1] (Стандартно 1)"," USAGE: /animcpo2 [0-1](Standart 1)");
return 1;
}
if(a == 0) {
o2[playerid] = 0;
SendPsychoText(playerid,COLOR_CMD," Готово."," Done.");
} else if(a == 1) {
o2[playerid] = 1;
SendPsychoText(playerid,COLOR_CMD," Готово."," Done.");
}
return 1;
}
if(strcmp(cmd, "/animcpo3", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 0 || a > 1) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animcpo3 [0-1] (Стандартно 1)"," USAGE: /animcpo3 [0-1](Standart 1)");
return 1;
}
if(a == 0) {
o3[playerid] = 0;
SendPsychoText(playerid,COLOR_CMD," Готово."," Done.");
} else if(a == 1) {
o3[playerid] = 1;
SendPsychoText(playerid,COLOR_CMD," Готово."," Done.");
}
return 1;
}
if(strcmp(cmd, "/animcpo4", true) == 0)
{
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 0 || a > 1)
{
SendPsychoText(playerid,COLOR_CMD," Пишите: /animcpo4 [0-1] (Стандартно 1)"," USAGE: /animcpo4 [0-1](Standart 1)");
return 1;
}
if(a == 0)
{
o4[playerid] = 0;
SendPsychoText(playerid,COLOR_CMD," Готово."," Done.");
} else if(a == 1)
{
o4[playerid] = 1;
SendPsychoText(playerid,COLOR_CMD," Готово."," Done.");
}
return 1;
}
if(strcmp(cmd, "/animcpo5", true) == 0)
{
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
if(!strlen(atmp))
{
SendPsychoText(playerid,COLOR_CMD," Пишите: /animcpo5 [0-1] (Стандартно 1)"," USAGE:/animcpo5 [0-1] (Standart 1) ");
return 1;
}
a = strval(atmp);
if( !strlen(atmp) || a < 0 || a > 1)
{
SendPsychoText(playerid,COLOR_CMD, " Пишите: /animcpo5 [0-1] (Стандартно 1)"," USAGE:/animcpo5 [0-1] (Standart 1) ");
return 1;
}
if(a == 0)
{
o5[playerid] = 0;
SendPsychoText(playerid,COLOR_CMD," Готово."," Done.");
} else if(a == 1)
{
o5[playerid] = 1;
SendPsychoText(playerid,COLOR_CMD," Готово."," Done.");
}
return 1;
}
if(strcmp(cmdtext, "/standart", true) == 0)
{
FF[playerid] = 4.1;
o1[playerid] = 0;
o2[playerid] = 1;
o3[playerid] = 1;
o4[playerid] = 1;
o5[playerid] = 1;
SendPsychoText(playerid,COLOR_CMD,"Готово."," Done.");
return 1;
}
if(strcmp(cmd, "/animbar", true) == 0)
{
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 12)
{
SendPsychoText(playerid,COLOR_CMD," Пишите: /animbar [1-12]"," USAGE: /animbar [1-12]");
return 1;
}
AnimBar(playerid,a);
return 1;
}
if(strcmp(cmd, "/animball", true) == 0)
{
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 11)
{
SendPsychoText(playerid,COLOR_CMD," Пишите: /animball [1-11]"," USAGE: /animball [1-11]");
return 1;
}
AnimBall(playerid,a);
return 1;
}
if(strcmp(cmd, "/animfire", true) == 0)
{
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 13)
{
SendPsychoText(playerid,COLOR_CMD," Пишите: /animfire [1-13]"," USAGE: /animfire [1-13]");
return 1;
}
AnimFire(playerid,a);
return 1;
}
if(strcmp(cmd, "/animbeach", true) == 0)
{
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 5)
{
SendPsychoText(playerid,COLOR_CMD," Пишите: /animbeach [1-5]"," USAGE: /animbeach [1-5]");
return 1;
}
AnimBeach(playerid,a);
return 1;
}
if(strcmp(cmd, "/animinf", true) == 0)
{
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 4)
{
SendPsychoText(playerid,COLOR_CMD," Пишите: /animinf [1-4]"," USAGE: /animinf [1-4]");
return 1;
}
AnimInf(playerid,a);
return 1;
}
if(strcmp(cmd, "/animbiked", true) == 0)
{
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 19)
{
SendPsychoText(playerid,COLOR_CMD," Пишите: /animbiked [1-19]"," USAGE: /animbiked [1-19]");
return 1;
}
AnimBiked(playerid,a);
return 1;
}
if(strcmp(cmd, "/animbp", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 7)
{
SendPsychoText(playerid,COLOR_CMD," Пишите: /animbp [1-7]"," USAGE: /animbp [1-7]");
return 1;
}
AnimBp(playerid,a);
return 1;
}
if(strcmp(cmd, "/animbh", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 18)
{
SendPsychoText(playerid,COLOR_CMD," Пишите: /animbh [1-18]"," USAGE: /animbh [1-18]");
return 1;
}
AnimBh(playerid,a);
return 1;
}
if(strcmp(cmd, "/animfood", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 33) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animfood [1-33]"," USAGE: /animfood [1-33]");
return 1;
}
AnimFood(playerid,a);
return 1;
}
if(strcmp(cmd, "/animms", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 41) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animms [1-41]"," USAGE: /animms [1-41]");
return 1;
}
AnimMms(playerid,a);
return 1;
}
if(strcmp(cmd, "/animbikelp", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 9){
SendPsychoText(playerid,COLOR_CMD," Пишите: /animbikelp [1-9]"," USAGE: /animbikelp [1-9]");
return 1;
}
AnimBikeLP(playerid,a);
return 1;
}
if(strcmp(cmd, "/animbikes", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 18) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animbikes [1-18]"," USAGE: /animbikes [1-18]");
return 1;
}
AnimBikes(playerid,a);
return 1;
}
if(strcmp(cmd, "/animbikev", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 18) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animbikev [1-18]"," USAGE: /animbikev [1-18]");
return 1;
}
AnimBikeV(playerid,a);
return 1;
}
if(strcmp(cmd, "/animbmx", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 18) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animbmx [1-18]"," USAGE: /animbmx [1-18]");
return 1;
}
AnimBMX(playerid,a);
return 1;
}
if(strcmp(cmd, "/animbikedbz", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 4) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animbikedbz [1-4]"," USAGE: /animbikedbz [1-4]");
return 1;
}
AnimBikeDBZ(playerid,a);
return 1;
}
if(strcmp(cmd, "/animchase", true) == 0){
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 25) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animchase [1-25]"," USAGE: /animchase [1-25]");
return 1;
}
AnimChase(playerid,a);
return 1;
}
if(strcmp(cmd, "/animbox", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 10) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animbox [1-10]"," USAGE: /animbox [1-10]");
return 1;
}
AnimBox(playerid,a);
return 1;
}
if(strcmp(cmd, "/animbomber", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 6) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animbomber [1-6]"," USAGE: /animbomber [1-6]");
return 1;
}
AnimBomber(playerid,a);
return 1;
}
if(strcmp(cmd, "/animbsp", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 41) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animbsp [1-41]"," USAGE: /animbsp [1-41]");
return 1;
}
AnimBSP(playerid,a);
return 1;
}
if(strcmp(cmd, "/animcamera", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 14) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animcamera [1-14]"," USAGE: /animcamera [1-14]");
return 1;
}
AnimCamera(playerid,a);
return 1;
}
if(strcmp(cmd, "/animgym", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 24) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animgym [1-24]"," USAGE: /animgym [1-24]");
return 1;
}
AnimGYM(playerid,a);
return 1;
}
if(strcmp(cmd, "/animpara", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 22) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animpara [1-22]"," USAGE: /animpara [1-22]");
return 1;
}
AnimPara(playerid,a);
return 1;
}
if(strcmp(cmd, "/animgangs", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 33) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animgangs [1-33]"," USAGE: /animgangs [1-33]");
return 1;
}
AnimGangs(playerid,a);
return 1;
}
if(strcmp(cmd, "/animlowrider", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 39) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animlowrider [1-39]"," USAGE: /animlowrider [1-39]");
return 1;
}
AnimLowrider(playerid,a);
return 1;
}
if(strcmp(cmd, "/animlookers", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 25) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animlookers [1-25]"," USAGE: /animlookers [1-25]");
return 1;
}
AnimLookers(playerid,a);
return 1;
}
if(strcmp(cmd, "/animcarchat", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 20) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animcarchat [1-20]"," USAGE: /animcarchat [1-20]");
return 1;
}
AnimCarChat(playerid,a);
return 1;
}
if(strcmp(cmd, "/animcasino", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 23) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animcasino [1-23]"," USAGE: /animcasino [1-23]");
return 1;
}
AnimCasino(playerid,a);
return 1;
}
if(strcmp(cmd, "/animbuddy", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 5) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animbuddy [1-5]"," USAGE: /animbuddy [1-5]");
return 1;
}
AnimBuddy(playerid,a);
return 1;
}
if(strcmp(cmd, "/animbus", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 9) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animbus [1-9]"," USAGE: /animbus [1-9]");
return 1;
}
AnimBus(playerid,a);
return 1;
}
if(strcmp(cmd, "/animcar", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 11) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animcar [1-11]"," USAGE: /animcar [1-11]");
return 1;
}
AnimCar(playerid,a);
return 1;
}
if(strcmp(cmd, "/animcarry", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 7) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animcarry [1-7]"," USAGE: /animcarry [1-7]");
return 1;
}
AnimCarry(playerid,a);
return 1;
}
if(strcmp(cmd, "/animintshop", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 8) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animintshop [1-8]"," USAGE: /animintshop [1-8]");
return 1;
}
AnimIntShop(playerid,a);
return 1;
}
if(strcmp(cmd, "/animjst", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 4) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animjst [1-4]"," USAGE: /animjst [1-4]");
return 1;
}
AnimJst(playerid,a);
return 1;
}
if(strcmp(cmd, "/animkart", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 4) {
SendPsychoText(playerid,COLOR_CMD," Пишите:  /animkart [1-4]"," USAGE: /animkart [1-4]");
return 1;
}
AnimKART(playerid,a);
return 1;
}
if(strcmp(cmd, "/animkissing", true) == 0)
{
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 14) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animkissing [1-14]"," USAGE: /animkissing [1-14]");
return 1;
}
AnimKissing(playerid,a);
return 1;
}
if(strcmp(cmd, "/animknife", true) == 0)
{
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 14) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animknife [1-14]"," USAGE: /animknife [1-14]");
return 1;
}
AnimKnife(playerid,a);
return 1;
}
if(strcmp(cmd, "/animlapdan", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 6) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animlapdan [1-6]"," USAGE: /animlapdan [1-6]");
return 1;
}
AnimLapdan(playerid,a);
return 1;
}
if(strcmp(cmd, "/animdend", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 8) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animdend [1-8]"," USAGE: /animdend [1-8]");
return 1;
}
AnimDend(playerid,a);
return 1;
}
if(strcmp(cmdtext, "/animmedic", true) == 0)
{
CheckItNow(playerid);
ApplyAnimation(playerid,"MEDIC","CPR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);
return 1;
}
if(strcmp(cmd, "/animmtb", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 18) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animmtb [1-18]"," USAGE: /animmtb [1-18]");
return 1;
}
AnimBTM(playerid,a);
return 1;
}
if(strcmp(cmd, "/animmusc", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 17) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animmusc [1-17]"," USAGE: /animmusc [1-17]");
return 1;
}
AnimMusc(playerid,a);
return 1;
}
if(strcmp(cmd, "/animotb", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 11) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animotb [1-11]"," USAGE: /animotb [1-11]");
return 1;
}
AnimMOTB(playerid,a);
return 1;
}
if(strcmp(cmd, "/animnevada", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 2) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animnevada [1-2]"," USAGE: /animnevada [1-2]");
return 1;
}
AnimNevada(playerid,a);
return 1;
}
if(strcmp(cmd, "/animpark", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 3) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animpark [1-3]"," USAGE: /animpark [1-3]");
return 1;
}
AnimPark(playerid,a);
return 1;
}
if(strcmp(cmd, "/animpaul", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 12) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animpaul [1-12]"," USAGE: /animpaul [1-12]");
return 1;
}
AnimPaul(playerid,a);
return 1;
}
if(strcmp(cmd, "/animsaw", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 12) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animsaw [1-10]"," USAGE: /animsaw [1-10]");
return 1;
}
AnimSAW(playerid,a);
return 1;
}
if(strcmp(cmd, "/animchoppa", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 18) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animchoppa [1-18]"," USAGE: /animchoppa [1-18]");
return 1;
}
AnimChoppa(playerid,a);
return 1;
}
if(strcmp(cmd, "/animclothes", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 13) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animclothes [1-13]"," USAGE: /animclothes [1-13]");
return 1;
}
AnimClothes(playerid,a);
return 1;
}
if(strcmp(cmd, "/animcoach", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 6) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animcoach [1-6]"," USAGE: /animcoach [1-6]");
return 1;
}
AnimCoach(playerid,a);
return 1;
}
if(strcmp(cmd, "/animcolt", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 7) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animcolt [1-7]"," USAGE: /animcolt [1-7]");
return 1;
}
AnimColt(playerid,a);
return 1;
}
if(strcmp(cmd, "/animcopa", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 12) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animcopa[1-12]"," USAGE: /animcopa [1-12]");
return 1;
}
AnimCopa(playerid,a);
return 1;
}
if(strcmp(cmd, "/animcod", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 4) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animcod [1-4]"," USAGE: /animcod [1-4]");
return 1;
}
AnimCod(playerid,a);
return 1;
}
if(strcmp(cmd, "/animcrack", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 9) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animcrack [1-9]"," USAGE: /animcrib [1-5]");
return 1;
}
AnimCrack(playerid,a);
return 1;
}
if(strcmp(cmd, "/animcrib", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 5) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animcrib [1-5]"," USAGE: /animcrib [1-5]");
return 1;
}
AnimCrib(playerid,a);
return 1;
}
if(strcmp(cmd, "/animjump", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 5) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animjump [1-5]"," USAGE: /animjump [1-5]");
return 1;
}
AnimJump(playerid,a);
return 1;
}
if(strcmp(cmd, "/animdance", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 13) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animdance [1-13]"," USAGE: /animdance [1-13]");
return 1;
}
AnimDance(playerid,a);
return 1;
}
if(strcmp(cmd, "/animdealer", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 7) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animdealer [1-7]"," USAGE: /animdealer [1-7]");
return 1;
}
AnimDealer(playerid,a);
return 1;
}
if(strcmp(cmd, "/animdildo", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 9) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animdildo [1-9]"," USAGE: /animdildo [1-9]");
return 1;
}
AnimDildo(playerid,a);
return 1;
}
if(strcmp(cmd, "/animdodge", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 4) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animdodge [1-4]"," USAGE: /animdodge [1-4]");
return 1;
}
AnimDodge(playerid,a);
return 1;
}
if(strcmp(cmd, "/animdozer", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 9) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animdozer [1-9]"," USAGE: /animdozer [1-9]");
return 1;
}
AnimDozer(playerid,a);
return 1;
}
if(strcmp(cmd, "/animdrivebys", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 8) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animdrivebys [1-8]"," USAGE: /animdrivebys [1-8]");
return 1;
}
AnimDriveBys(playerid,a);
return 1;
}
if(strcmp(cmd, "/animfat", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 17) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animfat [1-17]"," USAGE: /animfat [1-17]");
return 1;
}
AnimFAT(playerid,a);
return 1;
}
if(strcmp(cmd, "/animfightb", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 10) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animfightb [1-10]"," USAGE: /animfightb [1-10]");
return 1;
}
AnimFIGHTB(playerid,a);
return 1;
}
if(strcmp(cmd, "/animfightc", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 12) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animfightc [1-12]"," USAGE: /animfightd [1-10]");
return 1;
}
AnimFIGHTC(playerid,a);
return 1;
}
if(strcmp(cmd, "/animfightd", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 10) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animfightd [1-10]"," USAGE: /animfightd [1-10]");
return 1;
}
AnimFIGHTD(playerid,a);
return 1;
}
if(strcmp(cmd, "/animfighte", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 4) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animfighte [1-4]"," USAGE: /animfighte [1-4]");
return 1;
}
AnimFIGHTE(playerid,a);
return 1;
}
if(strcmp(cmd, "/animfinale", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 16) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animfinale [1-16]"," USAGE: /animfinale [1-16]");
return 1;
}
AnimFinale(playerid,a);
return 1;
}
if(strcmp(cmd, "/animfinale2", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 8) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animfinale2 [1-8]"," USAGE: /animfinale2 [1-8]");
return 1;
}
AnimFinale2(playerid,a);
return 1;
}
if(strcmp(cmdtext, "/animflamef", true) == 0) {
CheckItNow(playerid);
ApplyAnimation(playerid,"FLAME","FLAME_fire",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);
return 1;
}
if(strcmp(cmd, "/animflowers", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 3) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animflowers [1-3]"," USAGE: /animflowers [1-3]");
return 1;
}
AnimFlowers(playerid,a);
return 1;
}
if(strcmp(cmd, "/animghands", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 20) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animghands [1-20]"," USAGE: /animghands [1-20]");
return 1;
}
AnimHands(playerid,a);
return 1;
}
if(strcmp(cmd, "/animfw", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 9) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animfw [1-9]"," USAGE: /animfw [1-9]");
return 1;
}
AnimFW(playerid,a);
return 1;
}
if(strcmp(cmd, "/animghetto", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 7) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animghetto [1-7]"," USAGE: /animghetto [1-7]");
return 1;
}
AnimGhetto(playerid,a);
return 1;
}
if(strcmp(cmdtext, "/animgog", true) == 0) {
CheckItNow(playerid);
ApplyAnimation(playerid,"goggles","goggles_put_on",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);
return 1;
}
if(strcmp(cmd, "/animgraffity", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 2) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animgraffity [1-2]"," USAGE: /animgraffity [1-2]");
return 1;
}
AnimGraffity(playerid,a);
return 1;
}
if(strcmp(cmd, "/animgreya", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 3) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animgreya [1-3]"," USAGE: /animgreya [1-3]");
return 1;
}
AnimGreya(playerid,a);
return 1;
}
if(strcmp(cmd, "/animgren", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 3) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animgren [1-3]"," USAGE: /animgren [1-3]");
return 1;
}
AnimGren(playerid,a);
return 1;
}
if(strcmp(cmd, "/animhaircut", true) == 0)
{
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 13) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animhaircut [1-13]"," USAGE: /animhaircut [1-13]");
return 1;
}
AnimHair(playerid,a);
return 1;
}
if(strcmp(cmd, "/animheist", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 10) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animheist [1-10]"," USAGE: /animheist [1-10]");
return 1;
}
AnimHeist(playerid,a);
return 1;
}
if(strcmp(cmd, "/animinthouse", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 10) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animinthouse [1-10]"," USAGE: /animinthouse [1-10]");
return 1;
}
AnimIntHouse(playerid,a);
return 1;
}
if(strcmp(cmd, "/animintoffice", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 10) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animintoffice [1-10]"," USAGE: /animintoffice [1-10]");
return 1;
}
AnimOffice(playerid,a);
return 1;
}
if(strcmp(cmd, "/animplayerdbf", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 4) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animplayerdbf [1-4]"," USAGE: /animplayerdbf [1-4]");
return 1;
}
AnimPDBF(playerid,a);
return 1;
}
if(strcmp(cmd, "/animplayidles", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 5) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animplayidles [1-5]"," USAGE: /animplayidles [1-5]");
return 1;
}
AnimPlayidles(playerid,a);
return 1;
}
if(strcmp(cmd, "/animpolice", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 10) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animpolice [1-10]"," USAGE: /animpolice [1-10]");
return 1;
}
AnimPolice(playerid,a);
return 1;
}
if(strcmp(cmd, "/animpool", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 21) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animpool [1-21]"," USAGE: /animpool [1-21]");
return 1;
}
AnimPool(playerid,a);
return 1;
}
if(strcmp(cmd, "/animpoor", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 2) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animpoor [1-2]"," USAGE: /animpoor [1-2]");
return 1;
}
AnimPoor(playerid,a);
return 1;
}
if(strcmp(cmd, "/animpython", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 5) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animpython [1-5]"," USAGE: /animpython [1-5]");
return 1;
}
AnimPython(playerid,a);
return 1;
}
if(strcmp(cmd, "/animquad", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 17) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animquad [1-17]"," USAGE: /animquad [1-17]");
return 1;
}
AnimQUAD(playerid,a);
return 1;
}
if(strcmp(cmd, "/animquadbz", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 4) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animquadbz [1-4]"," USAGE: /animquadbz [1-4]");
return 1;
}
AnimQDBZ(playerid,a);
return 1;
}
if(strcmp(cmd, "/animrapping", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 8) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animrapping [1-8]"," USAGE: /animrapping [1-8]");
return 1;
}
AnimRapping(playerid,a);
return 1;
}
if(strcmp(cmd, "/animrifle", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 5) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animrifle [1-5]"," USAGE: /animrifle [1-5]");
return 1;
}
AnimRifle(playerid,a);
return 1;
}
if(strcmp(cmd, "/animriot", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 7) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animriot [1-7]"," USAGE: /animriot [1-7]");
return 1;
}
AnimRiot(playerid,a);
return 1;
}
if(strcmp(cmd, "/animrobbank", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 5) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animrobbank [1-5]"," USAGE: /animrobbank [1-5]");
return 1;
}
AnimRobBank(playerid,a);
return 1;
}
if(strcmp(cmd, "/animrocket", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 5) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animrocket [1-5]"," USAGE: /animrocket [1-5]");
return 1;
}
AnimRocket(playerid,a);
return 1;
}
if(strcmp(cmd, "/animrustler", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 5) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animrustler [1-5]"," USAGE: /animrustler [1-5]");
return 1;
}
AnimRustler(playerid,a);
return 1;
}
if(strcmp(cmd, "/animryder", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 15) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animryder [1-15]"," USAGE: /animryder [1-15]");
return 1;
}
AnimRyder(playerid,a);
return 1;
}
if(strcmp(cmd, "/animscrat", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 12) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animscrat [1-12]"," USAGE: /animscrat [1-12]");
return 1;
}
AnimScrat(playerid,a);
return 1;
}
if(strcmp(cmd, "/animshamal", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 4) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animshamal [1-4]"," USAGE: /animshamal [1-4]");
return 1;
}
AnimShamal(playerid,a);
return 1;
}
if(strcmp(cmd, "/animshop", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 24) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animshop [1-24]"," USAGE: /animshop [1-24]");
return 1;
}
AnimShop(playerid,a);
return 1;
}
if(strcmp(cmd, "/animshotgun", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 3) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animshotgun [1-3]"," USAGE: /animshotgun [1-3]");
return 1;
}
AnimShotgun(playerid,a);
return 1;
}
if(strcmp(cmd, "/animskate", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 3) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animskate [1-3]"," USAGE: /animskate [1-3]");
return 1;
}
AnimSkate(playerid,a);
return 1;
}
if(strcmp(cmd, "/animvortex", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 4) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animvortex [1-4]"," USAGE: /animvortex [1-4]");
return 1;
}
AnimVortex(playerid,a);
return 1;
}
if(strcmp(cmd, "/animtec", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 4) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animtec [1-4]"," USAGE: /animtec [1-4]");
return 1;
}
AnimTEC9(playerid,a);
return 1;
}
if(strcmp(cmd, "/animtrain", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 4) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animtrain [1-4]"," USAGE: /animtrain [1-4]");
return 1;
}
AnimTrain(playerid,a);
return 1;
}
if(strcmp(cmd, "/animsil", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 4) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animsil [1-4]"," USAGE: /animsil [1-4]");
return 1;
}
AnimSilence(playerid,a);
return 1;
}
if(strcmp(cmd, "/animtattoo", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 57) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animtattoo [1-57]"," USAGE: /animtattoo [1-57]");
return 1;
}
AnimTattoo(playerid,a);
return 1;
}
if(strcmp(cmd, "/animsmoking", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 8) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animsmoking [1-8]"," USAGE: /animsmoking [1-8]");
return 1;
}
AnimSmoking(playerid,a);
return 1;
}
if(strcmp(cmdtext, "/animsniper", true) == 0) {
CheckItNow(playerid);
ApplyAnimation(playerid,"SNIPER","WEAPON_sniper",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);
return 1;
}
if(strcmp(cmd, "/animspray", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 2) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animspray [1-2]"," USAGE: /animspray [1-2]");
return 1;
}
AnimSpray(playerid,a);
return 1;
}
if(strcmp(cmd, "/animstrip", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 20) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animstrip [1-20]"," USAGE: /animstrip [1-20]");
return 1;
}
AnimStrip(playerid,a);
return 1;
}
if(strcmp(cmd, "/animbath", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 18) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animbath [1-18]"," USAGE: /animbath [1-18]");
return 1;
}
AnimBath(playerid,a);
return 1;
}
if(strcmp(cmd, "/animswat", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 24) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animswat [1-24]"," USAGE: /animswat [1-24]");
return 1;
}
AnimSwat(playerid,a);
return 1;
}
if(strcmp(cmd, "/animsweet", true) == 0)
{
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 7) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animsweet [1-7]"," USAGE: /animsweet [1-7]");
return 1;
}
AnimSweet(playerid,a);
return 1;
}
if(strcmp(cmd, "/animswim", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 7) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animswim [1-7]"," USAGE: /animswim [1-7]");
return 1;
}
AnimSwim(playerid,a);
return 1;
}
if(strcmp(cmd, "/animsword", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 10) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animsword [1-10]"," USAGE: /animsword [1-10]");
return 1;
}
AnimSword(playerid,a);
return 1;
}
if(strcmp(cmd, "/animtank", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 6) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animtank [1-6]"," USAGE: /animtank [1-6]");
return 1;
}
AnimTank(playerid,a);
return 1;
}
if(strcmp(cmd, "/animtruck", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 17) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animtruck [1-17]"," USAGE: /animtruck [1-17]");
return 1;
}
AnimTruck(playerid,a);
return 1;
}
if(strcmp(cmd, "/animuzi", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 5) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animuzi [1-5]"," USAGE: /animuzi [1-5]");
return 1;
}
AnimUZI(playerid,a);
return 1;
}
if(strcmp(cmd, "/animvan", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 8) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animvan [1-8]"," USAGE: /animvan [1-8]");
return 1;
}
AnimVan(playerid,a);
return 1;
}
if(strcmp(cmd, "/animvending", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 6) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animvending [1-6]"," USAGE: /animvending [1-6]");
return 1;
}
AnimVending(playerid,a);
return 1;
}
if(strcmp(cmd, "/animway", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 17) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animway [1-17]"," USAGE: /animway [1-17]");
return 1;
}
AnimWay(playerid,a);
return 1;
}
if(strcmp(cmd, "/animweap", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 17) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animweap [1-17]"," USAGE: /animweap [1-17]");
return 1;
}
AnimWeap(playerid,a);
return 1;
}
if(strcmp(cmd, "/animwuzi", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 12) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animwuzi [1-12]"," USAGE: /animwuzi [1-12]");
return 1;
}
AnimWuzi(playerid,a);
return 1;
}
if(strcmp(cmd, "/animat", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 3) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animat [1-3]"," USAGE: /animat [1-3]");
return 1;
}
AnimMat(playerid,a);
return 1;
}
if(strcmp(cmdtext, "/animairport", true) == 0)
{
CheckItNow(playerid);
ApplyAnimation(playerid,"AIRPORT","thrw_barl_thrw",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);
return 1;
}
if(strcmp(cmd, "/animped", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 294) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animped [1-294]"," USAGE: /animped [1-294]");
return 1;
}
AnimPed(playerid,a);
return 1;
}
if(strcmp(cmdtext, "/handsup", true) == 0)
{
CheckItNow(playerid);
SetPlayerSpecialAction(playerid,SPECIAL_ACTION_HANDSUP);
return 1;
}
if(strcmp(cmd, "/dance", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 3) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /dance [1-4]"," USAGE: /dance [1-4]");
return 1;
}
if(a == 1) {
SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE1);
} else if(a == 2) {
SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE2);
} else if(a == 3) {
SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE3);
} else if(a == 4) {
SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE4);
}
return 1;
}
if(strcmp(cmd, "/animphone", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 3) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animphone [1-3]"," USAGE: /animphone [1-3]");
return 1;
}
if(a == 1) {
SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USECELLPHONE);
} else if(a == 2) {
SetPlayerSpecialAction(playerid,SPECIAL_ACTION_SITTING);
} else if(a == 3) {
SetPlayerSpecialAction(playerid,SPECIAL_ACTION_STOPUSECELLPHONE);
}
return 1;
}
if(strcmp(cmd, "/animsex", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 8) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animsex [1-8]"," USAGE: /animsex [1-8]");
return 1;
}
AnimSex(playerid,a);
return 1;
}
if(strcmp(cmd, "/animbjob", true) == 0) {
new atmp[256];  atmp = strtokcmd(cmdtext, idx);
CheckItNow(playerid);
a = strval(atmp);
if( !strlen(atmp) || a < 1 || a > 12) {
SendPsychoText(playerid,COLOR_CMD," Пишите: /animbjob [1-12]"," USAGE: /animbjob [1-12]");
return 1;
}
AnimBjob(playerid,a);
return 1;
}
if(!strcmp(cmdtext, "/animstop", true)){
CheckItNow(playerid);
ClearAnimations(playerid);
return 1;
}
if(strcmp(cmdtext, "/piss", true) == 0){
CheckItNow(playerid);
SetPlayerSpecialAction(playerid,68);
return 1;
}
if(strcmp(cmdtext,"/anim",true) == 0 && IsPlayerAdmin(playerid) == 1)
{
if(AnimsON == 1)
{
SendPsychoText(playerid,COLOR_CMD," Cистема анимаций выключена."," Animation system now off.");
AnimsON = 0;
}else{
SendPsychoText(playerid,COLOR_CMD," Cистема анимаций включена."," Animation system now on.");
AnimsON = 1;
}
return 1;
}
return 0;
}

stock SendPsychoText(playerid, color, const message0[], const message1[])
{
if(L == 0){SendClientMessage(playerid, color, message0);return 1;}
if(L == 1){SendClientMessage(playerid, color, message1);return 1;}
return 1;
}


stock TogglePlayerControllableP(playerid, toggle){
if(toggle == 0){TogglePlayerControllable(playerid,0);PlayerFreezed[playerid] = 1;}
if(toggle == 1){TogglePlayerControllable(playerid,1);PlayerFreezed[playerid] = 0;}
return 1;
}


strtokcmd(const string[], &index)
{
new length = strlen(string);
while ((index < length) && (string[index] <= ' ')){
index++;
}
new offset = index;
new result[20];
while ((index < length) && (string[index] > ' ') && ((index - offset) < (sizeof(result) - 1)))
{
result[index - offset] = string[index];
index++;
}
result[index - offset] = EOS;
return result;
}


forward CheckItNow(playerid);
public CheckItNow(playerid){
if(PlayerFreezed[playerid] == 1){SendPsychoText(playerid, COLOR_CMD," Нельзя использовать анимации во время заморозки."," Do not use animation during freeze.");return 1;}
if(AnimsON == 0){SendPsychoText(playerid, COLOR_CMD," Анимации временно выключены."," Animation System Now Off.");return 1;}
return 1;
}



forward AnimBar(playerid,s);
public AnimBar(playerid,s){
if(s == 1){ApplyAnimation(playerid,"BAR","Barcustom_get",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"BAR","Barcustom_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"BAR","Barcustom_order",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"BAR","Barserve_bottle",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"BAR","Barserve_give",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"BAR","Barserve_glass",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"BAR","Barserve_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"BAR","Barserve_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"BAR","Barserve_order",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"BAR","dnk_stndF_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"BAR","dnk_stndM_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"BAR","BARman_idle",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimBall(playerid,s);
public AnimBall(playerid,s){
if(s == 1){ApplyAnimation(playerid,"BASEBALL","Bat_1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"BASEBALL","Bat_2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"BASEBALL","Bat_2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"BASEBALL","Bat_4",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"BASEBALL","Bat_block",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"BASEBALL","Bat_Hit_1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"BASEBALL","Bat_Hit_2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"BASEBALL","Bat_Hit_3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"BASEBALL","Bat_IDLE",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"BASEBALL","Bat_M",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"BASEBALL","BAT_PART",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimFire(playerid,s);
public AnimFire(playerid,s){
if(s == 1){ApplyAnimation(playerid,"BD_FIRE","BD_Fire1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"BD_FIRE","BD_Fire2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"BD_FIRE","BD_Fire3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"BD_FIRE","BD_GF_Wave",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"BD_FIRE","BD_Panic_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"BD_FIRE","BD_Panic_02",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"BD_FIRE","BD_Panic_03",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"BD_FIRE","BD_Panic_04",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"BD_FIRE","BD_Panic_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"BD_FIRE","M_smklean_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"BD_FIRE","M_smklean_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"BD_FIRE","Playa_Kiss_03",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"BD_FIRE","wash_up",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimBeach(playerid,s);
public AnimBeach(playerid,s){
if(s == 1){ApplyAnimation(playerid,"BEACH","bather",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"BEACH","Lay_Bac_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"BEACH","BD_Fire3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"BEACH","ParkSit_W_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"BEACH","SitnWait_loop_W",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimInf(playerid,s);
public AnimInf(playerid,s){
if(s == 1){ApplyAnimation(playerid,"BF_injection","BF_getin_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"BF_injection","BF_getin_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"BF_injection","BF_getout_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"BF_injection","BF_getout_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimBp(playerid,s);
public AnimBp(playerid,s){
if(s == 1){ApplyAnimation(playerid,"benchpress","gym_bp_celebrate",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"benchpress","gym_bp_down",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"benchpress","gym_bp_getoff",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"benchpress","gym_bp_geton",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"benchpress","gym_bp_up_A",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"benchpress","gym_bp_up_B",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"benchpress","gym_bp_up_smooth",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimBh(playerid,s);
public AnimBh(playerid,s){
if(s == 1){ApplyAnimation(playerid,"BIKEH","BIKEh_Back",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"BIKEH","BIKEh_drivebyFT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"BIKEH","BIKEh_drivebyLHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"BIKEH","BIKEh_drivebyRHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"BIKEH","BIKEh_Fwd",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"BIKEH","BIKEh_getoffBACK",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"BIKEH","BIKEh_getoffLHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"BIKEH","BIKEh_getoffRHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"BIKEH","BIKEh_hit",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"BIKEH","BIKEh_jumponL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"BIKEH","BIKEh_jumponR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"BIKEH","BIKEh_kick",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"BIKEH","BIKEh_Left",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"BIKEH","BIKEh_passenger",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"BIKEH","BIKEh_pushes",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"BIKEH","BIKEh_Ride",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"BIKEH","BIKEh_Right",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"BIKEH","BIKEh_Still",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimFood(playerid,s);
public AnimFood(playerid,s){
if(s == 1){ApplyAnimation(playerid,"FOOD","EAT_Burger",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"FOOD","EAT_Chicken",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"FOOD","EAT_Pizza",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"FOOD","EAT_Vomit_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"FOOD","EAT_Vomit_SK",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"FOOD","FF_Dam_Bkw",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"FOOD","FF_Dam_Fwd",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"FOOD","FF_Dam_Left",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"FOOD","FF_Dam_Right",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"FOOD","FF_Die_Bkw",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"FOOD","FF_Die_Fwd",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"FOOD","FF_Die_Left",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"FOOD","FF_Die_Right",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"FOOD","FF_Sit_Eat1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"FOOD","FF_Sit_Eat2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"FOOD","FF_Sit_Eat3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"FOOD","FF_Sit_In",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"FOOD","FF_Sit_In_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 19){ApplyAnimation(playerid,"FOOD","FF_Sit_In_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 20){ApplyAnimation(playerid,"FOOD","FF_Sit_Look",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 21){ApplyAnimation(playerid,"FOOD","FF_Sit_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 22){ApplyAnimation(playerid,"FOOD","FF_Sit_Out_180",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 23){ApplyAnimation(playerid,"FOOD","FF_Sit_Out_L_180",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 24){ApplyAnimation(playerid,"FOOD","FF_Sit_Out_R_180",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 25){ApplyAnimation(playerid,"FOOD","SHP_Thank",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 26){ApplyAnimation(playerid,"FOOD","SHP_Tray_In",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 27){ApplyAnimation(playerid,"FOOD","SHP_Tray_Lift",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 28){ApplyAnimation(playerid,"FOOD","SHP_Tray_Lift_In",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 29){ApplyAnimation(playerid,"FOOD","SHP_Tray_Lift_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 30){ApplyAnimation(playerid,"FOOD","SHP_Tray_Lift_Out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 31){ApplyAnimation(playerid,"FOOD","SHP_Tray_Out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 32){ApplyAnimation(playerid,"FOOD","SHP_Tray_Pose",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 33){ApplyAnimation(playerid,"FOOD","SHP_Tray_Return",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimMms(playerid,s);
public AnimMms(playerid,s){
if(s == 1){ApplyAnimation(playerid,"MISC","bitchslap",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"MISC","BMX_celebrate",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"MISC","BMX_comeon",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"MISC","bmx_idleloop_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"MISC","bmx_idleloop_02",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"MISC","bmx_talkleft_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"MISC","bmx_talkleft_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"MISC","bmx_talkleft_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"MISC","bmx_talkright_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"MISC","bmx_talkright_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"MISC","bmx_talkright_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"MISC","bng_wndw",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"MISC","bng_wndw_02",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"MISC","Case_pickup",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"MISC","door_jet",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"MISC","GRAB_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"MISC","GRAB_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"MISC","Hiker_Pose",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 19){ApplyAnimation(playerid,"MISC","Hiker_Pose_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 20){ApplyAnimation(playerid,"MISC","Idle_Chat_02",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 21){ApplyAnimation(playerid,"MISC","KAT_Throw_K",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 22){ApplyAnimation(playerid,"MISC","KAT_Throw_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 23){ApplyAnimation(playerid,"MISC","KAT_Throw_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 24){ApplyAnimation(playerid,"MISC","PASS_Rifle_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 25){ApplyAnimation(playerid,"MISC","PASS_Rifle_Ped",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 26){ApplyAnimation(playerid,"MISC","PASS_Rifle_Ply",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 27){ApplyAnimation(playerid,"MISC","pickup_box",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 28){ApplyAnimation(playerid,"MISC","Plane_door",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 29){ApplyAnimation(playerid,"MISC","Plane_exit",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 30){ApplyAnimation(playerid,"MISC","Plane_hijack",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 31){ApplyAnimation(playerid,"MISC","Plunger_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 32){ApplyAnimation(playerid,"MISC","Plyrlean_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 33){ApplyAnimation(playerid,"MISC","plyr_shkhead",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 34){ApplyAnimation(playerid,"MISC","Run_Dive",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 35){ApplyAnimation(playerid,"MISC","Scratchballs_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 36){ApplyAnimation(playerid,"MISC","SEAT_LR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 37){ApplyAnimation(playerid,"MISC","Seat_talk_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 38){ApplyAnimation(playerid,"MISC","Seat_talk_02",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 39){ApplyAnimation(playerid,"MISC","SEAT_watch",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 40){ApplyAnimation(playerid,"MISC","smalplane_door",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 41){ApplyAnimation(playerid,"MISC","smlplane_door",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimBikeLP(playerid,s);
public AnimBikeLP(playerid,s){
if(s == 1){ApplyAnimation(playerid,"BIKELEAP","bk_blnce_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"BIKELEAP","bk_blnce_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"BIKELEAP","bk_jmp",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"BIKELEAP","bk_rdy_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"BIKELEAP","bk_rdy_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"BIKELEAP","struggle_cesar",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"BIKELEAP","struggle_driver",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"BIKELEAP","truck_driver",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"BIKELEAP","truck_getin",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimBikes(playerid,s);
public AnimBikes(playerid,s){
if(s == 1){ApplyAnimation(playerid,"BIKES","BIKEs_Back",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"BIKES","BIKEs_drivebyFT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"BIKES","BIKEs_drivebyLHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"BIKES","BIKEs_drivebyRHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"BIKES","BIKEs_Fwd",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"BIKES","BIKEs_getoffBACK",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"BIKES","BIKEs_getoffLHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"BIKES","BIKEs_getoffRHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"BIKES","BIKEs_hit",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"BIKES","BIKEs_jumponL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"BIKES","BIKEs_jumponR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"BIKES","BIKEs_kick",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"BIKES","BIKEs_Left",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"BIKES","BIKEs_passenger",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"BIKES","BIKEs_pushes",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"BIKES","BIKEs_Ride",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"BIKES","BIKEs_Right",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"BIKES","BIKEs_Still",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimBikeV(playerid,s);
public AnimBikeV(playerid,s){
if(s == 1){ApplyAnimation(playerid,"BIKEV","BIKEv_Back",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"BIKEV","BIKEv_drivebyFT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"BIKEV","BIKEv_drivebyLHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"BIKEV","BIKEv_drivebyRHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"BIKEV","BIKEv_Fwd",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"BIKEV","BIKEv_getoffBACK",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"BIKEV","BIKEv_getoffLHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"BIKEV","BIKEv_getoffRHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"BIKEV","BIKEv_hit",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"BIKEV","BIKEv_jumponL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"BIKEV","BIKEv_jumponR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"BIKEV","BIKEv_kick",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"BIKEV","BIKEv_Left",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"BIKEV","BIKEv_passenger",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"BIKEV","BIKEv_pushes",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"BIKEV","BIKEv_Ride",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"BIKEV","BIKEv_Right",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"BIKEV","BIKEv_Still",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimBMX(playerid,s);
public AnimBMX(playerid,s){
if(s == 1){ApplyAnimation(playerid,"BMX","BMX_back",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"BMX","BMX_bunnyhop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"BMX","BMX_drivebyFT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"BMX","BMX_driveby_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"BMX","BMX_driveby_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"BMX","BMX_fwd",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"BMX","BMX_getoffBACK",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"BMX","BMX_pushes",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"BMX","BMX_getoffLHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"BMX","BMX_getoffRHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"BMX","BMX_jumponL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"BMX","BMX_jumponR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"BMX","BMX_Left",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"BMX","BMX_pedal",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"BMX","BMX_Ride",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"BMX","BMX_Right",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"BMX","BMX_sprint",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"BMX","BMX_still",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimBikeDBZ(playerid,s);
public AnimBikeDBZ(playerid,s){
if(s == 1){ApplyAnimation(playerid,"BIKE_DBZ","Pass_Driveby_BWD",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"BIKE_DBZ","Pass_Driveby_FWD",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"BIKE_DBZ","Pass_Driveby_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"BIKE_DBZ","Pass_Driveby_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimChase(playerid,s);
public AnimChase(playerid,s){
if(s == 1){ApplyAnimation(playerid,"MD_CHASE","Carhit_Hangon",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"MD_CHASE","Carhit_Tumble",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"MD_CHASE","donutdrop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"MD_CHASE","Fen_Choppa_L1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"MD_CHASE","Fen_Choppa_L2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"MD_CHASE","Fen_Choppa_L3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"MD_CHASE","Fen_Choppa_R1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"MD_CHASE","Fen_Choppa_R2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"MD_CHASE","Fen_Choppa_R3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"MD_CHASE","Hangon_Stun_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"MD_CHASE","Hangon_Stun_Turn",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_2_HANG",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Jmp_BL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Jmp_F",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Lnd_BL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Lnd_Die_BL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Lnd_Die_F",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Lnd_F",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 19){ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Lnd_Roll",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 20){ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Lnd_Roll_F",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 21){ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Punch",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 22){ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Punch_F",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 23){ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Shot_F",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 24){ApplyAnimation(playerid,"MD_CHASE","MD_HANG_Lnd_Roll",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 25){ApplyAnimation(playerid,"MD_CHASE","MD_HANG_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimBox(playerid,s);
public AnimBox(playerid,s){
if(s == 1){ApplyAnimation(playerid,"BOX","boxhipin",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"BOX","boxhipup",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"BOX","boxshdwn",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"BOX","boxshup",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"BOX","bxhipwlk",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"BOX","bxhwlki",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"BOX","bxshwlk",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"BOX","bxshwlki",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"BOX","bxwlko",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"BOX","catch_box",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimBomber(playerid,s);
public AnimBomber(playerid,s){
if(s == 1){ApplyAnimation(playerid,"BOMBER","BOM_Plant",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"BOMBER","BOM_Plant_2Idle",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"BOMBER","BOM_Plant_Crouch_In",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"BOMBER","BOM_Plant_Crouch_Out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"BOMBER","BOM_Plant_In",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"BOMBER","BOM_Plant_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimBSP(playerid,s);
public AnimBSP(playerid,s){
if(s == 1){ApplyAnimation(playerid,"BSKTBALL","BBALL_def_jump_shot",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"BSKTBALL","BBALL_def_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"BSKTBALL","BBALL_def_stepL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"BSKTBALL","BBALL_def_stepR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"BSKTBALL","BBALL_Dnk",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"BSKTBALL","BBALL_Dnk_Gli",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"BSKTBALL","BBALL_Dnk_Gli_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"BSKTBALL","BBALL_Dnk_Lnch",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"BSKTBALL","BBALL_Dnk_Lnch_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"BSKTBALL","BBALL_Dnk_Lnd",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"BSKTBALL","BBALL_Dnk_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"BSKTBALL","BBALL_idle",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"BSKTBALL","BBALL_idle2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"BSKTBALL","BBALL_idle2_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"BSKTBALL","BBALL_idleloop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"BSKTBALL","BBALL_idleloop_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"BSKTBALL","BBALL_idle_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"BSKTBALL","BBALL_Jump_Cancel",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 19){ApplyAnimation(playerid,"BSKTBALL","BBALL_Jump_Cancel_0",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 20){ApplyAnimation(playerid,"BSKTBALL","BBALL_Jump_End",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 21){ApplyAnimation(playerid,"BSKTBALL","BBALL_Jump_Shot",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 22){ApplyAnimation(playerid,"BSKTBALL","BBALL_Jump_Shot_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 23){ApplyAnimation(playerid,"BSKTBALL","BBALL_Net_Dnk_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 24){ApplyAnimation(playerid,"BSKTBALL","BBALL_pickup",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 25){ApplyAnimation(playerid,"BSKTBALL","BBALL_pickup_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 26){ApplyAnimation(playerid,"BSKTBALL","BBALL_react_miss",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 27){ApplyAnimation(playerid,"BSKTBALL","BBALL_react_score",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 28){ApplyAnimation(playerid,"BSKTBALL","BBALL_run",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 29){ApplyAnimation(playerid,"BSKTBALL","BBALL_run_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 30){ApplyAnimation(playerid,"BSKTBALL","BBALL_SkidStop_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 31){ApplyAnimation(playerid,"BSKTBALL","BBALL_SkidStop_L_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 32){ApplyAnimation(playerid,"BSKTBALL","BBALL_SkidStop_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 33){ApplyAnimation(playerid,"BSKTBALL","BBALL_SkidStop_R_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 34){ApplyAnimation(playerid,"KBSTBALL","BBALL_walk",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 35){ApplyAnimation(playerid,"BSKTBALL","BBALL_WalkStop_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 36){ApplyAnimation(playerid,"BSKTBALL","BBALL_WalkStop_L_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 37){ApplyAnimation(playerid,"BSKTBALL","BBALL_WalkStop_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 38){ApplyAnimation(playerid,"BSKTBALL","BBALL_WalkStop_R_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 39){ApplyAnimation(playerid,"BSKTBALL","BBALL_walk_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 40){ApplyAnimation(playerid,"BSKTBALL","BBALL_walk_start",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 41){ApplyAnimation(playerid,"BSKTBALL","BBALL_walk_start_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimCamera(playerid,s);
public AnimCamera(playerid,s){
if(s == 1){ApplyAnimation(playerid,"CAMERA","camcrch_cmon",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"CAMERA","camcrch_idleloop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"CAMERA","camcrch_stay",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"CAMERA","camcrch_to_camstnd",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"CAMERA","camstnd_cmon",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"CAMERA","camstnd_idleloop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"CAMERA","camstnd_lkabt",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"CAMERA","camstnd_to_camcrch",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"CAMERA","piccrch_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"CAMERA","piccrch_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"CAMERA","piccrch_take",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"CAMERA","picstnd_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"CAMERA","picstnd_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"CAMERA","picstnd_take",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}

forward AnimPara(playerid,s);
public AnimPara(playerid,s){
if(s == 1){ApplyAnimation(playerid,"PARACHUTE","FALL_skyDive",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"PARACHUTE","FALL_SkyDive_Accel",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"PARACHUTE","FALL_skyDive_DIE",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"PARACHUTE","FALL_SkyDive_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"PARACHUTE","FALL_SkyDive_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"PARACHUTE","PARA_decel",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"PARACHUTE","PARA_decel_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"PARACHUTE","PARA_float",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"PARACHUTE","PARA_float_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"PARACHUTE","PARA_Land",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"PARACHUTE","PARA_Land_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"PARACHUTE","PARA_Land_Water",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"PARACHUTE","PARA_Land_Water_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"PARACHUTE","PARA_open",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"PARACHUTE","PARA_open_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"PARACHUTE","PARA_Rip_Land_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"PARACHUTE","PARA_Rip_Loop_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"PARACHUTE","PARA_Rip_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 19){ApplyAnimation(playerid,"PARACHUTE","PARA_steerL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 20){ApplyAnimation(playerid,"PARACHUTE","PARA_steerL_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 21){ApplyAnimation(playerid,"PARACHUTE","PARA_steerR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 22){ApplyAnimation(playerid,"PARACHUTE","PARA_steerR_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimGangs(playerid,s);
public AnimGangs(playerid,s){
if(s == 1){ApplyAnimation(playerid,"GANGS","DEALER_DEAL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"GANGS","DEALER_IDLE",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"GANGS","drnkbr_prtl",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"GANGS","drnkbr_prtl_F",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"GANGS","DRUGS_BUY",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"GANGS","hndshkaa",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"GANGS","hndshkba",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"GANGS","hndshkca",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"GANGS","hndshkcb",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"GANGS","hndshkda",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"GANGS","hndshkea",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"GANGS","hndshkfa",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"GANGS","hndshkfa_swt",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"GANGS","Invite_No",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"GANGS","Invite_Yes",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"GANGS","leanIDLE",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"GANGS","leanIN",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"GANGS","leanOUT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 19){ApplyAnimation(playerid,"GANGS","prtial_gngtlkA",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 20){ApplyAnimation(playerid,"GANGS","prtial_gngtlkB",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 21){ApplyAnimation(playerid,"GANGS","prtial_gngtlkCt",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 22){ApplyAnimation(playerid,"GANGS","prtial_gngtlkD",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 23){ApplyAnimation(playerid,"GANGS","prtial_gngtlkE",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 24){ApplyAnimation(playerid,"GANGS","prtial_gngtlkF",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 25){ApplyAnimation(playerid,"GANGS","prtial_gngtlkG",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 26){ApplyAnimation(playerid,"GANGS","prtial_gngtlkH",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 27){ApplyAnimation(playerid,"GANGS","prtial_hndshk_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 28){ApplyAnimation(playerid,"GANGS","prtial_hndshk_biz_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 29){ApplyAnimation(playerid,"GANGS","shake_cara",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 30){ApplyAnimation(playerid,"GANGS","shake_carK",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 31){ApplyAnimation(playerid,"GANGS","shake_carSH",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 32){ApplyAnimation(playerid,"GANGS","smkcig_prtl",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 33){ApplyAnimation(playerid,"GANGS","smkcig_prtl_F",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimLowrider(playerid,s);
public AnimLowrider(playerid,s){
if(s == 1){ApplyAnimation(playerid,"LOWRIDER","F_smklean_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"LOWRIDER","lrgirl_bdbnce",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"LOWRIDER","lrgirl_hair",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"LOWRIDER","lrgirl_hurry",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"LOWRIDER","lrgirl_idleloop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"LOWRIDER","lrgirl_idle_to_l0",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"LOWRIDER","lrgirl_l0_bnce",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"LOWRIDER","lrgirl_l0_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"LOWRIDER","lrgirl_l0_to_l1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"LOWRIDER","lrgirl_l12_to_l0",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"LOWRIDER","lrgirl_l1_bnce",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"LOWRIDER","lrgirl_l1_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"LOWRIDER","lrgirl_l1_to_l2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"LOWRIDER","lrgirl_l2_bnce",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"LOWRIDER","lrgirl_l2_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"LOWRIDER","lrgirl_l2_to_l3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"LOWRIDER","lrgirl_l345_to_l1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"LOWRIDER","lrgirl_l3_bnce",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 19){ApplyAnimation(playerid,"LOWRIDER","lrgirl_l3_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 20){ApplyAnimation(playerid,"LOWRIDER","lrgirl_l3_to_l4",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 21){ApplyAnimation(playerid,"LOWRIDER","lrgirl_l4_bnce",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 22){ApplyAnimation(playerid,"LOWRIDER","lrgirl_l4_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 23){ApplyAnimation(playerid,"LOWRIDER","lrgirl_l4_to_l5",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 24){ApplyAnimation(playerid,"LOWRIDER","lrgirl_l5_bnce",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 25){ApplyAnimation(playerid,"LOWRIDER","lrgirl_l5_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 26){ApplyAnimation(playerid,"LOWRIDER","M_smklean_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 27){ApplyAnimation(playerid,"LOWRIDER","M_smkstnd_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 28){ApplyAnimation(playerid,"LOWRIDER","prtial_gngtlkB",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 29){ApplyAnimation(playerid,"LOWRIDER","prtial_gngtlkC",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 30){ApplyAnimation(playerid,"LOWRIDER","prtial_gngtlkD",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 31){ApplyAnimation(playerid,"LOWRIDER","prtial_gngtlkE",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 32){ApplyAnimation(playerid,"LOWRIDER","prtial_gngtlkF",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 33){ApplyAnimation(playerid,"LOWRIDER","prtial_gngtlkG",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 34){ApplyAnimation(playerid,"LOWRIDER","prtial_gngtlkH",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 35){ApplyAnimation(playerid,"LOWRIDER","RAP_A_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 36){ApplyAnimation(playerid,"LOWRIDER","RAP_B_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 37){ApplyAnimation(playerid,"LOWRIDER","RAP_C_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 38){ApplyAnimation(playerid,"LOWRIDER","Sit_relaxed",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 39){ApplyAnimation(playerid,"LOWRIDER","Tap_hand",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimGYM(playerid,s);
public AnimGYM(playerid,s){
if(s == 1){ApplyAnimation(playerid,"GYMNASIUM","GYMshadowbox",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"GYMNASIUM","gym_bike_celebrate",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"GYMNASIUM","gym_bike_fast",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"GYMNASIUM","gym_bike_faster",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"GYMNASIUM","gym_bike_getoff",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"GYMNASIUM","gym_bike_geton",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"GYMNASIUM","gym_bike_pedal",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"GYMNASIUM","gym_bike_slow",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"GYMNASIUM","gym_bike_still",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"GYMNASIUM","gym_jog_falloff",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"GYMNASIUM","gym_shadowbox",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"GYMNASIUM","gym_tread_celebrate",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"GYMNASIUM","gym_tread_falloff",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"GYMNASIUM","gym_tread_getoff",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"GYMNASIUM","gym_tread_geton",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"GYMNASIUM","gym_tread_jog",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"GYMNASIUM","gym_tread_sprint",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"GYMNASIUM","gym_tread_tired",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 19){ApplyAnimation(playerid,"GYMNASIUM","gym_tread_walk",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 20){ApplyAnimation(playerid,"GYMNASIUM","gym_walk_falloff",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 21){ApplyAnimation(playerid,"GYMNASIUM","Pedals_fast",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 22){ApplyAnimation(playerid,"GYMNASIUM","Pedals_med",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 23){ApplyAnimation(playerid,"GYMNASIUM","Pedals_slow",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 24){ApplyAnimation(playerid,"GYMNASIUM","Pedals_still",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimLookers(playerid,s);
public AnimLookers(playerid,s){
if(s == 1){ApplyAnimation(playerid,"ON_LOOKERS","lkaround_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"ON_LOOKERS","lkaround_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"ON_LOOKERS","lkaround_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"ON_LOOKERS","lkup_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"ON_LOOKERS","lkup_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"ON_LOOKERS","lkup_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"ON_LOOKERS","lkup_point",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"ON_LOOKERS","panic_cower",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"ON_LOOKERS","panic_hide",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"ON_LOOKERS","panic_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"ON_LOOKERS","panic_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"ON_LOOKERS","panic_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"ON_LOOKERS","panic_point",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"ON_LOOKERS","panic_shout",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"ON_LOOKERS","Pointup_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"ON_LOOKERS","Pointup_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"ON_LOOKERS","Pointup_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"ON_LOOKERS","Pointup_shout",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 19){ApplyAnimation(playerid,"ON_LOOKERS","point_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 20){ApplyAnimation(playerid,"ON_LOOKERS","point_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 21){ApplyAnimation(playerid,"ON_LOOKERS","point_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 22){ApplyAnimation(playerid,"ON_LOOKERS","shout_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 23){ApplyAnimation(playerid,"ON_LOOKERS","shout_02",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 24){ApplyAnimation(playerid,"ON_LOOKERS","shout_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 25){ApplyAnimation(playerid,"ON_LOOKERS","shout_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 26){ApplyAnimation(playerid,"ON_LOOKERS","shout_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 27){ApplyAnimation(playerid,"ON_LOOKERS","wave_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 28){ApplyAnimation(playerid,"ON_LOOKERS","wave_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 29){ApplyAnimation(playerid,"ON_LOOKERS","wave_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimCarChat(playerid,s);
public AnimCarChat(playerid,s){
if(s == 1){ApplyAnimation(playerid,"CAR_CHAT","carfone_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"CAR_CHAT","carfone_loopA",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"CAR_CHAT","carfone_loopA_to_B",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"CAR_CHAT","carfone_loopB",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"CAR_CHAT","carfone_loopB_to_A",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"CAR_CHAT","carfone_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc1_BR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc1_FL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc1_FR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc2_FL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc3_BR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc3_FL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc3_FR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc4_BL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc4_BR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc4_FL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc4_FR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"CAR_CHAT","car_talkm_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 19){ApplyAnimation(playerid,"CAR_CHAT","car_talkm_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 20){ApplyAnimation(playerid,"CAR_CHAT","car_talkm_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}

forward AnimCasino(playerid,s);
public AnimCasino(playerid,s){
if(s == 1){ApplyAnimation(playerid,"CASINO","cards_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"CASINO","cards_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"CASINO","cards_lose",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"CASINO","cards_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"CASINO","cards_pick_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"CASINO","cards_pick_02",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"CASINO","cards_raise",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"CASINO","cards_win",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"CASINO","manwinb",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"CASINO","manwind",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"CASINO","Roulette_bet",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"CASINO","Roulette_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"CASINO","Roulette_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"CASINO","Roulette_lose",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"CASINO","Roulette_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"CASINO","Roulette_win",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"CASINO","Slot_bet_02",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"CASINO","Slot_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 19){ApplyAnimation(playerid,"CASINO","Slot_lose_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 20){ApplyAnimation(playerid,"CASINO","Slot_Plyr",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 21){ApplyAnimation(playerid,"CASINO","Slot_wait",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 22){ApplyAnimation(playerid,"CASINO","Slot_win_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 23){ApplyAnimation(playerid,"CASINO","wof",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimBuddy(playerid,s);
public AnimBuddy(playerid,s){
if(s == 1){ApplyAnimation(playerid,"BUDDY","buddy_crouchfire",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"BUDDY","buddy_crouchreload",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"BUDDY","buddy_fire",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"BUDDY","buddy_fire_poor",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"BUDDY","buddy_reload",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimBus(playerid,s);
public AnimBus(playerid,s){
if(s == 1){ApplyAnimation(playerid,"BUS","BUS_close",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"BUS","BUS_getin_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"BUS","BUS_getin_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"BUS","BUS_getout_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"BUS","BUS_getout_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"BUS","BUS_jacked_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"BUS","BUS_open",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"BUS","BUS_open_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"BUS","BUS_pullout_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimCar(playerid,s);
public AnimCar(playerid,s){
if(s == 1){ApplyAnimation(playerid,"CAR","Fixn_Car_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"CAR","Fixn_Car_Out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"CAR","flag_drop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"CAR","Sit_relaxed",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"CAR","Tap_hand",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"CAR","Tyd2car_bump",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"CAR","Tyd2car_high",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"CAR","Tyd2car_low",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"CAR","Tyd2car_med",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"CAR","Tyd2car_TurnL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"CAR","Tyd2car_TurnR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimCarry(playerid,s);
public AnimCarry(playerid,s){
if(s == 1){ApplyAnimation(playerid,"CARRY","crry_prtial",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"CARRY","liftup",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"CARRY","liftup05",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"CARRY","liftup105",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"CARRY","putdwn",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"CARRY","putdwn05",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"CARRY","putdwn105",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimIntShop(playerid,s);
public AnimIntShop(playerid,s){
if(s == 1){ApplyAnimation(playerid,"INT_SHOP","shop_cashier",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"INT_SHOP","shop_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"INT_SHOP","shop_lookA",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"INT_SHOP","shop_lookB",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"INT_SHOP","shop_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"INT_SHOP","shop_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"INT_SHOP","shop_pay",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"INT_SHOP","shop_shelf",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimJst(playerid,s);
public AnimJst(playerid,s){
if(s == 1){ApplyAnimation(playerid,"JST_BUISNESS","girl_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"JST_BUISNESS","girl_02",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"JST_BUISNESS","player_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"JST_BUISNESS","smoke_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimKART(playerid,s);
public AnimKART(playerid,s){
if(s == 1){ApplyAnimation(playerid,"KART","KART_getin_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"KART","KART_getin_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"KART","KART_getout_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"KART","KART_getout_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimKissing(playerid,s);
public AnimKissing(playerid,s){
if(s == 1){ApplyAnimation(playerid,"KISSING","BD_GF_Wave",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"KISSING","gfwave2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"KISSING","GF_CarArgue_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"KISSING","GF_CarArgue_02",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"KISSING","GF_CarSpot",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"KISSING","GF_StreetArgue_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"KISSING","GF_StreetArgue_02",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"KISSING","gift_give",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"KISSING","Grlfrd_Kiss_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"KISSING","Grlfrd_Kiss_02",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"KISSING","Grlfrd_Kiss_03",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"KISSING","Playa_Kiss_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"KISSING","Playa_Kiss_02",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"KISSING","Playa_Kiss_03",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimKnife(playerid,s);
public AnimKnife(playerid,s){
if(s == 1){ApplyAnimation(playerid,"KNIFE","KILL_Knife_Ped_Damage",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"KNIFE","KILL_Knife_Ped_Die",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"KNIFE","KILL_Knife_Player",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"KNIFE","KILL_Partial",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"KNIFE","knife_2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"KNIFE","knife_3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"KNIFE","knife_4",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"KNIFE","Knife_G",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"KNIFE","knife_hit_1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"KNIFE","knife_hit_2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"KNIFE","knife_IDLE",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"KNIFE","knife_hit_3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"KNIFE","knife_part",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"KNIFE","WEAPON_knifeidle",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimLapdan(playerid,s);
public AnimLapdan(playerid,s){
if(s == 1){ApplyAnimation(playerid,"LAPDAN1","LAPDAN_D",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"LAPDAN1","LAPDAN_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"LAPDAN2","LAPDAN_D",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"LAPDAN2","LAPDAN_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"LAPDAN3","LAPDAN_D",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"LAPDAN3","LAPDAN_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimDend(playerid,s);
public AnimDend(playerid,s){
if(s == 1){ApplyAnimation(playerid,"MD_END","END_SC1_PLY",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"MD_END","END_SC1_RYD",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"MD_END","END_SC1_SMO",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"MD_END","END_SC1_SWE",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"MD_END","END_SC2_PLY",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"MD_END","END_SC2_RYD",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"MD_END","END_SC2_SMO",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"MD_END","END_SC2_SWE",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimBTM(playerid,s);
public AnimBTM(playerid,s){
if(s == 1){ApplyAnimation(playerid,"MTB","MTB_back",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"MTB","MTB_bunnyhop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"MTB","MTB_drivebyFT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"MTB","MTB_driveby_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"MTB","MTB_driveby_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"MTB","MTB_fwd",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"MTB","MTB_getoffBACK",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"MTB","MTB_pushes",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"MTB","MTB_getoffLHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"MTB","MTB_getoffRHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"MTB","MTB_jumponL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"MTB","MTB_jumponR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"MTB","MTB_Left",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"MTB","MTB_pedal",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"MTB","MTB_Ride",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"MTB","MTB_Right",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"MTB","MTB_sprint",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"MTB","MTB_still",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimMusc(playerid,s);
public AnimMusc(playerid,s){
if(s == 1){ApplyAnimation(playerid,"MUSCULAR","MscleWalkst_armed",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"MUSCULAR","MscleWalkst_Csaw",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"MUSCULAR","Mscle_rckt_run",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"MUSCULAR","Mscle_rckt_walkst",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"MUSCULAR","Mscle_run_Csaw",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"MUSCULAR","MuscleIdle",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"MUSCULAR","MuscleIdle_armed",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"MUSCULAR","MuscleIdle_Csaw",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"MUSCULAR","MuscleIdle_rocket",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"MUSCULAR","MuscleRun",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"MUSCULAR","MuscleRun_armed",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"MUSCULAR","MuscleSprint",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"MUSCULAR","MuscleWalk",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"MUSCULAR","MuscleWalkstart",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"MUSCULAR","MuscleWalk_armed",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"MUSCULAR","Musclewalk_Csaw",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"MUSCULAR","Musclewalk_rocket",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimMOTB(playerid,s);
public AnimMOTB(playerid,s){
if(s == 1){ApplyAnimation(playerid,"OTB","betslp_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"OTB","betslp_lkabt",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"OTB","betslp_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"OTB","betslp_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"OTB","betslp_tnk",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"OTB","wtchrace_cmon",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"OTB","wtchrace_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"OTB","wtchrace_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"OTB","wtchrace_lose",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"OTB","wtchrace_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"OTB","wtchrace_win",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}

forward AnimSAW(playerid,s);
public AnimSAW(playerid,s){
if(s == 1){ApplyAnimation(playerid,"CHAINSAW","CSAW_1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"CHAINSAW","CSAW_2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"CHAINSAW","CSAW_3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"CHAINSAW","CSAW_G",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"CHAINSAW","CSAW_Hit_1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"CHAINSAW","CSAW_Hit_2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"CHAINSAW","CSAW_Hit_3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"CHAINSAW","IDLE_csaw",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"CHAINSAW","WEAPON_csaw",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"CHAINSAW","WEAPON_csawlo",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimChoppa(playerid,s);
public AnimChoppa(playerid,s){
if(s == 1){ApplyAnimation(playerid,"CHOPPA","CHOPPA_back",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"CHOPPA","CHOPPA_bunnyhop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"CHOPPA","CHOPPA_drivebyFT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"CHOPPA","CHOPPA_driveby_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"CHOPPA","CHOPPA_driveby_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"CHOPPA","CHOPPA_fwd",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"CHOPPA","CHOPPA_getoffBACK",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"CHOPPA","CHOPPA_getoffLHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"CHOPPA","CHOPPA_getoffRHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"CHOPPA","CHOPPA_jumponL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"CHOPPA","CHOPPA_jumponR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"CHOPPA","CHOPPA_Left",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"CHOPPA","CHOPPA_pedal",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"CHOPPA","CHOPPA_Pushes",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"CHOPPA","CHOPPA_ride",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"CHOPPA","CHOPPA_Right",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"CHOPPA","CHOPPA_sprint",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"CHOPPA","CHOPPA_Still",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimPark(playerid,s);
public AnimPark(playerid,s){
if(s == 1){ApplyAnimation(playerid,"PARK","Tai_Chi_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"PARK","Tai_Chi_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"PARK","Tai_Chi_Out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimNevada(playerid,s);
public AnimNevada(playerid,s){
if(s == 1){ApplyAnimation(playerid,"NEVADA","NEVADA_getin",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"NEVADA","NEVADA_getout",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimClothes(playerid,s);
public AnimClothes(playerid,s){
if(s == 1){ApplyAnimation(playerid,"CLOTHES","CLO_Buy",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"CLOTHES","CLO_In",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"CLOTHES","CLO_Out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"CLOTHES","CLO_Pose_Hat",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"CLOTHES","CLO_Pose_In",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"CLOTHES","CLO_Pose_In_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"CLOTHES","CLO_Pose_Legs",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"CLOTHES","CLO_Pose_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"CLOTHES","CLO_Pose_Out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"CLOTHES","CLO_Pose_Out_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"CLOTHES","CLO_Pose_Shoes",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"CLOTHES","CLO_Pose_Torso",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"CLOTHES","CLO_Pose_Watch",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimCoach(playerid,s);
public AnimCoach(playerid,s){
if(s == 1){ApplyAnimation(playerid,"COACH","COACH_inL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"COACH","COACH_inR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"COACH","COACH_opnL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"COACH","COACH_opnR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"COACH","COACH_outL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"COACH","COACH_outR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimColt(playerid,s);
public AnimColt(playerid,s){
if(s == 1){ApplyAnimation(playerid,"COLT45","2guns_crouchfire",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"COLT45","colt45_crouchfire",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"COLT45","colt45_crouchreload",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"COLT45","colt45_fire",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"COLT45","colt45_fire_2hands",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"COLT45","colt45_reload",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"COLT45","sawnoff_reload",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimCopa(playerid,s);
public AnimCopa(playerid,s){
if(s == 1){ApplyAnimation(playerid,"COP_AMBIENT","Copbrowse_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"COP_AMBIENT","Copbrowse_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"COP_AMBIENT","Copbrowse_nod",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"COP_AMBIENT","Copbrowse_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"COP_AMBIENT","Copbrowse_shake",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"COP_AMBIENT","Coplook_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"COP_AMBIENT","Coplook_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"COP_AMBIENT","Coplook_nod",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"COP_AMBIENT","Coplook_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"COP_AMBIENT","Coplook_shake",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"COP_AMBIENT","Coplook_think",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"COP_AMBIENT","Coplook_watch",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimPaul(playerid,s);
public AnimPaul(playerid,s){
if(s == 1){ApplyAnimation(playerid,"PAULNMAC","Piss_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"PAULNMAC","Piss_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"PAULNMAC","Piss_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"PAULNMAC","PnM_Argue1_A",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"PAULNMAC","PnM_Argue1_B",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"PAULNMAC","PnM_Argue2_A",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"PAULNMAC","PnM_Argue2_B",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"PAULNMAC","PnM_Loop_A",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"PAULNMAC","PnM_Loop_B",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"PAULNMAC","wank_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"PAULNMAC","wank_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"PAULNMAC","wank_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimCod(playerid,s);
public AnimCod(playerid,s){
if(s == 1){ApplyAnimation(playerid,"COP_DVBYZ","COP_Dvby_B",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"COP_DVBYZ","COP_Dvby_FT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"COP_DVBYZ","COP_Dvby_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"COP_DVBYZ","COP_Dvby_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimCrack(playerid,s);
public AnimCrack(playerid,s){
if(s == 1){ApplyAnimation(playerid,"CRACK","Bbalbat_Idle_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"CRACK","Bbalbat_Idle_02",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"CRACK","crckdeth1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"CRACK","crckdeth2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"CRACK","crckdeth3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"CRACK","crckdeth4",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"CRACK","crckidle1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"CRACK","crckidle2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"CRACK","crckidle3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimCrib(playerid,s);
public AnimCrib(playerid,s){
if(s == 1){ApplyAnimation(playerid,"CRIB","CRIB_Console_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"CRIB","CRIB_Use_Switch",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"CRIB","PED_Console_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"CRIB","PED_Console_Loose",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"CRIB","PED_Console_Win",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimJump(playerid,s);
public AnimJump(playerid,s){
if(s == 1){ApplyAnimation(playerid,"DAM_JUMP","DAM_Dive_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"DAM_JUMP","DAM_Land",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"DAM_JUMP","DAM_Launch",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"DAM_JUMP","Jump_Roll",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"DAM_JUMP","SF_JumpWall",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimDance(playerid,s);
public AnimDance(playerid,s){
if(s == 1){ApplyAnimation(playerid,"DANCING","bd_clap",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"DANCING","bd_clap1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"DANCING","dance_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"DANCING","DAN_Down_A",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"DANCING","DAN_Left_A",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"DANCING","DAN_Loop_A",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"DANCING","DAN_Right_A",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"DANCING","DAN_Up_A",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"DANCING","dnce_M_a",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"DANCING","dnce_M_b",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"DANCING","dnce_M_c",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"DANCING","dnce_M_d",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"DANCING","dnce_M_e",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimDealer(playerid,s);
public AnimDealer(playerid,s){
if(s == 1){ApplyAnimation(playerid,"DEALER","DEALER_DEAL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"DEALER","DEALER_IDLE",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"DEALER","DEALER_IDLE_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"DEALER","DEALER_IDLE_02",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"DEALER","DEALER_IDLE_03",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"DEALER","DRUGS_BUY",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"DEALER","shop_pay",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimDildo(playerid,s);
public AnimDildo(playerid,s){
if(s == 1){ApplyAnimation(playerid,"DILDO","DILDO_1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"DILDO","DILDO_2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"DILDO","DILDO_3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"DILDO","DILDO_block",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"DILDO","DILDO_G",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"DILDO","DILDO_Hit_1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"DILDO","DILDO_Hit_2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"DILDO","DILDO_Hit_3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"DILDO","DILDO_IDLE",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimDodge(playerid,s);
public AnimDodge(playerid,s){
if(s == 1){ApplyAnimation(playerid,"DODGE","Cover_Dive_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"DODGE","Cover_Dive_02",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"DODGE","Crushed",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"DODGE","Crush_Jump",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimDozer(playerid,s);
public AnimDozer(playerid,s){
if(s == 1){ApplyAnimation(playerid,"DOZER","DOZER_Align_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"DOZER","DOZER_Align_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"DOZER","DOZER_getin_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"DOZER","DOZER_getin_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"DOZER","DOZER_getout_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"DOZER","DOZER_getout_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"DOZER","DOZER_Jacked_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"DOZER","DOZER_Jacked_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"DOZER","DOZER_pullout_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimDriveBys(playerid,s);
public AnimDriveBys(playerid,s){
if(s == 1){ApplyAnimation(playerid,"DRIVEBYS","Gang_DrivebyLHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"DRIVEBYS","Gang_DrivebyLHS_Bwd",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"DRIVEBYS","Gang_DrivebyLHS_Fwd",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"DRIVEBYS","Gang_DrivebyRHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"DRIVEBYS","Gang_DrivebyRHS_Bwd",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"DRIVEBYS","Gang_DrivebyRHS_Fwd",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"DRIVEBYS","Gang_DrivebyTop_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"DRIVEBYS","Gang_DrivebyTop_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimFAT(playerid,s);
public AnimFAT(playerid,s){
if(s == 1){ApplyAnimation(playerid,"FAT","FatIdle",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"FAT","FatIdle_armed",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"FAT","FatIdle_Csaw",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"FAT","FatIdle_Rocket",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"FAT","FatRun",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"FAT","FatRun_armed",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"FAT","FatRun_Csaw",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"FAT","FatRun_Rocket",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"FAT","FatSprint",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"FAT","FatWalk",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"FAT","FatWalkstart",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"FAT","FatWalkstart_Csaw",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"FAT","FatWalkSt_armed",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"FAT","FatWalkSt_Rocket",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"FAT","FatWalk_armed",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"FAT","FatWalk_Csaw",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"FAT","FatWalk_Rocket",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"FAT","IDLE_tired",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimFIGHTB(playerid,s);
public AnimFIGHTB(playerid,s){
if(s == 1){ApplyAnimation(playerid,"FIGHT_B","FightB_1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"FIGHT_B","FightB_2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"FIGHT_B","FightB_3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"FIGHT_B","FightB_block",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"FIGHT_B","FightB_G",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"FIGHT_B","FightB_IDLE",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"FIGHT_B","FightB_M",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"FIGHT_B","HitB_1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"FIGHT_B","HitB_2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"FIGHT_B","HitB_3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimFIGHTC(playerid,s);
public AnimFIGHTC(playerid,s){
if(s == 1){ApplyAnimation(playerid,"FIGHT_C","FightC_1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"FIGHT_C","FightC_2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"FIGHT_C","FightC_3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"FIGHT_C","FightC_block",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"FIGHT_C","FightC_blocking",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"FIGHT_C","FightC_G",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"FIGHT_C","FightC_IDLE",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"FIGHT_C","FightC_M",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"FIGHT_C","FightC_Spar",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"FIGHT_C","HitC_1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"FIGHT_C","HitC_2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"FIGHT_C","HitC_3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimFIGHTD(playerid,s);
public AnimFIGHTD(playerid,s){
if(s == 1){ApplyAnimation(playerid,"FIGHT_D","FightD_1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"FIGHT_D","FightD_2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"FIGHT_D","FightD_3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"FIGHT_D","FightD_block",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"FIGHT_D","FightD_G",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"FIGHT_D","FightD_IDLE",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"FIGHT_D","FightD_M",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"FIGHT_D","HitD_1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"FIGHT_D","HitD_2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"FIGHT_D","HitD_3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimFIGHTE(playerid,s);
public AnimFIGHTE(playerid,s){
if(s == 1){ApplyAnimation(playerid,"FIGHT_E","FightKick",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"FIGHT_E","FightKick_B",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"FIGHT_E","Hit_fightkick",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"FIGHT_E","Hit_fightkick_B",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimFinale(playerid,s);
public AnimFinale(playerid,s){
if(s == 1){ApplyAnimation(playerid,"FINALE","FIN_Climb_In",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"FINALE","FIN_Cop1_ClimbOut2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"FINALE","FIN_Cop1_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"FINALE","FIN_Cop1_Stomp",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"FINALE","FIN_Hang_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"FINALE","FIN_Hang_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"FINALE","FIN_Hang_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"FINALE","FIN_Hang_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"FINALE","FIN_Jump_On",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"FINALE","FIN_Land_Car",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"FINALE","FIN_Land_Die",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"FINALE","FIN_LegsUp",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"FINALE","FIN_LegsUp_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"FINALE","FIN_LegsUp_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"FINALE","FIN_LegsUp_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"FINALE","FIN_Let_Go",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimFinale2(playerid,s);
public AnimFinale2(playerid,s){
if(s == 1){ApplyAnimation(playerid,"FINALE2","FIN_Cop1_ClimbOut",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"FINALE2","FIN_Cop1_Fall",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"FINALE2","FIN_Cop1_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"FINALE2","FIN_Cop1_Shot",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"FINALE2","FIN_Cop1_Swing",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"FINALE2","FIN_Cop2_ClimbOut",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"FINALE2","FIN_Switch_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"FINALE2","FIN_Switch_S",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimFlowers(playerid,s);
public AnimFlowers(playerid,s){
if(s == 1){ApplyAnimation(playerid,"Flowers","Flower_attack",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"Flowers","Flower_attack_M",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"Flowers","Flower_Hit",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimHands(playerid,s);
public AnimHands(playerid,s){
if(s == 1){ApplyAnimation(playerid,"GHANDS","gsign1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"GHANDS","gsign1LH",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"GHANDS","gsign2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"GHANDS","gsign2LH",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"GHANDS","gsign3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"GHANDS","gsign3LH",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"GHANDS","gsign4",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"GHANDS","gsign4LH",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"GHANDS","gsign5",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"GHANDS","gsign5LH",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"GHANDS","LHGsign1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"GHANDS","LHGsign2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"GHANDS","LHGsign3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"GHANDS","LHGsign4",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"GHANDS","LHGsign5",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"GHANDS","RHGsign1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"GHANDS","RHGsign2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"GHANDS","RHGsign3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 19){ApplyAnimation(playerid,"GHANDS","RHGsign4",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 20){ApplyAnimation(playerid,"GHANDS","RHGsign5",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimFW(playerid,s);
public AnimFW(playerid,s){
if(s == 1){ApplyAnimation(playerid,"Freeweights","gym_barbell",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"Freeweights","gym_free_A",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"Freeweights","gym_free_B",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"Freeweights","gym_free_celebrate",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"Freeweights","gym_free_down",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"Freeweights","gym_free_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"Freeweights","gym_free_pickup",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"Freeweights","gym_free_putdown",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"Freeweights","gym_free_up_smooth",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimGhetto(playerid,s);
public AnimGhetto(playerid,s){
if(s == 1){ApplyAnimation(playerid,"GHETTO_DB","GDB_Car2_PLY",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"GHETTO_DB","GDB_Car2_SMO",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"GHETTO_DB","GDB_Car2_SWE",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"GHETTO_DB","GDB_Car_PLY",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"GHETTO_DB","GDB_Car_RYD",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"GHETTO_DB","GDB_Car_SMO",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"GHETTO_DB","GDB_Car_SWE",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimGraffity(playerid,s);
public AnimGraffity(playerid,s){
if(s == 1){ApplyAnimation(playerid,"GRAFFITI","graffiti_Chkout",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 1){ApplyAnimation(playerid,"GRAFFITI","spraycan_fire",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimGren(playerid,s);
public AnimGren(playerid,s){
if(s == 1){ApplyAnimation(playerid,"GRENADE","WEAPON_start_throw",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"GRENADE","WEAPON_throw",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"GRENADE","WEAPON_throwu",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimGreya(playerid,s);
public AnimGreya(playerid,s){
if(s == 1){ApplyAnimation(playerid,"GRAVEYARD","mrnF_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"GRAVEYARD","mrnM_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"GRAVEYARD","prst_loopa",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimHair(playerid,s);
public AnimHair(playerid,s)
{
if(s == 1){ApplyAnimation(playerid,"HAIRCUTS","BRB_Beard_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"HAIRCUTS","BRB_Buy",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"HAIRCUTS","BRB_Cut",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"HAIRCUTS","BRB_Cut_In",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"HAIRCUTS","BRB_Cut_Out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"HAIRCUTS","BRB_Hair_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"HAIRCUTS","BRB_Hair_02",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"HAIRCUTS","BRB_In",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"HAIRCUTS","BRB_Out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"HAIRCUTS","BRB_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"HAIRCUTS","BRB_Sit_In",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"HAIRCUTS","BRB_Sit_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"HAIRCUTS","BRB_Sit_Out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimHeist(playerid,s);
public AnimHeist(playerid,s){
if(s == 1){ApplyAnimation(playerid,"HEIST9","CAS_G2_GasKO",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"HEIST9","swt_wllpk_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"HEIST9","swt_wllpk_L_back",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"HEIST9","swt_wllpk_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"HEIST9","swt_wllpk_R_back",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"HEIST9","swt_wllshoot_in_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"HEIST9","swt_wllshoot_in_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"HEIST9","swt_wllshoot_out_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"HEIST9","swt_wllshoot_out_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"HEIST9","Use_SwipeCard",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimIntHouse(playerid,s);
public AnimIntHouse(playerid,s){
if(s == 1){ApplyAnimation(playerid,"INT_HOUSE","BED_In_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"INT_HOUSE","BED_In_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"INT_HOUSE","BED_Loop_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"INT_HOUSE","BED_Loop_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"INT_HOUSE","BED_Out_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"INT_HOUSE","BED_Out_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"INT_HOUSE","LOU_In",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"INT_HOUSE","LOU_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"INT_HOUSE","LOU_Out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"INT_HOUSE","wash_up",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimOffice(playerid,s);
public AnimOffice(playerid,s){
if(s == 1){ApplyAnimation(playerid,"INT_OFFICE","FF_Dam_Fwd",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"INT_OFFICE","OFF_Sit_2Idle_180",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"INT_OFFICE","OFF_Sit_Bored_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"INT_OFFICE","OFF_Sit_Crash",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"INT_OFFICE","OFF_Sit_Drink",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"INT_OFFICE","OFF_Sit_Idle_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"INT_OFFICE","OFF_Sit_In",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"INT_OFFICE","OFF_Sit_Read",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"INT_OFFICE","OFF_Sit_Type_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"INT_OFFICE","OFF_Sit_Watch",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimPDBF(playerid,s);
public AnimPDBF(playerid,s)
{
if(s == 1){ApplyAnimation(playerid,"PLAYER_DVBYS","Plyr_DrivebyBwd",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"PLAYER_DVBYS","Plyr_DrivebyFwd",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"PLAYER_DVBYS","Plyr_DrivebyLHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"PLAYER_DVBYS","Plyr_DrivebyRHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimPlayidles(playerid,s);
public AnimPlayidles(playerid,s){
if(s == 1){ApplyAnimation(playerid,"PLAYIDLES","shift",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"PLAYIDLES","shldr",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"PLAYIDLES","stretch",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"PLAYIDLES","strleg",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"PLAYIDLES","time",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimPolice(playerid,s);
public AnimPolice(playerid,s){
if(s == 1){ApplyAnimation(playerid,"POLICE","CopTraf_Away",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"POLICE","CopTraf_Come",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"POLICE","CopTraf_Left",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"POLICE","CopTraf_Stop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"POLICE","COP_getoutcar_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"POLICE","Cop_move_FWD",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"POLICE","crm_drgbst_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"POLICE","Door_Kick",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"POLICE","plc_drgbst_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"POLICE","plc_drgbst_02",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimPool(playerid,s);
public AnimPool(playerid,s){
if(s == 1){ApplyAnimation(playerid,"POOL","POOL_ChalkCue",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"POOL","POOL_Idle_Stance",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"POOL","POOL_Long_Shot",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"POOL","POOL_Long_Shot_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"POOL","POOL_Long_Start",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"POOL","POOL_Long_Start_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"POOL","POOL_Med_Shot",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"POOL","POOL_Med_Shot_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"POOL","POOL_Med_Start",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"POOL","POOL_Med_Start_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"POOL","POOL_Place_White",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"POOL","POOL_Short_Shot",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"POOL","POOL_Short_Shot_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"POOL","POOL_Short_Start",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"POOL","POOL_Short_Start_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"POOL","POOL_Walk",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"POOL","POOL_Walk_Start",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"POOL","POOL_XLong_Shot",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 19){ApplyAnimation(playerid,"POOL","POOL_XLong_Shot_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 20){ApplyAnimation(playerid,"POOL","POOL_XLong_Start",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 21){ApplyAnimation(playerid,"POOL","POOL_XLong_Start_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimPoor(playerid,s);
public AnimPoor(playerid,s){
if(s == 1){ApplyAnimation(playerid,"POOR","WINWASH_Start",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"POOR","WINWASH_Wash2Beg",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimPython(playerid,s);
public AnimPython(playerid,s){
if(s == 1){ApplyAnimation(playerid,"PYTHON","python_crouchfire",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"PYTHON","python_crouchreload",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"PYTHON","python_fire",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"PYTHON","python_fire_poor",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"PYTHON","python_reload",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimQUAD(playerid,s);
public AnimQUAD(playerid,s){
if(s == 1){ApplyAnimation(playerid,"QUAD","QUAD_back",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"QUAD","QUAD_driveby_FT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"QUAD","QUAD_driveby_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"QUAD","QUAD_driveby_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"QUAD","QUAD_FWD",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"QUAD","QUAD_getoff_B",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"QUAD","QUAD_getoff_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"QUAD","QUAD_getoff_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"QUAD","QUAD_geton_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"QUAD","QUAD_geton_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"QUAD","QUAD_hit",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"QUAD","QUAD_kick",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"QUAD","QUAD_Left",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"QUAD","QUAD_passenger",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"QUAD","QUAD_reverse",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"QUAD","QUAD_ride",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"QUAD","QUAD_Right",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimQDBZ(playerid,s);
public AnimQDBZ(playerid,s){
if(s == 1){ApplyAnimation(playerid,"QUAD_DBZ","Pass_Driveby_BWD",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"QUAD_DBZ","Pass_Driveby_FWD",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"QUAD_DBZ","Pass_Driveby_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"QUAD_DBZ","Pass_Driveby_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimRapping(playerid,s);
public AnimRapping(playerid,s){
if(s == 1){ApplyAnimation(playerid,"RAPPING","Laugh_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"RAPPING","RAP_A_IN",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"RAPPING","RAP_A_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"RAPPING","RAP_A_OUT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"RAPPING","RAP_B_IN",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"RAPPING","RAP_B_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"RAPPING","RAP_B_OUT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"RAPPING","RAP_C_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimRifle(playerid,s);
public AnimRifle(playerid,s){
if(s == 1){ApplyAnimation(playerid,"RIFLE","RIFLE_crouchfire",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"RIFLE","RIFLE_crouchload",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"RIFLE","RIFLE_fire",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"RIFLE","RIFLE_fire_poor",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"RIFLE","RIFLE_load",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimRiot(playerid,s);
public AnimRiot(playerid,s){
if(s == 1){ApplyAnimation(playerid,"RIOT","RIOT_ANGRY",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"RIOT","RIOT_ANGRY_B",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"RIOT","RIOT_challenge",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"RIOT","RIOT_CHANT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"RIOT","RIOT_FUKU",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"RIOT","RIOT_PUNCHES",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"RIOT","RIOT_shout",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimRobBank(playerid,s);
public AnimRobBank(playerid,s){
if(s == 1){ApplyAnimation(playerid,"ROB_BANK","CAT_Safe_End",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"ROB_BANK","CAT_Safe_Open",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"ROB_BANK","CAT_Safe_Open_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"ROB_BANK","CAT_Safe_Rob",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"ROB_BANK","SHP_HandsUp_Scr",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimRocket(playerid,s);
public AnimRocket(playerid,s){
if(s == 1){ApplyAnimation(playerid,"ROCKET","idle_rocket",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"ROCKET","RocketFire",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"ROCKET","run_rocket",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"ROCKET","walk_rocket",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"ROCKET","WALK_start_rocket",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimRustler(playerid,s);
public AnimRustler(playerid,s){
if(s == 1){ApplyAnimation(playerid,"RUSTLER","Plane_align_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"RUSTLER","Plane_close",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"RUSTLER","Plane_getin",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"RUSTLER","Plane_getout",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"RUSTLER","Plane_open",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimBiked(playerid,s);
public AnimBiked(playerid,s){
if(s == 1){ApplyAnimation(playerid,"BIKED","BIKEd_Back",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"BIKED","BIKEd_drivebyFT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"BIKED","BIKEd_drivebyLHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"BIKED","BIKEd_drivebyRHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"BIKED","BIKEd_Fwd",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"BIKED","BIKEd_getoffBACK",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"BIKED","BIKEd_getoffLHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"BIKED","BIKEd_getoffRHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"BIKED","BIKEd_hit",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"BIKED","BIKEd_jumponL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"BIKED","BIKEd_jumponR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"BIKED","BIKEd_kick",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"BIKED","BIKEd_Left",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"BIKED","BIKEd_passenger",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"BIKED","BIKEd_pushes",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"BIKED","BIKEd_Ride",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"BIKED","BIKEd_Right",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"BIKED","BIKEd_shuffle",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 19){ApplyAnimation(playerid,"BIKED","BIKEd_Still",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimRyder(playerid,s);
public AnimRyder(playerid,s){
if(s == 1){ApplyAnimation(playerid,"RYDER","RYD_Beckon_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"RYDER","RYD_Beckon_02",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"RYDER","RYD_Beckon_03",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"RYDER","RYD_Die_PT1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"RYDER","RYD_Die_PT2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"RYDER","Van_Crate_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"RYDER","Van_Crate_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"RYDER","Van_Fall_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"RYDER","Van_Fall_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"RYDER","Van_Lean_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"RYDER","Van_Lean_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"RYDER","VAN_PickUp_S",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"RYDER","Van_Stand",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"RYDER","Van_Stand_Crate",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"RYDER","Van_Throw",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimScrat(playerid,s);
public AnimScrat(playerid,s){
if(s == 1){ApplyAnimation(playerid,"SCRATCHING","scdldlp",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"SCRATCHING","scdlulp",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"SCRATCHING","scdrdlp",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"SCRATCHING","scdrulp",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"SCRATCHING","sclng_l",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"SCRATCHING","sclng_r",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"SCRATCHING","scmid_l",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"SCRATCHING","scmid_r",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"SCRATCHING","scshrtl",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"SCRATCHING","scshrtr",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"SCRATCHING","sc_ltor",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"SCRATCHING","sc_rtol",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimShamal(playerid,s);
public AnimShamal(playerid,s){
if(s == 1){ApplyAnimation(playerid,"SHAMAL","SHAMAL_align",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"SHAMAL","SHAMAL_getin_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"SHAMAL","SHAMAL_getout_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"SHAMAL","SHAMAL_open",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimShop(playerid,s);
public AnimShop(playerid,s){
if(s == 1){ApplyAnimation(playerid,"SHOP","ROB_2Idle",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"SHOP","ROB_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"SHOP","donutdrop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"SHOP","ROB_Loop_Threat",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"SHOP","ROB_Shifty",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"SHOP","ROB_StickUp_In",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"SHOP","SHP_Duck_Fire",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"SHOP","SHP_Gun_Aim",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"SHOP","SHP_Gun_Duck",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"SHOP","SHP_Gun_Fire",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"SHOP","SHP_Gun_Grab",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"SHOP","SHP_Gun_Threat",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"SHOP","SHP_HandsUp_Scr",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"SHOP","SHP_Jump_Glide",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"SHOP","SHP_Jump_Land",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"SHOP","SHP_Jump_Launch",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"SHOP","SHP_Rob_GiveCash",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"SHOP","SHP_Rob_HandsUp",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 19){ApplyAnimation(playerid,"SHOP","SHP_Rob_React",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 20){ApplyAnimation(playerid,"SHOP","SHP_Serve_End",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 21){ApplyAnimation(playerid,"SHOP","SHP_Serve_Idle",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 22){ApplyAnimation(playerid,"SHOP","SHP_Serve_Loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 23){ApplyAnimation(playerid,"SHOP","SHP_Serve_Start",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 24){ApplyAnimation(playerid,"SHOP","Smoke_RYD",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimShotgun(playerid,s);
public AnimShotgun(playerid,s){
if(s == 1){ApplyAnimation(playerid,"SHOTGUN","shotgun_crouchfire",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"SHOTGUN","shotgun_fire",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"SHOTGUN","shotgun_fire_poor",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimSkate(playerid,s);
public AnimSkate(playerid,s){
if(s == 1){ApplyAnimation(playerid,"SKATE","skate_idle",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"SKATE","skate_run",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"SKATE","skate_sprint",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimVortex(playerid,s);
public AnimVortex(playerid,s){
if(s == 1){ApplyAnimation(playerid,"VORTEX","CAR_jumpin_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"VORTEX","CAR_jumpin_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"VORTEX","vortex_getout_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"VORTEX","vortex_getout_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimTEC9(playerid,s);
public AnimTEC9(playerid,s){
if(s == 1){ApplyAnimation(playerid,"TEC","TEC_crouchfire",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"TEC","TEC_crouchreload",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"TEC","TEC_fire",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"TEC","TEC_reload",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimSilence(playerid,s);
public AnimSilence(playerid,s){
if(s == 1){ApplyAnimation(playerid,"SILENCED","CrouchReload",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"SILENCED","SilenceCrouchfire",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"SILENCED","Silence_fire",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"SILENCED","Silence_reload",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimTrain(playerid,s);
public AnimTrain(playerid,s){
if(s == 1){ApplyAnimation(playerid,"TRAIN","tran_gtup",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"TRAIN","tran_hng",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"TRAIN","tran_ouch",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"TRAIN","tran_stmb",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimTattoo(playerid,s);
public AnimTattoo(playerid,s){
if(s == 1){ApplyAnimation(playerid,"TATTOOS","TAT_ArmL_In_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"TATTOOS","TAT_ArmL_In_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"TATTOOS","TAT_ArmL_In_T",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"TATTOOS","TAT_ArmL_Out_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"TATTOOS","TA_ArmL_Out_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"TATTOOS","TAT_ArmL_Out_T",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"TATTOOS","TAT_ArmL_Pose_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"TATTOOS","TAT_ArmL_Pose_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"TATTOOS","TAT_ArmL_Pose_T",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"TATTOOS","TAT_ArmR_In_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"TATTOOS","TAT_ArmR_In_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"TATTOOS","TAT_ArmR_In_T",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"TATTOOS","TAT_ArmR_Out_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"TATTOOS","TAT_ArmR_Out_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"TATTOOS","TAT_ArmR_Out_T",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"TATTOOS","TAT_ArmR_Pose_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"TATTOOS","TAT_ArmR_Pose_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"TATTOOS","TAT_ArmR_Pose_T",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 19){ApplyAnimation(playerid,"TATTOOS","TAT_Back_In_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 20){ApplyAnimation(playerid,"TATTOOS","TAT_Back_In_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 21){ApplyAnimation(playerid,"TATTOOS","TAT_Back_In_T",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 22){ApplyAnimation(playerid,"TATTOOS","TAT_Back_Out_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 23){ApplyAnimation(playerid,"TATTOOS","TAT_Back_Out_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 24){ApplyAnimation(playerid,"TATTOOS","TAT_Back_Out_T",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 25){ApplyAnimation(playerid,"TATTOOS","TAT_Back_Pose_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 26){ApplyAnimation(playerid,"TATTOOS","TAT_Back_Pose_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 27){ApplyAnimation(playerid,"TATTOOS","TAT_Back_Pose_T",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 28){ApplyAnimation(playerid,"TATTOOS","TAT_Back_Sit_In_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 29){ApplyAnimation(playerid,"TATTOOS","TAT_Back_Sit_Loop_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 30){ApplyAnimation(playerid,"TATTOOS","TAT_Back_Sit_Out_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 31){ApplyAnimation(playerid,"TATTOOS","TAT_Bel_In_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 32){ApplyAnimation(playerid,"TATTOOS","TAT_Bel_In_T",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 33){ApplyAnimation(playerid,"TATTOOS","TAT_Bel_Out_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 34){ApplyAnimation(playerid,"TATTOOS","TAT_Bel_Out_T",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 35){ApplyAnimation(playerid,"TATTOOS","TAT_Bel_Pose_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 36){ApplyAnimation(playerid,"TATTOOS","TAT_Bel_Pose_T",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 37){ApplyAnimation(playerid,"TATTOOS","TAT_Che_In_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 38){ApplyAnimation(playerid,"TATTOOS","Sit_relaxed",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 39){ApplyAnimation(playerid,"TATTOOS","TAT_Che_In_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 40){ApplyAnimation(playerid,"TATTOOS","TAT_Che_In_T",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 41){ApplyAnimation(playerid,"TATTOOS","TAT_Che_Out_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 42){ApplyAnimation(playerid,"TATTOOS","TAT_Che_Out_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 43){ApplyAnimation(playerid,"TATTOOS","TAT_Che_Out_T",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 44){ApplyAnimation(playerid,"TATTOOS","TAT_Che_Pose_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 45){ApplyAnimation(playerid,"TATTOOS","TAT_Che_Pose_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 46){ApplyAnimation(playerid,"TATTOOS","TAT_Che_Pose_T",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 47){ApplyAnimation(playerid,"TATTOOS","TAT_Idle_Loop_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 48){ApplyAnimation(playerid,"TATTOOS","TAT_Idle_Loop_T",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 49){ApplyAnimation(playerid,"TATTOOS","TAT_Sit_In_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 50){ApplyAnimation(playerid,"TATTOOS","TAT_Sit_In_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 51){ApplyAnimation(playerid,"TATTOOS","TAT_Sit_In_T",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 52){ApplyAnimation(playerid,"TATTOOS","TAT_Sit_Loop_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 53){ApplyAnimation(playerid,"TATTOOS","TAT_Sit_Loop_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 54){ApplyAnimation(playerid,"TATTOOS","TAT_Sit_Loop_T",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 55){ApplyAnimation(playerid,"TATTOOS","TAT_Sit_Out_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 56){ApplyAnimation(playerid,"TATTOOS","TAT_Sit_Out_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 57){ApplyAnimation(playerid,"TATTOOS","TAT_Sit_Out_T",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimSmoking(playerid,s);
public AnimSmoking(playerid,s){
if(s == 1){ApplyAnimation(playerid,"SMOKING","F_smklean_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"SMOKING","M_smklean_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"SMOKING","M_smkstnd_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"SMOKING","M_smk_drag",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"SMOKING","M_smk_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"SMOKING","M_smk_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"SMOKING","M_smk_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"SMOKING","M_smk_tap",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimSpray(playerid,s);
public AnimSpray(playerid,s){
if(s == 1){ApplyAnimation(playerid,"SPRAYCAN","spraycan_fire",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"SPRAYCAN","spraycan_full",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}

forward AnimStrip(playerid,s);
public AnimStrip(playerid,s){
if(s == 1){ApplyAnimation(playerid,"STRIP","PLY_CASH",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"STRIP","PUN_CASH",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"STRIP","PUN_HOLLER",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"STRIP","PUN_LOOP",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"STRIP","strip_A",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"STRIP","strip_B",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"STRIP","strip_C",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"STRIP","strip_D",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"STRIP","strip_E",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"STRIP","strip_F",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"STRIP","strip_G",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"STRIP","STR_A2B",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"STRIP","STR_B2A",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"STRIP","STR_B2C",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"STRIP","STR_C1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"STRIP","STR_C2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"STRIP","STR_C2B",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 19){ApplyAnimation(playerid,"STRIP","STR_Loop_A",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 20){ApplyAnimation(playerid,"STRIP","STR_Loop_B",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 21){ApplyAnimation(playerid,"STRIP","STR_Loop_C",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimBath(playerid,s);
public AnimBath(playerid,s){
if(s == 1){ApplyAnimation(playerid,"SUNBATHE","batherdown",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"SUNBATHE","batherup",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"SUNBATHE","Lay_Bac_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"SUNBATHE","Lay_Bac_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"SUNBATHE","ParkSit_M_IdleA",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"SUNBATHE","ParkSit_M_IdleB",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"SUNBATHE","ParkSit_M_IdleC",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"SUNBATHE","ParkSit_M_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"SUNBATHE","ParkSit_M_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"SUNBATHE","ParkSit_W_idleA",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"SUNBATHE","ParkSit_W_idleB",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"SUNBATHE","ParkSit_W_idleC",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"SUNBATHE","ParkSit_W_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"SUNBATHE","ParkSit_W_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"SUNBATHE","SBATHE_F_LieB2Sit",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"SUNBATHE","SBATHE_F_Out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"SUNBATHE","SitnWait_in_W",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"SUNBATHE","SitnWait_out_W",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimSwat(playerid,s);
public AnimSwat(playerid,s){
if(s == 1){ApplyAnimation(playerid,"SWAT","gnstwall_injurd",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"SWAT","JMP_Wall1m_180",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"SWAT","Rail_fall",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"SWAT","Rail_fall_crawl",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"SWAT","swt_breach_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"SWAT","cards_pick_02",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"SWAT","swt_breach_02",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"SWAT","swt_breach_03",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"SWAT","swt_go",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"SWAT","swt_lkt",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"SWAT","swt_sty",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"SWAT","swt_vent_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"SWAT","swt_vent_02",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"SWAT","swt_vnt_sht_die",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"SWAT","swt_vnt_sht_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"SWAT","swt_vnt_sht_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"SWAT","swt_wllpk_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"SWAT","swt_wllpk_L_back",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 19){ApplyAnimation(playerid,"SWAT","swt_wllpk_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 20){ApplyAnimation(playerid,"SWAT","swt_wllpk_R_back",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 21){ApplyAnimation(playerid,"SWAT","swt_wllshoot_in_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 22){ApplyAnimation(playerid,"SWAT","swt_wllshoot_in_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 23){ApplyAnimation(playerid,"SWAT","swt_wllshoot_out_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 24){ApplyAnimation(playerid,"SWAT","swt_wllshoot_out_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimSweet(playerid,s);
public AnimSweet(playerid,s){
if(s == 1){ApplyAnimation(playerid,"SWEET","ho_ass_slapped",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"SWEET","LaFin_Player",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"SWEET","LaFin_Sweet",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"SWEET","plyr_hndshldr_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"SWEET","sweet_ass_slap",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"SWEET","sweet_hndshldr_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"SWEET","Sweet_injuredloop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimSwim(playerid,s);
public AnimSwim(playerid,s){
if(s == 1){ApplyAnimation(playerid,"SWIM","Swim_Breast",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"SWIM","SWIM_crawl",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"SWIM","Swim_Dive_Under",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"SWIM","Swim_Glide",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"SWIM","Swim_jumpout",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"SWIM","Swim_Tread",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"SWIM","Swim_Under",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimSword(playerid,s);
public AnimSword(playerid,s){
if(s == 1){ApplyAnimation(playerid,"SWORD","sword_1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"SWORD","sword_2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"SWORD","sword_3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"SWORD","sword_4",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"SWORD","sword_block",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"SWORD","Sword_Hit_1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"SWORD","Sword_Hit_2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"SWORD","Sword_Hit_3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"SWORD","sword_IDLE",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"SWORD","sword_part",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimTank(playerid,s);
public AnimTank(playerid,s){
if(s == 1){ApplyAnimation(playerid,"TANK","TANK_align_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"TANK","TANK_close_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"TANK","TANK_doorlocked",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"TANK","TANK_getin_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"TANK","TANK_getout_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"TANK","TANK_open_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimTruck(playerid,s);
public AnimTruck(playerid,s){
if(s == 1){ApplyAnimation(playerid,"TRUCK","TRUCK_ALIGN_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"TRUCK","TRUCK_ALIGN_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"TRUCK","TRUCK_closedoor_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"TRUCK","TRUCK_closedoor_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"TRUCK","TRUCK_close_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"TRUCK","TRUCK_close_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"TRUCK","TRUCK_getin_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"TRUCK","TRUCK_getin_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"TRUCK","TRUCK_getout_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"TRUCK","TRUCK_getout_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"TRUCK","TRUCK_jackedLHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"TRUCK","TRUCK_jackedRHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"TRUCK","TRUCK_open_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"TRUCK","TRUCK_open_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"TRUCK","TRUCK_pullout_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"TRUCK","TRUCK_pullout_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"TRUCK","TRUCK_Shuffle",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimUZI(playerid,s);
public AnimUZI(playerid,s){
if(s == 1){ApplyAnimation(playerid,"UZI","UZI_crouchfire",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"UZI","UZI_crouchreload",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"UZI","UZI_fire",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"UZI","UZI_fire_poor",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"UZI","UZI_reload",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimVan(playerid,s);
public AnimVan(playerid,s){
if(s == 1){ApplyAnimation(playerid,"VAN","VAN_close_back_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"VAN","VAN_close_back_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"VAN","VAN_getin_Back_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"VAN","VAN_getin_Back_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"VAN","VAN_getout_back_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"VAN","VAN_getout_back_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"VAN","VAN_open_back_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"VAN","VAN_open_back_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimVending(playerid,s);
public AnimVending(playerid,s){
if(s == 1){ApplyAnimation(playerid,"VENDING","VEND_Drink2_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"VENDING","VEND_Drink_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"VENDING","vend_eat1_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"VENDING","VEND_Eat_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"VENDING","VEND_Use",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"VENDING","VEND_Use_pt2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimWay(playerid,s);
public AnimWay(playerid,s){
if(s == 1){ApplyAnimation(playerid,"WAYFARER","WF_Back",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"WAYFARER","WF_drivebyFT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"WAYFARER","WF_drivebyLHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"WAYFARER","WF_drivebyRHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"WAYFARER","WF_Fwd",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"WAYFARER","WF_getoffBACK",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"WAYFARER","WF_getoffLHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"WAYFARER","WF_getoffRHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"WAYFARER","WF_hit",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"WAYFARER","WF_jumponL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"WAYFARER","WF_jumponR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"WAYFARER","WF_kick",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"WAYFARER","WF_Left",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"WAYFARER","WF_passenger",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"WAYFARER","WF_pushes",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"WAYFARER","WF_Ride",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"WAYFARER","WF_Right",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"WAYFARER","WF_Still",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimWeap(playerid,s);
public AnimWeap(playerid,s){
if(s == 1){ApplyAnimation(playerid,"WEAPONS","SHP_1H_Lift",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"WEAPONS","SHP_1H_Lift_End",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"WEAPONS","SHP_1H_Ret",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"WEAPONS","SHP_1H_Ret_S",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"WEAPONS","SHP_2H_Lift",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"WEAPONS","SHP_2H_Lift_End",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"WEAPONS","SHP_2H_Ret",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"WEAPONS","SHP_2H_Ret_S",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"WEAPONS","SHP_Ar_Lift",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"WEAPONS","SHP_Ar_Lift_End",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"WEAPONS","SHP_Ar_Ret",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"WEAPONS","SHP_Ar_Ret_S",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"WEAPONS","SHP_G_Lift_In",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"WEAPONS","SHP_G_Lift_Out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"WEAPONS","SHP_Tray_In",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"WEAPONS","SHP_Tray_Out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"WEAPONS","SHP_Tray_Pose",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimWuzi(playerid,s);
public AnimWuzi(playerid,s){
if(s == 1){ApplyAnimation(playerid,"WUZI","CS_Dead_Guy",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"WUZI","CS_Plyr_pt1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"WUZI","CS_Plyr_pt2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"WUZI","CS_Wuzi_pt1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"WUZI","CS_Wuzi_pt2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"WUZI","Walkstart_Idle_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"WUZI","Wuzi_follow",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"WUZI","Wuzi_Greet_Plyr",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"WUZI","Wuzi_Greet_Wuzi",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"WUZI","Wuzi_grnd_chk",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"WUZI","Wuzi_stand_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"WUZI","Wuzi_Walk",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimMat(playerid,s);
public AnimMat(playerid,s){
if(s == 1){ApplyAnimation(playerid,"Attractors","Stepsit_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"Attractors","Stepsit_loop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"Attractors","Stepsit_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimPed(playerid,s);
public AnimPed(playerid,s){
if(s == 1){ApplyAnimation(playerid,"PED","IDLE_CHAT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"PED","WALK_DRUNK",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"PED","abseil",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"PED","ARRESTgun",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"PED","ATM",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"PED","BIKE_elbowL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"PED","BIKE_fallR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"PED","BIKE_fall_off",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"PED","BIKE_pickupL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"PED","BIKE_pickupR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"PED","BIKE_pullupL",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"PED","BIKE_pullupR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 13){ApplyAnimation(playerid,"PED","bomber",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 14){ApplyAnimation(playerid,"PED","CAR_alignHI_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 15){ApplyAnimation(playerid,"PED","CAR_alignHI_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 16){ApplyAnimation(playerid,"PED","CAR_align_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 17){ApplyAnimation(playerid,"PED","CAR_align_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 18){ApplyAnimation(playerid,"PED","CAR_closedoorL_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 19){ApplyAnimation(playerid,"PED","CAR_closedoorL_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 20){ApplyAnimation(playerid,"PED","CAR_closedoor_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 21){ApplyAnimation(playerid,"PED","CAR_closedoor_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 22){ApplyAnimation(playerid,"PED","CAR_close_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 23){ApplyAnimation(playerid,"PED","CAR_crawloutRHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 24){ApplyAnimation(playerid,"PED","CAR_dead_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 25){ApplyAnimation(playerid,"PED","CAR_dead_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 26){ApplyAnimation(playerid,"PED","CAR_doorlocked_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 27){ApplyAnimation(playerid,"PED","CAR_fallout_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 28){ApplyAnimation(playerid,"PED","CAR_fallout_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 29){ApplyAnimation(playerid,"PED","CAR_getinL_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 30){ApplyAnimation(playerid,"PED","CAR_getinL_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 31){ApplyAnimation(playerid,"PED","CAR_getin_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 32){ApplyAnimation(playerid,"PED","CAR_getin_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 33){ApplyAnimation(playerid,"PED","CAR_getoutL_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 34){ApplyAnimation(playerid,"PED","CAR_getout_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 35){ApplyAnimation(playerid,"PED","CAR_getout_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 36){ApplyAnimation(playerid,"PED","car_hookertalk",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 37){ApplyAnimation(playerid,"PED","CAR_jackedLHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 38){ApplyAnimation(playerid,"PED","CAR_jackedRHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 39){ApplyAnimation(playerid,"PED","CAR_jumpin_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 40){ApplyAnimation(playerid,"PED","CAR_LB",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 41){ApplyAnimation(playerid,"PED","CAR_LB_pro",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 42){ApplyAnimation(playerid,"PED","CAR_LB_weak",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 43){ApplyAnimation(playerid,"PED","CAR_LjackedLHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 44){ApplyAnimation(playerid,"PED","CAR_Lshuffle_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 45){ApplyAnimation(playerid,"PED","CAR_Lsit",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 46){ApplyAnimation(playerid,"PED","CAR_open_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 47){ApplyAnimation(playerid,"PED","CAR_open_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 48){ApplyAnimation(playerid,"PED","CAR_pulloutL_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 49){ApplyAnimation(playerid,"PED","CAR_pulloutL_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 50){ApplyAnimation(playerid,"PED","CAR_pullout_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 51){ApplyAnimation(playerid,"PED","CAR_pullout_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 52){ApplyAnimation(playerid,"PED","CAR_Qjacked",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 53){ApplyAnimation(playerid,"PED","CAR_rolldoor",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 54){ApplyAnimation(playerid,"PED","CAR_rolldoorLO",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 55){ApplyAnimation(playerid,"PED","CAR_rollout_LHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 56){ApplyAnimation(playerid,"PED","CAR_rollout_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 57){ApplyAnimation(playerid,"PED","CAR_shuffle_RHS",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 58){ApplyAnimation(playerid,"PED","CAR_sit",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 59){ApplyAnimation(playerid,"PED","CAR_sitp",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 60){ApplyAnimation(playerid,"PED","CAR_sitpLO",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 61){ApplyAnimation(playerid,"PED","CAR_sit_pro",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 62){ApplyAnimation(playerid,"PED","CAR_sit_weak",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 63){ApplyAnimation(playerid,"PED","CAR_tune_radio",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 64){ApplyAnimation(playerid,"PED","CLIMB_idle",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 65){ApplyAnimation(playerid,"PED","CLIMB_jump",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 66){ApplyAnimation(playerid,"PED","CLIMB_jump2fall",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 67){ApplyAnimation(playerid,"PED","CLIMB_jump_B",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 68){ApplyAnimation(playerid,"PED","CLIMB_Pull",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 69){ApplyAnimation(playerid,"PED","CLIMB_Stand",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 70){ApplyAnimation(playerid,"PED","CLIMB_Stand_finish",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 71){ApplyAnimation(playerid,"PED","cower",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 72){ApplyAnimation(playerid,"PED","Crouch_Roll_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 73){ApplyAnimation(playerid,"PED","Crouch_Roll_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 74){ApplyAnimation(playerid,"PED","DAM_armL_frmBK",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 75){ApplyAnimation(playerid,"PED","DAM_armL_frmFT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 76){ApplyAnimation(playerid,"PED","DAM_armL_frmLT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 77){ApplyAnimation(playerid,"PED","DAM_armR_frmBK",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 78){ApplyAnimation(playerid,"PED","DAM_armR_frmFT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 79){ApplyAnimation(playerid,"PED","DAM_armR_frmRT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 80){ApplyAnimation(playerid,"PED","DAM_LegL_frmBK",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 81){ApplyAnimation(playerid,"PED","DAM_LegL_frmFT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 82){ApplyAnimation(playerid,"PED","DAM_LegL_frmLT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 83){ApplyAnimation(playerid,"PED","DAM_LegR_frmBK",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 84){ApplyAnimation(playerid,"PED","DAM_LegR_frmFT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 85){ApplyAnimation(playerid,"PED","DAM_LegR_frmRT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 86){ApplyAnimation(playerid,"PED","DAM_stomach_frmBK",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 87){ApplyAnimation(playerid,"PED","DAM_stomach_frmFT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 88){ApplyAnimation(playerid,"PED","DAM_stomach_frmLT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 89){ApplyAnimation(playerid,"PED","DAM_stomach_frmRT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 90){ApplyAnimation(playerid,"PED","DOOR_LHinge_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 91){ApplyAnimation(playerid,"PED","DOOR_RHinge_O",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 92){ApplyAnimation(playerid,"PED","DrivebyL_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 93){ApplyAnimation(playerid,"PED","DrivebyL_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 94){ApplyAnimation(playerid,"PED","Driveby_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 95){ApplyAnimation(playerid,"PED","Driveby_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 96){ApplyAnimation(playerid,"PED","DRIVE_BOAT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 97){ApplyAnimation(playerid,"PED","DRIVE_BOAT_back",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 98){ApplyAnimation(playerid,"PED","DRIVE_BOAT_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 99){ApplyAnimation(playerid,"PED","DRIVE_BOAT_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 100){ApplyAnimation(playerid,"PED","Drive_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 101){ApplyAnimation(playerid,"PED","Drive_LO_l",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 102){ApplyAnimation(playerid,"PED","Drive_LO_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 103){ApplyAnimation(playerid,"PED","Drive_L_pro",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 104){ApplyAnimation(playerid,"PED","Drive_L_pro_slow",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 105){ApplyAnimation(playerid,"PED","Drive_L_slow",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 106){ApplyAnimation(playerid,"PED","Drive_L_weak",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 107){ApplyAnimation(playerid,"PED","Drive_L_weak_slow",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 108){ApplyAnimation(playerid,"PED","Drive_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 109){ApplyAnimation(playerid,"PED","Drive_R_pro",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 110){ApplyAnimation(playerid,"PED","Drive_R_pro_slow",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 111){ApplyAnimation(playerid,"PED","Drive_R_slow",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 112){ApplyAnimation(playerid,"PED","Drive_R_weak",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 113){ApplyAnimation(playerid,"PED","Drive_R_weak_slow",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 114){ApplyAnimation(playerid,"PED","Drive_truck",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 115){ApplyAnimation(playerid,"PED","DRIVE_truck_back",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 116){ApplyAnimation(playerid,"PED","DRIVE_truck_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 117){ApplyAnimation(playerid,"PED","DRIVE_truck_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 118){ApplyAnimation(playerid,"PED","Drown",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 119){ApplyAnimation(playerid,"PED","DUCK_cower",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 120){ApplyAnimation(playerid,"PED","endchat_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 121){ApplyAnimation(playerid,"PED","endchat_02",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 122){ApplyAnimation(playerid,"PED","endchat_03",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 123){ApplyAnimation(playerid,"PED","DRIVE_truck_back",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 124){ApplyAnimation(playerid,"PED","DRIVE_truck_back",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 125){ApplyAnimation(playerid,"PED","EV_dive",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 126){ApplyAnimation(playerid,"PED","EV_step",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 127){ApplyAnimation(playerid,"PED","facanger",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 128){ApplyAnimation(playerid,"PED","facanger",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 129){ApplyAnimation(playerid,"PED","facgum",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 130){ApplyAnimation(playerid,"PED","facsurp",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 131){ApplyAnimation(playerid,"PED","facsurpm",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 132){ApplyAnimation(playerid,"PED","factalk",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 133){ApplyAnimation(playerid,"PED","facurios",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 134){ApplyAnimation(playerid,"PED","FALL_back",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 135){ApplyAnimation(playerid,"PED","FALL_collapse",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 136){ApplyAnimation(playerid,"PED","FALL_fall",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 137){ApplyAnimation(playerid,"PED","FALL_front",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 138){ApplyAnimation(playerid,"PED","FALL_glide",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 139){ApplyAnimation(playerid,"PED","FALL_land",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 140){ApplyAnimation(playerid,"PED","FALL_skyDive",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 141){ApplyAnimation(playerid,"PED","Fight2Idle",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 142){ApplyAnimation(playerid,"PED","FightA_1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 143){ApplyAnimation(playerid,"PED","FightA_2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 144){ApplyAnimation(playerid,"PED","FightA_3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 145){ApplyAnimation(playerid,"PED","FightA_block",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 146){ApplyAnimation(playerid,"PED","FightA_G",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 147){ApplyAnimation(playerid,"PED","FightA_M",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 148){ApplyAnimation(playerid,"PED","FIGHTIDLE",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 149){ApplyAnimation(playerid,"PED","FightShB",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 150){ApplyAnimation(playerid,"PED","FightShF",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 151){ApplyAnimation(playerid,"PED","FightSh_BWD",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 152){ApplyAnimation(playerid,"PED","FightSh_FWD",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 153){ApplyAnimation(playerid,"PED","FightSh_Left",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 154){ApplyAnimation(playerid,"PED","FightSh_Right",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 155){ApplyAnimation(playerid,"PED","flee_lkaround_01",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 156){ApplyAnimation(playerid,"PED","FLOOR_hit",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 157){ApplyAnimation(playerid,"PED","FLOOR_hit_f",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 158){ApplyAnimation(playerid,"PED","fucku",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 159){ApplyAnimation(playerid,"PED","gang_gunstand",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 160){ApplyAnimation(playerid,"PED","gas_cwr",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 161){ApplyAnimation(playerid,"PED","getup",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 162){ApplyAnimation(playerid,"PED","getup_front",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 163){ApplyAnimation(playerid,"PED","gum_eat",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 164){ApplyAnimation(playerid,"PED","GunCrouchBwd",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 165){ApplyAnimation(playerid,"PED","GunCrouchFwd",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 166){ApplyAnimation(playerid,"PED","GunMove_BWD",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 167){ApplyAnimation(playerid,"PED","GunMove_FWD",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 168){ApplyAnimation(playerid,"PED","GunMove_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 169){ApplyAnimation(playerid,"PED","GunMove_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 170){ApplyAnimation(playerid,"PED","Gun_2_IDLE",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 171){ApplyAnimation(playerid,"PED","GUN_BUTT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 172){ApplyAnimation(playerid,"PED","GUN_BUTT_crouch",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 173){ApplyAnimation(playerid,"PED","Gun_stand",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 174){ApplyAnimation(playerid,"PED","handscower",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 175){ApplyAnimation(playerid,"PED","handsup",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 176){ApplyAnimation(playerid,"PED","HitA_1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 177){ApplyAnimation(playerid,"PED","HitA_2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 178){ApplyAnimation(playerid,"PED","HitA_3",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 179){ApplyAnimation(playerid,"PED","HIT_back",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 180){ApplyAnimation(playerid,"PED","HIT_behind",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 181){ApplyAnimation(playerid,"PED","HIT_front",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 182){ApplyAnimation(playerid,"PED","HIT_GUN_BUTT",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 183){ApplyAnimation(playerid,"PED","HIT_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 184){ApplyAnimation(playerid,"PED","HIT_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 185){ApplyAnimation(playerid,"PED","HIT_walk",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 186){ApplyAnimation(playerid,"PED","HIT_wall",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 187){ApplyAnimation(playerid,"PED","Idlestance_fat",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 188){ApplyAnimation(playerid,"PED","idlestance_old",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 189){ApplyAnimation(playerid,"PED","IDLE_armed",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 190){ApplyAnimation(playerid,"PED","IDLE_chat",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 191){ApplyAnimation(playerid,"PED","IDLE_csaw",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 192){ApplyAnimation(playerid,"PED","Idle_Gang1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 193){ApplyAnimation(playerid,"PED","IDLE_HBHB",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 194){ApplyAnimation(playerid,"PED","IDLE_ROCKET",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 195){ApplyAnimation(playerid,"PED","IDLE_stance",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 196){ApplyAnimation(playerid,"PED","IDLE_taxi",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 197){ApplyAnimation(playerid,"PED","IDLE_tired",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 198){ApplyAnimation(playerid,"PED","Jetpack_Idle",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 199){ApplyAnimation(playerid,"PED","JOG_femaleA",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 200){ApplyAnimation(playerid,"PED","JOG_maleA",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 201){ApplyAnimation(playerid,"PED","JUMP_glide",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 202){ApplyAnimation(playerid,"PED","JUMP_land",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 203){ApplyAnimation(playerid,"PED","JUMP_launch",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 204){ApplyAnimation(playerid,"PED","JUMP_launch_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 205){ApplyAnimation(playerid,"PED","KART_drive",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 206){ApplyAnimation(playerid,"PED","KART_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 207){ApplyAnimation(playerid,"PED","KART_LB",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 208){ApplyAnimation(playerid,"PED","KART_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 209){ApplyAnimation(playerid,"PED","KD_left",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 210){ApplyAnimation(playerid,"PED","KD_right",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 211){ApplyAnimation(playerid,"PED","KO_shot_face",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 212){ApplyAnimation(playerid,"PED","KO_shot_front",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 213){ApplyAnimation(playerid,"PED","KO_shot_stom",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 214){ApplyAnimation(playerid,"PED","KO_skid_back",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 215){ApplyAnimation(playerid,"PED","KO_skid_front",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 216){ApplyAnimation(playerid,"PED","KO_spin_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 217){ApplyAnimation(playerid,"PED","KO_spin_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 218){ApplyAnimation(playerid,"PED","pass_Smoke_in_car",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 219){ApplyAnimation(playerid,"PED","phone_in",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 220){ApplyAnimation(playerid,"PED","phone_out",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 221){ApplyAnimation(playerid,"PED","phone_talk",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 222){ApplyAnimation(playerid,"PED","Player_Sneak",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 223){ApplyAnimation(playerid,"PED","Player_Sneak_walkstart",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 224){ApplyAnimation(playerid,"PED","roadcross",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 225){ApplyAnimation(playerid,"PED","roadcross_female",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 226){ApplyAnimation(playerid,"PED","roadcross_gang",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 227){ApplyAnimation(playerid,"PED","roadcross_old",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 228){ApplyAnimation(playerid,"PED","run_1armed",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 229){ApplyAnimation(playerid,"PED","run_armed",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 230){ApplyAnimation(playerid,"PED","run_civi",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 231){ApplyAnimation(playerid,"PED","run_csaw",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 232){ApplyAnimation(playerid,"PED","run_fat",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 233){ApplyAnimation(playerid,"PED","run_fatold",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 234){ApplyAnimation(playerid,"PED","run_gang1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 235){ApplyAnimation(playerid,"PED","run_left",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 236){ApplyAnimation(playerid,"PED","run_old",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 237){ApplyAnimation(playerid,"PED","run_player",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 238){ApplyAnimation(playerid,"PED","run_right",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 239){ApplyAnimation(playerid,"PED","run_rocket",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 240){ApplyAnimation(playerid,"PED","Run_stop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 241){ApplyAnimation(playerid,"PED","Run_stopR",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 242){ApplyAnimation(playerid,"PED","Run_Wuzi",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 243){ApplyAnimation(playerid,"PED","SEAT_down",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 244){ApplyAnimation(playerid,"PED","SEAT_idle",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 245){ApplyAnimation(playerid,"PED","SEAT_up",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 246){ApplyAnimation(playerid,"PED","SHOT_leftP",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 247){ApplyAnimation(playerid,"PED","SHOT_partial",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 248){ApplyAnimation(playerid,"PED","SHOT_partial_B",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 249){ApplyAnimation(playerid,"PED","SHOT_rightP",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 250){ApplyAnimation(playerid,"PED","Shove_Partial",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 251){ApplyAnimation(playerid,"PED","Smoke_in_car",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 252){ApplyAnimation(playerid,"PED","sprint_civi",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 253){ApplyAnimation(playerid,"PED","sprint_panic",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 254){ApplyAnimation(playerid,"PED","Sprint_Wuzi",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 255){ApplyAnimation(playerid,"PED","swat_run",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 256){ApplyAnimation(playerid,"PED","Swim_Tread",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 257){ApplyAnimation(playerid,"PED","Tap_hand",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 258){ApplyAnimation(playerid,"PED","Tap_handP",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 259){ApplyAnimation(playerid,"PED","turn_180",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 260){ApplyAnimation(playerid,"PED","Turn_L",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 261){ApplyAnimation(playerid,"PED","Turn_R",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 262){ApplyAnimation(playerid,"PED","WALK_armed",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 263){ApplyAnimation(playerid,"PED","WALK_civi",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 264){ApplyAnimation(playerid,"PED","WALK_csaw",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 265){ApplyAnimation(playerid,"PED","Walk_DoorPartial",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 266){ApplyAnimation(playerid,"PED","WALK_drunk",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 267){ApplyAnimation(playerid,"PED","WALK_fat",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 268){ApplyAnimation(playerid,"PED","WALK_fatold",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 269){ApplyAnimation(playerid,"PED","WALK_gang1",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 270){ApplyAnimation(playerid,"PED","WALK_gang2",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 271){ApplyAnimation(playerid,"PED","WALK_old",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 272){ApplyAnimation(playerid,"PED","WALK_player",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 273){ApplyAnimation(playerid,"PED","WALK_rocket",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 274){ApplyAnimation(playerid,"PED","WALK_shuffle",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 275){ApplyAnimation(playerid,"PED","WALK_start",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 276){ApplyAnimation(playerid,"PED","WALK_start_armed",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 277){ApplyAnimation(playerid,"PED","WALK_start_csaw",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 278){ApplyAnimation(playerid,"PED","WALK_start_rocket",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 279){ApplyAnimation(playerid,"PED","Walk_Wuzi",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 280){ApplyAnimation(playerid,"PED","WEAPON_crouch",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 281){ApplyAnimation(playerid,"PED","woman_idlestance",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 282){ApplyAnimation(playerid,"PED","woman_run",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 283){ApplyAnimation(playerid,"PED","WOMAN_runbusy",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 284){ApplyAnimation(playerid,"PED","WOMAN_runfatold",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 285){ApplyAnimation(playerid,"PED","woman_runpanic",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 286){ApplyAnimation(playerid,"PED","WOMAN_runsexy",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 287){ApplyAnimation(playerid,"PED","WOMAN_walkbusy",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 288){ApplyAnimation(playerid,"PED","WOMAN_walkfatold",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 289){ApplyAnimation(playerid,"PED","WOMAN_walknorm",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 290){ApplyAnimation(playerid,"PED","WOMAN_walkold",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 291){ApplyAnimation(playerid,"PED","WOMAN_walkpro",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 292){ApplyAnimation(playerid,"PED","WOMAN_walksexy",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 293){ApplyAnimation(playerid,"PED","WOMAN_walkshop",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 294){ApplyAnimation(playerid,"PED","XPRESSscratch",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimSex(playerid,s);
public AnimSex(playerid,s){
if(s == 1){ApplyAnimation(playerid,"SNM","SPANKING_IDLEW",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"SNM","SPANKING_IDLEP",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"SNM","SPANKINGW",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"SNM","SPANKINGP",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"SNM","SPANKEDW",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"SNM","SPANKEDP",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"SNM","SPANKING_ENDW",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"SNM","SPANKING_ENDP",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}
forward AnimBjob(playerid,s);
public AnimBjob(playerid,s){
if(s == 1){ApplyAnimation(playerid,"BLOWJOBZ","BJ_COUCH_START_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 2){ApplyAnimation(playerid,"BLOWJOBZ","BJ_COUCH_START_W",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 3){ApplyAnimation(playerid,"BLOWJOBZ","BJ_COUCH_LOOP_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 4){ApplyAnimation(playerid,"BLOWJOBZ","BJ_COUCH_LOOP_W",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 5){ApplyAnimation(playerid,"BLOWJOBZ","BJ_COUCH_END_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 6){ApplyAnimation(playerid,"BLOWJOBZ","BJ_COUCH_END_W",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 7){ApplyAnimation(playerid,"BLOWJOBZ","BJ_STAND_START_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 8){ApplyAnimation(playerid,"BLOWJOBZ","BJ_STAND_START_W",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 9){ApplyAnimation(playerid,"BLOWJOBZ","BJ_STAND_LOOP_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 10){ApplyAnimation(playerid,"BLOWJOBZ","BJ_STAND_LOOP_W",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 11){ApplyAnimation(playerid,"BLOWJOBZ","BJ_STAND_END_P",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
if(s == 12){ApplyAnimation(playerid,"BLOWJOBZ","BJ_STAND_END_W",FF[playerid],o1[playerid],o2[playerid],o3[playerid],o4[playerid],o5[playerid]);}
return 1;
}

