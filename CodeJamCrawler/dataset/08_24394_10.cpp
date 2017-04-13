#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int rlen(string &s, int L) {
	char c = ' ';
	int l = 0;
	for (int i = 0; i < L; ++i)
		if (s[i] != c)
			++l, c = s[i];
	return l;
}

bool solve(int P) {
	int k; cin >> k;
	string S; getline(cin, S); getline(cin, S);
	int p[k];
	for (int i = 0; i < k; ++i) {
		p[i] = i;
	}
	int L = S.size();
	int l = L;
	string T = S;
	do {
		for (int i = 0; i < k; ++i)
			for (int j = 0; j < L; j += k)
				T[j + p[i]] = S[j + i];
		if (rlen(T, L) < l)
			l = rlen(T, L);
	} while (next_permutation(p, p + k));
	cout << "Case #" << P + 1 << ": " << l << endl;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
		solve(i);
	return 0;
}
