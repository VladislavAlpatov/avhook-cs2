#include <Windows.h>
#include "hacks/hooks/Hooker.h"


[[maybe_unused]] BOOL WINAPI DllMain([[maybe_unused]] const HMODULE hModule, const DWORD dwReason,[[maybe_unused]] LPVOID lpReserved)
{

    if (dwReason == DLL_PROCESS_ATTACH)
    {
        hacks::hooks::Hooker::Get()->Attach();
    }
    return TRUE;
}