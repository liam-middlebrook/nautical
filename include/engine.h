#pragma once

#include "systems/renderer.h"
#include "components/rendercomponent.h"

namespace nautical
{
    class Engine
    {
    public:
        Engine();
        ~Engine();

        // Not sure if I want settings to be sent through a struct in here
        // or if they should be several variables set in the constructor or
        // through individual properties
        void run();

    private:
        systems::Renderer _renderer;

        friend class components::RenderComponent;
    };
}
