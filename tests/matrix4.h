#ifndef _TEST_MAT4_H_
#define _TEST_MAT4_H_

#include "test.h"
#include "math/matrix4.h"

void test_matrix4_add(void);
void test_matrix4_subtract(void);
void test_matrix4_multiply(void);
void test_matrix4_vector(void);
void test_matrix4_transpose(void);
void test_matrix4_scale(void);
void test_matrix4_rotate(void);
void test_matrix4_translate(void);
void test_matrix4_determinant(void);
void test_matrix4_inverse(void);

static const TestDef tests_matrix4[] = {
    {"Test Matrix4 Add", test_matrix4_add},
    {"Test Matrix4 Subtract", test_matrix4_subtract},
    {"Test Matrix4 Multiply", test_matrix4_multiply},
    {"Test Matrix4 Vector", test_matrix4_vector},
    {"Test Matrix4 Transpose", test_matrix4_transpose},
    {"Test Matrix4 Scale", test_matrix4_scale},
    {"Test Matrix4 Rotate", test_matrix4_rotate},
    {"Test Matrix4 Translate", test_matrix4_translate},
    {"Test Matrix4 Determinant", test_matrix4_determinant},
    {"Test Matrix4 Inverse", test_matrix4_inverse},
    {nullptr, nullptr},
};

#endif
