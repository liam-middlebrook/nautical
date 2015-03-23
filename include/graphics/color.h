#pragma once

namespace nautical
{
    namespace graphics
    {
        class Color
        {
        public:
            constexpr Color() : r{1.0f}, g{1.0f}, b{1.0f}, a{1.0f} {}
            constexpr Color(float x) : r{x}, g{x}, b{x}, a{1.0f} {}
            constexpr Color(float r, float g, float b) : r{r}, g{g}, b{b}, a{1.0f} {}
            constexpr Color(float r, float g, float b, float a) : r{r}, g{g}, b{b}, a{a} {}
            float r, g, b, a;
        };

        namespace Colors
        {
            static constexpr Color Red = Color(1.0f, 0.0f, 0.0f);
        };
    }
}
