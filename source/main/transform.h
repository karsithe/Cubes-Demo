#pragma once

#include "maths/vector3.h"

struct Transform
{
    Vector3 m_position;
    Vector3 m_scale;
    Vector3 m_rotation;

    Transform()
        : m_position(0.f, 0.f, 0.f), m_scale(1.f, 1.f, 1.f), m_rotation(0.f, 0.f, 0.f)
    {
    }
};