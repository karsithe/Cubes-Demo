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
    float r = _col->m_radii.x * abs(m_normal.x) + _col->m_radii.y * abs(m_normal.y) + _col->m_radii.z * abs(m_normal.z);
    float s = m_normal.dot( _col->m_position ) - m_normal.dot( m_position );

    if(_contact)
    {
        _contact->m_normal = m_normal;
    }
    return abs(s) <= r;
}

bool PlaneCollider::testPlane(PlaneCollider* _col, Contact* _contact)
{
    return false;
}