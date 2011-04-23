/*
    AABB
    Axis Aligned Bounding Box
    Hazel McKendrick 2011
*/

#pragma once

#include <cmath>
#include "maths/vector3.h"
#include "physics/collider.h"

class AABB : public Collider
{
public:
    // Constructors
    AABB();
    AABB(Vector3 _position, Vector3 _scale);

    // Extents of the box
    Vector3 m_radii;
};