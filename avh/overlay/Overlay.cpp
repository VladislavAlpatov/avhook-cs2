//
// Created by Vlad on 29.09.2023.
//

#include "Overlay.h"

#include <cs2sdk/EntityList.h>
#include <cs2sdk/Player.h>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_dx11.h>
#include <imgui/imgui_impl_win32.h>
#include <imgui/imgui_freetype.h>

#include <cs2sdk/ViewProjectionMatrix.h>

#include <d3d11.h>



namespace overlay
{
    Overlay::Overlay(IDXGISwapChain *pChain)
    {

        ID3D11Device* pDevice = nullptr;

        pChain->GetDevice(__uuidof(ID3D11Device), (PVOID*)&pDevice);

        ID3D11Texture2D* pBackBuffer;
        pChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);

        D3D11_RENDER_TARGET_VIEW_DESC rtv_desc = {};
        rtv_desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        rtv_desc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;

        pDevice->CreateRenderTargetView(pBackBuffer, &rtv_desc, &m_pMainView);

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
        io.Fonts->AddFontFromFileTTF(R"(C:\Windows\Fonts\verdanab.ttf)", 13.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());

    }

    void Overlay::Render()
    {
        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        ImGui::GetForegroundDrawList()->AddText(ImVec2(), ImColor(255, 0, 0),
                                                "Press 'INSERT' key to open / close the menu."
                                                " Use mouse to navigate in menu.");
        if (m_show)
        {
            ImGui::Begin("Example window");
            {

                ImGui::End();
            }
        }

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