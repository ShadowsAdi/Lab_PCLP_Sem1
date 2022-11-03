/*
Să se scrie un program pentru generarea tuturor numerelor prime mai
mici sau egale cu un număr natural n.
*/

#include <cstdio>
#include <math.h>

const char *sFile = "numere_prime.txt";

int main()
{
	int iNumar;

	// 0 si 1 nu sunt numere prime
	int iMin = 2;

	scanf("%d", &iNumar);

	int i = 0;
	int iPrime = 0;

	char *sString = NULL;
	sString = new char[static_cast<int>(pow(1024, 2))];
	int iCounter = 0;

	FILE *pFile;

	pFile = fopen(sFile, "w+");

	if(pFile == NULL)
	{
		printf("Nu am putut deschide fisierul \"%s\"", sFile);
		return 0;
	}

	while(iMin < iNumar)
	{
		int iPrime = 0;

		for (i = 2; i <= iMin/2; i++) 
		{
			if (iMin % i == 0)
			{
				iPrime = 1;
				break;
			}
		}
	
		if(!iPrime)
		{
			sprintf(sString, "%s%s%d", iCounter != 0 ? sString : "", iCounter > 0 ? ", " : "", iMin);
			iCounter++;
		}

		iMin++;
	}

	fprintf(pFile, "Numere prime intre \"1\" si \"%d\": %s\n", iNumar, sString);

	fclose(pFile);

	delete[] sString;

	return 0;
}