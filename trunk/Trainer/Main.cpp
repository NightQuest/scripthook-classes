#include <windows.h>

#include "Trainer.h"

#include "../ScriptHook/ScriptHook/ScriptHookManager.h"

static Trainer _customThread;

BOOL APIENTRY DllMain( HANDLE hModule, DWORD  fdwReason, LPVOID lpReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH: 
        {
			ScriptHookManager::RegisterThread( &_customThread );

            break;
        }
        case DLL_PROCESS_DETACH:
        {
            break;
        }
    }

    return TRUE;
}