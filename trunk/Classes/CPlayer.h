#pragma once
#include "CPed.h"

class CPlayer : public CPed
{
private:
	CVehicle *veh;
	Scripting::Player plr;
	Scripting::Ped _ped;

public:
	// Constructor / Destructor
	CPlayer();
	~CPlayer();

	// Helper functions
	Scripting::Player GetPlayer() { return plr; }
	Scripting::Ped GetPlayerPed() { return _ped; }
	bool IsWanted() { return Scripting::IsWantedLevelGreater(plr, 0); }

	// Wrappers
	void AddScore(i32 score) { Scripting::AddScore(plr, score); }
	void AbleToCarryNonMissionObjects(bool allow) { Scripting::AllowPlayerToCarryNonMissionObjects(plr, allow); }
	void AlterWantedLevel(u32 level) { Scripting::AlterWantedLevel(plr, level); }
	void AlterWantedLevelNoDrop(u32 level) { Scripting::AlterWantedLevelNoDrop(plr, level); }
	void ApplyWantedLevelChangeNow() { Scripting::ApplyWantedLevelChangeNow(plr); }
	void ChangeModel(Scripting::eModel model) { Scripting::ChangePlayerModel(plr, model); }
	void ClearHasDamagedAtLeastOnePed() { Scripting::ClearPlayerHasDamagedAtLeastOnePed(plr); }
	//Player ConvertIntToPlayerIndex(u32 playerId) { return Scripting::ConvertIntToPlayerIndex(playerId); }
	void ClearWantedLevel() { Scripting::ClearWantedLevel(plr); }
	//void CreatePlayer(u32 playerId, f32 x, f32 y, f32 z, Player *pPlayerIndex) { Scripting::CreatePlayer(playerId, x, y, z, pPlayerIndex); }
	void DisableLockon(bool disabled) { Scripting::DisablePlayerLockon(plr, disabled); }
	void DisableSprint(bool disabled) { Scripting::DisablePlayerSprint(plr, disabled); }
	//Scripting::Ped GetPlayerChar() { Scripting::Ped ped; Scripting::GetPlayerChar(plr, &Ped); return ped; }
	Scripting::Group GetGroup() { Scripting::Group grp; Scripting::GetPlayerGroup(plr, &grp); return grp; }
	u32 GetId() { return Scripting::GetPlayerId(); }
	Scripting::Vehicle GetLastCarNoSave() { Scripting::Vehicle vehicle; Scripting::GetPlayersLastCarNoSave(&vehicle); return vehicle; }
	u32 GetMaxArmour() { u32 MaxArmour; Scripting::GetPlayerMaxArmour(plr, &MaxArmour); return MaxArmour; }
	const char *GetName() { return Scripting::GetPlayerName(plr); }
	Scripting::eModel GetSettingsModelChoice() { return Scripting::GetPlayerSettingsModelChoice(); }
	Scripting::ScriptAny GetToPlaceBombInCar(Scripting::Vehicle vehicle) { return Scripting::GetPlayerToPlaceBombInCar(vehicle); }
	u32 GetTimeSinceDroveAgainstTraffic() { return Scripting::GetTimeSincePlayerDroveAgainstTraffic(plr); }
	u32 GetTimeSinceDroveOnPavement() { return Scripting::GetTimeSincePlayerDroveOnPavement(plr); }
	u32 GetTimeSinceHitBuilding() { return Scripting::GetTimeSincePlayerHitBuilding(plr); }
	u32 GetTimeSinceHitCar() { return Scripting::GetTimeSincePlayerHitCar(plr); }
	u32 GetTimeSinceHitObject() { return Scripting::GetTimeSincePlayerHitObject(plr); }
	u32 GetTimeSinceHitPed() { return Scripting::GetTimeSincePlayerHitPed(plr); }
	u32 GetTimeSinceRanLight() { return Scripting::GetTimeSincePlayerRanLight(plr); }
	bool HasCollectedPickup(Scripting::Pickup pickup) { return Scripting::HasPlayerCollectedPickup(plr, pickup); }
	bool HasDamagedAtLeastOnePed() { return Scripting::HasPlayerDamagedAtLeastOnePed(plr); }
	bool IsClimbing() { return Scripting::IsPlayerClimbing(plr); }
	bool IsControlOn() { return Scripting::IsPlayerControlOn(plr); }
	bool IsDead() { return Scripting::IsPlayerDead(plr); }
	bool IsFreeAimingAtChar(Scripting::Ped ped) { return Scripting::IsPlayerFreeAimingAtChar(plr, ped); }
	bool IsFreeForAmbientTask() { return Scripting::IsPlayerFreeForAmbientTask(plr); }
	bool IsPlaying() { return Scripting::IsPlayerPlaying(plr); }
	bool IsPressingHorn() { return Scripting::IsPlayerPressingHorn(plr); }
	bool IsTargettingAnything() { return Scripting::IsPlayerTargettingAnything(plr); }
	bool IsTargettingChar(Scripting::Ped ped) { return Scripting::IsPlayerTargettingChar(plr, ped); }
	bool IsTargettingObject(Scripting::Object obj) { return Scripting::IsPlayerTargettingObject(plr, obj); }
	bool IsScoreGreater(u32 score) { return Scripting::IsScoreGreater(plr, score); }
	bool IsWantedLevelGreater(u32 level) { return Scripting::IsWantedLevelGreater(plr, level); }
	bool HasChar() { return Scripting::PlayerHasChar(plr); }
	bool HasFlashingStarsAboutToDrop() { return Scripting::PlayerHasFlashingStarsAboutToDrop(plr); }
	bool HasGreyedOutStars() { return Scripting::PlayerHasGreyedOutStars(plr); }
	void RegisterRespawnCoords(f32 x, f32 y, f32 z) { Scripting::RegisterPlayerRespawnCoords(plr, x, y, z); }
	void SetEveryoneIgnorePlayer(bool value) { Scripting::SetEveryoneIgnorePlayer(plr, value); }
	void SetCanBeHassledByGangs(bool value) { Scripting::SetPlayerCanBeHassledByGangs(plr, value); }
	void SetCanDoDriveBy(bool value) { Scripting::SetPlayerCanDoDriveBy(plr, value); }
	void SetCanUseCover(bool value) { Scripting::SetPlayerCanUseCover(plr, value); }
	void SetControl(bool value) { Scripting::SetPlayerControl(plr, value); }
	void SetControlAdvanced(bool unknown1, bool unknown2, bool unknown3) { Scripting::SetPlayerControlAdvanced(plr, unknown1, unknown2, unknown3); }
	void SetFastReload(bool value) { Scripting::SetPlayerFastReload(plr, value); }
	void SetGroupToFollowAlways(bool value) { Scripting::SetPlayerGroupToFollowAlways(plr, value); }
	void SetInvincible(bool value) { Scripting::SetPlayerInvincible(plr, value); }
	void SetMoodNormal() { Scripting::SetPlayerMoodNormal(plr); }
	void SetMoodPissedOff(u32 unknown150) { Scripting::SetPlayerMoodPissedOff(plr, unknown150); }
	void SetNeverGetsTired(bool value) { Scripting::SetPlayerNeverGetsTired(plr, value); }
	void SetSettingsModelVariationsChoice() { Scripting::SetPlayerSettingsModelVariationsChoice(plr); }
	void SetPoliceIgnorePlayer(bool value) { Scripting::SetPoliceIgnorePlayer(plr, value); }
	u32 StoreScore() { u32 value; Scripting::StoreScore(plr, &value); return value; }
	u32 StoreWantedLevel() { u32 value; Scripting::StoreWantedLevel(plr, &value); return value; }
	void RemoveHelmet(bool remove) { Scripting::RemovePlayerHelmet(plr, remove); }
};
