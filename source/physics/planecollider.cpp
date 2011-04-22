#include "physics/aabb.h"
#include "physics/planecollider.h"
#include "physics/contact.h"

PlaneCollider::PlaneCollider() 
    : Collider(Vector3(), COLLIDER_PLANE)
{}

PlaneCollider::PlaneCollider(Vector3 _position, Vector3 _normal)
    : Collider(_position, COLLIDER_PLANE), m_normal(_normal)
{}

bool PlaneCollider::testAABB(AABB* _col, Contact* _contact)
{
    float r = _col->m_radii.m_x * abs(m_normal.m_x) + _col->m_radii.m_y * abs(m_normal.m_y) + _col->m_radii.m_z * abs(m_normal.m_z);
    float s = m_normal.dot( _col->m_position ) - m_normal.dot( m_position );

    if(_contact)
    {
        _contact->m_bodyA = this->m_parent;
        _contact->m_bodyB = _col->m_parent;
        _contact->m_normal = m_normal;
        _contact->m_distance = abs(s) - r;
    }
    return abs(s) <= r;
}

bool PlaneCollider::testPlane(PlaneCollider* _col, Contact* _contact)
{
    return false;
}