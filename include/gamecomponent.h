#pragma once

#include <unordered_map>

namespace nautical
{
    class GameObject;
    class GameComponent
    {
    public:
        GameComponent(GameObject* hostObj) : _hostObj{hostObj} {}

        virtual ~GameComponent() = 0;

        virtual void init() = 0;

        virtual void update() = 0;

    private:
        GameObject* _hostObj;
    };
}
