#include "scriptloader.h"
#include "script.h"
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
using std::string;

Engine::Engine()
    : _keyboard{nullptr}, _renderer{nullptr}, _shaderLoader{nullptr},
      _textureLoader{nullptr}, _factory{new script::ScriptFactory()}
{
}

Engine::~Engine()
{
}

namespace {
	string prepareDir(string dir)
	{
		if(dir == "") {
			return ".";
		}
		while(dir[dir.length()-1] == '/') {
			dir = dir.substr(0, dir.length()-1);
		}
		return dir;
	}
}

void Engine::run(string dir=".")
{
	_directory = prepareDir(dir);
	string configFilename = _directory + "/config.json";
    if (!does_file_exist(configFilename.c_str()))
    {
        printf("config.json not found!\nCreating default config.json now!\n");
        return;
    }

    // Load config.json to memory
    rapidjson::Document nautical_config;
    std::ifstream configHandle(configFilename);
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
    for (rapidjson::Value::ConstMemberIterator itr = controls.MemberBegin(); itr != controls.MemberEnd(); ++itr)
    {
        _keyboard->setKeyBinding(itr->name.GetString(), itr->value.GetInt());
    }

    _factory->load(gamefile(nautical_config["script"]["file"].GetString()));
    auto s = _factory->script(nautical_config["script"]["class"].GetString(),
                              &world);
    world.addScript("script", s);

    world.init();

    while (!window.shouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();

        world.update();

        world.lateUpdate();

        _renderer->render();

        window.render();
    }
}

void Engine::addScriptLoader(nautical::script::ScriptLoader* loader)
{
	_factory->addLoader(loader);
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

void Engine::loadScript(std::string file)
{
    _factory->load(file);
}

void Engine::addScript(std::string className, GameObject* gameObject)
{
    gameObject->addScript(className.c_str(), _factory->script(className, gameObject));
}
