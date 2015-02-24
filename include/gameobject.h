#pragma once

#include "transform.h"
#include <unordered_map>

namespace nautical
{
    class GameObject
    {
    public:
        Transform<float> transform;

        GameObject(char* name);

        virtual ~GameObject();

        virtual void update();

        virtual void lateUpdate();

        void addComponent(char* name, GameComponent* component);

        GameComponent* getComponent(char* name);

    private:
        const char* _name;
        std::hash<char*> _hashAlg;
        std::unordered_map<size_t, GameObject*> _children;
        std::unordered_map<size_t, NauticalScript*> _scripts;
        std::unordered_map<size_t, GameComponent*> _components;
    };
}
