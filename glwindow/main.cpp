#include <iostream>
#include "glm/vec3.hpp"

#include "screen_manager.h"
#include "Window.h"
using std::cout;
using std::endl;
using std::cerr;

void loop()
{
}

int main()
{
    dyb::Window win(500, 400);
    // draw a red line
    for (int i = 0; i < 500; i++)
        win.getScreenManager()->drawPoint(glm::ivec2(i, 100), glm::vec3(1, 0, 0));
    for (int i = 0; i < 400; i++)
        win.getScreenManager()->drawPoint(glm::ivec2(100, i), glm::vec3(0, 1, 0));
    // draw a blue line
    win.getScreenManager()->drawLine(glm::ivec2(0, 0), glm::ivec2(250, 200), glm::vec3(0, 0, 1));

    win.runLoop(loop);
    return 0;
}