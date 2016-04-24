#include "coef.h"

struct coef {
	real *a;
	real *b;
	real *c;
	real *d;
	real *e;
	real *f;
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
	
	real x, y;
	int I, i, j;
	for(I = 0; I < N; I++) {
		i = ((I-1) % n) + 1;
		j = I/n + 1;
		
		x = a + (i - 1)*hx;
		y = c + (j - 1)*hy;
	
		novo->a[i] = gamma(x, y) + 2*ihx + 2*ihy;
		novo->b[i] = -ihx*ihx + betaX(x, y)*0.5*ihx;
		novo->c[i] = -ihx*ihx - betaX(x, y)*0.5*ihx;
		novo->d[i] = -ihy*ihy + betaY(x, y)*0.5*ihy;
		novo->e[i] = -ihy*ihy - betaY(x, y)*0.5*ihy;
		novo->f[i] = f(x, y);
	}
	
	return novo;
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

