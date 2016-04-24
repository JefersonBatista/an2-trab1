# Makefile

all: coef sor

coef: coef.c
	gcc -Wall -c coef.c
	
sor: sor.c
	gcc -Wall -c sor.c
	
clean:
	rm *.o

