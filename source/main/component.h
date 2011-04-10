#pragma once

class Entity;

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

protected:
    Entity* m_pParent;
};