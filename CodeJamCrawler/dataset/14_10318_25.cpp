#include <iostream>

int main()
{
	int cases=0;
	int anwers[2]={0};
	int arr1[4][4]={0};
	int arr2[4][4]={0};
	int num[100]={0};
	int card[100]={0};
	freopen( "A-small-attempt0.in", "r", stdin );
	freopen( "output.txt", "w", stdout );
	scanf("%d",&cases);
	for(int t=0;t<cases;t++)
	{
		scanf("%d",&anwers[0]);
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				scanf("%d",&arr1[i][j]);
			}
		}
		scanf("%d",&anwers[1]);
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				scanf("%d",&arr2[i][j]);
				if(i==(anwers[1]-1))
				{
					for(int k=0;k<4;k++)
					{
						if(arr1[anwers[0]-1][k]==arr2[i][j])
						{
							card[t]=arr2[i][j];
							num[t]++;
						}
					}
				}
			}
		}
	}

	for(int i=0;i<cases;i++)
	{
		switch(num[i])
		{
		case 0:printf("Case #%d: Volunteer cheated!\n",i+1);break;
		case 1:printf("Case #%d: %d\n",i+1,card[i]);break;
		default:printf("Case #%d: Bad magician!\n",i+1);break;
		}
	}
	return 0;
}