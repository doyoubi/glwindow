#ifndef DYB_WINDOW
#define DYB_WINDOW

#include "GLFW/glfw3.h"

namespace dyb
{
    class Window
    {
    public:
        Window(int width, int height);
        ~Window();
        typedef void (*LoopFunc)();
        void runLoop(LoopFunc);
    private:
        int _width, _height;
        GLFWwindow* window;
    };
}

#endif
