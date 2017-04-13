#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define FU(i,a,b) for(i = a; i < b; i++)
#define FD(i,a,b) for(i = a; i > b; i--)
#define FE(i,a) for(i = a.begin(); i != a.end(); i++)
#define PB(a,b) a.push_back(b)
#define SZ(a) (int)a.size()

typedef long long LL;
typedef vector<int> VI;

int k, a[10000];
int n;
string s;

int do_it() {
	string t = s;

	n = SZ(s);

	for(int i = 0; i < n; i += k)
		for(int j = 0; j < k; j++) t[i+j] = s[i+a[j]];

	int res = 1;

	for(int i = 1; i < n; i++)
		if(t[i] != t[i-1]) res++;

	return res;
}

int main(void) {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int c;

	scanf("%d", &c);
	for(int t = 1; t <= c; t++) {
		cin >> k >> s;

		for(int i = 0; i < k; i++) a[i] = i;

		int sol = 100000001;

		do {
			sol = min(sol, do_it());
		} while(next_permutation(a, a+k));

		printf("Case #%d: %d\n", t, sol);
	}

	exit(0);
}