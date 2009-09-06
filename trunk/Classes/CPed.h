#pragma once
#include "CEntity.h"

class CPed : public CEntity
{
private:
	Scripting::Ped _ped;

public:
	// Constructor / Destructor
	CPed() {}
	CPed(Scripting::Ped p) { _ped = p; }
	CPed operator = (Scripting::Ped ped) { _ped = ped; return _ped; }

	// Helper functions
	void SetCoordinates(f32 X, f32 Y, f32 Z) { Scripting::SetCharCoordinates(_ped, X, Y, Z); }

	// Wrappers
	virtual void AddAmmo(Scripting::eWeapon weapon, u32 amount) { Scripting::AddAmmoToChar(_ped, weapon, amount); }
	virtual void AddArmour(u32 amount) { Scripting::AddArmourToChar(_ped, amount); }
	virtual void ApplyForce(u32 unknown0_3, f32 x, f32 y, f32 z, f32 spinX, f32 spinY, f32 spinZ, u32 unknown4_0, u32 unknown5_1, u32 unknown6_1, u32 unknown7_1) { Scripting::ApplyForceToPed(_ped, unknown0_3, x, y, z, spinX, spinY, spinZ, unknown4_0, unknown5_1, unknown6_1, unknown7_1); }
	virtual void AttachToCar(Scripting::Vehicle vehicle, u32 unknown0_0, f32 offsetX, f32 offsetY, f32 offsetZ, f32 unknown1_276, f32 unknown2_0, u32 unknown3_0, u32 unknown4_0) { Scripting::AttachPedToCar(_ped, vehicle, unknown0_0, offsetX, offsetY, offsetZ, unknown1_276, unknown2_0, unknown3_0, unknown4_0); }
	virtual void BlockCharGestureAnims(bool value) { Scripting::BlockCharGestureAnims(_ped, value); }
	virtual void BlockPedWeaponSwitching(bool value) { Scripting::BlockPedWeaponSwitching(_ped, value); }
	virtual void CancelCurrentlyPlayingAmbientSpeech() { Scripting::CancelCurrentlyPlayingAmbientSpeech(_ped); }
	virtual void ClearAllCharProps() { Scripting::ClearAllCharProps(_ped); }
	virtual void ClearCharLastDamageBone() { Scripting::ClearCharLastDamageBone(_ped); }
	virtual void ClearCharLastDamageEntity() { Scripting::ClearCharLastDamageEntity(_ped); }
	virtual void ClearCharLastWeaponDamage() { Scripting::ClearCharLastWeaponDamage(_ped); }	
	virtual void ClearCharProp(bool unknown) { Scripting::ClearCharProp(_ped, unknown); }
	virtual void ClearCharSecondaryTask() { Scripting::ClearCharSecondaryTask(_ped); }
	virtual void ClearCharTasks() { Scripting::ClearCharTasks(_ped); }
	virtual void ClearCharTasksImmediately() { Scripting::ClearCharTasksImmediately(_ped); }
	virtual void ClearRoomForChar() { Scripting::ClearRoomForChar(_ped); }
	//virtual void CreateChar(u32 type, Scripting::eModel model, f32 x, f32 y, f32 z, Scripting::Ped *pPed, bool unknownTrue) { Scripting::CreateChar(type, model, x, y, z, pPed, unknownTrue); }
	//virtual void CreateRandomChar(f32 x, f32 y, f32 z, Scripting::Ped *pPed) { Scripting::CreateRandomChar(x, y, z, pPed); }
	//virtual void CreateRandomCharAsDriver(Scripting::Vehicle vehicle, Scripting::Ped *pPed) { Scripting::CreateRandomCharAsDriver(vehicle, pPed); }
	//virtual void CreateRandomFemaleChar(f32 x, f32 y, f32 z, Scripting::Ped *pPed) { Scripting::CreateRandomFemaleChar(x, y, z, pPed); }
	//virtual void CreateRandomMaleChar(f32 x, f32 y, f32 z, Scripting::Ped *pPed) { Scripting::CreateRandomMaleChar(x, y, z, pPed); }
	virtual void DamageChar(u32 hitPoints, bool unknown) { Scripting::DamageChar(_ped, hitPoints, unknown); }
	virtual void DamagePedBodyPart(Scripting::ePedBodyPart part, u32 hitPoints) { Scripting::DamagePedBodyPart(_ped, part, hitPoints); }
	//virtual void DeleteChar(Scripting::Ped *pPed) { Scripting::DeleteChar(pPed); }
	virtual void Detach(bool unknown) { Scripting::DetachPed(_ped, unknown); }
	virtual void DetachFromWithinCar(bool unknown) { Scripting::DetachPedFromWithinCar(_ped, unknown); }
	virtual bool DoesExist() { return Scripting::DoesCharExist(_ped); }
	virtual void DropObject(bool unknownTrue) { Scripting::DropObject(_ped, unknownTrue); }
	virtual void ExplodeHead() { Scripting::ExplodeCharHead(_ped); }
	virtual void ExtinguishCharFire() { Scripting::ExtinguishCharFire(_ped); }
	virtual void FireWeapon(f32 x, f32 y, f32 z) { Scripting::FirePedWeapon(_ped, x, y, z); }
	virtual void ForceCharToDropWeapon() { Scripting::ForceCharToDropWeapon(_ped); }
	virtual Scripting::ScriptAny ForcePedPinnedDown(bool force, u32 timerMaybe) { return Scripting::ForcePedPinnedDown(_ped, force, timerMaybe); }
	virtual void ForcePedToFleeWhilstDrivingVehicle(Scripting::Vehicle vehicle) { Scripting::ForcePedToFleeWhilstDrivingVehicle(_ped, vehicle); }
	virtual void FreezeCharPosition(bool frozen) { Scripting::FreezeCharPosition(_ped, frozen); }
	virtual void FreezeCharPositionAndDontLoadCollision(bool frozen) { Scripting::FreezeCharPositionAndDontLoadCollision(_ped, frozen); }
	virtual u32 GetAmmoInWeapon(Scripting::eWeapon weapon) { u32 ammo; Scripting::GetAmmoInCharWeapon(_ped, weapon, &ammo); return ammo; }
	virtual u32 GetAmmoInClip(Scripting::eWeapon weapon) { u32 ammo; Scripting::GetAmmoInClip(_ped, weapon, &ammo); return ammo; }
	virtual const char *GetAnimGroup() { return Scripting::GetAnimGroupFromChar(_ped); }
	virtual Scripting::Vector3 GetCoordinates() { Scripting::Vector3 loc; Scripting::GetCharCoordinates(_ped, &loc.X, &loc.Y, &loc.Z); return loc; }
	virtual u32 GetHealth() { u32 health; Scripting::GetCharHealth(_ped, &health); return health; }
	virtual f32 GetAnimCurrentTime(const char *animGroup, const char *animName) { f32 value; Scripting::GetCharAnimCurrentTime(_ped, animGroup, animName, &value); return value; }
	virtual f32 GetAnimTotalTime(const char *animGroup, const char *animName) { f32 value; Scripting::GetCharAnimTotalTime(_ped, animGroup, animName, &value); return value; }
	virtual u32 GetArmour() { u32 armour; Scripting::GetCharArmour(_ped, &armour); return armour; }
	virtual u32 GetDrawableVariation(Scripting::ePedComponent component) { return Scripting::GetCharDrawableVariation(_ped, component); }
	virtual Scripting::Vector3 GetExtractedDisplacement(bool unknown) { Scripting::Vector3 loc; Scripting::GetCharExtractedDisplacement(_ped, unknown, &loc.X, &loc.Y, &loc.Z); return loc; }
	virtual f32 GetHeading() { f32 value; Scripting::GetCharHeading(_ped, &value); return value; }
	virtual f32 GetHeightAboveGround() { f32 value; Scripting::GetCharHeightAboveGround(_ped, &value); return value; }
	virtual Scripting::ScriptAny GetLastDamageBone(Scripting::ePedBone *pBone) { return Scripting::GetCharLastDamageBone(_ped, pBone); }
	virtual bool GetMeleeActionFlag0() { return Scripting::GetCharMeleeActionFlag0(_ped); }
	virtual bool GetMeleeActionFlag1() { return Scripting::GetCharMeleeActionFlag1(_ped); }
	virtual Scripting::eModel GetModel() { Scripting::eModel model; Scripting::GetCharModel(_ped, &model); return model; }
	virtual u32 GetMoney() { return Scripting::GetCharMoney(_ped); }
	virtual u32 GetPropIndex(bool unknown) { u32 index; Scripting::GetCharPropIndex(_ped, unknown, &index); return index; }
	virtual bool IsReadyToBeExecuted() { return Scripting::GetCharReadyToBeExecuted(_ped); }
	virtual bool IsReadyToBeStunned() { return Scripting::GetCharReadyToBeStunned(_ped); }
	virtual f32 GetSpeed() { f32 speed; Scripting::GetCharSpeed(_ped, &speed); return speed; }
	virtual u32 GetTextureVariation(Scripting::ePedComponent component) { return Scripting::GetCharTextureVariation(_ped, component); }
	virtual Scripting::Vector3 GetVelocity() { Scripting::Vector3 v; Scripting::GetCharVelocity(_ped, &v.X, &v.Y, &v.Z); return v; }
	virtual void GetWeaponInSlot(Scripting::eWeaponSlot slot, Scripting::eWeapon *pWeapon, Scripting::ScriptAny *pUnknown1, Scripting::ScriptAny *pUnknown2) { Scripting::GetCharWeaponInSlot(_ped, slot, pWeapon, pUnknown1, pUnknown2); }
	virtual bool GetWillCowerInsteadOfFleeing() { return Scripting::GetCharWillCowerInsteadOfFleeing(_ped); }
	virtual Scripting::eWeapon GetCurrentWeapon() { Scripting::eWeapon wep; Scripting::GetCurrentCharWeapon(_ped, &wep); return wep; }
	virtual u32 GetDamageToBodyPart(Scripting::ePedBodyPart part) { return Scripting::GetDamageToPedBodyPart(_ped, part); }
	virtual Scripting::Vector3 GetDeadCharCoordinates() { Scripting::Vector3 loc; Scripting::GetDeadCharCoordinates(_ped, &loc.X, &loc.Y, &loc.Z); return loc; }
	virtual Scripting::Vector3 GetDeadCharPickupCoords() { Scripting::Vector3 loc; Scripting::GetDeadCharPickupCoords(_ped, &loc.X, &loc.Y, &loc.Z); return loc; }
	virtual Scripting::eInteriorRoomKey GetKeyForCharInRoom() { Scripting::eInteriorRoomKey key; Scripting::GetKeyForCharInRoom(_ped, &key); return key; }
	virtual u32 GetMaxAmmo(Scripting::eWeapon weapon) { u32 MaxAmmo; Scripting::GetMaxAmmo(_ped, weapon, &MaxAmmo); return MaxAmmo; }
	virtual u32 GetMaxAmmoInClip(Scripting::eWeapon weapon) { u32 MaxAmmo; Scripting::GetMaxAmmoInClip(_ped, weapon, &MaxAmmo); return MaxAmmo; }
	virtual u32 GetNumberOfDrawableVariations(Scripting::ePedComponent component) { return Scripting::GetNumberOfCharDrawableVariations(_ped, component); }
	virtual u32 GetNumberOfTextureVariations(Scripting::ePedComponent component, u32 unknown1) { return Scripting::GetNumberOfCharTextureVariations(_ped, component, unknown1); }
	virtual Scripting::Object GetObjectPedIsHolding() { return Scripting::GetObjectPedIsHolding(_ped); }
	virtual Scripting::Vector3 GetOffsetFromCharInWorldCoords(f32 x, f32 y, f32 z) { Scripting::Vector3 offset; Scripting::GetOffsetFromCharInWorldCoords(_ped, x, y, z, &offset.X, &offset.Y, &offset.Z); return offset; }
	virtual Scripting::ePedClimbState GetPedClimbState() { return Scripting::GetPedClimbState(_ped); }
	virtual Scripting::Vector3 GetPedBonePosition(Scripting::ePedBone bone, f32 x, f32 y, f32 z) { Scripting::Vector3 pos; Scripting::GetPedBonePosition(_ped, bone, x, y, z, &pos); return pos; }
	virtual u32 GetPedGroupIndex() { u32 index; Scripting::GetPedGroupIndex(_ped, &index); return index; }
	virtual Scripting::ePedType GetPedType() { Scripting::ePedType type; Scripting::GetPedType(_ped, &type); return type; }
	virtual void GivePedHelmet() { Scripting::GivePedHelmet(_ped); }
	virtual void GiveWeaponToChar(Scripting::eWeapon weapon, u32 ammo, bool unknown0) { Scripting::GiveWeaponToChar(_ped, weapon, ammo, unknown0); }
	virtual bool HasCharBeenDamagedByCar(Scripting::Vehicle vehicle) { return Scripting::HasCharBeenDamagedByCar(_ped, vehicle); }
	virtual bool HasCharBeenDamagedByChar(Scripting::Ped otherChar, bool unknownFalse) { return Scripting::HasCharBeenDamagedByChar(_ped, otherChar, unknownFalse); }
	virtual bool HasCharBeenDamagedByWeapon(Scripting::eWeapon weapon) { return Scripting::HasCharBeenDamagedByWeapon(_ped, weapon); }
	virtual bool HasCharGotWeapon(Scripting::eWeapon weapon) { return Scripting::HasCharGotWeapon(_ped, weapon); }
	virtual bool HasCharSpottedChar(Scripting::Ped otherChar) { return Scripting::HasCharSpottedChar(_ped, otherChar); }
	virtual bool HasCharSpottedCharInFront(Scripting::Ped otherChar) { return Scripting::HasCharSpottedCharInFront(_ped, otherChar); }
	virtual bool IsAmbientSpeechPlaying() { return Scripting::IsAmbientSpeechPlaying(_ped); }
	virtual bool IsCharArmed(Scripting::eWeaponSlot slot) { return Scripting::IsCharArmed(_ped, slot); }
	virtual bool IsCharDead() { return Scripting::IsCharDead(_ped); }
	virtual bool IsCharDucking() { return Scripting::IsCharDucking(_ped); }
	virtual bool IsCharFacingChar(Scripting::Ped otherChar, f32 angle) { return Scripting::IsCharFacingChar(_ped, otherChar, angle); }
	virtual bool IsCharFatallyInjured() { return Scripting::IsCharFatallyInjured(_ped); }
	virtual bool IsCharGesturing() { return Scripting::IsCharGesturing(_ped); }
	virtual bool IsCharGettingInToACar() { return Scripting::IsCharGettingInToACar(_ped); }
	virtual bool IsCharGettingUp() { return Scripting::IsCharGettingUp(_ped); }
	virtual bool IsCharHealthGreater(u32 health) { return Scripting::IsCharHealthGreater(_ped, health); }
	virtual bool IsCharInAir() { return Scripting::IsCharInAir(_ped); }
	virtual bool IsCharInAngledArea2D(f32 x1, f32 y1, f32 x2, f32 y2, f32 unknown, bool unknownFalse) { return Scripting::IsCharInAngledArea2D(_ped, x1, y1, x2, y2, unknown, unknownFalse); }
	virtual bool IsCharInAngledArea3D(f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, f32 unknown, bool unknownFalse) { return Scripting::IsCharInAngledArea3D(_ped, x1, y1, z1, x2, y2, z2, unknown, unknownFalse); }
	virtual bool IsCharInAnyBoat() { return Scripting::IsCharInAnyBoat(_ped); }
	virtual bool IsCharInAnyCar() { return Scripting::IsCharInAnyCar(_ped); }
	virtual bool IsCharInAnyHeli() { return Scripting::IsCharInAnyHeli(_ped); }
	virtual bool IsCharInAnyPlane() { return Scripting::IsCharInAnyPlane(_ped); }
	virtual bool IsCharInAnyPoliceVehicle() { return Scripting::IsCharInAnyPoliceVehicle(_ped); }
	virtual bool IsCharInAnyTrain() { return Scripting::IsCharInAnyTrain(_ped); }
	virtual bool IsCharInArea2D(f32 x1, f32 y1, f32 x2, f32 y2, bool unknownFalse) { return Scripting::IsCharInArea2D(_ped, x1, y1, x2, y2, unknownFalse); }
	virtual bool IsCharInArea3D(f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, bool unknownFalse) { return Scripting::IsCharInArea3D(_ped, x1, y1, z1, x2, y2, z2, unknownFalse); }
	virtual bool IsCharInAreaOnFoot2D(f32 x1, f32 y1, f32 x2, f32 y2, bool unknownFalse) { return Scripting::IsCharInAreaOnFoot2D(_ped, x1, y1, x2, y2, unknownFalse); }
	virtual bool IsCharInCar(Scripting::Vehicle vehicle) { return Scripting::IsCharInCar(_ped, vehicle); }
	virtual bool IsCharInFlyingVehicle() { return Scripting::IsCharInFlyingVehicle(_ped); }
	virtual bool IsCharInMeleeCombat() { return Scripting::IsCharInMeleeCombat(_ped); }
	virtual bool IsCharInModel(Scripting::eModel model) { return Scripting::IsCharInModel(_ped, model); }
	virtual bool IsCharInTaxi() { return Scripting::IsCharInTaxi(_ped); }
	virtual bool IsCharInWater() { return Scripting::IsCharInWater(_ped); }
	virtual bool IsCharInjured() { return Scripting::IsCharInjured(_ped); }
	virtual bool IsCharMale() { return Scripting::IsCharMale(_ped); }
	virtual bool IsCharModel(Scripting::eModel model) { return Scripting::IsCharModel(_ped, model); }
	virtual bool IsCharOnAnyBike() { return Scripting::IsCharOnAnyBike(_ped); }
	virtual bool IsCharOnFire() { return Scripting::IsCharOnFire(_ped); }
	virtual bool IsCharOnFoot() { return Scripting::IsCharOnFoot(_ped); }
	virtual bool IsCharOnScreen() { return Scripting::IsCharOnScreen(_ped); }
	virtual bool IsCharPlayingAnim(char *animSet, char *animName) { return Scripting::IsCharPlayingAnim(_ped, animSet, animName); }
	virtual bool IsCharShooting() { return Scripting::IsCharShooting(_ped); }
	virtual bool IsCharShootingInArea(f32 x1, f32 y1, f32 x2, f32 y2, bool unknownFalse) { return Scripting::IsCharShootingInArea(_ped, x1, y1, x2, y2, unknownFalse); }
	virtual bool IsCharSittingIdle() { return Scripting::IsCharSittingIdle(_ped); }
	virtual bool IsCharSittingInAnyCar() { return Scripting::IsCharSittingInAnyCar(_ped); }
	virtual bool IsCharSittingInCar(Scripting::Vehicle vehicle) { return Scripting::IsCharSittingInCar(_ped, vehicle); }
	virtual bool IsCharStopped() { return Scripting::IsCharStopped(_ped); }
	virtual bool IsCharStuckUnderCar() { return Scripting::IsCharStuckUnderCar(_ped); }
	virtual bool IsCharSwimming() { return Scripting::IsCharSwimming(_ped); }
	virtual bool IsCharTouchingChar(Scripting::Ped otherChar) { return Scripting::IsCharTouchingChar(_ped, otherChar); }
	virtual bool IsCharTouchingObject(Scripting::Object obj) { return Scripting::IsCharTouchingObject(_ped, obj); }
	virtual bool IsCharTouchingObjectOnFoot(Scripting::Object obj) { return Scripting::IsCharTouchingObjectOnFoot(_ped, obj); }
	virtual bool IsCharTouchingVehicle(Scripting::ScriptAny p0, Scripting::ScriptAny p1) { return Scripting::IsCharTouchingVehicle(p0, p1); }
	virtual bool IsCharTryingToEnterALockedCar() { return Scripting::IsCharTryingToEnterALockedCar(_ped); }
	virtual bool IsCharUsingAnyScenario() { return Scripting::IsCharUsingAnyScenario(_ped); }
	virtual bool IsCharUsingScenario(const char *scenarioName) { return Scripting::IsCharUsingScenario(_ped, scenarioName); }
	virtual bool IsCharVisible() { return Scripting::IsCharVisible(_ped); }
	virtual bool IsCharWaitingForWorldCollision() { return Scripting::IsCharWaitingForWorldCollision(_ped); }
	virtual bool IsPedAMissionPed() { return Scripting::IsPedAMissionPed(_ped); }
	virtual bool IsPedAttachedToAnyCar() { return Scripting::IsPedAttachedToAnyCar(_ped); }
	virtual bool IsPedAttachedToObject(Scripting::Object obj) { return Scripting::IsPedAttachedToObject(_ped, obj); }
	virtual bool IsPedBeingJacked() { return Scripting::IsPedBeingJacked(_ped); }
	virtual bool IsPedDoingDriveby() { return Scripting::IsPedDoingDriveby(_ped); }
	virtual bool IsPedFleeing() { return Scripting::IsPedFleeing(_ped); }
	virtual bool IsPedHoldingAnObject() { return Scripting::IsPedHoldingAnObject(_ped); }
	virtual bool IsPedInCombat() { return Scripting::IsPedInCombat(_ped); }
	virtual bool IsPedInCover() { return Scripting::IsPedInCover(_ped); }
	virtual bool IsPedInGroup() { return Scripting::IsPedInGroup(_ped); }
	virtual bool IsPedJacking() { return Scripting::IsPedJacking(_ped); }
	virtual bool IsPedLookingAtPed(Scripting::Ped otherChar) { return Scripting::IsPedLookingAtPed(_ped, otherChar); }
	virtual bool IsPedRagdoll() { return Scripting::IsPedRagdoll(_ped); }
	virtual bool IsPedRetreating() { return Scripting::IsPedRetreating(_ped); }
	virtual bool IsScriptedSpeechPlaying() { return Scripting::IsScriptedSpeechPlaying(_ped); }
	virtual void MarkCharAsNoLongerNeeded() { Scripting::MarkCharAsNoLongerNeeded(&_ped); }
	virtual void ModifyCharMoveState(Scripting::ePedMoveState state) { Scripting::ModifyCharMoveState(_ped, state); }
	virtual void RemoveAllCharWeapons() { Scripting::RemoveAllCharWeapons(_ped); }
	virtual void RemoveCharDefensiveArea() { Scripting::RemoveCharDefensiveArea(_ped); }
	virtual void RemoveCharElegantly() { Scripting::RemoveCharElegantly(_ped); }
	virtual void RemoveCharFromGroup() { Scripting::RemoveCharFromGroup(_ped); }
	virtual void ReviveInjuredPed() { Scripting::ReviveInjuredPed(_ped); }
	virtual void SayAmbientSpeech(char *phraseName, Scripting::ScriptAny unknown0_1, Scripting::ScriptAny unknown1_1, Scripting::ScriptAny unknown2_0) { Scripting::SayAmbientSpeech(_ped, phraseName, unknown0_1, unknown1_1, unknown2_0); }
	virtual Scripting::ScriptAny SetAmmoInClip(Scripting::eWeapon weapon, u32 ammo) { return Scripting::SetAmmoInClip(_ped, weapon, ammo); }
	virtual void SetBlockingOfNonTemporaryEvents(bool value) { Scripting::SetBlockingOfNonTemporaryEvents(_ped, value); }
	virtual void SetCharAccuracy(u32 value) { Scripting::SetCharAccuracy(_ped, value); }
	virtual void SetCharAmmo(Scripting::eWeapon weapon, u32 ammo) { Scripting::SetCharAmmo(_ped, weapon, ammo); }
	virtual void SetCharAsEnemy(bool value) { Scripting::SetCharAsEnemy(_ped, value); }
	virtual void SetCharAsMissionChar() { Scripting::SetCharAsMissionChar(_ped); }
	virtual void SetCharCanBeKnockedOffBike(bool value) { Scripting::SetCharCanBeKnockedOffBike(_ped, value); }
	virtual void SetCharCanBeShotInVehicle(bool enabled) { Scripting::SetCharCanBeShotInVehicle(_ped, enabled); }
	virtual void SetCharCantBeDraggedOut(bool enabled) { Scripting::SetCharCantBeDraggedOut(_ped, enabled); }
	virtual void SetCharComponentVariation(Scripting::ePedComponent component, u32 modelVariation, u32 textureVariation) { Scripting::SetCharComponentVariation(_ped, component, modelVariation, textureVariation); }
	virtual void SetCharCoordinates(f32 x, f32 y, f32 z) { Scripting::SetCharCoordinates(_ped, x, y, z); }
	virtual void SetCharDefaultComponentVariation() { Scripting::SetCharDefaultComponentVariation(_ped); }
	virtual void SetCharDesiredHeading(f32 heading) { Scripting::SetCharDesiredHeading(_ped, heading); }
	virtual void SetCharDropsWeaponsWhenDead(bool value) { Scripting::SetCharDropsWeaponsWhenDead(_ped, value); }
	virtual void SetCharDruggedUp(bool drugged) { Scripting::SetCharDruggedUp(_ped, drugged); }
	virtual void SetCharFireDamageMultiplier(f32 multiplier) { Scripting::SetCharFireDamageMultiplier(_ped, multiplier); }
	virtual void SetCharGravity(f32 value) { Scripting::SetCharGravity(_ped, value); }
	virtual void SetCharHeading(f32 heading) { Scripting::SetCharHeading(_ped, heading); }
	virtual void SetCharHealth(u32 health) { Scripting::SetCharHealth(_ped, health); }
	virtual void SetCharInvincible(bool enable) { Scripting::SetCharInvincible(_ped, enable); }
	virtual void SetCharIsTargetPriority(bool enable) { Scripting::SetCharIsTargetPriority(_ped, enable); }
	virtual void SetCharMaxHealth(u32 value) { Scripting::SetCharMaxHealth(_ped, value); }
	virtual void SetCharMoney(u32 amount) { Scripting::SetCharMoney(_ped, amount); }
	virtual void SetCharNeverLeavesGroup(bool value) { Scripting::SetCharNeverLeavesGroup(_ped, value); }
	virtual void SetCharProofs(bool unknown0, bool fallingDamage, bool unknown1, bool unknown2, bool unknown3) { Scripting::SetCharProofs(_ped, unknown0, fallingDamage, unknown1, unknown2, unknown3); }
	virtual void SetCharPropIndex(Scripting::ePedPropType propType, u32 index) { Scripting::SetCharPropIndex(_ped, propType, index); }
	virtual void SetCharRandomComponentVariation() { Scripting::SetCharRandomComponentVariation(_ped); }
	virtual void SetCharSphereDefensiveArea(f32 x, f32 y, f32 z, f32 radius) { Scripting::SetCharSphereDefensiveArea(_ped, x, y, z, radius); }
	virtual void SetCharSuffersCriticalHits(bool value) { Scripting::SetCharSuffersCriticalHits(_ped, value); }
	virtual void SetCharVelocity(f32 x, f32 y, f32 z) { Scripting::SetCharVelocity(_ped, x, y, z); }
	virtual void SetCharVisible(bool value) { Scripting::SetCharVisible(_ped, value); }
	virtual void SetCharWantedByPolice(bool wanted) { Scripting::SetCharWantedByPolice(_ped, wanted); }
	virtual void SetCharWillDoDrivebys(bool value) { Scripting::SetCharWillDoDrivebys(_ped, value); }
	virtual void SetCharWillFlyThroughWindscreen(bool value) { Scripting::SetCharWillFlyThroughWindscreen(_ped, value); }
	virtual void SetCharWillMoveWhenInjured(bool value) { Scripting::SetCharWillMoveWhenInjured(_ped, value); }
	virtual void SetCharWillUseCarsInCombat(bool value) { Scripting::SetCharWillUseCarsInCombat(_ped, value); }
	virtual void SetCharWillUseCover(Scripting::CoverPoint coverPoint) { Scripting::SetCharWillUseCover(_ped, coverPoint); }
	virtual void SetCurrentCharWeapon(Scripting::eWeapon w, bool unknownTrue) { Scripting::SetCurrentCharWeapon(_ped, w, unknownTrue); }
	virtual void SetGroupCharDucksWhenAimedAt(bool value) { Scripting::SetGroupCharDucksWhenAimedAt(_ped, value); }
	virtual void SetIgnoreLowPriorityShockingEvents(bool value) { Scripting::SetIgnoreLowPriorityShockingEvents(_ped, value); }
	virtual void SetPedDiesWhenInjured(bool value) { Scripting::SetPedDiesWhenInjured(_ped, value); }
	virtual void SetPedIsBlindRaging(bool value) { Scripting::SetPedIsBlindRaging(_ped, value); }
	virtual void SetPedIsDrunk(bool value) { Scripting::SetPedIsDrunk(_ped, value); }
	virtual void SetPedPathMayDropFromHeight(bool value) { Scripting::SetPedPathMayDropFromHeight(_ped, value); }
	virtual void SetPedPathMayUseClimbovers(bool value) { Scripting::SetPedPathMayUseClimbovers(_ped, value); }
	virtual void SetPedPathMayUseLadders(bool value) { Scripting::SetPedPathMayUseLadders(_ped, value); }
	virtual void SetRoomForCharByKey(Scripting::eInteriorRoomKey key) { Scripting::SetRoomForCharByKey(_ped, key); }
	virtual void SetSenseRange(f32 value) { Scripting::SetSenseRange(_ped, value); }
	virtual void SwitchPedToAnimated(bool unknownTrue) { Scripting::SwitchPedToAnimated(_ped ,unknownTrue); }
	virtual Scripting::ScriptAny SwitchPedToRagdoll(Scripting::ScriptAny p1, Scripting::ScriptAny p2, Scripting::ScriptAny p3, Scripting::ScriptAny p4, Scripting::ScriptAny p5, Scripting::ScriptAny p6) { return Scripting::SwitchPedToRagdoll(_ped, p1, p2, p3, p4, p5, p6); }    
	virtual void RemovePedHelmet(bool removed) { Scripting::RemovePedHelmet(_ped, removed); }
	virtual void RemoveWeaponFromChar(Scripting::eWeapon weapon) { Scripting::RemoveWeaponFromChar(_ped, weapon); }
	virtual void UnlockRagdoll(bool value) { Scripting::UnlockRagdoll(_ped, value); }
	virtual void WarpCharFromCarToCoord(f32 x, f32 y, f32 z) { Scripting::WarpCharFromCarToCoord(_ped, x, y, z); }
	virtual void WarpCharIntoCar(Scripting::Vehicle vehicle) { Scripting::WarpCharIntoCar(_ped, vehicle); }
	virtual void WarpCharIntoCarAsPassenger(Scripting::Vehicle vehicle, u32 seatIndex) { Scripting::WarpCharIntoCarAsPassenger(_ped, vehicle, seatIndex); }
	virtual void WarpCharFromCarToCar(Scripting::Vehicle vehicle, u32 seatIndex) { Scripting::WarpCharFromCarToCar(_ped, vehicle, seatIndex); }
};