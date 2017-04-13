// 2011Round1B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "string.h"
#include "stdio.h"

using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int C,D;
		cin>>C>>D;
		vector<pair<int,int> > g;
		for(int i=0;i<C;i++)
		{
			int P,V;
			cin>>P>>V;
			g.push_back(make_pair(P,V));
		}
		sort(g.begin(),g.end());
		double ans=0;
		double last=0;
		for(int i=0;i<g.size();i++)
		{
			long long v=g[i].second;
			long long l=(v-1)*D;
			double t=(double)l/2;
			if(i>0)
			{
				double ll=-t+g[i].first;
				double lp=ll;
				double rp=ll;
				if(ans>t)
				{
					lp=lp-(ans-t);
					rp=rp+(ans-t);
				}
				else
				{
					last-=(t-ans);
				}
				if(last+D>rp)
				{
					t=max(ans,t)+(last+D-rp)/2;
					last=t+g[i].first;
				}
				else
				{
					last=max(lp,last+D)+l;
				}
			}
			else
			{
				last=t+g[i].first;
			}
			if(ans<t)
				ans=t;
		}
		cout<<"Case #"<<tc+1<<": "<<ans<<endl;
	}
	return 0;
}

