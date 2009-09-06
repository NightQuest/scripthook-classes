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

	// Helper functions
	Scripting::Vector3 GetCoordinates();

	// Wrappers
};