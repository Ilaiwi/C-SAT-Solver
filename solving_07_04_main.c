#include "SAT/solving_07_01.h"
#include "SAT/solving_07_02.h"
#include "SAT/solving_09_01.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc , char * argv[] ) {

    Formula f;

    importDimacs(argv[1],&f);

    for (int i = 1; i <= f.nbVariables ; ++i) {
        vecInt *temp =getOccurrences(f,i);
        printf("\nl: %d     occurrences: %d", i, temp->size);
    }
}
