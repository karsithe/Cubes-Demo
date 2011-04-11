#pragma once

#include "maths\vector3.h"

class Transform;

class AABBCollider
{
public:
    AABBCollider(Transform* _transform);

    Vector3 getStart();
    Vector3 getEnd();

private:
    Transform* m_pTransform;
    Vector3 m_start, m_end;
};