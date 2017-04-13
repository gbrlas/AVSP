#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int R, C, origCnt, trgtCnt;
pair<int, int> orig[10], trgt[10];
char g[20][20];

inline long long encode(pair<int, int> * box, int cnt) {
	sort(box, box + cnt);
	long long res = 0;
	for (int i = 0; i < cnt; ++i)
		res = res * 256 + box[i].first * 16 + box[i].second;
	return res;
}
inline void decode(long long code, pair<int, int> * box, int cnt) {
	for (int i = cnt -1 ; i >= 0; --i) {
		int cur = code & 255;
		box[i].first = cur / 16;
	        box[i].second = cur & 15;
		code /= 256;
	}
}
int root[10];
int findRoot(int x) {
	int p = x, q = x, tmp;
	while (root[p] != p)
		p = root[p];
	while (p != q) {
		tmp = root[q];
		root[q] = p;
		q = tmp;
	}
	return p;
}
const int GO[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int getCnt() {
	for (int i = 0; i < origCnt; ++i)
		root[i] = i;
	int cnt = origCnt;
	for (int i = 0; i < origCnt; ++i)
		for (int j = i + 1; j < origCnt; ++j)
			if (abs(orig[i].first - orig[j].first) + abs(orig[i].second - orig[j].second) == 1) {
				int a = findRoot(i), b = findRoot(j);
				if (a != b) {
					root[b] = a; --cnt;
				}
			}
	return cnt;
}

int solve() {
	long long srcCode = encode(orig, origCnt);
	long long trgtCode = encode(trgt, trgtCnt);
	assert(origCnt == trgtCnt);
	queue< pair<long long,int> > q;
	set< long long > v;
	q.push(make_pair(srcCode, 0));
	v.insert(srcCode);
	if (srcCode == trgtCode)
		return 0;
	while (!q.empty()) {
		long long code = q.front().first; int step = q.front().second; q.pop();
		decode(code, orig, origCnt);
		int tot = getCnt();
	//	for (int i = 0; i < origCnt; ++i)
	//		printf("%d %d, ", orig[i].first, orig[i].second);
	//	printf("Cnt = %d, step = %d\n", tot, step);
		for (int i = 0; i < origCnt; ++i)
			for (int k = 0; k < 4; ++k) {
				int dx = orig[i].first + GO[k][0], dy = orig[i].second + GO[k][1];
				int sx = orig[i].first - GO[k][0], sy = orig[i].second - GO[k][1];
				//printf("-- %d %d -> %d %d (%d, %d)\n", orig[i].first, orig[i].second, dx, dy, sx, sy);
				if (0 <= dx && dx < R && 0 <= dy && dy < C && g[dx][dy] != '#' &&
					0 <= sx && sx < R && 0 <= sy && sy < C && g[sx][sy] != '#') {
					bool fail = false;
					for (int j = 0; j < origCnt; ++j)
						if (orig[j].first == dx && orig[j].second == dy ||
							orig[j].first == sx && orig[j].second == sy) {
							fail = true;
							break;
						}
					if (!fail) {
						orig[i].first = dx; orig[i].second = dy;
						if (tot == 1 || tot > 1 && getCnt() == 1) {
							for (int j = 0; j < trgtCnt; ++j)
								trgt[j] = orig[j];
							long long newCode = encode(trgt, trgtCnt);
							if (newCode == trgtCode)
								return step + 1;
							if (v.find(newCode) == v.end()) {
								v.insert(newCode);
								q.push(make_pair(newCode, step + 1));
							}

						}
						orig[i].first -= GO[k][0]; orig[i].second -= GO[k][1];
					}
				}
			}
	}
	return -1;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tId = 1; tId <= T; ++tId) {
		scanf("%d %d", &R, &C);
		origCnt = 0; trgtCnt = 0;
		for (int i = 0; i < R; ++i)  {
			scanf("%s", g[i]);
			for (int j = 0; j < C; ++j)
				if (g[i][j] == 'x')
					trgt[trgtCnt++] = make_pair(i, j);
				else if (g[i][j] == 'o')
					orig[origCnt++] = make_pair(i,j);
				else if (g[i][j] == 'w') {
					orig[origCnt++] = make_pair(i, j);
					trgt[trgtCnt++] = make_pair(i, j);
				}
		}
		//assert(origCnt <= 2);
		//assert(trgtCnt <= 2);
		printf("Case #%d: %d\n", tId, solve());
	}
	return 0;
}
