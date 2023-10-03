//
// Created by Vlad on 29.09.2023.
//

#pragma once

struct IDXGISwapChain;
struct ID3D11DeviceContext;
struct ID3D11RenderTargetView;


namespace overlay
{

    class Overlay
    {
    public:
        explicit Overlay(IDXGISwapChain* pChain);
        ~Overlay();
        void Render();
    private:
        ID3D11DeviceContext* m_pDeviceContext = nullptr;
        ID3D11RenderTargetView* m_pMainView;
    };

} // overlay
