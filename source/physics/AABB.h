#pragma once

#include <cmath>
#include "maths/vector3.h"
#include "physics/collider.h"
#include "physics/planecollider.h"
#include "physics/contact.h"

class AABB : public Collider
{
public:
    AABB() 
        : Collider(Vector3(), COLLIDER_AABB)
    {}

    AABB(Vector3 _position, Vector3 _scale)
        : Collider(_position, COLLIDER_AABB), m_radii(_scale)
    {}

    Vector3 m_radii;

    bool testAABB(AABB* _col, Contact* _contact)
    {
        if (abs(m_position.x - _col->m_position.x) > (m_radii.x + _col->m_radii.x)) return false;
        if (abs(m_position.y - _col->m_position.y) > (m_radii.y + _col->m_radii.y)) return false;
        if (abs(m_position.z - _col->m_position.z) > (m_radii.z + _col->m_radii.z)) return false;
        if(_contact)
        {
            _contact->m_normal = m_position - _col->m_position;
            _contact->m_normal.normalise();
        }
        return true;
    }

    bool testPlane(PlaneCollider* _col, Contact* _contact)
    {
        float r = m_radii.x * abs(_col->m_normal.x) + m_radii.y * abs(_col->m_normal.y) + m_radii.z * abs(_col->m_normal.z);
        float s = _col->m_normal.dot( m_position ) - _col->m_normal.dot( _col->m_position );
        if(_contact)
        {
            _contact->m_normal = _col->m_normal;
        }
        return abs(s) <= r;
    }
    
};