/*
    Application
    Controls creation, display and destruction of the scene
    Hazel McKendrick 2011
*/

#pragma once

#include <vector>

class iManager;

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

    std::vector<iManager*> m_pManagers;

};