#include<stdio.h>
void printing_date_logic(char x[]);
void display_date(int number, int date[], int count);
void display_month(int number, int count);
void display_year(int number1, int number2, int Year[]);
void one_digit_date(int f);
void two_digit_date(int g);
void one_digit_for_year(int h);
void two_digit_for_year(int i);
int power(int y, int z);
main()
{
	char date_given[100];
	int iterator = 0;
	printf("Enter the date \n");
	do
	{
		scanf_s("%c", &date_given[iterator]);
			iterator++;
	} while (date_given[iterator-1] != '\n');
	printing_date_logic(date_given);
	getchar();
}
void printing_date_logic(char date_given[100])
{
	int count = 0, count1 = 0, count2 = 0, iterator2, iterator1, iterator, number = 0, number1 = 0, number3 = 0, number4 = 0,number5=0;
	int date[5], month[5], year[5];
	for (iterator1 = 0; date_given[iterator1] != '/'; iterator1++)
	{
		date[iterator1] = date_given[iterator1] - 48;
		count++;
	}
	for (iterator = 0; iterator < count; iterator++)
	{
		number = number + (date[iterator] * power(10, ((count)-iterator - 1)));
	}
	for (iterator2 = count + 1; date_given[iterator2] != '/'; iterator2++)
	{
		month[count1] = date_given[iterator2] - 48;
		count1++;
	}
	for (iterator = 0; iterator < count1; iterator++)
	{
		number1 = number1 + (month[iterator] * power(10, ((count1)-iterator - 1)));
	}
	iterator2 = 0;
	count2 = count + 1 + count1 + 1;
	for (iterator1 = count2; iterator1 < count2 + 4; iterator1++)
	{
		year[iterator2] = (date_given[iterator1] - 48);
		iterator2++;
	}
	for (iterator = 0; iterator < 2; iterator++)
		number3 = number3 + (year[iterator] * power(10, (1 - iterator)));
	for (iterator = 2; iterator < 4; iterator++)
		number4 = number4 + year[iterator] * power(10, (3 - iterator));
	for (iterator = 0; iterator < 4; iterator++)
	{
		number5 = number5 + (year[iterator] * power(10, (1 - iterator)));
	}
	if (number1 == 2)
	{
		if (number5 % 4 == 0)//leap year
		{
			if (number > 29)
				printf("Wrong date((February month days less than 29) \n");
			else
			{
				display_date(number, date, count);
				display_month(number1, count1);
				display_year(number3, number4, year);
			}
		}
		else//not a leap year
		{
			if (number > 28)
				printf("Wrong date((February month days less than 28) \n");
			else
			{
				display_date(number, date, count);
				display_month(number1, count1);
				display_year(number3, number4, year);
			}
		}
	}
	else
	{
		display_date(number, date, count);
		display_month(number1, count1);
		display_year(number3, number4, year);
	}
}
void display_date(int number, int date[], int count)
{
	if (number > 31)
		printf("Wrong Date (Date error)\n");
	else if (count == 1)
		one_digit_date(number);
	else
	{
		if (date[0] = 0)
			one_digit_date(number);
		else
			two_digit_date(number);
	}
}
void display_month(int number10, int count)
{
	int number = number10;
	if (number>12)
		printf("Wrong date (Month error)\n");
	else if (number == 1)
		printf(" January ");
	else if (number == 2)
		printf(" February ");
	else if (number == 3)
		printf(" March ");
	else if (number == 4)
		printf(" April ");
	else if (number == 5)
		printf(" May ");
	else if (number == 6)
		printf(" June ");
	else if (number == 7)
		printf(" July ");
	else if (number == 8)
		printf(" August ");
	else if (number == 9)
		printf(" September ");
	else if (number == 10)
		printf(" October ");
	else if (number == 11)
		printf(" November ");
	else if (number == 12)
		printf(" December ");
}
void display_year(int number1, int number2, int Year[])
{
	
	if (number2 >= 10)
	{
		two_digit_for_year(number1);
		two_digit_for_year(number2);
	}
	else
	{
		if (Year[1] == 0)
		{
			one_digit_for_year(Year[0]);
			printf("Thousand ");
			if (number2 > 0)
			{
				printf("and ");
				one_digit_for_year(number2);
			}
		}
		else
		{
			two_digit_for_year(number1);
			if (number2>0)
			{
				printf(" not ");
				one_digit_for_year(number2);
			}
			else
				printf("Thousand \n");
		}
	}
}
void one_digit_date(int number)

