#include <cmath>
#include "maths/vector3.h"
#include "physics/collider.h"
#include "physics/planecollider.h"
#include "physics/contact.h"
#include "physics/aabb.h"

AABB::AABB() 
    : Collider(Vector3(), COLLIDER_AABB)
{}

AABB::AABB(Vector3 _position, Vector3 _scale)
    : Collider(_position, COLLIDER_AABB), m_radii(_scale)
{}

bool AABB::testAABB(AABB* _col, Contact* _contact)
{
    if (abs(m_position.m_x - _col->m_position.m_x) > (m_radii.m_x + _col->m_radii.m_x)) return false;
    if (abs(m_position.m_y - _col->m_position.m_y) > (m_radii.m_y + _col->m_radii.m_y)) return false;
    if (abs(m_position.m_z - _col->m_position.m_z) > (m_radii.m_z + _col->m_radii.m_z)) return false;
    if(_contact)
    {
        _contact->m_bodyA = this->m_parent;
        _contact->m_bodyB = _col->m_parent;
        _contact->m_normal = m_position - _col->m_position;
        _contact->m_distance = (_contact->m_normal - (m_radii+_col->m_radii)).magnitude();
        _contact->m_normal.normalise();
    }
    return true;
}

bool AABB::testPlane(PlaneCollider* _col, Contact* _contact)
{
    float r = m_radii.m_x * abs(_col->m_normal.m_x) + m_radii.m_y * abs(_col->m_normal.m_y) + m_radii.m_z * abs(_col->m_normal.m_z);
    float s = _col->m_normal.dot( m_position ) - _col->m_normal.dot( _col->m_position );
    if(_contact)
    {
        _contact->m_bodyA = this->m_parent;
        _contact->m_bodyB = _col->m_parent;
        _contact->m_normal = _col->m_normal;
        _contact->m_distance = abs(s) - r;
    }
    return abs(s) <= r;
}
