#pragma once

#include "../ScriptHook/NativeFiberThread.h"
#include "../ScriptHook/Services/KeyboardHook.h"
#include "../ScriptHook/ScriptingEnums.h"
#include "../ScriptHook/ScriptingTypes.h"
#include "CPlayer.h"

class Trainer : public NativeFiberThread
{
private:
	bool LaunchStuff;
	bool bGodMode;
	bool BulletTime;

	CPlayer *Plr;
	void SpawnCar(Scripting::eModel model);
	void TeleportToWaypoint(Scripting::Ped &ped);

protected:
	void RunScript();

public:
	Trainer();
	~Trainer();
};
