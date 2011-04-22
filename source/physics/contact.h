#pragma once

#include "maths/vector3.h"

class RigidBody;

class Contact
{
public:
    Contact()
    {}

    Contact(Vector3 _normal, float _dist)
        : m_normal(_normal), m_distance(_dist)
    {}

    RigidBody *m_bodyA, *m_bodyB;
    Vector3 m_normal;
    float m_distance;
};
