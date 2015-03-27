#include "graphics/window.h"

#include <GLFW/glfw3.h>

using namespace nautical;
using namespace nautical::graphics;

Window::Window(int width, int height, const char* title) : _w{width}, _h{height}
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    _window = glfwCreateWindow(width, height, title, NULL, NULL);
}

Window::~Window()
{
    glfwDestroyWindow(_window);
}

GLFWwindow* Window::getWindow()
{
    return _window;
}

void Window::getSize(int& w, int& h)
{
    w = _w;
    h = _h;
}

bool Window::shouldClose()
{
    return glfwWindowShouldClose(_window);
}

void Window::setActive()
{
    glfwMakeContextCurrent(_window);
}

void Window::render()
{
    glfwSwapBuffers(_window);
}

bool Window::init()
{
    return glfwInit();
}
