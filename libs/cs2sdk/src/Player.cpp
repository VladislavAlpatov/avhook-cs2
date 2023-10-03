//
// Created by Vlad on 29.09.2023.
//

#include "cs2sdk/Player.h"
#include <math/ImVec3.h>

namespace cs2_sdk
{
    namespace
    {
        constexpr std::ptrdiff_t offsetHealth = 0x808;
        constexpr std::ptrdiff_t offsetOrigin = 0x12AC;
    }


    int Player::GetHealth() const
    {
        return GetByOffset<int>(offsetHealth);
    }

    math::ImVec3 Player::GetOrigin() const
    {
        return GetByOffset<math::ImVec3>(offsetOrigin);
    }
} // cs2_sdk