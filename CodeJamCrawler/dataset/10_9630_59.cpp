
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution()
{
	int D, I, M, N, v;
	cin >> D >> I >> M >> N;
	vector <int> cost(256);
	for (int i = 0; i < N; i++) {
		cin >> v;
		vector <int> cost1(256);
		for (int v1 = 0; v1 < 256; v1++) {
			int c1 = cost[v1] + D;
				for (int v0 = 0; v0 < 256; v0++) {
					int c2 = cost[v0] + abs(v-v1);
					int delta = abs(v1-v0);
					if (delta > M) {
						if (M) c2 += ((delta-1)/M)*I;
						else c2 += 1000000000;
					}
					c1 = min(c2, c1);
				}
			cost1[v1] = c1;
		}
		cost.swap(cost1);
	}
	cout << *min_element(cost.begin(), cost.end()) << endl;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solution();
	}
	return 0;
}
