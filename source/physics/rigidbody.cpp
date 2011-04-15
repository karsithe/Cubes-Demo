
#include "main/transform.h"
#include "main/entity.h"
#include "physics/collider.h"
#include "physics/aabb.h"
#include "physics/planecollider.h"
#include "physics/physicsmanager.h"
#include "physics/rigidbody.h"
#include "physics/contact.h"

RigidBody::RigidBody(ColliderType _type, float _mass, bool _applyGravity)
    : m_colliderType(_type), m_mass(_mass), m_applyGravity(_applyGravity)
{

}

void RigidBody::setup()
{
    m_transform = m_pParent->getTransform();

    switch(m_colliderType)
    {
    case COLLIDER_AABB:
        m_pCollider = new AABB(m_transform.m_position, m_transform.m_scale * 0.5f);
        break;
    case COLLIDER_PLANE:
        m_pCollider = new PlaneCollider(m_transform.m_position, Vector3(0,-1,0));
        break;
    }    
}

void RigidBody::applyExternalForces(float _deltaTime)
{
    m_transform = m_pParent->getTransform();

    if(m_applyGravity)
    {
        m_velocity += Vector3(0.f,1.f,0.f) *m_pPhysics->m_gravity * _deltaTime;
    }

    m_pCollider->m_position = m_transform.m_position;
}

void RigidBody::update(float _deltaTime)
{
    m_transform.m_position += m_velocity;
    m_pParent->setTransform(m_transform);
}

void RigidBody::destroy()
{

}

void RigidBody::setManager(Manager* _manager)
{
    m_pManager = _manager;
    m_pPhysics = dynamic_cast<PhysicsManager*>(_manager);
}

void RigidBody::onCollide(Contact _contact, float _mass, Vector3 _velocity)
{
    Vector3 relativeV = m_velocity - _velocity;
    Vector3 impulse = _contact.m_normal * (relativeV.dot(_contact.m_normal)) * (1.8f) / (1/m_mass + 1/_mass);

    m_velocity -= impulse * 1/m_mass;
}

Collider* RigidBody::getCollider()
{
    return m_pCollider;
}

Transform RigidBody::getTransform()
{
    return m_transform;
}

float RigidBody::getMass()
{
    return m_mass;

}

Vector3 RigidBody::getVelocity()
{
    return m_velocity;
}