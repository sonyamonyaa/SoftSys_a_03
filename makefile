CC=gcc
AR=ar
FLAGS= -Wall -g
OBJ= main.o my_string.o

all: stringProg

connections: main.o libclass.a
		$(CC) $(FLAGS) -o stringProg main.o libclass.a

libclass.a: $(OBJ)
		$(AR) -rcs libclass.a $(OBJ)

main.o: main.c stringLib.h
		$(CC) $(FLAGS) -c main.c

my_mat.o: my_string.c stringLib.h
		$(CC) $(FLAGS) -c my_mat.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so connections
