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
int S;
int P;

int t[105];

void preprocess()
{
	
}

bool input()
{
	s(N);
	s(S);
	s(P);
	for(int i = 0; i < N; i++)
		s(t[i]);
	return true;
}

void solve()
{
	int k, m;
	int tot = 0;
	for(int i = 0; i < N; i++)
	{
		k = (t[i]+2)/3;
		m = t[i] % 3;
		if(k >= P)
		{
			tot ++ ;
			continue;
		}
		if(m == 0 && k == P-1 && S>0 && k != 0)
		{
			tot++;
			S--;
			continue;
		}
		if(m == 2 && k == P-1 && S>0)
		{
			tot ++;
			S--;
			continue;
		}
	}
	
	printf("Case #%d: %d\n", testNum, tot);
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
