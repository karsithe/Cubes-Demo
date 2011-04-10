/*
    Renderer
    Manager class for rendering the scene and components within it
    Hazel McKendrick 2011
*/


#pragma once

#include <vector>
#include "main/iManager.h"

class Renderer : public iManager
{
public:
    Renderer();
    
    void setup();
    void update(float _deltaTime);
    void destroy();

private:

    void setupStates();
};