#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<map>
#include<vector>

using namespace std;

int d[2010];
int price[11][2010];
int n,sum;

int min_num(int n1,int n2)
{
	if(n1<=n2)
		return n1;
	return n2;
}
int dfs(int p,int num)
{
	if(p==n)
		return d[num];
	int n1 = dfs(p+1,2*num);
	int n2 = dfs(p+1,2*num+1);
	if(n1 == 0 || n2==0)
	{
		sum++;
		return 0;
	}
	return min_num(n1-1,n2-1);
}
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("temp.txt","w",stdout);
	
	int t,cas=1;
	int i,j,num;
	
	scanf("%d",&t);
	while(t--)
	{		
		scanf("%d",&n);
		sum=0;
		for(i=0;i<(1<<n);i++)
			scanf("%d",&d[i]);
		for(i=0;i<=n-1;i++)
			for(j=0;j<(1<<i);j++)
				scanf("%d",&num);
		dfs(0,0);
		printf("Case #%d: ",cas++);
		printf("%d\n",sum);
	}
}
