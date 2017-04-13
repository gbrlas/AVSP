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
		int N,L,H;
		cin>>N>>L>>H;
		vector<int> g(N);
		for(int i=0;i<N;i++)
		{
			cin>>g[i];
		}
		int k;
		int isgood=0;
		for(k=L;k<=H;k++)
		{
			int found=0;
			for(int i=0;i<N;i++)
			{
				if(k>=g[i] && (k%g[i])==0)
				{
					continue;
				}
				else if(k<=g[i] && (g[i]%k)==0)
				{
					continue;
				}
				found=1;
				break;
			}
			if(found==0)
			{
				isgood=1;
				break;
			}
		}
		if(isgood)
		{
			cout<<"Case #"<<tc+1<<": "<<k<<endl;
		}
		else
		{
			cout<<"Case #"<<tc+1<<": NO"<<endl;
		}
	}
	return 0;
}

