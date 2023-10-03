//
// Created by Vlad on 29.09.2023.
//

#pragma once

#include <cstddef>
#include <cstdint>

#include "BaseObject.h"

namespace math
{
    class ImVec3;
}
namespace cs2_sdk
{
    class Player : public BaseObject
    {
    public:
        [[nodiscard]] int GetHealth() const;
        [[nodiscard]] math::ImVec3 GetOrigin() const;
    };

} // cs2_sdk
