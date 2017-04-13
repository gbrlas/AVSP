#pragma comment(linker, "/STACK:16777216")
#pragma warning (disable:4786)
#pragma warning (disable:4996)

#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
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

const int MAX = 10;
int x[MAX], y[MAX];
int n;

void Read()
{
	scanf("%d", &n);
	for (int i=0;i<n;i++)
		scanf("%d", &x[i]);
	for (int i=0;i<n;i++)
		scanf("%d", &y[i]);
}

int Count(int p[])
{
	int res = 0;
	for (int i=0;i<n;i++)
		res += x[i]*y[p[i]];
	return res;
}

void Solve()
{
	int p[MAX];
	for (int i=0;i<n;i++)
		p[i] = i;

	int ans = 0, ch = 0;

	do
	{
		int tec = Count(p);
		if ( ch==0 || (ans>tec) ) 
		{
			ch = 1;
			ans = tec;
		}
	}
	while ( next_permutation(p, p+n) );

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
