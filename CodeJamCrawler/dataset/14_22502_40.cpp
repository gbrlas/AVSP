#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int TC, M, N, ans, high, a[105];
char s[105];
string str[105];
set<string> trie[105];
void recur(int x) {
	if (x == M) {
		for (int i = 0; i < N; ++i) trie[i].clear();
		for (int k = 0; k < M; ++k) {
			for (int l = 0; l < str[k].length(); ++l) {
				trie[a[k]].insert(str[k].substr(0, l+1));
			}
		}
		bool fail = 0;
		int curans = 0;
		for (int i = 0; i < N; ++i) {
			if (trie[i].size() == 0) fail = 1;
			curans += trie[i].size() + 1;
		}
		if (fail) return;
		if (curans > high) {
			high = curans;
			ans = 1;
		} else if (curans == high) ++ans;
		
	}
	else {
		for (int i = 0; i < N; ++i) {
			a[x] = i;
			recur(x+1);
		}
	}
	return;
}
int main () {
	freopen("trie.in", "r", stdin);
	//freopen("trie.out", "w", stdout);
	
	scanf("%d", &TC);
	for (int T = 1; T <= TC; ++T) {
		ans = 0, high = 0;
		scanf("%d%d", &M, &N);
		for (int i = 0; i < M; ++i) {
			scanf("%s", s);
			str[i] = string(s);
		}
		recur(0);
		
		printf("Case #%d: %d %d\n", T, high, ans);
	}
}
