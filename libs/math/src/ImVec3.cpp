#include "math/ImVec3.h"
#include <cmath>


namespace math
{
    ImVec3::ImVec3(float x, float y, float z) : ImVec2(x, y)
    {
        this->z = z;
    }

    ImVec3::ImVec3(ImVec2 &vec2)
    {
        this->x = vec2.x;
        this->y = vec2.y;
    }

    bool ImVec3::operator==(const ImVec3 &src) const
    {
        return (src.x == x) && (src.y == y) && (src.z == z);
    }

    bool ImVec3::operator!=(const ImVec3 &src) const
    {
        return (src.x != x) || (src.y != y) || (src.z != z);
    }

    ImVec3 &ImVec3::operator+=(const ImVec3 &v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    ImVec3 &ImVec3::operator-=(const ImVec3 &v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    ImVec3 &ImVec3::operator+=(const ImVec2 &v)
    {
        this->x += v.x;
        this->y += v.y;

        return *this;
    }

    ImVec3 &ImVec3::operator*=(float fl)
    {
        x *= fl;
        y *= fl;
        z *= fl;
        return *this;
    }

    ImVec3 &ImVec3::operator*=(const ImVec3 &v)
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
    }

    ImVec3 &ImVec3::operator/=(const ImVec3 &v)
    {
        x /= v.x;
        y /= v.y;
        z /= v.z;
        return *this;
    }

    ImVec3 &ImVec3::operator+=(float fl)
    {
        x += fl;
        y += fl;
        z += fl;
        return *this;
    }

    ImVec3 &ImVec3::operator/=(float fl)
    {
        x /= fl;
        y /= fl;
        z /= fl;
        return *this;
    }

    ImVec3 &ImVec3::operator-=(float fl)
    {
        x -= fl;
        y -= fl;
        z -= fl;
        return *this;
    }

    float ImVec3::DistTo(const ImVec3 &vOther) const
    {
        ImVec3 delta;

        delta.x = x - vOther.x;
        delta.y = y - vOther.y;
        delta.z = z - vOther.z;

        return delta.Length();
    }

    float ImVec3::DistToSqr(const ImVec3 &vOther) const
    {
        ImVec3 delta;

        delta.x = x - vOther.x;
        delta.y = y - vOther.y;
        delta.z = z - vOther.z;

        return delta.LengthSqr();
    }

    float ImVec3::Dot(const ImVec3 &vOther) const
    {
        return (x * vOther.x + y * vOther.y + z * vOther.z);
    }

    float ImVec3::Length() const
    {
        return sqrt(x * x + y * y + z * z);
    }

    float ImVec3::LengthSqr(void) const
    {
        return (x * x + y * y + z * z);
    }

    float ImVec3::Length2D() const
    {
        return sqrt(x * x + y * y);
    }

    ImVec3 &ImVec3::operator=(const ImVec3 &vOther)
    {
        x = vOther.x;
        y = vOther.y;
        z = vOther.z;
        return *this;
    }

    ImVec3 ImVec3::operator-(void) const
    {
        return ImVec3(-x, -y, -z);
    }

    ImVec3 ImVec3::operator+(const ImVec3 &v) const
    {
        return {x + v.x, y + v.y, z + v.z};
    }

    ImVec3 ImVec3::operator-(const ImVec3 &v) const
    {
        return {x - v.x, y - v.y, z - v.z};
    }

    ImVec3 ImVec3::operator*(float fl) const
    {
        return {x * fl, y * fl, z * fl};
    }

    ImVec3 ImVec3::operator*(const ImVec3 &v) const
    {
        return {x * v.x, y * v.y, z * v.z};
    }

    ImVec3 ImVec3::operator/(float fl) const
    {
        return {x / fl, y / fl, z / fl};
    }

    ImVec3 ImVec3::operator/(const ImVec3 &v) const
    {
        return {x / v.x, y / v.y, z / v.z};
    }

    ImVec3 ImVec3::Normalize() const
    {
        return *this / Length();
    }
}