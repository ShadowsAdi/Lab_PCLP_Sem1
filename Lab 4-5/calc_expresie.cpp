/*
Folosind expresii condiţionale, să se scrie un program care citeşte
valoarea reală a lui x şi calculează valoarea funcţiei:
*/

#include <cstdio>
#include <math.h>

int main()
{
	double x;

	double fx;

	double expresie;

	scanf("%lf", &x);

	if(x <= -2)
	{
		fx = pow(x, 2) + (4*x) + 4;
	}
	else if(x == 0)
	{
		fx = 0;
	}
	else if( x > -2)	
	{
		fx = (x * x) + (5 * x);
	}

	printf("calc: %d", static_cast<int>(fx));

	return 0;
}