#include "engine.h"

#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include <stdio.h>

#include "util.h"
#include "graphics/window.h"

#include <fstream>
#include <iostream>
#include <rapidjson/document.h>

using namespace nautical;

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::run()
{
    if (!does_file_exist("config.json"))
    {
        printf("config.json not found!\nCreating default config.json now!\n");
        return;
    }

    // Load config.json to memory
    rapidjson::Document nautical_config;
    std::ifstream configHandle("config.json");
    std::string configString((std::istreambuf_iterator<char>(configHandle)),
                          std::istreambuf_iterator<char>());
    nautical_config.Parse(configString.c_str());

    if (!nautical::graphics::Window::init())
    {
        printf("Error Window System Not Inited!");
        return;
    }

    int width, height;
    const char* title;

    width = nautical_config["window"]["width"].GetInt();
    height = nautical_config["window"]["height"].GetInt();

    title = nautical_config["window"]["title"].GetString();

    GLfloat clearColor[4];

    const rapidjson::Value& clear = nautical_config["window"]["clear"];
    for(rapidjson::SizeType i = 0; i < clear.Size(); ++i)
    {
        clearColor[i] = static_cast<GLfloat>(clear[i].GetDouble());
    }


    nautical::graphics::Window window(width, height, title);

    window.setActive();

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
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
    _keyboard = new systems::input::Keyboard(window.getWindow());
    _renderer = new systems::Renderer(w, h);
    _shaderLoader = new graphics::ShaderLoader();
    _textureLoader = new graphics::TextureLoader();

    // Set clear color to what config states
    glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);

    const rapidjson::Value& controls = nautical_config["controls"];
    for(rapidjson::SizeType i = 0; i < controls.Size(); ++i)
    {
        const rapidjson::Value& control = controls[i];
        _keyboard->setKeyBinding(control["name"].GetString(), control["key"].GetInt());
    }
    // BEGIN TESTCODE

    /*
    _keyboard->setKeyBinding("left", 263);
    _keyboard->setKeyBinding("down", 264);
    _keyboard->setKeyBinding("up", 265);
    _keyboard->setKeyBinding("right", 262);
    //*/

    std::string shaderN = loadShader("name", "vert.glsl", "frag.glsl");

    loadTexture("remyd", "image.png");

    GameObject* child = world.addChild("remyd");
    components::RenderComponent* childRenderer =
        new components::RenderComponent(child);

    child->addComponent("renderer", childRenderer);

    childRenderer->texture = "remyd";
    childRenderer->shader = shaderN;
    childRenderer->tint = graphics::Colors::Red;

    child->transform.scale = math::Vector3<float>(64.0f, 64.0f, 1.0f);

    // END TESTCODE

    world.init();

    while (!window.shouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();

        world.update();

        world.lateUpdate();

        _renderer->render();

        if(_keyboard->keyPressed("left"))
        {
            child->transform.position += -math::Vector3<float>::right;
        }
        if(_keyboard->keyPressed("right"))
        {
            child->transform.position += math::Vector3<float>::right;
        }
        if(_keyboard->keyPressed("down"))
        {
            child->transform.position += -math::Vector3<float>::up;
        }
        if(_keyboard->keyPressed("up"))
        {
            child->transform.position += math::Vector3<float>::up;
        }

        window.render();
    }
}

std::string Engine::loadShader(std::string name, const char* vertLoc,
                               const char* fragLoc)
{
    return _shaderLoader->loadShader(name, vertLoc, fragLoc);
}

std::string Engine::loadTexture(std::string name, const char* fileLoc)
{
    return _textureLoader->loadTexture(name, fileLoc);
}
