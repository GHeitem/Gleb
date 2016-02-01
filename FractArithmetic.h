#ifndef _FRACT_ARITHM
#define _FRACT_ARITHM
#include <limits.h>
typedef struct
{
	int num, den;
} frac;

typedef struct
{
	int tot, num, den;
} Mfrac;
//Введем маркер пустого знаменателя, который указывает на то, что знаменатель не имеет значения. (Когда числитель равен нулю например).
#define EMPTY_DEN INT_MAX

frac add(frac, frac);
frac sub(frac, frac);
frac mul(frac, frac);
frac div(frac, frac);
#endif