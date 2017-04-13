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

using namespace std;

int H, W, R;
set <pair <int, int> > rock;
map <pair <int, int>, int> mem;

int Solve(int h, int w) {
	if(h == H && w == W)
		return 1;
	if(h >= H || w >= W)
		return 0;
	pair <int, int> key(h, w);
	if(rock.count(key))
		return 0;
	if(mem.count(key))
		return mem[key];
	return (mem[key] = (Solve(h + 1, w + 2) + Solve(h + 2, w + 1)) % 10007);
}

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		cin >> H >> W >> R;
		rock.clear();
		mem.clear();
		for(int i = 0; i < R; ++i) {
			int a, b;
			cin >> a >> b;
			rock.insert(make_pair(a, b));
		}
		int x = Solve(1, 1);
		printf("Case #%d: %d\n", t + 1, x);
	}
	return 0;
}
