#pragma once

#include "../ScriptHook/NativeThread.h"
#include "../ScriptHook/ScriptingEnums.h"

class CustomThread : 
	public NativeThread
{
private:
	enum eStateMachine
	{
		StateDefault,
		StateSpawnCar,
		StateChangeSkin,
	};

	eStateMachine m_State;
	
	Scripting::eModel m_CarModel;
	Scripting::eModel m_SkinModel;

protected:
	void RunTick();

public:
	CustomThread();
};