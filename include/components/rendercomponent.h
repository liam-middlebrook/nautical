#pragma once

#include "gamecomponent.h"
#include "systems/renderer.h"

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
        };
    }
}
