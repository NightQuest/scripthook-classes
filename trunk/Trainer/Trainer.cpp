#include "Trainer.h"
#include <math.h>

// Pull in all our scripting functions/types
using namespace Scripting;

Trainer::Trainer()
{
	SetName("Trainer");

	LaunchStuff = false;
	GodMode		= false;
	TerrorMode	= false;
	Plr			= NULL;
}

Trainer::~Trainer()
{
	if( Plr != NULL )
	{
		delete Plr;
		Plr = NULL;
	}
}

void Trainer::SpawnCar(eModel model)
{
	RequestModel(model);
	while(!HasModelLoaded(model))
		Wait(0);

	LogInfo("Car model available... spawning it!");

	CVehicle vehicle;
	vehicle.CreateCar(model, Plr->GetOffsetFromCharInWorldCoords(2.0f, 0.0f, 0.0f), true);

	MarkModelAsNoLongerNeeded(model);
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
		Plr->SetCharCoordinates(loc.X, loc.Y, loc.Z);
        while(loc.Z == 0.0f) // The chance that ground Z is 0.0 _exactly_ is really small
        {
            GetGroundZFor3DCoord(loc.X, loc.Y, 1000, &loc.Z);
            Wait(0);
        }

        Plr->SetCharCoordinates(loc.X, loc.Y, loc.Z);
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
			Plr = new CPlayer();

		if( (GetAsyncKeyState(VK_F4) & 1) != 0 )
		{
			DisplayLog("Spawning a NRG-900");
			SpawnCar(MODEL_NRG900);
		}
		else if( (GetAsyncKeyState(VK_F5) & 1) != 0 )
		{
			DisplayLog("Spawning a Infernus");
			SpawnCar(MODEL_INFERNUS);
		}
		else if( (GetAsyncKeyState(VK_F6) & 1) != 0 )
		{
			GodMode = !GodMode;
			DisplayLog("God Mode %s", (GodMode ? "Enabled" : "Disabled"));

			if( Plr->IsCharInAnyCar() && GodMode )
				Plr->CurrentVehicle()->FixCar();
		}
		else if( (GetAsyncKeyState(VK_F7) & 1) != 0 )
		{
			TerrorMode	= !TerrorMode;
			GodMode		= TerrorMode;
			DisplayLog("Terror Mode %s", (TerrorMode ? "Enabled" : "Disabled"));

			if( Plr->IsCharInAnyCar() && GodMode )
				Plr->CurrentVehicle()->FixCar();
		}
		else if( (GetAsyncKeyState(VK_F8) & 1) != 0 )
		{
			Vector3 loc = Plr->GetCoordinates();
			CVehicle vehicle = GetClosestCar(loc.X, loc.Y, loc.Z, 50.0f, false, 70);
			
			if( vehicle.DoesVehicleExist() )
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
			DisplayLog("Object launcher %s", (LaunchStuff ? "Enabled" : "Disabled"));
		}
		else if( (GetAsyncKeyState(VK_F11) & 1) != 0 )
		{
			if( Plr->IsCharInAnyCar() )
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

		// GodMode
		if( Plr->IsCharInAnyCar() )
		{
			Plr->CurrentVehicle()->SetCarCanBeDamaged(!GodMode);
			Plr->CurrentVehicle()->SetCarCanBeVisiblyDamaged(!GodMode);
		}
		Plr->SetInvincible(GodMode);
		Plr->SetCharWillFlyThroughWindscreen(!GodMode);
		Plr->SetCharCantBeDraggedOut(GodMode);
		Plr->SetCharCanBeKnockedOffBike(!GodMode);
		Plr->SetCharCanBeShotInVehicle(!GodMode);

		if( TerrorMode )
		{
			CPed cped;
			Ped ped;
			CVehicle vehicle;
			Vector3 loc, loc2;

			loc = Plr->GetCoordinates();

			GetClosestChar(loc.X, loc.Y, loc.Z, 15.0f, true, false, &ped);
			if( DoesCharExist(ped) )
				StartCharFire(ped);

			vehicle = GetClosestCar(loc.X, loc.Y, loc.Z, 15.0f, false, 70);
			if( vehicle.DoesVehicleExist() )
			{
				loc2 = vehicle.GetCarCoordinates();
				f32 angle = atan2(loc2.Y, loc2.X);
				loc2.X += Sin(angle) * vehicle.GetCarSpeed();
				loc2.Y += Cos(angle) * vehicle.GetCarSpeed();
				vehicle.ApplyForceToCar(3, loc2.X, loc2.Y, 0.0f, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1);
				//vehicle.ExplodeCar(true, false);
			}
		}

		// Launcher
		if( LaunchStuff )
		{
			Ped ped;
			CVehicle vehicle;
			Vector3 loc;

			loc = Plr->GetCoordinates();

			vehicle = GetClosestCar(loc.X, loc.Y, loc.Z, 15.0f, false, 70);
			if( vehicle.DoesVehicleExist() )
				vehicle.ApplyForceToCar(3, 0, 0, 10.0f, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1);

			GetClosestChar(loc.X, loc.Y, loc.Z, 15.0f, true, false, &ped);
			if( DoesCharExist(ped) )
				ApplyForceToPed(ped, 3, 0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1);
		}

		Wait(100);
	}
}
