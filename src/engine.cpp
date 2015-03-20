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

    float clearColor[4]
    {
        static_cast<float>(iniparser_getdouble(nautical_config, "window:clearR", 0.0f)),
        static_cast<float>(iniparser_getdouble(nautical_config, "window:clearG", 0.0f)),
        static_cast<float>(iniparser_getdouble(nautical_config, "window:clearB", 0.0f)),
        static_cast<float>(iniparser_getdouble(nautical_config, "window:clearA", 0.0f)),
    };

    nautical::graphics::Window window(width, height, title);

    window.setActive();

    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK)
    {
        printf("GLEW Not Initialized!\n");
        return;
    }

    _renderer = new systems::Renderer();
    _shaderLoader = new graphics::ShaderLoader();
    _textureLoader = new graphics::TextureLoader();

    GLuint shader = _shaderLoader->loadShader("vert.glsl", "frag.glsl");

    glUseProgram(shader);

    glUniform1i(glGetUniformLocation(shader, "tex"), 0);

    glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);

    GLuint tex = _textureLoader->loadTexture("image.png");

    GameObject world("world", this);

    world.addComponent("renderer", new components::RenderComponent(&world));

    static_cast<components::RenderComponent*>(world.getComponent("renderer"))->texture = tex;

    world.init();

    while(!window.shouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();

        world.update();

        world.lateUpdate();

        _renderer->render();

        window.render();
    }

    // loop until close
 
        // update game object and systems

    // subsystem destruct
}
