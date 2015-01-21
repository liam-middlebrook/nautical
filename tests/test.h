#ifndef TEST_FRAMEWORK_H_
#define TEST_FRAMEWORK_H_

#include <CUnit/Basic.h>

typedef struct {
    const char* name;
    CU_TestFunc func;
} TestDef;

typedef struct {
    const char* name;
    TestDef* tests;
    size_t count;
} SuiteDef;

// Begin Test Suite Declarations

#include "vector2.h"
#include "vector3.h"

static SuiteDef suites[] = {
    {"Vector2", tests_vector2, 7},
    {"Vector3", tests_vector3, 8},
};

static size_t suite_count = 2;
#endif
