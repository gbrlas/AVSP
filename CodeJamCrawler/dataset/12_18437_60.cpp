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

int googlers, min_interesting;
vector <int> scores;
int mem[128][128];

int Solve(int pos, int left) {
	if(pos == googlers)
		return left == 0? 0: -10000;
	if(mem[pos][left] != -1)
		return mem[pos][left];
	int result = -10000;
	if(min_interesting * 3 - 2 <= scores[pos])
		result = max(result, Solve(pos + 1, left) + 1);
	else
		result = max(result, Solve(pos + 1, left));
	if(left > 0) {
		for(int mi = 0; mi <= 10; ++mi)
			for(int d = 0; d <= 2 && mi + d <= 10; ++d) {
				int ma = scores[pos] - mi - mi - d;
				if(ma < mi + d || ma > 10 || ma - mi != 2)
					continue;
				if(ma >= min_interesting)
					result = max(result, Solve(pos + 1, left - 1) + 1);
				else
					result = max(result, Solve(pos + 1, left - 1));
			}
	}
	return mem[pos][left] = result;
}

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		int surprising;
		cin >> googlers >> surprising >> min_interesting;
		scores.resize(googlers);
		foreach(i, 0, scores)
			cin >> scores[i];
		memset(mem, 0xff, sizeof(mem));
		int result = Solve(0, surprising);
		printf("Case #%d: %d\n", t + 1, result);
	}
	return 0;
}
