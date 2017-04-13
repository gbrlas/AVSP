#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <ctime>
#include <numeric>

using namespace std;   

#define SZ(a) ((int)(a).size())
#define SQR(a) ((a)*(a))
#define FOR(i, a, b) for(int i=(a), _b(b); i<_b; ++i)
#define FORD(i, b, a) for(int i=(b)-1, _a(a); i>=_a; --i)
#define FILL(a, b) memset(a, b, sizeof(a))
#define FHAS(a, b) (find((a).begin(), (a).end(), (b))!=(a).end())
#define HAS(a, b) ((a).find(b) != (a).end())
#define HASB(a, b) ((a & (1 << b))>0)

template<class A, class B> A convert(B x) {stringstream s; s << x; A r; s >> r; return r;}

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long LL;

LL l;
int n;
int b[101];
int dp[10001];

int Rec(int rem)
{
	if (!rem) return 0;

	int& res = dp[rem];
	if (res != -1) return res;

	res = 1000000;
	FOR(i, 0, n)
	{
		if (b[i] > rem) break;
		res = min(res, Rec(rem-b[i])+1);
	}

	return res;
}

int main() {

	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);

	int tc, gl;
	for(scanf("%d", &tc), gl=1; tc-->0; gl++)
	{
		scanf("%lld %d", &l, &n);
		int sum=0;
		FOR(i, 0, n) {
			scanf("%d", b+i);
			sum += b[i];
		}
		sort(b, b+n); FILL(dp, -1);
		FOR(i, 1, 10001)
			Rec(i);
		LL res = 1000000000000000001LL;
		FOR(i, 1, 10001)
		{
			if (dp[i] != 1000000)
			{
				LL l1 = l-i;
				LL curr = dp[i];
				bool fl = false;
				FORD(i, n, 0)
					if (l1%b[i]==0)
					{
						curr += l1/(LL)b[i];
						fl = true;
						break;
					}
				if (!fl) continue;
				res = min(res, curr);
			}
		}
		if (res == 1000000000000000001LL)
			printf("Case #%d: IMPOSSIBLE\n", gl);
		else
			printf("Case #%d: %lld\n", gl, res);
	}

	return 0;
}