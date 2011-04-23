
#include <cmath>
#include "maths/quaternion.h"
#include "maths/vector3.h"

// Constructors

Quaternion::Quaternion()
    : m_x(0.f), m_y(0.f), m_z(0.f), m_w(1.f)
{
    // Set to rotation identity quaternion
} 

Quaternion::Quaternion(float _x, float _y, float _z, float _w)
    : m_x(_x), m_y(_y), m_z(_z), m_w(_w)
{

}


// Accessors

// Get exact magnitude
float Quaternion::magnitude()
{
    return std::sqrt(magnitudeSquared());
}

// Squared magnitude is sufficient for some tests
float Quaternion::magnitudeSquared()
{
    return m_x*m_x + m_y*m_y + m_z*m_z + m_w*m_w;
}

// Return the normalised version of this quaternion
Quaternion Quaternion::normalised()
{
    return (*this) / magnitude();
}


// Modifiers

// Normalise this quaternion
void Quaternion::normalise()
{
    Quaternion q = this->normalised();
    (*this) = q;
}


// Operators

// Assignment
Quaternion& Quaternion::operator = (const Quaternion& _rhs)
{
    m_x = _rhs.m_x;
    m_y = _rhs.m_y;
    m_z = _rhs.m_z;
    m_w = _rhs.m_w;
    return (*this);
}

// Equality
bool Quaternion::operator == (const Quaternion& _rhs)
{
    return 
    m_x == _rhs.m_x &&
    m_y == _rhs.m_y &&
    m_z == _rhs.m_z &&
    m_w == _rhs.m_w;
}

// Compound multiplication
Quaternion& Quaternion::operator *= (const Quaternion& _rhs)
{
    m_w = m_w * _rhs.m_w - m_x * _rhs.m_x - m_y * _rhs.m_y - m_z * _rhs.m_z;
    m_x = m_w * _rhs.m_x - m_x * _rhs.m_w - m_y * _rhs.m_z - m_z * _rhs.m_y;
    m_y = m_w * _rhs.m_y - m_x * _rhs.m_z - m_y * _rhs.m_w - m_z * _rhs.m_x;
    m_z = m_w * _rhs.m_z - m_x * _rhs.m_y - m_y * _rhs.m_x - m_z * _rhs.m_w;
    return (*this);
}

// Compound addition
Quaternion& Quaternion::operator += (const Quaternion& _rhs)
{
    m_w += _rhs.m_w;
    m_x += _rhs.m_x;
    m_y += _rhs.m_y;
    m_z += _rhs.m_z;
    return (*this);
}

// Multiplication
Quaternion  Quaternion::operator *  (const Quaternion& _rhs) const
{
    Quaternion q = (*this);
    q *= _rhs;
    return q;
}

// Addition
Quaternion  Quaternion::operator +  (const Quaternion& _rhs) const
{
    Quaternion q = (*this);
    q += _rhs;
    return q;
}

// Compound devision by scalar
Quaternion& Quaternion::operator /= (const float& _rhs)
{
    m_x /= _rhs;
    m_y /= _rhs;
    m_z /= _rhs;
    m_w /= _rhs;
    return (*this);
}

// Compound multiplication by scalar
Quaternion& Quaternion::operator *= (const float& _rhs)
{
    m_x *= _rhs;
    m_y *= _rhs;
    m_z *= _rhs;
    m_w *= _rhs;
    return (*this);
}

// Division by scalar
Quaternion  Quaternion::operator /  (const float& _rhs) const
{
    Quaternion q = (*this);
    q /= _rhs;
    return q;
}

// Multiplication by scalar
Quaternion  Quaternion::operator *  (const float& _rhs) const
{
    Quaternion q = (*this);
    q *= _rhs;
    return q;
}
