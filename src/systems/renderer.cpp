#include "systems/renderer.h"
#include <stdio.h>

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

using namespace nautical;
using namespace nautical::systems;

Renderer::Renderer(float width, float height)
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

    calculateViewProjectionMatrix(width, height);
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

        glUseProgram(draw.shader);

        //math::Matrix4<float> transform(modelViewMatrix * draw.transform);
        math::Matrix4<float> transform(draw.transform * modelViewMatrix);

        glUniform4f(glGetUniformLocation(draw.shader, "tint"),
                    draw.tint.r, draw.tint.g, draw.tint.b, draw.tint.a);

        glUniformMatrix4fv(glGetUniformLocation(draw.shader, "transform"), 1,
                           GL_FALSE, (float *)transform);

        glBindTexture(GL_TEXTURE_2D, draw.texture);

        glUniform1i(glGetUniformLocation(draw.shader, "tex"), 0);

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

void Renderer::calculateViewProjectionMatrix(float width, float height)
{
    float l, r, t, b, f, n;
    l = 1.0f;
    r = width - 1.0f;
    t = height - 1.0f;
    b = 1.0f;
    f = 1.0f;
    n = -1.0f;

    // hacky ortho projection matrix for now 640,480 enforced
    float data[] = {2/(r-l), 0.0f, 0.0f, -(r+l)/(r-l), 0.0f, 2/(t-b), 0.0f, -(t+b)/(t-b), 0.0f, 0.0f, -2/(f-n), -(f+n)/(f-n), 0.0f, 0.0f, 0.0f, 1.0f};
    modelViewMatrix = math::Matrix4<float>(data).transposed();
}
