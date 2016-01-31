#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include "FractArithmetic.h"
#include "FractUtils.h"
#include "GaussJordan.h"
#include <stdlib.h>
//Äëÿ calloc
int GaussJordan(frac **A,int n, frac *x)
{
	FILE *in = NULL, *out = NULL;
	int i, j, k;
	frac c, tmp;
	printf("ACA|b!\n");
	printFracMatr(A, n, n + 1, stdout);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i != j)
			{
				c = div(A[i][j],A[j][j]);
				for (k = 0; k < n+1; k++)
				{
					tmp = mul(c, A[j][k]);
					A[i][k] = sub(A[i][k], tmp);
				}
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		x[i] =div( A[i][n+1], A[i][i]);
	}
	return(0);
}


void printFracMatr(frac **A, int M, int N,FILE *f){
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			printFrac(A[i][j], f);
			fprintf(f, "  ");
		};
		fprintf(f, "\n");
	};
};

void getFracMatr(frac **A, int M, int N, FILE *f){
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			Mfrac tmp;
			scanMFrac(&tmp, f);
			A[i][j] = mixToImp(tmp);
		};
	};
};

frac ** GetMem(int M, int N){
	frac**A = (frac**)calloc(N, sizeof(frac*));
		for (int i = 0; i < M; i++){
			A[i] = (frac*)calloc(1, sizeof(frac));
		};
	return A;
}

void Erase(frac **A, int M, int N){
	for (int i = 0; i < M; i++){
		free(A[i]);
	};
	free(A);
}