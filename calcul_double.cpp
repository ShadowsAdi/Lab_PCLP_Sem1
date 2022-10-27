#include <iostream>
#include <math.h>

int main()
{
	double x, y;

	scanf("%lf", &x);

	scanf("%lf", &y);

	printf("\nCalculated \"%lf\" to power \"%lf\": %lf", x, y, pow(x, y));

	return 0;
}