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
map<vector<int>,int>st;
vector<int>a;
vector<__int64>earn;
vector<int>te;
int r,lim,n,leng;
int main()
{
	freopen("C:\\Users\\daizhy\\Downloads\\C-large (2).in","r",stdin);
	freopen("C:\\Users\\daizhy\\Documents\\output.txt","w",stdout);
	int i,j,k,cas,c=0;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d%d%d",&r,&lim,&n);
		a.clear();
		earn.clear();
		st.clear();
		te.clear();
		for (i=0;i<n;i++)
		{
			scanf("%d",&k);
			a.push_back(k);
		}
		__int64 ans=0,re;
		bool repeat=false;
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
		/*	printf("%d\n",sum);
			for (i=0;i<n;i++)
			{
				printf("%d ",a[i]);
			}
			puts("--");*/
			if (st.find(a)!=st.end())
			{
				repeat=true;
				te=a;
				int tu=st[a];
				leng=earn.size()-tu;
				//printf("l=%d\n",leng);
				re=ans+(__int64)sum-(__int64)earn[tu];
				//printf("tu=%d\n",tu);
				//printf("%I64d\n",ans+sum);
				ans+=(__int64)sum;
				//r++;
				break;
			}
			st.insert(make_pair(a,earn.size()));
			ans+=(__int64)sum;
			//printf
			earn.push_back(ans);			
		}
		if (repeat)
		{
			//printf("%d\n",leng);
			ans+=(r/leng)*re;
			r%=leng;
			a=te;
			/*for (i=0;i<n;i++)
			{
				printf("%d ",a[i]);
			}
			puts("-");*/
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
				ans+=(__int64)sum;			
			}
		}
		printf("Case #%d: %I64d\n",++c,ans);
	}
	return 0;
}
		
		
		
