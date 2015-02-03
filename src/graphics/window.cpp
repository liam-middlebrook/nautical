#include "graphics/window.h"

using namespace nautical;
using namespace nautical::graphics;

Window::Window(int width, int height, char* title)
{
    _window = glfwCreateWindow(width, height, title, NULL, NULL);
}
