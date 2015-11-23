#ifndef SOLVING_09_01_H
#define SOLVING_09_01_H
#include<structures/vecInt.h>
#include <SAT/solving_07_01.h>
#include <SAT/solving_07_02.h>



/***********************************************************/

// ----- Exercise 1 : 

/***********************************************************/


/**
 * Return all indexes clauses of the literal l in the formula f
 * @param f : the formula
 * @param l : the literal
 * @return a pointer on all occurences of the literal l in the formula f
 *
 */
clauseLink* getOccurrences(Formula f, Literal l);





/***********************************************************/

// ----- BE CAREFUL : EXERCISE 2, do not touch before!

/***********************************************************/



// CHANGE TO 1 WHEN STARTING EXERCISE 2
// ONLY USED FOR TESTING 
#define FORTESTS 1


/**
 * Used to retrieve occurences of v and \not v
 * all occurences for x are put in indexes 2*(v-1)
 * all occurences for \not x are put in indexes 2*(v-1) + 1
 */




int positiveVariableIdx(Variable v);
int negativeVariableIdx(Variable v);



/**
 * Used to retrieve occurences of l and \not l
 * If l is positive produces same results as before
 * If l is negative provides the opposite
 */

int literalIdx(Literal l);
int oppositeLiteralIdx(Literal l);
//get the letiral of an index
int idxLiteral(int index);


#endif
