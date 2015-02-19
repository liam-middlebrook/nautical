#ifndef _TEST_VEC2_H_
#define _TEST_VEC2_H_

#include "test.h"
#include "math/vector2.h"

void test_vector2_add(void);
void test_vector2_subtract(void);
void test_vector2_multiply(void);
void test_vector2_divide(void);
void test_vector2_magnitude(void);
void test_vector2_dot(void);
void test_vector2_normalize(void);

static const TestDef tests_vector2[] = {
    {"Test Vector2 Add", test_vector2_add},
    {"Test Vector2 Subtract", test_vector2_subtract},
    {"Test Vector2 Multiply", test_vector2_multiply},
    {"Test Vector2 Divide", test_vector2_divide},
    {"Test Vector2 Mangitude", test_vector2_magnitude},
    {"Test Vector2 Dot Product", test_vector2_dot},
    {"Test Vector2 Normalization", test_vector2_normalize},
    {nullptr, nullptr},
};

#endif
