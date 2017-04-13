// SpeedLimit.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "vector"
#include "string"
#include "iostream"
#include "sstream"
#include "stdio.h"
#include "math.h"
#include "algorithm"
#include "fstream"
using namespace std;

int main()
{
	int N;
	ifstream fin("c:\\C-small-attempt0.in");
	ofstream fout("c:\\Speed.txt");
	fin>>N;
	for(int i=0;i<N;i++)
	{
		int n,m,X,Y,Z;
		fin>>n>>m>>X>>Y>>Z;
		vector<long long> A;
		for(int j=0;j<m;j++)
		{
			int t;
			fin>>t;
			A.push_back(t);
		}
		vector<int> seq;
		for(int j=0;j<n;j++)
		{
			seq.push_back(A[j % m]);
			A[j % m]=((long long)X * A[j % m] + (long long)Y * (j + 1)) % Z ;
		}
		long long dp[1002]={};
		for(int j=0;j<n;j++)
		{
			dp[j]=1;
			for(int k=0;k<j;k++)
			{
				if(seq[k]<seq[j])
					dp[j]=(dp[j]+dp[k])%1000000007;
			}
		}
		long long ans=0;
		for(int j=0;j<n;j++)
		{
			ans=(ans+dp[j])%1000000007;
		}
		fout<<"Case #"<<i+1<<": "<<ans<<endl;
	}
	return 0;
}

