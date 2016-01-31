/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "FractUtils.h"
#include "FractArithmetic.h"
#include "GaussJordan.h"


int menu(FILE **in, FILE **out){
	char path[20];
	int key;
	printf("\n1- Keyboard, 2- File,3 - if u wan some jordan's mom... Else to quit>:\n");
	scanf("%d", &key);
	switch (key){
	case 1: *in = stdin; break;
	case 2: {
		printf("Put file path:\n>:");
		scanf("%s", path);
		*in = fopen(path, "r");
	}; break;
	default: printf("Error. Exiting..."); return 0;
	};
	printf("\n1- Monitor, 2- File... Else to quit \n>:");
	scanf("%d", &key);
	switch (key){
	case 1: *out = stdout; break;
	case 2: {
		printf("Put file path:\n>:");
		scanf("%s", path);
		*out = fopen(path, "w");
	}; break;
	default: printf(" Exiting..."); return 0;
	};
	return 1;

}

/*int main()
{

	frac a, b, result;
	int znak;
	int key;
	frac **A = NULL, *x = NULL;
	int N;
	FILE *in = NULL, *out = NULL;
	printf("How many equations in system? \n>:");
	scanf("%d", &N);
	if (N >= 2){
		A = GetMem(N, N + 1);
		x = (frac*)calloc(N, sizeof(frac));
		if (menu(&in, &out)){
			getFracMatr(A, N, N + 1, in);
			GaussJordan(A, N,x);
			printf("Reuslt of this shit: \n");
			for (int i = 0; i < N; i++){
				printFrac(x[i], out);
				fprintf(out,"  ");
			}
		};
		Erase(A, N, N + 1);
		free(x);
	}
	else{
		printf("Fuck you!");
	}
	fclose(in);
	fclose(out);
}*/