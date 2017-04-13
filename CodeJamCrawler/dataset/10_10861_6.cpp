#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
int map[105][105];
int hasil[105][105];
using namespace std;
int ymax,xmax;
int cek()
{
	int tan=0;
	for(int p=0;p<=ymax;p++)
	{
		for(int q=0;q<=xmax;q++)
		{
			map[p][q]=hasil[p][q];
			if(hasil[p][q]==1)tan=1;
		}
	}
	return tan;
}


int main()
{
	int t;
	int i,j;
	scanf("%d",&t);
	for(int it=0;it<t;it++)
	{
		int r;
		scanf("%d",&r);
		int x1,y1,x2,y2;
		int x,y;
		 ymax=0;
		 xmax=0;
		memset(map,0,sizeof(map));
		memset(hasil,0,sizeof(hasil));
		for(i=0;i<r;i++)
		{
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			int temp;
			if(x1>x2)
			{
				temp=x1;
				x1=x2;
				x2=temp;
			}
			if(y1>y2)
			{
				temp=y1;
				y1=y2;
				y2=temp;
			}
			if(y2>ymax)ymax=y2;
			if(x2>xmax)xmax=x2;
			for(x=x1;x<=x2;x++)
			{
				for(y=y1;y<=y2;y++)
				{
					map[y][x]=1;
				}
			}
		}
		int jum=0;
		do
		{
			for(y=1;y<=ymax;y++)
			{
				for(x=1;x<=xmax;x++)
				{
					if(map[y][x]==1)
					{
						if(map[y-1][x]==0&&map[y][x-1]==0)hasil[y][x]=0;
						else hasil[y][x]=1;
					}
					else
					{
						if(map[y-1][x]==1&&map[y][x-1]==1)hasil[y][x]=1;
						else hasil[y][x]=0;
					}
				}
			}
			jum++;
		}while(cek()!=0);
		printf("Case #%d: %d\n",it+1,jum);
	}
	return 0;
}
