#include "SAT/solving_07_01.h"
#include "SAT/solving_07_02.h"
#include "SAT/solving_08_01.h"
#include "SAT/solving_09_01.h"
#include <stdio.h>
#include <stdlib.h>



int main(){
    Formula f;
    Interpretation I;
    int clauses=rand()%20;
    int var=rand()%30;
    createFormula(&f, clauses, var);
    generateFullRandomFormula(&f,clauses,var);
    createAndInitializeInterpretation(&I, f.nbVariables);

    for (int i = 0; i < f.nbVariables; ++i) {
        assignVariable(I,i,rand()%2);
    }
    int randomValue= rand()%(f.nbClauses);
    printf("\nstatus of a random clause %d: %d",randomValue,statusClause(f.clauses[randomValue],I));


    randomValue= rand()%(f.nbClauses);

    printf("\nsatifcation of a random clause %d : %d",randomValue,isSatisfiedClause(f.clauses[randomValue],I));

    randomValue= rand()%(f.nbClauses);

    printf("\nfalsefcation of a random clause %d : %d",randomValue,isFalsifiedClause(f.clauses[randomValue],I));

    randomValue= rand()%(f.nbClauses);

    printf("\nUndetermination of a random clause %d : %d",randomValue,isUndefClause(f.clauses[randomValue],I));


    randomValue= rand()%(f.nbClauses);

    printf("\nUnit of a random clause %d : %d",randomValue,isUnit(f.clauses[randomValue],I));



    printf("\nThe status of the fourmla is %d",statusFormula(f,I));

    printf("\nSatification of the fourmla is %d",isSatisfiedFormula(f,I));

    printf("\nFalefication of the fourmla is %d",isFalsifiedFormula(f,I));

    printf("\nUndetermination of the fourmla is %d",isUndefFormula(f,I));

    displayFormula(f,I);


}