#pragma once

#include "../ScriptHook/ScriptHook/NativeFiberThread.h"
#include "../ScriptHook/ScriptHook/Scripting.h"
#include "../ScriptHook/ScriptHook/Log.h"
#include "../Classes/CPlayer.h"

#include <iostream>
#include <windows.h>

class Trainer : public NativeFiberThread
{
private:
	bool LaunchStuff;
	bool GodMode;
	bool TerrorMode;

	CPlayer *Plr;
	void SpawnCar(Scripting::eModel model);
	void TeleportToWaypoint();

protected:
	void RunScript();

public:
	Trainer();
	~Trainer();
};
