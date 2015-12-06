#include <stdio.h>
#include<malloc.h>
struct node
{
	int num;
	struct node *next;
};
struct node * createLinkedList();
void displayLinkedList(struct node *);
void descendingtoascending_LinkedList(struct node * LL1);
void main()
{
	typedef struct node NODE;
	NODE *ll1;
	printf("Enter first linked list elements\n");
	ll1 = createLinkedList();
	descendingtoascending_LinkedList(ll1);
	printf("The sorted linked list is \n");
	displayLinkedList(ll1);
	getchar();
	getchar();
}
struct node * createLinkedList()
{
	typedef struct node NODE;
	NODE *curr, *first, *temp = NULL;
	int count = NULL;
	int choice = 1;
	first = 0;

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
	temp->next = NULL;
	return first;
}
void descendingtoascending_LinkedList(struct node * LL1)
{
	struct node * cur = LL1, *stop1 = NULL, *temp1, *prev = LL1, *temp, *prev1=NULL;
	while (cur != NULL)
	{
		if (cur == LL1)
		{
			if (cur->num > cur->next->num)
			{
				stop1 = cur;
			}
			cur = cur->next;
		}
		else
		{
			if (cur->num > cur->next->num)
			{
				if (stop1 == NULL)
				{
					stop1 = cur;
					cur = cur->next;
					break;
				}
			}
			cur = cur->next;
			prev = prev->next;
		}
		if (stop1 != NULL)
			break;
	}
	temp = stop1;
	while (temp != NULL)
	{
		temp1 = temp->next;
		temp->next = prev1;
		prev1 = temp;
		temp = temp1;
	}
	prev->next = prev1;
}
void displayLinkedList(struct node *LL)
{
	while (LL != NULL)
	{
		printf("%d->", LL->num);
		LL = LL->next;
	}
	printf("NULL\n");
}