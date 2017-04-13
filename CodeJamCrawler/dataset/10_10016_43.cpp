// ProblemB.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "sstream"
using namespace std;
#define INF 0x1fffffff
int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int P;
		cin>>P;
		vector<int> M;
		int dp[2048][15]={};
		for(int i=0;i<2048;i++)
			for(int j=0;j<15;j++)
				dp[i][j]=INF;
		for(int i=0;i<(1<<P);i++)
		{
			int start=1<<(P);
			int t;
			cin>>t;
			M.push_back(t);
			for(int j=0;j<=t;j++)
				dp[start+i][j]=0;
		}
		int heap[2048]={};
		for(int i=0;i<P;i++)
		{
			int start=1<<(P-i-1);
			for(int j=0;j<(1<<(P-i-1));j++)
			{
				cin>>heap[start+j];
			}
		}

		for(int i=P-1;i>=0;i--)
		{
			int start=1<<i;
			for(int j=0;j<(1<<i);j++)
			{
				int pos=start+j;
				for(int n=0;n<=10;n++)
				{
					dp[pos][n]=min(dp[pos][n],dp[pos*2][n]+dp[pos*2+1][n]+heap[pos]);
					if(n>0)
						dp[pos][n-1]=min(dp[pos][n-1],dp[pos*2][n]+dp[pos*2+1][n]);
				}
			}
		}
		int ans=INF;
		for(int j=0;j<11;j++)
			ans=min(ans,dp[1][j]);
		cout<<"Case #"<<tc+1<<": "<<ans<<endl;
	}
	return 0;
}

