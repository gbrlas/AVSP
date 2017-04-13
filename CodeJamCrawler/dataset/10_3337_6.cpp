#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int cell[101][101];
int cell1[101][101];
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int cas;
	cin >> cas;
	int cass=1;
	while(cas--)
	{
		memset(cell,0,sizeof(cell));
		int r,x,y,x1,y1;
		cin >> r;
		for(int i=0;i<r;i++)
		{
			cin  >> x >> y >> x1 >> y1;
			for(int j=x;j<=x1;j++)
				for(int k=y;k<=y1;k++)
					cell[k][j]=1;
		}
		int sum=0;
		while(true)
		{
			int num=0;
			memset(cell1,0,sizeof(cell1));
			for(int i=1;i<=100;i++)
				for(int j=1;j<=100;j++)
				{
					if(cell[i-1][j]==0&&cell[i][j-1]==0)cell1[i][j]=0;
					else if(cell[i-1][j]==1&&cell[i][j-1]==1)cell1[i][j]=1;
					else cell1[i][j]=cell[i][j];
					if(cell1[i][j]==1)num++;
				}
			sum++;
			if(num==0)break;
			memcpy(cell,cell1,sizeof(cell));
		}
		printf("Case #%d: %d\n",cass++,sum);
	}
}