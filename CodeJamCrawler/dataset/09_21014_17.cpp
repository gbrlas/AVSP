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

typedef pair<int, int> PII;
typedef pair<int, long long> PIL;

const int MAXS = 12;
const int MAXN = 5;

const int MOVES[4][2] = {
	{-1, 0},
	{0, -1},
	{0, 1},
	{1, 0} 
};

int n;
int si, sj;
char grid[MAXS][MAXS + 1];
map<long long, int> minDis;

inline bool isValid(int i, int j) {
	return (0 <= i && i < si && 0 <= j && j < sj && grid[i][j] != '#');
}

inline long long compress(PII arr[]) {
	sort(arr, arr + n);
	long long res = 0;
	for (int i = 0; i < n; i++) {
		res = (res << 8) | (arr[i].first << 4) | arr[i].second;
	}
	return res;
}

inline void decompress(long long con, PII arr[]) {
	for (int i = n - 1; i >= 0; i--) {
		arr[i].second = con & 15;
		arr[i].first = (con >> 4) & 15;
		con >>= 8;
	}
}

inline bool checkConnect(PII arr[]) {
	bool tags[MAXS][MAXS];
	memset(tags, false, sizeof(tags));
	for (int i = 1; i < n; i++) {
		tags[arr[i].first][arr[i].second] = true;
	}
	queue<PII> bfs;
	bfs.push(arr[0]);
	int num = 0;
	while (!bfs.empty()) {
		PII p = bfs.front();
		bfs.pop();
		num++;
		for (int k = 0; k < 4; k++) {
			int ni = p.first + MOVES[k][0];
			int nj = p.second + MOVES[k][1];
			if (isValid(ni, nj) && tags[ni][nj]) {
				tags[ni][nj] = false;
				bfs.push(PII(ni, nj));
			}
		}
	}
	return n == num;
}

//inline void update(priority_queue<PIL, vector<PIL>, greater<PIL> > & heap, long long con, int dis) {
//	map<long long, int>::iterator it = minDis.find(con);
//	if (it == minDis.end()) {
//		minDis[con] = dis;
//		heap.push(PIL(dis, con));
//	} else if (it->second > dis) {
//		it->second = dis;
//		heap.push(PIL(dis, con));
//	}
//}

int main() {
	int caseNum;
	cin >> caseNum;
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		cin >> si >> sj;
		for (int i = 0; i < si; i++) {
			cin >> grid[i];
		}
		int ns = 0, ne = 0;
		PII start[MAXN], end[MAXN];
		for (int i = 0; i < si; i++) {
			for (int j = 0; j < sj; j++) {
				if (grid[i][j] == 'o' || grid[i][j] == 'w') {
					start[ns++] = PII(i, j);
				}
				if (grid[i][j] == 'x' || grid[i][j] == 'w') {
					end[ne++] = PII(i, j);
				}
			}
		}
		n = ns;
		minDis.clear();
		//priority_queue<PIL, vector<PIL>, greater<PIL> > heap;
		queue<long long> bfs;
		long long scon = compress(start);
		long long econ = compress(end);
		int ans = -1;
		bfs.push(scon);
		minDis[scon] = 0;
		if (scon == econ) {
			ans = 0;
		}
		PII cur[MAXN];
		PII next[MAXN];
		while (!bfs.empty() && ans < 0) {
			long long con = bfs.front();
			bfs.pop();
			decompress(con, cur);
			int dis = minDis[con];
			bool isCon = checkConnect(cur);
			for (int k = 0; k < n; k++) {
				for (int d1 = 0; d1 < 4; d1++) {
					int ni = cur[k].first + MOVES[d1][0];
					int nj = cur[k].second + MOVES[d1][1];
					int pi = cur[k].first + MOVES[3 - d1][0];
					int pj = cur[k].second + MOVES[3 - d1][1];
					bool isOk = isValid(ni, nj) && isValid(pi, pj);
					for (int p = 0; p < n && isOk; p++) {
						if (p != k && ((cur[p].first == ni && cur[p].second == nj) || (cur[p].first == pi && cur[p].second == pj))) {
							isOk = false;
						}
					}
					if (isOk) {
						memcpy(next, cur, sizeof(PII) * n);
						next[k].first = ni;
						next[k].second = nj;
						if (isCon || checkConnect(next)) {
							long long ncon = compress(next);
							if (ncon == econ) {
								ans = dis + 1;
								break;
							} else if (minDis.find(ncon) == minDis.end()) {
								minDis[ncon] = dis + 1;
								bfs.push(ncon);
							}
						}
						//for (int d2 = 0; d2 < 4; d2++) {
						//	if (d1 + d2 == 3) {
						//		continue;
						//	}
						//	int ei = ni + MOVES[d2][0];
						//	int ej = nj + MOVES[d2][1];
						//	isOk = isValid(ei, ej);
						//	if (!isOk) {
						//		continue;
						//	}
						//	for (int p = 0; p < n; p++) {
						//		if (p != k && cur[p].first == ei && cur[p].second == ej) {
						//			memcpy(next, cur, sizeof(PII) * n);
						//			next[k].first = ni;
						//			next[k].second = nj;
						//			update(heap, compress(next), pr.first + 1);
						//			isOk = false;
						//		}
						//	}
						//	if (isOk) {
						//		for (int d3 = 0; d3 < 4; d3++) {
						//			int fi = ei + MOVES[d3][0];
						//			int fj = ej + MOVES[d3][1];
						//			if (isValid(fi, fj)) {
						//				for (int p = 0; p < n; p++) {
						//					if (p != k && cur[p].first == fi && cur[p].second == fj) {
						//						memcpy(next, cur, sizeof(PII) * n);
						//						next[k].first = fi;
						//						next[k].second = fj;
						//						update(heap, compress(next), pr.first + 2);
						//					}
						//				}
						//			}
						//		}
						//	}
						//}
					}
				}
			}
		}
		cout << "Case #" << caseIndex << ": " << ans << endl;
	}

	return 0;
}
