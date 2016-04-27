#include "sor.h"
#include "contorno.h"

// Agora todo o contorno deve ser tratado para rodar o programa
// Ainda tenho que consertar o critério de parada por tol

int main() {
	int n, m, N;
	real a, b, c, d;
	
	real omega, tol;
	int iterMax;
	real valor;
	
	scanf("%d", &n);
	scanf("%d", &m);
	
	scanf("%lf", &a);
	scanf("%lf", &b);
	scanf("%lf", &c);
	scanf("%lf", &d);
	
	scanf("%lf", &omega);
	scanf("%d", &iterMax);
	scanf("%lf", &tol);
	scanf("%lf", &valor);
	
	N = n*m;
	
	Coef *coef = criaCoef(a, b, c, d, n, m);
	valorPrescrito(coef, valor, DOWN);
	valorPrescrito(coef, valor, LEFT);
	valorPrescrito(coef, valor, RIGHT);
	valorPrescrito(coef, valor, UP);
	printCoef(coef);
	real *x = sor(coef, omega, iterMax, tol);
	
	printf("Solução do sistema linear: \n");
	int I;
	
	for(I = 0; I < N; I++)
		printf("%lf\n", x[I]);
	
	return 0;
}


