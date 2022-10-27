/*Să se scrie un program care citeşte un unghi în grade şi calculează
valoarea funcţiei sinus, cosinus şi tangentă.*/

#include <iostream>
#include <math.h>

void CalcGrade(double grade, double &res_sin, double &res_cos, double &res_tan);

int main(int argc, char const *argv[])
{
	double grade, res_sin, res_cos, res_tan;

	scanf("%lf", &grade);

	CalcGrade(grade, res_sin, res_cos, res_tan);

	printf("\nGrade: %lf | Sin: %lf | Cos: %lf | Tan: %lf", grade, res_sin, res_cos, res_tan);

	return 0;
}

void CalcGrade(double grade, double &res_sin, double &res_cos, double &res_tan)
{
	res_sin = sin(grade);

	res_cos = cos(grade);

	res_tan = tan(grade);
}