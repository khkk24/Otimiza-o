CC = gcc
WFLAG = -Wall

.PHONY: doc clean purge

all: main

trab1.o: trab1.c trab1.h
	$(CC) -c trab1.c $(WFLAG)
main.o : main.c trab1.o
	$(CC) -c main.c $(WFLAGS)

main: main.o trab1.o
	$(CC) -o trab1 main.o trab1.o $(WFLAGS)

clean: 
	-rm -f *~ *.o

purge: clean
	-rm trab1
	-rm -rf