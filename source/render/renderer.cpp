#include <vector>
#include <GL/GLFW.h>
#include "render/renderer.h"
#include "main/component.h"

Renderer::Renderer()
{

}
    
void Renderer::setup()
{
    setupStates();

    std::vector<Component *>::iterator p;
    for(p = m_pComponents.begin(); p != m_pComponents.end(); ++p)
    {
        (*p)->setup();
    }
}

void Renderer::update(float _deltaTime)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 50.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f);

    std::vector<Component *>::iterator p;
    for(p = m_pComponents.begin(); p != m_pComponents.end(); ++p)
    {
        (*p)->update(_deltaTime);
    }
    
    glfwSwapBuffers();
}

void Renderer::destroy()
{
    std::vector<Component *>::iterator p;
    for(p = m_pComponents.begin(); p != m_pComponents.end(); ++p)
    {
        (*p)->destroy();
        delete (*p);
    }
}

void Renderer::setupStates()
{
    int size = 600;
    glViewport(0,0,size,size);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Calculate aspect ratio
	gluPerspective(45.0f,(GLfloat)size/(GLfloat)size, 1 ,1000.0f);

	// Reset the modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
        
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);				// Blue Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations 
	glEnable(GL_TEXTURE_2D);							// Enable texturing
    glEnable(GL_COLOR_MATERIAL);

    glColor4f(1.f, 1.f, 1.f, 1.f);
    glEnable(GL_LIGHTING);								// Enable Lighting
    glEnable(GL_LIGHT0);
    float amb[] = { 0.3f, 0.3f, 0.3f, 1.f };
    glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, amb);
    float position[] = { 1.0f, -1.f, 0.f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    float global_ambient[] = { 0.3f, 0.3f, 0.3f, 1.f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

    glDisable(GL_CULL_FACE);
     
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // Linear Filtering
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // Linear Filtering
}