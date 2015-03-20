#include "systems/renderer.h"
#include <stdio.h>

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

using namespace nautical;
using namespace nautical::systems;

Renderer::Renderer()
{
    // init opengl
    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);

    glGenBuffers(1, &this->vbo);

    GLfloat vertices[] = 
    {
        // x y u v
        -0.5f, -0.5f, 0.0f, 0.0f,
        -0.5f,  0.5f, 0.0f, 1.0f,
         0.5f,  0.5f, 1.0f, 1.0f,
         0.5f, -0.5f, 1.0f, 0.0f
    };

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 0 is position
    glEnableVertexAttribArray(0);

    // 1 is texture-uv
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), BUFFER_OFFSET(0));
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), BUFFER_OFFSET(2 * sizeof(GLfloat)));

    // disable
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);
}

Renderer::~Renderer()
{
    // unload opengl
    glDeleteBuffers(1, &this->vbo);
    glDeleteVertexArrays(1, &this->vao);
}

void Renderer::render()
{
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    // draw shit
    for(auto& draw : drawQueue)
    {
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    }

    drawQueue.clear();

    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);

    // render everything in  drawQUeue
}

void Renderer::addSpriteToRenderBatch(graphics::DrawParams spriteToAdd)
{
    drawQueue.push_back(spriteToAdd);
}
