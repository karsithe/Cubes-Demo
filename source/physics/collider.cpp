#include "physics/aabb.h"
#include "physics/planecollider.h"
#include "physics/contact.h"
#include "physics/collider.h"
#include "physics/contact.h"

Collider::Collider(Vector3 _position, ColliderType _type)
    : m_position(_position), m_type(_type)
{}

ColliderType Collider::getType()
{
    return m_type;
}

bool Collider::test(Collider* _col, Contact* _contact)
{
    switch(_col->getType())
    {
    case COLLIDER_AABB:
        return testAABB(dynamic_cast<AABB*>(_col), _contact);
    case COLLIDER_PLANE:
        return testPlane(dynamic_cast<PlaneCollider*>(_col), _contact);
    }

    return false;
}
