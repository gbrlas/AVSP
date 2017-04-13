#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
char map[55][55];
char huruf;
int n,k;

int cek(int x, int y, char a)
{
	int p,q;
	p=x;
	int tot=0;
	int jumlah;
	jumlah=0;
	while(map[y][p]==a)//ke kanan
	{
		tot++;
		p++;
		if(tot==k)return 1;
		if(p==n)break;
		
	}
	p=y;
	tot=0;
	while(map[p][x]==a)//ke bawah
	{
		tot++;
		p++;
		if(tot==k)return 1;
		if(p==n)break;
	}
	p=y;
	q=x;
	tot=0;
	while(map[p][q]==a)
	{
		tot++;
		p++;
		q++;
		if(tot==k)return 1;
		if(p==n||q==n)break;
	}
	p=y;
	q=x;
	tot=0;
	while(map[p][q]==a)
	{
		tot++;
		p++;
		q--;
		if(tot==k)return 1;
		if(p==n||q==n)break;
	}
	return 0;
}


int main()
{
	int t;
	scanf("%d",&t);
	for(int it=0;it<t;it++)
	{
		int i,j;
		
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)scanf("%s",map[i]);
		int temp;
		for(i=0;i<n;i++)
		{
			for(j=n-1;j>=0;j--)
			{
				if(map[i][j]=='R'||map[i][j]=='B')
				{
					temp=j;
					huruf=map[i][j];
					while(temp+1<n&&map[i][temp+1]=='.')
					{
						map[i][temp+1]=huruf;
						map[i][temp]='.';
						temp++;
						
					}
				}
			}
		}
		//for(i=0;i<n;i++)printf("%s\n",map[i]);
		int merah,biru;
		merah=0;
		biru=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(map[i][j]=='R')
				{
					if(merah==0)merah+=cek(j,i,'R');
				}
				else if(map[i][j]=='B')
				{
					if(biru==0)biru+=cek(j,i,'B');
				}
			}
		}
		printf("Case #%d: ",it+1);
		if(merah==0&&biru==0)printf("Neither\n");
		else if(merah==1&&biru==1)printf("Both\n");
		else if(merah==1)printf("Red\n");
		else if(biru==1)printf("Blue\n");
	}
	return 0;
}
