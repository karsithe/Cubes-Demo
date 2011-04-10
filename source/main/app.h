/*
    Application
    Controls creation, display and destruction of the scene
    Hazel McKendrick 2011
*/

#pragma once

#include <vector>

class Manager;
class Entity;

class Application
{
public:
    Application();

    bool setup();
    bool run();
    bool end();

private:
    bool m_run;
    float m_time;

    std::vector<Manager*> m_pManagers;
    std::vector<Entity*> m_pEntities;
};