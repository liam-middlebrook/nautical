#ifndef _TEST_MAT3_H_
#define _TEST_MAT3_H_

#include "test.h"
#include "math/matrix3.h"

void test_matrix3_multiply(void);
void test_matrix3_vector(void);
void test_matrix3_transpose(void);

static TestDef tests_matrix3[] = {
    {"Test Matrix3 Multiply", test_matrix3_multiply},
    {"Test Matrix3 Vector", test_matrix3_vector},
    {"Test Matrix3 Transpose", test_matrix3_transpose},
};

static size_t tests_matrix3_count = 3;

#endif
