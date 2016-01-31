#define _CRT_SECURE_NO_WARNINGS
#ifndef _GAUSS_JORDAN
#define _GAUSS_JORDAN
int GaussJordan(frac **A, int n,frac*x);
void printFracMatr(frac **A, int M, int N, FILE *f);
void getFracMatr(frac **A, int M, int N, FILE *f);
frac ** GetMem(int M, int N);
void Erase(frac **A, int M, int N);
#endif