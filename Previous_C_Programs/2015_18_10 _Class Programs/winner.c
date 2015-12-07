//Winner element program
//Shubham Agarwal Mission R&D 2015 MGIT
#include<stdio.h>
int get_count(int[], int, int, int[]);
void cost(int[], int, int[]);
void main()
{
	int size, k, iterator, x = 0, arr[10], count[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, cost_mat[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	printf("Enter the array size \n");
	scanf_s("%d", &size);
	printf("Enter the array elements \n");
	for (iterator = 0; iterator < size; iterator++)
		scanf_s("%d", &arr[iterator]);
	printf("Enter the k value \n");
	scanf_s("%d", &k);
	x = get_count(arr, k, size, count);
	if (x != 1)
	{
		cost(count, k, cost_mat);
		int min = 0;
		for (iterator = 0; iterator < 10; iterator++)
		{
			if (cost_mat[min] > cost_mat[iterator] && cost_mat[iterator]>0)
				min = iterator;
		}
		printf("\n%d is the winner element and its cost is %d.\n", min, cost_mat[min]);
	}
	getchar();
	getchar();
}
int get_count(int arr[], int k, int size, int count[])
{
	int iterator, x = 0;
	for (iterator = 0; iterator < size; iterator++)
	{
		count[arr[iterator]]++;
		if (count[arr[iterator]] >= k)
		{
			printf("\n%d is the winner element and its cost is 0.\n", arr[iterator]);
			x++;
			return x;
		}
	}
	return x;
}
void cost(int count[], int k, int cost_mat[])
{
	int iterator, diff, iterator1, iterator2, cou = 0;
	for (iterator = 0; iterator < 10; iterator++)
	{
		if (count[iterator]>0)
		{
			diff = k - count[iterator];
			if (diff > 0)
			{
				iterator2 = iterator - 1;
				iterator1 = iterator + 1;
				while (diff != 0)
				{
					cou++;
					if (iterator2 < 0)
						iterator2--;
					else
					{
						if (diff <= count[iterator2] && diff>0)
						{
							cost_mat[iterator] = cost_mat[iterator] + (cou * diff);
							diff = 0;
						}
						else if (diff > count[iterator2] && diff>0 && count[iterator2]>0)
						{
							diff = diff - count[iterator2];
							cost_mat[iterator] = cost_mat[iterator] + (cou * count[iterator2]);
						}
					}
					iterator2--;
					if (iterator1 > 9)
						iterator1++;
					else
					{
						if (diff <= count[iterator1] && diff>0)
						{
							cost_mat[iterator] = cost_mat[iterator] + (cou * diff);
							diff = 0;
						}
						else if (diff > count[iterator1] && diff>0 && count[iterator1]>0)
						{
							diff = diff - count[iterator1];
							cost_mat[iterator] = cost_mat[iterator] + (cou * count[iterator1]);
						}
					}
					iterator1++;
				}
				cou = 0;
			}
		}
	}
}