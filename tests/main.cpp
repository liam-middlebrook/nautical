#include <stdio.h>
#include <CUnit/Basic.h>

#include "test_list.h"

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

    CU_basic_set_mode(CU_BRM_VERBOSE);
	if(argc > 1) {
		for(int i=1; i<argc; i++)
		{
			CU_pSuite suite = CU_get_suite(argv[i]);
			CU_basic_run_suite(suite);
		}
	} else {
	    CU_basic_run_tests();
	}

    int errCode = CU_get_number_of_tests_failed();
    CU_cleanup_registry();
    return errCode;
}
