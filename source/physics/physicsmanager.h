#pragma once

#include "main/manager.h"

class PhysicsManager : public Manager
{
public:
    void setup();
    void update(float _deltaTime);
    void destroy();

    float m_gravity;
    float m_floorY;

private:
    void bruteForceCollision();

};