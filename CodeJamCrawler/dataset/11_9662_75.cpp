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

char a[128][128];
int w[128], pl[128];

double wp[128], owp[128], oowp[128];

int main() {

	freopen((prob+".in").c_str(), "r", stdin);
	freopen((prob+".out").c_str(), "w", stdout);

	int tc, gl=1; scanf("%d", &tc);

	while (tc --> 0)
	{
		int n; scanf("%d", &n);
		FOR(i, 0, n) {
			scanf("%s", a[i]);
			w[i] = pl[i] = 0;
			FOR(j, 0, n)
				pl[i] += a[i][j]!='.', w[i] += a[i][j]=='1';
		}

		FOR(i, 0, n) {
			wp[i] = (double)w[i]/(double)pl[i];
		}

		FOR(i, 0, n)
		{
			owp[i] = 0;
			int k = 0;
			FOR(j, 0, n)
				if (a[i][j]!='.')
				{
					int ch = w[j];
					int zn = pl[j];
					ch -= a[j][i]=='1';
					zn -= a[j][i]!='.';
					owp[i] += (double)ch/(double)zn;
					k++;
				}
			owp[i] /= (double)(k);
		}

		FOR(i, 0, n)
		{
			oowp[i] = 0;
			int k = 0;
			FOR(j, 0, n)
				if (a[i][j] != '.') {
					oowp[i] += owp[j];
					k++;
				}
			oowp[i] /= (double)(k);
		}

		printf("Case #%d:\n", gl++);
		FOR(i, 0, n)
			printf("%.10lf\n", 0.25*wp[i]+0.5*owp[i]+0.25*oowp[i]);
	}

	return 0;
}