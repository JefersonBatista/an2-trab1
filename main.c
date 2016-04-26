#include "sor.h"

int main() {
	Coef *coef = criaCoef(0.0, 1.0, 0.0, 1.0, 4, 4);
	printCoef(coef);
	real *x = sor(coef, 1.0, 100, 0.1);
	
	printf("Solução do sistema linear: \n");
	int i;
	
	for(i = 0; i < 16; i++)
		printf("%lf\n", x[i]);
	
	return 0;
}


