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
#define INF 1e9

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

const int MAX = 1024;
int k;
char s[MAX];

void Read()
{
	scanf("%d", &k);
	scanf("%s", s);
}

int CompSize(char* a)
{
	int len = strlen(s);
	//todo
	char ch = ' ';
	int tec = 0;
	int res = 0;
	while ( tec<len )
	{
		if ( a[tec]!=ch )
		{
			res++;
			ch = a[tec];
		}
		tec++;
	}

	return res;
}

int Count(int p[])
{
	int len = strlen(s);
	char buf[MAX];
	for (int i=0;i<len;i++)
		buf[i] = '?';
	buf[len] = 0;

	int tec = 0;
	for (int i=0;i<len/k;i++)
	{
		for (int j=0;j<k;j++)
			buf[tec++] = s[(i*k)+p[j]];
	}

	return CompSize(buf);
}

void Solve()
{
	int p[10];
	for (int i=0;i<k;i++)
		p[i] = i;

	int ans = 100000000;

	do
	{
		int tec = Count(p);
		ans = min(ans, tec);
	}
	while ( next_permutation(p, p+k) );

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
