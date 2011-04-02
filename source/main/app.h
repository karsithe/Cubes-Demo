#pragma once

class Application
{
public:
    Application();

    bool setup();
    bool run();
    bool end();

private:
    bool m_run;
};