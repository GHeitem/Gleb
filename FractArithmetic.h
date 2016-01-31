#ifndef _FRACT_ARITHM
#define _FRACT_ARITHM
typedef struct
{
	int num, den;
} frac;

typedef struct
{
	int tot, num, den;
} Mfrac;

frac add(frac, frac);
frac sub(frac, frac);
frac mul(frac, frac);
frac div(frac, frac);
#endif