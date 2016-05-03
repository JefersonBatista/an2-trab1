#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define euler 2.718281828

// Definição das macros
#define k 1
#define betaX(x, y) (0)
#define betaY(x, y) (0)
#define gamma(x, y) (0)

typedef double real;
typedef struct coef Coef;

Coef *criaCoef(real a, real b, real c, real d, int n, int m);
void printCoef(Coef *coef);
real *A(Coef *coef);
real *B(Coef *coef);
real *C(Coef *coef);
real *D(Coef *coef);
real *E(Coef *coef);
real *F(Coef *coef);
int divX(Coef *coef);
int divY(Coef *coef);

void liberaCoef(Coef *coef);

real f(real x, real y);
real val(real x, real y);


