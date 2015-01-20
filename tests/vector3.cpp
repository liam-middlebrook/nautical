#include "vector3.h"
#include <stdio.h>

using namespace nautical::math;

void print_vector(Vector3<float> vector)
{
    printf("Vector: X: %f Y: %f Z: %f", vector.x, vector.y, vector.z);
}

void test_vector3_add(void)
{
    Vector3<float> vec1(15.0f, -30.0f, 10.2f);
    Vector3<float> vec2(28.0f, 14.4, -2.0f);

    Vector3<float> answer(43.0f, -15.6f, 8.2f);

    CU_ASSERT((vec1 + vec2) == answer);

    vec1 += vec2;
    CU_ASSERT(vec1 == answer);
}

void test_vector3_subtract(void)
{
    Vector3<float> vec1(15.0f, -30.0f, 2.0f);
    Vector3<float> vec2(28.0f, 14.4, -3.0f);

    Vector3<float> answer(-13.0f, -44.4f, 5.0f);

    CU_ASSERT((vec1 - vec2) == answer);

    vec1 -= vec2;
    CU_ASSERT(vec1 == answer);
}

void test_vector3_multiply(void)
{
    Vector3<float> vec1(15.0f, -30.0f, 2.5f);
    Vector3<float> vec2(28.0f, 14.4, 2.0f);

    Vector3<float> answer(420.0f, -432.0f, 5.0f);

    CU_ASSERT((vec1 * vec2) == answer);

    vec1 *= vec2;
    CU_ASSERT(vec1 == answer);
}

void test_vector3_divide(void)
{
    Vector3<float> vec1(15.0f, -30.0f, 49.0f);
    Vector3<float> vec2(5.0f, 6.0f, -7.0f);

    Vector3<float> answer(3.0f, -5.0f, -7.0f);

    CU_ASSERT((vec1 / vec2) == answer);

    vec1 /= vec2;
    CU_ASSERT(vec1 == answer);
}

void test_vector3_magnitude(void)
{
    Vector3<float> vec1(3.0f, 4.0f, 3.0f);
    float magnitude = sqrt(34);

    CU_ASSERT(vec1.length() == magnitude);
    CU_ASSERT(vec1.lengthSquared() == 34.0f);
}

void test_vector3_dot(void)
{
    Vector3<float> vec1(3.0f, 5.0f, 12.0f);
    Vector3<float> vec2(12.0f, -2.0f, 4.0f);

    float answer = 74.0f;

    CU_ASSERT(vec1.dot(vec2) == answer);
}

void test_vector3_cross(void)
{
    Vector3<float> vec1(3.0f, 5.0f, 4.0f);
    Vector3<float> vec2(3.0f, -2.0f, 1.0f);

    Vector3<float> cross(13.0f, 9.0f, -21.0f);

    CU_ASSERT(vec1.cross(vec2) == cross);
}

void test_vector3_normalize(void)
{
    Vector3<float> vec1(15.0f, 0.0f, 0.0f);
    Vector3<float> vec1Ans(1.0f, 0.0f, 0.0f);

    Vector3<float> vec2(30.0f, 40.0f, 5.0f);
    Vector3<float> vec2Ans(6.0f/sqrt(101), 8.0f/sqrt(101), 1/sqrt(101));

    CU_ASSERT(vec1.normalized() == vec1Ans);
    CU_ASSERT(vec2.normalized() == vec2Ans);
}
