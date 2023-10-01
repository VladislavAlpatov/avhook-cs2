//
// Created by Vlad on 29.09.2023.
//

#pragma once
#include <cstddef>


namespace cs2_sdk
{
    class BaseObject
    {
    protected:

        template<class type>
        [[nodiscard]] type& GetByOffset(std::ptrdiff_t offset) const
        {
            return *(type*)((uintptr_t)this + offset);
        }
    };
}