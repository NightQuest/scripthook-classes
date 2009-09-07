#pragma once
#include "CEntity.h"

class CVehicle : public CEntity
{
private:
	Scripting::Vehicle veh;

public:
	// Constructor / Destructor
	CVehicle() {}
	CVehicle(Scripting::Vehicle v) { veh = v; }

	// Operators
	Scripting::Vehicle operator = (Scripting::Vehicle v) { veh = v; return veh; }
	Scripting::Vehicle &operator = (Scripting::Vehicle &v) { veh = v; return veh; }
	Scripting::Vehicle *operator &() { return &veh; }
	bool operator !() { return !(veh.IsValid() && DoesVehicleExist()); }

	// Helper functions
	void UpdateVehicle(Scripting::Ped ped) { Scripting::GetCarCharIsUsing(ped, &veh); }
	Scripting::Vehicle GetVehicle() { return veh; }

	// Wrappers
	void AddUpsideDownCarCheck() { Scripting::AddUpsideDownCarCheck(veh); }
	void AnchorBoat(bool anchor) { Scripting::AnchorBoat(veh, anchor); }
	void ApplyForceToCar(u32 unknown0_3, f32 x, f32 y, f32 z, f32 spinX, f32 spinY, f32 spinZ, u32 unknown4_0, u32 unknown5_1, u32 unknown6_1, u32 unknown7_1) { Scripting::ApplyForceToCar(veh, unknown0_3, x, y, z, spinX, spinY, spinZ, unknown4_0, unknown5_1, unknown6_1, unknown7_1); }
	bool AreTaxiLightsOn() { return Scripting::AreTaxiLightsOn(veh); }
	void BreakCarDoor(Scripting::eVehicleDoor door, bool unknownFalse) { Scripting::BreakCarDoor(veh, door, unknownFalse); }
	void BurstCarTyre(Scripting::eVehicleTyre tyre) { Scripting::BurstCarTyre(veh, tyre); }
	//void CreateCar(u32 nameHash, f32 x, f32 y, f32 z, Scripting::Vehicle *pVehicle, bool unknownTrue) { Scripting::CreateCar(nameHash, x, y, z, pVehicle, unknownTrue); }
	Scripting::Ped CreateCharAsPassenger(Scripting::ePedType charType, Scripting::eModel model, u32 passengerIndex) { Scripting::Ped ped; Scripting::CreateCharAsPassenger(veh, charType, model, passengerIndex, &ped); return ped; }
	Scripting::Ped CreateCharInsideCar(Scripting::ePedType charType, Scripting::eModel model) { Scripting::Ped ped; Scripting::CreateCharInsideCar(veh, charType, model, &ped); return ped; }
	void ChangeCarColour(Scripting::ColourIndex colour1, Scripting::ColourIndex colour2) { Scripting::ChangeCarColour(veh, colour1, colour2); }
	void ClearCarLastDamageEntity() { Scripting::ClearCarLastDamageEntity(veh); }
	void ClearCarLastWeaponDamage() { Scripting::ClearCarLastWeaponDamage(veh); }
	void ClearRoomForCar() { Scripting::ClearRoomForCar(veh); }
	void CloseAllCarDoors() { Scripting::CloseAllCarDoors(veh); }
	void ControlCarDoor(Scripting::eVehicleDoor door, u32 unknown_maybe_open, f32 angle) { Scripting::ControlCarDoor(veh, door, unknown_maybe_open, angle); }
	//bool CreateEmergencyServicesCar(Scripting::eModel model, f32 x, f32 y, f32 z) { return Scripting::CreateEmergencyServicesCar(model, x, y, z); }
	Scripting::Ped CreateRandomCharAsPassenger(u32 seat) { Scripting::Ped ped; Scripting::CreateRandomCharAsPassenger(veh, seat, &ped); return ped; }
	void DeleteCar() { Scripting::DeleteCar(&veh); }
	void DetachCar() { Scripting::DetachCar(veh); }
	bool DoesCarHaveRoof() { return Scripting::DoesCarHaveRoof(veh); }
	bool DoesCarHaveStuckCarCheck() { return Scripting::DoesCarHaveStuckCarCheck(veh); }
	bool DoesVehicleExist() { return Scripting::DoesVehicleExist(veh); }
	//void EnablePedHelmet(Scripting::Ped ped, bool enable) { Scripting::EnablePedHelmet(ped, enable); }
	void ExplodeCar(bool unknownTrue, bool unknownFalse) { Scripting::ExplodeCar(veh, unknownTrue, unknownFalse); }
	void ExtinguishCarFire() { Scripting::ExtinguishCarFire(veh); }
	void FixCar() { Scripting::FixCar(veh); }
	void FixCarTyre(Scripting::eVehicleTyre tyre) { Scripting::FixCarTyre(veh, tyre); }
	void ForceVehicleLights(Scripting::eVehicleLights lights) { Scripting::ForceVehicleLights(veh, lights); }
	void FreezeCarPosition(bool frozen) { Scripting::FreezeCarPosition(veh, frozen); }
	void FreezeCarPositionAndDontLoadCollision(bool frozen) { Scripting::FreezeCarPositionAndDontLoadCollision(veh, frozen); }
	//void GetCarCharIsUsing(Scripting::Ped ped, Scripting::Vehicle *pVehicle) { Scripting::GetCarCharIsUsing(ped, pVehicle); }
	void GetCarColours(Scripting::ColourIndex *pColour1, Scripting::ColourIndex *pColour2) { Scripting::GetCarColours(veh, pColour1, pColour2); }
	Scripting::Vector3 GetCarCoordinates(f32 *pX, f32 *pY, f32 *pZ) { Scripting::Vector3 loc; Scripting::GetCarCoordinates(veh, &loc.X, &loc.Y, &loc.Z); return loc; }
	Scripting::Vector3 GetCarDeformationAtPos(f32 x, f32 y, f32 z) { Scripting::Vector3 deformation; Scripting::GetCarDeformationAtPos(veh, x, y, z, &deformation); return deformation; }
	Scripting::eVehicleDoorLock GetCarDoorLockStatus() { Scripting::eVehicleDoorLock value; Scripting::GetCarDoorLockStatus(veh, &value); return value; }
	f32 GetCarForwardX() { f32 value; Scripting::GetCarForwardX(veh, &value); return value; }
	f32 GetCarForwardY() { f32 value; Scripting::GetCarForwardY(veh,&value); return value; }
	f32 GetCarHeading() { f32 value; Scripting::GetCarHeading(veh, &value); return value; }
	u32 GetCarHealth() { u32 value; Scripting::GetCarHealth(veh, &value); return value; }
	Scripting::eModel GetCarModel() { Scripting::eModel model; Scripting::GetCarModel(veh, &model); return model; }
	f32 GetCarPitch() { f32 pitch; Scripting::GetCarPitch(veh, &pitch); return pitch; }
	f32 GetCarRoll() { f32 roll; Scripting::GetCarRoll(veh, &roll); return roll; }
	f32 GetCarSpeed() { f32 speed; Scripting::GetCarSpeed(veh, &speed); return speed; }
	Scripting::Vector3 GetCarSpeedVector(bool unknownFalse) { Scripting::Vector3 speed; Scripting::GetCarSpeedVector(veh, &speed, unknownFalse); return speed; }
	f32 GetCarUprightValue() { f32 value; Scripting::GetCarUprightValue(veh, &value); return value; }
	Scripting::Ped GetCharInCarPassengerSeat(u32 seatIndex) { Scripting::Ped ped; Scripting::GetCharInCarPassengerSeat(veh, seatIndex, &ped); return ped; }
	//Scripting::Vehicle GetClosestCar(f32 x, f32 y, f32 z, f32 radius, u32 unknown0_0, u32 unknown1_70) { return Scripting::GetClosestCar(x, y, z, radius, unknown0_0, unknown1_70); }
	//bool GetClosestCarNode(f32 x, f32 y, f32 z, f32 *pResX, f32 *pResY, f32 *pResZ) { return Scripting::GetClosestCarNode(x, y, z, pResX, pResY, pResZ); }
	//bool GetClosestCarNodeWithHeading(f32 x, f32 y, f32 z, f32 *pResX, f32 *pResY, f32 *pResZ, f32 *pHeading) { return Scripting::GetClosestCarNodeWithHeading(x, y, z, pResX, pResY, pResZ, pHeading); }
	//bool GetClosestMajorCarNode(f32 x, f32 y, f32 z, f32 *pResX, f32 *pResY, f32 *pResZ) { return Scripting::GetClosestMajorCarNode(x, y, z, pResX, pResY, pResZ); }
	//bool GetNthClosestCarNodeWithHeading(f32 x, f32 y, f32 z, u32 nodeNum,  f32 *pResX, f32 *pResY, f32 *pResZ, f32 *pHeading) { return Scripting::GetNthClosestCarNodeWithHeading(x, y, z, nodeNum, pResX, pResY, pResZ, pHeading); }
	//bool GetNthClosestCarNodeWithHeadingOnIsland(f32 x, f32 y, f32 z, u32 nodeNum, u32 areaId, f32 *pResX, f32 *pResY, f32 *pResZ, f32 *pHeading, u32 *pUnknownMaybeAreaId) { return Scripting::GetNthClosestCarNodeWithHeadingOnIsland(x, y, z, nodeNum, areaId, pResX, pResY, pResZ, pHeading, pUnknownMaybeAreaId); }
	Scripting::Vector3 GetDeadCarCoordinates() { Scripting::Vector3 loc; Scripting::GetDeadCarCoordinates(veh, &loc.X, &loc.Y, &loc.Z); return loc; }
	f32 GetDoorAngleRatio(Scripting::eVehicleDoor door) { f32 AngleRatio; Scripting::GetDoorAngleRatio(veh, door, &AngleRatio); return AngleRatio; }
	Scripting::Ped GetDriverOfCar() { Scripting::Ped ped; Scripting::GetDriverOfCar(veh, &ped); return ped; }
	f32 GetEngineHealth() { return Scripting::GetEngineHealth(veh); }
	void GetExtraCarColours(Scripting::ColourIndex *pColour1, Scripting::ColourIndex *pColour2) { Scripting::GetExtraCarColours(veh, pColour1, pColour2); }
	f32 GetHeightOfVehicle(f32 x, f32 y, f32 z, bool unknownTrue1, bool unknownTrue2) { return Scripting::GetHeightOfVehicle(veh, x, y, z, unknownTrue1, unknownTrue2); }
	u32 GetKeyForCarInRoom() { u32 key; Scripting::GetKeyForCarInRoom(veh, &key); return key; }
	u32 GetMaximumNumberOfPassengers() { u32 max; Scripting::GetMaximumNumberOfPassengers(veh, &max); return max; }
	//void GetNearestCableCar(f32 x, f32 y, f32 z, f32 radius, Scripting::Vehicle *pVehicle) { Scripting::GetNearestCableCar(x, y, z, radius, pVehicle); }
	u32 GetNumCarColours() { u32 NumColours; Scripting::GetNumCarColours(veh, &NumColours); return NumColours; }
	u32 GetNumberOfPassengers() { u32 NumPassengers; Scripting::GetNumberOfPassengers(veh, &NumPassengers); return NumPassengers; }
	Scripting::Vector3 GetOffsetFromCarGivenWorldCoords(f32 x, f32 y, f32 z) { Scripting::Vector3 offset; Scripting::GetOffsetFromCarGivenWorldCoords(veh, x, y, z, &offset.X, &offset.Y, &offset.Z); return offset; }
	Scripting::Vector3 GetOffsetFromCarInWorldCoords(f32 x, f32 y, f32 z) { Scripting::Vector3 offset; Scripting::GetOffsetFromCarInWorldCoords(veh, x, y, z, &offset.X, &offset.Y, &offset.Z); return offset; }
	f32 GetPetrolTankHealth() { return Scripting::GetPetrolTankHealth(veh); }
	void GetRandomCarModelInMemory(bool unknownTrue, u32 *pHash, Scripting::ScriptAny *pUnknown) { Scripting::GetRandomCarModelInMemory(unknownTrue, pHash, pUnknown); }
	f32 GetVehicleDirtLevel() { f32 Intensity; Scripting::GetVehicleDirtLevel(veh, &Intensity); return Intensity; }
	bool HasCarBeenDamagedByCar(Scripting::Vehicle otherCar) { return Scripting::HasCarBeenDamagedByCar(veh, otherCar); }
	bool HasCarBeenDamagedByChar(Scripting::Ped ped) { return Scripting::HasCarBeenDamagedByChar(veh, ped); }
	bool HasCarBeenDamagedByWeapon(Scripting::eWeapon weapon) { return Scripting::HasCarBeenDamagedByWeapon(veh, weapon); }
	bool HasCarBeenResprayed() { return Scripting::HasCarBeenResprayed(veh); }
	bool IsBigVehicle() { return Scripting::IsBigVehicle(veh); }
	bool IsCarAMissionCar() { return Scripting::IsCarAMissionCar(veh); }
	bool IsCarAttached() { return Scripting::IsCarAttached(veh); }
	bool IsCarDead() { return Scripting::IsCarDead(veh); }
	bool IsCarDoorDamaged(Scripting::eVehicleDoor door) { return Scripting::IsCarDoorDamaged(veh, door); }
	bool IsCarDoorFullyOpen(Scripting::eVehicleDoor door) { return Scripting::IsCarDoorFullyOpen(veh, door); }
	bool IsCarInAirProper() { return Scripting::IsCarInAirProper(veh); }
	bool IsCarInArea2D(f32 x1, f32 y1, f32 x2, f32 y2, bool unknownFalse) { return Scripting::IsCarInArea2D(veh, x1, y1, x2, y2, unknownFalse); }
	bool IsCarInArea3D(f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, u8 unknownFalse) { return Scripting::IsCarInArea3D(veh, x1, y1, z1, x2, y2, z2, unknownFalse); }
	bool IsCarInWater() { return Scripting::IsCarInWater(veh); }
	bool IsCarModel(Scripting::eModel model) { return Scripting::IsCarModel(veh, model); }
	bool IsCarOnFire() { return Scripting::IsCarOnFire(veh); }
	bool IsCarOnScreen() { return Scripting::IsCarOnScreen(veh); }
	bool IsCarPassengerSeatFree(u32 seatIndex) { return Scripting::IsCarPassengerSeatFree(veh, seatIndex); }
	bool IsCarSirenOn() { return Scripting::IsCarSirenOn(veh); }
	bool IsCarStopped() { return Scripting::IsCarStopped(veh); }
	bool IsCarStoppedAtTrafficLights() { return Scripting::IsCarStoppedAtTrafficLights(veh); }
	bool IsCarStuckOnRoof() { return Scripting::IsCarStuckOnRoof(veh); }
	bool IsCarTouchingCar(Scripting::Vehicle otherCar) { return Scripting::IsCarTouchingCar(veh, otherCar); }
	bool IsCarTyreBurst(Scripting::eVehicleTyre tyre) { return Scripting::IsCarTyreBurst(veh, tyre); }
	bool IsCarUpright() { return Scripting::IsCarUpright(veh); }
	bool IsCarUpsidedown() { return Scripting::IsCarUpsidedown(veh); }
	bool IsCarWaitingForWorldCollision() { return Scripting::IsCarWaitingForWorldCollision(veh); }
	bool IsVehDriveable() { return Scripting::IsVehDriveable(veh); }
	bool IsVehWindowIntact(Scripting::eVehicleWindow window) { return Scripting::IsVehWindowIntact(veh, window); }
	bool IsVehicleExtraTurnedOn(Scripting::eVehicleExtra extra) { return Scripting::IsVehicleExtraTurnedOn(veh, extra); }
	bool IsVehicleOnAllWheels() { return Scripting::IsVehicleOnAllWheels(veh); }
	void KnockPedOffBike() { Scripting::KnockPedOffBike(veh); }
	void LockCarDoors(Scripting::eVehicleDoorLock value) { Scripting::LockCarDoors(veh, value); }
	void MarkCarAsConvoyCar(bool convoyCar) { Scripting::MarkCarAsConvoyCar(veh, convoyCar); }
	void MarkCarAsNoLongerNeeded() { Scripting::MarkCarAsNoLongerNeeded(&veh); }
	void OpenCarDoor(Scripting::eVehicleDoor door) { Scripting::OpenCarDoor(veh, door); }
	void PopCarBoot() { Scripting::PopCarBoot(veh); }
	void RemoveVehicleWindow(Scripting::eVehicleWindow window) { Scripting::RemoveVehicleWindow(veh, window); }
	void RemoveStuckCarCheck() { Scripting::RemoveStuckCarCheck(veh); }
	void RemoveUpsidedownCarCheck() { Scripting::RemoveUpsidedownCarCheck(veh); }
	void SetCarCoordinates(f32 pX, f32 pY, f32 pZ) { Scripting::SetCarCoordinates(veh, pX, pY, pZ); }
	void SetCarHealth(u32 pValue) { Scripting::SetCarHealth(veh, pValue); }
	void SetPetrolTankHealth(f32 value) { Scripting::SetPetrolTankHealth(veh, value); }
	void SetCarCanBeDamaged(bool value) { Scripting::SetCarCanBeDamaged(veh, value); }
	void SetCarCanBeVisiblyDamaged(bool value) { Scripting::SetCarCanBeVisiblyDamaged(veh, value); }
	void SetCarForwardSpeed(f32 speed) { Scripting::SetCarForwardSpeed(veh, speed); }
	void SetCarHeading(f32 dir) { Scripting::SetCarHeading(veh, dir); }
	Scripting::ScriptAny SetCarOnGroundProperly() { return Scripting::SetCarOnGroundProperly(veh); }
	void SetCarProofs(bool bulletProof, bool fireProof, bool explosionProof, bool collisionProof, bool meleeProof) { Scripting::SetCarProofs(veh, bulletProof, fireProof, explosionProof, collisionProof, meleeProof); }
	void SetCarStrong(bool strong) { Scripting::SetCarStrong(veh, strong); }
	void SetCarVisible(bool value) { Scripting::SetCarVisible(veh, value); }
	void SetExtraCarColours(Scripting::ColourIndex colour1, Scripting::ColourIndex colour2) { Scripting::SetExtraCarColours(veh, colour1, colour2); }
	void SetEngineHealth(f32 health) { Scripting::SetEngineHealth(veh, health); }
	void SetVehHazardLights(bool on) { Scripting::SetVehHazardLights(veh, on); }
	void SetVehicleDirtLevel(f32 intensity) { Scripting::SetVehicleDirtLevel(veh, intensity); }
	void ShutCarDoor(Scripting::eVehicleDoor door) { Scripting::ShutCarDoor(veh, door); }
	void SoundCarHorn(u32 duration) { Scripting::SoundCarHorn(veh, duration); }
	void WashVehicleTextures(u32 intensity) { Scripting::WashVehicleTextures(veh, intensity); }
};