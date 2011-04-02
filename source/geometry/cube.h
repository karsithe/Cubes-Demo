#include "render/irenderable.h"
#include "maths/vector3.h"

#pragma once

class Cube : public iRenderable
{
public:

    void setup();
    void update();
    void end();

    void draw();
    void updatePhysics();

private:
    Vertex *m_verts;
    int *m_indices;
    Vertex *m_normals;
    int m_res, m_res2, m_res3;
    float m_width;

    Vector3 m_position;
    Vector3 m_rotation;

    int i3D(int _i, int _j, int _k);

};