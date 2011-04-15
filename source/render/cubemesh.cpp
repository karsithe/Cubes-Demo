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

    glTranslatef(trans.m_position.x, trans.m_position.y, trans.m_position.z);
    glScalef(trans.m_scale.x, trans.m_scale.y, trans.m_scale.z);
    glRotatef(trans.m_rotation.z, 0.0f, 0.0f, 1.0f);
    glRotatef(trans.m_rotation.x, 1.0f, 0.0f, 0.0f);
    glRotatef(trans.m_rotation.y, 0.0f, 1.0f, 0.0f);
    glColor3f(m_colour.x, m_colour.y, m_colour.z);

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

