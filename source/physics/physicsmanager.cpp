#include "main/component.h"
#include "physics/rigidbody.h"
#include "physics/contact.h"
#include "physics/physicsmanager.h"

void PhysicsManager::setup()
{
    m_gravity = -0.1f;
    m_floorY = -10.f;

    std::vector<Component *>::iterator ppBody;
    for(ppBody = m_pComponents.begin(); ppBody != m_pComponents.end(); ++ppBody)
    {
        (*ppBody)->setup();
    }
}

void PhysicsManager::update(float _deltaTime)
{
    std::vector<RigidBody *>::iterator ppBody;
    for(ppBody = m_pBodies.begin(); ppBody != m_pBodies.end(); ++ppBody)
    {
        (*ppBody)->applyExternalForces(_deltaTime);
    }

    bruteForceCollision();

    for(ppBody = m_pBodies.begin(); ppBody != m_pBodies.end(); ++ppBody)
    {
        (*ppBody)->update(_deltaTime);
    }
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

void PhysicsManager::addComponent(Component* _pComponent)
{
    _pComponent->setManager(this);
    m_pComponents.push_back(_pComponent);
    m_pBodies.push_back(dynamic_cast<RigidBody*>(_pComponent));
}

void PhysicsManager::bruteForceCollision()
{
    for(int i = 0; i < m_pBodies.size()-1; ++i )
    {
        for(int j = i+1; j < m_pBodies.size(); ++j)
        {
            if(m_pBodies[i] != m_pBodies[j])
            {
                Contact c;
                if( m_pBodies[i]->getCollider()->test( m_pBodies[j]->getCollider(), &c ) )
                {
                    m_pBodies[i]->onCollide(c, m_pBodies[j]->getMass(), m_pBodies[j]->getVelocity());
                    m_pBodies[j]->onCollide(c, m_pBodies[i]->getMass(), m_pBodies[i]->getVelocity());
                }
            }
        }
    }
}