#include<iostream>
#include<stdio.h>

int main()
{
	int test,ans1,ans2,cas=1;
	scanf("%d",&test);
	while( test -- )
	{
		scanf("%d",&ans1);
		int arr1[4];
		int index1 = 0;
		for( int i=1;i<=16;i++)
		{
			int temp;
			scanf("%d",&temp);
			if( i > (ans1-1)*4 && i <= ans1*4 )
				arr1[index1++] = temp;
		}
		scanf("%d",&ans2);
		int arr2[4];
		int index2 = 0;
		for( int i=1;i<=16;i++)
		{
			int temp;
			scanf("%d",&temp);
			if( i > (ans2-1)*4 && i <= ans2*4 )
				arr2[index2++] = temp;
		}
		int count = 0;
		for( int i=0;i<=3;i++)
		{
			for( int j=0;j<=3;j++)
			{
				if( arr1[i] == arr2[j] )
				{
					count++;
					break;
				}
			}
		}
		printf("Case #%d: ",cas);
		if( count == 0 )
			printf("Volunteer cheated!\n");
		else if ( count > 1 )
			printf("Bad magician!\n");
		else if( count == 1)
		{
			for( int i=0;i<=3;i++)
			{
				for( int j=0;j<=3;j++)
				{
					if( arr1[i] == arr2[j] )
					{
						printf("%d\n",arr1[i]);
						break;
					}
				}
			}

		}
		cas++;
	}
	return 0;
}
