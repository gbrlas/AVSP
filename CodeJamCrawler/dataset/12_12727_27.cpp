// GCJ2012Round2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "string.h"
#include "math.h"
#include "stdio.h"
#include "map"

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int N;
		cin>>N;
		vector<int> g(N);
		for(int i=1;i<N;i++)
		{
			cin>>g[i];
		}
		vector<int> ans(N+1);
		ans[N]=500000000;
		ans[N-1]=500000000;
		int isgood=1;
		vector<int> mid;
		mid.push_back(N-1);
		mid.push_back(N);
		for(int i=N-2;i>0;i--)
		{
			int found=0;
			if(g[i]==mid[0])
			{
				found=1;
				double r=1.0*(ans[mid[1]]-ans[mid[0]])/(mid[1]-mid[0]);
				ans[i]=floor(ans[mid[0]]-r*(mid[0]-i))-1;
				mid.push_back(i);
				sort(mid.begin(),mid.end());
			}
			else if(g[i]==mid[mid.size()-1])
			{
				int n=mid.size();
				found=1;
				double r=1.0*(ans[mid[n-1]]-ans[mid[n-2]])/(mid[n-1]-mid[n-2]);
				ans[i]=ceil(ans[mid[n-1]]-r*(mid[n-1]-i))+1;
				mid.clear();
				mid.push_back(i);
				mid.push_back(N);
			}
			else
			{
				for(int j=1;j<mid.size()-1;j++)
				{
					if(g[i]==mid[j])
					{
						found=1;
						int low=0,high;
						int m=mid[j];
						int n=mid[j-1];
						double r=1.0*(ans[m]-ans[n])/(m-n);
						high=ceil(ans[m]-r*(m-i));
						int s=mid[j+1];
						r=1.0*(ans[s]-ans[m])/(s-m);
						low=floor(ans[s]-r*(s-i));
						//if(high<low) cout<<"error!!";
						ans[i]=(high+low)/2;
						vector<int> mid1;
						mid1.push_back(i);
						for(int k=j;k<mid.size();k++)
						{
							mid1.push_back(mid[k]);
						}
						mid=mid1;
					}
				}
			}
			if(found==0)
			{
				isgood=0;
				break;
			}
		}
		cout<<"Case #"<<tc+1<<":";
		if(isgood)
		{
			//check
			for(int i=1;i<N;i++)
			{
				int tt=g[i];
				double r=1.0*(ans[tt]-ans[i])/(tt-i);
				double cur=ans[i];
				for(int j=i+1;j<=N;j++)
				{
					cur+=r;
					if(j==tt) continue;
					if(cur<ans[j]+1e-6)
					{
						cout<<"error";
						break;
					}
				}
			}
			for(int i=1;i<=N;i++)
			{
				cout<<" "<<ans[i];
			}
			cout<<endl;
		}
		else
		{
			cout<<" Impossible"<<endl;
		}
	}
	return 0;
}

