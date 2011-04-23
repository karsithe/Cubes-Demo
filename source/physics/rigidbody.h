#pragma once

#include "main/transform.h"
#include "main/component.h"
#include "physics/collider.h"
#include "physics/contact.h"
#include "physics/bodystate.h"

class PhysicsManager;

class RigidBody : public Component
{
public:
    RigidBody(ColliderType m_type = COLLIDER_AABB);

    void setup();
    void applyForces(float _deltaTime);
    void update(float _deltaTime);
    void destroy();

    void onCollide(Contact _contact, RigidBody* _body);

    void setManager(Manager* _manager);
    
    Collider* getCollider();
    BodyState& getBody();

private:
    PhysicsManager* m_pPhysics;

    BodyState m_body;

    ColliderType m_colliderType;
    Collider* m_pBroadCollider;
    Collider* m_pNarrowCollider;
};