#include "CPlayer.h"

CPlayer::CPlayer()
{
	plr = Scripting::ConvertIntToPlayerIndex(Scripting::GetPlayerId());
	Scripting::GetPlayerChar(plr, &ped);

	vehicle = new CVehicle;
}
CPlayer::~CPlayer()
{
	delete vehicle;
}

Scripting::Vector3 CPlayer::GetCoordinates()
{
	Scripting::Vector3 loc;
	Scripting::GetCharCoordinates(_ped, &loc.X, &loc.Y, &loc.Z);
	return loc;
}