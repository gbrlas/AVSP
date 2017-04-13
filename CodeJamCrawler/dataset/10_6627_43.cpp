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

map<int, int> mm;
int n;
int _x1[11], _x2[11], __y1[11], _y2[11];
int a[101][101];

bool Yes(int xx, int yy)
{
	if (!xx || !yy) return false;
	return a[xx][yy];
}

int main() {

	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int tc, gl;
	for(scanf("%d", &tc), gl=1; tc-->0; gl++)
	{
		mm.clear(); FILL(a, 0);
		scanf("%d", &n);
		FOR(i, 0, n)
		{
			scanf("%d %d %d %d", &_x1[i], &__y1[i], &_x2[i], &_y2[i]);
			FOR(xx, _x1[i], _x2[i]+1)
				FOR(yy, __y1[i], _y2[i]+1)
					a[xx][yy] = 1;
		}
		int kk = 0;
		FOR(xx, 0, 101)
			FOR(yy, 0, 101)
				kk += a[xx][yy];

		int res = 0;
		vector<PII> Add, Del;
		while (kk)
		{
			Add.clear(); Del.clear();
			res++;
			FOR(xx, 0, 101)
				FOR(yy, 0, 101)
					if (a[xx][yy])
					{
						if (!Yes(xx-1, yy) && !Yes(xx, yy-1))
							Del.push_back(PII(xx, yy));
					}
					else
					{
						if (Yes(xx-1, yy) && Yes(xx, yy-1))
							Add.push_back(PII(xx, yy));
					}

			kk = kk-SZ(Del)+SZ(Add);
			FOR(i, 0, SZ(Del))
				a[Del[i].first][Del[i].second] = 0;
			FOR(i, 0, SZ(Add))
				a[Add[i].first][Add[i].second] = 1;
		}
		printf("Case #%d: %d\n", gl, res);
	}

	return 0;
}