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
	real invHx = 1/hx;
	real invHy = 1/hy;

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
	
		novo->a[I] = gamma(x, y) + 2*invHx*invHx + 2*invHy*invHy;
		
		// Vizinho da direita
		/* if(i == n)
			novo->b[I] = 0.0;
		else */
		novo->b[I] = -invHx*invHx + betaX(x, y)*0.5*invHx;
		
		// Vizinho da esquerda
		/* if(i == 1)
			novo->c[I] = 0.0;
		else */
		novo->c[I] = -invHx*invHx - betaX(x, y)*0.5*invHx;
		
		// Vizinho de cima
		/* if(j == m)
			novo->d[I] = 0.0;
		else */
		novo->d[I] = -invHy*invHy + betaY(x, y)*0.5*invHy;
		
		// Vizinho de baixo
		/* if(j == 1)
			novo->e[I] = 0.0;
		else */
		novo->e[I] = -invHy*invHy - betaY(x, y)*0.5*invHy;
		
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
		
	printf("\n\nb -> ");
	
	for(I = 0; I < N; I++)
		printf("%lf ", b[I]);
	
	printf("\n\nc -> ");
	
	for(I = 0; I < N; I++)
		printf("%lf ", c[I]);
		
	printf("\n\nd -> ");
	
	for(I = 0; I < N; I++)
		printf("%lf ", d[I]);
		
	printf("\n\ne -> ");
	
	for(I = 0; I < N; I++)
		printf("%lf ", e[I]);
		
	printf("\n\nf -> ");
	
	for(I = 0; I < N; I++)
		printf("%lf ", f[I]);
		
	printf("\n\n");
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

/* real f(real x, real y) {
	real monstro = -((5.0/2) * (pow(e,pow(x,4.5))) *  (81 * (pow(x,9)) - 81 * (pow(x,8)) + 135 * (pow(x,4.5)) - 99 * (pow(x,3.5)) + 8) * (y-1) * y + (20 * (pow(e,pow(x,4.5))) * (x -1) * x) ) + 5 * (pow(e,pow(x,4.5))) * ( x * ( 9 *( x-1) * (pow(x,3.5))+4)-2)*(y-1)*y + 20*y*(10*(pow(e,pow(x,4.5)))*(x-1)*x*(2*y-1))+ 10 * x*y*(1-x)*(1-y)*(pow(e,pow(x,4.5)))
} */

