#ifndef _TEST_VEC4_H_
#define _TEST_VEC4_H_

#include "test.h"
#include "math/vector4.h"

void test_vector4_add(void);
void test_vector4_subtract(void);
void test_vector4_multiply(void);
void test_vector4_divide(void);
void test_vector4_magnitude(void);
void test_vector4_dot(void);
void test_vector4_normalize(void);

static const TestDef tests_vector4[] = {
    {"Test Vector3 Add", test_vector4_add},
    {"Test Vector3 Subtract", test_vector4_subtract},
    {"Test Vector3 Multiply", test_vector4_multiply},
    {"Test Vector3 Divide", test_vector4_divide},
    {"Test Vector3 Mangitude", test_vector4_magnitude},
    {"Test Vector3 Dot Product", test_vector4_dot},
    {"Test Vector3 Normalization", test_vector4_normalize},
    {nullptr, nullptr},
};

#endif
