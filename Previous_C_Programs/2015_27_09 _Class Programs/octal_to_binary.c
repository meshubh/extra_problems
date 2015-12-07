//Octal to binary conversion
//Shubham Agarwal Mission RnD 2015
#include<stdio.h>
int BintoOctal(int binum[],int length,int octnum[]);
void main()
{
	int binnum[10000],length,iterator, octnum[100] = { 0 }, iterator1;
	printf("Enter the length of binary number \n");
	scanf_s("%d", &length);
	printf("Enter the Binary number\n");
	for (iterator1 = 0; iterator1 < length; iterator1++)
	scanf_s("%d", &binnum[iterator1]);
	iterator=BintoOctal(binnum,length,octnum);
	printf("Octal equivalent = ");
	for (iterator1 = iterator - 1; iterator1 >= 0; iterator1--)
		printf("%d", octnum[iterator1]);
	getchar();
	getchar();
}
int BintoOctal(int binnum[],int length,int octnum[])
{
	int z = 1, num = 0, iterator = 0, rem, count = 0, iterator1 = length - 1;
	while (iterator1 >= 0)
	{
		rem = binnum[iterator1];
		num = num + (rem*z);
		z = z * 2;
		count++;
		iterator1--;
		if (count == 3)
		{
			octnum[iterator] = num;
			iterator++;
			num = 0;
			count = 0;
			z = 1;
		}
	}
		if (num > 0)
		{
			octnum[iterator] = num;
			iterator++;
		}
		printf("\n");
	return iterator;
}