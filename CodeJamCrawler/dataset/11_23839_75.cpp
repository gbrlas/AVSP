#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
#include <string>
#include <deque>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cmath>

using namespace std;

typedef long long LL;

struct pos_t {
	LL pos;
	LL cnt;
};

pos_t p[205];

int main() {
	int cases;
	cin >> cases;
	for (int caseid = 1; caseid <= cases; ++caseid) {
		cout << "Case #" << caseid << ": ";
		int C;
		LL D;
		cin >> C >> D;
		D *= 2;
		for (int i = 0; i < C; ++i) {
			cin >> p[i].pos >> p[i].cnt;
			p[i].pos *= 2;
			if (i > 0)
				assert( p[i].pos > p[i-1].pos );
		}
		LL u = 0;
		LL v = (LL) 10000000; // 10^7
		v *= v;
		while (u <= v) {
			LL t = (u + v) / 2;
			int ok = 1;
			LL from = 0;
			for (int i = 0; i < C; ++i) {
				// 1st:  p[i].pos-t;
				// last: p[i].pos-t+(p[i].cnt-1)*D
				if (i == 0)
					from = p[i].pos - t;
				else
					from = max(from, p[i].pos - t);

				LL last = from + (p[i].cnt - 1) * D;
				if (last > p[i].pos + t) {
					ok = 0;
					break;
				}
				from = last + D;
			}
			if (!ok) {
				u = t + 1;
			} else {
				v = t - 1;
			}
		}
		if (u % 2 == 0)
			cout << u / 2 << endl;
		else
			cout << (u / 2) << ".5\n";
	}
	return 0;
}
