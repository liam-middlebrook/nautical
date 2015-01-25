#include <cstdio>

#include "math/vector2.h"
#include "math/matrix3.h"

int main(int argc, char** argv)
{
    nautical::math::Vector2<double> vector(4.0f, 3.0f);

    nautical::math::Vector2<double> b(7.0, 4.0);

    vector += b;

    printf("Vector: %f, %f", vector[1], vector.y);

    printf("Length: %f", vector.length());

    printf("Direction %f", vector.direction());
    return 0;
}
