/*
    Plane Collider
    Infinite plane
*/

#pragma once

#include <cmath>
#include "maths/vector3.h"
#include "physics/collider.h"

class PlaneCollider : public Collider
{
public:
    // Constructors
    PlaneCollider();
    PlaneCollider(Vector3 _position, Vector3 _normal);

    // Plane normal
    Vector3 m_normal;
};