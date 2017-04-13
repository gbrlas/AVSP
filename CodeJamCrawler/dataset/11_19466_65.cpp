#include<iostream>
using namespace std;
int R,C;
char maze[55][55];
bool cantran()
{
	int i,j;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			if(maze[i][j]=='#')
			{
				if(j+1==C||maze[i][j+1]!='#')
					return false;
				if(i+1==R||maze[i+1][j]!='#'||maze[i+1][j+1]!='#')
					return false;
				maze[i][j]='/';
				maze[i][j+1]='\\';
				maze[i+1][j]='\\';
				maze[i+1][j+1]='/';
			}
		}
	}
	return true;
}
int main()
{
	//freopen("A-large.in","r",stdin);
	//freopen("A-large.out","w",stdout);
	int T,Case=0;
	int i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&R,&C);
		for(i=0;i<R;i++)
			scanf("%s",maze[i]);
		printf("Case #%d:\n",++Case);
		if(cantran())
		{
			for(i=0;i<R;i++)
				printf("%s\n",maze[i]);
		}
		else
			printf("Impossible\n");
	}
	return 0;
}
