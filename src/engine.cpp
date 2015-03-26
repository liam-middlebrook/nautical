#include "engine.h"

#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

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


    GameObject world("world", *this, NULL);

    // Center world inside of window
    int w, h;

    window.getSize(w, h);

    world.transform.position.x = w / 2.0f;
    world.transform.position.y = h / 2.0f;

    // Setup subsystems
    _renderer = new systems::Renderer(w, h);
    _shaderLoader = new graphics::ShaderLoader();
    _textureLoader = new graphics::TextureLoader();

    // Set clear color to what config states
    glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);



    // BEGIN TESTCODE

    std::string shaderN = loadShader("name", "vert.glsl", "frag.glsl");

    loadTexture("remyd", "image.png");

    GameObject* child = world.addChild("remyd");
    components::RenderComponent* childRenderer = new components::RenderComponent(child);

    child->addComponent("renderer", childRenderer);

    childRenderer->texture = "remyd";
    childRenderer->shader = shaderN;
    childRenderer->tint = graphics::Colors::Red;

    child->transform.scale = math::Vector3<float>(64.0f, 64.0f, 1.0f);

    // END TESTCODE

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
}

std::string Engine::loadShader(std::string name, const char* vertLoc, const char* fragLoc)
{
    return _shaderLoader->loadShader(name, vertLoc, fragLoc);
}

std::string Engine::loadTexture(std::string name, const char* fileLoc)
{
    return _textureLoader->loadTexture(name, fileLoc);
}
