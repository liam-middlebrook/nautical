#include "matrix3.h"
#include <stdio.h>

using namespace nautical::math;

void print_vector3(Vector3<float> vector)
{
    printf("Vector: X: %f Y: %f Z: %f\n", vector.x, vector.y, vector.z);
}

void print_matrix(Matrix3<float> m)
{
    printf("Matrix3:\n"
           "%f %f %f\n"
           "%f %f %f\n"
           "%f %f %f\n",
           m(0, 0), m(0, 1), m(0, 2), m(1, 0), m(1, 1), m(1, 2), m(2, 0),
           m(2, 1), m(2, 2));
}

void test_matrix3_add(void)
{
    Matrix3<float> dummy;
    Matrix3<float> mat1;
    mat1(0, 0) = 15.0f;
    mat1(1, 2) = -70.0f;
    mat1(2, 0) = 14.6f;
    mat1(2, 2) = -3.5f;

    Matrix3<float> answer;
    answer(0, 0) = 16.0f;
    answer(1, 1) = 2.0f;
    answer(1, 2) = -70.0f;
    answer(2, 0) = 14.6f;
    answer(2, 2) = -2.5f;

    CU_ASSERT((mat1 + Matrix3<float>::identity) == answer);

    dummy = mat1;
    dummy += Matrix3<float>::identity;

    CU_ASSERT(dummy == answer);
}

void test_matrix3_subtract(void)
{
    Matrix3<float> dummy;
    Matrix3<float> mat1;
    mat1(0, 0) = 15.0f;
    mat1(1, 2) = -70.0f;
    mat1(2, 0) = 14.6f;
    mat1(2, 2) = -3.5f;

    Matrix3<float> answer;
    answer(0, 0) = 14.0f;
    answer(1, 1) = 0.0f;
    answer(1, 2) = -70.0f;
    answer(2, 0) = 14.6f;
    answer(2, 2) = -4.5f;

    CU_ASSERT((mat1 - Matrix3<float>::identity) == answer);

    dummy = mat1;
    dummy -= Matrix3<float>::identity;

    CU_ASSERT(dummy == answer);
}

void test_matrix3_multiply(void)
{
    Matrix3<float> dummy;
    Matrix3<float> mat1;

    Matrix3<float> mat2;
    mat2(0, 0) = 3;
    mat2(1, 1) = 5;
    mat2(2, 2) = 7;

    Matrix3<float> answer;
    answer(0, 0) = 3;
    answer(1, 1) = 5;
    answer(2, 2) = 7;

    CU_ASSERT((mat1 * mat2) == answer);

    dummy = mat1;
    dummy *= mat2;

    CU_ASSERT(dummy == answer);
    CU_ASSERT((mat2 * mat1) == answer);

    dummy = mat2;
    dummy *= mat1;

    CU_ASSERT(dummy == answer);

    mat1(0, 2) = 2;
    mat1(1, 1) = 4;
    mat1(2, 0) = 6;

    answer = Matrix3<float>();
    answer(0, 0) = 3;
    answer(0, 2) = 14;
    answer(1, 1) = 20;
    answer(2, 0) = 18;
    answer(2, 2) = 7;

    CU_ASSERT((mat1 * mat2) == answer);

    answer = Matrix3<float>();
    answer(0, 0) = 3;
    answer(0, 2) = 6;
    answer(1, 1) = 20;
    answer(2, 0) = 42;
    answer(2, 2) = 7;

    CU_ASSERT((mat2 * mat1) == answer);
}

void test_matrix3_vector(void)
{
    Vector3<float> vec(12.0f, 14.6f, -10.0f);

    Matrix3<float> mat;

    mat(0, 0) = 3.0f;
    mat(1, 1) = 0.5f;
    mat(2, 2) = -2.0f;

    Vector3<float> answer(36.0f, 7.3f, 20.0f);

    CU_ASSERT(Vector3<float>(mat * vec) == answer);
}

void test_matrix3_transpose(void)
{
    Matrix3<float> mat;
    mat(0, 1) = 5.0f;
    Matrix3<float> answer;
    answer(1, 0) = 5.0f;

    CU_ASSERT(mat.transpose() == answer);
}

void test_matrix3_scale(void)
{
    Matrix3<float> mat = Matrix3<float>::scale(Vector2<float>(15.0f, -5.0f));

    Matrix3<float> answer;
    answer(0, 0) = 15.0f;
    answer(1, 1) = -5.0f;

    CU_ASSERT(mat == answer);
}

void test_matrix3_rotate(void)
{
    Matrix3<float> mat = Matrix3<float>::rotate(degreesToRadians(90.0f));

    Matrix3<float> answer;
    answer(0, 0) = -0.0f;
    answer(1, 1) = -0.0f;
    answer(0, 1) = -1.0f;
    answer(1, 0) = 1.0f;

    CU_ASSERT(mat == answer);

    answer = Matrix3<float>::rotate(degreesToRadians(-270.0f));

    CU_ASSERT(mat == answer);
}

void test_matrix3_translate(void)
{
    Matrix3<float> mat =
        Matrix3<float>::translate(Vector2<float>(15.0f, -10.0f));

    Matrix3<float> answer;

    answer(0, 2) = 15.0f;
    answer(1, 2) = -10.0f;

    CU_ASSERT(mat == answer);
}

void test_matrix3_determinant(void)
{
    Matrix3<float> mat;
    mat(0, 0) = 1.0f;
    mat(0, 1) = 2.0f;
    mat(0, 2) = 3.0f;
    mat(1, 0) = 0.0f;
    mat(1, 1) = -4.0f;
    mat(1, 2) = 1.0f;
    mat(2, 0) = 0.0f;
    mat(2, 1) = 3.0f;
    mat(2, 2) = -1.0f;

    CU_ASSERT(mat.determinant() == 1.0f);
}

void test_matrix3_inverse(void)
{
    Matrix3<float> mat;

    mat(0, 0) = 2.0f;
    mat(0, 2) = 2.0f;
    mat(1, 2) = 2.0f;
    mat(2, 2) = 2.0f;

    Matrix3<float> inv;
    inv(0, 0) = 0.5f;
    inv(0, 2) = -0.5f;
    inv(1, 2) = -1.0f;
    inv(2, 2) = 0.5f;

    CU_ASSERT(mat.inverse() == inv);
}
