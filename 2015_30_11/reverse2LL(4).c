#include <stdio.h>
#include<malloc.h>
struct node
{
	int num;
	struct node *next;
};
struct node * createLinkedList(int *);
struct node * findtail_LinkedList(struct node *);
void reverse_2_LinkedList(struct node * head,struct node *,int);
void displayLinkedList(struct node *);
void main()
{
	typedef struct node NODE;
	NODE *ll1,*tail=NULL;
	int len = 0;
	printf("Enter first linked list elements in sorted order only\n");
	ll1 = createLinkedList(&len);
	tail = findtail_LinkedList(ll1);
	if(ll1->next!=NULL)
		reverse_2_LinkedList(ll1,tail,len-1);
	printf("\nThe reversed Linked List is: \n");
	displayLinkedList(ll1);
}
struct node * createLinkedList(int *len)
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
		*len = *len + 1;
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
void reverse_2_LinkedList(struct node* head,struct node * tail,int len)
{
	struct node *temp,*temp1=head;
	int iterator = 0;
	if (head->next == tail || head->next->next == tail)
	{
		temp=head->num;
		head->num = tail->num;
		tail->num = temp;
		return;
	}
	else
	{
		len = len - 2;
		while (iterator <= len && len > 0)
		{
			temp1 = temp1->next;
			iterator++;
		}
		reverse_2_LinkedList(head->next, temp1,len);
		temp = head->num;
		head->num = tail->num;
		tail->num = temp;
	}
}