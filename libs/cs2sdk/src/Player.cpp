//
// Created by Vlad on 29.09.2023.
//

#include "cs2sdk/Player.h"

namespace cs2_sdk
{
    namespace
    {
        constexpr std::ptrdiff_t offsetHealth = 0x32C;
    }


    int Player::GetHealth() const
    {
        return GetByOffset<int>(offsetHealth);
    }
} // cs2_sdk