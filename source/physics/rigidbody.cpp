
#include "main/transform.h"
#include "main/entity.h"
#include "physics/collider.h"
#include "physics/aabb.h"
#include "physics/planecollider.h"
#include "physics/physicsmanager.h"
#include "physics/rigidbody.h"
#include "physics/contact.h"

RigidBody::RigidBody(ColliderType _type)
    : m_colliderType(_type)
{
    m_body.m_mass = 1.f;
    m_body.m_inverseMass = 1.f;
    m_body.m_velocity = Vector3();
}

void RigidBody::setup()
{
    m_body.m_position = m_pParent->getTransform().m_position;

    switch(m_colliderType)
    {
    case COLLIDER_AABB:
        m_body.m_static = false;
        m_pBroadCollider = new AABB(m_body.m_position, m_pParent->getTransform().m_scale * 0.5f);
        break;
    case COLLIDER_PLANE:
        m_body.m_static = true;
        m_body.m_mass = 100.f;
        m_body.m_inverseMass = 1.f/m_body.m_mass;
        m_pBroadCollider = new PlaneCollider(m_body.m_position, Vector3(0,-1,0));
        break;
    }    
}

void RigidBody::applyForces(float _deltaTime)
{
    if(!m_body.m_static)
        m_body.m_gatheredForce += Vector3(0.f,1.f,0.f) * m_pPhysics->m_gravity;

    m_pBroadCollider->m_position = m_body.m_position;
}

void RigidBody::update(float _deltaTime)
{
    m_body.integrateRK4(_deltaTime);

    Transform t = m_pParent->getTransform();
    t.m_position = m_body.m_position;
    m_pParent->setTransform(t);
}

void RigidBody::destroy()
{

}

void RigidBody::setManager(Manager* _manager)
{
    m_pManager = _manager;
    m_pPhysics = dynamic_cast<PhysicsManager*>(_manager);
}

void RigidBody::onCollide(Contact _contact, RigidBody* _body)
{
    if(m_body.m_static) return;

    // Normal impulse
    Vector3 relativeV = m_body.m_velocity - _body->getBody().m_velocity;
    Vector3 impulse = _contact.m_normal * (relativeV.dot(_contact.m_normal)) * (2.0f) / (m_body.m_inverseMass + _body->getBody().m_inverseMass) * -1.f;
    m_body.m_momentum += impulse;


}

Collider* RigidBody::getCollider()
{
    return m_pBroadCollider;
}

BodyState& RigidBody::getBody()
{
    return m_body;
}
