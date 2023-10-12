//
// Created by Vlad on 10.10.2023.
//

#pragma once


namespace overlay::window
{
    class IBaseDrawable
    {
    public:
        virtual void Render() = 0;
    };
}