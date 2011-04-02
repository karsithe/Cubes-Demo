#include <GL/GLFW.h>
#include "maths\vector3.h"
#include "geometry/cube.h"

void Cube::setup()
{
    m_width = 5.f;
    m_res = 10;
    m_res2 = m_res * m_res;
    m_res3 = m_res2 * m_res;

    // buffer for points, including those inside cube
    m_verts = new Vertex[m_res3];

    // indices for external points
    m_indices = new int[m_res2 * 6];

    // normals for external points
    m_normals = new Vertex[m_res2 * 6];

    // create cube of vertices
    for(int i = 0; i < m_res; i++)
    {
        for(int j = 0; j < m_res; j++)
        {
            for(int k = 0; k < m_res; k++)
            {
                m_verts[i3D(i,j,k)] = Vertex(i*m_width/m_res-m_width/2.f,j*m_width/m_res-m_width/2.f,k*m_width/m_res-m_width/2.f);
            }
        }
    }
}

void Cube::update()
{

}

void Cube::end()
{

}

void Cube::draw()
{
    glPushMatrix();

    glTranslatef(m_position.x, m_position.y, m_position.z);
    glRotatef(m_rotation.z, 0.0f, 0.0f, 1.0f);
    glRotatef(m_rotation.x, 1.0f, 0.0f, 0.0f);
    glRotatef(m_rotation.y, 0.0f, 1.0f, 0.0f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POINTS);
    for(int i=0; i < m_res3; i++)
    {
        glVertex3f(m_verts[i].x, m_verts[i].y, m_verts[i].z);
    }
    glEnd();

    glPopMatrix();
}

int Cube::i3D(int _i, int _j, int _k)
{
    return _i + _j * m_res + _k * m_res2;
}