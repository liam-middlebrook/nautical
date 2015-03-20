#pragma once

#include <GL/glew.h>
#include <GL/gl.h>

namespace nautical
{
    namespace graphics
    {
        class ShaderLoader
        {
        public:
            ShaderLoader();
            ~ShaderLoader();

            GLuint loadShader(const char* vertLoc, const char* fragLoc);
        };
    }
}
