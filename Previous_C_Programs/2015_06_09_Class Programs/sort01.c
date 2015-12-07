#include<stdio.h>
void sort01(int arr[],int n);
void main()
{
	int arr[100], iterator, n_val, n;
	printf("Enter array size\n");
	scanf_s("%d", &n);
	printf("Enter the array elements only 0's and 1's\n");
	for (iterator = 0; iterator < n; iterator++)
		scanf_s("%d", &arr[iterator]);
	sort01(arr, n);
}
void sort01(int arr[], int n)
{
	int count0 = 0,iterator;
	for (iterator = 0; iterator < n; iterator++)
	{
		if (arr[iterator] == 0)
			count0++;
	}
	for (iterator = 0; iterator < count0; iterator++)
		arr[iterator] = 0;
	for (iterator = count0; iterator < n; iterator++)
		arr[iterator] = 1;
	printf("\n");
	for (iterator = 0; iterator < n; iterator++)
		printf("%d ", arr[iterator]);
	printf("\n");
}
	