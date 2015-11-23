#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include<SAT/solving_07_01.h>
#include<SAT/solving_07_02.h>


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




void testCreateFormula(void) {
  Formula f;
  createFormula(&f,100,10);
  freeFormula(&f);
}

void testOneClause(void) {
  Formula f;
  createFormula(&f,100,10);

  for(int i = 1;i<=10;i++) 
    addLiteralInClause(f,0,i);

  display(f.clauses[0]);
  
  CU_ASSERT(f.clauses[0].size==10);

  for(int i = 1;i<=10;i++) {
    CU_ASSERT(f.clauses[0].datas[i-1] == i);
  }

  freeFormula(&f);
}

void testLongClause(void) {
  Formula f;
  createFormula(&f,100,100);

  for(int i = 1;i<=40;i++) 
    addLiteralInClause(f,0,-i);

  display(f.clauses[0]);

  CU_ASSERT(f.clauses[0].size==40);

  for(int i = 1;i<=40;i++) {
    CU_ASSERT(f.clauses[0].datas[i-1] == -i);
  }

  freeFormula(&f);
}



/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
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
   if ((NULL == CU_add_test(pSuite, "test create Empty formula", testCreateFormula)) ||
       (NULL == CU_add_test(pSuite, "test create a clause", testOneClause)) ||
       (NULL == CU_add_test(pSuite, "test create a long clause", testLongClause)) 
       ) {
     CU_cleanup_registry();
     return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
      CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
