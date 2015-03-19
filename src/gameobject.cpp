#include "gameobject.h"

#include "engine.h"
#include "gamecomponent.h"
#include "nauticalscript.h"

using namespace nautical;

GameObject::GameObject(char* name, Engine* engine)
    : _name{name}, _engine{engine}
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
        script.second->init();
    }

    // Init all components
    for(auto& component : _components)
    {
        component.second->init();
    }

    // Init all children
    for(auto& child : _children)
    {
        child.second->init();
    }
}

void GameObject::update()
{
    // Update all scripts
    for(auto& script : _scripts)
    {
        script.second->update();
    }

    // Update all components
    for(auto& component : _components)
    {
        component.second->update();
    }

    // Update all children
    for(auto& child : _children)
    {
        child.second->update();
    }
}

void GameObject::lateUpdate()
{
    // Update all scripts
    for(auto& script : _scripts)
    {
        script.second->lateUpdate();
    }

    // Update all children
    for(auto& child : _children)
    {
        child.second->lateUpdate();
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

GameObject* GameObject::addChild(char* name)
{
    GameObject* newObject = new GameObject(name, _engine);

    _children.insert(std::make_pair(_hashAlg(name), newObject));

    return newObject;
}

GameComponent* GameObject::getComponent(char* name)
{
    return _components.at(_hashAlg(name));
}

NauticalScript* GameObject::getScript(char* name)
{
    return _scripts.at(_hashAlg(name));
}
