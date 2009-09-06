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
	Scripting::Vector3 GetCoordinates() { Scripting::Vector3 loc; Scripting::GetCharCoordinates(_ped, &loc.X, &loc.Y, &loc.Z); return loc; }
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
	virtual const char *GetAnimGroupFromChar() { return NativeInvoke::Invoke<const char *>("GET_ANIM_GROUP_FROM_CHAR", _ped); }
	virtual void GetCharCoordinates(f32 *pX, f32 *pY, f32 *pZ) {  }
	virtual void GetCharHealth(u32 *pHealth) {  }
	virtual void GetCharAnimCurrentTime(const char *animGroup, const char *animName, f32 *pValue) {  }
	virtual void GetCharAnimTotalTime(const char *animGroup, const char *animName, f32 *pValue) {  }
	virtual void GetCharArmour(u32 *pArmour) {  }
	virtual u32 GetCharDrawableVariation(Scripting::ePedComponent component) { return NativeInvoke::Invoke<Scripting::ScriptAny>("GET_CHAR_DRAWABLE_VARIATION", _ped, component); }
	virtual void GetCharExtractedDisplacement(bool unknown, f32 *pX, f32 *pY, f32 *pZ) {  }
	virtual void GetCharHeading(f32 *pValue) {  }
	virtual void GetCharHeightAboveGround(f32 *pValue) {  }
	virtual Scripting::ScriptAny GetCharLastDamageBone(Scripting::ePedBone *pBone) { return NativeInvoke::Invoke<Scripting::ScriptAny>("GET_CHAR_LAST_DAMAGE_BONE", _ped, pBone); }
	virtual bool GetCharMeleeActionFlag0() { return NativeInvoke::Invoke<bool>("GET_CHAR_MELEE_ACTION_FLAG0", _ped); }
	virtual bool GetCharMeleeActionFlag1() { return NativeInvoke::Invoke<bool>("GET_CHAR_MELEE_ACTION_FLAG1", _ped); }
	virtual void GetCharModel(Scripting::eModel *pModel) {  }
	virtual u32 GetCharMoney() { return NativeInvoke::Invoke<u32>("GET_CHAR_MONEY", _ped); }
	virtual void GetCharPropIndex(bool unknown, u32 *pIndex) {  }
	virtual bool GetCharReadyToBeExecuted() { return NativeInvoke::Invoke<bool>("GET_CHAR_READY_TO_BE_EXECUTED", _ped); }
	virtual bool GetCharReadyToBeStunned() { return NativeInvoke::Invoke<bool>("GET_CHAR_READY_TO_BE_STUNNED", _ped); }
	virtual void GetCharSpeed(f32 *pValue) {  }
	virtual u32 GetCharTextureVariation(Scripting::ePedComponent component) { return NativeInvoke::Invoke<u32>("GET_CHAR_TEXTURE_VARIATION", _ped, component); }
	virtual void GetCharVelocity(f32 *pX, f32 *pY, f32 *pZ) {  }
	virtual void GetCharWeaponInSlot(Scripting::eWeaponSlot slot, Scripting::eWeapon *pWeapon, Scripting::ScriptAny *pUnknown1, Scripting::ScriptAny *pUnknown2) {  }
	virtual bool GetCharWillCowerInsteadOfFleeing() { return NativeInvoke::Invoke<bool>("GET_CHAR_WILL_COWER_INSTEAD_OF_FLEEING", _ped); }
	virtual Scripting::ScriptAny GetCurrentCharWeapon(Scripting::eWeapon *pWeapon) { return NativeInvoke::Invoke<Scripting::ScriptAny>("GET_CURRENT_CHAR_WEAPON", _ped, pWeapon); }
	virtual u32 GetDamageToPedBodyPart(Scripting::ePedBodyPart part) { return NativeInvoke::Invoke<u32>("GET_DAMAGE_TO_PED_BODY_PART", _ped, part); }
	virtual void GetDeadCharCoordinates(f32 *pX, f32 *pY, f32 *pZ) {  }
	virtual void GetDeadCharPickupCoords(f32 *pX, f32 *pY, f32 *pZ) {  }
	virtual void GetKeyForCharInRoom(Scripting::eInteriorRoomKey *pKey) {  }
	virtual Scripting::ScriptAny GetMaxAmmo(Scripting::eWeapon weapon, u32 *pMaxAmmo) { return NativeInvoke::Invoke<Scripting::ScriptAny>("GET_MAX_AMMO", _ped, weapon, pMaxAmmo); }
	virtual void GetMaxAmmoInClip(Scripting::eWeapon weapon, u32 *pMaxAmmo) {  }
	virtual u32 GetNumberOfCharDrawableVariations(Scripting::ePedComponent component) { return NativeInvoke::Invoke<u32>("GET_NUMBER_OF_CHAR_DRAWABLE_VARIATIONS", _ped, component); }
	virtual u32 GetNumberOfCharTextureVariations(Scripting::ePedComponent component, u32 unknown1) { return NativeInvoke::Invoke<u32>("GET_NUMBER_OF_CHAR_TEXTURE_VARIATIONS", _ped, component, unknown1); }
	virtual Scripting::Object GetObjectPedIsHolding() { return NativeInvoke::Invoke<Scripting::Object>("GET_OBJECT_PED_IS_HOLDING", _ped); }
	virtual void GetOffsetFromCharInWorldCoords(f32 x, f32 y, f32 z, f32 *pOffX, f32 *pOffY, f32 *pOffZ) {  }
	virtual Scripting::ePedClimbState GetPedClimbState() { return NativeInvoke::Invoke<Scripting::ePedClimbState>("GET_PED_CLIMB_STATE", _ped); }
	virtual void GetPedBonePosition(Scripting::ePedBone bone, f32 x, f32 y, f32 z, Scripting::Vector3 *pPosition) {  }
	virtual void GetPedGroupIndex(u32 *pIndex) {  }
	virtual void GetPedType(Scripting::ePedType *pType) {  }
	virtual void GivePedHelmet() {  }
	virtual void GiveWeaponToChar(Scripting::eWeapon weapon, u32 ammo, bool unknown0) {  }
	virtual bool HasCharBeenDamagedByCar(Scripting::Vehicle vehicle) { return NativeInvoke::Invoke<bool>("HAS_CHAR_BEEN_DAMAGED_BY_CAR", _ped, vehicle); }
	virtual bool HasCharBeenDamagedByChar(Scripting::Ped otherChar, bool unknownFalse) { return NativeInvoke::Invoke<bool>("HAS_CHAR_BEEN_DAMAGED_BY_CHAR", _ped, otherChar, unknownFalse); }
	virtual bool HasCharBeenDamagedByWeapon(Scripting::eWeapon weapon) { return NativeInvoke::Invoke<bool>("HAS_CHAR_BEEN_DAMAGED_BY_WEAPON", _ped, weapon); }
	virtual bool HasCharGotWeapon(Scripting::eWeapon weapon) { return NativeInvoke::Invoke<bool>("HAS_CHAR_GOT_WEAPON", _ped, weapon); }
	virtual bool HasCharSpottedChar(Scripting::Ped otherChar) { return NativeInvoke::Invoke<bool>("HAS_CHAR_SPOTTED_CHAR", _ped, otherChar); }
	virtual bool HasCharSpottedCharInFront(Scripting::Ped otherChar) { return NativeInvoke::Invoke<bool>("HAS_CHAR_SPOTTED_CHAR_IN_FRONT", _ped, otherChar); }
	virtual bool IsAmbientSpeechPlaying() { return NativeInvoke::Invoke<bool>("IS_AMBIENT_SPEECH_PLAYING", _ped); }
	virtual bool IsCharArmed(Scripting::eWeaponSlot slot) { return NativeInvoke::Invoke<bool>("IS_CHAR_ARMED", _ped, slot); }
	virtual bool IsCharDead() { return NativeInvoke::Invoke<bool>("IS_CHAR_DEAD", _ped); }
	virtual bool IsCharDucking() { return NativeInvoke::Invoke<bool>("IS_CHAR_DUCKING", _ped); }
	virtual bool IsCharFacingChar(Scripting::Ped otherChar, f32 angle) { return NativeInvoke::Invoke<bool>("IS_CHAR_FACING_CHAR", _ped, otherChar, angle); }
	virtual bool IsCharFatallyInjured() { return NativeInvoke::Invoke<bool>("IS_CHAR_FATALLY_INJURED", _ped); }
	virtual bool IsCharGesturing() { return NativeInvoke::Invoke<bool>("IS_CHAR_GESTURING", _ped); }
	virtual bool IsCharGettingInToACar() { return NativeInvoke::Invoke<bool>("IS_CHAR_GETTING_IN_TO_A_CAR", _ped); }
	virtual bool IsCharGettingUp() { return NativeInvoke::Invoke<bool>("IS_CHAR_GETTING_UP", _ped); }
	virtual bool IsCharHealthGreater(u32 health) { return NativeInvoke::Invoke<bool>("IS_CHAR_HEALTH_GREATER", _ped, health); }
	virtual bool IsCharInAir() { return NativeInvoke::Invoke<bool>("IS_CHAR_IN_AIR", _ped); }	
	virtual bool IsCharInAngledArea2D(f32 x1, f32 y1, f32 x2, f32 y2, f32 unknown, bool unknownFalse) { return NativeInvoke::Invoke<bool>("IS_CHAR_IN_ANGLED_AREA_2D", _ped, x1, y1, x2, y2, unknown, unknownFalse); }
	virtual bool IsCharInAngledArea3D(f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, f32 unknown, bool unknownFalse) { return NativeInvoke::Invoke<bool>("IS_CHAR_IN_ANGLED_AREA_3D", _ped, x1, y1, z1, x2, y2, z2, unknown, unknownFalse); }
	virtual bool IsCharInAnyBoat() { return NativeInvoke::Invoke<bool>("IS_CHAR_IN_ANY_BOAT", _ped); }
	virtual bool IsCharInAnyCar() { return NativeInvoke::Invoke<bool>("IS_CHAR_IN_ANY_CAR", _ped); }
	virtual bool IsCharInAnyHeli() { return NativeInvoke::Invoke<bool>("IS_CHAR_IN_ANY_HELI", _ped); }
	virtual bool IsCharInAnyPlane() { return NativeInvoke::Invoke<bool>("IS_CHAR_IN_ANY_PLANE", _ped); }
	virtual bool IsCharInAnyPoliceVehicle() { return NativeInvoke::Invoke<bool>("IS_CHAR_IN_ANY_POLICE_VEHICLE", _ped); }
	virtual bool IsCharInAnyTrain() { return NativeInvoke::Invoke<bool>("IS_CHAR_IN_ANY_TRAIN", _ped); }
	virtual bool IsCharInArea2D(f32 x1, f32 y1, f32 x2, f32 y2, bool unknownFalse) { return NativeInvoke::Invoke<bool>("IS_CHAR_IN_AREA_2D", _ped, x1, y1, x2, y2, unknownFalse); }
	virtual bool IsCharInArea3D(f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, bool unknownFalse) { return NativeInvoke::Invoke<bool>("IS_CHAR_IN_AREA_3D", _ped, x1, y1, z1, x2, y2, z2, unknownFalse); }
	virtual bool IsCharInAreaOnFoot2D(f32 x1, f32 y1, f32 x2, f32 y2, bool unknownFalse) { return NativeInvoke::Invoke<bool>("IS_CHAR_IN_AREA_ON_FOOT_2D", _ped, x1, y1, x2, y2, unknownFalse); }
	virtual bool IsCharInCar(Scripting::Vehicle vehicle) { return NativeInvoke::Invoke<bool>("IS_CHAR_IN_CAR", _ped, vehicle); }
	virtual bool IsCharInFlyingVehicle() { return NativeInvoke::Invoke<bool>("IS_CHAR_IN_FLYING_VEHICLE", _ped); }
	virtual bool IsCharInMeleeCombat() { return NativeInvoke::Invoke<bool>("IS_CHAR_IN_MELEE_COMBAT", _ped); }
	virtual bool IsCharInModel(Scripting::eModel model) { return NativeInvoke::Invoke<bool>("IS_CHAR_IN_MODEL", _ped, model); }
	virtual bool IsCharInTaxi() { return NativeInvoke::Invoke<bool>("IS_CHAR_IN_TAXI", _ped); }
	virtual bool IsCharInWater() { return NativeInvoke::Invoke<bool>("IS_CHAR_IN_WATER", _ped); }
	virtual bool IsCharInjured() { return NativeInvoke::Invoke<bool>("IS_CHAR_INJURED", _ped); }
	virtual bool IsCharMale() { return NativeInvoke::Invoke<bool>("IS_CHAR_MALE", _ped); }
	virtual bool IsCharModel(Scripting::eModel model) { return NativeInvoke::Invoke<bool>("IS_CHAR_MODEL", _ped, model); }
	virtual bool IsCharOnAnyBike() { return NativeInvoke::Invoke<bool>("IS_CHAR_ON_ANY_BIKE", _ped); }
	virtual bool IsCharOnFire() { return NativeInvoke::Invoke<bool>("IS_CHAR_ON_FIRE", _ped); }
	virtual bool IsCharOnFoot() { return NativeInvoke::Invoke<bool>("IS_CHAR_ON_FOOT", _ped); }
	virtual bool IsCharOnScreen() { return NativeInvoke::Invoke<bool>("IS_CHAR_ON_SCREEN", _ped); }
	virtual bool IsCharPlayingAnim(char *animSet, char *animName) { return NativeInvoke::Invoke<bool>("IS_CHAR_PLAYING_ANIM", _ped, animSet, animName); }
	virtual bool IsCharShooting() { return NativeInvoke::Invoke<bool>("IS_CHAR_SHOOTING", _ped); }
	virtual bool IsCharShootingInArea(f32 x1, f32 y1, f32 x2, f32 y2, bool unknownFalse) { return NativeInvoke::Invoke<bool>("IS_CHAR_SHOOTING_IN_AREA", _ped, x1, y1, x2, y2, unknownFalse); }
	virtual bool IsCharSittingIdle() { return NativeInvoke::Invoke<bool>("IS_CHAR_SITTING_IDLE", _ped); }
	virtual bool IsCharSittingInAnyCar() { return NativeInvoke::Invoke<bool>("IS_CHAR_SITTING_IN_ANY_CAR", _ped); }
	virtual bool IsCharSittingInCar(Scripting::Vehicle vehicle) { return NativeInvoke::Invoke<bool>("IS_CHAR_SITTING_IN_CAR", _ped, vehicle); }
	virtual bool IsCharStopped() { return NativeInvoke::Invoke<bool>("IS_CHAR_STOPPED", _ped); }
	virtual bool IsCharStuckUnderCar() { return NativeInvoke::Invoke<bool>("IS_CHAR_STUCK_UNDER_CAR", _ped); }
	virtual bool IsCharSwimming() { return NativeInvoke::Invoke<bool>("IS_CHAR_SWIMMING", _ped); }
	virtual bool IsCharTouchingChar(Scripting::Ped otherChar) { return NativeInvoke::Invoke<bool>("IS_CHAR_TOUCHING_CHAR", _ped, otherChar); }
	virtual bool IsCharTouchingObject(Scripting::Object obj) { return NativeInvoke::Invoke<bool>("IS_CHAR_TOUCHING_OBJECT", _ped, obj); }
	virtual bool IsCharTouchingObjectOnFoot(Scripting::Object obj) { return NativeInvoke::Invoke<bool>("IS_CHAR_TOUCHING_OBJECT_ON_FOOT", _ped, obj); }
	virtual bool IsCharTouchingVehicle(Scripting::ScriptAny p0, Scripting::ScriptAny p1) { return NativeInvoke::Invoke<bool>("IS_CHAR_TOUCHING_VEHICLE", p0, p1); }
	virtual bool IsCharTryingToEnterALockedCar() { return NativeInvoke::Invoke<bool>("IS_CHAR_TRYING_TO_ENTER_A_LOCKED_CAR", _ped); }
	virtual bool IsCharUsingAnyScenario() { return NativeInvoke::Invoke<bool>("IS_CHAR_USING_ANY_SCENARIO", _ped); }
	virtual bool IsCharUsingScenario(const char *scenarioName) { return NativeInvoke::Invoke<bool>("IS_CHAR_USING_SCENARIO", _ped, scenarioName); }
	virtual bool IsCharVisible() { return NativeInvoke::Invoke<bool>("IS_CHAR_VISIBLE", _ped); }
	virtual bool IsCharWaitingForWorldCollision() { return NativeInvoke::Invoke<bool>("IS_CHAR_WAITING_FOR_WORLD_COLLISION", _ped); }
	virtual bool IsPedAMissionPed() { return NativeInvoke::Invoke<bool>("IS_PED_A_MISSION_PED", _ped); }
	virtual bool IsPedAttachedToAnyCar() { return NativeInvoke::Invoke<bool>("IS_PED_ATTACHED_TO_ANY_CAR", _ped); }
	virtual bool IsPedAttachedToObject(Scripting::Object obj) { return NativeInvoke::Invoke<bool>("IS_PED_ATTACHED_TO_OBJECT", _ped, obj); }
	virtual bool IsPedBeingJacked() { return NativeInvoke::Invoke<bool>("IS_PED_BEING_JACKED", _ped); }
	virtual bool IsPedDoingDriveby() { return NativeInvoke::Invoke<bool>("IS_PED_DOING_DRIVEBY", _ped); }
	virtual bool IsPedFleeing() { return NativeInvoke::Invoke<bool>("IS_PED_FLEEING", _ped); }
	virtual bool IsPedHoldingAnObject() { return NativeInvoke::Invoke<bool>("IS_PED_HOLDING_AN_OBJECT", _ped); }
	virtual bool IsPedInCombat() { return NativeInvoke::Invoke<bool>("IS_PED_IN_COMBAT", _ped); }
	virtual bool IsPedInCover() { return NativeInvoke::Invoke<bool>("IS_PED_IN_COVER", _ped); }
	virtual bool IsPedInGroup() { return NativeInvoke::Invoke<bool>("IS_PED_IN_GROUP", _ped); }
	virtual bool IsPedJacking() { return NativeInvoke::Invoke<bool>("IS_PED_JACKING", _ped); }
	virtual bool IsPedLookingAtPed(Scripting::Ped otherChar) { return NativeInvoke::Invoke<bool>("IS_PED_LOOKING_AT_PED", _ped, otherChar); }
	virtual bool IsPedRagdoll() { return NativeInvoke::Invoke<bool>("IS_PED_RAGDOLL", _ped); }
	virtual bool IsPedRetreating() { return NativeInvoke::Invoke<bool>("IS_PED_RETREATING", _ped); }
	virtual bool IsScriptedSpeechPlaying() { return NativeInvoke::Invoke<bool>("IS_SCRIPTED_SPEECH_PLAYING", _ped); }
	virtual void MarkCharAsNoLongerNeeded(Scripting::Ped *pPed) {  }
	virtual void ModifyCharMoveState(Scripting::ePedMoveState state) {  }
	virtual void RemoveAllCharWeapons() {  }
	virtual void RemoveCharDefensiveArea() {  }
	virtual void RemoveCharElegantly() {  }
	virtual void RemoveCharFromGroup() {  }
	virtual void ReviveInjuredPed() {  }
	virtual void SayAmbientSpeech(char *phraseName, Scripting::ScriptAny unknown0_1, Scripting::ScriptAny unknown1_1, Scripting::ScriptAny unknown2_0) {  }
	virtual Scripting::ScriptAny SetAmmoInClip(Scripting::eWeapon weapon, u32 ammo) { return NativeInvoke::Invoke<Scripting::ScriptAny>("SET_AMMO_IN_CLIP", _ped, weapon, ammo); }
	virtual void SetBlockingOfNonTemporaryEvents(bool value) {  }
	virtual void SetCharAccuracy(u32 value) {  }
	virtual void SetCharAmmo(Scripting::eWeapon weapon, u32 ammo) {  }
	virtual void SetCharAsEnemy(bool value) {  }
	virtual void SetCharAsMissionChar() {  }
	virtual void SetCharCanBeKnockedOffBike(bool value) {  }
	virtual void SetCharCanBeShotInVehicle(bool enabled) {  }
	virtual void SetCharCantBeDraggedOut(bool enabled) {  }
	virtual void SetCharComponentVariation(Scripting::ePedComponent component, u32 modelVariation, u32 textureVariation) {  }
	virtual void SetCharCoordinates(f32 x, f32 y, f32 z) {  }
	virtual void SetCharDefaultComponentVariation() {  }
	virtual void SetCharDesiredHeading(f32 heading) {  }
	virtual void SetCharDropsWeaponsWhenDead(bool value) {  }
	virtual void SetCharDruggedUp(bool drugged) {  }
	virtual void SetCharFireDamageMultiplier(f32 multiplier) {  }
	virtual void SetCharGravity(f32 value) {  }
	virtual void SetCharHeading(f32 heading) {  }
	virtual void SetCharHealth(u32 health) {  }
	virtual void SetCharInvincible(bool enable) {  }
	virtual void SetCharIsTargetPriority(bool enable) {  }
	virtual void SetCharMaxHealth(u32 value) {  }
	virtual void SetCharMoney(u32 amount) {  }
	virtual void SetCharNeverLeavesGroup(bool value) {  }
	virtual void SetCharProofs(bool unknown0, bool fallingDamage, bool unknown1, bool unknown2, bool unknown3) {  }
	virtual void SetCharPropIndex(Scripting::ePedPropType propType, u32 index) {  }
	virtual void SetCharRandomComponentVariation() {  }
	virtual void SetCharSphereDefensiveArea(f32 x, f32 y, f32 z, f32 radius) {  }
	virtual void SetCharSuffersCriticalHits(bool value) {  }
	virtual void SetCharVelocity(f32 x, f32 y, f32 z) {  }
	virtual void SetCharVisible(bool value) {  }
	virtual void SetCharWantedByPolice(bool wanted) {  }
	virtual void SetCharWillDoDrivebys(bool value) {  }
	virtual void SetCharWillFlyThroughWindscreen(bool value) {  }
	virtual void SetCharWillMoveWhenInjured(bool value) {  }
	virtual void SetCharWillUseCarsInCombat(bool value) {  }
	virtual void SetCharWillUseCover(Scripting::CoverPoint coverPoint) {  }
	virtual void SetCurrentCharWeapon(Scripting::eWeapon w, bool unknownTrue) {  }
	virtual void SetGroupCharDucksWhenAimedAt(bool value) {  }
	virtual void SetIgnoreLowPriorityShockingEvents(bool value) {  }
	virtual void SetPedDiesWhenInjured(bool value) {  }
	virtual void SetPedIsBlindRaging(bool value) {  }
	virtual void SetPedIsDrunk(bool value) {  }
	virtual void SetPedPathMayDropFromHeight(bool value) {  }
	virtual void SetPedPathMayUseClimbovers(bool value) {  }
	virtual void SetPedPathMayUseLadders(bool value) {  }
	virtual void SetRoomForCharByKey(Scripting::eInteriorRoomKey key) {  }
	virtual void SetSenseRange(f32 value) {  }
	virtual void SwitchPedToAnimated(bool unknownTrue) {  }
	virtual Scripting::ScriptAny SwitchPedToRagdoll(Scripting::ScriptAny p1, Scripting::ScriptAny p2, Scripting::ScriptAny p3, Scripting::ScriptAny p4, Scripting::ScriptAny p5, Scripting::ScriptAny p6) { return NativeInvoke::Invoke<Scripting::ScriptAny>("SWITCH_PED_TO_RAGDOLL", _ped, p1, p2, p3, p4, p5, p6); }    
	virtual void RemovePedHelmet(bool removed) {  }
	virtual void RemoveWeaponFromChar(Scripting::eWeapon weapon) {  }
	virtual void UnlockRagdoll(bool value) {  }
	virtual void WarpCharFromCarToCoord(f32 x, f32 y, f32 z) {  }
	virtual void WarpCharIntoCar(Scripting::Vehicle vehicle) {  }
	virtual void WarpCharIntoCarAsPassenger(Scripting::Vehicle vehicle, u32 seatIndex) {  }
	virtual void WarpCharFromCarToCar(Scripting::Vehicle vehicle, u32 seatIndex) {  }
};