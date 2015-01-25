#ifndef _TEST_MAT3_H_
#define _TEST_MAT3_H_

#include "test.h"
#include "math/matrix3.h"

void test_matrix3_multiply(void);
void test_matrix3_vector(void);
void test_matrix3_transpose(void);
void test_matrix3_scale(void);
void test_matrix3_rotate(void);
void test_matrix3_translate(void);

static TestDef tests_matrix3[] = {
    {"Test Matrix3 Multiply", test_matrix3_multiply},
    {"Test Matrix3 Vector", test_matrix3_vector},
    {"Test Matrix3 Transpose", test_matrix3_transpose},
    {"Test Matrix3 Scale", test_matrix3_scale},
    {"Test Matrix3 Rotate", test_matrix3_rotate},
    {"Test Matrix3 Translate", test_matrix3_translate},
};

static size_t tests_matrix3_count = 6;

#endif
