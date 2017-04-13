// Rotate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int N,K;
		cin>>N>>K;
		int g[51][51]={};
		for(int i=0;i<N;i++)
		{
			string str;
			cin>>str;
			for(int j=0;j<N;j++)
			{
				if(str[j]=='R')
					g[i][j]=1;
				else if(str[j]=='B')
					g[i][j]=2;
				else
				g[i][j]=0;
			}
		}
		//rotate
		vector<int> col[50];
		for(int j=N-1;j>=0;j--)
		{
			for(int i=N-1;i>=0;i--)
			{
				if(g[i][j]>0)
					col[N-1-i].push_back(g[i][j]);
			}
		}
		int gg[51][51]={};
		for(int i=0;i<N;i++)
		{
			int pos=N-1;
			for(int j=0;j<col[i].size();j++,pos--)
			{
				gg[pos][i]=col[i][j];
			}
		}
		//for(int i=0;i<N;i++)
		//{
		//	cout<<endl;
		//	for(int j=0;j<N;j++)
		//	{
		//		cout<<gg[i][j];
		//	}
		//}
		//cout<<endl;
		int win=0;
		for(int i=0;i<N;i++)
		{
			int cnt=0; int last=0;
			for(int j=0;j<N;j++)
			{
				if(gg[i][j])
				{
					if(gg[i][j]==last) 
					{
						cnt++;
					}
					else
					{
						last=gg[i][j];
						cnt=1;
					}
				}
				else
				{
					cnt=0; last=0;
				}
				if(cnt==K) 
					win|=last;
			}
		}
		for(int j=0;j<N;j++)
		{
			int cnt=0; int last=0;
			for(int i=0;i<N;i++)
			{
				if(gg[i][j])
				{
					if(gg[i][j]==last) 
					{
						cnt++;
					}
					else
					{
						last=gg[i][j];
						cnt=1;
					}
				}
				else
				{
					cnt=0; last=0;
				}
				if(cnt==K)
					win|=last;
			}
		}
		for(int x=0;x<N+N-1;x++)
		{
			int cnt=0; int last=0;
			int i=min(N-1,x);
			int j=x-i;
			for(;i>=0;i--,j++)
			{
				if(gg[i][j])
				{
					if(gg[i][j]==last) 
					{
						cnt++;
					}
					else
					{
						last=gg[i][j];
						cnt=1;
					}
				}
				else
				{
					cnt=0; last=0;
				}
				if(cnt==K) win|=last;
			}
		}
		for(int x=N+N-2;x>=0;x--)
		{
			int cnt=0; int last=0;
			int i=min(N-1,x);
			int j=min(N+N-2-x,N-1);
			for(;i>=0 && j>=0;i--,j--)
			{
				if(gg[i][j])
				{
					if(gg[i][j]==last) 
					{
						cnt++;
					}
					else
					{
						last=gg[i][j];
						cnt=1;
					}
				}
				else
				{
					cnt=0; last=0;
				}
				if(cnt==K) win|=last;
			}
		}
		cout<<"Case #"<<tc+1<<": ";
		switch(win)
		{
		case 0:
			cout<<"Neither"<<endl;
			break;
		case 1:
			cout<<"Red"<<endl;
			break;
		case 2:
			cout<<"Blue"<<endl;
			break;
		case 3:
			cout<<"Both"<<endl;
			break;
		}
	}
	return 0;
}

