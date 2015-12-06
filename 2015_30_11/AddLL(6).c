#include <stdio.h>
#include<malloc.h>
struct node
{
	int num;
	struct node *next;
};
struct node * createLinkedList();
void displayLinkedList(struct node *);
struct node * addLinkedList(struct node * LL1, struct node * LL2);
void main()
{
	typedef struct node NODE;
	NODE *ll1, *ll2, *result;
	printf("Enter first linked list elementsly\n");
	ll1 = createLinkedList();
	printf("Enter second linked list elements\n");
	ll2 = createLinkedList();
	result = addLinkedList(ll1, ll2);
	printf("Added linked list is :\n");
	displayLinkedList(result);
}
struct node * createLinkedList()
{
	typedef struct node NODE;
	NODE *curr, *first, *temp = NULL;
	int count = NULL;
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
void displayLinkedList(struct node *LL)
{
	while (LL != NULL)
	{
		printf("%d->", LL->num);
		LL = LL->next;
	}
	printf("NULL\n");
}
struct node * addLinkedList(struct node * LL1, struct node * LL2)
{
	struct node *temp = LL1;
	while (temp != NULL || LL2 != NULL)
	{
		if (temp->next == NULL && LL2->next != NULL)
		{
			temp->num = temp->num + LL2->num;
			break;
		}
		else if (temp->next != NULL && LL2->next == NULL)
		{
			temp->num = temp->num + LL2->num;
			LL2 = LL2->next;
			temp = LL2;
			break;
		}
		else
		{
			temp->num = temp->num + LL2->num;
		}
		temp = temp->next;
		LL2 = LL2->next;
	}
	return LL1;
}