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
		int R, C;
		cin >> R >> C;
		vector <string> map(R);
		foreach(i, 0, map)
			cin >> map[i];
		foreach(i, 1, map)
			foreach(j, 1, map[i]) {
				if(map[i - 1][j - 1] != '#' || map[i - 1][j] != '#' || map[i][j - 1] != '#' || map[i][j] != '#')
					continue;
				map[i - 1][j - 1] = map[i][j] = '/';
				map[i - 1][j] = map[i][j - 1] = '\\';
			}
		bool ok = true;
		foreach(i, 0, map)
			ok = ok && count(map[i].begin(), map[i].end(), '#') == 0;
		
		printf("Case #%d:\n", t + 1);
		if(ok) {
			foreach(i, 0, map)
				cout << map[i] << endl;
		} else {
			cout << "Impossible" << endl;
		}
	}
	return 0;
}
