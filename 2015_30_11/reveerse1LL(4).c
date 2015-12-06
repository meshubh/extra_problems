#include <stdio.h>
#include<malloc.h>
struct node
{
	int num;
	struct node *next;
};
struct node * createLinkedList();
struct node * findtail_LinkedList(struct node *);
void reverse_1_LinkedList(struct node * head,struct node *);
void displayLinkedList(struct node *);
void main()
{
	typedef struct node NODE;
	NODE *ll1,*tail=NULL;
	printf("Enter first linked list elements in sorted order only\n");
	ll1 = createLinkedList();
	tail = findtail_LinkedList(ll1);
	if(ll1->next!=NULL)
		reverse_1_LinkedList(ll1->next,ll1);
	printf("\nThe reversed Linked List is: \n");
	displayLinkedList(tail);
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
struct node * findtail_LinkedList(struct node *LL1)
{
	while (LL1->next != NULL)
	{
		LL1 = LL1->next;
	}
	return LL1;
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
void reverse_1_LinkedList(struct node* head,struct node * prev)
{
	struct node *temp;
		if (head->next == NULL) 
		{
			temp = prev;
			head->next = temp;
			temp->next = NULL;
			return;
		}
		reverse_1_LinkedList(head->next, head);
		head->next= prev;
		prev->next = NULL;
		return;
}