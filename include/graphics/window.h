#pragma once

struct GLFWwindow;

namespace nautical
{
    namespace graphics
    {
        class Window
        {
        public:
            Window(int width, int height, const char* title);

            virtual ~Window();

            GLFWwindow* getWindow();

            void getSize(int& w, int& h);

            bool shouldClose();

            void setActive();

            void render();

            static bool init();

        private:
            GLFWwindow* _window;
            int _w, _h;
        };
    }
}
