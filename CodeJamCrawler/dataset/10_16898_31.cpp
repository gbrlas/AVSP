#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<map>
#include<vector>

using namespace std;
int a[110][110];
int c[]={-1,0};
int d[]={0,-1};
int m,n;
int b[110][110];
bool die()
{
	int i,j;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
			if(a[i][j])
				break;
		if(j<=n)
			break;
	}
	return i>m;
}
bool ok(int x,int y)
{
	if(x>=1 && x<=m && y>=1 && y<=n)
		return true;
	return false;
}
void change()
{
	int i,j,k,x,y;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			b[i][j]=a[i][j];
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			if(b[i][j])
			{
				if( (!ok(i-1,j) || b[i-1][j] ==0) && (!ok(i,j-1) || b[i][j-1]==0))
					a[i][j]=0;
			}
			else
			{
				if((ok(i-1,j) && b[i-1][j]) && (ok(i,j-1) && b[i][j-1]))
					a[i][j]=1;
			}
		}
}
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("temp.txt","w",stdout);
	
	int t,cas=1;
	int i,j,num;
	int x1,y1,x2,y2;
	
	scanf("%d",&t);
	while(t--)
	{		
		scanf("%d",&num);
		m=n=0;
		memset(a,0,sizeof(a));
		while(num--)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if(x2>m) m=x2;
			if(y2>n) n=y2;
			for(i=x1;i<=x2;i++)
				for(j=y1;j<=y2;j++)
					a[i][j]=1;
		}
		num=0;
		while(1)
		{
			if(die())
				break;
			num++;
			change();
		}
		printf("Case #%d: ",cas++);
		printf("%d\n",num);
	}
}
