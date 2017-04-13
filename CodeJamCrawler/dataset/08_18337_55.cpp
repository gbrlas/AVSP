#pragma comment(linker, "/STACK:16777216")
#pragma warning (disable:4786)
#pragma warning (disable:4996)

#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define Abs(a) ((a)>0?(a):-(a))
#define Sqr(a) ((a)*(a))

#define EPS 1e-7

using namespace std;

#ifdef _MSC_VER
	typedef __int64 LL;
#else
	typedef long long LL;
#endif

typedef vector <int> VI;
typedef vector <VI> VVI;

typedef double LD;
typedef vector <LD> VD;
typedef vector <VD> VVD;

typedef vector <string> VS;

const int INF2 = 100000000;
const int MAX = 128000;

int M, V;
int G[MAX];
int C[MAX];
int I[MAX];
int hash[MAX][2];

void Read()
{
	scanf("%d %d", &M, &V);
	for (int i=1;i<=(M-1)/2;i++)
	{
		scanf("%d %d", &G[i], &C[i]);
	}

	for (int i=1;i<=(M+1)/2;i++)
	{
		scanf("%d", &I[(M-1)/2+i]);
	}
}

int GetMin(int index, int value)
{
	if ( hash[index][value]!=-1 )
		return hash[index][value];

	if ( index>(M-1)/2 )
	{
		if ( I[index]==value ) return 0;
		return -1;
	}

	int res = INF2;
	if ( G[index]==1 )
	{
		//AND
		if ( value==1 )
		{
			int a1 = GetMin(index*2, 1);
			int a2 = GetMin(index*2+1, 1);

			if ( a1!=-1 && a2!=-1 )
				res = min(res, a1+a2);
		}
		else
		{
			int a1 = GetMin(index*2, 0);
			int a2 = GetMin(index*2+1, 0);

			if ( a1!=-1 )
				res = min(res, a1);
			if ( a2!=-1 )
				res = min(res, a2);
		}
	}
	else
	{
		//OR
		if ( value==0 )
		{
			int a1 = GetMin(index*2, 0);
			int a2 = GetMin(index*2+1, 0);

			if ( a1!=-1 && a2!=-1 )
				res = min(res, a1+a2);
		}
		else
		{
			int a1 = GetMin(index*2, 1);
			int a2 = GetMin(index*2+1, 1);

			if ( a1!=-1 )
				res = min(res, a1);
			if ( a2!=-1 )
				res = min(res, a2);
		}
	}

	//change
	if ( C[index]==1 )
	{
		if ( G[index]==0 )
		{
			//AND
			if ( value==1 )
			{
				int a1 = GetMin(index*2, 1);
				int a2 = GetMin(index*2+1, 1);

				if ( a1!=-1 && a2!=-1 )
					res = min(res, a1+a2+1);
			}
			else
			{
				int a1 = GetMin(index*2, 0);
				int a2 = GetMin(index*2+1, 0);

				if ( a1!=-1 )
					res = min(res, a1+1);
				if ( a2!=-1 )
					res = min(res, a2+1);
			}
		}
		else
		{
			//OR
			if ( value==0 )
			{
				int a1 = GetMin(index*2, 0);
				int a2 = GetMin(index*2+1, 0);

				if ( a1!=-1 && a2!=-1 )
					res = min(res, a1+a2+1);
			}
			else
			{
				int a1 = GetMin(index*2, 1);
				int a2 = GetMin(index*2+1, 1);

				if ( a1!=-1 )
					res = min(res, a1+1);
				if ( a2!=-1 )
					res = min(res, a2+1);
			}
		}
	}

	if ( res==INF2 ) res = -1;
	hash[index][value] = res;
	return res;
}

void Solve()
{
	for (int i=0;i<MAX;i++)
		hash[i][0] = hash[i][1] = -1;

	int ans = GetMin(1, V);
	//int ans = GetMin(1, 1);
	if ( ans==-1 )
		printf("IMPOSSIBLE\n");
	else
		printf("%d\n", ans);
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int ntest;
	scanf("%d", &ntest);
	for (int t=0;t<ntest;t++)
	{
		printf("Case #%d: ", t+1);
		Read();
		Solve();
	}

	return 0;
}
