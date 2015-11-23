#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include<SAT/solving_07_01.h>
#include<SAT/solving_07_02.h>
#include<SAT/solving_08_01.h>
#include<SAT/solving_09_01.h>


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

void testIndexes(void) {
  if(FORTESTS) {
    CU_ASSERT(positiveVariableIdx(1) == 0);
    CU_ASSERT(negativeVariableIdx(1) == 1);
    CU_ASSERT(positiveVariableIdx(2) == 2);
    CU_ASSERT(negativeVariableIdx(2) == 3);
    CU_ASSERT(positiveVariableIdx(3) == 4);
    CU_ASSERT(negativeVariableIdx(3) == 5);
    
    CU_ASSERT(positiveVariableIdx(10) == 18);
    CU_ASSERT(negativeVariableIdx(10) == 19);
    
    
    CU_ASSERT(literalIdx(1) == 0);
    CU_ASSERT(oppositeLiteralIdx(1) == 1);
    CU_ASSERT(literalIdx(-1) == 1);
    CU_ASSERT(oppositeLiteralIdx(-1) == 0);
    
    CU_ASSERT(literalIdx(2) == 2);
    CU_ASSERT(oppositeLiteralIdx(2) == 3);
    CU_ASSERT(literalIdx(-2) == 3);
    CU_ASSERT(oppositeLiteralIdx(-2) == 2);
  }
}



void testOccurrences(void) {
  Formula f;
  Interpretation I;
  createAndInitializeInterpretation(&I,10);
  createFormula(&f,3,10);


  // 1 2 0 
  addLiteralInClause(f,0,1);
  addLiteralInClause(f,0,2);
  // 1 -3 -4 0
  addLiteralInClause(f,1,1);
  addLiteralInClause(f,1,-3);
  addLiteralInClause(f,1,-4);
  // 4 0
  addLiteralInClause(f,2,4);
  
  vecInt* occp4 = getOccurrences(f,4);
  vecInt* occm4 = getOccurrences(f,-4);
  

  CU_ASSERT(occp4->size==1);
  CU_ASSERT(occp4->datas[0] == 2);
  CU_ASSERT(occm4->size==1);
  CU_ASSERT(occm4->datas[0]==1);

  vecInt* occp1 = getOccurrences(f,1);
  vecInt* occm1 = getOccurrences(f,-1);
  CU_ASSERT(occp1->size==2);
  CU_ASSERT(occp1->datas[0]==0);
  CU_ASSERT(occp1->datas[1]==1);

  CU_ASSERT(occm1->size==0);


  vecInt* occp2 = getOccurrences(f,2);
  vecInt* occm2 = getOccurrences(f,-2);
  CU_ASSERT(occp2->size==1);
  CU_ASSERT(occp2->datas[0]==0);

  CU_ASSERT(occm2->size==0);

  vecInt* occp3 = getOccurrences(f,3);
  vecInt* occm3 = getOccurrences(f,-3);
  CU_ASSERT(occp3->size==0);
  CU_ASSERT(occm3->size==1);
  CU_ASSERT(occm3->datas[0]==1);





  freeFormula(&f);
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
   if ((NULL == CU_add_test(pSuite, "test indexes for occurences", testIndexes)) ||
       (NULL == CU_add_test(pSuite, "test Formula", testOccurrences))
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
