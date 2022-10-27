/*
Să se scrie un program pentru afişarea unui întreg citit de la tastatură în
octal, hexazecimal şi binar.
*/

#include <cstdio>
#include <cstring>

void decToBinary(int n, char *test);

int main()
{
	int nr;
	int binaryNum[32];
    char *test;

	scanf("%d", &nr);

    decToBinary(nr, test);

	printf("\nNumarul \"%d\" in format octal \"%o\", hexazecimal \"0x%04x\", binar \"%s\"", nr, nr, nr, test);

	return 0;
}

void decToBinary(int n, char *test)
{
    int i = 0;
    int binaryNum[32];
    int c = 0;

    while (n > 0) 
    {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        sprintf(test, "%s%d", c != 0 ? test : "", binaryNum[j]);
        //printf("%d", binaryNum[j]);
        c++;
    }
}