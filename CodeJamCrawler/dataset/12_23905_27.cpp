#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int, int> int2;

int score(int2 ledge, int pos) {
	return ledge.first + min(ledge.second, ledge.first - pos);
}

int main() {
	int T; cin >> T;
	for (int No = 1; No <= T; No++) {
		int N; cin >> N;
		vector<int2> ledges(N);
		for (int i = 0; i < N; i++) {
			cin >> ledges[i].first >> ledges[i].second;
		}
		int D; cin >> D;

		vector<int> reach(N);
		int ok = 1;
		reach[0] = ledges[0].first * 2;

		bool ans = false;
		for (int i = 0; i < N; i++) {
			int pos = ledges[i].first;
			if (ok <= i) {
				break;
			}
			if (reach[i] >= D) {
				ans = true;
				break;
			}
			for (; ok < N && ledges[ok].first <= reach[i]; ok++) {
				reach[ok] = score(ledges[ok], pos);
			}
		}
		
		cout << "Case #" << No << ": " << (ans ? "YES" : "NO") << endl;
	}
	return 0;
}
