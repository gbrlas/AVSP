#pragma comment(linker, "/STACK:16777216")
#pragma warning (disable:4786)

#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
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
const int MAXS = 128;
char buf[MAX];
int S, Q;
string names[MAX];
string query[MAX];
map<string, int> hash;
int dp[MAXS][MAX];

void Read()
{
	hash.clear();

	gets(buf);
	sscanf(buf, "%d", &S);
	for (int i=0;i<S;i++)
	{
		gets(buf);
		names[i] = string(buf);
		hash[names[i]] = i;
	}

	gets(buf);
	sscanf(buf, "%d", &Q);
	for (int i=0;i<Q;i++)
	{
		gets(buf);
		query[i] = string(buf);
	}
}

void Solve()
{
	if ( Q<=1 )
	{
		printf("%d\n", 0);
		return;
	}

	int a[MAX];
	for (int i=0;i<Q;i++)
	{
		a[i] = hash[query[i]];
		//printf("%d ", a[i]);
	}

	for (int i=0;i<MAXS;i++)
		for (int j=0;j<MAX;j++)
			dp[i][j] = -1;

	for (int i=0;i<S;i++)
		if ( a[0]!=i ) dp[0][i] = 0;

	for (int i=1;i<Q;i++)
	{
		for (int j=0;j<S;j++)
			if ( a[i]!=j )
			{
				for (int k=0;k<S;k++)
					if ( dp[i-1][k]!=-1 )
						if ( dp[i][j]==-1 || dp[i][j]>dp[i-1][k]+(k==j ? 0 : 1) ) dp[i][j] = dp[i-1][k]+(k==j ? 0 : 1);
			}
	}

	int ans = -1;
	for (int j=0;j<S;j++)
		if ( dp[Q-1][j]!=-1 )
			if ( ans==-1 || ans>dp[Q-1][j] ) ans = dp[Q-1][j];

	printf("%d\n", ans);
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int ntest;
	gets(buf);
	sscanf(buf, "%d", &ntest);

	for (int t=0;t<ntest;t++)
	{
		printf("Case #%d: ", t+1);
		Read();
		Solve();
	}

	return 0;
}
