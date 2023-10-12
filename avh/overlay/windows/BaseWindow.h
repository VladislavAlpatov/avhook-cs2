//
// Created by Vlad on 10.10.2023.
//

#pragma once
#include "IBaseDrawable.h"
#include "imgui/imgui.h"

namespace overlay::window
{
    class BaseWindow : public IBaseDrawable
    {
    public:
        void Toggle();
        void Show();
        void Hide();
    private:
        bool m_show = false;

    protected:
        static const int m_iImGuiStyle =
                ImGuiWindowFlags_NoResize |
                ImGuiWindowFlags_NoSavedSettings |
                ImGuiWindowFlags_NoTitleBar |
                ImGuiWindowFlags_NoScrollbar |
                ImGuiWindowFlags_NoScrollWithMouse;

    };

}
