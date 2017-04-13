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

int g[2048]={};
void dfs(int N,int l, int r)
{
	int d[2048]={};
	if(N==0) return;
	int j=l;
	for(int i=l;i<r;i+=2)
	{
		d[j++]=g[i];
	}
	for(int i=l+1;i<r;i+=2)
	{
		d[j++]=g[i];
	}
	for(int i=l;i<r;i++)
		g[i]=d[i];
	dfs(N-1,l,(l+r)/2);
	dfs(N-1,(l+r)/2,r);
}
int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int N;
		long long P;
		cin>>N>>P;
		memset(g,0,sizeof(g));
		for(int i=0;i<(1<<N);i++)
			g[i]=i;
		dfs(N,0,1<<N);
		int ans1=0;
		for(int i=0;i<P;i++)
		{
			ans1=max(g[i],ans1);
		}
		int ans2=(1<<N)-1;
		for(int i=P;i<(1<<N);i++)
		{
			ans2=min(g[i]-1,ans2);
		}
		cout<<"Case #"<<tc+1<<": "<<ans2<<" "<<ans1<<endl;
	}
	return 0;
}

//A
//long long calc(int N, int n)
//{
//	long long start = N;
//	long long end = N-n+1;
//	long long ans=(start+end)*n/2;
//	return ans;
//}
//
//int cmp(const pair<int,int> &a,const pair<int,int> &b)
//{
//	if(a.first!=b.first)
//		return a.first<b.first;
//	return a.second>b.second;
//}
//int main()
//{
//	int T;
//	cin>>T;
//	for(int tc=0;tc<T;tc++)
//	{
//		int N,M;
//		cin>>N>>M;
//		vector<pair<int,int> > g;
//		vector<long long> total;
//		for(int i=0;i<M;i++)
//		{
//			int x,y,p;
//			cin>>x>>y>>p;
//			g.push_back(make_pair(x,p));
//			g.push_back(make_pair(y,-p));
//			total.push_back(calc(N,y-x)*p);
//		}
//		sort(g.begin(),g.end(),cmp);
//		vector<pair<int,int> > passengers;
//		vector<long long> ans;
//		for(int i=0;i<g.size();i++)
//		{
//			if(g[i].second>0)
//			{
//				passengers.push_back(make_pair(g[i].first,g[i].second));
//			}
//			else
//			{
//				int cur=-g[i].second;
//				while(cur>0)
//				{
//					int x=passengers[passengers.size()-1].first;
//					int y=passengers[passengers.size()-1].second;
//					if(y>cur)
//					{
//						ans.push_back(calc(N,g[i].first-x)*cur);
//						y-=cur;
//						passengers[passengers.size()-1].second=y;
//						cur=0;
//					}
//					else
//					{
//						ans.push_back(calc(N,g[i].first-x)*y);
//						cur-=y;
//						passengers.pop_back();
//					}
//				}
//			}
//		}
//		int i=0,j=0;
//		long long ccc=0;
//		while(i<total.size())
//		{
//			ccc+=total[i];
//			i++;
//			while(j<ans.size())
//			{
//				if(ccc>=ans[j])
//				{
//					ccc-=ans[j];
//					j++;
//				}
//				else
//				{
//					break;
//				}
//			}
//		}
//		cout<<"Case #"<<tc+1<<": "<<ccc<<endl;
//	}
//}