#pragma once

#include <cmath>
#include "maths/vector3.h"
#include "physics/collider.h"
#include "physics/planecollider.h"
#include "physics/contact.h"

class AABB : public Collider
{
public:
    AABB();

    AABB(Vector3 _position, Vector3 _scale);

    Vector3 m_radii;

    bool testAABB(AABB* _col, Contact* _contact);

    bool testPlane(PlaneCollider* _col, Contact* _contact);
};