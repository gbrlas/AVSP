#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

const int maxn = 1000 + 10;

set<string> dict;
char s[maxn];
int n, k;

void gao1(string t) {
	if (t[0] == 'o') t[0] = '0';
	if (t[0] == 'i') t[0] = '1';
	if (t[0] == 'e') t[0] = '3';
	if (t[0] == 'a') t[0] = '4';
	if (t[0] == 's') t[0] = '5';
	if (t[0] == 't') t[0] = '7';
	if (t[0] == 'b') t[0] = '8';
	if (t[0] == 'g') t[0] = '9';
	dict.insert(t);
}

void gao2(string t) {
	if (t[1] == 'o') t[1] = '0';
	if (t[1] == 'i') t[1] = '1';
	if (t[1] == 'e') t[1] = '3';
	if (t[1] == 'a') t[1] = '4';
	if (t[1] == 's') t[1] = '5';
	if (t[1] == 't') t[1] = '7';
	if (t[1] == 'b') t[1] = '8';
	if (t[1] == 'g') t[1] = '9';
	dict.insert(t);
}

void gao3(string t) {
	if (t[0] == 'o') t[0] = '0';
	if (t[0] == 'i') t[0] = '1';
	if (t[0] == 'e') t[0] = '3';
	if (t[0] == 'a') t[0] = '4';
	if (t[0] == 's') t[0] = '5';
	if (t[0] == 't') t[0] = '7';
	if (t[0] == 'b') t[0] = '8';
	if (t[0] == 'g') t[0] = '9';

	if (t[1] == 'o') t[1] = '0';
	if (t[1] == 'i') t[1] = '1';
	if (t[1] == 'e') t[1] = '3';
	if (t[1] == 'a') t[1] = '4';
	if (t[1] == 's') t[1] = '5';
	if (t[1] == 't') t[1] = '7';
	if (t[1] == 'b') t[1] = '8';
	if (t[1] == 'g') t[1] = '9';
	dict.insert(t);
}

const int MAXN = 10000; //number of vertices
const int MAXE = 10000000; //number of edges

struct Tedge {
	int v, next;
};

Tedge edge[MAXE];
int first[MAXN], px[MAXN], py[MAXN], dx[MAXN], dy[MAXN], q[MAXN];
bool used[MAXN];
int N, E, len;

void init() {
	memset(first, -1, sizeof(first));
	E = 0;
}

inline void add_edge(int u, int v) {
	edge[E].v = v; edge[E].next = first[u]; first[u] = E++;
}

bool search(int u) {
	if (dx[u] > len) return 0;
	used[u] = 1;
	for (int i = first[u]; i != -1; i = edge[i].next) {
		int v = edge[i].v;
		if ((py[v] == -1 || !used[py[v]]) && dx[u] + 1 == dy[v]) {
			int tx = px[u], ty = py[v];
			px[u] = v; py[v] = u;
			if (ty == -1 || search(ty)) return 1;
			px[u] = tx; py[v] = ty;
		}
	}
	return 0;
}

int hopcroft() {
	memset(px, -1, sizeof(px));
	memset(py, -1, sizeof(py));

	while (1) {
		memset(dx, 0, sizeof(dx));
		memset(dy, 0, sizeof(dy));
		int t = len = 0;
		for (int i = 0; i < N; ++i)
			if (px[i] == -1) q[t++] = i, dx[i] = 1;
		for (int h = 0; h < t; ++h) {
			int u = q[h];
			for (int i = first[u]; i != -1; i = edge[i].next) {
				int v = edge[i].v;
				if (!dy[v]) {
					dy[v] = dx[u] + 1;
					if (py[v] != -1) q[t++] = py[v], dx[py[v]] = dy[v] + 1;
					else len = max(len, dy[v]);
				}
			}
		}
		if (!len) break;
		memset(used, 0, sizeof(used));
		for (int i = 0; i < N; ++i)
			if (px[i] == -1) search(i);
	}

	int ret = 0;
	for (int i = 0; i < N; ++i)
		if (px[i] != -1) ++ret;
	return ret;
}


int main() {
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase) {
		scanf("%d", &k);
		scanf("%s", s);
		n = strlen(s);

		dict.clear();
		for (int i = 0; i + 1 < n; ++i) {
			string t = "";
			t += s[i]; t += s[i + 1];
			dict.insert(t);
			
			gao1(t);
			gao2(t);
			gao3(t);
		}

		//printf("%d\n", dict.size());

		init();
		N = dict.size();
		int cntI = 0;
		for (set<string>::iterator i = dict.begin(); i != dict.end(); ++i) {
			int cntJ = 0;
			for (set<string>::iterator j = dict.begin(); j != dict.end(); ++j) {
				if (cntI != cntJ && (*i)[1] == (*j)[0]) add_edge(cntI, cntJ);
				++cntJ;
			}
			++cntI;
		}

		int ans = hopcroft();
		if (ans == N) --ans;
		printf("Case #%d: %d\n", nCase, 2 * N - ans);
	}

	return 0;
}
