#include "physics/contact.h"
#include "physics/aabb.h"
#include "physics/planecollider.h"
#include "physics/collider.h"

// Constructor
Collider::Collider(Vector3 _position, ColliderType _type)
    : m_position(_position), m_type(_type)
{}


// Perform correct collision test operation given the collider shapes

// Determine which test to perform
bool Collider::test(const Collider* _pCol1, const Collider* _pCol2, Contact* _contact)
{
    switch(_pCol1->m_type)
    {
    case COLLIDER_AABB:
        switch(_pCol2->m_type)
        {
        case COLLIDER_AABB:
            return test(static_cast<const AABB*>(_pCol1), static_cast<const AABB*>(_pCol2), _contact);
        case COLLIDER_PLANE:
            return test(static_cast<const PlaneCollider*>(_pCol2), static_cast<const AABB*>(_pCol1), _contact);
        }
    case COLLIDER_PLANE:
        switch(_pCol2->m_type)
        {
        case COLLIDER_AABB:
            return test(static_cast<const PlaneCollider*>(_pCol1), static_cast<const AABB*>(_pCol2), _contact);
        case COLLIDER_PLANE:
            return false;
        }
    }
    return false;
}

// AABB vs AABB
bool Collider::test(const AABB* _aabb1, const AABB* _aabb2, Contact* _contact)
{
    if (abs(_aabb1->m_position.m_x - _aabb2->m_position.m_x) > (_aabb1->m_radii.m_x + _aabb2->m_radii.m_x)) return false;
    if (abs(_aabb1->m_position.m_y - _aabb2->m_position.m_y) > (_aabb1->m_radii.m_y + _aabb2->m_radii.m_y)) return false;
    if (abs(_aabb1->m_position.m_z - _aabb2->m_position.m_z) > (_aabb1->m_radii.m_z + _aabb2->m_radii.m_z)) return false;
    
    // Collision occurred, fill in contact information
    if(_contact)
    {
        _contact->m_normal = _aabb1->m_position - _aabb2->m_position;
        _contact->m_distance = (_contact->m_normal - (_aabb1->m_radii + _aabb2->m_radii)).magnitude();
        _contact->m_normal.normalise();
    }
    return true;
}

// AABB vs Plane
bool Collider::test(const PlaneCollider* _plane, const AABB* _aabb, Contact* _contact)
{
    float r = _aabb->m_radii.m_x * abs(_plane->m_normal.m_x) + _aabb->m_radii.m_y * abs(_plane->m_normal.m_y) + _aabb->m_radii.m_z * abs(_plane->m_normal.m_z);
    float s = _plane->m_normal.dot( _aabb->m_position ) - _plane->m_normal.dot( _plane->m_position );

    // Fill in contact info
    if(_contact)
    {
        // Collision normal is the plane normal
        _contact->m_normal = _plane->m_normal;
        _contact->m_distance = abs(s) - r;
    }

    return abs(s) <= r;
}