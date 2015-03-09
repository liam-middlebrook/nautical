#ifndef TEST_FRAMEWORK_H_
#define TEST_FRAMEWORK_H_

#include <CUnit/Basic.h>

typedef struct
{
    const char* name;
    CU_TestFunc func;
} TestDef;

typedef struct
{
    const char* name;
    const TestDef* tests;
} SuiteDef;

#endif
