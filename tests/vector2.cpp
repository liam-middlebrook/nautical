#include "vector2.h"
#include <stdio.h>

using namespace nautical::math;

void print_vector(Vector2<float> vector)
{
    printf("Vector: X: %f Y: %f", vector.x, vector.y);
}

void test_vector2_add(void)
{
    Vector2<float> vec1(15.0f, -30.0f);
    Vector2<float> vec2(28.0f, 14.4);

    Vector2<float> answer(43.0f, -15.6f);

    CU_ASSERT((vec1 + vec2) == answer);

    vec1 += vec2;
    CU_ASSERT(vec1 == answer);
}

void test_vector2_subtract(void)
{
    Vector2<float> vec1(15.0f, -30.0f);
    Vector2<float> vec2(28.0f, 14.4);

    Vector2<float> answer(-13.0f, -44.4f);

    CU_ASSERT((vec1 - vec2) == answer);

    vec1 -= vec2;
    CU_ASSERT(vec1 == answer);
}

void test_vector2_multiply(void)
{
    Vector2<float> vec1(15.0f, -30.0f);
    Vector2<float> vec2(28.0f, 14.4);

    Vector2<float> answer(420.0f, -432.0f);

    CU_ASSERT((vec1 * vec2) == answer);

    vec1 *= vec2;
    CU_ASSERT(vec1 == answer);
}

void test_vector2_divide(void)
{
    Vector2<float> vec1(15.0f, -30.0f);
    Vector2<float> vec2(5.0f, 6.0f);

    Vector2<float> answer(3.0f, -5.0f);

    CU_ASSERT((vec1 / vec2) == answer);

    vec1 /= vec2;
    CU_ASSERT(vec1 == answer);
}

void test_vector2_magnitude(void)
{
    Vector2<float> vec1(3.0f, 4.0f);
    float magnitude = 5.0f;

    CU_ASSERT(vec1.length() == magnitude);
    CU_ASSERT(vec1.lengthSquared() == magnitude * magnitude);
}

void test_vector2_dot(void)
{
    Vector2<float> vec1(3.0f, 5.0f);
    Vector2<float> vec2(12.0f, -2.0f);

    float answer = 26.0f;

    CU_ASSERT(vec1.dot(vec2) == answer);
}
