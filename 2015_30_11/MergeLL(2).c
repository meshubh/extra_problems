#include <stdio.h>
#include<malloc.h>
struct node
	{
		int num;
		struct node *next;
	};
struct node * createLinkedList();
void displayLinkedList(struct node *);
struct node * merge_sortLinkedList(struct node * LL1,struct node * LL2);
void main()
{
	typedef struct node NODE;
	NODE *ll1, *ll2, *result;
	printf("Enter first linked list elements in sorted order only\n");
	ll1 = createLinkedList();
	printf("Enter second linked list elements in sorted order only\n");
	ll2 = createLinkedList();
	result=merge_sortLinkedList(ll1, ll2);
	printf("Sorted merged Lists is as follows :\n");
	displayLinkedList(result);
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
	temp->next = NULL;
	return first;
}
struct node * merge_sortLinkedList(struct node * LL1, struct node * LL2)
{
	struct node * head, * temp;
	if (LL1->num < LL2->num)
	{
		head = LL1;
	}
	else
	{
		head = LL2;
		LL2 = LL1;
		LL1 = head;
	}
	while (LL1 != NULL && LL2 != NULL)
	{
		if (LL1->next != NULL)
		{
			if (LL1->next->num <= LL2->num)
			{
				//("\n^^%d^^\n", LL1->num);
				LL1 = LL1->next;
			}
			else
			{
				temp = LL1->next;
				LL1->next = LL2;
				LL2 = temp;
			}
		}
		else
		{
			temp = LL1->next;
			LL1->next = LL2;
			LL2 = temp;
		}
	}
	if (LL2 != NULL)
		LL1->next = LL2;
	return head;
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