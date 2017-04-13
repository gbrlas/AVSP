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

PII p[22];
int n, d;
const double eps = 1e-9;

bool Can(double T)
{
	double last = -1e100;
	FOR(i, 0, n)
	{
		double mm = (double)p[i].first-T;
		mm = max(mm, last);
		if (mm-p[i].first-eps > T) return false;
		if ((double)(p[i].second-1) * (double)d + mm - eps - (double)p[i].first > T) return false;
		last = mm + (double)(p[i].second-1)*(double)d;
		last = last + (double)d;
	}
	return true;
}

int main() {

	freopen((prob+".in").c_str(), "r", stdin);
	freopen((prob+".out").c_str(), "w", stdout);

	int tc, gl=1; scanf("%d", &tc);

	while (tc --> 0)
	{
		scanf("%d %d", &n, &d);
		FOR(i, 0, n)
		{
			int pp, vv; scanf("%d %d", &pp, &vv);
			p[i] = PII(pp, vv);
		}

		double L = 0, R = 1e60, res;
		FOR(it, 0, 2000)
		{
			double M = (L+R)/2.;
			if (Can(M))
				R = res = M;
			else
				L = res = M;
		}

		printf("Case #%d: %.8lf\n", gl++, res);
	}

	return 0;
}