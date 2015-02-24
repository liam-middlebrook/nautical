#include "gameobject.h"

using namespace nautical;

GameObject::GameObject(char* name) : _name(name)
{
    // Do Constructor Stuff
}

GameObject::~GameObject()
{
    // Unload Constructor Stuff
}

void GameObject::update()
{
    // Update all scripts
    // Update all components
    // Update all children
}

void GameObject::lateUpdate()
{
    // Update all scripts
    // Update all children
}

void GameObject::addComponent(char* name, GameComponent* component)
{
    // Insert component into dictionary with name (hashed)
    _components.insert(std::make_pair(_hashAlg(name), component));
}

GameComponent* GameObject::getComponent(char* name)
{
    return _components.at(_hashAlg(name));
}
