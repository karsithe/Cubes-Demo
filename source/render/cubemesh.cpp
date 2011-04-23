#include <GL/glfw.h>
#include "main/transform.h"
#include "main/entity.h"
#include "render/cubemesh.h"

void CubeMesh::setup()
{
    m_colour = Vector3(rand()*1.0f/RAND_MAX,rand()*1.0f/RAND_MAX,rand()*1.0f/RAND_MAX);
}

void CubeMesh::update(float _deltaTime)
{
    Transform trans = m_pParent->getTransform();
    glPushMatrix();

    glTranslatef(trans.m_position.m_x, trans.m_position.m_y, trans.m_position.m_z);
    glScalef(trans.m_scale.m_x * 0.5f, trans.m_scale.m_y * 0.5f, trans.m_scale.m_z * 0.5f);
    glRotatef(trans.m_rotation.m_z, 0.0f, 0.0f, 1.0f);
    glRotatef(trans.m_rotation.m_x, 1.0f, 0.0f, 0.0f);
    glRotatef(trans.m_rotation.m_y, 0.0f, 1.0f, 0.0f);
    glColor3f(m_colour.m_x, m_colour.m_y, m_colour.m_z);

    glBegin(GL_QUADS);

	    glNormal3f(0.0f, 1.0f, 0.0f);
	    glVertex3f(-1.0f, 1.0f, 1.0f);
	    glVertex3f(1.0f, 1.0f, 1.0f);
	    glVertex3f(1.0f, 1.0f, -1.0f);
	    glVertex3f(-1.0f, 1.0f, -1.0f);

	    glNormal3f(0.0f, 0.0f, 1.0f);
	    glVertex3f(1.0f, -1.0f, 1.0f);
	    glVertex3f(1.0f, 1.0f, 1.0f);
	    glVertex3f(-1.0f, 1.0f, 1.0f);
	    glVertex3f(-1.0f, -1.0f, 1.0f);

	    glNormal3f(1.0f, 0.0f, 0.0f);
	    glVertex3f(1.0f, 1.0f, -1.0f);
	    glVertex3f(1.0f, 1.0f, 1.0f);
	    glVertex3f(1.0f, -1.0f, 1.0f);
	    glVertex3f(1.0f, -1.0f, -1.0f);

	    glNormal3f(-1.0f, 0.0f, 0.0f);
	    glVertex3f(-1.0f, -1.0f, 1.0f);
	    glVertex3f(-1.0f, 1.0f, 1.0f);
	    glVertex3f(-1.0f, 1.0f, -1.0f);
	    glVertex3f(-1.0f, -1.0f, -1.0f);

	    glNormal3f(0.0f, -1.0f, 0.0f);
	    glVertex3f(1.0f, -1.0f, 1.0f);
	    glVertex3f(-1.0f, -1.0f, 1.0f);
	    glVertex3f(-1.0f, -1.0f, -1.0f);
	    glVertex3f(1.0f, -1.0f, -1.0f);

	    glNormal3f(0.0f, 0.0f, -1.0f);
	    glVertex3f(1.0f, 1.0f, -1.0f);
	    glVertex3f(1.0f, -1.0f, -1.0f);
	    glVertex3f(-1.0f, -1.0f, -1.0f);
	    glVertex3f(-1.0f, 1.0f, -1.0f);

    glEnd();

    glPopMatrix();
}

void CubeMesh::destroy()
{

}

