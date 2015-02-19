#include "matrix4.h"
#include <stdio.h>

using namespace nautical::math;

void print_matrix44(Matrix4<float> m)
{
    printf("Matrix4:\n"
           "%f %f %f %f\n"
           "%f %f %f %f\n"
           "%f %f %f %f\n"
           "%f %f %f %f\n",
           m(0, 0), m(0, 1), m(0, 2), m(0, 3), m(1, 0), m(1, 1), m(1, 2),
           m(1, 3), m(2, 0), m(2, 1), m(2, 2), m(2, 3), m(3, 0), m(3, 1),
           m(3, 2), m(3, 3));
}

void test_matrix4_add(void)
{
    Matrix4<float> dummy;
    Matrix4<float> mat1;
    mat1(0, 0) = 15.0f;
    mat1(1, 2) = -70.0f;
    mat1(2, 0) = 14.6f;
    mat1(2, 2) = -3.5f;
    mat1(3, 3) = 1.0f;

    Matrix4<float> answer;
    answer(0, 0) = 16.0f;
    answer(1, 1) = 2.0f;
    answer(1, 2) = -70.0f;
    answer(2, 0) = 14.6f;
    answer(2, 2) = -2.5f;
    answer(3, 3) = 2.0f;

    CU_ASSERT((mat1 + Matrix4<float>::identity) == answer);

    dummy = mat1;
    dummy += Matrix4<float>::identity;

    CU_ASSERT(dummy == answer);
}

void test_matrix4_subtract(void)
{
    Matrix4<float> dummy;
    Matrix4<float> mat1;
    mat1(0, 0) = 15.0f;
    mat1(1, 2) = -70.0f;
    mat1(2, 0) = 14.6f;
    mat1(2, 2) = -3.5f;

    Matrix4<float> answer;
    answer(0, 0) = 14.0f;
    answer(1, 1) = 0.0f;
    answer(1, 2) = -70.0f;
    answer(2, 0) = 14.6f;
    answer(2, 2) = -4.5f;
    answer(3, 3) = 0.0f;

    CU_ASSERT((mat1 - Matrix4<float>::identity) == answer);

    dummy = mat1;
    dummy -= Matrix4<float>::identity;

    CU_ASSERT(dummy == answer);
}

void test_matrix4_multiply(void)
{
    Matrix4<float> dummy;
    Matrix4<float> mat1;

    Matrix4<float> mat2;
    mat2(0, 0) = 3;
    mat2(1, 1) = 5;
    mat2(2, 2) = 7;
    mat2(3, 3) = 9;

    Matrix4<float> answer;
    answer(0, 0) = 3;
    answer(1, 1) = 5;
    answer(2, 2) = 7;
    answer(3, 3) = 9;

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

    answer = Matrix4<float>();
    answer(0, 0) = 3;
    answer(0, 2) = 14;
    answer(1, 1) = 20;
    answer(2, 0) = 18;
    answer(2, 2) = 7;
    answer(3, 3) = 9;

    CU_ASSERT((mat1 * mat2) == answer);

    answer = Matrix4<float>();
    answer(0, 0) = 3;
    answer(0, 2) = 6;
    answer(1, 1) = 20;
    answer(2, 0) = 42;
    answer(2, 2) = 7;
    answer(3, 3) = 9;

    CU_ASSERT((mat2 * mat1) == answer);
}

void test_matrix4_vector(void)
{
    Vector4<float> vec(12.0f, 14.6f, -10.0f, 10.0f);

    Matrix4<float> mat;

    mat(0, 0) = 3.0f;
    mat(1, 1) = 0.5f;
    mat(2, 2) = -2.0f;

    Vector4<float> answer(36.0f, 7.3f, 20.0f, 10.0f);

    CU_ASSERT(Vector4<float>(mat * vec) == answer);
}

void test_matrix4_transpose(void)
{
    Matrix4<float> mat;
    mat(0, 1) = 5.0f;
    Matrix4<float> answer;
    answer(1, 0) = 5.0f;

    CU_ASSERT(mat.transpose() == answer);
}

void test_matrix4_scale(void)
{
    Matrix4<float> mat =
        Matrix4<float>::scale(Vector3<float>(15.0f, -5.0f, 3.5f));

    Matrix4<float> answer;
    answer(0, 0) = 15.0f;
    answer(1, 1) = -5.0f;
    answer(2, 2) = 3.5f;

    CU_ASSERT(mat == answer);
}

void test_matrix4_rotate(void)
{
    float angle = degreesToRadians(90.0f);
    float s = sin(angle);
    float c = cos(angle);

    Matrix4<float> mat = Matrix4<float>::rotate(Vector3<float>(0, 0, 1), angle);

    Matrix4<float> answer;

    answer(0, 0) = c;
    answer(0, 1) = -s;
    answer(1, 0) = s;
    answer(1, 1) = c;

    CU_ASSERT(mat == answer);

    mat = Matrix4<float>::rotate(Vector3<float>(0, 1, 0), angle);

    answer = Matrix4<float>();

    answer(0, 0) = c;
    answer(0, 2) = s;
    answer(2, 0) = -s;
    answer(2, 2) = c;

    CU_ASSERT(mat == answer);

    mat = Matrix4<float>::rotate(Vector3<float>(1, 0, 0), angle);

    answer = Matrix4<float>();

    answer(1, 1) = c;
    answer(1, 2) = -s;
    answer(2, 1) = s;
    answer(2, 2) = c;

    CU_ASSERT(mat == answer);
}

void test_matrix4_translate(void)
{
    Matrix4<float> mat =
        Matrix4<float>::translate(Vector3<float>(15.0f, -10.0f, 3.5f));

    Matrix4<float> answer;

    answer(0, 3) = 15.0f;
    answer(1, 3) = -10.0f;
    answer(2, 3) = 3.5f;

    CU_ASSERT(mat == answer);
}

void test_matrix4_determinant(void)
{
    Matrix4<float> mat;
    mat(0, 0) = 1.0f;
    mat(0, 1) = 2.0f;
    mat(0, 2) = 3.0f;
    mat(0, 3) = 5.0f;
    mat(1, 0) = 0.0f;
    mat(1, 1) = -4.0f;
    mat(1, 2) = 1.0f;
    mat(2, 0) = 0.0f;
    mat(2, 1) = 3.0f;
    mat(2, 2) = -1.0f;
    mat(2, 3) = -2.0f;
    mat(3, 0) = 5.0f;
    mat(3, 2) = 8.0f;
    mat(3, 3) = 0.0f;

    CU_ASSERT(mat.determinant() == 51);
}

void test_matrix4_inverse(void)
{
    Matrix4<float> mat;

    mat(0, 0) = 2.0f;
    mat(0, 2) = 2.0f;
    mat(1, 1) = 2.0f;
    mat(1, 3) = 5.0f;
    mat(2, 2) = 2.0f;
    mat(3, 1) = 5.0f;
    mat(3, 3) = 0.0f;

    Matrix4<float> inv;
    inv(0, 0) = 0.5f;
    inv(0, 2) = -0.5f;
    inv(1, 1) = 0.0f;
    inv(1, 3) = 0.2f;
    inv(2, 2) = 0.5f;
    inv(3, 1) = 0.2f;
    inv(3, 3) = -0.08;

    CU_ASSERT(mat.inverse() == inv);
}
