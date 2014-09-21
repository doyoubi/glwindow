#include <iostream>
#include "GLFW/glfw3.h"
#include "glm/vec3.hpp"

#include "screen_manager.h"
using std::cout;
using std::endl;
using std::cerr;

void error_callback(int error, const char* description)
{
    std::cerr << description << endl;
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(
        dyb::ScreenManager::window_width, dyb::ScreenManager::window_height,
        "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    // draw a red line
    for (int i = 0; i < 400; i++)
        dyb::ScreenManager::instance()->drawPoint(glm::ivec2(i, 100), glm::vec3(1,0,0));
    dyb::ScreenManager::instance()->drawLine(glm::ivec2(30, 30), glm::ivec2(200, 300), glm::vec3(0, 0, 1));

    while (!glfwWindowShouldClose(window))
    {
        dyb::ScreenManager::instance()->drawToGL();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}