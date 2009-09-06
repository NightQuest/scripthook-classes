#pragma once

#include "../ScriptHook/NativeFiberThread.h"
#include "../ScriptHook/ScriptingEnums.h"
#include "../ScriptHook/ScriptingTypes.h"

class CustomFiberThread : 
	public NativeFiberThread
{
private:
	Scripting::Player GetPlayer();
	Scripting::Ped GetPlayerPed();

	void SpawnCar(Scripting::eModel model);
	void ChangePlayerSkin(Scripting::eModel model);
    void TeleportToWaypoint(Scripting::Ped &ped);

protected:
	void RunScript();

public:
	CustomFiberThread();
};