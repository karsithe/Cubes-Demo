/*
    Vector3
    3D floating point vector and related functions
    Hazel McKendrick 2011
*/

#pragma once

class Vector3
{
public: 
    // Constructors
    Vector3();
    Vector3(float _x, float _y, float _z);

    // Accessors
    float dot(const Vector3& _rhs) const;
    float magnitude();
    float magnitudeSquared();
    Vector3 normalised();
    Vector3 cross(Vector3 _rhs);

    // Modifiers
    void normalise();

    // Operators
    Vector3& operator =  (const Vector3& _rhs);
    bool     operator == (const Vector3& _rhs);

    Vector3& operator += (const Vector3& _rhs);
    Vector3& operator -= (const Vector3& _rhs);
    Vector3  operator +  (const Vector3& _rhs) const;
    Vector3  operator -  (const Vector3& _rhs) const;

    Vector3& operator /= (const float& _rhs);
    Vector3& operator *= (const float& _rhs);
    Vector3  operator /  (const float& _rhs) const;
    Vector3  operator *  (const float& _rhs) const;

    // Data
    float m_x, m_y, m_z;
};