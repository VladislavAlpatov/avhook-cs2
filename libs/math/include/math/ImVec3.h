#pragma once
#include <imgui/imgui.h>
namespace math
{
    class ImVec3 : public ImVec2
    {
    public:
        float z = 0;

        ImVec3(float x, float y, float z);

        ImVec3() = default;

        explicit ImVec3(ImVec2 &vec2);

        bool operator==(const ImVec3 &src) const;

        bool operator!=(const ImVec3 &src) const;

        ImVec3 &operator+=(const ImVec3 &v);

        ImVec3 &operator-=(const ImVec3 &v);

        ImVec3 &operator+=(const ImVec2 &v);

        ImVec3 &operator*=(float fl);

        ImVec3 &operator*=(const ImVec3 &v);

        ImVec3 &operator/=(const ImVec3 &v);

        ImVec3 &operator+=(float fl);

        ImVec3 &operator/=(float fl);

        ImVec3 &operator-=(float fl);

        [[nodiscard]] float DistTo(const ImVec3 &vOther) const;

        [[nodiscard]] float DistToSqr(const ImVec3 &vOther) const;

        [[nodiscard]] float Dot(const ImVec3 &vOther) const;

        [[nodiscard]] float Length() const;

        [[nodiscard]] ImVec3 Normalize() const;

        [[nodiscard]] float LengthSqr() const;

        [[nodiscard]] float Length2D() const;

        ImVec3 &operator=(const ImVec3 &vOther);

        ImVec3 operator-() const;

        ImVec3 operator+(const ImVec3 &v) const;

        ImVec3 operator-(const ImVec3 &v) const;

        ImVec3 operator*(float fl) const;

        ImVec3 operator*(const ImVec3 &v) const;

        ImVec3 operator/(float fl) const;

        ImVec3 operator/(const ImVec3 &v) const;
    };
}