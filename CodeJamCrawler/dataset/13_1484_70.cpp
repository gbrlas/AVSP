#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
typedef long long llong;

#define mp make_pair
#define lowbit(x) ((x) & (-(x)))
#define pf(x) ((x) * (x))
#define two(x) (1 << (x))
#define twoL(x) ((llong) 1 << (x))
#define clr(x, c) memset(x, c, sizeof(x))

inline void ch_max(int &x, int y) {if (x < y) x = y;}
inline void ch_min(int &x, int y) {if (x > y) x = y;}

const double pi = acos(-1.0);
const double eps = 1e-9;

template<typename T>
void Scanf(const vector<string> &vs, vector<T> &d) {
	string str;stringstream ss;
	for (int i = 0; i < vs.size(); ++i) str += vs[i];
	ss << str;d.clear();for (T t; ss >> t; ) d.push_back(t);
}

const int N = 105;
int a[N][N];
int n, m;

int na[N], ma[N];

int main() {
	freopen("temp\\B-large.in", "r", stdin);
	//freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t, nc = 0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		clr(na, 0);
		clr(ma, 0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%d", &a[i][j]);
				ch_max(na[i], a[i][j]);
				ch_max(ma[j], a[i][j]);
			}
		}
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (a[i][j] != min(na[i], ma[j])) {
					ok = false;
				}
			}
		}
		if (ok) printf("Case #%d: YES\n", ++nc);
		else printf("Case #%d: NO\n", ++nc);
	}
	return 0;
}