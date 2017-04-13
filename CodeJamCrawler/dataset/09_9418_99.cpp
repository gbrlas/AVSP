// WelcometoCoddJam.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "vector"
#include "iostream"
#include "string"
#include "algorithm"
using namespace std;

int main()
{
	int N;
	cin>>N;
	string target = "welcome to code jam";
	char buf[1000]={};
	cin.getline(buf,1000);
	for(int i=0;i<N;i++)
	{
		cin.getline(buf,1000);
		string str(buf);
		int dp[501]={};
		for(int j=0;j<target.size();j++)
		{
			int dp1[501]={};
			int cur=0;
			if(j==0) cur=1;
			for(int k=0;k<str.size();k++)
			{
				cur=(cur+dp[k])%10000;
				if(str[k]==target[j])
				{
					dp1[k]=cur;
				}
			}
			for(int k=0;k<501;k++)
				dp[k]=dp1[k];
		}
		int ans=0;
		for(int k=0;k<501;k++)
			ans=(ans+dp[k])%10000;
		int a,b,c,d;
		d=ans%10;
		ans/=10;
		c=ans%10;
		ans/=10;
		b=ans%10;
		ans/=10;
		a=ans%10;
		cout<<"Case #"<<i+1<<": "<<a<<b<<c<<d<<endl;
	}
	return 0;
}

