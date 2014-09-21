glwindow
========

Simple framework for drawing point and displaying them using glfw. It's basically used to visualize the result of some algorithm.

set draw square in the coordinate whose original point is in left bottom
default is full screen, which means original point is (0,0) and (width, height) is the same as window size
```dyb::ScreenManager::instance()->set_draw_square(int left_bottom_x, int left_bottom_y, int width, int height);

draw a single point
```ScreenManager::draw(int x, int y, glm::vec3 rgb);

inside the main loop, you have to push the data to graphic card using drawToGL after finishing ScreenManager::draw
```void drawToGL()
