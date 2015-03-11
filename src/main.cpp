#include <cstdio>

#include "util.h"
#include "graphics/window.h"

extern "C" {
#include "iniparser.h"
}

#define UNUSED (void)

static dictionary *nautical_config;

int main(int argc, char** argv)
{
    UNUSED argc;
    UNUSED argv;

    if(!does_file_exist("config.ini"))
    {
        printf("config.ini not found!\nCreating default config.ini now!\n");

        // write default config file to disk
        const char* defaultINI =
        "[window]\n"
        "width = 640\n"
        "height = 480\n"
        "title = Nautical Game\n"
        "[game]\n"
        "file=main.py\n"
        "class=MainClass\n";

        write_string_to_file("config.ini", defaultINI);
    }

    nautical_config = iniparser_load("config.ini");

    if(!nautical::graphics::Window::init())
    {
        printf("Error Window System Not Inited!");
        return 1;
    }

    int width, height;
    char* title;

    width = iniparser_getint(nautical_config, "window:width", 0);
    height = iniparser_getint(nautical_config, "window:height", 0);
    title = iniparser_getstring(nautical_config, "window:title", (char*)"Nautical Game");
    nautical::graphics::Window window(width, height, title);

    window.setActive();

    while(!window.shouldClose())
    {
        glfwPollEvents();
    //    window.render();
    }
    return 0;
}
