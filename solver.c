#include "SAT/solving_07_01.h"
#include "SAT/solving_07_02.h"
#include "SAT/solving_09_01.h"
#include "SAT/solving_08_01.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main(int argc, char  *argv[])
{
	Formula f;
    importDimacs(argv[1], &f);
    Interpretation I;
    createAndInitializeInterpretation(&I, f.nbVariables);
    generateRandomComplete(I);
    if(solveSat(f,I)) {
        printf("SAT");
        exit(10);
    }
	return 0;
}
