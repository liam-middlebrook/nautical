#ifndef TEST_LIST_H_
#define TEST_LIST_H_

// Begin Test Suite Declarations

#include "vector2.h"
#include "vector3.h"

static SuiteDef suites[] = {
    {"Vector2", tests_vector2, 7},
    {"Vector3", tests_vector3, 8},
};

static size_t suite_count = 2;

#endif
