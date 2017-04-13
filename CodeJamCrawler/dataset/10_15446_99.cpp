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
set<vector<int> >st;
vector<int>a;
int r,lim,n;
int main()
{
	freopen("C:\\Users\\daizhy\\Documents\\output.txt","w",stdout);
	int i,j,k,cas,c=0;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d%d%d",&r,&lim,&n);
		a.clear();
		for (i=0;i<n;i++)
		{
			scanf("%d",&k);
			a.push_back(k);
		}
		__int64 ans=0;
		while (1)
		{
			r--;
			if (r==-1)break;
			int sum=0,tt=0;
			while (1)
			{
				int ty=*a.begin();
				sum+=ty;
				tt++;
				if (sum>lim)
				{
					sum-=ty;break;
				}
				if (tt==n)break;
				a.erase(a.begin());
				a.push_back(ty);
			}
			//printf("%d\n",sum);
			ans+=(__int64)sum;
			/*for (i=0;i<n;i++)
			{
				printf("%d ",a[i]);
			}
			puts("");*/
		}
		printf("Case #%d: %I64d\n",++c,ans);
	}
	return 0;
}
		
		
		
