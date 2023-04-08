#include <a_samp>
#include <dudb>
#include <dini>
#include <zcmd>
#include <colors>
#include <utils>
#define MAX_HOUSES 1500
#define MAX_VEH 1500
#define MAX_BUSINESSES 650
enum PData
{
	LoggedIn,
	AdminLevel,
	Skin,
	Phone,
	Cash,
	BankCash,
	CarID,
	HouseID,
	BusinessID,
	GroupID,
	SAPDLevel,
	SWATLevel,
	FBILevel,
	IsWanted
}
new PlayerData[MAX_PLAYERS][PData];

enum HData
{
	Price,
	Owner[24],
	Rent,
	Renters[5],
	Size,
	IntID,
	VirtualWorld,
	PickupX,
	PickupY,
	PickupZ
}
new HouseData[MAX_HOUSES][HData];

enum VData
{
	OwnerID,
	Model,
	Price,
	Color1,
	Color2,
	Float:SpawnX,
	Float:SpawnY,
	Float:SpawnZ,
	Float:SpawnAng,
	Engine
}

new VehicleData[MAX_VEH][VData];

enum BizData
{
	Owner[24],
	Price,
	Workers[50],
	Type,
	IntID,
	VirtualWorld,
	SafeCash,
	PickupX,
	PickupY,
	PickupZ
}
new BData[MAX_BUSINESSES][BizData];
