#pragma once

#include "physics/contact.h"
#include "maths/vector3.h"

enum ColliderType
{
    COLLIDER_AABB,
    COLLIDER_PLANE
};

class AABB;
class PlaneCollider;

class Collider
{
public:
    Collider(Vector3 _position, ColliderType _type);

    ColliderType getType();

    bool test(Collider* _col, Contact* _contact = 0);
    virtual bool testAABB(AABB* _col, Contact* _contact) = 0;
    virtual bool testPlane(PlaneCollider* _col, Contact* _contact) = 0;

    Vector3 m_position;

protected:
    ColliderType m_type;

};