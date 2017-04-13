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
map<pair<int,int>,int>mp;
int win(int q,int w)//2 win 1 lose
{
	
	if (q==w)return 1;
	if (w%q==0)return 2;
	if (w/q>=2)return 2;
	if (!q)return 2;
	if (mp[make_pair(q,w)]!=0)return mp[make_pair(q,w)];
	int i,j,k,tmp,tr=0;
	for (tmp=q;tmp<=w;tmp+=q)
	{
		int tx=w-tmp;
		int ty=q;
		if (tx>ty)swap(tx,ty);
		if (win(tx,ty)==1)
		{
			tr=1;break;
		}
	}
	if (tr)
	{
		mp[make_pair(q,w)]=2;
		return 2;
	}
	mp[make_pair(q,w)]=1;
	return 1;
}
int main()
{
	//printf("%d\n",win(3,1000000));
	freopen("C:\\Users\\daizhy\\Documents\\output.txt","w",stdout);
	int i,j,k,cas,ccc=0;
	scanf("%d",&cas);
	while (cas--)
	{
		int a1,a2,b1,b2,sum=0;
		scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
		for (i=a1;i<=a2;i++)
		{
			for (j=b1;j<=b2;j++)
			{
				//mp.clear();
				int tx=i,ty=j;
				if (tx>ty)swap(tx,ty);
				if (win(tx,ty)==2)
				{
					sum++;
				}
				
			}
		}
		printf("Case #%d: %d\n",++ccc,sum);
	}
	return 0;
}
