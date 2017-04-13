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

#define FILE_IN  "C-small-attempt0.in"
#define FILE_OUT "C-small-attempt0.out"

#define MAXW 22
#define MAXL 100
#define D 4

typedef map<int, string> mis;
typedef map<int, int> mii;
typedef set<int> si;

int w;
char square[MAXW][MAXW];

mis math[MAXL][MAXW][MAXW];
mii lengths;
si found[MAXW][MAXW];
int len;

int dx[D] = {0, 1, 0, -1};
int dy[D] = {1, 0, -1, 0};

inline bool in_range(int x) { return x >= 0 && x < w; }
inline bool in_range(int x, int y) { return in_range(x) && in_range(y); }

void calcfrom(int len, int i, int j) {
	for (int d = 0; d < D; ++d) {
		int opi = i + dx[d];
		int opj = j + dy[d];
		if (!in_range(opi, opj))
			continue;
		char op = square[opi][opj];
		for (int dd = 0; dd < D; ++dd) {
			int ni = opi + dx[dd];
			int nj = opj + dy[dd];
			if (!in_range(ni, nj))
				continue;
			int add = square[ni][nj] - '0';
			if (op == '-')
				add = -add;
			for (mis::iterator it = math[len-1][ni][nj].begin(); it != math[len-1][ni][nj].end(); ++it) {
				int res = add + it->first;
				if (found[i][j].count(res) > 0 && math[len][i][j].count(res) == 0)
					continue;
				string expr = string() + op + square[ni][nj] + it->second;
				if (math[len][i][j].count(res) == 0 || expr < math[len][i][j][res]) {
					math[len][i][j][res] = expr;
					found[i][j].insert(res);
					if (lengths.count(square[i][j] - '0' + res) == 0)
						lengths[square[i][j] - '0' + res] = len;
				}
			}
		}
	}
}

void calc(int len) {
	for (int i = 0; i < w; ++i)
		for (int j = 0; j < w; ++j) if (isdigit(square[i][j]))
			calcfrom(len, i, j);
}

void solve() {
	int q;
	scanf("%d %d", &w, &q);
	for (int i = 0; i < w; ++i)
		scanf(" %s", square[i]);
	fill(math[0][0], math[MAXL][0], mis());
	fill(found[0], found[MAXW], si());
	lengths = mii();
	for (int i = 0; i < w; ++i)
		for (int j = 0; j < w; ++j) if (isdigit(square[i][j])) {
			math[0][i][j][0] = "";
			found[i][j].insert(0);
			lengths[square[i][j]-'0'] = 0;
		}
	len = 0;
	for (int qi = 0; qi < q; ++qi) {
		int qq;
		scanf(" %d", &qq);
		while (lengths.count(qq) == 0)
			calc(++len);
		int qlen = lengths[qq];
		string res = "";
		for (int i = 0; i < w; ++i)
			for (int j = 0; j < w; ++j) if (isdigit(square[i][j])) {
				int rem = qq - (square[i][j] - '0');
				if (math[qlen][i][j].count(rem) == 0)
					continue;
				string expr = square[i][j] + math[qlen][i][j][rem];
				if (res == "" || expr < res)
					res = expr;
			}
		printf("%s\n", res.c_str());
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
