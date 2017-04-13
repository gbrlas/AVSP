#pragma comment(linker, "/STACK:16777216")
#pragma warning (disable:4786)
#pragma warning (disable:4996)

#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
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

const int MAXN = 2000;
const int MAXM = 2000;
int g[MAXM][2*MAXN];
int n, m;
set<int> v[MAXM];
vector<int> pl[MAXN][2];

void Read()
{
	memset(g, 0, sizeof(g));
	for (int i=0;i<m;i++)
		v[i].clear();

	for (int i=0;i<n;i++)
	{
		pl[i][0].clear();
		pl[i][1].clear();
	}

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
			v[i].insert(2*x+y);
			pl[x][y].push_back(i);
		}
	}
}

int st[MAXN];
void SetIndex(int ind)
{
	st[ind] = 1;
	for (int i=0;i<pl[ind][0].size();i++)
	{
		v[pl[ind][0][i]].erase(ind*2);
	}
}

bool Satis()
{
	for (int i=0;i<m;i++)
	{
		bool ffind = false;
		for (int j=0;j<n;j++)
			if ( g[i][2*j+st[j]]==1 ) {ffind = true; break;}
		if ( !ffind ) return false;
	}
	return true;
}

void Solve()
{
	for (int i=0;i<n;i++)
		st[i] = -1;

	while ( 1 )
	{
		bool upd = false;
		for (int i=0;i<m;i++)
		{
			if ( v[i].size()==0 )
			{
				printf(" IMPOSSIBLE\n");
				return;
			}

			if ( v[i].size()==1 )
			{
				int f = *v[i].begin();
				if ( f%2==1 && st[f/2]==-1 )
				{
					SetIndex(f/2);
					upd = true;
				}
			}
		}

		if ( !upd ) break;
	}

	for (int i=0;i<n;i++)
		if ( st[i]==-1 ) st[i] = 0;

	while ( !Satis() );

	for (int i=0;i<n;i++)
		printf(" %d", st[i]);
	printf("\n");
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
