// g++ -std=c++0x lawnmower.cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

bool dw() {
	size_t N, M;
	cin >> N >> M;
	vvi lawn(N, vi(M)), lawnp(M, vi(N));
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++) {
			cin >> lawn[i][j];
			lawnp[j][i] = lawn[i][j];
		}
	}

	vi bv(N), bh(M);
	for (size_t i = 0; i < N; i++) {
		bv[i] = *max_element(lawn[i].begin(), lawn[i].end());
	}
	for (size_t i = 0; i < M; i++) {
		bh[i] = *max_element(lawnp[i].begin(), lawnp[i].end());
	}

	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++) {
			if (lawn[i][j] != min(bv[i], bh[j])) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	size_t T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		cout << "Case #" << (t + 1) << ": " << (dw() ? "YES" : "NO") << endl;
	}
	return 0;
}

