#include "Trainer.h"

// Pull in all our scripting functions/types
using namespace Scripting;

Trainer::Trainer()
{
	SetName("Trainer");

	LaunchStuff = false;
	bGodMode	= false;
	Plr			= NULL;
}

Trainer::~Trainer()
{
	if( Plr != NULL )
		delete Plr;
}

void Trainer::SpawnCar(eModel model)
{
	RequestModel(model);
	while(!HasModelLoaded(model))
		Wait(0);

	LogInfo("Car model available... spawning it!");

	Vector3 loc;
	Vehicle vehicle;

	loc = Plr->GetCoordinates();
	CreateCar(model, loc.X, loc.Y, loc.Z, &vehicle, true);

	MarkModelAsNoLongerNeeded(model);
	MarkCarAsNoLongerNeeded(&vehicle);
}

void Trainer::TeleportToWaypoint()
{
    Blip wp = GetFirstBlipInfoId(BLIP_WAYPOINT);
    if(wp.IsValid())
    {
        Vector3 loc;
        GetBlipCoords(wp, &loc);

        LogInfo("Teleporting to %f, %f", loc.X, loc.Y);

        // Thanks to Prince-Link for this magical Z coord detection code...
		Plr->SetCoordinates(loc.X, loc.Y, loc.Z);
        while(loc.Z == 0.0f) // The chance that ground Z is 0.0 _exactly_ is really small
        {
            GetGroundZFor3DCoord(loc.X, loc.Y, 1000, &loc.Z);
            Wait(0);
        }

        Plr->SetCoordinates(loc.X, loc.Y, loc.Z);
    }
    else
    {
        LogError("No way point found to teleport to.");
    }
}

void DisplayLog(char *format, ...)
{
	char text[512] = { NULL };

	va_list args;
	va_start(args, format);
	vsprintf_s(text, sizeof(text), format, args);
	va_end(args);

	LogInfo(text);
	PrintStringWithLiteralStringNow("STRING", text, 5000, 1);
}

void Trainer::RunScript()
{
	while(IsThreadAlive())
	{
		if( Plr == NULL )
			Plr = new CPlayer;

		if( Plr->IsInVehicle() )
		{
			Plr->CurrentVehicle()->SetCarCanBeDamaged(!bGodMode);
			Plr->CurrentVehicle()->SetCarCanBeVisiblyDamaged(!bGodMode);
		}
		Plr->SetInvincible(bGodMode);

		if( (GetAsyncKeyState(VK_F4) & 1) != 0 )
		{
			LogInfo("Requested a MODEL_NRG900 spawn");
			SpawnCar(MODEL_NRG900);
		}
		else if( (GetAsyncKeyState(VK_F5) & 1) != 0 )
		{
			LogInfo("Requested a MODEL_INFERNUS spawn");
			SpawnCar(MODEL_INFERNUS);
		}
		else if( (GetAsyncKeyState(VK_F6) & 1) != 0 )
		{
			bGodMode = !bGodMode;
			DisplayLog("%s GodMode", (bGodMode ? "Enabling" : "Disabling"));

			Plr->SetInvincible(bGodMode);
			if( Plr->IsInVehicle() )
				Plr->CurrentVehicle()->FixCar();
		}
		else if( (GetAsyncKeyState(VK_F7) & 1) != 0 )
		{
			// Filler
		}
		else if( (GetAsyncKeyState(VK_F8) & 1) != 0 )
		{
			Vector3 loc = Plr->GetCoordinates();
			CVehicle vehicle = GetClosestCar(loc.X, loc.Y, loc.Z, 50.0f, false, 70);
			
			if( vehicle.DoesExist() )
			{
				DisplayLog("Blowing up closest car");
				vehicle.ExplodeCar(true, false);
			}
		}
		else if( (GetAsyncKeyState(VK_F9) & 1) != 0 )
		{
			if( Plr->IsWanted() )
			{
				DisplayLog("Clearing Wanted Level");
				Plr->ClearWantedLevel();
			}
			else
			{
				DisplayLog("Maxing Wanted Level");
				Plr->AlterWantedLevel(6);
			}
		}
		else if( (GetAsyncKeyState(VK_F10) & 1) != 0 )
		{
			LaunchStuff = !LaunchStuff;
			DisplayLog("%s Object launcher", (LaunchStuff ? "Enabling" : "Disabling"));
		}
		else if( (GetAsyncKeyState(VK_F11) & 1) != 0 )
		{
			if( Plr->IsInVehicle() )
			{
				LogInfo("Launching car");
				Plr->CurrentVehicle()->ApplyForceToCar(3, 0, 0, 10.0f, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1);
			}
			else
			{
				LogInfo("Launching player");
				Plr->ApplyForce(3, 0, 0, 10.0f, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1);
			}
		}

		if( LaunchStuff )
		{
			Ped ped;
			CVehicle vehicle;
			Vector3 loc;

			loc = Plr->GetCoordinates();

			vehicle = GetClosestCar(loc.X, loc.Y, loc.Z, 15.0f, false, 70);

			if( vehicle.DoesExist() )
				vehicle.ApplyForceToCar(3, 0, 0, 10.0f, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1);

			GetClosestChar(loc.X, loc.Y, loc.Z, 15.0f, true, false, &ped);
			if( DoesCharExist(ped) )
				ApplyForceToPed(ped, 3, 0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1);
		}

		Wait(100);
	}
}
