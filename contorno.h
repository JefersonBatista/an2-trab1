#include <stdio.h>
#include <stdlib.h>
#include "coef.h"

#define DOWN 0
#define LEFT 1
#define RIGHT 2
#define UP 3

void valorPrescrito(Coef *coef, real valor, int lado);
void derivadaContorno(Coef *coef, real c, real h, real hx, real hy, int lado);


