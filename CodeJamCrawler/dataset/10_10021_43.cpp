// ProblemC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "sstream"
using namespace std;

int main()
{
	int C;
	cin>>C;
	for(int tc=0;tc<C;tc++)
	{
		int R;
		cin>>R;
		int g[501][501]={};
		for(int i=0;i<R;i++)
		{
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			for(int j=x1;j<=x2;j++)
				for(int k=y1;k<=y2;k++)
					g[k][j]=1;
		}
		int n=0;
		while(1)
		{
			int found=0;
			//for(int i=1;i<10;i++)
			//{
			//	for(int j=1;j<10;j++)
			//		cout<<g[i][j];
			//	cout<<endl;
			//}
			for(int i=220;i>=0;i--)
				for(int j=220;j>=0;j--)
					if(g[i][j])
					{
						if(g[i-1][j]==0 && g[i][j-1]==0)
							g[i][j]=0;
						found=1;
					}
					else
					{
						if(g[i-1][j]==1 && g[i][j-1]==1)
							g[i][j]=1;
					}

			if(found==0) break;
			n++;
		}
		cout<<"Case #"<<tc+1<<": "<<n<<endl;
	}
	return 0;
}

