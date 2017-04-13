#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <ctime>
#include <numeric>
#include <cstdio>
#include <memory.h>

using namespace std;   

#define SZ(a) ((int)(a).size())
#define SQR(a) ((a)*(a))
#define FOR(i, a, b) for(int i=(a), _b(b); i<_b; ++i)
#define FORD(i, b, a) for(int i=(b)-1, _a(a); i>=_a; --i)
#define FILL(a, b) memset(a, b, sizeof(a))
#define FHAS(a, b) (find((a).begin(), (a).end(), (b))!=(a).end())
#define HAS(a, b) ((a).find(b) != (a).end())
#define HASB(a, b) (((a) & (1 << (b)))>0)

template<class A, class B> A convert(B x) {stringstream s; s << x; A r; s >> r; return r;}

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long LL;

const string prob = "B";

int R, C, D;
int a[11][11];
char line[1<<10];

bool Check(int i1, int j1, int len)
{
	int i2 = i1+len-1;
	int j2 = j1+len-1;
	if (i2>=R || j2>=C) return false;

	int sumI = 0, sumJ = 0;

	int ic = i1+len/2;
	int jc = j1+len/2;

	if (len&1)
	{
		FOR(ii, i1, i2+1)
			FOR(jj, j1, j2+1)
			{
				if (ii==i1 && jj==j1) continue;
				if (ii==i1 && jj==j2) continue;
				if (ii==i2 && jj==j1) continue;
				if (ii==i2 && jj==j2) continue;
				if (ii<ic) sumI += a[ii][jj]*(ic-ii);
				if (ii>ic) sumI -= a[ii][jj]*(ii-ic);
				if (jj<jc) sumJ += a[ii][jj]*(jc-jj);
				if (jj>jc) sumJ -= a[ii][jj]*(jj-jc);
			}
	}
	else
	{
		FOR(ii, i1, i2+1)
			FOR(jj, j1, j2+1)
			{
				if (ii==i1 && jj==j1) continue;
				if (ii==i1 && jj==j2) continue;
				if (ii==i2 && jj==j1) continue;
				if (ii==i2 && jj==j2) continue;
				if (ii<ic) sumI += a[ii][jj]*(ic-ii);
				if (ii>=ic) sumI -= a[ii][jj]*(ii-ic+1);
				if (jj<jc) sumJ += a[ii][jj]*(jc-jj);
				if (jj>=jc) sumJ -= a[ii][jj]*(jj-jc+1);
			}
	}

	return sumI==0 && sumJ==0;
}

int main() {

	freopen((prob+".in").c_str(), "r", stdin);
	freopen((prob+".out").c_str(), "w", stdout);

	int tc, gl=1; scanf("%d", &tc);

	while (tc --> 0)
	{
		scanf("%d %d %d", &R, &C, &D);
		FOR(i, 0, R)
		{
			scanf("%s", line);
			FOR(j, 0, C)
				a[i][j] = (line[j]-'0')+D;
		}

		int res = -1;
		FOR(i, 0, R)
			FOR(j, 0, C)
				FOR(len, 3, R+C)
					if (Check(i, j, len))
						res = max(res, len);

		printf("Case #%d: ", gl++);
		if (res == -1) printf("IMPOSSIBLE\n");
		else
			printf("%d\n", res);
	}

	return 0;
}