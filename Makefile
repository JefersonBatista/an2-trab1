# Makefile

all: coef sor contorno main

coef: coef.c
	gcc -Wall -c coef.c
	
sor: sor.c
	gcc -Wall -c sor.c
	
contorno: contorno.c
	gcc -Wall -c contorno.c
	
main: main.c coef.o sor.o contorno.o
	gcc -Wall -o main main.c coef.o sor.o contorno.o
	
clean:
	rm *.o main

