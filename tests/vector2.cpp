#include "vector2.h"
#include <stdio.h>

void print_vector(nautical::math::Vector2<float> vector)
{
    printf("Vector: X: %f Y: %f", vector.x, vector.y);
}


void test_vector2_add(void)
{
    // Lets pretend addition works for now

    using namespace nautical::math;

    Vector2<float> vec1(15.0f, -30.0f);
    Vector2<float> vec2(28.0f, 14.4);

    CU_ASSERT((vec1 + vec2) == Vector2<float>(43.0f, -15.6f));
}
