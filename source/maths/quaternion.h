#pragma once

class Quaternion
{
public:
    // Constructors
    Quaternion();
    Quaternion(float _x, float _y, float _z, float _w);

    // Accessors
    float magnitude();
    float magnitudeSquared();
    Quaternion normalised();

    // Modifiers
    void normalise();

    // Operators
    Quaternion& operator =  (const Quaternion& _rhs);
    bool        operator == (const Quaternion& _rhs);

    Quaternion& operator *= (const Quaternion& _rhs);
    Quaternion  operator *  (const Quaternion& _rhs) const;

    Quaternion& operator /= (const float& _rhs);
    Quaternion& operator *= (const float& _rhs);
    Quaternion  operator /  (const float& _rhs) const;
    Quaternion  operator *  (const float& _rhs) const;

    // Data
    float m_x, m_y, m_z, m_w;
};
