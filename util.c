/*
* util.c
*
* Created: 15/04/2019 4:00:39 AM
*  Author: liam
*/

#include "util.h"

int int_pow(int base, int exp) {
	int result = 1;
	while (exp)
	{
		if (exp & 1)
		result *= base;
		exp /= 2;
		base *= base;
	}
	return result;
}