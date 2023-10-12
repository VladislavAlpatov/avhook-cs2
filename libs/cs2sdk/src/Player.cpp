//
// Created by Vlad on 29.09.2023.
//

#include "cs2sdk/Player.h"
#include <math/ImVec3.h>

namespace cs2_sdk
{
    namespace
    {
        constexpr std::ptrdiff_t offsetHealth = 0x32C;
        constexpr std::ptrdiff_t offsetOrigin = 0xCD8;
        constexpr std::ptrdiff_t offsetFlags  = 0x3C8;
        constexpr std::ptrdiff_t offsetViewAngles  = 0x1158;
    }


    int Player::GetHealth() const
    {
        return GetByOffset<int>(offsetHealth);
    }

    math::ImVec3 Player::GetOrigin() const
    {
        return GetByOffset<math::ImVec3>(offsetOrigin);
    }

    uint32_t Player::GetFlags() const
    {
        return GetByOffset<uint32_t>(offsetFlags);
    }

    math::ImVec3 Player::GetViewAngles() const
    {
        return GetByOffset<math::ImVec3>(offsetViewAngles);
    }

} // cs2_sdk