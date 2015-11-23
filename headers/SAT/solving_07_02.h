#ifndef SOLVING_07_02_H
#define SOLVING_07_02_H
#include<structures/vecInt.h>
#include<SAT/solving_07_01.h>
#include <stdio.h>
#include <stdlib.h>
#define DEFAULTSIZE 20
// Typedef usefull for readbility
typedef vecInt Clause;

//new structure were the clauses are represented as a linked list which 
//contain a pointer to a cluase of type vecInt and a pointer for the next clause
typedef struct t_link
{
	int clauseNumber;
	struct t_link * next;
	Clause * clause;
} clauseLink ; 

//this occurences data structure is the same as clauseLink that will represent in our solver as an array of occurences that points
//to a link list contains a pointer to the clauses that containes the letiral represented by its index which can represent a positive
//or negative letiral corresponding to its index.
typedef clauseLink Occurences;

//this data structure is to represent the formulas witht he number of clauses, number of variables, link list of clauses and array of occurances
typedef struct {
	vecInt countUniq;
	vecInt countUnSat;
    int nbClauses;
    int nbVariables;
    clauseLink* clauseHead;
    Occurences** literalOccurrences;
} Formula;





/*****************************************************
 * Create the memory space for a formula f
 * @param f the formula
 * @param nbClauses
 * @param nbVariables
 */
void createFormula(Formula *f,int nbClauses,int nbVariables);

/*****************************************************
 * Free the dynamic memory allocation

 * 
 */
void freeFormula(Formula *f);



/*****************************************************
 * Create space for clause 
 * The default space allocated will be DEFAULTSIZE
 * @param f the formula
 * @param clauseNumber (the position)

 */
clauseLink* createClause(Formula *f, int clauseNumber);

/*****************************************************
 * insert a literal l in a given clause
 * @param f the formula
 * @param clauseNumber (the position)
 * @param Literal l
 */
void addLiteralInClause(Formula *f,int clauseNumber, Literal l);


// int search(node* header, int val);

/*****************************************************
 * insert a clause to link list of clauses of the fourmola
 * @param f the formula
 * @param the clause to add
 */
void addNodeToFront(Formula *f, clauseLink * toAdd);

/*****************************************************
 * free a link list of clauses
 * @param f the formula
 */
void freeList(Formula f);


/*****************************************************
 * find the clause from the link list
 * @param f the formula
 * @param clauseNumber the formula
 * @return pointer to clause
 */
clauseLink* findClause(Formula f, int clauseNumber);


void printFormula(Formula f);

void importDimacs(char *name,Formula *f);

void exportDimacs(char *name,Formula *f);



clauseLink* createClauseOcc(int clauseNumber) ;
void addNodeToFrontOcc(clauseLink** head, clauseLink * toAdd);
#endif
