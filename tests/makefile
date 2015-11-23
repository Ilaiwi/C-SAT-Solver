include ../include.mk

tests0701: solving_07_01_tests.c ../src/SAT/solving_07_01.o  ../src/structures/vecInt.o
	$(CC) $(CFLAGS) $(INC)  -o solving_07_01_tests ../src/structures/vecInt.o solving_07_01_tests.c ../src/SAT/solving_07_01.o -lcunit
	./solving_07_01_tests

tests0702: solving_07_02_tests.c ../src/SAT/solving_07_01.o ../src/SAT/solving_07_02.o  ../src/structures/vecInt.o  ../src/SAT/solving_09_01.o
	$(CC) $(CFLAGS) $(INC)  -o solving_07_02_tests ../src/structures/vecInt.o solving_07_02_tests.c ../src/SAT/solving_07_01.o ../src/SAT/solving_07_02.o ../src/SAT/solving_09_01.o  -lcunit
	./solving_07_02_tests


tests0801: solving_08_01_tests.c ../src/SAT/solving_07_01.o ../src/SAT/solving_07_02.o ../src/structures/vecInt.o ../src/SAT/solving_08_01.o ../src/SAT/solving_09_01.o
	$(CC) $(CFLAGS) $(INC)  -o solving_08_01_tests ../src/structures/vecInt.o solving_08_01_tests.c ../src/SAT/solving_07_01.o ../src/SAT/solving_07_02.o ../src/SAT/solving_08_01.o ../src/SAT/solving_09_01.o -lcunit
	./solving_08_01_tests

tests0901: solving_09_01_tests.c ../src/SAT/solving_07_01.o ../src/SAT/solving_07_02.o ../src/structures/vecInt.o ../src/SAT/solving_08_01.o ../src/SAT/solving_09_01.o
	$(CC) $(CFLAGS) $(INC) -o solving_09_01_tests ../src/structures/vecInt.o solving_09_01_tests.c ../src/SAT/solving_07_01.o ../src/SAT/solving_07_02.o ../src/SAT/solving_08_01.o ../src/SAT/solving_09_01.o -lcunit
	./solving_09_01_tests



clean : 
	rm -rf solving_07_02_tests solving_07_01_tests solving_08_01_tests solving_09_01_tests