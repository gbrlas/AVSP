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

const int MOD = 10007;
const int MAXR = 10;
const int MAX = 128;

int n, m, R;
int xr[MAXR], yr[MAXR];

void Read()
{
	scanf("%d %d %d", &n, &m, &R);
	for (int i=0;i<R;i++)
		scanf("%d %d", &xr[i], &yr[i]);

}

int dx[2] = {1, 2};
int dy[2] = {2, 1};

int dp[MAX][MAX];
bool ok[MAX][MAX];

void Solve()
{
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			ok[i][j] = true;
	for (int i=0;i<R;i++)
	{
		ok[xr[i]-1][yr[i]-1] = false;
	}

	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			dp[i][j] = 0;

	dp[0][0] = 1;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if ( dp[i][j]>0 )
			{
				for (int k=0;k<2;k++)
				{
					int nx = dx[k]+i;
					int ny = dy[k]+j;
					if ( nx<n && ny<m && ok[nx][ny] )
						dp[nx][ny] = (dp[nx][ny] + dp[i][j])%MOD;
				}
			}

	printf("%d\n", dp[n-1][m-1]);
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
