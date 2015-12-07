#include <stdio.h>
void merge_sort(int arr[], int min, int max);
void merge(int arr[], int min, int mid, int max);
main()
{
	int size, array[100], iterator;
	printf("Enter array size \n");
	scanf_s("%d", &size);
	printf("Enter array elements \n");
	for (iterator = 0; iterator <size; iterator++)
		scanf_s("%d", &array[iterator]);
	merge_sort(array, 0, size - 1);
	printf("The maximum number in given list is %d and the minimum number is %d", array[size - 1], array[0]);
	getchar();
	getchar();
}
void merge_sort(int arr[], int min, int max)
{
	int mid;
	if (min<max)
	{
		mid = (min + max) / 2;
		merge_sort(arr, min, mid);
		merge_sort(arr, mid + 1, max);
		merge(arr, min, mid, max);
	}
}
void merge(int arr[], int min, int mid, int max)
{
	int tmp[30];
	int iterator1, iterator2, iterator3, start_second;
	iterator2 = min;
	start_second = mid + 1;
	for (iterator1 = min; iterator2 <= mid && start_second <= max; iterator1++)
	{
		if (arr[iterator2] <= arr[start_second])
		{
			tmp[iterator1] = arr[iterator2];
			iterator2++;
		}
		else
		{
			tmp[iterator1] = arr[start_second];
			start_second++;
		}
	}
	if (iterator2>mid)
	{
		for (iterator3 = start_second; iterator3 <= max; iterator3++)
		{
			tmp[iterator1] = arr[iterator3];
			iterator1++;
		}
	}
	else
	{
		for (iterator3 = iterator2; iterator3 <= mid; iterator3++)
		{
			tmp[iterator1] = arr[iterator3];
			iterator1++;
		}
	}
	for (iterator3 = min; iterator3 <= max; iterator3++)
		arr[iterator3] = tmp[iterator3];
}