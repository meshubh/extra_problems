//An unsigned number Q is formed by taking input P which is an unsigned integer in string format, 
//K: number of times P repeated to form Q. 
//write a function to find whether the number Q is divisible by 3 or not
//Misson R&D 2015 Shubham Agarwal MGIT
#include<stdio.h>
int divisible_by_3(char[], int, int);
void main()
{
	char string_number[10000];
	int iterator = 0, result, repeat_number;
	printf("Enter the number\n");
	do
	{
		string_number[iterator] = getchar();
		iterator++;
	} while (string_number[iterator - 1] != '\n');
	string_number[iterator - 1] = '\0';
	printf("Enter number of times the number should be repeated\n");
	scanf_s("%d", &repeat_number);
	result = divisible_by_3(string_number, iterator - 1, repeat_number);
	if (result == 1)
	{
		printf("The given number ");
		for (iterator = 0; iterator < repeat_number; iterator++)
			printf("%s", string_number);
		printf(" is divisble by 3");
	}
	else
	{
		printf("The given number ");
		for (iterator = 0; iterator < repeat_number; iterator++)
			printf("%s", string_number);
		printf(" is not divisble by 3");
	}
	getchar();
	getchar();
}
int divisible_by_3(char number[], int length, int repeat_number)
{
	int sum = 0, iterator1, final_sum;
	for (iterator1 = 0; iterator1 < length; iterator1++)
	{
			sum += number[iterator1] - 48;
	}
	final_sum = (sum*repeat_number);
	if (final_sum % 3 == 0)
		return 1;
	else
		return 0;
}