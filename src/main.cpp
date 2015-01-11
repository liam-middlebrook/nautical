#include <cstdio>

#include "math/vector2.h"

int main(int argc, char** argv)
{
    nautical::math::Vector2<double> vector(4.0f, 3.0f);

    printf("Vector: %f, %f", vector.x, vector.y);

    printf("Length: %f", vector.length());

    printf("Direction %f", vector.direction());
    return 0;
}
