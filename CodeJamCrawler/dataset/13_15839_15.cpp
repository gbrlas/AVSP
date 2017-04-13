// Round2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "string"
#include "vector"
#include "iostream"
#include "algorithm"
#include "stdio.h"
#include "string.h"
using namespace std;

long long calc(int N, int n)
{
	long long start = N;
	long long end = N-n+1;
	long long ans=(start+end)*n/2;
	return ans;
}

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int N,M;
		cin>>N>>M;
		vector<pair<int,int> > g;
		long long total=0;
		for(int i=0;i<M;i++)
		{
			int x,y,p;
			cin>>x>>y>>p;
			for(int j=0;j<p;j++)
				g.push_back(make_pair(x,1));
			for(int j=0;j<p;j++)
				g.push_back(make_pair(y,2));
			for(int j=0;j<p;j++)
				total+=calc(N,y-x);
		}
		sort(g.begin(),g.end());
		vector<int> passengers;
		long long ans=0;
		for(int i=0;i<g.size();i++)
		{
			if(g[i].second==1)
			{
				passengers.push_back(g[i].first);
			}
			else
			{
				int x=passengers[passengers.size()-1];
				passengers.pop_back();
				ans+=calc(N,g[i].first-x);
			}
		}
		cout<<"Case #"<<tc+1<<": "<<total-ans<<endl;
	}
}