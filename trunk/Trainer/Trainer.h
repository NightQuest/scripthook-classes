#pragma once

#include "../ScriptHook/ScriptHook/NativeFiberThread.h"
#include "../ScriptHook/ScriptHook/Scripting.h"
#include "../ScriptHook/ScriptHook/Log.h"
#include "../Classes/CPlayer.h"

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
