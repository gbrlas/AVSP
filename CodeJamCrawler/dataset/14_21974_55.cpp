#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<memory>
#include<algorithm>
#include<list>
#include<queue>
#include<vector>
using namespace std;
int a[5][5],b[5][5];
int main()
{
	int T;
	//freopen("A-small-attempt3.in","r",stdin);
	//freopen("gcja.txt","w",stdout);
	scanf("%d",&T);
	
		int r1,r2;
		int flag,ind;
		for(int i=1;i<=T;i++)
		{
			flag=0;
			ind=0;
			scanf("%d",&r1);
			for(int j=1;j<=4;j++)
				for(int k=1;k<=4;k++)
					scanf("%d",&a[j][k]);
			scanf("%d",&r2);
			for(int j=1;j<=4;j++)
				for(int k=1;k<=4;k++)
					scanf("%d",&b[j][k]);
			for(int j=1;j<=4;j++)
				for(int k=1;k<=4;k++)
				{
					if(a[r1][j] == b[r2][k])
					{
						flag++;
						if(flag == 1)
							ind=j;
					}
				}
			if(flag==0)
			{
				printf("Case #%d: Volunteer cheated!\n",i);
			}
			else if(flag>1)
				printf("Case #%d: Bad magician!\n",i);
			else
				printf("Case #%d: %d\n",i,a[r1][ind]);
		}
	
	return 0;
}
