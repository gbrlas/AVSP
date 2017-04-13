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

int fl[1000001];
int from[1000001];
int a[1001];
int d, k;
int P[6] = {10, 100, 1000, 10000, 100000, 1000000};

int powMod(int a, int t, int p)
{
	if (t == 0) return 1;
	LL T = powMod(a, t/2, p);
	T = (T*T)%p;
	if (t&1)
		T = (T*(LL)a)%p;
	return T;
}

int inv(int t, int p)
{
	t = (t%p+p)%p;
	return powMod(t, p-2, p);
}

void getAB(int s2, int s3, int s1, int mod, int& a, int& b)
{
	if (s1==s2)
	{
		if (s3 == s2)
		{
			a = 0; b = s2;
		}
		else
		{
			a = -1; b = -1;
		}
		return;
	}
	int a1 = ((s2-s3)%mod+mod)%mod;
	int a2 = inv(s1-s2, mod);
	a = ((LL)a1*(LL)a2)%mod;
	b = (((LL)s2-(LL)a*(LL)s1)%mod+mod)%mod;
}

int Check(int p)
{
	int a1, b1, a2, b2;
	getAB(a[1], a[2], a[0], p, a1, b1);
	if (a1<0) return -1;
	FOR(i, 2, k-1)
	{
		getAB(a[i], a[i+1], a[i-1], p, a2, b2);
		if (a2<0) return -1;
		if (a1 != a2 || b1 != b2) return -1;
	}
	return ((LL)a1*(LL)a[k-1]+(LL)b1)%p;
}

int main() {

	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	FILL(fl, false);
	FOR(i, 2, 1000000)
		if (!fl[i])
		{
			for(LL j=(LL)i*(LL)i; j<1000000; j+=i)
				fl[j] = true;
		}

	int last = 1000000;
	FORD(i, 1000000, 0)
	{
		from[i] = last;
		if (!fl[i]) last = i;
	}

	int tc, gl;
	for(scanf("%d", &tc), gl=1; tc-->0; gl++)
	{
		scanf("%d %d", &d, &k);
		int mm = 0;
		FOR(i, 0, k) {
			scanf("%d", a+i);
			mm = max(mm, a[i]);
		}
		if (k == 1)
		{
			printf("Case #%d: I don\'t know.\n", gl);
			continue;
		}
		if (count(a, a+k, a[0]) == k)
		{
			printf("Case #%d: %d\n", gl, a[0]);
			continue;
		}
		if (k == 2)
		{
			printf("Case #%d: I don\'t know.\n", gl);
			continue;
		}

		set<int> res;
		FOR(p, from[mm], P[d-1])
			if (!fl[p])
			{
				int t = Check(p);
				if (t == -1) continue;
				res.insert(t);
				if (SZ(res)>1) break;
			}
		if (SZ(res)>1)
			printf("Case #%d: I don\'t know.\n", gl);
		else
			printf("Case #%d: %d\n", gl, *res.begin());
	}

	return 0;
}