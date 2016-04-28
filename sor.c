#include "sor.h"

real *sor(Coef *coef, real omega, int iterMax, real tol) {
	int n, m, N, I, iter;
	n = divX(coef);
	m = divY(coef);
	N = n*m;
	
	real *u = (real*) calloc(N, sizeof(real));
	real r, soma, erro, erroMax, temp;
	
	real *a, *b, *c, *d, *e, *f;
	a = A(coef);
	b = B(coef);
	c = C(coef);
	d = D(coef);
	e = E(coef);
	f = F(coef);
	
	for(I = 0; I < N; I++)
		u[I] = f[I]/a[I];
	
	iter = 0;
	while(iter < iterMax) {
		erroMax = 0.0;
		
		for(I = 0; I < N; I++) {
			r = 1.0/a[I];
			
			soma = f[I];
			if(e[I] != 0.0)
				soma -= e[I]*u[I-n];
			if(c[I] != 0.0)
				soma -= c[I]*u[I-1];
			if(b[I] != 0.0)
				soma -= b[I]*u[I+1];
			if(d[I] != 0.0)
				soma -= d[I]*u[I+n];
			
			temp = r*omega*soma + (1.0-omega)*u[I];
			erro = fabs(u[I] - temp);
			
			if(erro > erroMax)
				erroMax = erro;
				
			u[I] = temp;
		}
		
		// printf("erroMax = %lf\n", erroMax);
		
		if(erroMax < tol)
			break;
		
		iter++;
	}
	
	printf("iter = %d\n\n", iter);
	
	return u;
}

real *sorLivre(real a, real b, real c, real d, int n, int m, real omega, int iterMax, real tol, real valor) {
	int N = n*m;
	real hx = (b - a)/(n - 1);
	real hy = (d - c)/(m - 1);
	real invHx = 1/hx;
	real invHy = 1/hy;
	
	real x, y, A, B, C, D, E, F;
	int I, i, j, iter;
	
	real *u = (real*) calloc(N, sizeof(real));
	real r, soma, erro, erroMax, temp;
	
	for(I = 0; I < N; I++)
		u[I] = 0.0;
	
	iter = 0;
	while(iter < iterMax) {
		erroMax = 0.0;
		
		for(I = 0; I < N; I++) {
			i = (I % n) + 1;
			j = I/n + 1;
		
			x = a + (i - 1)*hx;
			y = c + (j - 1)*hy;
			
			if(i != 1 && i != n && j != 1 && j!= m) {
				A = gamma(x, y) + 2*invHx*invHx + 2*invHy*invHy;
				B = -invHx*invHx + betaX(x, y)*0.5*invHx;
				C = -invHx*invHx - betaX(x, y)*0.5*invHx;
				D = -invHy*invHy + betaY(x, y)*0.5*invHy;
				E = -invHy*invHy - betaY(x, y)*0.5*invHy;
				F = f(x, y);
			
				r = 1.0/A;
			
				soma = F = f(x, y);
				soma -= E*u[I-n];
				soma -= C*u[I-1];
				soma -= B*u[I+1];
				soma -= D*u[I+n];
			
				temp = r*omega*soma + (1.0-omega)*u[I];
			}
			else 
				temp = valor*omega + (1.0-omega)*u[I];
				
			erro = fabs(u[I] - temp);
			
			if(erro > erroMax)
				erroMax = erro;
				
			u[I] = temp;
		}
		
		// printf("erroMax = %lf\n", erroMax);
		
		if(erroMax < tol)
			break;
		
		iter++;
	}
	
	printf("iter = %d\n\n", iter);
	
	return u;
}

