#include<stdio.h>
#include<malloc.h>
struct node
{
	int num;
	struct node *next;
};
struct node * createLinkedList(int n1,int limit);
struct node * secondinsert_LinkedList(struct node *LL1, int n2, int limit);
void print_r_in_LinkedList(struct node *LL1,int r);
void displayLinkedList(struct node *LL);
void main()
{
	struct node *ll1;
	int n1, n2, r;
	printf("Enter the value of n1\n");
	scanf_s("%d", &n1);
	printf("Enter the value of n2\n");
	scanf_s("%d", &n2);
	printf("Enter the value of r\n");
	scanf_s("%d", &r);
	if (n1 < n2)
	{
		ll1 = createLinkedList(n1, r);
		displayLinkedList(ll1);
		ll1=secondinsert_LinkedList(ll1, n2,r);
		printf("\nThe linked list formed is : \n");
		displayLinkedList(ll1);
	}
	else
	{
		ll1 = createLinkedList(n2, r);
		displayLinkedList(ll1);
		ll1 = secondinsert_LinkedList(ll1, n1, r);
		printf("\nThe linked list formed is : \n");
		displayLinkedList(ll1);
	}
	print_r_in_LinkedList(ll1,r);

}
struct node * createLinkedList(int n1,int limit)
{
	typedef struct node NODE;
	NODE *curr, *first, *temp = NULL;
	int data1,iterator=1;
	first = NULL;
	while (iterator<=limit)
	{
		data1 = n1*iterator;
		curr = (NODE *)malloc(sizeof(NODE));
		curr->num = data1;
		if (first != NULL)
		{
			temp->next = curr;
			temp = curr;
		}
		else
		{
			first = temp = curr;
		}
		iterator++;
	}
	temp->next = NULL;
	return first;
}
struct node * secondinsert_LinkedList(struct node *LL1, int n2, int limit)
{
	int choice, data2, iterator = 1;
	struct node *temp = (struct node*)malloc(sizeof(struct node)), *temp1 = LL1,*prev=LL1,*first=LL1;
	while (iterator <= limit)
	{
		data2 = n2*iterator;
		if (temp1 == first)
		{
			if (data2 < temp1->num)
			{
				temp = (struct node*)malloc(sizeof(struct node));
				temp->num = data2;
				temp->next = temp1;
				LL1 = temp;
				iterator++;
			}
			else if (data2 == temp1->num)
			{
				iterator++;
				temp1 = temp1->next;
			}
			else
			{
				temp1 = temp1->next;
			}
		}
		else if (temp1->next == NULL)
		{
			if (data2 < temp1->num)
			{
				temp->num = data2;
				temp->next = temp1;
				prev->next = temp;
				prev = temp;
				iterator++;
			}
			else if (data2 == temp1->num)
			{
				iterator++;
			}
			else
			{
				temp = (struct node*)malloc(sizeof(struct node));
				temp->num = data2;
				temp1->next = temp;
				temp1 = temp;
				temp1->next = NULL;
				prev = prev->next;
				iterator++;
			}
		}
		else
		{
			if (data2 < temp1->num)
			{
				temp = (struct node*)malloc(sizeof(struct node));
				temp->num = data2;
				temp->next = temp1;
				prev->next = temp;
				prev = temp;
				iterator++;
				displayLinkedList(first);
			}
			else if (data2 == temp1->num)
			{
				iterator++;
				temp1 = temp1->next;
				prev = prev->next;
			}
			else
			{
				temp1 = temp1->next;
				prev = prev->next;
			}
		}
	}
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
void print_r_in_LinkedList(struct node *LL1, int r)
{
	int count = r;
	while (count > 1)
	{
		LL1 = LL1->next;
		count--;
	}
	printf("\nThe %d element is %d\n", r, LL1->num);
}