#include "components/rendercomponent.h"

using namespace nautical;
using namespace nautical::components;

RenderComponent::RenderComponent(GameObject* hostObj)
{
    this->_hostObj = hostObj;
}

RenderComponent::~RenderComponent()
{
    // unload gl buffer stuffs
}

void RenderComponent::init()
{
    // init gl buffer stuffs
}

void RenderComponent::update()
{
    // add to render system's drawQueue
}
