#pragma once

namespace nautical
{
    // Forward Declare
    class GameObject;
    class GameComponent
    {
    public:
        // Create a component that will be unique to a host obj
        GameComponent(GameObject* hostObj) : _hostObj{hostObj} {}

        virtual ~GameComponent() = 0;

        // Initialization logic for the component
        virtual void init() = 0;

        // Update logic for the component
        virtual void update() = 0;

    private:
        GameObject* _hostObj;
    };
}
