/*
    Renderer
    Manager class for rendering the scene and components within it
    Hazel McKendrick 2011
*/


#pragma once

#include <vector>
#include "main/manager.h"

class Renderer : public Manager
{
public:
    Renderer();
    
    void setup();
    void update(float _deltaTime);
    void destroy();

private:

    void setupStates();
};