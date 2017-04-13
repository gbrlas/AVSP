#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cctype>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#define FILE_IN  "B-large.in"
#define FILE_OUT "B-large.out"

typedef pair<int, int> pii;
typedef stack<pii> spii;

#define SIZE 103
#define D 4

int dx[D] = {-1, 0, 0, 1};
int dy[D] = {0, -1, 1, 0};

void solve() {
	int h, w;
	scanf("%d%d", &h, &w);
	int el[SIZE][SIZE];
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			scanf("%d", &el[i][j]);
	
	int basin[SIZE][SIZE];
	fill(basin[0], basin[SIZE], -1);
	int bn = 0;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			if (basin[i][j] < 0) {
				int ii = i, jj = j;
				spii path;
				while (true) {
					path.push(pii(ii, jj));
					int flow = -1;
					for (int d = 0; d < D; ++d) {
						int nii = ii + dx[d];
						int njj = jj + dy[d];
						if (nii < 0 || nii >= h || njj < 0 || njj >= w)
							continue;
						if (el[nii][njj] >= el[ii][jj])
							continue;
						if (flow < 0 || el[nii][njj] < el[ii + dx[flow]][jj + dy[flow]])
							flow = d;
					}
					if (flow < 0)
						break;
					ii += dx[flow];
					jj += dy[flow];
					if (basin[ii][jj] >= 0)
						break;
				}
				int bas = basin[ii][jj];
				if (bas < 0)
					bas = bn++;
				while (!path.empty()) {
					basin[path.top().first][path.top().second] = bas;
					path.pop();
				}
			}
	
	char assign[26];
	fill(assign, assign + 26, 0);
	int a = 0;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			if (assign[basin[i][j]] == 0)
				assign[basin[i][j]] = a++ + 'a';
	
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (j)
				printf(" ");
			printf("%c", assign[basin[i][j]]);
		}
		printf("\n");
	}
}

int main() {
	freopen(FILE_IN, "r", stdin);
	freopen(FILE_OUT, "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d:\n", i);
		solve();
	}
	return 0;
}
