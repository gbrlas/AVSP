#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include <algorithm>

using namespace std;

const int MAXN = 100;
const int MAXM = 25;

#define _clr(x) memset(x, 0xff, sizeof(int) * n)

int hungary(int n, const bool mat[][MAXN], int * match1, int * match2) {
	int s[MAXN], t[MAXN], p, q, ret = 0, i, j, k;
	_clr(match1);
	_clr(match2);
	for (i = 0; i < n; ret += (match1[i++] >= 0)) {
		_clr(t);
		for (s[p = q = 0] = i; p <= q && match1[i] < 0; p++) {
			for (k = s[p], j = 0; j < n && match1[i] < 0; j++) {
				if (mat[k][j] && t[j] < 0) {
					s[++q] = match2[j];
					t[j] = k;
					if (s[q] < 0) {
						for (p = j; p >= 0; j = p) {
							match2[j] = k = t[j];
							p = match1[k];
							match1[k] = j;
						}
					}
				}
			}
		}
	}
	return ret;
}

inline int pathCover(int n, const bool mat[][MAXN], int * pre, int * next) {
	return n - hungary(n, mat, next, pre);
}


int pos[MAXN][MAXM];
bool adj[MAXN][MAXN];
int dummy[2][MAXN];

int main() {
	int caseNum;
	cin >> caseNum;
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> pos[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				/*adj[j][i] = */adj[i][j] = true;
				for (int k = 0; k < m; k++) {
					if (!(pos[i][k] < pos[j][k])) {
						/*adj[j][i] = */adj[i][j] = false;
						break;
					}
				}
			}
		}
		int ans = pathCover(n, adj, dummy[0], dummy[1]);
		cout << "Case #" << caseIndex << ": " << ans << endl;
	}

	return 0;
}
