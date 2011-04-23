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

    class Derivative
    {
    public:
        Vector3 m_velocity;
        Vector3 m_force;
        Quaternion m_spin;
        Vector3 m_torque;
    };

    // Collected
    Vector3 m_gatheredForce;
    Vector3 m_gatheredTorque;

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

    void integrateRK4(float _deltaTime)
    {
        Derivative a = evaluate(_deltaTime);
        Derivative b = evaluate(_deltaTime*0.5f, a);
        Derivative c = evaluate(_deltaTime*0.5f, b);
        Derivative d = evaluate(_deltaTime, c);

        m_position        += (a.m_velocity + (b.m_velocity + c.m_velocity) *2.0f + d.m_velocity) * 1.0f/6.0f * _deltaTime ;
        m_momentum        += (a.m_force    + (b.m_force + c.m_force) *2.0f       + d.m_force)    * 1.0f/6.0f * _deltaTime ;
        m_orientation     += (a.m_spin     + (b.m_spin + c.m_spin) *2.0f         + d.m_spin)     * 1.0f/6.0f * _deltaTime ;
        m_angularMomentum += (a.m_torque   + (b.m_torque + c.m_torque) *2.0f     + d.m_torque)   * 1.0f/6.0f * _deltaTime ;

        m_gatheredForce = Vector3();
        m_gatheredTorque = Vector3();

        recalculate();
    }

private:
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

    Derivative evaluate(float _deltaTime)
    {
        Derivative rtn;
        rtn.m_velocity = m_velocity;
        rtn.m_spin = m_spin;
        rtn.m_force = m_gatheredForce;
        rtn.m_torque = m_gatheredTorque;
        return rtn;
    }

    Derivative evaluate(float _deltaTime, Derivative _derivative)
    {
        m_position += _derivative.m_velocity * _deltaTime;
        m_momentum += _derivative.m_force * _deltaTime;
        m_orientation += _derivative.m_spin * _deltaTime;
        m_angularMomentum += _derivative.m_torque * _deltaTime;
        recalculate();

        Derivative rtn;
        rtn.m_velocity = m_velocity;
        rtn.m_spin = m_spin;
        rtn.m_force = m_gatheredForce;
        rtn.m_torque = m_gatheredTorque;
        return rtn;
    }
};