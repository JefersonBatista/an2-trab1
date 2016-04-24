#include <stdio.h>
#include <stdlib.h>

// Definição das macros
#define k 1
#define betaX(x, y) (1)
#define betaY(x, y) (20*y)
#define gamma(x, y) (1)
#define f(x, y) (x + y)

typedef float real;
typedef struct coef Coef;

Coef *criaCoef(real a, real b, real c, real d, int n, int m);
real *A(Coef *coef);
real *B(Coef *coef);
real *C(Coef *coef);
real *D(Coef *coef);
real *E(Coef *coef);
real *F(Coef *coef);

