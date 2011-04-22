#pragma once

#include "main/transform.h"
#include "main/component.h"
#include "physics/collider.h"
#include "physics/contact.h"

class PhysicsManager;

class RigidBody : public Component
{
public:
    RigidBody(ColliderType m_type = COLLIDER_AABB, float _mass = 1.f, bool _applyGravity = true);

    void setup();
    void applyExternalForces(float _deltaTime);
    void update(float _deltaTime);
    void destroy();

    void onCollide(Contact _contact, RigidBody* _body);

    void setManager(Manager* _manager);
    
    Collider* getCollider();
    Transform getTransform();
    float getMass();
    float getInverseMass();
    Vector3 getVelocity();

private:
    void recalculateVelocity();

    PhysicsManager* m_pPhysics;

    Vector3 m_velocity;
    Transform m_transform;
    Vector3 m_momentum;

    float m_mass;
    float m_inverseMass;

    bool m_static;

    ColliderType m_colliderType;
    Collider* m_pCollider;
};