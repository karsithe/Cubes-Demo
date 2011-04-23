/*
    Body State
    Defines a body moving in 3D space
    Hazel McKendrick 2011
*/

#pragma once

#include "maths/quaternion.h"
#include "maths/vector3.h"

class BodyState
{
public:
    // Updated
    Vector3 m_position;
    Vector3 m_momentum;
    Quaternion m_orientation;
    Vector3 m_angularMomentum;

    // Inferred
    Vector3 m_velocity;
    Quaternion m_spin;
    Vector3 m_angularVelocity;

    // Constant
    bool m_static;
    float m_mass;
    float m_inverseMass;
    float m_inertia;
    float m_inverseInertia;

    // Calculate inferred values from updated values
    void recalculate()
    {
        // Linear motion
        m_velocity = m_momentum * m_inverseMass;

        // Angular motion
        m_angularVelocity = m_angularMomentum * m_inverseInertia;
        m_orientation.normalise();
        m_spin = Quaternion(0, m_angularVelocity.m_x, m_angularVelocity.m_y, m_angularVelocity.m_z) * m_orientation * 0.5f;
    }
};