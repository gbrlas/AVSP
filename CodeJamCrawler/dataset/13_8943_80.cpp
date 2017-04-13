/* fAnSKyer */
/* 11-02-2010 */
/* replace DT lattice*/
/* Useage: */
/* Directory E:\FeatureProcessor */


#pragma warning (disable:4786) 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int s[200][200],st[200][200];
int f[200];
int g[200];
int n,m,t;
int checkv(int x,int y)
{
	for (int i=x+1;i<n;i++)
		if (s[i][y]>s[x][y]) return 1;
	return 0;
}
int pcheckv(int x,int y)
{
	for (int i=0;i<x;i++)
		if (s[i][y]>s[x][y]) return 1;
	return 0;
}

int checkh(int x,int y)
{
	for (int i=y+1;i<m;i++)
		if (s[x][i]>s[x][y]) return 1;
	return 0;
}

int pcheckh(int x,int y)
{
	for (int i=0;i<y;i++)
		if (s[x][i]>s[x][y]) return 1;
	return 0;
}

int check()
{
	int i,j,flag,sum;
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	{
		flag=1;
		if (pcheckv(i,j)==0 && checkv(i,j)==0) flag=0;
		if (pcheckh(i,j)==0 && checkh(i,j)==0) flag=0;

		if (flag==1) return 0;
	}
	return 1;
}
int main(int argc,char* argv[])
{
	char name[500],ch[500];	
	int i,j,v,cnt=0,temp;
	int cas, ans=1;
	/* read the dictionary */
	freopen("B-small-attempt3.in","r",stdin); //B-small-attempt0.in
	freopen("output.txt","w",stdout);
	scanf("%d",&cas);
	for(t=0;t<cas;t++)
	{
		//memset(s,0,sizeof(s));
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			scanf("%d",&s[i][j]);		
		}
		printf("Case #%d: ",t+1);
		memset(f,0,sizeof(f));
		
		/*
		printf("%d %d\n",n,m);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				printf("%d",s[i][j]);
			printf("\n");
		}
		*/
		if (check()==0) ans=0; 
		else ans=1;
			
		if (ans==0)
		printf("NO\n");
		else printf("YES\n");

	}
}
