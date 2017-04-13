// GCJ2012Round2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "string.h"
#include "math.h"
#include "stdio.h"
#include "map"

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int N;
		cin>>N;
		vector<pair<int,int> > g;
		for(int i=0;i<N;i++)
		{
			int d,l;
			cin>>d>>l;
			g.push_back(make_pair(d,l));
		}
		int D;
		cin>>D;
		long long dp[10005]={};
		dp[0]=g[0].first*2LL;
		int good=0;
		for(int i=0;i<N;i++)
		{
			int cur=g[i].first;
			if(dp[i]>=D)
			{
				good=1;
				break;
			}
			for(int j=i+1;j<g.size();j++)
			{
				int d=g[j].first;
				int len=dp[i];
				if(len<d) break;
				dp[j]=max(dp[j],0LL+d+d-cur);
				dp[j]=min(dp[j],0LL+d+g[j].second);
			}
		}
		if(good)
		{
			cout<<"Case #"<<tc+1<<": YES"<<endl;
		}
		else
		{
			cout<<"Case #"<<tc+1<<": NO"<<endl;
		}
	}
	return 0;
}

