#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "FractUtils.h"
#include "FractArithmetic.h"
/*
int menu(FILE **in, FILE **out){
	char path[20] = "D:\\test.txt";
	int key;
	printf("\n1- Keyboard, 2- File:>");
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

}*/

int main()
{

	frac a, b;
	frac c;
	FILE *in = NULL, *out = NULL;
	in = stdin;
	out = stdout;

	printf("1frac: >");
	scanFrac(&a, in);
	printFrac(a, out);
	
	/*printf("\n2frac: >");
	scanMFrac(&b, in);
	
	printf("Result: >");
	c = add(mixToImp(a),mixToImp(b));*/

	

	getchar();
	getchar();

}