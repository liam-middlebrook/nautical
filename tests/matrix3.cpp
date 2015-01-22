#include "matrix3.h"
#include <stdio.h>

using namespace nautical::math;

void print_matrix(Matrix3<float> m)
{
    printf("Matrix3:\n
            %f %f %f\n
            %f %f %f\n
            %f %f %f",
            m.m11, m.m12, m.m13,
            m.m21, m.m22, m.m23,
            m.m31, m.m32, m.m33);
}

void test_matrix3_multiply(void)
{
    Matrix3<float> mat1;

    print_matrix(mat1);

    Matrix3<float> mat2;
    mat2.m11 = 3;
    mat2.m22 = 5;
    mat2.m33 = 7;

    print_matrix(mat2);

    Matrix3<float> answer;
    answer.m11 = 3;
    answer.m22 = 5;
    answer.m33 = 7;

    print_matrix(answer);

    CU_ASSERT((mat1 * mat2) == answer);
    CU_ASSERT((mat2 * mat1) == answer);
}

void test_matrix3_vector(void)
{
    
}
