//
// Created by Ahmad Ilaiwi on 7/28/15.
//

#include "SAT/solving_07_01.h"
#include "SAT/solving_07_02.h"
#include "SAT/solving_09_01.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {


    Formula f;
    importDimacs(argv[1], &f);
    Interpretation I;
    createAndInitializeInterpretation(&I, f.nbVariables);


    char fileName[200] = {"models"};
    int k = 6;
    for (int i = 0; argv[1][i] != 0; ++i) {
        fileName[k] = argv[1][i];
        k++;
    }
    fileName[k]='.';
    k++;
    fileName[k]='t';
    k++;
    fileName[k]='x';
    k++;
    fileName[k]='t';
    k++;
    fileName[k]=0;



    //printf("\n %d \n", f.nbVariables);
    //printf("\n %d \n", f.nbClauses);

    FILE *file;
    file = fopen(fileName, "wa");


    int nbRuns = 100;
    int nbFlips = 1000;

    for (int i = 0; i < nbRuns; ++i) {
        generateRandomComplete(I);
        for (int j = 0; j < nbFlips; ++j) {
            int randV = rand() % (f.nbVariables - 1) + 1;
            //printf("\n%d\n",randV);
            flipValue(I, randV);
            if (isSatisfiedFormula(f, I)) {
                printf("\nSatisfied\n");
                break;
            }
        }
        if (isSatisfiedFormula(f, I)) {
            printf("\nSatisfied\n");
            for (int j = 0; j < I.size; ++j) {
                fprintf(file, "%d ", I.datas[i]);
            }
            fprintf(file, "\n", I.datas[i]);
        }
    }


}
