#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <memory.h>
using namespace std;
#define sz(c) (int)c.size()
#define pb push_back
#define all(c) c.begin(), c.end()


void initialize()
{
    freopen("C1.in","r",stdin);
    freopen("output.txt","w",stdout);
}


const int MAX = 17, MAXK = 30, INF = 100000;
int a[MAX][MAXK];
int n, k;

bool good[1 << MAX];
bool visited[1 << MAX];
int dyn[1 << MAX];

int run(int myset)
{
	if (myset == 0) return 0;
	if (visited[myset]) return dyn[myset];
	int res = INF;
	for (int m = myset; m > 0; m = (m - 1) & myset)
	{
		if (good[m])
		{
			int r = run(myset - m);
			res = min(res, r + 1);
		}
	}
	visited[myset] = true;
	dyn[myset] = res;
	return res;
}

bool inter(int n1, int n2)
{
	bool less = false, more = false;
	for (int i = 0; i < k; ++i)
	{
		if (a[n1][i] == a[n2][i]) return true;
		if (a[n1][i] < a[n2][i]) less = true;
		if (a[n1][i] > a[n2][i]) more = true;
	}
	if (more && less) return true;
	return false;
}

int main()
{
    initialize();

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		memset(visited, 0, sizeof(visited));
		memset(dyn, 0, sizeof(dyn));

		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < k; ++j)
				scanf("%d", &a[i][j]);
		}
	
		for (int i = 0; i < (1 << n); ++i)
		{
			bool b[MAX];
			int num = i;
			for (int j = 0; j < n; ++j, num >>= 1)
			{
				if (num & 1)
					b[j] = true;
				else
					b[j] = false;
			}

			bool ok = false;
			for (int j = 0; j < n && !ok; ++j)
			{
				for (int l = 0; l < n && !ok; ++l)
				{
					if (j == l) continue;
					if (b[j] && b[l] && inter(j, l))
						ok = true;
				}
			}
			if (!ok) good[i] = true;
			else good[i] = false;
		}

		int res = run((1 << n) - 1);
		printf("Case #%d: %d\n", t, res);
	}


    return 0;
}