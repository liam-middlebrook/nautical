#include "gameobject.h"

#include "engine.h"
#include "gamecomponent.h"
#include "scriptloader.h"
#include "script.h"

using namespace nautical;
using nautical::script::Script;

GameObject::GameObject(const char* name, Engine& engine, GameObject* parent)
    : _name{name}, _engine{engine}, _parent{parent}
{
    // Do Constructor Stuff
}

GameObject::~GameObject()
{
    // Unload Constructor Stuff
}

void GameObject::init()
{
    printf("\niniti\n");
    // Init all scripts
    for (auto& script : _scripts)
    {
        script.second->init();
    }
    printf("\nasda\n");
    printf("%d compeontents\n", _components.size());
    // Init all components
    for (auto& component : _components)
    {
        printf("hey i am: %s I am gonna init components\n", this->_name);
        printf("\nname %d\n", component.second);
        component.second->init();
    }

    // Init all children
    for (auto& child : _children)
    {
        child.second->init();
    }
}

void GameObject::update()
{
    // Update all scripts
    for (auto& script : _scripts)
    {
        script.second->update();
    }

    // Update all components
    for (auto& component : _components)
    {
        component.second->update();
    }

    // Update all children
    for (auto& child : _children)
    {
        child.second->update();
    }
}

void GameObject::lateUpdate()
{
    // Update all scripts
    for (auto& script : _scripts)
    {
        script.second->lateUpdate();
    }

    // Update all children
    for (auto& child : _children)
    {
        child.second->lateUpdate();
    }
}

void GameObject::addComponent(const char* name, GameComponent* component)
{
    printf("adding a componenetns: %d\n", component);
    // Insert component into dictionary with name (hashed)
    _components.insert(std::make_pair(_hashAlg(name), component));
}

void GameObject::addScript(const char* name, Script* script)
{
    // Insert script into dictionary with name (hashed)
    _scripts.insert(std::make_pair(_hashAlg(name), script));
}

GameObject* GameObject::addChild(const char* name)
{
    GameObject* newObject = new GameObject(name, _engine, this);

    _children.insert(std::make_pair(_hashAlg(name), newObject));

    return newObject;
}

GameComponent* GameObject::getComponent(const char* name)
{
    return _components.at(_hashAlg(name));
}

Script* GameObject::getScript(const char* name)
{
    return _scripts.at(_hashAlg(name));
}

GameObject* GameObject::getParent()
{
    return _parent;
}

math::Matrix4<float> GameObject::getMatrix()
{
    if (_parent != nullptr)
    {
        return transform.getMatrix() * _parent->getMatrix();
    }

    return transform.getMatrix();
}
