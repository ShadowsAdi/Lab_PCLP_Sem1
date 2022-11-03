/*
Să se scrie un program care să convertească un număr citit în cifre
romane în cifre arabe.
*/

#include <cstdio>
#include <cstring>
#include <cctype>

bool bMatchString(char sString[], int iArray[], int iLen)
{
	for (int i = 0; i < iLen; ++i)
	{
		sString[i] = toupper(sString[i]);sString[i] = toupper(sString[i]);

		if(iArray[sString[i]] == (int)NULL)
		{
			return false;
		}
	}

	return true;
}

int iApplyRules(char sString[32], int iLen)
{
	char String;
	char PreString;
	int iPos = 0;

	for(int i = 1; i < iLen; i++)
	{
		String = sString[i];
		
		PreString = sString[i - 1];
		
		if((String == 'M' || String == 'D') && PreString == 'C')
		{
			iPos += 200;
		}
		
		if((String == 'L' || String == 'C') && PreString == 'X')
		{
			iPos += 20;
		}
		
		if((String == 'V' || String == 'X') && PreString == 'I')
		{
			iPos += 2;
		}
	}
	
	return iPos;
}

bool bAllow(char cChar, char cPre, char cAntePre, char cPost)
{
	static int sCounter['x' + 1];
	
	if(cChar == 'I' || cChar == 'X' || cChar == 'C')
	{
		sCounter[cChar]++;
		
		if(sCounter[cChar] > 3)
		{
			return false;
		}
	}
	
	if(cChar == 'V' || cChar == 'L' || cChar == 'D')
	{
		sCounter[cChar]++;
		
		if(sCounter[cChar] > 1)
		{
			return false;
		}
	}

	if(cPre == 'V' && (cChar == 'X' || cChar == 'L' || cChar == 'C' || cChar == 'D' || cChar == 'M')
	|| cPre == 'L' && (cChar == 'C' || cChar == 'D' || cChar == 'M')
	|| cPre == 'D' && cChar == 'M'
	|| cPre == 'X' && (cChar =='D' || cChar == 'M'))
	{
		return false;
	}

	if(cAntePre == 'I' && cPre == 'I')
	{
		return false;
	}
	
	return true;
}

int main()
{
	// https://www.rapidtables.com/code/text/ascii-table.html#table
	// ( X = 88 ) < ( x = 120 )
	int sArray['x' + 1] = {NULL};

	char sString[32];

	scanf("%s", &sString);

	int iNumar = 0;
	int len = strlen(sString);

	sArray['I'] = 1;
	sArray['V'] = 5;
	sArray['X'] = 10;
	sArray['L'] = 50;
	sArray['C'] = 100;
	sArray['D'] = 500;
	sArray['M'] = 1000;

	if(!bMatchString(sString, sArray, len))
	{
		printf("Insert only roman valid characters!\n");
		return 0;
	}

	int iPre = 0, iPost, iIterator = 0;
	int i = len - 1;
	
	do
	{
		iPost = sArray[sString[i]];
		
		iIterator = iPost >= iPre ? 1 : -1;
		
		iNumar = bAllow(sString[i], sString[i - 1], sString[i - 2],
		sString[i + 1]) == true ? iNumar +  iPost : iNumar = -1;
		iPre = iPost;
		i--;
	}
	while(i >= 0 && iNumar != -1);
	
	printf("Roman Number: %s \nInteger Number: %d%s\n", sString, iNumar != -1 ? (iNumar - iApplyRules(sString, len)) : NULL, iNumar == -1 ? " - Doesn't exist" : "");

	return 0;
}