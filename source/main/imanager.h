#pragma once

#include <vector>

class iComponent;

class iManager
{
public:
    virtual void setup() = 0;
    virtual void update(float _deltaTime) = 0;
    virtual void destroy() = 0;

    void addComponent(iComponent* _pComponent)
    {
        m_pComponents.push_back(_pComponent);
    }

protected:
    std::vector<iComponent*> m_pComponents;
};