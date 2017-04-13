#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
#define PB push_back
#define MP make_pair
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
const int MAXN = 1010;
const double eps = 1e-9;
int b[MAXN], e[MAXN], w[MAXN], ind[MAXN];

inline bool cmp(const int & x, const int & y) {
	if (w[x] == w[y])
		return (e[x] - b[x]) > (e[y] - b[y]);
	return w[x] < w[y];
}
int main() {
	int testnum, x, s, r, T, n, tot, last, cur;
	double ret, dt, t;
	
	scanf("%d", &testnum);
	for (int test = 1;test <= testnum;test++) {
		scanf("%d%d%d%d%d", &x, &s, &r, &T, &n);
		t = T;
		last = tot = 0;
		ret = 0;
		for (int i = 0;i < n;i++) {
			scanf("%d%d%d", &b[i], &e[i], &w[i]);
			ret += (double)(b[i] - last) / s;
			ret += (double)(e[i] - b[i]) / (s + w[i]);
			last = e[i];
			ind[i] = i;
			tot += (e[i] - b[i]);
		}
		ret += (double)(x - last) / s;
		b[n] = 0; e[n] = x - tot; w[n] = 0;
		ind[n] = n;
		n++;
		sort(ind, ind + n, cmp);
		cur = 0;
		while (t > eps && cur < n) {
			int c = ind[cur];
			dt = (double)(e[c] - b[c]) / (r + w[c]);
			if (dt > t + eps) {
				ret = ret - (double)t * (r + w[c]) / (s + w[c]) + t;
				t = 0;
			} else {
				ret = ret - (double)(e[c] - b[c]) / (s + w[c]) + dt;
				t -= dt;
			}
			cur++;
		}
		printf("Case #%d: %.20lf\n", test, ret);
	}
	return 0;
}
