#pragma once

#include "physics/aabb.h"
#include "main/transform.h"
#include "main/component.h"

class PhysicsManager;

class RigidBody : public Component
{
public:
    RigidBody() : Component() {}

    void setup();
    void update(float _deltaTime);
    void destroy();

    void setManager(Manager* _manager);

    AABB getAABB();

private:
    PhysicsManager* m_pPhysics;
    Vector3 m_velocity;
    Transform m_transform;
    AABB m_AABB;
};