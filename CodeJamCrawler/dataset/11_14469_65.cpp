// 2011Round1C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "string.h"
#include "math.h"
using namespace std;


int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int L,N,C;
		long long t;
		cin>>L>>t>>N>>C;
		vector<int> a(C);
		for(int i=0;i<C;i++)
		{
			cin>>a[i];
		}
		vector<int> g;
		for(int i=0;i<N;i++)
		{
			g.push_back(a[i%C]);
		}
		long long sum=0;
		vector<int> chosen;
		int first=1;
		for(int i=0;i<N;i++)
		{
			sum+=g[i]*2;
			if(sum>=t)
			{
				if(first)
				{
					chosen.push_back((sum-t)/2);
				}
				else
				{
					chosen.push_back(g[i]);
				}
				first=0;
			}
		}
		sort(chosen.rbegin(),chosen.rend());
		for(int i=0;i<L;i++)
		{
			if(i==chosen.size()) break;
			sum-=chosen[i];
		}
		cout<<"Case #"<<tc+1<<": "<<sum<<endl;
	}
	return 0;
}

