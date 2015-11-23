include ../../include.mk

SRC = solving_07_01.c solving_07_02.c solving_08_01.c solving_01_04_modify.c solving_09_01.c

all: $(OBJ)

clean:
	rm -f *.o depend.mk

depend.mk:
	$(CC) $(CFLAGS) $(INC) $(SRC) -MM  > depend.mk



-include depend.mk