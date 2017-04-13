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

LL dp[12][1<<12][12];
int m[1<<12], n;
int p[12][1<<12];
int m1[12][1<<12];

LL Rec(int rr, int cc, int kk=0)
{
	if (rr == 0) return 0;
	LL& res = dp[rr][cc][kk];
	if (res != -1) return res;

	res = p[rr-1][cc] + Rec(rr-1, cc*2, kk) + Rec(rr-1, cc*2+1, kk);

	if (kk < m1[rr][cc])
		res = min(res, Rec(rr-1, cc*2, kk+1) + Rec(rr-1, cc*2+1, kk+1));

	return res;
}

int main() {

	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);

	int tc, gl;
	for(scanf("%d", &tc), gl=1; tc-->0; gl++)
	{
		scanf("%d", &n);
		FOR(i, 0, (1<<n)) scanf("%d", m+i);
		FOR(i, 0, n)
			FOR(j, 0, 1<<(n-i-1))
				scanf("%d", &p[i][j]);
		FOR(j, 0, 1<<n)
			m1[0][j] = m[j];
		FOR(i, 1, n+1) {
			FOR(j, 0, 1<<(n-i))
				m1[i][j] = min(m1[i-1][2*j], m1[i-1][2*j+1]);
		}
		FILL(dp, -1);
		LL res = Rec(n, 0);
		printf("Case #%d: %lld\n", gl, res);
	}

	return 0;
}