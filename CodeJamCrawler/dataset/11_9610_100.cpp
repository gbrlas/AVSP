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

int main() {

	freopen((prob+".in").c_str(), "r", stdin);
	freopen((prob+".out").c_str(), "w", stdout);

	int tc, gl=1; scanf("%d", &tc);

	while (tc --> 0)
	{
		int n, nom, res=0;
		int p[2] = {1, 1}, f[2] = {0, 0};
		scanf("%d", &n);
		FOR(i, 0, n)
		{
			char op[2]; int t, d;
			scanf("%s %d", op, &t);		
			nom = (op[0]!='B');
			
			d = abs(p[nom]-t);
			int k = min(f[nom], d);
			f[nom] -= k; d-= k;
			res += d+1; f[nom^1] += d+1; p[nom] = t;
			f[nom]=0;
		}
		printf("Case #%d: %d\n", gl++, res);

	}

	return 0;
}