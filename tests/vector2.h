#ifndef _TEST_VEC2_H_
#define _TEST_VEC2_H_

#include <CUnit/Basic.h>
#include "math/vector2.h"

typedef struct {
    const char* name;
    CU_TestFunc func;
} TestDef;

void test_vector2_add(void);
void test_vector2_subtract(void);
void test_vector2_multiply(void);
void test_vector2_divide(void);
void test_vector2_magnitude(void);
void test_vector2_dot(void);

static TestDef tests_vector2[] = {
    {"Test Vector2 Add", test_vector2_add},
    {"Test Vector2 Subtract", test_vector2_subtract},
    {"Test Vector2 Multiply", test_vector2_multiply},
    {"Test Vector2 Divide", test_vector2_divide},
    {"Test Vector2 Mangitude", test_vector2_magnitude},
    {"Test Vector2 Dot Product", test_vector2_dot},
};

static size_t tests_vector2_count = 6;

#endif
