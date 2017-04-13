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
using namespace std;

#define s(T) scanf("%d", &T)
#define sl(T) scanf("%lld", &T)
#define fill(a, val) memset(a, val, sizeof(a))

int totalCases, testNum;
long long C, D;
long long P[1000006];
int N;

void preprocess()
{
	
}

bool input()
{
	sl(C);
	sl(D);
	D *= 2;
	
	N = 0;
	int x, y;
	for(int i = 0; i < C; i++)
	{
		s(x);
		s(y);
		for(int j = 0; j < y; j++)
			P[N++] = x<<1ll;
	}
	
	return true;
}

bool poss(long long t)
{
	long long prev = P[0] - t;
	for(int i = 1; i < N; i++)
	{
		if(P[i] + t < prev + D)
			return false;
		prev = max(P[i] - t, prev + D);
	}
	return true;
}

void solve()
{
	long long lo, hi;
	lo = 0;
	hi = N * D;
	while( lo < hi )
	{
		long long mid = (lo + hi) / 2;
		if(poss(mid))
			hi = mid;
		else 
			lo = mid+1;
	}
	cout << (hi/2.0) << endl;
}

int main()
{
	preprocess();
	s(totalCases);
	for(testNum = 1; testNum <= totalCases; testNum++)
	{
		if( !input())
			break;
		printf("Case #%d: ", testNum);
		solve();
	}
}
