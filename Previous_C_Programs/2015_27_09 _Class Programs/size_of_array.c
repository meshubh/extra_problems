#include<stdio.h>
int check(int arr[]);
void main()
{
	int arr[10], iterator, n_val;
	printf("Enter the array elements \n");
	for (iterator = 0; iterator < 10; iterator++)
		scanf_s("%d", &arr[iterator]);
	n_val=check(arr);
	if (n_val == 0)
		printf("Array given is incorrect \n");
	else
		printf("The value of n is %d \n", n_val);
	getchar();
	getchar();
	getchar();
}
int check(int arr[])
{
	int iterator = 0, max, x = 0;
	while (arr[iterator] != 0)
	{
		iterator = iterator + pow(2, x);
		x++;
	}
	while(arr[iterator] == 0 && arr[iterator - 1] == 0)
	{
		max = iterator;
		x--;
		iterator = iterator - pow(2, x);
		x = 0;
		iterator = iterator + pow(2, x);
		x++;
		while (iterator < max)
		{
			if (arr[iterator] == 0)
				break;
			else
			{
				iterator = iterator + pow(2, x);
				x++;
			}
		}
	}
	return iterator - 2;
}
int pow(int num1, int num2)
{
	int iterator,result=1;
	if (num2 == 0)
		return 1;
	else
	{
		for (iterator = 1; iterator <= num2; iterator++)
			result = result * 2;
	}
	return result;
}
