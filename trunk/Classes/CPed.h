#pragma once
#include "CEntity.h"
#include "CVehicle.h"

class CPed : public CEntity
{
private:
	CVehicle veh;
	Scripting::Ped _ped;

public:
	// Constructor / Destructor
	CPed() {}
	CPed(Scripting::Ped p) { _ped = p; }

	// Operators
	Scripting::Ped operator = (Scripting::Ped ped) { _ped = ped; return _ped; }

	// Helper functions
	CVehicle *CurrentVehicle() { veh.UpdateVehicle(_ped); return &veh; }
	Scripting::Ped GetPed() { return _ped; }
	void SetPed(Scripting::Ped ped) { _ped = ped; }

	// Wrappers
	void AddAmmo(Scripting::eWeapon weapon, u32 amount) { Scripting::AddAmmoToChar(_ped, weapon, amount); }
	void AddArmour(u32 amount) { Scripting::AddArmourToChar(_ped, amount); }
	void ApplyForce(u32 unknown0_3, f32 x, f32 y, f32 z, f32 spinX, f32 spinY, f32 spinZ, u32 unknown4_0, u32 unknown5_1, u32 unknown6_1, u32 unknown7_1) { Scripting::ApplyForceToPed(_ped, unknown0_3, x, y, z, spinX, spinY, spinZ, unknown4_0, unknown5_1, unknown6_1, unknown7_1); }
	void AttachToCar(Scripting::Vehicle vehicle, u32 unknown0_0, f32 offsetX, f32 offsetY, f32 offsetZ, f32 unknown1_276, f32 unknown2_0, u32 unknown3_0, u32 unknown4_0) { Scripting::AttachPedToCar(_ped, vehicle, unknown0_0, offsetX, offsetY, offsetZ, unknown1_276, unknown2_0, unknown3_0, unknown4_0); }
	void BlockCharGestureAnims(bool value) { Scripting::BlockCharGestureAnims(_ped, value); }
	void BlockPedWeaponSwitching(bool value) { Scripting::BlockPedWeaponSwitching(_ped, value); }
	void CancelCurrentlyPlayingAmbientSpeech() { Scripting::CancelCurrentlyPlayingAmbientSpeech(_ped); }
	void ClearAllCharProps() { Scripting::ClearAllCharProps(_ped); }
	void ClearCharLastDamageBone() { Scripting::ClearCharLastDamageBone(_ped); }
	void ClearCharLastDamageEntity() { Scripting::ClearCharLastDamageEntity(_ped); }
	void ClearCharLastWeaponDamage() { Scripting::ClearCharLastWeaponDamage(_ped); }	
	void ClearCharProp(bool unknown) { Scripting::ClearCharProp(_ped, unknown); }
	void ClearCharSecondaryTask() { Scripting::ClearCharSecondaryTask(_ped); }
	void ClearCharTasks() { Scripting::ClearCharTasks(_ped); }
	void ClearCharTasksImmediately() { Scripting::ClearCharTasksImmediately(_ped); }
	void ClearRoomForChar() { Scripting::ClearRoomForChar(_ped); }
	//void CreateChar(u32 type, Scripting::eModel model, f32 x, f32 y, f32 z, Scripting::Ped *pPed, bool unknownTrue) { Scripting::CreateChar(type, model, x, y, z, pPed, unknownTrue); }
	//void CreateRandomChar(f32 x, f32 y, f32 z, Scripting::Ped *pPed) { Scripting::CreateRandomChar(x, y, z, pPed); }
	//void CreateRandomCharAsDriver(Scripting::Vehicle vehicle, Scripting::Ped *pPed) { Scripting::CreateRandomCharAsDriver(vehicle, pPed); }
	//void CreateRandomFemaleChar(f32 x, f32 y, f32 z, Scripting::Ped *pPed) { Scripting::CreateRandomFemaleChar(x, y, z, pPed); }
	//void CreateRandomMaleChar(f32 x, f32 y, f32 z, Scripting::Ped *pPed) { Scripting::CreateRandomMaleChar(x, y, z, pPed); }
	void DamageChar(u32 hitPoints, bool unknown) { Scripting::DamageChar(_ped, hitPoints, unknown); }
	void DamagePedBodyPart(Scripting::ePedBodyPart part, u32 hitPoints) { Scripting::DamagePedBodyPart(_ped, part, hitPoints); }
	//void DeleteChar(Scripting::Ped *pPed) { Scripting::DeleteChar(pPed); }
	void Detach(bool unknown) { Scripting::DetachPed(_ped, unknown); }
	void DetachFromWithinCar(bool unknown) { Scripting::DetachPedFromWithinCar(_ped, unknown); }
	bool DoesExist() { return Scripting::DoesCharExist(_ped); }
	void DropObject(bool unknownTrue) { Scripting::DropObject(_ped, unknownTrue); }
	void ExplodeHead() { Scripting::ExplodeCharHead(_ped); }
	void ExtinguishCharFire() { Scripting::ExtinguishCharFire(_ped); }
	void FireWeapon(f32 x, f32 y, f32 z) { Scripting::FirePedWeapon(_ped, x, y, z); }
	void ForceCharToDropWeapon() { Scripting::ForceCharToDropWeapon(_ped); }
	Scripting::ScriptAny ForcePedPinnedDown(bool force, u32 timerMaybe) { return Scripting::ForcePedPinnedDown(_ped, force, timerMaybe); }
	void ForcePedToFleeWhilstDrivingVehicle(Scripting::Vehicle vehicle) { Scripting::ForcePedToFleeWhilstDrivingVehicle(_ped, vehicle); }
	void FreezeCharPosition(bool frozen) { Scripting::FreezeCharPosition(_ped, frozen); }
	void FreezeCharPositionAndDontLoadCollision(bool frozen) { Scripting::FreezeCharPositionAndDontLoadCollision(_ped, frozen); }
	u32 GetAmmoInWeapon(Scripting::eWeapon weapon) { u32 ammo; Scripting::GetAmmoInCharWeapon(_ped, weapon, &ammo); return ammo; }
	u32 GetAmmoInClip(Scripting::eWeapon weapon) { u32 ammo; Scripting::GetAmmoInClip(_ped, weapon, &ammo); return ammo; }
	const char *GetAnimGroup() { return Scripting::GetAnimGroupFromChar(_ped); }
	Scripting::Vector3 GetCoordinates() { Scripting::Vector3 loc; Scripting::GetCharCoordinates(_ped, &loc.X, &loc.Y, &loc.Z); return loc; }
	u32 GetHealth() { u32 health; Scripting::GetCharHealth(_ped, &health); return health; }
	f32 GetAnimCurrentTime(const char *animGroup, const char *animName) { f32 value; Scripting::GetCharAnimCurrentTime(_ped, animGroup, animName, &value); return value; }
	f32 GetAnimTotalTime(const char *animGroup, const char *animName) { f32 value; Scripting::GetCharAnimTotalTime(_ped, animGroup, animName, &value); return value; }
	u32 GetArmour() { u32 armour; Scripting::GetCharArmour(_ped, &armour); return armour; }
	Scripting::Vehicle GetVehicle() { Scripting::Vehicle v; Scripting::GetCarCharIsUsing(_ped, &v); return v; }
	u32 GetDrawableVariation(Scripting::ePedComponent component) { return Scripting::GetCharDrawableVariation(_ped, component); }
	Scripting::Vector3 GetExtractedDisplacement(bool unknown) { Scripting::Vector3 loc; Scripting::GetCharExtractedDisplacement(_ped, unknown, &loc.X, &loc.Y, &loc.Z); return loc; }
	f32 GetHeading() { f32 value; Scripting::GetCharHeading(_ped, &value); return value; }
	f32 GetHeightAboveGround() { f32 value; Scripting::GetCharHeightAboveGround(_ped, &value); return value; }
	Scripting::ScriptAny GetLastDamageBone(Scripting::ePedBone *pBone) { return Scripting::GetCharLastDamageBone(_ped, pBone); }
	bool GetMeleeActionFlag0() { return Scripting::GetCharMeleeActionFlag0(_ped); }
	bool GetMeleeActionFlag1() { return Scripting::GetCharMeleeActionFlag1(_ped); }
	Scripting::eModel GetModel() { Scripting::eModel model; Scripting::GetCharModel(_ped, &model); return model; }
	u32 GetMoney() { return Scripting::GetCharMoney(_ped); }
	u32 GetPropIndex(bool unknown) { u32 index; Scripting::GetCharPropIndex(_ped, unknown, &index); return index; }
	bool IsReadyToBeExecuted() { return Scripting::GetCharReadyToBeExecuted(_ped); }
	bool IsReadyToBeStunned() { return Scripting::GetCharReadyToBeStunned(_ped); }
	f32 GetSpeed() { f32 speed; Scripting::GetCharSpeed(_ped, &speed); return speed; }
	u32 GetTextureVariation(Scripting::ePedComponent component) { return Scripting::GetCharTextureVariation(_ped, component); }
	Scripting::Vector3 GetVelocity() { Scripting::Vector3 v; Scripting::GetCharVelocity(_ped, &v.X, &v.Y, &v.Z); return v; }
	void GetWeaponInSlot(Scripting::eWeaponSlot slot, Scripting::eWeapon *pWeapon, Scripting::ScriptAny *pUnknown1, Scripting::ScriptAny *pUnknown2) { Scripting::GetCharWeaponInSlot(_ped, slot, pWeapon, pUnknown1, pUnknown2); }
	bool GetWillCowerInsteadOfFleeing() { return Scripting::GetCharWillCowerInsteadOfFleeing(_ped); }
	Scripting::eWeapon GetCurrentWeapon() { Scripting::eWeapon wep; Scripting::GetCurrentCharWeapon(_ped, &wep); return wep; }
	u32 GetDamageToBodyPart(Scripting::ePedBodyPart part) { return Scripting::GetDamageToPedBodyPart(_ped, part); }
	Scripting::Vector3 GetDeadCharCoordinates() { Scripting::Vector3 loc; Scripting::GetDeadCharCoordinates(_ped, &loc.X, &loc.Y, &loc.Z); return loc; }
	Scripting::Vector3 GetDeadCharPickupCoords() { Scripting::Vector3 loc; Scripting::GetDeadCharPickupCoords(_ped, &loc.X, &loc.Y, &loc.Z); return loc; }
	Scripting::eInteriorRoomKey GetKeyForCharInRoom() { Scripting::eInteriorRoomKey key; Scripting::GetKeyForCharInRoom(_ped, &key); return key; }
	u32 GetMaxAmmo(Scripting::eWeapon weapon) { u32 MaxAmmo; Scripting::GetMaxAmmo(_ped, weapon, &MaxAmmo); return MaxAmmo; }
	u32 GetMaxAmmoInClip(Scripting::eWeapon weapon) { u32 MaxAmmo; Scripting::GetMaxAmmoInClip(_ped, weapon, &MaxAmmo); return MaxAmmo; }
	u32 GetNumberOfDrawableVariations(Scripting::ePedComponent component) { return Scripting::GetNumberOfCharDrawableVariations(_ped, component); }
	u32 GetNumberOfTextureVariations(Scripting::ePedComponent component, u32 unknown1) { return Scripting::GetNumberOfCharTextureVariations(_ped, component, unknown1); }
	Scripting::Object GetObjectPedIsHolding() { return Scripting::GetObjectPedIsHolding(_ped); }
	Scripting::Vector3 GetOffsetFromCharInWorldCoords(f32 x, f32 y, f32 z) { Scripting::Vector3 offset; Scripting::GetOffsetFromCharInWorldCoords(_ped, x, y, z, &offset.X, &offset.Y, &offset.Z); return offset; }
	Scripting::ePedClimbState GetPedClimbState() { return Scripting::GetPedClimbState(_ped); }
	Scripting::Vector3 GetPedBonePosition(Scripting::ePedBone bone, f32 x, f32 y, f32 z) { Scripting::Vector3 pos; Scripting::GetPedBonePosition(_ped, bone, x, y, z, &pos); return pos; }
	u32 GetPedGroupIndex() { u32 index; Scripting::GetPedGroupIndex(_ped, &index); return index; }
	Scripting::ePedType GetPedType() { Scripting::ePedType type; Scripting::GetPedType(_ped, &type); return type; }
	void GivePedHelmet() { Scripting::GivePedHelmet(_ped); }
	void GiveWeaponToChar(Scripting::eWeapon weapon, u32 ammo, bool unknown0) { Scripting::GiveWeaponToChar(_ped, weapon, ammo, unknown0); }
	bool HasCharBeenDamagedByCar(Scripting::Vehicle vehicle) { return Scripting::HasCharBeenDamagedByCar(_ped, vehicle); }
	bool HasCharBeenDamagedByChar(Scripting::Ped otherChar, bool unknownFalse) { return Scripting::HasCharBeenDamagedByChar(_ped, otherChar, unknownFalse); }
	bool HasCharBeenDamagedByWeapon(Scripting::eWeapon weapon) { return Scripting::HasCharBeenDamagedByWeapon(_ped, weapon); }
	bool HasCharGotWeapon(Scripting::eWeapon weapon) { return Scripting::HasCharGotWeapon(_ped, weapon); }
	bool HasCharSpottedChar(Scripting::Ped otherChar) { return Scripting::HasCharSpottedChar(_ped, otherChar); }
	bool HasCharSpottedCharInFront(Scripting::Ped otherChar) { return Scripting::HasCharSpottedCharInFront(_ped, otherChar); }
	bool IsAmbientSpeechPlaying() { return Scripting::IsAmbientSpeechPlaying(_ped); }
	bool IsCharArmed(Scripting::eWeaponSlot slot) { return Scripting::IsCharArmed(_ped, slot); }
	bool IsCharDead() { return Scripting::IsCharDead(_ped); }
	bool IsCharDucking() { return Scripting::IsCharDucking(_ped); }
	bool IsCharFacingChar(Scripting::Ped otherChar, f32 angle) { return Scripting::IsCharFacingChar(_ped, otherChar, angle); }
	bool IsCharFatallyInjured() { return Scripting::IsCharFatallyInjured(_ped); }
	bool IsCharGesturing() { return Scripting::IsCharGesturing(_ped); }
	bool IsCharGettingInToACar() { return Scripting::IsCharGettingInToACar(_ped); }
	bool IsCharGettingUp() { return Scripting::IsCharGettingUp(_ped); }
	bool IsCharHealthGreater(u32 health) { return Scripting::IsCharHealthGreater(_ped, health); }
	bool IsCharInAir() { return Scripting::IsCharInAir(_ped); }
	bool IsCharInAngledArea2D(f32 x1, f32 y1, f32 x2, f32 y2, f32 unknown, bool unknownFalse) { return Scripting::IsCharInAngledArea2D(_ped, x1, y1, x2, y2, unknown, unknownFalse); }
	bool IsCharInAngledArea3D(f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, f32 unknown, bool unknownFalse) { return Scripting::IsCharInAngledArea3D(_ped, x1, y1, z1, x2, y2, z2, unknown, unknownFalse); }
	bool IsCharInAnyBoat() { return Scripting::IsCharInAnyBoat(_ped); }
	bool IsCharInAnyCar() { return Scripting::IsCharInAnyCar(_ped); }
	bool IsCharInAnyHeli() { return Scripting::IsCharInAnyHeli(_ped); }
	bool IsCharInAnyPlane() { return Scripting::IsCharInAnyPlane(_ped); }
	bool IsCharInAnyPoliceVehicle() { return Scripting::IsCharInAnyPoliceVehicle(_ped); }
	bool IsCharInAnyTrain() { return Scripting::IsCharInAnyTrain(_ped); }
	bool IsCharInArea2D(f32 x1, f32 y1, f32 x2, f32 y2, bool unknownFalse) { return Scripting::IsCharInArea2D(_ped, x1, y1, x2, y2, unknownFalse); }
	bool IsCharInArea3D(f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, bool unknownFalse) { return Scripting::IsCharInArea3D(_ped, x1, y1, z1, x2, y2, z2, unknownFalse); }
	bool IsCharInAreaOnFoot2D(f32 x1, f32 y1, f32 x2, f32 y2, bool unknownFalse) { return Scripting::IsCharInAreaOnFoot2D(_ped, x1, y1, x2, y2, unknownFalse); }
	bool IsCharInCar(Scripting::Vehicle vehicle) { return Scripting::IsCharInCar(_ped, vehicle); }
	bool IsCharInFlyingVehicle() { return Scripting::IsCharInFlyingVehicle(_ped); }
	bool IsCharInMeleeCombat() { return Scripting::IsCharInMeleeCombat(_ped); }
	bool IsCharInModel(Scripting::eModel model) { return Scripting::IsCharInModel(_ped, model); }
	bool IsCharInTaxi() { return Scripting::IsCharInTaxi(_ped); }
	bool IsCharInWater() { return Scripting::IsCharInWater(_ped); }
	bool IsCharInjured() { return Scripting::IsCharInjured(_ped); }
	bool IsCharMale() { return Scripting::IsCharMale(_ped); }
	bool IsCharModel(Scripting::eModel model) { return Scripting::IsCharModel(_ped, model); }
	bool IsCharOnAnyBike() { return Scripting::IsCharOnAnyBike(_ped); }
	bool IsCharOnFire() { return Scripting::IsCharOnFire(_ped); }
	bool IsCharOnFoot() { return Scripting::IsCharOnFoot(_ped); }
	bool IsCharOnScreen() { return Scripting::IsCharOnScreen(_ped); }
	bool IsCharPlayingAnim(char *animSet, char *animName) { return Scripting::IsCharPlayingAnim(_ped, animSet, animName); }
	bool IsCharShooting() { return Scripting::IsCharShooting(_ped); }
	bool IsCharShootingInArea(f32 x1, f32 y1, f32 x2, f32 y2, bool unknownFalse) { return Scripting::IsCharShootingInArea(_ped, x1, y1, x2, y2, unknownFalse); }
	bool IsCharSittingIdle() { return Scripting::IsCharSittingIdle(_ped); }
	bool IsCharSittingInAnyCar() { return Scripting::IsCharSittingInAnyCar(_ped); }
	bool IsCharSittingInCar(Scripting::Vehicle vehicle) { return Scripting::IsCharSittingInCar(_ped, vehicle); }
	bool IsCharStopped() { return Scripting::IsCharStopped(_ped); }
	bool IsCharStuckUnderCar() { return Scripting::IsCharStuckUnderCar(_ped); }
	bool IsCharSwimming() { return Scripting::IsCharSwimming(_ped); }
	bool IsCharTouchingChar(Scripting::Ped otherChar) { return Scripting::IsCharTouchingChar(_ped, otherChar); }
	bool IsCharTouchingObject(Scripting::Object obj) { return Scripting::IsCharTouchingObject(_ped, obj); }
	bool IsCharTouchingObjectOnFoot(Scripting::Object obj) { return Scripting::IsCharTouchingObjectOnFoot(_ped, obj); }
	bool IsCharTouchingVehicle(Scripting::ScriptAny p0, Scripting::ScriptAny p1) { return Scripting::IsCharTouchingVehicle(p0, p1); }
	bool IsCharTryingToEnterALockedCar() { return Scripting::IsCharTryingToEnterALockedCar(_ped); }
	bool IsCharUsingAnyScenario() { return Scripting::IsCharUsingAnyScenario(_ped); }
	bool IsCharUsingScenario(const char *scenarioName) { return Scripting::IsCharUsingScenario(_ped, scenarioName); }
	bool IsCharVisible() { return Scripting::IsCharVisible(_ped); }
	bool IsCharWaitingForWorldCollision() { return Scripting::IsCharWaitingForWorldCollision(_ped); }
	bool IsPedAMissionPed() { return Scripting::IsPedAMissionPed(_ped); }
	bool IsPedAttachedToAnyCar() { return Scripting::IsPedAttachedToAnyCar(_ped); }
	bool IsPedAttachedToObject(Scripting::Object obj) { return Scripting::IsPedAttachedToObject(_ped, obj); }
	bool IsPedBeingJacked() { return Scripting::IsPedBeingJacked(_ped); }
	bool IsPedDoingDriveby() { return Scripting::IsPedDoingDriveby(_ped); }
	bool IsPedFleeing() { return Scripting::IsPedFleeing(_ped); }
	bool IsPedHoldingAnObject() { return Scripting::IsPedHoldingAnObject(_ped); }
	bool IsPedInCombat() { return Scripting::IsPedInCombat(_ped); }
	bool IsPedInCover() { return Scripting::IsPedInCover(_ped); }
	bool IsPedInGroup() { return Scripting::IsPedInGroup(_ped); }
	bool IsPedJacking() { return Scripting::IsPedJacking(_ped); }
	bool IsPedLookingAtPed(Scripting::Ped otherChar) { return Scripting::IsPedLookingAtPed(_ped, otherChar); }
	bool IsPedRagdoll() { return Scripting::IsPedRagdoll(_ped); }
	bool IsPedRetreating() { return Scripting::IsPedRetreating(_ped); }
	bool IsScriptedSpeechPlaying() { return Scripting::IsScriptedSpeechPlaying(_ped); }
	void MarkCharAsNoLongerNeeded() { Scripting::MarkCharAsNoLongerNeeded(&_ped); }
	void ModifyCharMoveState(Scripting::ePedMoveState state) { Scripting::ModifyCharMoveState(_ped, state); }
	void RemoveAllCharWeapons() { Scripting::RemoveAllCharWeapons(_ped); }
	void RemoveCharDefensiveArea() { Scripting::RemoveCharDefensiveArea(_ped); }
	void RemoveCharElegantly() { Scripting::RemoveCharElegantly(_ped); }
	void RemoveCharFromGroup() { Scripting::RemoveCharFromGroup(_ped); }
	void ReviveInjuredPed() { Scripting::ReviveInjuredPed(_ped); }
	void SayAmbientSpeech(char *phraseName, Scripting::ScriptAny unknown0_1, Scripting::ScriptAny unknown1_1, Scripting::ScriptAny unknown2_0) { Scripting::SayAmbientSpeech(_ped, phraseName, unknown0_1, unknown1_1, unknown2_0); }
	Scripting::ScriptAny SetAmmoInClip(Scripting::eWeapon weapon, u32 ammo) { return Scripting::SetAmmoInClip(_ped, weapon, ammo); }
	void SetBlockingOfNonTemporaryEvents(bool value) { Scripting::SetBlockingOfNonTemporaryEvents(_ped, value); }
	void SetCharAccuracy(u32 value) { Scripting::SetCharAccuracy(_ped, value); }
	void SetCharAmmo(Scripting::eWeapon weapon, u32 ammo) { Scripting::SetCharAmmo(_ped, weapon, ammo); }
	void SetCharAsEnemy(bool value) { Scripting::SetCharAsEnemy(_ped, value); }
	void SetCharAsMissionChar() { Scripting::SetCharAsMissionChar(_ped); }
	void SetCharCanBeKnockedOffBike(bool value) { Scripting::SetCharCanBeKnockedOffBike(_ped, value); }
	void SetCharCanBeShotInVehicle(bool enabled) { Scripting::SetCharCanBeShotInVehicle(_ped, enabled); }
	void SetCharCantBeDraggedOut(bool enabled) { Scripting::SetCharCantBeDraggedOut(_ped, enabled); }
	void SetCharComponentVariation(Scripting::ePedComponent component, u32 modelVariation, u32 textureVariation) { Scripting::SetCharComponentVariation(_ped, component, modelVariation, textureVariation); }
	void SetCharCoordinates(f32 x, f32 y, f32 z) { Scripting::SetCharCoordinates(_ped, x, y, z); }
	void SetCharDefaultComponentVariation() { Scripting::SetCharDefaultComponentVariation(_ped); }
	void SetCharDesiredHeading(f32 heading) { Scripting::SetCharDesiredHeading(_ped, heading); }
	void SetCharDropsWeaponsWhenDead(bool value) { Scripting::SetCharDropsWeaponsWhenDead(_ped, value); }
	void SetCharDruggedUp(bool drugged) { Scripting::SetCharDruggedUp(_ped, drugged); }
	void SetCharFireDamageMultiplier(f32 multiplier) { Scripting::SetCharFireDamageMultiplier(_ped, multiplier); }
	void SetCharGravity(f32 value) { Scripting::SetCharGravity(_ped, value); }
	void SetCharHeading(f32 heading) { Scripting::SetCharHeading(_ped, heading); }
	void SetCharHealth(u32 health) { Scripting::SetCharHealth(_ped, health); }
	void SetCharInvincible(bool enable) { Scripting::SetCharInvincible(_ped, enable); }
	void SetCharIsTargetPriority(bool enable) { Scripting::SetCharIsTargetPriority(_ped, enable); }
	void SetCharMaxHealth(u32 value) { Scripting::SetCharMaxHealth(_ped, value); }
	void SetCharMoney(u32 amount) { Scripting::SetCharMoney(_ped, amount); }
	void SetCharNeverLeavesGroup(bool value) { Scripting::SetCharNeverLeavesGroup(_ped, value); }
	void SetCharProofs(bool unknown0, bool fallingDamage, bool unknown1, bool unknown2, bool unknown3) { Scripting::SetCharProofs(_ped, unknown0, fallingDamage, unknown1, unknown2, unknown3); }
	void SetCharPropIndex(Scripting::ePedPropType propType, u32 index) { Scripting::SetCharPropIndex(_ped, propType, index); }
	void SetCharRandomComponentVariation() { Scripting::SetCharRandomComponentVariation(_ped); }
	void SetCharSphereDefensiveArea(f32 x, f32 y, f32 z, f32 radius) { Scripting::SetCharSphereDefensiveArea(_ped, x, y, z, radius); }
	void SetCharSuffersCriticalHits(bool value) { Scripting::SetCharSuffersCriticalHits(_ped, value); }
	void SetCharVelocity(f32 x, f32 y, f32 z) { Scripting::SetCharVelocity(_ped, x, y, z); }
	void SetCharVisible(bool value) { Scripting::SetCharVisible(_ped, value); }
	void SetCharWantedByPolice(bool wanted) { Scripting::SetCharWantedByPolice(_ped, wanted); }
	void SetCharWillDoDrivebys(bool value) { Scripting::SetCharWillDoDrivebys(_ped, value); }
	void SetCharWillFlyThroughWindscreen(bool value) { Scripting::SetCharWillFlyThroughWindscreen(_ped, value); }
	void SetCharWillMoveWhenInjured(bool value) { Scripting::SetCharWillMoveWhenInjured(_ped, value); }
	void SetCharWillUseCarsInCombat(bool value) { Scripting::SetCharWillUseCarsInCombat(_ped, value); }
	void SetCharWillUseCover(Scripting::CoverPoint coverPoint) { Scripting::SetCharWillUseCover(_ped, coverPoint); }
	void SetCurrentCharWeapon(Scripting::eWeapon w, bool unknownTrue) { Scripting::SetCurrentCharWeapon(_ped, w, unknownTrue); }
	void SetGroupCharDucksWhenAimedAt(bool value) { Scripting::SetGroupCharDucksWhenAimedAt(_ped, value); }
	void SetIgnoreLowPriorityShockingEvents(bool value) { Scripting::SetIgnoreLowPriorityShockingEvents(_ped, value); }
	void SetPedDiesWhenInjured(bool value) { Scripting::SetPedDiesWhenInjured(_ped, value); }
	void SetPedIsBlindRaging(bool value) { Scripting::SetPedIsBlindRaging(_ped, value); }
	void SetPedIsDrunk(bool value) { Scripting::SetPedIsDrunk(_ped, value); }
	void SetPedPathMayDropFromHeight(bool value) { Scripting::SetPedPathMayDropFromHeight(_ped, value); }
	void SetPedPathMayUseClimbovers(bool value) { Scripting::SetPedPathMayUseClimbovers(_ped, value); }
	void SetPedPathMayUseLadders(bool value) { Scripting::SetPedPathMayUseLadders(_ped, value); }
	void SetRoomForCharByKey(Scripting::eInteriorRoomKey key) { Scripting::SetRoomForCharByKey(_ped, key); }
	void SetSenseRange(f32 value) { Scripting::SetSenseRange(_ped, value); }
	void SwitchPedToAnimated(bool unknownTrue) { Scripting::SwitchPedToAnimated(_ped ,unknownTrue); }
	Scripting::ScriptAny SwitchPedToRagdoll(Scripting::ScriptAny p1, Scripting::ScriptAny p2, Scripting::ScriptAny p3, Scripting::ScriptAny p4, Scripting::ScriptAny p5, Scripting::ScriptAny p6) { return Scripting::SwitchPedToRagdoll(_ped, p1, p2, p3, p4, p5, p6); }    
	void RemovePedHelmet(bool removed) { Scripting::RemovePedHelmet(_ped, removed); }
	void RemoveWeaponFromChar(Scripting::eWeapon weapon) { Scripting::RemoveWeaponFromChar(_ped, weapon); }
	void UnlockRagdoll(bool value) { Scripting::UnlockRagdoll(_ped, value); }
	void WarpCharFromCarToCoord(f32 x, f32 y, f32 z) { Scripting::WarpCharFromCarToCoord(_ped, x, y, z); }
	void WarpCharIntoCar(Scripting::Vehicle vehicle) { Scripting::WarpCharIntoCar(_ped, vehicle); }
	void WarpCharIntoCarAsPassenger(Scripting::Vehicle vehicle, u32 seatIndex) { Scripting::WarpCharIntoCarAsPassenger(_ped, vehicle, seatIndex); }
	void WarpCharFromCarToCar(Scripting::Vehicle vehicle, u32 seatIndex) { Scripting::WarpCharFromCarToCar(_ped, vehicle, seatIndex); }
};