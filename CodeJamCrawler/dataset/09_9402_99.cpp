// Watersheds.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
using namespace std;

void run()
{
	int g[101][101]={};
	int al[101][101]={};
	int H,W;
	cin>>H>>W;
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
		{
			cin>>al[i][j];
			g[i][j]=i*100+j;
		}
	}

	//NWES
	int mx[4]={-1,0,0,1}; 
	int my[4]={0,-1,1,0};
	
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
		{
			int chosen=-1;
			int curAlt=al[i][j];
			for(int r=0;r<4;r++)
			{
				int x=i+mx[r];
				int y=j+my[r];
				if(x>=0 && y>=0 && x<H && y<W)
				{
					if(al[x][y]<curAlt)
					{
						curAlt=al[x][y];
						chosen=g[x][y];
					}
				}
			}
			if(chosen!=-1)
			{
				g[i][j]=chosen;
			}
		}
	}
	char used[10001]={};
	char ch='a';
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
		{
			int x=i,y=j;
			while(g[x][y]!=x*100+y)
			{
				int id=g[x][y];
				x=id/100;
				y=id%100;
			}
			if(used[g[x][y]]==0)
			{
				used[g[x][y]]=ch;
				ch++;
			}
			if(j>0)
				cout<<" ";
			cout<<used[g[x][y]];
		}
		cout<<endl;
	}
}

int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cout<<"Case #"<<i+1<<":"<<endl;
		run();
	}
	return 0;
}

