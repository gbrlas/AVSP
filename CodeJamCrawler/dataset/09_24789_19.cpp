#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <iostream>
#define P(X) ((X)*(X))

using namespace std;

int bases[11];
set <string> s;

string converte (int n, int b) {
	int i;
	for (i = 1; i <= n; i*=b);
	string r = "";
	i /= b;
	for (; i >= 1; i/=b) {
		r += (n / i);
		n %= i;
	}
	return r;
}

string novo (string n, int b) {
	int tmp = 0;
	for (int i = 0; i < (int)n.size(); i++)
		tmp += P(n[i]);
	return converte (tmp, b);
}


bool testa (string n, int b) {
	//cout << n << " " << b << endl;
	if (s.find (n) != s.end())
		return false;
	s.insert (n);
	string r = novo (n, b);
	if ((int)r.size() == 1 && r[0] == 1)
		return 1;
	return testa (r, b);
}
	

int f () {
	for (int i = 2; ; i++) {
		bool flag = 1;
		for (int b = 2; b < 11 && flag; b++)
			if (bases[b]) {
				s.clear();
				flag = testa (converte (i, b), b);
			}
		if (flag)
			return i;
	}
	return 0;
}


int main () {
	int T;
	scanf ("%d ", &T);
	for (int tes = 1; tes <= T; tes++) {
		for (int i = 0; i < 11; i++)
			bases[i] = 0;
		int c1;
		char c2;
		while (scanf ("%d%c", &c1, &c2)) {
			bases[c1] = 1;
			if (c2 == '\n')
				break;
		}
		printf ("Case #%d: %d\n", tes, f ());
	}
	return 0;
}
