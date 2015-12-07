#include<stdio.h>
int adder(int sum[], char string_number1[], char string_number2[]);
void main()
{
	char string_number1[100], string_number2[100];
	int sum[100] = { 0 };
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
	sum_length = adder(sum, string_number1, string_number2);
	for (iterator1 = 0; iterator1 < sum_length; iterator1++)
		printf("%d", sum[iterator1]);
	getchar();
	getchar();
}
int adder(int sum[], char str1[], char str2[])
{
	int iterator1, iterator2, iterator3;
	for (iterator1 = 0; str1[iterator1] != '\0'; iterator1++)
	{
		if ((str1[iterator1] - 48 + str2[iterator1] - 48) < 9)
		{
			iterator2 = iterator1;
			sum[iterator1] = (str1[iterator1] - 48 + str2[iterator2] - 48);
		}
		else if ((str1[iterator1] - 48 + str2[iterator1] - 48) > 9)
		{
			sum[iterator1] = (str1[iterator1] - 48 + str2[iterator2] - 48)%10;
			sum[iterator2] = sum[iterator2] + 1;
			for (iterator3 = iterator1; iterator3 > iterator2; iterator3--)
			{
				sum[iterator3] = 0;
			}
			iterator2 = iterator1;
		}
	}
	return iterator1;
}