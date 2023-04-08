//Easy vehicle by Ivan Pantovic
#include <a_samp>

forward TogVehicleEngine(vehicleid, easy_engine);
forward TogVehicleLights(vehicleid, easy_lights);
forward TogVehicleAlarm(vehicleid, easy_alarm);
forward TogVehicleDoors(vehicleid, easy_doors);
forward TogVehicleBonnet(vehicleid, easy_bonnet);
forward TogVehicleBoot(vehicleid, easy_boot);
forward TogVehicleObjective(vehicleid, easy_objective);

forward GetVehicleEngine(vehicleid, easy_engine);
forward GetVehicleLights(vehicleid, easy_lights);
forward GetVehicleAlarm(vehicleid, easy_alarm);
forward GetVehicleDoors(vehicleid, easy_doors);
forward GetVehicleBonnet(vehicleid, easy_bonnet);
forward GetVehicleBoot(vehicleid, easy_boot);
forward GetVehicleObjective(vehicleid, easy_objective);

new engine_before,lights_before,alarm_before,doors_before,bonnet_before,boot_before,objective_before;

public GetVehicleEngine(vehicleid, easy_engine)
{
	GetVehicleParamsEx(vehicleid, easy_engine, lights_before, alarm_before, doors_before, bonnet_before, boot_before, objective_before);
}

public GetVehicleLights(vehicleid, easy_lights)
{
	GetVehicleParamsEx(vehicleid, engine_before, easy_lights, alarm_before, doors_before, bonnet_before, boot_before, objective_before);
}

public GetVehicleAlarm(vehicleid, easy_alarm)
{
	GetVehicleParamsEx(vehicleid, engine_before, lights_before, easy_alarm, doors_before, bonnet_before, boot_before, objective_before);
}

public GetVehicleDoors(vehicleid, easy_doors)
{
	GetVehicleParamsEx(vehicleid, engine_before, lights_before, alarm_before, easy_doors, bonnet_before, boot_before, objective_before);
}

public GetVehicleBonnet(vehicleid, easy_bonnet)
{
	GetVehicleParamsEx(vehicleid, engine_before, lights_before, alarm_before, doors_before, bonnet_before, boot_before, objective_before);
}

public GetVehicleBoot(vehicleid, easy_boot)
{
	GetVehicleParamsEx(vehicleid, engine_before, lights_before, alarm_before, doors_before, bonnet_before, easy_boot, objective_before);
}

public GetVehicleObjective(vehicleid, easy_objective)
{
	GetVehicleParamsEx(vehicleid, engine_before, lights_before, alarm_before, doors_before, bonnet_before, boot_before, easy_objective);
}

public TogVehicleEngine(vehicleid, easy_engine)
{
	GetVehicleParamsEx(vehicleid, engine_before, lights_before, alarm_before, doors_before, bonnet_before, boot_before, objective_before);
	SetVehicleParamsEx(vehicleid, easy_engine, lights_before, alarm_before, doors_before, bonnet_before, boot_before, objective_before);
}

public TogVehicleLights(vehicleid, easy_lights)
{
	GetVehicleParamsEx(vehicleid, engine_before, lights_before, alarm_before, doors_before, bonnet_before, boot_before, objective_before);
	SetVehicleParamsEx(vehicleid, engine_before, easy_lights, alarm_before, doors_before, bonnet_before, boot_before, objective_before);
}

public TogVehicleAlarm(vehicleid, easy_alarm)
{
	GetVehicleParamsEx(vehicleid, engine_before, lights_before, alarm_before, doors_before, bonnet_before, boot_before, objective_before);
	SetVehicleParamsEx(vehicleid, engine_before, lights_before, easy_alarm, doors_before, bonnet_before, boot_before, objective_before);
}

public TogVehicleDoors(vehicleid, easy_doors)
{
	GetVehicleParamsEx(vehicleid, engine_before, lights_before, alarm_before, doors_before, bonnet_before, boot_before, objective_before);
	SetVehicleParamsEx(vehicleid, engine_before, lights_before, alarm_before, easy_doors, bonnet_before, boot_before, objective_before);
}

public TogVehicleBonnet(vehicleid, easy_bonnet)
{
	GetVehicleParamsEx(vehicleid, engine_before, lights_before, alarm_before, doors_before, bonnet_before, boot_before, objective_before);
	SetVehicleParamsEx(vehicleid, engine_before, lights_before, alarm_before, doors_before, easy_bonnet, boot_before, objective_before);
}

public TogVehicleBoot(vehicleid, easy_boot)
{
	GetVehicleParamsEx(vehicleid, engine_before, lights_before, alarm_before, doors_before, bonnet_before, boot_before, objective_before);
	SetVehicleParamsEx(vehicleid, engine_before, lights_before, alarm_before, doors_before, bonnet_before, easy_boot, objective_before);
}

public TogVehicleObjective(vehicleid, easy_objective)
{
	GetVehicleParamsEx(vehicleid, engine_before, lights_before, alarm_before, doors_before, bonnet_before, boot_before, objective_before);
	SetVehicleParamsEx(vehicleid, engine_before, lights_before, alarm_before, doors_before, bonnet_before, boot_before, easy_objective);
}