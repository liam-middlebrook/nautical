#pragma once

#include "math/matrix4.h"

#include "graphics/color.h"

#include <vector>
#include <GL/glew.h>
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
        public:
            GLuint texture;
            GLuint shader;
            math::Matrix4<float> transform;
            graphics::Color tint;
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

            GLuint vao;
            GLuint vbo;

            friend class components::RenderComponent;
        };
    }
}
