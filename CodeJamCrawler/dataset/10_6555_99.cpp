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

int n, a[1001];

LL gcd(LL a, LL b) { return b?gcd(b, a%b):a; }

LL min(LL a, LL b) { return a<b?a:b; }

int main() {

	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int t; scanf("%d", &t);
	FOR(gl, 1, t+1) {
		scanf("%d", &n);
		FOR(i, 0, n) scanf("%d", a+i);
		sort(a, a+n, greater<int>() );
		LL r = a[0]-a[1];
		FOR(i, 2, n)
			r = gcd(r, a[0]-a[i]);
		LL res = (r-a[0]%r)%r;
		FOR(i, 1, n)
			res = min(res, (r-a[i]%r)%r);
		printf("Case #%d: %lld\n", gl, res);
	}

	return 0;
}