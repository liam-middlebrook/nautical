#pragma once

#include "math/matrix4.h"

#include <vector>
#include <GL/gl.h>

namespace nautical
{
    namespace components
    {
        class RenderComponent;
    }

    namespace graphics
    {
        class DrawParams
        {
            GLuint texture;
            math::Matrix4<float> transform;
            // add a color for tinting and stuff 
        };
    }

    namespace systems
    {
        class Renderer
        {
        public:
            Renderer();
            ~Renderer();

            // loop through and render everything sent to the queue
            void render();

        private:
            void addSpriteToRenderBatch(graphics::DrawParams spriteToAdd);

            math::Matrix4<float> modelViewMatrix;

            std::vector<graphics::DrawParams> drawQueue;

            friend class RenderComponent;
        };
    }
}
