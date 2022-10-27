/*
Să se scrie un program care să convertească un număr citit în cifre
romane în cifre arabe.
*/

#include <cstdio>
#include <cstring>

int main()
{
	// https://www.rapidtables.com/code/text/ascii-table.html#table
	// ( X = 88 ) < ( x = 120 )
	int sArray['x' + 1];

	char sString[32];

	int iNumar = 0;

	scanf("%s", &sString);

	int len = strlen(sString);

    sArray['i', 'I'] = 1;
    sArray['v', 'V'] = 5;
    sArray['x', 'X'] = 10;
    sArray['l', 'L'] = 50;
    sArray['c', 'C'] = 100;
    sArray['D', 'd'] = 500;
    sArray['M', 'm'] = 1000;

    // XCIX

    int iPre = 0, iPost, iIterator = 0;
    int i = len - 1;
    do
    {
        iPost = sArray[sString[i]];
        
        iIterator = iPost >= iPre ? 1 : -1;

        iNumar += iIterator * iPost;
        iPre = iPost;
        i--;
    } 
    while(i >= 0);
	
	printf("Numar roman: %s \nNumar decimal: %d\n", sString, iNumar);

	return 0;
}