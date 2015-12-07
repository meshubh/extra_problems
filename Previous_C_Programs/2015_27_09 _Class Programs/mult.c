//Input 2 arrays convert to binary to form large nmber then multiply the large numbers and return the product in the form of an array
//Shubham Agarwal MGIT Mission R&D 2015
#include<stdio.h>
void continous_conv_to_binary(int, int[], int);
int multiply(int bin1[], int size1, int bin2[], int size2, int finbin[][480]);
void conv_to_decimal(int[], int, int, int[]);
int pow_2(int index);
void main()
{
	int size1, size2, row, array1[10], array2[5], resultarr[15], bin1[320] = { 0 }, bin2[160] = { 0 }, finbin[160][480] = { 0 }, iterator;
	printf("Enter the size of first array that should be less than or equal to 10\n");
	scanf_s("%d", &size1);
	printf("Enter array1 elements\n");
	for (iterator = 0; iterator < size1; iterator++)
		scanf_s("%d", &array1[iterator]);
	printf("Enter the size of second array that should be less than or equal to 5\n");
	scanf_s("%d", &size2);
	printf("Enter array2 elements\n");
	for (iterator = 0; iterator < size2; iterator++)
		scanf_s("%d", &array2[iterator]);
	for (iterator = 0; iterator < size1; iterator++)
		continous_conv_to_binary(array1[iterator], bin1, size1 - iterator);
	for (iterator = 0; iterator < size2; iterator++)
		continous_conv_to_binary(array2[iterator], bin2, size2 - iterator);
	row = multiply(bin1, size1, bin2, size2, finbin);
	conv_to_decimal(finbin, size1 + size2, row, resultarr);
	for (iterator = 0; iterator < size1 + size2; iterator++)
		printf("%d\t", resultarr[iterator]);
	printf("\n");
	getchar();
	getchar();
}
void continous_conv_to_binary(int num, int bin[], int size)
{
	int iterator2 = 0;
	iterator2 = (32 * size) - 1;
	while (num>0)
	{
		bin[iterator2] = num % 2;
		iterator2--;
		num = num / 2;
	}
}
int multiply(int bin1[], int size1, int bin2[], int size2, int finbin[][480])
{
	int iterator1, iterator, iterator2, iterator3 = 0, iterator4, iterator5, count = 0, size, addrow1 = 0, addrow2 = 0;
	size = size1 + size2;
	iterator5 = size2 * 32 - 1;
	for (iterator1 = 0; iterator1 < size2 * 32; iterator1++)
	{
		iterator3 = (size * 32) - iterator1 - 1;
		if (count == 2)
		{
			for (iterator4 = (size * 32) - 1; iterator4 >= size2 + iterator1; iterator4--)
			{
				finbin[addrow1][iterator4] = finbin[addrow1][iterator4] + finbin[addrow2][iterator4];
				if (finbin[addrow1][iterator4] == 2)
				{
					finbin[addrow1][iterator4] = 0;
					finbin[addrow1][iterator4 - 1] = finbin[addrow1][iterator4 - 1] + 1;
				}
				else if (finbin[addrow1][iterator4] == 3)
				{
					finbin[addrow1][iterator4] = 1;
					finbin[addrow1][iterator4 - 1] = finbin[addrow1][iterator4 - 1] + 1;
				}
			}
			count = 1;
		}
		if (bin2[iterator5] == 1)
		{
			count++;
			for (iterator2 = size1 * 32 - 1; iterator2 >= 0; iterator2--)
			{
				finbin[iterator1][iterator3] = bin1[iterator2];
				iterator3--;
			}
			if (count == 1)
				addrow1 = iterator1;
			else
				addrow2 = iterator1;
		}
		iterator5--;
	}
	return addrow1;
}
void conv_to_decimal(int finbin[][480], int size, int row, int resultarr[])
{
	int iterator, iterator1 = 0, iterator2, num = 0;
	for (iterator2 = 0; iterator2 < size; iterator2++)
	{
		for (iterator = (size - iterator1) * 32 - 1; iterator >= (size - iterator1 - 1) * 32; iterator--)
		{
			if (finbin[row][iterator] == 1)
			{
				num = num + pow_2((31 - iterator % 32));
			}
		}
		resultarr[iterator1] = num;
		iterator1++;
		num = 0;
	}
}
int pow_2(int index)
{
	int iterator, result = 1;
	for (iterator = 1; iterator <= index; iterator++)
		result = result * 2;
	return result;
}