#ifndef _SCREEN_MANAGER_H
#define _SCREEN_MANAGER_H

#include <iostream>
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"

namespace dyb
{

    class ScreenManager
    {
        public:
            static const int window_width = 400;
            static const int window_height = 400;

            static ScreenManager * instance();
            // default is full screen
            void set_draw_square(int left_bottom_x, int left_bottom_y, int width, int height);
            void drawPoint(const glm::ivec2 & point, const glm::vec3 & rgb);
            void drawLine(const glm::ivec2 & start, const glm::ivec2 & end, const glm::vec3 & rgb);
            void drawToGL();

            typedef const GLfloat (*image)[window_width][3];
            image generate_screen_image()const;
            const GLfloat (*operator[](int height)const)[3];
        private:
            ScreenManager();
            GLfloat screen[window_height][window_width][3];
            int left_bottom_x_of_draw_square, left_bottom_y_of_draw_square;
            int width_of_draw_square, height_of_draw_square;
    };

}

#endif
