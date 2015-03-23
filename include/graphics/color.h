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
            static constexpr Color White = Color(1.0f, 1.0f, 1.0f);
            static constexpr Color Black = Color(0.0f, 0.0f, 0.0f);
            static constexpr Color Gray = Color(0.5f, 0.5f, 0.5f);
            static constexpr Color Silver = Color(0.75f, 0.75f, 0.75f);
            static constexpr Color Maroon = Color(0.5f, 0.0f, 0.0f);
            static constexpr Color Red = Color(1.0f, 0.0f, 0.0f);
            static constexpr Color Olive = Color(0.5f, 0.5f, 0.0f);
            static constexpr Color Yellow = Color(1.0f, 1.0f, 0.0f);
            static constexpr Color Green = Color(0.0f, 0.5f, 0.0f);
            static constexpr Color Lime = Color(0.0f, 1.0f, 0.0f);
            static constexpr Color Teal = Color(0.0f, 0.5f, 0.5f);
            static constexpr Color Aqua = Color(0.0f, 1.0f, 1.0f);
            static constexpr Color Navy = Color(0.0f, 0.0f, 0.5f);
            static constexpr Color Blue = Color(0.0f, 0.0f, 1.0f);
            static constexpr Color Purple = Color(0.5f, 0.0f, 0.5f);
            static constexpr Color Fuchsia = Color(1.0f, 0.0f, 1.0f);
        }
    }
}
