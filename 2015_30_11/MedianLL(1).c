#include <stdio.h>
#include<malloc.h>
struct node
{
	int num;
	struct node *next;
};
struct node * createLinkedList();
void median_LinkedList(struct node * LL1);
void main()
{
	typedef struct node NODE;
	NODE *ll1;
	printf("Enter first linked list elements in sorted order only\n");
	ll1 = createLinkedList();
	median_LinkedList(ll1);
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
void median_LinkedList(struct node * LL1)
{
	struct node *temp = LL1;
	int len = 0,i=0,sum=0;
	while (LL1->next != NULL)
	{
		len++;
		LL1=LL1->next;
	}
	if (len % 2 == 0)
	{
		while (i < len/2-1)
		{
			temp = temp->next;
			i++;
		}
		printf("Median is %d \n", temp->num);
	}
	else
	{
		while (i < len / 2 )
		{
			temp = temp->next;
			i++;
		}
		sum += temp->num;
		temp = temp->next;
		sum += temp->num;
		printf("Median is %d\n", sum/2);
	}
}