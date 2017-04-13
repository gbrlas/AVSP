// TextMessage.cpp : 定义控制台应用程序的入口点。
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
	ifstream fin("c:\\A-small-attempt0.in");
	ofstream fout("c:\\TextMessage.txt");
	fin>>N;
	for(int i=0;i<N;i++)
	{
		int P,K,L;
		fin>>P>>K>>L;
		vector<int> freq;
		for(int j=0;j<L;j++)
		{
			int t;
			fin>>t;
			freq.push_back(t);
		}
		sort(freq.rbegin(),freq.rend());
		int cur=1; int left=K;
		int ans=0;
		for(int j=0;j<freq.size();j++)
		{
			ans+=cur*freq[j];
			left--;
			if(left==0) left=K,cur++;
		}
		fout<<"Case #"<<i+1<<": "<<ans<<endl;
	}

	return 0;
}

