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
	//~CVehicle();
	CVehicle operator = (Scripting::Vehicle v) { veh = v; return veh; }

	// Helper functions
	void UpdateVehicle(Scripting::Ped ped) { Scripting::GetCarCharIsUsing(ped, &veh); }
	Scripting::Vehicle GetVehicle() { return veh; }
	void SetVehicle(Scripting::Vehicle v) { veh = v; }
	bool DoesExist() { return (veh.IsValid() && Scripting::DoesVehicleExist(veh)); }

	// Wrappers
	void AddUpsideDownCarCheck(Scripting::Vehicle vehicle) { Scripting::AddUpsideDownCarCheck(vehicle); }
	void AnchorBoat(Scripting::Vehicle boat, bool anchor) { Scripting::AnchorBoat(boat, anchor); }
	void ApplyForceToCar(Scripting::Vehicle vehicle, u32 unknown0_3, f32 x, f32 y, f32 z, f32 spinX, f32 spinY, f32 spinZ, u32 unknown4_0, u32 unknown5_1, u32 unknown6_1, u32 unknown7_1) { Scripting::ApplyForceToCar(vehicle, unknown0_3, x, y, z, spinX, spinY, spinZ, unknown4_0, unknown5_1, unknown6_1, unknown7_1); }
	bool AreTaxiLightsOn(Scripting::Vehicle vehicle) { return Scripting::AreTaxiLightsOn(vehicle); }
	void BreakCarDoor(Scripting::Vehicle vehicle, Scripting::eVehicleDoor door, bool unknownFalse) { Scripting::BreakCarDoor(vehicle, door, unknownFalse); }
	void BurstCarTyre(Scripting::Vehicle vehicle, Scripting::eVehicleTyre tyre) { Scripting::BurstCarTyre(vehicle, tyre); }
	void CreateCar(u32 nameHash, f32 x, f32 y, f32 z, Scripting::Vehicle *pVehicle, bool unknownTrue) { Scripting::CreateCar(nameHash, x, y, z, pVehicle, unknownTrue); }
	void CreateCharAsPassenger(Scripting::Vehicle vehicle, Scripting::ePedType charType, Scripting::eModel model, u32 passengerIndex, Scripting::Ped *pPed) { Scripting::CreateCharAsPassenger(vehicle, charType, model, passengerIndex, pPed); }
	void CreateCharInsideCar(Scripting::Vehicle vehicle, Scripting::ePedType charType, Scripting::eModel model, Scripting::Ped *pPed) { Scripting::CreateCharInsideCar(vehicle, charType, model, pPed); }
	void ChangeCarColour(Scripting::Vehicle vehicle, Scripting::ColourIndex colour1, Scripting::ColourIndex colour2) { Scripting::ChangeCarColour(vehicle, colour1, colour2); }
	void ClearCarLastDamageEntity(Scripting::Vehicle vehicle) { Scripting::ClearCarLastDamageEntity(vehicle); }
	void ClearCarLastWeaponDamage(Scripting::Vehicle vehicle) { Scripting::ClearCarLastWeaponDamage(vehicle); }
	void ClearRoomForCar(Scripting::Vehicle vehicle) { Scripting::ClearRoomForCar(vehicle); }
	void CloseAllCarDoors(Scripting::Vehicle vehicle) { Scripting::CloseAllCarDoors(vehicle); }
	void ControlCarDoor(Scripting::Vehicle vehicle, Scripting::eVehicleDoor door, u32 unknown_maybe_open, f32 angle) { Scripting::ControlCarDoor(vehicle, door, unknown_maybe_open, angle); }
	bool CreateEmergencyServicesCar(Scripting::eModel model, f32 x, f32 y, f32 z) { return Scripting::CreateEmergencyServicesCar(model, x, y, z); }
	void CreateRandomCharAsPassenger(Scripting::Vehicle vehicle, u32 seat, Scripting::Ped *pPed) { Scripting::CreateRandomCharAsPassenger(vehicle, seat, pPed); }
	void DeleteCar(Scripting::Vehicle *pVehicle) { Scripting::DeleteCar(pVehicle); }
	void DetachCar(Scripting::Vehicle vehicle) { Scripting::DetachCar(vehicle); }
	bool DoesCarHaveRoof(Scripting::Vehicle vehicle) { return Scripting::DoesCarHaveRoof(vehicle); }
	bool DoesCarHaveStuckCarCheck(Scripting::Vehicle vehicle) { return Scripting::DoesCarHaveStuckCarCheck(vehicle); }
	bool DoesVehicleExist(Scripting::Vehicle vehicle) { return Scripting::DoesVehicleExist(vehicle); }
	void EnablePedHelmet(Scripting::Ped ped, bool enable) { Scripting::EnablePedHelmet(ped, enable); }
	void ExplodeCar(Scripting::Vehicle vehicle, bool unknownTrue, bool unknownFalse) { Scripting::ExplodeCar(vehicle, unknownTrue, unknownFalse); }
	void ExtinguishCarFire(Scripting::Vehicle vehicle) { Scripting::ExtinguishCarFire(vehicle); }
	void FixCar(Scripting::Vehicle vehicle) { Scripting::FixCar(vehicle); }
	void FixCarTyre(Scripting::Vehicle vehicle, Scripting::eVehicleTyre tyre) { Scripting::FixCarTyre(vehicle, tyre); }
	void ForceVehicleLights(Scripting::Vehicle vehicle, Scripting::eVehicleLights lights) { Scripting::ForceVehicleLights(vehicle, lights); }
	void FreezeCarPosition(Scripting::Vehicle vehicle, bool frozen) { Scripting::FreezeCarPosition(vehicle, frozen); }
	void FreezeCarPositionAndDontLoadCollision(Scripting::Vehicle vehicle, bool frozen) { Scripting::FreezeCarPositionAndDontLoadCollision(vehicle, frozen); }
	void GetCarCharIsUsing(Scripting::Ped ped, Scripting::Vehicle *pVehicle) { Scripting::GetCarCharIsUsing(ped, pVehicle); }
	void GetCarColours(Scripting::Vehicle vehicle, Scripting::ColourIndex *pColour1, Scripting::ColourIndex *pColour2) { Scripting::GetCarColours(vehicle, pColour1, pColour2); }
	void GetCarCoordinates(Scripting::Vehicle vehicle, f32 *pX, f32 *pY, f32 *pZ) { Scripting::GetCarCoordinates(vehicle, pX, pY, pZ); }
	void GetCarDeformationAtPos(Scripting::Vehicle vehicle, f32 x, f32 y, f32 z, Scripting::Vector3 *pDeformation) { Scripting::GetCarDeformationAtPos(vehicle, x, y, z, pDeformation); }
	void GetCarDoorLockStatus(Scripting::Vehicle vehicle, Scripting::eVehicleDoorLock *pValue) { Scripting::GetCarDoorLockStatus(vehicle, pValue); }
	void GetCarForwardX(Scripting::Vehicle vehicle, f32 *pValue) { Scripting::GetCarForwardX(vehicle, pValue); }
	void GetCarForwardY(Scripting::Vehicle vehicle, f32 *pValue) { Scripting::GetCarForwardY(vehicle, pValue); }
	void GetCarHeading(Scripting::Vehicle vehicle, f32 *pValue) { Scripting::GetCarHeading(vehicle, pValue); }
	void GetCarHealth(Scripting::Vehicle vehicle, u32 *pValue) { Scripting::GetCarHealth(vehicle, pValue); }
	void GetCarModel(Scripting::Vehicle vehicle, Scripting::eModel *pValue) { Scripting::GetCarModel(vehicle, pValue); }
	void GetCarPitch(Scripting::Vehicle vehicle, f32 *pValue) { Scripting::GetCarPitch(vehicle, pValue); }
	void GetCarRoll(Scripting::Vehicle vehicle, f32 *pValue) { Scripting::GetCarRoll(vehicle, pValue); }
	void GetCarSpeed(Scripting::Vehicle vehicle, f32 *pValue) { Scripting::GetCarSpeed(vehicle, pValue); }
	void GetCarSpeedVector(Scripting::Vehicle vehicle, Scripting::Vector3 *pVector, bool unknownFalse) { Scripting::GetCarSpeedVector(vehicle, pVector, unknownFalse); }
	void GetCarUprightValue(Scripting::Vehicle vehicle, f32 *pValue) { Scripting::GetCarUprightValue(vehicle, pValue); }
	void GetCharInCarPassengerSeat(Scripting::Vehicle vehicle, u32 seatIndex, Scripting::Ped *pPed) { Scripting::GetCharInCarPassengerSeat(vehicle, seatIndex, pPed); }
	Scripting::Vehicle GetClosestCar(f32 x, f32 y, f32 z, f32 radius, u32 unknown0_0, u32 unknown1_70) { return Scripting::GetClosestCar(x, y, z, radius, unknown0_0, unknown1_70); }
	bool GetClosestCarNode(f32 x, f32 y, f32 z, f32 *pResX, f32 *pResY, f32 *pResZ) { return Scripting::GetClosestCarNode(x, y, z, pResX, pResY, pResZ); }
	bool GetClosestCarNodeWithHeading(f32 x, f32 y, f32 z, f32 *pResX, f32 *pResY, f32 *pResZ, f32 *pHeading) { return Scripting::GetClosestCarNodeWithHeading(x, y, z, pResX, pResY, pResZ, pHeading); }
	bool GetClosestMajorCarNode(f32 x, f32 y, f32 z, f32 *pResX, f32 *pResY, f32 *pResZ) { return Scripting::GetClosestMajorCarNode(x, y, z, pResX, pResY, pResZ); }
	bool GetNthClosestCarNodeWithHeading(f32 x, f32 y, f32 z, u32 nodeNum,  f32 *pResX, f32 *pResY, f32 *pResZ, f32 *pHeading) { return Scripting::GetNthClosestCarNodeWithHeading(x, y, z, nodeNum, pResX, pResY, pResZ, pHeading); }
	bool GetNthClosestCarNodeWithHeadingOnIsland(f32 x, f32 y, f32 z, u32 nodeNum, u32 areaId, f32 *pResX, f32 *pResY, f32 *pResZ, f32 *pHeading, u32 *pUnknownMaybeAreaId) { return Scripting::GetNthClosestCarNodeWithHeadingOnIsland(x, y, z, nodeNum, areaId, pResX, pResY, pResZ, pHeading, pUnknownMaybeAreaId); }
	void GetDeadCarCoordinates(Scripting::Vehicle vehicle, f32 *pX, f32 *pY, f32 *pZ) { Scripting::GetDeadCarCoordinates(vehicle, pX, pY, pZ); }
	void GetDoorAngleRatio(Scripting::Vehicle vehicle, Scripting::eVehicleDoor door, f32 *pAngleRatio) { Scripting::GetDoorAngleRatio(vehicle, door, pAngleRatio); }
	void GetDriverOfCar(Scripting::Vehicle vehicle, Scripting::Ped *pPed) { Scripting::GetDriverOfCar(vehicle, pPed); }
	f32 GetEngineHealth(Scripting::Vehicle vehicle) { return Scripting::GetEngineHealth(vehicle); }
	void GetExtraCarColours(Scripting::Vehicle vehicle, Scripting::ColourIndex *pColour1, Scripting::ColourIndex *pColour2) { Scripting::GetExtraCarColours(vehicle, pColour1, pColour2); }
	f32 GetHeightOfVehicle(Scripting::Vehicle vehicle, f32 x, f32 y, f32 z, bool unknownTrue1, bool unknownTrue2) { return Scripting::GetHeightOfVehicle(vehicle, x, y, z, unknownTrue1, unknownTrue2); }
	void GetKeyForCarInRoom(Scripting::Vehicle vehicle, u32 *pKey) { Scripting::GetKeyForCarInRoom(vehicle, pKey); }
	void GetMaximumNumberOfPassengers(Scripting::Vehicle vehicle, u32 *pMax) { Scripting::GetMaximumNumberOfPassengers(vehicle, pMax); }
	void GetNearestCableCar(f32 x, f32 y, f32 z, f32 radius, Scripting::Vehicle *pVehicle) { Scripting::GetNearestCableCar(x, y, z, radius, pVehicle); }
	void GetNumCarColours(Scripting::Vehicle vehicle, u32 *pNumColours) { Scripting::GetNumCarColours(vehicle, pNumColours); }
	void GetNumberOfPassengers(Scripting::Vehicle vehicle, u32 *pNumPassengers) { Scripting::GetNumberOfPassengers(vehicle, pNumPassengers); }
	void GetOffsetFromCarGivenWorldCoords(Scripting::Vehicle vehicle, f32 x, f32 y, f32 z, f32 *pOffX, f32 *pOffY, f32 *pOffZ) { Scripting::GetOffsetFromCarGivenWorldCoords(vehicle, x, y, z, pOffX, pOffY, pOffZ); }
	void GetOffsetFromCarInWorldCoords(Scripting::Vehicle vehicle, f32 x, f32 y, f32 z, f32 *pOffX, f32 *pOffY, f32 *pOffZ) { Scripting::GetOffsetFromCarInWorldCoords(vehicle, x, y, z, pOffX, pOffY, pOffZ); }
	f32 GetPetrolTankHealth(Scripting::Vehicle vehicle) { return Scripting::GetPetrolTankHealth(vehicle); }
	void GetRandomCarModelInMemory(bool unknownTrue, u32 *pHash, Scripting::ScriptAny *pUnknown) { Scripting::GetRandomCarModelInMemory(unknownTrue, pHash, pUnknown); }
	void GetVehicleDirtLevel(Scripting::Vehicle vehicle, f32* pIntensity) { Scripting::GetVehicleDirtLevel(vehicle, pIntensity); }
	bool HasCarBeenDamagedByCar(Scripting::Vehicle vehicle, Scripting::Vehicle otherCar) { return Scripting::HasCarBeenDamagedByCar(vehicle, otherCar); }
	bool HasCarBeenDamagedByChar(Scripting::Vehicle vehicle, Scripting::Ped ped) { return Scripting::HasCarBeenDamagedByChar(vehicle, ped); }
	bool HasCarBeenDamagedByWeapon(Scripting::Vehicle vehicle, Scripting::eWeapon weapon) { return Scripting::HasCarBeenDamagedByWeapon(vehicle, weapon); }
	bool HasCarBeenResprayed(Scripting::Vehicle vehicle) { return Scripting::HasCarBeenResprayed(vehicle); }
	bool IsBigVehicle(Scripting::Vehicle vehicle) { return Scripting::IsBigVehicle(vehicle); }
	bool IsCarAMissionCar(Scripting::Vehicle vehicle) { return Scripting::IsCarAMissionCar(vehicle); }
	bool IsCarAttached(Scripting::Vehicle vehicle) { return Scripting::IsCarAttached(vehicle); }
	bool IsCarDead(Scripting::Vehicle vehicle) { return Scripting::IsCarDead(vehicle); }
	bool IsCarDoorDamaged(Scripting::Vehicle vehicle, Scripting::eVehicleDoor door) { return Scripting::IsCarDoorDamaged(vehicle, door); }
	bool IsCarDoorFullyOpen(Scripting::Vehicle vehicle, Scripting::eVehicleDoor door) { return Scripting::IsCarDoorFullyOpen(vehicle, door); }
	bool IsCarInAirProper(Scripting::Vehicle vehicle) { return Scripting::IsCarInAirProper(vehicle); }
	bool IsCarInArea2D(Scripting::Vehicle vehicle, f32 x1, f32 y1, f32 x2, f32 y2, bool unknownFalse) { return Scripting::IsCarInArea2D(vehicle, x1, y1, x2, y2, unknownFalse); }
	bool IsCarInArea3D(Scripting::Vehicle vehicle, f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, u8 unknownFalse) { return Scripting::IsCarInArea3D(vehicle, x1, y1, z1, x2, y2, z2, unknownFalse); }
	bool IsCarInWater(Scripting::Vehicle vehicle) { return Scripting::IsCarInWater(vehicle); }
	bool IsCarModel(Scripting::Vehicle vehicle, Scripting::eModel model) { return Scripting::IsCarModel(vehicle, model); }
	bool IsCarOnFire(Scripting::Vehicle vehicle) { return Scripting::IsCarOnFire(vehicle); }
	bool IsCarOnScreen(Scripting::Vehicle vehicle) { return Scripting::IsCarOnScreen(vehicle); }
	bool IsCarPassengerSeatFree(Scripting::Vehicle vehicle, u32 seatIndex) { return Scripting::IsCarPassengerSeatFree(vehicle, seatIndex); }
	bool IsCarSirenOn(Scripting::Vehicle vehicle) { return Scripting::IsCarSirenOn(vehicle); }
	bool IsCarStopped(Scripting::Vehicle vehicle) { return Scripting::IsCarStopped(vehicle); }
	bool IsCarStoppedAtTrafficLights(Scripting::Vehicle vehicle) { return Scripting::IsCarStoppedAtTrafficLights(vehicle); }
	bool IsCarStuckOnRoof(Scripting::Vehicle vehicle) { return Scripting::IsCarStuckOnRoof(vehicle); }
	bool IsCarTouchingCar(Scripting::Vehicle vehicle, Scripting::Vehicle otherCar) { return Scripting::IsCarTouchingCar(vehicle, otherCar); }
	bool IsCarTyreBurst(Scripting::Vehicle vehicle, Scripting::eVehicleTyre tyre) { return Scripting::IsCarTyreBurst(vehicle, tyre); }
	bool IsCarUpright(Scripting::Vehicle vehicle) { return Scripting::IsCarUpright(vehicle); }
	bool IsCarUpsidedown(Scripting::Vehicle vehicle) { return Scripting::IsCarUpsidedown(vehicle); }
	bool IsCarWaitingForWorldCollision(Scripting::Vehicle vehicle) { return Scripting::IsCarWaitingForWorldCollision(vehicle); }
	bool IsVehDriveable(Scripting::Vehicle vehicle) { return Scripting::IsVehDriveable(vehicle); }
	bool IsVehWindowIntact(Scripting::Vehicle vehicle, Scripting::eVehicleWindow window) { return Scripting::IsVehWindowIntact(vehicle, window); }
	bool IsVehicleExtraTurnedOn(Scripting::Vehicle vehicle, Scripting::eVehicleExtra extra) { return Scripting::IsVehicleExtraTurnedOn(vehicle, extra); }
	bool IsVehicleOnAllWheels(Scripting::Vehicle vehicle) { return Scripting::IsVehicleOnAllWheels(vehicle); }
	void KnockPedOffBike(Scripting::Vehicle vehicle) { Scripting::KnockPedOffBike(vehicle); }
	void LockCarDoors(Scripting::Vehicle vehicle, Scripting::eVehicleDoorLock value) { Scripting::LockCarDoors(vehicle, value); }
	void MarkCarAsConvoyCar(Scripting::Vehicle vehicle, bool convoyCar) { Scripting::MarkCarAsConvoyCar(vehicle, convoyCar); }
	void MarkCarAsNoLongerNeeded(Scripting::Vehicle *pVehicle) { Scripting::MarkCarAsNoLongerNeeded(pVehicle); }
	void OpenCarDoor(Scripting::Vehicle vehicle, Scripting::eVehicleDoor door) { Scripting::OpenCarDoor(vehicle, door); }
	void PopCarBoot(Scripting::Vehicle vehicle) { Scripting::PopCarBoot(vehicle); }
	void RemoveVehicleWindow(Scripting::Vehicle vehicle, Scripting::eVehicleWindow window) { Scripting::RemoveVehicleWindow(vehicle, window); }
	void RemoveStuckCarCheck(Scripting::Vehicle vehicle) { Scripting::RemoveStuckCarCheck(vehicle); }
	void RemoveUpsidedownCarCheck(Scripting::Vehicle vehicle) { Scripting::RemoveUpsidedownCarCheck(vehicle); }
	void SetCarCoordinates(Scripting::Vehicle vehicle, f32 pX, f32 pY, f32 pZ) { Scripting::SetCarCoordinates(vehicle, pX, pY, pZ); }
	void SetCarHealth(Scripting::Vehicle vehicle, u32 pValue) { Scripting::SetCarHealth(vehicle, pValue); }
	void SetPetrolTankHealth(Scripting::Vehicle vehicle, f32 value) { Scripting::SetPetrolTankHealth(vehicle, value); }
	void SetCarCanBeDamaged(Scripting::Vehicle vehicle, bool value) { Scripting::SetCarCanBeDamaged(vehicle, value); }
	void SetCarCanBeVisiblyDamaged(Scripting::Vehicle vehicle, bool value) { Scripting::SetCarCanBeVisiblyDamaged(vehicle, value); }
	void SetCarForwardSpeed(Scripting::Vehicle vehicle, f32 speed) { Scripting::SetCarForwardSpeed(vehicle, speed); }
	void SetCarHeading(Scripting::Vehicle vehicle, f32 dir) { Scripting::SetCarHeading(vehicle, dir); }
	Scripting::ScriptAny SetCarOnGroundProperly(Scripting::Vehicle vehicle) { return Scripting::SetCarOnGroundProperly(vehicle); }
	void SetCarProofs(Scripting::Vehicle vehicle, bool bulletProof, bool fireProof, bool explosionProof, bool collisionProof, bool meleeProof) { Scripting::SetCarProofs(vehicle, bulletProof, fireProof, explosionProof, collisionProof, meleeProof); }
	void SetCarStrong(Scripting::Vehicle vehicle, bool strong) { Scripting::SetCarStrong(vehicle, strong); }
	void SetCarVisible(Scripting::Vehicle vehicle, bool value) { Scripting::SetCarVisible(vehicle, value); }
	void SetExtraCarColours(Scripting::Vehicle vehicle, Scripting::ColourIndex colour1, Scripting::ColourIndex colour2) { Scripting::SetExtraCarColours(vehicle, colour1, colour2); }
	void SetEngineHealth(Scripting::Vehicle vehicle, f32 health) { Scripting::SetEngineHealth(vehicle, health); }
	void SetVehHazardLights(Scripting::Vehicle vehicle, bool on) { Scripting::SetVehHazardLights(vehicle, on); }
	void SetVehicleDirtLevel(Scripting::Vehicle vehicle, f32 intensity) { Scripting::SetVehicleDirtLevel(vehicle, intensity); }
	void ShutCarDoor(Scripting::Vehicle vehicle, Scripting::eVehicleDoor door) { Scripting::ShutCarDoor(vehicle, door); }
	void SoundCarHorn(Scripting::Vehicle vehicle, u32 duration) { Scripting::SoundCarHorn(vehicle, duration); }
	void WashVehicleTextures(Scripting::Vehicle vehicle, u32 intensity) { Scripting::WashVehicleTextures(vehicle, intensity); }
};