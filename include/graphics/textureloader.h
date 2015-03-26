#pragma once
#include <GL/glew.h>
#include <GL/gl.h>
#include <string>
#include <unordered_map>

namespace nautical
{
    namespace graphics
    {
        class TextureLoader
        {
        public:
            TextureLoader();
            ~TextureLoader();

            std::string loadTexture(std::string name, const char* fileLoc);

            inline GLuint getTexture(std::string name)
            {
                return _dict[name];
            }

        private:
            std::unordered_map<std::string, GLuint> _dict;
        };
    }
}
