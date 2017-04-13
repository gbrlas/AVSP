// ProblemC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "map"
using namespace std;

#define NN 8000000
#define NN1 4000000
int g[8000000]={};
int used[8000000]={};
int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int C;
		cin>>C;
		for(int i=0;i<8000000;i++)
			used[i]=g[i]=0;
		vector<int> queue;
		for(int i=0;i<C;i++)
		{
			int P,V;
			cin>>P>>V;
			g[P+NN1]=V;
			if(V>0) 
			{
				queue.push_back(P+NN1);
				used[P+NN1]=1;
			}
		}
		int p=0; int q=queue.size();
		long long ans=0;
		while(p<q)
		{
			int pos=queue[p];
			int n=g[pos]/2;
			int start=pos-n;
			int end=pos+n;
			int k=n;
			ans=ans+(long long)k*(k+1)*(2*k+1)/6;
			for(int i=start;i<=end;i++)
			{
				if(i==pos)
				{
					g[i]=g[i]%2;
					continue;
				}
				g[i]=g[i]+1;
				if(g[i]>1 && used[i]==0)
				{
					queue.push_back(i);
					used[i]=1;
				}
			}
			used[pos]=0;
			p++;
			if(p==q)
			{
				q=queue.size();
			}
		}
		cout<<"Case #"<<tc+1<<": "<<ans<<endl;
	}

	return 0;
}

