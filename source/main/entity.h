/*
    Entity
    An object in the scene
    Hazel McKendrick 2011
*/

#pragma once

#include <vector>
#include "main/component.h"
#include "main/transform.h"

class Entity
{
public:
    // Constructors
    Entity() {}
    Entity(Transform _transform) : m_transform(_transform) {}

    // Add components to make up the functionality and attributes of the Entity
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