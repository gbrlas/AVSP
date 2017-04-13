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

const int MAX = 2000000;

vector <int> smallest[MAX + 1];

void init() {
	char buf[8];
	for(int i = 10; i <= MAX; ++i) {
		sprintf(buf, "%d", i);
		int len = strlen(buf);
		for(int start = 0; start < len; ++start) {
			int num = 0;
			for(int j = 0; j < len; ++j) {
				num *= 10;
				num += buf[(start + j) % len] - '0';
			}
			if(i >= num)
				continue;
			smallest[i].push_back(num);
		}
		sort(smallest[i].begin(), smallest[i].end());
		smallest[i].resize(unique(smallest[i].begin(), smallest[i].end()) - smallest[i].begin());
	}
}

int main() {
	init();
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		int a, b;
		cin >> a >> b;
		int result = 0;
		for(int i = a; i <= b; ++i)
			foreach(j, 0, smallest[i]) {
				if(smallest[i][j] <= b)
					++result;
				else
					break;
			}
		printf("Case #%d: %d\n", t + 1, result);
	}
	return 0;
}
