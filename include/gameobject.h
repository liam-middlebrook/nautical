#pragma once

#include <vector>

namespace nautical
{
    class GameObject
    {
    public:
        Transform transform;

        static GameObject* Create(char* name);

        inline const int getId()
        {
            return _id;
        }

        inline const char* getName()
        {
            return _name;
        }
    private:
        GameObject();
        char* _name;
        int _id;
        std::vector _children;
    };
}
