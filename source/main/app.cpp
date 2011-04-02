#include <cstdlib>
#include <GL/GLFW.h>
#include "app.h"
#include "render\renderer.h"

Application::Application()
{
    m_run = true;
}

bool Application::setup()
{
    if (!glfwInit())
        return 1;

    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 2);
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 1);
    if (!glfwOpenWindow(400,400,0,0,0,0,0,0,GLFW_WINDOW))
    {
        glfwTerminate();
        return 1;
    }
    return 0;
}

bool Application::run()
{
    Renderer r;

    r.setup();
    while(m_run)
    {
        r.update();
        m_run = !glfwGetKey( GLFW_KEY_ESC ) && glfwGetWindowParam( GLFW_OPENED );
    }
    r.end();

    return 0;
}

bool Application::end()
{
    glfwTerminate();
    return 0;
}