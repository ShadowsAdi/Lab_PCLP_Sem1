#include <iostream>
#include <cstring>

void Convert(char string[32]);

int main()
{
	char string[32];

	scanf("%s", string);

	printf("\n String before: %s", string);

	Convert(string);

	printf("\n String after: %s", string);

	return 0;
}

void Convert(char string[32])
{	
	for (int i = 0; i < strlen(string); ++i)
	{
		string[i] -= 32;
	}
}