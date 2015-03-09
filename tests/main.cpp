#include <map>
#include <string>
#include <CUnit/CUnit.h>
using std::map;
using std::string;

#include "test_list.h"

int main(int argc, char** argv)
{
    map<string, CU_pSuite> suitemap;

    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    for (const SuiteDef* sp{suites}; sp->name != nullptr; ++sp)
    {
        CU_pSuite suite = CU_add_suite(sp->name, nullptr, nullptr);
        if (suite == nullptr)
        {
            CU_cleanup_registry();
            return CU_get_error();
        }
        suitemap[sp->name] = suite;

        for (const TestDef* tst{sp->tests}; tst->name != nullptr; ++tst)
        {
            if (CU_add_test(suite, tst->name, tst->func) == nullptr)
            {
                CU_cleanup_registry();
                return CU_get_error();
            }
        }
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            CU_basic_run_suite(suitemap[argv[i]]);
        }
    }
    else
    {
        CU_basic_run_tests();
    }

    int errCode = CU_get_number_of_tests_failed();
    CU_cleanup_registry();
    return errCode;
}
