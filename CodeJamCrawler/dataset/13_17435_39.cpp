#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

typedef long long Long;
const Long mod = 1000002013LL;
const int maxn = 22222;

struct thing {
	Long place, num, t;
} a[maxn];

Long pric;

bool cmp(thing a, thing b) {
	if (a.place != b.place) 
		return a.place < b.place;
	return a.t < b.t;
}

const Long GETON = 1, GETOFF = 2;

Long calc(Long l, Long r, Long n) {
	Long k = r - l;
	Long ans = (pric + pric - k + 1) * k / 2;
	ans = ans % mod;
	ans = ans * n; 
	return ans % mod;
}

map<int, Long> ticket;

void work(int cas) {
	int n, m;
	scanf("%d%d", &n, &m);
	pric = n;
	Long old = 0, ans = 0;
	for (int i = 1; i <= m; ++i) {
		int o, e, p;
		scanf("%d%d%d", &o, &e, &p);
		old += calc(o, e, p);
		a[i].place = o;
		a[i].num = p;
		a[i].t = GETON;
		a[i + m].place = e;
		a[i + m].num = p;
		a[i + m].t = GETOFF;
	}
	int	mm = m + m;
	sort(a + 1, a + mm + 1, cmp);
	ticket.clear();
	for (int i = 1; i <= mm; ++i) {
		if (a[i].t == GETON) 
			ticket[a[i].place] += a[i].num; 
		else {
			while (a[i].num > 0) {
				map<int, Long> :: iterator itr = ticket.end(); --itr;
				Long x = itr -> first, y = itr -> second;
				ticket.erase(itr);
				if (y > a[i].num) {
					ans += calc(x, a[i].place, a[i].num);
					y -= a[i].num;
					a[i].num = 0;
					ticket[x] = y;
				} else {
					ans += calc(x, a[i].place, y);
					a[i].num -= y;
				}
			}
		}
	}
	Long p = old - ans;
	p = p % mod; p += mod;
	p = p % mod;
	printf("Case #%d: ", cas);
	cout << p << endl;
}

int main() {
	int t; scanf("%d", &t);
	for  (int i = 1; i <= t; ++i) 
		work(i);
	return 0;
}
