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


int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int N,M;
		cin>>N>>M;
		int g[105][105]={};
		int r[105]={};
		int c[105]={};
		for(int i=0;i<N;i++)
		{
			int h=0;
			for(int j=0;j<M;j++)
			{
				cin>>g[i][j];
				h=max(h,g[i][j]);
			}
			r[i]=h;
		}
		for(int j=0;j<M;j++)
		{
			int h=0;
			for(int i=0;i<N;i++)
			{
				h=max(h,g[i][j]);
			}
			c[j]=h;
		}
		int g1[105][105]={};
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				g1[i][j]=r[i];
			}
		}
		for(int j=0;j<M;j++)
		{
			for(int i=0;i<N;i++)
			{
				g1[i][j]=min(g1[i][j],c[j]);
			}
		}
		int isgood=1;
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				if(g[i][j]!=g1[i][j])
					isgood=0;
		cout<<"Case #"<<tc+1<<": ";
		if(isgood)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}

