#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include<SAT/solving_07_01.h>
//#include "SAT/solving_0_02.h"


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




void testVariables(void) {
  CU_ASSERT(getVariable(10)==10);
  CU_ASSERT(getVariable(25)==25);
  CU_ASSERT(getVariable(-15)==15);
  CU_ASSERT(getVariable(-14322)==14322);
}


void testAssignVariable(void) {
  Interpretation I;
  createAndInitializeInterpretation(&I,100); // 100 variables, for example

  for(int i = 1;i <= 100;i++) 
    CU_ASSERT(getValueVariable(I,i)==UNDEF);
    
  
  assignVariable(I,10,TRUE);
  CU_ASSERT(getValueVariable(I,10)==TRUE);

  assignVariable(I,10,UNDEF);
  CU_ASSERT(getValueVariable(I,10)==UNDEF);


  assignVariable(I,100,FALSE);
  CU_ASSERT(getValueVariable(I,100)==FALSE);

  assignVariable(I,1,TRUE);
  CU_ASSERT(getValueVariable(I,1)==TRUE);
  
  freeInterpretation(&I);
}


void testAssignLiteral(void) {
  Interpretation I;
  createAndInitializeInterpretation(&I,100); // 100 variables, for example
  assignLiteral(I,10);
  CU_ASSERT(getValueLiteral(I,10)==TRUE);
  CU_ASSERT(getValueLiteral(I,-10)==FALSE);

  assignVariable(I,10,UNDEF);
  CU_ASSERT(getValueLiteral(I,10)==UNDEF);
  CU_ASSERT(getValueLiteral(I,-10)==UNDEF);


  assignLiteral(I,-100);
  CU_ASSERT(getValueVariable(I,100)==FALSE);
  CU_ASSERT(getValueLiteral(I,100)==FALSE);
  CU_ASSERT(getValueLiteral(I,-100)==TRUE);


  assignLiteral(I,-1);
  CU_ASSERT(getValueVariable(I,1)==FALSE);
  CU_ASSERT(getValueLiteral(I,1)==FALSE);
  CU_ASSERT(getValueLiteral(I,-1)==TRUE);
  freeInterpretation(&I);

}

void testFlip(void) {
  Interpretation I;
  createAndInitializeInterpretation(&I,100); // 100 variables, for example
  assignLiteral(I,10);
  flipValue(I,10);
  CU_ASSERT(getValueLiteral(I,-10)==TRUE);

  assignLiteral(I,-25);
  flipValue(I,25);
  CU_ASSERT(getValueLiteral(I,25)==TRUE);
  
  assignVariable(I,33,UNDEF);
  flipValue(I,33);
  CU_ASSERT(getValueVariable(I,33)==UNDEF);
  freeInterpretation(&I);


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
   if ((NULL == CU_add_test(pSuite, "test getVariable", testVariables)) ||
       (NULL == CU_add_test(pSuite, "test assign variable", testAssignVariable)) ||
       (NULL == CU_add_test(pSuite, "test assign literal", testAssignLiteral)) ||
       (NULL == CU_add_test(pSuite, "test flip value", testFlip))
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
