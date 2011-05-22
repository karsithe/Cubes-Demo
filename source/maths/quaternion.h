/*
    Quaternion
    "I saw every point in the three sphere, in 4D. In a color I've never seen before..." 
    Hazel McKendrick 2011
*/

#pragma once

class Vector3;    

class Quaternion
{
public:
    // Constructors
    Quaternion();
    Quaternion(float _w, float _x, float _y, float _z);

    // Accessors
    float magnitude();
    float magnitudeSquared();
    Quaternion normalised();
    Vector3 eulerAngles();

    // Modifiers
    void normalise();

    // Operators
    Quaternion& operator =  (const Quaternion& _rhs);
    bool        operator == (const Quaternion& _rhs);

    Quaternion& operator *= (const Quaternion& _rhs);
    Quaternion& operator += (const Quaternion& _rhs);
    Quaternion  operator *  (const Quaternion& _rhs) const;
    Quaternion  operator +  (const Quaternion& _rhs) const;

    Quaternion& operator /= (const float& _rhs);
    Quaternion& operator *= (const float& _rhs);
    Quaternion  operator /  (const float& _rhs) const;
    Quaternion  operator *  (const float& _rhs) const;

    // Data
    float m_w, m_x, m_y, m_z;
};


