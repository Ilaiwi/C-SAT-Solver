#include<structures/vecInt.h>
#include<SAT/solving_07_02.h>
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

int main(int argc, char const *argv[])
{
	


	Formula f , n , w;
	//first test
	createFormula(&f,5,5);
	importDimacs("cnf.txt",&f);
	printFormula(f);


	//second test
	createFormula(&n,10,10);
	importDimacs("cnf1.txt",&n);
	printFormula(n);


	//third test
	createFormula(&w,20,20);
	importDimacs("cnf2.txt",&w);
	printFormula(w);


	return 0;
}