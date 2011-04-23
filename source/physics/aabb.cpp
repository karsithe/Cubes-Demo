#include <cmath>
#include "maths/vector3.h"
#include "physics/collider.h"
#include "physics/aabb.h"


// Constructors

// Default to creating unit cube
AABB::AABB() 
    : Collider(Vector3(), COLLIDER_AABB), m_radii(Vector3(1.f, 1.f, 1.f))
{}

AABB::AABB(Vector3 _position, Vector3 _scale)
    : Collider(_position, COLLIDER_AABB), m_radii(_scale)
{}
