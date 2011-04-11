#pragma once

#include <cmath>
#include "maths/vector3.h"

class AABB
{
public:
    AABB() {}

    AABB(Vector3 _position, Vector3 _scale)
        : m_position(_position), m_radii(_scale)
    {}

    Vector3 m_position;
    Vector3 m_radii;

    bool test(AABB _aabb)
    {
        if (abs(m_position.x - _aabb.m_position.x) > (m_radii.x + _aabb.m_radii.x)) return false;
        if (abs(m_position.y - _aabb.m_position.y) > (m_radii.y + _aabb.m_radii.y)) return false;
        if (abs(m_position.z - _aabb.m_position.z) > (m_radii.z + _aabb.m_radii.z)) return false;
        return true;
    }
};