//Mineral element program
//Shubham Agarwal Mission R&D 2015 MGIT
#include<stdio.h>
int cal_sum(int, int[], int);
void main()
{
	int size, val, iterator, arr[100],result;
	printf("Ennter the size of array \n");
	scanf_s("%d", &size);
	printf("Enter array elements \n");
	for (iterator = 0; iterator < size; iterator++)
		scanf_s("%d", &arr[iterator]);
	printf("Enter the range to be considered \n");
	scanf_s("%d", &val);
	result=cal_sum(size, arr, val);
	printf("Mineral element is %d \n", arr[result]);
}
int cal_sum(int size, int arr[],int val)
{
	int sum_right[100] = { 0 }, sum_left[100] = { 0 }, min_sum[100] = { 0 }, iterator1, sum, org_val = val, iterator2, left_count, right_count;
	for (iterator1 = 0; iterator1 < size - 1; iterator1++)
	{
		sum = 0;
		for (iterator2 = iterator1 + 1; iterator2 < size; iterator2++)
		{
			sum = sum + arr[iterator2];
		}
		sum_right[iterator1] = sum;
	}
	for (iterator1 = size-1; iterator1 >0; iterator1--)
	{
		sum = 0;
		for (iterator2 = iterator1 - 1; iterator2 >0; iterator2--)
		{
			sum = sum + arr[iterator2];
		}
		sum_left[iterator1] = sum;
	}
	if (val % 2 == 0)
	{
		left_count = val / 2;
		val = val / 2;
		right_count = val - 1;	
	}
	else
	{
		left_count = right_count = val / 2;
	}
	for (iterator1 = org_val / 2; iterator1 < size - org_val / 2; iterator1++)
	{
		min_sum[iterator1] =(sum_left[iterator1]- sum_left[left_count]) + arr[iterator1] +(sum_right[iterator1]- sum_right[right_count]);
	}
	int max = 0;
	for (iterator1 = 0; iterator1 < size; iterator1++)
	{
		if (min_sum[max] < min_sum[iterator1] && min_sum[iterator1]>0)
			max = iterator1;
	}
	return max;
}