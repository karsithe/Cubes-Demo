/*
    Component
    An representation or part of an object in the scene
    Hazel McKendrick 2011s
*/

#pragma once

class Entity;
class Manager;

class Component
{
public:
    Component() {}

    // Pure virtual members
    virtual void setup() = 0;                   // Called once at the start of the program
    virtual void update(float _deltaTime) = 0;  // Called once per frame
    virtual void destroy() = 0;                 // Called once at the end of the program

    // Set the entity containing this component
    void setParent(Entity* _parent)
    {
        m_pParent = _parent;
    }

    // Set the manager responsible for updating this component
    virtual void setManager(Manager* _manager)
    {
        m_pManager = _manager;
    }

protected:
    Entity* m_pParent;
    Manager* m_pManager;
};