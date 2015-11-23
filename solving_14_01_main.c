#include "SAT/solving_07_01.h"
#include "SAT/solving_07_02.h"
#include "SAT/solving_09_01.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



void readInterpretation( Interpretation I , char* name){
    FILE *file;
    file = fopen(name, "r");
    if (file == NULL) {
        perror("There is a problem hereee");
        exit(EXIT_FAILURE);
    }

    char buffer[1000];

    extractWord(file, buffer);
    int literal;
    //str2int(buffer,&literal);
    //int literal;
    for (int i = 1; i < I.size ; ++i) {
        str2int(buffer,&literal);
        //printf("\n%d\n",literal);
        assert(literal!=0);
        assignLiteral(I,literal);
        extractWord(file, buffer);
    }

}



int main(int argc , char* argv[]){

    //printf("\n%s\n \n%s\n",argv[1],argv[2]);
    Formula f;
    importDimacs(argv[1], &f);
    Interpretation I;
    createAndInitializeInterpretation(&I, f.nbVariables);
    //printf("\n%s\n \n\n",argv[2]);
    readInterpretation(I,argv[2]);

 //   printf("\n\n\n");
//
//    for (int i = 1; i < I.size ; ++i) {
//        printf("%d",I.datas[i]);
//    }

    if(isSatisfiedFormula(f,I)) {
        printf("\n\nSaticfiable\n\n");
    }


}


