//Program for multiplication without using multiplication(*) and addition(+) operators
//Shubham Agarwal MGIT 2015 MissionRnD
#include<stdio.h>
int bitwiswe_Addition(int num1, int num2);
int main()
{
	int num1, num2, output = 0, iterator;
	printf("Enter 1st and 2nd number respectively \n");
	scanf_s("%d%d", &num1, &num2);
	for (iterator = 0; iterator <num2; iterator++)
		//Adding num1 to itself, num2 times
		output = bitwise_Addition(output, num1);
	printf("product of %d and %d is %d \n", num1, num2, output);
}
//Addition using bitwise operator function
int bitwise_Addition(int num1, int num2)
{
	int carry;
	while (num2 != 0)
	{
		carry = (num1&num2) << 1;//calculating the carry and perform a lift shift to carry
		num1 = num1^num2; //calculating the sum
		num2 = carry;
	}
	return num1;
}