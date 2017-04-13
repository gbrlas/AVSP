#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;
char s[110][110];
int v[110][110],head[110];
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("temp.txt","w",stdout);
	
	int t,cas=1;
	int i,j,k;
	int n,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&c);
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		memset(v,0,sizeof(v));
		for(i=0;i<n;i++)
			head[i]=n-1;
		for(i=0;i<n;i++)
		{
			for(j=n-1;j>=0;j--)
				if(s[i][j]=='R')
				{
					v[head[n-i-1]--][n-i-1]=1;
				}
				else if(s[i][j]=='B')
				{
					v[head[n-i-1]--][n-i-1]=-1;
				}
		}
	
		bool f1=false;
		bool f2=false;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				int x=i,y=j;
				if(v[i][j]!=0)
				{
					int num=0;
					k=0;
					while(x+k<n&&v[x+k][y]==v[i][j])
					{
						num++;
						k++;
					}
					if(num>=c)
					{
						if(v[i][j]==1)
							f1=true;
						else if(v[i][j]==-1)
							f2=true;
					}
					num=0;
					k=0;
					while(y+k<n&&v[x][y+k]==v[i][j])
					{
						num++;
						k++;
					}
					if(num>=c)
					{
						if(v[i][j]==1)
							f1=true;
						else if(v[i][j]==-1)
							f2=true;
					}
					num=0;
					k=0;
					while(x+k<n&&y+k<n&&v[x+k][y+k]==v[i][j])
					{
						num++;
						k++;
					}
					if(num>=c)
					{
						if(v[i][j]==1)
							f1=true;
						else if(v[i][j]==-1)
							f2=true;
					}
					num=0;
					k=0;
					while(x-k>=0&&y+k<n&&v[x-k][y+k]==v[i][j])
					{
						num++;
						k++;
					}
					if(num>=c)
					{
						if(v[i][j]==1)
							f1=true;
						else if(v[i][j]==-1)
							f2=true;
					}	
				}
			}
		printf("Case #%d: ",cas++);
		if(f1&&f2)
			printf("Both");
		else if(f1)
			printf("Red");
		else if(f2)
			printf("Blue");
		else printf("Neither");
		printf("\n");
	}
}
