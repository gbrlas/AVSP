#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <sstream>
#include <set>
using namespace std;

int m[25600];
int main() {
	freopen("A.in", "rt", stdin);
	freopen("A.out", "wt", stdout);
	string x;
	int test;
	cin >> test;
	for(int T = 1; T <= test; T++) {
		cin >> x;
		memset(m, -1, sizeof(m));
		m[x[0]] = 1;
		int b = 2;
		bool ok = true;
		int i = 1;
		while(i < x.length() && x[i] == x[0]) i++;
		for(; i < x.length(); i++) {
			if(m[x[i]] == -1 && ok) {
				m[x[i]] = 0;
				ok = false;
			} else {
				if(m[x[i]] == -1) m[x[i]] = b++;
			}
		}
		long long res = 0;
		long long j = 1;
		for(int i = x.length() - 1; i >= 0; i--, j *= b) {
			int mm = m[x[i]];
			res += j * mm;
		}
		cout << "Case #" << T << ": " << res << endl;
	}
	return 0;
}