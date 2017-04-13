// ProblemA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "sstream"
#include "set"
using namespace std;

int isnum(char ch)
{
	if(ch>='0' && ch<='9') return 1;
	return 0;
}
int isgood(int x,int y)
{
	if(x<0 || x>255) return 0;
	if(y<0 || y>255) return 0;
	return 1;
}

int check(char g[256][256], int x, int y, int k)
{
	for(int i=0;i<2*k-1;i++)
	{
		for(int j=0;j<2*k-1;j++)
		{
			int x1=x+i,y1=y+j;
			int x2=x+i,y2=y-j;
			int x3=x-i,y3=y+j;
			int x4=x-i,y4=y-j;
			vector<char> d;
			if(isgood(x1,y1) && isnum(g[x1][y1]))
				d.push_back(g[x1][y1]);

			if(isgood(x2,y2) && isnum(g[x2][y2]))
				d.push_back(g[x2][y2]);

			if(isgood(x3,y3) && isnum(g[x3][y3]))
				d.push_back(g[x3][y3]);

			if(isgood(x4,y4) && isnum(g[x4][y4]))
				d.push_back(g[x4][y4]);

			for(int n=1;n<d.size();n++)
				if(d[n]!=d[n-1]) return -1;
		}
	}
	return 1;
}
int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int k;
		cin>>k;
		char g[256][256]={};
		cin.getline(g[0],256);
		for(int i=0;i<k*2-1;i++)
		{
			cin.getline(g[i],256);
		}
		int ans=-1;
		for(int i=0;i<k*2-1;i++)
		{
			for(int j=0;j<k*2-1;j++)
			{
				int ret=check(g,i,j,k);
				if(ret==-1) continue;
				int cnt=abs(k-1-i)+abs(k-1-j);
				cnt=(k+cnt)*(k+cnt)-k*k;
				if(ans==-1 || ans>cnt)
					ans=cnt;
			}
		}

		cout<<"Case #"<<tc+1<<": "<<ans<<endl;
	}
	return 0;
}

