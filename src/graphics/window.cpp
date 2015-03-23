#include "graphics/window.h"

#include <GLFW/glfw3.h>

using namespace nautical;
using namespace nautical::graphics;

Window::Window(int width, int height, char* title) : _w{width}, _h{height}
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    _window = glfwCreateWindow(width, height, title, NULL, NULL);
}
