//Given two strings which are unsigned integer numbers (in string format)
//write an adder to add the numbers. Lenghts of both can be different.
//Misson R&D 2015 Shubham Agarwal MGIT
#include<stdio.h>
int adder(char sum[], char string_number1[], int length1, char string_number2[], int length2);
void main()
{
	char string_number1[100] , string_number2[100];
	int sum[100] = {0};
	int iterator1 = 0, iterator2 = 0, sum_length;
	printf("Enter the first number \n");
	do
	{
		string_number1[iterator1] = getchar();
		iterator1++;
	} while (string_number1[iterator1 - 1] != '\n');
	string_number1[iterator1 - 1] = '\0';
	printf("Enter the second number \n");
	do
	{
		string_number2[iterator2] = getchar();
		iterator2++;
	} while (string_number2[iterator2 - 1] != '\n');
	string_number2[iterator2 - 1] = '\0';
	sum_length=adder(sum, string_number1, iterator1 - 1, string_number2, iterator2 - 1);
	printf("The sum of the given two numbers %s and %s is \n", string_number1, string_number2);
	for (iterator2 = 0; iterator2 < sum_length; iterator2++)
		printf("%d", sum[iterator2]);
	printf("\n");
	getchar();
}
int adder(int sum[], char string_number1[], int length1, char string_number2[], int length2)
{
	int iterator, length = 0,iterator1;
	if (length1 > length2)
	{
		iterator1 = length2 - 1;
		for (iterator = length1 - 1; iterator >= (length1 - length2); iterator--)
		{
			sum[iterator+1] = sum[iterator+1] + string_number1[iterator] - 48 + string_number2[iterator1] - 48;
			if (sum[iterator+1] / 10 > 0)
			{
				sum[iterator+1] = sum[iterator+1] % 10;
				sum[iterator] = 1;
			}
			length++;
			iterator1--;
		}
		for (iterator = (length1 - length2 - 1); iterator >= 0; iterator--)
		{
			sum[iterator+1] = sum[iterator+1] + string_number1[iterator] - 48;
			if (sum[iterator+1] / 10 > 0)
			{
				sum[iterator+1] = sum[iterator+1] % 10;
				sum[iterator] = 1;
			}
			length++;
		}
	}
	else
	{
		iterator1 = length1 - 1;
		for (iterator = length2 - 1; iterator >= (length2 - length1); iterator--)
		{
			sum[iterator+1] = sum[iterator+1] + string_number1[iterator1] - 48 + string_number2[iterator] - 48;
			if (sum[iterator+1] / 10 > 0)
			{
				sum[iterator+1] = sum[iterator+1] % 10;
				sum[iterator ] = 1;
			}
			length++;
			iterator1--;
		}
		for (iterator = (length2 - length1 - 1); iterator >= 0; iterator--)
		{
			sum[iterator+1] = sum[iterator+1] + string_number2[iterator] - 48;
			if (sum[iterator+1] / 10 > 0)
			{
				sum[iterator+1] = sum[iterator+1] % 10;
				sum[iterator] = 1;
			}
			length++;
		}
	}
	return length+1;
}