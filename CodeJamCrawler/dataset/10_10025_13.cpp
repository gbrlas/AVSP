// ProblemB.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

int used[1000000]={};

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		long long L;
		int N;
		cin>>L>>N;
		vector<int> B(N);
		for(int i=0;i<N;i++)
		{
			cin>>B[i];
		}
		for(int i=0;i<1000000;i++)
			used[i]=0;
		sort(B.rbegin(),B.rend());
		vector<int> queue;
		int p=0; int q=1;
		queue.push_back(0);
		int step=1;
		while(p<q)
		{
			int n=queue[p];
			for(int i=0;i<N;i++)
			{
				if(n+B[i]<1000000 && used[n+B[i]]==0)
				{
					used[n+B[i]]=step;
					queue.push_back(n+B[i]);
				}
			}
			p++;
			if(p==q)
			{
				q=queue.size();
				step++;
			}
		}
		long long ans=-1;
		for(int i=0;i<B.size();i++)
		{
			int t=L%B[i];
			long long cnt=L/B[i];
			if(t==0)
			{
				ans=min(ans,cnt);
			}
			while(t<1000000)
			{
				if(used[t])
				{
					if(ans==-1)
						ans=cnt+used[t];
					if(ans>cnt+used[t])
						ans=cnt+used[t];
				}
				t+=B[i];
				cnt--;
			}
		}
		if(ans==-1)
		{
			cout<<"Case #"<<tc+1<<": "<<"IMPOSSIBLE"<<endl;
		}
		else
		{
			cout<<"Case #"<<tc+1<<": "<<ans<<endl;
		}
	}
	return 0;
}

