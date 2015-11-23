#include<structures/vecInt.h>
#include<SAT/solving_07_01.h>
#include <SAT/solving_07_02.h>
#include<SAT/solving_08_01.h>
#include<SAT/solving_09_01.h>

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>





/**
 * Return all indexes clauses of the literal l in the formula f
 * @param f : the formula
 * @param l : the literal
 * @return a pointer on all occurences of the literal l in the formula f
 */

clauseLink* getOccurrences(Formula f, Literal l) {


    return (f.literalOccurrences[literalIdx(l)]);

}



/***********************************************************/

// ----- BE CAREFUL : EXERCISE 2, do not touch before!

/***********************************************************/





/**
 * Used to retrieve occurences of v and \not v
 */
// I suppose occurences[v] is at position 2*(v-1)
// occurences[-v] is at position 2*(v-1)+1

int positiveVariableIdx(Variable v) {
    //printf("%d",2*(v-1));
    return 2*(v-1);

}

int negativeVariableIdx(Variable v) {
    return 2*(v-1)+1;
}

/**
 * Used to retrieve occurences of l and \not l
 * If l is positive produces same results as before
 * If l is negative provides the opposite
 */

int literalIdx(Literal l) {
    return (l>0 ? positiveVariableIdx(l) : negativeVariableIdx(-l));
}

int oppositeLiteralIdx(Literal l) {
    return (l<0 ? positiveVariableIdx(-l) : negativeVariableIdx(l));
}

//get the letiral of an index
int idxLiteral(int index){
	if (index%2)
	{
		return -1*(((index-1)/2)+1);
	}
	else{
		return (index/2)+1;
	}
}







