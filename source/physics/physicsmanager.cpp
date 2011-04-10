#include "main/component.h"
#include "physics/physicsmanager.h"

void PhysicsManager::setup()
{

}

void PhysicsManager::update(float _deltaTime)
{
    std::vector<Component *>::iterator ppBody;
    for(ppBody = m_pComponents.begin(); ppBody != m_pComponents.end(); ++ppBody)
    {
        (*ppBody)->update(_deltaTime);
    }
}

void PhysicsManager::destroy()
{

}