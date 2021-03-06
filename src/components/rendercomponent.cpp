#include "components/rendercomponent.h"

using namespace nautical;
using namespace nautical::components;

RenderComponent::RenderComponent(GameObject* hostObj)
{
    this->_hostObj = hostObj;
}

RenderComponent::~RenderComponent()
{
}

void RenderComponent::init()
{
}

void RenderComponent::update()
{
    // add to render system's drawQueue
    graphics::DrawParams sprite;

    Engine& engine = _hostObj->getEngine();

    sprite.texture = engine._textureLoader->getTexture(texture);

    sprite.shader = engine._shaderLoader->getShader(shader);

    sprite.transform = _hostObj->getMatrix();

    sprite.tint = tint;

    engine._renderer->addSpriteToRenderBatch(sprite);
}
