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
	int sign,tmp1;
	/*if ((f.tot || f.den || f.num ) < 0)
	{
		sign = -1;
	}
	if (((f.tot&&f.den) || (f.den&&f.num) || (f.tot&&f.num) < 0) || ((f.tot&&f.den&&f.num) < 0))
	{
		sign = 1;
	}
	if ((f.tot || f.den || f.num) >= 0)
	{
		sign = 1;
	}*/
	/*tmp1 = f.tot*f.num*f.den;//если чтото из них ноль
	if (tmp1 < 0)
	{
		
	}
	else
	{
		sign = 1;
	}*/

	if 

	tmp.num =sign*(f.num);//а что если числитель уже с минусом?, всё похерится, надо чёто другое придумать
	tmp.den = f.den;
	return simplify(tmp);
}
void lcf(frac* f1, frac* f2) //Приводит к общему знаменателю
{
	if (f1->den == f2->den)
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
	int negative = (f.num*f.den<0);

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
	} while (!(determine(c) != 0) && (c != '\0')&&!(feof(f)));
	return (determine(c));
};
int  scanMFrac(Mfrac *tmp,FILE *f){//Чё возвращает то ?

	int t = fscanf(f, "%d.%d:%d", &(tmp->tot), &(tmp->num), &(tmp->den));
	if ((tmp->num||tmp->den)==0)
	{
		printf("Sike! That's tho rong number!");
			return 0;
	}
	return t;// int ретёрнится, где дробь Mfrac?

};
Mfrac toMix(frac f){
	Mfrac tmp;
	tmp.den = f.den;
	tmp.tot =f.num / f.den;
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
	fprintf(f,"%d.%d", tmp.tot, tmp.num);
	if (tmp.num)
	fprintf(f, ":%d", tmp.den);
	printf("  ");
}
