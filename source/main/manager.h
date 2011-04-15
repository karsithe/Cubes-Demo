#pragma once

#include <vector>
#include "main/component.h"

class Manager
{
public:
    virtual void setup() = 0;
    virtual void update(float _deltaTime) = 0;
    virtual void destroy() = 0;

    virtual void addComponent(Component* _pComponent)
    {
        _pComponent->setManager(this);
        m_pComponents.push_back(_pComponent);
    }

protected:
    std::vector<Component*> m_pComponents;
};