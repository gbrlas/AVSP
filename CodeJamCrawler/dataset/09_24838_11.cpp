// gcj R2 A
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#define all(t) t.begin(), t.end()
#define REP(i, n) for(int i=0; i<(int)(n); ++i)

int n;
char a[15][15];

int go(vector<int> P)
{
	int cnt =0 ,i , j;
	for(i=n-1; i>0; i--)
	{
		for(j=i; j<n; j++)
		{
			if(P[j - 1] > P[j])
			{
				swap(P[j-1], P[j]);
				cnt++;
			}
		}
	}
	return cnt;
}

bool avail(vector<int> &P)
{
	vector<string> b(n);

	for(int i=0; i<n; ++i)
		b[i] = a[ P[i] ];
	for(int i=0; i<n; ++i)
	{
		for(int j=i+1; j<n; ++j)
			if(b[i][j] == '1')
				return false;
	}
	return true;
}

int main()
{
	freopen("A-small.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	
	int T; scanf("%d", &T);
	for(int tt=1; tt<=T; ++tt)
	{
		scanf("%d", &n);
		REP(i, n) scanf("%s", a+i);
		
		vector<int> a(n);
		REP(i, n) a[i] = i;
		int ret = 987654321;

		do {
			if(avail(a))
				ret = min(ret, go(a));
		}while(next_permutation(all(a)));

		printf("Case #%d: %d\n", tt,ret);
	}
	return 0;
}