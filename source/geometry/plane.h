#include "render/irenderable.h"

#pragma once

class Plane : public iRenderable
{
public:

    void setup();
    void update();
    void end();

    void draw();

private:
    Vertex *m_verts;
    int *m_indices;
    Vertex *m_normals;
    int m_res, m_res2;
    float m_width;

    int i2D(int _i, int _j);
};