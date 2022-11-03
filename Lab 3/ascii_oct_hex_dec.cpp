#include <iostream>
#include <cstring>

void PrintDecimal(char string[32]);

void PrintOctal(char string[32]);

void PrintHexa(char string[32]);

int main()
{
	char string[32];

	scanf("%s", string);

	printf("\n Caracterele ASCII al stringului \"%s\" sunt:");

	PrintDecimal(string);

	PrintOctal(string);

	PrintHexa(string);

	return 0;
}

void PrintDecimal(char string[32])
{
	printf("\n Decimal:");
	for (int i = 0; i < strlen(string); i++)
	{
		printf("\n%d", string[i]);
	}
}

void PrintOctal(char string[32])
{
	printf("\n Octal:");

	for (int i = 0; i < strlen(string); i++)
	{
		printf("\n%04o", string[i]);
	}
}

void PrintHexa(char string[32])
{
	printf("\n Hexa:");

	for (int i = 0; i < strlen(string); i++)
	{
		printf("\n0x%04x", string[i]);
	}
}