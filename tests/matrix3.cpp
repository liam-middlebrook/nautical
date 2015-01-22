#include "matrix3.h"
#include <stdio.h>

using namespace nautical::math;

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
}

void test_matrix3_vector(void)
{
    
}
