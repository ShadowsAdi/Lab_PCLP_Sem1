/*
De la tastatură sunt citite elementele reale ale unui şir de dimensiunea n.
Să se găsească valoarea minimă şi valoarea maximă dintre elementele şirului şi
poziţia lor.
*/

#include <cstdio>
#include <cctype>

int main()
{
	int n;

	printf("Introduceti dimensiunea sirului!\n");

	scanf("%d", &n);

	if(isdigit(n) < 0 || n < 0)
	{
		printf("Introduceti dimensiunea mai mare decat \"0\"\n");
		return 0;
	}

	int iNumere[n];

	for (int i = 0; i < n; i++)
	{
		printf("Introduceti elementul cu numarul \"%d\" al sirului\n", i + 1);
		scanf("%d", &iNumere[i]);
	}
	
	int iNumar, temp, k;

	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < i; k++)
		{
			if(iNumere[k] < iNumere[i]) k++;
			else
			{
				temp = iNumere[i];
				iNumere[i] = iNumere[k];
				iNumere[k] = temp;
			}

		}
	}

	printf("Valoare minima a sirului: %d in pozitia: %d.\nValoare maxima: %d in pozitia %d\n", iNumere[0], 1, iNumere[n - 1], n);

	return 0;
}