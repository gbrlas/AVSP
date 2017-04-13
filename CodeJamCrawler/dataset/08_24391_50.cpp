#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int PS[] = {2, 3, 5, 7};
const int LCM = 210;

typedef unsigned long long C;
typedef vector<C> V;

void rec(string &s, int i, vector<V> &m) {
	int l = s.size(), n = 0;
	for (int j = 0; i + j < l; ++j) {
		n = (n * 10 + (s[i + j] - '0')) % LCM;
		for (int x = 0; x < LCM; ++x) {
			m[i][x] += m[i + j + 1][(n + x) % LCM];
			if (i > 0)
				m[i][x] += m[i + j + 1][(n - x + LCM) % LCM];
		}
	}
}

bool solve(int P) {
	string s; getline(cin, s);
	int l = s.size();
	V v(LCM, 0);
	vector<V> m(l + 1, v);
	m[l][0] = 1;
	for (int i = l; i-- > 0; )
		rec(s, i, m);
	C c = 0;
	for (int x = 0; x < LCM; ++x) {
		if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) {
			c += m[0][x];
		}
	}
	cout << "Case #" << P + 1 << ": " << c << endl;
}

int main() {
	int n; cin >> n;
	string eol; getline(cin, eol);
	for (int i = 0; i < n; ++i)
		solve(i);
	return 0;
}
