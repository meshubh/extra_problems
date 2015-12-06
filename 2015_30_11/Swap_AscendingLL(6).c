#include <stdio.h>
#include<malloc.h>
struct node
{
	int num;
	struct node *next;
};
struct node * createLinkedList();
void displayLinkedList(struct node *);
void elementSwap_LinkedList(struct node * LL1);
void main()
{
	typedef struct node NODE;
	NODE *ll1;
	printf("Enter first linked list elements\n");
	ll1 = createLinkedList();
	elementSwap_LinkedList(ll1);
	printf("The sorted linked list is \n");
	displayLinkedList(ll1);
	getchar();
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
void elementSwap_LinkedList(struct node * LL1)
{
	struct node * cur=LL1, *stop1 = NULL, *stop2 = NULL,*prev = LL1,*present;
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
	present = cur;
	while (present != NULL)
	{
		if (cur->next == NULL)
		{
			if (cur->num < stop1->num)
			{
				stop2 = cur;
				break;
			}
		}
		else
		{
			if (prev != LL1)
			{
				if (prev->num < present->num && present->num < cur->num)
				{
					stop2 = present;
					break;
				}
			}
			else
			{
				if (present->num < cur->num)
				{
					stop2 = present;
					break;
				}
			}
		}
		present = present->next;
	}
	stop1->num = stop1->num + stop2->num;
	stop2->num = stop1->num - stop2->num;
	stop1->num = stop1->num - stop2->num;
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