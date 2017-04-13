#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main()
{
	freopen("A-small.in", "r", stdin);
    freopen("A-small.txt", "w", stdout);
	int t,i;
	char ans[30];
	int mat[4][4],r,c,a,b,m2[4],count,no;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		count=0;
		scanf("%d",&a);
		a--;
		for(r=0;r<4;r++)
		{
			for(c=0;c<4;c++)
				scanf("%d",&mat[r][c]);
		}
		for(c=0;c<4;c++)
			m2[c]=mat[a][c];
		scanf("%d",&b);
		b--;
		for(r=0;r<4;r++)
		{
			for(c=0;c<4;c++)
			{
				scanf("%d",&mat[r][c]);
			}
		}
		for(c=0;c<4;c++)
		{
			if(mat[b][c]==m2[0])
			{
				count++;
				no=m2[0];
			}
			if(mat[b][c]==m2[1])
			{
				count++;
				no=m2[1];
			}
			if(mat[b][c]==m2[2])
			{
				count++;
				no=m2[2];
			}
			if(mat[b][c]==m2[3])
			{
				count++;
				no=m2[3];
			}
		}
		if(count==0)
			strcpy(ans,"Volunteer cheated!");
		else if(count==1)
			itoa(no,ans,10);
		else
			strcpy(ans,"Bad magician!");
		printf("Case #%d: %s\n",i,ans);
	}
}
