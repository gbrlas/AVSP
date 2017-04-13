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

#define foreach(i, s, w) for(int i = s; i < int(w.size()); ++i)
#define forX(i, m) for(typeof(m.begin()) i = m.begin(); i != m.end(); ++i)

using namespace std;

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		int N;
		cin >> N;
		set <pair <int, int> > p;
		for(int i = 0; i < N; ++i) {
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			for(int y = y1; y <= y2; ++y)
				for(int x = x1; x <= x2; ++x)
					p.insert(make_pair(x, y));
		}
		int result = 0;
		while(p.size()) {
			set <pair <int, int> > p2;
			forX(i, p) {
				if(p.count(make_pair(i->first - 1, i->second)) || p.count(make_pair(i->first, i->second - 1)))
					p2.insert(*i);
				if(!p.count(make_pair(i->first + 1, i->second)) && p.count(make_pair(i->first + 1, i->second - 1)))
					p2.insert(make_pair(i->first + 1, i->second));
			}
			p = p2;
			++result;
		}
		printf("Case #%d: %d\n", t + 1, result);
	}
	return 0;
}
