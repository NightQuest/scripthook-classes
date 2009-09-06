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
	Scripting::Vector3 GetCoordinates() { Scripting::Vector3 loc; Scripting::GetCharCoordinates(_ped, &loc.X, &loc.Y, &loc.Z); return loc; }
	void SetCoordinates(f32 X, f32 Y, f32 Z) { Scripting::SetCharCoordinates(_ped, X, Y, Z); }

	// Wrappers
};