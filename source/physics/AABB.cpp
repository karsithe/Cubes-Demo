#include "physics\AABB.h"
#include "maths\vector3.h"

AABB::AABB(Vector3 _position, Vector3 _scale)
    : m_scale(_scale)
{
    position(_position);
}

void AABB::position(Vector3 _position)
{
    m_position = _position;
    /*m_start = _position - m_scale;
    m_end = _position + m_scale;*/
}

Vector3 AABB::position()
{
    return m_position;
}

Vector3 AABB::start()
{
    return m_start;
}

Vector3 AABB::end()
{
    return m_end;
}