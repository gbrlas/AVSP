#include <vector>
#include <limits>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

long long solve(vector<long long> & dist, long long l, long long t,
		long long n, long long c) {
	vector<int> pos(n, 0);

	for (int i = 0; i < n; ++i)
		pos[i] = 2 * dist[i % c];

	int i = 0;
	long long tnow = 0;
	while (tnow < t && i < n) {
		if (tnow + pos[i] < t) {
			tnow += pos[i];
			++i;
		} else {
			pos[i] -= t - tnow;
			tnow = t;
		}
	}

	nth_element(pos.begin() + i, pos.end() - l, pos.end());

	while (i < n - l) {
		tnow += pos[i];
		++i;
	}

	while (i < n) {
		tnow += pos[i] / 2;
		++i;
	}

	return tnow;
}

int main(void) {
	long long i, j, ncase, l, t, n, c;
	vector<long long> dist;
	for (i = 1, cin >> ncase; i <= ncase; ++i) {
		// Read input
		cin >> l >> t >> n >> c;

		dist.resize(c);
		for (j = 0; j < c; ++j)
			cin >> dist[j];

		// Print the result
		printf("Case #%lld: %lld\n", i, solve(dist, l, t, n, c));

		dist.clear();
	}
}
