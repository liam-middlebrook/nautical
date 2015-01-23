#ifndef TEST_LIST_H_
#define TEST_LIST_H_

// Begin Test Suite Declarations

#include "vector2.h"
#include "vector3.h"
#include "matrix3.h"

static SuiteDef suites[] = {
    {"Vector2", tests_vector2, tests_vector2_count},
    {"Vector3", tests_vector3, tests_vector3_count},
    {"Matrix3", tests_matrix3, tests_matrix3_count},
};

static size_t suite_count = 3;

#endif
