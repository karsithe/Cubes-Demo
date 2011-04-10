#pragma once

#include <vector>

class Component;

class Manager
{
public:
    virtual void setup() = 0;
    virtual void update(float _deltaTime) = 0;
    virtual void destroy() = 0;

    void addComponent(Component* _pComponent)
    {
        m_pComponents.push_back(_pComponent);
    }

protected:
    std::vector<Component*> m_pComponents;
};