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
int sum, xsum, minval;
int N;

void preprocess()
{
	
}

bool input()
{
	
	return true;
}

void solve()
{
	s(N);
	sum = xsum = 0;
	minval = 10000000;
	int  x;
	for(int i = 0; i < N; i++)
	{
		s(x);
		xsum = xsum ^ x;
		sum += x;
		minval = min(minval, x);
	}
	
	printf("Case #%d: ", testNum);
	if(xsum)
		printf("NO\n");
	else 
		printf("%d\n", sum - minval);
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
