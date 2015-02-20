#pragma once

#include "transform.h"
#include <vector>
#include <unordered_map>

namespace nautical
{
    class GameObject
    {
    public:
        Transform<float> transform;

        GameObject(char* name);

        static GameObject* GetById(int id);

        static void GetChildByName(GameObject* parent, char* name,
                                        std::vector<GameObject*>& retList,
                                        bool recursive);

        static void GetByName(char* name,
                                            std::vector<GameObject*> retList);

        inline int getId()
        {
            return _id;
        }

        inline const char* getName()
        {
            return _name;
        }

    protected:
        virtual void update() = 0;

        virtual void lateUpdate() = 0;

        virtual void render() = 0;

    private:
        char* _name;
        int _id;
        std::vector<GameObject*> _children;

        static std::unordered_map<char*, int> _objectsStr;
        static std::unordered_map<int, GameObject*> _objectsID;
    };
}
