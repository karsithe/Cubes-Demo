#pragma once

#include "maths\vector3.h"

class AABB
{
public:
    AABB(Vector3 _position, Vector3 _scale);

    void position(Vector3 _position);

    Vector3 position();
    Vector3 start();
    Vector3 end();

private:
    Vector3 m_position;
    Vector3 m_scale;
    Vector3 m_start, m_end;
};