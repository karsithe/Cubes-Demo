#include <cstdlib>
#include <GL/GLFW.h>
#include "app.h"
#include "render\renderer.h"
#include "physics\physicsmanager.h"

Application::Application()
{
    m_run = true;
    m_time = static_cast<float>(glfwGetTime());
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

    m_pManagers.push_back(new Renderer());
//    m_pManagers.push_back(new PhysicsManager());

    return 0;
}

bool Application::run()
{
    std::vector<Manager *>::iterator _ppMgr;

    for(_ppMgr = m_pManagers.begin(); _ppMgr != m_pManagers.end(); ++_ppMgr)
    {
        (*_ppMgr)->setup();
    }

    while(m_run)
    {
        float newTime = static_cast<float>(glfwGetTime());

        for(_ppMgr = m_pManagers.begin(); _ppMgr != m_pManagers.end(); ++_ppMgr)
        {
            (*_ppMgr)->update(newTime - m_time);
        }
        
        m_run = !glfwGetKey( GLFW_KEY_ESC ) && glfwGetWindowParam( GLFW_OPENED );
        m_time = newTime;
    }

    for(_ppMgr = m_pManagers.begin(); _ppMgr != m_pManagers.end(); ++_ppMgr)
    {
        (*_ppMgr)->destroy();
    }
        

    return 0;
}

bool Application::end()
{
    glfwTerminate();
    return 0;
}