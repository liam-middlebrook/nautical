#pragma once

#include <GLFW/glfw3.h>

namespace nautical
{
    namespace graphics
    {
        class Window
        {
        public:
            Window(int width, int height, char* title);

            inline virtual ~Window() { glfwDestroyWindow(_window); }

            inline GLFWwindow* getWindow() { return _window; }

            inline void getSize(int& w, int& h) { w = _w; h = _h; }

            inline bool shouldClose() { return glfwWindowShouldClose(_window); }

            inline void setActive() { glfwMakeContextCurrent(_window); }

            inline void render() { glfwSwapBuffers(_window); }

            inline static bool init()
            {
                return glfwInit();
            }

        private:
            GLFWwindow* _window;
            int _w, _h;
        };
    }
}
