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

int r, k, n;
int a[2001];
int s[2001];
LL rs[2001];

int next[2001];
int fl[1001];

int FindNext(int nn) {
	int ss = 0;
	FOR(i, 0, n) {
		ss += a[nn+i];
		if (ss > k) return i;
	}
	return n;
}

LL Simul(int& nn, int m) {
	LL res = 0;
	while (m --> 0) {
		res += (LL)(s[nn+next[nn]]-s[nn]);
		nn = (nn+next[nn])%n;
	}
	return res;
}

int main() {

	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int t; scanf("%d", &t);
	FOR(gl, 1, t+1) {
		scanf("%d %d %d", &r, &k, &n);
		FOR(i, 0, n) {
			scanf("%d", a+i);
			a[n+i] = a[i];
		}
		s[0] = 0; FOR(i, 0, 2*n) s[i+1] = s[i] + a[i];
		FOR(i, 0, n)
			next[i] = FindNext(i);

		FILL(fl, false);
		LL kk = 0, ss = 0, res = 0;
		int nn = 0;
		
		while (r --> 0) {
			ss += s[nn+next[nn]]-s[nn];
			res += s[nn+next[nn]]-s[nn];
			nn = (nn+next[nn])%n;
			++kk;
			if (fl[nn]) {
				int len = kk-fl[nn];
				res += (LL)(r/len)*(ss-rs[nn]);
				res += Simul(nn, r%len);
				break;
			}
			fl[nn] = kk;
			rs[nn] = ss;
		}

		printf("Case #%d: %lld\n", gl, res);
	}

	return 0;
}