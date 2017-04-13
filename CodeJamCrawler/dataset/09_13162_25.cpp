#include <cstdio>
#include <algorithm>
#include <vector>
#include <complex>
#include <cmath>
#include <set>

using namespace std;

const int MAX_N = 1000 + 10;
int N;
pair<int, int> seq[MAX_N];

vector<int> adj[MAX_N];

bool oneColor() {
	for (int i = 0; i < N; ++i)
		if (adj[i].size() != 0)
			return false;
	return true;
}

bool twoColor() {
	static int color[MAX_N], q[MAX_N];
	fill(color, color + N, -1);
	for (int i = 0; i < N; ++i) {
		if (color[i] != -1)
			continue;
		color[i] = 0;
		int front = -1, rear = 0; q[0] = i;
		while (front++ < rear) {
			int x = q[front];
			for (vector<int>::iterator iter = adj[x].begin(); iter != adj[x].end(); ++iter) {
				if (color[*iter] == color[x])
					return false;
				if (color[*iter] == -1) {
					color[*iter] = 1 - color[x];
					q[++rear] = *iter;
				}
			}
		}
	}
	return true;
}

int lastColor[40], M, x[1000], y[1000], minY, maxY;
set<int> tried[1000];
bool searchColor(int now, int limit) {
	if (now == -1)
		return true;

	int code = 0;
	for (int i = minY; i <= maxY; ++i)
		code = code * (limit + 1) + (lastColor[i] + 1);
	if (tried[now].find(code) != tried[now].end())
		return false;
	tried[now].insert(code);

	int used = 0, curY = y[now], prev = lastColor[curY];
	if (lastColor[curY] != -1)
		used |= 1 << lastColor[curY];
	if (lastColor[curY - 1] != -1)
		used |= 1 << lastColor[curY - 1];
	if (lastColor[curY + 1] != -1)
		used |= 1 << lastColor[curY + 1];
	for (int i = 0; i < limit; ++i)
		if ((used & (1 << i)) == 0) {
			lastColor[curY] = i;
			if (searchColor(now - 1, limit))
				return true;
		}
	lastColor[curY] = prev;
	return false;
}

bool tryColor(int _minY, int _maxY, int limit) {
	minY = _minY; maxY = _maxY;
	M = 0;
	for (int i = 0; i < N; ++i)
		if (minY <= seq[i].second && seq[i].second <= maxY)
			y[M++] = seq[i].second;
	for (int i = 0; i < M; ++i)
		tried[i].clear();
	//printf("%d %d - %de\n", minY, maxY, M);
	//for (int i = 0; i < M; ++i)
	//	printf("%d ", y[i]);
	//printf("\n");
	fill(lastColor, lastColor + 40, -1);
	return searchColor(M - 1, limit);
}

int cnt[40];
bool mySearchColor(int limit) {
	for (int i = 1, last = -1; i <= 31; ++i)
		if (cnt[i] == 0 && last != -1) {
			if (!tryColor(last, i - 1, limit))
				return false;
			last = -1;
		} else if (cnt[i] != 0 && last == -1)
			last = i;
	return true;
}

int solve() {
	for (int i = 0; i < N; ++i)
		adj[i].clear();
	fill(cnt, cnt + 40, 0);
	for (int i = 0; i < N; ++i)
		++cnt[seq[i].second];
	for (int i = 0; i < N; ++i) {
		bool foundPrev = false, foundNext = false, foundHere = false;
		assert(seq[i].second >= 1);
		assert(seq[i].second <= 15);
		for (int j = i + 1; j < N; ++j) {
			assert(seq[j].first > seq[i].first);
			if (!foundPrev && seq[j].second == seq[i].second - 1) {
				foundPrev = true;
				adj[i].push_back(j);
				adj[j].push_back(i);
			} else if (!foundNext && seq[j].second == seq[i].second + 1) {
				foundNext = true;
				adj[i].push_back(j);
				adj[j].push_back(i);
			} else if (!foundHere && seq[j].second == seq[i].second) {
				foundHere = true;
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	if (mySearchColor(2) != twoColor())
	{
		printf("ERROR! %d %d\n", mySearchColor(2), twoColor());
		printf("%d\n", N);
		for (int i = 0; i < N; ++i)
			printf("%d %d\n", seq[i].first, seq[i].second);
		return -1;
	}
	if (oneColor())
		return 1;
	else if (twoColor())
		return 2;
	else if (mySearchColor(3))
		return 3;
	else if (mySearchColor(4))
		return 4;
	else
		return 5;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tId = 1; tId <= T; ++tId) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
			scanf("%d %d", &seq[i].first, &seq[i].second);
		sort(seq, seq + N);
		printf("Case #%d: %d\n", tId, solve());
	}
	return 0;
}

