#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
int a[200][200],tmp[200][200];
int main()
{
	freopen("C:\\Users\\daizhy\\Documents\\output.txt","w",stdout);
	int i,j,k,cas,cc=0,r;
	scanf("%d",&cas);
	while (cas--)
	{
		memset(a,0,sizeof(a));
		scanf("%d",&r);
		while (r--)
		{
			int x,y,z,w;
			scanf("%d%d%d%d",&x,&y,&z,&w);
			swap(x,y);
			swap(z,w);
			for (i=x;i<=z;i++)
			{
				for (j=y;j<=w;j++)
				{
					a[i][j]=1;
				}
			}
		}
		int ans=0;
		while (1)
		{
			int ff=0;
			for (i=1;i<=100;i++)
			{
				for (j=1;j<=100;j++)
				{
					if (a[i][j])
					{
						ff=1;
					}
					if (ff)break;
				}
				if (ff)break;
			}
			if (!ff)break;
			for (i=1;i<=100;i++)
			{
				for (j=1;j<=100;j++)
				{
					if (a[i][j])
					{
						if (!a[i-1][j]&&!a[i][j-1])
						{
							tmp[i][j]=0;
						}
						else 
						{
							tmp[i][j]=1;
						}
					}
					if (!a[i][j])
					{
						if (i>1&&j>1&&a[i-1][j]&&a[i][j-1])
						{
							tmp[i][j]=1;
						}
						else 
						{
							tmp[i][j]=0;
						}
					}
				}
			}
			ans++;
			memcpy(a,tmp,sizeof(tmp));
			memset(tmp,0,sizeof(tmp));
		}
		printf("Case #%d: %d\n",++cc,ans);
	}
	return 0;
}
