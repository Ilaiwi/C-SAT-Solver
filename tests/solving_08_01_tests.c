#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include<SAT/solving_07_01.h>
#include<SAT/solving_07_02.h>
#include<SAT/solving_08_01.h>


/* The suite initialization function.
 * Returns zero on success, non-zero otherwise.
 */
int init_suite1(void) {

    return 0;
}

/* The suite cleanup function.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite1(void) {
    return 0;
}




void testFormula(void) {
    Formula f;
    Interpretation I;
    createAndInitializeInterpretation(&I, 10);
    createFormula(&f, 3, 10);


    // 1 2 0
    addLiteralInClause(&f, 0, 1);
    addLiteralInClause(&f, 0, 2);
    // 1 -3 -4 0
    addLiteralInClause(&f, 1, 1);
    addLiteralInClause(&f, 1, -3);
    addLiteralInClause(&f, 1, -4);
    // 4 0
    addLiteralInClause(&f, 2, 4);

    CU_ASSERT(isUndefFormula(f, I));

    assignLiteral(I, 4);
    CU_ASSERT(isUndefFormula(f, I));
    flipValue(I, 4);
    CU_ASSERT(isFalsifiedFormula(f, I));

    flipValue(I, 4);
    assignLiteral(I, 1);
    CU_ASSERT(isSatisfiedFormula(f, I));

    //displayFormula(f, I);

    freeFormula(&f);
    freeInterpretation(&I);

}

/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main() {
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* add a suite to the registry */
    pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
    if ((NULL == CU_add_test(pSuite, "test Formula", testFormula))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
