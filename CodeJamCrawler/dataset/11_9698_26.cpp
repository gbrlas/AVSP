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

const string prob = "A";
const double eps = 1e-9;

int x, s, r, t, n;
vector< pair<int, int> > v;

int main() {

	freopen((prob+".in").c_str(), "r", stdin);
	freopen((prob+".out").c_str(), "w", stdout);

	int tc, gl=1; scanf("%d", &tc);

	while (tc --> 0)
	{
		scanf("%d %d %d %d %d", &x, &s, &r, &t, &n);
		int sum = 0; v.clear(); v.resize(n);
		FOR(i, 0, n)
		{
			int b, e;
			scanf("%d %d %d", &b, &e, &v[i].first);
			v[i].second = e-b;
			sum += e-b;
		}
		v.push_back(make_pair(0, x-sum));

		double res = 0, T = t;
		sort(v.begin(), v.end());
		FOR(i, 0, SZ(v))
		{
			double ss = v[i].second;
			double vv = v[i].first;

			if (T*(vv+(double)r)+eps<ss) {
				ss -= T*(vv+(double)r);
				res += T;
				res += ss/(double)(v[i].first+s);
				v[i].second = 0;
				break;
			}
			else {
				double tt = ss/(vv+(double)r);
				res += tt; T -= tt;
				v[i].second=0;
			}
		}
		FOR(i, 0, SZ(v))
			res += (double)v[i].second/(double)(v[i].first+s);

		printf("Case #%d: %.10lf\n", gl++, res);
	}

	return 0;
}	