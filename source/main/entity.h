#pragma once

#include <vector>
#include "main/icomponent.h"

class Entity
{
public:

    void addComponent(iComponent* _pComponent)
    {
        _pComponent->setParent(this);
        m_pComponents.push_back(_pComponent);
    }

private:
    std::vector<iComponent *> m_pComponents;

};