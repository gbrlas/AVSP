#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
#define MAX 110
#define MOD 10007

int t,T;
int table[MAX][MAX];
int res[MAX][MAX];

int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	int i,j;
	for (t=1;t<=T;t++)
	{
		int a,b;
		for (i=0;i<MAX;i++)
			for (j=0;j<MAX;j++)
				res[i][j]=table[i][j]=0;
		res[1][1]=1;
		int n,m,r;
		scanf("%d%d%d",&n,&m,&r);
		for (i=1;i<=r;i++)
		{
			scanf("%d%d",&a,&b);
			table[a][b]=1;
		}
		int x,y;
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=m;j++)
			{
				if (res[i][j]==0 && table[i][j]==0)
				{
					x=i-1;y=j-2;
					if (x>0 && y>0)
					{
						res[i][j]+=res[x][y];
						res[i][j]%=MOD;
					}
					x=i-2;y=j-1;
					if (x>0 && y>0)
					{
						res[i][j]+=res[x][y];
						res[i][j]%=MOD;
					}
				}
			}
		}
		
		printf("Case #%d: %d\n",t,res[n][m]);
	}

	return 0;
}