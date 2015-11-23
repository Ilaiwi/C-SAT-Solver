CC = gcc
CFLAGS = -std=c99 -Wall -O2 -g 
ROOT = /Users/ahmadilaiwi/documents/ibnsina/ibnsina/day3/7/SATsession
INC = -I$(ROOT)/headers
LIBS = 

OBJ=$(subst .c,.o,$(SRC))


.c.o:
	$(CC) -c $(CFLAGS) $(INC) $<




