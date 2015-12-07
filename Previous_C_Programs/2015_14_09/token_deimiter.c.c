#include <stdio.h>
int print_tokens(char[], char[][100], char);
void main()
{
	char string[500], output_array[100][100];
	char delimiter;
	int iterator = 0, limit;
	printf("Enter the string \n");
	do
	{
		string[iterator] = getchar();
		iterator++;
	} while (string[iterator-1] != '\n');
	string[iterator - 1] = '\0';
	printf("Enter the delimiter token \n");
	delimiter = getchar();
	limit = print_tokens(string, output_array, delimiter, iterator);
	printf("[");
	for (iterator = 0; iterator < limit; iterator++)
		printf("%s", output_array[iterator]);
	printf("%s]", output_array[iterator]);
	getchar();
	getchar();
}
int print_tokens(char string[], char output_array[][100], char delimiter)
{
	int iterator, iterator2 = 0, iterator1 = 0;
	for (iterator = 0; string[iterator] != '\0'; iterator++)
	{
		if (string[iterator] != delimiter)
		{
			output_array[iterator1][iterator2] = string[iterator];
			iterator2++;
		}
		else
		{
			output_array[iterator1][iterator2] = '\0';
			iterator1++;
			iterator2 = 0;
		}
	}
	output_array[iterator1][iterator2] = '\0';
	return iterator1;
}