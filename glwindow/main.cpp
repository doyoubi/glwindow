#include <iostream>
#include "glm/vec3.hpp"

#include "screen_manager.h"
#include "Window.h"
using std::cout;
using std::endl;
using std::cerr;

void loop()
{
    dyb::ScreenManager::instance()->drawToGL();
}

int main()
{
    // draw a red line
    for (int i = 0; i < 400; i++)
        dyb::ScreenManager::instance()->drawPoint(glm::ivec2(i, 100), glm::vec3(1,0,0));
    // draw a blue line
    dyb::ScreenManager::instance()->drawLine(glm::ivec2(30, 30), glm::ivec2(200, 300), glm::vec3(0, 0, 1));

    dyb::Window win(dyb::ScreenManager::window_width, dyb::ScreenManager::window_height);
    win.runLoop(loop);
    return 0;
}