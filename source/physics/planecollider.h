#pragma once

#include <cmath>
#include "maths/vector3.h"
#include "physics/collider.h"

class AABB;
class Contact;

class PlaneCollider : public Collider
{
public:
    PlaneCollider();

    PlaneCollider(Vector3 _position, Vector3 _normal);

    bool testAABB(AABB* _col, Contact* _contact);

    bool testPlane(PlaneCollider* _col, Contact* _contact);

    Vector3 m_normal;
};