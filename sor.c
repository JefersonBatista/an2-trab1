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
			erro = abs(u[I] - temp);
			
			if(erro > erroMax)
				erroMax = erro;
				
			u[I] = temp;
		}
		
		printf("erroMax = %lf\n", erroMax);
		
		/* if(erroMax < tol)
			break; */
		
		iter++;
	}
	
	printf("iter = %d\n\n", iter);
	
	return u;
}

