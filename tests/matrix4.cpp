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
            m.m11, m.m12, m.m13, m.m14,
            m.m21, m.m22, m.m23, m.m24,
            m.m31, m.m32, m.m33, m.m34,
            m.m41, m.m42, m.m43, m.m44);
}

void test_matrix4_add(void)
{
    Matrix4<float> dummy;
    Matrix4<float> mat1;
    mat1.m11 = 15.0f;
    mat1.m23 = -70.0f;
    mat1.m31 = 14.6f;
    mat1.m33 = -3.5f;
    mat1.m44 = 1.0f;

    Matrix4<float> answer;
    answer.m11 = 16.0f;
    answer.m22 = 2.0f;
    answer.m23 = -70.0f;
    answer.m31 = 14.6f;
    answer.m33 = -2.5f;
    answer.m44 = 2.0f;

    CU_ASSERT((mat1 + Matrix4<float>::identity) == answer);

    dummy = mat1;
    dummy += Matrix4<float>::identity;

    CU_ASSERT(dummy == answer);
}

void test_matrix4_subtract(void)
{
    Matrix4<float> dummy;
    Matrix4<float> mat1;
    mat1.m11 = 15.0f;
    mat1.m23 = -70.0f;
    mat1.m31 = 14.6f;
    mat1.m33 = -3.5f;

    Matrix4<float> answer;
    answer.m11 = 14.0f;
    answer.m22 = 0.0f;
    answer.m23 = -70.0f;
    answer.m31 = 14.6f;
    answer.m33 = -4.5f;
    answer.m44 = 0.0f;

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
    mat2.m11 = 3;
    mat2.m22 = 5;
    mat2.m33 = 7;
    mat2.m44 = 9;

    Matrix4<float> answer;
    answer.m11 = 3;
    answer.m22 = 5;
    answer.m33 = 7;
    answer.m44 = 9;

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

    answer = Matrix4<float>();
    answer.m11 = 3;
    answer.m13 = 14;
    answer.m22 = 20;
    answer.m31 = 18;
    answer.m33 = 7;
    answer.m44 = 9;

    CU_ASSERT((mat1 * mat2) == answer);

    answer = Matrix4<float>();
    answer.m11 = 3;
    answer.m13 = 6;
    answer.m22 = 20;
    answer.m31 = 42;
    answer.m33 = 7;
    answer.m44 = 9;

    CU_ASSERT((mat2 * mat1) == answer);
}

void test_matrix4_vector(void)
{
    Vector4<float> vec(12.0f, 14.6f, -10.0f, 10.0f);

    Matrix4<float> mat;

    mat.m11 = 3.0f;
    mat.m22 = 0.5f;
    mat.m33 = -2.0f;

    Vector4<float> answer(36.0f, 7.3f, 20.0f, 10.0f);

    CU_ASSERT(Vector4<float>(mat * vec) == answer);
}

void test_matrix4_transpose(void)
{
    Matrix4<float> mat;
    mat.m12 = 5.0f;
    Matrix4<float> answer;
    answer.m21 = 5.0f;

    CU_ASSERT(mat.transpose() == answer);
}

void test_matrix4_scale(void)
{
    Matrix4<float> mat = Matrix4<float>::scale(Vector3<float>(15.0f, -5.0f, 3.5f));

    Matrix4<float> answer;
    answer.m11 = 15.0f;
    answer.m22 = -5.0f;
    answer.m33 = 3.5f;

    CU_ASSERT(mat == answer);
}

void test_matrix4_rotate(void)
{
    CU_ASSERT(0);
}

void test_matrix4_translate(void)
{
    Matrix4<float> mat = Matrix4<float>::translate(Vector3<float>(15.0f, -10.0f, 3.5f));

    Matrix4<float> answer;

    answer.m14 = 15.0f;
    answer.m24 = -10.0f;
    answer.m34 = 3.5f;

    CU_ASSERT(mat == answer);
}

void test_matrix4_determinant(void)
{
    Matrix4<float> mat;
    mat.m11 = 1.0f;
    mat.m12 = 2.0f;
    mat.m13 = 3.0f;
    mat.m14 = 5.0f;
    mat.m21 = 0.0f;
    mat.m22 = -4.0f;
    mat.m23 = 1.0f;
    mat.m31 = 0.0f;
    mat.m32 = 3.0f;
    mat.m33 = -1.0f;
    mat.m34 = -2.0f;
    mat.m41 = 5.0f;
    mat.m43 = 8.0f;
    mat.m44 = 0.0f;

    CU_ASSERT(mat.determinant() == 51);
}

void test_matrix4_inverse(void)
{
    Matrix4<float> mat;

    mat.m11 = 2.0f;
    mat.m13 = 2.0f;
    mat.m22 = 2.0f;
    mat.m24 = 5.0f;
    mat.m33 = 2.0f;
    mat.m42 = 5.0f;
    mat.m44 = 0.0f;

    Matrix4<float> inv;
    inv.m11 = 0.5f;
    inv.m13 = -0.5f;
    inv.m22 = 0.0f;
    inv.m24 = 0.2f;
    inv.m33 = 0.5f;
    inv.m42 = 0.2f;
    inv.m44 = -0.08;

    CU_ASSERT(mat.inverse() == inv);
}
