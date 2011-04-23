/*
    Collider
    Base class for collider shapes
    Hazel McKendrick 2011
*/

#pragma once

#include "physics/contact.h"
#include "maths/vector3.h"

class AABB;
class PlaneCollider;

enum ColliderType
{
    COLLIDER_NONE,
    COLLIDER_AABB,
    COLLIDER_PLANE
};

class Collider
{
public:
    // Constructor
    Collider(Vector3 _position, ColliderType _type);

    // Collision tests
    static bool test(const Collider* _pCol1, const Collider* _pCol2, Contact* _contact = 0);

    // Data
    Vector3 m_position;
    RigidBody* m_pParent;
    ColliderType m_type;

private:
    // Collision tests
    static bool test(const AABB* _pAABB1, const AABB* _pAABB2, Contact* _contact);
    static bool test(const PlaneCollider* _pPlane, const AABB* _pAABB, Contact* _contact);
};