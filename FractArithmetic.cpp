#include "FractArithmetic.h"
#include "FractUtils.h"
frac add(frac f1, frac f2) //+
{
	lcf(&f1, &f2);

	f1.num = f1.num + f2.num;

	return f1;
}
frac sub(frac f1, frac f2) //-
{
	lcf(&f1, &f2);

	f1.num = f1.num - f2.num;

	return f1;
}
frac mul(frac f1, frac f2) //*
{
	f1.num = f1.num * f2.num;
	f1.den = f1.den!=EMPTY_DEN?f1.den * f2.den:EMPTY_DEN;

	return f1;
}
frac div(frac f1, frac f2) //%
{
	f1.num = f1.num * f2.den;
	f1.den = f1.den * f2.num;

	return f1;
}
