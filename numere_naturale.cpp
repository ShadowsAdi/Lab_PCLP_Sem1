/*
Să se scrie un program care verifică dacă trei numere naturale pot fi 
laturile unui triunghi; în caz afirmativ se va preciza tipul triunghiului: isoscel, 
dreptunghiular, echilateral sau oarecare.
*/

#include <math.h>
#include <cstdio>

int LaturaMare(int *Laturi);
int CalcLaturi(int *Laturi);

enum
{
	ISOSCEL = 1,
	DREPT,
	ECHIL,
	OARECARE
};

int main()
{
	// Introducem doar numere naturale
	int iLaturi[3];
	
	for(int i = 0; i < 3; i++)
	{
		_again:
		printf("Introduceti latura numarul %d:\n", i + 1);
		scanf("%d", &iLaturi[i]);
		
		if(0 > iLaturi[i])
		{
			printf("Introduceti doar numere pozitive!\n");
			goto _again;
			break;
		}
	}
	
	int temp = CalcLaturi(iLaturi);
		
	switch(temp)
	{
		case ISOSCEL:
		{
			printf("Triunghiul este isoscel!\n");
			break;
		}
		case DREPT:
		{
			printf("Triunghiul este dreptunghic!\n");
			break;
		}
		case ECHIL:
		{
			printf("Triunghiul este echilateral!\n");
			break;
		}	
		default:
		{
			printf("Triunghiul este oarecare!\n");
		}
	}
		
	return 0;
}

int CalcLaturi(int *Laturi)
{	
	if(Laturi[0] == Laturi[1] && Laturi[1] == Laturi[2])
	{
		return ECHIL;
	}

	if(int temps = LaturaMare(Laturi))
	{
		int iSuma = 0;

		for(int i = 0; i < 3; i++)
		{
			if(temps == i)
				continue;

			iSuma += static_cast<int>(pow(Laturi[i], 2));
		}
		
		int temp = Laturi[temps] * Laturi[temps];
				
		if(temp == iSuma)
			return DREPT;
	}

	if(Laturi[0] == Laturi[1] || Laturi[1] == Laturi[2] || Laturi[0] == Laturi[2])
	{
		return ISOSCEL;
	}
	
	return OARECARE;
}

int LaturaMare(int *Laturi)
{
	int iTemp = 0;
	int iIterator;
	for(int i = 0; i < 3; i++)
	{
		if(Laturi[i] > iTemp)
		{
			iTemp = Laturi[i];
			iIterator = i;
		}
	}
	
	return iIterator;
}