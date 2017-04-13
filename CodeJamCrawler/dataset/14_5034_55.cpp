#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		int n1,arr1[17]={0},arr2[17]={0},n2,tmp;
		scanf("%d",&n1);
		for(int i=1,j=0;i<=16;i++)
		{
			if(i%4==1)
				j++;
			scanf("%d",&tmp);
			if(j==n1)
			{
				arr1[tmp]=1;
				//printf("%d\n",tmp );
			}
		}
		scanf("%d",&n2);
		for(int i=1,j=0;i<=16;i++)
		{
			if(i%4==1)
				j++;
			scanf("%d",&tmp);
			if(j==n2)
			{
				arr2[tmp]=1;
				//printf("%d\n",tmp );
			}
		}
		int j=0,count=0;
		for (int i = 1; i <=16; i++)
		{
			if(arr1[i]==1 && arr2[i]==1)
				{
					count++;
					//printf("%d\n",i );
					j=i;
				}

		}
		//printf("%d %d\n", j, count );
		if(count==1)
			printf("Case #%d: %d\n",cas,j);
		else if(count>1)
			printf("Case #%d: Bad magician!\n",cas);
		else if(count<1)
			printf("Case #%d: Volunteer cheated!\n",cas);
		cas++;
	}
	return 0;
}
