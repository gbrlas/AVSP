// 2011Round2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "math.h"
using namespace std;

int cmp(const pair<pair<int,int>,int> &a, const pair<pair<int,int>,int> &b)
{
	if(a.second==b.second)
		return a>b;
	return a.second<b.second;
}

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int X,S,R,T,N;
		cin>>X>>S>>R>>T>>N;
		vector<pair<pair<int,int>,int> > g;
		for(int i=0;i<N;i++)
		{
			int b,e,w;
			cin>>b>>e>>w;
			g.push_back(make_pair(make_pair(b,e),S+w));
		}
		sort(g.begin(),g.end());
		int cur=0;
		int nn=g.size();
		for(int i=0;i<nn;i++)
		{
			if(cur<g[i].first.first)
			{
				g.push_back(make_pair(make_pair(cur,g[i].first.first),S));
			}
			cur=g[i].first.second;
		}
		if(cur<X)
			g.push_back(make_pair(make_pair(cur,X),S));
		sort(g.begin(),g.end(),cmp);
		//cout<<"Case #"<<tc+1<<": "<<ans<<endl;
		double ans=0;
		double t=T;
		for(int i=0;i<g.size();i++)
		{
			int b=g[i].first.first;
			int e=g[i].first.second;
			int v=g[i].second;
			if(t>0)
			{
				if(t*(v+R-S)>e-b)
				{
					double time=(double)(e-b)/(v+R-S);
					t-=time;
					ans+=time;
				}
				else
				{
					double time=t+(double)(e-b-t*(v+R-S))/v;
					ans+=time;
					t=0;
				}
			}
			else
			{
				ans+=(double)(e-b)/v;
			}
		}
		printf("Case #%d: %.8lf\n",tc+1,ans);
	}
	return 0;
}

