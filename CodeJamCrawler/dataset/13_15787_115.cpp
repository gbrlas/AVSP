// QualRound.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "vector"
#include "string.h"
#include "algorithm"
#include "stdio.h"
using namespace std;

int check(vector<string> &g, char ch)
{
	for(int i=0;i<4;i++)
	{
		int isgood=1;
		int cnt=0;
		for(int j=0;j<4;j++)
		{
			if(g[i][j]!=ch && g[i][j]!='T')
			{
				isgood=0;
			}
			if(g[i][j]==ch) cnt++;
		}
		if(isgood && cnt>=3) return 1;
	}
	for(int i=0;i<4;i++)
	{
		int isgood=1;
		int cnt=0;
		for(int j=0;j<4;j++)
		{
			if(g[j][i]!=ch && g[j][i]!='T')
			{
				isgood=0;
			}
			if(g[j][i]==ch) cnt++;
		}
		if(isgood && cnt>=3) return 1;
	}
	{
		int isgood=1;
		int cnt=0;
		for(int j=0;j<4;j++)
		{
			if(g[j][j]!=ch && g[j][j]!='T')
			{
				isgood=0;
			}
			if(g[j][j]==ch) cnt++;
		}
		if(isgood && cnt>=3) return 1;
	}
	{
		int isgood=1;
		int cnt=0;
		for(int j=0;j<4;j++)
		{
			if(g[j][3-j]!=ch && g[j][3-j]!='T')
			{
				isgood=0;
			}
			if(g[j][3-j]==ch) cnt++;
		}
		if(isgood && cnt>=3) return 1;
	}

	return 0;
}

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		vector<string> g(4);
		int completed=1;
		for(int i=0;i<4;i++)
		{
			cin>>g[i];
			for(int j=0;j<4;j++)
				if(g[i][j]=='.')
					completed=0;
		}
		cout<<"Case #"<<tc+1<<": ";
		int a=check(g,'X');
		int b=check(g,'O');
		if(a==0 && b==0)
		{
			if(completed)
			{
				cout<<"Draw"<<endl;
			}
			else
			{
				cout<<"Game has not completed"<<endl;
			}
		}
		else if(a==1 && b==0)
		{
			cout<<"X won"<<endl;
		}
		else if(a==0 && b==1)
		{
			cout<<"O won"<<endl;
		}
		else 
		{
			cout<<"Draw"<<endl;
		}
	}
	return 0;
}

