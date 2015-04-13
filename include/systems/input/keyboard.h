#pragma once

#include <string>
#include <unordered_map>

struct GLFWwindow;

namespace nautical
{
    namespace systems
    {
        namespace input
        {
            class Keyboard
            {
            public:
                Keyboard(GLFWwindow* window);
                ~Keyboard();

                bool keyPressed(std::string name);

                bool keyJustReleased(std::string name);

                void setKeyBinding(std::string name, int key);

                void clearKeyBinding(int key);

            private:
                void keyCallback(int key, int action);

                // stored value w/ 8 prev states
                std::unordered_map<std::string, char> _keyValues;

                // keycode with string association
                std::unordered_map<int, std::string> _keyCodes;
            };
        }
    }
}
