#include <stdio.h>
void last_n_lines(int);
void main()
{
	int n;
	printf("Enter the number of lines to be printed\n");
	scanf_s("%d", &n);
	last_n_lines(n);
}
void last_n_lines(int n)
{
	FILE *fp1, *fp2;
	fopen_s(&fp1, "test.txt", "r");
	fopen_s(&fp2, "test.txt", "r");
	int LENGTH = 256;
	char line[256];
	int linecount = 0;
	while (fgets(line, LENGTH, fp1) != NULL)
	{
		printf("%s", line);
	}
	if (fp1 == NULL || fp2 == NULL)
	{
		printf("error in opening the text file");
		return 0;
	}
	while (fgets(line, LENGTH, fp1) != NULL)
	{
		if (linecount < n)
			linecount = linecount + 1;
		else
		{
			fgets(line, LENGTH, fp2);
		}
	}
	if (linecount < n)
	{
		printf("less than %d lines in the file\n", n);
		return 0;
	}
	while (fgets(line, LENGTH, fp2) != NULL)
	{
		printf("%s", line);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}