#include <algorithm>
#include <numeric>
#include <sstream>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <iostream>
#include <cassert>

#define foreach(i, s, w) for(int i = s; i < int(w.size()); ++i)
#define forX(i, m) for(typeof(m.begin()) i = m.begin(); i != m.end(); ++i)

using namespace std;

vector <string> vs;
short first_len[22][22][1002];

struct node {
	string expr;
	int x, y, value;

	node(const char c, const int x, const int y): expr(1, c), x(x), y(y), value(c - '0') {}

	inline friend bool operator<(const node &a, const node &b) {
		if(a.expr.size() != b.expr.size())
			return a.expr.size() > b.expr.size();
		if(a.expr != b.expr)
			return a.expr > b.expr;
		if(a.value != b.value)
			return a.value > b.value;
		if(a.y != b.y)
			return a.y > b.y;
		return a.x > b.x;
	}

	node expand(const char c, const int x, const int y) const {
		node res(c, x, y);
		//cout << "expr " << expr << " + \"" << c << "\"";
		res.expr = expr + c;
		res.value = value;
		if(c >= '0' && c <= '9') {
			if(expr[expr.size() - 1] == '+')
				res.value += c - '0';
			else
				res.value -= c - '0';
		//	cout << "a/r " << int(res.value) << endl;
		}
		//cout << res.expr << " (" << res.value << ")" << endl;
		//system("pause");
		return res;
	}
};

const int move[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int width, num;
		cin >> width >> num;
		vs.resize(width + 2);
		for(int i = 1; i <= width; ++i) {
			cin >> vs[i];
			vs[i] = "#" + vs[i] + "#";
		}
		vs[0] = vs.back() = string(vs[1].size(), '#');
		vector <int> want(num);
		vector <string> res(num);
		vector <bool> had(3000);
		foreach(i, 0, want)
			cin >> want[i];
		
		priority_queue <node> Q;
		memset(first_len, 0xff, sizeof(first_len));
		int need = want.size();
		
		foreach(i, 0, vs)
			foreach(j, 0, vs[i])
				if(vs[i][j] >= '0' && vs[i][j] <= '9') {
					node x(vs[i][j], j, i);
					Q.push(x);
					first_len[x.y][x.x][x.value + 500] = x.expr.size();
					if(x.value >= -500 && x.value <= 500 && !had[x.value + 1500]) {
						had[x.value + 1500] = 1;
						const int pos = find(want.begin(), want.end(), x.value) - want.begin();
						if(pos != want.size()) {
							res[pos] = x.expr;
							--need;
							//cout << "found " << pos << ": " << res[pos] << endl;
						}
					}
			}
		
		while(need && !Q.empty()) {
			node n = Q.top();
			//cout << n.expr << "(" << n.x << ", " << n.y << ") " << n.value << ", " << first_len[n.y][n.x][n.value] << endl;
			Q.pop();
			if(first_len[n.y][n.x][n.value + 500] != n.expr.size())
				continue;
			//cout << "ok" << endl;
			first_len[n.y][n.x][n.value + 500] = -2;
			for(int k = 0; k < 4; ++k) {
				const char c = vs[n.y + move[k][0]][n.x + move[k][1]];
				if(c == '#')
					continue;
				node x = n.expand(c, n.x + move[k][1], n.y + move[k][0]);
				if(x.value >= -500 && x.value <= 500 && first_len[x.y][x.x][x.value + 500] == -1) {
					first_len[x.y][x.x][x.value + 500] = x.expr.size();
					Q.push(x);
					if(!had[x.value + 1500]) {
						had[x.value + 1500] = 1;
						const int pos = find(want.begin(), want.end(), x.value) - want.begin();
						if(pos != want.size()) {
							res[pos] = x.expr;
							--need;
							//cout << "found " << pos << ": " << res[pos] << endl;
						}
					}
				}
			}
		}

		printf("Case #%d:\n", t);
		foreach(i, 0, res)
			cout << res[i] << endl;
		assert(!need);
	}
	return 0;
}
