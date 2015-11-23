#include<structures/vecInt.h>
#include<SAT/solving_07_01.h>
#include<SAT/solving_07_02.h>
//#include<SAT/solving_08_01.h>
#include<SAT/solving_09_01.h>
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>


/*****************************************************
 * Create the memory space for a formula f
 * 
 */
void createFormula(Formula *f, int nbClauses, int nbVariables) {
    f->nbClauses = nbClauses;
    f->nbVariables = nbVariables;
    f->literalOccurrences = (Occurences **) malloc(sizeof(Occurences*) * 2 * f->nbVariables);
    for (int i = 0; i < 2*f->nbVariables; ++i)
    {
        f->literalOccurrences[i]=NULL;
    }
    f->clauseHead=NULL;
    createEmptyVec(nbVariables+1,&f->countUniq);
    createEmptyVec(nbVariables+1,&f->countUnSat);
    for (int i = 0; i < nbVariables+1; ++i)
    {
        addLast(&f->countUnSat,0);
        addLast(&f->countUniq,0);
    }

}

void freeFormula(Formula * f) {
    clauseLink* temp=f->clauseHead;
    for (int i = 0; i < f->nbClauses; i++){
        freeVec((temp->clause));
        free(temp->clause);
        temp=temp->next;
        free(f->clauseHead);
        f->clauseHead=temp;
    }
    for (int i = 0; i < (f->nbVariables*2) ; ++i)
    {
        temp=f->literalOccurrences[i];
        while(temp!=NULL){
            
            temp=temp->next;
            free(f->literalOccurrences[i]);
            f->literalOccurrences[i]=temp;
        }
    }
}


/*****************************************************
 * Create space for clause 
 * The default space allocated will be DEFAULTSIZE
 * @param f the formula
 * @param clauseNumber (the position)

 */

clauseLink* createClause(Formula *f, int clauseNumber) {
    assert(clauseNumber <= f->nbClauses);
    clauseLink* temp=(clauseLink*) malloc(sizeof(clauseLink));
    temp->clauseNumber=clauseNumber;
    temp->next=NULL;
    temp->clause=(vecInt*) malloc(sizeof(vecInt));
    createEmptyVec(DEFAULTSIZE, (temp->clause));
    assert(temp->clauseNumber==clauseNumber);
    assert(temp->clause!=NULL);
    addNodeToFront(f, temp);
    return temp;
}

/*****************************************************
 * insert a literal l in a given clause
 * @param f the formula
 * @param clauseNumber (the position)
 * @param Literal l
 */
void addLiteralInClause(Formula *f, int clauseNumber, Literal l) {
    assert(clauseNumber < f->nbClauses);
    clauseLink* temp= findClause(*f,clauseNumber);
    if (temp==NULL){
        assert(temp==NULL);
        //printf("hereeee\n");
        temp=createClause(f,clauseNumber);
        assert(temp->clause!=NULL);
        //findClause(*f,clauseNumber);
        assert(temp!=NULL);
        addLast(temp->clause, l);
    }
    else{
        assert(temp!=NULL);
        //printf("\n%d\n",temp->clauseNumber);
        assert(temp->clause!=NULL);
        addLast(temp->clause, l);
        
    }
    clauseLink* tempOcc =createClauseOcc(clauseNumber);
    tempOcc->clause=temp->clause;
    //printf("%d\n",tempOcc->clauseNumber );   
    addNodeToFrontOcc(&f->literalOccurrences[literalIdx(l)],tempOcc);
    //printf("%d\n", f->literalOccurrences[literalIdx(l)]->clauseNumber);
}


//new
/*****************************************************
 * insert a clause to link list of clauses of the fourmola
 * @param f the formula
 * @param the clause to add
 */
void addNodeToFront(Formula *f, clauseLink * toAdd){
    assert(toAdd!=NULL);
    //if linked is empty then add the node to the front of the linked list
    if (f->clauseHead==NULL)
    {
        f->clauseHead=toAdd;
    }
    else
    {
        toAdd->next=f->clauseHead;
        f->clauseHead=toAdd;
    }
    assert(f->clauseHead!=NULL);
}


/*****************************************************
 * insert a occurance to link list of occurances of the literal
 * @param f the formula
 * @param the clause to add
 */
void addNodeToFrontOcc(clauseLink** head, clauseLink * toAdd){
    assert(toAdd!=NULL);
    //printf("call\n");
    //if linked is empty then add the node to the front of the linked list
    if (head==NULL)
    {
        *head=toAdd;
    }
    else
    {
        //printf("call\n");

        toAdd->next=*head;
        *head=toAdd;
    }
    assert(head!=NULL);
}


/*****************************************************
 * Create space for occurance 
 * @param clauseNumber (the position)

 */

