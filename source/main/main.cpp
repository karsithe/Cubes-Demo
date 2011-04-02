#include <Windows.h>
#include "app.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nShowCmd)
{
    Application app;
    
    app.setup();
    app.run();
    app.end();

    return 0;
}
