#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 109;
int bd[N][N];
int row[N], col[N];

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%d", &bd[i][j]);
			}
			row[i] = *max_element(&bd[i][0], &bd[i][m]);
		}
		for (int i = 0; i < m; ++i) {
			int maxv = 0;
			for (int j = 0; j < n; ++j) {
				maxv = max(maxv, bd[j][i]);
			}
			col[i] = maxv;
		}
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (bd[i][j] < row[i] && bd[i][j] < col[j]) {
					ok = false;
				}
			}
		}
		if (ok) {
			printf("Case #%d: YES\n", t);
		} else {
			printf("Case #%d: NO\n", t);
		}
	}
	return 0;
}
