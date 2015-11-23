// #ifndef SOLVING_01_04_MOFIFY_H
// #define SOLVING_01_04_MOFIFY_H
// #include<SAT/solving_07_01.h>
// #include<SAT/solving_07_02.h>
// #include<stdlib.h>
// #include<stdio.h>


// /**
//  * Generate and print a random clause with nbLiterals literals
//  * @param f the formula
//  * @param clauseNumber : the clause to generate
//  * @param : the number of literals that contain the clause
//  */

// void generateClause(Formula f,int clauseNumber, int nbLiterals) {
//   for(int i = 0;i<nbLiterals;i++) {
//     int sign = rand()%2 ? 1 : -1;
//     Literal l = sign*(rand()%f.nbVariables+1);
//     addLast(&(f.clauses[i]),l);
//   }
// }

// /**
//  * Generate and print nbClauses
//  * @param f the formula
//  * @param 
//  */

// void generateAllClauses(Formula f) {
//   for(int i = 0;i<f.nbClauses;i++) 
//     generateClause(f,i,rand()%1000+1);
// }

// /**
//  * Generate a full random formula
//  * @param number of variables
//  * @param number of clauses
//  * @return the formula
//  */

// void generateFullRandomFormula(Formula *f,int nbVars,int nbClauses) {
//   createFormula(f,nbVars,nbClauses);
//   generateAllClauses(*f);
// }
// /**
//  * Generate a 3-SAT random formula
//  * Each clause have to contain exactly 3 literals
//  * @param number of variables
//  * @param number of clauses
//  * Return the formula
//  */

// void generate3RandomFormula(Formula *f,int nbVars,int nbClauses) {
  
// }


// /**
//  * Print in a DIMACS format a formula
//  * @param f the formula to print
//  */

// void printDimacs(Formula f);
// #endif

