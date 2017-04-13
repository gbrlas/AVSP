#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define FU(i,a,b) for(i = a; i < b; i++)
#define FD(i,a,b) for(i = a; i > b; i--)
#define FE(i,a) for(i = a.begin(); i != a.end(); i++)
#define PB(a,b) a.push_back(b)
#define SZ(a) (int)a.size()

typedef long long LL;
typedef vector<int> VI;

int n, m, a;

int main(void) {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int c;
	scanf("%d", &c);
	for(int t = 1; t <= c; t++) {
		scanf("%d%d%d", &n, &m, &a);

		printf("Case #%d: ", t);

		bool q = true;

		for(int y = 0; q && y <= m; y++) {
			int k = n*y-a;
			if(k < 0) continue;

			for(int x = n; x >= 0; x--) {
				if(k > m*x) break;
				if(k%x == 0) {
					printf("0 0 %d %d %d %d\n", n, k/x, x, y);
					q = false;
					break;
				}
			}
		}

		if(q) printf("IMPOSSIBLE\n");
	}

	exit(0);
}