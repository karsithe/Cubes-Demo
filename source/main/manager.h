/*
    Manager
    Oversees an particular element of the game and updates related components
    Hazel McKendrick 2011
*/

#pragma once

#include <vector>
#include "main/component.h"

class Manager
{
public:
    // Pure virtual members
    virtual void setup() = 0;
    virtual void update(float _deltaTime) = 0;
    virtual void destroy() = 0;

    // Add a component to be updated
    virtual void addComponent(Component* _pComponent)
    {
        _pComponent->setManager(this);
        m_pComponents.push_back(_pComponent);
    }

protected:
    std::vector<Component*> m_pComponents;
};