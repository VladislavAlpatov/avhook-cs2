//
// Created by Vlad on 03.10.2023.
//

#include "cs2sdk/ViewProjectionMatrix.h"

#include <sigscanner/ModuleScanner.h>
#include <imgui/imgui.h>

namespace cs2_sdk
{
    ViewProjectionMatrix ViewProjectionMatrix::Get()
    {
        static std::shared_ptr<ViewProjectionMatrix> pViewMatrix;
        static const auto addr =
                signature_scanner::ModuleScanner("client.dll").
                FindPattern("48 8D 05 ? ? ? ? 48 8B D3 4C 8D 05 ? ? ? ? ");
        static auto localOffset = *(uint32_t*)(addr.value()+3);

        return {4, 4,(float *)(addr.value() + localOffset + 7)};
    }

    ViewProjectionMatrix::ViewProjectionMatrix(size_t rows, size_t columns, float *pRaw)
    : matrix(rows, columns, pRaw)
    {

    }

    std::optional<ImVec2> ViewProjectionMatrix::WorldToScreen(const math::ImVec3& worldPosition,
                                                              const ImVec2& screenSize) const
    {
        auto projected = (*this * worldPosition).transpose();

        if (projected.at(0,3) <= 0.f)
            return std::nullopt;

        projected /= projected.at(0, 3);


        const auto out = projected * matrix::to_screen_matrix(screenSize.x,
                                                              screenSize.y);


        return math::ImVec3(out.at(0,0),
                            out.at(0, 1),
                            out.at(0,2));
    }
} // cs2_sdk