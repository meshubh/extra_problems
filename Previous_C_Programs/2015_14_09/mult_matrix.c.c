#include<stdio.h>
void read_matrix(int row, int column, int matrix[][100]);
void multiply_matrix(int row1, int column1, int matrix1[][100], int row2, int column2, int matrix2[][100], int final_matrix[][100]);
void display_matrix(int row, int column, int matrix[][100]);
void main()
{
	int row1, column1, row2, column2;
	int matrix1[100][100], matrix2[100][100], final_matrix[100][100];
	printf("Enter number of rows and columns of matrix 1\n");
	scanf_s("%d%d", &row1, &column1);
	printf("Enter elements of matrix 1\n");
	read_matrix(row1, column1, matrix1);
	printf("Enter number of rows and columns of matrix 2\n");
	scanf_s("%d%d", &row2, &column2);
	if (column1 != row2)
		printf("Matrices cannot be multiplied \n");
	else
	{
		printf("Enter elements of matrix 2\n");
		read_matrix(row2, column2, matrix2);
	}
	printf("Matrix 1  is as follows \n");
	display_matrix(row1, column1, matrix1);
	printf("Mtrix 2 is as follows \n");
	display_matrix(row2, column2, matrix2);
	multiply_matrix(row1, column1, matrix1, row2, column2, matrix2, final_matrix);
	printf("Resultant Matrix is as follows \n");
	display_matrix(row1, column2, final_matrix);
	getchar();
	getchar();
	getchar();
}
void read_matrix(int row, int column, int matrix[][100])
{
	int iterator1, iterator2;
	for (iterator1 = 0; iterator1<row; iterator1++)
	{
		for (iterator2 = 0; iterator2<column; iterator2++)
		{
			scanf_s("%d", &matrix[iterator1][iterator2]);
		}
	}
}
void multiply_matrix(int row1, int column1, int matrix1[][100], int row2, int column2, int matrix2[][100], int final_matrix[][100])
{
	int iterator1, iterator2, iterator3;
	for (iterator1 = 0; iterator1<row1; iterator1++)
	{
		for (iterator2 = 0; iterator2<column2; iterator2++)
		{
			final_matrix[iterator1][iterator2] = 0;
				for (iterator3 = 0; iterator3<row1; iterator3++)
					final_matrix[iterator1][iterator2] = final_matrix[iterator1][iterator2] + (matrix1[iterator1][iterator3] * matrix2[iterator3][iterator2]);
		}
	}
}
void display_matrix(int row, int column, int matrix[][100])
{

	int iterator1, iterator2;
	for (iterator1 = 0; iterator1<row; iterator1++)
	{
		for (iterator2 = 0; iterator2<column; iterator2++)
		{
			printf("%d \t", matrix[iterator1][iterator2]);
		}
		printf("\n");
	}
}