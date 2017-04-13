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

int a[128];
int dp[128][300];
int d, I, m, n;

int Rec(int pos, int prev)
{
	if (pos == n)
		return 0;

	int& res = dp[pos][prev];
	if (res != -1) return res;

	// DEL
	res = Rec(pos+1, prev)+d;

	FOR(i, 0, 256)
	{
		int k1 = abs(i-a[pos]);
		int k2 = 0;

		if (!m)
		{
			if (prev<256 && i!=prev) continue;
			res = min(res, Rec(pos+1, i)+k1);
			continue;
		}

		if (prev<256) {
			if (m == 1 && i==prev)
				k2 = 0;
			else
				k2 = (abs(prev-i)-1)/m;
		}

		res = min(res, Rec(pos+1, i)+k1+k2*I);
	}

	return res;
}

int main() {

	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);

	int tc, gl=0; scanf("%d", &tc);
	while (tc --> 0) {
		gl++;
		scanf("%d %d %d %d", &d, &I, &m, &n);
		FOR(i, 0, n)
			scanf("%d", a+i);
		printf("Case #%d: ", gl);

		FILL(dp, -1);
		printf("%d\n", Rec(0, 275));
	}

	return 0;
}