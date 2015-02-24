#include "gameobject.h"

using namespace nautical;

GameObject::GameObject(char* name) : _name{name}
{
    // Do Constructor Stuff
}

GameObject::~GameObject()
{
    // Unload Constructor Stuff
}

void GameObject::init()
{
    // Init all scripts
    for(auto& script : _scripts)
    {
        script.init();
    }

    // Init all components
    for(auto& component : _components)
    {
        component.init();
    }

    // Init all children
    for(auto& child : _children)
    {
        child.init();
    }
}

void GameObject::update()
{
    // Update all scripts
    for(auto& script : _scripts)
    {
        script.update();
    }

    // Update all components
    for(auto& component : _components)
    {
        component.update();
    }

    // Update all children
    for(auto& child : _children)
    {
        child.update();
    }
}

void GameObject::lateUpdate()
{
    // Update all scripts
    for(auto& script : _scripts)
    {
        script.lateUpdate();
    }

    // Update all children
    for(auto& child : _children)
    {
        child.lateUpdate();
    }
}

void GameObject::addComponent(char* name, GameComponent* component)
{
    // Insert component into dictionary with name (hashed)
    _components.insert(std::make_pair(_hashAlg(name), component));
}

void GameObject::addScript(char* name, NauticalScript* script)
{
    // Insert script into dictionary with name (hashed)
    _scripts.insert(std::make_pair(_hashAlg(name), script));
}

GameComponent* GameObject::getComponent(char* name)
{
    return _components.at(_hashAlg(name));
}
