#include "gameobject.h"
#include <cstring>
#include <functional>
#include <time.h>

using namespace nautical;

std::unordered_map<char*, int> GameObject::_objectsStr;
std::unordered_map<int, GameObject*> GameObject::_objectsID;

GameObject::GameObject(char* name)
{
    this->_name = name;
    this->_id = std::hash<char*>()(name) * time_t(nullptr);

    GameObject::_objectsID.insert(std::make_pair(this->_id, this));
    GameObject::_objectsStr.insert(std::make_pair(this->_name, this->_id));
}

void GameObject::GetChildByName(GameObject* parent, char* name,
                                std::vector<GameObject*>& retList,
                                bool recursive)
{
    if(recursive)
    {
        // Iterate through any children
        std::vector<GameObject*>& list = (parent->_children);
        for(auto itr : list)
        {
            GameObject::GetChildByName(itr, name, retList, true);
        }
    }

    if (!strcmp(parent->getName(), name))
    {
        retList.push_back(parent);
    }
}

void GameObject::GetByName(char* name, std::vector<GameObject*> retList)
{
    for(auto& itr : GameObject::_objectsStr)
    {
        if(!strcmp(itr.first, name))
        {
            retList.push_back(GameObject::_objectsID.at(itr.second));
        }
    }
}

GameObject* GameObject::GetById(int id)
{
    for(auto& itr : GameObject::_objectsID)
    {
        if(itr.first == id)
        {
            return itr.second;
        }
    }
    return nullptr;
}
