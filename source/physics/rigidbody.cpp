
#include "main/transform.h"
#include "main/entity.h"
#include "physics/aabb.h"
#include "physics/physicsmanager.h"
#include "physics/rigidbody.h"

void RigidBody::setup()
{
    m_AABB = AABB(m_transform.m_position, m_transform.m_scale * 0.5f); 
}

void RigidBody::update(float _deltaTime)
{
    m_transform = m_pParent->getTransform();

    if(m_transform.m_position.y > m_pPhysics->m_floorY)
        m_velocity.y += m_pPhysics->m_gravity * _deltaTime;
    else
    {
        m_velocity = m_velocity - Vector3(0.f,-1.f,0.f) * (m_velocity.dot( Vector3(0.f,-1.f,0.f ))) * (1.5f);
        m_transform.m_position.y = m_pPhysics->m_floorY;
    }

    m_transform.m_position.y += m_velocity.y;

    m_pParent->setTransform(m_transform);
    m_AABB.m_position = m_transform.m_position;
}

void RigidBody::destroy()
{

}

void RigidBody::setManager(Manager* _manager)
{
    m_pManager = _manager;
    m_pPhysics = dynamic_cast<PhysicsManager*>(_manager);
}

AABB RigidBody::getAABB()
{
    return m_AABB;
}