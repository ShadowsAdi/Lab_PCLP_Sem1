/*
Să se scrie un program care să convertească un număr citit în cifre
romane în cifre arabe.
*/

#include <cstdio>
#include <cstring>

int main()
{
	char sString[32];
	int iNumar = 0;

	scanf("%s", &sString);

	int len = strlen(sString);

	for (int i = 0; i < len; i++)
	{
		if(sString[i] == 'M')
		{
			iNumar += 1000;
		}
		else if(sString[i] == 'D')
		{
			iNumar += 500;
		}
		else if(sString[i] == 'C')
		{
			iNumar += 100;
		}
		else if(sString[i] == 'L')
		{
			iNumar += 50;
		}
		else if(sString[i] == 'X')
		{
			iNumar += 10;
		}
		else if(sString[i] == 'V')
		{
			iNumar += 5;
		}
		else if(sString[i] == 'I')
		{
			iNumar += 1;
		}
	}
	
	printf("Numar roman: %s \nNumar decimal: %d\n", sString, iNumar);

	return 0;
}
