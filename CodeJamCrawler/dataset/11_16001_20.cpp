#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>
using namespace std;
char m[55][55];
int main()
{
	int t;
	scanf("%d",&t);
	for(int it=0;it<t;it++)
	{
		int r,c;
		scanf("%d %d",&r,&c);
		for(int i=0;i<r;i++)scanf("%s",m[i]);
		int flag = 1;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(m[i][j]=='#')
				{
					if(j+1<c&&i+1<r)
					{
						if(m[i][j+1]=='#'&&m[i+1][j]=='#'&&m[i+1][j+1]=='#')
						{
							m[i][j]='/';
							m[i][j+1]='\\';
							m[i+1][j]='\\';
							m[i+1][j+1]='/';
						}
						else flag = 0;
					}
					else flag=0;
				}
				if(flag==0)break;
			}
			if(flag==0)break;
		}
		printf("Case #%d:\n",it+1);
		if(flag==0)printf("Impossible\n");
		else
		{
			for(int i=0;i<r;i++)printf("%s\n",m[i]);
		}
	}
	return 0;
}
