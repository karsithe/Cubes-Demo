#pragma once

#include "main/component.h"

class PhysicsManager;

class RigidBody : public Component
{
public:
    void setup();
    void update(float _deltaTime);
    void destroy();

    void setManager(Manager* _manager);

    Vector3 getAABBStart();
    Vector3 getAABBEnd();

private:
    PhysicsManager* m_pPhysics;
    Vector3 m_velocity;
    Transform m_pTransform;
};