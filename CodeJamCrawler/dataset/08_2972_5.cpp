#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int label[150][150];
int ans[150][150];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int nt;
	scanf("%d", &nt);
	for (int it=1;it<=nt;it++)
	{
		int n,m,r;
		scanf("%d%d%d",&n,&m,&r);
		memset(label,0,sizeof(label));
		memset(ans,0,sizeof(ans));
		for (int i=0;i<r;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			a--;
			b--;
			label[a][b]=1;
		}
		ans[0][0]=1;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				if (ans[i][j]>0)
				{
					if (!label[i+1][j+2])
						ans[i+1][j+2]=(ans[i+1][j+2]+ans[i][j])%10007;
					if (!label[i+2][j+1])
						ans[i+2][j+1]=(ans[i+2][j+1]+ans[i][j])%10007;
				}
			}
		}
		printf("Case #%d: %d\n",it,ans[n-1][m-1]);
	}
	return 0;
}
