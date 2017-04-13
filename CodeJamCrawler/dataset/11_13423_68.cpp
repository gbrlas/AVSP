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
#include<cmath>
using namespace std;

typedef long long ll;

const int size = 1000005;
bool prost[size];

int main()
{
	vector<ll> pr;
	for(int i=2;i<=size;i++)
		prost[i]=true;
	for(int i=2;i<=size;i++)
		if (prost[i])
		{
			pr.push_back(i);
			for(int j=2*i;j<=size;j+=i)
				prost[j]=false;		
		}

	int test_count;
	cin>>test_count;
	for(int test_num=0;test_num<test_count;test_num++)
	{
		ll N;
		scanf("%lld",&N);
		ll N2 = N;
		N = min(N, ll(sqrt(N+0.0)+1));

		int P = 0;
		while(pr[P+1]<=N) P++;
		P++;
		int MinA = P;
		int MaxA = 1;
		for(int i=0;i<P;i++)
		{
			ll x = pr[i];
			ll y = 1;
			while(y<=N2)
			{
				y*=x;
				MaxA++;
			}
			MaxA--;
		}
		if (N==1) MinA = MaxA = 1;
		printf("Case #%d: %d\n",test_num+1,MaxA-MinA);
	}
	return 0;
}