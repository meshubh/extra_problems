#include <stdio.h>
int print_words(char[], char[][100], int);
void main()
{
	char string[500], array_output[100][100];
	int iterator = 0, output_array_size;
	printf("Enter the string \n");
	do
	{
		scanf_s("%c", &string[iterator]);
		iterator++;
	} while (string[iterator - 1] != '\n');
	string[iterator-1] = '\0';
	output_array_size = print_words(string, array_output, iterator);
	printf("[");
	for (iterator = 0; iterator < output_array_size; iterator++)
		printf("%s,", array_output[iterator]);
	printf("%s]", array_output[iterator]);
	getchar();
}
int print_words(char string[], char array_output[][100], int size)
{
	int iterator1 = 0, iterator2 = 0, position = 0, iterator3 = 0;
	while (string[iterator3] != '\0')
	{
		if (string[iterator3] != ' ')
		{
			array_output[iterator1][iterator2] = string[iterator3];
			iterator2++;
		}
		else
		{
			array_output[iterator1][iterator2] = '\0';
			iterator1++;
			iterator2 = 0;
		}
		iterator3++;
	}
	array_output[iterator1][iterator2] = '\0';
	return iterator1;
}