#ifndef _F_UTILS
#define _F_UTILS
#include <stdio.h>
#include "FractArithmetic.h"
frac mixToImp(Mfrac );
void lcf(frac*, frac *);
int gcd(int, int);
frac simplify(frac);
int implement(frac, frac, int, frac *);
int determine(char);
int parse(FILE *);
int scanMFrac(Mfrac*, FILE *);
Mfrac toMix(frac);
void scanFrac(frac *, FILE *);
void printFrac(frac , FILE *);
#endif
