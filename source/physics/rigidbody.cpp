
#include "main/transform.h"
#include "main/entity.h"
#include "physics/physicsmanager.h"
#include "physics/rigidbody.h"

void RigidBody::setup()
{
}

void RigidBody::update(float _deltaTime)
{
    m_pTransform = m_pParent->getTransform();

    if(m_pTransform.m_position.y > m_pPhysics->m_floorY)
        m_velocity.y += m_pPhysics->m_gravity * _deltaTime;
    else
        m_velocity.y = 0.f;
    
    m_pTransform.m_position.y += m_velocity.y;

    m_pParent->setTransform(m_pTransform);
}

void RigidBody::destroy()
{

}

void RigidBody::setManager(Manager* _manager)
{
    m_pManager = _manager;
    m_pPhysics = dynamic_cast<PhysicsManager*>(_manager);
}

Vector3 RigidBody::getAABBStart()
{
    return m_pTransform.m_position - m_pTransform.m_scale * 0.5f;
}

Vector3 RigidBody::getAABBEnd()
{
    return m_pTransform.m_position + m_pTransform.m_scale * 0.5f;
}