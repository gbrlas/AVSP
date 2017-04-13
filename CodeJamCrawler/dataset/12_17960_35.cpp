/*
 	Team Proof
	IIT Delhi
 
	C++ Template
 */


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
using namespace std;

#define s(T) scanf("%d", &T)
#define sl(T) scanf("%lld", &T)
#define fill(a, val) memset(a, val, sizeof(a))
#define mp make_pair

int totalCases, testNum;
int N;
int x[60005];
int l[60005];
int D;

int dp[60005];

const int INF = 1000000005;

void preprocess()
{
	
}

bool input()
{
	s(N);
	for(int i = 0; i < N; i++)
	{
		s(x[i]);
		s(l[i]);
	}
	s(D);
	return true;
}

void solve()
{
	//for(int i = 0; i < N; i++)
	//	dp[i] = INF;
	fill(dp, 0);
	
	int j = 1;
	
	printf("Case #%d: ", testNum);
	
	l[0] = x[0];
	dp[0] = x[0];
	for(int i = 0; i < N; i++)
	{
		int reach = min(l[i], dp[i]);
		while(j < N && x[i] + reach >= x[j])
		{
			dp[j] = x[j] - x[i];
			j++;
		}
		if(x[i] + reach >= D)
		{
			printf("YES\n");
			return;
		}
	}
	
	printf("NO\n");
	return;
}

int main()
{
	preprocess();
	s(totalCases);
	for(testNum = 1; testNum <= totalCases; testNum++)
	{
		if( !input())
			break;
		solve();
	}
}
