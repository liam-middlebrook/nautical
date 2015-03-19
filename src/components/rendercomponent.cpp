#include "components/rendercomponent.h"

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

using namespace nautical;
using namespace nautical::components;

RenderComponent::RenderComponent(GameObject* hostObj)
{
    this->_hostObj = hostObj;
}

RenderComponent::~RenderComponent()
{
    glDeleteBuffers(1, &this->vbo);
    glDeleteVertexArrays(1, &this->vao);
}

void RenderComponent::init()
{
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

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), BUFFER_OFFSET(0));
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), BUFFER_OFFSET(2 * sizeof(GLfloat)));

    // disable
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);
}

void RenderComponent::update()
{
    // add to render system's drawQueue

    graphics::DrawParams sprite;

    sprite.transform = math::Matrix4<float>::identity;

    _hostObj->getEngine()->_renderer.addSpriteToRenderBatch(sprite);
}
