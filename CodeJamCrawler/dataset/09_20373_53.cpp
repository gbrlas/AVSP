#include<windows.h>
#include<stdio.h>
#include<vector>
#include<string>

using namespace std;


const int maxn=100+5;

int mapB[maxn][maxn];
int visited[maxn][maxn];
int sol[maxn][maxn];
int H,W;
void init()
{
	
	scanf("%d %d",&H,&W);
	printf("\n");
	for (int i=1;i<=H;i++) 
	{
		for (int j=1;j<=W;j++) 
		{
			scanf("%d",&mapB[i][j]);
			visited[i][j]=-1;
			sol[i][j]=-1;
		}
	}
}
void traverse(int  &i, int &j)
{
	int tempi;
	int tempj;
	int tempp;
	int tempq;

	tempi=tempp=i;
	tempj=tempq=j;

	int min = mapB[i][j];

	if(i!=1)
	{
		if(mapB[i-1][j] < min)
		{
			min = mapB[i-1][j];
			tempi=i-1;
			tempj=j;
		}
	}
	if(j!=1)
	{
		if(mapB[i][j-1] < min)
		{
			min = mapB[i][j-1];
			tempi=i;
			tempj=j-1;
		}
	}
	
	if(j!=W)
	{
		if(mapB[i][j+1] < min)
		{
			min = mapB[i][j+1];
			tempi=i;
			tempj=j+1;

		}
	}
	if(i!=H)
	{
		if(mapB[i+1][j] < min)
		{
			min = mapB[i+1][j];
			tempi=i+1;
			tempj=j;
		}
	}
	if(i==tempi && j==tempj)
	{
		visited[tempp][tempq] = (W * (i-1)) + j-1;
		return;
	}
	else
	{
		i=tempi;
		j=tempj;
		traverse(i,j);
		visited[tempp][tempq] = (W * (i-1)) + j-1;
	}

}
void printsol()
{
	for(int i=1;i<=H;i++)
	{
		for(int j=1;j<W;j++)
		{
			printf("%c ",sol[i][j]);
		
		}
		printf("%c\n",sol[i][j]);
		//printf("\n");
	}
}
void createsol()
{
	int currentletter=96;
	int temp;
	for(int k=0; k<(H*W);k++)
		{

			temp= visited[(k/W)+1][(k%W +1)];
			
			if(sol[(k/W)+1][(k%W +1)] == -1)
			{
				currentletter++;
				for(int i=1;i<=H;i++)
					for(int j=1;j<=W;j++)
					{
						if(visited[i][j] == temp && sol[i][j]==-1)
							sol[i][j]=currentletter;
					}
			}
			
		}
}

void solve()
{
	int tempi,tempj;
	for(int i=1;i<=H;i++)
		for(int j=1;j<=W;j++)
		{
			tempi=i;
			tempj=j;
			if(visited[i][j]==-1)
				traverse(tempi,tempj);	
		}
}


void main()
{
	freopen("C:\\A-large.in","r",stdin);
	freopen("C:\\A-large.out","w",stdout);
	int testcase;
	int ret=0;
	scanf("%d",&testcase);
	for (int caseId=1;caseId<=testcase;caseId++)
	{
		printf("Case #%d: ",caseId);
		init();
		solve();
		createsol();
		printsol();
		fflush(stdout);
	}


}


