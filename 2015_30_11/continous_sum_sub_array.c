
#include<stdio.h>
void subarray(int a[], int size)
{

	int startIndex = 0, endIndex = 0;
	int iterator;
	int currStartIndex = 0;
	int maxSum = 0;
	int currentSum = 0;
	for (iterator = 0; iterator < size; iterator++)
	{
		currentSum = currentSum + a[iterator];
		if (currentSum > maxSum)
		{
			maxSum = currentSum;
			endIndex = iterator;
			startIndex = currStartIndex;
		}

		if (currentSum <= 0)
		{
			currStartIndex = iterator + 1;
			currentSum = 0;
		}
	}
	printf("\nMaximum Sum : %d", maxSum);
	printf("\nThe sub array is as follows \n");
	for (iterator = startIndex; iterator <= endIndex; iterator++)
		printf("%d\t", a[iterator]);
	printf("\n");
}

void main() 
{	
	int Arr[100], size,iterator;
	printf("Enter the size of the array \n");
	scanf_s("%d", &size);
	printf("Enter the array elements\n");
	for (iterator = 0; iterator < size; iterator++)
		scanf_s("%d", &Arr[iterator]);
	subarray(Arr,	size);
}