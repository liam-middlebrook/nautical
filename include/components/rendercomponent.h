#pragma once

#include "gamecomponent.h"
#include "gameobject.h"
#include "engine.h"
#include "systems/renderer.h"
#include "graphics/color.h"

namespace nautical
{
    namespace components
    {
        class RenderComponent : public GameComponent
        {
        public:
            RenderComponent(GameObject* hostObj);
            ~RenderComponent();

            void init();

            void update();

            std::string texture;

            std::string shader;

            graphics::Color tint;
        };
    }
}
