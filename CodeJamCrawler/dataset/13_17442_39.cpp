#include <iostream>

using namespace std;
typedef long long Long;

Long calc(Long M, Long P) {
	if (M == P) return M - 1;
	Long ret = 0, k = 1;
	while (P > M / 2) {
		k = k * 2;
		ret += k;
		P -= M / 2;
		M /= 2;
	}
	return ret;
}

void  solve(int cas) {
	cout << "Case #" << cas << ": " ;
	Long N, P, M;
	cin >> N >> P;
	M = (1LL << N);
	Long ans1 = calc(M, P);
	Long ans2 = calc(M, M - P);
	ans2 = M - ans2 - 2;
	if (P == M) ans2 = M - 1;
	cout << ans1 << ' ' << ans2 << endl;
}

int main() {
	int task; cin >> task;
	for (int t = 1; t <= task; ++t) 
		solve(t);
	return 0;
}
