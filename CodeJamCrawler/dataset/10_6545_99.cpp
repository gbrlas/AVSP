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

int t, n, k;

int main() {

	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	scanf("%d", &t);
	int tc = 0;
	while (t --> 0) {
		tc++;
		printf("Case #%d: ", tc);
		scanf("%d %d", &n, &k);
		int m = (1<<n)-1;
		if ((k&m) == m)
			printf("ON\n");
		else
			printf("OFF\n");
	}

	return 0;
}