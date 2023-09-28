//
// Created by Vlad on 29.09.2023.
//

#include <D3D11.h>
#include "Overlay.h"

#include <imgui/imgui.h>

#include <imgui/imgui_impl_dx11.h>
#include <imgui/imgui_impl_win32.h>


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
        auto  window    = sd.OutputWindow;
        pDevice->GetImmediateContext(&m_pDeviceContext);
        ImGui_ImplWin32_Init(window);
        ImGui_ImplDX11_Init(pDevice, m_pDeviceContext);
    }

    void Overlay::Render()
    {
        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Super cool cheat menu");
        {
            ImGui::TextColored(ImColor(255, 77, 77),"Some colored text!");
            ImGui::End();
        }


        ImGui::EndFrame();
        ImGui::Render();
        m_pDeviceContext->OMSetRenderTargets(1, &m_pMainView, nullptr);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
    }
} // overlay