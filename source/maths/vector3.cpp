#pragma once

#include <cmath>
#include "maths/vector3.h"

Vector3::Vector3()
    : x(0.f), y(0.f), z(0.f)
{ }

Vector3::Vector3(float _x, float _y, float _z)
    : x(_x), y(_y), z(_z)
{ }

Vector3& Vector3::operator = (const Vector3& _rhs)
{
    x = _rhs.x;
    y = _rhs.y;
    z = _rhs.z;
    return (*this);
}

bool Vector3::operator == (const Vector3& _rhs)
{
    return 
    x == _rhs.x &&
    y == _rhs.y &&
    z == _rhs.z;
}

Vector3& Vector3::operator += (const Vector3& _rhs)
{
    x += _rhs.x;
    y += _rhs.y;
    z += _rhs.z;
    return (*this);
}

Vector3& Vector3::operator -= (const Vector3& _rhs)
{
    x -= _rhs.x;
    y -= _rhs.y;
    z -= _rhs.z;
    return (*this);
}

Vector3  Vector3::operator +  (const Vector3& _rhs) const
{
    Vector3 lhs = (*this);
    lhs += _rhs;
    return lhs;
}

Vector3  Vector3::operator -  (const Vector3& _rhs) const
{
    Vector3 lhs = (*this);
    lhs -= _rhs;
    return lhs;
}

Vector3& Vector3::operator /= (const float& _rhs)
{
    x /= _rhs;
    y /= _rhs;
    z /= _rhs;
    return (*this);
}

Vector3& Vector3::operator *= (const float& _rhs)
{
    x *= _rhs;
    y *= _rhs;
    z *= _rhs;
    return (*this);
}

Vector3  Vector3::operator /  (const float& _rhs) const
{
    Vector3 lhs = (*this);
    lhs /= _rhs;
    return lhs;
}

Vector3  Vector3::operator *  (const float& _rhs) const
{
    Vector3 lhs = (*this);
    lhs *= _rhs;
    return lhs;
}

float Vector3::dot(const Vector3& _rhs) const
{
    return x * _rhs.x + y * _rhs.y + z * _rhs.z;
}

float Vector3::magnitude()
{
    return sqrt(x*x + y*y + z*z);
}

void Vector3::normalise()
{
    float m = magnitude();
    x /= m;
    y /= m;
    z /= m;
}