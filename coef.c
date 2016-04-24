#include "coef.h"

struct coef {
	real *a, *b, *c, *d, *e, *f;
	int n, m;
};

// Calculando os coeficientes
Coef *criaCoef(real a, real b, real c, real d, int n, int m) {
	int N = n*m;
	real hx = (b - a)/(n - 1);
	real hy = (d - c)/(m - 1);
	real ihx = 1/hx;
	real ihy = 1/hy;

	// Alocando espaço para os coeficientes
	Coef *novo = (Coef*) malloc(sizeof(Coef));
	novo->a = (real*) calloc(N, sizeof(real));
	novo->b = (real*) calloc(N, sizeof(real));
	novo->c = (real*) calloc(N, sizeof(real));
	novo->d = (real*) calloc(N, sizeof(real));
	novo->e = (real*) calloc(N, sizeof(real));
	novo->f = (real*) calloc(N, sizeof(real));
	
	novo->n = n;
	novo->m = m;
	
	real x, y;
	int I, i, j;
	for(I = 0; I < N; I++) {
		i = (I % n) + 1;
		j = I/n + 1;
		
		x = a + (i - 1)*hx;
		y = c + (j - 1)*hy;
	
		novo->a[I] = gamma(x, y) + 2*ihx + 2*ihy;
		
		// Vizinho da direita
		if(i == n)
			novo->b[I] = 0.0;
		else
			novo->b[I] = -ihx*ihx + betaX(x, y)*0.5*ihx;
		
		// Vizinho da esquerda
		if(i == 1)
			novo->c[I] = 0.0;
		else
			novo->c[I] = -ihx*ihx - betaX(x, y)*0.5*ihx;
		
		// Vizinho de cima
		if(j == m)
			novo->d[I] = 0.0;
		else
			novo->d[I] = -ihy*ihy + betaY(x, y)*0.5*ihy;
		
		// Vizinho de baixo
		if(j == 1)
			novo->e[I] = 0.0;
		else
			novo->e[I] = -ihy*ihy - betaY(x, y)*0.5*ihy;
		
		// Vetor independente
		novo->f[I] = f(x, y);
	}
	
	return novo;
}

void printCoef(Coef *coef) {
	int I, N, n, m;
	real *a = coef->a;
	real *b = coef->b;
	real *c = coef->c;
	real *d = coef->d;
	real *e = coef->e;
	real *f = coef->f;
	
	n = coef->n;
	m = coef->m;
	N = n*m;
	
	printf("\na -> ");
	
	for(I = 0; I < N; I++)
		printf("%lf ", a[I]);
		
	printf("\nb -> ");
	
	for(I = 0; I < N; I++)
		printf("%lf ", b[I]);
	
	printf("\nc -> ");
	
	for(I = 0; I < N; I++)
		printf("%lf ", c[I]);
		
	printf("\nd -> ");
	
	for(I = 0; I < N; I++)
		printf("%lf ", d[I]);
		
	printf("\ne -> ");
	
	for(I = 0; I < N; I++)
		printf("%lf ", e[I]);
		
	printf("\nf -> ");
	
	for(I = 0; I < N; I++)
		printf("%lf ", f[I]);
}

real *A(Coef *coef) {
	return coef->a;
}

real *B(Coef *coef) {
	return coef->b;
}

real *C(Coef *coef) {
	return coef->c;
}

real *D(Coef *coef) {
	return coef->d;
}

real *E(Coef *coef) {
	return coef->e;
}

real *F(Coef *coef) {
	return coef->f;
}

int divX(Coef *coef) {
	return coef->n;
}

int divY(Coef *coef) {
	return coef->m;
}

