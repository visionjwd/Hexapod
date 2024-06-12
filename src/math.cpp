#include <Arduino.h>
#include "Header.h"


#define LEN1 45
#define LEN2 73
#define LEN3 155

//V3
#pragma region V3
V3::V3(float xx, float yy, float zz) : x(xx), y(yy), z(zz){}

//opertor overloads

V3 V3::operator+(const V3 &input) const
{
    return V3(x + input.x, y + input.y, z + input.z);
}
V3 V3::operator-(const V3 &input) const
{
    return V3(x - input.x, y - input.y, z - input.z);
}
V3 V3::operator*(const float &scalar) const
{
    return V3(x * scalar, y * scalar, z * scalar);
}
V3 V3::operator/(const float &scalar) const
{
    return V3(x / scalar, y / scalar, z / scalar);
}
V3 &V3::operator=(const V3 &input)
{
    if (this != &input)
    {
        x = input.x;
        y = input.y;
        z = input.z;
    }
    return *this;
}
float V3::magnitude() const
{
    return sqrt(x*x + y*y + z*z);
}
float V3::xscorr() const
{
    return (x-LEN1)*(x-LEN1);
}
float V3::ys() const
{
    return y*y;
}
float V3::zs() const
{
    return z*z;
}
V3 V3::lerp(const V3 &start, const V3 &end, const float &t)
{
    
}
#pragma endregion

//V2
#pragma region V2

V2::V2(float xx, float yy) : x(xx), y(yy)
{
}
V2 V2::operator+(const V2 &input) const
{
     return V2(x + input.x, y + input.y);
}
V2 V2::operator-(const V2 &input) const
{
    return V2(x - input.x, y - input.y);
}
V2 V2::operator*(const float &value) const
{
    return V2(x * value, y * value);
}
V2 V2::operator/(const float &value) const
{
    return V2(x / value, y / value);
}
V2 &V2::operator=(const V2 &input)
{
    if (this != &input)
    {
        x = input.x;
        y = input.y;
    }
    return *this;
}


#pragma endregion