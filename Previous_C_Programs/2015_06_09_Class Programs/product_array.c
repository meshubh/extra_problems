#include<stdio.h>
void calcul(int a[], int n);
int b[100];
void main()
{
	int a[100], i, n;
	printf("Enter no. of array elements");
	scanf_s("%d", &n);
	printf("Enter array elements\n");
	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	calcul(a, n);
	for (i = 0; i < n; i++)
		printf("%d \t", b[i]);
}
void calcul(int a[], int n)
{
	int i,j,k,l,p=1;
	for (i = 0; i < n; i++)
	{
		j = i + 1;
		k = i - 1;
		for (l = 1; l < n; l++)
		{
			if (j < n)
			{
				p *= a[j];
				j++;
			}
			if (k >= 0)
			{
				p *= a[k];
				k--;
			}
		}
		b[i] = p;
		p = 1;
	}
}