// Given a unsigned number as a string input  write a function to find whether the number is divisible by 11 or not
//Misson R&D 2015 Shubham Agarwal MGIT
#include<stdio.h>
int divisible_by_11(char[], int);
void main()
{
	char string_number[10000];
	int iterator = 0,result;
	printf("Enter the number\n");
	do
	{
		string_number[iterator] = getchar();
		iterator++;
	} while (string_number[iterator - 1] != '\n');
	string_number[iterator - 1] = '\0';
	result= divisible_by_11(string_number, iterator - 1);
	if (result == 1)
		printf("The given number %s is divisble by 11", string_number);
	else
		printf("The given number %s is not divisible by 11",string_number);
	getchar();
}
int divisible_by_11(char number[], int length)
{
	int sum_of_even = 0, sum_of_odd = 0, iterator1 ,difference;
	for (iterator1 = 0; iterator1 < length; iterator1++)
	{
		if (iterator1 % 2 == 0)
			sum_of_odd += number[iterator1]-48;
		else
			sum_of_even += number[iterator1]-48;
	}
	difference = sum_of_odd - sum_of_even;
	if (difference % 11 == 0)
		return 1;
	else
		return 0;
}
