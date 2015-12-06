#include <stdio.h>
#include<malloc.h>
struct node
{
	int num;
	struct node *next;
};
struct node * createLinkedList();
struct node * insert_LinkedList(struct node *);
void displayLinkedList(struct node * LL1);
void main()
{
	typedef struct node NODE;
	NODE *ll1;
	int opt;
	printf("Enter first linked list elements\n");
	ll1 = createLinkedList();
	printf("The given linked list is \n");
	displayLinkedList(ll1);
	do
	{
		printf("Do you want to insert element in list Type 0 if no or 1 if yes \n");
		scanf_s("%d", &opt);
		if (opt == 1)
			ll1=insert_LinkedList(ll1);
		else
			break;
		printf("The new linked list is \n");
		displayLinkedList(ll1);
	} while (opt != 0);
	printf("The final linked list is \n");
	displayLinkedList(ll1);
	getchar();
}
struct node * createLinkedList()
{
	typedef struct node NODE;
	NODE *curr, *first, *temp = NULL;
	int choice = 1;
	first = NULL;

	while (choice)
	{
		curr = (NODE *)malloc(sizeof(NODE));
		printf("Enter the data item\n");
		scanf_s("%d", &curr->num);
		if (first != NULL)
		{
			temp->next = curr;
			temp = curr;
		}
		else
		{
			first = temp = curr;
		}
		printf("Do you want to continue(Type 0 if no or 1 if yes)?\n");
		scanf_s("%d", &choice);
	}
	temp->next = first;
	return first;
}
struct node * insert_LinkedList(struct node *LL1)
{
	int choice,num,t=1;
	struct node *temp = (struct node*)malloc(sizeof(struct node)),*temp1=LL1;
	printf("Enter where do you want to insert the element 1 for first || 2 for anywhere in the list || 3 for last\n");
	scanf_s("%d", &choice);
	printf("Enter the value of the element you want to insert \n");
	scanf_s("%d", &num);
	if (choice == 1)
	{
		temp->num = num;
		temp->next = LL1;
		while (temp1->next != LL1)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;
		LL1 = temp;
		return LL1;
	}
	else if (choice == 2)
	{
		printf("Enter the exact position where you wish to insert the data \n");
		scanf_s("%d", &choice);
		if (choice == 1)
		{
			temp->num = num;
			temp->next = LL1;
			while (temp1->next != LL1)
			{
				temp1 = temp1->next;
			}
			temp1->next = temp;
			LL1 = temp;
			return LL1;
		}
		else
		{
			while (t < choice - 1)
			{
				temp1 = temp1->next;
				t++;
				if (temp1->next == LL1)
				{
					printf("Position is beyond the length of the list please try again \n");
					return LL1;
				}
			}
		}
		temp->num = num;
		temp->next = temp1->next;
		temp1->  next = temp;
		return LL1;
	}
	else if (choice == 3)
	{
		temp->num = num;
		while (temp1->next != LL1)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;
		temp->next = LL1;
		return LL1;
	}
	else
	{
		printf("Wrong choice please retry\n");
		return LL1;
	}
}
void displayLinkedList(struct node *LL)
{
	struct node*head = LL;
	while (LL->next != head)
	{
		printf("%d->", LL->num);
		LL = LL->next;
	}
	printf("%d \n",LL->num);
}