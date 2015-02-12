#ifndef _TEST_VEC3_H_
#define _TEST_VEC3_H_

#include "test.h"
#include "math/vector3.h"

void test_vector3_add(void);
void test_vector3_subtract(void);
void test_vector3_multiply(void);
void test_vector3_divide(void);
void test_vector3_magnitude(void);
void test_vector3_dot(void);
void test_vector3_cross(void);
void test_vector3_normalize(void);

static TestDef tests_vector3[] = {
    {"Test Vector3 Add", test_vector3_add},
    {"Test Vector3 Subtract", test_vector3_subtract},
    {"Test Vector3 Multiply", test_vector3_multiply},
    {"Test Vector3 Divide", test_vector3_divide},
    {"Test Vector3 Mangitude", test_vector3_magnitude},
    {"Test Vector3 Dot Product", test_vector3_dot},
    {"Test Vector3 Cross Product", test_vector3_cross},
    {"Test Vector3 Normalization", test_vector3_normalize},
};

static size_t tests_vector3_count = 8;

#endif
