#include <a_samp>

forward CheckForAll();
forward CheckForMeele();
forward CheckForHeavy();
forward CheckForAssault();
forward CheckForLight();
forward CheckForShotgun();
forward CheckForRifle();
forward CheckForRPG();
forward CheckForMinigun();
forward CheckForGrenade();
forward CheckForMolotov();
forward CheckForStatchel();
forward CheckForVision();

public CheckForAll()
{
    SetTimer("AllCheck", 1000, true);
}
public CheckForMeele()
{
    SetTimer("MeeleCheck", 1000, true);
}
public CheckForHeavy()
{
    SetTimer("HeavyCheck", 1000, true);
}
public CheckForAssault()
{
    SetTimer("AssaultCheck", 1000, true);
}
public CheckForLight()
{
    SetTimer("LightCheck", 1000, true);
}
public CheckForShotgun()
{
    SetTimer("ShotgunCheck", 1000, true);
}
public CheckForRifle()
{
    SetTimer("RifleCheck", 1000, true);
}
public CheckForRPG()
{
    SetTimer("RPGCheck", 1000, true);
}
public CheckForMinigun()
{
    SetTimer("MinigunCheck", 1000, true);
}
public CheckForGrenade()
{
    SetTimer("GrenadeCheck", 1000, true);
}
public CheckForMolotov()
{
    SetTimer("MolotovCheck", 1000, true);
}
public CheckForStatchel()
{
    SetTimer("StatchelCheck", 1000, true);
}
public CheckForVision()
{
    SetTimer("VisionCheck", 1000, true);
}

forward AllCheck(playerid);
public AllCheck(playerid)
{
    if(GetPlayerWeapon(playerid) == 1) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 2) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 3) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 4) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 5) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 6) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 7) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 8) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 9) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 10) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 11) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 12) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 13) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 14) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 15) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 16) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 17) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 18) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 22) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 23) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 24) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 25) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 26) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 27) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 28) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 29) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 31) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 32) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 33) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 34) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 35) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 36) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 37) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 38) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 39) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 40) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 41) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 42) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 43) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 45) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 46) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 47) Kick(playerid);
    
}
forward MeeleCheck(playerid);
public MeeleCheck(playerid)
{
    if(GetPlayerWeapon(playerid) == 1) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 2) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 3) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 4) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 5) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 6) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 7) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 8) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 9) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 10) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 11) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 12) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 13) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 14) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 15) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 41) Kick(playerid);
}
forward HeavyCheck(playerid);
public HeavyCheck(playerid)
{
    if(GetPlayerWeapon(playerid) == 9) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 34) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 35) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 36) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 37) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 38) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 39) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 40) Kick(playerid);
}
forward AssaultCheck(playerid);
public AssaultCheck(playerid)
{
    if(GetPlayerWeapon(playerid) == 30) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 31) Kick(playerid);
}
forward LightCheck(playerid);
public LightCheck(playerid)
{
    if(GetPlayerWeapon(playerid) == 22) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 23) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 24) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 26) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 28) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 29) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 32) Kick(playerid);
}
forward ShotgunCheck(playerid);
public ShotgunCheck(playerid)
{
    if(GetPlayerWeapon(playerid) == 25) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 26) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 27) Kick(playerid);
}
forward RifleCheck(playerid);
public RifleCheck(playerid)
{
    if(GetPlayerWeapon(playerid) == 33) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 34) Kick(playerid);
}
forward RPGCheck(playerid);
public RPGCheck(playerid)
{
    if(GetPlayerWeapon(playerid) == 35) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 36) Kick(playerid);
}
forward StatchelCheck(playerid);
public StatchelCheck(playerid)
{
    if(GetPlayerWeapon(playerid) == 39) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 40) Kick(playerid);
}
forward VisionCheck(playerid);
public VisionCheck(playerid)
{
    if(GetPlayerWeapon(playerid) == 44) Kick(playerid);
    if(GetPlayerWeapon(playerid) == 45) Kick(playerid);
}

