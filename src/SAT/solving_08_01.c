#include<SAT/solving_08_01.h>

/**
 * give the status of a clause under a given interpretation
 * @param c the clause
 * @parm I the interpretation
 * @return TRUE if it is satisfied, FALSE if it is falsified, UNDEF if one can not answer this question
 */
int statusClause(Clause c,Interpretation I){
    if (isUndefClause(c,I)) return UNDEF;
    else if (isUndefClause(c,I)) return FALSE;
    else if (isSatisfiedClause(c,I)) return TRUE;
    else return UNDEF;
}


/**
 * These 3 functions are used to help the readability
 * Use statusClause with good parameters
 */

int isSatisfiedClause(Clause c,Interpretation I){
    int countTRUE=0;
    for (int i = 0; i < c.size ; ++i) {
        int literal = getValueLiteral(I,c.datas[i]);
        if (literal == TRUE){
            if (i>0){
                int temp;
                temp=c.datas[i];
                c.datas[i]=c.datas[0];
                c.datas[0]=temp;

            }
            countTRUE++;
        }
    }
    if (countTRUE>0) return TRUE;
    else return FALSE;
}
int isFalsifiedClause(Clause c,Interpretation I){
    for (int i = 0; i <c.size ; ++i) {
        int literal = getValueLiteral(I,c.datas[i]);
        if (literal==UNDEF){
            return FALSE;
        }
        else if (literal == TRUE){
            return FALSE;
        }
    }
    return TRUE;
}


int isUndefClause(Clause c,Interpretation I){
    if (!isFalsifiedClause(c,I) && !isSatisfiedClause(c,I)) return TRUE;
    if (!isFalsifiedClause(c,I) && !isSatisfiedClause(c,I)) return TRUE;
    else return FALSE;
}


/**
 * Say if a clause is unit (only one literal is UNDEF and all other ones are falsified
 * under a given interpretation
 * @return 1 if yes, 0 otherwise
 */
int isUnit(Clause c,Interpretation I){
    int countUNDEFF=0;
    int countFALSE=0;
    //if (isSatisfiedClause(c,I)) return FALSE;
    //else {
        for (int i = 0; i <c.size ; i++) {
            int literal = getValueLiteral(I,c.datas[i]);
            if (literal == UNDEF){
                countUNDEFF++;
            }
            else if (literal==TRUE){
                return FALSE;
            }
            else if (literal==FALSE){
                countFALSE++;
            }
        }
        if (countUNDEFF==1 && countFALSE== (c.size-1)) {
            return TRUE;
        }
    return FALSE;

}



/**
 * @param f the formula
 * @param I an interpretation
 * @return TRUE if it is satisfied, FALSE if it is falsified, UNDEF if one can not answer this question
 */
int statusFormula(Formula f,Interpretation I){
    if (isUndefFormula(f,I)) return UNDEF;
    else if (isSatisfiedFormula(f,I)) return TRUE;
    else if (isFalsifiedFormula(f,I)) return FALSE;
    else return UNDEF;
}

/**
 * These 3 functions are used to help the readability
 * Use statusFormula with good parameters
 */
int isSatisfiedFormula(Formula c,Interpretation I){
	while(c.clauseHead!=NULL){
		int clauseStatus= statusClause(*c.clauseHead->clause,I);
        if (clauseStatus != TRUE ) return FALSE;
        c.clauseHead=c.clauseHead->next;
	}
	return TRUE;
}


int isFalsifiedFormula(Formula c,Interpretation I){


	while(c.clauseHead!=NULL){
		 if (isFalsifiedClause(*c.clauseHead->clause,I)) return TRUE;
		 c.clauseHead=c.clauseHead->next;
	}
    return FALSE;
}


int isUndefFormula(Formula c,Interpretation I){
    if (!isFalsifiedFormula(c,I) && !isSatisfiedFormula(c,I)) return TRUE;
    else return FALSE;
}


/**
new
 * gives the status of a clause under a given interpretation if it is staticfied by only one literal or not
 * @param c the clause
 * @parm I the interpretation
 * @parm l the litiral
 * @return TRUE if it is satisfied uniquely, FALSE if not uniquely satiscfied.
 */
