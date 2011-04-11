#include "main/component.h"
#include "physics/rigidbody.h"
#include "physics/aabb.h"
#include "physics/physicsmanager.h"

void PhysicsManager::setup()
{
    m_gravity = -1.f;
    m_floorY = -10.f;

    std::vector<Component *>::iterator ppBody;
    for(ppBody = m_pComponents.begin(); ppBody != m_pComponents.end(); ++ppBody)
    {
        (*ppBody)->setup();
    }
}

void PhysicsManager::update(float _deltaTime)
{
    std::vector<Component *>::iterator ppBody;
    for(ppBody = m_pComponents.begin(); ppBody != m_pComponents.end(); ++ppBody)
    {
        (*ppBody)->update(_deltaTime);
    }

    bruteForceCollision();
}

void PhysicsManager::destroy()
{
    std::vector<Component *>::iterator ppBody;
    for(ppBody = m_pComponents.begin(); ppBody != m_pComponents.end(); ++ppBody)
    {
        (*ppBody)->destroy();
        delete (*ppBody);
    }
}

void PhysicsManager::bruteForceCollision()
{
    std::vector<Component *>::iterator ppBody1, ppBody2;
    for(ppBody1 = m_pComponents.begin(); ppBody1 != m_pComponents.end(); ++ppBody1)
    {
        for(ppBody2 = m_pComponents.begin(); ppBody2 != m_pComponents.end(); ++ppBody2)
        {
            if( dynamic_cast<RigidBody*>((*ppBody1))->getAABB().test( dynamic_cast<RigidBody*>((*ppBody2))->getAABB() ) )
            {
//                dynamic_cast<RigidBody*>((*ppBody1))->onCollide();
//                dynamic_cast<RigidBody*>((*ppBody2))->onCollide();
            }
        }
    }
}