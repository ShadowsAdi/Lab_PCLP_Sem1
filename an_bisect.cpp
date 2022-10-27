/*
Să se scrie un program care citeşte un număr natural ce reprezintă un an
şi verifică dacă este bisect sau nu.
*/

#include <iostream>

int main(int argc, char const *argv[])
{
	int year;

	while(1)
	{
		scanf("%d", &year);

		if(year == 112)
		{
			printf("\nIesire program");
			break;
		}

		printf("\nAnul introdus %seste bisect\n", ((year % 4) == 0) ? "" : "nu ");
	}
		
	return 0;
}