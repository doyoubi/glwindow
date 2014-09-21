#include <iostream>
#include "screen_manager.h"

namespace dyb
{
    using glm::vec3;
    using glm::ivec2;

    ScreenManager * ScreenManager::instance()
    {
        static ScreenManager sm;
        return &sm;
    }

    void ScreenManager::drawToGL()
    {
        glDrawPixels(window_width, ScreenManager::window_height,
            GL_RGB, GL_FLOAT, dyb::ScreenManager::instance()->generate_screen_image());
    }

    ScreenManager::ScreenManager()
    {
        for(int x = 0; x < window_width; x++)
            for(int y = 0; y < window_height; y++)
                for(int i = 0; i < 3; i++)
                    screen[y][x][i] = 0;
        left_bottom_x_of_draw_square = 0;
        left_bottom_y_of_draw_square = 0;
        width_of_draw_square = window_width;
        height_of_draw_square = window_height;
    }

    ScreenManager::image ScreenManager::generate_screen_image()const
    { 
        return screen;
    }

    void ScreenManager::set_draw_square(int left_bottom_x, int left_bottom_y, int width, int height)
    {
        if(left_bottom_x < 0 || left_bottom_y < 0 || width < 0 || height < 0
        || left_bottom_x+width > window_width || left_bottom_y+height > window_height )
        {
            std::cerr<< "invalid square start point or size" <<std::endl;
            exit(1);
        }
        left_bottom_x_of_draw_square = left_bottom_x;
        left_bottom_y_of_draw_square = left_bottom_y;
        width_of_draw_square = width;
        height_of_draw_square = height;
    }

    void ScreenManager::drawPoint(const ivec2 & p, const vec3 & rgb)
    {
        if(p.x < 0 || p.x >= width_of_draw_square 
        || p.y < 0 || p.y >= height_of_draw_square)
        {
            std::cerr<< "draw out of bound!" <<std::endl;
            return;
        }
        screen[left_bottom_y_of_draw_square + p.y][left_bottom_x_of_draw_square + p.x][0] = rgb.r;
        screen[left_bottom_y_of_draw_square + p.y][left_bottom_x_of_draw_square + p.x][1] = rgb.g;
        screen[left_bottom_y_of_draw_square + p.y][left_bottom_x_of_draw_square + p.x][2] = rgb.b;
    }

    const GLfloat (*ScreenManager::operator[](int height)const)[3]
    { 
        return screen[height];
    }

    void recursiveDraw(ScreenManager * sm, const ivec2 & start, const ivec2 & end, const vec3 & rgb)
    {
        ivec2 delta = glm::abs(start - end);
        if (delta.x <= 1 && delta.y <= 1) return;
        ivec2 mid = (start + end) / 2;
        using namespace std;
        auto echoVec2 = [](const ivec2 & v){
            cout << v.x << ' ' << v.y << endl;
        };
        sm->drawPoint(mid, rgb);
        recursiveDraw(sm, start, mid, rgb);
        recursiveDraw(sm, mid, end, rgb);
    }

    void ScreenManager::drawLine(const ivec2 & start, const ivec2 & end, const vec3 & rgb)
    {
        drawPoint(start, rgb);
        drawPoint(end, rgb);
        recursiveDraw(this, start, end, rgb);
    }

}
