#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<stdlib.h>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
char m[105][105];
double wp[105],owp[105],oowp[105];
int jum[105];
int ada[105];
int main()
{
	int t;
	scanf("%d",&t);
	for(int it=0;it<t;it++)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",m[i]);
			wp[i]=owp[i]=oowp[i]=0;
		}
		for(int i=0;i<n;i++)
		{
			jum[i]=ada[i]=0;
			for(int j=0;j<n;j++)
			{
				if(m[i][j]!='.')
				{
					if(m[i][j]=='1')jum[i]++;
					ada[i]++;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			wp[i]=(double)jum[i]/(double)ada[i];
		//	cout << wp[i] << endl;
			
		}
		
		for(int i=0;i<n;i++)
		{
			double temp = 0.0;
			int ad = 0;
			for(int j=0;j<n;j++)
			{
				if(m[j][i]!='.')
				{
					ad++;
					if(m[j][i]=='0')temp = temp + (((double)jum[j])/((double)(ada[j]-1)));
					else temp =temp + (((double)(jum[j]-1))/((double)(ada[j]-1)));
				//	cout << temp << " " << j << endl;
				}
			}
			owp[i]= temp/(double)ad;
		//	cout << owp[i] << endl;
		}
		for(int i=0;i<n;i++)
		{
			double temp = 0.0;
			int ad = 0;
			for(int j=0;j<n;j++)
			{
				if(m[i][j]!='.')
				{
					temp+=owp[j];
					ad++;
				}
			}
			oowp[i]=temp/(double)ad;
		}
		printf("Case #%d:\n",it+1);
		for(int i=0;i<n;i++)
		{
			double bil = ((double)0.25 * wp[i] + (double)0.50 * owp[i] + (double) 0.25 * oowp[i]);
			
			cout <<  bil << endl;
		
		}
	}
	return 0;
}
