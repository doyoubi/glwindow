#include <iostream>
#include "glm/vec3.hpp"

#include "screen_manager.h"
#include "Window.h"
using std::cout;
using std::endl;
using std::cerr;

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
    win.setLoopFunc([&](){
        static int i = 0;
        if (i >= 400) return;
        win.getScreenManager()->drawPoint(glm::ivec2(250, i), glm::vec3(1, 1, 0));
        i++;
    });

    win.setMouseButtonFunc([&](int x, int y){
        win.getScreenManager()->drawPoint(glm::ivec2(x, y), glm::vec3(0, 0, 1));
    });

    win.runLoop();
    return 0;
}