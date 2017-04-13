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
const int MOD = 100003;

using namespace std;

template <typename T>
struct CombinationsModulo {
	vector <vector <T> > comb;
	
	CombinationsModulo(int N, T MOD) {
		comb.resize(N + 1);
		comb[0].push_back(1);
		foreach(i, 1, comb)
			for(int j = 0; j <= i; ++j)
				comb[i].push_back(((j == 0? 0: comb[i - 1][j - 1]) + (j == i? 0: comb[i - 1][j])) % MOD);
	}
};

CombinationsModulo <long long> comb(600, MOD);

int T, N;
map <int, int> mem[600];

int Solve(int pos, int number) {
	if(number < pos || number < 1 || pos < 1)
		return 0;
	if(pos == 1)
		return (number > 1? 1: 0);
	if(mem[pos].count(number))
		return mem[pos][number];
	long long result = 0;
	const int next = pos;
	int len = number - pos - 1;
	for(int l = 0; l <= len; ++l) {
		result += Solve(pos - l - 1, next) * comb.comb[len][l];
		result %= MOD;
	}
	return mem[pos][number] = result;
}

int main() {
	cin >> T;
	for(int t = 0; t < T; ++t) {
		cin >> N;
		int result = 0;
		for(int len = 1; len <= N; ++len) {
			result += Solve(len, N);
			result %= MOD;
		}
		printf("Case #%d: %d\n", t + 1, result);
	}
}
