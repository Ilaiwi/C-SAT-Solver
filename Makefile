include ./include.mk

SRC= solving_07_04_main.c

SUBDIRS= src/structures src/SAT

.SUFFIXES: .c

all: depend.mk
	for i in $(SUBDIRS); do (cd $$i; $(MAKE) all); done

solving_07_04_main: all solving_07_04_main.c
	$(CC) $(CFLAGS) -o $@ $(INC) src/SAT/solving_07_01.o src/SAT/solving_07_02.o src/structures/vecInt.o solving_07_04_main.c src/SAT/solving_09_01.o


solving_12_01_main: all solving_12_01_main.c
	$(CC) $(CFLAGS) -o $@ $(INC) src/SAT/solving_07_01.o src/SAT/solving_07_02.o src/structures/vecInt.o solving_12_01_main.c src/SAT/solving_09_01.o src/SAT/solving_08_01.o


solving_14_01_main: all solving_12_01_main.c
	$(CC) $(CFLAGS) -o $@ $(INC) src/SAT/solving_07_01.o src/SAT/solving_07_02.o src/structures/vecInt.o solving_14_01_main.c src/SAT/solving_09_01.o src/SAT/solving_08_01.o


solving_15_01_main: all solving_15_01_main.c
	$(CC) $(CFLAGS) -o $@ $(INC) src/SAT/solving_07_01.o src/SAT/solving_09_01.o src/SAT/solving_07_02.o src/structures/vecInt.o solving_15_01_main.c

solver: all solver.c
	$(CC) $(CFLAGS) -o $@ $(INC) src/SAT/solving_07_01.o src/SAT/solving_09_01.o src/SAT/solving_07_02.o src/SAT/solving_08_01.o src/structures/vecInt.o solver.c


solving_08_02_main: all solving_08_02_main.c
	$(CC) $(CFLAGS) -o $@ $(INC) src/SAT/solving_07_01.o src/SAT/solving_08_01.o src/SAT/solving_07_02.o src/SAT/solving_09_01.o src/structures/vecInt.o solving_08_02_main.c  src/SAT/solving_01_04_modify.o


tests0701: all
	cd tests; make tests0701 


tests0702: all
	cd tests; make tests0702 

tests0801: all
	cd tests; make tests0801 

tests0901: all
	cd tests; make tests0901 


clean:
	rm -f $(OBJ) core *~ depend.mk
	for i in $(SUBDIRS); do (cd $$i; $(MAKE) clean); done
	cd tests; make clean

mrproper : clean
	rm solving_07_04_main

depend.mk: $(SRC)
	$(CC) $(CFLAGS) $(INC) $(SRC) -MM  > depend.mk
	for i in $(SUBDIRS); do (cd $$i; $(MAKE) depend.mk); done


include depend.mk
