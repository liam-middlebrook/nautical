#include "matrix3.h"
#include <stdio.h>

using namespace nautical::math;

void print_vector3(Vector3<float> vector)
{
    printf("Vector: X: %f Y: %f Z: %f", vector.x, vector.y, vector.z);
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

void test_matrix3_multiply(void)
{
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
    CU_ASSERT((mat2 * mat1) == answer);

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

    print_vector3(vec);
    print_matrix(mat);
    print_vector3(mat * vec);
    CU_ASSERT((mat * vec) == answer);
}
