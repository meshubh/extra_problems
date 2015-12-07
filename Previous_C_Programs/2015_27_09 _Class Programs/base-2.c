//Base -2 Binary form
//Shubham Agarwal Mission RnD 2015
#include<stdio.h>
int base_negative_2(int number, int arr[]);
void main()
{
	int number,arr[100],size,iterator;
	printf("Enter the number \n");
	scanf_s("%d", &number);
	size=base_negative_2(number, arr);
	for (iterator = 0; iterator < size; iterator++)
		printf("%d", arr[iterator]);
	printf("\n");
	getchar();
	getchar();
}
int base_negative_2(int number,int arr[])
{
	int rem, quot,iterator=0;
	while (number != 0)
	{
		rem = number % (-2);
		number = number / (-2);
		if (rem == -1)
		{
			number = number + 1;
			rem = 1;
			arr[iterator] = rem;
			iterator++;
		}
		else
		{
			arr[iterator] = rem;
			iterator++;
		}
	}
	return iterator;
}