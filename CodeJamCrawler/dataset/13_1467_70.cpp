#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
typedef long long llong;

#define mp make_pair
#define lowbit(x) ((x) & (-(x)))
#define pf(x) ((x) * (x))
#define two(x) (1 << (x))
#define twoL(x) ((llong) 1 << (x))
#define clr(x, c) memset(x, c, sizeof(x))

inline void ch_max(int &x, int y) {if (x < y) x = y;}
inline void ch_min(int &x, int y) {if (x > y) x = y;}

const double pi = acos(-1.0);
const double eps = 1e-9;

template<typename T>
void Scanf(const vector<string> &vs, vector<T> &d) {
	string str;stringstream ss;
	for (int i = 0; i < vs.size(); ++i) str += vs[i];
	ss << str;d.clear();for (T t; ss >> t; ) d.push_back(t);
}

char str[4][5];

bool win(char c) {
	int k;
	for (int i = 0; i < 4; ++i) {
		for (k = 0; k < 4; ++k) {
			if (str[i][k] != 'T' && str[i][k] != c) break;
		}
		if (k == 4) return true;

		for (k = 0; k < 4; ++k) {
			if (str[k][i] != 'T' && str[k][i] != c) break;
		}
		if (k == 4) return true;
	}

	for (k = 0; k < 4; ++k) {
		if (str[k][k] != 'T' && str[k][k] != c) break;
	}
	if (k == 4) return true;

	for (k = 0; k < 4; ++k) {
		if (str[k][3 - k] != 'T' && str[k][3 - k] != c) break;
	}
	if (k == 4) return true;
	
	return false;
}

bool empty() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (str[i][j] == '.') return false;
		}
	}
	return true;
}
int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	//freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t, nc = 0;
	scanf("%d", &t);
	while (t--) {
		clr(str, 0);
		for (int i = 0; i < 4; ++i) scanf("%s", str[i]);
		if (win('X')) printf("Case #%d: X won\n", ++nc);
		else if (win('O')) printf("Case #%d: O won\n", ++nc);
		else if (!empty()) printf("Case #%d: Game has not completed\n", ++nc);
		else printf("Case #%d: Draw\n", ++nc);
	}
	return 0;
}