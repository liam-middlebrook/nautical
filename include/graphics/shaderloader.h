#pragma once

#include <GL/glew.h>
#include <GL/gl.h>
#include <unordered_map>

namespace nautical
{
    namespace graphics
    {
        class ShaderLoader
        {
        public:
            ShaderLoader();
            ~ShaderLoader();

            std::string loadShader(std::string name, const char* vertLoc, const char* fragLoc);

            inline GLuint getShader(std::string name)
            {
                return _dict[name];
            }

        private:
            std::unordered_map<std::string, GLuint> _dict;
        };
    }
}
