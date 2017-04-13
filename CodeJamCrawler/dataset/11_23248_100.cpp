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

typedef pair<char, char> pcc;
typedef map<pcc, char> mpccc;
typedef set<pcc> spcc;
typedef vector<char> vc;

mpccc combine;
spcc destroy;
vc elems;

pcc mpair(char a, char b) {
	if (a > b)
		swap(a, b);
	return pcc(a, b);
}

char get_combine(char a, char b) {
	mpccc::iterator it = combine.find(mpair(a, b));
	if (it == combine.end())
		return false;
	return it->second;
}

void solve() {
	combine.clear();
	destroy.clear();
	elems.clear();
	int c, d, n;
	scanf("%d", &c);
	for (int i = 0; i < c; ++i) {
		char a, b, r;
		scanf(" %c%c%c", &a, &b, &r);
		combine[mpair(a, b)] = r;
	}
	scanf("%d", &d);
	for (int i = 0; i < d; ++i) {
		char a, b;
		scanf(" %c%c", &a, &b);
		destroy.insert(mpair(a, b));
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		char a;
		scanf(" %c", &a);
		if (elems.size() > 0) {
			char cmb = get_combine(a, elems.back());
			if (cmb) {
				elems.pop_back();
				elems.push_back(cmb);
				continue;
			}
		}
		bool dest = false;
		for (int j = 0, jj = elems.size(); !dest && j < jj; ++j) {
			if (destroy.find(mpair(elems[j], a)) != destroy.end())
				dest = true;
		}
		if (dest) {
			elems.clear();
			continue;
		}
		elems.push_back(a);
	}
	printf("[");
	for (int i = 0, ii = elems.size(); i < ii; ++i) {
		if (i > 0)
			printf(", ");
		printf("%c", elems[i]);
	}
	printf("]\n");
}

int main() {
	freopen(FILE_IN, "r", stdin);
	freopen(FILE_OUT, "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
