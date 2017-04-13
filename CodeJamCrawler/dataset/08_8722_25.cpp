// Saving_the_Universe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "stdio.h"
#include "math.h"
#include "fstream"
#include "vector"
#include "map"
using namespace std;

int main()
{
	int Case;
	cin>>Case;
	ofstream fout("c:\\Saving_the_Universe.txt");
	for(int idx=0;idx<Case;idx++)
	{
		int N,S;
		char garbage[256];
		cin>>N;
		cin.getline(garbage,256);
		map<string,int> engines;
		for(int i=0;i<N;i++)
		{
			char buf[1024];
			cin.getline(buf,1024);
			string eng(buf);
			engines[eng]=i+1;
		}
		cin>>S;
		cin.getline(garbage,256);
		vector<int> g;
		for(int i=0;i<S;i++)
		{
			char buf[1024];
			cin.getline(buf,1024);
			string eng(buf);
			if(engines.find(eng)!=engines.end())
			{
				g.push_back(engines[eng]);
			}
			else
			{
				g.push_back(0);
			}
		}
		//DP
		int dp[101][1001]={};
		for(int x=1;x<=N;x++)
			if(x!=g[0]) dp[x][1]=0;
			else dp[x][1]=99999999;
		
		for(int j=2;j<=S;j++)
		{
			for(int x=1;x<=N;x++)
			{
				dp[x][j]=99999999;
				int cc=g[j-1];
				if(x!=g[j-1])
					dp[x][j]=dp[x][j-1];
				for(int y=1;y<=N;y++)
				{
					if(x==y) continue;
					if(x==g[j-1]) continue;
					if(dp[y][j-1]+1<dp[x][j])
						dp[x][j]=dp[y][j-1]+1;
				}
			}
		}
		int ans=dp[1][S];
		for(int k=1;k<=N;k++)
			if(dp[k][S]<ans) ans=dp[k][S];
		fout<<"Case #"<<idx+1<<": "<<ans<<endl;
	}

	return 0;
}