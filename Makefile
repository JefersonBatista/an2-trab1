# Makefile

all: coef sor main

coef: coef.c
	gcc -Wall -c coef.c
	
sor: sor.c
	gcc -Wall -c sor.c
	
main: main.c coef.o sor.o
	gcc -Wall -o main main.c coef.o sor.o
	
clean:
	rm *.o main

