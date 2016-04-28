#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coef.h"

real *sor(Coef *coef, real omega, int iterMax, real tol);
real *sorLivre(real a, real b, real c, real d, int n, int m, real omega, int iterMax, real tol, real valor);

