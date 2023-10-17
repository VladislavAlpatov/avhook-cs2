//
// Created by Vlad on 10.10.2023.
//

#include "BaseWindow.h"

void overlay::window::BaseWindow::Toggle()
{
    m_show = !m_show;
}

void overlay::window::BaseWindow::Show()
{
    m_show = true;
}

void overlay::window::BaseWindow::Hide()
{
    m_show = false;
}