{
	if (number == 1)
		printf("First of");
	else if (number == 2)
		printf("Second of");
	else if (number == 3)
		printf("Third of");
	else if (number == 4)
		printf("Fourth of");
	else if (number == 5)
		printf("Fifth of");
	else if (number == 6)
		printf("Sixth of");
	else if (number == 7)
		printf("Seventh of");
	else if (number == 8)
		printf("Eighth of");
	else if (number == 9)
		printf("Ninth of");
}
void two_digit_date(int number)
{
	int first_part = number / 10;
	number = number % 10;
	if (first_part == 1)
	{
		if (number == 1)
			printf("Eleventh of");
		else if (number == 2)
			printf("Twelvth of");
		else if (number == 3)
			printf("Thirteenth of");
		else if (number == 4)
			printf("Fourteenth of");
		else if (number == 5)
			printf("Fifteenth of");
		else if (number == 6)
			printf("Sixteenth of");
		else if (number == 7)
			printf("Seventeenth of");
		else if (number == 8)
			printf("Eighteenth of");
		else if (number == 9)
			printf("Ninteenth of");
		else
			printf("Tenth of");
	}
	else if (first_part == 2)
	{
		printf("Twenty");
		if (number == 0)
			printf("th of");
		else
			one_digit_date(number);
	}
	else if (first_part == 3)
	{
		printf("Thirty");
		if (number == 0)
			printf("th of");
		else if (number == 1)
			printf("First of ");
		else
			printf("Wrong Date \n");
	}
}
void one_digit_for_year(int number)
{
	if (number == 1)
		printf("One ");
	else if (number == 2)
		printf("Two ");
	else if (number == 3)
		printf("Three ");
	else if (number == 4)
		printf("Four ");
	else if (number == 5)
		printf("Five ");
	else if (number == 6)
		printf("Six ");
	else if (number == 7)
		printf("Seven ");
	else if (number == 8)
		printf("Eight ");
	else if (number==9)
		printf("Nine ");
}
void two_digit_for_year(int number)
{
	int first_part = number / 10;
	number = number % 10;
	if (first_part == 1)
	{
		if (number == 0)
			printf("Ten ");
		else if (number == 1)
			printf("Eleven ");
		else if (number == 2)
			printf("Twelve ");
		else if (number == 3)
			printf("Thirteen ");
		else if (number == 4)
			printf("Fourteen ");
		else if (number == 5)
			printf("Fifteen ");
		else if (number == 6)
			printf("Sixteen ");
		else if (number == 7)
			printf("Seventeen ");
		else if (number == 8)
			printf("Eighteen ");
		else
			printf("Nineteen ");
	}
	else if (first_part == 2)
	{
		printf("Twenty ");
		if (number>0)
		one_digit_for_year(number);
	}
	else if (first_part == 3)
	{
		printf("Thirty ");
		if (number>0)
		one_digit_for_year(number);
	}
	else if (first_part == 4)
	{
		printf("Fourty ");
		if (number>0)
		one_digit_for_year(number);
	}
	else if (first_part == 5)
	{
		printf("Fifty ");
		if (number>0)
		one_digit_for_year(number);
	}
	else if (first_part == 6)
	{
		printf("Sixty ");
		if (number>0)
		one_digit_for_year(number);
	}
	else if (first_part == 7)
	{
		printf("Seventy ");
		if (number>0)
		one_digit_for_year(number);
	}
	else if (first_part == 8)
	{
		printf("Eighty ");
		if (number>0)
		one_digit_for_year(number);
	}
	else
	{
		printf("Ninty ");
		if (number>0)
		one_digit_for_year(number);
	}
}
int power(int number1, int number2)
{
	int iterator, answer = 1;
	for (iterator = 1; iterator <= number2; iterator++)
	{
		answer = answer*number1;
	}
	return answer;
}