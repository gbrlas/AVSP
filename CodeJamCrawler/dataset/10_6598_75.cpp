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

int dp[1001][1001];

int Brut(int A, int B)
{
	if (!A || !B) return 1;
	if (A<B) swap(A, B);

	int& res = dp[A][B];
	if (res != -1) return res;
	while (A>=B)
	{
		A-=B;
		if (!Brut(A, B))
			return res=1;
	}
	return res=0;
}

int dp1[500][2];

int Win(int A, int B, int mm=0, int ll = 0)
{
	if (A<B) swap(A, B);
	if (!B) return 1;

	int& res = dp1[mm][ll];
	if (res != -1) return res;

	int k = A/B;
	if (k == 1)
		return (res=1-Win(B, A%B, mm+1, 1-ll));

	if (Win(B, A%B, mm+1, 1-ll) == 0)
		return res=1;
	if (Win(B, A%B, mm+1, ll) == 1)
		return res=1;

	return res=0;
}

int main() {

	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);

	int tc, gl=0; scanf("%d", &tc);
	while (tc --> 0)
	{
		gl++;
		int a1, a2, b1, b2, res=0;
		scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
		FOR(A, a1, a2+1)
			FOR(B, b1, b2+1) {
				FILL(dp1, -1);
				if (Win(A, B))
					++res;
			}

		printf("Case #%d: %d\n", gl, res);
	}
	return 0;
}