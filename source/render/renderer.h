#pragma once

#include <vector>
#include "irenderable.h"

class Renderer
{
public:
    Renderer();
    
    void setup();
    void update();
    void end();

private:
    std::vector<iRenderable*> m_components;

    void setupStates();
};