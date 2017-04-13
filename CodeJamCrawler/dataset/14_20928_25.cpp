#include <stdio.h>
#include <conio.h>
int main()
{
	int testCases,i;
	scanf("%d",&testCases);
	for(i=1;i<=testCases;i++)
	{
	    printf("Case #%d: ",i);
	    magicTrick();
	    printf("\n");
	}

	return 0;
}

void magicTrick()
{
    int choice_row,arr1[4], arr2[4], i, j,ignored, count=0,answer;
	scanf("%d",&choice_row);

	for(i = 1;i <= 4;i++)
	{
		if(i == choice_row)
		{
			for(j=0;j<=3;j++)
			scanf("%d",&arr1[j]);
		}
		else
		{
			for(j=0;j<=3;j++)
			scanf("%d",&ignored);
		}
	}


	scanf("%d",&choice_row);
	for(i = 1;i <= 4;i++)
	{
		if(i == choice_row)
		{
			for(j=0;j<=3;j++)
			scanf("%d",&arr2[j]);
		}
		else
		{
			for(j=0;j<=3;j++)
			scanf("%d",&ignored);
		}
	}



	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(arr1[j]==arr2[i])
			{
				answer = arr1[j];
				count+=1;
			}
		}

	}

	if(count == 0)
	{
		printf("Volunteer cheated!");
	}
	else if(count > 1)
	{
		printf("Bad magician!");
	}
	else printf("%d", answer);
}
