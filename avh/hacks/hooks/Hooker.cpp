//
// Created by Vlad on 28.09.2023.
//

#include "Hooker.h"

#include <MinHook.h>
#include <sigscanner/ModuleScanner.h>
#include <cassert>
#include "overlay/Overlay.h"
#include <imgui/imgui.h>



inline uintptr_t oPresent;
inline uintptr_t oWndProc;

HRESULT __fastcall hPresent([[maybe_unused]] IDXGISwapChain* pChain,
                            [[maybe_unused]] UINT SyncInterval,
                            [[maybe_unused]] UINT Flags)
{
    static overlay::Overlay overlay(pChain);

    overlay.Render();


    typedef HRESULT(__fastcall* tPresent)(IDXGISwapChain*, UINT, UINT);
    return reinterpret_cast<tPresent>(oPresent)(pChain, SyncInterval, Flags);
}
LRESULT CALLBACK hWndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

    if (ImGui::GetCurrentContext())
        ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);

    return CallWindowProcW((WNDPROC)oWndProc, hWnd, uMsg, wParam, lParam);
}

namespace hacks::hooks
{

    std::shared_ptr<Hooker> Hooker::Get()
    {
        static auto pObj = std::shared_ptr<Hooker>(new Hooker());

        return pObj;
    }

    void Hooker::Attach()
    {
        const auto dxgiScanner = signature_scanner::ModuleScanner("dxgi.dll");

        const auto swapChainPresentFunction = dxgiScanner.FindPattern("? ? ? ? ? 48 89 74 24 ? 55 57 41 56 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 60");

        assert(swapChainPresentFunction.has_value());

        MH_CreateHook((void*)swapChainPresentFunction.value(), hPresent, (LPVOID*)&oPresent);
        MH_EnableHook((void*)swapChainPresentFunction.value());
        oWndProc = (uintptr_t)(SetWindowLongPtr(FindWindowA(nullptr, "Counter-Strike 2"),
                                                GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(hWndProc)));
    }

    void Hooker::Detach()
    {
        SetWindowLongPtr(FindWindowA(nullptr, "Counter-Strike 2"),
                         GWLP_WNDPROC, (LONG_PTR)(oWndProc));

        MH_DisableHook(MH_ALL_HOOKS);
    }

    Hooker::~Hooker()
    {
        MH_Uninitialize();
    }

    Hooker::Hooker()
    {
        MH_Initialize();
    }
} // hooks