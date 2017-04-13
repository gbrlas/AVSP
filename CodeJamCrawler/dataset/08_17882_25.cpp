#include <algorithm>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <iostream>

#define foreach(i,s,w) for(int i=s;i<w.size();++i)
#define forX(i,m) for(typeof(m.begin())i=m.begin();i!=m.end();++i)
#define value is_and

using namespace std;

struct node {
	bool is_and, changeable, is_leaf;
};

int M, V;
vector <node> tree;
short mem[25000][2];

short Solve(short pos, bool need) {
	assert(pos > 0 && pos < tree.size());
	if(tree[pos].is_leaf)
		return (tree[pos].value == need? 0: -1);
	if(mem[pos][need] != -2)
		return mem[pos][need];
	short a[2], b[2];
	a[0] = Solve(2 * pos, 0);
	a[1] = Solve(2 * pos, 1);
	b[0] = Solve(2 * pos + 1, 0);
	b[1] = Solve(2 * pos + 1, 1);
	short result = -1;
	for(short i = 0; i < 2; ++i)
		for(short j = 0; j < 2; ++j) {
			if(a[i] == -1 || b[j] == -1)
				continue;
			int an = (tree[pos].is_and? 0: 1);
			int o = (tree[pos].is_and? 1: 0);
			if(bool(i && j) == need) {
				if(result == -1 || result > a[i] + b[j] + an)
					if(an == 0 || tree[pos].changeable)
						result = a[i] + b[j] + an;
			}
			if(bool(i || j) == need) {
				if(result == -1 || result > a[i] + b[j] + o)
					if(o == 0 || tree[pos].changeable)
						result = a[i] + b[j] + o;
			}
		}
	mem[pos][need] = result;
	return result;
}

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		cin >> M >> V;
		int internal = (M - 1) / 2, num = 1;
		tree.clear();
		tree.push_back(node());
		for(int i = 0; i < internal; ++i, num *= 2) {
			node x;
			int g, c;
			cin >> g >> c;
			x.is_and = (g == 1);
			x.changeable = (c == 1);
			x.is_leaf = false;
			tree.push_back(x);
		}
		for(int i = internal; i < M; ++i) {
			node x;
			int val;
			cin >> val;
			x.value = val;
			x.changeable = false;
			x.is_leaf = true;
			tree.push_back(x);
		}
		for(int i = 0; i < 25000; ++i)
			for(int j = 0; j < 2; ++j)
				mem[i][j] = -2;
		int result = Solve(1, V);
		if(result == -1)
			cout << "Case #" << (t + 1) << ": IMPOSSIBLE" << endl;
		else
			cout << "Case #" << (t + 1) << ": " << result << endl;
	}
	return 0;
}
