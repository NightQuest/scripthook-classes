#include "CPlayer.h"

CPlayer::CPlayer()
{
	plr = Scripting::ConvertIntToPlayerIndex(Scripting::GetPlayerId());
	Scripting::GetPlayerChar(plr, &_ped);

	veh = new CVehicle;
}
CPlayer::~CPlayer()
{
	delete veh;
}
