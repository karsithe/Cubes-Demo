#pragma once

#include <vector>
#include "main/component.h"

class Entity
{
public:

    void addComponent(Component* _pComponent)
    {
        _pComponent->setParent(this);
        m_pComponents.push_back(_pComponent);
    }

private:
    std::vector<Component *> m_pComponents;

};