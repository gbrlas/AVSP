#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(i=0;i<n;i++)
#define F1(i,n) for(i=1;i<=n;i++)
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;

struct node {
	int v;
	int type; // 1: AND GATE, 0: OR GATE
	int ch; // changeable
};

int m, v;
node t[1000] = {0};


int logic(int gate, int a, int b) {
	if (gate == 0) {
		if (a == 1 || b == 1) return 1;
		return 0;
	} else if (gate == 1) {
		if (a == 1 && b == 1) return 1;
		return 0;
	}
}

int findV(int sw) {
	for (int i = (m - 1) / 2; i >= 1; i--, sw >>= 1) {
		int gate = t[i].type;
		if ((sw > 0) && (sw & 1) == 1 && (t[i].ch == 1)) {
			if (gate == 1) gate = 0;
			else gate = 1;
		}
		//printf("%d %d\n", i,  sw & 1);
		t[i].v = logic(gate, t[2*i].v, t[2*i + 1].v);
	}
	return t[1].v;
}

int countCh(int sw) {
	int count = 0;
	while (sw > 0) {
		if (sw & 1 == 1) count++;
		sw >>= 1;
	}
	return count;
}

int twoPow(int a, int b) {
	int ret = a;
	for (int i = 1; i < b; i++)
		ret *= a;
	return ret;
}

int main() {

	int tt, tn;
	cin >> tn;
	F1(tt,tn) {
		cin >> m >> v;
		if (v != 0 && v != 1) {
			printf("#Case #%d: IMPOSSIBLE\n", tt);
			continue;
		}
		for (int i = 1; i <= (m - 1) / 2; i++)
			cin >> t[i].type >> t[i].ch;
		for (int i = (m + 1) / 2; i <= m; i++)
			cin >> t[i].v;
		
		

		int min = m + 100;
		for (int i = 0; i < twoPow(2, (m - 1)/2); i++) {
			int ans = findV(i);
			if (ans == v) {
				int tmp = countCh(i);
				if (tmp < min) min = tmp;
			}
		}

		if (min < m + 100)
			printf("Case #%d: %d\n", tt, min);
		else printf("Case #%d: IMPOSSIBLE\n", tt);
	}

	return 0;
}

