#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "FractArithmetic.h"
#include "FractUtils.h"

const int ADD = 1;
const int SUB = 2;
const int MULT = 3;
const int DIV = 4;

frac mixToImp(Mfrac f)
{
	frac tmp;
	int sign;

	if (f.tot == 0){
		tmp.num = f.num;
		tmp.den = abs(f.den);
	}
	else
	{
		sign = f.tot / (abs(f.tot));
		if (f.num){
			tmp.num = sign*(abs(f.den*f.tot) + f.num);
			tmp.den = abs(f.den);
		}
		else{
			tmp.num = sign*f.tot;
			tmp.den = 1;
		}
	};
	return tmp;
}
void lcf(frac* f1, frac* f2) //Приводит к общему знаменателю
{
	if ((f1->den == f2->den) && (!f1->den || !f2->den))
	{
		return;
	}
	int d1 = f1->den;
	int d2 = f2->den;

	f1->num = f1->num * d2;
	f1->den = f1->den * d2;

	f2->num = f2->num * d1;
	f2->den = f2->den * d1;
}
int gcd(int a, int b)//Наибольший общий делитель
{
	if (b == 0)
	{
		return a;
	}

	else
	{
		return gcd(b, a % b);
	}
}
frac simplify(frac f)//Упрощение дроби
{
	int negative = (f.num*f.den < 0);

	f.num = abs(f.num);
	f.den = abs(f.den);  //!!!!!!!!

	if (f.num == 0){
		f.den = 1;
		return f;
	}
	int lpcf; // Largest Possible Common Factor максимально возможный общий множитель
	lpcf = gcd(f.den, f.num); // !!!!
	f.den /= lpcf; // !!!!!!!!!!
	f.num /= lpcf;
	if (negative)
	{
		f.num = f.num * -1;
	};

	return f;
}
int implement(frac a, frac b, int c, frac *result) //Выполняет операцию с кодом с над а и б, резуьтат записывает по указателю result. Возвращает 1 при успешном исходе

{
	switch (c)
	{
	case ADD: *result = add(a, b); break;
	case SUB: *result = sub(a, b); break;
	case MULT: *result = mul(a, b); break;
	case DIV: *result = div(a, b); break;
	default:printf("Incorrect format"); return 0;
	}
	return 1;
}
int determine(char c)
{
	switch (c)
	{
	case '+':return ADD;
	case '-':return SUB;
	case '*':return MULT;
	case '/':return DIV;
	default:return 0;
	}
};
int parse(FILE *f)
{
	char c;
	do
	{
		fscanf(f, "%c", &c);
	} while (!(determine(c) != 0) && (c != '\0') && !(feof(f)));
	return (determine(c));
};
int  scanMFrac(Mfrac *tmp, FILE *f){//Чё возвращает то ?
	int t = fscanf(f, "%d.%d", &(tmp->tot), &(tmp->num));
	if (tmp->num){//Если что-либо считалось и числитель не равен нулю, то имеет смысл считывать знаменатель.
		fscanf(f, " :%d", &(tmp->den));
		if (!tmp->den){
			tmp->den = EMPTY_DEN; //Маркер пустого знаменателя. 
		}
	};
	return t;

};
Mfrac toMix(frac f){
	Mfrac tmp;
	tmp.den = f.den;
	tmp.tot = f.num / f.den;
	tmp.num = f.num % f.den;
	return tmp;
};
void scanFrac(frac *a, FILE *in){
	Mfrac tmp;
	scanMFrac(&tmp, in);
	*a = mixToImp(tmp);
}
void printFrac(frac a, FILE *f){
	Mfrac tmp = toMix(a);
	fprintf(f, "%d.%d", tmp.tot, tmp.num);
	if (tmp.num)
		fprintf(f, ":%d", tmp.den);
	printf("  ");
}
