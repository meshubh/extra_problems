//Given three unsigned numbers as input X, Y, Z find out X to the power of Y modulo Z (power(x,y) mod z)
//Shubham Agarwal(MGIT) Mission RnD 2015
#include<stdio.h>
int modulo(int, int, int);
int pow(int, int);
void main()
{
	int x, y, a,answer;
	printf("Enter the values of x,y ad a respectively \n");
	scanf_s("%d%d%d", &x, &y, &a);
	answer = modulo(x, y, a);
	printf("The modulo is %d \n", answer);
	getchar();
}
int modulo(int x, int y, int a)
{
	int answer,iterator1=0,iterator2=0, modulo_array[100];
	if (x == a)
		printf("0");
	else
	{
		while (iterator2<= x)
		{
			modulo_array[iterator1] = (pow(x, iterator2)) % a;
			iterator1++;
			iterator2++;
		}
	}
	answer = modulo_array[(y % (x + 1))];
	return answer;
}
int pow(int a, int b)
{
	int product = 1, i;
	for (i = 1; i <= b; i++)
		product *= a;
	return product;
}