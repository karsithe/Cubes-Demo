#include "physics/planecollider.h"
#include "physics/contact.h"

// Constructors

PlaneCollider::PlaneCollider() 
    : Collider(Vector3(), COLLIDER_PLANE)
{}

PlaneCollider::PlaneCollider(Vector3 _position, Vector3 _normal)
    : Collider(_position, COLLIDER_PLANE), m_normal(_normal)
{}
