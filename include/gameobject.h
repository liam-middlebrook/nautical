#pragma once

#include "transform.h"
#include <unordered_map>

namespace nautical
{
    class GameComponent;
    class NauticalScript;
    class Engine;

    class GameObject
    {
    public:
        // World Transformation for GameObject
        Transform<float> transform;

        // Init Function (called at object creation)
        void init();

        // Update Function (called once per gameloop)
        void update();

        // LateUpdate function (called once per gameloop)
        void lateUpdate();

        // Adds a component with the specified name to the object
        void addComponent(char* name, GameComponent* component);

        // Adds a script with the specified name to the object
        void addScript(char* name, NauticalScript* script);

        // createa a new child gameobject
        // This is *essentially* it's constructor
        GameObject* addChild(char* name);

        // Retrives a component from the gameobject
        GameComponent* getComponent(char* name);

        NauticalScript* getScript(char* name);

        inline Engine* getEngine()
        {
            return _engine;
        }

    private:
        GameObject(char* name, Engine* engine);
        ~GameObject();

        const char* _name;
        Engine* _engine;
        std::hash<char*> _hashAlg;
        std::unordered_map<size_t, GameObject*> _children;
        std::unordered_map<size_t, NauticalScript*> _scripts;
        std::unordered_map<size_t, GameComponent*> _components;

        friend class GameComponent;
    };
}
