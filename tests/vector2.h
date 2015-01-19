#ifndef _TEST_VEC2_H_
#define _TEST_VEC2_H_

#include <CUnit/Basic.h>
#include "math/vector2.h"

typedef struct {
    const char* name;
    CU_TestFunc func;
} TestDef;

void test_vector2_add(void);

static TestDef tests_vector2[] = {
    {"Test Vector2 Add", test_vector2_add},
};

static size_t tests_vector2_count = 1;

#endif
