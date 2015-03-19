#include "engine.h"

#include <GL/glew.h>
#include <GL/gl.h>

#include <stdio.h>

#include "util.h"
#include "graphics/window.h"

extern "C" {
#include "iniparser.h"
}

using namespace nautical;

static dictionary *nautical_config;

Engine::Engine()
{

}

Engine::~Engine()
{

}

void Engine::run()
{
    // subsystems init
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
        return;
    }

    int width, height;
    char* title;

    width = iniparser_getint(nautical_config, "window:width", 0);
    height = iniparser_getint(nautical_config, "window:height", 0);
    title = iniparser_getstring(nautical_config, "window:title", (char*)"Nautical Game");
    nautical::graphics::Window window(width, height, title);

    glewExperimental = GL_TRUE;
    if(!glewInit())
    {
        printf("GLEW Not Initialized!\n");
        return;
    }

    window.setActive();

    glClearColor(0,0,1,1);
    while(!window.shouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
        window.render();
    }

    // loop until close
 
        // update game object and systems

    // subsystem destruct
}
