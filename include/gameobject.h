#pragma once

#include "gamecomponent.h"
#include "transform.h"
#include <unordered_map>

namespace nautical
{
    class GameObject
    {
    public:
        // World Transformation for GameObject
        Transform<float> transform;

        GameObject(char* name);

        virtual ~GameObject();

        // Init Function (called at object creation)
        virtual void init();

        // Update Function (called once per gameloop)
        virtual void update();

        // LateUpdate function (called once per gameloop)
        virtual void lateUpdate();

        // Adds a component with the specified name to the object
        void addComponent(char* name, GameComponent* component);

        // Adds a script with the specified name to the object
        void addScript(char* name, NauticalScript* script);

        // Retrives a component from the gameobject
        GameComponent* getComponent(char* name);

    private:
        const char* _name;
        std::hash<char*> _hashAlg;
        std::unordered_map<size_t, GameObject*> _children;
        std::unordered_map<size_t, NauticalScript*> _scripts;
        std::unordered_map<size_t, GameComponent*> _components;
    };
}
