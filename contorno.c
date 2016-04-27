#include "contorno.h"

void valorPrescrito(Coef *coef, real valor, int lado) {
	int n = divX(coef);
	int m = divY(coef);
	int i, j, I;
	
	real *a = A(coef);
	real *b = B(coef);
	real *c = C(coef);
	real *d = D(coef);
	real *e = E(coef);
	real *f = F(coef);
	
	switch(lado) {
		case DOWN:
			j = 1;
			for(i = 2; i < n; i++) {
				I = i + n*(j - 1) - 1;
		
				a[I] = 1.0;
				b[I] = 0.0;
				c[I] = 0.0;
				d[I] = 0.0;
				e[I] = 0.0;
				f[I] = valor;
			}
			break;
	
		case LEFT:
			i = 1;
			for(j = 1; j <= m; j++) {
				I = i + n*(j - 1) - 1;
		
				a[I] = 1.0;
				b[I] = 0.0;
				c[I] = 0.0;
				d[I] = 0.0;
				e[I] = 0.0;
				f[I] = valor;		
			}
			break;
	
		case RIGHT:
			i = n;
			for(j = 1; j <= m; j++) {
				I = i + n*(j - 1) - 1;
		
				a[I] = 1.0;
				b[I] = 0.0;
				c[I] = 0.0;
				d[I] = 0.0;
				e[I] = 0.0;
				f[I] = valor;		
			}
			break;
	
		case UP:
			j = m;
			for(i = 2; i < n; i++) {
				I = i + n*(j - 1) - 1;
		
				a[I] = 1.0;
				b[I] = 0.0;
				c[I] = 0.0;
				d[I] = 0.0;
				e[I] = 0.0;
				f[I] = valor;		
			}
			break;
			
		default:
			printf("\nLado inexistente!\n");
	}
}

void derivadaContorno(Coef *coef, real cst, real H, real hx, real hy, int lado) {
	int n = divX(coef);
	int m = divY(coef);
	int i, j, I;
	
	real *a = A(coef);
	real *b = B(coef);
	real *c = C(coef);
	real *d = D(coef);
	real *e = E(coef);
	real *f = F(coef);
	
	switch(lado) {
		case DOWN:
			j = 1;
			for(i = 2; i < n; i++) {
				I = i + n*(j - 1) - 1;
		
				a[I] += e[I]*(1-hy*cst/k);
				f[I] -= e[I]*(hy*cst*H/k);
				e[I] = 0.0;
			}
			break;
	
		case LEFT:
			i = 1;
			
			e[0] = 0.0; // canto de baixo
			d[n*(m-1)] = 0.0 // canto de cima
			
			for(j = 1; j <= m; j++) {
				I = i + n*(j - 1) - 1;
		
				a[I] += c[I]*(1-hx*cst/k);
				f[I] -= c[I]*(hx*cst*H/k);
				c[I] = 0.0;		
			}
			break;
	
		case RIGHT:
			i = n;
			
			e[n-1] = 0.0; // canto de baixo
			d[n*m - 1] = 0.0; //canto de cima
			
			for(j = 1; j <= m; j++) {
				I = i + n*(j - 1) - 1;
		
				a[I] += b[I]*(1-hx*cst/k);
				f[I] -= b[I]*(hx*cst*H/k);
				b[I] = 0.0;		
			}
			break;
	
		case UP:
			j = m;
			for(i = 2; i < n; i++) {
				I = i + n*(j - 1) - 1;
		
				a[I] += d[I]*(1-hy*cst/k);
				f[I] -= d[I]*(hy*cst*H/k);
				d[I] = 0.0;		
			}
			break;
			
		default:
			printf("\nLado inexistente!\n");
	}
}


