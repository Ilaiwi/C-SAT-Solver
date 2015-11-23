include ../../include.mk

SRC =vecInt.c 

all: $(OBJ)

clean:
	rm -f *.o depend.mk

depend.mk:
	$(CC) $(CFLAGS) $(INC) $(SRC) -MM  > depend.mk

-include depend.mk
