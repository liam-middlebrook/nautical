#include <cstdio>

#include "graphics/window.h"

#define UNUSED (void)

int main(int argc, char** argv)
{
    UNUSED argc;
    UNUSED argv;

    if(!nautical::graphics::Window::init())
    {
        printf("Error Window System Not Inited!");
        return 1;
    }

    nautical::graphics::Window window(500, 500, "Window!");

    window.setActive();

    while(!window.shouldClose())
    {
        glfwPollEvents();
    //    window.render();
    }
    return 0;
}
