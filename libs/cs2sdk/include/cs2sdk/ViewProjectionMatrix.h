//
// Created by Vlad on 03.10.2023.
//

#pragma once

#include <memory>
#include <optional>
#include <math/matrix.h>


struct ImVec2;

namespace math
{
    class  ImVec3;
}

namespace cs2_sdk
{


    class ViewProjectionMatrix : public math::matrix
    {
    public:
        ViewProjectionMatrix() = delete;

        [[nodiscard]] static ViewProjectionMatrix Get();

        [[nodiscard]] std::optional<ImVec2> WorldToScreen(const math::ImVec3& worldPosition,const ImVec2& screenSize) const;

    private:
        ViewProjectionMatrix(size_t rows, size_t columns, float *pRaw);
    };

} // cs2_sdk