int isUniquelySat(Clause c , Interpretation I , Literal l)
{
	assert(isSatisfiedClause(c,I));
	int status=0;
	int temp=-1;
	for (int i = 0; i < c.size; ++i)
	{

		if (c.datas[i]!=l)
		{
			temp=getValueLiteral(I, c.datas[i]);
			//printf("value of literal %d: %d\n",c.datas[i], temp);
			assert(temp!=-1);
			status=status|| temp;
			if (status)
			{
				return FALSE;
			}
		}
	}
	status=status||getValueLiteral(I,l);
	assert(status);
	return TRUE;
}


/**
new
 * gives the count of clauses that each literal solves uniequely and the clauses that are not satifiable by the literal
 * @param c the clause
 * @parm I the interpretation
 * @parm f the fourmla that contains the arrays of occus
 * @return TRUE if it is satisfied uniquely, FALSE if not uniquely satiscfied.
 */
void countSatLiterals(Formula f ,Interpretation I)
{
	for (int i = 1; i <= f.nbVariables ; ++i)
	{
		clauseLink* head ,* headOpp;
		int count=0, index;
		if (getValueLiteral(I,i))
		{
			head=f.literalOccurrences[literalIdx(i)];
			headOpp=f.literalOccurrences[oppositeLiteralIdx(i)];
			index=i;
		}
		else
		{
			head=f.literalOccurrences[oppositeLiteralIdx(i)];
			headOpp=f.literalOccurrences[literalIdx(i)];
			index= (-1*i);
		}


		
		while(head!=NULL)
		{
			if (isUniquelySat(*head->clause,I,index))
			{
				count++;
			}
			head=head->next;
		}
		f.countUniq.datas[i]=count;
		//printf("for literal %d the count of sat is %d\n",i,count);
		count=0;
		while(headOpp!=NULL){
			if (isFalsifiedClause(*headOpp->clause,I))
			{
				count++;
			}
			headOpp=headOpp->next;
		}
		f.countUnSat.datas[i]=count;
		//printf("for literal %d the count of unsat is %d\n",i,count);
	}
}


/**
new
 * gives the best index to flip by computing the litral with largest number of unsat clauses and lest number of uniq sat clauses if not found return 0
 * @param f the formula
 * @parm limit an integer to help find the literal with largest unsat clauses and lest uniq sat
 * @return TRUE if it is satisfied uniquely, FALSE if not uniquely satiscfied.
 */
int findBestFlipIndex(Formula f , int limit){
	int index=0;
	int max=-1;
	for (int i = 1; i < f.countUnSat.size; ++i)
	{
		if (max < f.countUnSat.datas[i] && f.countUnSat.datas[i] < limit )
		{
			max=f.countUnSat.datas[i];
			index=i;
		}
	}
	if(index==0){
		return 0;
	}
	else if (f.countUniq.datas[index]==0)
	{
		
		if (f.countUnSat.datas[index]>0)
		{
			//printf("%d is the best to flip\n", index );
			return index;
		}
		else
		{
			//printf("return 0\n");
			return 0;
		}
	}
	else 
	{
		return findBestFlipIndex(f,max);
	}
}

/**
new
 * gives the sulotion of the sat problem if it finds it
 * @param f the formula
 * @parm I interpreatation
 * @return TRUE if it is satisfied , FALSE if not found
 */
int solveSat(Formula f, Interpretation I){
	int index;
	for (int j = 0; j < 3000; ++j)
	{
		for (int i = 0; i < f.nbVariables*1000; ++i)
		{
			index=findBestFlipIndex(f,f.nbClauses+1);
			//printf("the value index returned :%d\n",index);
			if (index>0)
			{
				flipValue(I, index);
				//printf("the new I after flip \n");
				// for (int j = 1; j < I.size; ++j)
				// {
				// 	printf("%d ,", I.datas[j]);
				// }
				// printf("\n");
				if (isSatisfiedFormula(f,I))
				{
					//printf("found the solution\n");
					return 1;
				}
				countSatLiterals(f,I);
			}
			else 
			{
				break;
			}
		}
	//printf("the new I after index=0 \n");
	generateRandomComplete(I);
	countSatLiterals(f,I);
}
	return 0;
}

