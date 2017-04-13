#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
#define MAX 30010
#define INF 10000
int t,T;
int V[MAX];
int TT[MAX];
int res[MAX][2];
bool visited[MAX][2];

int Run(int num,int r)
{
	if (!visited[num][r])
	{
		visited[num][r]=true;
		if (TT[num]==2)
		{
			if (r==V[num])
				res[num][r]=0;
			else
				res[num][r]=INF;
		}
		else {
		int R=INF;
		int a;
		if (r==0 && TT[num]==0)
		{
			a=Run(num*2,0);
			if (a<R)
				R=a;
			a=Run(num*2+1,0);
			if (a<R)
				R=a;
		}
		else if (r==1 && TT[num]==0)
		{
			a=Run(num*2+1,1)+Run(num*2,1);
			if (a<R) R=a;
			if (V[num]==1)
			{
				a=min(Run(num*2+1,1),Run(num*2,1));
				if (a+1<R)
					R=a+1;
			}
		}
		else if (r==0 && TT[num]==1)
		{
			a=Run(num*2+1,0)+Run(num*2,0);
			if (a<R) R=a;
			if (V[num]==1)
			{
				a=min(Run(num*2+1,0),Run(num*2,0));
				if (a+1<R)
					R=a+1;
			}
		}
		else if (r==1 && TT[num]==1)
		{
			a=Run(num*2,1);
			if (a<R)
				R=a;
			a=Run(num*2+1,1);
			if (a<R)
				R=a;
		}
		res[num][r]=R;
		}
	}
	return res[num][r];
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("1.out","w",stdout);
	int i,j;
	scanf("%d",&T);
	for (t=1;t<=T;t++)
	{
		memset(V,0,sizeof(V));
		memset(TT,0,sizeof(TT));
		for (i=0;i<MAX;i++)
			for (j=0;j<2;j++)
				visited[i][j]=false;
		int n,v;
		int a,b;
		scanf("%d%d",&n,&v);
		for (i=1;i<=(n-1)/2;i++)
		{
			scanf("%d%d",&TT[i],&V[i]);
			TT[i]=1-TT[i];
		}
		for (i=1+((n-1)/2);i<=n;i++)
		{
			scanf("%d",&V[i]);
			TT[i]=2;
		}
		Run(1,v);
		printf("Case #%d: ",t); 
		if (res[1][v]!=INF)
			printf("%d\n",res[1][v]);
		else
			printf("IMPOSSIBLE\n");
	}

	return 0;
}