#pragma once

#include <vector>
#include "main/manager.h"

class RigidBody;

class PhysicsManager : public Manager
{
public:
    void setup();
    void update(float _deltaTime);
    void destroy();

    void addComponent(Component* _pComponent);

    float m_gravity;
    float m_floorY;

private:
    void fixedUpdate(float _deltaTime);
    void bruteForceCollision();

    std::vector<RigidBody*> m_pBodies;

    float m_fixedDeltaTime;
    float m_timeAccumulator;
};