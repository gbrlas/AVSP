// ProblemA.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "vector"
#include "string"
#include "math.h"
#include "algorithm"
#include "fstream"
#include "sstream"
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int N;
		cin>>N;
		string str;
		vector<int> g;
		for(int i=0;i<N;i++)
		{
			cin>>str;
			int pos=0;
			for(int j=0;j<str.size();j++)
			{
				if(str[j]=='1')
					pos=j;
			}
			g.push_back(pos);
		}
		int ans=0;
		for(int i=0;i<N;i++)
		{
			int j=i;
			for(;j<N;j++)
			{
				if(g[j]<=i) break;
			}
			for(int k=j;k>i;k--)
			{
				swap(g[k-1],g[k]);
				ans++;
			}
		}
		cout<<"Case #"<<tc+1<<": "<<ans<<endl;
	}
	return 0;
}

