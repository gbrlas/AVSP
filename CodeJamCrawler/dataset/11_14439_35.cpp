// 2011Round1B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "string.h"
#include "stdio.h"

using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int N;
		cin>>N;
		vector<string> g;
		for(int i=0;i<N;i++)
		{
			string str;
			cin>>str;
			g.push_back(str);
		}
		double WP[105]={},OWP[105]={},OOWP[105]={};
		for(int i=0;i<N;i++)
		{
			int wins=0;
			int total=0;
			for(int j=0;j<N;j++)
			{
				if(i==j) continue;
				if(g[i][j]=='.') continue;
				if(g[i][j]=='1')
					wins++;
				total++;
			}
			WP[i]=(double)wins/total;
		}
		for(int i=0;i<N;i++)
		{
			double owp=0;
			int cnt=0;
			for(int j=0;j<N;j++)
			{
				if(i==j) continue;
				if(g[i][j]=='.') continue;
				int wins=0; int total=0;
				for(int k=0;k<N;k++)
				{
					if(j==k || k==i) continue;
					if(g[j][k]=='.') continue;
					if(g[j][k]=='1') wins++;
					total++;
				}
				owp+=(double)wins/total;
				cnt++;
			}
			OWP[i]=owp/cnt;
		}
		for(int i=0;i<N;i++)
		{
			double oowp=0;
			int cnt=0;
			for(int j=0;j<N;j++)
			{
				if(i==j) continue;
				if(g[i][j]=='.') continue;
				oowp+=OWP[j];
				cnt++;
			}
			OOWP[i]=oowp/cnt;
		}
		cout<<"Case #"<<tc+1<<":"<<endl;
		for(int i=0;i<N;i++)
		{
			double RPI=0.25*WP[i]+0.5*OWP[i]+0.25*OOWP[i];
			//cout<<WP[i]<<" "<<OWP[i]<<" "<<OOWP[i]<<endl;
			printf("%.10lf\n",RPI);
		}
	}
	return 0;
}

