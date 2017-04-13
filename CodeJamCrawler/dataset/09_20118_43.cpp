#include<iostream>
#include<algorithm>

using namespace std;

int H,W;
int mat[100][100];
int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
char s[10001];
char* label[100][100];
int now=0;

bool extractMin(int &_x,int &_y)
{
	int i;
	int x=_x,y=_y;
	int now=mat[x][y];
	for(i=0;i<4;i++)
	{
		if(x+dir[i][0] <0 || x+dir[i][0] >=H || y+dir[i][1]<0 || y+dir[i][1] >=W)
			continue;
		if(mat[x+dir[i][0]][y+dir[i][1]]<now)
		{
			now=mat[x+dir[i][0]][y+dir[i][1]];
			_x=x+dir[i][0];
			_y=y+dir[i][1];
		}
	}
	if(x==_x && y==_y)
		return false;
	return true;
}

void sourceFrom(int x,int y)
{
	label[x][y]=&s[now];
	if(!extractMin(x,y))
	{
		if(now==0)
		{
			s[now++]='a';
		//	printf("%d %d :)\n",x,y);
		}
		else
		{
			s[now]=s[now-1]+1;
			now++;//printf("%d %d :)\n",x,y);
		}
	}
	else
	{
		if(label[x][y])
		{
			s[now++]=*label[x][y];//printf("%d %d :)\n",x,y);
		}
		else
		{
			sourceFrom(x,y);
		}
	}
}

int main()
{
	int id;
	int nCase;
	int i,j,k;
	scanf("%d",&nCase);
	for(id=1;id<=nCase;id++)
	{
		now=0;
		memset(label,0,sizeof(label));
		cin>>H>>W;
		for(i=0;i<H;i++)
		{
			for(j=0;j<W;j++)
				scanf("%d",&mat[i][j]);
		}

		for(i=0;i<H;i++)
		{
			for(j=0;j<W;j++)
			{
				if(label[i][j]==0)
				{
				//	cout<<"now: "<<i<<" "<<j<<endl;
					sourceFrom(i,j);
				}
			}
		}
		printf("Case #%d:\n",id);
		for(i=0;i<H;i++)
		{
			printf("%c",*label[i][0]);
			for(j=1;j<W;j++)
			{
				printf(" %c",*label[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}