clauseLink* createClauseOcc(int clauseNumber) {
    clauseLink* temp=(clauseLink*) malloc(sizeof(clauseLink));
    temp->clauseNumber=clauseNumber;
    temp->next=NULL;
    assert(temp->clauseNumber==clauseNumber);
    return temp;
}




//new
/*****************************************************
 * find the clause from the link list
 * @param f the formula
 * @param clauseNumber the formula
 * @return pointer to clause
 */
clauseLink* findClause(Formula f, int clauseNumber){
    assert(clauseNumber>=0);
    //assert(f.clauseHead!=NULL);
    clauseLink *temp=f.clauseHead;
    while(temp!=NULL){
        if (temp->clauseNumber==clauseNumber)
        {
            assert(temp!=NULL);
            return temp;
        }
        else
        {
            temp=temp->next;
        }
    }
    return NULL;
}


void printFormula(Formula f){
    printf("\nNumber of clauses: %d",f.nbClauses);
    printf("\nNumber of varialbes: %d",f.nbVariables);
    printf("\nClauses:\n");
    clauseLink* temp=f.clauseHead;
    while(temp!=NULL){
        printf("clause Number: %d [",temp->clauseNumber);
        for (int i = 0; i < temp->clause->size; ++i)
        {
            printf("%d ,",temp->clause->datas[i]);
        }
        printf("] -->\n");
        temp=temp->next;
    }

    printf("Occurences:\n");
    for (int i = 0; i < f.nbVariables*2; ++i)
    {
        temp=f.literalOccurrences[i];
        printf("occurances of literal: %d is\n[", idxLiteral(i));
        while(temp!=NULL)
        {
            printf("%d ,", temp->clauseNumber);
            temp=temp->next;
        }
        printf("] -->\n" );
    }
}



/**
  We suppose the string is trimmed
 * Otherwise: http://stackoverflow.com/questions/122616/how-do-i-trim-leading-trailing-whitespace-in-a-standard-way
 * @return -1 if OK, the position of the error otherwise
 */
int str2int(char *str, int *value) {
    *value = 0;
    int sign = (str[0] == '-' ? -1 : 1);
    for (int i = (str[0] == '-' ? 1 : 0); str[i] != 0; i++) {
        if (!(str[i] >= 48 && str[i] <= 57)) // Ascii char 0 to 9
            return i;
        *value = *value * 10 + (str[i] - 48);
    }
    *value = *value * sign;
    return -1;
}

int extractWord(FILE *f, char *buffer) {
    int i = 0;
    char c;
    // skip space, tab, \n...
    do {
        c = fgetc(f);
    } while (c == ' ' || c == 10 || c == 13 || c == '\t');
    if (c == EOF) {
        buffer[i] = 0;// Finish the empty word
        return 1;
    }
    do {
        buffer[i++] = c;
        c = fgetc(f);
        if (c == EOF) break;
    } while (c != ' ' && c != 10 && c != '\t' && c != 13);

    buffer[i] = 0;
    return c == EOF;
}

// Be careful, suppose the buffer is enough large
// return 1 if end of file is reached
int extractLine(FILE *f, char *buffer) {
    int i = 0;
    char c;
    do {
        c = fgetc(f);
    } while (c == 10 || c == 13);
    if (c == EOF) {
        buffer[i] = 0;// Finish the empty word
        return 1;
    }
    do {
        buffer[i++] = c;
        c = fgetc(f);
        if (c == EOF) break;
    } while (c != 10 && c != 13);

    buffer[i] = 0;
    return c == EOF;
}





void importDimacs(char *name, Formula *f) {
    FILE *file;
    file = fopen(name, "r");
    if (file == NULL) {
        perror("There is a problem");
        exit(EXIT_FAILURE);
    }

    char buffer[1000];


    extractWord(file, buffer); // p
    //printf("%s \n", buffer);
    extractWord(file, buffer); // cnf
    //printf("%s \n", buffer);
    extractWord(file, buffer); // var
    //printf("%s \n", buffer);
    int nbVar;
    str2int(buffer, &nbVar);
    extractWord(file, buffer); // clauses
    //printf("%s \n", buffer);
    int nbClauses;
    str2int(buffer, &nbClauses);
    //printf("%d     %d", nbVar, nbClauses);
    createFormula(f, nbClauses, nbVar);
    int clauseNum = 0;
    int temp = extractWord(file, buffer);
    while (!temp) {
        while (buffer[0] != '0') {
            int literal;
            str2int(buffer, &literal);
            addLiteralInClause(f, clauseNum, literal);
            //printf("\n%s %d", buffer, clauseNum);
            temp = extractWord(file, buffer);
        }
        clauseNum++;
        extractWord(file, buffer);
    }
}












