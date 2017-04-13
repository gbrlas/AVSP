#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<iomanip>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<memory.h>
#include<iomanip>
using namespace std;


typedef long long ll;

ll gcd(ll a, ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	int test_count;
	cin>>test_count;
	for(int test_num=0;test_num<test_count;test_num++)
	{
		ll N,Pd,Pg;
		scanf("%lld%lld%lld",&N,&Pd,&Pg);
		
		bool res;
		if (Pd>0 && Pg==0)
			res=false;
		else if (Pg==100 && Pd<100)
			res=false;
		else if (Pd==0)
			res=true;
		else 
		{
			int x1 = 100;
			while(x1%2==0 && Pd%2==0)
			{
				x1/=2;
				Pd/=2;
			}
			while(x1%5==0 && Pd%5==0)
			{
				x1/=5;
				Pd/=5;
			}
			ll M = x1;
			if (M<=N)
				res=true;
			else
				res=false;
			/*
			int x2 = 100;
			while(x2%2==0 && Pg%2==0)
			{
				x2/=2;
				Pg/=2;
			}
			while(x2%5==0 && Pg%5==0)
			{
				x2/=5;
				Pg/=5;
			}
			ll M = x1*x2/gcd(x1,x2);
			*/
		}
		if (res)
			printf("Case #%d: Possible\n",test_num+1);
		else
			printf("Case #%d: Broken\n",test_num+1);
	}
	
	return 0;
}