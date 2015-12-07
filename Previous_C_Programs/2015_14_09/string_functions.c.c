#include<stdio.h>
void str_len(char string[], int size);
void str_cat(char string1[], char string2[], int size1, int size2);
void str_sub(char string[], int start, int length);
void str_cmp(char string[], char string1[], int size1, int size2);
void trim(char string[], int size);
void main()
{
	char string[100], string1[100];
	int iterator = 0, iterator1 = 0, start, length;
	printf("Enter the string for finding string lngth \n");
	do
	{
		scanf_s("%c", &string[iterator]);
		iterator++;
	} while (string[iterator - 1] != '\n');
	string[iterator - 1] = '\0';
	str_len(string, iterator - 1);
	iterator = 0;
	printf("Enter the first string for strcat function \n");
	do
	{
		scanf_s("%c", &string[iterator]);
		iterator++;
	} while (string[iterator - 1] != '\n');
	string[iterator - 1] = '\0';
	printf("Enter second string which will be used only for strcat function \n");
	do
	{
		scanf_s("%c", &string1[iterator1]);
		iterator1++;
	} while (string1[iterator1 - 1] != '\n');
	string1[iterator1 - 1] = '\0';
	str_cat(string, string1, iterator - 1, iterator1 - 1);
	iterator = 0;
	printf("Enter the string for strsub function \n");
	do
	{
		scanf_s("%c", &string[iterator]);
		iterator++;
	} while (string[iterator - 1] != '\n');
	string[iterator - 1] = '\0';
	printf("Enter the starting position of sub string in strsub function \n");
	scanf_s("%d", &start);
	printf("Enter the length of the sub string required \n");
	scanf_s("%d", &length);
	str_sub(string, start, length);
	iterator = 0;
	printf("Enter the first string which will be used for strcmp function \n");
	do
	{
		scanf_s("%c", &string[iterator]);
		iterator++;
	} while (string[iterator - 1] != '\n');
	string[iterator - 1] = '\0';
	int iterator2 = 0;
	printf("Enter second string which will be used only for strcmp function \n");
	do
	{
		scanf_s("%c", &string1[iterator2]);
		iterator2++;
	} while (string1[iterator2 - 1] != '\n');
	string1[iterator2 - 1] = '\0';
	str_cmp(string, string1, iterator - 1, iterator2 - 1);
	iterator = 0;
	printf("Enter the string used for trim function \n");
	do
	{
		scanf_s("%c", &string[iterator]);
		iterator++;
	} while (string[iterator - 1] != '\n');
	string[iterator - 1] = '\0';
	trim(string, iterator - 1);
}
void str_len(char string[], int size)
{
	int iterator, length = 0;
	for (iterator = 0; iterator < size; iterator++)
		length++;
	printf("The given string length is : ");
	printf("%d\n", length);
}
void str_cat(char string[], char string2[], int size1, int size2)
{
	int iterator, iterator1 = 0;
	for (iterator = size1; iterator < (size1 + size2); iterator++)
	{
		string[iterator] = string2[iterator1];
		iterator1++;
	}
	for (iterator = 0; iterator < (size1 + size2); iterator++)
		printf("%c", string[iterator]);
	printf("\n");
}
void str_sub(char string[], int start, int length)
{
	int iterator;
	for (iterator = start; iterator < (start + length); iterator++)
		printf("%c", string[iterator]);
	getchar();
	printf("\n");
}
void str_cmp(char string[], char string1[], int size1, int size2)
{
	int iterator = 0;
	while (string[iterator] != '\0' && string1[iterator] != '\0')
	{
		if (string[iterator] < string1[iterator])
		{
			printf("-1 \n");
			getchar();
			break;
		}
		else if (string[iterator]>string1[iterator])
		{
			printf("1 \n");
			getchar();
			break;
		}
		else
			iterator++;
	}
	if (string[iterator]  == '\0' && string1[iterator] == '\0')
		printf("0 \n");
}
void trim(char string[], int size)
{
	int iterator = 0, start_space = 0, iterator1, iterator2;
	//leading spaces
	while (string[iterator] == ' ')
	{
		start_space++;
		iterator++;
	}
	for (iterator = 0; iterator < size; iterator++)
		string[iterator] = string[iterator + start_space];
	size = size - start_space;
	//In between spaces
	for (iterator = 0; iterator < size; iterator++)
	{
		if (string[iterator] == ' '&& string[iterator + 1] == ' ')
		{
			for (iterator1 = iterator; iterator1 < size; iterator1++)
				string[iterator1] = string[iterator1 + 1];
			iterator--;
			size = size - 1;
		}
	}
	//trialing spaces if any will only be 1 coz in between spces will removng extra trialing spaces
	if (string[size - 1] == ' ')
		size = size - 1;
	printf("String after trimming it\n");
	for (iterator2 = 0; iterator2 < size; iterator2++)
		printf("%c", string[iterator2]);
	printf("\n");
	getchar();
}