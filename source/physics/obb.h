/*
    OBB
    Oriented Bounding Box
    Hazel McKendrick 2011
*/

#pragma once

#include <cmath>
#include "maths/vector3.h"
#include "physics/collider.h"

class OBB : public Collider
{
public:
    // Constructors
    OBB();
    OBB(Vector3 _position, Vector3 _scale);
    OBB(Vector3 _position, Vector3 _scale, Vector3 _axes[3]);

    // Extents of the box
    Vector3 m_radii;
    Vector3 m_xaxis;
    Vector3 m_yaxis;
    Vector3 m_zaxis;
};