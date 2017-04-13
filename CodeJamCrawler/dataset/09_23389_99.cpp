#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <numeric>
#include <cstdio>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

int mat[100][100], res[100][100];
struct PT {
	int x, y;
	PT(int _x, int _y) {
		x = _x; y = _y;
	}
	PT() {}
};

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int h, w;
PT findP(PT& p) {
	PT res;
	res.x = p.x;
	res.y = p.y;
	int minA = mat[p.x][p.y];
	bool goon = true;

	while (goon) {
		int temp = minA, x = res.x, y = res.y, xx, yy;
		for (int i = 0; i < 4; ++i) {
			x = res.x + dx[i];
			y = res.y + dy[i];
			if (x > -1 && x < h && y > -1 && y < w && mat[x][y] < temp) {
				temp = mat[x][y];
				xx = x;
				yy = y;
			}
		}
		if (temp < minA) {
			minA = temp;
			res.x = xx;
			res.y = yy;
		} else {
			goon = false;
		}
	}

	return res;
}

int main() {
	freopen("E:\\Ëã·¨\\GCJ\\09qual\\B-small.in", "r", stdin);
	freopen("E:\\Ëã·¨\\GCJ\\09qual\\B-small.out", "w", stdout);
	int t = 0;
	cin >> t;

	for (int cnt = 1; cnt <= t; ++cnt) {
		cin >> h >> w;
		memset(res, -1, sizeof res);
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				cin >> mat[i][j];

		int r = 0;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (res[i][j] < 0) {
					PT pt = findP(PT(i,j));
					if (res[pt.x][pt.y] < 0) {
						res[i][j] = res[pt.x][pt.y] = r++;
					} else {
						res[i][j] = res[pt.x][pt.y];
					}
				}
			}
		}

		cout << "Case #" << cnt << ":" << endl;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j)
				cout << static_cast<char>('a' + res[i][j]) << " ";
			cout << endl;
		}
	}
	return 0;
}
