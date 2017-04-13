#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int N, M;

bool check(int x1, int y1, int x2, int y2) {
	if (max(0, max(x1, x2)) - min(0, min(x1, x2)) > N) return false;
	if (max(0, max(y1, y2)) - min(0, min(y1, y2)) > M) return false;
	int ox = min(0, min(x1, x2));
	int oy = min(0, min(y1, y2));
	cout << -ox << ' ' << -oy << ' ';
	cout << x1 - ox << ' ' << y1 - oy << ' ';
	cout << x2 - ox << ' ' << y2 - oy << endl;
	return true;
}

bool solve(int P) {
	int A; cin >> N >> M >> A;
	cout << "Case #" << P + 1 << ": ";
	for (int x1 = 1; x1 <= N; ++x1) {
		for (int y1 = 0; y1 <= M; ++y1) {
			for (int x2 = -N; x2 <= N; ++x2) {
				if (x1 == 0 || x2 * y1 % x1 == A % x1) {
					int y2 = x1 == 0 ? y1 : (x2 * y1 - A) / x1;
					if (check(x1, y1, x2, y2))
						return true;
				}
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
		solve(i);
	return 0;
}
