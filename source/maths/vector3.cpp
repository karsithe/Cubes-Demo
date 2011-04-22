#pragma once

#include <cmath>
#include "maths/vector3.h"

Vector3::Vector3()
    : m_x(0.f), m_y(0.f), m_z(0.f)
{ }

Vector3::Vector3(float _x, float _y, float _z)
    : m_x(_x), m_y(_y), m_z(_z)
{ }

Vector3& Vector3::operator = (const Vector3& _rhs)
{
    m_x = _rhs.m_x;
    m_y = _rhs.m_y;
    m_z = _rhs.m_z;
    return (*this);
}

bool Vector3::operator == (const Vector3& _rhs)
{
    return 
    m_x == _rhs.m_x &&
    m_y == _rhs.m_y &&
    m_z == _rhs.m_z;
}

Vector3& Vector3::operator += (const Vector3& _rhs)
{
    m_x += _rhs.m_x;
    m_y += _rhs.m_y;
    m_z += _rhs.m_z;
    return (*this);
}

Vector3& Vector3::operator -= (const Vector3& _rhs)
{
    m_x -= _rhs.m_x;
    m_y -= _rhs.m_y;
    m_z -= _rhs.m_z;
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
    m_x /= _rhs;
    m_y /= _rhs;
    m_z /= _rhs;
    return (*this);
}

Vector3& Vector3::operator *= (const float& _rhs)
{
    m_x *= _rhs;
    m_y *= _rhs;
    m_z *= _rhs;
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
    return m_x * _rhs.m_x + m_y * _rhs.m_y + m_z * _rhs.m_z;
}

float Vector3::magnitude()
{
    return sqrt(m_x*m_x + m_y*m_y + m_z*m_z);
}

void Vector3::normalise()
{
    float m = magnitude();
    m_x /= m;
    m_y /= m;
    m_z /= m;
}