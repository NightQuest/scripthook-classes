#include "CPed.h"

CPed::CPed()
{
	veh = new CVehicle;
}
CPed::CPed(Scripting::Ped p)
{
	_ped = p;
	veh = new CVehicle(GetVehicle());
}

CPed::~CPed()
{
	delete veh;
}