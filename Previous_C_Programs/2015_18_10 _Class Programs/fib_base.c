//convert a number to binary having base as fibnocii series
//Shubham Agarwal Mission R&D 2015 MGIT
#include<stdio.h>
void conv_to_best_fib_bin(int);
void main()
{
	int num;
	printf("Enter the number \n");
	scanf_s("%d", &num);
	conv_to_best_fib_bin(num);
	getchar();
	getchar();
}
void conv_to_best_fib_bin(int num)
{
	int n1 = 0, n2 = 1, n3 = 1, sum = 0, temp, i = 0, j, iterator, a[100] = { 0 };
	while (sum < num)
	{
		sum = sum + n3;
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
		i++;
	}
	i--;
	j = i;
	a[i] = 1;
	i--;
	n3 = n1;
	temp = n2;
	n2 = n1;
	n1 = temp - n1;
	num = num - n3;
	while (num > 0)
	{
		n3 = n1;
		temp = n2;
		n2 = n1;
		n1 = temp - n1;
		if (num >= n3)
		{
			num = num - n3;
			a[i] = 1;
			i--;
		}
		else
		{
			a[i] = 0;
			i--;
		}
	}
	if (a[1] == 1 && a[0] == 0)
	{
		a[1] = 0;
		a[0] = 1;
	}
	for (iterator = j; iterator >= 0; iterator--)
	{
		if (a[iterator] == 1 && a[iterator - 1] == 0 && a[iterator - 2] == 0 && iterator > 1)
		{
			a[iterator] = 0;
			a[iterator - 1] = 1;
			a[iterator - 2] = 1;
		}
	}
	if (a[1] == 1 && a[0] == 0)
	{
		a[1] = 0;
		a[0] = 1;
	}
	for (iterator = j; iterator >= 0; iterator--)
	{
		printf("%d ", a[iterator]);
	}
	printf("\n");
}