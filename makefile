CC = gcc
AR = ar -rcs
OBJECTS_MAIN = main.o
OBJECTS_LIB = myBank.o
FLAGS = -I. -Wall

all: main

main: $(OBJECTS_MAIN) libmybank.a
	$(CC) $(FLAGS) -o main $(OBJECTS_MAIN) libmybank.a

mybank: libmybank.a

libmybank.a: $(OBJECTS_LIB)
	$(AR) $@ $(OBJECTS_LIB)

main.o: main.c
	$(CC) $(FLAGS) -c main.c

myBank.o: myBank.c
	$(CC) $(FLAGS) -c myBank.c

.PHONY: clean all mybank

clean:
	rm -f *.o *.a *.so main