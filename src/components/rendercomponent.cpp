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

    sprite.texture = texture;

    sprite.shader = shader;

    sprite.transform = _hostObj->getMatrix();

    _hostObj->getEngine()->_renderer->addSpriteToRenderBatch(sprite);
}
