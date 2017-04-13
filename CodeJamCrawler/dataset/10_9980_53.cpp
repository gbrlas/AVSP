// ThemePark.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int R,k,N;
		cin>>R>>k>>N;
		vector<int> g;
		for(int i=0;i<N;i++)
		{
			int tmp;
			cin>>tmp;
			g.push_back(tmp);
		}
		int cur=0,left=k;
		long long ans=0;
		for(int i=1;i<=R;i++)
		{
			int old=cur;
			while(cur<old+N && left>=g[cur%N])
			{
				left-=g[cur%N];
				ans+=g[cur%N];
				cur++;
			}
			cur=cur%N;
			left=k;
		}
		cout<<"Case #"<<tc+1<<": "<<ans<<endl;
	}
	return 0;
}

