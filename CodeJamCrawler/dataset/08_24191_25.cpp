#include<iostream>
#include<string.h>
#include<fstream>
#define INF 1000000000

using namespace std;

char s[110][110];
int dp[1100][110];
int q[1100];

int main()
{
	int p,ncase,i,j,k,m,n;
	ifstream cin("a2.in");
	ofstream cout("a2.out");
	cin>>ncase;
	for(p=1;p<=ncase;p++)
	{
		cin>>n;
		cin.ignore();
		for(i=1;i<=n;i++)
			cin.getline(s[i],110);
		cin>>m;
		cin.ignore();
		char tmp[110];
		for(i=1;i<=m;i++)
		{
			cin.getline(tmp,110);
			for(j=1;j<=n;j++)
				if(strcmp(tmp,s[j])==0)
				{
					q[i]=j;
					break;
				}
		}
		for(i=0;i<=n;i++)
			dp[0][i]=0;
		for(i=1;i<=m;i++)
		{
			int min=INF;
			for(k=1;k<=n;k++)
			{
				//if(q[i-1]==k)
				//	dp[i-1][k]=INF;
				if(dp[i-1][k]<min)
					min=dp[i-1][k];
			}
			for(j=1;j<=n;j++)
			{
				//dp[i][j]=min;
				if(q[i]==j)
				{
					dp[i][j]=INF;
					continue;
				}
				if(dp[i-1][j]==min && q[i-1]!=j)
					dp[i][j]=min;
				else dp[i][j]=min+1;
			}
		}
		int mm=INF;
		for(i=1;i<=n;i++)
			if(dp[m][i]<mm)
				mm=dp[m][i];
		cout<<"Case #"<<p<<": "<<mm<<endl;
	}
	return 0;
}
