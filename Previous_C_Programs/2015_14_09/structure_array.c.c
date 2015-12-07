#include<stdio.h>
struct student
{
	char name[50];
	char department[50];
	char section[20];
	char student_id[20];
};
void student_structure_input(int size, struct student data[]);
int obtaining_position_of_given_student_id(int size, struct student data[]);
void print_required_structure(int position, struct student data[]);
main()
{
	int size, position, iterator = 0;
	struct student data[50];
	char required_id[20];
	printf("Enter the number of students \n");
	scanf_s("%d", &size);
	student_structure_input(size, data);
	position = obtaining_position_of_given_student_id(size, data);
	if (position == -1)
		printf("Student id not found in the given structure\n");
	else
	{
		print_required_structure(position, data);
	}
	getchar();
	getchar();
	getchar();
}
void student_structure_input(int size, struct student data[])
{
	int iterator1, iterator2;
	getchar();
	for (iterator1 = 0; iterator1 < size; iterator1++)
	{
		iterator2 = 0;
		printf("Enter student name \n");
		do
		{
			scanf_s("%c", &data[iterator1].name[iterator2]);
			iterator2++;
		} while (data[iterator1].name[iterator2 - 1] != '\n');
		data[iterator1].name[iterator2 - 1] = '\0';
		iterator2 = 0;
		printf("Enter student department \n");
		do
		{
			scanf_s("%c", &data[iterator1].department[iterator2]);
			iterator2++;
		} while (data[iterator1].department[iterator2 - 1] != '\n');
		data[iterator1].department[iterator2 - 1] = '\0';
		iterator2 = 0;
		printf("Enter student section \n");
		do
		{
			scanf_s("%c", &data[iterator1].section[iterator2]);
			iterator2++;
		} while (data[iterator1].section[iterator2 - 1] != '\n');
		data[iterator1].section[iterator2 - 1] = '\0';
		iterator2 = 0;
		printf("Enter student id \n");
		do
		{
			scanf_s("%c", &data[iterator1].student_id[iterator2]);
			iterator2++;
		} while (data[iterator1].student_id[iterator2 - 1] != '\n');
		data[iterator1].student_id[iterator2 - 1] = '\0';
	}
}
int obtaining_position_of_given_student_id(int size, struct student data[])
{
	int iterator1 = 0, iterator2 = 0;
	char required_id[100];
	printf("Enter the required student id \n");
	do
	{
		scanf_s("%c", &required_id[iterator1]);
		iterator1++;
	} while (required_id[iterator1 - 1] != '\n');
	required_id[iterator1 - 1] = '\0';
	for (iterator1 = 0; iterator1 < size; iterator1++)
	{
		iterator2 = 0;
		while (required_id[iterator2] != '\0' && data[iterator1].student_id[iterator2] != '\0')
		{
			if (required_id[iterator2] == data[iterator1].student_id[iterator2])
				iterator2++;
			else
				break;
		}
		if (required_id[iterator2] == '\0' && data[iterator1].student_id[iterator2] == '\0')
			return iterator1;
	}
	return -1;
}
void print_required_structure(int position, struct student data[])
{
	printf("Student's name is %s \n", data[position].name);
	printf("Student's department is %s \n", data[position].department);
	printf("Student's section is %s \n", data[position].section);
	printf("Student's id is %s \n", data[position].student_id);
}