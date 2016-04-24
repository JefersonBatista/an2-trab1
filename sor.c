#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coef.h"

real *sor(Coef *coef, real w, int iterMax, int tol, int n, int m) {
	int iter, i, N = n*m;
	iter = 0;
	
	real *u = (real*) calloc(N, sizeof(real));
	real r, soma, erro, erroMax, temp;
	
	real *a, *b, *c, *d, *e, *f;
	a = A(coef);
	b = B(coef);
	c = C(coef);
	d = D(coef);
	e = E(coef);
	f = F(coef);
	
	for(i = 0; i < N; i++)
		u[i] = f[i]/a[i];
	
	while(iter < iterMax) {
		erroMax = 0.0;
		
		for(i = 0; i < N; i++) {
			r = 1/a[i];
			
			soma = 0;
			soma += f[i];
			soma -= e[i]*u[i-n];
			soma -= c[i]*u[i-1];
			soma -= b[i]*u[i+1];
			soma -= d[i]*u[i+n];
			
			temp = r*w*soma + (1-w)*u[i];
			erro = abs(u[i] - temp);
			
			if(erro > erroMax)
				erroMax = erro;
				
			u[i] = temp;
		}
		
		if(erroMax < tol)
			break;
		
		iter++;
	}
	return u;
}

