#include <GL/GLFW.h>
#include "geometry/Plane.h"

void Plane::setup()
{
    m_width = 20.f;
    m_res = 20;
    m_res2 = m_res * m_res;

    // buffer for points, including those inside Plane
    m_verts = new Vertex[m_res2];

    // indices for external points
    m_indices = new int[m_res2];

    // normals for external points
    m_normals = new Vertex[m_res2];

    // create Plane of vertices
    for(int i = 0; i < m_res; i++)
    {
        for(int j = 0; j < m_res; j++)
        {
            m_verts[i2D(i,j)] = Vertex(i*m_width/m_res, -5.0f, j*m_width/m_res);
        }
    }
}

void Plane::update()
{

}

void Plane::end()
{

}

void Plane::draw()
{
    glPushMatrix();

    glTranslatef(-m_width/2.f, 0.0f, -m_width/2.f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POINTS);
    for(int i=0; i < m_res2; i++)
    {
        glVertex3f(m_verts[i].x, m_verts[i].y, m_verts[i].z);
    }
    glEnd();

    glPopMatrix();
}

int Plane::i2D(int _i, int _j)
{
    return _i + _j * m_res;
}