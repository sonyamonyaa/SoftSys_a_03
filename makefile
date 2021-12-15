CC=gcc
AR=ar
FLAGS= -Wall -g
OBJ= main.o my_string.o

all: stringProg

stringProg: main.o stringLib.a
		$(CC) $(FLAGS) -o stringProg main.o stringLib.a

stringLib.a: $(OBJ)
		$(AR) -rcs stringLib.a $(OBJ)

main.o: main.c stringLib.h
		$(CC) $(FLAGS) -c main.c

my_string.o: my_string.c stringLib.h
		$(CC) $(FLAGS) -c my_string.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so stringProg
