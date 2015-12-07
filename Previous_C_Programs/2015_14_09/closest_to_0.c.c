#include <stdio.h>
int find_min_number_return_position(int diff_array[], int size);
main()
{
	int size, array[100],diff_array[99], iterator,min_position;
	printf("Enter array size \n");
	scanf_s("%d", &size);
	printf("Enter array elements \n");
	for (iterator = 0; iterator <size; iterator++)
		scanf_s("%d", &array[iterator]);
	for (iterator = 0; iterator <size - 1; iterator++)
	{
		if (array[iterator + 1]>array[iterator])
			diff_array[iterator] = array[iterator + 1] - array[iterator];
		else
			diff_array[iterator] = array[iterator] - array[iterator + 1];
	}
	min_position = find_min_number_return_position(diff_array, size - 1);
		printf("The integers whose difference is closest to 0 are %d and %d and the difference is %d ", array[min_position], array[min_position + 1],(array[min_position+1]-array[min_position]));
		getchar();
		getchar();
}
int find_min_number_return_position(int diff_array[], int size)
{
	int min, iterator,result=0;
	min = diff_array[0];
	for (iterator = 1; iterator <size; iterator++)
	{
		if (min > diff_array[iterator])
		{
			min = diff_array[iterator];
			result = iterator;
		}
	}
	return result;
}