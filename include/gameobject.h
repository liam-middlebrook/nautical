#pragma once

#include "transform.h"
#include <unordered_map>

namespace nautical
{
    class GameComponent;
    class Engine;
    namespace script
    {
        class Script;
    }

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
        void addComponent(const char* name, GameComponent* component);

        // Adds a script with the specified name to the object
        void addScript(const char* name, script::Script* script);

        // Gets the Transformation Matrix of the Game Object in absolute
        // coordinates (this factors in the local transformation and it's
        // parents' transformation)
        math::Matrix4<float> getMatrix();

        // Gets a pointer to the parent Game Object
        // If a parent doesn't exist, returns null
        GameObject* getParent();

        // createa a new child gameobject
        // This is *essentially* it's constructor
        GameObject* addChild(const char* name);

        // Retrives a component from the gameobject
        GameComponent* getComponent(const char* name);

        // Retrives a script from the gameobject
        script::Script* getScript(const char* name);

        // Gets the engine instance that this object was created in
        inline Engine& getEngine()
        {
            return _engine;
        }

    private:
        GameObject(const char* name, Engine& engine, GameObject* parent);
        ~GameObject();

        const char* _name;
        Engine& _engine;
        GameObject* _parent;
        std::hash<const char*> _hashAlg;
        std::unordered_map<size_t, GameObject*> _children;
        std::unordered_map<size_t, script::Script*> _scripts;
        std::unordered_map<size_t, GameComponent*> _components;

        friend class Engine;
    };
}
