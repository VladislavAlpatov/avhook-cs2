#include <Windows.h>
#include "hacks/hooks/Hooker.h"
#include <thread>

void Main(HMODULE hmodule)
{
   hacks::hooks::Hooker::Get()->Attach();

    while (!GetAsyncKeyState(VK_END))
        Sleep(50);

    hacks::hooks::Hooker::Get()->Detach();
    Sleep(100);

    FreeLibraryAndExitThread(hmodule, 0);
}

[[maybe_unused]] BOOL WINAPI DllMain([[maybe_unused]] const HMODULE hModule, const DWORD dwReason,[[maybe_unused]] LPVOID lpReserved)
{

    if (dwReason == DLL_PROCESS_ATTACH)
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Main, hModule, 0, nullptr);

    return TRUE;
}