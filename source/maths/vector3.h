/*
    Vector3
    3D floating point vector and related functions
    Hazel McKendrick 2011
*/


#pragma once

class Vector3
{
public: 
    float x, y, z;

    Vector3();
    Vector3(float _x, float _y, float _z);

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
};