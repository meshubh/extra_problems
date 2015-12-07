//Generate all 6 digit numbers which when multiplied by a number(between 1 and 7(exclusive)) 
//produces a number that has the same digits as the original number
//Shubham Agarwal Mission R&D 2015 MGIT
#include<stdio.h>
void cal();
void main()
{
	cal();
	getchar();
}
void cal()
{
	int  iterator=2, max_poss, iterator1, num[6], prod[6], dig,iterator2,numb,iterator3,iterator4,match=0,product;
	for (iterator = 2; iterator < 7; iterator++)
	{
		printf("\n***********************MULTIPER IS %d****************************\n", iterator);
		max_poss = 1000000 / iterator;
		for (iterator1 = 100001; iterator1 < max_poss; iterator1++)
		{
			iterator2 = 0;
			numb = iterator1;
			while (numb > 0)
			{
				dig =numb % 10;
				num[iterator2] = dig;
				numb = numb / 10;
				iterator2++;
			}
			iterator2 = 0;
			product = iterator1*iterator;
			while (product > 0)
			{
				dig = product % 10;
				prod[iterator2] = dig;
				product = product / 10;
				iterator2++;
			}
			for (iterator3 = 0; iterator3 < 6; iterator3++)
			{
				for (iterator4 = 0; iterator4 < 6; iterator4++)
				{
					if (num[iterator4] == prod[iterator3])
					{
						match++;
						num[iterator4] = -100;
						break;
					}
				}
				if (match != iterator3 + 1)
					break;
			}
			if (match == 6)
			{
				printf("%d \n", iterator1);
			}
			match = 0;
		}
	}
}