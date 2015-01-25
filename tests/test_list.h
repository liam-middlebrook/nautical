#ifndef TEST_LIST_H_
#define TEST_LIST_H_

// Begin Test Suite Declarations

#include "vector2.h"
#include "vector3.h"
#include "vector4.h"
#include "matrix3.h"

static SuiteDef suites[] = {
    {"Vector2", tests_vector2, tests_vector2_count},
    {"Vector3", tests_vector3, tests_vector3_count},
    {"Vector4", tests_vector4, tests_vector4_count},
    {"Matrix3", tests_matrix3, tests_matrix3_count},
};

static size_t suite_count = 4;

#endif
