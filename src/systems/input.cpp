#include "systems/input.h"

#include <GLFW/glfw3.h>

#include <stdio.h>

using namespace nautical;
using namespace nautical::systems;

Input::Input(GLFWwindow* window)
{
    glfwSetWindowUserPointer(window, this);

    auto callback = [](GLFWwindow* w, int k, int, int a, int)
    {
        static_cast<Input*>(glfwGetWindowUserPointer(w))->keyCallback(k, a);
    };

    glfwSetKeyCallback(window, callback);
}

Input::~Input()
{
}

bool Input::keyPressed(std::string name)
{
    return _keyValues[name] & 1;
}

bool Input::keyJustReleased(std::string name)
{
    return !(_keyValues[name] & 1) && (_keyValues[name] & 2);
}

void Input::setKeyBinding(std::string name, int key)
{
    _keyCodes[key] = name;
    _keyValues[name] = 0;
}

void Input::clearKeyBinding(int key)
{
    _keyValues.erase(_keyCodes[key]);
    _keyCodes.erase(key);
}

void Input::keyCallback(int key, int action)
{
    std::string name = _keyCodes[key];

    _keyValues[name] <<= 1;

    int k = action;

    k = (k & 1) || (k & 2);

    _keyValues[name] |= k;
}
