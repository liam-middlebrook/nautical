#include <stdio.h>
#include <CUnit/Basic.h>

#include "vector2.h"
#include "vector3.h"

int main(int argc, char** argv)
{

    if(CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    for(size_t i = 0; i < suite_count; ++i)
    {
        CU_pSuite suite = CU_add_suite(suites[i].name, NULL, NULL);
        if(suite == NULL)
        {
            CU_cleanup_registry();
            return CU_get_error();
        }

        for(size_t j = 0; j < suites[i].count; ++j)
        {
            if(CU_add_test(suite, suites[i].tests[j].name, suites[i].tests[j].func) == NULL)
            {
                CU_cleanup_registry();
                return CU_get_error();
            }
        }
    }
/*
    vector2_suite = CU_add_suite("Vector2", NULL, NULL);
    if(vector2_suite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    for(size_t i = 0; i < tests_vector2_count; ++i)
    {
        if(CU_add_test(vector2_suite, tests_vector2[i].name, tests_vector2[i].func) == NULL)
        {
            CU_cleanup_registry();
            return CU_get_error();
        }
    }

    vector3_suite = CU_add_suite("Vector3", NULL, NULL);
    if(vector3_suite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    for(size_t i = 0; i < tests_vector3_count; ++i)
    {
        if(CU_add_test(vector3_suite, tests_vector3[i].name, tests_vector3[i].func) == NULL)
        {
            CU_cleanup_registry();
            return CU_get_error();
        }
    }
*/
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    int errCode = CU_get_number_of_tests_failed();
    CU_cleanup_registry();
    return errCode;
}
