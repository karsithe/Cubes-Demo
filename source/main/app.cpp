#include <cstdlib>
#include <GL/GLFW.h>
#include "main/app.h"
#include "main/entity.h"
#include "main/transform.h"
#include "render/renderer.h"
#include "render/cubemesh.h"
#include "physics/collider.h"
#include "physics/rigidbody.h"
#include "physics/physicsmanager.h"

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

    Renderer* r = new Renderer();
    m_pManagers.push_back(r);
    PhysicsManager* p = new PhysicsManager();
    m_pManagers.push_back(p);

    Entity* e = new Entity(Transform(Vector3(1.f,15.f,0.f)));
    CubeMesh* cm = new CubeMesh();
    e->addComponent(cm);
    r->addComponent(cm);
    RigidBody* rb = new RigidBody(COLLIDER_AABB, 2.f);
    e->addComponent(rb);
    p->addComponent(rb);
    m_pEntities.push_back(e);

    e = new Entity(Transform(Vector3(0.0f,10.f,0.f)));
    cm = new CubeMesh();
    e->addComponent(cm);
    r->addComponent(cm);
    rb = new RigidBody(COLLIDER_AABB);
    e->addComponent(rb);
    p->addComponent(rb);
    m_pEntities.push_back(e);

    e = new Entity(Transform(Vector3(-1.0f,12.f,0.f)));
    cm = new CubeMesh();
    e->addComponent(cm);
    r->addComponent(cm);
    rb = new RigidBody(COLLIDER_AABB);
    e->addComponent(rb);
    p->addComponent(rb);
    m_pEntities.push_back(e);

    e = new Entity(Transform(Vector3(0.f, -10.f, 0.f), Vector3(15.f, 0.1f, 15.f)));
    cm = new CubeMesh();
    e->addComponent(cm);
    r->addComponent(cm);
    rb = new RigidBody(COLLIDER_PLANE, 10000000.f, false);
    e->addComponent(rb);
    p->addComponent(rb);
    m_pEntities.push_back(e);
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
    std::vector<Entity *>::iterator _ppEnt;
    for(_ppEnt = m_pEntities.begin(); _ppEnt != m_pEntities.end(); ++_ppEnt)
    {
        delete (*_ppEnt);
    }
        
    glfwTerminate();
    return 0;
}