// 2011Round2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "math.h"
#include "string.h"
using namespace std;

int g[505][505]={};
long long dp[505][505]={};

long long get(int l, int r, int u, int d)
{
	long long ans=dp[d][r]-dp[u-1][r]-dp[d][l-1]+dp[u-1][l-1];
	return ans;
}

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int R,C,D;
		cin>>R>>C>>D;
		D=0;
		memset(g,0,sizeof(g));
		for(int i=0;i<R;i++)
		{
			string str;
			cin>>str;
			long long sum=0;
			for(int j=0;j<C;j++)
			{
				g[i][j]=str[j]+D-'0';
				sum+=g[i][j];
				dp[i+1][j+1]=sum+dp[i][j+1];
			}
		}
		int N=min(R,C);
		int ans=-1;
		for(int k=3;k<=N;k++)
		{
			int found=0;
			if(k%2)
			{
				for(int i=k/2;i<=R-k/2;i++)
				{
					for(int j=k/2;j<=C-k/2;j++)
					{
						int u=i-k/2;
						int d=i+k/2;
						int l=j-k/2;
						int r=j+k/2;
						long long s1=0; 
						for(int n=u;n<i;n++)
						{
							if(n==u)
								s1+=get(l+1,r-1,n,n)*(i-n);
							else
								s1+=get(l,r,n,n)*(i-n);
						}
						long long s2=0; 
						for(int n=i+1;n<=i+k/2;n++)
						{
							if(n==i+k/2)
								s2+=get(l+1,r-1,n,n)*(n-i);
							else
								s2+=get(l,r,n,n)*(n-i);
						}
						long long s3=0; 
						for(int n=l;n<j;n++)
						{
							if(n==l)
								s3+=get(n,n,u+1,d-1)*(j-n);
							else
								s3+=get(n,n,u,d)*(j-n);
						}
						long long s4=0; 
						for(int n=j+1;n<=j+k/2;n++)
						{
							if(n==j+k/2)
								s4+=get(n,n,u+1,d-1)*(n-j);
							else
								s4+=get(n,n,u,d)*(n-j);
						}
						if(s1==s2 && s3==s4)
						{
							found=1;
							ans=k;
							break;
						}
					}
					if(found) break;
				}
			}
			else
			{
				for(int i=k/2;i<=R-k/2+1;i++)
				{
					for(int j=k/2;j<=C-k/2+1;j++)
					{
						int u=i-k/2+1;
						int d=i+k/2;
						int l=j-k/2+1;
						int r=j+k/2;
						long long s1=0; 
						for(int n=u;n<=i;n++)
						{
							if(n==u)
								s1+=get(l+1,r-1,n,n)*(i-n+1);
							else
								s1+=get(l,r,n,n)*(i-n+1);
						}
						long long s2=0; 
						for(int n=i+1;n<=i+k/2;n++)
						{
							if(n==i+k/2)
								s2+=get(l+1,r-1,n,n)*(n-i);
							else
								s2+=get(l,r,n,n)*(n-i);
						}
						long long s3=0; 
						for(int n=l;n<=j;n++)
						{
							if(n==l)
								s3+=get(n,n,u+1,d-1)*(j-n+1);
							else
								s3+=get(n,n,u,d)*(j-n+1);
						}
						long long s4=0; 
						for(int n=j+1;n<=j+k/2;n++)
						{
							if(n==j+k/2)
								s4+=get(n,n,u+1,d-1)*(n-j);
							else
								s4+=get(n,n,u,d)*(n-j);
						}
						if(s1==s2 && s3==s4)
						{
							found=1;
							ans=k;
							break;
						}
					}
					if(found) break;
				}
			}
		}
		if(ans==-1)
		{
			cout<<"Case #"<<tc+1<<": "<<"IMPOSSIBLE"<<endl;
		}
		else
		{
			cout<<"Case #"<<tc+1<<": "<<ans<<endl;
		}
	}
	return 0;
}

