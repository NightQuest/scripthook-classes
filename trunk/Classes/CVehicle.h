#pragma once
#include "CEntity.h"

class CVehicle : public CEntity
{
private:
	Scripting::Vehicle vehicle;

public:
	// Constructor / Destructor
	CVehicle() {}
	CVehicle(Scripting::Vehicle v) { vehicle = v; }
	//~CVehicle();
	CVehicle operator = (Scripting::Vehicle v) { vehicle = v; return vehicle; }

	// Helper functions
	void UpdateVehicle(Scripting::Ped ped) { Scripting::GetCarCharIsUsing(ped, &vehicle); }
	Scripting::Vehicle GetVehicle() { return vehicle; }
	void SetVehicle(Scripting::Vehicle v) { vehicle = v; }
	bool DoesExist() { return (vehicle.IsValid() && Scripting::DoesVehicleExist(vehicle)); }

	void ApplyForce(u32 unknown0_3, f32 x, f32 y, f32 z, f32 spinX, f32 spinY, f32 spinZ, u32 unknown4_0, u32 unknown5_1, u32 unknown6_1, u32 unknown7_1);
	void Explode(bool unknownTrue, bool unknownFalse) { Scripting::ExplodeCar(vehicle, unknownTrue, unknownFalse); }
	void Repair() { Scripting::FixCar(vehicle); }
	void SetCanBeDamaged(bool CanBeDamaged) { Scripting::SetCarCanBeDamaged(vehicle, CanBeDamaged); }
	void SetCanBeVisiblyDamaged(bool CanBeVisiblyDamaged) { Scripting::SetCarCanBeVisiblyDamaged(vehicle, CanBeVisiblyDamaged); }
};