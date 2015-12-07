// A function to find rank of a string in all permutations of given number
//Shubham Agarwal MGIT 2015 MissionRnD
#include<stdio.h>
int find_rank_logic(int numb_array[], int size);
int convert_to_array_return_size(int num, int numb_array[]);
int find_small_in_right(int numb_array[], int iterator, int size);
int check_for_repeat(int numb_array[], int size, int start_position);
int fact(int number);
int find_rank_logic(int numb_array[], int size)
{
	int iterator, rank = 0, count_right, repeating_num;
	for (iterator = 0; iterator < size; iterator++)
	{
		count_right = find_small_in_right(numb_array, iterator, size);
		repeating_num = (check_for_repeat(numb_array, size, iterator));
		if (repeating_num>1)
			rank += ((fact(size - iterator - 1))*count_right / (fact(repeating_num)));
		else
			rank += fact(size-iterator-1)*count_right;
	}
	return rank;
}
int convert_to_array_return_size(int num, int numb_array[])
{
	int temp_array[100];
	int iteration = 0, length = 0;
	while (num>0)
	{
		temp_array[iteration] = num % 10;
		num = num / 10;
		iteration++; length++;
	}
	for (iteration = 0; iteration < length; iteration++)
		numb_array[iteration] = temp_array[length -iteration- 1];
	return length;
}
int find_small_in_right(int numb_array[], int iterator, int size)
{
	int iterator1, small_count = 0;
	for (iterator1 = iterator + 1; iterator1<size; iterator1++)
	{
		if (numb_array[iterator]>numb_array[iterator1])
			small_count=small_count+1;
	}
	return small_count;
}
int check_for_repeat(int numb_array[], int size, int start_position)
{
	int iteration,iteration2, repeat = 1;
	for (iteration = start_position; iteration<size-1; iteration++)
	{
		for (iteration2 = iteration + 1; iteration2 < size; iteration2++)
		{
			if (numb_array[iteration] == numb_array[iteration2])
				repeat++;
		}
	}
	return repeat;
}
int fact(int number)
{
	int factorial = 1, iterator;
	for (iterator = number; iterator>0; iterator--)
		factorial *= iterator;
	return factorial;
}
int main()
{
	int num, numb_array[100], size,i, fin_rank;
	printf("Enter the number \n");
	scanf_s("%d", &num);
	size = convert_to_array_return_size(num, numb_array);
	fin_rank = find_rank_logic(numb_array, size);
	printf("%d \n", fin_rank);
	getchar();
}