#include <iostream>
#include <vector>
#include <map>
using namespace std;

long long mod = 1000002013;

long long price(int n, long long dist) {
	return (dist * n - dist * (dist - 1) / 2) % mod;
}

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int n, m;
		cin >> n >> m;
		typedef map<int, pair<int, int> > p_map;
		p_map p;

		long long full = 0;
		for (int i = 0; i < m; ++i) {
			int o, e, cnt;
			cin >> o >> e >> cnt;
			full = (full + cnt * price(n, e - o)) % mod;
			p[o].first += cnt;
			p[e].second += cnt;
		}

		typedef map<int, int, greater<int> > a_map;
		a_map active;
		long long red = 0;
		for (p_map::iterator it = p.begin(); it != p.end(); ++it) {
			active[it->first] += it->second.first;
			int e = it->second.second;
			while (e > 0) {
				a_map::iterator it2 = active.begin();
				int out = min(it2->second, e);
				red = (red + out * price(n, it->first - it2->first)) % mod;
				it2->second -= out;
				e -= out;
				if (it2->second == 0) {
					active.erase(it2);
				}
			}
		}

		cout << "Case #" << test << ": " << (full - red + mod) % mod << endl;
	}
}
