#include <cstdio>

#include "math/vector2.h"

int main(int argc, char** argv)
{
    nautical::math::Vector2<float> vector(2.0f, 3.0f);

    printf("Vector: %f, %f", vector.x, vector.y);
    return 0;
}
