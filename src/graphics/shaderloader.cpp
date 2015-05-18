#include "graphics/shaderloader.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "util.h"

using namespace nautical;
using namespace nautical::graphics;

ShaderLoader::ShaderLoader()
{
}

ShaderLoader::~ShaderLoader()
{
}

std::string ShaderLoader::loadShader(std::string name, const char* vertLoc,
                                     const char* fragLoc)
{
    // Load shader and shit
	if(!does_file_exist(vertLoc)) {
		vertLoc = (get_data_location() + "/resources/" + vertLoc).c_str();
	}
    std::ifstream vertIn(vertLoc);
    std::string vertexStr((std::istreambuf_iterator<char>(vertIn)),
                          std::istreambuf_iterator<char>());

    const char* vertexChars = vertexStr.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexChars, NULL);
    glCompileShader(vertexShader);

    GLint status;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
    printf("Vertex Shader Status %d\n", status);

	if(!does_file_exist(fragLoc)) {
		fragLoc = (get_data_location() + "/resources/" + fragLoc).c_str();
	}
    std::ifstream fragIn(fragLoc);
    std::string fragStr((std::istreambuf_iterator<char>(fragIn)),
                        std::istreambuf_iterator<char>());
    const char* fragmentChars = fragStr.c_str();

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentChars, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
    printf("Fragment Shader Status %d\n", status);

    GLuint shaderProg = glCreateProgram();
    glAttachShader(shaderProg, vertexShader);
    glAttachShader(shaderProg, fragmentShader);
    glLinkProgram(shaderProg);

    glGetShaderiv(shaderProg, GL_LINK_STATUS, &status);
    printf("Shader Link Status %d\n", status);

    if (_dict.find(name) != _dict.end())
    {
        return "";
    }

    _dict[name] = shaderProg;

    return name;
}
