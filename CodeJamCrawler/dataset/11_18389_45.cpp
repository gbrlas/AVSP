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
		vector <pair <char, int> > order(N);
		vector <int> to[2];
		to[0].resize(N + 1, -1);
		to[1].resize(N + 1, -1);
		foreach(i, 0, order)
			cin >> order[i].first >> order[i].second;
		for(int i = N - 1; i >= 0; --i) {
			if(order[i].first == 'O') {
				to[0][i] = order[i].second;
				to[1][i] = to[1][i + 1];
			} else {
				to[1][i] = order[i].second;
				to[0][i] = to[0][i + 1];
			}
		}

		int result = 0, at0 = 1, at1 = 1;
		foreach(i, 0, order) {
			int togo;
			if(order[i].first == 'O') {
				togo = abs(at0 - order[i].second) + 1;
				at0 = order[i].second;
				int need = abs(at1 - to[1][i]);
				if(need <= togo)
					at1 = to[1][i];
				else
					at1 += (at1 - to[1][i]) / -need * togo;
			} else {
				togo = abs(at1 - order[i].second) + 1;
				at1 = order[i].second;
				int need = abs(at0 - to[0][i]);
				if(need <= togo)
					at0 = to[0][i];
				else
				at0 += (at0 - to[0][i]) / -need * togo;
			}
			result += togo;
		}

		printf("Case #%d: %d\n", t + 1, result);
	}
	return 0;
}
