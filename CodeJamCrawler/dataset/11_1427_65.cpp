#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <cstdio>
#include <utility>
#include <cctype>
#include <queue>
#include <deque>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

#define X first
#define INF 1000000000
#define Y second
#define For(A,B) for(int A=0;A<B.size();++A)
#define ll long long
#define ld long double
#define PB push_back
#define sz size()
#define eps 0.0000001 
#define V second
#define P first

int main() {
	//freopen("in.txt", "r", stdin);
	freopen("A-small-attempt0_.in", "r", stdin);
	freopen("A-small-attempt0_.out", "w", stdout);
	int t, T; cin >> T;
	int r, c; 
for(t=1;t<=T; t++) {
	scanf("%d %d\n", &r, &c);
	vector<vector<char> > m(r, vector<char>(c));
	char s[1000];
	for (int i=0; i<r; i++) {
		gets(s);
		for (int j=0; j<c; j++) {
			m[i][j] = s[j];
		}
	}
	for (int i=0; i<(r-1); i++) {
		for (int j=0; j<(c-1); j++){
			if ((m[i][j]	    == '#') &&
				(m[i+1][j]   == '#') &&
				(m[i][j+1]   == '#') &&
				(m[i+1][j+1] == '#')) {
				
				m[i][j]	    = '/';
				m[i+1][j]   = '\\';
				m[i][j+1]   = '\\';
				m[i+1][j+1] = '/';
			}
		}
	}
	bool fl = true;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++){
			if (m[i][j]	== '#') {
				fl = false;
			}
		}
	}
	printf("Case #%d:\n", t);
	if (fl) {
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++){
				putchar(m[i][j]);
			}
			putchar('\n');
		}
	} else {
		printf("Impossible\n");
	}
}
	return 0;
}