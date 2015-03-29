#include "systems/input/keyboard.h"

#include <GLFW/glfw3.h>

#include <stdio.h>

using namespace nautical::systems::input;

Keyboard::Keyboard(GLFWwindow* window)
{
    glfwSetWindowUserPointer(window, this);

    auto callback = [](GLFWwindow* w, int k, int, int a, int)
    {
        static_cast<Keyboard*>(glfwGetWindowUserPointer(w))->keyCallback(k, a);
    };

    glfwSetKeyCallback(window, callback);
}

Keyboard::~Keyboard()
{
}

bool Keyboard::keyPressed(std::string name)
{
    return _keyValues[name] & 1;
}

bool Keyboard::keyJustReleased(std::string name)
{
    return !(_keyValues[name] & 1) && (_keyValues[name] & 2);
}

void Keyboard::setKeyBinding(std::string name, int key)
{
    _keyCodes[key] = name;
    _keyValues[name] = 0;
}

void Keyboard::clearKeyBinding(int key)
{
    _keyValues.erase(_keyCodes[key]);
    _keyCodes.erase(key);
}

void Keyboard::keyCallback(int key, int action)
{
    std::string name = _keyCodes[key];

    _keyValues[name] <<= 1;

    int k = action;

    k = (k & 1) || (k & 2);

    _keyValues[name] |= k;
}
