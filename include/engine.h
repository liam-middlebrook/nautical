#pragma once

#include "graphics/shaderloader.h"
#include "graphics/textureloader.h"
#include "systems/input/keyboard.h"
#include "systems/renderer.h"
#include "components/rendercomponent.h"

namespace nautical
{
    namespace script
    {
        class ScriptFactory;
		class ScriptLoader;
    }

    class Engine
    {
    public:
        Engine();
        ~Engine();

        // Not sure if I want settings to be sent through a struct in here
        // or if they should be several variables set in the constructor or
        // through individual properties
        void run();

        std::string loadShader(std::string name, const char* vertLoc,
                               const char* fragLoc);

        std::string loadTexture(std::string name, const char* fileLoc);

        void loadScript(std::string file);

        void addScript(std::string className, GameObject* gameObject);

		void addScriptLoader(nautical::script::ScriptLoader*);

        inline systems::input::Keyboard* getKeyboard()
        {
            return _keyboard;
        }
    private:
        systems::input::Keyboard* _keyboard;
        systems::Renderer* _renderer;
        graphics::ShaderLoader* _shaderLoader;
        graphics::TextureLoader* _textureLoader;
        script::ScriptFactory* _factory;

        friend class components::RenderComponent;
    };
}
