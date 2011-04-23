#include <cmath>
#include "maths/vector3.h"


// Constructors

// Zero Vector
Vector3::Vector3()
    : m_x(0.f), m_y(0.f), m_z(0.f)
{ }

Vector3::Vector3(float _x, float _y, float _z)
    : m_x(_x), m_y(_y), m_z(_z)
{ }


// Accessors

// Scalar product
float Vector3::dot(const Vector3& _rhs) const
{
    return m_x * _rhs.m_x + m_y * _rhs.m_y + m_z * _rhs.m_z;
}

// Magnitude
float Vector3::magnitude()
{
    return sqrt(magnitudeSquared());
}

// Squared magnitude
float Vector3::magnitudeSquared()
{
    return m_x*m_x + m_y*m_y + m_z*m_z;
}

// Return unit vector
Vector3 Vector3::normalised()
{
    Vector3 v = (*this);
    float m = magnitude();
    v.m_x /= m;
    v.m_y /= m;
    v.m_z /= m;
    return v;
}

Vector3 Vector3::cross(Vector3 _rhs)
{
    return Vector3(m_y * _rhs.m_z - m_z * _rhs.m_y,
                   m_z * _rhs.m_x - m_x * _rhs.m_z,
                   m_x * _rhs.m_y - m_y * _rhs.m_x);
}


// Modifiers

// Normalise this vector
void Vector3::normalise()
{
    float m = magnitude();
    m_x /= m;
    m_y /= m;
    m_z /= m;
}


// Operators

// Assignment
Vector3& Vector3::operator = (const Vector3& _rhs)
{
    m_x = _rhs.m_x;
    m_y = _rhs.m_y;
    m_z = _rhs.m_z;
    return (*this);
}

// Equality
bool Vector3::operator == (const Vector3& _rhs)
{
    return 
    m_x == _rhs.m_x &&
    m_y == _rhs.m_y &&
    m_z == _rhs.m_z;
}

// Compound addition
Vector3& Vector3::operator += (const Vector3& _rhs)
{
    m_x += _rhs.m_x;
    m_y += _rhs.m_y;
    m_z += _rhs.m_z;
    return (*this);
}

// Compound subtraction
Vector3& Vector3::operator -= (const Vector3& _rhs)
{
    m_x -= _rhs.m_x;
    m_y -= _rhs.m_y;
    m_z -= _rhs.m_z;
    return (*this);
}

// Addition
Vector3  Vector3::operator +  (const Vector3& _rhs) const
{
    Vector3 lhs = (*this);
    lhs += _rhs;
    return lhs;
}


// Subtraction
Vector3  Vector3::operator -  (const Vector3& _rhs) const
{
    Vector3 lhs = (*this);
    lhs -= _rhs;
    return lhs;
}

// Compound division by scalar
Vector3& Vector3::operator /= (const float& _rhs)
{
    m_x /= _rhs;
    m_y /= _rhs;
    m_z /= _rhs;
    return (*this);
}

// Compound multiplication by scalar
Vector3& Vector3::operator *= (const float& _rhs)
{
    m_x *= _rhs;
    m_y *= _rhs;
    m_z *= _rhs;
    return (*this);
}

// Division by scalar
Vector3  Vector3::operator /  (const float& _rhs) const
{
    Vector3 lhs = (*this);
    lhs /= _rhs;
    return lhs;
}

// Multiplication by scalar
Vector3  Vector3::operator *  (const float& _rhs) const
{
    Vector3 lhs = (*this);
    lhs *= _rhs;
    return lhs;
}