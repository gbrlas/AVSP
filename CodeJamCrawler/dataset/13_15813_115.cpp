// QualRound.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "vector"
#include "string.h"
#include "algorithm"
#include "stdio.h"
using namespace std;

int ispal(long long t)
{
	int g[105]={};
	int p=0;
	while(t)
	{
		g[p++]=t%10;
		t/=10;
	}
	int l=0, r=p-1;
	while(l<r)
	{
		if(g[l]!=g[r]) return 0;
		l++; r--;
	}
	return 1;
}

int main()
{
	int T;
	cin>>T;
	vector<long long> g;
	for(int i=1;i<=10000000;i++)
	{
		if(!ispal(i)) continue;
		long long t=1LL*i*i;
		if(ispal(t))
			g.push_back(t);
	}
	for(int tc=0;tc<T;tc++)
	{
		long long A,B;
		cin>>A>>B;
		int ans=upper_bound(g.begin(),g.end(),B)-lower_bound(g.begin(),g.end(),A);
		cout<<"Case #"<<tc+1<<": "<<ans<<endl;
	}
	return 0;
}

