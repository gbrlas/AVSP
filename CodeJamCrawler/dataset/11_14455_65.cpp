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
		int R,C;
		cin>>R>>C;
		vector<string> g;
		for(int i=0;i<R;i++)
		{
			string str;
			cin>>str;
			g.push_back(str);
		}
		for(int i=0;i<R-1;i++)
		{
			for(int j=0;j<C-1;j++)
			{
				if(g[i][j]=='#' && g[i+1][j]=='#' && g[i][j+1]=='#' && g[i+1][j+1]=='#')
				{
					g[i][j]='/';
					g[i+1][j]='\\';
					g[i][j+1]='\\';
					g[i+1][j+1]='/';
				}
			}
		}
		int found=0;
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				if(g[i][j]=='#')
				{
					found=1;
					break;
				}
			}
		}
		cout<<"Case #"<<tc+1<<":"<<endl;
		if(found)
		{
			cout<<"Impossible"<<endl;
		}
		else
		{
			for(int i=0;i<R;i++)
				cout<<g[i]<<endl;
		}
	}
	return 0;
}

