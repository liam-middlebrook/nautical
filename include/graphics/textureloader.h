#pragma once
#include <GL/glew.h>
#include <GL/gl.h>

namespace nautical
{
    namespace graphics
    {
        class TextureLoader
        {
        public:
            TextureLoader();
            ~TextureLoader();

            GLuint loadTexture(const char* fileLoc);
        };
    }
}
