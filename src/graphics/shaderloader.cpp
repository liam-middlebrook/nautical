#include "graphics/shaderloader.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace nautical;
using namespace nautical::graphics;

std::string* loadFile(const char* fileLoc)
{
    std::string* file = new std::string();
    std::ifstream fs(fileLoc, std::ios::in);

    std::string line = "";

    if(!fs.is_open())
    {
        exit(EXIT_FAILURE);
    }

    while(!fs.eof())
    {
        std::getline(fs, line);
        file->append(line + "\n");
    }

    fs.close();
    return file;
}

ShaderLoader::ShaderLoader()
{
}

ShaderLoader::~ShaderLoader()
{
}

GLuint ShaderLoader::loadShader(const char* vertLoc, const char* fragLoc)
{
    // Load shader and shit
    std::string* file = loadFile(vertLoc);

    const char* vertexChars = file->c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexChars, NULL);
    glCompileShader(vertexShader);

    delete file;

    GLint status;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
    printf("Vertex Shader Status %d\n", status);

    file = loadFile(fragLoc);
    const char* fragmentChars = file->c_str();

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentChars, NULL);
    glCompileShader(fragmentShader);

    delete file;

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
    printf("Fragment Shader Status %d\n", status);

    GLuint shaderProg = glCreateProgram();
    glAttachShader(shaderProg, vertexShader);
    glAttachShader(shaderProg, fragmentShader);
    glLinkProgram(shaderProg);

    glGetShaderiv(shaderProg, GL_LINK_STATUS, &status);
    printf("Shader Link Status %d\n", status);

    return shaderProg;
}
