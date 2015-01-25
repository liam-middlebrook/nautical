#include "vector4.h"
#include <stdio.h>

using namespace nautical::math;

void print_vector(Vector4<float> vector)
{
    printf("Vector: X: %f Y: %f Z: %f W: %f", vector.x, vector.y, vector.z, vector.w);
}

void test_vector4_add(void)
{
    Vector4<float> vec1(15.0f, -30.0f, 10.2f, 36.0f);
    Vector4<float> vec2(28.0f, 14.4, -2.0f, -16.0f);

    Vector4<float> answer(43.0f, -15.6f, 8.2f, 20.0f);

    CU_ASSERT((vec1 + vec2) == answer);

    vec1 += vec2;
    CU_ASSERT(vec1 == answer);
}

void test_vector4_subtract(void)
{
    Vector4<float> vec1(15.0f, -30.0f, 2.0f, 30.0f);
    Vector4<float> vec2(28.0f, 14.4, -3.0f, -5.0f);

    Vector4<float> answer(-13.0f, -44.4f, 5.0f, 35.0f);

    CU_ASSERT((vec1 - vec2) == answer);

    vec1 -= vec2;
    CU_ASSERT(vec1 == answer);
}

void test_vector4_multiply(void)
{
    Vector4<float> vec1(15.0f, -30.0f, 2.5f, 3.0f);
    Vector4<float> vec2(28.0f, 14.4, 2.0f, 4.0f);

    Vector4<float> answer(420.0f, -432.0f, 5.0f, 12.0f);

    CU_ASSERT((vec1 * vec2) == answer);

    vec1 *= vec2;
    CU_ASSERT(vec1 == answer);
}

void test_vector4_divide(void)
{
    Vector4<float> vec1(15.0f, -30.0f, 49.0f, 24.0f);
    Vector4<float> vec2(5.0f, 6.0f, -7.0f, -6.0f);

    Vector4<float> answer(3.0f, -5.0f, -7.0f, -4.0f);

    CU_ASSERT((vec1 / vec2) == answer);

    vec1 /= vec2;
    CU_ASSERT(vec1 == answer);
}

void test_vector4_magnitude(void)
{
    Vector4<float> vec1(3.0f, 4.0f, 3.0f, 5.0f);
    float magnitude = sqrt(59);

    CU_ASSERT(vec1.length() == magnitude);
    CU_ASSERT(vec1.lengthSquared() == 34.0f);
}

void test_vector4_dot(void)
{
    Vector4<float> vec1(3.0f, 5.0f, 12.0f, 5.0f);
    Vector4<float> vec2(12.0f, -2.0f, 4.0f, 2.0f);

    float answer = 84.0f;

    CU_ASSERT(vec1.dot(vec2) == answer);
}

void test_vector4_normalize(void)
{
    Vector4<float> vec1(15.0f, 0.0f, 0.0f, 0.0f);
    Vector4<float> vec1Ans(1.0f, 0.0f, 0.0f, 0.0f);

    Vector4<float> vec2(3.0f, 4.0f, 3.0f, 5.0f);
    Vector4<float> vec2Ans(3.0f/sqrt(59), 4.0f/sqrt(59), 3/sqrt(59), 5/sqrt(59));

    CU_ASSERT(vec1.normalized() == vec1Ans);
    CU_ASSERT(vec2.normalized() == vec2Ans);
}
