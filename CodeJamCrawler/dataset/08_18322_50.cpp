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

const int MAXN = 10;
const int MAXM = 100;
int g[MAXM][2*MAXN];
int n, m;

void Read()
{
	memset(g, 0, sizeof(g));

	scanf("%d %d", &n, &m);
	for (int i=0;i<m;i++)
	{
		int t;
		scanf("%d", &t);
		for (int j=0;j<t;j++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			x--;
			g[i][2*x + y] = 1;
		}
	}
}

int ans, ba[MAXN];
int tec[MAXN];

bool Satis()
{
	for (int i=0;i<m;i++)
	{
		bool ffind = false;
		for (int j=0;j<n;j++)
			if ( g[i][2*j+tec[j]]==1 ) {ffind = true; break;}
		if ( !ffind ) return false;
	}
	return true;
}

void Rec(int q, int sum)
{
	if ( ans!=-1 && ans<sum ) return;

	if ( tec[0]==1 )
		int ttt=0;

	if ( q==n )
	{
		if ( Satis() )
			if ( ans==-1 || ans>sum )
			{
				ans = sum;
				memcpy(ba, tec, n*sizeof(ba[0]));
			}

		return;
	}

	tec[q] = 0;
	Rec(q+1, sum);
	tec[q] = 1;
	Rec(q+1, sum+1);
}

void Solve()
{
	ans = -1;
	Rec(0, 0);

	if ( ans==-1 )
		printf(" IMPOSSIBLE\n");
	else
	{
		for (int i=0;i<n;i++)
			printf(" %d", ba[i]);
		printf("\n");
	}
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int ntest;
	scanf("%d", &ntest);
	for (int t=0;t<ntest;t++)
	{
		printf("Case #%d:", t+1);
		Read();
		Solve();
	}

	return 0;
}
