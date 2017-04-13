// FairWarning.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
using namespace std;

//class BigInt
//{
//	string value;
//public:
//	BitInt(string str)
//	{
//		value=str;
//	}
//}
//
//BigInt Mod(BigInt a, BigInt b)
//{
//	
//}
//
//BigInt gcd(BigInt a, BigInt b)
//{
//	if(b>a) return gcd(b,a);
//	if((a%b)==0)
//		return b;
//	return gcd(b,a%b);
//}


int gcd(int a, int b)
{
	if(b>a) return gcd(b,a);
	if((a%b)==0)
		return b;
	return gcd(b,a%b);
}

int main()
{
	int C;
	cin>>C;
	for(int tc=0;tc<C;tc++)
	{
		int N;
		cin>>N;
		int old=0,cur=0;
		cin>>old;
		int T=0;
		for(int i=1;i<N;i++)
		{
			cin>>cur;
			int diff=abs(cur-old);
			if(diff>0)
			{
				if(T==0)
					T=diff;
				else
					T=gcd(diff,T);
			}
			old=cur;
		}
		int ans=(T-(cur%T))%T;
		cout<<"Case #"<<tc+1<<": "<<ans<<endl;
	}
	return 0;
}

