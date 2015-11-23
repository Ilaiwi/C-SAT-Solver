#ifndef SOLVING_08_01_H
#define SOLVING_08_01_H

#include<structures/vecInt.h>
#include<SAT/solving_07_01.h>
#include<SAT/solving_07_02.h>
#include<SAT/solving_08_01.h>
#include<SAT/solving_09_01.h>
#include <assert.h>

 

/**
 * give the status of a clause under a given interpretation
 * @param c the clause
 * @parm I the interpretation
 * @return TRUE if it is satisfied, FALSE if it is falsified, UNDEF if one can not answer this question
 */
int statusClause(Clause c,Interpretation I);


/**
new
 * gives the status of a clause under a given interpretation if it is staticfied by only one literal or not
 * @param c the clause
 * @parm I the interpretation
 * @parm l the litiral
 * @return TRUE if it is satisfied uniquely, FALSE if not uniquely satiscfied.
 */
int isUniquelySat(Clause c , Interpretation I , Literal l);


/**
new
 * gives the count of clauses that each literal solves uniequely and the clauses that are not satifiable by the literal
 * @param c the clause
 * @parm I the interpretation
 * @parm f the fourmla that contains the arrays of occus
 */
void countSatLiterals(Formula f ,Interpretation I);


/**
new
 * gives the sulotion of the sat problem if it finds it
 * @param f the formula
 * @parm I interpreatation
 * @return TRUE if it is satisfied , FALSE if not found
 */
int solveSat(Formula f, Interpretation I);


/**
new
 * gives the best index to flip by computing the litral with largest number of unsat clauses and lest number of uniq sat clauses if not found return 0
 * @param f the formula
 * @parm limit an integer to help find the literal with largest unsat clauses and lest uniq sat
 * @return TRUE if it is satisfied uniquely, FALSE if not uniquely satiscfied.
 */
int findBestFlipIndex(Formula f , int limit);

/**
 * These 3 functions are used to help the readability
 * Use statusClause with good parameters
 */

int isSatisfiedClause(Clause c,Interpretation I);
int isFalsifiedClause(Clause c,Interpretation I);
int isUndefClause(Clause c,Interpretation I);




/**
 * Say if a clause is unit (only one literal is UNDEF and all other ones are falsified
 * under a given interpretation
 * @return 1 if yes, 0 otherwise
 */
int isUnit(Clause c,Interpretation I);

/**
 * Display a clause under a given interpretation
 * You can print colors on terminal 
 * see http://www.daniweb.com/software-development/c/threads/266484/how-to-print-text-into-a-different-color-in-terminal
 * For example: 
 *  the literal is true in the clause : write in green
 *  the literal is false in the clause : write in red
 * the literal is undefined in the clause : write in blue
 * @param c the clause
 * @parm I the interpretation
 */ 
 void displayClause(Clause c,Interpretation I);



/**
 * @param f the formula
 * @param I an interpretation 
 * @return TRUE if it is satisfied, FALSE if it is falsified, UNDEF if one can not answer this question
 */
int statusFormula(Formula f,Interpretation I);

/**
 * These 3 functions are used to help the readability
 * Use statusFormula with good parameters
 */
int isSatisfiedFormula(Formula c,Interpretation I);
int isFalsifiedFormula(Formula c,Interpretation I);
int isUndefFormula(Formula c,Interpretation I);

/**
 * Display a Formula under a given interpretation : Display all clauses!
 * @param c the clause
 * @parm I the interpretation
 */
void displayFormula(Formula c , Interpretation I);


#endif
