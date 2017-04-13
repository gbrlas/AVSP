#include <vector>
#include <limits>
#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;

bool test(vector<int> & note, int freq) {
	for (int i = 0; i < note.size(); ++i)
		if (freq % note[i] != 0 && note[i] % freq != 0)
			return false;
	return true;
}

int main(void) {
	int res;
	int i, j, t, n, l, h;
	vector<int> note;
	for (i = 1, cin >> t; i <= t; ++i) {
		// Read input
		cin >> n >> l >> h;
		note.resize(n);
		for (j = 0; j < n; ++j)
			cin >> note[j];

		for (res = l; res <= h; ++res) {
			if (test(note, res))
				break;
		}
		// Print the result
		printf("Case #%d: ", i);
		if (res > h)
			printf("NO\n");
		else
			printf("%d\n", res);
		note.clear();
	}
}
