#pragma once

class Entity;
class Manager;

class Component
{
public:
    virtual void setup() = 0;
    virtual void update(float _deltaTime) = 0;
    virtual void destroy() = 0;

    void setParent(Entity* _parent)
    {
        m_pParent = _parent;
    }

    virtual void setManager(Manager* _manager)
    {
        m_pManager = _manager;
    }

protected:
    Entity* m_pParent;
    Manager* m_pManager;
};