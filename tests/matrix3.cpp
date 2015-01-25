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
            m.m11, m.m12, m.m13,
            m.m21, m.m22, m.m23,
            m.m31, m.m32, m.m33);
}

void test_matrix3_add(void)
{
    Matrix3<float> dummy;
    Matrix3<float> mat1;
    mat1.m11 = 15.0f;
    mat1.m23 = -70.0f;
    mat1.m31 = 14.6f;
    mat1.m33 = -3.5f;

    Matrix3<float> answer;
    answer.m11 = 16.0f;
    answer.m22 = 2.0f;
    answer.m23 = -70.0f;
    answer.m31 = 14.6f;
    answer.m33 = -2.5f;

    CU_ASSERT((mat1 + Matrix3<float>::identity) == answer);

    dummy = mat1;
    dummy += Matrix3<float>::identity;

    CU_ASSERT(dummy == answer);
}

void test_matrix3_subtract(void)
{
    Matrix3<float> dummy;
    Matrix3<float> mat1;
    mat1.m11 = 15.0f;
    mat1.m23 = -70.0f;
    mat1.m31 = 14.6f;
    mat1.m33 = -3.5f;

    Matrix3<float> answer;
    answer.m11 = 14.0f;
    answer.m22 = 0.0f;
    answer.m23 = -70.0f;
    answer.m31 = 14.6f;
    answer.m33 = -4.5f;

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
    mat2.m11 = 3;
    mat2.m22 = 5;
    mat2.m33 = 7;

    Matrix3<float> answer;
    answer.m11 = 3;
    answer.m22 = 5;
    answer.m33 = 7;

    CU_ASSERT((mat1 * mat2) == answer);

    dummy = mat1;
    dummy *= mat2;

    CU_ASSERT(dummy == answer);
    CU_ASSERT((mat2 * mat1) == answer);

    dummy = mat2;
    dummy *= mat1;

    CU_ASSERT(dummy == answer);

    mat1.m13 = 2;
    mat1.m22 = 4;
    mat1.m31 = 6;

    answer = Matrix3<float>();
    answer.m11 = 3;
    answer.m13 = 14;
    answer.m22 = 20;
    answer.m31 = 18;
    answer.m33 = 7;

    CU_ASSERT((mat1 * mat2) == answer);

    answer = Matrix3<float>();
    answer.m11 = 3;
    answer.m13 = 6;
    answer.m22 = 20;
    answer.m31 = 42;
    answer.m33 = 7;

    CU_ASSERT((mat2 * mat1) == answer);
}

void test_matrix3_vector(void)
{
    Vector3<float> vec(12.0f, 14.6f, -10.0f);

    Matrix3<float> mat;

    mat.m11 = 3.0f;
    mat.m22 = 0.5f;
    mat.m33 = -2.0f;

    Vector3<float> answer(36.0f, 7.3f, 20.0f);

    CU_ASSERT(Vector3<float>(mat * vec) == answer);
}

void test_matrix3_transpose(void)
{
    Matrix3<float> mat;
    mat.m12 = 5.0f;
    Matrix3<float> answer;
    answer.m21 = 5.0f;

    CU_ASSERT(mat.transpose() == answer);
}

void test_matrix3_scale(void)
{
    Matrix3<float> mat = Matrix3<float>::scale(Vector2<float>(15.0f, -5.0f));

    Matrix3<float> answer;
    answer.m11 = 15.0f;
    answer.m22 = -5.0f;

    CU_ASSERT(mat == answer);
}

void test_matrix3_rotate(void)
{
    Matrix3<float> mat = Matrix3<float>::rotate(degreesToRadians(90.0f));

    Matrix3<float> answer;
    answer.m11 = -0.0f;
    answer.m22 = -0.0f;
    answer.m12 = -1.0f;
    answer.m21 = 1.0f;

    CU_ASSERT(mat == answer);

    answer = Matrix3<float>::rotate(degreesToRadians(-270.0f));

    CU_ASSERT(mat == answer);
}

void test_matrix3_translate(void)
{
    Matrix3<float> mat = Matrix3<float>::translate(Vector2<float>(15.0f, -10.0f));

    Matrix3<float> answer;

    answer.m13 = 15.0f;
    answer.m23 = -10.0f;

    CU_ASSERT(mat == answer);
}

void test_matrix3_determinant(void)
{
    Matrix3<float> mat;
    mat.m11 = 1.0f;
    mat.m12 = 2.0f;
    mat.m13 = 3.0f;
    mat.m21 = 0.0f;
    mat.m22 = -4.0f;
    mat.m23 = 1.0f;
    mat.m31 = 0.0f;
    mat.m32 = 3.0f;
    mat.m33 = -1.0f;

    CU_ASSERT(mat.determinant() == 1.0f);
}

void test_matrix3_inverse(void)
{
    Matrix3<float> mat;

    mat.m11 = 2.0f;
    mat.m13 = 2.0f;
    mat.m23 = 2.0f;
    mat.m33 = 2.0f;

    Matrix3<float> inv;
    inv.m11 = 0.5f;
    inv.m13 = -0.5f;
    inv.m23 = -1.0f;
    inv.m33 = 0.5f;

    CU_ASSERT(mat.inverse() == inv);
}
