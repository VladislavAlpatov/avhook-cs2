//
// Created by Vlad on 29.09.2023.
//

#include <D3D11.h>
#include "Overlay.h"

#include <imgui/imgui.h>
#include <imgui/imgui_impl_dx11.h>
#include <imgui/imgui_impl_win32.h>
#include <imgui/imgui_freetype.h>


#include <cs2sdk/ViewProjectionMatrix.h>



namespace overlay
{
    Overlay::Overlay(IDXGISwapChain *pChain)
    {

        ID3D11Device* pDevice = nullptr;

        pChain->GetDevice(__uuidof(ID3D11Device), (PVOID*)&pDevice);

        ID3D11Texture2D* pBackBuffer;
        // D3DX11CreateTextureFromMemory(pDevice, RawData::AVhookLogoData, sizeof(RawData::AVhookLogoData), &m_pTexureCheatLogo);
        pChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
        pDevice->CreateRenderTargetView(pBackBuffer, nullptr, &m_pMainView);
        pBackBuffer->Release();

        DXGI_SWAP_CHAIN_DESC sd;
        pChain->GetDesc(&sd);

        ImGui::CreateContext();
        ImGuiIO& io     = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        pDevice->GetImmediateContext(&m_pDeviceContext);

        ImGui_ImplWin32_Init(sd.OutputWindow);
        ImGui_ImplDX11_Init(pDevice, m_pDeviceContext);


        ImFontConfig cfg;
        cfg.FontBuilderFlags |= ImGuiFreeTypeBuilderFlags_Monochrome | ImGuiFreeTypeBuilderFlags_MonoHinting;
        // static ImWchar ranges[] = { 0x1, 0xFFFD, 0 };


        io.Fonts->AddFontFromFileTTF(R"(C:\Windows\Fonts\verdanab.ttf)", 13.f, &cfg);

    }

    void Overlay::Render()
    {
        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        ImGui::GetForegroundDrawList()->AddText(ImVec2(), ImColor(255, 0, 0),
                                                "Press 'INSERT' key to open / close the menu. Use mouse to navigate in menu.");
        ImGui::Begin("AVhook");
        {
            const auto vpm = cs2_sdk::ViewProjectionMatrix::Get();

            auto pos = vpm.WorldToScreen({}, ImGui::GetMainViewport()->Size);

            if (pos)
                ImGui::GetForegroundDrawList()->AddText(pos.value(), ImColor(255, 255, 255), "projected");

        }
        ImGui::End();
        ImGui::EndFrame();
        ImGui::Render();
        m_pDeviceContext->OMSetRenderTargets(1, &m_pMainView, nullptr);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
    }

    Overlay::~Overlay()
    {
        ImGui_ImplDX11_Shutdown();
        ImGui_ImplWin32_Shutdown();
        ImGui::DestroyContext();

        m_pMainView->Release();
    }
} // overlay