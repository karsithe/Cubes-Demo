/*
    Transform
    Position and orientation of an object in space
    Hazel McKendrick 2011
*/

#pragma once

#include "maths/vector3.h"

class Transform
{
public:
    Transform(Vector3 _position = Vector3(), Vector3 _scale = Vector3(1.f, 1.f, 1.f), Vector3 _rotation = Vector3())
        : m_position(_position), m_scale(_scale), m_rotation(_rotation)
    {
    }

    Vector3 m_position;
    Vector3 m_scale;
    Vector3 m_rotation;
};