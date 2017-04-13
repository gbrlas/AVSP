/*
Filename:  1.cpp
Author: spracle
Created:  2008年07月27日 17时12分47秒
*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int p,n,k,l;long long res;

int main()
{
	freopen("A-small.in","r",stdin);
	freopen("A-small.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		vector<int>f;
		scanf("%d %d %d",&p,&k,&l);
		for(int ii=0;ii<l;ii++)
		{
			int tp;scanf("%d",&tp);
			f.push_back(tp);
		}
		sort(f.begin(),f.end(),greater<int>());
		int cntt=0;res=0;bool flag=0;
		for(int t=0;t<l;t+=k)
		{
			if(flag) break;
			++cntt;
			for(int o=0;o<k;o++)
			{
				if((t+o)>=l) 
				{
					flag=1;
					break;
				}
				else 
					res+=f[o+t]*cntt;
			}
	
		}

		printf("Case #%d: %lld\n",i,res);
	}

	return 0;
}



