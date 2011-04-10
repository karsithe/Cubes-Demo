#pragma once

#include <vector>
#include "main/component.h"
#include "main/transform.h"

class Entity
{
public:
    Entity() {}

    Entity(Transform _transform) : m_transform(_transform) {}

    void addComponent(Component* _pComponent)
    {
        _pComponent->setParent(this);
        m_pComponents.push_back(_pComponent);
    }

    Transform getTransform() const
    {
        return m_transform;
    }

    void setTransform(Transform& _transform)
    {
        m_transform = _transform;
    }

private:
    std::vector<Component *> m_pComponents;
    Transform m_transform;

};